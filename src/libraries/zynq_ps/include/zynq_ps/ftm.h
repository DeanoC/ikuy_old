#pragma once
// Copyright Deano Calver
// SPDX-License-Identifier: MIT
// Instrumentation Trace
// Auto-generated on Sun Sep 20 15:25:57 EEST 2020

#include <stdint.h>

// 1 banks of ftm chips
#define ftm_BASE_ADDR 0xf880b000

// FTM Global Control.
#define ftm_GLBCTRL_OFFSET 0x00000000

// FTM Status Register
#define ftm_STATUS_OFFSET 0x00000004

// FTM Configuration
#define ftm_CONTROL_OFFSET 0x00000008

// FPGA Debug Register P2F0
#define ftm_P2FDBG0_OFFSET 0x0000000c

// FPGA Debug Register P2F1
#define ftm_P2FDBG1_OFFSET 0x00000010

// FPGA Debug Register P2F2
#define ftm_P2FDBG2_OFFSET 0x00000014

// FPGA Debug Register P2F3
#define ftm_P2FDBG3_OFFSET 0x00000018

// FPGA Debug Register F2P0
#define ftm_F2PDBG0_OFFSET 0x0000001c

// FPGA Debug Register F2P1
#define ftm_F2PDBG1_OFFSET 0x00000020

// FPGA Debug Register F2P2
#define ftm_F2PDBG2_OFFSET 0x00000024

// FPGA Debug Register F2P3
#define ftm_F2PDBG3_OFFSET 0x00000028

// AXI Cycle Count clock pre-scaler
#define ftm_CYCOUNTPRE_OFFSET 0x0000002c

// FTM Synchronization Counter reload value
#define ftm_SYNCRELOAD_OFFSET 0x00000030

// FTM Synchronization Counter value
#define ftm_SYNCCOUT_OFFSET 0x00000034

// FTM ATID Value Register
#define ftm_ATID_OFFSET 0x00000400

// Trigger Output Acknowledge Integration Test Register
#define ftm_ITTRIGOUTACK_OFFSET 0x00000ed0

// Trigger Output Integration Test Register
#define ftm_ITTRIGGER_OFFSET 0x00000ed4

// External Trace Disable Integration Test Register
#define ftm_ITTRACEDIS_OFFSET 0x00000ed8

// Cycle Counter Test Register
#define ftm_ITCYCCOUNT_OFFSET 0x00000edc

// ATB Data Integration Test Register 0
#define ftm_ITATBDATA0_OFFSET 0x00000eec

// ATB Control Integration Test Register 2
#define ftm_ITATBCTR2_OFFSET 0x00000ef0

// ATB Control Integration Test Register 1
#define ftm_ITATBCTR1_OFFSET 0x00000ef4

// ATB Control Integration Test Register 0
#define ftm_ITATBCTR0_OFFSET 0x00000ef8

// FTM Test Control Register
#define ftm_ITCR_OFFSET 0x00000f00

// Claim Tag Set Register
#define ftm_CLAIMTAGSET_OFFSET 0x00000fa0

// Claim Tag Clear Register
#define ftm_CLAIMTAGCLR_OFFSET 0x00000fa4

// Lock Access Register
#define ftm_LOCK_ACCESS_OFFSET 0x00000fb0

// Lock Status Register
#define ftm_LOCK_STATUS_OFFSET 0x00000fb4

// Authentication Status Register
#define ftm_AUTHSTATUS_OFFSET 0x00000fb8

// Device Configuration Register
#define ftm_DEVID_OFFSET 0x00000fc8

// Device Type Identification Register
#define ftm_DEV_TYPE_OFFSET 0x00000fcc

// Peripheral ID4
#define ftm_PERIPHID4_OFFSET 0x00000fd0

// Peripheral ID5
#define ftm_PERIPHID5_OFFSET 0x00000fd4

// Peripheral ID6
#define ftm_PERIPHID6_OFFSET 0x00000fd8

// Peripheral ID7
#define ftm_PERIPHID7_OFFSET 0x00000fdc

// Peripheral ID0
#define ftm_PERIPHID0_OFFSET 0x00000fe0

// Peripheral ID1
#define ftm_PERIPHID1_OFFSET 0x00000fe4

// Peripheral ID2
#define ftm_PERIPHID2_OFFSET 0x00000fe8

// Peripheral ID3
#define ftm_PERIPHID3_OFFSET 0x00000fec

// Component ID0
#define ftm_COMPONID0_OFFSET 0x00000ff0

// Component ID1
#define ftm_COMPONID1_OFFSET 0x00000ff4

// Component ID2
#define ftm_COMPONID2_OFFSET 0x00000ff8

// Component ID3
#define ftm_COMPONID3_OFFSET 0x00000ffc
