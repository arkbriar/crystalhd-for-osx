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
 * $brcm_Workfile: bchp_pcie_dll.h $
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
 * Date:           Generated on         Fri Jul 17 19:42:21 2009
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
 * $brcm_Log: /magnum/basemodules/chp/70015/rdb/a0/bchp_pcie_dll.h $
 * 
 * Hydra_Software_Devel/1   7/17/09 8:13p albertl
 * PR56880: Initial revision.
 *
 ***************************************************************************/

#ifndef BCHP_PCIE_DLL_H__
#define BCHP_PCIE_DLL_H__

/***************************************************************************
 *PCIE_DLL - PCIE DLL related registers
 ***************************************************************************/
#define BCHP_PCIE_DLL_DATA_LINK_CONTROL          0x00500500 /* DATA_LINK_CONTROL Register */
#define BCHP_PCIE_DLL_DATA_LINK_STATUS           0x00500504 /* DATA_LINK_STATUS Register */
#define BCHP_PCIE_DLL_DATA_LINK_ATTENTION        0x00500508 /* DATA_LINK_ATTENTION Register */
#define BCHP_PCIE_DLL_DATA_LINK_ATTENTION_MASK   0x0050050c /* DATA_LINK_ATTENTION_MASK Register */
#define BCHP_PCIE_DLL_NEXT_TRANSMIT_SEQUENCE_NUMBER_DEBUG 0x00500510 /* NEXT_TRANSMIT_SEQUENCE_NUMBER_DEBUG Register */
#define BCHP_PCIE_DLL_ACK_ED_TRANSMIT_SEQUENCE_NUMBER_DEBUG 0x00500514 /* ACK_ED_TRANSMIT_SEQUENCE_NUMBER_DEBUG Register */
#define BCHP_PCIE_DLL_PURGED_TRANSMIT_SEQUENCE_NUMBER_DEBUG 0x00500518 /* PURGED_TRANSMIT_SEQUENCE_NUMBER_DEBUG Register */
#define BCHP_PCIE_DLL_RECEIVE_SEQUENCE_NUMBER_DEBUG 0x0050051c /* RECEIVE_SEQUENCE_NUMBER_DEBUG Register */
#define BCHP_PCIE_DLL_DATA_LINK_REPLAY           0x00500520 /* DATA_LINK_REPLAY Register */
#define BCHP_PCIE_DLL_DATA_LINK_ACK_TIMEOUT      0x00500524 /* DATA_LINK_ACK_TIMEOUT Register */
#define BCHP_PCIE_DLL_POWER_MANAGEMENT_THRESHOLD 0x00500528 /* POWER_MANAGEMENT_THRESHOLD Register */
#define BCHP_PCIE_DLL_RETRY_BUFFER_WRITE_POINTER_DEBUG 0x0050052c /* RETRY_BUFFER_WRITE_POINTER_DEBUG Register */
#define BCHP_PCIE_DLL_RETRY_BUFFER_READ_POINTER_DEBUG 0x00500530 /* RETRY_BUFFER_READ_POINTER_DEBUG Register */
#define BCHP_PCIE_DLL_RETRY_BUFFER_PURGED_POINTER_DEBUG 0x00500534 /* RETRY_BUFFER_PURGED_POINTER_DEBUG Register */
#define BCHP_PCIE_DLL_RETRY_BUFFER_READ_WRITE_DEBUG_PORT 0x00500538 /* RETRY_BUFFER_READ_WRITE_DEBUG_PORT Register */
#define BCHP_PCIE_DLL_ERROR_COUNT_THRESHOLD      0x0050053c /* ERROR_COUNT_THRESHOLD Register */
#define BCHP_PCIE_DLL_TL_ERROR_COUNTER           0x00500540 /* TL_ERROR_COUNTER Register */
#define BCHP_PCIE_DLL_DLLP_ERROR_COUNTER         0x00500544 /* DLLP_ERROR_COUNTER Register */
#define BCHP_PCIE_DLL_NAK_RECEIVED_COUNTER       0x00500548 /* NAK_RECEIVED_COUNTER Register */
#define BCHP_PCIE_DLL_DATA_LINK_TEST             0x0050054c /* DATA_LINK_TEST Register */
#define BCHP_PCIE_DLL_PACKET_BIST                0x00500550 /* PACKET_BIST Register */
#define BCHP_PCIE_DLL_LINK_PCIE_1_1_CONTROL      0x00500554 /* LINK_PCIE_1_1_CONTROL Register */

/***************************************************************************
 *DATA_LINK_CONTROL - DATA_LINK_CONTROL Register
 ***************************************************************************/
/* PCIE_DLL :: DATA_LINK_CONTROL :: RESERVED_0 [31:31] */
#define BCHP_PCIE_DLL_DATA_LINK_CONTROL_RESERVED_0_MASK            0x80000000
#define BCHP_PCIE_DLL_DATA_LINK_CONTROL_RESERVED_0_SHIFT           31

/* PCIE_DLL :: DATA_LINK_CONTROL :: CQ28102_FIX_ENABLE [30:30] */
#define BCHP_PCIE_DLL_DATA_LINK_CONTROL_CQ28102_FIX_ENABLE_MASK    0x40000000
#define BCHP_PCIE_DLL_DATA_LINK_CONTROL_CQ28102_FIX_ENABLE_SHIFT   30

/* PCIE_DLL :: DATA_LINK_CONTROL :: CQ28001_FIX_ENABLE [29:29] */
#define BCHP_PCIE_DLL_DATA_LINK_CONTROL_CQ28001_FIX_ENABLE_MASK    0x20000000
#define BCHP_PCIE_DLL_DATA_LINK_CONTROL_CQ28001_FIX_ENABLE_SHIFT   29

/* PCIE_DLL :: DATA_LINK_CONTROL :: CQ27820_FIX_ENABLE [28:28] */
#define BCHP_PCIE_DLL_DATA_LINK_CONTROL_CQ27820_FIX_ENABLE_MASK    0x10000000
#define BCHP_PCIE_DLL_DATA_LINK_CONTROL_CQ27820_FIX_ENABLE_SHIFT   28

/* PCIE_DLL :: DATA_LINK_CONTROL :: ASPM_L1_ENABLE [27:27] */
#define BCHP_PCIE_DLL_DATA_LINK_CONTROL_ASPM_L1_ENABLE_MASK        0x08000000
#define BCHP_PCIE_DLL_DATA_LINK_CONTROL_ASPM_L1_ENABLE_SHIFT       27

/* PCIE_DLL :: DATA_LINK_CONTROL :: RESERVED_1 [26:25] */
#define BCHP_PCIE_DLL_DATA_LINK_CONTROL_RESERVED_1_MASK            0x06000000
#define BCHP_PCIE_DLL_DATA_LINK_CONTROL_RESERVED_1_SHIFT           25

/* PCIE_DLL :: DATA_LINK_CONTROL :: CQ11211 [24:24] */
#define BCHP_PCIE_DLL_DATA_LINK_CONTROL_CQ11211_MASK               0x01000000
#define BCHP_PCIE_DLL_DATA_LINK_CONTROL_CQ11211_SHIFT              24

/* PCIE_DLL :: DATA_LINK_CONTROL :: RESERVED_2 [23:23] */
#define BCHP_PCIE_DLL_DATA_LINK_CONTROL_RESERVED_2_MASK            0x00800000
#define BCHP_PCIE_DLL_DATA_LINK_CONTROL_RESERVED_2_SHIFT           23

/* PCIE_DLL :: DATA_LINK_CONTROL :: RESERVED_3 [22:22] */
#define BCHP_PCIE_DLL_DATA_LINK_CONTROL_RESERVED_3_MASK            0x00400000
#define BCHP_PCIE_DLL_DATA_LINK_CONTROL_RESERVED_3_SHIFT           22

/* PCIE_DLL :: DATA_LINK_CONTROL :: RESERVED_4 [21:21] */
#define BCHP_PCIE_DLL_DATA_LINK_CONTROL_RESERVED_4_MASK            0x00200000
#define BCHP_PCIE_DLL_DATA_LINK_CONTROL_RESERVED_4_SHIFT           21

/* PCIE_DLL :: DATA_LINK_CONTROL :: RESERVED_5 [20:20] */
#define BCHP_PCIE_DLL_DATA_LINK_CONTROL_RESERVED_5_MASK            0x00100000
#define BCHP_PCIE_DLL_DATA_LINK_CONTROL_RESERVED_5_SHIFT           20

/* PCIE_DLL :: DATA_LINK_CONTROL :: RESERVED_6 [19:19] */
#define BCHP_PCIE_DLL_DATA_LINK_CONTROL_RESERVED_6_MASK            0x00080000
#define BCHP_PCIE_DLL_DATA_LINK_CONTROL_RESERVED_6_SHIFT           19

/* PCIE_DLL :: DATA_LINK_CONTROL :: PLL_REFSEL_SWITCH_CONTROL_CQ11011 [18:18] */
#define BCHP_PCIE_DLL_DATA_LINK_CONTROL_PLL_REFSEL_SWITCH_CONTROL_CQ11011_MASK 0x00040000
#define BCHP_PCIE_DLL_DATA_LINK_CONTROL_PLL_REFSEL_SWITCH_CONTROL_CQ11011_SHIFT 18

/* PCIE_DLL :: DATA_LINK_CONTROL :: RESERVED_7 [17:17] */
#define BCHP_PCIE_DLL_DATA_LINK_CONTROL_RESERVED_7_MASK            0x00020000
#define BCHP_PCIE_DLL_DATA_LINK_CONTROL_RESERVED_7_SHIFT           17

/* PCIE_DLL :: DATA_LINK_CONTROL :: POWER_MANAGEMENT_CONTROL [16:16] */
#define BCHP_PCIE_DLL_DATA_LINK_CONTROL_POWER_MANAGEMENT_CONTROL_MASK 0x00010000
#define BCHP_PCIE_DLL_DATA_LINK_CONTROL_POWER_MANAGEMENT_CONTROL_SHIFT 16

/* PCIE_DLL :: DATA_LINK_CONTROL :: POWER_DOWN_SERDES_TRANSMITTER [15:15] */
#define BCHP_PCIE_DLL_DATA_LINK_CONTROL_POWER_DOWN_SERDES_TRANSMITTER_MASK 0x00008000
#define BCHP_PCIE_DLL_DATA_LINK_CONTROL_POWER_DOWN_SERDES_TRANSMITTER_SHIFT 15

/* PCIE_DLL :: DATA_LINK_CONTROL :: POWER_DOWN_SERDES_PLL [14:14] */
#define BCHP_PCIE_DLL_DATA_LINK_CONTROL_POWER_DOWN_SERDES_PLL_MASK 0x00004000
#define BCHP_PCIE_DLL_DATA_LINK_CONTROL_POWER_DOWN_SERDES_PLL_SHIFT 14

/* PCIE_DLL :: DATA_LINK_CONTROL :: POWER_DOWN_SERDES_RECEIVER [13:13] */
#define BCHP_PCIE_DLL_DATA_LINK_CONTROL_POWER_DOWN_SERDES_RECEIVER_MASK 0x00002000
#define BCHP_PCIE_DLL_DATA_LINK_CONTROL_POWER_DOWN_SERDES_RECEIVER_SHIFT 13

/* PCIE_DLL :: DATA_LINK_CONTROL :: ENABLE_BEACON [12:12] */
#define BCHP_PCIE_DLL_DATA_LINK_CONTROL_ENABLE_BEACON_MASK         0x00001000
#define BCHP_PCIE_DLL_DATA_LINK_CONTROL_ENABLE_BEACON_SHIFT        12

/* PCIE_DLL :: DATA_LINK_CONTROL :: AUTOMATIC_TIMER_THRESHOLD_ENABLE [11:11] */
#define BCHP_PCIE_DLL_DATA_LINK_CONTROL_AUTOMATIC_TIMER_THRESHOLD_ENABLE_MASK 0x00000800
#define BCHP_PCIE_DLL_DATA_LINK_CONTROL_AUTOMATIC_TIMER_THRESHOLD_ENABLE_SHIFT 11

/* PCIE_DLL :: DATA_LINK_CONTROL :: ENABLE_DLLP_TIMEOUT_MECHANISM [10:10] */
#define BCHP_PCIE_DLL_DATA_LINK_CONTROL_ENABLE_DLLP_TIMEOUT_MECHANISM_MASK 0x00000400
#define BCHP_PCIE_DLL_DATA_LINK_CONTROL_ENABLE_DLLP_TIMEOUT_MECHANISM_SHIFT 10

/* PCIE_DLL :: DATA_LINK_CONTROL :: CHECK_RECEIVE_FLOW_CONTROL_CREDITS [09:09] */
#define BCHP_PCIE_DLL_DATA_LINK_CONTROL_CHECK_RECEIVE_FLOW_CONTROL_CREDITS_MASK 0x00000200
#define BCHP_PCIE_DLL_DATA_LINK_CONTROL_CHECK_RECEIVE_FLOW_CONTROL_CREDITS_SHIFT 9

/* PCIE_DLL :: DATA_LINK_CONTROL :: LINK_ENABLE [08:08] */
#define BCHP_PCIE_DLL_DATA_LINK_CONTROL_LINK_ENABLE_MASK           0x00000100
#define BCHP_PCIE_DLL_DATA_LINK_CONTROL_LINK_ENABLE_SHIFT          8

/* PCIE_DLL :: DATA_LINK_CONTROL :: POWER_MANAGEMENT_CONTROL_2 [07:00] */
#define BCHP_PCIE_DLL_DATA_LINK_CONTROL_POWER_MANAGEMENT_CONTROL_2_MASK 0x000000ff
#define BCHP_PCIE_DLL_DATA_LINK_CONTROL_POWER_MANAGEMENT_CONTROL_2_SHIFT 0

/***************************************************************************
 *DATA_LINK_STATUS - DATA_LINK_STATUS Register
 ***************************************************************************/
/* PCIE_DLL :: DATA_LINK_STATUS :: RESERVED_0 [31:26] */
#define BCHP_PCIE_DLL_DATA_LINK_STATUS_RESERVED_0_MASK             0xfc000000
#define BCHP_PCIE_DLL_DATA_LINK_STATUS_RESERVED_0_SHIFT            26

/* PCIE_DLL :: DATA_LINK_STATUS :: PHY_LINK_STATE [25:23] */
#define BCHP_PCIE_DLL_DATA_LINK_STATUS_PHY_LINK_STATE_MASK         0x03800000
#define BCHP_PCIE_DLL_DATA_LINK_STATUS_PHY_LINK_STATE_SHIFT        23

/* PCIE_DLL :: DATA_LINK_STATUS :: POWER_MANAGEMENT_STATE [22:19] */
#define BCHP_PCIE_DLL_DATA_LINK_STATUS_POWER_MANAGEMENT_STATE_MASK 0x00780000
#define BCHP_PCIE_DLL_DATA_LINK_STATUS_POWER_MANAGEMENT_STATE_SHIFT 19

/* PCIE_DLL :: DATA_LINK_STATUS :: POWER_MANAGEMENT_SUB_STATE [18:17] */
#define BCHP_PCIE_DLL_DATA_LINK_STATUS_POWER_MANAGEMENT_SUB_STATE_MASK 0x00060000
#define BCHP_PCIE_DLL_DATA_LINK_STATUS_POWER_MANAGEMENT_SUB_STATE_SHIFT 17

/* PCIE_DLL :: DATA_LINK_STATUS :: DATA_LINK_UP [16:16] */
#define BCHP_PCIE_DLL_DATA_LINK_STATUS_DATA_LINK_UP_MASK           0x00010000
#define BCHP_PCIE_DLL_DATA_LINK_STATUS_DATA_LINK_UP_SHIFT          16

/* PCIE_DLL :: DATA_LINK_STATUS :: RESERVED_1 [15:11] */
#define BCHP_PCIE_DLL_DATA_LINK_STATUS_RESERVED_1_MASK             0x0000f800
#define BCHP_PCIE_DLL_DATA_LINK_STATUS_RESERVED_1_SHIFT            11

/* PCIE_DLL :: DATA_LINK_STATUS :: PME_TURN_OFF_STATUS_IN_D0 [10:10] */
#define BCHP_PCIE_DLL_DATA_LINK_STATUS_PME_TURN_OFF_STATUS_IN_D0_MASK 0x00000400
#define BCHP_PCIE_DLL_DATA_LINK_STATUS_PME_TURN_OFF_STATUS_IN_D0_SHIFT 10

/* PCIE_DLL :: DATA_LINK_STATUS :: FLOW_CONTROL_UPDATE_TIMEOUT [09:09] */
#define BCHP_PCIE_DLL_DATA_LINK_STATUS_FLOW_CONTROL_UPDATE_TIMEOUT_MASK 0x00000200
#define BCHP_PCIE_DLL_DATA_LINK_STATUS_FLOW_CONTROL_UPDATE_TIMEOUT_SHIFT 9

/* PCIE_DLL :: DATA_LINK_STATUS :: FLOW_CONTROL_RECEIVE_OVERFLOW [08:08] */
#define BCHP_PCIE_DLL_DATA_LINK_STATUS_FLOW_CONTROL_RECEIVE_OVERFLOW_MASK 0x00000100
#define BCHP_PCIE_DLL_DATA_LINK_STATUS_FLOW_CONTROL_RECEIVE_OVERFLOW_SHIFT 8

/* PCIE_DLL :: DATA_LINK_STATUS :: FLOW_CONTROL_PROTOCOL_ERROR [07:07] */
#define BCHP_PCIE_DLL_DATA_LINK_STATUS_FLOW_CONTROL_PROTOCOL_ERROR_MASK 0x00000080
#define BCHP_PCIE_DLL_DATA_LINK_STATUS_FLOW_CONTROL_PROTOCOL_ERROR_SHIFT 7

/* PCIE_DLL :: DATA_LINK_STATUS :: DATA_LINK_PROTOCOL_ERROR [06:06] */
#define BCHP_PCIE_DLL_DATA_LINK_STATUS_DATA_LINK_PROTOCOL_ERROR_MASK 0x00000040
#define BCHP_PCIE_DLL_DATA_LINK_STATUS_DATA_LINK_PROTOCOL_ERROR_SHIFT 6

/* PCIE_DLL :: DATA_LINK_STATUS :: REPLAY_ROLLOVER [05:05] */
#define BCHP_PCIE_DLL_DATA_LINK_STATUS_REPLAY_ROLLOVER_MASK        0x00000020
#define BCHP_PCIE_DLL_DATA_LINK_STATUS_REPLAY_ROLLOVER_SHIFT       5

/* PCIE_DLL :: DATA_LINK_STATUS :: REPLAY_TIMEOUT [04:04] */
#define BCHP_PCIE_DLL_DATA_LINK_STATUS_REPLAY_TIMEOUT_MASK         0x00000010
#define BCHP_PCIE_DLL_DATA_LINK_STATUS_REPLAY_TIMEOUT_SHIFT        4

/* PCIE_DLL :: DATA_LINK_STATUS :: NAK_RECEIVED [03:03] */
#define BCHP_PCIE_DLL_DATA_LINK_STATUS_NAK_RECEIVED_MASK           0x00000008
#define BCHP_PCIE_DLL_DATA_LINK_STATUS_NAK_RECEIVED_SHIFT          3

/* PCIE_DLL :: DATA_LINK_STATUS :: DLLP_ERROR [02:02] */
#define BCHP_PCIE_DLL_DATA_LINK_STATUS_DLLP_ERROR_MASK             0x00000004
#define BCHP_PCIE_DLL_DATA_LINK_STATUS_DLLP_ERROR_SHIFT            2

/* PCIE_DLL :: DATA_LINK_STATUS :: BAD_TLP_SEQUENCE_NUMBER [01:01] */
#define BCHP_PCIE_DLL_DATA_LINK_STATUS_BAD_TLP_SEQUENCE_NUMBER_MASK 0x00000002
#define BCHP_PCIE_DLL_DATA_LINK_STATUS_BAD_TLP_SEQUENCE_NUMBER_SHIFT 1

/* PCIE_DLL :: DATA_LINK_STATUS :: TLP_ERROR [00:00] */
#define BCHP_PCIE_DLL_DATA_LINK_STATUS_TLP_ERROR_MASK              0x00000001
#define BCHP_PCIE_DLL_DATA_LINK_STATUS_TLP_ERROR_SHIFT             0

/***************************************************************************
 *DATA_LINK_ATTENTION - DATA_LINK_ATTENTION Register
 ***************************************************************************/
/* PCIE_DLL :: DATA_LINK_ATTENTION :: RESERVED_0 [31:06] */
#define BCHP_PCIE_DLL_DATA_LINK_ATTENTION_RESERVED_0_MASK          0xffffffc0
#define BCHP_PCIE_DLL_DATA_LINK_ATTENTION_RESERVED_0_SHIFT         6

/* PCIE_DLL :: DATA_LINK_ATTENTION :: DATA_LINK_LAYER_PACKET_TEST_INDICATOR [05:05] */
#define BCHP_PCIE_DLL_DATA_LINK_ATTENTION_DATA_LINK_LAYER_PACKET_TEST_INDICATOR_MASK 0x00000020
#define BCHP_PCIE_DLL_DATA_LINK_ATTENTION_DATA_LINK_LAYER_PACKET_TEST_INDICATOR_SHIFT 5

/* PCIE_DLL :: DATA_LINK_ATTENTION :: DATA_LINK_LAYER_ERROR_ATTENTION_INDICATOR [04:04] */
#define BCHP_PCIE_DLL_DATA_LINK_ATTENTION_DATA_LINK_LAYER_ERROR_ATTENTION_INDICATOR_MASK 0x00000010
#define BCHP_PCIE_DLL_DATA_LINK_ATTENTION_DATA_LINK_LAYER_ERROR_ATTENTION_INDICATOR_SHIFT 4

/* PCIE_DLL :: DATA_LINK_ATTENTION :: NAK_RECEIVED_COUNTER_ATTENTION_INDICATOR [03:03] */
#define BCHP_PCIE_DLL_DATA_LINK_ATTENTION_NAK_RECEIVED_COUNTER_ATTENTION_INDICATOR_MASK 0x00000008
#define BCHP_PCIE_DLL_DATA_LINK_ATTENTION_NAK_RECEIVED_COUNTER_ATTENTION_INDICATOR_SHIFT 3

/* PCIE_DLL :: DATA_LINK_ATTENTION :: DLLP_ERROR_COUNTER_ATTENTION_INDICATOR [02:02] */
#define BCHP_PCIE_DLL_DATA_LINK_ATTENTION_DLLP_ERROR_COUNTER_ATTENTION_INDICATOR_MASK 0x00000004
#define BCHP_PCIE_DLL_DATA_LINK_ATTENTION_DLLP_ERROR_COUNTER_ATTENTION_INDICATOR_SHIFT 2

/* PCIE_DLL :: DATA_LINK_ATTENTION :: TLP_BAD_SEQUENCE_COUNTER_ATTENTION_INDICATOR [01:01] */
#define BCHP_PCIE_DLL_DATA_LINK_ATTENTION_TLP_BAD_SEQUENCE_COUNTER_ATTENTION_INDICATOR_MASK 0x00000002
#define BCHP_PCIE_DLL_DATA_LINK_ATTENTION_TLP_BAD_SEQUENCE_COUNTER_ATTENTION_INDICATOR_SHIFT 1

/* PCIE_DLL :: DATA_LINK_ATTENTION :: TLP_ERROR_COUNTER_ATTENTION_INDICATOR [00:00] */
#define BCHP_PCIE_DLL_DATA_LINK_ATTENTION_TLP_ERROR_COUNTER_ATTENTION_INDICATOR_MASK 0x00000001
#define BCHP_PCIE_DLL_DATA_LINK_ATTENTION_TLP_ERROR_COUNTER_ATTENTION_INDICATOR_SHIFT 0

/***************************************************************************
 *DATA_LINK_ATTENTION_MASK - DATA_LINK_ATTENTION_MASK Register
 ***************************************************************************/
/* PCIE_DLL :: DATA_LINK_ATTENTION_MASK :: RESERVED_0 [31:08] */
#define BCHP_PCIE_DLL_DATA_LINK_ATTENTION_MASK_RESERVED_0_MASK     0xffffff00
#define BCHP_PCIE_DLL_DATA_LINK_ATTENTION_MASK_RESERVED_0_SHIFT    8

/* PCIE_DLL :: DATA_LINK_ATTENTION_MASK :: UNUSED_0 [07:06] */
#define BCHP_PCIE_DLL_DATA_LINK_ATTENTION_MASK_UNUSED_0_MASK       0x000000c0
#define BCHP_PCIE_DLL_DATA_LINK_ATTENTION_MASK_UNUSED_0_SHIFT      6

/* PCIE_DLL :: DATA_LINK_ATTENTION_MASK :: DATA_LINK_LAYER_PACKET_TEST_ATTENTION_MASK [05:05] */
#define BCHP_PCIE_DLL_DATA_LINK_ATTENTION_MASK_DATA_LINK_LAYER_PACKET_TEST_ATTENTION_MASK_MASK 0x00000020
#define BCHP_PCIE_DLL_DATA_LINK_ATTENTION_MASK_DATA_LINK_LAYER_PACKET_TEST_ATTENTION_MASK_SHIFT 5

/* PCIE_DLL :: DATA_LINK_ATTENTION_MASK :: DATA_LINK_LAYER_ERROR_ATTENTION_MASK [04:04] */
#define BCHP_PCIE_DLL_DATA_LINK_ATTENTION_MASK_DATA_LINK_LAYER_ERROR_ATTENTION_MASK_MASK 0x00000010
#define BCHP_PCIE_DLL_DATA_LINK_ATTENTION_MASK_DATA_LINK_LAYER_ERROR_ATTENTION_MASK_SHIFT 4

/* PCIE_DLL :: DATA_LINK_ATTENTION_MASK :: NAK_RECEIVED_COUNTER_ATTENTION_MASK [03:03] */
#define BCHP_PCIE_DLL_DATA_LINK_ATTENTION_MASK_NAK_RECEIVED_COUNTER_ATTENTION_MASK_MASK 0x00000008
#define BCHP_PCIE_DLL_DATA_LINK_ATTENTION_MASK_NAK_RECEIVED_COUNTER_ATTENTION_MASK_SHIFT 3

/* PCIE_DLL :: DATA_LINK_ATTENTION_MASK :: DLLP_ERROR_COUNTER_ATTENTION_MASK [02:02] */
#define BCHP_PCIE_DLL_DATA_LINK_ATTENTION_MASK_DLLP_ERROR_COUNTER_ATTENTION_MASK_MASK 0x00000004
#define BCHP_PCIE_DLL_DATA_LINK_ATTENTION_MASK_DLLP_ERROR_COUNTER_ATTENTION_MASK_SHIFT 2

/* PCIE_DLL :: DATA_LINK_ATTENTION_MASK :: TLP_BAD_SEQUENCE_COUNTER_ATTENTION_MASK [01:01] */
#define BCHP_PCIE_DLL_DATA_LINK_ATTENTION_MASK_TLP_BAD_SEQUENCE_COUNTER_ATTENTION_MASK_MASK 0x00000002
#define BCHP_PCIE_DLL_DATA_LINK_ATTENTION_MASK_TLP_BAD_SEQUENCE_COUNTER_ATTENTION_MASK_SHIFT 1

/* PCIE_DLL :: DATA_LINK_ATTENTION_MASK :: TLP_ERROR_COUNTER_ATTENTION_MASK [00:00] */
#define BCHP_PCIE_DLL_DATA_LINK_ATTENTION_MASK_TLP_ERROR_COUNTER_ATTENTION_MASK_MASK 0x00000001
#define BCHP_PCIE_DLL_DATA_LINK_ATTENTION_MASK_TLP_ERROR_COUNTER_ATTENTION_MASK_SHIFT 0

/***************************************************************************
 *NEXT_TRANSMIT_SEQUENCE_NUMBER_DEBUG - NEXT_TRANSMIT_SEQUENCE_NUMBER_DEBUG Register
 ***************************************************************************/
/* PCIE_DLL :: NEXT_TRANSMIT_SEQUENCE_NUMBER_DEBUG :: RESERVED_0 [31:12] */
#define BCHP_PCIE_DLL_NEXT_TRANSMIT_SEQUENCE_NUMBER_DEBUG_RESERVED_0_MASK 0xfffff000
#define BCHP_PCIE_DLL_NEXT_TRANSMIT_SEQUENCE_NUMBER_DEBUG_RESERVED_0_SHIFT 12

/* PCIE_DLL :: NEXT_TRANSMIT_SEQUENCE_NUMBER_DEBUG :: NEXT_TRANSMIT_SEQUENCE_NUMBER [11:00] */
#define BCHP_PCIE_DLL_NEXT_TRANSMIT_SEQUENCE_NUMBER_DEBUG_NEXT_TRANSMIT_SEQUENCE_NUMBER_MASK 0x00000fff
#define BCHP_PCIE_DLL_NEXT_TRANSMIT_SEQUENCE_NUMBER_DEBUG_NEXT_TRANSMIT_SEQUENCE_NUMBER_SHIFT 0

/***************************************************************************
 *ACK_ED_TRANSMIT_SEQUENCE_NUMBER_DEBUG - ACK_ED_TRANSMIT_SEQUENCE_NUMBER_DEBUG Register
 ***************************************************************************/
/* PCIE_DLL :: ACK_ED_TRANSMIT_SEQUENCE_NUMBER_DEBUG :: RESERVED_0 [31:12] */
#define BCHP_PCIE_DLL_ACK_ED_TRANSMIT_SEQUENCE_NUMBER_DEBUG_RESERVED_0_MASK 0xfffff000
#define BCHP_PCIE_DLL_ACK_ED_TRANSMIT_SEQUENCE_NUMBER_DEBUG_RESERVED_0_SHIFT 12

/* PCIE_DLL :: ACK_ED_TRANSMIT_SEQUENCE_NUMBER_DEBUG :: ACK_ED_TRANSMIT_SEQUENCE_NUMBER [11:00] */
#define BCHP_PCIE_DLL_ACK_ED_TRANSMIT_SEQUENCE_NUMBER_DEBUG_ACK_ED_TRANSMIT_SEQUENCE_NUMBER_MASK 0x00000fff
#define BCHP_PCIE_DLL_ACK_ED_TRANSMIT_SEQUENCE_NUMBER_DEBUG_ACK_ED_TRANSMIT_SEQUENCE_NUMBER_SHIFT 0

/***************************************************************************
 *PURGED_TRANSMIT_SEQUENCE_NUMBER_DEBUG - PURGED_TRANSMIT_SEQUENCE_NUMBER_DEBUG Register
 ***************************************************************************/
/* PCIE_DLL :: PURGED_TRANSMIT_SEQUENCE_NUMBER_DEBUG :: RESERVED_0 [31:12] */
#define BCHP_PCIE_DLL_PURGED_TRANSMIT_SEQUENCE_NUMBER_DEBUG_RESERVED_0_MASK 0xfffff000
#define BCHP_PCIE_DLL_PURGED_TRANSMIT_SEQUENCE_NUMBER_DEBUG_RESERVED_0_SHIFT 12

/* PCIE_DLL :: PURGED_TRANSMIT_SEQUENCE_NUMBER_DEBUG :: PURGED_TRANSMIT_SEQUENCE_NUMBER [11:00] */
#define BCHP_PCIE_DLL_PURGED_TRANSMIT_SEQUENCE_NUMBER_DEBUG_PURGED_TRANSMIT_SEQUENCE_NUMBER_MASK 0x00000fff
#define BCHP_PCIE_DLL_PURGED_TRANSMIT_SEQUENCE_NUMBER_DEBUG_PURGED_TRANSMIT_SEQUENCE_NUMBER_SHIFT 0

/***************************************************************************
 *RECEIVE_SEQUENCE_NUMBER_DEBUG - RECEIVE_SEQUENCE_NUMBER_DEBUG Register
 ***************************************************************************/
/* PCIE_DLL :: RECEIVE_SEQUENCE_NUMBER_DEBUG :: RESERVED_0 [31:12] */
#define BCHP_PCIE_DLL_RECEIVE_SEQUENCE_NUMBER_DEBUG_RESERVED_0_MASK 0xfffff000
#define BCHP_PCIE_DLL_RECEIVE_SEQUENCE_NUMBER_DEBUG_RESERVED_0_SHIFT 12

/* PCIE_DLL :: RECEIVE_SEQUENCE_NUMBER_DEBUG :: RECEIVE_SEQUENCE_NUMBER [11:00] */
#define BCHP_PCIE_DLL_RECEIVE_SEQUENCE_NUMBER_DEBUG_RECEIVE_SEQUENCE_NUMBER_MASK 0x00000fff
#define BCHP_PCIE_DLL_RECEIVE_SEQUENCE_NUMBER_DEBUG_RECEIVE_SEQUENCE_NUMBER_SHIFT 0

/***************************************************************************
 *DATA_LINK_REPLAY - DATA_LINK_REPLAY Register
 ***************************************************************************/
/* PCIE_DLL :: DATA_LINK_REPLAY :: RESERVED_0 [31:23] */
#define BCHP_PCIE_DLL_DATA_LINK_REPLAY_RESERVED_0_MASK             0xff800000
#define BCHP_PCIE_DLL_DATA_LINK_REPLAY_RESERVED_0_SHIFT            23

/* PCIE_DLL :: DATA_LINK_REPLAY :: REPLAY_TIMEOUT_VALUE [22:10] */
#define BCHP_PCIE_DLL_DATA_LINK_REPLAY_REPLAY_TIMEOUT_VALUE_MASK   0x007ffc00
#define BCHP_PCIE_DLL_DATA_LINK_REPLAY_REPLAY_TIMEOUT_VALUE_SHIFT  10

/* PCIE_DLL :: DATA_LINK_REPLAY :: REPLAY_BUFFER_SIZE [09:00] */
#define BCHP_PCIE_DLL_DATA_LINK_REPLAY_REPLAY_BUFFER_SIZE_MASK     0x000003ff
#define BCHP_PCIE_DLL_DATA_LINK_REPLAY_REPLAY_BUFFER_SIZE_SHIFT    0

/***************************************************************************
 *DATA_LINK_ACK_TIMEOUT - DATA_LINK_ACK_TIMEOUT Register
 ***************************************************************************/
/* PCIE_DLL :: DATA_LINK_ACK_TIMEOUT :: RESERVED_0 [31:11] */
#define BCHP_PCIE_DLL_DATA_LINK_ACK_TIMEOUT_RESERVED_0_MASK        0xfffff800
#define BCHP_PCIE_DLL_DATA_LINK_ACK_TIMEOUT_RESERVED_0_SHIFT       11

/* PCIE_DLL :: DATA_LINK_ACK_TIMEOUT :: ACK_LATENCY_TIMEOUT_VALUE [10:00] */
#define BCHP_PCIE_DLL_DATA_LINK_ACK_TIMEOUT_ACK_LATENCY_TIMEOUT_VALUE_MASK 0x000007ff
#define BCHP_PCIE_DLL_DATA_LINK_ACK_TIMEOUT_ACK_LATENCY_TIMEOUT_VALUE_SHIFT 0

/***************************************************************************
 *POWER_MANAGEMENT_THRESHOLD - POWER_MANAGEMENT_THRESHOLD Register
 ***************************************************************************/
/* PCIE_DLL :: POWER_MANAGEMENT_THRESHOLD :: RESERVED_0 [31:24] */
#define BCHP_PCIE_DLL_POWER_MANAGEMENT_THRESHOLD_RESERVED_0_MASK   0xff000000
#define BCHP_PCIE_DLL_POWER_MANAGEMENT_THRESHOLD_RESERVED_0_SHIFT  24

/* PCIE_DLL :: POWER_MANAGEMENT_THRESHOLD :: L0_STAY_TIME [23:20] */
#define BCHP_PCIE_DLL_POWER_MANAGEMENT_THRESHOLD_L0_STAY_TIME_MASK 0x00f00000
#define BCHP_PCIE_DLL_POWER_MANAGEMENT_THRESHOLD_L0_STAY_TIME_SHIFT 20

/* PCIE_DLL :: POWER_MANAGEMENT_THRESHOLD :: L1_STAY_TIME [19:16] */
#define BCHP_PCIE_DLL_POWER_MANAGEMENT_THRESHOLD_L1_STAY_TIME_MASK 0x000f0000
#define BCHP_PCIE_DLL_POWER_MANAGEMENT_THRESHOLD_L1_STAY_TIME_SHIFT 16

/* PCIE_DLL :: POWER_MANAGEMENT_THRESHOLD :: L1_THRESHOLD [15:08] */
#define BCHP_PCIE_DLL_POWER_MANAGEMENT_THRESHOLD_L1_THRESHOLD_MASK 0x0000ff00
#define BCHP_PCIE_DLL_POWER_MANAGEMENT_THRESHOLD_L1_THRESHOLD_SHIFT 8

/* PCIE_DLL :: POWER_MANAGEMENT_THRESHOLD :: L0S_THRESHOLD [07:00] */
#define BCHP_PCIE_DLL_POWER_MANAGEMENT_THRESHOLD_L0S_THRESHOLD_MASK 0x000000ff
#define BCHP_PCIE_DLL_POWER_MANAGEMENT_THRESHOLD_L0S_THRESHOLD_SHIFT 0

/***************************************************************************
 *RETRY_BUFFER_WRITE_POINTER_DEBUG - RETRY_BUFFER_WRITE_POINTER_DEBUG Register
 ***************************************************************************/
/* PCIE_DLL :: RETRY_BUFFER_WRITE_POINTER_DEBUG :: RESERVED_0 [31:11] */
#define BCHP_PCIE_DLL_RETRY_BUFFER_WRITE_POINTER_DEBUG_RESERVED_0_MASK 0xfffff800
#define BCHP_PCIE_DLL_RETRY_BUFFER_WRITE_POINTER_DEBUG_RESERVED_0_SHIFT 11

/* PCIE_DLL :: RETRY_BUFFER_WRITE_POINTER_DEBUG :: RETRY_BUFFER_WRITE_POINTER [10:00] */
#define BCHP_PCIE_DLL_RETRY_BUFFER_WRITE_POINTER_DEBUG_RETRY_BUFFER_WRITE_POINTER_MASK 0x000007ff
#define BCHP_PCIE_DLL_RETRY_BUFFER_WRITE_POINTER_DEBUG_RETRY_BUFFER_WRITE_POINTER_SHIFT 0

/***************************************************************************
 *RETRY_BUFFER_READ_POINTER_DEBUG - RETRY_BUFFER_READ_POINTER_DEBUG Register
 ***************************************************************************/
/* PCIE_DLL :: RETRY_BUFFER_READ_POINTER_DEBUG :: RESERVED_0 [31:11] */
#define BCHP_PCIE_DLL_RETRY_BUFFER_READ_POINTER_DEBUG_RESERVED_0_MASK 0xfffff800
#define BCHP_PCIE_DLL_RETRY_BUFFER_READ_POINTER_DEBUG_RESERVED_0_SHIFT 11

/* PCIE_DLL :: RETRY_BUFFER_READ_POINTER_DEBUG :: RETRY_BUFFER_READ_POINTER [10:00] */
#define BCHP_PCIE_DLL_RETRY_BUFFER_READ_POINTER_DEBUG_RETRY_BUFFER_READ_POINTER_MASK 0x000007ff
#define BCHP_PCIE_DLL_RETRY_BUFFER_READ_POINTER_DEBUG_RETRY_BUFFER_READ_POINTER_SHIFT 0

/***************************************************************************
 *RETRY_BUFFER_PURGED_POINTER_DEBUG - RETRY_BUFFER_PURGED_POINTER_DEBUG Register
 ***************************************************************************/
/* PCIE_DLL :: RETRY_BUFFER_PURGED_POINTER_DEBUG :: RESERVED_0 [31:11] */
#define BCHP_PCIE_DLL_RETRY_BUFFER_PURGED_POINTER_DEBUG_RESERVED_0_MASK 0xfffff800
#define BCHP_PCIE_DLL_RETRY_BUFFER_PURGED_POINTER_DEBUG_RESERVED_0_SHIFT 11

/* PCIE_DLL :: RETRY_BUFFER_PURGED_POINTER_DEBUG :: RETRY_BUFFER_PURGED_POINTER [10:00] */
#define BCHP_PCIE_DLL_RETRY_BUFFER_PURGED_POINTER_DEBUG_RETRY_BUFFER_PURGED_POINTER_MASK 0x000007ff
#define BCHP_PCIE_DLL_RETRY_BUFFER_PURGED_POINTER_DEBUG_RETRY_BUFFER_PURGED_POINTER_SHIFT 0

/***************************************************************************
 *RETRY_BUFFER_READ_WRITE_DEBUG_PORT - RETRY_BUFFER_READ_WRITE_DEBUG_PORT Register
 ***************************************************************************/
/* PCIE_DLL :: RETRY_BUFFER_READ_WRITE_DEBUG_PORT :: RETRY_BUFFER_DATA [31:00] */
#define BCHP_PCIE_DLL_RETRY_BUFFER_READ_WRITE_DEBUG_PORT_RETRY_BUFFER_DATA_MASK 0xffffffff
#define BCHP_PCIE_DLL_RETRY_BUFFER_READ_WRITE_DEBUG_PORT_RETRY_BUFFER_DATA_SHIFT 0

/***************************************************************************
 *ERROR_COUNT_THRESHOLD - ERROR_COUNT_THRESHOLD Register
 ***************************************************************************/
/* PCIE_DLL :: ERROR_COUNT_THRESHOLD :: RESERVED_0 [31:15] */
#define BCHP_PCIE_DLL_ERROR_COUNT_THRESHOLD_RESERVED_0_MASK        0xffff8000
#define BCHP_PCIE_DLL_ERROR_COUNT_THRESHOLD_RESERVED_0_SHIFT       15

/* PCIE_DLL :: ERROR_COUNT_THRESHOLD :: BAD_SEQUENCE_NUMBER_COUNT_THRESHOLD [14:12] */
#define BCHP_PCIE_DLL_ERROR_COUNT_THRESHOLD_BAD_SEQUENCE_NUMBER_COUNT_THRESHOLD_MASK 0x00007000
#define BCHP_PCIE_DLL_ERROR_COUNT_THRESHOLD_BAD_SEQUENCE_NUMBER_COUNT_THRESHOLD_SHIFT 12

/* PCIE_DLL :: ERROR_COUNT_THRESHOLD :: NAK_RECEIVED_COUNT_THRESHOLD [11:08] */
#define BCHP_PCIE_DLL_ERROR_COUNT_THRESHOLD_NAK_RECEIVED_COUNT_THRESHOLD_MASK 0x00000f00
#define BCHP_PCIE_DLL_ERROR_COUNT_THRESHOLD_NAK_RECEIVED_COUNT_THRESHOLD_SHIFT 8

/* PCIE_DLL :: ERROR_COUNT_THRESHOLD :: DLLP_ERROR_COUNT_THRESHOLD [07:04] */
#define BCHP_PCIE_DLL_ERROR_COUNT_THRESHOLD_DLLP_ERROR_COUNT_THRESHOLD_MASK 0x000000f0
#define BCHP_PCIE_DLL_ERROR_COUNT_THRESHOLD_DLLP_ERROR_COUNT_THRESHOLD_SHIFT 4

/* PCIE_DLL :: ERROR_COUNT_THRESHOLD :: TLP_ERROR_COUNT_THRESHOLD [03:00] */
#define BCHP_PCIE_DLL_ERROR_COUNT_THRESHOLD_TLP_ERROR_COUNT_THRESHOLD_MASK 0x0000000f
#define BCHP_PCIE_DLL_ERROR_COUNT_THRESHOLD_TLP_ERROR_COUNT_THRESHOLD_SHIFT 0

/***************************************************************************
 *TL_ERROR_COUNTER - TL_ERROR_COUNTER Register
 ***************************************************************************/
/* PCIE_DLL :: TL_ERROR_COUNTER :: RESERVED_0 [31:24] */
#define BCHP_PCIE_DLL_TL_ERROR_COUNTER_RESERVED_0_MASK             0xff000000
#define BCHP_PCIE_DLL_TL_ERROR_COUNTER_RESERVED_0_SHIFT            24

/* PCIE_DLL :: TL_ERROR_COUNTER :: TLP_BAD_SEQUENCE_NUMBER_COUNTER [23:16] */
#define BCHP_PCIE_DLL_TL_ERROR_COUNTER_TLP_BAD_SEQUENCE_NUMBER_COUNTER_MASK 0x00ff0000
#define BCHP_PCIE_DLL_TL_ERROR_COUNTER_TLP_BAD_SEQUENCE_NUMBER_COUNTER_SHIFT 16

/* PCIE_DLL :: TL_ERROR_COUNTER :: TLP_ERROR_COUNTER [15:00] */
#define BCHP_PCIE_DLL_TL_ERROR_COUNTER_TLP_ERROR_COUNTER_MASK      0x0000ffff
#define BCHP_PCIE_DLL_TL_ERROR_COUNTER_TLP_ERROR_COUNTER_SHIFT     0

/***************************************************************************
 *DLLP_ERROR_COUNTER - DLLP_ERROR_COUNTER Register
 ***************************************************************************/
/* PCIE_DLL :: DLLP_ERROR_COUNTER :: RESERVED_0 [31:16] */
#define BCHP_PCIE_DLL_DLLP_ERROR_COUNTER_RESERVED_0_MASK           0xffff0000
#define BCHP_PCIE_DLL_DLLP_ERROR_COUNTER_RESERVED_0_SHIFT          16

/* PCIE_DLL :: DLLP_ERROR_COUNTER :: DLLP_ERROR_COUNTER [15:00] */
#define BCHP_PCIE_DLL_DLLP_ERROR_COUNTER_DLLP_ERROR_COUNTER_MASK   0x0000ffff
#define BCHP_PCIE_DLL_DLLP_ERROR_COUNTER_DLLP_ERROR_COUNTER_SHIFT  0

/***************************************************************************
 *NAK_RECEIVED_COUNTER - NAK_RECEIVED_COUNTER Register
 ***************************************************************************/
/* PCIE_DLL :: NAK_RECEIVED_COUNTER :: RESERVED_0 [31:16] */
#define BCHP_PCIE_DLL_NAK_RECEIVED_COUNTER_RESERVED_0_MASK         0xffff0000
#define BCHP_PCIE_DLL_NAK_RECEIVED_COUNTER_RESERVED_0_SHIFT        16

/* PCIE_DLL :: NAK_RECEIVED_COUNTER :: NAK_RECEIVED_COUNTER [15:00] */
#define BCHP_PCIE_DLL_NAK_RECEIVED_COUNTER_NAK_RECEIVED_COUNTER_MASK 0x0000ffff
#define BCHP_PCIE_DLL_NAK_RECEIVED_COUNTER_NAK_RECEIVED_COUNTER_SHIFT 0

/***************************************************************************
 *DATA_LINK_TEST - DATA_LINK_TEST Register
 ***************************************************************************/
/* PCIE_DLL :: DATA_LINK_TEST :: RESERVED_0 [31:16] */
#define BCHP_PCIE_DLL_DATA_LINK_TEST_RESERVED_0_MASK               0xffff0000
#define BCHP_PCIE_DLL_DATA_LINK_TEST_RESERVED_0_SHIFT              16

/* PCIE_DLL :: DATA_LINK_TEST :: STORE_RECEIVE_TLPS [15:15] */
#define BCHP_PCIE_DLL_DATA_LINK_TEST_STORE_RECEIVE_TLPS_MASK       0x00008000
#define BCHP_PCIE_DLL_DATA_LINK_TEST_STORE_RECEIVE_TLPS_SHIFT      15

/* PCIE_DLL :: DATA_LINK_TEST :: DISABLE_TLPS [14:14] */
#define BCHP_PCIE_DLL_DATA_LINK_TEST_DISABLE_TLPS_MASK             0x00004000
#define BCHP_PCIE_DLL_DATA_LINK_TEST_DISABLE_TLPS_SHIFT            14

/* PCIE_DLL :: DATA_LINK_TEST :: DISABLE_DLLPS [13:13] */
#define BCHP_PCIE_DLL_DATA_LINK_TEST_DISABLE_DLLPS_MASK            0x00002000
#define BCHP_PCIE_DLL_DATA_LINK_TEST_DISABLE_DLLPS_SHIFT           13

/* PCIE_DLL :: DATA_LINK_TEST :: FORCE_PHY_LINK_UP [12:12] */
#define BCHP_PCIE_DLL_DATA_LINK_TEST_FORCE_PHY_LINK_UP_MASK        0x00001000
#define BCHP_PCIE_DLL_DATA_LINK_TEST_FORCE_PHY_LINK_UP_SHIFT       12

/* PCIE_DLL :: DATA_LINK_TEST :: BYPASS_FLOW_CONTROL [11:11] */
#define BCHP_PCIE_DLL_DATA_LINK_TEST_BYPASS_FLOW_CONTROL_MASK      0x00000800
#define BCHP_PCIE_DLL_DATA_LINK_TEST_BYPASS_FLOW_CONTROL_SHIFT     11

/* PCIE_DLL :: DATA_LINK_TEST :: ENABLE_RAM_CORE_CLOCK_MARGIN_TEST_MODE [10:10] */
#define BCHP_PCIE_DLL_DATA_LINK_TEST_ENABLE_RAM_CORE_CLOCK_MARGIN_TEST_MODE_MASK 0x00000400
#define BCHP_PCIE_DLL_DATA_LINK_TEST_ENABLE_RAM_CORE_CLOCK_MARGIN_TEST_MODE_SHIFT 10

/* PCIE_DLL :: DATA_LINK_TEST :: ENABLE_RAM_OVERSTRESS_TEST_MODE [09:09] */
#define BCHP_PCIE_DLL_DATA_LINK_TEST_ENABLE_RAM_OVERSTRESS_TEST_MODE_MASK 0x00000200
#define BCHP_PCIE_DLL_DATA_LINK_TEST_ENABLE_RAM_OVERSTRESS_TEST_MODE_SHIFT 9

/* PCIE_DLL :: DATA_LINK_TEST :: SPEED_UP_SLOW_CLOCK [08:08] */
#define BCHP_PCIE_DLL_DATA_LINK_TEST_SPEED_UP_SLOW_CLOCK_MASK      0x00000100
#define BCHP_PCIE_DLL_DATA_LINK_TEST_SPEED_UP_SLOW_CLOCK_SHIFT     8

/* PCIE_DLL :: DATA_LINK_TEST :: SPEED_UP_COMPLETION_TIMER [07:07] */
#define BCHP_PCIE_DLL_DATA_LINK_TEST_SPEED_UP_COMPLETION_TIMER_MASK 0x00000080
#define BCHP_PCIE_DLL_DATA_LINK_TEST_SPEED_UP_COMPLETION_TIMER_SHIFT 7

/* PCIE_DLL :: DATA_LINK_TEST :: SPEED_UP_REPLAY_TIMER [06:06] */
#define BCHP_PCIE_DLL_DATA_LINK_TEST_SPEED_UP_REPLAY_TIMER_MASK    0x00000040
#define BCHP_PCIE_DLL_DATA_LINK_TEST_SPEED_UP_REPLAY_TIMER_SHIFT   6

/* PCIE_DLL :: DATA_LINK_TEST :: SPEED_UP_ACK_LATENCY_TIMER [05:05] */
#define BCHP_PCIE_DLL_DATA_LINK_TEST_SPEED_UP_ACK_LATENCY_TIMER_MASK 0x00000020
#define BCHP_PCIE_DLL_DATA_LINK_TEST_SPEED_UP_ACK_LATENCY_TIMER_SHIFT 5

/* PCIE_DLL :: DATA_LINK_TEST :: SPEED_UP_PME_SERVICE_TIMER [04:04] */
#define BCHP_PCIE_DLL_DATA_LINK_TEST_SPEED_UP_PME_SERVICE_TIMER_MASK 0x00000010
#define BCHP_PCIE_DLL_DATA_LINK_TEST_SPEED_UP_PME_SERVICE_TIMER_SHIFT 4

/* PCIE_DLL :: DATA_LINK_TEST :: FORCE_PURGE [03:03] */
#define BCHP_PCIE_DLL_DATA_LINK_TEST_FORCE_PURGE_MASK              0x00000008
#define BCHP_PCIE_DLL_DATA_LINK_TEST_FORCE_PURGE_SHIFT             3

/* PCIE_DLL :: DATA_LINK_TEST :: FORCE_RETRY [02:02] */
#define BCHP_PCIE_DLL_DATA_LINK_TEST_FORCE_RETRY_MASK              0x00000004
#define BCHP_PCIE_DLL_DATA_LINK_TEST_FORCE_RETRY_SHIFT             2

/* PCIE_DLL :: DATA_LINK_TEST :: INVERT_CRC [01:01] */
#define BCHP_PCIE_DLL_DATA_LINK_TEST_INVERT_CRC_MASK               0x00000002
#define BCHP_PCIE_DLL_DATA_LINK_TEST_INVERT_CRC_SHIFT              1

/* PCIE_DLL :: DATA_LINK_TEST :: SEND_BAD_CRC_BIT [00:00] */
#define BCHP_PCIE_DLL_DATA_LINK_TEST_SEND_BAD_CRC_BIT_MASK         0x00000001
#define BCHP_PCIE_DLL_DATA_LINK_TEST_SEND_BAD_CRC_BIT_SHIFT        0

/***************************************************************************
 *PACKET_BIST - PACKET_BIST Register
 ***************************************************************************/
/* PCIE_DLL :: PACKET_BIST :: RESERVED_0 [31:24] */
#define BCHP_PCIE_DLL_PACKET_BIST_RESERVED_0_MASK                  0xff000000
#define BCHP_PCIE_DLL_PACKET_BIST_RESERVED_0_SHIFT                 24

/* PCIE_DLL :: PACKET_BIST :: PACKET_CHECKER_LOCKED [23:23] */
#define BCHP_PCIE_DLL_PACKET_BIST_PACKET_CHECKER_LOCKED_MASK       0x00800000
#define BCHP_PCIE_DLL_PACKET_BIST_PACKET_CHECKER_LOCKED_SHIFT      23

/* PCIE_DLL :: PACKET_BIST :: RECEIVE_MISMATCH [22:22] */
#define BCHP_PCIE_DLL_PACKET_BIST_RECEIVE_MISMATCH_MASK            0x00400000
#define BCHP_PCIE_DLL_PACKET_BIST_RECEIVE_MISMATCH_SHIFT           22

/* PCIE_DLL :: PACKET_BIST :: ENABLE_RANDOM_TLP_LENGTH [21:21] */
#define BCHP_PCIE_DLL_PACKET_BIST_ENABLE_RANDOM_TLP_LENGTH_MASK    0x00200000
#define BCHP_PCIE_DLL_PACKET_BIST_ENABLE_RANDOM_TLP_LENGTH_SHIFT   21

/* PCIE_DLL :: PACKET_BIST :: TLP_LENGTH [20:10] */
#define BCHP_PCIE_DLL_PACKET_BIST_TLP_LENGTH_MASK                  0x001ffc00
#define BCHP_PCIE_DLL_PACKET_BIST_TLP_LENGTH_SHIFT                 10

/* PCIE_DLL :: PACKET_BIST :: ENABLE_RANDOM_IPG_LENGTH [09:09] */
#define BCHP_PCIE_DLL_PACKET_BIST_ENABLE_RANDOM_IPG_LENGTH_MASK    0x00000200
#define BCHP_PCIE_DLL_PACKET_BIST_ENABLE_RANDOM_IPG_LENGTH_SHIFT   9

/* PCIE_DLL :: PACKET_BIST :: IPG_LENGTH [08:02] */
#define BCHP_PCIE_DLL_PACKET_BIST_IPG_LENGTH_MASK                  0x000001fc
#define BCHP_PCIE_DLL_PACKET_BIST_IPG_LENGTH_SHIFT                 2

/* PCIE_DLL :: PACKET_BIST :: TRANSMIT_START [01:01] */
#define BCHP_PCIE_DLL_PACKET_BIST_TRANSMIT_START_MASK              0x00000002
#define BCHP_PCIE_DLL_PACKET_BIST_TRANSMIT_START_SHIFT             1

/* PCIE_DLL :: PACKET_BIST :: ENABLE_PACKET_GENERATOR_TEST_MODE [00:00] */
#define BCHP_PCIE_DLL_PACKET_BIST_ENABLE_PACKET_GENERATOR_TEST_MODE_MASK 0x00000001
#define BCHP_PCIE_DLL_PACKET_BIST_ENABLE_PACKET_GENERATOR_TEST_MODE_SHIFT 0

/***************************************************************************
 *LINK_PCIE_1_1_CONTROL - LINK_PCIE_1_1_CONTROL Register
 ***************************************************************************/
/* PCIE_DLL :: LINK_PCIE_1_1_CONTROL :: RTBF_CT_2_0 [31:29] */
#define BCHP_PCIE_DLL_LINK_PCIE_1_1_CONTROL_RTBF_CT_2_0_MASK       0xe0000000
#define BCHP_PCIE_DLL_LINK_PCIE_1_1_CONTROL_RTBF_CT_2_0_SHIFT      29

/* PCIE_DLL :: LINK_PCIE_1_1_CONTROL :: RTBF_SAM_1_0 [28:27] */
#define BCHP_PCIE_DLL_LINK_PCIE_1_1_CONTROL_RTBF_SAM_1_0_MASK      0x18000000
#define BCHP_PCIE_DLL_LINK_PCIE_1_1_CONTROL_RTBF_SAM_1_0_SHIFT     27

/* PCIE_DLL :: LINK_PCIE_1_1_CONTROL :: UNUSED_0 [26:10] */
#define BCHP_PCIE_DLL_LINK_PCIE_1_1_CONTROL_UNUSED_0_MASK          0x07fffc00
#define BCHP_PCIE_DLL_LINK_PCIE_1_1_CONTROL_UNUSED_0_SHIFT         10

/* PCIE_DLL :: LINK_PCIE_1_1_CONTROL :: SELOCALXTAL [09:09] */
#define BCHP_PCIE_DLL_LINK_PCIE_1_1_CONTROL_SELOCALXTAL_MASK       0x00000200
#define BCHP_PCIE_DLL_LINK_PCIE_1_1_CONTROL_SELOCALXTAL_SHIFT      9

/* PCIE_DLL :: LINK_PCIE_1_1_CONTROL :: L2_PLL_POWERDOWN_DISABLE [08:08] */
#define BCHP_PCIE_DLL_LINK_PCIE_1_1_CONTROL_L2_PLL_POWERDOWN_DISABLE_MASK 0x00000100
#define BCHP_PCIE_DLL_LINK_PCIE_1_1_CONTROL_L2_PLL_POWERDOWN_DISABLE_SHIFT 8

/* PCIE_DLL :: LINK_PCIE_1_1_CONTROL :: L1_PLL_POWERDOWN_DISABLE [07:07] */
#define BCHP_PCIE_DLL_LINK_PCIE_1_1_CONTROL_L1_PLL_POWERDOWN_DISABLE_MASK 0x00000080
#define BCHP_PCIE_DLL_LINK_PCIE_1_1_CONTROL_L1_PLL_POWERDOWN_DISABLE_SHIFT 7

/* PCIE_DLL :: LINK_PCIE_1_1_CONTROL :: L2_D3PM_CLKREQ_DISABLE [06:06] */
#define BCHP_PCIE_DLL_LINK_PCIE_1_1_CONTROL_L2_D3PM_CLKREQ_DISABLE_MASK 0x00000040
#define BCHP_PCIE_DLL_LINK_PCIE_1_1_CONTROL_L2_D3PM_CLKREQ_DISABLE_SHIFT 6

/* PCIE_DLL :: LINK_PCIE_1_1_CONTROL :: L1_D3PM_CLKREQ_DISABLE [05:05] */
#define BCHP_PCIE_DLL_LINK_PCIE_1_1_CONTROL_L1_D3PM_CLKREQ_DISABLE_MASK 0x00000020
#define BCHP_PCIE_DLL_LINK_PCIE_1_1_CONTROL_L1_D3PM_CLKREQ_DISABLE_SHIFT 5

/* PCIE_DLL :: LINK_PCIE_1_1_CONTROL :: L1_ASPM_CLKREQ_DISABLE [04:04] */
#define BCHP_PCIE_DLL_LINK_PCIE_1_1_CONTROL_L1_ASPM_CLKREQ_DISABLE_MASK 0x00000010
#define BCHP_PCIE_DLL_LINK_PCIE_1_1_CONTROL_L1_ASPM_CLKREQ_DISABLE_SHIFT 4

/* PCIE_DLL :: LINK_PCIE_1_1_CONTROL :: L1_PLL_PD_W_O_CLKREQ [03:03] */
#define BCHP_PCIE_DLL_LINK_PCIE_1_1_CONTROL_L1_PLL_PD_W_O_CLKREQ_MASK 0x00000008
#define BCHP_PCIE_DLL_LINK_PCIE_1_1_CONTROL_L1_PLL_PD_W_O_CLKREQ_SHIFT 3

/* PCIE_DLL :: LINK_PCIE_1_1_CONTROL :: DASPM10USTIMER [02:02] */
#define BCHP_PCIE_DLL_LINK_PCIE_1_1_CONTROL_DASPM10USTIMER_MASK    0x00000004
#define BCHP_PCIE_DLL_LINK_PCIE_1_1_CONTROL_DASPM10USTIMER_SHIFT   2

/* PCIE_DLL :: LINK_PCIE_1_1_CONTROL :: DFFU_EL1 [01:01] */
#define BCHP_PCIE_DLL_LINK_PCIE_1_1_CONTROL_DFFU_EL1_MASK          0x00000002
#define BCHP_PCIE_DLL_LINK_PCIE_1_1_CONTROL_DFFU_EL1_SHIFT         1

/* PCIE_DLL :: LINK_PCIE_1_1_CONTROL :: DFLOWCTLUPDATE1_1 [00:00] */
#define BCHP_PCIE_DLL_LINK_PCIE_1_1_CONTROL_DFLOWCTLUPDATE1_1_MASK 0x00000001
#define BCHP_PCIE_DLL_LINK_PCIE_1_1_CONTROL_DFLOWCTLUPDATE1_1_SHIFT 0

#endif /* #ifndef BCHP_PCIE_DLL_H__ */

/* End of File */
