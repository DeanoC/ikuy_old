#pragma once
// Copyright Deano Calver
// SPDX-License-Identifier: MIT
// Embedded Trace Buffer
// Auto-generated on Sun Sep 20 15:25:57 EEST 2020

#include <stdint.h>

// 1 banks of etb chips
#define etb_BASE_ADDR 0xf8801000

// RAM Depth Register
#define etb_RDP_OFFSET 0x00000004

// Status Register
#define etb_STS_OFFSET 0x0000000c

// RAM Read Data Register
#define etb_RRD_OFFSET 0x00000010

// RAM Read Pointer Register
#define etb_RRP_OFFSET 0x00000014

// RAM Write Pointer Register
#define etb_RWP_OFFSET 0x00000018

// Trigger Counter Register
#define etb_TRG_OFFSET 0x0000001c

// Control Register
#define etb_CTL_OFFSET 0x00000020

// RAM Write Data Register
#define etb_RWD_OFFSET 0x00000024

// Formatter and Flush Status Register
#define etb_FFSR_OFFSET 0x00000300

// Formatter and Flush Control Register
#define etb_FFCR_OFFSET 0x00000304

// Integration Test Miscellaneous Output Register 0
#define etb_ITMISCOP0_OFFSET 0x00000ee0

// Integration Test Trigger In and Flush In Acknowledge Register
#define etb_ITTRFLINACK_OFFSET 0x00000ee4

// Integration Test Trigger In and Flush In Register
#define etb_ITTRFLIN_OFFSET 0x00000ee8

// Integration Test ATB Data Register
#define etb_ITATBDATA0_OFFSET 0x00000eec

// Integration Test ATB Control Register 2
#define etb_ITATBCTR2_OFFSET 0x00000ef0

// Integration Test ATB Control Register 1
#define etb_ITATBCTR1_OFFSET 0x00000ef4

// Integration Test ATB Control Register 0
#define etb_ITATBCTR0_OFFSET 0x00000ef8

// Integration Mode Control Register
#define etb_IMCR_OFFSET 0x00000f00

// Claim Tag Set Register
#define etb_CTSR_OFFSET 0x00000fa0

// Claim Tag Clear Register
#define etb_CTCR_OFFSET 0x00000fa4

// Lock Access Register
#define etb_LAR_OFFSET 0x00000fb0

// Lock Status Register
#define etb_LSR_OFFSET 0x00000fb4

// Authentication Status Register
#define etb_ASR_OFFSET 0x00000fb8

// Device ID
#define etb_DEVID_OFFSET 0x00000fc8

// Device Type Identifier Register
#define etb_DTIR_OFFSET 0x00000fcc

// Peripheral ID4
#define etb_PERIPHID4_OFFSET 0x00000fd0

// Peripheral ID5
#define etb_PERIPHID5_OFFSET 0x00000fd4

// Peripheral ID6
#define etb_PERIPHID6_OFFSET 0x00000fd8

// Peripheral ID7
#define etb_PERIPHID7_OFFSET 0x00000fdc

// Peripheral ID0
#define etb_PERIPHID0_OFFSET 0x00000fe0

// Peripheral ID1
#define etb_PERIPHID1_OFFSET 0x00000fe4

// Peripheral ID2
#define etb_PERIPHID2_OFFSET 0x00000fe8

// Peripheral ID3
#define etb_PERIPHID3_OFFSET 0x00000fec

// Component ID0
#define etb_COMPID0_OFFSET 0x00000ff0

// Component ID1
#define etb_COMPID1_OFFSET 0x00000ff4

// Component ID2
#define etb_COMPID2_OFFSET 0x00000ff8

// Component ID3
#define etb_COMPID3_OFFSET 0x00000ffc
