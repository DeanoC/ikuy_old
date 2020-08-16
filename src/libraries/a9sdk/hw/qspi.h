#pragma once
#include <stdint.h>

// Quad SPI

// 1 bank of qspi

#define qspi_BASE_ADDR 0xe000d000U

// Registers

// QSPI configuration register
#define qspi_CR_REG 0x0U
typedef union qspi_CR
{
	struct
	{
		uint32_t IFMODE : 1;
		uint32_t RESERVED_0 : 4;
		uint32_t ENDIAN : 1;
		uint32_t RESERVED_1 : 6;
		uint32_t HOLDDB_DR : 1;
		uint32_t RESERVED_2 : 1;
		uint32_t RESERVED_3 : 1;
		uint32_t MANSTRT : 1;
		uint32_t MANSTRTEN : 1;
		uint32_t SSFORCE : 1;
		uint32_t RESERVED_4 : 3;
		uint32_t PCS : 1;
		uint32_t RESERVED_5 : 1;
		uint32_t REF_CLK : 1;
		uint32_t FIFO_WIDTH : 2;
		uint32_t BAUD_RATE_DIV : 3;
		uint32_t CPHA : 1;
		uint32_t CPOL : 1;
		uint32_t MSTREN : 1;
	} fields;
	uint32_t v;
} qspi_CR;

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
typedef union qspi_SR
{
	struct
	{
		uint32_t RESERVED_0 : 25;
		uint32_t IXR_TXUF : 1;
		uint32_t IXR_RXFULL : 1;
		uint32_t IXR_RXNEMPTY : 1;
		uint32_t IXR_TXFULL : 1;
		uint32_t IXR_TXOW : 1;
		uint32_t RESERVED_1 : 1;
		uint32_t IXR_RXOVR : 1;
	} fields;
	uint32_t v;
} qspi_SR;

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
typedef union qspi_IER
{
	struct
	{
		uint32_t RESERVED_0 : 25;
		uint32_t IXR_TXUF : 1;
		uint32_t IXR_RXFULL : 1;
		uint32_t IXR_RXNEMPTY : 1;
		uint32_t IXR_TXFULL : 1;
		uint32_t IXR_TXOW : 1;
		uint32_t RESERVED_1 : 1;
		uint32_t IXR_RXOVR : 1;
	} fields;
	uint32_t v;
} qspi_IER;

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
typedef union qspi_IDR
{
	struct
	{
		uint32_t RESERVED_0 : 25;
		uint32_t IXR_TXUF : 1;
		uint32_t IXR_RXFULL : 1;
		uint32_t IXR_RXNEMPTY : 1;
		uint32_t IXR_TXFULL : 1;
		uint32_t IXR_TXOW : 1;
		uint32_t RESERVED_1 : 1;
		uint32_t IXR_RXOVR : 1;
	} fields;
	uint32_t v;
} qspi_IDR;

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
typedef union qspi_IMR
{
	struct
	{
		uint32_t RESERVED_0 : 25;
		uint32_t IXR_TXUF : 1;
		uint32_t IXR_RXFULL : 1;
		uint32_t IXR_RXNEMPTY : 1;
		uint32_t IXR_TXFULL : 1;
		uint32_t IXR_TXOW : 1;
		uint32_t RESERVED_1 : 1;
		uint32_t IXR_RXOVR : 1;
	} fields;
	uint32_t v;
} qspi_IMR;

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
typedef union qspi_ER
{
	struct
	{
		uint32_t RESERVED_0 : 31;
		uint32_t ENABLE : 1;
	} fields;
	uint32_t v;
} qspi_ER;

#define qspi_ER_RESERVED_0_LSHIFT 1U
#define qspi_ER_RESERVED_0_MASK 0xfffffffeU
#define qspi_ER_ENABLE_LSHIFT 0U
#define qspi_ER_ENABLE 0x1U
#define qspi_ER_ENABLE_MASK 0x1U
#define qspi_ER_MASK 0x1U


// Delay Register
#define qspi_DR_REG 0x18U
typedef union qspi_DR
{
	struct
	{
		uint32_t D_NSS : 8;
		uint32_t BTWN : 8;
		uint32_t AFTER : 8;
		uint32_t INIT : 8;
	} fields;
	uint32_t v;
} qspi_DR;

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
typedef union qspi_TXD_00
{
	struct
	{
		uint32_t TXD : 32;
	} fields;
	uint32_t v;
} qspi_TXD_00;

#define qspi_TXD_00_TXD_LSHIFT 0U
#define qspi_TXD_00_TXD_MASK 0x0U
#define qspi_TXD_00_MASK 0x0U


// Receive Data Register
#define qspi_RXD_REG 0x20U
typedef union qspi_RXD
{
	struct
	{
		uint32_t RX_FIFO : 32;
	} fields;
	uint32_t v;
} qspi_RXD;

#define qspi_RXD_RX_FIFO_LSHIFT 0U
#define qspi_RXD_RX_FIFO_MASK 0x0U
#define qspi_RXD_MASK 0x0U


// Slave Idle Count Register
#define qspi_SICR_REG 0x24U
typedef union qspi_SICR
{
	struct
	{
		uint32_t RESERVED_0 : 24;
		uint32_t MASK : 8;
	} fields;
	uint32_t v;
} qspi_SICR;

#define qspi_SICR_RESERVED_0_LSHIFT 8U
#define qspi_SICR_RESERVED_0_MASK 0xffffff00U
#define qspi_SICR_MASK_LSHIFT 0U
#define qspi_SICR_MASK_MASK 0xffU
#define qspi_SICR_MASK 0xffU


// TX_FIFO Threshold Register
#define qspi_TXWR_REG 0x28U
typedef union qspi_TXWR
{
	struct
	{
		uint32_t THRESHOLD_OF_TX_FIFO : 32;
	} fields;
	uint32_t v;
} qspi_TXWR;

#define qspi_TXWR_THRESHOLD_OF_TX_FIFO_LSHIFT 0U
#define qspi_TXWR_THRESHOLD_OF_TX_FIFO_MASK 0x0U
#define qspi_TXWR_MASK 0x0U


// RX FIFO Threshold Register 
#define qspi_RX_THRES_REG 0x2cU
typedef union qspi_RX_THRES
{
	struct
	{
		uint32_t THRESHOLD_OF_RX_FIFO : 32;
	} fields;
	uint32_t v;
} qspi_RX_THRES;

#define qspi_RX_THRES_THRESHOLD_OF_RX_FIFO_LSHIFT 0U
#define qspi_RX_THRES_THRESHOLD_OF_RX_FIFO_MASK 0x0U
#define qspi_RX_THRES_MASK 0x0U


// General Purpose Inputs and Outputs Register for the Quad-SPI Controller core
#define qspi_GPIO_REG 0x30U
typedef union qspi_GPIO
{
	struct
	{
		uint32_t RESERVED_0 : 31;
		uint32_t WP_N : 1;
	} fields;
	uint32_t v;
} qspi_GPIO;

#define qspi_GPIO_RESERVED_0_LSHIFT 1U
#define qspi_GPIO_RESERVED_0_MASK 0xfffffffeU
#define qspi_GPIO_WP_N_LSHIFT 0U
#define qspi_GPIO_WP_N 0x1U
#define qspi_GPIO_WP_N_MASK 0x1U
#define qspi_GPIO_MASK 0x1U


// Loopback Master Clock Delay Adjustment Register
#define qspi_LPBK_DLY_ADJ_REG 0x38U
typedef union qspi_LPBK_DLY_ADJ
{
	struct
	{
		uint32_t RESERVED_0 : 26;
		uint32_t USE_LPBK : 1;
		uint32_t RESERVED_1 : 5;
	} fields;
	uint32_t v;
} qspi_LPBK_DLY_ADJ;

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
typedef union qspi_TXD_01
{
	struct
	{
		uint32_t TXD : 32;
	} fields;
	uint32_t v;
} qspi_TXD_01;

#define qspi_TXD_01_TXD_LSHIFT 0U
#define qspi_TXD_01_TXD_MASK 0x0U
#define qspi_TXD_01_MASK 0x0U


// Transmit Data Register. Keyhole addresses for the Transmit data FIFO.
#define qspi_TXD_10_REG 0x84U
typedef union qspi_TXD_10
{
	struct
	{
		uint32_t TXD : 32;
	} fields;
	uint32_t v;
} qspi_TXD_10;

#define qspi_TXD_10_TXD_LSHIFT 0U
#define qspi_TXD_10_TXD_MASK 0x0U
#define qspi_TXD_10_MASK 0x0U


// Transmit Data Register. Keyhole addresses for the Transmit data FIFO.
#define qspi_TXD_11_REG 0x88U
typedef union qspi_TXD_11
{
	struct
	{
		uint32_t TXD : 32;
	} fields;
	uint32_t v;
} qspi_TXD_11;

#define qspi_TXD_11_TXD_LSHIFT 0U
#define qspi_TXD_11_TXD_MASK 0x0U
#define qspi_TXD_11_MASK 0x0U


// 31:16 wo 0x0
#define qspi_LQSPI_CR_REG 0xa0U
typedef union qspi_LQSPI_CR
{
	struct
	{
		uint32_t LINEAR : 1;
		uint32_t TWO_MEM : 1;
		uint32_t SEP_BUS : 1;
		uint32_t U_PAGE : 1;
		uint32_t RESERVED_0 : 1;
		uint32_t RESERVED_1 : 1;
		uint32_t MODE_EN : 1;
		uint32_t MODE_ON : 1;
		uint32_t MODE_BITS : 8;
		uint32_t RESERVED_2 : 5;
		uint32_t DUMMY : 3;
		uint32_t INST : 8;
	} fields;
	uint32_t v;
} qspi_LQSPI_CR;

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
typedef union qspi_LQSPI_SR
{
	struct
	{
		uint32_t RESERVED_0 : 29;
		uint32_t FB_RECVD : 1;
		uint32_t WR_RECVD : 1;
		uint32_t RESERVED_1 : 1;
	} fields;
	uint32_t v;
} qspi_LQSPI_SR;

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
typedef union qspi_MOD_ID
{
	struct
	{
		uint32_t ID : 32;
	} fields;
	uint32_t v;
} qspi_MOD_ID;

#define qspi_MOD_ID_ID_LSHIFT 0U
#define qspi_MOD_ID_ID_MASK 0x0U
#define qspi_MOD_ID_MASK 0x0U


