#pragma once
// Copyright Deano Calver
// SPDX-License-Identifier: MIT
// Direct Memory Access Controller (PL330)
// Auto-generated on Sun Sep 20 15:25:57 EEST 2020

#include <stdint.h>

// 2 banks of dmac chips
#define dmac0_s_BASE_ADDR 0xf8003000
#define dmac0_ns_BASE_ADDR 0xf8004000

// DMA Manager Status
#define dmac_DS_OFFSET 0x00000000

// DMA Program Counter
#define dmac_DPC_OFFSET 0x00000004

// DMASEV Instruction Response Control
#define dmac_INTEN_OFFSET 0x00000020

// Event Interrupt Raw Status
#define dmac_ES_OFFSET 0x00000024

// Interrupt Status
#define dmac_INTSTATUS_OFFSET 0x00000028

// Interrupt Clear
#define dmac_INTCLR_OFFSET 0x0000002c

// Fault Status DMA Manager
#define dmac_FSM_OFFSET 0x00000030

// Fault Status DMA Channel
#define dmac_FSC_OFFSET 0x00000034

// Fault Type DMA Manager
#define dmac_FTM_OFFSET 0x00000038

// Default Type DMA Channel 0
#define dmac_FTC0_OFFSET 0x00000040

// Default Type DMA Channel 1
#define dmac_FTCN_1_OFFSET 0x00000044

// Default Type DMA Channel 2
#define dmac_FTCN_2_OFFSET 0x00000048

// Default Type DMA Channel 3
#define dmac_FTCN_3_OFFSET 0x0000004c

// Default Type DMA Channel 4
#define dmac_FTCN_4_OFFSET 0x00000050

// Default Type DMA Channel 5
#define dmac_FTCN_5_OFFSET 0x00000054

// Default Type DMA Channel 6
#define dmac_FTCN_6_OFFSET 0x00000058

// Default Type DMA Channel 7
#define dmac_FTCN_7_OFFSET 0x0000005c

// Channel Status DMA Channel 0
#define dmac_CS0_OFFSET 0x00000100

// Channel PC for DMA Channel 0
#define dmac_CPC0_OFFSET 0x00000104

// Channel Status DMA Channel 1
#define dmac_CSN_1_OFFSET 0x00000108

// Channel PC for DMA Channel 1
#define dmac_CPCN_1_OFFSET 0x0000010c

// Channel Status DMA Channel 2
#define dmac_CSN_2_OFFSET 0x00000110

// Channel PC for DMA Channel 2
#define dmac_CPCN_2_OFFSET 0x00000114

// Channel Status DMA Channel 3
#define dmac_CSN_3_OFFSET 0x00000118

// Channel PC for DMA Channel 3
#define dmac_CPCN_3_OFFSET 0x0000011c

// Channel Status DMA Channel 4
#define dmac_CSN_4_OFFSET 0x00000120

// Channel PC for DMA Channel 4
#define dmac_CPCN_4_OFFSET 0x00000124

// Channel Status DMA Channel 5
#define dmac_CSN_5_OFFSET 0x00000128

// Channel PC for DMA Channel 5
#define dmac_CPCN_5_OFFSET 0x0000012c

// Channel Status DMA Channel 6
#define dmac_CSN_6_OFFSET 0x00000130

// Channel PC for DMA Channel 6
#define dmac_CPCN_6_OFFSET 0x00000134

// Channel Status DMA Channel 7
#define dmac_CSN_7_OFFSET 0x00000138

// Channel PC for DMA Channel 7
#define dmac_CPCN_7_OFFSET 0x0000013c

// Source Address DMA Channel 0
#define dmac_SA_0_OFFSET 0x00000400

// Destination Addr DMA Channel 0
#define dmac_DA_0_OFFSET 0x00000404

// Channel Control DMA Channel 0
#define dmac_CC_0_OFFSET 0x00000408

// Loop Counter 0 DMA Channel 0
#define dmac_LC0_0_OFFSET 0x0000040c

// Loop Counter 1 DMA Channel 0
#define dmac_LC1_0_OFFSET 0x00000410

// Source address DMA Channel 1
#define dmac_SA_N_1_OFFSET 0x00000420

// Destination Addr DMA Channel 1
#define dmac_DA_N_1_OFFSET 0x00000424

// Channel Control DMA Channel 1
#define dmac_CC_N_1_OFFSET 0x00000428

// Loop Counter 0 DMA Channel 1
#define dmac_LC0_N_1_OFFSET 0x0000042c

// Loop Counter 1 DMA Channel 1
#define dmac_LC1_N_1_OFFSET 0x00000430

// Source Address DMA Channel 2
#define dmac_SA_N_2_OFFSET 0x00000440

// Destination Addr DMA Channel 2
#define dmac_DA_N_2_OFFSET 0x00000444

// Channel Control DMA Channel 2
#define dmac_CC_N_2_OFFSET 0x00000448

// Loop Counter 0 DMA Channel 2
#define dmac_LC0_N_2_OFFSET 0x0000044c

// Loop Counter 1 DMA Channel 2
#define dmac_LC1_N_2_OFFSET 0x00000450

// Source Address DMA Channel 3
#define dmac_SA_N_3_OFFSET 0x00000460

// Destination Addr DMA Channel 3
#define dmac_DA_N_3_OFFSET 0x00000464

// Channel Control DMA Channel 3
#define dmac_CC_N_3_OFFSET 0x00000468

// Loop Counter 0 DMA Channel 3
#define dmac_LC0_N_3_OFFSET 0x0000046c

// Loop Counter 1 DMA Channel 3
#define dmac_LC1_N_3_OFFSET 0x00000470

// Source Address DMA Channel 4
#define dmac_SA_N_4_OFFSET 0x00000480

// Destination Addr DMA Channel 4
#define dmac_DA_N_4_OFFSET 0x00000484

// Channel Control DMA Channel 4
#define dmac_CC_N_4_OFFSET 0x00000488

// Loop Counter 0 DMA Channel 4
#define dmac_LC0_N_4_OFFSET 0x0000048c

// Loop Counter 1 DMA Channel 4
#define dmac_LC1_N_4_OFFSET 0x00000490

// Source Address DMA Channel 5
#define dmac_SA_N_5_OFFSET 0x000004a0

// Destination Addr DMA Channel 5
#define dmac_DA_N_5_OFFSET 0x000004a4

// Channel Control DMA Channel 5
#define dmac_CC_N_5_OFFSET 0x000004a8

// Loop Counter 0 DMA Channel 5
#define dmac_LC0_N_5_OFFSET 0x000004ac

// Loop Counter 1 DMA Channel 5
#define dmac_LC1_N_5_OFFSET 0x000004b0

// Source Address DMA Channel 6
#define dmac_SA_N_6_OFFSET 0x000004c0

// Destination Addr DMA Channel 6
#define dmac_DA_N_6_OFFSET 0x000004c4

// Channel Control DMA Channel 6
#define dmac_CC_N_6_OFFSET 0x000004c8

// Loop Counter 0 DMA Channel 6
#define dmac_LC0_N_6_OFFSET 0x000004cc

// Loop Counter 1 DMA Channel 6
#define dmac_LC1_N_6_OFFSET 0x000004d0

// Source Address DMA Channel 7
#define dmac_SA_N_7_OFFSET 0x000004e0

// Destination Addr DMA Channel 7
#define dmac_DA_N_7_OFFSET 0x000004e4

// Channel Control DMA Channel 7
#define dmac_CC_N_7_OFFSET 0x000004e8

// Loop Counter 0 DMA Channel 7
#define dmac_LC0_N_7_OFFSET 0x000004ec

// Loop Counter 1 DMA Channel 7
#define dmac_LC1_N_7_OFFSET 0x000004f0

// DMA Manager Execution Status
#define dmac_DBGSTATUS_OFFSET 0x00000d00

// DMA Manager Instr. Command
#define dmac_DBGCMD_OFFSET 0x00000d04

// DMA Manager Instruction Part A
#define dmac_DBGINST0_OFFSET 0x00000d08

// DMA Manager Instruction Part B
#define dmac_DBGINST1_OFFSET 0x00000d0c

// Config. 0: Events, Peripheral Interfaces, PC, Mode
#define dmac_CR0_OFFSET 0x00000e00

// Config. 1: Instruction Cache
#define dmac_CR1_OFFSET 0x00000e04

// Config. 2: DMA Mgr Boot Addr
#define dmac_CR2_OFFSET 0x00000e08

// Config. 3: Security state of IRQs
#define dmac_CR3_OFFSET 0x00000e0c

// Config 4, Security of Periph Interfaces
#define dmac_CR4_OFFSET 0x00000e10

// DMA configuration
#define dmac_CRDN_OFFSET 0x00000e14

// Watchdog Timer
#define dmac_WD_OFFSET 0x00000e80

// Peripheral Idenfication register 0
#define dmac_PERIPH_ID_0_OFFSET 0x00000fe0

// Peripheral Idenfication register 1
#define dmac_PERIPH_ID_1_OFFSET 0x00000fe4

// Peripheral Idenfication register 2
#define dmac_PERIPH_ID_2_OFFSET 0x00000fe8

// Peripheral Idenfication register 3
#define dmac_PERIPH_ID_3_OFFSET 0x00000fec

// Compontent Idenfication register 0
#define dmac_PCELL_ID_0_OFFSET 0x00000ff0

// Compontent Idenfication register 1
#define dmac_PCELL_ID_1_OFFSET 0x00000ff4

// Compontent Idenfication register 2
#define dmac_PCELL_ID_2_OFFSET 0x00000ff8

// Compontent Idenfication register 3
#define dmac_PCELL_ID_3_OFFSET 0x00000ffc
