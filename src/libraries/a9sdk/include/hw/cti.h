#pragma once
// Copyright Deano Calver
// SPDX-License-Identifier: MIT

#include <stdint.h>

// CoreSight Cross Trigger Interface

// 4 banks of cti

#define debug_cpu_cti0_BASE_ADDR 0xf8898000U
#define debug_cpu_cti1_BASE_ADDR 0xf8899000U
#define debug_cti_etb_tpiu_BASE_ADDR 0xf8802000U
#define debug_cti_ftm_BASE_ADDR 0xf8809000U

// Registers

// CTI Control Register
#define cti_CTICONTROL_REG 0x0U


// CTI Interrupt Acknowledge Register
#define cti_CTIINTACK_REG 0x10U


// CTI Application Trigger Set Register
#define cti_CTIAPPSET_REG 0x14U


// CTI Application Trigger Clear Register
#define cti_CTIAPPCLEAR_REG 0x18U


// CTI Application Pulse Register
#define cti_CTIAPPPULSE_REG 0x1cU


// CTI Trigger to Channel Enable 0 Register
#define cti_CTIINEN0_REG 0x20U


// CTI Trigger to Channel Enable 1 Register
#define cti_CTIINEN1_REG 0x24U


// CTI Trigger to Channel Enable 2 Register
#define cti_CTIINEN2_REG 0x28U


// CTI Trigger to Channel Enable 3 Register
#define cti_CTIINEN3_REG 0x2cU


// CTI Trigger to Channel Enable 4 Register
#define cti_CTIINEN4_REG 0x30U


// CTI Trigger to Channel Enable 5 Register
#define cti_CTIINEN5_REG 0x34U


// CTI Trigger to Channel Enable 6 Register
#define cti_CTIINEN6_REG 0x38U


// CTI Trigger to Channel Enable 7 Register
#define cti_CTIINEN7_REG 0x3cU


// CTI Channel to Trigger Enable 0 Register
#define cti_CTIOUTEN0_REG 0xa0U


// CTI Channel to Trigger Enable 1 Register
#define cti_CTIOUTEN1_REG 0xa4U


// CTI Channel to Trigger Enable 2 Register
#define cti_CTIOUTEN2_REG 0xa8U


// CTI Channel to Trigger Enable 3 Register
#define cti_CTIOUTEN3_REG 0xacU


// CTI Channel to Trigger Enable 4 Register
#define cti_CTIOUTEN4_REG 0xb0U


// CTI Channel to Trigger Enable 5 Register
#define cti_CTIOUTEN5_REG 0xb4U


// CTI Channel to Trigger Enable 6 Register
#define cti_CTIOUTEN6_REG 0xb8U


// CTI Channel to Trigger Enable 7 Register
#define cti_CTIOUTEN7_REG 0xbcU


// 7 Register
#define cti_CTITRIGINSTATUS_REG 0x130U


// CTI Trigger Out Status Register
#define cti_CTITRIGOUTSTATUS_REG 0x134U


// Register
#define cti_CTICHINSTATUS_REG 0x138U


// CTI Channel Out Status Register
#define cti_CTICHOUTSTATUS_REG 0x13cU


// Enable CTI Channel Gate Register
#define cti_CTIGATE_REG 0x140U


// External Multiplexor Control Register
#define cti_ASICCTL_REG 0x144U


// ITCHINACK Register
#define cti_ITCHINACK_REG 0xedcU


// ITTRIGINACK Register
#define cti_ITTRIGINACK_REG 0xee0U


// ITCHOUT Register
#define cti_ITCHOUT_REG 0xee4U


// ITTRIGOUT Register
#define cti_ITTRIGOUT_REG 0xee8U


// ITCHOUTACK Register
#define cti_ITCHOUTACK_REG 0xeecU


// ITTRIGOUTACK Register
#define cti_ITTRIGOUTACK_REG 0xef0U


// ITCHIN Register
#define cti_ITCHIN_REG 0xef4U


// ITTRIGIN Register
#define cti_ITTRIGIN_REG 0xef8U


// IT Control Register
#define cti_ITCTRL_REG 0xf00U


// Claim Tag Set Register
#define cti_CTSR_REG 0xfa0U


// Claim Tag Clear Register
#define cti_CTCR_REG 0xfa4U


// Lock Access Register
#define cti_LAR_REG 0xfb0U


// Lock Status Register
#define cti_LSR_REG 0xfb4U


// Register
#define cti_ASR_REG 0xfb8U


// Device ID
#define cti_DEVID_REG 0xfc8U


// Device Type Identifier Register
#define cti_DTIR_REG 0xfccU


// Peripheral ID4
#define cti_PERIPHID4_REG 0xfd0U


// Peripheral ID5
#define cti_PERIPHID5_REG 0xfd4U


// Peripheral ID6
#define cti_PERIPHID6_REG 0xfd8U


// Peripheral ID7
#define cti_PERIPHID7_REG 0xfdcU


// Peripheral ID0
#define cti_PERIPHID0_REG 0xfe0U


// Peripheral ID1
#define cti_PERIPHID1_REG 0xfe4U


// Peripheral ID2
#define cti_PERIPHID2_REG 0xfe8U


// Peripheral ID3
#define cti_PERIPHID3_REG 0xfecU


// Component ID0
#define cti_COMPID0_REG 0xff0U


// Component ID1
#define cti_COMPID1_REG 0xff4U


// Component ID2
#define cti_COMPID2_REG 0xff8U


// Component ID3
#define cti_COMPID3_REG 0xffcU


