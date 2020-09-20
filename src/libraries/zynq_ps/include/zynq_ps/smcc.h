#pragma once
// Copyright Deano Calver
// SPDX-License-Identifier: MIT
// Static Memory Controller
// Auto-generated on Sun Sep 20 15:25:57 EEST 2020

#include <stdint.h>

// 1 banks of smcc chips
#define smcc_BASE_ADDR 0xe000e000

// Operating and Interrupt Status
#define smcc_MEMC_STATUS_OFFSET 0x00000000

// SMC configuration information
#define smcc_MEMC_IF_CONFIG_OFFSET 0x00000004

// Enable interrupts and lower power state
#define smcc_MEMC_SET_CONFIG_OFFSET 0x00000008

// Disable interrupts and exit from low-power state
#define smcc_MEMC_CLR_CONFIG_OFFSET 0x0000000c

// Issue mem commands and register updates
#define smcc_DIRECT_CMD_OFFSET 0x00000010

// Stage a write to a Cycle register
#define smcc_SET_CYCLES_OFFSET 0x00000014

// Stage a write to an OpMode register
#define smcc_SET_OPMODE_OFFSET 0x00000018

// Idle cycles between read/write bursts
#define smcc_REFRESH_PERIOD_0_OFFSET 0x00000020

// Insert idle cycles between bursts
#define smcc_REFRESH_PERIOD_1_OFFSET 0x00000024

// SRAM/NOR chip select 0 timing, active
#define smcc_IF0_CHIP_0_CONFIG_OFFSET 0x00000100

// SRAM/NOR chip select 0 OpCode, active
#define smcc_OPMODE_OFFSET 0x00000104

// SRAM/NOR chip select 1 timing, active
#define smcc_IF0_CHIP_1_CONFIG_OFFSET 0x00000120

// SRAM/NOR chip select 1 OpCode, active
#define smcc_OPMODE0_1_OFFSET 0x00000124

// NAND Flash timing, active
#define smcc_IF1_CHIP_0_CONFIG_OFFSET 0x00000180

// NAND Flash OpCode, active
#define smcc_OPMODE1_0_OFFSET 0x00000184

// User Status
#define smcc_USER_STATUS_OFFSET 0x00000200

// User Configuration
#define smcc_USER_CONFIG_OFFSET 0x00000204

// ECC Status and Clear
#define smcc_IF1_ECC_OFFSET 0x00000400

// ECC Memory Configuation
#define smcc_ECC_MEMCFG_1_OFFSET 0x00000404

// ECC Memory Command 1
#define smcc_ECC_MEMCOMMAND1_1_OFFSET 0x00000408

// ECC Memory Command 2
#define smcc_ECC_MEMCOMMAND2_1_OFFSET 0x0000040c

// ECC Address 0
#define smcc_ECC_ADDR0_1_OFFSET 0x00000410

// ECC Address 1
#define smcc_ECC_ADDR1_1_OFFSET 0x00000414

// ECC Value 0
#define smcc_ECC_VALUE0_1_OFFSET 0x00000418

// ECC Value 1
#define smcc_ECC_VALUE1_1_OFFSET 0x0000041c

// ECC Value 2
#define smcc_ECC_VALUE2_1_OFFSET 0x00000420

// ECC Value 3
#define smcc_ECC_VALUE3_1_OFFSET 0x00000424
