/***************************************************************************
 *     Copyright (c) 1999-2009, Broadcom Corporation
 *     All Rights Reserved
 *     Confidential Property of Broadcom Corporation
 *
 *
 * THIS SOFTWARE MAY ONLY BE USED SUBJECT TO AN EXECUTED SOFTWARE LICENSE
 * AGREEMENT  BETWEEN THE USER AND BROADCOM.  YOU HAVE NO RIGHT TO USE OR
 * EXPLOIT THIS MATERIAL EXCEPT SUBJECT TO THE TERMS OF SUCH AN AGREEMENT.
 *
 * $brcm_Workfile: bchp_pm_l2.h $
 * $brcm_Revision: Hydra_Software_Devel/1 $
 * $brcm_Date: 7/17/09 8:13p $
 *
 * Module Description:
 *                     DO NOT EDIT THIS FILE DIRECTLY
 *
 * This module was generated magically with RDB from a source description
 * file. You must edit the source file for changes to be made to this file.
 *
 *
 * Date:           Generated on         Fri Jul 17 19:43:04 2009
 *                 MD5 Checksum         2914699efc3fb3edefca5cb4f4f38b34
 *
 * Compiled with:  RDB Utility          combo_header.pl
 *                 RDB Parser           3.0
 *                 unknown              unknown
 *                 Perl Interpreter     5.008008
 *                 Operating System     linux
 *
 * Revision History:
 *
 * $brcm_Log: /magnum/basemodules/chp/70015/rdb/a0/bchp_pm_l2.h $
 * 
 * Hydra_Software_Devel/1   7/17/09 8:13p albertl
 * PR56880: Initial revision.
 *
 ***************************************************************************/

#ifndef BCHP_PM_L2_H__
#define BCHP_PM_L2_H__

/***************************************************************************
 *PM_L2 - Registers for the power management block's L2 interrupt controller
 ***************************************************************************/
#define BCHP_PM_L2_CPU_STATUS                    0x00401c00 /* CPU interrupt Status Register */
#define BCHP_PM_L2_CPU_SET                       0x00401c04 /* CPU interrupt Set Register */
#define BCHP_PM_L2_CPU_CLEAR                     0x00401c08 /* CPU interrupt Clear Register */
#define BCHP_PM_L2_CPU_MASK_STATUS               0x00401c0c /* CPU interrupt Mask Status Register */
#define BCHP_PM_L2_CPU_MASK_SET                  0x00401c10 /* CPU interrupt Mask Set Register */
#define BCHP_PM_L2_CPU_MASK_CLEAR                0x00401c14 /* CPU interrupt Mask Clear Register */
#define BCHP_PM_L2_PCI_STATUS                    0x00401c18 /* PCI interrupt Status Register */
#define BCHP_PM_L2_PCI_SET                       0x00401c1c /* PCI interrupt Set Register */
#define BCHP_PM_L2_PCI_CLEAR                     0x00401c20 /* PCI interrupt Clear Register */
#define BCHP_PM_L2_PCI_MASK_STATUS               0x00401c24 /* PCI interrupt Mask Status Register */
#define BCHP_PM_L2_PCI_MASK_SET                  0x00401c28 /* PCI interrupt Mask Set Register */
#define BCHP_PM_L2_PCI_MASK_CLEAR                0x00401c2c /* PCI interrupt Mask Clear Register */

/***************************************************************************
 *CPU_STATUS - CPU interrupt Status Register
 ***************************************************************************/
/* PM_L2 :: CPU_STATUS :: reserved0 [31:01] */
#define BCHP_PM_L2_CPU_STATUS_reserved0_MASK                       0xfffffffe
#define BCHP_PM_L2_CPU_STATUS_reserved0_SHIFT                      1

/* PM_L2 :: CPU_STATUS :: SPARE_WAKEUP_EVENT_0 [00:00] */
#define BCHP_PM_L2_CPU_STATUS_SPARE_WAKEUP_EVENT_0_MASK            0x00000001
#define BCHP_PM_L2_CPU_STATUS_SPARE_WAKEUP_EVENT_0_SHIFT           0

/***************************************************************************
 *CPU_SET - CPU interrupt Set Register
 ***************************************************************************/
/* PM_L2 :: CPU_SET :: reserved0 [31:01] */
#define BCHP_PM_L2_CPU_SET_reserved0_MASK                          0xfffffffe
#define BCHP_PM_L2_CPU_SET_reserved0_SHIFT                         1

/* PM_L2 :: CPU_SET :: SPARE_WAKEUP_EVENT_0 [00:00] */
#define BCHP_PM_L2_CPU_SET_SPARE_WAKEUP_EVENT_0_MASK               0x00000001
#define BCHP_PM_L2_CPU_SET_SPARE_WAKEUP_EVENT_0_SHIFT              0

/***************************************************************************
 *CPU_CLEAR - CPU interrupt Clear Register
 ***************************************************************************/
/* PM_L2 :: CPU_CLEAR :: reserved0 [31:01] */
#define BCHP_PM_L2_CPU_CLEAR_reserved0_MASK                        0xfffffffe
#define BCHP_PM_L2_CPU_CLEAR_reserved0_SHIFT                       1

/* PM_L2 :: CPU_CLEAR :: SPARE_WAKEUP_EVENT_0 [00:00] */
#define BCHP_PM_L2_CPU_CLEAR_SPARE_WAKEUP_EVENT_0_MASK             0x00000001
#define BCHP_PM_L2_CPU_CLEAR_SPARE_WAKEUP_EVENT_0_SHIFT            0

/***************************************************************************
 *CPU_MASK_STATUS - CPU interrupt Mask Status Register
 ***************************************************************************/
/* PM_L2 :: CPU_MASK_STATUS :: reserved0 [31:01] */
#define BCHP_PM_L2_CPU_MASK_STATUS_reserved0_MASK                  0xfffffffe
#define BCHP_PM_L2_CPU_MASK_STATUS_reserved0_SHIFT                 1

/* PM_L2 :: CPU_MASK_STATUS :: SPARE_WAKEUP_EVENT_0 [00:00] */
#define BCHP_PM_L2_CPU_MASK_STATUS_SPARE_WAKEUP_EVENT_0_MASK       0x00000001
#define BCHP_PM_L2_CPU_MASK_STATUS_SPARE_WAKEUP_EVENT_0_SHIFT      0

/***************************************************************************
 *CPU_MASK_SET - CPU interrupt Mask Set Register
 ***************************************************************************/
/* PM_L2 :: CPU_MASK_SET :: reserved0 [31:01] */
#define BCHP_PM_L2_CPU_MASK_SET_reserved0_MASK                     0xfffffffe
#define BCHP_PM_L2_CPU_MASK_SET_reserved0_SHIFT                    1

/* PM_L2 :: CPU_MASK_SET :: SPARE_WAKEUP_EVENT_0 [00:00] */
#define BCHP_PM_L2_CPU_MASK_SET_SPARE_WAKEUP_EVENT_0_MASK          0x00000001
#define BCHP_PM_L2_CPU_MASK_SET_SPARE_WAKEUP_EVENT_0_SHIFT         0

/***************************************************************************
 *CPU_MASK_CLEAR - CPU interrupt Mask Clear Register
 ***************************************************************************/
/* PM_L2 :: CPU_MASK_CLEAR :: reserved0 [31:01] */
#define BCHP_PM_L2_CPU_MASK_CLEAR_reserved0_MASK                   0xfffffffe
#define BCHP_PM_L2_CPU_MASK_CLEAR_reserved0_SHIFT                  1

/* PM_L2 :: CPU_MASK_CLEAR :: SPARE_WAKEUP_EVENT_0 [00:00] */
#define BCHP_PM_L2_CPU_MASK_CLEAR_SPARE_WAKEUP_EVENT_0_MASK        0x00000001
#define BCHP_PM_L2_CPU_MASK_CLEAR_SPARE_WAKEUP_EVENT_0_SHIFT       0

/***************************************************************************
 *PCI_STATUS - PCI interrupt Status Register
 ***************************************************************************/
/* PM_L2 :: PCI_STATUS :: reserved0 [31:01] */
#define BCHP_PM_L2_PCI_STATUS_reserved0_MASK                       0xfffffffe
#define BCHP_PM_L2_PCI_STATUS_reserved0_SHIFT                      1

/* PM_L2 :: PCI_STATUS :: SPARE_WAKEUP_EVENT_0 [00:00] */
#define BCHP_PM_L2_PCI_STATUS_SPARE_WAKEUP_EVENT_0_MASK            0x00000001
#define BCHP_PM_L2_PCI_STATUS_SPARE_WAKEUP_EVENT_0_SHIFT           0

/***************************************************************************
 *PCI_SET - PCI interrupt Set Register
 ***************************************************************************/
/* PM_L2 :: PCI_SET :: reserved0 [31:01] */
#define BCHP_PM_L2_PCI_SET_reserved0_MASK                          0xfffffffe
#define BCHP_PM_L2_PCI_SET_reserved0_SHIFT                         1

/* PM_L2 :: PCI_SET :: SPARE_WAKEUP_EVENT_0 [00:00] */
#define BCHP_PM_L2_PCI_SET_SPARE_WAKEUP_EVENT_0_MASK               0x00000001
#define BCHP_PM_L2_PCI_SET_SPARE_WAKEUP_EVENT_0_SHIFT              0

/***************************************************************************
 *PCI_CLEAR - PCI interrupt Clear Register
 ***************************************************************************/
/* PM_L2 :: PCI_CLEAR :: reserved0 [31:01] */
#define BCHP_PM_L2_PCI_CLEAR_reserved0_MASK                        0xfffffffe
#define BCHP_PM_L2_PCI_CLEAR_reserved0_SHIFT                       1

/* PM_L2 :: PCI_CLEAR :: SPARE_WAKEUP_EVENT_0 [00:00] */
#define BCHP_PM_L2_PCI_CLEAR_SPARE_WAKEUP_EVENT_0_MASK             0x00000001
#define BCHP_PM_L2_PCI_CLEAR_SPARE_WAKEUP_EVENT_0_SHIFT            0

/***************************************************************************
 *PCI_MASK_STATUS - PCI interrupt Mask Status Register
 ***************************************************************************/
/* PM_L2 :: PCI_MASK_STATUS :: reserved0 [31:01] */
#define BCHP_PM_L2_PCI_MASK_STATUS_reserved0_MASK                  0xfffffffe
#define BCHP_PM_L2_PCI_MASK_STATUS_reserved0_SHIFT                 1

/* PM_L2 :: PCI_MASK_STATUS :: SPARE_WAKEUP_EVENT_0 [00:00] */
#define BCHP_PM_L2_PCI_MASK_STATUS_SPARE_WAKEUP_EVENT_0_MASK       0x00000001
#define BCHP_PM_L2_PCI_MASK_STATUS_SPARE_WAKEUP_EVENT_0_SHIFT      0

/***************************************************************************
 *PCI_MASK_SET - PCI interrupt Mask Set Register
 ***************************************************************************/
/* PM_L2 :: PCI_MASK_SET :: reserved0 [31:01] */
#define BCHP_PM_L2_PCI_MASK_SET_reserved0_MASK                     0xfffffffe
#define BCHP_PM_L2_PCI_MASK_SET_reserved0_SHIFT                    1

/* PM_L2 :: PCI_MASK_SET :: SPARE_WAKEUP_EVENT_0 [00:00] */
#define BCHP_PM_L2_PCI_MASK_SET_SPARE_WAKEUP_EVENT_0_MASK          0x00000001
#define BCHP_PM_L2_PCI_MASK_SET_SPARE_WAKEUP_EVENT_0_SHIFT         0

/***************************************************************************
 *PCI_MASK_CLEAR - PCI interrupt Mask Clear Register
 ***************************************************************************/
/* PM_L2 :: PCI_MASK_CLEAR :: reserved0 [31:01] */
#define BCHP_PM_L2_PCI_MASK_CLEAR_reserved0_MASK                   0xfffffffe
#define BCHP_PM_L2_PCI_MASK_CLEAR_reserved0_SHIFT                  1

/* PM_L2 :: PCI_MASK_CLEAR :: SPARE_WAKEUP_EVENT_0 [00:00] */
#define BCHP_PM_L2_PCI_MASK_CLEAR_SPARE_WAKEUP_EVENT_0_MASK        0x00000001
#define BCHP_PM_L2_PCI_MASK_CLEAR_SPARE_WAKEUP_EVENT_0_SHIFT       0

#endif /* #ifndef BCHP_PM_L2_H__ */

/* End of File */
