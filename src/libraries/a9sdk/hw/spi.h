#pragma once
// Copyright Deano Calver
// SPDX-License-Identifier: MIT

#include <stdint.h>

// SPI

// 2 banks of spi

#define spi0_BASE_ADDR 0xe0006000U
#define spi1_BASE_ADDR 0xe0007000U

// Registers

// SPI Configuration.
#define spi_CR_REG 0x0U
#define spi_CR_RESERVED_0_LSHIFT 18U
#define spi_CR_RESERVED_0_MASK 0xfffc0000U
#define spi_CR_MODEFAIL_GEN_EN_LSHIFT 17U
#define spi_CR_MODEFAIL_GEN_EN 0x20000U
#define spi_CR_MODEFAIL_GEN_EN_MASK 0x20000U
#define spi_CR_MANSTRT_LSHIFT 16U
#define spi_CR_MANSTRT 0x10000U
#define spi_CR_MANSTRT_MASK 0x10000U
#define spi_CR_MAN_START_EN_LSHIFT 15U
#define spi_CR_MAN_START_EN 0x8000U
#define spi_CR_MAN_START_EN_MASK 0x8000U
#define spi_CR_MANUAL_CS_LSHIFT 14U
#define spi_CR_MANUAL_CS 0x4000U
#define spi_CR_MANUAL_CS_MASK 0x4000U
#define spi_CR_CS_LSHIFT 10U
#define spi_CR_CS_MASK 0x3c00U
#define spi_CR_PERI_SEL_LSHIFT 9U
#define spi_CR_PERI_SEL 0x200U
#define spi_CR_PERI_SEL_MASK 0x200U
#define spi_CR_REF_CLK_LSHIFT 8U
#define spi_CR_REF_CLK 0x100U
#define spi_CR_REF_CLK_MASK 0x100U
#define spi_CR_RESERVED_1_LSHIFT 6U
#define spi_CR_RESERVED_1_MASK 0xc0U
#define spi_CR_BAUD_RATE_DIV_LSHIFT 3U
#define spi_CR_BAUD_RATE_DIV_MASK 0x38U
#define spi_CR_CPHA_LSHIFT 2U
#define spi_CR_CPHA 0x4U
#define spi_CR_CPHA_MASK 0x4U
#define spi_CR_CPOL_LSHIFT 1U
#define spi_CR_CPOL 0x2U
#define spi_CR_CPOL_MASK 0x2U
#define spi_CR_MSTREN_LSHIFT 0U
#define spi_CR_MSTREN 0x1U
#define spi_CR_MSTREN_MASK 0x1U
#define spi_CR_MASK 0x3ff3fU


// SPI Interrupt Status
#define spi_SR_REG 0x4U
#define spi_SR_RESERVED_0_LSHIFT 7U
#define spi_SR_RESERVED_0_MASK 0xffffff80U
#define spi_SR_IXR_TXUF_LSHIFT 6U
#define spi_SR_IXR_TXUF 0x40U
#define spi_SR_IXR_TXUF_MASK 0x40U
#define spi_SR_IXR_RXFULL_LSHIFT 5U
#define spi_SR_IXR_RXFULL 0x20U
#define spi_SR_IXR_RXFULL_MASK 0x20U
#define spi_SR_IXR_RXNEMPTY_LSHIFT 4U
#define spi_SR_IXR_RXNEMPTY 0x10U
#define spi_SR_IXR_RXNEMPTY_MASK 0x10U
#define spi_SR_IXR_TXFULL_LSHIFT 3U
#define spi_SR_IXR_TXFULL 0x8U
#define spi_SR_IXR_TXFULL_MASK 0x8U
#define spi_SR_IXR_TXOW_LSHIFT 2U
#define spi_SR_IXR_TXOW 0x4U
#define spi_SR_IXR_TXOW_MASK 0x4U
#define spi_SR_IXR_MODF_LSHIFT 1U
#define spi_SR_IXR_MODF 0x2U
#define spi_SR_IXR_MODF_MASK 0x2U
#define spi_SR_IXR_RXOVR_LSHIFT 0U
#define spi_SR_IXR_RXOVR 0x1U
#define spi_SR_IXR_RXOVR_MASK 0x1U
#define spi_SR_MASK 0x7fU


// Interrupt Enable.
#define spi_IER_REG 0x8U
#define spi_IER_RESERVED_0_LSHIFT 7U
#define spi_IER_RESERVED_0_MASK 0xffffff80U
#define spi_IER_IXR_TXUF_LSHIFT 6U
#define spi_IER_IXR_TXUF 0x40U
#define spi_IER_IXR_TXUF_MASK 0x40U
#define spi_IER_IXR_RXFULL_LSHIFT 5U
#define spi_IER_IXR_RXFULL 0x20U
#define spi_IER_IXR_RXFULL_MASK 0x20U
#define spi_IER_IXR_RXNEMPTY_LSHIFT 4U
#define spi_IER_IXR_RXNEMPTY 0x10U
#define spi_IER_IXR_RXNEMPTY_MASK 0x10U
#define spi_IER_IXR_TXFULL_LSHIFT 3U
#define spi_IER_IXR_TXFULL 0x8U
#define spi_IER_IXR_TXFULL_MASK 0x8U
#define spi_IER_IXR_TXOW_LSHIFT 2U
#define spi_IER_IXR_TXOW 0x4U
#define spi_IER_IXR_TXOW_MASK 0x4U
#define spi_IER_IXR_MODF_LSHIFT 1U
#define spi_IER_IXR_MODF 0x2U
#define spi_IER_IXR_MODF_MASK 0x2U
#define spi_IER_IXR_RXOVR_LSHIFT 0U
#define spi_IER_IXR_RXOVR 0x1U
#define spi_IER_IXR_RXOVR_MASK 0x1U
#define spi_IER_MASK 0x7fU


// Interrupt disable.
#define spi_IDR_REG 0xcU
#define spi_IDR_RESERVED_0_LSHIFT 7U
#define spi_IDR_RESERVED_0_MASK 0xffffff80U
#define spi_IDR_IXR_TXUF_LSHIFT 6U
#define spi_IDR_IXR_TXUF 0x40U
#define spi_IDR_IXR_TXUF_MASK 0x40U
#define spi_IDR_IXR_RXFULL_LSHIFT 5U
#define spi_IDR_IXR_RXFULL 0x20U
#define spi_IDR_IXR_RXFULL_MASK 0x20U
#define spi_IDR_IXR_RXNEMPTY_LSHIFT 4U
#define spi_IDR_IXR_RXNEMPTY 0x10U
#define spi_IDR_IXR_RXNEMPTY_MASK 0x10U
#define spi_IDR_IXR_TXFULL_LSHIFT 3U
#define spi_IDR_IXR_TXFULL 0x8U
#define spi_IDR_IXR_TXFULL_MASK 0x8U
#define spi_IDR_IXR_TXOW_LSHIFT 2U
#define spi_IDR_IXR_TXOW 0x4U
#define spi_IDR_IXR_TXOW_MASK 0x4U
#define spi_IDR_IXR_MODF_LSHIFT 1U
#define spi_IDR_IXR_MODF 0x2U
#define spi_IDR_IXR_MODF_MASK 0x2U
#define spi_IDR_IXR_RXOVR_LSHIFT 0U
#define spi_IDR_IXR_RXOVR 0x1U
#define spi_IDR_IXR_RXOVR_MASK 0x1U
#define spi_IDR_MASK 0x7fU


// Interrupt mask.
#define spi_IMR_REG 0x10U
#define spi_IMR_RESERVED_0_LSHIFT 7U
#define spi_IMR_RESERVED_0_MASK 0xffffff80U
#define spi_IMR_IXR_TXUF_LSHIFT 6U
#define spi_IMR_IXR_TXUF 0x40U
#define spi_IMR_IXR_TXUF_MASK 0x40U
#define spi_IMR_IXR_RXFULL_LSHIFT 5U
#define spi_IMR_IXR_RXFULL 0x20U
#define spi_IMR_IXR_RXFULL_MASK 0x20U
#define spi_IMR_IXR_RXNEMPTY_LSHIFT 4U
#define spi_IMR_IXR_RXNEMPTY 0x10U
#define spi_IMR_IXR_RXNEMPTY_MASK 0x10U
#define spi_IMR_IXR_TXFULL_LSHIFT 3U
#define spi_IMR_IXR_TXFULL 0x8U
#define spi_IMR_IXR_TXFULL_MASK 0x8U
#define spi_IMR_IXR_TXOW_LSHIFT 2U
#define spi_IMR_IXR_TXOW 0x4U
#define spi_IMR_IXR_TXOW_MASK 0x4U
#define spi_IMR_IXR_MODF_LSHIFT 1U
#define spi_IMR_IXR_MODF 0x2U
#define spi_IMR_IXR_MODF_MASK 0x2U
#define spi_IMR_IXR_RXOVR_LSHIFT 0U
#define spi_IMR_IXR_RXOVR 0x1U
#define spi_IMR_IXR_RXOVR_MASK 0x1U
#define spi_IMR_MASK 0x7fU


// SPI Controller Enable.
#define spi_ER_REG 0x14U
#define spi_ER_RESERVED_0_LSHIFT 1U
#define spi_ER_RESERVED_0_MASK 0xfffffffeU
#define spi_ER_ENABLE_LSHIFT 0U
#define spi_ER_ENABLE 0x1U
#define spi_ER_ENABLE_MASK 0x1U
#define spi_ER_MASK 0x1U


// Delay Control
#define spi_DR_REG 0x18U
#define spi_DR_D_NSS_LSHIFT 24U
#define spi_DR_D_NSS_MASK 0xff000000U
#define spi_DR_BTWN_LSHIFT 16U
#define spi_DR_BTWN_MASK 0xff0000U
#define spi_DR_AFTER_LSHIFT 8U
#define spi_DR_AFTER_MASK 0xff00U
#define spi_DR_INIT_LSHIFT 0U
#define spi_DR_INIT_MASK 0xffU
#define spi_DR_MASK 0xffffffffU


// Transmit Data.
#define spi_TXD_REG 0x1cU
#define spi_TXD_TX_FIFO_data_LSHIFT 0U
#define spi_TXD_TX_FIFO_data_MASK 0x0U
#define spi_TXD_MASK 0x0U


// Receive Data.
#define spi_RXD_REG 0x20U
#define spi_RXD_RX_FIFO_data_LSHIFT 0U
#define spi_RXD_RX_FIFO_data_MASK 0x0U
#define spi_RXD_MASK 0x0U


// Slave Idle Count.
#define spi_SICR_REG 0x24U
#define spi_SICR_RESERVED_0_LSHIFT 8U
#define spi_SICR_RESERVED_0_MASK 0xffffff00U
#define spi_SICR_SLAVE_IDLE_COUNT_LSHIFT 0U
#define spi_SICR_SLAVE_IDLE_COUNT_MASK 0xffU
#define spi_SICR_MASK 0xffU


// TX_FIFO Threshold.
#define spi_TXWR_REG 0x28U
#define spi_TXWR_THRESHOLD_OF_TX_FIFO_LSHIFT 0U
#define spi_TXWR_THRESHOLD_OF_TX_FIFO_MASK 0x0U
#define spi_TXWR_MASK 0x0U


// RX FIFO Threshold.
#define spi_RX_THRES_REG 0x2cU
#define spi_RX_THRES_THRESHOLD_OF_RX_FIFO_LSHIFT 0U
#define spi_RX_THRES_THRESHOLD_OF_RX_FIFO_MASK 0x0U
#define spi_RX_THRES_MASK 0x0U


// Module ID
#define spi_MOD_ID_REG 0xfcU
#define spi_MOD_ID_RESERVED_0_LSHIFT 25U
#define spi_MOD_ID_RESERVED_0_MASK 0xfe000000U
#define spi_MOD_ID_MODULE_ID_LSHIFT 0U
#define spi_MOD_ID_MODULE_ID_MASK 0x1ffffffU
#define spi_MOD_ID_MASK 0x1ffffffU


