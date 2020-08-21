#pragma once
// Copyright Deano Calver
// SPDX-License-Identifier: MIT

#include <stdint.h>

// DDR Memory Controller

// 1 bank of ddrc

#define ddrc_BASE_ADDR 0xf8006000U

// Registers

// DDRC Control
#define ddrc_ddrc_ctrl_REG 0x0U


// Two Rank Configuration
#define ddrc_Two_rank_cfg_REG 0x4U


// HPR Queue control
#define ddrc_HPR_reg_REG 0x8U


// LPR Queue control
#define ddrc_LPR_reg_REG 0xcU


// WR Queue control
#define ddrc_WR_reg_REG 0x10U


// DRAM Parameters 0
#define ddrc_DRAM_param_reg0_REG 0x14U


// DRAM Parameters 1
#define ddrc_DRAM_param_reg1_REG 0x18U


// DRAM Parameters 2
#define ddrc_DRAM_param_reg2_REG 0x1cU


// DRAM Parameters 3
#define ddrc_DRAM_param_reg3_REG 0x20U


// DRAM Parameters 4
#define ddrc_DRAM_param_reg4_REG 0x24U


// DRAM Initialization Parameters
#define ddrc_DRAM_init_param_REG 0x28U


// DRAM EMR2, EMR3 access
#define ddrc_DRAM_EMR_reg_REG 0x2cU


// DRAM EMR, MR access
#define ddrc_DRAM_EMR_MR_reg_REG 0x30U


// DRAM Burst 8 read/write
#define ddrc_DRAM_burst8_rdwr_REG 0x34U


// DRAM Disable DQ
#define ddrc_DRAM_disable_DQ_REG 0x38U


// Row/Column address bits
#define ddrc_DRAM_addr_map_bank_REG 0x3cU


// Column address bits
#define ddrc_DRAM_addr_map_col_REG 0x40U


// Select DRAM row address bits
#define ddrc_DRAM_addr_map_row_REG 0x44U


// DRAM ODT control
#define ddrc_DRAM_ODT_reg_REG 0x48U


// PHY debug
#define ddrc_phy_dbg_reg_REG 0x4cU


// PHY command time out and
#define ddrc_phy_cmd_timeout_rddata_cpt_REG 0x50U


// Controller operation mode status
#define ddrc_read_data_capture_FIFOmode_sts_REG 0x54U


// DLL calibration
#define ddrc_DLL_calib_REG 0x58U


// ODT delay and ODT hold
#define ddrc_ODT_delay_hold_REG 0x5cU


// Controller 1
#define ddrc_ctrl_reg1_REG 0x60U


// Controller 2
#define ddrc_ctrl_reg2_REG 0x64U


// Controller 3
#define ddrc_ctrl_reg3_REG 0x68U


// Controller 4
#define ddrc_ctrl_reg4_REG 0x6cU


// Controller register 5
#define ddrc_ctrl_reg5_REG 0x78U


// Controller register 6
#define ddrc_ctrl_reg6_REG 0x7cU


// CHE_REFRESH_TIMER01
#define ddrc_CHE_REFRESH_TIMER01_REG 0xa0U


// ZQ parameters
#define ddrc_CHE_T_ZQ_REG 0xa4U


// Misc parameters
#define ddrc_CHE_T_ZQ_Short_Interval_Reg_REG 0xa8U


// Deep powerdown (LPDDR2)
#define ddrc_deep_pwrdwn_reg_REG 0xacU


// Training control
#define ddrc_reg_2c_REG 0xb0U


// Misc Debug
#define ddrc_reg_2d_REG 0xb4U


// DFI timing
#define ddrc_dfi_timing_REG 0xb8U


// ECC error clear
#define ddrc_CHE_ECC_CONTROL_REG_OFFSET_REG 0xc4U


// ECC error correction
#define ddrc_CHE_CORR_ECC_LOG_REG_OFFSET_REG 0xc8U


// ECC error correction address log
#define ddrc_CHE_CORR_ECC_ADDR_REG_OFFSET_REG 0xccU


// ECC error correction data log low
#define ddrc_CHE_CORR_ECC_DATA_31_0_REG_OFFSET_REG 0xd0U


// ECC error correction data log mid
#define ddrc_CHE_CORR_ECC_DATA_63_32_REG_OFFSET_REG 0xd4U


// ECC error correction data log high
#define ddrc_CHE_CORR_ECC_DATA_71_64_REG_OFFSET_REG 0xd8U


// ECC unrecoverable error status
#define ddrc_CHE_UNCORR_ECC_LOG_REG_OFFSET_REG 0xdcU


// ECC unrecoverable error address
#define ddrc_CHE_UNCORR_ECC_ADDR_REG_OFFSET_REG 0xe0U


// ECC unrecoverable error data low
#define ddrc_CHE_UNCORR_ECC_DATA_31_0_REG_OFFSET_REG 0xe4U


// ECC unrecoverable error data middle
#define ddrc_CHE_UNCORR_ECC_DATA_63_32_REG_OFFSET_REG 0xe8U


// ECC unrecoverable error data high
#define ddrc_CHE_UNCORR_ECC_DATA_71_64_REG_OFFSET_REG 0xecU


// ECC error count
#define ddrc_CHE_ECC_STATS_REG_OFFSET_REG 0xf0U


// ECC mode/scrub
#define ddrc_ECC_scrub_REG 0xf4U


// ECC data mask low
#define ddrc_CHE_ECC_CORR_BIT_MASK_31_0_REG_OFFSET_REG 0xf8U


// ECC data mask high
#define ddrc_CHE_ECC_CORR_BIT_MASK_63_32_REG_OFFSET_REG 0xfcU


// Phy receiver enable register
#define ddrc_phy_rcvr_enable_REG 0x114U


// PHY configuration register for data slice 0.
#define ddrc_PHY_Config0_REG 0x118U


// PHY configuration register for data slice 1.
#define ddrc_PHY_Config1_REG 0x11cU


// PHY configuration register for data slice 2.
#define ddrc_PHY_Config2_REG 0x120U


// PHY configuration register for data slice 3.
#define ddrc_PHY_Config3_REG 0x124U


// PHY init ratio register for data slice 0.
#define ddrc_phy_init_ratio0_REG 0x12cU


// PHY init ratio register for data slice 1.
#define ddrc_phy_init_ratio1_REG 0x130U


// PHY init ratio register for data slice 2.
#define ddrc_phy_init_ratio2_REG 0x134U


// PHY init ratio register for data slice 3.
#define ddrc_phy_init_ratio3_REG 0x138U


// PHY read DQS configuration register for data slice 0.
#define ddrc_phy_rd_dqs_cfg0_REG 0x140U


// PHY read DQS configuration register for data slice 1.
#define ddrc_phy_rd_dqs_cfg1_REG 0x144U


// PHY read DQS configuration register for data slice 2.
#define ddrc_phy_rd_dqs_cfg2_REG 0x148U


// PHY read DQS configuration register for data slice 3.
#define ddrc_phy_rd_dqs_cfg3_REG 0x14cU


// PHY write DQS configuration register for data slice 0.
#define ddrc_phy_wr_dqs_cfg0_REG 0x154U


// PHY write DQS configuration register for data slice 1.
#define ddrc_phy_wr_dqs_cfg1_REG 0x158U


// PHY write DQS configuration register for data slice 2.
#define ddrc_phy_wr_dqs_cfg2_REG 0x15cU


// PHY write DQS configuration register for data slice 3.
#define ddrc_phy_wr_dqs_cfg3_REG 0x160U


// PHY FIFO write enable configuration for data slice 0.
#define ddrc_phy_we_cfg0_REG 0x168U


// PHY FIFO write enable configuration for data slice 1.
#define ddrc_phy_we_cfg1_REG 0x16cU


// PHY FIFO write enable configuration for data slice 2.
#define ddrc_phy_we_cfg2_REG 0x170U


// PHY FIFO write enable configuration for data slice 3.
#define ddrc_phy_we_cfg3_REG 0x174U


// PHY write data slave ratio config for data slice 0.
#define ddrc_wr_data_slv0_REG 0x17cU


// PHY write data slave ratio config for data slice 1.
#define ddrc_wr_data_slv1_REG 0x180U


// PHY write data slave ratio config for data slice 2.
#define ddrc_wr_data_slv2_REG 0x184U


// PHY write data slave ratio config for data slice 3.
#define ddrc_wr_data_slv3_REG 0x188U


// Training control 2
#define ddrc_reg_64_REG 0x190U


// Training control 3
#define ddrc_reg_65_REG 0x194U


// Training results for data slice 0.
#define ddrc_reg69_6a0_REG 0x1a4U


// Training results for data slice 1.
#define ddrc_reg69_6a1_REG 0x1a8U


// Training results for data slice 2.
#define ddrc_reg6c_6d2_REG 0x1b0U


// Training results for data slice 3.
#define ddrc_reg6c_6d3_REG 0x1b4U


// 3.
#define ddrc_reg6e_710_REG 0x1b8U


// 3.
#define ddrc_reg6e_711_REG 0x1bcU


// 3.
#define ddrc_reg6e_712_REG 0x1c0U


// 3.
#define ddrc_reg6e_713_REG 0x1c4U


// Slave DLL results for data slice 0.
#define ddrc_phy_dll_sts0_REG 0x1ccU


// Slave DLL results for data slice 1.
#define ddrc_phy_dll_sts1_REG 0x1d0U


// Slave DLL results for data slice 2.
#define ddrc_phy_dll_sts2_REG 0x1d4U


// Slave DLL results for data slice 3.
#define ddrc_phy_dll_sts3_REG 0x1d8U


// DLL Lock Status, read
#define ddrc_dll_lock_sts_REG 0x1e0U


// slice 3.
#define ddrc_phy_ctrl_sts_REG 0x1e4U


// PHY Control status (2), read
#define ddrc_phy_ctrl_sts_reg2_REG 0x1e8U


// ID and revision information
#define ddrc_axi_id_REG 0x200U


// Page mask
#define ddrc_page_mask_REG 0x204U


// AXI Priority control for write port 0.
#define ddrc_axi_priority_wr_port0_REG 0x208U


// AXI Priority control for write port 1.
#define ddrc_axi_priority_wr_port1_REG 0x20cU


// AXI Priority control for write port 2.
#define ddrc_axi_priority_wr_port2_REG 0x210U


// AXI Priority control for write port 3.
#define ddrc_axi_priority_wr_port3_REG 0x214U


// AXI Priority control for read port 0.
#define ddrc_axi_priority_rd_port0_REG 0x218U


// AXI Priority control for read port 1.
#define ddrc_axi_priority_rd_port1_REG 0x21cU


// AXI Priority control for read port 2.
#define ddrc_axi_priority_rd_port2_REG 0x220U


// AXI Priority control for read port 3.
#define ddrc_axi_priority_rd_port3_REG 0x224U


// Exclusive access configuration for port 0.
#define ddrc_excl_access_cfg0_REG 0x294U


// Exclusive access configuration for port 1.
#define ddrc_excl_access_cfg1_REG 0x298U


// Exclusive access configuration for port 2.
#define ddrc_excl_access_cfg2_REG 0x29cU


// Exclusive access configuration for port 3.
#define ddrc_excl_access_cfg3_REG 0x2a0U


// Mode register read data
#define ddrc_mode_reg_read_REG 0x2a4U


// LPDDR2 Control 0
#define ddrc_lpddr_ctrl0_REG 0x2a8U


// LPDDR2 Control 1
#define ddrc_lpddr_ctrl1_REG 0x2acU


// LPDDR2 Control 2
#define ddrc_lpddr_ctrl2_REG 0x2b0U


// LPDDR2 Control 3
#define ddrc_lpddr_ctrl3_REG 0x2b4U


