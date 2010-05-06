//  BroadcomCrystalHD.cpp
//  BroadcomCrystalHD V1.0
//
//  Created by Scott Davilla on 08.03.09
//  Copyright 2009-2010 4pi Analysis, Inc. All rights reserved.
//
//  ** LICENSE *************************************************************************
//
//  Copyright 2009-2010 4pi Analysis, Inc. All rights reserved.
//  All rights reserved.
//  
//  Redistribution and use in source and binary forms, with or without modification,
//  are permitted provided that the following conditions are met:
//  
//  * Redistributions of source code must retain the above copyright notice, this list
//    of conditions and the following disclaimer.
//  
//  * Redistributions in binary form must reproduce the above copyright notice, this
//    list of conditions and the following disclaimer in the documentation and/or other
//    materials provided with the distribution.
//  
//  * Neither the name of 4pi Analysis, Inc. nor the names of its contributors may be
//    used to endorse or promote products derived from this software without specific
//    prior written permission.
//  
//  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY
//  EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
//  OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT
//  SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
//  INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED
//  TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR
//  BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
//  CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
//  ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH
//  DAMAGE.
//
//  ************************************************************************************

#include <sys/types.h>
#include <sys/conf.h>
#include <miscfs/devfs/devfs.h>
#include <sys/systm.h>

#include "BroadcomCrystalHD.h"
#include "crystalhd_lnx.h"

// Define the metaclass information that is used for runtime
// typechecking of IOKit objects. We're a subclass of IOService,
// but usually we would subclass from a family class.
#define super IOService
OSDefineMetaClassAndStructors( BroadcomCrystalHD, IOService );

// Support For BSD Functions (helpers and macros)
#define DEV_NUM_FLAGS		1
#define DEV_UNIT(dev)		( minor(dev) >> DEV_NUM_FLAGS)

// BSD device interface, we only handle open, close and ioctl and pretend to be a tty char device.
__BEGIN_DECLS
extern int   seltrue(dev_t, int, struct proc *);
__END_DECLS
#define nullread    (d_read_t*)&nulldev
#define nullwrite   (d_write_t*)&nulldev
#define nullselect  (d_select_t*)&nulldev
#define nullstop    (d_stop_t*)&nulldev
#define nullreset   (d_reset_t*)&nulldev
#define mmselect    (select_fcn_t*)seltrue

// Icky, globals (fix this later)
OSArray* g_bcm_dma_info = NULL;
struct crystalhd_user* g_bcm_USER = NULL;
struct crystalhd_adp* g_bcm_adapter = NULL;

IOPCIDevice* BroadcomCrystalHD::m_pciNub = NULL;

// BSD ioctl API
int  bsd_open(dev_t dev, int flags, int devtype, struct proc *p);
int  bsd_close(dev_t dev, int flags, int devtype, struct proc *p);
int  bsd_ioctl(dev_t dev, u_long cmd, caddr_t data, int fflag, struct proc *p);

struct cdevsw BroadcomCrystalHD::m_devsw =
{
    /* d_open     */ bsd_open,
    /* d_close    */ bsd_close,
    /* d_read     */ nullread,
    /* d_write    */ nullwrite,
    /* d_ioctl    */ bsd_ioctl,
    /* d_stop     */ nullstop,
    /* d_reset    */ nullreset,
    /* d_ttys     */ NULL,
    /* d_select   */ mmselect,
    /* d_mmap     */ eno_mmap,
    /* d_strategy */ eno_strat,
    /* d_getc     */ eno_getc,
    /* d_putc     */ eno_putc,
    /* d_type     */ D_TTY
};

// crystalhd bsd user functions
void bsd_add_user(dev_t dev, int pid, struct crystalhd_user* uc);
void bsd_del_user(dev_t dev, int pid, struct crystalhd_user* uc);
struct crystalhd_user* bsd_get_user(dev_t dev, int pid);

//-------------------------------------------------------------------------------
//-------------------------------------------------------------------------------
//-------------------------------------------------------------------------------
// Kext start routine. First routine to be called once we have succesfully matched.
// Return true if we really can handle this device, false if not.
bool
BroadcomCrystalHD::start( IOService * provider )
{
    BC_STATUS           sts = BC_STS_SUCCESS;
    IOReturn            io_return;
    bool                result = false;

    IOLog("BroadcomCrystalHD::start\n");

    g_bcm_dma_info = new OSArray();
    g_bcm_dma_info->initWithCapacity(1);

    if( !super::start( provider ))
        return( false );

    PMinit();
	
    // create BSD dev and make device node
    if (bsd_create_device() != kIOReturnSuccess) {
        goto abortOpen;
    }

    // Our provider class is specified in the driver property table
    // as IOPCIDevice, so the provider must be of that class.
    // The assert is just to make absolutely sure for debugging.
    assert( OSDynamicCast( IOPCIDevice, provider ));
    m_pciNub = (IOPCIDevice*)provider;
    m_pciNub->retain();
    m_pciNub->open(this);

    //IOLog("Starting: PCI Card, ven(0x%x), dev(0x%x)\n", m_pciNub->configRead16(0), m_pciNub->configRead16(2));

    // Request domain power.
    // Without this, the PCIDevice may be in state 0, and the
    // PCI config space may be invalid if the machine has been
    // sleeping.
    m_pciNub->requestPowerDomainState(
		/* power flags */ kIOPMPowerOn,
		/* connection  */ (IOPowerConnection *) getParentEntry(gIOPowerPlane),
		/* spec        */ IOPMLowestState );

    // Create a workloop for scheduling events and also to provide
    // a single threaded context so that this driver will be able to
    // migrate from CPU to CPU on a SMP box.
    m_workloop = IOWorkLoop::workLoop();
    if (!m_workloop) {
        goto abortOpen;
    }
	
    m_commandgate = IOCommandGate::commandGate(this);
    if (!m_commandgate || (m_workloop->addEventSource(m_commandgate) != kIOReturnSuccess)) {
        IOLog("BroadcomCrystalHD::Cannot create command gate\n");
        goto abortOpen;
    }
    
    // Find preferd MSI interrupt and create/register interrupt event source
    do {
        // search for the indexes for legacy and MSI interrupts
        bool    prefer_msi = true;
        int     msi_index = -1;
        int     legacy_index = -1;
        int     intr_type;
        int     intr_index = 0;
        while (1) {
            io_return = m_pciNub->getInterruptType(intr_index, &intr_type);
            if (io_return != kIOReturnSuccess) {
                break;
            }
            if (intr_type == kIOInterruptTypeLevel) {
                legacy_index = intr_index;
            } else if (intr_type & kIOInterruptTypePCIMessaged) {
                msi_index = intr_index;
            }
            intr_index++;
        }
        if (prefer_msi && msi_index != -1) {
            intr_index = msi_index;
        } else {
            intr_index = legacy_index;
        }

        //IOLog("Starting: create and register our interrupt event source\n");
        m_interrupt_source = IOInterruptEventSource::interruptEventSource(
            this, 
            OSMemberFunctionCast(IOInterruptEventAction, this, &BroadcomCrystalHD::interruptOccured),
            m_pciNub,
            intr_index);
    
        if (!m_interrupt_source || (m_workloop->addEventSource(m_interrupt_source) != kIOReturnSuccess) ) {
            goto abortOpen;
        }
    } while(0);
        
    // Enable memory response from the card
    m_pciNub->setMemoryEnable(true);

    m_pci_bar0 = m_pciNub->mapDeviceMemoryWithRegister(kIOPCIConfigBaseAddress0, kIOMapInhibitCache);
    m_pci_bar2 = m_pciNub->mapDeviceMemoryWithRegister(kIOPCIConfigBaseAddress2, kIOMapInhibitCache);
    //IOLog("Starting: map PCI bars, bar0(%p), bar2(%p)\n", m_pci_bar0, m_pci_bar2);

    // Setup crystalhd adapter
    chd_set_log_level(NULL, "debug");
    g_bcm_adapter->pci_i2o_len  = m_pci_bar0->getLength();
    g_bcm_adapter->i2o_addr = m_pci_bar0->getVirtualAddress();
    g_bcm_adapter->pci_mem_len  = m_pci_bar2->getLength();
    g_bcm_adapter->addr = m_pci_bar2->getVirtualAddress();
    alloc_spin_lock(g_bcm_adapter->lock);
    // Setup crystalhd ioctl handler
    chd_dec_init_chdev(g_bcm_adapter);
    
    if ( (sts = crystalhd_setup_cmd_context(&g_bcm_adapter->cmds, g_bcm_adapter)) != BC_STS_SUCCESS){
        BCMLOG_ERR("cmd setup :%d \n", sts);
        goto abortOpen;
    }

    // Enable bus-mastering from the card
    m_pciNub->setBusMasterEnable(true);
    
    // setup power handling
    registerWithPolicyMaker(this);
    provider->joinPMtree(this);
	
    m_workloop->enableAllEventSources();
    m_interrupt_source->enable();

    // Last we have to let user land know that we are ready to publish services
    // on ourselves.  Since we only have one service we just register "this" as a "nub".
    registerService();
    result = true;
    
    IOLog("BroadcomCrystalHD: Found HW and started driver SW.\n");
	
abortOpen:
    return(result);
}

//-------------------------------------------------------------------------------
// Stop Routine. In general the stop routine cleans up all of the resources that
// were allocated in the start routine.  Note however that the stop routine NEVER
// gets called while the driver has its provider open.  So while we have a user 
// client open this driver can not be unloaded! 
void
BroadcomCrystalHD::stop( IOService * provider )
{
    BC_STATUS           sts = BC_STS_SUCCESS;
    
    IOLog("BroadcomCrystalHD::stop\n");
    
    if (m_interrupt_source) {
         m_interrupt_source->disable();
         m_workloop->removeEventSource(m_interrupt_source);
         SAFE_RELEASE(m_interrupt_source);
    }
    if (m_workloop) {
         SAFE_RELEASE(m_workloop);
    }

    // unmap PCI bars and close pci nub.
    SAFE_RELEASE(m_pci_bar0);
    SAFE_RELEASE(m_pci_bar2);
    m_pciNub->close(this);
    SAFE_RELEASE(m_pciNub);

    // shutdown BSD API handler
    if ( (sts = crystalhd_delete_cmd_context(&g_bcm_adapter->cmds)) != BC_STS_SUCCESS){
        BCMLOG_ERR("crystalhd_delete_cmd_context :%d \n",sts);
    }
    chd_dec_release_chdev(g_bcm_adapter);
    // chd_dec_release_chdev uses adp->lock so free lock after.
    free_spin_lock(g_bcm_adapter->lock);
    // free BSD device mode.
    bsd_destroy_device();
	
    g_bcm_dma_info->flushCollection();
    SAFE_RELEASE(g_bcm_dma_info);
    
	PMstop();
    super::stop( provider );
}

//-------------------------------------------------------------------------------
// Override the IOService::getWorkLoop method to return _WorkLoop
// that we MUST have created to deliver interrupts on.
IOWorkLoop*
BroadcomCrystalHD::getWorkLoop(void)
{
    return m_workloop;
}

//-------------------------------------------------------------------------------
IOPCIDevice*
BroadcomCrystalHD::getPciNub(void)
{
    return(m_pciNub);
}
//-------------------------------------------------------------------------------
IOCommandGate*
BroadcomCrystalHD::getCommandGate(void)
{
    return(m_commandgate);
}
//-------------------------------------------------------------------------------
void
BroadcomCrystalHD::interruptOccured(IOInterruptEventSource *sender, int count)
{
    if (g_bcm_adapter) {
      crystalhd_cmd_interrupt(&g_bcm_adapter->cmds);
    }
}

//-------------------------------------------------------------------------------
//-------------------------------------------------------------------------------
IOReturn
BroadcomCrystalHD::bsd_create_device(void)
{
    IOReturn io_return = kIOReturnSuccess;

    //IOLog("BroadcomCrystalHD::bsd_create_device\n");

    // initialize these so bsd_destroy_device will not barf if called early.
    m_bds_lock = NULL;
    m_Major = (unsigned int)-1;
    m_LastMinor = 4;
    m_base_dev = (dev_t)-1;
    m_cdev_node = NULL;

    do {
        m_Names = OSDictionary::withCapacity(4);
        m_DEVs = (BroadcomCrystalHD**)IOMalloc(m_LastMinor * sizeof(m_DEVs[0]));
        g_bcm_adapter = (struct crystalhd_adp*)IOMalloc(sizeof(*g_bcm_adapter));
        m_bds_lock = IOLockAlloc();

        if (!m_bds_lock || !g_bcm_adapter || !m_DEVs || !m_Names) {
            IOLog("BroadcomCrystalHD::chd_create_device didn't initialize\n");
            io_return = kIOReturnNoMemory;
            break;
        }

        bzero(g_bcm_adapter,sizeof(*g_bcm_adapter));
        bzero(m_DEVs, m_LastMinor * sizeof(m_DEVs[0]));
        IOLockInit(m_bds_lock);
        m_Major = cdevsw_add(-1, &m_devsw);
        if (m_Major == (unsigned int)-1) {
            IOLog("BroadcomCrystalHD::cdevsw_add failed\n");
            io_return = kIOReturnNoDevice;
            break;
        }

        m_base_dev = bsd_create_node();
        if (m_base_dev == (dev_t)-1) {
            IOLog("BroadcomCrystalHD::bsd_create_node failed\n");
            io_return = kIOReturnNoDevice;
            break;
        }

        m_cdev_node = devfs_make_node(m_base_dev, DEVFS_CHAR, UID_ROOT, GID_WHEEL, 0666, "crystalhd");
        if (!m_cdev_node) {
            IOLog("BroadcomCrystalHD::devfs_make_node failed");
            io_return = kIOReturnNoDevice;
            break;
        }

        // FIXME
        if (!bsd_register_node(m_base_dev, this)) {
            IOLog("BroadcomCrystalHD::bsd_register failed\n");
            //io_return = kIOReturnNoDevice;
            //break;
        }
    } while (0);

    return(io_return);
}
//-------------------------------------------------------------------------------
IOReturn
BroadcomCrystalHD::bsd_destroy_device(void)
{
    //IOLog("BroadcomCrystalHD::bsd_destroy_device\n");

    if (m_cdev_node) {
        //IOLog("BroadcomCrystalHD::devfs_remove\n");
        devfs_remove(m_cdev_node);
    }
    if (m_base_dev != (dev_t)-1) {
        //IOLog("BroadcomCrystalHD::bsd_register NULL\n");
        bsd_register_node(m_base_dev, NULL);
    }

    SAFE_RELEASE(m_Names);
    if (m_Major != (unsigned int)-1) {
        //IOLog("BroadcomCrystalHD::cdevsw_remove\n");
        cdevsw_remove(m_Major, &m_devsw);
    }
    if (m_DEVs) {
        //IOLog("BroadcomCrystalHD::IOFree m_DEVs\n");
        IOFree(m_DEVs, m_LastMinor * sizeof(m_DEVs[0]));
    }
    if (g_bcm_adapter) {
        //IOLog("BroadcomCrystalHD::IOFree m_adapter\n");
        IOFree(g_bcm_adapter, sizeof(*g_bcm_adapter));
    }
    if (m_bds_lock) {
        IOLockFree(m_bds_lock);
    }
      
    return(kIOReturnSuccess);
}
//-------------------------------------------------------------------------------
dev_t BroadcomCrystalHD::bsd_create_node(void)
{
    unsigned int i;

    //IOLog("BroadcomCrystalHD::bsd_create_node\n");
    IOTakeLock(m_bds_lock);

    for (i = 0; i < m_LastMinor && m_DEVs[i]; i++)
        ;

    if (i == m_LastMinor) {
        unsigned int newLastMinor = m_LastMinor + 4;
        BroadcomCrystalHD **newDEVs;

        newDEVs = (BroadcomCrystalHD**)IOMalloc(newLastMinor * sizeof(m_DEVs[0]));
        if (!newDEVs) {
            IOUnlock(m_bds_lock);
            return (dev_t)-1;
        }

        bzero(&newDEVs[m_LastMinor], 4 * sizeof(m_DEVs[0]));
        bcopy(m_DEVs, newDEVs, m_LastMinor * sizeof(m_DEVs[0]));
        IOFree(m_DEVs, m_LastMinor * sizeof(m_DEVs[0]));
        m_LastMinor = newLastMinor;
        m_DEVs = newDEVs;
    }

    dev_t dev = makedev(m_Major, i << DEV_NUM_FLAGS);
    m_DEVs[i] = (BroadcomCrystalHD*)-1;

    IOUnlock(m_bds_lock);

    return dev;
}
//-------------------------------------------------------------------------------
bool 
BroadcomCrystalHD::bsd_register_node(dev_t dev, BroadcomCrystalHD *kext)
{
    bool ret = false;
    unsigned int i = DEV_UNIT(dev);

    //IOLog("BroadcomCrystalHD::bsd_register_node\n");

    IOTakeLock(m_bds_lock);

    assert(i < m_LastMinor);
    if (i < m_LastMinor) {
        assert(!kext || fDEVs[i] != (BroadcomCrystalHD*) -1);
        if (kext && m_DEVs[i] == (BroadcomCrystalHD*) -1) {
            m_DEVs[i] = kext;
            ret = true;
        }
    }

    IOUnlock(m_bds_lock);

    return ret;
}
//-------------------------------------------------------------------------------
BroadcomCrystalHD*
BroadcomCrystalHD::bsd_get_device(dev_t dev)
{
    return m_DEVs[DEV_UNIT(dev)];
}

//-------------------------------------------------------------------------------
//-------------------------------------------------------------------------------
int
bsd_open(dev_t dev, int flags, int devtype, struct proc *p)
{
    struct crystalhd_adp	*adp = g_bcm_adapter;
    BC_STATUS             sts = BC_STS_SUCCESS;
    struct crystalhd_user	*uc = NULL;
    int                   rc = 0;

    if(!adp) {
        BCMLOG_ERR("Invalid adp \n");
        rc = -1;
        goto exitOpen;
    }
    if (adp->cfg_users >= BC_LINK_MAX_OPENS) {
        BCMLOG(BCMLOG_INFO,"Already in use.%d\n", adp->cfg_users);
        rc = -EBUSY;
        goto exitOpen;
    }

    if ( (sts = crystalhd_user_open(&adp->cmds, &uc)) != BC_STS_SUCCESS) {
        BCMLOG_ERR("cmd_user_open - %d \n", sts);
        rc = -EBUSY;
        goto exitOpen;
    }

    bsd_add_user(dev, proc_pid(p), uc);
    adp->cfg_users++;

    //BCMLOG(BCMLOG_INFO,"BroadcomCrystalHD opened\n");
exitOpen:
    return rc;
}

//-------------------------------------------------------------------------------
int
bsd_close(dev_t dev, int flags, int devtype, struct proc *p)
{
    struct crystalhd_adp	*adp = g_bcm_adapter;
    struct crystalhd_user *uc=NULL;

    if (!adp) {
        BCMLOG_ERR("Invalid adp \n");
        return -1;
    }

    if ( !(uc = bsd_get_user(dev, proc_pid(p) )) ) {
        BCMLOG_ERR("Failed to get uc\n");
        return -1;
    }

    crystalhd_user_close(&adp->cmds, uc);

    bsd_del_user(dev, proc_pid(p), uc);
    adp->cfg_users--;

    //BCMLOG(BCMLOG_INFO,"BroadcomCrystalHD closed\n");
    return 0;
}

//-------------------------------------------------------------------------------
int
bsd_ioctl(dev_t dev, u_long cmd, caddr_t data, int fflag, struct proc *p)
{
    // @param   Dev         The device number (major+minor).
    // @param   cmd         The IOCtl command.
    // @param   data        Pointer to the data (if any it's a SUPDRVIOCTLDATA (kernel copy)).
    // @param   fflag       Flag saying we're a character device (like we didn't know already).
    // @param   p           The process issuing this request.
    struct crystalhd_adp	*adp = g_bcm_adapter;
    crystalhd_cmd_proc    cproc = NULL;
    struct crystalhd_user	*uc = NULL;
    user_addr_t           arg = NULL;
    int                   error = -1;
    
    if (!adp) {
        BCMLOG_ERR("Invalid adp \n");
        error = EINVAL;
        goto exitIoctl;
    }
    if ( !(uc = (struct crystalhd_user*)bsd_get_user( dev, proc_pid(p) )) ) {
        BCMLOG_ERR("Failed to get uc\n");
        error = -1;
        goto exitIoctl;
    }
    if (!(cproc = crystalhd_get_cmd_proc(&adp->cmds, cmd, uc))) {
        BCMLOG_ERR("Unhandled command: %d \n", (int)cmd);
        error = EINVAL;
        goto exitIoctl;
    }

    if (data) {
        BC_IOCTL_ARG *tmp = (BC_IOCTL_ARG*)data;
        arg = tmp->user_address;
        //BCMLOG_ERR("DtsDrvCmd:ioctl 0x%x 0x%llX\n", (unsigned int)cmd, arg);
    }
    
    error = chd_dec_api_cmd(adp, arg, uc->uid, cmd, cproc);

exitIoctl:
    return error;
}

//-------------------------------------------------------------------------------
//-------------------------------------------------------------------------------
//-------------------------------------------------------------------------------
void
bsd_add_user(dev_t dev, int pid, struct crystalhd_user* uc)
{
    g_bcm_USER = uc;
    // FIXME
    //fUSERs[DEV_UNIT(dev)] = uc;
}
//-------------------------------------------------------------------------------
void
bsd_del_user(dev_t dev, int pid, struct crystalhd_user* uc)
{
    // FIXME
    g_bcm_USER = NULL;
}
//-------------------------------------------------------------------------------
struct crystalhd_user*
bsd_get_user(dev_t dev, int pid)
{
    // FIXME
    return g_bcm_USER;
}
