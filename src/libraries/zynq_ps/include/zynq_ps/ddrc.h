#pragma once
// Copyright Deano Calver
// SPDX-License-Identifier: MIT
// DDR Memory Controller
// Auto-generated on Sun Sep 20 15:25:57 EEST 2020

#include <stdint.h>

// 1 banks of ddrc chips
#define ddrc_BASE_ADDR 0xf8006000

// DDRC Control
#define ddrc_CTRL_OFFSET 0x00000000

// Two Rank Configuration
#define ddrc_TWO_RANK_CFG_OFFSET 0x00000004

// HPR Queue control
#define ddrc_HPR_OFFSET 0x00000008

// LPR Queue control
#define ddrc_LPR_OFFSET 0x0000000c

// WR Queue control
#define ddrc_WR_OFFSET 0x00000010

// DRAM Parameters 0
#define ddrc_DRAM_PARAM0_OFFSET 0x00000014

// DRAM Parameters 1
#define ddrc_DRAM_PARAM1_OFFSET 0x00000018

// DRAM Parameters 2
#define ddrc_DRAM_PARAM2_OFFSET 0x0000001c

// DRAM Parameters 3
#define ddrc_DRAM_PARAM3_OFFSET 0x00000020

// DRAM Parameters 4
#define ddrc_DRAM_PARAM4_OFFSET 0x00000024

// DRAM Initialization Parameters
#define ddrc_DRAM_INIT_PARAM_OFFSET 0x00000028

// DRAM EMR2, EMR3 access
#define ddrc_DRAM_EMR_OFFSET 0x0000002c

// DRAM EMR, MR access
#define ddrc_DRAM_EMR_MR_OFFSET 0x00000030

// DRAM Burst 8 read/write
#define ddrc_DRAM_BURST8_RDWR_OFFSET 0x00000034

// DRAM Disable DQ
#define ddrc_DRAM_DISABLE_DQ_OFFSET 0x00000038

// Row/Column address bits
#define ddrc_DRAM_ADDR_MAP_BANK_OFFSET 0x0000003c

// Column address bits
#define ddrc_DRAM_ADDR_MAP_COL_OFFSET 0x00000040

// Select DRAM row address bits
#define ddrc_DRAM_ADDR_MAP_ROW_OFFSET 0x00000044

// DRAM ODT control
#define ddrc_DRAM_ODT_OFFSET 0x00000048

// PHY debug
#define ddrc_PHY_DBG_OFFSET 0x0000004c

// PHY command time out and
#define ddrc_PHY_CMD_TIMEOUT_RDDATA_CPT_OFFSET 0x00000050

// Controller operation mode status
#define ddrc_READ_DATA_CAPTURE_FIFOMODE_STS_OFFSET 0x00000054

// DLL calibration
#define ddrc_DLL_CALIB_OFFSET 0x00000058

// ODT delay and ODT hold
#define ddrc_ODT_DELAY_HOLD_OFFSET 0x0000005c

// Controller 1
#define ddrc_CTRL1_OFFSET 0x00000060

// Controller 2
#define ddrc_CTRL2_OFFSET 0x00000064

// Controller 3
#define ddrc_CTRL3_OFFSET 0x00000068

// Controller 4
#define ddrc_CTRL4_OFFSET 0x0000006c

// Controller register 5
#define ddrc_CTRL5_OFFSET 0x00000078

// Controller register 6
#define ddrc_CTRL6_OFFSET 0x0000007c

// CHE_REFRESH_TIMER01
#define ddrc_CHE_REFRESH_TIMER01_OFFSET 0x000000a0

// ZQ parameters
#define ddrc_CHE_T_ZQ_OFFSET 0x000000a4

// Misc parameters
#define ddrc_CHE_T_ZQ_Short_Interval_Reg_OFFSET 0x000000a8

// Deep powerdown (LPDDR2)
#define ddrc_DEEP_PWRDWN_OFFSET 0x000000ac

// Training control
#define ddrc_REG_2C_OFFSET 0x000000b0

// Misc Debug
#define ddrc_REG_2D_OFFSET 0x000000b4

// DFI timing
#define ddrc_DFI_TIMING_OFFSET 0x000000b8

// ECC error clear
#define ddrc_CHE_ECC_CONTROL_OFFSET 0x000000c4

// ECC error correction
#define ddrc_CHE_CORR_ECC_LOG_OFFSET 0x000000c8

// ECC error correction address log
#define ddrc_CHE_CORR_ECC_ADDR_OFFSET 0x000000cc

// ECC error correction data log low
#define ddrc_CHE_CORR_ECC_DATA_31_0_OFFSET 0x000000d0

// ECC error correction data log mid
#define ddrc_CHE_CORR_ECC_DATA_63_32_OFFSET 0x000000d4

// ECC error correction data log high
#define ddrc_CHE_CORR_ECC_DATA_71_64_OFFSET 0x000000d8

// ECC unrecoverable error status
#define ddrc_CHE_UNCORR_ECC_LOG_OFFSET 0x000000dc

// ECC unrecoverable error address
#define ddrc_CHE_UNCORR_ECC_ADDR_OFFSET 0x000000e0

// ECC unrecoverable error data low
#define ddrc_CHE_UNCORR_ECC_DATA_31_0_OFFSET 0x000000e4

// ECC unrecoverable error data middle
#define ddrc_CHE_UNCORR_ECC_DATA_63_32_OFFSET 0x000000e8

// ECC unrecoverable error data high
#define ddrc_CHE_UNCORR_ECC_DATA_71_64_OFFSET 0x000000ec

// ECC error count
#define ddrc_CHE_ECC_STATS_OFFSET 0x000000f0

// ECC mode/scrub
#define ddrc_ECC_SCRUB_OFFSET 0x000000f4

// ECC data mask low
#define ddrc_CHE_ECC_CORR_BIT_MASK_31_0_REG_OFFSET 0x000000f8

// ECC data mask high
#define ddrc_CHE_ECC_CORR_BIT_MASK_63_32_REG_OFFSET 0x000000fc

// Phy receiver enable register
#define ddrc_PHY_RCVR_ENABLE_OFFSET 0x00000114

// PHY configuration register for data slice 0.
#define ddrc_PHY_CONFIG0_OFFSET 0x00000118

// PHY configuration register for data slice 1.
#define ddrc_PHY_CONFIG1_OFFSET 0x0000011c

// PHY configuration register for data slice 2.
#define ddrc_PHY_CONFIG2_OFFSET 0x00000120

// PHY configuration register for data slice 3.
#define ddrc_PHY_CONFIG3_OFFSET 0x00000124

// PHY init ratio register for data slice 0.
#define ddrc_PHY_INIT_RATIO0_OFFSET 0x0000012c

// PHY init ratio register for data slice 1.
#define ddrc_PHY_INIT_RATIO1_OFFSET 0x00000130

// PHY init ratio register for data slice 2.
#define ddrc_PHY_INIT_RATIO2_OFFSET 0x00000134

// PHY init ratio register for data slice 3.
#define ddrc_PHY_INIT_RATIO3_OFFSET 0x00000138

// PHY read DQS configuration register for data slice 0.
#define ddrc_PHY_RD_DQS_CFG0_OFFSET 0x00000140

// PHY read DQS configuration register for data slice 1.
#define ddrc_PHY_RD_DQS_CFG1_OFFSET 0x00000144

// PHY read DQS configuration register for data slice 2.
#define ddrc_PHY_RD_DQS_CFG2_OFFSET 0x00000148

// PHY read DQS configuration register for data slice 3.
#define ddrc_PHY_RD_DQS_CFG3_OFFSET 0x0000014c

// PHY write DQS configuration register for data slice 0.
#define ddrc_PHY_WR_DQS_CFG0_OFFSET 0x00000154

// PHY write DQS configuration register for data slice 1.
#define ddrc_PHY_WR_DQS_CFG1_OFFSET 0x00000158

// PHY write DQS configuration register for data slice 2.
#define ddrc_PHY_WR_DQS_CFG2_OFFSET 0x0000015c

// PHY write DQS configuration register for data slice 3.
#define ddrc_PHY_WR_DQS_CFG3_OFFSET 0x00000160

// PHY FIFO write enable configuration for data slice 0.
#define ddrc_PHY_WE_CFG0_OFFSET 0x00000168

// PHY FIFO write enable configuration for data slice 1.
#define ddrc_PHY_WE_CFG1_OFFSET 0x0000016c

// PHY FIFO write enable configuration for data slice 2.
#define ddrc_PHY_WE_CFG2_OFFSET 0x00000170

// PHY FIFO write enable configuration for data slice 3.
#define ddrc_PHY_WE_CFG3_OFFSET 0x00000174

// PHY write data slave ratio config for data slice 0.
#define ddrc_WR_DATA_SLV0_OFFSET 0x0000017c

// PHY write data slave ratio config for data slice 1.
#define ddrc_WR_DATA_SLV1_OFFSET 0x00000180

// PHY write data slave ratio config for data slice 2.
#define ddrc_WR_DATA_SLV2_OFFSET 0x00000184

// PHY write data slave ratio config for data slice 3.
#define ddrc_WR_DATA_SLV3_OFFSET 0x00000188

// Training control 2
#define ddrc_REG_64_OFFSET 0x00000190

// Training control 3
#define ddrc_REG_65_OFFSET 0x00000194

// Training results for data slice 0.
#define ddrc_REG69_6A0_OFFSET 0x000001a4

// Training results for data slice 1.
#define ddrc_REG69_6A1_OFFSET 0x000001a8

// Training results for data slice 2.
#define ddrc_REG6C_6D2_OFFSET 0x000001b0

// Training results for data slice 3.
#define ddrc_REG6C_6D3_OFFSET 0x000001b4

// Training results (2) for data slice 0.
#define ddrc_REG6E_710_OFFSET 0x000001b8

// Training results (2) for data slice 1.
#define ddrc_REG6E_711_OFFSET 0x000001bc

// Training results (2) for data slice 2.
#define ddrc_REG6E_712_OFFSET 0x000001c0

// Training results (2) for data slice 3.
#define ddrc_REG6E_713_OFFSET 0x000001c4

// Slave DLL results for data slice 0.
#define ddrc_PHY_DLL_STS0_OFFSET 0x000001cc

// Slave DLL results for data slice 1.
#define ddrc_PHY_DLL_STS1_OFFSET 0x000001d0

// Slave DLL results for data slice 2.
#define ddrc_PHY_DLL_STS2_OFFSET 0x000001d4

// Slave DLL results for data slice 3.
#define ddrc_PHY_DLL_STS3_OFFSET 0x000001d8

// DLL Lock Status, read
#define ddrc_DLL_LOCK_STS_OFFSET 0x000001e0

// PHY Control status, read
#define ddrc_PHY_CTRL_STS_OFFSET 0x000001e4

// PHY Control status (2), read
#define ddrc_PHY_CTRL_STS_REG2_OFFSET 0x000001e8

// ID and revision information
#define ddrc_AXI_ID_OFFSET 0x00000200

// Page mask
#define ddrc_PAGE_MASK_OFFSET 0x00000204

// AXI Priority control for write port 0.
#define ddrc_AXI_PRIORITY_WR_PORT0_OFFSET 0x00000208

// AXI Priority control for write port 1.
#define ddrc_AXI_PRIORITY_WR_PORT1_OFFSET 0x0000020c

// AXI Priority control for write port 2.
#define ddrc_AXI_PRIORITY_WR_PORT2_OFFSET 0x00000210

// AXI Priority control for write port 3.
#define ddrc_AXI_PRIORITY_WR_PORT3_OFFSET 0x00000214

// AXI Priority control for read port 0.
#define ddrc_AXI_PRIORITY_RD_PORT0_OFFSET 0x00000218

// AXI Priority control for read port 1.
#define ddrc_AXI_PRIORITY_RD_PORT1_OFFSET 0x0000021c

// AXI Priority control for read port 2.
#define ddrc_AXI_PRIORITY_RD_PORT2_OFFSET 0x00000220

// AXI Priority control for read port 3.
#define ddrc_AXI_PRIORITY_RD_PORT3_OFFSET 0x00000224

// Exclusive access configuration for port 0.
#define ddrc_EXCL_ACCESS_CFG0_OFFSET 0x00000294

// Exclusive access configuration for port 1.
#define ddrc_EXCL_ACCESS_CFG1_OFFSET 0x00000298

// Exclusive access configuration for port 2.
#define ddrc_EXCL_ACCESS_CFG2_OFFSET 0x0000029c

// Exclusive access configuration for port 3.
#define ddrc_EXCL_ACCESS_CFG3_OFFSET 0x000002a0

// Mode register read data
#define ddrc_MODE_REG_READ_OFFSET 0x000002a4

// LPDDR2 Control 0
#define ddrc_LPDDR_CTRL0_OFFSET 0x000002a8

// LPDDR2 Control 1
#define ddrc_LPDDR_CTRL1_OFFSET 0x000002ac

// LPDDR2 Control 2
#define ddrc_LPDDR_CTRL2_OFFSET 0x000002b0

// LPDDR2 Control 3
#define ddrc_LPDDR_CTRL3_OFFSET 0x000002b4
