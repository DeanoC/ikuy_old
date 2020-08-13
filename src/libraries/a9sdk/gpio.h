#pragma once
#include <stdint.h>

// 1 bank of gpio

#define gpio_BASE_ADDR 0xe000a000U

// Registers

// Maskable Output Data (GPIO Bank0, MIO, Lower 16bits)
#define gpio_MASK_DATA_0_LSW_REG 0x0U
typedef union gpio_MASK_DATA_0_LSW
{
	struct
	{
		uint32_t MASK : 16;
		uint32_t DATA : 16;
	} fields;
	uint32_t v;
} gpio_MASK_DATA_0_LSW;

#define gpio_MASK_DATA_0_LSW_MASK_LSHIFT 16U
#define gpio_MASK_DATA_0_LSW_MASK_MASK 0xffff0000U
#define gpio_MASK_DATA_0_LSW_DATA_LSHIFT 0U
#define gpio_MASK_DATA_0_LSW_DATA_MASK 0xffffU
#define gpio_MASK_DATA_0_LSW_MASK 0xffffffffU


// Maskable Output Data (GPIO Bank0, MIO, Upper 16bits)
#define gpio_MASK_DATA_0_MSW_REG 0x4U
typedef union gpio_MASK_DATA_0_MSW
{
	struct
	{
		uint32_t MASK : 16;
		uint32_t DATA : 16;
	} fields;
	uint32_t v;
} gpio_MASK_DATA_0_MSW;

#define gpio_MASK_DATA_0_MSW_MASK_LSHIFT 16U
#define gpio_MASK_DATA_0_MSW_MASK_MASK 0xffff0000U
#define gpio_MASK_DATA_0_MSW_DATA_LSHIFT 0U
#define gpio_MASK_DATA_0_MSW_DATA_MASK 0xffffU
#define gpio_MASK_DATA_0_MSW_MASK 0xffffffffU


// 15:0 wo 0x00000000
#define gpio_MASK_DATA_1_LSW_REG 0x8U
typedef union gpio_MASK_DATA_1_LSW
{
	struct
	{
		uint32_t MASK : 16;
		uint32_t DATA : 16;
	} fields;
	uint32_t v;
} gpio_MASK_DATA_1_LSW;

#define gpio_MASK_DATA_1_LSW_MASK_LSHIFT 16U
#define gpio_MASK_DATA_1_LSW_MASK_MASK 0xffff0000U
#define gpio_MASK_DATA_1_LSW_DATA_LSHIFT 0U
#define gpio_MASK_DATA_1_LSW_DATA_MASK 0xffffU
#define gpio_MASK_DATA_1_LSW_MASK 0xffffffffU


// 15:0 wo 0x00000000
#define gpio_MASK_DATA_1_MSW_REG 0xcU
typedef union gpio_MASK_DATA_1_MSW
{
	struct
	{
		uint32_t MASK : 16;
		uint32_t DATA : 16;
	} fields;
	uint32_t v;
} gpio_MASK_DATA_1_MSW;

#define gpio_MASK_DATA_1_MSW_MASK_LSHIFT 16U
#define gpio_MASK_DATA_1_MSW_MASK_MASK 0xffff0000U
#define gpio_MASK_DATA_1_MSW_DATA_LSHIFT 0U
#define gpio_MASK_DATA_1_MSW_DATA_MASK 0xffffU
#define gpio_MASK_DATA_1_MSW_MASK 0xffffffffU


// Maskable Output Data (GPIO Bank2, EMIO, Lower 16bits)
#define gpio_MASK_DATA_2_LSW_REG 0x10U
typedef union gpio_MASK_DATA_2_LSW
{
	struct
	{
		uint32_t MASK : 16;
		uint32_t DATA : 16;
	} fields;
	uint32_t v;
} gpio_MASK_DATA_2_LSW;

#define gpio_MASK_DATA_2_LSW_MASK_LSHIFT 16U
#define gpio_MASK_DATA_2_LSW_MASK_MASK 0xffff0000U
#define gpio_MASK_DATA_2_LSW_DATA_LSHIFT 0U
#define gpio_MASK_DATA_2_LSW_DATA_MASK 0xffffU
#define gpio_MASK_DATA_2_LSW_MASK 0xffffffffU


// Maskable Output Data (GPIO Bank2, EMIO, Upper 16bits)
#define gpio_MASK_DATA_2_MSW_REG 0x14U
typedef union gpio_MASK_DATA_2_MSW
{
	struct
	{
		uint32_t MASK : 16;
		uint32_t DATA : 16;
	} fields;
	uint32_t v;
} gpio_MASK_DATA_2_MSW;

#define gpio_MASK_DATA_2_MSW_MASK_LSHIFT 16U
#define gpio_MASK_DATA_2_MSW_MASK_MASK 0xffff0000U
#define gpio_MASK_DATA_2_MSW_DATA_LSHIFT 0U
#define gpio_MASK_DATA_2_MSW_DATA_MASK 0xffffU
#define gpio_MASK_DATA_2_MSW_MASK 0xffffffffU


// Maskable Output Data (GPIO Bank3, EMIO, Lower 16bits)
#define gpio_MASK_DATA_3_LSW_REG 0x18U
typedef union gpio_MASK_DATA_3_LSW
{
	struct
	{
		uint32_t MASK : 16;
		uint32_t DATA : 16;
	} fields;
	uint32_t v;
} gpio_MASK_DATA_3_LSW;

#define gpio_MASK_DATA_3_LSW_MASK_LSHIFT 16U
#define gpio_MASK_DATA_3_LSW_MASK_MASK 0xffff0000U
#define gpio_MASK_DATA_3_LSW_DATA_LSHIFT 0U
#define gpio_MASK_DATA_3_LSW_DATA_MASK 0xffffU
#define gpio_MASK_DATA_3_LSW_MASK 0xffffffffU


// Maskable Output Data (GPIO Bank3, EMIO, Upper 16bits)
#define gpio_MASK_DATA_3_MSW_REG 0x1cU
typedef union gpio_MASK_DATA_3_MSW
{
	struct
	{
		uint32_t MASK : 16;
		uint32_t DATA : 16;
	} fields;
	uint32_t v;
} gpio_MASK_DATA_3_MSW;

#define gpio_MASK_DATA_3_MSW_MASK_LSHIFT 16U
#define gpio_MASK_DATA_3_MSW_MASK_MASK 0xffff0000U
#define gpio_MASK_DATA_3_MSW_DATA_LSHIFT 0U
#define gpio_MASK_DATA_3_MSW_DATA_MASK 0xffffU
#define gpio_MASK_DATA_3_MSW_MASK 0xffffffffU


// Data (GPIO Bank3, EMIO, Upper 16bits)
#define gpio_DATA_0_REG 0x40U
typedef union gpio_DATA_0
{
	struct
	{
		uint32_t DATA : 32;
	} fields;
	uint32_t v;
} gpio_DATA_0;

#define gpio_DATA_0_DATA_LSHIFT 0U
#define gpio_DATA_0_DATA_MASK 0x0U
#define gpio_DATA_0_MASK 0x0U


// Data (GPIO Bank3, EMIO, Upper 16bits)
#define gpio_DATA_1_REG 0x44U
typedef union gpio_DATA_1
{
	struct
	{
		uint32_t DATA : 32;
	} fields;
	uint32_t v;
} gpio_DATA_1;

#define gpio_DATA_1_DATA_LSHIFT 0U
#define gpio_DATA_1_DATA_MASK 0x0U
#define gpio_DATA_1_MASK 0x0U


// Output Data (GPIO Bank2, EMIO)
#define gpio_DATA_2_REG 0x48U
typedef union gpio_DATA_2
{
	struct
	{
		uint32_t DATA : 32;
	} fields;
	uint32_t v;
} gpio_DATA_2;

#define gpio_DATA_2_DATA_LSHIFT 0U
#define gpio_DATA_2_DATA_MASK 0x0U
#define gpio_DATA_2_MASK 0x0U


// Output Data (GPIO Bank3, EMIO)
#define gpio_DATA_3_REG 0x4cU
typedef union gpio_DATA_3
{
	struct
	{
		uint32_t DATA : 32;
	} fields;
	uint32_t v;
} gpio_DATA_3;

#define gpio_DATA_3_DATA_LSHIFT 0U
#define gpio_DATA_3_DATA_MASK 0x0U
#define gpio_DATA_3_MASK 0x0U


// EMIO)
#define gpio_DATA_0_RO_REG 0x60U
typedef union gpio_DATA_0_RO
{
	struct
	{
		uint32_t DATA : 32;
	} fields;
	uint32_t v;
} gpio_DATA_0_RO;

#define gpio_DATA_0_RO_DATA_LSHIFT 0U
#define gpio_DATA_0_RO_DATA_MASK 0x0U
#define gpio_DATA_0_RO_MASK 0x0U


// EMIO)
#define gpio_DATA_1_RO_REG 0x64U
typedef union gpio_DATA_1_RO
{
	struct
	{
		uint32_t DATA : 32;
	} fields;
	uint32_t v;
} gpio_DATA_1_RO;

#define gpio_DATA_1_RO_DATA_LSHIFT 0U
#define gpio_DATA_1_RO_DATA_MASK 0x0U
#define gpio_DATA_1_RO_MASK 0x0U


// Input Data (GPIO Bank2, EMIO)
#define gpio_DATA_2_RO_REG 0x68U
typedef union gpio_DATA_2_RO
{
	struct
	{
		uint32_t DATA : 32;
	} fields;
	uint32_t v;
} gpio_DATA_2_RO;

#define gpio_DATA_2_RO_DATA_LSHIFT 0U
#define gpio_DATA_2_RO_DATA_MASK 0x0U
#define gpio_DATA_2_RO_MASK 0x0U


// Input Data (GPIO Bank3, EMIO)
#define gpio_DATA_3_RO_REG 0x6cU
typedef union gpio_DATA_3_RO
{
	struct
	{
		uint32_t DATA : 32;
	} fields;
	uint32_t v;
} gpio_DATA_3_RO;

#define gpio_DATA_3_RO_DATA_LSHIFT 0U
#define gpio_DATA_3_RO_DATA_MASK 0x0U
#define gpio_DATA_3_RO_MASK 0x0U


// Direction mode (GPIO Bank0, MIO)
#define gpio_DIRM_0_REG 0x204U
typedef union gpio_DIRM_0
{
	struct
	{
		uint32_t DIRECTION_0 : 32;
	} fields;
	uint32_t v;
} gpio_DIRM_0;

#define gpio_DIRM_0_DIRECTION_0_LSHIFT 0U
#define gpio_DIRM_0_DIRECTION_0_MASK 0x0U
#define gpio_DIRM_0_MASK 0x0U


// Output enable (GPIO Bank0, EMIO)
#define gpio_OEN_0_REG 0x208U
typedef union gpio_OEN_0
{
	struct
	{
		uint32_t OP_ENABLE : 32;
	} fields;
	uint32_t v;
} gpio_OEN_0;

#define gpio_OEN_0_OP_ENABLE_LSHIFT 0U
#define gpio_OEN_0_OP_ENABLE_MASK 0x0U
#define gpio_OEN_0_MASK 0x0U


// Interrupt Mask Status (GPIO Bank0, MIO)
#define gpio_INT_MASK_0_REG 0x20cU
typedef union gpio_INT_MASK_0
{
	struct
	{
		uint32_t INT_MASK : 32;
	} fields;
	uint32_t v;
} gpio_INT_MASK_0;

#define gpio_INT_MASK_0_INT_MASK_LSHIFT 0U
#define gpio_INT_MASK_0_INT_MASK_MASK 0x0U
#define gpio_INT_MASK_0_MASK 0x0U


// Interrupt Enable/Unmask (GPIO Bank0, MIO)
#define gpio_INT_EN_0_REG 0x210U
typedef union gpio_INT_EN_0
{
	struct
	{
		uint32_t INT_ENABLE : 32;
	} fields;
	uint32_t v;
} gpio_INT_EN_0;

#define gpio_INT_EN_0_INT_ENABLE_LSHIFT 0U
#define gpio_INT_EN_0_INT_ENABLE_MASK 0x0U
#define gpio_INT_EN_0_MASK 0x0U


// Interrupt Disable/Mask (GPIO Bank0, MIO)
#define gpio_INT_DIS_0_REG 0x214U
typedef union gpio_INT_DIS_0
{
	struct
	{
		uint32_t INT_DISABLE : 32;
	} fields;
	uint32_t v;
} gpio_INT_DIS_0;

#define gpio_INT_DIS_0_INT_DISABLE_LSHIFT 0U
#define gpio_INT_DIS_0_INT_DISABLE_MASK 0x0U
#define gpio_INT_DIS_0_MASK 0x0U


// Interrupt Status (GPIO Bank0, MIO)
#define gpio_INT_STAT_0_REG 0x218U
typedef union gpio_INT_STAT_0
{
	struct
	{
		uint32_t INT_STATUS : 32;
	} fields;
	uint32_t v;
} gpio_INT_STAT_0;

#define gpio_INT_STAT_0_INT_STATUS_LSHIFT 0U
#define gpio_INT_STAT_0_INT_STATUS_MASK 0x0U
#define gpio_INT_STAT_0_MASK 0x0U


// Interrupt Type (GPIO Bank0, MIO)
#define gpio_INT_TYPE_0_REG 0x21cU
typedef union gpio_INT_TYPE_0
{
	struct
	{
		uint32_t INT_TYPE : 32;
	} fields;
	uint32_t v;
} gpio_INT_TYPE_0;

#define gpio_INT_TYPE_0_INT_TYPE_LSHIFT 0U
#define gpio_INT_TYPE_0_INT_TYPE_MASK 0x0U
#define gpio_INT_TYPE_0_MASK 0x0U


// Interrupt Polarity (GPIO Bank0, MIO)
#define gpio_INT_POLARITY_0_REG 0x220U
typedef union gpio_INT_POLARITY_0
{
	struct
	{
		uint32_t INT_POL : 32;
	} fields;
	uint32_t v;
} gpio_INT_POLARITY_0;

#define gpio_INT_POLARITY_0_INT_POL_LSHIFT 0U
#define gpio_INT_POLARITY_0_INT_POL_MASK 0x0U
#define gpio_INT_POLARITY_0_MASK 0x0U


// Interrupt Any Edge Sensitive (GPIO Bank0, MIO)
#define gpio_INT_ANY_0_REG 0x224U
typedef union gpio_INT_ANY_0
{
	struct
	{
		uint32_t INT_ON_ANY : 32;
	} fields;
	uint32_t v;
} gpio_INT_ANY_0;

#define gpio_INT_ANY_0_INT_ON_ANY_LSHIFT 0U
#define gpio_INT_ANY_0_INT_ON_ANY_MASK 0x0U
#define gpio_INT_ANY_0_MASK 0x0U


// Direction mode (GPIO Bank1, MIO)
#define gpio_DIRM_1_REG 0x244U
typedef union gpio_DIRM_1
{
	struct
	{
		uint32_t DIRECTION_0 : 32;
	} fields;
	uint32_t v;
} gpio_DIRM_1;

#define gpio_DIRM_1_DIRECTION_0_LSHIFT 0U
#define gpio_DIRM_1_DIRECTION_0_MASK 0x0U
#define gpio_DIRM_1_MASK 0x0U


// Output enable (GPIO Bank1, MIO)
#define gpio_OEN_1_REG 0x248U
typedef union gpio_OEN_1
{
	struct
	{
		uint32_t OP_ENABLE : 32;
	} fields;
	uint32_t v;
} gpio_OEN_1;

#define gpio_OEN_1_OP_ENABLE_LSHIFT 0U
#define gpio_OEN_1_OP_ENABLE_MASK 0x0U
#define gpio_OEN_1_MASK 0x0U


// Interrupt Mask Status (GPIO Bank1, MIO)
#define gpio_INT_MASK_1_REG 0x24cU
typedef union gpio_INT_MASK_1
{
	struct
	{
		uint32_t INT_MASK : 32;
	} fields;
	uint32_t v;
} gpio_INT_MASK_1;

#define gpio_INT_MASK_1_INT_MASK_LSHIFT 0U
#define gpio_INT_MASK_1_INT_MASK_MASK 0x0U
#define gpio_INT_MASK_1_MASK 0x0U


// Interrupt Enable/Unmask (GPIO Bank1, MIO)
#define gpio_INT_EN_1_REG 0x250U
typedef union gpio_INT_EN_1
{
	struct
	{
		uint32_t INT_ENABLE : 32;
	} fields;
	uint32_t v;
} gpio_INT_EN_1;

#define gpio_INT_EN_1_INT_ENABLE_LSHIFT 0U
#define gpio_INT_EN_1_INT_ENABLE_MASK 0x0U
#define gpio_INT_EN_1_MASK 0x0U


// Interrupt Disable/Mask (GPIO Bank1, MIO)
#define gpio_INT_DIS_1_REG 0x254U
typedef union gpio_INT_DIS_1
{
	struct
	{
		uint32_t INT_DISABLE : 32;
	} fields;
	uint32_t v;
} gpio_INT_DIS_1;

#define gpio_INT_DIS_1_INT_DISABLE_LSHIFT 0U
#define gpio_INT_DIS_1_INT_DISABLE_MASK 0x0U
#define gpio_INT_DIS_1_MASK 0x0U


// Interrupt Status (GPIO Bank1, MIO)
#define gpio_INT_STAT_1_REG 0x258U
typedef union gpio_INT_STAT_1
{
	struct
	{
		uint32_t INT_STATUS : 32;
	} fields;
	uint32_t v;
} gpio_INT_STAT_1;

#define gpio_INT_STAT_1_INT_STATUS_LSHIFT 0U
#define gpio_INT_STAT_1_INT_STATUS_MASK 0x0U
#define gpio_INT_STAT_1_MASK 0x0U


// Interrupt Type (GPIO Bank1, MIO)
#define gpio_INT_TYPE_1_REG 0x25cU
typedef union gpio_INT_TYPE_1
{
	struct
	{
		uint32_t INT_TYPE : 32;
	} fields;
	uint32_t v;
} gpio_INT_TYPE_1;

#define gpio_INT_TYPE_1_INT_TYPE_LSHIFT 0U
#define gpio_INT_TYPE_1_INT_TYPE_MASK 0x0U
#define gpio_INT_TYPE_1_MASK 0x0U


// Interrupt Polarity (GPIO Bank1, MIO)
#define gpio_INT_POLARITY_1_REG 0x260U
typedef union gpio_INT_POLARITY_1
{
	struct
	{
		uint32_t INT_POL : 32;
	} fields;
	uint32_t v;
} gpio_INT_POLARITY_1;

#define gpio_INT_POLARITY_1_INT_POL_LSHIFT 0U
#define gpio_INT_POLARITY_1_INT_POL_MASK 0x0U
#define gpio_INT_POLARITY_1_MASK 0x0U


// Interrupt Any Edge Sensitive (GPIO Bank1, MIO)
#define gpio_INT_ANY_1_REG 0x264U
typedef union gpio_INT_ANY_1
{
	struct
	{
		uint32_t INT_ON_ANY : 32;
	} fields;
	uint32_t v;
} gpio_INT_ANY_1;

#define gpio_INT_ANY_1_INT_ON_ANY_LSHIFT 0U
#define gpio_INT_ANY_1_INT_ON_ANY_MASK 0x0U
#define gpio_INT_ANY_1_MASK 0x0U


// Direction mode (GPIO Bank2, EMIO)
#define gpio_DIRM_2_REG 0x284U
typedef union gpio_DIRM_2
{
	struct
	{
		uint32_t DIRECTION_0 : 32;
	} fields;
	uint32_t v;
} gpio_DIRM_2;

#define gpio_DIRM_2_DIRECTION_0_LSHIFT 0U
#define gpio_DIRM_2_DIRECTION_0_MASK 0x0U
#define gpio_DIRM_2_MASK 0x0U


// Output enable (GPIO Bank2, EMIO)
#define gpio_OEN_2_REG 0x288U
typedef union gpio_OEN_2
{
	struct
	{
		uint32_t OP_ENABLE : 32;
	} fields;
	uint32_t v;
} gpio_OEN_2;

#define gpio_OEN_2_OP_ENABLE_LSHIFT 0U
#define gpio_OEN_2_OP_ENABLE_MASK 0x0U
#define gpio_OEN_2_MASK 0x0U


// Interrupt Mask Status (GPIO Bank2, EMIO)
#define gpio_INT_MASK_2_REG 0x28cU
typedef union gpio_INT_MASK_2
{
	struct
	{
		uint32_t INT_MASK : 32;
	} fields;
	uint32_t v;
} gpio_INT_MASK_2;

#define gpio_INT_MASK_2_INT_MASK_LSHIFT 0U
#define gpio_INT_MASK_2_INT_MASK_MASK 0x0U
#define gpio_INT_MASK_2_MASK 0x0U


// Interrupt Enable/Unmask (GPIO Bank2, EMIO)
#define gpio_INT_EN_2_REG 0x290U
typedef union gpio_INT_EN_2
{
	struct
	{
		uint32_t INT_ENABLE : 32;
	} fields;
	uint32_t v;
} gpio_INT_EN_2;

#define gpio_INT_EN_2_INT_ENABLE_LSHIFT 0U
#define gpio_INT_EN_2_INT_ENABLE_MASK 0x0U
#define gpio_INT_EN_2_MASK 0x0U


// Interrupt Disable/Mask (GPIO Bank2, EMIO)
#define gpio_INT_DIS_2_REG 0x294U
typedef union gpio_INT_DIS_2
{
	struct
	{
		uint32_t INT_DISABLE : 32;
	} fields;
	uint32_t v;
} gpio_INT_DIS_2;

#define gpio_INT_DIS_2_INT_DISABLE_LSHIFT 0U
#define gpio_INT_DIS_2_INT_DISABLE_MASK 0x0U
#define gpio_INT_DIS_2_MASK 0x0U


// Interrup
#define gpio_INT_STAT_2_REG 0x298U
typedef union gpio_INT_STAT_2
{
	struct
	{
		uint32_t INT_STATUS : 32;
	} fields;
	uint32_t v;
} gpio_INT_STAT_2;

#define gpio_INT_STAT_2_INT_STATUS_LSHIFT 0U
#define gpio_INT_STAT_2_INT_STATUS_MASK 0x0U
#define gpio_INT_STAT_2_MASK 0x0U


// Interrupt Type (GPIO Bank2, EMIO)
#define gpio_INT_TYPE_2_REG 0x29cU
typedef union gpio_INT_TYPE_2
{
	struct
	{
		uint32_t INT_TYPE : 32;
	} fields;
	uint32_t v;
} gpio_INT_TYPE_2;

#define gpio_INT_TYPE_2_INT_TYPE_LSHIFT 0U
#define gpio_INT_TYPE_2_INT_TYPE_MASK 0x0U
#define gpio_INT_TYPE_2_MASK 0x0U


// Interrupt Polarity (GPIO Bank2, EMIO)
#define gpio_INT_POLARITY_2_REG 0x2a0U
typedef union gpio_INT_POLARITY_2
{
	struct
	{
		uint32_t INT_POL : 32;
	} fields;
	uint32_t v;
} gpio_INT_POLARITY_2;

#define gpio_INT_POLARITY_2_INT_POL_LSHIFT 0U
#define gpio_INT_POLARITY_2_INT_POL_MASK 0x0U
#define gpio_INT_POLARITY_2_MASK 0x0U


// Interrupt Any Edge Sensitive (GPIO Bank2, EMIO)
#define gpio_INT_ANY_2_REG 0x2a4U
typedef union gpio_INT_ANY_2
{
	struct
	{
		uint32_t INT_ON_ANY : 32;
	} fields;
	uint32_t v;
} gpio_INT_ANY_2;

#define gpio_INT_ANY_2_INT_ON_ANY_LSHIFT 0U
#define gpio_INT_ANY_2_INT_ON_ANY_MASK 0x0U
#define gpio_INT_ANY_2_MASK 0x0U


// Direction mode (GPIO Bank3, EMIO)
#define gpio_DIRM_3_REG 0x2c4U
typedef union gpio_DIRM_3
{
	struct
	{
		uint32_t DIRECTION_0 : 32;
	} fields;
	uint32_t v;
} gpio_DIRM_3;

#define gpio_DIRM_3_DIRECTION_0_LSHIFT 0U
#define gpio_DIRM_3_DIRECTION_0_MASK 0x0U
#define gpio_DIRM_3_MASK 0x0U


// Output enable (GPIO Bank3, EMIO)
#define gpio_OEN_3_REG 0x2c8U
typedef union gpio_OEN_3
{
	struct
	{
		uint32_t OP_ENABLE : 32;
	} fields;
	uint32_t v;
} gpio_OEN_3;

#define gpio_OEN_3_OP_ENABLE_LSHIFT 0U
#define gpio_OEN_3_OP_ENABLE_MASK 0x0U
#define gpio_OEN_3_MASK 0x0U


// Interrupt Mask Status (GPIO Bank3, EMIO)
#define gpio_INT_MASK_3_REG 0x2ccU
typedef union gpio_INT_MASK_3
{
	struct
	{
		uint32_t INT_MASK : 32;
	} fields;
	uint32_t v;
} gpio_INT_MASK_3;

#define gpio_INT_MASK_3_INT_MASK_LSHIFT 0U
#define gpio_INT_MASK_3_INT_MASK_MASK 0x0U
#define gpio_INT_MASK_3_MASK 0x0U


// Interrupt Enable/Unmask (GPIO Bank3, EMIO)
#define gpio_INT_EN_3_REG 0x2d0U
typedef union gpio_INT_EN_3
{
	struct
	{
		uint32_t INT_ENABLE : 32;
	} fields;
	uint32_t v;
} gpio_INT_EN_3;

#define gpio_INT_EN_3_INT_ENABLE_LSHIFT 0U
#define gpio_INT_EN_3_INT_ENABLE_MASK 0x0U
#define gpio_INT_EN_3_MASK 0x0U


// Interrupt Disable/Mask (GPIO Bank3, EMIO)
#define gpio_INT_DIS_3_REG 0x2d4U
typedef union gpio_INT_DIS_3
{
	struct
	{
		uint32_t INT_DISABLE : 32;
	} fields;
	uint32_t v;
} gpio_INT_DIS_3;

#define gpio_INT_DIS_3_INT_DISABLE_LSHIFT 0U
#define gpio_INT_DIS_3_INT_DISABLE_MASK 0x0U
#define gpio_INT_DIS_3_MASK 0x0U


// Interrupt Status (GPIO Bank3, EMIO)
#define gpio_INT_STAT_3_REG 0x2d8U
typedef union gpio_INT_STAT_3
{
	struct
	{
		uint32_t INT_STATUS : 32;
	} fields;
	uint32_t v;
} gpio_INT_STAT_3;

#define gpio_INT_STAT_3_INT_STATUS_LSHIFT 0U
#define gpio_INT_STAT_3_INT_STATUS_MASK 0x0U
#define gpio_INT_STAT_3_MASK 0x0U


// Interrupt Type (GPIO Bank3, EMIO)
#define gpio_INT_TYPE_3_REG 0x2dcU
typedef union gpio_INT_TYPE_3
{
	struct
	{
		uint32_t INT_TYPE : 32;
	} fields;
	uint32_t v;
} gpio_INT_TYPE_3;

#define gpio_INT_TYPE_3_INT_TYPE_LSHIFT 0U
#define gpio_INT_TYPE_3_INT_TYPE_MASK 0x0U
#define gpio_INT_TYPE_3_MASK 0x0U


// Interrupt Polarity (GPIO Bank3, EMIO)
#define gpio_INT_POLARITY_3_REG 0x2e0U
typedef union gpio_INT_POLARITY_3
{
	struct
	{
		uint32_t INT_POL : 32;
	} fields;
	uint32_t v;
} gpio_INT_POLARITY_3;

#define gpio_INT_POLARITY_3_INT_POL_LSHIFT 0U
#define gpio_INT_POLARITY_3_INT_POL_MASK 0x0U
#define gpio_INT_POLARITY_3_MASK 0x0U


// Interrupt Any Edge S
#define gpio_INT_ANY_3_REG 0x2e4U
typedef union gpio_INT_ANY_3
{
	struct
	{
		uint32_t INT_ON_ANY : 32;
	} fields;
	uint32_t v;
} gpio_INT_ANY_3;

#define gpio_INT_ANY_3_INT_ON_ANY_LSHIFT 0U
#define gpio_INT_ANY_3_INT_ON_ANY_MASK 0x0U
#define gpio_INT_ANY_3_MASK 0x0U


