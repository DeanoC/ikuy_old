#pragma once
// Copyright Deano Calver
// SPDX-License-Identifier: MIT
// Serial Peripheral Interface
// Auto-generated on Mon Sep 21 19:32:27 EEST 2020

#include <stdint.h>

// 2 banks of spi chips
#define spi0_BASE_ADDR 0xe0006000U
#define spi1_BASE_ADDR 0xe0007000U

// SPI Configuration.
#define spi_CR_OFFSET 0x00000000U
#define spi_CR_reserved_0_LSHIFT 0x00000012U
#define spi_CR_reserved_0_MASK 0xfffc0000U
#define spi_CR_MODEFAIL_GEN_EN_LSHIFT 0x00000011U
#define spi_CR_MODEFAIL_GEN_EN    0x20000U
#define spi_CR_MODEFAIL_GEN_EN_MASK 0x00020000U
#define spi_CR_MANSTRT_LSHIFT 0x00000010U
#define spi_CR_MANSTRT    0x10000U
#define spi_CR_MANSTRT_MASK 0x00010000U
#define spi_CR_MAN_START_EN_LSHIFT 0x0000000fU
#define spi_CR_MAN_START_EN     0x8000U
#define spi_CR_MAN_START_EN_MASK 0x00008000U
#define spi_CR_MANUAL_CS_LSHIFT 0x0000000eU
#define spi_CR_MANUAL_CS     0x4000U
#define spi_CR_MANUAL_CS_MASK 0x00004000U
#define spi_CR_CS_LSHIFT 0x0000000aU
#define spi_CR_CS_MASK 0x00003c00U
#define spi_CR_PERI_SEL_LSHIFT 0x00000009U
#define spi_CR_PERI_SEL      0x200U
#define spi_CR_PERI_SEL_MASK 0x00000200U
#define spi_CR_REF_CLK_LSHIFT 0x00000008U
#define spi_CR_REF_CLK      0x100U
#define spi_CR_REF_CLK_MASK 0x00000100U
#define spi_CR_reserved_1_LSHIFT 0x00000006U
#define spi_CR_reserved_1_MASK 0x000000c0U
#define spi_CR_BAUD_RATE_DIV_LSHIFT 0x00000003U
#define spi_CR_BAUD_RATE_DIV_MASK 0x00000038U
#define spi_CR_CPHA_LSHIFT 0x00000002U
#define spi_CR_CPHA        0x4U
#define spi_CR_CPHA_MASK 0x00000004U
#define spi_CR_CPOL_LSHIFT 0x00000001U
#define spi_CR_CPOL        0x2U
#define spi_CR_CPOL_MASK 0x00000002U
#define spi_CR_MSTREN_LSHIFT 0x00000000U
#define spi_CR_MSTREN        0x1U
#define spi_CR_MSTREN_MASK 0x00000001U
#define spi_CR_MASK 0x0003ff3fU

// SPI Interrupt Status
#define spi_SR_OFFSET 0x00000004U
#define spi_SR_reserved_0_LSHIFT 0x00000007U
#define spi_SR_reserved_0_MASK 0xffffff80U
#define spi_SR_IXR_TXUF_LSHIFT 0x00000006U
#define spi_SR_IXR_TXUF       0x40U
#define spi_SR_IXR_TXUF_MASK 0x00000040U
#define spi_SR_IXR_RXFULL_LSHIFT 0x00000005U
#define spi_SR_IXR_RXFULL       0x20U
#define spi_SR_IXR_RXFULL_MASK 0x00000020U
#define spi_SR_IXR_RXNEMPTY_LSHIFT 0x00000004U
#define spi_SR_IXR_RXNEMPTY       0x10U
#define spi_SR_IXR_RXNEMPTY_MASK 0x00000010U
#define spi_SR_IXR_TXFULL_LSHIFT 0x00000003U
#define spi_SR_IXR_TXFULL        0x8U
#define spi_SR_IXR_TXFULL_MASK 0x00000008U
#define spi_SR_IXR_TXOW_LSHIFT 0x00000002U
#define spi_SR_IXR_TXOW        0x4U
#define spi_SR_IXR_TXOW_MASK 0x00000004U
#define spi_SR_IXR_MODF_LSHIFT 0x00000001U
#define spi_SR_IXR_MODF        0x2U
#define spi_SR_IXR_MODF_MASK 0x00000002U
#define spi_SR_IXR_RXOVR_LSHIFT 0x00000000U
#define spi_SR_IXR_RXOVR        0x1U
#define spi_SR_IXR_RXOVR_MASK 0x00000001U
#define spi_SR_MASK 0x0000007fU

// Interrupt Enable.
#define spi_IER_OFFSET 0x00000008U
#define spi_IER_reserved_0_LSHIFT 0x00000007U
#define spi_IER_reserved_0_MASK 0xffffff80U
#define spi_IER_IXR_TXUF_LSHIFT 0x00000006U
#define spi_IER_IXR_TXUF       0x40U
#define spi_IER_IXR_TXUF_MASK 0x00000040U
#define spi_IER_IXR_RXFULL_LSHIFT 0x00000005U
#define spi_IER_IXR_RXFULL       0x20U
#define spi_IER_IXR_RXFULL_MASK 0x00000020U
#define spi_IER_IXR_RXNEMPTY_LSHIFT 0x00000004U
#define spi_IER_IXR_RXNEMPTY       0x10U
#define spi_IER_IXR_RXNEMPTY_MASK 0x00000010U
#define spi_IER_IXR_TXFULL_LSHIFT 0x00000003U
#define spi_IER_IXR_TXFULL        0x8U
#define spi_IER_IXR_TXFULL_MASK 0x00000008U
#define spi_IER_IXR_TXOW_LSHIFT 0x00000002U
#define spi_IER_IXR_TXOW        0x4U
#define spi_IER_IXR_TXOW_MASK 0x00000004U
#define spi_IER_IXR_MODF_LSHIFT 0x00000001U
#define spi_IER_IXR_MODF        0x2U
#define spi_IER_IXR_MODF_MASK 0x00000002U
#define spi_IER_IXR_RXOVR_LSHIFT 0x00000000U
#define spi_IER_IXR_RXOVR        0x1U
#define spi_IER_IXR_RXOVR_MASK 0x00000001U
#define spi_IER_MASK 0x0000007fU

// Interrupt disable.
#define spi_IDR_OFFSET 0x0000000cU
#define spi_IDR_reserved_0_LSHIFT 0x00000007U
#define spi_IDR_reserved_0_MASK 0xffffff80U
#define spi_IDR_IXR_TXUF_LSHIFT 0x00000006U
#define spi_IDR_IXR_TXUF       0x40U
#define spi_IDR_IXR_TXUF_MASK 0x00000040U
#define spi_IDR_IXR_RXFULL_LSHIFT 0x00000005U
#define spi_IDR_IXR_RXFULL       0x20U
#define spi_IDR_IXR_RXFULL_MASK 0x00000020U
#define spi_IDR_IXR_RXNEMPTY_LSHIFT 0x00000004U
#define spi_IDR_IXR_RXNEMPTY       0x10U
#define spi_IDR_IXR_RXNEMPTY_MASK 0x00000010U
#define spi_IDR_IXR_TXFULL_LSHIFT 0x00000003U
#define spi_IDR_IXR_TXFULL        0x8U
#define spi_IDR_IXR_TXFULL_MASK 0x00000008U
#define spi_IDR_IXR_TXOW_LSHIFT 0x00000002U
#define spi_IDR_IXR_TXOW        0x4U
#define spi_IDR_IXR_TXOW_MASK 0x00000004U
#define spi_IDR_IXR_MODF_LSHIFT 0x00000001U
#define spi_IDR_IXR_MODF        0x2U
#define spi_IDR_IXR_MODF_MASK 0x00000002U
#define spi_IDR_IXR_RXOVR_LSHIFT 0x00000000U
#define spi_IDR_IXR_RXOVR        0x1U
#define spi_IDR_IXR_RXOVR_MASK 0x00000001U
#define spi_IDR_MASK 0x0000007fU

// Interrupt mask.
#define spi_IMR_OFFSET 0x00000010U
#define spi_IMR_reserved_0_LSHIFT 0x00000007U
#define spi_IMR_reserved_0_MASK 0xffffff80U
#define spi_IMR_IXR_TXUF_LSHIFT 0x00000006U
#define spi_IMR_IXR_TXUF       0x40U
#define spi_IMR_IXR_TXUF_MASK 0x00000040U
#define spi_IMR_IXR_RXFULL_LSHIFT 0x00000005U
#define spi_IMR_IXR_RXFULL       0x20U
#define spi_IMR_IXR_RXFULL_MASK 0x00000020U
#define spi_IMR_IXR_RXNEMPTY_LSHIFT 0x00000004U
#define spi_IMR_IXR_RXNEMPTY       0x10U
#define spi_IMR_IXR_RXNEMPTY_MASK 0x00000010U
#define spi_IMR_IXR_TXFULL_LSHIFT 0x00000003U
#define spi_IMR_IXR_TXFULL        0x8U
#define spi_IMR_IXR_TXFULL_MASK 0x00000008U
#define spi_IMR_IXR_TXOW_LSHIFT 0x00000002U
#define spi_IMR_IXR_TXOW        0x4U
#define spi_IMR_IXR_TXOW_MASK 0x00000004U
#define spi_IMR_IXR_MODF_LSHIFT 0x00000001U
#define spi_IMR_IXR_MODF        0x2U
#define spi_IMR_IXR_MODF_MASK 0x00000002U
#define spi_IMR_IXR_RXOVR_LSHIFT 0x00000000U
#define spi_IMR_IXR_RXOVR        0x1U
#define spi_IMR_IXR_RXOVR_MASK 0x00000001U
#define spi_IMR_MASK 0x0000007fU

// SPI Controller Enable.
#define spi_ER_OFFSET 0x00000014U
#define spi_ER_reserved_0_LSHIFT 0x00000001U
#define spi_ER_reserved_0_MASK 0xfffffffeU
#define spi_ER_ENABLE_LSHIFT 0x00000000U
#define spi_ER_ENABLE        0x1U
#define spi_ER_ENABLE_MASK 0x00000001U
#define spi_ER_MASK 0x00000001U

// Delay Control
#define spi_DR_OFFSET 0x00000018U
#define spi_DR_D_NSS_LSHIFT 0x00000018U
#define spi_DR_D_NSS_MASK 0xff000000U
#define spi_DR_BTWN_LSHIFT 0x00000010U
#define spi_DR_BTWN_MASK 0x00ff0000U
#define spi_DR_AFTER_LSHIFT 0x00000008U
#define spi_DR_AFTER_MASK 0x0000ff00U
#define spi_DR_INIT_LSHIFT 0x00000000U
#define spi_DR_INIT_MASK 0x000000ffU
#define spi_DR_MASK 0xffffffffU

// Transmit Data.
#define spi_TXD_OFFSET 0x0000001cU
#define spi_TXD_TX_FIFO_data_LSHIFT 0x00000000U
#define spi_TXD_TX_FIFO_data_MASK 0x00000000U

// Receive Data.
#define spi_RXD_OFFSET 0x00000020U
#define spi_RXD_RX_FIFO_data_LSHIFT 0x00000000U
#define spi_RXD_RX_FIFO_data_MASK 0x00000000U

// Slave Idle Count.
#define spi_SICR_OFFSET 0x00000024U
#define spi_SICR_reserved_0_LSHIFT 0x00000008U
#define spi_SICR_reserved_0_MASK 0xffffff00U
#define spi_SICR_SLAVE_IDLE_COUNT_LSHIFT 0x00000000U
#define spi_SICR_SLAVE_IDLE_COUNT_MASK 0x000000ffU
#define spi_SICR_MASK 0x000000ffU

// TX_FIFO Threshold.
#define spi_TXWR_OFFSET 0x00000028U
#define spi_TXWR_THRESHOLD_OF_TX_FIFO_LSHIFT 0x00000000U
#define spi_TXWR_THRESHOLD_OF_TX_FIFO_MASK 0x00000000U

// RX FIFO Threshold.
#define spi_RX_THRES_OFFSET 0x0000002cU
#define spi_RX_THRES_THRESHOLD_OF_RX_FIFO_LSHIFT 0x00000000U
#define spi_RX_THRES_THRESHOLD_OF_RX_FIFO_MASK 0x00000000U

// Module ID
#define spi_MOD_ID_OFFSET 0x000000fcU
#define spi_MOD_ID_reserved_0_LSHIFT 0x00000019U
#define spi_MOD_ID_reserved_0_MASK 0xfe000000U
#define spi_MOD_ID_MODULE_ID_LSHIFT 0x00000000U
#define spi_MOD_ID_MODULE_ID_MASK 0x01ffffffU
#define spi_MOD_ID_MASK 0x01ffffffU
