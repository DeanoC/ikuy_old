#pragma once
// Copyright Deano Calver
// SPDX-License-Identifier: MIT
// CoreSight Cross Trigger Interface
// Auto-generated on Sun Sep 20 15:25:57 EEST 2020

#include <stdint.h>

// 4 banks of cti chips
#define debug_cpu_cti0_BASE_ADDR 0xf8898000
#define debug_cpu_cti1_BASE_ADDR 0xf8899000
#define debug_cpu_etb_tpiu_BASE_ADDR 0xf8802000
#define debug_cpu_ftm_BASE_ADDR 0xf8809000

// CTI Control Register
#define cti_CTICONTROL_OFFSET 0x00000000

// CTI Interrupt Acknowledge Register
#define cti_CTIINTACK_OFFSET 0x00000010

// CTI Application Trigger Set Register
#define cti_CTIAPPSET_OFFSET 0x00000014

// CTI Application Trigger Clear Register
#define cti_CTIAPPCLEAR_OFFSET 0x00000018

// CTI Application Pulse Register
#define cti_CTIAPPPULSE_OFFSET 0x0000001c

// CTI Trigger to Channel Enable 0 Register
#define cti_CTIINEN0_OFFSET 0x00000020

// CTI Trigger to Channel Enable 1 Register
#define cti_CTIINEN1_OFFSET 0x00000024

// CTI Trigger to Channel Enable 2 Register
#define cti_CTIINEN2_OFFSET 0x00000028

// CTI Trigger to Channel Enable 3 Register
#define cti_CTIINEN3_OFFSET 0x0000002c

// CTI Trigger to Channel Enable 4 Register
#define cti_CTIINEN4_OFFSET 0x00000030

// CTI Trigger to Channel Enable 5 Register
#define cti_CTIINEN5_OFFSET 0x00000034

// CTI Trigger to Channel Enable 6 Register
#define cti_CTIINEN6_OFFSET 0x00000038

// CTI Trigger to Channel Enable 7 Register
#define cti_CTIINEN7_OFFSET 0x0000003c

// CTI Channel to Trigger Enable 0 Register
#define cti_CTIOUTEN0_OFFSET 0x000000a0

// CTI Channel to Trigger Enable 1 Register
#define cti_CTIOUTEN1_OFFSET 0x000000a4

// CTI Channel to Trigger Enable 2 Register
#define cti_CTIOUTEN2_OFFSET 0x000000a8

// CTI Channel to Trigger Enable 3 Register
#define cti_CTIOUTEN3_OFFSET 0x000000ac

// CTI Channel to Trigger Enable 4 Register
#define cti_CTIOUTEN4_OFFSET 0x000000b0

// CTI Channel to Trigger Enable 5 Register
#define cti_CTIOUTEN5_OFFSET 0x000000b4

// CTI Channel to Trigger Enable 6 Register
#define cti_CTIOUTEN6_OFFSET 0x000000b8

// CTI Channel to Trigger Enable 7 Register
#define cti_CTIOUTEN7_OFFSET 0x000000bc

// CTI Trigger In Status Register
#define cti_CTITRIGINSTATUS_OFFSET 0x00000130

// CTI Trigger Out Status Register
#define cti_CTITRIGOUTSTATUS_OFFSET 0x00000134

// CTI Channel In Status Register
#define cti_CTICHINSTATUS_OFFSET 0x00000138

// CTI Channel Out Status Register
#define cti_CTICHOUTSTATUS_OFFSET 0x0000013c

// Enable CTI Channel Gate Register
#define cti_CTIGATE_OFFSET 0x00000140

// External Multiplexor Control Register
#define cti_ASICCTL_OFFSET 0x00000144

// ITCHINACK Register
#define cti_ITCHINACK_OFFSET 0x00000edc

// ITTRIGINACK Register
#define cti_ITTRIGINACK_OFFSET 0x00000ee0

// ITCHOUT Register
#define cti_ITCHOUT_OFFSET 0x00000ee4

// ITTRIGOUT Register
#define cti_ITTRIGOUT_OFFSET 0x00000ee8

// ITCHOUTACK Register
#define cti_ITCHOUTACK_OFFSET 0x00000eec

// ITTRIGOUTACK Register
#define cti_ITTRIGOUTACK_OFFSET 0x00000ef0

// ITCHIN Register
#define cti_ITCHIN_OFFSET 0x00000ef4

// ITTRIGIN Register
#define cti_ITTRIGIN_OFFSET 0x00000ef8

// IT Control Register
#define cti_ITCTRL_OFFSET 0x00000f00

// Claim Tag Set Register
#define cti_CTSR_OFFSET 0x00000fa0

// Claim Tag Clear Register
#define cti_CTCR_OFFSET 0x00000fa4

// Lock Access Register
#define cti_LAR_OFFSET 0x00000fb0

// Lock Status Register
#define cti_LSR_OFFSET 0x00000fb4

// Authentication Status Register
#define cti_ASR_OFFSET 0x00000fb8

// Device ID
#define cti_DEVID_OFFSET 0x00000fc8

// Device Type Identifier Register
#define cti_DTIR_OFFSET 0x00000fcc

// Peripheral ID4
#define cti_PERIPHID4_OFFSET 0x00000fd0

// Peripheral ID5
#define cti_PERIPHID5_OFFSET 0x00000fd4

// Peripheral ID6
#define cti_PERIPHID6_OFFSET 0x00000fd8

// Peripheral ID7
#define cti_PERIPHID7_OFFSET 0x00000fdc

// Peripheral ID0
#define cti_PERIPHID0_OFFSET 0x00000fe0

// Peripheral ID1
#define cti_PERIPHID1_OFFSET 0x00000fe4

// Peripheral ID2
#define cti_PERIPHID2_OFFSET 0x00000fe8

// Peripheral ID3
#define cti_PERIPHID3_OFFSET 0x00000fec

// Component ID0
#define cti_COMPID0_OFFSET 0x00000ff0

// Component ID1
#define cti_COMPID1_OFFSET 0x00000ff4

// Component ID2
#define cti_COMPID2_OFFSET 0x00000ff8

// Component ID3
#define cti_COMPID3_OFFSET 0x00000ffc
