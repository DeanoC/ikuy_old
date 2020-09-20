#pragma once
// Copyright Deano Calver
// SPDX-License-Identifier: MIT
// DDR Memory Controller
// Auto-generated on Sun Sep 20 23:32:01 EEST 2020

#include <stdint.h>

// 1 banks of ddrc chips
#define ddrc_BASE_ADDR 0xf8006000U

// DDRC Control
#define ddrc_CTRL_OFFSET 0x00000000U

// Two Rank Configuration
#define ddrc_TWO_RANK_CFG_OFFSET 0x00000004U

// HPR Queue control
#define ddrc_HPR_OFFSET 0x00000008U

// LPR Queue control
#define ddrc_LPR_OFFSET 0x0000000cU

// WR Queue control
#define ddrc_WR_OFFSET 0x00000010U

// DRAM Parameters 0
#define ddrc_DRAM_PARAM0_OFFSET 0x00000014U

// DRAM Parameters 1
#define ddrc_DRAM_PARAM1_OFFSET 0x00000018U

// DRAM Parameters 2
#define ddrc_DRAM_PARAM2_OFFSET 0x0000001cU

// DRAM Parameters 3
#define ddrc_DRAM_PARAM3_OFFSET 0x00000020U

// DRAM Parameters 4
#define ddrc_DRAM_PARAM4_OFFSET 0x00000024U

// DRAM Initialization Parameters
#define ddrc_DRAM_INIT_PARAM_OFFSET 0x00000028U

// DRAM EMR2, EMR3 access
#define ddrc_DRAM_EMR_OFFSET 0x0000002cU

// DRAM EMR, MR access
#define ddrc_DRAM_EMR_MR_OFFSET 0x00000030U

// DRAM Burst 8 read/write
#define ddrc_DRAM_BURST8_RDWR_OFFSET 0x00000034U

// DRAM Disable DQ
#define ddrc_DRAM_DISABLE_DQ_OFFSET 0x00000038U

// Row/Column address bits
#define ddrc_DRAM_ADDR_MAP_BANK_OFFSET 0x0000003cU

// Column address bits
#define ddrc_DRAM_ADDR_MAP_COL_OFFSET 0x00000040U

// Select DRAM row address bits
#define ddrc_DRAM_ADDR_MAP_ROW_OFFSET 0x00000044U

// DRAM ODT control
#define ddrc_DRAM_ODT_OFFSET 0x00000048U

// PHY debug
#define ddrc_PHY_DBG_OFFSET 0x0000004cU

// PHY command time out and
#define ddrc_PHY_CMD_TIMEOUT_RDDATA_CPT_OFFSET 0x00000050U

// Controller operation mode status
#define ddrc_READ_DATA_CAPTURE_FIFOMODE_STS_OFFSET 0x00000054U

// DLL calibration
#define ddrc_DLL_CALIB_OFFSET 0x00000058U

// ODT delay and ODT hold
#define ddrc_ODT_DELAY_HOLD_OFFSET 0x0000005cU

// Controller 1
#define ddrc_CTRL1_OFFSET 0x00000060U

// Controller 2
#define ddrc_CTRL2_OFFSET 0x00000064U

// Controller 3
#define ddrc_CTRL3_OFFSET 0x00000068U

// Controller 4
#define ddrc_CTRL4_OFFSET 0x0000006cU

// Controller register 5
#define ddrc_CTRL5_OFFSET 0x00000078U

// Controller register 6
#define ddrc_CTRL6_OFFSET 0x0000007cU

// CHE_REFRESH_TIMER01
#define ddrc_CHE_REFRESH_TIMER01_OFFSET 0x000000a0U

// ZQ parameters
#define ddrc_CHE_T_ZQ_OFFSET 0x000000a4U

// Misc parameters
#define ddrc_CHE_T_ZQ_Short_Interval_Reg_OFFSET 0x000000a8U

// Deep powerdown (LPDDR2)
#define ddrc_DEEP_PWRDWN_OFFSET 0x000000acU

// Training control
#define ddrc_REG_2C_OFFSET 0x000000b0U

// Misc Debug
#define ddrc_REG_2D_OFFSET 0x000000b4U

// DFI timing
#define ddrc_DFI_TIMING_OFFSET 0x000000b8U

// ECC error clear
#define ddrc_CHE_ECC_CONTROL_OFFSET 0x000000c4U

// ECC error correction
#define ddrc_CHE_CORR_ECC_LOG_OFFSET 0x000000c8U

// ECC error correction address log
#define ddrc_CHE_CORR_ECC_ADDR_OFFSET 0x000000ccU

// ECC error correction data log low
#define ddrc_CHE_CORR_ECC_DATA_31_0_OFFSET 0x000000d0U

// ECC error correction data log mid
#define ddrc_CHE_CORR_ECC_DATA_63_32_OFFSET 0x000000d4U

// ECC error correction data log high
#define ddrc_CHE_CORR_ECC_DATA_71_64_OFFSET 0x000000d8U

// ECC unrecoverable error status
#define ddrc_CHE_UNCORR_ECC_LOG_OFFSET 0x000000dcU

// ECC unrecoverable error address
#define ddrc_CHE_UNCORR_ECC_ADDR_OFFSET 0x000000e0U

// ECC unrecoverable error data low
#define ddrc_CHE_UNCORR_ECC_DATA_31_0_OFFSET 0x000000e4U

// ECC unrecoverable error data middle
#define ddrc_CHE_UNCORR_ECC_DATA_63_32_OFFSET 0x000000e8U

// ECC unrecoverable error data high
#define ddrc_CHE_UNCORR_ECC_DATA_71_64_OFFSET 0x000000ecU

// ECC error count
#define ddrc_CHE_ECC_STATS_OFFSET 0x000000f0U

// ECC mode/scrub
#define ddrc_ECC_SCRUB_OFFSET 0x000000f4U

// ECC data mask low
#define ddrc_CHE_ECC_CORR_BIT_MASK_31_0_REG_OFFSET 0x000000f8U

// ECC data mask high
#define ddrc_CHE_ECC_CORR_BIT_MASK_63_32_REG_OFFSET 0x000000fcU

// Phy receiver enable register
#define ddrc_PHY_RCVR_ENABLE_OFFSET 0x00000114U

// PHY configuration register for data slice 0.
#define ddrc_PHY_CONFIG0_OFFSET 0x00000118U

// PHY configuration register for data slice 1.
#define ddrc_PHY_CONFIG1_OFFSET 0x0000011cU

// PHY configuration register for data slice 2.
#define ddrc_PHY_CONFIG2_OFFSET 0x00000120U

// PHY configuration register for data slice 3.
#define ddrc_PHY_CONFIG3_OFFSET 0x00000124U

// PHY init ratio register for data slice 0.
#define ddrc_PHY_INIT_RATIO0_OFFSET 0x0000012cU

// PHY init ratio register for data slice 1.
#define ddrc_PHY_INIT_RATIO1_OFFSET 0x00000130U

// PHY init ratio register for data slice 2.
#define ddrc_PHY_INIT_RATIO2_OFFSET 0x00000134U

// PHY init ratio register for data slice 3.
#define ddrc_PHY_INIT_RATIO3_OFFSET 0x00000138U

// PHY read DQS configuration register for data slice 0.
#define ddrc_PHY_RD_DQS_CFG0_OFFSET 0x00000140U

// PHY read DQS configuration register for data slice 1.
#define ddrc_PHY_RD_DQS_CFG1_OFFSET 0x00000144U

// PHY read DQS configuration register for data slice 2.
#define ddrc_PHY_RD_DQS_CFG2_OFFSET 0x00000148U

// PHY read DQS configuration register for data slice 3.
#define ddrc_PHY_RD_DQS_CFG3_OFFSET 0x0000014cU

// PHY write DQS configuration register for data slice 0.
#define ddrc_PHY_WR_DQS_CFG0_OFFSET 0x00000154U

// PHY write DQS configuration register for data slice 1.
#define ddrc_PHY_WR_DQS_CFG1_OFFSET 0x00000158U

// PHY write DQS configuration register for data slice 2.
#define ddrc_PHY_WR_DQS_CFG2_OFFSET 0x0000015cU

// PHY write DQS configuration register for data slice 3.
#define ddrc_PHY_WR_DQS_CFG3_OFFSET 0x00000160U

// PHY FIFO write enable configuration for data slice 0.
#define ddrc_PHY_WE_CFG0_OFFSET 0x00000168U

// PHY FIFO write enable configuration for data slice 1.
#define ddrc_PHY_WE_CFG1_OFFSET 0x0000016cU

// PHY FIFO write enable configuration for data slice 2.
#define ddrc_PHY_WE_CFG2_OFFSET 0x00000170U

// PHY FIFO write enable configuration for data slice 3.
#define ddrc_PHY_WE_CFG3_OFFSET 0x00000174U

// PHY write data slave ratio config for data slice 0.
#define ddrc_WR_DATA_SLV0_OFFSET 0x0000017cU

// PHY write data slave ratio config for data slice 1.
#define ddrc_WR_DATA_SLV1_OFFSET 0x00000180U

// PHY write data slave ratio config for data slice 2.
#define ddrc_WR_DATA_SLV2_OFFSET 0x00000184U

// PHY write data slave ratio config for data slice 3.
#define ddrc_WR_DATA_SLV3_OFFSET 0x00000188U

// Training control 2
#define ddrc_REG_64_OFFSET 0x00000190U

// Training control 3
#define ddrc_REG_65_OFFSET 0x00000194U

// Training results for data slice 0.
#define ddrc_REG69_6A0_OFFSET 0x000001a4U

// Training results for data slice 1.
#define ddrc_REG69_6A1_OFFSET 0x000001a8U

// Training results for data slice 2.
#define ddrc_REG6C_6D2_OFFSET 0x000001b0U

// Training results for data slice 3.
#define ddrc_REG6C_6D3_OFFSET 0x000001b4U

// Training results (2) for data slice 0.
#define ddrc_REG6E_710_OFFSET 0x000001b8U

// Training results (2) for data slice 1.
#define ddrc_REG6E_711_OFFSET 0x000001bcU

// Training results (2) for data slice 2.
#define ddrc_REG6E_712_OFFSET 0x000001c0U

// Training results (2) for data slice 3.
#define ddrc_REG6E_713_OFFSET 0x000001c4U

// Slave DLL results for data slice 0.
#define ddrc_PHY_DLL_STS0_OFFSET 0x000001ccU

// Slave DLL results for data slice 1.
#define ddrc_PHY_DLL_STS1_OFFSET 0x000001d0U

// Slave DLL results for data slice 2.
#define ddrc_PHY_DLL_STS2_OFFSET 0x000001d4U

// Slave DLL results for data slice 3.
#define ddrc_PHY_DLL_STS3_OFFSET 0x000001d8U

// DLL Lock Status, read
#define ddrc_DLL_LOCK_STS_OFFSET 0x000001e0U

// PHY Control status, read
#define ddrc_PHY_CTRL_STS_OFFSET 0x000001e4U

// PHY Control status (2), read
#define ddrc_PHY_CTRL_STS_REG2_OFFSET 0x000001e8U

// ID and revision information
#define ddrc_AXI_ID_OFFSET 0x00000200U

// Page mask
#define ddrc_PAGE_MASK_OFFSET 0x00000204U

// AXI Priority control for write port 0.
#define ddrc_AXI_PRIORITY_WR_PORT0_OFFSET 0x00000208U

// AXI Priority control for write port 1.
#define ddrc_AXI_PRIORITY_WR_PORT1_OFFSET 0x0000020cU

// AXI Priority control for write port 2.
#define ddrc_AXI_PRIORITY_WR_PORT2_OFFSET 0x00000210U

// AXI Priority control for write port 3.
#define ddrc_AXI_PRIORITY_WR_PORT3_OFFSET 0x00000214U

// AXI Priority control for read port 0.
#define ddrc_AXI_PRIORITY_RD_PORT0_OFFSET 0x00000218U

// AXI Priority control for read port 1.
#define ddrc_AXI_PRIORITY_RD_PORT1_OFFSET 0x0000021cU

// AXI Priority control for read port 2.
#define ddrc_AXI_PRIORITY_RD_PORT2_OFFSET 0x00000220U

// AXI Priority control for read port 3.
#define ddrc_AXI_PRIORITY_RD_PORT3_OFFSET 0x00000224U

// Exclusive access configuration for port 0.
#define ddrc_EXCL_ACCESS_CFG0_OFFSET 0x00000294U

// Exclusive access configuration for port 1.
#define ddrc_EXCL_ACCESS_CFG1_OFFSET 0x00000298U

// Exclusive access configuration for port 2.
#define ddrc_EXCL_ACCESS_CFG2_OFFSET 0x0000029cU

// Exclusive access configuration for port 3.
#define ddrc_EXCL_ACCESS_CFG3_OFFSET 0x000002a0U

// Mode register read data
#define ddrc_MODE_REG_READ_OFFSET 0x000002a4U

// LPDDR2 Control 0
#define ddrc_LPDDR_CTRL0_OFFSET 0x000002a8U

// LPDDR2 Control 1
#define ddrc_LPDDR_CTRL1_OFFSET 0x000002acU

// LPDDR2 Control 2
#define ddrc_LPDDR_CTRL2_OFFSET 0x000002b0U

// LPDDR2 Control 3
#define ddrc_LPDDR_CTRL3_OFFSET 0x000002b4U
