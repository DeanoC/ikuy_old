#pragma once
#include <stdint.h>

// GPIO

// 1 bank of gpio

#define gpio_BASE_ADDR 0xe000a000U

// Registers

// Maskable Output Data (GPIO Bank0, MIO, Lower 16bits)
#define gpio_MASK_DATA_0_LSW_REG 0x0U
#define gpio_MASK_DATA_0_LSW_MASK_LSHIFT 16U
#define gpio_MASK_DATA_0_LSW_MASK_MASK 0xffff0000U
#define gpio_MASK_DATA_0_LSW_DATA_LSHIFT 0U
#define gpio_MASK_DATA_0_LSW_DATA_MASK 0xffffU
#define gpio_MASK_DATA_0_LSW_MASK 0xffffffffU


// Maskable Output Data (GPIO Bank0, MIO, Upper 16bits)
#define gpio_MASK_DATA_0_MSW_REG 0x4U
#define gpio_MASK_DATA_0_MSW_MASK_LSHIFT 16U
#define gpio_MASK_DATA_0_MSW_MASK_MASK 0xffff0000U
#define gpio_MASK_DATA_0_MSW_DATA_LSHIFT 0U
#define gpio_MASK_DATA_0_MSW_DATA_MASK 0xffffU
#define gpio_MASK_DATA_0_MSW_MASK 0xffffffffU


// 0x00000B70 32 rw 0x00000020 DDR IOB DCI Config
#define gpio_MASK_DATA_1_LSW_REG 0x8U
#define gpio_MASK_DATA_1_LSW_MASK_LSHIFT 16U
#define gpio_MASK_DATA_1_LSW_MASK_MASK 0xffff0000U
#define gpio_MASK_DATA_1_LSW_DATA_LSHIFT 0U
#define gpio_MASK_DATA_1_LSW_DATA_MASK 0xffffU
#define gpio_MASK_DATA_1_LSW_MASK 0xffffffffU


// 0x00000B70 32 rw 0x00000020 DDR IOB DCI Config
#define gpio_MASK_DATA_1_MSW_REG 0xcU
#define gpio_MASK_DATA_1_MSW_MASK_LSHIFT 16U
#define gpio_MASK_DATA_1_MSW_MASK_MASK 0xffff0000U
#define gpio_MASK_DATA_1_MSW_DATA_LSHIFT 0U
#define gpio_MASK_DATA_1_MSW_DATA_MASK 0xffffU
#define gpio_MASK_DATA_1_MSW_MASK 0xffffffffU


// Maskable Output Data (GPIO Bank2, EMIO, Lower 16bits)
#define gpio_MASK_DATA_2_LSW_REG 0x10U
#define gpio_MASK_DATA_2_LSW_MASK_LSHIFT 16U
#define gpio_MASK_DATA_2_LSW_MASK_MASK 0xffff0000U
#define gpio_MASK_DATA_2_LSW_DATA_LSHIFT 0U
#define gpio_MASK_DATA_2_LSW_DATA_MASK 0xffffU
#define gpio_MASK_DATA_2_LSW_MASK 0xffffffffU


// Maskable Output Data (GPIO Bank2, EMIO, Upper 16bits)
#define gpio_MASK_DATA_2_MSW_REG 0x14U
#define gpio_MASK_DATA_2_MSW_MASK_LSHIFT 16U
#define gpio_MASK_DATA_2_MSW_MASK_MASK 0xffff0000U
#define gpio_MASK_DATA_2_MSW_DATA_LSHIFT 0U
#define gpio_MASK_DATA_2_MSW_DATA_MASK 0xffffU
#define gpio_MASK_DATA_2_MSW_MASK 0xffffffffU


// Maskable Output Data (GPIO Bank3, EMIO, Lower 16bits)
#define gpio_MASK_DATA_3_LSW_REG 0x18U
#define gpio_MASK_DATA_3_LSW_MASK_LSHIFT 16U
#define gpio_MASK_DATA_3_LSW_MASK_MASK 0xffff0000U
#define gpio_MASK_DATA_3_LSW_DATA_LSHIFT 0U
#define gpio_MASK_DATA_3_LSW_DATA_MASK 0xffffU
#define gpio_MASK_DATA_3_LSW_MASK 0xffffffffU


// Maskable Output Data (GPIO Bank3, EMIO, Upper 16bits)
#define gpio_MASK_DATA_3_MSW_REG 0x1cU
#define gpio_MASK_DATA_3_MSW_MASK_LSHIFT 16U
#define gpio_MASK_DATA_3_MSW_MASK_MASK 0xffff0000U
#define gpio_MASK_DATA_3_MSW_DATA_LSHIFT 0U
#define gpio_MASK_DATA_3_MSW_DATA_MASK 0xffffU
#define gpio_MASK_DATA_3_MSW_MASK 0xffffffffU


// Data (GPIO Bank3, EMIO, Upper 16bits)
#define gpio_DATA_0_REG 0x40U
#define gpio_DATA_0_DATA_LSHIFT 0U
#define gpio_DATA_0_DATA_MASK 0x0U
#define gpio_DATA_0_MASK 0x0U


// Data (GPIO Bank3, EMIO, Upper 16bits)
#define gpio_DATA_1_REG 0x44U
#define gpio_DATA_1_DATA_LSHIFT 0U
#define gpio_DATA_1_DATA_MASK 0x0U
#define gpio_DATA_1_MASK 0x0U


// Output Data (GPIO Bank2, EMIO)
#define gpio_DATA_2_REG 0x48U
#define gpio_DATA_2_DATA_LSHIFT 0U
#define gpio_DATA_2_DATA_MASK 0x0U
#define gpio_DATA_2_MASK 0x0U


// Output Data (GPIO Bank3, EMIO)
#define gpio_DATA_3_REG 0x4cU
#define gpio_DATA_3_DATA_LSHIFT 0U
#define gpio_DATA_3_DATA_MASK 0x0U
#define gpio_DATA_3_MASK 0x0U


// EMIO)
#define gpio_DATA_0_RO_REG 0x60U
#define gpio_DATA_0_RO_DATA_LSHIFT 0U
#define gpio_DATA_0_RO_DATA_MASK 0x0U
#define gpio_DATA_0_RO_MASK 0x0U


// EMIO)
#define gpio_DATA_1_RO_REG 0x64U
#define gpio_DATA_1_RO_DATA_LSHIFT 0U
#define gpio_DATA_1_RO_DATA_MASK 0x0U
#define gpio_DATA_1_RO_MASK 0x0U


// Input Data (GPIO Bank2, EMIO)
#define gpio_DATA_2_RO_REG 0x68U
#define gpio_DATA_2_RO_DATA_LSHIFT 0U
#define gpio_DATA_2_RO_DATA_MASK 0x0U
#define gpio_DATA_2_RO_MASK 0x0U


// Input Data (GPIO Bank3, EMIO)
#define gpio_DATA_3_RO_REG 0x6cU
#define gpio_DATA_3_RO_DATA_LSHIFT 0U
#define gpio_DATA_3_RO_DATA_MASK 0x0U
#define gpio_DATA_3_RO_MASK 0x0U


// Direction mode (GPIO Bank0, MIO)
#define gpio_DIRM_0_REG 0x204U
#define gpio_DIRM_0_DIRECTION_0_LSHIFT 0U
#define gpio_DIRM_0_DIRECTION_0_MASK 0x0U
#define gpio_DIRM_0_MASK 0x0U


// Output enable (GPIO Bank0, EMIO)
#define gpio_OEN_0_REG 0x208U
#define gpio_OEN_0_OP_ENABLE_LSHIFT 0U
#define gpio_OEN_0_OP_ENABLE_MASK 0x0U
#define gpio_OEN_0_MASK 0x0U


// Interrupt Mask Status (GPIO Bank0, MIO)
#define gpio_INT_MASK_0_REG 0x20cU
#define gpio_INT_MASK_0_INT_MASK_LSHIFT 0U
#define gpio_INT_MASK_0_INT_MASK_MASK 0x0U
#define gpio_INT_MASK_0_MASK 0x0U


// Interrupt Enable/Unmask (GPIO Bank0, MIO)
#define gpio_INT_EN_0_REG 0x210U
#define gpio_INT_EN_0_INT_ENABLE_LSHIFT 0U
#define gpio_INT_EN_0_INT_ENABLE_MASK 0x0U
#define gpio_INT_EN_0_MASK 0x0U


// Interrupt Disable/Mask (GPIO Bank0, MIO)
#define gpio_INT_DIS_0_REG 0x214U
#define gpio_INT_DIS_0_INT_DISABLE_LSHIFT 0U
#define gpio_INT_DIS_0_INT_DISABLE_MASK 0x0U
#define gpio_INT_DIS_0_MASK 0x0U


// Interrupt Status (GPIO Bank0, MIO)
#define gpio_INT_STAT_0_REG 0x218U
#define gpio_INT_STAT_0_INT_STATUS_LSHIFT 0U
#define gpio_INT_STAT_0_INT_STATUS_MASK 0x0U
#define gpio_INT_STAT_0_MASK 0x0U


// Interrupt Type (GPIO Bank0, MIO)
#define gpio_INT_TYPE_0_REG 0x21cU
#define gpio_INT_TYPE_0_INT_TYPE_LSHIFT 0U
#define gpio_INT_TYPE_0_INT_TYPE_MASK 0x0U
#define gpio_INT_TYPE_0_MASK 0x0U


// Interrupt Polarity (GPIO Bank0, MIO)
#define gpio_INT_POLARITY_0_REG 0x220U
#define gpio_INT_POLARITY_0_INT_POL_LSHIFT 0U
#define gpio_INT_POLARITY_0_INT_POL_MASK 0x0U
#define gpio_INT_POLARITY_0_MASK 0x0U


// Interrupt Any Edge Sensitive (GPIO Bank0, MIO)
#define gpio_INT_ANY_0_REG 0x224U
#define gpio_INT_ANY_0_INT_ON_ANY_LSHIFT 0U
#define gpio_INT_ANY_0_INT_ON_ANY_MASK 0x0U
#define gpio_INT_ANY_0_MASK 0x0U


// Direction mode (GPIO Bank1, MIO)
#define gpio_DIRM_1_REG 0x244U
#define gpio_DIRM_1_DIRECTION_0_LSHIFT 0U
#define gpio_DIRM_1_DIRECTION_0_MASK 0x0U
#define gpio_DIRM_1_MASK 0x0U


// Output enable (GPIO Bank1, MIO)
#define gpio_OEN_1_REG 0x248U
#define gpio_OEN_1_OP_ENABLE_LSHIFT 0U
#define gpio_OEN_1_OP_ENABLE_MASK 0x0U
#define gpio_OEN_1_MASK 0x0U


// Interrupt Mask Status (GPIO Bank1, MIO)
#define gpio_INT_MASK_1_REG 0x24cU
#define gpio_INT_MASK_1_INT_MASK_LSHIFT 0U
#define gpio_INT_MASK_1_INT_MASK_MASK 0x0U
#define gpio_INT_MASK_1_MASK 0x0U


// Interrupt Enable/Unmask (GPIO Bank1, MIO)
#define gpio_INT_EN_1_REG 0x250U
#define gpio_INT_EN_1_INT_ENABLE_LSHIFT 0U
#define gpio_INT_EN_1_INT_ENABLE_MASK 0x0U
#define gpio_INT_EN_1_MASK 0x0U


// Interrupt Disable/Mask (GPIO Bank1, MIO)
#define gpio_INT_DIS_1_REG 0x254U
#define gpio_INT_DIS_1_INT_DISABLE_LSHIFT 0U
#define gpio_INT_DIS_1_INT_DISABLE_MASK 0x0U
#define gpio_INT_DIS_1_MASK 0x0U


// Interrupt Status (GPIO Bank1, MIO)
#define gpio_INT_STAT_1_REG 0x258U
#define gpio_INT_STAT_1_INT_STATUS_LSHIFT 0U
#define gpio_INT_STAT_1_INT_STATUS_MASK 0x0U
#define gpio_INT_STAT_1_MASK 0x0U


// Interrupt Type (GPIO Bank1, MIO)
#define gpio_INT_TYPE_1_REG 0x25cU
#define gpio_INT_TYPE_1_INT_TYPE_LSHIFT 0U
#define gpio_INT_TYPE_1_INT_TYPE_MASK 0x0U
#define gpio_INT_TYPE_1_MASK 0x0U


// Interrupt Polarity (GPIO Bank1, MIO)
#define gpio_INT_POLARITY_1_REG 0x260U
#define gpio_INT_POLARITY_1_INT_POL_LSHIFT 0U
#define gpio_INT_POLARITY_1_INT_POL_MASK 0x0U
#define gpio_INT_POLARITY_1_MASK 0x0U


// Interrupt Any Edge Sensitive (GPIO Bank1, MIO)
#define gpio_INT_ANY_1_REG 0x264U
#define gpio_INT_ANY_1_INT_ON_ANY_LSHIFT 0U
#define gpio_INT_ANY_1_INT_ON_ANY_MASK 0x0U
#define gpio_INT_ANY_1_MASK 0x0U


// Direction mode (GPIO Bank2, EMIO)
#define gpio_DIRM_2_REG 0x284U
#define gpio_DIRM_2_DIRECTION_0_LSHIFT 0U
#define gpio_DIRM_2_DIRECTION_0_MASK 0x0U
#define gpio_DIRM_2_MASK 0x0U


// Output enable (GPIO Bank2, EMIO)
#define gpio_OEN_2_REG 0x288U
#define gpio_OEN_2_OP_ENABLE_LSHIFT 0U
#define gpio_OEN_2_OP_ENABLE_MASK 0x0U
#define gpio_OEN_2_MASK 0x0U


// Interrupt Mask Status (GPIO Bank2, EMIO)
#define gpio_INT_MASK_2_REG 0x28cU
#define gpio_INT_MASK_2_INT_MASK_LSHIFT 0U
#define gpio_INT_MASK_2_INT_MASK_MASK 0x0U
#define gpio_INT_MASK_2_MASK 0x0U


// Interrupt Enable/Unmask (GPIO Bank2, EMIO)
#define gpio_INT_EN_2_REG 0x290U
#define gpio_INT_EN_2_INT_ENABLE_LSHIFT 0U
#define gpio_INT_EN_2_INT_ENABLE_MASK 0x0U
#define gpio_INT_EN_2_MASK 0x0U


// Interrupt Disable/Mask (GPIO Bank2, EMIO)
#define gpio_INT_DIS_2_REG 0x294U
#define gpio_INT_DIS_2_INT_DISABLE_LSHIFT 0U
#define gpio_INT_DIS_2_INT_DISABLE_MASK 0x0U
#define gpio_INT_DIS_2_MASK 0x0U


// Interrup
#define gpio_INT_STAT_2_REG 0x298U
#define gpio_INT_STAT_2_INT_STATUS_LSHIFT 0U
#define gpio_INT_STAT_2_INT_STATUS_MASK 0x0U
#define gpio_INT_STAT_2_MASK 0x0U


// Interrupt Type (GPIO Bank2, EMIO)
#define gpio_INT_TYPE_2_REG 0x29cU
#define gpio_INT_TYPE_2_INT_TYPE_LSHIFT 0U
#define gpio_INT_TYPE_2_INT_TYPE_MASK 0x0U
#define gpio_INT_TYPE_2_MASK 0x0U


// Interrupt Polarity (GPIO Bank2, EMIO)
#define gpio_INT_POLARITY_2_REG 0x2a0U
#define gpio_INT_POLARITY_2_INT_POL_LSHIFT 0U
#define gpio_INT_POLARITY_2_INT_POL_MASK 0x0U
#define gpio_INT_POLARITY_2_MASK 0x0U


// Interrupt Any Edge Sensitive (GPIO Bank2, EMIO)
#define gpio_INT_ANY_2_REG 0x2a4U
#define gpio_INT_ANY_2_INT_ON_ANY_LSHIFT 0U
#define gpio_INT_ANY_2_INT_ON_ANY_MASK 0x0U
#define gpio_INT_ANY_2_MASK 0x0U


// Direction mode (GPIO Bank3, EMIO)
#define gpio_DIRM_3_REG 0x2c4U
#define gpio_DIRM_3_DIRECTION_0_LSHIFT 0U
#define gpio_DIRM_3_DIRECTION_0_MASK 0x0U
#define gpio_DIRM_3_MASK 0x0U


// Output enable (GPIO Bank3, EMIO)
#define gpio_OEN_3_REG 0x2c8U
#define gpio_OEN_3_OP_ENABLE_LSHIFT 0U
#define gpio_OEN_3_OP_ENABLE_MASK 0x0U
#define gpio_OEN_3_MASK 0x0U


// Interrupt Mask Status (GPIO Bank3, EMIO)
#define gpio_INT_MASK_3_REG 0x2ccU
#define gpio_INT_MASK_3_INT_MASK_LSHIFT 0U
#define gpio_INT_MASK_3_INT_MASK_MASK 0x0U
#define gpio_INT_MASK_3_MASK 0x0U


// Interrupt Enable/Unmask (GPIO Bank3, EMIO)
#define gpio_INT_EN_3_REG 0x2d0U
#define gpio_INT_EN_3_INT_ENABLE_LSHIFT 0U
#define gpio_INT_EN_3_INT_ENABLE_MASK 0x0U
#define gpio_INT_EN_3_MASK 0x0U


// Interrupt Disable/Mask (GPIO Bank3, EMIO)
#define gpio_INT_DIS_3_REG 0x2d4U
#define gpio_INT_DIS_3_INT_DISABLE_LSHIFT 0U
#define gpio_INT_DIS_3_INT_DISABLE_MASK 0x0U
#define gpio_INT_DIS_3_MASK 0x0U


// Interrupt Status (GPIO Bank3, EMIO)
#define gpio_INT_STAT_3_REG 0x2d8U
#define gpio_INT_STAT_3_INT_STATUS_LSHIFT 0U
#define gpio_INT_STAT_3_INT_STATUS_MASK 0x0U
#define gpio_INT_STAT_3_MASK 0x0U


// Interrupt Type (GPIO Bank3, EMIO)
#define gpio_INT_TYPE_3_REG 0x2dcU
#define gpio_INT_TYPE_3_INT_TYPE_LSHIFT 0U
#define gpio_INT_TYPE_3_INT_TYPE_MASK 0x0U
#define gpio_INT_TYPE_3_MASK 0x0U


// Interrupt Polarity (GPIO Bank3, EMIO)
#define gpio_INT_POLARITY_3_REG 0x2e0U
#define gpio_INT_POLARITY_3_INT_POL_LSHIFT 0U
#define gpio_INT_POLARITY_3_INT_POL_MASK 0x0U
#define gpio_INT_POLARITY_3_MASK 0x0U


// Interrupt Any Edge S
#define gpio_INT_ANY_3_REG 0x2e4U
#define gpio_INT_ANY_3_INT_ON_ANY_LSHIFT 0U
#define gpio_INT_ANY_3_INT_ON_ANY_MASK 0x0U
#define gpio_INT_ANY_3_MASK 0x0U


