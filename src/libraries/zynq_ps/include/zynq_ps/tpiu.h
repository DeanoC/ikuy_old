#pragma once
// Copyright Deano Calver
// SPDX-License-Identifier: MIT
// Trace Port Interface
// Auto-generated on Sun Sep 20 23:32:01 EEST 2020

#include <stdint.h>

// 1 banks of tpiu chips
#define tpiu_BASE_ADDR 0xf8803000U

// Supported Port Size Register
#define tpiu_SuppSize_OFFSET 0x00000000U

// Current Port Size Register
#define tpiu_CurrentSize_OFFSET 0x00000004U

// Supported Trigger Modes Register
#define tpiu_SuppTrigMode_OFFSET 0x00000100U

// Trigger Counter Register
#define tpiu_TrigCount_OFFSET 0x00000104U

// Trigger Multiplier Register
#define tpiu_TrigMult_OFFSET 0x00000108U

// Supported Test Patterns/Modes Register
#define tpiu_SuppTest_OFFSET 0x00000200U

// Current Test Patterns/Modes Register
#define tpiu_CurrentTest_OFFSET 0x00000204U

// TPIU Test Pattern Repeat Counter Register
#define tpiu_TestRepeatCount_OFFSET 0x00000208U

// Formatter and Flush Status Register
#define tpiu_FFSR_OFFSET 0x00000300U

// Formatter and Flush Control Register
#define tpiu_FFCR_OFFSET 0x00000304U

// Formatter Synchronization Counter Register
#define tpiu_FormatSyncCount_OFFSET 0x00000308U

// EXTCTL In Port
#define tpiu_EXTCTLIn_OFFSET 0x00000400U

// EXTCTL Out Port
#define tpiu_EXTCTLOut_OFFSET 0x00000404U

// Integration Test Trigger In and Flush In Acknowledge Register
#define tpiu_ITTRFLINACK_OFFSET 0x00000ee4U

// Integration Test Trigger In and Flush In Register
#define tpiu_ITTRFLIN_OFFSET 0x00000ee8U

// Integration Test ATB Data Register 0
#define tpiu_ITATBDATA0_OFFSET 0x00000eecU

// Integration Test ATB Control Register 2
#define tpiu_ITATBCTR2_OFFSET 0x00000ef0U

// Integration Test ATB Control Register 1
#define tpiu_ITATBCTR1_OFFSET 0x00000ef4U

// Integration Test ATB Control Register 0
#define tpiu_ITATBCTR0_OFFSET 0x00000ef8U

// Integration Mode Control Register
#define tpiu_IMCR_OFFSET 0x00000f00U

// Claim Tag Set Register
#define tpiu_CTSR_OFFSET 0x00000fa0U

// Claim Tag Clear Register
#define tpiu_CTCR_OFFSET 0x00000fa4U

// Lock Access Register
#define tpiu_LAR_OFFSET 0x00000fb0U

// Lock Status Register
#define tpiu_LSR_OFFSET 0x00000fb4U

// Authentication Status Register
#define tpiu_ASR_OFFSET 0x00000fb8U

// Device ID
#define tpiu_DEVID_OFFSET 0x00000fc8U

// Device Type Identifier Register
#define tpiu_DTIR_OFFSET 0x00000fccU

// Peripheral ID4
#define tpiu_PERIPHID4_OFFSET 0x00000fd0U

// Peripheral ID5
#define tpiu_PERIPHID5_OFFSET 0x00000fd4U

// Peripheral ID6
#define tpiu_PERIPHID6_OFFSET 0x00000fd8U

// Peripheral ID7
#define tpiu_PERIPHID7_OFFSET 0x00000fdcU

// Peripheral ID0
#define tpiu_PERIPHID0_OFFSET 0x00000fe0U

// Peripheral ID1
#define tpiu_PERIPHID1_OFFSET 0x00000fe4U

// Peripheral ID2
#define tpiu_PERIPHID2_OFFSET 0x00000fe8U

// Peripheral ID3
#define tpiu_PERIPHID3_OFFSET 0x00000fecU

// Component ID0
#define tpiu_COMPID0_OFFSET 0x00000ff0U

// Component ID1
#define tpiu_COMPID1_OFFSET 0x00000ff4U

// Component ID2
#define tpiu_COMPID2_OFFSET 0x00000ff8U

// Component ID3
#define tpiu_COMPID3_OFFSET 0x00000ffcU
