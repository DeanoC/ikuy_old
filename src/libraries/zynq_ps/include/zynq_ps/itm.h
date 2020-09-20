#pragma once
// Copyright Deano Calver
// SPDX-License-Identifier: MIT
// Fabric Trace
// Auto-generated on Sun Sep 20 15:25:57 EEST 2020

#include <stdint.h>

// 1 banks of itm chips
#define itm_BASE_ADDR 0xf8805000

// Stimulus Port Register 0
#define itm_StimPort00_OFFSET 0x00000000

// Stimulus Port Register 1
#define itm_StimPort01_OFFSET 0x00000004

// Stimulus Port Register 2
#define itm_StimPort02_OFFSET 0x00000008

// Stimulus Port Register 3
#define itm_StimPort03_OFFSET 0x0000000c

// Stimulus Port Register 4
#define itm_StimPort04_OFFSET 0x00000010

// Stimulus Port Register 5
#define itm_StimPort05_OFFSET 0x00000014

// Stimulus Port Register 6
#define itm_StimPort06_OFFSET 0x00000018

// Stimulus Port Register 7
#define itm_StimPort07_OFFSET 0x0000001c

// Stimulus Port Register 8
#define itm_StimPort08_OFFSET 0x00000020

// Stimulus Port Register 9
#define itm_StimPort09_OFFSET 0x00000024

// Stimulus Port Register 10
#define itm_StimPort10_OFFSET 0x00000028

// Stimulus Port Register 11
#define itm_StimPort11_OFFSET 0x0000002c

// Stimulus Port Register 12
#define itm_StimPort12_OFFSET 0x00000030

// Stimulus Port Register 13
#define itm_StimPort13_OFFSET 0x00000034

// Stimulus Port Register 14
#define itm_StimPort14_OFFSET 0x00000038

// Stimulus Port Register 15
#define itm_StimPort15_OFFSET 0x0000003c

// Stimulus Port Register 16
#define itm_StimPort16_OFFSET 0x00000040

// Stimulus Port Register 17
#define itm_StimPort17_OFFSET 0x00000044

// Stimulus Port Register 18
#define itm_StimPort18_OFFSET 0x00000048

// Stimulus Port Register 19
#define itm_StimPort19_OFFSET 0x0000004c

// Stimulus Port Register 20
#define itm_StimPort20_OFFSET 0x00000050

// Stimulus Port Register 21
#define itm_StimPort21_OFFSET 0x00000054

// Stimulus Port Register 22
#define itm_StimPort22_OFFSET 0x00000058

// Stimulus Port Register 23
#define itm_StimPort23_OFFSET 0x0000005c

// Stimulus Port Register 24
#define itm_StimPort24_OFFSET 0x00000060

// Stimulus Port Register 25
#define itm_StimPort25_OFFSET 0x00000064

// Stimulus Port Register 26
#define itm_StimPort26_OFFSET 0x00000068

// Stimulus Port Register 27
#define itm_StimPort27_OFFSET 0x0000006c

// Stimulus Port Register 28
#define itm_StimPort28_OFFSET 0x00000070

// Stimulus Port Register 29
#define itm_StimPort29_OFFSET 0x00000074

// Stimulus Port Register 30
#define itm_StimPort30_OFFSET 0x00000078

// Stimulus Port Register 31
#define itm_StimPort31_OFFSET 0x0000007c

// Trace Enable Register
#define itm_TER_OFFSET 0x00000e00

// Trace Trigger Register
#define itm_TTR_OFFSET 0x00000e20

// Control Register
#define itm_CR_OFFSET 0x00000e80

// Synchronization Control Register
#define itm_SCR_OFFSET 0x00000e90

// Integration Test Trigger Out Acknowledge Register
#define itm_ITTRIGOUTACK_OFFSET 0x00000ee4

// Integration Test Trigger Out Register
#define itm_ITTRIGOUT_OFFSET 0x00000ee8

// Integration Test ATB Data Register 0
#define itm_ITATBDATA0_OFFSET 0x00000eec

// Integration Test ATB Control Register 2
#define itm_ITATBCTR2_OFFSET 0x00000ef0

// Integration Test ATB Control Register 1
#define itm_ITATABCTR1_OFFSET 0x00000ef4

// Integration Test ATB Control Register 0
#define itm_ITATBCTR0_OFFSET 0x00000ef8

// Integration Mode Control Register
#define itm_IMCR_OFFSET 0x00000f00

// Claim Tag Set Register
#define itm_CTSR_OFFSET 0x00000fa0

// Claim Tag Clear Register
#define itm_CTCR_OFFSET 0x00000fa4

// Lock Access Register
#define itm_LAR_OFFSET 0x00000fb0

// Lock Status Register
#define itm_LSR_OFFSET 0x00000fb4

// Authentication Status Register
#define itm_ASR_OFFSET 0x00000fb8

// Device ID
#define itm_DEVID_OFFSET 0x00000fc8

// Device Type Identifier Register
#define itm_DTIR_OFFSET 0x00000fcc

// Peripheral ID4
#define itm_PERIPHID4_OFFSET 0x00000fd0

// Peripheral ID5
#define itm_PERIPHID5_OFFSET 0x00000fd4

// Peripheral ID6
#define itm_PERIPHID6_OFFSET 0x00000fd8

// Peripheral ID7
#define itm_PERIPHID7_OFFSET 0x00000fdc

// Peripheral ID0
#define itm_PERIPHID0_OFFSET 0x00000fe0

// Peripheral ID1
#define itm_PERIPHID1_OFFSET 0x00000fe4

// Peripheral ID2
#define itm_PERIPHID2_OFFSET 0x00000fe8

// Peripheral ID3
#define itm_PERIPHID3_OFFSET 0x00000fec

// Component ID0
#define itm_COMPID0_OFFSET 0x00000ff0

// Component ID1
#define itm_COMPID1_OFFSET 0x00000ff4

// Component ID2
#define itm_COMPID2_OFFSET 0x00000ff8

// Component ID3
#define itm_COMPID3_OFFSET 0x00000ffc
