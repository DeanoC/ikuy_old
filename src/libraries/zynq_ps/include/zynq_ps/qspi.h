#pragma once
// Copyright Deano Calver
// SPDX-License-Identifier: MIT
// Quad SPI
// Auto-generated on Sun Sep 20 23:32:01 EEST 2020

#include <stdint.h>

// 1 banks of qspi chips
#define qspi_BASE_ADDR 0xe000d000U

// QSPI configuration register
#define qspi_CR_OFFSET 0x00000000U
#define qspi_CR_IFMODE_LSHIFT 0x0000001fU
#define qspi_CR_IFMODE 0x80000000U
#define qspi_CR_IFMODE_MASK 0x80000000U
#define qspi_CR_reserved_0_LSHIFT 0x0000001bU
#define qspi_CR_reserved_0_MASK 0x78000000U
#define qspi_CR_ENDIAN_LSHIFT 0x0000001aU
#define qspi_CR_ENDIAN  0x4000000U
#define qspi_CR_ENDIAN_MASK 0x04000000U
#define qspi_CR_reserved_1_LSHIFT 0x00000014U
#define qspi_CR_reserved_1_MASK 0x03f00000U
#define qspi_CR_HOLDDB_DR_LSHIFT 0x00000013U
#define qspi_CR_HOLDDB_DR    0x80000U
#define qspi_CR_HOLDDB_DR_MASK 0x00080000U
#define qspi_CR_reserved_2_LSHIFT 0x00000012U
#define qspi_CR_reserved_2    0x40000U
#define qspi_CR_reserved_2_MASK 0x00040000U
#define qspi_CR_reserved_3_LSHIFT 0x00000011U
#define qspi_CR_reserved_3    0x20000U
#define qspi_CR_reserved_3_MASK 0x00020000U
#define qspi_CR_MANSTRT_LSHIFT 0x00000010U
#define qspi_CR_MANSTRT    0x10000U
#define qspi_CR_MANSTRT_MASK 0x00010000U
#define qspi_CR_MANSTRTEN_LSHIFT 0x0000000fU
#define qspi_CR_MANSTRTEN     0x8000U
#define qspi_CR_MANSTRTEN_MASK 0x00008000U
#define qspi_CR_SSFORCE_LSHIFT 0x0000000eU
#define qspi_CR_SSFORCE     0x4000U
#define qspi_CR_SSFORCE_MASK 0x00004000U
#define qspi_CR_reserved_4_LSHIFT 0x0000000bU
#define qspi_CR_reserved_4_MASK 0x00003800U
#define qspi_CR_PCS_LSHIFT 0x0000000aU
#define qspi_CR_PCS      0x400U
#define qspi_CR_PCS_MASK 0x00000400U
#define qspi_CR_reserved_5_LSHIFT 0x00000009U
#define qspi_CR_reserved_5      0x200U
#define qspi_CR_reserved_5_MASK 0x00000200U
#define qspi_CR_REF_CLK_LSHIFT 0x00000008U
#define qspi_CR_REF_CLK      0x100U
#define qspi_CR_REF_CLK_MASK 0x00000100U
#define qspi_CR_FIFO_WIDTH_LSHIFT 0x00000006U
#define qspi_CR_FIFO_WIDTH_MASK 0x000000c0U
#define qspi_CR_BAUD_RATE_DIV_LSHIFT 0x00000003U
#define qspi_CR_BAUD_RATE_DIV_MASK 0x00000038U
#define qspi_CR_CPHA_LSHIFT 0x00000002U
#define qspi_CR_CPHA        0x4U
#define qspi_CR_CPHA_MASK 0x00000004U
#define qspi_CR_CPOL_LSHIFT 0x00000001U
#define qspi_CR_CPOL        0x2U
#define qspi_CR_CPOL_MASK 0x00000002U
#define qspi_CR_MSTREN_LSHIFT 0x00000000U
#define qspi_CR_MSTREN        0x1U
#define qspi_CR_MSTREN_MASK 0x00000001U
#define qspi_CR_MASK 0x8409c5ffU

// QSPI interrupt status register
#define qspi_SR_OFFSET 0x00000004U
#define qspi_SR_reserved_0_LSHIFT 0x00000007U
#define qspi_SR_reserved_0_MASK 0xffffff80U
#define qspi_SR_IXR_TXUF_LSHIFT 0x00000006U
#define qspi_SR_IXR_TXUF       0x40U
#define qspi_SR_IXR_TXUF_MASK 0x00000040U
#define qspi_SR_IXR_RXFULL_LSHIFT 0x00000005U
#define qspi_SR_IXR_RXFULL       0x20U
#define qspi_SR_IXR_RXFULL_MASK 0x00000020U
#define qspi_SR_IXR_RXNEMPTY_LSHIFT 0x00000004U
#define qspi_SR_IXR_RXNEMPTY       0x10U
#define qspi_SR_IXR_RXNEMPTY_MASK 0x00000010U
#define qspi_SR_IXR_TXFULL_LSHIFT 0x00000003U
#define qspi_SR_IXR_TXFULL        0x8U
#define qspi_SR_IXR_TXFULL_MASK 0x00000008U
#define qspi_SR_IXR_TXOW_LSHIFT 0x00000002U
#define qspi_SR_IXR_TXOW        0x4U
#define qspi_SR_IXR_TXOW_MASK 0x00000004U
#define qspi_SR_reserved_1_LSHIFT 0x00000001U
#define qspi_SR_reserved_1        0x2U
#define qspi_SR_reserved_1_MASK 0x00000002U
#define qspi_SR_IXR_RXOVR_LSHIFT 0x00000000U
#define qspi_SR_IXR_RXOVR        0x1U
#define qspi_SR_IXR_RXOVR_MASK 0x00000001U
#define qspi_SR_MASK 0x0000007dU

// Interrupt Enable register.
#define qspi_IER_OFFSET 0x00000008U
#define qspi_IER_reserved_0_LSHIFT 0x00000007U
#define qspi_IER_reserved_0_MASK 0xffffff80U
#define qspi_IER_IXR_TXUF_LSHIFT 0x00000006U
#define qspi_IER_IXR_TXUF       0x40U
#define qspi_IER_IXR_TXUF_MASK 0x00000040U
#define qspi_IER_IXR_RXFULL_LSHIFT 0x00000005U
#define qspi_IER_IXR_RXFULL       0x20U
#define qspi_IER_IXR_RXFULL_MASK 0x00000020U
#define qspi_IER_IXR_RXNEMPTY_LSHIFT 0x00000004U
#define qspi_IER_IXR_RXNEMPTY       0x10U
#define qspi_IER_IXR_RXNEMPTY_MASK 0x00000010U
#define qspi_IER_IXR_TXFULL_LSHIFT 0x00000003U
#define qspi_IER_IXR_TXFULL        0x8U
#define qspi_IER_IXR_TXFULL_MASK 0x00000008U
#define qspi_IER_IXR_TXOW_LSHIFT 0x00000002U
#define qspi_IER_IXR_TXOW        0x4U
#define qspi_IER_IXR_TXOW_MASK 0x00000004U
#define qspi_IER_reserved_1_LSHIFT 0x00000001U
#define qspi_IER_reserved_1        0x2U
#define qspi_IER_reserved_1_MASK 0x00000002U
#define qspi_IER_IXR_RXOVR_LSHIFT 0x00000000U
#define qspi_IER_IXR_RXOVR        0x1U
#define qspi_IER_IXR_RXOVR_MASK 0x00000001U
#define qspi_IER_MASK 0x0000007dU

// Interrupt disable register.
#define qspi_IDR_OFFSET 0x0000000cU
#define qspi_IDR_reserved_0_LSHIFT 0x00000007U
#define qspi_IDR_reserved_0_MASK 0xffffff80U
#define qspi_IDR_IXR_TXUF_LSHIFT 0x00000006U
#define qspi_IDR_IXR_TXUF       0x40U
#define qspi_IDR_IXR_TXUF_MASK 0x00000040U
#define qspi_IDR_IXR_RXFULL_LSHIFT 0x00000005U
#define qspi_IDR_IXR_RXFULL       0x20U
#define qspi_IDR_IXR_RXFULL_MASK 0x00000020U
#define qspi_IDR_IXR_RXNEMPTY_LSHIFT 0x00000004U
#define qspi_IDR_IXR_RXNEMPTY       0x10U
#define qspi_IDR_IXR_RXNEMPTY_MASK 0x00000010U
#define qspi_IDR_IXR_TXFULL_LSHIFT 0x00000003U
#define qspi_IDR_IXR_TXFULL        0x8U
#define qspi_IDR_IXR_TXFULL_MASK 0x00000008U
#define qspi_IDR_IXR_TXOW_LSHIFT 0x00000002U
#define qspi_IDR_IXR_TXOW        0x4U
#define qspi_IDR_IXR_TXOW_MASK 0x00000004U
#define qspi_IDR_reserved_1_LSHIFT 0x00000001U
#define qspi_IDR_reserved_1        0x2U
#define qspi_IDR_reserved_1_MASK 0x00000002U
#define qspi_IDR_IXR_RXOVR_LSHIFT 0x00000000U
#define qspi_IDR_IXR_RXOVR        0x1U
#define qspi_IDR_IXR_RXOVR_MASK 0x00000001U
#define qspi_IDR_MASK 0x0000007dU

// Interrupt mask register
#define qspi_IMR_OFFSET 0x00000010U
#define qspi_IMR_reserved_0_LSHIFT 0x00000007U
#define qspi_IMR_reserved_0_MASK 0xffffff80U
#define qspi_IMR_IXR_TXUF_LSHIFT 0x00000006U
#define qspi_IMR_IXR_TXUF       0x40U
#define qspi_IMR_IXR_TXUF_MASK 0x00000040U
#define qspi_IMR_IXR_RXFULL_LSHIFT 0x00000005U
#define qspi_IMR_IXR_RXFULL       0x20U
#define qspi_IMR_IXR_RXFULL_MASK 0x00000020U
#define qspi_IMR_IXR_RXNEMPTY_LSHIFT 0x00000004U
#define qspi_IMR_IXR_RXNEMPTY       0x10U
#define qspi_IMR_IXR_RXNEMPTY_MASK 0x00000010U
#define qspi_IMR_IXR_TXFULL_LSHIFT 0x00000003U
#define qspi_IMR_IXR_TXFULL        0x8U
#define qspi_IMR_IXR_TXFULL_MASK 0x00000008U
#define qspi_IMR_IXR_TXOW_LSHIFT 0x00000002U
#define qspi_IMR_IXR_TXOW        0x4U
#define qspi_IMR_IXR_TXOW_MASK 0x00000004U
#define qspi_IMR_reserved_1_LSHIFT 0x00000001U
#define qspi_IMR_reserved_1        0x2U
#define qspi_IMR_reserved_1_MASK 0x00000002U
#define qspi_IMR_IXR_RXOVR_LSHIFT 0x00000000U
#define qspi_IMR_IXR_RXOVR        0x1U
#define qspi_IMR_IXR_RXOVR_MASK 0x00000001U
#define qspi_IMR_MASK 0x0000007dU

// SPI_Enable Register
#define qspi_ER_OFFSET 0x00000014U
#define qspi_ER_reserved_0_LSHIFT 0x00000001U
#define qspi_ER_reserved_0_MASK 0xfffffffeU
#define qspi_ER_ENABLE_LSHIFT 0x00000000U
#define qspi_ER_ENABLE        0x1U
#define qspi_ER_ENABLE_MASK 0x00000001U
#define qspi_ER_MASK 0x00000001U

// Delay Register
#define qspi_DR_OFFSET 0x00000018U
#define qspi_DR_D_NSS_LSHIFT 0x00000018U
#define qspi_DR_D_NSS_MASK 0xff000000U
#define qspi_DR_BTWN_LSHIFT 0x00000010U
#define qspi_DR_BTWN_MASK 0x00ff0000U
#define qspi_DR_AFTER_LSHIFT 0x00000008U
#define qspi_DR_AFTER_MASK 0x0000ff00U
#define qspi_DR_INIT_LSHIFT 0x00000000U
#define qspi_DR_INIT_MASK 0x000000ffU
#define qspi_DR_MASK 0xffffffffU

// Transmit Data Register. Keyhole addresses for the Transmit data FIFO.
#define qspi_TXD_00_OFFSET 0x0000001cU
#define qspi_TXD_00_TXD_LSHIFT 0x00000000U
#define qspi_TXD_00_TXD_MASK 0x00000000U

// Receive Data Register
#define qspi_RXD_OFFSET 0x00000020U
#define qspi_RXD_RX_FIFO_LSHIFT 0x00000000U
#define qspi_RXD_RX_FIFO_MASK 0x00000000U

// Slave Idle Count Register
#define qspi_SICR_OFFSET 0x00000024U
#define qspi_SICR_reserved_0_LSHIFT 0x00000008U
#define qspi_SICR_reserved_0_MASK 0xffffff00U
#define qspi_SICR_MASK_LSHIFT 0x00000000U
#define qspi_SICR_MASK_MASK 0x000000ffU
#define qspi_SICR_MASK 0x000000ffU

// TX_FIFO Threshold Register
#define qspi_TXWR_OFFSET 0x00000028U
#define qspi_TXWR_THRESHOLD_OF_TX_FIFO_LSHIFT 0x00000000U
#define qspi_TXWR_THRESHOLD_OF_TX_FIFO_MASK 0x00000000U

// RX FIFO Threshold Register
#define qspi_RX_THRES_OFFSET 0x0000002cU
#define qspi_RX_THRES_THRESHOLD_OF_RX_FIFO_LSHIFT 0x00000000U
#define qspi_RX_THRES_THRESHOLD_OF_RX_FIFO_MASK 0x00000000U

// General Purpose Inputs and Outputs Register for the Quad-SPI Controller core
#define qspi_GPIO_OFFSET 0x00000030U
#define qspi_GPIO_reserved_0_LSHIFT 0x00000001U
#define qspi_GPIO_reserved_0_MASK 0xfffffffeU
#define qspi_GPIO_WP_N_LSHIFT 0x00000000U
#define qspi_GPIO_WP_N        0x1U
#define qspi_GPIO_WP_N_MASK 0x00000001U
#define qspi_GPIO_MASK 0x00000001U

// Loopback Master Clock Delay Adjustment Register
#define qspi_LPBK_DLY_ADJ_OFFSET 0x00000038U
#define qspi_LPBK_DLY_ADJ_reserved_0_LSHIFT 0x00000006U
#define qspi_LPBK_DLY_ADJ_reserved_0_MASK 0xffffffc0U
#define qspi_LPBK_DLY_ADJ_USE_LPBK_LSHIFT 0x00000005U
#define qspi_LPBK_DLY_ADJ_USE_LPBK       0x20U
#define qspi_LPBK_DLY_ADJ_USE_LPBK_MASK 0x00000020U
#define qspi_LPBK_DLY_ADJ_reserved_1_LSHIFT 0x00000000U
#define qspi_LPBK_DLY_ADJ_reserved_1_MASK 0x0000001fU
#define qspi_LPBK_DLY_ADJ_MASK 0x00000020U

// Transmit Data Register. Keyhole addresses for the Transmit data FIFO.
#define qspi_TXD_01_OFFSET 0x00000080U
#define qspi_TXD_01_TXD_LSHIFT 0x00000000U
#define qspi_TXD_01_TXD_MASK 0x00000000U

// Transmit Data Register. Keyhole addresses for the Transmit data FIFO.
#define qspi_TXD_10_OFFSET 0x00000084U
#define qspi_TXD_10_TXD_LSHIFT 0x00000000U
#define qspi_TXD_10_TXD_MASK 0x00000000U

// Transmit Data Register. Keyhole addresses for the Transmit data FIFO.
#define qspi_TXD_11_OFFSET 0x00000088U
#define qspi_TXD_11_TXD_LSHIFT 0x00000000U
#define qspi_TXD_11_TXD_MASK 0x00000000U

// Configuration Register specifically for the Linear Quad-SPI Controller
#define qspi_LQSPI_CR_OFFSET 0x000000a0U
#define qspi_LQSPI_CR_LINEAR_LSHIFT 0x0000001fU
#define qspi_LQSPI_CR_LINEAR 0x80000000U
#define qspi_LQSPI_CR_LINEAR_MASK 0x80000000U
#define qspi_LQSPI_CR_TWO_MEM_LSHIFT 0x0000001eU
#define qspi_LQSPI_CR_TWO_MEM 0x40000000U
#define qspi_LQSPI_CR_TWO_MEM_MASK 0x40000000U
#define qspi_LQSPI_CR_SEP_BUS_LSHIFT 0x0000001dU
#define qspi_LQSPI_CR_SEP_BUS 0x20000000U
#define qspi_LQSPI_CR_SEP_BUS_MASK 0x20000000U
#define qspi_LQSPI_CR_U_PAGE_LSHIFT 0x0000001cU
#define qspi_LQSPI_CR_U_PAGE 0x10000000U
#define qspi_LQSPI_CR_U_PAGE_MASK 0x10000000U
#define qspi_LQSPI_CR_reserved_0_LSHIFT 0x0000001bU
#define qspi_LQSPI_CR_reserved_0  0x8000000U
#define qspi_LQSPI_CR_reserved_0_MASK 0x08000000U
#define qspi_LQSPI_CR_reserved_1_LSHIFT 0x0000001aU
#define qspi_LQSPI_CR_reserved_1  0x4000000U
#define qspi_LQSPI_CR_reserved_1_MASK 0x04000000U
#define qspi_LQSPI_CR_MODE_EN_LSHIFT 0x00000019U
#define qspi_LQSPI_CR_MODE_EN  0x2000000U
#define qspi_LQSPI_CR_MODE_EN_MASK 0x02000000U
#define qspi_LQSPI_CR_MODE_ON_LSHIFT 0x00000018U
#define qspi_LQSPI_CR_MODE_ON  0x1000000U
#define qspi_LQSPI_CR_MODE_ON_MASK 0x01000000U
#define qspi_LQSPI_CR_MODE_BITS_LSHIFT 0x00000010U
#define qspi_LQSPI_CR_MODE_BITS_MASK 0x00ff0000U
#define qspi_LQSPI_CR_reserved_2_LSHIFT 0x0000000bU
#define qspi_LQSPI_CR_reserved_2_MASK 0x0000f800U
#define qspi_LQSPI_CR_DUMMY_LSHIFT 0x00000008U
#define qspi_LQSPI_CR_DUMMY_MASK 0x00000700U
#define qspi_LQSPI_CR_INST_LSHIFT 0x00000000U
#define qspi_LQSPI_CR_INST_MASK 0x000000ffU
#define qspi_LQSPI_CR_MASK 0xf3ff07ffU

// Status Register specifically for the Linear Quad-SPI Controller
#define qspi_LQSPI_SR_OFFSET 0x000000a4U
#define qspi_LQSPI_SR_reserved_0_LSHIFT 0x00000003U
#define qspi_LQSPI_SR_reserved_0_MASK 0xfffffff8U
#define qspi_LQSPI_SR_FB_RECVD_LSHIFT 0x00000002U
#define qspi_LQSPI_SR_FB_RECVD        0x4U
#define qspi_LQSPI_SR_FB_RECVD_MASK 0x00000004U
#define qspi_LQSPI_SR_WR_RECVD_LSHIFT 0x00000001U
#define qspi_LQSPI_SR_WR_RECVD        0x2U
#define qspi_LQSPI_SR_WR_RECVD_MASK 0x00000002U
#define qspi_LQSPI_SR_reserved_1_LSHIFT 0x00000000U
#define qspi_LQSPI_SR_reserved_1        0x1U
#define qspi_LQSPI_SR_reserved_1_MASK 0x00000001U
#define qspi_LQSPI_SR_MASK 0x00000006U

// Module Identification register
#define qspi_MOD_ID_OFFSET 0x000000fcU
#define qspi_MOD_ID_ID_LSHIFT 0x00000000U
#define qspi_MOD_ID_ID_MASK 0x00000000U
