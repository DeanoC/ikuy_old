#pragma once
// Copyright Deano Calver
// SPDX-License-Identifier: MIT
// Static Memory Controller
// Auto-generated on Sun Sep 20 23:32:01 EEST 2020

#include <stdint.h>

// 1 banks of smcc chips
#define smcc_BASE_ADDR 0xe000e000U

// Operating and Interrupt Status
#define smcc_MEMC_STATUS_OFFSET 0x00000000U

// SMC configuration information
#define smcc_MEMC_IF_CONFIG_OFFSET 0x00000004U

// Enable interrupts and lower power state
#define smcc_MEMC_SET_CONFIG_OFFSET 0x00000008U

// Disable interrupts and exit from low-power state
#define smcc_MEMC_CLR_CONFIG_OFFSET 0x0000000cU

// Issue mem commands and register updates
#define smcc_DIRECT_CMD_OFFSET 0x00000010U

// Stage a write to a Cycle register
#define smcc_SET_CYCLES_OFFSET 0x00000014U

// Stage a write to an OpMode register
#define smcc_SET_OPMODE_OFFSET 0x00000018U

// Idle cycles between read/write bursts
#define smcc_REFRESH_PERIOD_0_OFFSET 0x00000020U

// Insert idle cycles between bursts
#define smcc_REFRESH_PERIOD_1_OFFSET 0x00000024U

// SRAM/NOR chip select 0 timing, active
#define smcc_IF0_CHIP_0_CONFIG_OFFSET 0x00000100U

// SRAM/NOR chip select 0 OpCode, active
#define smcc_OPMODE_OFFSET 0x00000104U

// SRAM/NOR chip select 1 timing, active
#define smcc_IF0_CHIP_1_CONFIG_OFFSET 0x00000120U

// SRAM/NOR chip select 1 OpCode, active
#define smcc_OPMODE0_1_OFFSET 0x00000124U

// NAND Flash timing, active
#define smcc_IF1_CHIP_0_CONFIG_OFFSET 0x00000180U

// NAND Flash OpCode, active
#define smcc_OPMODE1_0_OFFSET 0x00000184U

// User Status
#define smcc_USER_STATUS_OFFSET 0x00000200U

// User Configuration
#define smcc_USER_CONFIG_OFFSET 0x00000204U

// ECC Status and Clear
#define smcc_IF1_ECC_OFFSET 0x00000400U

// ECC Memory Configuation
#define smcc_ECC_MEMCFG_1_OFFSET 0x00000404U

// ECC Memory Command 1
#define smcc_ECC_MEMCOMMAND1_1_OFFSET 0x00000408U

// ECC Memory Command 2
#define smcc_ECC_MEMCOMMAND2_1_OFFSET 0x0000040cU

// ECC Address 0
#define smcc_ECC_ADDR0_1_OFFSET 0x00000410U

// ECC Address 1
#define smcc_ECC_ADDR1_1_OFFSET 0x00000414U

// ECC Value 0
#define smcc_ECC_VALUE0_1_OFFSET 0x00000418U

// ECC Value 1
#define smcc_ECC_VALUE1_1_OFFSET 0x0000041cU

// ECC Value 2
#define smcc_ECC_VALUE2_1_OFFSET 0x00000420U

// ECC Value 3
#define smcc_ECC_VALUE3_1_OFFSET 0x00000424U
