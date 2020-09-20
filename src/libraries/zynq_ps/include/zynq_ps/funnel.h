#pragma once
// Copyright Deano Calver
// SPDX-License-Identifier: MIT
// CoreSight Trace Funnel
// Auto-generated on Sun Sep 20 15:25:57 EEST 2020

#include <stdint.h>

// 1 banks of funnel chips
#define funnel_BASE_ADDR 0xf8804000

// CSTF Control Register
#define funnel_CONTROL_OFFSET 0x00000000

// CSTF Priority Control Register
#define funnel_PRICONTROL_OFFSET 0x00000004

// Integration Test ATB Data 0 Register
#define funnel_ITATBDATA0_OFFSET 0x00000eec

// Integration Test ATB Control 2 Register
#define funnel_ITATBCTR2_OFFSET 0x00000ef0

// Integration Test ATB Control 1 Register
#define funnel_ITATBCTR1_OFFSET 0x00000ef4

// Integration Test ATB Control 0 Register
#define funnel_ITATBCTR0_OFFSET 0x00000ef8

// Integration Mode Control Register
#define funnel_IMCR_OFFSET 0x00000f00

// Claim Tag Set Register
#define funnel_CTSR_OFFSET 0x00000fa0

// Claim Tag Clear Register
#define funnel_CTCR_OFFSET 0x00000fa4

// Lock Access Register
#define funnel_LAR_OFFSET 0x00000fb0

// Lock Status Register
#define funnel_LSR_OFFSET 0x00000fb4

// Authentication Status Register
#define funnel_ASR_OFFSET 0x00000fb8

// Device ID
#define funnel_DEVID_OFFSET 0x00000fc8

// Device Type Identifier Register
#define funnel_DTIR_OFFSET 0x00000fcc

// Peripheral ID4
#define funnel_PERIPHID4_OFFSET 0x00000fd0

// Peripheral ID5
#define funnel_PERIPHID5_OFFSET 0x00000fd4

// Peripheral ID6
#define funnel_PERIPHID6_OFFSET 0x00000fd8

// Peripheral ID7
#define funnel_PERIPHID7_OFFSET 0x00000fdc

// Peripheral ID0
#define funnel_PERIPHID0_OFFSET 0x00000fe0

// Peripheral ID1
#define funnel_PERIPHID1_OFFSET 0x00000fe4

// Peripheral ID2
#define funnel_PERIPHID2_OFFSET 0x00000fe8

// Peripheral ID3
#define funnel_PERIPHID3_OFFSET 0x00000fec

// Component ID0
#define funnel_COMPID0_OFFSET 0x00000ff0

// Component ID1
#define funnel_COMPID1_OFFSET 0x00000ff4

// Component ID2
#define funnel_COMPID2_OFFSET 0x00000ff8

// Component ID3
#define funnel_COMPID3_OFFSET 0x00000ffc
