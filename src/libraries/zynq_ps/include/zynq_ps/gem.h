#pragma once
// Copyright Deano Calver
// SPDX-License-Identifier: MIT
// Gigabit Ethernet Controller
// Auto-generated on Sun Sep 20 15:25:57 EEST 2020

#include <stdint.h>

// 2 banks of gem chips
#define gem0_BASE_ADDR 0xe000b000
#define gem1_BASE_ADDR 0xe000c000

// Network Control
#define gem_NWCTRL_OFFSET 0x00000000

// Network Configuration
#define gem_NWCFG_OFFSET 0x00000004

// Network Status
#define gem_NWSR_OFFSET 0x00000008

// DMA Configuration
#define gem_DMACR_OFFSET 0x00000010

// Transmit Status
#define gem_TXSR_OFFSET 0x00000014

// Receive Buffer Queue Base Address
#define gem_RXQBASE_OFFSET 0x00000018

// Transmit Buffer Queue Base Address
#define gem_TXQBASE_OFFSET 0x0000001c

// Receive Status
#define gem_RXSR_OFFSET 0x00000020

// Interrupt Status
#define gem_ISR_OFFSET 0x00000024

// Interrupt Enable
#define gem_IER_OFFSET 0x00000028

// Interrupt Disable
#define gem_IDR_OFFSET 0x0000002c

// Interrupt Mask Status
#define gem_IMR_OFFSET 0x00000030

// PHY Maintenance
#define gem_PHYMNTNC_OFFSET 0x00000034

// Received Pause Quantum
#define gem_RXPAUSE_OFFSET 0x00000038

// Transmit Pause Quantum
#define gem_TXPAUSE_OFFSET 0x0000003c

// Hash Register Bottom [31:0]
#define gem_HASHL_OFFSET 0x00000080

// Hash Register Top [63:32]
#define gem_HASHH_OFFSET 0x00000084

// Specific Address 1 Bottom [31:0]
#define gem_LADDR1L_OFFSET 0x00000088

// Specific Address 1 Top [47:32]
#define gem_LADDR1H_OFFSET 0x0000008c

// Specific Address 2 Bottom [31:0]
#define gem_LADDR2L_OFFSET 0x00000090

// Specific Address 2 Top [47:32]
#define gem_LADDR2H_OFFSET 0x00000094

// Specific Address 3 Bottom [31:0]
#define gem_LADDR3L_OFFSET 0x00000098

// Specific Address 3 Top [47:32]
#define gem_LADDR3H_OFFSET 0x0000009c

// Specific Address 4 Bottom [31:0]
#define gem_LADDR4L_OFFSET 0x000000a0

// Specific Address 4 Top [47:32]
#define gem_LADDR4H_OFFSET 0x000000a4

// Type ID Match 1
#define gem_MATCH1_OFFSET 0x000000a8

// Type ID Match 2
#define gem_MATCH2_OFFSET 0x000000ac

// Type ID Match 3
#define gem_MATCH3_OFFSET 0x000000b0

// Type ID Match 4
#define gem_MATCH4_OFFSET 0x000000b4

// Wake on LAN Register
#define gem_WAKE_ON_LAN_OFFSET 0x000000b8

// IPG stretch register
#define gem_STRETCH_OFFSET 0x000000bc

// Stacked VLAN Register
#define gem_STACKED_VLAN_OFFSET 0x000000c0

// Transmit PFC Pause Register
#define gem_TX_PFC_PAUSE_OFFSET 0x000000c4

// Specific Address Mask 1 Bottom [31:0]
#define gem_SPEC_ADDR1_MASK_BOT_OFFSET 0x000000c8

// Specific Address Mask 1 Top [47:32]
#define gem_SPEC_ADDR1_MASK_TOP_OFFSET 0x000000cc

// Module ID
#define gem_MODULE_ID_OFFSET 0x000000fc

// Octets transmitted [31:0] (in frames without error)
#define gem_OCTTXL_OFFSET 0x00000100

// Octets transmitted [47:32] (in frames without error)
#define gem_OCTTXH_OFFSET 0x00000104

// Frames Transmitted
#define gem_TXCNT_OFFSET 0x00000108

// Broadcast frames Tx
#define gem_TXBCCNT_OFFSET 0x0000010c

// Multicast frames Tx
#define gem_TXMCCNT_OFFSET 0x00000110

// Pause frames Tx
#define gem_TXPAUSECNT_OFFSET 0x00000114

// Frames Tx, 64-byte length
#define gem_TX64CNT_OFFSET 0x00000118

// Frames Tx, 65 to 127-byte length
#define gem_TX65CNT_OFFSET 0x0000011c

// Frames Tx, 128 to 255-bytelength
#define gem_TX128CNT_OFFSET 0x00000120

// Frames Tx, 256 to 511-byte length
#define gem_TX256CNT_OFFSET 0x00000124

// Frames Tx, 512 to 1023-byte length
#define gem_TX512CNT_OFFSET 0x00000128

// Frame Tx, 1024 to 1518-byte length
#define gem_TX1024CNT_OFFSET 0x0000012c

// Transmit under runs
#define gem_TXURUNCNT_OFFSET 0x00000134

// Single Collision Frames
#define gem_SNGLCOLLCNT_OFFSET 0x00000138

// Multiple Collision Frames
#define gem_MULTICOLLCNT_OFFSET 0x0000013c

// Excessive Collisions
#define gem_EXCESSCOLLCNT_OFFSET 0x00000140

// Late Collisions
#define gem_LATECOLLCNT_OFFSET 0x00000144

// Deferred Transmission Frames
#define gem_TXDEFERCNT_OFFSET 0x00000148

// Carrier Sense Errors.
#define gem_TXCSENSECNT_OFFSET 0x0000014c

// Octets Received [31:0]
#define gem_OCTRXL_OFFSET 0x00000150

// Octets Received [47:32]
#define gem_OCTRXH_OFFSET 0x00000154

// Frames Received
#define gem_RXCNT_OFFSET 0x00000158

// Broadcast Frames Rx
#define gem_RXBROADCNT_OFFSET 0x0000015c

// Multicast Frames Rx
#define gem_RXMULTICNT_OFFSET 0x00000160

// Pause Frames Rx
#define gem_RXPAUSECNT_OFFSET 0x00000164

// Frames Rx, 64-byte length
#define gem_RX64CNT_OFFSET 0x00000168

// Frames Rx, 65 to 127-byte length
#define gem_RX65CNT_OFFSET 0x0000016c

// Frames Rx, 128 to 255-byte length
#define gem_RX128CNT_OFFSET 0x00000170

// Frames Rx, 256 to 511-byte length
#define gem_RX256CNT_OFFSET 0x00000174

// Frames Rx, 512 to 1023-byte length
#define gem_RX512CNT_OFFSET 0x00000178

// Frames Rx, 1024 to 1518-byte length
#define gem_RX1024CNT_OFFSET 0x0000017c

// Undersize frames received
#define gem_RXUNDRCNT_OFFSET 0x00000184

// Oversize frames received
#define gem_RXOVRCNT_OFFSET 0x00000188

// Jabbers received
#define gem_RXJABCNT_OFFSET 0x0000018c

// Frame check sequence errors
#define gem_RXFCSCNT_OFFSET 0x00000190

// Length field frame errors
#define gem_RXLENGTHCNT_OFFSET 0x00000194

// Receive symbol errors
#define gem_RXSYMBCNT_OFFSET 0x00000198

// Alignment errors
#define gem_RXALIGNCNT_OFFSET 0x0000019c

// Receive resource errors
#define gem_RXRESERRCNT_OFFSET 0x000001a0

// Receive overrun errors
#define gem_RXORCNT_OFFSET 0x000001a4

// IP header checksum errors
#define gem_RXIPCCNT_OFFSET 0x000001a8

// TCP checksum errors
#define gem_RXTCPCCNT_OFFSET 0x000001ac

// UDP checksum error
#define gem_RXUDPCCNT_OFFSET 0x000001b0

// 1588 timer sync strobe seconds
#define gem_ROBE_S_OFFSET 0x000001c8

// 1588 timer sync strobe nanoseconds
#define gem_ROBE_NS_OFFSET 0x000001cc

// 1588 timer seconds
#define gem_TIMER_1588_SEC_OFFSET 0x000001d0

// 1588 timer nanoseconds
#define gem_TIMER_1588_NANOSEC_OFFSET 0x000001d4

// 1588 timer adjust
#define gem_TIMER_1588_ADJ_OFFSET 0x000001d8

// 1588 timer increment
#define gem_TIMER_1588_INC_OFFSET 0x000001dc

// PTP event frame transmitted seconds
#define gem_PTP_TXSEC_OFFSET 0x000001e0

// PTP event frame transmitted nanoseconds
#define gem_PTP_TXNANOSEC_OFFSET 0x000001e4

// PTP event frame received seconds
#define gem_PTP_RXSEC_OFFSET 0x000001e8

// PTP event frame received nanoseconds.
#define gem_PTP_RXNANOSEC_OFFSET 0x000001ec

// PTP peer event frame transmitted seconds
#define gem_PTPP_TXSEC_OFFSET 0x000001f0

// PTP peer event frame transmitted nanoseconds
#define gem_PTPP_TXNANOSEC_OFFSET 0x000001f4

// PTP peer event frame received seconds
#define gem_PTPP_RXSEC_OFFSET 0x000001f8

// PTP peer event frame received nanoseconds.
#define gem_PTPP_RXNANOSEC_OFFSET 0x000001fc

// Design Configuration 2
#define gem_DESIGN_CFG2_OFFSET 0x00000284

// Design Configuration 3
#define gem_DESIGN_CFG3_OFFSET 0x00000288

// Design Configuration 4
#define gem_DESIGN_CFG4_OFFSET 0x0000028c

// Design Configuration 5
#define gem_DESIGN_CFG5_OFFSET 0x00000290
