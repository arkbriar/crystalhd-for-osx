/***************************************************************************
 * Copyright (c) 2005-2009, Broadcom Corporation.
 *
 *  Name: crystalhd_hw . c
 *
 *  Description:
 *		BCM70010 Linux driver HW layer.
 *
 **********************************************************************
 * This file is part of the crystalhd device driver.
 *
 * This driver is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, version 2 of the License.
 *
 * This driver is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this driver.  If not, see <http://www.gnu.org/licenses/>.
 **********************************************************************/

#ifndef __APPLE__
#include <linux/pci.h>
#include <linux/delay.h>
#include <linux/device.h>
#include <asm/tsc.h>
#endif
#include "crystalhd_lnx.h"

#define OFFSETOF(_s_, _m_) ((size_t)(unsigned long)&(((_s_ *)0)->_m_))

crystalhd_rx_dma_pkt *crystalhd_hw_alloc_rx_pkt(struct crystalhd_hw *hw)
{
	unsigned long flags = 0;
	crystalhd_rx_dma_pkt *temp = NULL;

	if (!hw)
		return NULL;

	spin_lock_irqsave(&hw->lock, flags);
	temp = hw->rx_pkt_pool_head;
	if (temp) {
		hw->rx_pkt_pool_head = hw->rx_pkt_pool_head->next;
		temp->dio_req = NULL;
		temp->pkt_tag = 0;
		temp->flags = 0;
	}
	spin_unlock_irqrestore(&hw->lock, flags);

	return temp;
}

void crystalhd_hw_free_rx_pkt(struct crystalhd_hw *hw,
				   crystalhd_rx_dma_pkt *pkt)
{
	unsigned long flags = 0;

	if (!hw || !pkt)
		return;

	spin_lock_irqsave(&hw->lock, flags);
	pkt->next = hw->rx_pkt_pool_head;
	hw->rx_pkt_pool_head = pkt;
	spin_unlock_irqrestore(&hw->lock, flags);
}

/*
 * Call back from TX - IOQ deletion.
 *
 * This routine will release the TX DMA rings allocated
 * druing setup_dma rings interface.
 *
 * Memory is allocated per DMA ring basis. This is just
 * a place holder to be able to create the dio queues.
 */
void crystalhd_tx_desc_rel_call_back(void *context, void *data)
{
}

/*
 * Rx Packet release callback..
 *
 * Release All user mapped capture buffers and Our DMA packets
 * back to our free pool. The actual cleanup of the DMA
 * ring descriptors happen during dma ring release.
 */
void crystalhd_rx_pkt_rel_call_back(void *context, void *data)
{
	struct crystalhd_hw *hw = (struct crystalhd_hw *)context;
	crystalhd_rx_dma_pkt *pkt = (crystalhd_rx_dma_pkt *)data;

	if (!pkt || !hw) {
		printk(KERN_ERR "%s: Invalid arg - %p %p\n", __func__, hw, pkt);
		return;
	}

	if (pkt->dio_req)
		crystalhd_unmap_dio(hw->adp, pkt->dio_req);

	crystalhd_hw_free_rx_pkt(hw, pkt);
}

#define crystalhd_hw_delete_ioq(adp, q)		\
	if (q) {				\
		crystalhd_delete_dioq(adp, q);	\
		q = NULL;			\
	}

void crystalhd_hw_delete_ioqs(struct crystalhd_hw *hw)
{
	if (!hw)
		return;

	crystalhd_hw_delete_ioq(hw->adp, hw->tx_actq);
	crystalhd_hw_delete_ioq(hw->adp, hw->tx_freeq);
	crystalhd_hw_delete_ioq(hw->adp, hw->rx_actq);
	crystalhd_hw_delete_ioq(hw->adp, hw->rx_freeq);
	crystalhd_hw_delete_ioq(hw->adp, hw->rx_rdyq);
}

#define crystalhd_hw_create_ioq(sts, hw, q, cb)			\
do {								\
	sts = crystalhd_create_dioq(hw->adp, &q, cb, hw);	\
	if (sts != BC_STS_SUCCESS)				\
		goto hw_create_ioq_err;				\
} while (0)

/*
 * Create IOQs..
 *
 * TX - Active & Free
 * RX - Active, Ready and Free.
 */
BC_STATUS crystalhd_hw_create_ioqs(struct crystalhd_hw *hw)
{
	BC_STATUS   sts = BC_STS_SUCCESS;

	if (!hw) {
		printk(KERN_ERR "%s: Invalid Arg!!\n", __func__);
		return BC_STS_INV_ARG;
	}

	crystalhd_hw_create_ioq(sts, hw, hw->tx_freeq,
			      crystalhd_tx_desc_rel_call_back);
	crystalhd_hw_create_ioq(sts, hw, hw->tx_actq,
			      crystalhd_tx_desc_rel_call_back);

	crystalhd_hw_create_ioq(sts, hw, hw->rx_freeq,
			      crystalhd_rx_pkt_rel_call_back);
	crystalhd_hw_create_ioq(sts, hw, hw->rx_rdyq,
			      crystalhd_rx_pkt_rel_call_back);
	crystalhd_hw_create_ioq(sts, hw, hw->rx_actq,
			      crystalhd_rx_pkt_rel_call_back);

	return sts;

hw_create_ioq_err:
	crystalhd_hw_delete_ioqs(hw);

	return sts;
}

BC_STATUS crystalhd_hw_open(struct crystalhd_hw *hw, struct crystalhd_adp *adp)
{
	if (!hw || !adp) {
		printk(KERN_ERR "%s: Invalid Arguments\n", __func__);
		return BC_STS_INV_ARG;
	}

	printk("opening HW\n");
	if (hw->dev_started)
		return BC_STS_SUCCESS;

	// Setup HW specific functions appropriately
	
	if (adp->pdev->device == BC_PCI_DEVID_FLEA) {
		
		/*
		pHWExt->HwPrivFuncs.pfnNotifyFLLChange = HWFleaNotifyFllChange;
		pHWExt->HwPrivFuncs.pfnFireRx = HwFleaFireRx;
		pHWExt->HwPrivFuncs.pfnPostProcessPicture = HwFleaPostProcessPicture;
		pHWExt->HwPrivFuncs.pfnIssuePause = HwFleaIssuePause;
		*/
	} else {
		printk("setting up functions\n");
		hw->pfnStartDevice = crystalhd_link_start_device;
		hw->pfnStopDevice = crystalhd_link_stop_device;
		hw->pfnPostRxSideBuff = crystalhd_link_hw_post_cap_buff;
		hw->pfnHWGetDoneSize = crystalhd_link_get_dnsz;
		hw->pfnReadDevRegister = link_dec_reg_rd;
		hw->pfnReadFPGARegister = crystalhd_link_reg_rd;
		hw->pfnWriteFPGARegister = crystalhd_link_reg_wr;
		hw->pfnWriteDevRegister = link_dec_reg_wr;
		hw->pfnCheckInputFIFO = crystalhd_link_check_input_full;
		hw->pfnDevDRAMRead = crystalhd_link_mem_rd;
		hw->pfnDevDRAMWrite = crystalhd_link_mem_wr;
		hw->pfnDoFirmwareCmd = crystalhd_link_do_fw_cmd;
		hw->pfnFWDwnld = crystalhd_link_download_fw;
		hw->pfnHWGetDoneSize = crystalhd_link_get_dnsz;
		hw->pfnIssuePause = crystalhd_link_hw_pause;
		hw->pfnPeekNextDeodedFr = crystalhd_link_peek_next_decoded_frame;
		hw->pfnPostRxSideBuff = crystalhd_link_hw_post_cap_buff;
		hw->pfnStartTxDMA = crystalhd_link_start_tx_dma_engine;
		hw->pfnStopRXDMAEngines = crystalhd_link_stop_rx_dma_engine;
		hw->pfnStopTxDMA = crystalhd_link_stop_tx_dma_engine;
	}
				
	hw->adp = adp;
	spin_lock_init(&hw->lock);
	spin_lock_init(&hw->rx_lock);
	/* FIXME: jarod: what are these magic numbers?!? */
	hw->tx_ioq_tag_seed = 0x70023070;
	hw->rx_pkt_tag_seed = 0x70029070;

	hw->stop_pending = 0;
	hw->pfnStartDevice(hw);
	hw->dev_started = true;

	return BC_STS_SUCCESS;
}

BC_STATUS crystalhd_hw_close(struct crystalhd_hw *hw)
{
	if (!hw) {
		printk(KERN_ERR "%s: Invalid Arguments\n", __func__);
		return BC_STS_SUCCESS;
	}
	printk("Closing HW\n");
	if (!hw->dev_started)
		return BC_STS_SUCCESS;

	/* Stop and DDR sleep will happen in here */
	crystalhd_hw_suspend(hw);
#ifdef __APPLE__
	free_spin_lock(&hw->lock);
	free_spin_lock(&hw->rx_lock);
#endif
	hw->dev_started = false;

	return BC_STS_SUCCESS;
}

BC_STATUS crystalhd_hw_setup_dma_rings(struct crystalhd_hw *hw)
{
	struct device *dev;
	unsigned int i;
	void *mem;
	size_t mem_len;
	dma_addr_t phy_addr;
	BC_STATUS sts = BC_STS_SUCCESS;
	crystalhd_rx_dma_pkt *rpkt;

	if (!hw || !hw->adp) {
		printk(KERN_ERR "%s: Invalid Arguments\n", __func__);
		return BC_STS_INV_ARG;
	}

	dev = &hw->adp->pdev->dev;

	sts = crystalhd_hw_create_ioqs(hw);
	if (sts != BC_STS_SUCCESS) {
		dev_err(dev, "Failed to create IOQs..\n");
		return sts;
	}

	mem_len = BC_LINK_MAX_SGLS * sizeof(dma_descriptor);

	for (i = 0; i < BC_TX_LIST_CNT; i++) {
		mem = bc_kern_dma_alloc(hw->adp, mem_len, &phy_addr);
		if (mem) {
			memset(mem, 0, mem_len);
		} else {
			dev_err(dev, "Insufficient Memory For TX\n");
			crystalhd_hw_free_dma_rings(hw);
			return BC_STS_INSUFF_RES;
		}
		/* rx_pkt_pool -- static memory allocation  */
#ifndef __APPLE__
		hw->tx_pkt_pool[i].desc_mem.pdma_desc_start = mem;
#else
		hw->tx_pkt_pool[i].desc_mem.pdma_desc_start = (dma_descriptor*)mem;
#endif
		hw->tx_pkt_pool[i].desc_mem.phy_addr = phy_addr;
		hw->tx_pkt_pool[i].desc_mem.sz = BC_LINK_MAX_SGLS *
						 sizeof(dma_descriptor);
		hw->tx_pkt_pool[i].list_tag = 0;

		/* Add TX dma requests to Free Queue..*/
		sts = crystalhd_dioq_add(hw->tx_freeq,
				       &hw->tx_pkt_pool[i], false, 0);
		if (sts != BC_STS_SUCCESS) {
			crystalhd_hw_free_dma_rings(hw);
			return sts;
		}
	}

	for (i = 0; i < BC_RX_LIST_CNT; i++) {
#ifndef __APPLE__
		rpkt = kzalloc(sizeof(*rpkt), GFP_KERNEL);
#else
		rpkt = (crystalhd_rx_dma_pkt*)kzalloc(sizeof(*rpkt), GFP_KERNEL);
#endif
		if (!rpkt) {
			dev_err(dev, "Insufficient Memory For RX\n");
			crystalhd_hw_free_dma_rings(hw);
			return BC_STS_INSUFF_RES;
		}

		mem = bc_kern_dma_alloc(hw->adp, mem_len, &phy_addr);
		if (mem) {
			memset(mem, 0, mem_len);
		} else {
			dev_err(dev, "Insufficient Memory For RX\n");
			crystalhd_hw_free_dma_rings(hw);
			return BC_STS_INSUFF_RES;
		}
#ifndef __APPLE__
		rpkt->desc_mem.pdma_desc_start = mem;
#else
		rpkt->desc_mem.pdma_desc_start = (dma_descriptor*)mem;
#endif
		rpkt->desc_mem.phy_addr = phy_addr;
		rpkt->desc_mem.sz  = BC_LINK_MAX_SGLS * sizeof(dma_descriptor);
		rpkt->pkt_tag = hw->rx_pkt_tag_seed + i;
		crystalhd_hw_free_rx_pkt(hw, rpkt);
	}

	return BC_STS_SUCCESS;
}

BC_STATUS crystalhd_hw_free_dma_rings(struct crystalhd_hw *hw)
{
	unsigned int i;
	crystalhd_rx_dma_pkt *rpkt = NULL;

	if (!hw || !hw->adp) {
		printk(KERN_ERR "%s: Invalid Arguments\n", __func__);
		return BC_STS_INV_ARG;
	}

	/* Delete all IOQs.. */
	crystalhd_hw_delete_ioqs(hw);

	for (i = 0; i < BC_TX_LIST_CNT; i++) {
		if (hw->tx_pkt_pool[i].desc_mem.pdma_desc_start) {
			bc_kern_dma_free(hw->adp,
				hw->tx_pkt_pool[i].desc_mem.sz,
				hw->tx_pkt_pool[i].desc_mem.pdma_desc_start,
				hw->tx_pkt_pool[i].desc_mem.phy_addr);

			hw->tx_pkt_pool[i].desc_mem.pdma_desc_start = NULL;
		}
	}

	dev_dbg(&hw->adp->pdev->dev, "Releasing RX Pkt pool\n");
	do {
		rpkt = crystalhd_hw_alloc_rx_pkt(hw);
		if (!rpkt)
			break;
		bc_kern_dma_free(hw->adp, rpkt->desc_mem.sz,
				 rpkt->desc_mem.pdma_desc_start,
				 rpkt->desc_mem.phy_addr);
		kfree(rpkt);
	} while (rpkt);

	return BC_STS_SUCCESS;
}

BC_STATUS crystalhd_hw_tx_req_complete(struct crystalhd_hw *hw,
											  uint32_t list_id, BC_STATUS cs)
{
	tx_dma_pkt *tx_req;

	if (!hw || !list_id) {
		printk(KERN_ERR "%s: Invalid Arg!!\n", __func__);
		return BC_STS_INV_ARG;
	}

	tx_req = (tx_dma_pkt *)crystalhd_dioq_find_and_fetch(hw->tx_actq, list_id);
	if (!tx_req) {
		if (cs != BC_STS_IO_USER_ABORT)
			dev_err(&hw->adp->pdev->dev, "Find/Fetch: no req!\n");
		return BC_STS_NO_DATA;
	}

	if (tx_req->call_back) {
		tx_req->call_back(tx_req->dio_req, tx_req->cb_event, cs);
		tx_req->dio_req   = NULL;
		tx_req->cb_event  = NULL;
		tx_req->call_back = NULL;
	} else {
		dev_dbg(&hw->adp->pdev->dev, "Missing Tx Callback - %X\n",
		tx_req->list_tag);
	}

	/* Now put back the tx_list back in FreeQ */
	tx_req->list_tag = 0;

	return crystalhd_dioq_add(hw->tx_freeq, tx_req, false, 0);
}

BC_STATUS crystalhd_hw_fill_desc(crystalhd_dio_req *ioreq,
										dma_descriptor *desc,
										dma_addr_t desc_paddr_base,
										uint32_t sg_cnt, uint32_t sg_st_ix,
										uint32_t sg_st_off, uint32_t xfr_sz,
										struct device *dev)
{
	uint32_t count = 0, ix = 0, sg_ix = 0, len = 0, last_desc_ix = 0;
	dma_addr_t desc_phy_addr = desc_paddr_base;
	addr_64 addr_temp;

	if (!ioreq || !desc || !desc_paddr_base || !xfr_sz ||
		(!sg_cnt && !ioreq->uinfo.dir_tx)) {
		dev_err(dev, "%s: Invalid Args\n", __func__);
	return BC_STS_INV_ARG;
	}

	for (ix = 0; ix < sg_cnt; ix++) {

		/* Setup SGLE index. */
		sg_ix = ix + sg_st_ix;

		/* Get SGLE length */
		len = crystalhd_get_sgle_len(ioreq, sg_ix);
		if (len % 4) {
			dev_err(dev, "unsupported len in sg %d %d %d\n",
			len, sg_ix, sg_cnt);
			return BC_STS_NOT_IMPL;
		}
		/* Setup DMA desc with Phy addr & Length at current index. */
		addr_temp.full_addr = crystalhd_get_sgle_paddr(ioreq, sg_ix);
		if (sg_ix == sg_st_ix) {
			addr_temp.full_addr += sg_st_off;
			len -= sg_st_off;
		}
		memset(&desc[ix], 0, sizeof(desc[ix]));
		desc[ix].buff_addr_low  = addr_temp.low_part;
		desc[ix].buff_addr_high = addr_temp.high_part;
		desc[ix].dma_dir        = ioreq->uinfo.dir_tx;

		/* Chain DMA descriptor.  */
		addr_temp.full_addr = desc_phy_addr + sizeof(dma_descriptor);
		desc[ix].next_desc_addr_low = addr_temp.low_part;
		desc[ix].next_desc_addr_high = addr_temp.high_part;

		if ((count + len) > xfr_sz)
			len = xfr_sz - count;

		/* Debug.. */
		if ((!len) || (len > crystalhd_get_sgle_len(ioreq, sg_ix))) {
			dev_err(dev, "inv-len(%x) Ix(%d) count:%x xfr_sz:%x "
			"sg_cnt:%d\n", len, ix, count, xfr_sz, sg_cnt);
			return BC_STS_ERROR;
		}
		/* Length expects Multiple of 4 */
		desc[ix].xfer_size = (len / 4);

		count += len;
		desc_phy_addr += sizeof(dma_descriptor);
	}

	last_desc_ix = ix - 1;

	if (ioreq->fb_size) {
		memset(&desc[ix], 0, sizeof(desc[ix]));
		addr_temp.full_addr     = ioreq->fb_pa;
		desc[ix].buff_addr_low  = addr_temp.low_part;
		desc[ix].buff_addr_high = addr_temp.high_part;
		desc[ix].dma_dir        = ioreq->uinfo.dir_tx;
		desc[ix].xfer_size	= 1;
		desc[ix].fill_bytes	= 4 - ioreq->fb_size;
		count += ioreq->fb_size;
		last_desc_ix++;
	}

	/* setup last descriptor..*/
	desc[last_desc_ix].last_rec_indicator  = 1;
	desc[last_desc_ix].next_desc_addr_low  = 0;
	desc[last_desc_ix].next_desc_addr_high = 0;
	desc[last_desc_ix].intr_enable = 1;

	if (count != xfr_sz) {
		dev_err(dev, "interal error sz curr:%x exp:%x\n",
		count, xfr_sz);
		return BC_STS_ERROR;
	}

	return BC_STS_SUCCESS;
}
										
BC_STATUS crystalhd_xlat_sgl_to_dma_desc(crystalhd_dio_req *ioreq,
												pdma_desc_mem pdesc_mem,
												uint32_t *uv_desc_index,
												struct device *dev)
{
	dma_descriptor *desc = NULL;
	dma_addr_t desc_paddr_base = 0;
	uint32_t sg_cnt = 0, sg_st_ix = 0, sg_st_off = 0;
	uint32_t xfr_sz = 0;
	BC_STATUS sts = BC_STS_SUCCESS;

	/* Check params.. */
	if (!ioreq || !pdesc_mem || !uv_desc_index) {
		dev_err(dev, "%s: Invalid Args\n", __func__);
		return BC_STS_INV_ARG;
	}

	if (!pdesc_mem->sz || !pdesc_mem->pdma_desc_start ||
		!ioreq->sg || (!ioreq->sg_cnt && !ioreq->uinfo.dir_tx)) {
		dev_err(dev, "%s: Invalid Args\n", __func__);
	return BC_STS_INV_ARG;
	}

	if ((ioreq->uinfo.dir_tx) && (ioreq->uinfo.uv_offset)) {
		dev_err(dev, "%s: UV offset for TX??\n", __func__);
		return BC_STS_INV_ARG;

	}

	desc = pdesc_mem->pdma_desc_start;
	desc_paddr_base = pdesc_mem->phy_addr;

	if (ioreq->uinfo.dir_tx || (ioreq->uinfo.uv_offset == 0)) {
		sg_cnt = ioreq->sg_cnt;
		xfr_sz = ioreq->uinfo.xfr_len;
	} else {
		sg_cnt = ioreq->uinfo.uv_sg_ix + 1;
		xfr_sz = ioreq->uinfo.uv_offset;
	}

	sts = crystalhd_hw_fill_desc(ioreq, desc, desc_paddr_base, sg_cnt,
									sg_st_ix, sg_st_off, xfr_sz, dev);

	if ((sts != BC_STS_SUCCESS) || !ioreq->uinfo.uv_offset)
		return sts;

	/* Prepare for UV mapping.. */
	desc = &pdesc_mem->pdma_desc_start[sg_cnt];
	desc_paddr_base = pdesc_mem->phy_addr +
	(sg_cnt * sizeof(dma_descriptor));

	/* Done with desc addr.. now update sg stuff.*/
	sg_cnt    = ioreq->sg_cnt - ioreq->uinfo.uv_sg_ix;
	xfr_sz    = ioreq->uinfo.xfr_len - ioreq->uinfo.uv_offset;
	sg_st_ix  = ioreq->uinfo.uv_sg_ix;
	sg_st_off = ioreq->uinfo.uv_sg_off;

	sts = crystalhd_hw_fill_desc(ioreq, desc, desc_paddr_base, sg_cnt,
								sg_st_ix, sg_st_off, xfr_sz, dev);
	if (sts != BC_STS_SUCCESS)
		return sts;

	*uv_desc_index = sg_st_ix;

	return sts;
}

BC_STATUS crystalhd_rx_pkt_done(struct crystalhd_hw *hw,
									   uint32_t list_index,
									   BC_STATUS comp_sts)
{
	crystalhd_rx_dma_pkt *rx_pkt = NULL;
	uint32_t y_dw_dnsz, uv_dw_dnsz;
	BC_STATUS sts = BC_STS_SUCCESS;

	if (!hw || list_index >= DMA_ENGINE_CNT) {
		printk(KERN_ERR "%s: Invalid Arguments\n", __func__);
		return BC_STS_INV_ARG;
	}
#ifndef __APPLE__
	rx_pkt = crystalhd_dioq_find_and_fetch(hw->rx_actq,
#else
	rx_pkt = (crystalhd_rx_dma_pkt*)crystalhd_dioq_find_and_fetch(hw->rx_actq,
#endif
	hw->rx_pkt_tag_seed + list_index);
	if (!rx_pkt) {
		dev_err(&hw->adp->pdev->dev, "Act-Q: PostIx:%x L0Sts:%x "
		"L1Sts:%x current L:%x tag:%x comp:%x\n",
				hw->rx_list_post_index, hw->rx_list_sts[0],
				hw->rx_list_sts[1], list_index,
				hw->rx_pkt_tag_seed + list_index, comp_sts);
				return BC_STS_INV_ARG;
	}

	if (comp_sts == BC_STS_SUCCESS) {
		hw->pfnHWGetDoneSize(hw, list_index, &y_dw_dnsz, &uv_dw_dnsz);
		rx_pkt->dio_req->uinfo.y_done_sz = y_dw_dnsz;
		rx_pkt->flags = COMP_FLAG_DATA_VALID;
		if (rx_pkt->uv_phy_addr)
			rx_pkt->dio_req->uinfo.uv_done_sz = uv_dw_dnsz;
		crystalhd_dioq_add(hw->rx_rdyq, rx_pkt, true,
							hw->rx_pkt_tag_seed + list_index);
		if(crystalhd_dioq_count(hw->rx_rdyq) > HW_PAUSE_THRESHOLD)
		{
			dev_info(&hw->adp->pdev->dev, "HW PAUSE\n");
			hw->pfnIssuePause(hw, true);
			hw->hw_pause_issued = true;
		}
		return sts;
	}
	/* Check if we can post this DIO again. */
	return hw->pfnPostRxSideBuff(hw, rx_pkt);
}

BC_STATUS crystalhd_hw_post_tx(struct crystalhd_hw *hw, crystalhd_dio_req *ioreq,
			     hw_comp_callback call_back,
			     wait_queue_head_t *cb_event, uint32_t *list_id,
			     uint8_t data_flags)
{
	struct device *dev;
	tx_dma_pkt *tx_dma_packet = NULL;
	uint32_t low_addr, high_addr;
	addr_64 desc_addr;
	BC_STATUS sts, add_sts;
	uint32_t dummy_index = 0;
	unsigned long flags;
	uint8_t list_posted;
	bool rc;

	if (!hw || !ioreq || !call_back || !cb_event || !list_id) {
		printk(KERN_ERR "%s: Invalid Arguments\n", __func__);
		return BC_STS_INV_ARG;
	}

	dev = &hw->adp->pdev->dev;

	/*
	 * Since we hit code in busy condition very frequently,
	 * we will check the code in status first before
	 * checking the availability of free elem.
	 *
	 * This will avoid the Q fetch/add in normal condition.
	 */
	rc = hw->pfnCheckInputFIFO(hw, ioreq->uinfo.xfr_len,
					   &dummy_index, false, data_flags);
	if (rc) {
		hw->stats.cin_busy++;
		return BC_STS_BUSY;
	}

	/* Get a list from TxFreeQ */
	tx_dma_packet = (tx_dma_pkt *)crystalhd_dioq_fetch(hw->tx_freeq);
	if (!tx_dma_packet) {
		dev_err(dev, "No empty elements..\n");
		return BC_STS_ERR_USAGE;
	}

	sts = crystalhd_xlat_sgl_to_dma_desc(ioreq,
					     &tx_dma_packet->desc_mem,
					     &dummy_index, dev);
	if (sts != BC_STS_SUCCESS) {
		add_sts = crystalhd_dioq_add(hw->tx_freeq, tx_dma_packet,
					   false, 0);
		if (add_sts != BC_STS_SUCCESS)
			dev_err(dev, "double fault..\n");

		return sts;
	}

	desc_addr.full_addr = tx_dma_packet->desc_mem.phy_addr;
	low_addr = desc_addr.low_part;
	high_addr = desc_addr.high_part;

	tx_dma_packet->call_back = call_back;
	tx_dma_packet->cb_event  = cb_event;
	tx_dma_packet->dio_req   = ioreq;

	spin_lock_irqsave(&hw->lock, flags);

	list_posted = hw->tx_list_post_index;

	*list_id = tx_dma_packet->list_tag = hw->tx_ioq_tag_seed +
					     hw->tx_list_post_index;

	hw->tx_list_post_index = (hw->tx_list_post_index + 1) % DMA_ENGINE_CNT;

	spin_unlock_irqrestore(&hw->lock, flags);


	/* Insert in Active Q..*/
	crystalhd_dioq_add(hw->tx_actq, tx_dma_packet, false,
			 tx_dma_packet->list_tag);

	/*
	 * Interrupt will come as soon as you write
	 * the valid bit. So be ready for that. All
	 * the initialization should happen before that.
	 */
	hw->pfnStartTxDMA(hw, list_posted, desc_addr);

	return BC_STS_SUCCESS;
}

/*
 * This is a force cancel and we are racing with ISR.
 *
 * Will try to remove the req from ActQ before ISR gets it.
 * If ISR gets it first then the completion happens in the
 * normal path and we will return _STS_NO_DATA from here.
 *
 * FIX_ME: Not Tested the actual condition..
 */
BC_STATUS crystalhd_hw_cancel_tx(struct crystalhd_hw *hw, uint32_t list_id)
{
	if (!hw || !list_id) {
		printk(KERN_ERR "%s: Invalid Arguments\n", __func__);
		return BC_STS_INV_ARG;
	}

	hw->pfnStopTxDMA(hw);
	crystalhd_hw_tx_req_complete(hw, list_id, BC_STS_IO_USER_ABORT);

	return BC_STS_SUCCESS;
}

BC_STATUS crystalhd_hw_add_cap_buffer(struct crystalhd_hw *hw,
				    crystalhd_dio_req *ioreq, bool en_post)
{
	crystalhd_rx_dma_pkt *rpkt;
	uint32_t tag, uv_desc_ix = 0;
	BC_STATUS sts;

	if (!hw || !ioreq) {
		printk(KERN_ERR "%s: Invalid Arguments\n", __func__);
		return BC_STS_INV_ARG;
	}

	rpkt = crystalhd_hw_alloc_rx_pkt(hw);
	if (!rpkt) {
		dev_err(&hw->adp->pdev->dev, "Insufficient resources\n");
		return BC_STS_INSUFF_RES;
	}

	rpkt->dio_req = ioreq;
	tag = rpkt->pkt_tag;

	sts = crystalhd_xlat_sgl_to_dma_desc(ioreq, &rpkt->desc_mem,
					     &uv_desc_ix, &hw->adp->pdev->dev);
	if (sts != BC_STS_SUCCESS)
		return sts;

	rpkt->uv_phy_addr = 0;

	/* Store the address of UV in the rx packet for post*/
	if (uv_desc_ix)
		rpkt->uv_phy_addr = rpkt->desc_mem.phy_addr +
				    (sizeof(dma_descriptor) * (uv_desc_ix + 1));

	if (en_post && !hw->hw_pause_issued)
		sts = hw->pfnPostRxSideBuff(hw, rpkt);
	else
		sts = crystalhd_dioq_add(hw->rx_freeq, rpkt, false, tag);

	return sts;
}

BC_STATUS crystalhd_hw_get_cap_buffer(struct crystalhd_hw *hw,
				    BC_PIC_INFO_BLOCK *pib,
				    crystalhd_dio_req **ioreq)
{
	crystalhd_rx_dma_pkt *rpkt;
	uint32_t timeout = BC_PROC_OUTPUT_TIMEOUT / 1000;
	uint32_t sig_pending = 0;

	if (!hw || !ioreq || !pib) {
		printk(KERN_ERR "%s: Invalid Arguments\n", __func__);
		return BC_STS_INV_ARG;
	}

#ifndef __APPLE__
	rpkt = crystalhd_dioq_fetch_wait(hw, timeout, &sig_pending);
#else
	rpkt = (crystalhd_rx_dma_pkt*)crystalhd_dioq_fetch_wait(hw, timeout, &sig_pending);
#endif
	if((crystalhd_dioq_count(hw->rx_rdyq) < HW_RESUME_THRESHOLD) && hw->hw_pause_issued)
	{
		dev_info(&hw->adp->pdev->dev, "HW RESUME with rdy list %u \n",crystalhd_dioq_count(hw->rx_rdyq));
		hw->pfnIssuePause(hw, false);
		hw->hw_pause_issued = false;
	}
	if (!rpkt) {
		if (sig_pending) {
			return BC_STS_IO_USER_ABORT;
		} else {
			return BC_STS_TIMEOUT;
		}
	}

	rpkt->dio_req->uinfo.comp_flags = rpkt->flags;

	if (rpkt->flags & COMP_FLAG_PIB_VALID)
		memcpy(pib, &rpkt->pib, sizeof(*pib));

	*ioreq = rpkt->dio_req;

	crystalhd_hw_free_rx_pkt(hw, rpkt);

	return BC_STS_SUCCESS;
}

BC_STATUS crystalhd_hw_start_capture(struct crystalhd_hw *hw)
{
	crystalhd_rx_dma_pkt *rx_pkt;
	BC_STATUS sts;
	uint32_t i;

	if (!hw) {
		printk(KERN_ERR "%s: Invalid Arguments\n", __func__);
		return BC_STS_INV_ARG;
	}

	/* This is start of capture.. Post to both the lists.. */
	for (i = 0; i < DMA_ENGINE_CNT; i++) {
#ifndef __APPLE__
		rx_pkt = crystalhd_dioq_fetch(hw->rx_freeq);
#else
		rx_pkt = (crystalhd_rx_dma_pkt*)crystalhd_dioq_fetch(hw->rx_freeq);
#endif
		if (!rx_pkt)
			return BC_STS_NO_DATA;
		sts = hw->pfnPostRxSideBuff(hw, rx_pkt);
		if (BC_STS_SUCCESS != sts)
			break;

	}

	return BC_STS_SUCCESS;
}

BC_STATUS crystalhd_hw_stop_capture(struct crystalhd_hw *hw, bool unmap)
{
	void *temp = NULL;

	if (!hw) {
		printk(KERN_ERR "%s: Invalid Arguments\n", __func__);
		return BC_STS_INV_ARG;
	}

	hw->pfnStopRXDMAEngines(hw);

	if(!unmap)
		return BC_STS_SUCCESS;
	
	// Clear up Active, Ready and Free lists one by one and release resources
	do {
		temp = crystalhd_dioq_fetch(hw->rx_actq);
		if (temp)
			crystalhd_rx_pkt_rel_call_back(hw, temp);
	} while (temp);

	do {
		temp = crystalhd_dioq_fetch(hw->rx_rdyq);
		if (temp)
			crystalhd_rx_pkt_rel_call_back(hw, temp);
	} while (temp);

	do {
		temp = crystalhd_dioq_fetch(hw->rx_freeq);
		if (temp)
			crystalhd_rx_pkt_rel_call_back(hw, temp);
	} while (temp);

	return BC_STS_SUCCESS;
}

BC_STATUS crystalhd_hw_suspend(struct crystalhd_hw *hw)
{
	if (!hw) {
		printk(KERN_ERR "%s: Invalid Arguments\n", __func__);
		return BC_STS_INV_ARG;
	}

	if (!hw->pfnStopDevice(hw)) {
		dev_err(&hw->adp->pdev->dev, "Failed to Stop Device!!\n");
		return BC_STS_ERROR;
	}

	return BC_STS_SUCCESS;
}

void crystalhd_hw_stats(struct crystalhd_hw *hw, struct crystalhd_hw_stats *stats)
{
	if (!hw) {
		printk(KERN_ERR "%s: Invalid Arguments\n", __func__);
		return;
	}

	/* if called w/NULL stats, its a req to zero out the stats */
	if (!stats) {
		memset(&hw->stats, 0, sizeof(hw->stats));
		return;
	}

	hw->stats.freeq_count = crystalhd_dioq_count(hw->rx_freeq);
	hw->stats.rdyq_count  = crystalhd_dioq_count(hw->rx_rdyq);
	memcpy(stats, &hw->stats, sizeof(*stats));
}
