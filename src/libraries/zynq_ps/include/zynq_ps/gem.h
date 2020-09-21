#pragma once
// Copyright Deano Calver
// SPDX-License-Identifier: MIT
// Gigabit Ethernet Controller
// Auto-generated on Mon Sep 21 17:18:27 EEST 2020

#include <stdint.h>

// 2 banks of gem chips
#define gem0_BASE_ADDR 0xe000b000U
#define gem1_BASE_ADDR 0xe000c000U

// Network Control
#define gem_NWCTRL_OFFSET 0x00000000U

// Network Configuration
#define gem_NWCFG_OFFSET 0x00000004U

// Network Status
#define gem_NWSR_OFFSET 0x00000008U

// DMA Configuration
#define gem_DMACR_OFFSET 0x00000010U

// Transmit Status
#define gem_TXSR_OFFSET 0x00000014U

// Receive Buffer Queue Base Address
#define gem_RXQBASE_OFFSET 0x00000018U

// Transmit Buffer Queue Base Address
#define gem_TXQBASE_OFFSET 0x0000001cU

// Receive Status
#define gem_RXSR_OFFSET 0x00000020U

// Interrupt Status
#define gem_ISR_OFFSET 0x00000024U

// Interrupt Enable
#define gem_IER_OFFSET 0x00000028U

// Interrupt Disable
#define gem_IDR_OFFSET 0x0000002cU

// Interrupt Mask Status
#define gem_IMR_OFFSET 0x00000030U

// PHY Maintenance
#define gem_PHYMNTNC_OFFSET 0x00000034U

// Received Pause Quantum
#define gem_RXPAUSE_OFFSET 0x00000038U

// Transmit Pause Quantum
#define gem_TXPAUSE_OFFSET 0x0000003cU

// Hash Register Bottom [31:0]
#define gem_HASHL_OFFSET 0x00000080U

// Hash Register Top [63:32]
#define gem_HASHH_OFFSET 0x00000084U

// Specific Address 1 Bottom [31:0]
#define gem_LADDR1L_OFFSET 0x00000088U

// Specific Address 1 Top [47:32]
#define gem_LADDR1H_OFFSET 0x0000008cU

// Specific Address 2 Bottom [31:0]
#define gem_LADDR2L_OFFSET 0x00000090U

// Specific Address 2 Top [47:32]
#define gem_LADDR2H_OFFSET 0x00000094U

// Specific Address 3 Bottom [31:0]
#define gem_LADDR3L_OFFSET 0x00000098U

// Specific Address 3 Top [47:32]
#define gem_LADDR3H_OFFSET 0x0000009cU

// Specific Address 4 Bottom [31:0]
#define gem_LADDR4L_OFFSET 0x000000a0U

// Specific Address 4 Top [47:32]
#define gem_LADDR4H_OFFSET 0x000000a4U

// Type ID Match 1
#define gem_MATCH1_OFFSET 0x000000a8U

// Type ID Match 2
#define gem_MATCH2_OFFSET 0x000000acU

// Type ID Match 3
#define gem_MATCH3_OFFSET 0x000000b0U

// Type ID Match 4
#define gem_MATCH4_OFFSET 0x000000b4U

// Wake on LAN Register
#define gem_WAKE_ON_LAN_OFFSET 0x000000b8U

// IPG stretch register
#define gem_STRETCH_OFFSET 0x000000bcU

// Stacked VLAN Register
#define gem_STACKED_VLAN_OFFSET 0x000000c0U

// Transmit PFC Pause Register
#define gem_TX_PFC_PAUSE_OFFSET 0x000000c4U

// Specific Address Mask 1 Bottom [31:0]
#define gem_SPEC_ADDR1_MASK_BOT_OFFSET 0x000000c8U

// Specific Address Mask 1 Top [47:32]
#define gem_SPEC_ADDR1_MASK_TOP_OFFSET 0x000000ccU

// Module ID
#define gem_MODULE_ID_OFFSET 0x000000fcU

// Octets transmitted [31:0] (in frames without error)
#define gem_OCTTXL_OFFSET 0x00000100U

// Octets transmitted [47:32] (in frames without error)
#define gem_OCTTXH_OFFSET 0x00000104U

// Frames Transmitted
#define gem_TXCNT_OFFSET 0x00000108U

// Broadcast frames Tx
#define gem_TXBCCNT_OFFSET 0x0000010cU

// Multicast frames Tx
#define gem_TXMCCNT_OFFSET 0x00000110U

// Pause frames Tx
#define gem_TXPAUSECNT_OFFSET 0x00000114U

// Frames Tx, 64-byte length
#define gem_TX64CNT_OFFSET 0x00000118U

// Frames Tx, 65 to 127-byte length
#define gem_TX65CNT_OFFSET 0x0000011cU

// Frames Tx, 128 to 255-bytelength
#define gem_TX128CNT_OFFSET 0x00000120U

// Frames Tx, 256 to 511-byte length
#define gem_TX256CNT_OFFSET 0x00000124U

// Frames Tx, 512 to 1023-byte length
#define gem_TX512CNT_OFFSET 0x00000128U

// Frame Tx, 1024 to 1518-byte length
#define gem_TX1024CNT_OFFSET 0x0000012cU

// Transmit under runs
#define gem_TXURUNCNT_OFFSET 0x00000134U

// Single Collision Frames
#define gem_SNGLCOLLCNT_OFFSET 0x00000138U

// Multiple Collision Frames
#define gem_MULTICOLLCNT_OFFSET 0x0000013cU

// Excessive Collisions
#define gem_EXCESSCOLLCNT_OFFSET 0x00000140U

// Late Collisions
#define gem_LATECOLLCNT_OFFSET 0x00000144U

// Deferred Transmission Frames
#define gem_TXDEFERCNT_OFFSET 0x00000148U

// Carrier Sense Errors.
#define gem_TXCSENSECNT_OFFSET 0x0000014cU

// Octets Received [31:0]
#define gem_OCTRXL_OFFSET 0x00000150U

// Octets Received [47:32]
#define gem_OCTRXH_OFFSET 0x00000154U

// Frames Received
#define gem_RXCNT_OFFSET 0x00000158U

// Broadcast Frames Rx
#define gem_RXBROADCNT_OFFSET 0x0000015cU

// Multicast Frames Rx
#define gem_RXMULTICNT_OFFSET 0x00000160U

// Pause Frames Rx
#define gem_RXPAUSECNT_OFFSET 0x00000164U

// Frames Rx, 64-byte length
#define gem_RX64CNT_OFFSET 0x00000168U

// Frames Rx, 65 to 127-byte length
#define gem_RX65CNT_OFFSET 0x0000016cU

// Frames Rx, 128 to 255-byte length
#define gem_RX128CNT_OFFSET 0x00000170U

// Frames Rx, 256 to 511-byte length
#define gem_RX256CNT_OFFSET 0x00000174U

// Frames Rx, 512 to 1023-byte length
#define gem_RX512CNT_OFFSET 0x00000178U

// Frames Rx, 1024 to 1518-byte length
#define gem_RX1024CNT_OFFSET 0x0000017cU

// Undersize frames received
#define gem_RXUNDRCNT_OFFSET 0x00000184U

// Oversize frames received
#define gem_RXOVRCNT_OFFSET 0x00000188U

// Jabbers received
#define gem_RXJABCNT_OFFSET 0x0000018cU

// Frame check sequence errors
#define gem_RXFCSCNT_OFFSET 0x00000190U

// Length field frame errors
#define gem_RXLENGTHCNT_OFFSET 0x00000194U

// Receive symbol errors
#define gem_RXSYMBCNT_OFFSET 0x00000198U

// Alignment errors
#define gem_RXALIGNCNT_OFFSET 0x0000019cU

// Receive resource errors
#define gem_RXRESERRCNT_OFFSET 0x000001a0U

// Receive overrun errors
#define gem_RXORCNT_OFFSET 0x000001a4U

// IP header checksum errors
#define gem_RXIPCCNT_OFFSET 0x000001a8U

// TCP checksum errors
#define gem_RXTCPCCNT_OFFSET 0x000001acU

// UDP checksum error
#define gem_RXUDPCCNT_OFFSET 0x000001b0U

// 1588 timer sync strobe seconds
#define gem_ROBE_S_OFFSET 0x000001c8U

// 1588 timer sync strobe nanoseconds
#define gem_ROBE_NS_OFFSET 0x000001ccU

// 1588 timer seconds
#define gem_TIMER_1588_SEC_OFFSET 0x000001d0U

// 1588 timer nanoseconds
#define gem_TIMER_1588_NANOSEC_OFFSET 0x000001d4U

// 1588 timer adjust
#define gem_TIMER_1588_ADJ_OFFSET 0x000001d8U

// 1588 timer increment
#define gem_TIMER_1588_INC_OFFSET 0x000001dcU

// PTP event frame transmitted seconds
#define gem_PTP_TXSEC_OFFSET 0x000001e0U

// PTP event frame transmitted nanoseconds
#define gem_PTP_TXNANOSEC_OFFSET 0x000001e4U

// PTP event frame received seconds
#define gem_PTP_RXSEC_OFFSET 0x000001e8U

// PTP event frame received nanoseconds.
#define gem_PTP_RXNANOSEC_OFFSET 0x000001ecU

// PTP peer event frame transmitted seconds
#define gem_PTPP_TXSEC_OFFSET 0x000001f0U

// PTP peer event frame transmitted nanoseconds
#define gem_PTPP_TXNANOSEC_OFFSET 0x000001f4U

// PTP peer event frame received seconds
#define gem_PTPP_RXSEC_OFFSET 0x000001f8U

// PTP peer event frame received nanoseconds.
#define gem_PTPP_RXNANOSEC_OFFSET 0x000001fcU

// Design Configuration 2
#define gem_DESIGN_CFG2_OFFSET 0x00000284U

// Design Configuration 3
#define gem_DESIGN_CFG3_OFFSET 0x00000288U

// Design Configuration 4
#define gem_DESIGN_CFG4_OFFSET 0x0000028cU

// Design Configuration 5
#define gem_DESIGN_CFG5_OFFSET 0x00000290U
