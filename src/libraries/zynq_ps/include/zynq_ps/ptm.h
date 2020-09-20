#pragma once
// Copyright Deano Calver
// SPDX-License-Identifier: MIT
// CoreSight PTM-A9
// Auto-generated on Sun Sep 20 15:25:57 EEST 2020

#include <stdint.h>

// 2 banks of ptm chips
#define debug_cpu_ptm0_BASE_ADDR 0xf889c000
#define debug_cpu_ptm1_BASE_ADDR 0xf889d000

// Main Control Register
#define ptm_CR_OFFSET 0x00000000

// Configuration Code Register
#define ptm_CCR_OFFSET 0x00000004

// Trigger Event Register
#define ptm_TRIGGER_OFFSET 0x00000008

// Status Register
#define ptm_SR_OFFSET 0x00000010

// System Configuration Register
#define ptm_SCR_OFFSET 0x00000014

// TraceEnable Start/Stop Control Register
#define ptm_TSSCR_OFFSET 0x00000018

// TraceEnable Event
#define ptm_TEEVR_OFFSET 0x00000020

// TraceEnable Control Register 1
#define ptm_TECR1_OFFSET 0x00000024

// Address Comparator Value Register 1
#define ptm_ACVR1_OFFSET 0x00000040

// Address Comparator Value Register 2
#define ptm_ACVR2_OFFSET 0x00000044

// Address Comparator Value Register 3
#define ptm_ACVR3_OFFSET 0x00000048

// Address Comparator Value Register 4
#define ptm_ACVR4_OFFSET 0x0000004c

// Address Comparator Value Register 5
#define ptm_ACVR5_OFFSET 0x00000050

// Address Comparator Value Register 6
#define ptm_ACVR6_OFFSET 0x00000054

// Address Comparator Value Register 7
#define ptm_ACVR7_OFFSET 0x00000058

// Address Comparator Value Register 8
#define ptm_ACVR8_OFFSET 0x0000005c

// Address Comparator Access Type Register 1
#define ptm_ACTR1_OFFSET 0x00000080

// Address Comparator Access Type Register 2
#define ptm_ACTR2_OFFSET 0x00000084

// Address Comparator Access Type Register 3
#define ptm_ACTR3_OFFSET 0x00000088

// Address Comparator Access Type Register 4
#define ptm_ACTR4_OFFSET 0x0000008c

// Address Comparator Access Type Register 5
#define ptm_ACTR5_OFFSET 0x00000090

// Address Comparator Access Type Register 6
#define ptm_ACTR6_OFFSET 0x00000094

// Address Comparator Access Type Register 7
#define ptm_ACTR7_OFFSET 0x00000098

// Address Comparator Access Type Register 8
#define ptm_ACTR8_OFFSET 0x0000009c

// Counter Reload Value Register 1
#define ptm_CNTRLDVR1_OFFSET 0x00000140

// Counter Reload Value Register 2
#define ptm_CNTRLDVR2_OFFSET 0x00000144

// Counter Enable Event Register 1
#define ptm_CNTENR1_OFFSET 0x00000150

// Counter Enable Event Register 2
#define ptm_CNTENR2_OFFSET 0x00000154

// Counter Reload Event Register 1
#define ptm_CNTRLDEVR1_OFFSET 0x00000160

// Counter Reload Event Register 2
#define ptm_CNTRLDEVR2_OFFSET 0x00000164

// Counter Value Register 1
#define ptm_CNTVR1_OFFSET 0x00000170

// Counter Value Register 2
#define ptm_CNTVR2_OFFSET 0x00000174

// Sequencer State Transition Event Register 12
#define ptm_SQ12EVR_OFFSET 0x00000180

// Sequencer State Transition Event Register 21
#define ptm_SQ21EVR_OFFSET 0x00000184

// Sequencer State Transition Event Register 23
#define ptm_SQ23EVR_OFFSET 0x00000188

// Sequencer State Transition Event Register 31
#define ptm_SQ31EVR_OFFSET 0x0000018c

// Sequencer State Transition Event Register 32
#define ptm_SQ32EVR_OFFSET 0x00000190

// Sequencer State Transition Event Register 13
#define ptm_SQ13EVR_OFFSET 0x00000194

// Current Sequencer State Register
#define ptm_SQR_OFFSET 0x0000019c

// External Output Event Register 1
#define ptm_EXTOUTEVR1_OFFSET 0x000001a0

// External Output Event Register 2
#define ptm_EXTOUTEVR2_OFFSET 0x000001a4

// Context ID Comparator Value Register
#define ptm_CIDCVR1_OFFSET 0x000001b0

// Context ID Comparator Mask Register
#define ptm_CIDCMR_OFFSET 0x000001bc

// Synchronization Frequency Register
#define ptm_SYNCFR_OFFSET 0x000001e0

// ID Register
#define ptm_IDR_OFFSET 0x000001e4

// Configuration Code Extension Register
#define ptm_CCER_OFFSET 0x000001e8

// Extended External Input Selection Register
#define ptm_EXTINSELR_OFFSET 0x000001ec

// Timestamp Event
#define ptm_TSEVR_OFFSET 0x000001f8

// Auxiliary Control Register
#define ptm_AUXCR_OFFSET 0x000001fc

// CoreSight Trace ID Register
#define ptm_TRACEIDR_OFFSET 0x00000200

// OS Lock Status Register
#define ptm_OSLSR_OFFSET 0x00000304

// Device Powerdown Status Register
#define ptm_PDSR_OFFSET 0x00000314

// Miscellaneous Outputs Register
#define ptm_ITMISCOUT_OFFSET 0x00000edc

// Miscellaneous Inputs Register
#define ptm_ITMISCIN_OFFSET 0x00000ee0

// Trigger Register
#define ptm_ITTRIGGER_OFFSET 0x00000ee8

// ATB Data 0 Register
#define ptm_ITATBDATA0_OFFSET 0x00000eec

// ATB Control 2 Register
#define ptm_ITATBCTR2_OFFSET 0x00000ef0

// ATB Identification Register
#define ptm_ITATBID_OFFSET 0x00000ef4

// ATB Control 0 Register
#define ptm_ITATBCTR0_OFFSET 0x00000ef8

// Integration Mode Control Register
#define ptm_ITCTRL_OFFSET 0x00000f00

// Claim Tag Set Register
#define ptm_CTSR_OFFSET 0x00000fa0

// Claim Tag Clear Register
#define ptm_CTCR_OFFSET 0x00000fa4

// Lock Access Register
#define ptm_LAR_OFFSET 0x00000fb0

// Lock Status Register
#define ptm_LSR_OFFSET 0x00000fb4

// Authentication Status Register
#define ptm_ASR_OFFSET 0x00000fb8

// Device ID
#define ptm_DEVID_OFFSET 0x00000fc8

// Device Type Identifier (ETMDEVTYPE)
#define ptm_DTIR_OFFSET 0x00000fcc

// Peripheral ID4
#define ptm_PERIPHID4_OFFSET 0x00000fd0

// Peripheral ID5
#define ptm_PERIPHID5_OFFSET 0x00000fd4

// Peripheral ID6
#define ptm_PERIPHID6_OFFSET 0x00000fd8

// Peripheral ID7
#define ptm_PERIPHID7_OFFSET 0x00000fdc

// Peripheral ID0
#define ptm_PERIPHID0_OFFSET 0x00000fe0

// Peripheral ID1
#define ptm_PERIPHID1_OFFSET 0x00000fe4

// Peripheral ID2
#define ptm_PERIPHID2_OFFSET 0x00000fe8

// Peripheral ID3
#define ptm_PERIPHID3_OFFSET 0x00000fec

// Component ID0
#define ptm_COMPID0_OFFSET 0x00000ff0

// Component ID1
#define ptm_COMPID1_OFFSET 0x00000ff4

// Component ID2
#define ptm_COMPID2_OFFSET 0x00000ff8

// Component ID3
#define ptm_COMPID3_OFFSET 0x00000ffc
