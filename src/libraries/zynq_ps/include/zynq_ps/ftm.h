#pragma once
// Copyright Deano Calver
// SPDX-License-Identifier: MIT
// Instrumentation Trace
// Auto-generated on Mon Sep 21 21:57:55 EEST 2020

#include <stdint.h>

// 1 banks of ftm chips
#define ftm_BASE_ADDR 0xf880b000U

// FTM Global Control.
#define ftm_GLBCTRL_OFFSET 0x00000000U

// FTM Status Register
#define ftm_STATUS_OFFSET 0x00000004U

// FTM Configuration
#define ftm_CONTROL_OFFSET 0x00000008U

// FPGA Debug Register P2F0
#define ftm_P2FDBG0_OFFSET 0x0000000cU

// FPGA Debug Register P2F1
#define ftm_P2FDBG1_OFFSET 0x00000010U

// FPGA Debug Register P2F2
#define ftm_P2FDBG2_OFFSET 0x00000014U

// FPGA Debug Register P2F3
#define ftm_P2FDBG3_OFFSET 0x00000018U

// FPGA Debug Register F2P0
#define ftm_F2PDBG0_OFFSET 0x0000001cU

// FPGA Debug Register F2P1
#define ftm_F2PDBG1_OFFSET 0x00000020U

// FPGA Debug Register F2P2
#define ftm_F2PDBG2_OFFSET 0x00000024U

// FPGA Debug Register F2P3
#define ftm_F2PDBG3_OFFSET 0x00000028U

// AXI Cycle Count clock pre-scaler
#define ftm_CYCOUNTPRE_OFFSET 0x0000002cU

// FTM Synchronization Counter reload value
#define ftm_SYNCRELOAD_OFFSET 0x00000030U

// FTM Synchronization Counter value
#define ftm_SYNCCOUT_OFFSET 0x00000034U

// FTM ATID Value Register
#define ftm_ATID_OFFSET 0x00000400U

// Trigger Output Acknowledge Integration Test Register
#define ftm_ITTRIGOUTACK_OFFSET 0x00000ed0U

// Trigger Output Integration Test Register
#define ftm_ITTRIGGER_OFFSET 0x00000ed4U

// External Trace Disable Integration Test Register
#define ftm_ITTRACEDIS_OFFSET 0x00000ed8U

// Cycle Counter Test Register
#define ftm_ITCYCCOUNT_OFFSET 0x00000edcU

// ATB Data Integration Test Register 0
#define ftm_ITATBDATA0_OFFSET 0x00000eecU

// ATB Control Integration Test Register 2
#define ftm_ITATBCTR2_OFFSET 0x00000ef0U

// ATB Control Integration Test Register 1
#define ftm_ITATBCTR1_OFFSET 0x00000ef4U

// ATB Control Integration Test Register 0
#define ftm_ITATBCTR0_OFFSET 0x00000ef8U

// FTM Test Control Register
#define ftm_ITCR_OFFSET 0x00000f00U

// Claim Tag Set Register
#define ftm_CLAIMTAGSET_OFFSET 0x00000fa0U

// Claim Tag Clear Register
#define ftm_CLAIMTAGCLR_OFFSET 0x00000fa4U

// Lock Access Register
#define ftm_LOCK_ACCESS_OFFSET 0x00000fb0U

// Lock Status Register
#define ftm_LOCK_STATUS_OFFSET 0x00000fb4U

// Authentication Status Register
#define ftm_AUTHSTATUS_OFFSET 0x00000fb8U

// Device Configuration Register
#define ftm_DEVID_OFFSET 0x00000fc8U

// Device Type Identification Register
#define ftm_DEV_TYPE_OFFSET 0x00000fccU

// Peripheral ID4
#define ftm_PERIPHID4_OFFSET 0x00000fd0U

// Peripheral ID5
#define ftm_PERIPHID5_OFFSET 0x00000fd4U

// Peripheral ID6
#define ftm_PERIPHID6_OFFSET 0x00000fd8U

// Peripheral ID7
#define ftm_PERIPHID7_OFFSET 0x00000fdcU

// Peripheral ID0
#define ftm_PERIPHID0_OFFSET 0x00000fe0U

// Peripheral ID1
#define ftm_PERIPHID1_OFFSET 0x00000fe4U

// Peripheral ID2
#define ftm_PERIPHID2_OFFSET 0x00000fe8U

// Peripheral ID3
#define ftm_PERIPHID3_OFFSET 0x00000fecU

// Component ID0
#define ftm_COMPONID0_OFFSET 0x00000ff0U

// Component ID1
#define ftm_COMPONID1_OFFSET 0x00000ff4U

// Component ID2
#define ftm_COMPONID2_OFFSET 0x00000ff8U

// Component ID3
#define ftm_COMPONID3_OFFSET 0x00000ffcU
