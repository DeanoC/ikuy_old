#pragma once
// Copyright Deano Calver
// SPDX-License-Identifier: MIT
// CoreSight Trace Funnel
// Auto-generated on Mon Sep 21 19:32:27 EEST 2020

#include <stdint.h>

// 1 banks of funnel chips
#define funnel_BASE_ADDR 0xf8804000U

// CSTF Control Register
#define funnel_CONTROL_OFFSET 0x00000000U

// CSTF Priority Control Register
#define funnel_PRICONTROL_OFFSET 0x00000004U

// Integration Test ATB Data 0 Register
#define funnel_ITATBDATA0_OFFSET 0x00000eecU

// Integration Test ATB Control 2 Register
#define funnel_ITATBCTR2_OFFSET 0x00000ef0U

// Integration Test ATB Control 1 Register
#define funnel_ITATBCTR1_OFFSET 0x00000ef4U

// Integration Test ATB Control 0 Register
#define funnel_ITATBCTR0_OFFSET 0x00000ef8U

// Integration Mode Control Register
#define funnel_IMCR_OFFSET 0x00000f00U

// Claim Tag Set Register
#define funnel_CTSR_OFFSET 0x00000fa0U

// Claim Tag Clear Register
#define funnel_CTCR_OFFSET 0x00000fa4U

// Lock Access Register
#define funnel_LAR_OFFSET 0x00000fb0U

// Lock Status Register
#define funnel_LSR_OFFSET 0x00000fb4U

// Authentication Status Register
#define funnel_ASR_OFFSET 0x00000fb8U

// Device ID
#define funnel_DEVID_OFFSET 0x00000fc8U

// Device Type Identifier Register
#define funnel_DTIR_OFFSET 0x00000fccU

// Peripheral ID4
#define funnel_PERIPHID4_OFFSET 0x00000fd0U

// Peripheral ID5
#define funnel_PERIPHID5_OFFSET 0x00000fd4U

// Peripheral ID6
#define funnel_PERIPHID6_OFFSET 0x00000fd8U

// Peripheral ID7
#define funnel_PERIPHID7_OFFSET 0x00000fdcU

// Peripheral ID0
#define funnel_PERIPHID0_OFFSET 0x00000fe0U

// Peripheral ID1
#define funnel_PERIPHID1_OFFSET 0x00000fe4U

// Peripheral ID2
#define funnel_PERIPHID2_OFFSET 0x00000fe8U

// Peripheral ID3
#define funnel_PERIPHID3_OFFSET 0x00000fecU

// Component ID0
#define funnel_COMPID0_OFFSET 0x00000ff0U

// Component ID1
#define funnel_COMPID1_OFFSET 0x00000ff4U

// Component ID2
#define funnel_COMPID2_OFFSET 0x00000ff8U

// Component ID3
#define funnel_COMPID3_OFFSET 0x00000ffcU
