//  linux_compatible.h
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

#ifndef _LINUX_COMPATIBLE_H_
#define _LINUX_COMPATIBLE_H_

#include <IOKit/IOLib.h>
#include <IOKit/IOBufferMemoryDescriptor.h>

typedef unsigned char      u8;
typedef unsigned short    u16;
typedef unsigned int      u32;

typedef IOPhysicalAddress dma_addr_t;
typedef uint32_t          wait_queue_head_t;
typedef IOLock            *spinlock_t;
typedef uint32_t          gfp_t;
#define GFP_KERNEL 1
#define GFP_ATOMIC 1
#define printk IOLog

enum dma_data_direction {
  READ = 1,
  WRITE = 2,
	DMA_TO_DEVICE = 1,
	DMA_FROM_DEVICE = 2,
};

struct scatterlist {
  unsigned int    length;
  uint32_t        dma_address;
  unsigned int    dma_length;
};

// spinlock defs, note that we don't want to diddle the interrupt under OSX
// so fake it.
#define alloc_spin_lock(_lock)  \
do{                       \
  _lock = IOLockAlloc();  \
}while(0)

#define free_spin_lock(_lock)   \
do{                       \
	IOLockFree(_lock);      \
	_lock = NULL;           \
}while(0)

#define spin_lock_irqsave(_lock,_flags)   \
do{                       \
	_flags = 1;             \
	IOLockLock(*_lock);     \
}while(0)

#define spin_unlock_irqrestore(_lock,_flags) \
do{                       \
  IOLockUnlock(*_lock);   \
	_flags = 0;             \
}while(0)

// FIXME: convert to inlines or defines later
void udelay(unsigned int microseconds);
unsigned long msleep_interruptible(unsigned int msecs);

// FIXME: convert to inlines or defines later
unsigned long readl(IOVirtualAddress addr);
void writel(unsigned long value, IOVirtualAddress addr);

// FIXME: convert to inlines or defines later
int pci_read_config_byte(  void *dev, uint8_t off,  u8 *val);
int pci_read_config_word(  void *dev, uint8_t off, u16 *val);
int pci_read_config_dword( void *dev, uint8_t off, u32 *val);
int pci_write_config_byte( void *dev, uint8_t off,  u8  val);
int pci_write_config_word( void *dev, uint8_t off, u16  val);
int pci_write_config_dword(void *dev, uint8_t off, u32  val);

struct pci_pool {
  IOBufferMemoryDescriptor  *memory;
  void                      *freeStart;
  uint32_t                  freeBytes;
  uint32_t                  chunk_size;
  uint32_t                  chunk_align;
};
struct pci_pool* pci_pool_create(const char *name, void *pdev, size_t size, size_t align, int flags);
void* pci_pool_alloc(struct pci_pool *pool, int mem_flags, dma_addr_t * handle);
void pci_pool_free(struct pci_pool *pool, void *vaddr, dma_addr_t dma);
void pci_pool_destroy(struct pci_pool *pool);

void *pci_alloc_consistent(void *pdev, size_t size, dma_addr_t *dma_handle);
void pci_free_consistent(void *pdev, size_t size, void *vaddr, dma_addr_t dma_handle);

// FIXME: convert to inlines or defines later
void* kzalloc(size_t size, gfp_t flags);
void* kalloc(size_t size, gfp_t flags);
void kfree(void *addr);

// FIXME: convert to inlines or defines later
void* vmalloc(size_t size);
void vfree(void *addr);

#endif