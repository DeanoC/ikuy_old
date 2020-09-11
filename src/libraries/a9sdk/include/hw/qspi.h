#pragma once
// Copyright Deano Calver
// SPDX-License-Identifier: MIT

#include <stdint.h>

// Quad SPI

// 1 bank of qspi

#define qspi_BASE_ADDR 0xe000d000U

// Registers

// QSPI configuration register
#define qspi_CR_REG 0x0U
#define qspi_CR_IFMODE_LSHIFT 31U
#define qspi_CR_IFMODE 0x80000000U
#define qspi_CR_IFMODE_MASK 0x80000000U
#define qspi_CR_RESERVED_0_LSHIFT 27U
#define qspi_CR_RESERVED_0_MASK 0x78000000U
#define qspi_CR_ENDIAN_LSHIFT 26U
#define qspi_CR_ENDIAN 0x4000000U
#define qspi_CR_ENDIAN_MASK 0x4000000U
#define qspi_CR_RESERVED_1_LSHIFT 20U
#define qspi_CR_RESERVED_1_MASK 0x3f00000U
#define qspi_CR_HOLDDB_DR_LSHIFT 19U
#define qspi_CR_HOLDDB_DR 0x80000U
#define qspi_CR_HOLDDB_DR_MASK 0x80000U
#define qspi_CR_RESERVED_2_LSHIFT 18U
#define qspi_CR_RESERVED_2 0x40000U
#define qspi_CR_RESERVED_2_MASK 0x40000U
#define qspi_CR_RESERVED_3_LSHIFT 17U
#define qspi_CR_RESERVED_3 0x20000U
#define qspi_CR_RESERVED_3_MASK 0x20000U
#define qspi_CR_MANSTRT_LSHIFT 16U
#define qspi_CR_MANSTRT 0x10000U
#define qspi_CR_MANSTRT_MASK 0x10000U
#define qspi_CR_MANSTRTEN_LSHIFT 15U
#define qspi_CR_MANSTRTEN 0x8000U
#define qspi_CR_MANSTRTEN_MASK 0x8000U
#define qspi_CR_SSFORCE_LSHIFT 14U
#define qspi_CR_SSFORCE 0x4000U
#define qspi_CR_SSFORCE_MASK 0x4000U
#define qspi_CR_RESERVED_4_LSHIFT 11U
#define qspi_CR_RESERVED_4_MASK 0x3800U
#define qspi_CR_PCS_LSHIFT 10U
#define qspi_CR_PCS 0x400U
#define qspi_CR_PCS_MASK 0x400U
#define qspi_CR_RESERVED_5_LSHIFT 9U
#define qspi_CR_RESERVED_5 0x200U
#define qspi_CR_RESERVED_5_MASK 0x200U
#define qspi_CR_REF_CLK_LSHIFT 8U
#define qspi_CR_REF_CLK 0x100U
#define qspi_CR_REF_CLK_MASK 0x100U
#define qspi_CR_FIFO_WIDTH_LSHIFT 6U
#define qspi_CR_FIFO_WIDTH_MASK 0xc0U
#define qspi_CR_BAUD_RATE_DIV_LSHIFT 3U
#define qspi_CR_BAUD_RATE_DIV_MASK 0x38U
#define qspi_CR_CPHA_LSHIFT 2U
#define qspi_CR_CPHA 0x4U
#define qspi_CR_CPHA_MASK 0x4U
#define qspi_CR_CPOL_LSHIFT 1U
#define qspi_CR_CPOL 0x2U
#define qspi_CR_CPOL_MASK 0x2U
#define qspi_CR_MSTREN_LSHIFT 0U
#define qspi_CR_MSTREN 0x1U
#define qspi_CR_MSTREN_MASK 0x1U
#define qspi_CR_MASK 0x8409c5ffU


// QSPI interrupt status register
#define qspi_SR_REG 0x4U
#define qspi_SR_RESERVED_0_LSHIFT 7U
#define qspi_SR_RESERVED_0_MASK 0xffffff80U
#define qspi_SR_IXR_TXUF_LSHIFT 6U
#define qspi_SR_IXR_TXUF 0x40U
#define qspi_SR_IXR_TXUF_MASK 0x40U
#define qspi_SR_IXR_RXFULL_LSHIFT 5U
#define qspi_SR_IXR_RXFULL 0x20U
#define qspi_SR_IXR_RXFULL_MASK 0x20U
#define qspi_SR_IXR_RXNEMPTY_LSHIFT 4U
#define qspi_SR_IXR_RXNEMPTY 0x10U
#define qspi_SR_IXR_RXNEMPTY_MASK 0x10U
#define qspi_SR_IXR_TXFULL_LSHIFT 3U
#define qspi_SR_IXR_TXFULL 0x8U
#define qspi_SR_IXR_TXFULL_MASK 0x8U
#define qspi_SR_IXR_TXOW_LSHIFT 2U
#define qspi_SR_IXR_TXOW 0x4U
#define qspi_SR_IXR_TXOW_MASK 0x4U
#define qspi_SR_RESERVED_1_LSHIFT 1U
#define qspi_SR_RESERVED_1 0x2U
#define qspi_SR_RESERVED_1_MASK 0x2U
#define qspi_SR_IXR_RXOVR_LSHIFT 0U
#define qspi_SR_IXR_RXOVR 0x1U
#define qspi_SR_IXR_RXOVR_MASK 0x1U
#define qspi_SR_MASK 0x7dU


// Interrupt Enable register.
#define qspi_IER_REG 0x8U
#define qspi_IER_RESERVED_0_LSHIFT 7U
#define qspi_IER_RESERVED_0_MASK 0xffffff80U
#define qspi_IER_IXR_TXUF_LSHIFT 6U
#define qspi_IER_IXR_TXUF 0x40U
#define qspi_IER_IXR_TXUF_MASK 0x40U
#define qspi_IER_IXR_RXFULL_LSHIFT 5U
#define qspi_IER_IXR_RXFULL 0x20U
#define qspi_IER_IXR_RXFULL_MASK 0x20U
#define qspi_IER_IXR_RXNEMPTY_LSHIFT 4U
#define qspi_IER_IXR_RXNEMPTY 0x10U
#define qspi_IER_IXR_RXNEMPTY_MASK 0x10U
#define qspi_IER_IXR_TXFULL_LSHIFT 3U
#define qspi_IER_IXR_TXFULL 0x8U
#define qspi_IER_IXR_TXFULL_MASK 0x8U
#define qspi_IER_IXR_TXOW_LSHIFT 2U
#define qspi_IER_IXR_TXOW 0x4U
#define qspi_IER_IXR_TXOW_MASK 0x4U
#define qspi_IER_RESERVED_1_LSHIFT 1U
#define qspi_IER_RESERVED_1 0x2U
#define qspi_IER_RESERVED_1_MASK 0x2U
#define qspi_IER_IXR_RXOVR_LSHIFT 0U
#define qspi_IER_IXR_RXOVR 0x1U
#define qspi_IER_IXR_RXOVR_MASK 0x1U
#define qspi_IER_MASK 0x7dU


// Interrupt disable register.
#define qspi_IDR_REG 0xcU
#define qspi_IDR_RESERVED_0_LSHIFT 7U
#define qspi_IDR_RESERVED_0_MASK 0xffffff80U
#define qspi_IDR_IXR_TXUF_LSHIFT 6U
#define qspi_IDR_IXR_TXUF 0x40U
#define qspi_IDR_IXR_TXUF_MASK 0x40U
#define qspi_IDR_IXR_RXFULL_LSHIFT 5U
#define qspi_IDR_IXR_RXFULL 0x20U
#define qspi_IDR_IXR_RXFULL_MASK 0x20U
#define qspi_IDR_IXR_RXNEMPTY_LSHIFT 4U
#define qspi_IDR_IXR_RXNEMPTY 0x10U
#define qspi_IDR_IXR_RXNEMPTY_MASK 0x10U
#define qspi_IDR_IXR_TXFULL_LSHIFT 3U
#define qspi_IDR_IXR_TXFULL 0x8U
#define qspi_IDR_IXR_TXFULL_MASK 0x8U
#define qspi_IDR_IXR_TXOW_LSHIFT 2U
#define qspi_IDR_IXR_TXOW 0x4U
#define qspi_IDR_IXR_TXOW_MASK 0x4U
#define qspi_IDR_RESERVED_1_LSHIFT 1U
#define qspi_IDR_RESERVED_1 0x2U
#define qspi_IDR_RESERVED_1_MASK 0x2U
#define qspi_IDR_IXR_RXOVR_LSHIFT 0U
#define qspi_IDR_IXR_RXOVR 0x1U
#define qspi_IDR_IXR_RXOVR_MASK 0x1U
#define qspi_IDR_MASK 0x7dU


// Interrupt mask register
#define qspi_IMR_REG 0x10U
#define qspi_IMR_RESERVED_0_LSHIFT 7U
#define qspi_IMR_RESERVED_0_MASK 0xffffff80U
#define qspi_IMR_IXR_TXUF_LSHIFT 6U
#define qspi_IMR_IXR_TXUF 0x40U
#define qspi_IMR_IXR_TXUF_MASK 0x40U
#define qspi_IMR_IXR_RXFULL_LSHIFT 5U
#define qspi_IMR_IXR_RXFULL 0x20U
#define qspi_IMR_IXR_RXFULL_MASK 0x20U
#define qspi_IMR_IXR_RXNEMPTY_LSHIFT 4U
#define qspi_IMR_IXR_RXNEMPTY 0x10U
#define qspi_IMR_IXR_RXNEMPTY_MASK 0x10U
#define qspi_IMR_IXR_TXFULL_LSHIFT 3U
#define qspi_IMR_IXR_TXFULL 0x8U
#define qspi_IMR_IXR_TXFULL_MASK 0x8U
#define qspi_IMR_IXR_TXOW_LSHIFT 2U
#define qspi_IMR_IXR_TXOW 0x4U
#define qspi_IMR_IXR_TXOW_MASK 0x4U
#define qspi_IMR_RESERVED_1_LSHIFT 1U
#define qspi_IMR_RESERVED_1 0x2U
#define qspi_IMR_RESERVED_1_MASK 0x2U
#define qspi_IMR_IXR_RXOVR_LSHIFT 0U
#define qspi_IMR_IXR_RXOVR 0x1U
#define qspi_IMR_IXR_RXOVR_MASK 0x1U
#define qspi_IMR_MASK 0x7dU


// SPI_Enable Register
#define qspi_ER_REG 0x14U
#define qspi_ER_RESERVED_0_LSHIFT 1U
#define qspi_ER_RESERVED_0_MASK 0xfffffffeU
#define qspi_ER_ENABLE_LSHIFT 0U
#define qspi_ER_ENABLE 0x1U
#define qspi_ER_ENABLE_MASK 0x1U
#define qspi_ER_MASK 0x1U


// Delay Register
#define qspi_DR_REG 0x18U
#define qspi_DR_D_NSS_LSHIFT 24U
#define qspi_DR_D_NSS_MASK 0xff000000U
#define qspi_DR_BTWN_LSHIFT 16U
#define qspi_DR_BTWN_MASK 0xff0000U
#define qspi_DR_AFTER_LSHIFT 8U
#define qspi_DR_AFTER_MASK 0xff00U
#define qspi_DR_INIT_LSHIFT 0U
#define qspi_DR_INIT_MASK 0xffU
#define qspi_DR_MASK 0xffffffffU


// Transmit Data Register. Keyhole addresses for the Transmit data FIFO.
#define qspi_TXD_00_REG 0x1cU
#define qspi_TXD_00_TXD_LSHIFT 0U
#define qspi_TXD_00_TXD_MASK 0x0U
#define qspi_TXD_00_MASK 0x0U


// Receive Data Register
#define qspi_RXD_REG 0x20U
#define qspi_RXD_RX_FIFO_LSHIFT 0U
#define qspi_RXD_RX_FIFO_MASK 0x0U
#define qspi_RXD_MASK 0x0U


// Slave Idle Count Register
#define qspi_SICR_REG 0x24U
#define qspi_SICR_RESERVED_0_LSHIFT 8U
#define qspi_SICR_RESERVED_0_MASK 0xffffff00U
#define qspi_SICR_MASK_LSHIFT 0U
#define qspi_SICR_MASK_MASK 0xffU
#define qspi_SICR_MASK 0xffU


// TX_FIFO Threshold Register
#define qspi_TXWR_REG 0x28U
#define qspi_TXWR_THRESHOLD_OF_TX_FIFO_LSHIFT 0U
#define qspi_TXWR_THRESHOLD_OF_TX_FIFO_MASK 0x0U
#define qspi_TXWR_MASK 0x0U


// RX FIFO Threshold Register 
#define qspi_RX_THRES_REG 0x2cU
#define qspi_RX_THRES_THRESHOLD_OF_RX_FIFO_LSHIFT 0U
#define qspi_RX_THRES_THRESHOLD_OF_RX_FIFO_MASK 0x0U
#define qspi_RX_THRES_MASK 0x0U


// General Purpose Inputs and Outputs Register for the Quad-SPI Controller core
#define qspi_GPIO_REG 0x30U
#define qspi_GPIO_RESERVED_0_LSHIFT 1U
#define qspi_GPIO_RESERVED_0_MASK 0xfffffffeU
#define qspi_GPIO_WP_N_LSHIFT 0U
#define qspi_GPIO_WP_N 0x1U
#define qspi_GPIO_WP_N_MASK 0x1U
#define qspi_GPIO_MASK 0x1U


// Loopback Master Clock Delay Adjustment Register
#define qspi_LPBK_DLY_ADJ_REG 0x38U
#define qspi_LPBK_DLY_ADJ_RESERVED_0_LSHIFT 6U
#define qspi_LPBK_DLY_ADJ_RESERVED_0_MASK 0xffffffc0U
#define qspi_LPBK_DLY_ADJ_USE_LPBK_LSHIFT 5U
#define qspi_LPBK_DLY_ADJ_USE_LPBK 0x20U
#define qspi_LPBK_DLY_ADJ_USE_LPBK_MASK 0x20U
#define qspi_LPBK_DLY_ADJ_RESERVED_1_LSHIFT 0U
#define qspi_LPBK_DLY_ADJ_RESERVED_1_MASK 0x1fU
#define qspi_LPBK_DLY_ADJ_MASK 0x20U


// Transmit Data Register. Keyhole addresses for the Transmit data FIFO.
#define qspi_TXD_01_REG 0x80U
#define qspi_TXD_01_TXD_LSHIFT 0U
#define qspi_TXD_01_TXD_MASK 0x0U
#define qspi_TXD_01_MASK 0x0U


// Transmit Data Register. Keyhole addresses for the Transmit data FIFO.
#define qspi_TXD_10_REG 0x84U
#define qspi_TXD_10_TXD_LSHIFT 0U
#define qspi_TXD_10_TXD_MASK 0x0U
#define qspi_TXD_10_MASK 0x0U


// Transmit Data Register. Keyhole addresses for the Transmit data FIFO.
#define qspi_TXD_11_REG 0x88U
#define qspi_TXD_11_TXD_LSHIFT 0U
#define qspi_TXD_11_TXD_MASK 0x0U
#define qspi_TXD_11_MASK 0x0U


//  Configuration Register specifically for the Linear Quad-SPI Controller
#define qspi_LQSPI_CR_REG 0xa0U
#define qspi_LQSPI_CR_LINEAR_LSHIFT 31U
#define qspi_LQSPI_CR_LINEAR 0x80000000U
#define qspi_LQSPI_CR_LINEAR_MASK 0x80000000U
#define qspi_LQSPI_CR_TWO_MEM_LSHIFT 30U
#define qspi_LQSPI_CR_TWO_MEM 0x40000000U
#define qspi_LQSPI_CR_TWO_MEM_MASK 0x40000000U
#define qspi_LQSPI_CR_SEP_BUS_LSHIFT 29U
#define qspi_LQSPI_CR_SEP_BUS 0x20000000U
#define qspi_LQSPI_CR_SEP_BUS_MASK 0x20000000U
#define qspi_LQSPI_CR_U_PAGE_LSHIFT 28U
#define qspi_LQSPI_CR_U_PAGE 0x10000000U
#define qspi_LQSPI_CR_U_PAGE_MASK 0x10000000U
#define qspi_LQSPI_CR_RESERVED_0_LSHIFT 27U
#define qspi_LQSPI_CR_RESERVED_0 0x8000000U
#define qspi_LQSPI_CR_RESERVED_0_MASK 0x8000000U
#define qspi_LQSPI_CR_RESERVED_1_LSHIFT 26U
#define qspi_LQSPI_CR_RESERVED_1 0x4000000U
#define qspi_LQSPI_CR_RESERVED_1_MASK 0x4000000U
#define qspi_LQSPI_CR_MODE_EN_LSHIFT 25U
#define qspi_LQSPI_CR_MODE_EN 0x2000000U
#define qspi_LQSPI_CR_MODE_EN_MASK 0x2000000U
#define qspi_LQSPI_CR_MODE_ON_LSHIFT 24U
#define qspi_LQSPI_CR_MODE_ON 0x1000000U
#define qspi_LQSPI_CR_MODE_ON_MASK 0x1000000U
#define qspi_LQSPI_CR_MODE_BITS_LSHIFT 16U
#define qspi_LQSPI_CR_MODE_BITS_MASK 0xff0000U
#define qspi_LQSPI_CR_RESERVED_2_LSHIFT 11U
#define qspi_LQSPI_CR_RESERVED_2_MASK 0xf800U
#define qspi_LQSPI_CR_DUMMY_LSHIFT 8U
#define qspi_LQSPI_CR_DUMMY_MASK 0x700U
#define qspi_LQSPI_CR_INST_LSHIFT 0U
#define qspi_LQSPI_CR_INST_MASK 0xffU
#define qspi_LQSPI_CR_MASK 0xf3ff07ffU


// Status Register specifically for the Linear Quad-SPI Controller
#define qspi_LQSPI_SR_REG 0xa4U
#define qspi_LQSPI_SR_RESERVED_0_LSHIFT 3U
#define qspi_LQSPI_SR_RESERVED_0_MASK 0xfffffff8U
#define qspi_LQSPI_SR_FB_RECVD_LSHIFT 2U
#define qspi_LQSPI_SR_FB_RECVD 0x4U
#define qspi_LQSPI_SR_FB_RECVD_MASK 0x4U
#define qspi_LQSPI_SR_WR_RECVD_LSHIFT 1U
#define qspi_LQSPI_SR_WR_RECVD 0x2U
#define qspi_LQSPI_SR_WR_RECVD_MASK 0x2U
#define qspi_LQSPI_SR_RESERVED_1_LSHIFT 0U
#define qspi_LQSPI_SR_RESERVED_1 0x1U
#define qspi_LQSPI_SR_RESERVED_1_MASK 0x1U
#define qspi_LQSPI_SR_MASK 0x6U


// Module Identification register
#define qspi_MOD_ID_REG 0xfcU
#define qspi_MOD_ID_ID_LSHIFT 0U
#define qspi_MOD_ID_ID_MASK 0x0U
#define qspi_MOD_ID_MASK 0x0U


