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
 * $brcm_Workfile: bchp_wrap_misc_secure_intr2.h $
 * $brcm_Revision: Hydra_Software_Devel/1 $
 * $brcm_Date: 7/17/09 8:23p $
 *
 * Module Description:
 *                     DO NOT EDIT THIS FILE DIRECTLY
 *
 * This module was generated magically with RDB from a source description
 * file. You must edit the source file for changes to be made to this file.
 *
 *
 * Date:           Generated on         Fri Jul 17 19:43:01 2009
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
 * $brcm_Log: /magnum/basemodules/chp/70015/rdb/a0/bchp_wrap_misc_secure_intr2.h $
 * 
 * Hydra_Software_Devel/1   7/17/09 8:23p albertl
 * PR56880: Initial revision.
 *
 ***************************************************************************/

#ifndef BCHP_WRAP_MISC_SECURE_INTR2_H__
#define BCHP_WRAP_MISC_SECURE_INTR2_H__

/***************************************************************************
 *WRAP_MISC_SECURE_INTR2 - MISC block secure Level 2 Interrupt Controller
 ***************************************************************************/
#define BCHP_WRAP_MISC_SECURE_INTR2_CPU_STATUS   0x000ff500 /* CPU interrupt Status Register */
#define BCHP_WRAP_MISC_SECURE_INTR2_CPU_SET      0x000ff504 /* CPU interrupt Set Register */
#define BCHP_WRAP_MISC_SECURE_INTR2_CPU_CLEAR    0x000ff508 /* CPU interrupt Clear Register */
#define BCHP_WRAP_MISC_SECURE_INTR2_CPU_MASK_STATUS 0x000ff50c /* CPU interrupt Mask Status Register */
#define BCHP_WRAP_MISC_SECURE_INTR2_CPU_MASK_SET 0x000ff510 /* CPU interrupt Mask Set Register */
#define BCHP_WRAP_MISC_SECURE_INTR2_CPU_MASK_CLEAR 0x000ff514 /* CPU interrupt Mask Clear Register */
#define BCHP_WRAP_MISC_SECURE_INTR2_PCI_STATUS   0x000ff518 /* PCI interrupt Status Register */
#define BCHP_WRAP_MISC_SECURE_INTR2_PCI_SET      0x000ff51c /* PCI interrupt Set Register */
#define BCHP_WRAP_MISC_SECURE_INTR2_PCI_CLEAR    0x000ff520 /* PCI interrupt Clear Register */
#define BCHP_WRAP_MISC_SECURE_INTR2_PCI_MASK_STATUS 0x000ff524 /* PCI interrupt Mask Status Register */
#define BCHP_WRAP_MISC_SECURE_INTR2_PCI_MASK_SET 0x000ff528 /* PCI interrupt Mask Set Register */
#define BCHP_WRAP_MISC_SECURE_INTR2_PCI_MASK_CLEAR 0x000ff52c /* PCI interrupt Mask Clear Register */

/***************************************************************************
 *CPU_STATUS - CPU interrupt Status Register
 ***************************************************************************/
/* WRAP_MISC_SECURE_INTR2 :: CPU_STATUS :: reserved0 [31:09] */
#define BCHP_WRAP_MISC_SECURE_INTR2_CPU_STATUS_reserved0_MASK      0xfffffe00
#define BCHP_WRAP_MISC_SECURE_INTR2_CPU_STATUS_reserved0_SHIFT     9

/* WRAP_MISC_SECURE_INTR2 :: CPU_STATUS :: STARCH_SECURE_INTR [08:08] */
#define BCHP_WRAP_MISC_SECURE_INTR2_CPU_STATUS_STARCH_SECURE_INTR_MASK 0x00000100
#define BCHP_WRAP_MISC_SECURE_INTR2_CPU_STATUS_STARCH_SECURE_INTR_SHIFT 8

/* WRAP_MISC_SECURE_INTR2 :: CPU_STATUS :: GISB_SECURE_BREAKPOINT_INTR [07:07] */
#define BCHP_WRAP_MISC_SECURE_INTR2_CPU_STATUS_GISB_SECURE_BREAKPOINT_INTR_MASK 0x00000080
#define BCHP_WRAP_MISC_SECURE_INTR2_CPU_STATUS_GISB_SECURE_BREAKPOINT_INTR_SHIFT 7

/* WRAP_MISC_SECURE_INTR2 :: CPU_STATUS :: SHARF_SECURE_INTR [06:06] */
#define BCHP_WRAP_MISC_SECURE_INTR2_CPU_STATUS_SHARF_SECURE_INTR_MASK 0x00000040
#define BCHP_WRAP_MISC_SECURE_INTR2_CPU_STATUS_SHARF_SECURE_INTR_SHIFT 6

/* WRAP_MISC_SECURE_INTR2 :: CPU_STATUS :: XPT_WR_CHECKER_INTR [05:05] */
#define BCHP_WRAP_MISC_SECURE_INTR2_CPU_STATUS_XPT_WR_CHECKER_INTR_MASK 0x00000020
#define BCHP_WRAP_MISC_SECURE_INTR2_CPU_STATUS_XPT_WR_CHECKER_INTR_SHIFT 5

/* WRAP_MISC_SECURE_INTR2 :: CPU_STATUS :: AVD_VICH_INTR [04:02] */
#define BCHP_WRAP_MISC_SECURE_INTR2_CPU_STATUS_AVD_VICH_INTR_MASK  0x0000001c
#define BCHP_WRAP_MISC_SECURE_INTR2_CPU_STATUS_AVD_VICH_INTR_SHIFT 2

/* WRAP_MISC_SECURE_INTR2 :: CPU_STATUS :: ARB_WRITE_CHECKER_INTR [01:01] */
#define BCHP_WRAP_MISC_SECURE_INTR2_CPU_STATUS_ARB_WRITE_CHECKER_INTR_MASK 0x00000002
#define BCHP_WRAP_MISC_SECURE_INTR2_CPU_STATUS_ARB_WRITE_CHECKER_INTR_SHIFT 1

/* WRAP_MISC_SECURE_INTR2 :: CPU_STATUS :: ARB_SARCH_INTR [00:00] */
#define BCHP_WRAP_MISC_SECURE_INTR2_CPU_STATUS_ARB_SARCH_INTR_MASK 0x00000001
#define BCHP_WRAP_MISC_SECURE_INTR2_CPU_STATUS_ARB_SARCH_INTR_SHIFT 0

/***************************************************************************
 *CPU_SET - CPU interrupt Set Register
 ***************************************************************************/
/* WRAP_MISC_SECURE_INTR2 :: CPU_SET :: reserved0 [31:09] */
#define BCHP_WRAP_MISC_SECURE_INTR2_CPU_SET_reserved0_MASK         0xfffffe00
#define BCHP_WRAP_MISC_SECURE_INTR2_CPU_SET_reserved0_SHIFT        9

/* WRAP_MISC_SECURE_INTR2 :: CPU_SET :: STARCH_SECURE_INTR [08:08] */
#define BCHP_WRAP_MISC_SECURE_INTR2_CPU_SET_STARCH_SECURE_INTR_MASK 0x00000100
#define BCHP_WRAP_MISC_SECURE_INTR2_CPU_SET_STARCH_SECURE_INTR_SHIFT 8

/* WRAP_MISC_SECURE_INTR2 :: CPU_SET :: GISB_SECURE_BREAKPOINT_INTR [07:07] */
#define BCHP_WRAP_MISC_SECURE_INTR2_CPU_SET_GISB_SECURE_BREAKPOINT_INTR_MASK 0x00000080
#define BCHP_WRAP_MISC_SECURE_INTR2_CPU_SET_GISB_SECURE_BREAKPOINT_INTR_SHIFT 7

/* WRAP_MISC_SECURE_INTR2 :: CPU_SET :: SHARF_SECURE_INTR [06:06] */
#define BCHP_WRAP_MISC_SECURE_INTR2_CPU_SET_SHARF_SECURE_INTR_MASK 0x00000040
#define BCHP_WRAP_MISC_SECURE_INTR2_CPU_SET_SHARF_SECURE_INTR_SHIFT 6

/* WRAP_MISC_SECURE_INTR2 :: CPU_SET :: XPT_WR_CHECKER_INTR [05:05] */
#define BCHP_WRAP_MISC_SECURE_INTR2_CPU_SET_XPT_WR_CHECKER_INTR_MASK 0x00000020
#define BCHP_WRAP_MISC_SECURE_INTR2_CPU_SET_XPT_WR_CHECKER_INTR_SHIFT 5

/* WRAP_MISC_SECURE_INTR2 :: CPU_SET :: AVD_VICH_INTR [04:02] */
#define BCHP_WRAP_MISC_SECURE_INTR2_CPU_SET_AVD_VICH_INTR_MASK     0x0000001c
#define BCHP_WRAP_MISC_SECURE_INTR2_CPU_SET_AVD_VICH_INTR_SHIFT    2

/* WRAP_MISC_SECURE_INTR2 :: CPU_SET :: ARB_WRITE_CHECKER_INTR [01:01] */
#define BCHP_WRAP_MISC_SECURE_INTR2_CPU_SET_ARB_WRITE_CHECKER_INTR_MASK 0x00000002
#define BCHP_WRAP_MISC_SECURE_INTR2_CPU_SET_ARB_WRITE_CHECKER_INTR_SHIFT 1

/* WRAP_MISC_SECURE_INTR2 :: CPU_SET :: ARB_SARCH_INTR [00:00] */
#define BCHP_WRAP_MISC_SECURE_INTR2_CPU_SET_ARB_SARCH_INTR_MASK    0x00000001
#define BCHP_WRAP_MISC_SECURE_INTR2_CPU_SET_ARB_SARCH_INTR_SHIFT   0

/***************************************************************************
 *CPU_CLEAR - CPU interrupt Clear Register
 ***************************************************************************/
/* WRAP_MISC_SECURE_INTR2 :: CPU_CLEAR :: reserved0 [31:09] */
#define BCHP_WRAP_MISC_SECURE_INTR2_CPU_CLEAR_reserved0_MASK       0xfffffe00
#define BCHP_WRAP_MISC_SECURE_INTR2_CPU_CLEAR_reserved0_SHIFT      9

/* WRAP_MISC_SECURE_INTR2 :: CPU_CLEAR :: STARCH_SECURE_INTR [08:08] */
#define BCHP_WRAP_MISC_SECURE_INTR2_CPU_CLEAR_STARCH_SECURE_INTR_MASK 0x00000100
#define BCHP_WRAP_MISC_SECURE_INTR2_CPU_CLEAR_STARCH_SECURE_INTR_SHIFT 8

/* WRAP_MISC_SECURE_INTR2 :: CPU_CLEAR :: GISB_SECURE_BREAKPOINT_INTR [07:07] */
#define BCHP_WRAP_MISC_SECURE_INTR2_CPU_CLEAR_GISB_SECURE_BREAKPOINT_INTR_MASK 0x00000080
#define BCHP_WRAP_MISC_SECURE_INTR2_CPU_CLEAR_GISB_SECURE_BREAKPOINT_INTR_SHIFT 7

/* WRAP_MISC_SECURE_INTR2 :: CPU_CLEAR :: SHARF_SECURE_INTR [06:06] */
#define BCHP_WRAP_MISC_SECURE_INTR2_CPU_CLEAR_SHARF_SECURE_INTR_MASK 0x00000040
#define BCHP_WRAP_MISC_SECURE_INTR2_CPU_CLEAR_SHARF_SECURE_INTR_SHIFT 6

/* WRAP_MISC_SECURE_INTR2 :: CPU_CLEAR :: XPT_WR_CHECKER_INTR [05:05] */
#define BCHP_WRAP_MISC_SECURE_INTR2_CPU_CLEAR_XPT_WR_CHECKER_INTR_MASK 0x00000020
#define BCHP_WRAP_MISC_SECURE_INTR2_CPU_CLEAR_XPT_WR_CHECKER_INTR_SHIFT 5

/* WRAP_MISC_SECURE_INTR2 :: CPU_CLEAR :: AVD_VICH_INTR [04:02] */
#define BCHP_WRAP_MISC_SECURE_INTR2_CPU_CLEAR_AVD_VICH_INTR_MASK   0x0000001c
#define BCHP_WRAP_MISC_SECURE_INTR2_CPU_CLEAR_AVD_VICH_INTR_SHIFT  2

/* WRAP_MISC_SECURE_INTR2 :: CPU_CLEAR :: ARB_WRITE_CHECKER_INTR [01:01] */
#define BCHP_WRAP_MISC_SECURE_INTR2_CPU_CLEAR_ARB_WRITE_CHECKER_INTR_MASK 0x00000002
#define BCHP_WRAP_MISC_SECURE_INTR2_CPU_CLEAR_ARB_WRITE_CHECKER_INTR_SHIFT 1

/* WRAP_MISC_SECURE_INTR2 :: CPU_CLEAR :: ARB_SARCH_INTR [00:00] */
#define BCHP_WRAP_MISC_SECURE_INTR2_CPU_CLEAR_ARB_SARCH_INTR_MASK  0x00000001
#define BCHP_WRAP_MISC_SECURE_INTR2_CPU_CLEAR_ARB_SARCH_INTR_SHIFT 0

/***************************************************************************
 *CPU_MASK_STATUS - CPU interrupt Mask Status Register
 ***************************************************************************/
/* WRAP_MISC_SECURE_INTR2 :: CPU_MASK_STATUS :: reserved0 [31:09] */
#define BCHP_WRAP_MISC_SECURE_INTR2_CPU_MASK_STATUS_reserved0_MASK 0xfffffe00
#define BCHP_WRAP_MISC_SECURE_INTR2_CPU_MASK_STATUS_reserved0_SHIFT 9

/* WRAP_MISC_SECURE_INTR2 :: CPU_MASK_STATUS :: STARCH_SECURE_MASK [08:08] */
#define BCHP_WRAP_MISC_SECURE_INTR2_CPU_MASK_STATUS_STARCH_SECURE_MASK_MASK 0x00000100
#define BCHP_WRAP_MISC_SECURE_INTR2_CPU_MASK_STATUS_STARCH_SECURE_MASK_SHIFT 8

/* WRAP_MISC_SECURE_INTR2 :: CPU_MASK_STATUS :: GISB_SECURE_BREAKPOINT_MASK [07:07] */
#define BCHP_WRAP_MISC_SECURE_INTR2_CPU_MASK_STATUS_GISB_SECURE_BREAKPOINT_MASK_MASK 0x00000080
#define BCHP_WRAP_MISC_SECURE_INTR2_CPU_MASK_STATUS_GISB_SECURE_BREAKPOINT_MASK_SHIFT 7

/* WRAP_MISC_SECURE_INTR2 :: CPU_MASK_STATUS :: SHARF_SECURE_MASK [06:06] */
#define BCHP_WRAP_MISC_SECURE_INTR2_CPU_MASK_STATUS_SHARF_SECURE_MASK_MASK 0x00000040
#define BCHP_WRAP_MISC_SECURE_INTR2_CPU_MASK_STATUS_SHARF_SECURE_MASK_SHIFT 6

/* WRAP_MISC_SECURE_INTR2 :: CPU_MASK_STATUS :: XPT_WR_CHECKER_MASK [05:05] */
#define BCHP_WRAP_MISC_SECURE_INTR2_CPU_MASK_STATUS_XPT_WR_CHECKER_MASK_MASK 0x00000020
#define BCHP_WRAP_MISC_SECURE_INTR2_CPU_MASK_STATUS_XPT_WR_CHECKER_MASK_SHIFT 5

/* WRAP_MISC_SECURE_INTR2 :: CPU_MASK_STATUS :: AVD_VICH_MASK [04:02] */
#define BCHP_WRAP_MISC_SECURE_INTR2_CPU_MASK_STATUS_AVD_VICH_MASK_MASK 0x0000001c
#define BCHP_WRAP_MISC_SECURE_INTR2_CPU_MASK_STATUS_AVD_VICH_MASK_SHIFT 2

/* WRAP_MISC_SECURE_INTR2 :: CPU_MASK_STATUS :: ARB_WRITE_CHECKER_MASK [01:01] */
#define BCHP_WRAP_MISC_SECURE_INTR2_CPU_MASK_STATUS_ARB_WRITE_CHECKER_MASK_MASK 0x00000002
#define BCHP_WRAP_MISC_SECURE_INTR2_CPU_MASK_STATUS_ARB_WRITE_CHECKER_MASK_SHIFT 1

/* WRAP_MISC_SECURE_INTR2 :: CPU_MASK_STATUS :: ARB_SARCH_MASK [00:00] */
#define BCHP_WRAP_MISC_SECURE_INTR2_CPU_MASK_STATUS_ARB_SARCH_MASK_MASK 0x00000001
#define BCHP_WRAP_MISC_SECURE_INTR2_CPU_MASK_STATUS_ARB_SARCH_MASK_SHIFT 0

/***************************************************************************
 *CPU_MASK_SET - CPU interrupt Mask Set Register
 ***************************************************************************/
/* WRAP_MISC_SECURE_INTR2 :: CPU_MASK_SET :: reserved0 [31:09] */
#define BCHP_WRAP_MISC_SECURE_INTR2_CPU_MASK_SET_reserved0_MASK    0xfffffe00
#define BCHP_WRAP_MISC_SECURE_INTR2_CPU_MASK_SET_reserved0_SHIFT   9

/* WRAP_MISC_SECURE_INTR2 :: CPU_MASK_SET :: STARCH_SECURE_MASK [08:08] */
#define BCHP_WRAP_MISC_SECURE_INTR2_CPU_MASK_SET_STARCH_SECURE_MASK_MASK 0x00000100
#define BCHP_WRAP_MISC_SECURE_INTR2_CPU_MASK_SET_STARCH_SECURE_MASK_SHIFT 8

/* WRAP_MISC_SECURE_INTR2 :: CPU_MASK_SET :: GISB_SECURE_BREAKPOINT_MASK [07:07] */
#define BCHP_WRAP_MISC_SECURE_INTR2_CPU_MASK_SET_GISB_SECURE_BREAKPOINT_MASK_MASK 0x00000080
#define BCHP_WRAP_MISC_SECURE_INTR2_CPU_MASK_SET_GISB_SECURE_BREAKPOINT_MASK_SHIFT 7

/* WRAP_MISC_SECURE_INTR2 :: CPU_MASK_SET :: SHARF_SECURE_MASK [06:06] */
#define BCHP_WRAP_MISC_SECURE_INTR2_CPU_MASK_SET_SHARF_SECURE_MASK_MASK 0x00000040
#define BCHP_WRAP_MISC_SECURE_INTR2_CPU_MASK_SET_SHARF_SECURE_MASK_SHIFT 6

/* WRAP_MISC_SECURE_INTR2 :: CPU_MASK_SET :: XPT_WR_CHECKER_MASK [05:05] */
#define BCHP_WRAP_MISC_SECURE_INTR2_CPU_MASK_SET_XPT_WR_CHECKER_MASK_MASK 0x00000020
#define BCHP_WRAP_MISC_SECURE_INTR2_CPU_MASK_SET_XPT_WR_CHECKER_MASK_SHIFT 5

/* WRAP_MISC_SECURE_INTR2 :: CPU_MASK_SET :: AVD_VICH_MASK [04:02] */
#define BCHP_WRAP_MISC_SECURE_INTR2_CPU_MASK_SET_AVD_VICH_MASK_MASK 0x0000001c
#define BCHP_WRAP_MISC_SECURE_INTR2_CPU_MASK_SET_AVD_VICH_MASK_SHIFT 2

/* WRAP_MISC_SECURE_INTR2 :: CPU_MASK_SET :: ARB_WRITE_CHECKER_MASK [01:01] */
#define BCHP_WRAP_MISC_SECURE_INTR2_CPU_MASK_SET_ARB_WRITE_CHECKER_MASK_MASK 0x00000002
#define BCHP_WRAP_MISC_SECURE_INTR2_CPU_MASK_SET_ARB_WRITE_CHECKER_MASK_SHIFT 1

/* WRAP_MISC_SECURE_INTR2 :: CPU_MASK_SET :: ARB_SARCH_MASK [00:00] */
#define BCHP_WRAP_MISC_SECURE_INTR2_CPU_MASK_SET_ARB_SARCH_MASK_MASK 0x00000001
#define BCHP_WRAP_MISC_SECURE_INTR2_CPU_MASK_SET_ARB_SARCH_MASK_SHIFT 0

/***************************************************************************
 *CPU_MASK_CLEAR - CPU interrupt Mask Clear Register
 ***************************************************************************/
/* WRAP_MISC_SECURE_INTR2 :: CPU_MASK_CLEAR :: reserved0 [31:09] */
#define BCHP_WRAP_MISC_SECURE_INTR2_CPU_MASK_CLEAR_reserved0_MASK  0xfffffe00
#define BCHP_WRAP_MISC_SECURE_INTR2_CPU_MASK_CLEAR_reserved0_SHIFT 9

/* WRAP_MISC_SECURE_INTR2 :: CPU_MASK_CLEAR :: STARCH_SECURE_MASK [08:08] */
#define BCHP_WRAP_MISC_SECURE_INTR2_CPU_MASK_CLEAR_STARCH_SECURE_MASK_MASK 0x00000100
#define BCHP_WRAP_MISC_SECURE_INTR2_CPU_MASK_CLEAR_STARCH_SECURE_MASK_SHIFT 8

/* WRAP_MISC_SECURE_INTR2 :: CPU_MASK_CLEAR :: GISB_SECURE_BREAKPOINT_MASK [07:07] */
#define BCHP_WRAP_MISC_SECURE_INTR2_CPU_MASK_CLEAR_GISB_SECURE_BREAKPOINT_MASK_MASK 0x00000080
#define BCHP_WRAP_MISC_SECURE_INTR2_CPU_MASK_CLEAR_GISB_SECURE_BREAKPOINT_MASK_SHIFT 7

/* WRAP_MISC_SECURE_INTR2 :: CPU_MASK_CLEAR :: SHARF_SECURE_MASK [06:06] */
#define BCHP_WRAP_MISC_SECURE_INTR2_CPU_MASK_CLEAR_SHARF_SECURE_MASK_MASK 0x00000040
#define BCHP_WRAP_MISC_SECURE_INTR2_CPU_MASK_CLEAR_SHARF_SECURE_MASK_SHIFT 6

/* WRAP_MISC_SECURE_INTR2 :: CPU_MASK_CLEAR :: XPT_WR_CHECKER_MASK [05:05] */
#define BCHP_WRAP_MISC_SECURE_INTR2_CPU_MASK_CLEAR_XPT_WR_CHECKER_MASK_MASK 0x00000020
#define BCHP_WRAP_MISC_SECURE_INTR2_CPU_MASK_CLEAR_XPT_WR_CHECKER_MASK_SHIFT 5

/* WRAP_MISC_SECURE_INTR2 :: CPU_MASK_CLEAR :: AVD_VICH_MASK [04:02] */
#define BCHP_WRAP_MISC_SECURE_INTR2_CPU_MASK_CLEAR_AVD_VICH_MASK_MASK 0x0000001c
#define BCHP_WRAP_MISC_SECURE_INTR2_CPU_MASK_CLEAR_AVD_VICH_MASK_SHIFT 2

/* WRAP_MISC_SECURE_INTR2 :: CPU_MASK_CLEAR :: ARB_WRITE_CHECKER_MASK [01:01] */
#define BCHP_WRAP_MISC_SECURE_INTR2_CPU_MASK_CLEAR_ARB_WRITE_CHECKER_MASK_MASK 0x00000002
#define BCHP_WRAP_MISC_SECURE_INTR2_CPU_MASK_CLEAR_ARB_WRITE_CHECKER_MASK_SHIFT 1

/* WRAP_MISC_SECURE_INTR2 :: CPU_MASK_CLEAR :: ARB_SARCH_MASK [00:00] */
#define BCHP_WRAP_MISC_SECURE_INTR2_CPU_MASK_CLEAR_ARB_SARCH_MASK_MASK 0x00000001
#define BCHP_WRAP_MISC_SECURE_INTR2_CPU_MASK_CLEAR_ARB_SARCH_MASK_SHIFT 0

/***************************************************************************
 *PCI_STATUS - PCI interrupt Status Register
 ***************************************************************************/
/* WRAP_MISC_SECURE_INTR2 :: PCI_STATUS :: reserved0 [31:09] */
#define BCHP_WRAP_MISC_SECURE_INTR2_PCI_STATUS_reserved0_MASK      0xfffffe00
#define BCHP_WRAP_MISC_SECURE_INTR2_PCI_STATUS_reserved0_SHIFT     9

/* WRAP_MISC_SECURE_INTR2 :: PCI_STATUS :: STARCH_SECURE_INTR [08:08] */
#define BCHP_WRAP_MISC_SECURE_INTR2_PCI_STATUS_STARCH_SECURE_INTR_MASK 0x00000100
#define BCHP_WRAP_MISC_SECURE_INTR2_PCI_STATUS_STARCH_SECURE_INTR_SHIFT 8

/* WRAP_MISC_SECURE_INTR2 :: PCI_STATUS :: GISB_SECURE_BREAKPOINT_INTR [07:07] */
#define BCHP_WRAP_MISC_SECURE_INTR2_PCI_STATUS_GISB_SECURE_BREAKPOINT_INTR_MASK 0x00000080
#define BCHP_WRAP_MISC_SECURE_INTR2_PCI_STATUS_GISB_SECURE_BREAKPOINT_INTR_SHIFT 7

/* WRAP_MISC_SECURE_INTR2 :: PCI_STATUS :: SHARF_SECURE_INTR [06:06] */
#define BCHP_WRAP_MISC_SECURE_INTR2_PCI_STATUS_SHARF_SECURE_INTR_MASK 0x00000040
#define BCHP_WRAP_MISC_SECURE_INTR2_PCI_STATUS_SHARF_SECURE_INTR_SHIFT 6

/* WRAP_MISC_SECURE_INTR2 :: PCI_STATUS :: XPT_WR_CHECKER_INTR [05:05] */
#define BCHP_WRAP_MISC_SECURE_INTR2_PCI_STATUS_XPT_WR_CHECKER_INTR_MASK 0x00000020
#define BCHP_WRAP_MISC_SECURE_INTR2_PCI_STATUS_XPT_WR_CHECKER_INTR_SHIFT 5

/* WRAP_MISC_SECURE_INTR2 :: PCI_STATUS :: AVD_VICH_INTR [04:02] */
#define BCHP_WRAP_MISC_SECURE_INTR2_PCI_STATUS_AVD_VICH_INTR_MASK  0x0000001c
#define BCHP_WRAP_MISC_SECURE_INTR2_PCI_STATUS_AVD_VICH_INTR_SHIFT 2

/* WRAP_MISC_SECURE_INTR2 :: PCI_STATUS :: ARB_WRITE_CHECKER_INTR [01:01] */
#define BCHP_WRAP_MISC_SECURE_INTR2_PCI_STATUS_ARB_WRITE_CHECKER_INTR_MASK 0x00000002
#define BCHP_WRAP_MISC_SECURE_INTR2_PCI_STATUS_ARB_WRITE_CHECKER_INTR_SHIFT 1

/* WRAP_MISC_SECURE_INTR2 :: PCI_STATUS :: ARB_SARCH_INTR [00:00] */
#define BCHP_WRAP_MISC_SECURE_INTR2_PCI_STATUS_ARB_SARCH_INTR_MASK 0x00000001
#define BCHP_WRAP_MISC_SECURE_INTR2_PCI_STATUS_ARB_SARCH_INTR_SHIFT 0

/***************************************************************************
 *PCI_SET - PCI interrupt Set Register
 ***************************************************************************/
/* WRAP_MISC_SECURE_INTR2 :: PCI_SET :: reserved0 [31:09] */
#define BCHP_WRAP_MISC_SECURE_INTR2_PCI_SET_reserved0_MASK         0xfffffe00
#define BCHP_WRAP_MISC_SECURE_INTR2_PCI_SET_reserved0_SHIFT        9

/* WRAP_MISC_SECURE_INTR2 :: PCI_SET :: STARCH_SECURE_INTR [08:08] */
#define BCHP_WRAP_MISC_SECURE_INTR2_PCI_SET_STARCH_SECURE_INTR_MASK 0x00000100
#define BCHP_WRAP_MISC_SECURE_INTR2_PCI_SET_STARCH_SECURE_INTR_SHIFT 8

/* WRAP_MISC_SECURE_INTR2 :: PCI_SET :: GISB_SECURE_BREAKPOINT_INTR [07:07] */
#define BCHP_WRAP_MISC_SECURE_INTR2_PCI_SET_GISB_SECURE_BREAKPOINT_INTR_MASK 0x00000080
#define BCHP_WRAP_MISC_SECURE_INTR2_PCI_SET_GISB_SECURE_BREAKPOINT_INTR_SHIFT 7

/* WRAP_MISC_SECURE_INTR2 :: PCI_SET :: SHARF_SECURE_INTR [06:06] */
#define BCHP_WRAP_MISC_SECURE_INTR2_PCI_SET_SHARF_SECURE_INTR_MASK 0x00000040
#define BCHP_WRAP_MISC_SECURE_INTR2_PCI_SET_SHARF_SECURE_INTR_SHIFT 6

/* WRAP_MISC_SECURE_INTR2 :: PCI_SET :: XPT_WR_CHECKER_INTR [05:05] */
#define BCHP_WRAP_MISC_SECURE_INTR2_PCI_SET_XPT_WR_CHECKER_INTR_MASK 0x00000020
#define BCHP_WRAP_MISC_SECURE_INTR2_PCI_SET_XPT_WR_CHECKER_INTR_SHIFT 5

/* WRAP_MISC_SECURE_INTR2 :: PCI_SET :: AVD_VICH_INTR [04:02] */
#define BCHP_WRAP_MISC_SECURE_INTR2_PCI_SET_AVD_VICH_INTR_MASK     0x0000001c
#define BCHP_WRAP_MISC_SECURE_INTR2_PCI_SET_AVD_VICH_INTR_SHIFT    2

/* WRAP_MISC_SECURE_INTR2 :: PCI_SET :: ARB_WRITE_CHECKER_INTR [01:01] */
#define BCHP_WRAP_MISC_SECURE_INTR2_PCI_SET_ARB_WRITE_CHECKER_INTR_MASK 0x00000002
#define BCHP_WRAP_MISC_SECURE_INTR2_PCI_SET_ARB_WRITE_CHECKER_INTR_SHIFT 1

/* WRAP_MISC_SECURE_INTR2 :: PCI_SET :: ARB_SARCH_INTR [00:00] */
#define BCHP_WRAP_MISC_SECURE_INTR2_PCI_SET_ARB_SARCH_INTR_MASK    0x00000001
#define BCHP_WRAP_MISC_SECURE_INTR2_PCI_SET_ARB_SARCH_INTR_SHIFT   0

/***************************************************************************
 *PCI_CLEAR - PCI interrupt Clear Register
 ***************************************************************************/
/* WRAP_MISC_SECURE_INTR2 :: PCI_CLEAR :: reserved0 [31:09] */
#define BCHP_WRAP_MISC_SECURE_INTR2_PCI_CLEAR_reserved0_MASK       0xfffffe00
#define BCHP_WRAP_MISC_SECURE_INTR2_PCI_CLEAR_reserved0_SHIFT      9

/* WRAP_MISC_SECURE_INTR2 :: PCI_CLEAR :: STARCH_SECURE_INTR [08:08] */
#define BCHP_WRAP_MISC_SECURE_INTR2_PCI_CLEAR_STARCH_SECURE_INTR_MASK 0x00000100
#define BCHP_WRAP_MISC_SECURE_INTR2_PCI_CLEAR_STARCH_SECURE_INTR_SHIFT 8

/* WRAP_MISC_SECURE_INTR2 :: PCI_CLEAR :: GISB_SECURE_BREAKPOINT_INTR [07:07] */
#define BCHP_WRAP_MISC_SECURE_INTR2_PCI_CLEAR_GISB_SECURE_BREAKPOINT_INTR_MASK 0x00000080
#define BCHP_WRAP_MISC_SECURE_INTR2_PCI_CLEAR_GISB_SECURE_BREAKPOINT_INTR_SHIFT 7

/* WRAP_MISC_SECURE_INTR2 :: PCI_CLEAR :: SHARF_SECURE_INTR [06:06] */
#define BCHP_WRAP_MISC_SECURE_INTR2_PCI_CLEAR_SHARF_SECURE_INTR_MASK 0x00000040
#define BCHP_WRAP_MISC_SECURE_INTR2_PCI_CLEAR_SHARF_SECURE_INTR_SHIFT 6

/* WRAP_MISC_SECURE_INTR2 :: PCI_CLEAR :: XPT_WR_CHECKER_INTR [05:05] */
#define BCHP_WRAP_MISC_SECURE_INTR2_PCI_CLEAR_XPT_WR_CHECKER_INTR_MASK 0x00000020
#define BCHP_WRAP_MISC_SECURE_INTR2_PCI_CLEAR_XPT_WR_CHECKER_INTR_SHIFT 5

/* WRAP_MISC_SECURE_INTR2 :: PCI_CLEAR :: AVD_VICH_INTR [04:02] */
#define BCHP_WRAP_MISC_SECURE_INTR2_PCI_CLEAR_AVD_VICH_INTR_MASK   0x0000001c
#define BCHP_WRAP_MISC_SECURE_INTR2_PCI_CLEAR_AVD_VICH_INTR_SHIFT  2

/* WRAP_MISC_SECURE_INTR2 :: PCI_CLEAR :: ARB_WRITE_CHECKER_INTR [01:01] */
#define BCHP_WRAP_MISC_SECURE_INTR2_PCI_CLEAR_ARB_WRITE_CHECKER_INTR_MASK 0x00000002
#define BCHP_WRAP_MISC_SECURE_INTR2_PCI_CLEAR_ARB_WRITE_CHECKER_INTR_SHIFT 1

/* WRAP_MISC_SECURE_INTR2 :: PCI_CLEAR :: ARB_SARCH_INTR [00:00] */
#define BCHP_WRAP_MISC_SECURE_INTR2_PCI_CLEAR_ARB_SARCH_INTR_MASK  0x00000001
#define BCHP_WRAP_MISC_SECURE_INTR2_PCI_CLEAR_ARB_SARCH_INTR_SHIFT 0

/***************************************************************************
 *PCI_MASK_STATUS - PCI interrupt Mask Status Register
 ***************************************************************************/
/* WRAP_MISC_SECURE_INTR2 :: PCI_MASK_STATUS :: reserved0 [31:09] */
#define BCHP_WRAP_MISC_SECURE_INTR2_PCI_MASK_STATUS_reserved0_MASK 0xfffffe00
#define BCHP_WRAP_MISC_SECURE_INTR2_PCI_MASK_STATUS_reserved0_SHIFT 9

/* WRAP_MISC_SECURE_INTR2 :: PCI_MASK_STATUS :: STARCH_SECURE_MASK [08:08] */
#define BCHP_WRAP_MISC_SECURE_INTR2_PCI_MASK_STATUS_STARCH_SECURE_MASK_MASK 0x00000100
#define BCHP_WRAP_MISC_SECURE_INTR2_PCI_MASK_STATUS_STARCH_SECURE_MASK_SHIFT 8

/* WRAP_MISC_SECURE_INTR2 :: PCI_MASK_STATUS :: GISB_SECURE_BREAKPOINT_MASK [07:07] */
#define BCHP_WRAP_MISC_SECURE_INTR2_PCI_MASK_STATUS_GISB_SECURE_BREAKPOINT_MASK_MASK 0x00000080
#define BCHP_WRAP_MISC_SECURE_INTR2_PCI_MASK_STATUS_GISB_SECURE_BREAKPOINT_MASK_SHIFT 7

/* WRAP_MISC_SECURE_INTR2 :: PCI_MASK_STATUS :: SHARF_SECURE_MASK [06:06] */
#define BCHP_WRAP_MISC_SECURE_INTR2_PCI_MASK_STATUS_SHARF_SECURE_MASK_MASK 0x00000040
#define BCHP_WRAP_MISC_SECURE_INTR2_PCI_MASK_STATUS_SHARF_SECURE_MASK_SHIFT 6

/* WRAP_MISC_SECURE_INTR2 :: PCI_MASK_STATUS :: XPT_WR_CHECKER_MASK [05:05] */
#define BCHP_WRAP_MISC_SECURE_INTR2_PCI_MASK_STATUS_XPT_WR_CHECKER_MASK_MASK 0x00000020
#define BCHP_WRAP_MISC_SECURE_INTR2_PCI_MASK_STATUS_XPT_WR_CHECKER_MASK_SHIFT 5

/* WRAP_MISC_SECURE_INTR2 :: PCI_MASK_STATUS :: AVD_VICH_MASK [04:02] */
#define BCHP_WRAP_MISC_SECURE_INTR2_PCI_MASK_STATUS_AVD_VICH_MASK_MASK 0x0000001c
#define BCHP_WRAP_MISC_SECURE_INTR2_PCI_MASK_STATUS_AVD_VICH_MASK_SHIFT 2

/* WRAP_MISC_SECURE_INTR2 :: PCI_MASK_STATUS :: ARB_WRITE_CHECKER_MASK [01:01] */
#define BCHP_WRAP_MISC_SECURE_INTR2_PCI_MASK_STATUS_ARB_WRITE_CHECKER_MASK_MASK 0x00000002
#define BCHP_WRAP_MISC_SECURE_INTR2_PCI_MASK_STATUS_ARB_WRITE_CHECKER_MASK_SHIFT 1

/* WRAP_MISC_SECURE_INTR2 :: PCI_MASK_STATUS :: ARB_SARCH_MASK [00:00] */
#define BCHP_WRAP_MISC_SECURE_INTR2_PCI_MASK_STATUS_ARB_SARCH_MASK_MASK 0x00000001
#define BCHP_WRAP_MISC_SECURE_INTR2_PCI_MASK_STATUS_ARB_SARCH_MASK_SHIFT 0

/***************************************************************************
 *PCI_MASK_SET - PCI interrupt Mask Set Register
 ***************************************************************************/
/* WRAP_MISC_SECURE_INTR2 :: PCI_MASK_SET :: reserved0 [31:09] */
#define BCHP_WRAP_MISC_SECURE_INTR2_PCI_MASK_SET_reserved0_MASK    0xfffffe00
#define BCHP_WRAP_MISC_SECURE_INTR2_PCI_MASK_SET_reserved0_SHIFT   9

/* WRAP_MISC_SECURE_INTR2 :: PCI_MASK_SET :: STARCH_SECURE_MASK [08:08] */
#define BCHP_WRAP_MISC_SECURE_INTR2_PCI_MASK_SET_STARCH_SECURE_MASK_MASK 0x00000100
#define BCHP_WRAP_MISC_SECURE_INTR2_PCI_MASK_SET_STARCH_SECURE_MASK_SHIFT 8

/* WRAP_MISC_SECURE_INTR2 :: PCI_MASK_SET :: GISB_SECURE_BREAKPOINT_MASK [07:07] */
#define BCHP_WRAP_MISC_SECURE_INTR2_PCI_MASK_SET_GISB_SECURE_BREAKPOINT_MASK_MASK 0x00000080
#define BCHP_WRAP_MISC_SECURE_INTR2_PCI_MASK_SET_GISB_SECURE_BREAKPOINT_MASK_SHIFT 7

/* WRAP_MISC_SECURE_INTR2 :: PCI_MASK_SET :: SHARF_SECURE_MASK [06:06] */
#define BCHP_WRAP_MISC_SECURE_INTR2_PCI_MASK_SET_SHARF_SECURE_MASK_MASK 0x00000040
#define BCHP_WRAP_MISC_SECURE_INTR2_PCI_MASK_SET_SHARF_SECURE_MASK_SHIFT 6

/* WRAP_MISC_SECURE_INTR2 :: PCI_MASK_SET :: XPT_WR_CHECKER_MASK [05:05] */
#define BCHP_WRAP_MISC_SECURE_INTR2_PCI_MASK_SET_XPT_WR_CHECKER_MASK_MASK 0x00000020
#define BCHP_WRAP_MISC_SECURE_INTR2_PCI_MASK_SET_XPT_WR_CHECKER_MASK_SHIFT 5

/* WRAP_MISC_SECURE_INTR2 :: PCI_MASK_SET :: AVD_VICH_MASK [04:02] */
#define BCHP_WRAP_MISC_SECURE_INTR2_PCI_MASK_SET_AVD_VICH_MASK_MASK 0x0000001c
#define BCHP_WRAP_MISC_SECURE_INTR2_PCI_MASK_SET_AVD_VICH_MASK_SHIFT 2

/* WRAP_MISC_SECURE_INTR2 :: PCI_MASK_SET :: ARB_WRITE_CHECKER_MASK [01:01] */
#define BCHP_WRAP_MISC_SECURE_INTR2_PCI_MASK_SET_ARB_WRITE_CHECKER_MASK_MASK 0x00000002
#define BCHP_WRAP_MISC_SECURE_INTR2_PCI_MASK_SET_ARB_WRITE_CHECKER_MASK_SHIFT 1

/* WRAP_MISC_SECURE_INTR2 :: PCI_MASK_SET :: ARB_SARCH_MASK [00:00] */
#define BCHP_WRAP_MISC_SECURE_INTR2_PCI_MASK_SET_ARB_SARCH_MASK_MASK 0x00000001
#define BCHP_WRAP_MISC_SECURE_INTR2_PCI_MASK_SET_ARB_SARCH_MASK_SHIFT 0

/***************************************************************************
 *PCI_MASK_CLEAR - PCI interrupt Mask Clear Register
 ***************************************************************************/
/* WRAP_MISC_SECURE_INTR2 :: PCI_MASK_CLEAR :: reserved0 [31:09] */
#define BCHP_WRAP_MISC_SECURE_INTR2_PCI_MASK_CLEAR_reserved0_MASK  0xfffffe00
#define BCHP_WRAP_MISC_SECURE_INTR2_PCI_MASK_CLEAR_reserved0_SHIFT 9

/* WRAP_MISC_SECURE_INTR2 :: PCI_MASK_CLEAR :: STARCH_SECURE_MASK [08:08] */
#define BCHP_WRAP_MISC_SECURE_INTR2_PCI_MASK_CLEAR_STARCH_SECURE_MASK_MASK 0x00000100
#define BCHP_WRAP_MISC_SECURE_INTR2_PCI_MASK_CLEAR_STARCH_SECURE_MASK_SHIFT 8

/* WRAP_MISC_SECURE_INTR2 :: PCI_MASK_CLEAR :: GISB_SECURE_BREAKPOINT_MASK [07:07] */
#define BCHP_WRAP_MISC_SECURE_INTR2_PCI_MASK_CLEAR_GISB_SECURE_BREAKPOINT_MASK_MASK 0x00000080
#define BCHP_WRAP_MISC_SECURE_INTR2_PCI_MASK_CLEAR_GISB_SECURE_BREAKPOINT_MASK_SHIFT 7

/* WRAP_MISC_SECURE_INTR2 :: PCI_MASK_CLEAR :: SHARF_SECURE_MASK [06:06] */
#define BCHP_WRAP_MISC_SECURE_INTR2_PCI_MASK_CLEAR_SHARF_SECURE_MASK_MASK 0x00000040
#define BCHP_WRAP_MISC_SECURE_INTR2_PCI_MASK_CLEAR_SHARF_SECURE_MASK_SHIFT 6

/* WRAP_MISC_SECURE_INTR2 :: PCI_MASK_CLEAR :: XPT_WR_CHECKER_MASK [05:05] */
#define BCHP_WRAP_MISC_SECURE_INTR2_PCI_MASK_CLEAR_XPT_WR_CHECKER_MASK_MASK 0x00000020
#define BCHP_WRAP_MISC_SECURE_INTR2_PCI_MASK_CLEAR_XPT_WR_CHECKER_MASK_SHIFT 5

/* WRAP_MISC_SECURE_INTR2 :: PCI_MASK_CLEAR :: AVD_VICH_MASK [04:02] */
#define BCHP_WRAP_MISC_SECURE_INTR2_PCI_MASK_CLEAR_AVD_VICH_MASK_MASK 0x0000001c
#define BCHP_WRAP_MISC_SECURE_INTR2_PCI_MASK_CLEAR_AVD_VICH_MASK_SHIFT 2

/* WRAP_MISC_SECURE_INTR2 :: PCI_MASK_CLEAR :: ARB_WRITE_CHECKER_MASK [01:01] */
#define BCHP_WRAP_MISC_SECURE_INTR2_PCI_MASK_CLEAR_ARB_WRITE_CHECKER_MASK_MASK 0x00000002
#define BCHP_WRAP_MISC_SECURE_INTR2_PCI_MASK_CLEAR_ARB_WRITE_CHECKER_MASK_SHIFT 1

/* WRAP_MISC_SECURE_INTR2 :: PCI_MASK_CLEAR :: ARB_SARCH_MASK [00:00] */
#define BCHP_WRAP_MISC_SECURE_INTR2_PCI_MASK_CLEAR_ARB_SARCH_MASK_MASK 0x00000001
#define BCHP_WRAP_MISC_SECURE_INTR2_PCI_MASK_CLEAR_ARB_SARCH_MASK_SHIFT 0

#endif /* #ifndef BCHP_WRAP_MISC_SECURE_INTR2_H__ */

/* End of File */
