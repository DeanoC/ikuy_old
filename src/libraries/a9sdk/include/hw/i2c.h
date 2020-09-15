#pragma once
// Copyright Deano Calver
// SPDX-License-Identifier: MIT

#include <stdint.h>

// Inter Integrated Circuit(I2C)

// 2 banks of i2c

#define i2c0_BASE_ADDR 0xe0004000U
#define i2c1_BASE_ADDR 0xe0005000U

// Registers

// Control Register
#define i2c_I2CPS_CR_REG 0x0U
#define i2c_I2CPS_CR_DIV_A_LSHIFT 14U
#define i2c_I2CPS_CR_DIV_A_MASK 0xc000U
#define i2c_I2CPS_CR_DIV_B_LSHIFT 8U
#define i2c_I2CPS_CR_DIV_B_MASK 0x3f00U
#define i2c_I2CPS_CR_RESERVED_0_LSHIFT 7U
#define i2c_I2CPS_CR_RESERVED_0 0x80U
#define i2c_I2CPS_CR_RESERVED_0_MASK 0x80U
#define i2c_I2CPS_CR_CLR_FIFO_LSHIFT 6U
#define i2c_I2CPS_CR_CLR_FIFO 0x40U
#define i2c_I2CPS_CR_CLR_FIFO_MASK 0x40U
#define i2c_I2CPS_CR_SLVMON_LSHIFT 5U
#define i2c_I2CPS_CR_SLVMON 0x20U
#define i2c_I2CPS_CR_SLVMON_MASK 0x20U
#define i2c_I2CPS_CR_HOLD_LSHIFT 4U
#define i2c_I2CPS_CR_HOLD 0x10U
#define i2c_I2CPS_CR_HOLD_MASK 0x10U
#define i2c_I2CPS_CR_ACKEN_LSHIFT 3U
#define i2c_I2CPS_CR_ACKEN 0x8U
#define i2c_I2CPS_CR_ACKEN_MASK 0x8U
#define i2c_I2CPS_CR_NEA_LSHIFT 2U
#define i2c_I2CPS_CR_NEA 0x4U
#define i2c_I2CPS_CR_NEA_MASK 0x4U
#define i2c_I2CPS_CR_MS_LSHIFT 1U
#define i2c_I2CPS_CR_MS 0x2U
#define i2c_I2CPS_CR_MS_MASK 0x2U
#define i2c_I2CPS_CR_RD_WR_LSHIFT 0U
#define i2c_I2CPS_CR_RD_WR 0x1U
#define i2c_I2CPS_CR_RD_WR_MASK 0x1U
#define i2c_I2CPS_CR_MASK 0xff7fU


// Status register
#define i2c_I2CPS_SR_REG 0x4U
#define i2c_I2CPS_SR_RESERVED_0_LSHIFT 9U
#define i2c_I2CPS_SR_RESERVED_0_MASK 0xfe00U
#define i2c_I2CPS_SR_BA_LSHIFT 8U
#define i2c_I2CPS_SR_BA 0x100U
#define i2c_I2CPS_SR_BA_MASK 0x100U
#define i2c_I2CPS_SR_RXOVF_LSHIFT 7U
#define i2c_I2CPS_SR_RXOVF 0x80U
#define i2c_I2CPS_SR_RXOVF_MASK 0x80U
#define i2c_I2CPS_SR_TXDV_LSHIFT 6U
#define i2c_I2CPS_SR_TXDV 0x40U
#define i2c_I2CPS_SR_TXDV_MASK 0x40U
#define i2c_I2CPS_SR_RXDV_LSHIFT 5U
#define i2c_I2CPS_SR_RXDV 0x20U
#define i2c_I2CPS_SR_RXDV_MASK 0x20U
#define i2c_I2CPS_SR_RESERVED_1_LSHIFT 4U
#define i2c_I2CPS_SR_RESERVED_1 0x10U
#define i2c_I2CPS_SR_RESERVED_1_MASK 0x10U
#define i2c_I2CPS_SR_RXRW_LSHIFT 3U
#define i2c_I2CPS_SR_RXRW 0x8U
#define i2c_I2CPS_SR_RXRW_MASK 0x8U
#define i2c_I2CPS_SR_RESERVED_2_LSHIFT 0U
#define i2c_I2CPS_SR_RESERVED_2_MASK 0x7U
#define i2c_I2CPS_SR_MASK 0x1e8U


// I2C Address register
#define i2c_I2CPS_ADDR_REG 0x8U
#define i2c_I2CPS_ADDR_RESERVED_0_LSHIFT 10U
#define i2c_I2CPS_ADDR_RESERVED_0_MASK 0xfc00U
#define i2c_I2CPS_ADDR_MASK_LSHIFT 0U
#define i2c_I2CPS_ADDR_MASK_MASK 0x3ffU
#define i2c_I2CPS_ADDR_MASK 0x3ffU


// I2C data register
#define i2c_I2CPS_DATA_REG 0xcU
#define i2c_I2CPS_DATA_RESERVED_0_LSHIFT 8U
#define i2c_I2CPS_DATA_RESERVED_0_MASK 0xff00U
#define i2c_I2CPS_DATA_MASK_LSHIFT 0U
#define i2c_I2CPS_DATA_MASK_MASK 0xffU
#define i2c_I2CPS_DATA_MASK 0xffU


// I2C interrupt status register
#define i2c_I2CPS_ISR_REG 0x10U
#define i2c_I2CPS_ISR_RESERVED_0_LSHIFT 10U
#define i2c_I2CPS_ISR_RESERVED_0_MASK 0xfc00U
#define i2c_I2CPS_ISR_IXR_ARB_LOST_LSHIFT 9U
#define i2c_I2CPS_ISR_IXR_ARB_LOST 0x200U
#define i2c_I2CPS_ISR_IXR_ARB_LOST_MASK 0x200U
#define i2c_I2CPS_ISR_RESERVED_1_LSHIFT 8U
#define i2c_I2CPS_ISR_RESERVED_1 0x100U
#define i2c_I2CPS_ISR_RESERVED_1_MASK 0x100U
#define i2c_I2CPS_ISR_IXR_RX_UNF_LSHIFT 7U
#define i2c_I2CPS_ISR_IXR_RX_UNF 0x80U
#define i2c_I2CPS_ISR_IXR_RX_UNF_MASK 0x80U
#define i2c_I2CPS_ISR_IXR_TX_OVR_LSHIFT 6U
#define i2c_I2CPS_ISR_IXR_TX_OVR 0x40U
#define i2c_I2CPS_ISR_IXR_TX_OVR_MASK 0x40U
#define i2c_I2CPS_ISR_IXR_RX_OVR_LSHIFT 5U
#define i2c_I2CPS_ISR_IXR_RX_OVR 0x20U
#define i2c_I2CPS_ISR_IXR_RX_OVR_MASK 0x20U
#define i2c_I2CPS_ISR_IXR_SLV_RDY_LSHIFT 4U
#define i2c_I2CPS_ISR_IXR_SLV_RDY 0x10U
#define i2c_I2CPS_ISR_IXR_SLV_RDY_MASK 0x10U
#define i2c_I2CPS_ISR_IXR_TO_LSHIFT 3U
#define i2c_I2CPS_ISR_IXR_TO 0x8U
#define i2c_I2CPS_ISR_IXR_TO_MASK 0x8U
#define i2c_I2CPS_ISR_IXR_NACK_LSHIFT 2U
#define i2c_I2CPS_ISR_IXR_NACK 0x4U
#define i2c_I2CPS_ISR_IXR_NACK_MASK 0x4U
#define i2c_I2CPS_ISR_IXR_DATA_LSHIFT 1U
#define i2c_I2CPS_ISR_IXR_DATA 0x2U
#define i2c_I2CPS_ISR_IXR_DATA_MASK 0x2U
#define i2c_I2CPS_ISR_IXR_COMP_LSHIFT 0U
#define i2c_I2CPS_ISR_IXR_COMP 0x1U
#define i2c_I2CPS_ISR_IXR_COMP_MASK 0x1U
#define i2c_I2CPS_ISR_MASK 0x2ffU


// Transfer Size Register
#define i2c_I2CPS_TRANS_SIZE_REG 0x14U
#define i2c_I2CPS_TRANS_SIZE_MASK_LSHIFT 0U
#define i2c_I2CPS_TRANS_SIZE_MASK_MASK 0xffU
#define i2c_I2CPS_TRANS_SIZE_MASK 0xffU


// Slave Monitor Pause Register
#define i2c_I2CPS_SLV_PAUSE_REG 0x18U
#define i2c_I2CPS_SLV_PAUSE_RESERVED_0_LSHIFT 4U
#define i2c_I2CPS_SLV_PAUSE_RESERVED_0_MASK 0xf0U
#define i2c_I2CPS_SLV_PAUSE_MASK_LSHIFT 0U
#define i2c_I2CPS_SLV_PAUSE_MASK_MASK 0xfU
#define i2c_I2CPS_SLV_PAUSE_MASK 0xfU


// Time out register
#define i2c_I2CPS_TIME_OUT_REG 0x1cU
#define i2c_I2CPS_TIME_OUT_MASK_LSHIFT 0U
#define i2c_I2CPS_TIME_OUT_MASK_MASK 0xffU
#define i2c_I2CPS_TIME_OUT_MASK 0xffU


// Interrupt mask register
#define i2c_I2CPS_IMR_REG 0x20U
#define i2c_I2CPS_IMR_RESERVED_0_LSHIFT 10U
#define i2c_I2CPS_IMR_RESERVED_0_MASK 0xfc00U
#define i2c_I2CPS_IMR_ARB_LOST_LSHIFT 9U
#define i2c_I2CPS_IMR_ARB_LOST 0x200U
#define i2c_I2CPS_IMR_ARB_LOST_MASK 0x200U
#define i2c_I2CPS_IMR_RESERVED_1_LSHIFT 8U
#define i2c_I2CPS_IMR_RESERVED_1 0x100U
#define i2c_I2CPS_IMR_RESERVED_1_MASK 0x100U
#define i2c_I2CPS_IMR_RX_UNF_LSHIFT 7U
#define i2c_I2CPS_IMR_RX_UNF 0x80U
#define i2c_I2CPS_IMR_RX_UNF_MASK 0x80U
#define i2c_I2CPS_IMR_TX_OVR_LSHIFT 6U
#define i2c_I2CPS_IMR_TX_OVR 0x40U
#define i2c_I2CPS_IMR_TX_OVR_MASK 0x40U
#define i2c_I2CPS_IMR_RX_OVR_LSHIFT 5U
#define i2c_I2CPS_IMR_RX_OVR 0x20U
#define i2c_I2CPS_IMR_RX_OVR_MASK 0x20U
#define i2c_I2CPS_IMR_SLV_RDY_LSHIFT 4U
#define i2c_I2CPS_IMR_SLV_RDY 0x10U
#define i2c_I2CPS_IMR_SLV_RDY_MASK 0x10U
#define i2c_I2CPS_IMR_TO_LSHIFT 3U
#define i2c_I2CPS_IMR_TO 0x8U
#define i2c_I2CPS_IMR_TO_MASK 0x8U
#define i2c_I2CPS_IMR_NACK_LSHIFT 2U
#define i2c_I2CPS_IMR_NACK 0x4U
#define i2c_I2CPS_IMR_NACK_MASK 0x4U
#define i2c_I2CPS_IMR_DATA_LSHIFT 1U
#define i2c_I2CPS_IMR_DATA 0x2U
#define i2c_I2CPS_IMR_DATA_MASK 0x2U
#define i2c_I2CPS_IMR_COMP_LSHIFT 0U
#define i2c_I2CPS_IMR_COMP 0x1U
#define i2c_I2CPS_IMR_COMP_MASK 0x1U
#define i2c_I2CPS_IMR_MASK 0x2ffU


// Interrupt Enable Register
#define i2c_I2CPS_IER_REG 0x24U
#define i2c_I2CPS_IER_RESERVED_0_LSHIFT 10U
#define i2c_I2CPS_IER_RESERVED_0_MASK 0xfc00U
#define i2c_I2CPS_IER_ARB_LOST_LSHIFT 9U
#define i2c_I2CPS_IER_ARB_LOST 0x200U
#define i2c_I2CPS_IER_ARB_LOST_MASK 0x200U
#define i2c_I2CPS_IER_RESERVED_1_LSHIFT 8U
#define i2c_I2CPS_IER_RESERVED_1 0x100U
#define i2c_I2CPS_IER_RESERVED_1_MASK 0x100U
#define i2c_I2CPS_IER_RX_UNF_LSHIFT 7U
#define i2c_I2CPS_IER_RX_UNF 0x80U
#define i2c_I2CPS_IER_RX_UNF_MASK 0x80U
#define i2c_I2CPS_IER_TX_OVR_LSHIFT 6U
#define i2c_I2CPS_IER_TX_OVR 0x40U
#define i2c_I2CPS_IER_TX_OVR_MASK 0x40U
#define i2c_I2CPS_IER_RX_OVR_LSHIFT 5U
#define i2c_I2CPS_IER_RX_OVR 0x20U
#define i2c_I2CPS_IER_RX_OVR_MASK 0x20U
#define i2c_I2CPS_IER_SLV_RDY_LSHIFT 4U
#define i2c_I2CPS_IER_SLV_RDY 0x10U
#define i2c_I2CPS_IER_SLV_RDY_MASK 0x10U
#define i2c_I2CPS_IER_TO_LSHIFT 3U
#define i2c_I2CPS_IER_TO 0x8U
#define i2c_I2CPS_IER_TO_MASK 0x8U
#define i2c_I2CPS_IER_NACK_LSHIFT 2U
#define i2c_I2CPS_IER_NACK 0x4U
#define i2c_I2CPS_IER_NACK_MASK 0x4U
#define i2c_I2CPS_IER_DATA_LSHIFT 1U
#define i2c_I2CPS_IER_DATA 0x2U
#define i2c_I2CPS_IER_DATA_MASK 0x2U
#define i2c_I2CPS_IER_COMP_LSHIFT 0U
#define i2c_I2CPS_IER_COMP 0x1U
#define i2c_I2CPS_IER_COMP_MASK 0x1U
#define i2c_I2CPS_IER_MASK 0x2ffU


// Interrupt Disable Register
#define i2c_I2CPS_IDR_REG 0x28U
#define i2c_I2CPS_IDR_RESERVED_0_LSHIFT 10U
#define i2c_I2CPS_IDR_RESERVED_0_MASK 0xfc00U
#define i2c_I2CPS_IDR_ARB_LOST_LSHIFT 9U
#define i2c_I2CPS_IDR_ARB_LOST 0x200U
#define i2c_I2CPS_IDR_ARB_LOST_MASK 0x200U
#define i2c_I2CPS_IDR_RESERVED_1_LSHIFT 8U
#define i2c_I2CPS_IDR_RESERVED_1 0x100U
#define i2c_I2CPS_IDR_RESERVED_1_MASK 0x100U
#define i2c_I2CPS_IDR_RX_UNF_LSHIFT 7U
#define i2c_I2CPS_IDR_RX_UNF 0x80U
#define i2c_I2CPS_IDR_RX_UNF_MASK 0x80U
#define i2c_I2CPS_IDR_TX_OVR_LSHIFT 6U
#define i2c_I2CPS_IDR_TX_OVR 0x40U
#define i2c_I2CPS_IDR_TX_OVR_MASK 0x40U
#define i2c_I2CPS_IDR_RX_OVR_LSHIFT 5U
#define i2c_I2CPS_IDR_RX_OVR 0x20U
#define i2c_I2CPS_IDR_RX_OVR_MASK 0x20U
#define i2c_I2CPS_IDR_SLV_RDY_LSHIFT 4U
#define i2c_I2CPS_IDR_SLV_RDY 0x10U
#define i2c_I2CPS_IDR_SLV_RDY_MASK 0x10U
#define i2c_I2CPS_IDR_TO_LSHIFT 3U
#define i2c_I2CPS_IDR_TO 0x8U
#define i2c_I2CPS_IDR_TO_MASK 0x8U
#define i2c_I2CPS_IDR_NACK_LSHIFT 2U
#define i2c_I2CPS_IDR_NACK 0x4U
#define i2c_I2CPS_IDR_NACK_MASK 0x4U
#define i2c_I2CPS_IDR_DATA_LSHIFT 1U
#define i2c_I2CPS_IDR_DATA 0x2U
#define i2c_I2CPS_IDR_DATA_MASK 0x2U
#define i2c_I2CPS_IDR_COMP_LSHIFT 0U
#define i2c_I2CPS_IDR_COMP 0x1U
#define i2c_I2CPS_IDR_COMP_MASK 0x1U
#define i2c_I2CPS_IDR_MASK 0x2ffU

