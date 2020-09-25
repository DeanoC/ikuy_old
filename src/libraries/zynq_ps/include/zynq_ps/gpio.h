#pragma once
// Copyright Deano Calver
// SPDX-License-Identifier: MIT
// General Purpose Input/Output
// Auto-generated on Fri Sep 25 10:29:41 EEST 2020

#include <stdint.h>

// 1 banks of gpio chips
#define gpio_BASE_ADDR 0xe000a000U

// Maskable Output Data (GPIO Bank0, MIO, Lower 16bits)
#define gpio_MASK_DATA_0_LSW_OFFSET 0x00000000U
#define gpio_MASK_DATA_0_LSW_MASK_LSHIFT 0x00000010U
#define gpio_MASK_DATA_0_LSW_MASK_MASK 0xffff0000U
#define gpio_MASK_DATA_0_LSW_DATA_LSHIFT 0x00000000U
#define gpio_MASK_DATA_0_LSW_DATA_MASK 0x0000ffffU
#define gpio_MASK_DATA_0_LSW_MASK 0xffffffffU

// Maskable Output Data (GPIO Bank0, MIO, Upper 16bits)
#define gpio_MASK_DATA_0_MSW_OFFSET 0x00000004U
#define gpio_MASK_DATA_0_MSW_MASK_LSHIFT 0x00000010U
#define gpio_MASK_DATA_0_MSW_MASK_MASK 0xffff0000U
#define gpio_MASK_DATA_0_MSW_DATA_LSHIFT 0x00000000U
#define gpio_MASK_DATA_0_MSW_DATA_MASK 0x0000ffffU
#define gpio_MASK_DATA_0_MSW_MASK 0xffffffffU

// Maskable Output Data (GPIO Bank1, MIO, Lower 16bits)
#define gpio_MASK_DATA_1_LSW_OFFSET 0x00000008U
#define gpio_MASK_DATA_1_LSW_MASK_LSHIFT 0x00000010U
#define gpio_MASK_DATA_1_LSW_MASK_MASK 0xffff0000U
#define gpio_MASK_DATA_1_LSW_DATA_LSHIFT 0x00000000U
#define gpio_MASK_DATA_1_LSW_DATA_MASK 0x0000ffffU
#define gpio_MASK_DATA_1_LSW_MASK 0xffffffffU

// Maskable Output Data (GPIO Bank1, MIO, Upper 6bits)
#define gpio_MASK_DATA_1_MSW_OFFSET 0x0000000cU
#define gpio_MASK_DATA_1_MSW_MASK_LSHIFT 0x00000010U
#define gpio_MASK_DATA_1_MSW_MASK_MASK 0xffff0000U
#define gpio_MASK_DATA_1_MSW_DATA_LSHIFT 0x00000000U
#define gpio_MASK_DATA_1_MSW_DATA_MASK 0x0000ffffU
#define gpio_MASK_DATA_1_MSW_MASK 0xffffffffU

// Maskable Output Data (GPIO Bank2, EMIO, Lower 16bits)
#define gpio_MASK_DATA_2_LSW_OFFSET 0x00000010U
#define gpio_MASK_DATA_2_LSW_MASK_LSHIFT 0x00000010U
#define gpio_MASK_DATA_2_LSW_MASK_MASK 0xffff0000U
#define gpio_MASK_DATA_2_LSW_DATA_LSHIFT 0x00000000U
#define gpio_MASK_DATA_2_LSW_DATA_MASK 0x0000ffffU
#define gpio_MASK_DATA_2_LSW_MASK 0xffffffffU

// Maskable Output Data (GPIO Bank2, EMIO, Upper 16bits)
#define gpio_MASK_DATA_2_MSW_OFFSET 0x00000014U
#define gpio_MASK_DATA_2_MSW_MASK_LSHIFT 0x00000010U
#define gpio_MASK_DATA_2_MSW_MASK_MASK 0xffff0000U
#define gpio_MASK_DATA_2_MSW_DATA_LSHIFT 0x00000000U
#define gpio_MASK_DATA_2_MSW_DATA_MASK 0x0000ffffU
#define gpio_MASK_DATA_2_MSW_MASK 0xffffffffU

// Maskable Output Data (GPIO Bank3, EMIO, Lower 16bits)
#define gpio_MASK_DATA_3_LSW_OFFSET 0x00000018U
#define gpio_MASK_DATA_3_LSW_MASK_LSHIFT 0x00000010U
#define gpio_MASK_DATA_3_LSW_MASK_MASK 0xffff0000U
#define gpio_MASK_DATA_3_LSW_DATA_LSHIFT 0x00000000U
#define gpio_MASK_DATA_3_LSW_DATA_MASK 0x0000ffffU
#define gpio_MASK_DATA_3_LSW_MASK 0xffffffffU

// Maskable Output Data (GPIO Bank3, EMIO, Upper 16bits)
#define gpio_MASK_DATA_3_MSW_OFFSET 0x0000001cU
#define gpio_MASK_DATA_3_MSW_MASK_LSHIFT 0x00000010U
#define gpio_MASK_DATA_3_MSW_MASK_MASK 0xffff0000U
#define gpio_MASK_DATA_3_MSW_DATA_LSHIFT 0x00000000U
#define gpio_MASK_DATA_3_MSW_DATA_MASK 0x0000ffffU
#define gpio_MASK_DATA_3_MSW_MASK 0xffffffffU

// Output Data (GPIO Bank0, MIO)
#define gpio_DATA_0_OFFSET 0x00000040U
#define gpio_DATA_0_DATA_LSHIFT 0x00000000U
#define gpio_DATA_0_DATA_MASK 0x00000000U

// Output Data (GPIO Bank1, MIO)
#define gpio_DATA_1_OFFSET 0x00000044U
#define gpio_DATA_1_DATA_LSHIFT 0x00000000U
#define gpio_DATA_1_DATA_MASK 0x00000000U

// Output Data (GPIO Bank2, EMIO)
#define gpio_DATA_2_OFFSET 0x00000048U
#define gpio_DATA_2_DATA_LSHIFT 0x00000000U
#define gpio_DATA_2_DATA_MASK 0x00000000U

// Output Data (GPIO Bank3, EMIO)
#define gpio_DATA_3_OFFSET 0x0000004cU
#define gpio_DATA_3_DATA_LSHIFT 0x00000000U
#define gpio_DATA_3_DATA_MASK 0x00000000U

// Input Data (GPIO Bank0, MIO)
#define gpio_DATA_0_RO_OFFSET 0x00000060U
#define gpio_DATA_0_RO_DATA_LSHIFT 0x00000000U
#define gpio_DATA_0_RO_DATA_MASK 0x00000000U

// Input Data (GPIO Bank1, MIO)
#define gpio_DATA_1_RO_OFFSET 0x00000064U
#define gpio_DATA_1_RO_DATA_LSHIFT 0x00000000U
#define gpio_DATA_1_RO_DATA_MASK 0x00000000U

// Input Data (GPIO Bank2, EMIO)
#define gpio_DATA_2_RO_OFFSET 0x00000068U
#define gpio_DATA_2_RO_DATA_LSHIFT 0x00000000U
#define gpio_DATA_2_RO_DATA_MASK 0x00000000U

// Input Data (GPIO Bank3, EMIO)
#define gpio_DATA_3_RO_OFFSET 0x0000006cU
#define gpio_DATA_3_RO_DATA_LSHIFT 0x00000000U
#define gpio_DATA_3_RO_DATA_MASK 0x00000000U

// Direction mode (GPIO Bank0, MIO)
#define gpio_DIRM_0_OFFSET 0x00000204U
#define gpio_DIRM_0_DIRECTION_0_LSHIFT 0x00000000U
#define gpio_DIRM_0_DIRECTION_0_MASK 0x00000000U

// Output enable (GPIO Bank0, EMIO)
#define gpio_OEN_0_OFFSET 0x00000208U
#define gpio_OEN_0_OP_ENABLE_LSHIFT 0x00000000U
#define gpio_OEN_0_OP_ENABLE_MASK 0x00000000U

// Interrupt Mask Status (GPIO Bank0, MIO)
#define gpio_INT_MASK_0_OFFSET 0x0000020cU
#define gpio_INT_MASK_0_INT_MASK_LSHIFT 0x00000000U
#define gpio_INT_MASK_0_INT_MASK_MASK 0x00000000U

// Interrupt Enable/Unmask (GPIO Bank0, MIO)
#define gpio_INT_EN_0_OFFSET 0x00000210U
#define gpio_INT_EN_0_INT_ENABLE_LSHIFT 0x00000000U
#define gpio_INT_EN_0_INT_ENABLE_MASK 0x00000000U

// Interrupt Disable/Mask (GPIO Bank0, MIO)
#define gpio_INT_DIS_0_OFFSET 0x00000214U
#define gpio_INT_DIS_0_INT_DISABLE_LSHIFT 0x00000000U
#define gpio_INT_DIS_0_INT_DISABLE_MASK 0x00000000U

// Interrupt Status (GPIO Bank0, MIO)
#define gpio_INT_STAT_0_OFFSET 0x00000218U
#define gpio_INT_STAT_0_INT_STATUS_LSHIFT 0x00000000U
#define gpio_INT_STAT_0_INT_STATUS_MASK 0x00000000U

// Interrupt Type (GPIO Bank0, MIO)
#define gpio_INT_TYPE_0_OFFSET 0x0000021cU
#define gpio_INT_TYPE_0_INT_TYPE_LSHIFT 0x00000000U
#define gpio_INT_TYPE_0_INT_TYPE_MASK 0x00000000U

// Interrupt Polarity (GPIO Bank0, MIO)
#define gpio_INT_POLARITY_0_OFFSET 0x00000220U
#define gpio_INT_POLARITY_0_INT_POL_LSHIFT 0x00000000U
#define gpio_INT_POLARITY_0_INT_POL_MASK 0x00000000U

// Interrupt Any Edge Sensitive (GPIO Bank0, MIO)
#define gpio_INT_ANY_0_OFFSET 0x00000224U
#define gpio_INT_ANY_0_INT_ON_ANY_LSHIFT 0x00000000U
#define gpio_INT_ANY_0_INT_ON_ANY_MASK 0x00000000U

// Direction mode (GPIO Bank1, MIO)
#define gpio_DIRM_1_OFFSET 0x00000244U
#define gpio_DIRM_1_DIRECTION_0_LSHIFT 0x00000000U
#define gpio_DIRM_1_DIRECTION_0_MASK 0x00000000U

// Output enable (GPIO Bank1, MIO)
#define gpio_OEN_1_OFFSET 0x00000248U
#define gpio_OEN_1_OP_ENABLE_LSHIFT 0x00000000U
#define gpio_OEN_1_OP_ENABLE_MASK 0x00000000U

// Interrupt Mask Status (GPIO Bank1, MIO)
#define gpio_INT_MASK_1_OFFSET 0x0000024cU
#define gpio_INT_MASK_1_INT_MASK_LSHIFT 0x00000000U
#define gpio_INT_MASK_1_INT_MASK_MASK 0x00000000U

// Interrupt Enable/Unmask (GPIO Bank1, MIO)
#define gpio_INT_EN_1_OFFSET 0x00000250U
#define gpio_INT_EN_1_INT_ENABLE_LSHIFT 0x00000000U
#define gpio_INT_EN_1_INT_ENABLE_MASK 0x00000000U

// Interrupt Disable/Mask (GPIO Bank1, MIO)
#define gpio_INT_DIS_1_OFFSET 0x00000254U
#define gpio_INT_DIS_1_INT_DISABLE_LSHIFT 0x00000000U
#define gpio_INT_DIS_1_INT_DISABLE_MASK 0x00000000U

// Interrupt Status (GPIO Bank1, MIO)
#define gpio_INT_STAT_1_OFFSET 0x00000258U
#define gpio_INT_STAT_1_INT_STATUS_LSHIFT 0x00000000U
#define gpio_INT_STAT_1_INT_STATUS_MASK 0x00000000U

// Interrupt Type (GPIO Bank1, MIO)
#define gpio_INT_TYPE_1_OFFSET 0x0000025cU
#define gpio_INT_TYPE_1_INT_TYPE_LSHIFT 0x00000000U
#define gpio_INT_TYPE_1_INT_TYPE_MASK 0x00000000U

// Interrupt Polarity (GPIO Bank1, MIO)
#define gpio_INT_POLARITY_1_OFFSET 0x00000260U
#define gpio_INT_POLARITY_1_INT_POL_LSHIFT 0x00000000U
#define gpio_INT_POLARITY_1_INT_POL_MASK 0x00000000U

// Interrupt Any Edge Sensitive (GPIO Bank1, MIO)
#define gpio_INT_ANY_1_OFFSET 0x00000264U
#define gpio_INT_ANY_1_INT_ON_ANY_LSHIFT 0x00000000U
#define gpio_INT_ANY_1_INT_ON_ANY_MASK 0x00000000U

// Direction mode (GPIO Bank2, EMIO)
#define gpio_DIRM_2_OFFSET 0x00000284U
#define gpio_DIRM_2_DIRECTION_0_LSHIFT 0x00000000U
#define gpio_DIRM_2_DIRECTION_0_MASK 0x00000000U

// Output enable (GPIO Bank2, EMIO)
#define gpio_OEN_2_OFFSET 0x00000288U
#define gpio_OEN_2_OP_ENABLE_LSHIFT 0x00000000U
#define gpio_OEN_2_OP_ENABLE_MASK 0x00000000U

// Interrupt Mask Status (GPIO Bank2, EMIO)
#define gpio_INT_MASK_2_OFFSET 0x0000028cU
#define gpio_INT_MASK_2_INT_MASK_LSHIFT 0x00000000U
#define gpio_INT_MASK_2_INT_MASK_MASK 0x00000000U

// Interrupt Enable/Unmask (GPIO Bank2, EMIO)
#define gpio_INT_EN_2_OFFSET 0x00000290U
#define gpio_INT_EN_2_INT_ENABLE_LSHIFT 0x00000000U
#define gpio_INT_EN_2_INT_ENABLE_MASK 0x00000000U

// Interrupt Disable/Mask (GPIO Bank2, EMIO)
#define gpio_INT_DIS_2_OFFSET 0x00000294U
#define gpio_INT_DIS_2_INT_DISABLE_LSHIFT 0x00000000U
#define gpio_INT_DIS_2_INT_DISABLE_MASK 0x00000000U

// Interrup
#define gpio_INT_STAT_2_OFFSET 0x00000298U
#define gpio_INT_STAT_2_INT_STATUS_LSHIFT 0x00000000U
#define gpio_INT_STAT_2_INT_STATUS_MASK 0x00000000U

// Interrupt Type (GPIO Bank2, EMIO)
#define gpio_INT_TYPE_2_OFFSET 0x0000029cU
#define gpio_INT_TYPE_2_INT_TYPE_LSHIFT 0x00000000U
#define gpio_INT_TYPE_2_INT_TYPE_MASK 0x00000000U

// Interrupt Polarity (GPIO Bank2, EMIO)
#define gpio_INT_POLARITY_2_OFFSET 0x000002a0U
#define gpio_INT_POLARITY_2_INT_POL_LSHIFT 0x00000000U
#define gpio_INT_POLARITY_2_INT_POL_MASK 0x00000000U

// Interrupt Any Edge Sensitive (GPIO Bank2, EMIO)
#define gpio_INT_ANY_2_OFFSET 0x000002a4U
#define gpio_INT_ANY_2_INT_ON_ANY_LSHIFT 0x00000000U
#define gpio_INT_ANY_2_INT_ON_ANY_MASK 0x00000000U

// Direction mode (GPIO Bank3, EMIO)
#define gpio_DIRM_3_OFFSET 0x000002c4U
#define gpio_DIRM_3_DIRECTION_0_LSHIFT 0x00000000U
#define gpio_DIRM_3_DIRECTION_0_MASK 0x00000000U

// Output enable (GPIO Bank3, EMIO)
#define gpio_OEN_3_OFFSET 0x000002c8U
#define gpio_OEN_3_OP_ENABLE_LSHIFT 0x00000000U
#define gpio_OEN_3_OP_ENABLE_MASK 0x00000000U

// Interrupt Mask Status (GPIO Bank3, EMIO)
#define gpio_INT_MASK_3_OFFSET 0x000002ccU
#define gpio_INT_MASK_3_INT_MASK_LSHIFT 0x00000000U
#define gpio_INT_MASK_3_INT_MASK_MASK 0x00000000U

// Interrupt Enable/Unmask (GPIO Bank3, EMIO)
#define gpio_INT_EN_3_OFFSET 0x000002d0U
#define gpio_INT_EN_3_INT_ENABLE_LSHIFT 0x00000000U
#define gpio_INT_EN_3_INT_ENABLE_MASK 0x00000000U

// Interrupt Disable/Mask (GPIO Bank3, EMIO)
#define gpio_INT_DIS_3_OFFSET 0x000002d4U
#define gpio_INT_DIS_3_INT_DISABLE_LSHIFT 0x00000000U
#define gpio_INT_DIS_3_INT_DISABLE_MASK 0x00000000U

// Interrupt Status (GPIO Bank3, EMIO)
#define gpio_INT_STAT_3_OFFSET 0x000002d8U
#define gpio_INT_STAT_3_INT_STATUS_LSHIFT 0x00000000U
#define gpio_INT_STAT_3_INT_STATUS_MASK 0x00000000U

// Interrupt Type (GPIO Bank3, EMIO)
#define gpio_INT_TYPE_3_OFFSET 0x000002dcU
#define gpio_INT_TYPE_3_INT_TYPE_LSHIFT 0x00000000U
#define gpio_INT_TYPE_3_INT_TYPE_MASK 0x00000000U

// Interrupt Polarity (GPIO Bank3, EMIO)
#define gpio_INT_POLARITY_3_OFFSET 0x000002e0U
#define gpio_INT_POLARITY_3_INT_POL_LSHIFT 0x00000000U
#define gpio_INT_POLARITY_3_INT_POL_MASK 0x00000000U

// Interrupt Any Edge S
#define gpio_INT_ANY_3_OFFSET 0x000002e4U
#define gpio_INT_ANY_3_INT_ON_ANY_LSHIFT 0x00000000U
#define gpio_INT_ANY_3_INT_ON_ANY_MASK 0x00000000U