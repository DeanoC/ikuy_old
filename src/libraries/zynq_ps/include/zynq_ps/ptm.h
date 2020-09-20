#pragma once
// Copyright Deano Calver
// SPDX-License-Identifier: MIT
// CoreSight PTM-A9
// Auto-generated on Sun Sep 20 23:32:01 EEST 2020

#include <stdint.h>

// 2 banks of ptm chips
#define debug_cpu_ptm0_BASE_ADDR 0xf889c000U
#define debug_cpu_ptm1_BASE_ADDR 0xf889d000U

// Main Control Register
#define ptm_CR_OFFSET 0x00000000U

// Configuration Code Register
#define ptm_CCR_OFFSET 0x00000004U

// Trigger Event Register
#define ptm_TRIGGER_OFFSET 0x00000008U

// Status Register
#define ptm_SR_OFFSET 0x00000010U

// System Configuration Register
#define ptm_SCR_OFFSET 0x00000014U

// TraceEnable Start/Stop Control Register
#define ptm_TSSCR_OFFSET 0x00000018U

// TraceEnable Event
#define ptm_TEEVR_OFFSET 0x00000020U

// TraceEnable Control Register 1
#define ptm_TECR1_OFFSET 0x00000024U

// Address Comparator Value Register 1
#define ptm_ACVR1_OFFSET 0x00000040U

// Address Comparator Value Register 2
#define ptm_ACVR2_OFFSET 0x00000044U

// Address Comparator Value Register 3
#define ptm_ACVR3_OFFSET 0x00000048U

// Address Comparator Value Register 4
#define ptm_ACVR4_OFFSET 0x0000004cU

// Address Comparator Value Register 5
#define ptm_ACVR5_OFFSET 0x00000050U

// Address Comparator Value Register 6
#define ptm_ACVR6_OFFSET 0x00000054U

// Address Comparator Value Register 7
#define ptm_ACVR7_OFFSET 0x00000058U

// Address Comparator Value Register 8
#define ptm_ACVR8_OFFSET 0x0000005cU

// Address Comparator Access Type Register 1
#define ptm_ACTR1_OFFSET 0x00000080U

// Address Comparator Access Type Register 2
#define ptm_ACTR2_OFFSET 0x00000084U

// Address Comparator Access Type Register 3
#define ptm_ACTR3_OFFSET 0x00000088U

// Address Comparator Access Type Register 4
#define ptm_ACTR4_OFFSET 0x0000008cU

// Address Comparator Access Type Register 5
#define ptm_ACTR5_OFFSET 0x00000090U

// Address Comparator Access Type Register 6
#define ptm_ACTR6_OFFSET 0x00000094U

// Address Comparator Access Type Register 7
#define ptm_ACTR7_OFFSET 0x00000098U

// Address Comparator Access Type Register 8
#define ptm_ACTR8_OFFSET 0x0000009cU

// Counter Reload Value Register 1
#define ptm_CNTRLDVR1_OFFSET 0x00000140U

// Counter Reload Value Register 2
#define ptm_CNTRLDVR2_OFFSET 0x00000144U

// Counter Enable Event Register 1
#define ptm_CNTENR1_OFFSET 0x00000150U

// Counter Enable Event Register 2
#define ptm_CNTENR2_OFFSET 0x00000154U

// Counter Reload Event Register 1
#define ptm_CNTRLDEVR1_OFFSET 0x00000160U

// Counter Reload Event Register 2
#define ptm_CNTRLDEVR2_OFFSET 0x00000164U

// Counter Value Register 1
#define ptm_CNTVR1_OFFSET 0x00000170U

// Counter Value Register 2
#define ptm_CNTVR2_OFFSET 0x00000174U

// Sequencer State Transition Event Register 12
#define ptm_SQ12EVR_OFFSET 0x00000180U

// Sequencer State Transition Event Register 21
#define ptm_SQ21EVR_OFFSET 0x00000184U

// Sequencer State Transition Event Register 23
#define ptm_SQ23EVR_OFFSET 0x00000188U

// Sequencer State Transition Event Register 31
#define ptm_SQ31EVR_OFFSET 0x0000018cU

// Sequencer State Transition Event Register 32
#define ptm_SQ32EVR_OFFSET 0x00000190U

// Sequencer State Transition Event Register 13
#define ptm_SQ13EVR_OFFSET 0x00000194U

// Current Sequencer State Register
#define ptm_SQR_OFFSET 0x0000019cU

// External Output Event Register 1
#define ptm_EXTOUTEVR1_OFFSET 0x000001a0U

// External Output Event Register 2
#define ptm_EXTOUTEVR2_OFFSET 0x000001a4U

// Context ID Comparator Value Register
#define ptm_CIDCVR1_OFFSET 0x000001b0U

// Context ID Comparator Mask Register
#define ptm_CIDCMR_OFFSET 0x000001bcU

// Synchronization Frequency Register
#define ptm_SYNCFR_OFFSET 0x000001e0U

// ID Register
#define ptm_IDR_OFFSET 0x000001e4U

// Configuration Code Extension Register
#define ptm_CCER_OFFSET 0x000001e8U

// Extended External Input Selection Register
#define ptm_EXTINSELR_OFFSET 0x000001ecU

// Timestamp Event
#define ptm_TSEVR_OFFSET 0x000001f8U

// Auxiliary Control Register
#define ptm_AUXCR_OFFSET 0x000001fcU

// CoreSight Trace ID Register
#define ptm_TRACEIDR_OFFSET 0x00000200U

// OS Lock Status Register
#define ptm_OSLSR_OFFSET 0x00000304U

// Device Powerdown Status Register
#define ptm_PDSR_OFFSET 0x00000314U

// Miscellaneous Outputs Register
#define ptm_ITMISCOUT_OFFSET 0x00000edcU

// Miscellaneous Inputs Register
#define ptm_ITMISCIN_OFFSET 0x00000ee0U

// Trigger Register
#define ptm_ITTRIGGER_OFFSET 0x00000ee8U

// ATB Data 0 Register
#define ptm_ITATBDATA0_OFFSET 0x00000eecU

// ATB Control 2 Register
#define ptm_ITATBCTR2_OFFSET 0x00000ef0U

// ATB Identification Register
#define ptm_ITATBID_OFFSET 0x00000ef4U

// ATB Control 0 Register
#define ptm_ITATBCTR0_OFFSET 0x00000ef8U

// Integration Mode Control Register
#define ptm_ITCTRL_OFFSET 0x00000f00U

// Claim Tag Set Register
#define ptm_CTSR_OFFSET 0x00000fa0U

// Claim Tag Clear Register
#define ptm_CTCR_OFFSET 0x00000fa4U

// Lock Access Register
#define ptm_LAR_OFFSET 0x00000fb0U

// Lock Status Register
#define ptm_LSR_OFFSET 0x00000fb4U

// Authentication Status Register
#define ptm_ASR_OFFSET 0x00000fb8U

// Device ID
#define ptm_DEVID_OFFSET 0x00000fc8U

// Device Type Identifier (ETMDEVTYPE)
#define ptm_DTIR_OFFSET 0x00000fccU

// Peripheral ID4
#define ptm_PERIPHID4_OFFSET 0x00000fd0U

// Peripheral ID5
#define ptm_PERIPHID5_OFFSET 0x00000fd4U

// Peripheral ID6
#define ptm_PERIPHID6_OFFSET 0x00000fd8U

// Peripheral ID7
#define ptm_PERIPHID7_OFFSET 0x00000fdcU

// Peripheral ID0
#define ptm_PERIPHID0_OFFSET 0x00000fe0U

// Peripheral ID1
#define ptm_PERIPHID1_OFFSET 0x00000fe4U

// Peripheral ID2
#define ptm_PERIPHID2_OFFSET 0x00000fe8U

// Peripheral ID3
#define ptm_PERIPHID3_OFFSET 0x00000fecU

// Component ID0
#define ptm_COMPID0_OFFSET 0x00000ff0U

// Component ID1
#define ptm_COMPID1_OFFSET 0x00000ff4U

// Component ID2
#define ptm_COMPID2_OFFSET 0x00000ff8U

// Component ID3
#define ptm_COMPID3_OFFSET 0x00000ffcU
