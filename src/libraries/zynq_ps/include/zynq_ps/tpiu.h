#pragma once
// Copyright Deano Calver
// SPDX-License-Identifier: MIT
// Trace Port Interface
// Auto-generated on Sun Sep 20 15:25:57 EEST 2020

#include <stdint.h>

// 1 banks of tpiu chips
#define tpiu_BASE_ADDR 0xf8803000

// Supported Port Size Register
#define tpiu_SuppSize_OFFSET 0x00000000

// Current Port Size Register
#define tpiu_CurrentSize_OFFSET 0x00000004

// Supported Trigger Modes Register
#define tpiu_SuppTrigMode_OFFSET 0x00000100

// Trigger Counter Register
#define tpiu_TrigCount_OFFSET 0x00000104

// Trigger Multiplier Register
#define tpiu_TrigMult_OFFSET 0x00000108

// Supported Test Patterns/Modes Register
#define tpiu_SuppTest_OFFSET 0x00000200

// Current Test Patterns/Modes Register
#define tpiu_CurrentTest_OFFSET 0x00000204

// TPIU Test Pattern Repeat Counter Register
#define tpiu_TestRepeatCount_OFFSET 0x00000208

// Formatter and Flush Status Register
#define tpiu_FFSR_OFFSET 0x00000300

// Formatter and Flush Control Register
#define tpiu_FFCR_OFFSET 0x00000304

// Formatter Synchronization Counter Register
#define tpiu_FormatSyncCount_OFFSET 0x00000308

// EXTCTL In Port
#define tpiu_EXTCTLIn_OFFSET 0x00000400

// EXTCTL Out Port
#define tpiu_EXTCTLOut_OFFSET 0x00000404

// Integration Test Trigger In and Flush In Acknowledge Register
#define tpiu_ITTRFLINACK_OFFSET 0x00000ee4

// Integration Test Trigger In and Flush In Register
#define tpiu_ITTRFLIN_OFFSET 0x00000ee8

// Integration Test ATB Data Register 0
#define tpiu_ITATBDATA0_OFFSET 0x00000eec

// Integration Test ATB Control Register 2
#define tpiu_ITATBCTR2_OFFSET 0x00000ef0

// Integration Test ATB Control Register 1
#define tpiu_ITATBCTR1_OFFSET 0x00000ef4

// Integration Test ATB Control Register 0
#define tpiu_ITATBCTR0_OFFSET 0x00000ef8

// Integration Mode Control Register
#define tpiu_IMCR_OFFSET 0x00000f00

// Claim Tag Set Register
#define tpiu_CTSR_OFFSET 0x00000fa0

// Claim Tag Clear Register
#define tpiu_CTCR_OFFSET 0x00000fa4

// Lock Access Register
#define tpiu_LAR_OFFSET 0x00000fb0

// Lock Status Register
#define tpiu_LSR_OFFSET 0x00000fb4

// Authentication Status Register
#define tpiu_ASR_OFFSET 0x00000fb8

// Device ID
#define tpiu_DEVID_OFFSET 0x00000fc8

// Device Type Identifier Register
#define tpiu_DTIR_OFFSET 0x00000fcc

// Peripheral ID4
#define tpiu_PERIPHID4_OFFSET 0x00000fd0

// Peripheral ID5
#define tpiu_PERIPHID5_OFFSET 0x00000fd4

// Peripheral ID6
#define tpiu_PERIPHID6_OFFSET 0x00000fd8

// Peripheral ID7
#define tpiu_PERIPHID7_OFFSET 0x00000fdc

// Peripheral ID0
#define tpiu_PERIPHID0_OFFSET 0x00000fe0

// Peripheral ID1
#define tpiu_PERIPHID1_OFFSET 0x00000fe4

// Peripheral ID2
#define tpiu_PERIPHID2_OFFSET 0x00000fe8

// Peripheral ID3
#define tpiu_PERIPHID3_OFFSET 0x00000fec

// Component ID0
#define tpiu_COMPID0_OFFSET 0x00000ff0

// Component ID1
#define tpiu_COMPID1_OFFSET 0x00000ff4

// Component ID2
#define tpiu_COMPID2_OFFSET 0x00000ff8

// Component ID3
#define tpiu_COMPID3_OFFSET 0x00000ffc
