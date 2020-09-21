#pragma once
// Copyright Deano Calver
// SPDX-License-Identifier: MIT
// Inter Integrated Circuit(I2C)
// Auto-generated on Mon Sep 21 17:18:27 EEST 2020

#include <stdint.h>

// 2 banks of i2c chips
#define i2c0_BASE_ADDR 0xe0004000U
#define i2c1_BASE_ADDR 0xe0005000U

// Control Register
#define i2c_CR_OFFSET 0x00000000U
#define i2c_CR_DIV_A_LSHIFT 0x0000000eU
#define i2c_CR_DIV_A_MASK 0x0000c000U
#define i2c_CR_DIV_B_LSHIFT 0x00000008U
#define i2c_CR_DIV_B_MASK 0x00003f00U
#define i2c_CR_reserved_0_LSHIFT 0x00000007U
#define i2c_CR_reserved_0       0x80U
#define i2c_CR_reserved_0_MASK 0x00000080U
#define i2c_CR_CLR_FIFO_LSHIFT 0x00000006U
#define i2c_CR_CLR_FIFO       0x40U
#define i2c_CR_CLR_FIFO_MASK 0x00000040U
#define i2c_CR_SLVMON_LSHIFT 0x00000005U
#define i2c_CR_SLVMON       0x20U
#define i2c_CR_SLVMON_MASK 0x00000020U
#define i2c_CR_HOLD_LSHIFT 0x00000004U
#define i2c_CR_HOLD       0x10U
#define i2c_CR_HOLD_MASK 0x00000010U
#define i2c_CR_ACKEN_LSHIFT 0x00000003U
#define i2c_CR_ACKEN        0x8U
#define i2c_CR_ACKEN_MASK 0x00000008U
#define i2c_CR_NEA_LSHIFT 0x00000002U
#define i2c_CR_NEA        0x4U
#define i2c_CR_NEA_MASK 0x00000004U
#define i2c_CR_MS_LSHIFT 0x00000001U
#define i2c_CR_MS        0x2U
#define i2c_CR_MS_MASK 0x00000002U
#define i2c_CR_RD_WR_LSHIFT 0x00000000U
#define i2c_CR_RD_WR        0x1U
#define i2c_CR_RD_WR_MASK 0x00000001U
#define i2c_CR_MASK 0x0000ff7fU

// Status register
#define i2c_SR_OFFSET 0x00000004U
#define i2c_SR_reserved_0_LSHIFT 0x00000009U
#define i2c_SR_reserved_0_MASK 0x0000fe00U
#define i2c_SR_BA_LSHIFT 0x00000008U
#define i2c_SR_BA      0x100U
#define i2c_SR_BA_MASK 0x00000100U
#define i2c_SR_RXOVF_LSHIFT 0x00000007U
#define i2c_SR_RXOVF       0x80U
#define i2c_SR_RXOVF_MASK 0x00000080U
#define i2c_SR_TXDV_LSHIFT 0x00000006U
#define i2c_SR_TXDV       0x40U
#define i2c_SR_TXDV_MASK 0x00000040U
#define i2c_SR_RXDV_LSHIFT 0x00000005U
#define i2c_SR_RXDV       0x20U
#define i2c_SR_RXDV_MASK 0x00000020U
#define i2c_SR_reserved_1_LSHIFT 0x00000004U
#define i2c_SR_reserved_1       0x10U
#define i2c_SR_reserved_1_MASK 0x00000010U
#define i2c_SR_RXRW_LSHIFT 0x00000003U
#define i2c_SR_RXRW        0x8U
#define i2c_SR_RXRW_MASK 0x00000008U
#define i2c_SR_reserved_2_LSHIFT 0x00000000U
#define i2c_SR_reserved_2_MASK 0x00000007U
#define i2c_SR_MASK 0x000001e8U

// I2C Address register
#define i2c_ADDR_OFFSET 0x00000008U
#define i2c_ADDR_reserved_0_LSHIFT 0x0000000aU
#define i2c_ADDR_reserved_0_MASK 0x0000fc00U
#define i2c_ADDR_MASK_LSHIFT 0x00000000U
#define i2c_ADDR_MASK_MASK 0x000003ffU
#define i2c_ADDR_MASK 0x000003ffU

// I2C data register
#define i2c_DATA_OFFSET 0x0000000cU
#define i2c_DATA_reserved_0_LSHIFT 0x00000008U
#define i2c_DATA_reserved_0_MASK 0x0000ff00U
#define i2c_DATA_MASK_LSHIFT 0x00000000U
#define i2c_DATA_MASK_MASK 0x000000ffU
#define i2c_DATA_MASK 0x000000ffU

// I2C interrupt status register
#define i2c_ISR_OFFSET 0x00000010U
#define i2c_ISR_reserved_0_LSHIFT 0x0000000aU
#define i2c_ISR_reserved_0_MASK 0x0000fc00U
#define i2c_ISR_IXR_ARB_LOST_LSHIFT 0x00000009U
#define i2c_ISR_IXR_ARB_LOST      0x200U
#define i2c_ISR_IXR_ARB_LOST_MASK 0x00000200U
#define i2c_ISR_reserved_1_LSHIFT 0x00000008U
#define i2c_ISR_reserved_1      0x100U
#define i2c_ISR_reserved_1_MASK 0x00000100U
#define i2c_ISR_IXR_RX_UNF_LSHIFT 0x00000007U
#define i2c_ISR_IXR_RX_UNF       0x80U
#define i2c_ISR_IXR_RX_UNF_MASK 0x00000080U
#define i2c_ISR_IXR_TX_OVR_LSHIFT 0x00000006U
#define i2c_ISR_IXR_TX_OVR       0x40U
#define i2c_ISR_IXR_TX_OVR_MASK 0x00000040U
#define i2c_ISR_IXR_RX_OVR_LSHIFT 0x00000005U
#define i2c_ISR_IXR_RX_OVR       0x20U
#define i2c_ISR_IXR_RX_OVR_MASK 0x00000020U
#define i2c_ISR_IXR_SLV_RDY_LSHIFT 0x00000004U
#define i2c_ISR_IXR_SLV_RDY       0x10U
#define i2c_ISR_IXR_SLV_RDY_MASK 0x00000010U
#define i2c_ISR_IXR_TO_LSHIFT 0x00000003U
#define i2c_ISR_IXR_TO        0x8U
#define i2c_ISR_IXR_TO_MASK 0x00000008U
#define i2c_ISR_IXR_NACK_LSHIFT 0x00000002U
#define i2c_ISR_IXR_NACK        0x4U
#define i2c_ISR_IXR_NACK_MASK 0x00000004U
#define i2c_ISR_IXR_DATA_LSHIFT 0x00000001U
#define i2c_ISR_IXR_DATA        0x2U
#define i2c_ISR_IXR_DATA_MASK 0x00000002U
#define i2c_ISR_IXR_COMP_LSHIFT 0x00000000U
#define i2c_ISR_IXR_COMP        0x1U
#define i2c_ISR_IXR_COMP_MASK 0x00000001U
#define i2c_ISR_MASK 0x000002ffU

// Transfer Size Register
#define i2c_TRANS_SIZE_OFFSET 0x00000014U
#define i2c_TRANS_SIZE_MASK_LSHIFT 0x00000000U
#define i2c_TRANS_SIZE_MASK_MASK 0x000000ffU
#define i2c_TRANS_SIZE_MASK 0x000000ffU

// Slave Monitor Pause Register
#define i2c_SLV_PAUSE_OFFSET 0x00000018U
#define i2c_SLV_PAUSE_reserved_0_LSHIFT 0x00000004U
#define i2c_SLV_PAUSE_reserved_0_MASK 0x000000f0U
#define i2c_SLV_PAUSE_MASK_LSHIFT 0x00000000U
#define i2c_SLV_PAUSE_MASK_MASK 0x0000000fU
#define i2c_SLV_PAUSE_MASK 0x0000000fU

// Time out register
#define i2c_TIME_OUT_OFFSET 0x0000001cU
#define i2c_TIME_OUT_MASK_LSHIFT 0x00000000U
#define i2c_TIME_OUT_MASK_MASK 0x000000ffU
#define i2c_TIME_OUT_MASK 0x000000ffU

// Interrupt mask register
#define i2c_IMR_OFFSET 0x00000020U
#define i2c_IMR_reserved_0_LSHIFT 0x0000000aU
#define i2c_IMR_reserved_0_MASK 0x0000fc00U
#define i2c_IMR_ARB_LOST_LSHIFT 0x00000009U
#define i2c_IMR_ARB_LOST      0x200U
#define i2c_IMR_ARB_LOST_MASK 0x00000200U
#define i2c_IMR_reserved_1_LSHIFT 0x00000008U
#define i2c_IMR_reserved_1      0x100U
#define i2c_IMR_reserved_1_MASK 0x00000100U
#define i2c_IMR_RX_UNF_LSHIFT 0x00000007U
#define i2c_IMR_RX_UNF       0x80U
#define i2c_IMR_RX_UNF_MASK 0x00000080U
#define i2c_IMR_TX_OVR_LSHIFT 0x00000006U
#define i2c_IMR_TX_OVR       0x40U
#define i2c_IMR_TX_OVR_MASK 0x00000040U
#define i2c_IMR_RX_OVR_LSHIFT 0x00000005U
#define i2c_IMR_RX_OVR       0x20U
#define i2c_IMR_RX_OVR_MASK 0x00000020U
#define i2c_IMR_SLV_RDY_LSHIFT 0x00000004U
#define i2c_IMR_SLV_RDY       0x10U
#define i2c_IMR_SLV_RDY_MASK 0x00000010U
#define i2c_IMR_TO_LSHIFT 0x00000003U
#define i2c_IMR_TO        0x8U
#define i2c_IMR_TO_MASK 0x00000008U
#define i2c_IMR_NACK_LSHIFT 0x00000002U
#define i2c_IMR_NACK        0x4U
#define i2c_IMR_NACK_MASK 0x00000004U
#define i2c_IMR_DATA_LSHIFT 0x00000001U
#define i2c_IMR_DATA        0x2U
#define i2c_IMR_DATA_MASK 0x00000002U
#define i2c_IMR_COMP_LSHIFT 0x00000000U
#define i2c_IMR_COMP        0x1U
#define i2c_IMR_COMP_MASK 0x00000001U
#define i2c_IMR_MASK 0x000002ffU

// Interrupt Enable Register
#define i2c_IER_OFFSET 0x00000024U
#define i2c_IER_reserved_0_LSHIFT 0x0000000aU
#define i2c_IER_reserved_0_MASK 0x0000fc00U
#define i2c_IER_ARB_LOST_LSHIFT 0x00000009U
#define i2c_IER_ARB_LOST      0x200U
#define i2c_IER_ARB_LOST_MASK 0x00000200U
#define i2c_IER_reserved_1_LSHIFT 0x00000008U
#define i2c_IER_reserved_1      0x100U
#define i2c_IER_reserved_1_MASK 0x00000100U
#define i2c_IER_RX_UNF_LSHIFT 0x00000007U
#define i2c_IER_RX_UNF       0x80U
#define i2c_IER_RX_UNF_MASK 0x00000080U
#define i2c_IER_TX_OVR_LSHIFT 0x00000006U
#define i2c_IER_TX_OVR       0x40U
#define i2c_IER_TX_OVR_MASK 0x00000040U
#define i2c_IER_RX_OVR_LSHIFT 0x00000005U
#define i2c_IER_RX_OVR       0x20U
#define i2c_IER_RX_OVR_MASK 0x00000020U
#define i2c_IER_SLV_RDY_LSHIFT 0x00000004U
#define i2c_IER_SLV_RDY       0x10U
#define i2c_IER_SLV_RDY_MASK 0x00000010U
#define i2c_IER_TO_LSHIFT 0x00000003U
#define i2c_IER_TO        0x8U
#define i2c_IER_TO_MASK 0x00000008U
#define i2c_IER_NACK_LSHIFT 0x00000002U
#define i2c_IER_NACK        0x4U
#define i2c_IER_NACK_MASK 0x00000004U
#define i2c_IER_DATA_LSHIFT 0x00000001U
#define i2c_IER_DATA        0x2U
#define i2c_IER_DATA_MASK 0x00000002U
#define i2c_IER_COMP_LSHIFT 0x00000000U
#define i2c_IER_COMP        0x1U
#define i2c_IER_COMP_MASK 0x00000001U
#define i2c_IER_MASK 0x000002ffU

// Interrupt Disable Register
#define i2c_IDR_OFFSET 0x00000028U
#define i2c_IDR_reserved_0_LSHIFT 0x0000000aU
#define i2c_IDR_reserved_0_MASK 0x0000fc00U
#define i2c_IDR_ARB_LOST_LSHIFT 0x00000009U
#define i2c_IDR_ARB_LOST      0x200U
#define i2c_IDR_ARB_LOST_MASK 0x00000200U
#define i2c_IDR_reserved_1_LSHIFT 0x00000008U
#define i2c_IDR_reserved_1      0x100U
#define i2c_IDR_reserved_1_MASK 0x00000100U
#define i2c_IDR_RX_UNF_LSHIFT 0x00000007U
#define i2c_IDR_RX_UNF       0x80U
#define i2c_IDR_RX_UNF_MASK 0x00000080U
#define i2c_IDR_TX_OVR_LSHIFT 0x00000006U
#define i2c_IDR_TX_OVR       0x40U
#define i2c_IDR_TX_OVR_MASK 0x00000040U
#define i2c_IDR_RX_OVR_LSHIFT 0x00000005U
#define i2c_IDR_RX_OVR       0x20U
#define i2c_IDR_RX_OVR_MASK 0x00000020U
#define i2c_IDR_SLV_RDY_LSHIFT 0x00000004U
#define i2c_IDR_SLV_RDY       0x10U
#define i2c_IDR_SLV_RDY_MASK 0x00000010U
#define i2c_IDR_TO_LSHIFT 0x00000003U
#define i2c_IDR_TO        0x8U
#define i2c_IDR_TO_MASK 0x00000008U
#define i2c_IDR_NACK_LSHIFT 0x00000002U
#define i2c_IDR_NACK        0x4U
#define i2c_IDR_NACK_MASK 0x00000004U
#define i2c_IDR_DATA_LSHIFT 0x00000001U
#define i2c_IDR_DATA        0x2U
#define i2c_IDR_DATA_MASK 0x00000002U
#define i2c_IDR_COMP_LSHIFT 0x00000000U
#define i2c_IDR_COMP        0x1U
#define i2c_IDR_COMP_MASK 0x00000001U
#define i2c_IDR_MASK 0x000002ffU
