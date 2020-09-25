#pragma once
// Copyright Deano Calver
// SPDX-License-Identifier: MIT
// Fabric Trace
// Auto-generated on Fri Sep 25 10:29:41 EEST 2020

#include <stdint.h>

// 1 banks of itm chips
#define itm_BASE_ADDR 0xf8805000U

// Stimulus Port Register 0
#define itm_StimPort00_OFFSET 0x00000000U

// Stimulus Port Register 1
#define itm_StimPort01_OFFSET 0x00000004U

// Stimulus Port Register 2
#define itm_StimPort02_OFFSET 0x00000008U

// Stimulus Port Register 3
#define itm_StimPort03_OFFSET 0x0000000cU

// Stimulus Port Register 4
#define itm_StimPort04_OFFSET 0x00000010U

// Stimulus Port Register 5
#define itm_StimPort05_OFFSET 0x00000014U

// Stimulus Port Register 6
#define itm_StimPort06_OFFSET 0x00000018U

// Stimulus Port Register 7
#define itm_StimPort07_OFFSET 0x0000001cU

// Stimulus Port Register 8
#define itm_StimPort08_OFFSET 0x00000020U

// Stimulus Port Register 9
#define itm_StimPort09_OFFSET 0x00000024U

// Stimulus Port Register 10
#define itm_StimPort10_OFFSET 0x00000028U

// Stimulus Port Register 11
#define itm_StimPort11_OFFSET 0x0000002cU

// Stimulus Port Register 12
#define itm_StimPort12_OFFSET 0x00000030U

// Stimulus Port Register 13
#define itm_StimPort13_OFFSET 0x00000034U

// Stimulus Port Register 14
#define itm_StimPort14_OFFSET 0x00000038U

// Stimulus Port Register 15
#define itm_StimPort15_OFFSET 0x0000003cU

// Stimulus Port Register 16
#define itm_StimPort16_OFFSET 0x00000040U

// Stimulus Port Register 17
#define itm_StimPort17_OFFSET 0x00000044U

// Stimulus Port Register 18
#define itm_StimPort18_OFFSET 0x00000048U

// Stimulus Port Register 19
#define itm_StimPort19_OFFSET 0x0000004cU

// Stimulus Port Register 20
#define itm_StimPort20_OFFSET 0x00000050U

// Stimulus Port Register 21
#define itm_StimPort21_OFFSET 0x00000054U

// Stimulus Port Register 22
#define itm_StimPort22_OFFSET 0x00000058U

// Stimulus Port Register 23
#define itm_StimPort23_OFFSET 0x0000005cU

// Stimulus Port Register 24
#define itm_StimPort24_OFFSET 0x00000060U

// Stimulus Port Register 25
#define itm_StimPort25_OFFSET 0x00000064U

// Stimulus Port Register 26
#define itm_StimPort26_OFFSET 0x00000068U

// Stimulus Port Register 27
#define itm_StimPort27_OFFSET 0x0000006cU

// Stimulus Port Register 28
#define itm_StimPort28_OFFSET 0x00000070U

// Stimulus Port Register 29
#define itm_StimPort29_OFFSET 0x00000074U

// Stimulus Port Register 30
#define itm_StimPort30_OFFSET 0x00000078U

// Stimulus Port Register 31
#define itm_StimPort31_OFFSET 0x0000007cU

// Trace Enable Register
#define itm_TER_OFFSET 0x00000e00U

// Trace Trigger Register
#define itm_TTR_OFFSET 0x00000e20U

// Control Register
#define itm_CR_OFFSET 0x00000e80U

// Synchronization Control Register
#define itm_SCR_OFFSET 0x00000e90U

// Integration Test Trigger Out Acknowledge Register
#define itm_ITTRIGOUTACK_OFFSET 0x00000ee4U

// Integration Test Trigger Out Register
#define itm_ITTRIGOUT_OFFSET 0x00000ee8U

// Integration Test ATB Data Register 0
#define itm_ITATBDATA0_OFFSET 0x00000eecU

// Integration Test ATB Control Register 2
#define itm_ITATBCTR2_OFFSET 0x00000ef0U

// Integration Test ATB Control Register 1
#define itm_ITATABCTR1_OFFSET 0x00000ef4U

// Integration Test ATB Control Register 0
#define itm_ITATBCTR0_OFFSET 0x00000ef8U

// Integration Mode Control Register
#define itm_IMCR_OFFSET 0x00000f00U

// Claim Tag Set Register
#define itm_CTSR_OFFSET 0x00000fa0U

// Claim Tag Clear Register
#define itm_CTCR_OFFSET 0x00000fa4U

// Lock Access Register
#define itm_LAR_OFFSET 0x00000fb0U

// Lock Status Register
#define itm_LSR_OFFSET 0x00000fb4U

// Authentication Status Register
#define itm_ASR_OFFSET 0x00000fb8U

// Device ID
#define itm_DEVID_OFFSET 0x00000fc8U

// Device Type Identifier Register
#define itm_DTIR_OFFSET 0x00000fccU

// Peripheral ID4
#define itm_PERIPHID4_OFFSET 0x00000fd0U

// Peripheral ID5
#define itm_PERIPHID5_OFFSET 0x00000fd4U

// Peripheral ID6
#define itm_PERIPHID6_OFFSET 0x00000fd8U

// Peripheral ID7
#define itm_PERIPHID7_OFFSET 0x00000fdcU

// Peripheral ID0
#define itm_PERIPHID0_OFFSET 0x00000fe0U

// Peripheral ID1
#define itm_PERIPHID1_OFFSET 0x00000fe4U

// Peripheral ID2
#define itm_PERIPHID2_OFFSET 0x00000fe8U

// Peripheral ID3
#define itm_PERIPHID3_OFFSET 0x00000fecU

// Component ID0
#define itm_COMPID0_OFFSET 0x00000ff0U

// Component ID1
#define itm_COMPID1_OFFSET 0x00000ff4U

// Component ID2
#define itm_COMPID2_OFFSET 0x00000ff8U

// Component ID3
#define itm_COMPID3_OFFSET 0x00000ffcU
