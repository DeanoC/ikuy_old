#pragma once
// Copyright Deano Calver
// SPDX-License-Identifier: MIT
// CoreSight Cross Trigger Interface
// Auto-generated on Mon Sep 21 17:18:27 EEST 2020

#include <stdint.h>

// 4 banks of cti chips
#define debug_cpu_cti0_BASE_ADDR 0xf8898000U
#define debug_cpu_cti1_BASE_ADDR 0xf8899000U
#define debug_cpu_etb_tpiu_BASE_ADDR 0xf8802000U
#define debug_cpu_ftm_BASE_ADDR 0xf8809000U

// CTI Control Register
#define cti_CTICONTROL_OFFSET 0x00000000U

// CTI Interrupt Acknowledge Register
#define cti_CTIINTACK_OFFSET 0x00000010U

// CTI Application Trigger Set Register
#define cti_CTIAPPSET_OFFSET 0x00000014U

// CTI Application Trigger Clear Register
#define cti_CTIAPPCLEAR_OFFSET 0x00000018U

// CTI Application Pulse Register
#define cti_CTIAPPPULSE_OFFSET 0x0000001cU

// CTI Trigger to Channel Enable 0 Register
#define cti_CTIINEN0_OFFSET 0x00000020U

// CTI Trigger to Channel Enable 1 Register
#define cti_CTIINEN1_OFFSET 0x00000024U

// CTI Trigger to Channel Enable 2 Register
#define cti_CTIINEN2_OFFSET 0x00000028U

// CTI Trigger to Channel Enable 3 Register
#define cti_CTIINEN3_OFFSET 0x0000002cU

// CTI Trigger to Channel Enable 4 Register
#define cti_CTIINEN4_OFFSET 0x00000030U

// CTI Trigger to Channel Enable 5 Register
#define cti_CTIINEN5_OFFSET 0x00000034U

// CTI Trigger to Channel Enable 6 Register
#define cti_CTIINEN6_OFFSET 0x00000038U

// CTI Trigger to Channel Enable 7 Register
#define cti_CTIINEN7_OFFSET 0x0000003cU

// CTI Channel to Trigger Enable 0 Register
#define cti_CTIOUTEN0_OFFSET 0x000000a0U

// CTI Channel to Trigger Enable 1 Register
#define cti_CTIOUTEN1_OFFSET 0x000000a4U

// CTI Channel to Trigger Enable 2 Register
#define cti_CTIOUTEN2_OFFSET 0x000000a8U

// CTI Channel to Trigger Enable 3 Register
#define cti_CTIOUTEN3_OFFSET 0x000000acU

// CTI Channel to Trigger Enable 4 Register
#define cti_CTIOUTEN4_OFFSET 0x000000b0U

// CTI Channel to Trigger Enable 5 Register
#define cti_CTIOUTEN5_OFFSET 0x000000b4U

// CTI Channel to Trigger Enable 6 Register
#define cti_CTIOUTEN6_OFFSET 0x000000b8U

// CTI Channel to Trigger Enable 7 Register
#define cti_CTIOUTEN7_OFFSET 0x000000bcU

// CTI Trigger In Status Register
#define cti_CTITRIGINSTATUS_OFFSET 0x00000130U

// CTI Trigger Out Status Register
#define cti_CTITRIGOUTSTATUS_OFFSET 0x00000134U

// CTI Channel In Status Register
#define cti_CTICHINSTATUS_OFFSET 0x00000138U

// CTI Channel Out Status Register
#define cti_CTICHOUTSTATUS_OFFSET 0x0000013cU

// Enable CTI Channel Gate Register
#define cti_CTIGATE_OFFSET 0x00000140U

// External Multiplexor Control Register
#define cti_ASICCTL_OFFSET 0x00000144U

// ITCHINACK Register
#define cti_ITCHINACK_OFFSET 0x00000edcU

// ITTRIGINACK Register
#define cti_ITTRIGINACK_OFFSET 0x00000ee0U

// ITCHOUT Register
#define cti_ITCHOUT_OFFSET 0x00000ee4U

// ITTRIGOUT Register
#define cti_ITTRIGOUT_OFFSET 0x00000ee8U

// ITCHOUTACK Register
#define cti_ITCHOUTACK_OFFSET 0x00000eecU

// ITTRIGOUTACK Register
#define cti_ITTRIGOUTACK_OFFSET 0x00000ef0U

// ITCHIN Register
#define cti_ITCHIN_OFFSET 0x00000ef4U

// ITTRIGIN Register
#define cti_ITTRIGIN_OFFSET 0x00000ef8U

// IT Control Register
#define cti_ITCTRL_OFFSET 0x00000f00U

// Claim Tag Set Register
#define cti_CTSR_OFFSET 0x00000fa0U

// Claim Tag Clear Register
#define cti_CTCR_OFFSET 0x00000fa4U

// Lock Access Register
#define cti_LAR_OFFSET 0x00000fb0U

// Lock Status Register
#define cti_LSR_OFFSET 0x00000fb4U

// Authentication Status Register
#define cti_ASR_OFFSET 0x00000fb8U

// Device ID
#define cti_DEVID_OFFSET 0x00000fc8U

// Device Type Identifier Register
#define cti_DTIR_OFFSET 0x00000fccU

// Peripheral ID4
#define cti_PERIPHID4_OFFSET 0x00000fd0U

// Peripheral ID5
#define cti_PERIPHID5_OFFSET 0x00000fd4U

// Peripheral ID6
#define cti_PERIPHID6_OFFSET 0x00000fd8U

// Peripheral ID7
#define cti_PERIPHID7_OFFSET 0x00000fdcU

// Peripheral ID0
#define cti_PERIPHID0_OFFSET 0x00000fe0U

// Peripheral ID1
#define cti_PERIPHID1_OFFSET 0x00000fe4U

// Peripheral ID2
#define cti_PERIPHID2_OFFSET 0x00000fe8U

// Peripheral ID3
#define cti_PERIPHID3_OFFSET 0x00000fecU

// Component ID0
#define cti_COMPID0_OFFSET 0x00000ff0U

// Component ID1
#define cti_COMPID1_OFFSET 0x00000ff4U

// Component ID2
#define cti_COMPID2_OFFSET 0x00000ff8U

// Component ID3
#define cti_COMPID3_OFFSET 0x00000ffcU
