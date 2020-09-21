#pragma once
// Copyright Deano Calver
// SPDX-License-Identifier: MIT
// Direct Memory Access Controller (PL330)
// Auto-generated on Mon Sep 21 19:32:27 EEST 2020

#include <stdint.h>

// 2 banks of dmac chips
#define dmac0_s_BASE_ADDR 0xf8003000U
#define dmac0_ns_BASE_ADDR 0xf8004000U

// DMA Manager Status
#define dmac_DS_OFFSET 0x00000000U

// DMA Program Counter
#define dmac_DPC_OFFSET 0x00000004U

// DMASEV Instruction Response Control
#define dmac_INTEN_OFFSET 0x00000020U

// Event Interrupt Raw Status
#define dmac_ES_OFFSET 0x00000024U

// Interrupt Status
#define dmac_INTSTATUS_OFFSET 0x00000028U

// Interrupt Clear
#define dmac_INTCLR_OFFSET 0x0000002cU

// Fault Status DMA Manager
#define dmac_FSM_OFFSET 0x00000030U

// Fault Status DMA Channel
#define dmac_FSC_OFFSET 0x00000034U

// Fault Type DMA Manager
#define dmac_FTM_OFFSET 0x00000038U

// Default Type DMA Channel 0
#define dmac_FTC0_OFFSET 0x00000040U

// Default Type DMA Channel 1
#define dmac_FTCN_1_OFFSET 0x00000044U

// Default Type DMA Channel 2
#define dmac_FTCN_2_OFFSET 0x00000048U

// Default Type DMA Channel 3
#define dmac_FTCN_3_OFFSET 0x0000004cU

// Default Type DMA Channel 4
#define dmac_FTCN_4_OFFSET 0x00000050U

// Default Type DMA Channel 5
#define dmac_FTCN_5_OFFSET 0x00000054U

// Default Type DMA Channel 6
#define dmac_FTCN_6_OFFSET 0x00000058U

// Default Type DMA Channel 7
#define dmac_FTCN_7_OFFSET 0x0000005cU

// Channel Status DMA Channel 0
#define dmac_CS0_OFFSET 0x00000100U

// Channel PC for DMA Channel 0
#define dmac_CPC0_OFFSET 0x00000104U

// Channel Status DMA Channel 1
#define dmac_CSN_1_OFFSET 0x00000108U

// Channel PC for DMA Channel 1
#define dmac_CPCN_1_OFFSET 0x0000010cU

// Channel Status DMA Channel 2
#define dmac_CSN_2_OFFSET 0x00000110U

// Channel PC for DMA Channel 2
#define dmac_CPCN_2_OFFSET 0x00000114U

// Channel Status DMA Channel 3
#define dmac_CSN_3_OFFSET 0x00000118U

// Channel PC for DMA Channel 3
#define dmac_CPCN_3_OFFSET 0x0000011cU

// Channel Status DMA Channel 4
#define dmac_CSN_4_OFFSET 0x00000120U

// Channel PC for DMA Channel 4
#define dmac_CPCN_4_OFFSET 0x00000124U

// Channel Status DMA Channel 5
#define dmac_CSN_5_OFFSET 0x00000128U

// Channel PC for DMA Channel 5
#define dmac_CPCN_5_OFFSET 0x0000012cU

// Channel Status DMA Channel 6
#define dmac_CSN_6_OFFSET 0x00000130U

// Channel PC for DMA Channel 6
#define dmac_CPCN_6_OFFSET 0x00000134U

// Channel Status DMA Channel 7
#define dmac_CSN_7_OFFSET 0x00000138U

// Channel PC for DMA Channel 7
#define dmac_CPCN_7_OFFSET 0x0000013cU

// Source Address DMA Channel 0
#define dmac_SA_0_OFFSET 0x00000400U

// Destination Addr DMA Channel 0
#define dmac_DA_0_OFFSET 0x00000404U

// Channel Control DMA Channel 0
#define dmac_CC_0_OFFSET 0x00000408U

// Loop Counter 0 DMA Channel 0
#define dmac_LC0_0_OFFSET 0x0000040cU

// Loop Counter 1 DMA Channel 0
#define dmac_LC1_0_OFFSET 0x00000410U

// Source address DMA Channel 1
#define dmac_SA_N_1_OFFSET 0x00000420U

// Destination Addr DMA Channel 1
#define dmac_DA_N_1_OFFSET 0x00000424U

// Channel Control DMA Channel 1
#define dmac_CC_N_1_OFFSET 0x00000428U

// Loop Counter 0 DMA Channel 1
#define dmac_LC0_N_1_OFFSET 0x0000042cU

// Loop Counter 1 DMA Channel 1
#define dmac_LC1_N_1_OFFSET 0x00000430U

// Source Address DMA Channel 2
#define dmac_SA_N_2_OFFSET 0x00000440U

// Destination Addr DMA Channel 2
#define dmac_DA_N_2_OFFSET 0x00000444U

// Channel Control DMA Channel 2
#define dmac_CC_N_2_OFFSET 0x00000448U

// Loop Counter 0 DMA Channel 2
#define dmac_LC0_N_2_OFFSET 0x0000044cU

// Loop Counter 1 DMA Channel 2
#define dmac_LC1_N_2_OFFSET 0x00000450U

// Source Address DMA Channel 3
#define dmac_SA_N_3_OFFSET 0x00000460U

// Destination Addr DMA Channel 3
#define dmac_DA_N_3_OFFSET 0x00000464U

// Channel Control DMA Channel 3
#define dmac_CC_N_3_OFFSET 0x00000468U

// Loop Counter 0 DMA Channel 3
#define dmac_LC0_N_3_OFFSET 0x0000046cU

// Loop Counter 1 DMA Channel 3
#define dmac_LC1_N_3_OFFSET 0x00000470U

// Source Address DMA Channel 4
#define dmac_SA_N_4_OFFSET 0x00000480U

// Destination Addr DMA Channel 4
#define dmac_DA_N_4_OFFSET 0x00000484U

// Channel Control DMA Channel 4
#define dmac_CC_N_4_OFFSET 0x00000488U

// Loop Counter 0 DMA Channel 4
#define dmac_LC0_N_4_OFFSET 0x0000048cU

// Loop Counter 1 DMA Channel 4
#define dmac_LC1_N_4_OFFSET 0x00000490U

// Source Address DMA Channel 5
#define dmac_SA_N_5_OFFSET 0x000004a0U

// Destination Addr DMA Channel 5
#define dmac_DA_N_5_OFFSET 0x000004a4U

// Channel Control DMA Channel 5
#define dmac_CC_N_5_OFFSET 0x000004a8U

// Loop Counter 0 DMA Channel 5
#define dmac_LC0_N_5_OFFSET 0x000004acU

// Loop Counter 1 DMA Channel 5
#define dmac_LC1_N_5_OFFSET 0x000004b0U

// Source Address DMA Channel 6
#define dmac_SA_N_6_OFFSET 0x000004c0U

// Destination Addr DMA Channel 6
#define dmac_DA_N_6_OFFSET 0x000004c4U

// Channel Control DMA Channel 6
#define dmac_CC_N_6_OFFSET 0x000004c8U

// Loop Counter 0 DMA Channel 6
#define dmac_LC0_N_6_OFFSET 0x000004ccU

// Loop Counter 1 DMA Channel 6
#define dmac_LC1_N_6_OFFSET 0x000004d0U

// Source Address DMA Channel 7
#define dmac_SA_N_7_OFFSET 0x000004e0U

// Destination Addr DMA Channel 7
#define dmac_DA_N_7_OFFSET 0x000004e4U

// Channel Control DMA Channel 7
#define dmac_CC_N_7_OFFSET 0x000004e8U

// Loop Counter 0 DMA Channel 7
#define dmac_LC0_N_7_OFFSET 0x000004ecU

// Loop Counter 1 DMA Channel 7
#define dmac_LC1_N_7_OFFSET 0x000004f0U

// DMA Manager Execution Status
#define dmac_DBGSTATUS_OFFSET 0x00000d00U

// DMA Manager Instr. Command
#define dmac_DBGCMD_OFFSET 0x00000d04U

// DMA Manager Instruction Part A
#define dmac_DBGINST0_OFFSET 0x00000d08U

// DMA Manager Instruction Part B
#define dmac_DBGINST1_OFFSET 0x00000d0cU

// Config. 0: Events, Peripheral Interfaces, PC, Mode
#define dmac_CR0_OFFSET 0x00000e00U

// Config. 1: Instruction Cache
#define dmac_CR1_OFFSET 0x00000e04U

// Config. 2: DMA Mgr Boot Addr
#define dmac_CR2_OFFSET 0x00000e08U

// Config. 3: Security state of IRQs
#define dmac_CR3_OFFSET 0x00000e0cU

// Config 4, Security of Periph Interfaces
#define dmac_CR4_OFFSET 0x00000e10U

// DMA configuration
#define dmac_CRDN_OFFSET 0x00000e14U

// Watchdog Timer
#define dmac_WD_OFFSET 0x00000e80U

// Peripheral Idenfication register 0
#define dmac_PERIPH_ID_0_OFFSET 0x00000fe0U

// Peripheral Idenfication register 1
#define dmac_PERIPH_ID_1_OFFSET 0x00000fe4U

// Peripheral Idenfication register 2
#define dmac_PERIPH_ID_2_OFFSET 0x00000fe8U

// Peripheral Idenfication register 3
#define dmac_PERIPH_ID_3_OFFSET 0x00000fecU

// Compontent Idenfication register 0
#define dmac_PCELL_ID_0_OFFSET 0x00000ff0U

// Compontent Idenfication register 1
#define dmac_PCELL_ID_1_OFFSET 0x00000ff4U

// Compontent Idenfication register 2
#define dmac_PCELL_ID_2_OFFSET 0x00000ff8U

// Compontent Idenfication register 3
#define dmac_PCELL_ID_3_OFFSET 0x00000ffcU
