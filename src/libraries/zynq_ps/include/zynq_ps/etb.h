#pragma once
// Copyright Deano Calver
// SPDX-License-Identifier: MIT
// Embedded Trace Buffer
// Auto-generated on Mon Sep 21 21:57:55 EEST 2020

#include <stdint.h>

// 1 banks of etb chips
#define etb_BASE_ADDR 0xf8801000U

// RAM Depth Register
#define etb_RDP_OFFSET 0x00000004U

// Status Register
#define etb_STS_OFFSET 0x0000000cU

// RAM Read Data Register
#define etb_RRD_OFFSET 0x00000010U

// RAM Read Pointer Register
#define etb_RRP_OFFSET 0x00000014U

// RAM Write Pointer Register
#define etb_RWP_OFFSET 0x00000018U

// Trigger Counter Register
#define etb_TRG_OFFSET 0x0000001cU

// Control Register
#define etb_CTL_OFFSET 0x00000020U

// RAM Write Data Register
#define etb_RWD_OFFSET 0x00000024U

// Formatter and Flush Status Register
#define etb_FFSR_OFFSET 0x00000300U

// Formatter and Flush Control Register
#define etb_FFCR_OFFSET 0x00000304U

// Integration Test Miscellaneous Output Register 0
#define etb_ITMISCOP0_OFFSET 0x00000ee0U

// Integration Test Trigger In and Flush In Acknowledge Register
#define etb_ITTRFLINACK_OFFSET 0x00000ee4U

// Integration Test Trigger In and Flush In Register
#define etb_ITTRFLIN_OFFSET 0x00000ee8U

// Integration Test ATB Data Register
#define etb_ITATBDATA0_OFFSET 0x00000eecU

// Integration Test ATB Control Register 2
#define etb_ITATBCTR2_OFFSET 0x00000ef0U

// Integration Test ATB Control Register 1
#define etb_ITATBCTR1_OFFSET 0x00000ef4U

// Integration Test ATB Control Register 0
#define etb_ITATBCTR0_OFFSET 0x00000ef8U

// Integration Mode Control Register
#define etb_IMCR_OFFSET 0x00000f00U

// Claim Tag Set Register
#define etb_CTSR_OFFSET 0x00000fa0U

// Claim Tag Clear Register
#define etb_CTCR_OFFSET 0x00000fa4U

// Lock Access Register
#define etb_LAR_OFFSET 0x00000fb0U

// Lock Status Register
#define etb_LSR_OFFSET 0x00000fb4U

// Authentication Status Register
#define etb_ASR_OFFSET 0x00000fb8U

// Device ID
#define etb_DEVID_OFFSET 0x00000fc8U

// Device Type Identifier Register
#define etb_DTIR_OFFSET 0x00000fccU

// Peripheral ID4
#define etb_PERIPHID4_OFFSET 0x00000fd0U

// Peripheral ID5
#define etb_PERIPHID5_OFFSET 0x00000fd4U

// Peripheral ID6
#define etb_PERIPHID6_OFFSET 0x00000fd8U

// Peripheral ID7
#define etb_PERIPHID7_OFFSET 0x00000fdcU

// Peripheral ID0
#define etb_PERIPHID0_OFFSET 0x00000fe0U

// Peripheral ID1
#define etb_PERIPHID1_OFFSET 0x00000fe4U

// Peripheral ID2
#define etb_PERIPHID2_OFFSET 0x00000fe8U

// Peripheral ID3
#define etb_PERIPHID3_OFFSET 0x00000fecU

// Component ID0
#define etb_COMPID0_OFFSET 0x00000ff0U

// Component ID1
#define etb_COMPID1_OFFSET 0x00000ff4U

// Component ID2
#define etb_COMPID2_OFFSET 0x00000ff8U

// Component ID3
#define etb_COMPID3_OFFSET 0x00000ffcU
