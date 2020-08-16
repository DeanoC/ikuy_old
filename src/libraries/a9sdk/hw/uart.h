#pragma once
#include <stdint.h>

// UART (serial)

// 2 banks of uart

#define uart0_BASE_ADDR 0xe0000000U
#define uart1_BASE_ADDR 0xe0001000U

// Registers

// UART Control Register
#define uart_CR_REG 0x0U
typedef union uart_CR
{
	struct
	{
		uint32_t RESERVED_0 : 23;
		uint32_t STOPBRK : 1;
		uint32_t STARTBRK : 1;
		uint32_t TORST : 1;
		uint32_t TX_DIS : 1;
		uint32_t TX_EN : 1;
		uint32_t RX_DIS : 1;
		uint32_t RX_EN : 1;
		uint32_t TXRST : 1;
		uint32_t RXRST : 1;
	} fields;
	uint32_t v;
} uart_CR;

#define uart_CR_RESERVED_0_LSHIFT 9U
#define uart_CR_RESERVED_0_MASK 0xfffffe00U
#define uart_CR_STOPBRK_LSHIFT 8U
#define uart_CR_STOPBRK 0x100U
#define uart_CR_STOPBRK_MASK 0x100U
#define uart_CR_STARTBRK_LSHIFT 7U
#define uart_CR_STARTBRK 0x80U
#define uart_CR_STARTBRK_MASK 0x80U
#define uart_CR_TORST_LSHIFT 6U
#define uart_CR_TORST 0x40U
#define uart_CR_TORST_MASK 0x40U
#define uart_CR_TX_DIS_LSHIFT 5U
#define uart_CR_TX_DIS 0x20U
#define uart_CR_TX_DIS_MASK 0x20U
#define uart_CR_TX_EN_LSHIFT 4U
#define uart_CR_TX_EN 0x10U
#define uart_CR_TX_EN_MASK 0x10U
#define uart_CR_RX_DIS_LSHIFT 3U
#define uart_CR_RX_DIS 0x8U
#define uart_CR_RX_DIS_MASK 0x8U
#define uart_CR_RX_EN_LSHIFT 2U
#define uart_CR_RX_EN 0x4U
#define uart_CR_RX_EN_MASK 0x4U
#define uart_CR_TXRST_LSHIFT 1U
#define uart_CR_TXRST 0x2U
#define uart_CR_TXRST_MASK 0x2U
#define uart_CR_RXRST_LSHIFT 0U
#define uart_CR_RXRST 0x1U
#define uart_CR_RXRST_MASK 0x1U
#define uart_CR_MASK 0x1ffU


// UART Mode Register
#define uart_MR_REG 0x4U
typedef union uart_MR
{
	struct
	{
		uint32_t RESERVED_0 : 20;
		uint32_t RESERVED_1 : 1;
		uint32_t RESERVED_2 : 1;
		uint32_t CHMODE : 2;
		uint32_t NBSTOP : 2;
		uint32_t PAR : 3;
		uint32_t CHRL : 2;
		uint32_t CLKSEL : 1;
	} fields;
	uint32_t v;
} uart_MR;

#define uart_MR_RESERVED_0_LSHIFT 12U
#define uart_MR_RESERVED_0_MASK 0xfffff000U
#define uart_MR_RESERVED_1_LSHIFT 11U
#define uart_MR_RESERVED_1 0x800U
#define uart_MR_RESERVED_1_MASK 0x800U
#define uart_MR_RESERVED_2_LSHIFT 10U
#define uart_MR_RESERVED_2 0x400U
#define uart_MR_RESERVED_2_MASK 0x400U
#define uart_MR_CHMODE_LSHIFT 8U
#define uart_MR_CHMODE_MASK 0x300U
#define uart_MR_NBSTOP_LSHIFT 6U
#define uart_MR_NBSTOP_MASK 0xc0U
#define uart_MR_PAR_LSHIFT 3U
#define uart_MR_PAR_MASK 0x38U
#define uart_MR_CHRL_LSHIFT 1U
#define uart_MR_CHRL_MASK 0x6U
#define uart_MR_CLKSEL_LSHIFT 0U
#define uart_MR_CLKSEL 0x1U
#define uart_MR_CLKSEL_MASK 0x1U
#define uart_MR_MASK 0x3ffU


// Interrupt Enable Register
#define uart_IER_REG 0x8U
typedef union uart_IER
{
	struct
	{
		uint32_t RESERVED_0 : 19;
		uint32_t TOVR : 1;
		uint32_t TNFUL : 1;
		uint32_t TTRIG : 1;
		uint32_t DMS : 1;
		uint32_t TOUT : 1;
		uint32_t PARITY : 1;
		uint32_t FRAMING : 1;
		uint32_t OVER : 1;
		uint32_t TXFULL : 1;
		uint32_t TXEMPTY : 1;
		uint32_t RXFULL : 1;
		uint32_t RXEMPTY : 1;
		uint32_t RXOVR : 1;
	} fields;
	uint32_t v;
} uart_IER;

#define uart_IER_RESERVED_0_LSHIFT 13U
#define uart_IER_RESERVED_0_MASK 0xffffe000U
#define uart_IER_TOVR_LSHIFT 12U
#define uart_IER_TOVR 0x1000U
#define uart_IER_TOVR_MASK 0x1000U
#define uart_IER_TNFUL_LSHIFT 11U
#define uart_IER_TNFUL 0x800U
#define uart_IER_TNFUL_MASK 0x800U
#define uart_IER_TTRIG_LSHIFT 10U
#define uart_IER_TTRIG 0x400U
#define uart_IER_TTRIG_MASK 0x400U
#define uart_IER_DMS_LSHIFT 9U
#define uart_IER_DMS 0x200U
#define uart_IER_DMS_MASK 0x200U
#define uart_IER_TOUT_LSHIFT 8U
#define uart_IER_TOUT 0x100U
#define uart_IER_TOUT_MASK 0x100U
#define uart_IER_PARITY_LSHIFT 7U
#define uart_IER_PARITY 0x80U
#define uart_IER_PARITY_MASK 0x80U
#define uart_IER_FRAMING_LSHIFT 6U
#define uart_IER_FRAMING 0x40U
#define uart_IER_FRAMING_MASK 0x40U
#define uart_IER_OVER_LSHIFT 5U
#define uart_IER_OVER 0x20U
#define uart_IER_OVER_MASK 0x20U
#define uart_IER_TXFULL_LSHIFT 4U
#define uart_IER_TXFULL 0x10U
#define uart_IER_TXFULL_MASK 0x10U
#define uart_IER_TXEMPTY_LSHIFT 3U
#define uart_IER_TXEMPTY 0x8U
#define uart_IER_TXEMPTY_MASK 0x8U
#define uart_IER_RXFULL_LSHIFT 2U
#define uart_IER_RXFULL 0x4U
#define uart_IER_RXFULL_MASK 0x4U
#define uart_IER_RXEMPTY_LSHIFT 1U
#define uart_IER_RXEMPTY 0x2U
#define uart_IER_RXEMPTY_MASK 0x2U
#define uart_IER_RXOVR_LSHIFT 0U
#define uart_IER_RXOVR 0x1U
#define uart_IER_RXOVR_MASK 0x1U
#define uart_IER_MASK 0x1fffU


// Interrupt Disable Register
#define uart_IDR_REG 0xcU
typedef union uart_IDR
{
	struct
	{
		uint32_t RESERVED_0 : 19;
		uint32_t TOVR : 1;
		uint32_t TNFUL : 1;
		uint32_t TTRIG : 1;
		uint32_t DMS : 1;
		uint32_t TOUT : 1;
		uint32_t PARITY : 1;
		uint32_t FRAMING : 1;
		uint32_t OVER : 1;
		uint32_t TXFULL : 1;
		uint32_t TXEMPTY : 1;
		uint32_t RXFULL : 1;
		uint32_t RXEMPTY : 1;
		uint32_t RXOVR : 1;
	} fields;
	uint32_t v;
} uart_IDR;

#define uart_IDR_RESERVED_0_LSHIFT 13U
#define uart_IDR_RESERVED_0_MASK 0xffffe000U
#define uart_IDR_TOVR_LSHIFT 12U
#define uart_IDR_TOVR 0x1000U
#define uart_IDR_TOVR_MASK 0x1000U
#define uart_IDR_TNFUL_LSHIFT 11U
#define uart_IDR_TNFUL 0x800U
#define uart_IDR_TNFUL_MASK 0x800U
#define uart_IDR_TTRIG_LSHIFT 10U
#define uart_IDR_TTRIG 0x400U
#define uart_IDR_TTRIG_MASK 0x400U
#define uart_IDR_DMS_LSHIFT 9U
#define uart_IDR_DMS 0x200U
#define uart_IDR_DMS_MASK 0x200U
#define uart_IDR_TOUT_LSHIFT 8U
#define uart_IDR_TOUT 0x100U
#define uart_IDR_TOUT_MASK 0x100U
#define uart_IDR_PARITY_LSHIFT 7U
#define uart_IDR_PARITY 0x80U
#define uart_IDR_PARITY_MASK 0x80U
#define uart_IDR_FRAMING_LSHIFT 6U
#define uart_IDR_FRAMING 0x40U
#define uart_IDR_FRAMING_MASK 0x40U
#define uart_IDR_OVER_LSHIFT 5U
#define uart_IDR_OVER 0x20U
#define uart_IDR_OVER_MASK 0x20U
#define uart_IDR_TXFULL_LSHIFT 4U
#define uart_IDR_TXFULL 0x10U
#define uart_IDR_TXFULL_MASK 0x10U
#define uart_IDR_TXEMPTY_LSHIFT 3U
#define uart_IDR_TXEMPTY 0x8U
#define uart_IDR_TXEMPTY_MASK 0x8U
#define uart_IDR_RXFULL_LSHIFT 2U
#define uart_IDR_RXFULL 0x4U
#define uart_IDR_RXFULL_MASK 0x4U
#define uart_IDR_RXEMPTY_LSHIFT 1U
#define uart_IDR_RXEMPTY 0x2U
#define uart_IDR_RXEMPTY_MASK 0x2U
#define uart_IDR_RXOVR_LSHIFT 0U
#define uart_IDR_RXOVR 0x1U
#define uart_IDR_RXOVR_MASK 0x1U
#define uart_IDR_MASK 0x1fffU


// Interrupt Mask Register
#define uart_IMR_REG 0x10U
typedef union uart_IMR
{
	struct
	{
		uint32_t RESERVED_0 : 19;
		uint32_t TOVR : 1;
		uint32_t TNFUL : 1;
		uint32_t TTRIG : 1;
		uint32_t DMS : 1;
		uint32_t TOUT : 1;
		uint32_t PARITY : 1;
		uint32_t FRAMING : 1;
		uint32_t OVER : 1;
		uint32_t TXFULL : 1;
		uint32_t TXEMPTY : 1;
		uint32_t RXFULL : 1;
		uint32_t RXEMPTY : 1;
		uint32_t RXOVR : 1;
	} fields;
	uint32_t v;
} uart_IMR;

#define uart_IMR_RESERVED_0_LSHIFT 13U
#define uart_IMR_RESERVED_0_MASK 0xffffe000U
#define uart_IMR_TOVR_LSHIFT 12U
#define uart_IMR_TOVR 0x1000U
#define uart_IMR_TOVR_MASK 0x1000U
#define uart_IMR_TNFUL_LSHIFT 11U
#define uart_IMR_TNFUL 0x800U
#define uart_IMR_TNFUL_MASK 0x800U
#define uart_IMR_TTRIG_LSHIFT 10U
#define uart_IMR_TTRIG 0x400U
#define uart_IMR_TTRIG_MASK 0x400U
#define uart_IMR_DMS_LSHIFT 9U
#define uart_IMR_DMS 0x200U
#define uart_IMR_DMS_MASK 0x200U
#define uart_IMR_TOUT_LSHIFT 8U
#define uart_IMR_TOUT 0x100U
#define uart_IMR_TOUT_MASK 0x100U
#define uart_IMR_PARITY_LSHIFT 7U
#define uart_IMR_PARITY 0x80U
#define uart_IMR_PARITY_MASK 0x80U
#define uart_IMR_FRAMING_LSHIFT 6U
#define uart_IMR_FRAMING 0x40U
#define uart_IMR_FRAMING_MASK 0x40U
#define uart_IMR_OVER_LSHIFT 5U
#define uart_IMR_OVER 0x20U
#define uart_IMR_OVER_MASK 0x20U
#define uart_IMR_TXFULL_LSHIFT 4U
#define uart_IMR_TXFULL 0x10U
#define uart_IMR_TXFULL_MASK 0x10U
#define uart_IMR_TXEMPTY_LSHIFT 3U
#define uart_IMR_TXEMPTY 0x8U
#define uart_IMR_TXEMPTY_MASK 0x8U
#define uart_IMR_RXFULL_LSHIFT 2U
#define uart_IMR_RXFULL 0x4U
#define uart_IMR_RXFULL_MASK 0x4U
#define uart_IMR_RXEMPTY_LSHIFT 1U
#define uart_IMR_RXEMPTY 0x2U
#define uart_IMR_RXEMPTY_MASK 0x2U
#define uart_IMR_RXOVR_LSHIFT 0U
#define uart_IMR_RXOVR 0x1U
#define uart_IMR_RXOVR_MASK 0x1U
#define uart_IMR_MASK 0x1fffU


// Channel Interrupt Status Register
#define uart_ISR_REG 0x14U
typedef union uart_ISR
{
	struct
	{
		uint32_t RESERVED_0 : 19;
		uint32_t TOVR : 1;
		uint32_t L : 1;
		uint32_t G : 1;
		uint32_t DMS : 1;
		uint32_t TOUT : 1;
		uint32_t PARITY : 1;
		uint32_t FRAMING : 1;
		uint32_t OVER : 1;
		uint32_t TXFULL : 1;
		uint32_t TXEMPTY : 1;
		uint32_t RXFULL : 1;
		uint32_t RXEMPTY : 1;
		uint32_t RXOVR : 1;
	} fields;
	uint32_t v;
} uart_ISR;

#define uart_ISR_RESERVED_0_LSHIFT 13U
#define uart_ISR_RESERVED_0_MASK 0xffffe000U
#define uart_ISR_TOVR_LSHIFT 12U
#define uart_ISR_TOVR 0x1000U
#define uart_ISR_TOVR_MASK 0x1000U
#define uart_ISR_L_LSHIFT 11U
#define uart_ISR_L 0x800U
#define uart_ISR_L_MASK 0x800U
#define uart_ISR_G_LSHIFT 10U
#define uart_ISR_G 0x400U
#define uart_ISR_G_MASK 0x400U
#define uart_ISR_DMS_LSHIFT 9U
#define uart_ISR_DMS 0x200U
#define uart_ISR_DMS_MASK 0x200U
#define uart_ISR_TOUT_LSHIFT 8U
#define uart_ISR_TOUT 0x100U
#define uart_ISR_TOUT_MASK 0x100U
#define uart_ISR_PARITY_LSHIFT 7U
#define uart_ISR_PARITY 0x80U
#define uart_ISR_PARITY_MASK 0x80U
#define uart_ISR_FRAMING_LSHIFT 6U
#define uart_ISR_FRAMING 0x40U
#define uart_ISR_FRAMING_MASK 0x40U
#define uart_ISR_OVER_LSHIFT 5U
#define uart_ISR_OVER 0x20U
#define uart_ISR_OVER_MASK 0x20U
#define uart_ISR_TXFULL_LSHIFT 4U
#define uart_ISR_TXFULL 0x10U
#define uart_ISR_TXFULL_MASK 0x10U
#define uart_ISR_TXEMPTY_LSHIFT 3U
#define uart_ISR_TXEMPTY 0x8U
#define uart_ISR_TXEMPTY_MASK 0x8U
#define uart_ISR_RXFULL_LSHIFT 2U
#define uart_ISR_RXFULL 0x4U
#define uart_ISR_RXFULL_MASK 0x4U
#define uart_ISR_RXEMPTY_LSHIFT 1U
#define uart_ISR_RXEMPTY 0x2U
#define uart_ISR_RXEMPTY_MASK 0x2U
#define uart_ISR_RXOVR_LSHIFT 0U
#define uart_ISR_RXOVR 0x1U
#define uart_ISR_RXOVR_MASK 0x1U
#define uart_ISR_MASK 0x1fffU


// Baud Rate Generator Register.
#define uart_BAUD_RATE_GENERATOR_REG 0x18U
typedef union uart_BAUD_RATE_GENERATOR
{
	struct
	{
		uint32_t RESERVED_0 : 16;
		uint32_t CD : 16;
	} fields;
	uint32_t v;
} uart_BAUD_RATE_GENERATOR;

#define uart_BAUD_RATE_GENERATOR_RESERVED_0_LSHIFT 16U
#define uart_BAUD_RATE_GENERATOR_RESERVED_0_MASK 0xffff0000U
#define uart_BAUD_RATE_GENERATOR_CD_LSHIFT 0U
#define uart_BAUD_RATE_GENERATOR_CD_MASK 0xffffU
#define uart_BAUD_RATE_GENERATOR_MASK 0xffffU


// Receiver Timeout Register
#define uart_RXTOUT_REG 0x1cU
typedef union uart_RXTOUT
{
	struct
	{
		uint32_t RESERVED_0 : 24;
		uint32_t RTO : 8;
	} fields;
	uint32_t v;
} uart_RXTOUT;

#define uart_RXTOUT_RESERVED_0_LSHIFT 8U
#define uart_RXTOUT_RESERVED_0_MASK 0xffffff00U
#define uart_RXTOUT_RTO_LSHIFT 0U
#define uart_RXTOUT_RTO_MASK 0xffU
#define uart_RXTOUT_MASK 0xffU


// Receiver FIFO Trigger Level Register
#define uart_RX_FIFO_TRIGGER_LEVEL_REG 0x20U
typedef union uart_RX_FIFO_TRIGGER_LEVEL
{
	struct
	{
		uint32_t RESERVED_0 : 26;
		uint32_t TRIGGER : 6;
	} fields;
	uint32_t v;
} uart_RX_FIFO_TRIGGER_LEVEL;

#define uart_RX_FIFO_TRIGGER_LEVEL_RESERVED_0_LSHIFT 6U
#define uart_RX_FIFO_TRIGGER_LEVEL_RESERVED_0_MASK 0xffffffc0U
#define uart_RX_FIFO_TRIGGER_LEVEL_TRIGGER_LSHIFT 0U
#define uart_RX_FIFO_TRIGGER_LEVEL_TRIGGER_MASK 0x3fU
#define uart_RX_FIFO_TRIGGER_LEVEL_MASK 0x3fU


// Modem Control Register
#define uart_MODEMCR_REG 0x24U
typedef union uart_MODEMCR
{
	struct
	{
		uint32_t RESERVED_0 : 26;
		uint32_t FCM : 1;
		uint32_t RESERVED_1 : 3;
		uint32_t RTS : 1;
		uint32_t DTR : 1;
	} fields;
	uint32_t v;
} uart_MODEMCR;

#define uart_MODEMCR_RESERVED_0_LSHIFT 6U
#define uart_MODEMCR_RESERVED_0_MASK 0xffffffc0U
#define uart_MODEMCR_FCM_LSHIFT 5U
#define uart_MODEMCR_FCM 0x20U
#define uart_MODEMCR_FCM_MASK 0x20U
#define uart_MODEMCR_RESERVED_1_LSHIFT 2U
#define uart_MODEMCR_RESERVED_1_MASK 0x1cU
#define uart_MODEMCR_RTS_LSHIFT 1U
#define uart_MODEMCR_RTS 0x2U
#define uart_MODEMCR_RTS_MASK 0x2U
#define uart_MODEMCR_DTR_LSHIFT 0U
#define uart_MODEMCR_DTR 0x1U
#define uart_MODEMCR_DTR_MASK 0x1U
#define uart_MODEMCR_MASK 0x23U


// Trigger Level Register
#define uart_MODEMSR_REG 0x28U
typedef union uart_MODEMSR
{
	struct
	{
		uint32_t RESERVED_0 : 23;
		uint32_t FCMS : 1;
		uint32_t DCD : 1;
		uint32_t RI : 1;
		uint32_t DSR : 1;
		uint32_t CTS : 1;
		uint32_t MEDEMSR_DCDX : 1;
		uint32_t MEDEMSR_RIX : 1;
		uint32_t MEDEMSR_DSRX : 1;
		uint32_t MEDEMSR_CTSX : 1;
	} fields;
	uint32_t v;
} uart_MODEMSR;

#define uart_MODEMSR_RESERVED_0_LSHIFT 9U
#define uart_MODEMSR_RESERVED_0_MASK 0xfffffe00U
#define uart_MODEMSR_FCMS_LSHIFT 8U
#define uart_MODEMSR_FCMS 0x100U
#define uart_MODEMSR_FCMS_MASK 0x100U
#define uart_MODEMSR_DCD_LSHIFT 7U
#define uart_MODEMSR_DCD 0x80U
#define uart_MODEMSR_DCD_MASK 0x80U
#define uart_MODEMSR_RI_LSHIFT 6U
#define uart_MODEMSR_RI 0x40U
#define uart_MODEMSR_RI_MASK 0x40U
#define uart_MODEMSR_DSR_LSHIFT 5U
#define uart_MODEMSR_DSR 0x20U
#define uart_MODEMSR_DSR_MASK 0x20U
#define uart_MODEMSR_CTS_LSHIFT 4U
#define uart_MODEMSR_CTS 0x10U
#define uart_MODEMSR_CTS_MASK 0x10U
#define uart_MODEMSR_MEDEMSR_DCDX_LSHIFT 3U
#define uart_MODEMSR_MEDEMSR_DCDX 0x8U
#define uart_MODEMSR_MEDEMSR_DCDX_MASK 0x8U
#define uart_MODEMSR_MEDEMSR_RIX_LSHIFT 2U
#define uart_MODEMSR_MEDEMSR_RIX 0x4U
#define uart_MODEMSR_MEDEMSR_RIX_MASK 0x4U
#define uart_MODEMSR_MEDEMSR_DSRX_LSHIFT 1U
#define uart_MODEMSR_MEDEMSR_DSRX 0x2U
#define uart_MODEMSR_MEDEMSR_DSRX_MASK 0x2U
#define uart_MODEMSR_MEDEMSR_CTSX_LSHIFT 0U
#define uart_MODEMSR_MEDEMSR_CTSX 0x1U
#define uart_MODEMSR_MEDEMSR_CTSX_MASK 0x1U
#define uart_MODEMSR_MASK 0x1ffU


// Channel Status Register
#define uart_SR_REG 0x2cU
typedef union uart_SR
{
	struct
	{
		uint32_t RESERVED_0 : 17;
		uint32_t TNFUL : 1;
		uint32_t TTRIG : 1;
		uint32_t FLOWDEL : 1;
		uint32_t TACTIVE : 1;
		uint32_t RACTIVE : 1;
		uint32_t RESERVED_1 : 1;
		uint32_t RESERVED_2 : 1;
		uint32_t RESERVED_3 : 1;
		uint32_t RESERVED_4 : 1;
		uint32_t RESERVED_5 : 1;
		uint32_t TXFULL : 1;
		uint32_t TXEMPTY : 1;
		uint32_t RXFULL : 1;
		uint32_t RXEMPTY : 1;
		uint32_t RXOVR : 1;
	} fields;
	uint32_t v;
} uart_SR;

#define uart_SR_RESERVED_0_LSHIFT 15U
#define uart_SR_RESERVED_0_MASK 0xffff8000U
#define uart_SR_TNFUL_LSHIFT 14U
#define uart_SR_TNFUL 0x4000U
#define uart_SR_TNFUL_MASK 0x4000U
#define uart_SR_TTRIG_LSHIFT 13U
#define uart_SR_TTRIG 0x2000U
#define uart_SR_TTRIG_MASK 0x2000U
#define uart_SR_FLOWDEL_LSHIFT 12U
#define uart_SR_FLOWDEL 0x1000U
#define uart_SR_FLOWDEL_MASK 0x1000U
#define uart_SR_TACTIVE_LSHIFT 11U
#define uart_SR_TACTIVE 0x800U
#define uart_SR_TACTIVE_MASK 0x800U
#define uart_SR_RACTIVE_LSHIFT 10U
#define uart_SR_RACTIVE 0x400U
#define uart_SR_RACTIVE_MASK 0x400U
#define uart_SR_RESERVED_1_LSHIFT 9U
#define uart_SR_RESERVED_1 0x200U
#define uart_SR_RESERVED_1_MASK 0x200U
#define uart_SR_RESERVED_2_LSHIFT 8U
#define uart_SR_RESERVED_2 0x100U
#define uart_SR_RESERVED_2_MASK 0x100U
#define uart_SR_RESERVED_3_LSHIFT 7U
#define uart_SR_RESERVED_3 0x80U
#define uart_SR_RESERVED_3_MASK 0x80U
#define uart_SR_RESERVED_4_LSHIFT 6U
#define uart_SR_RESERVED_4 0x40U
#define uart_SR_RESERVED_4_MASK 0x40U
#define uart_SR_RESERVED_5_LSHIFT 5U
#define uart_SR_RESERVED_5 0x20U
#define uart_SR_RESERVED_5_MASK 0x20U
#define uart_SR_TXFULL_LSHIFT 4U
#define uart_SR_TXFULL 0x10U
#define uart_SR_TXFULL_MASK 0x10U
#define uart_SR_TXEMPTY_LSHIFT 3U
#define uart_SR_TXEMPTY 0x8U
#define uart_SR_TXEMPTY_MASK 0x8U
#define uart_SR_RXFULL_LSHIFT 2U
#define uart_SR_RXFULL 0x4U
#define uart_SR_RXFULL_MASK 0x4U
#define uart_SR_RXEMPTY_LSHIFT 1U
#define uart_SR_RXEMPTY 0x2U
#define uart_SR_RXEMPTY_MASK 0x2U
#define uart_SR_RXOVR_LSHIFT 0U
#define uart_SR_RXOVR 0x1U
#define uart_SR_RXOVR_MASK 0x1U
#define uart_SR_MASK 0x7c1fU


// Transmit and Receive FIFO
#define uart_FIFO_REG 0x30U
typedef union uart_FIFO
{
	struct
	{
		uint32_t RESERVED_0 : 24;
		uint32_t FIFO : 8;
	} fields;
	uint32_t v;
} uart_FIFO;

#define uart_FIFO_RESERVED_0_LSHIFT 8U
#define uart_FIFO_RESERVED_0_MASK 0xffffff00U
#define uart_FIFO_FIFO_LSHIFT 0U
#define uart_FIFO_FIFO_MASK 0xffU
#define uart_FIFO_MASK 0xffU


// Baud Rate Divider Register
#define uart_BAUD_RATE_DIVIDER_REG 0x34U
typedef union uart_BAUD_RATE_DIVIDER
{
	struct
	{
		uint32_t RESERVED_0 : 24;
		uint32_t BDIV : 8;
	} fields;
	uint32_t v;
} uart_BAUD_RATE_DIVIDER;

#define uart_BAUD_RATE_DIVIDER_RESERVED_0_LSHIFT 8U
#define uart_BAUD_RATE_DIVIDER_RESERVED_0_MASK 0xffffff00U
#define uart_BAUD_RATE_DIVIDER_BDIV_LSHIFT 0U
#define uart_BAUD_RATE_DIVIDER_BDIV_MASK 0xffU
#define uart_BAUD_RATE_DIVIDER_MASK 0xffU


// Flow Control Delay Register
#define uart_FLOW_DELAY_REG 0x38U
typedef union uart_FLOW_DELAY
{
	struct
	{
		uint32_t RESERVED_0 : 26;
		uint32_t FDEL : 6;
	} fields;
	uint32_t v;
} uart_FLOW_DELAY;

#define uart_FLOW_DELAY_RESERVED_0_LSHIFT 6U
#define uart_FLOW_DELAY_RESERVED_0_MASK 0xffffffc0U
#define uart_FLOW_DELAY_FDEL_LSHIFT 0U
#define uart_FLOW_DELAY_FDEL_MASK 0x3fU
#define uart_FLOW_DELAY_MASK 0x3fU


// Transmitter fifo trigger level
#define uart_TX_FIFO_TRIGGER_LEVEL_REG 0x44U
typedef union uart_TX_FIFO_TRIGGER_LEVEL
{
	struct
	{
		uint32_t RESERVED_0 : 26;
		uint32_t TRIGGER : 6;
	} fields;
	uint32_t v;
} uart_TX_FIFO_TRIGGER_LEVEL;

#define uart_TX_FIFO_TRIGGER_LEVEL_RESERVED_0_LSHIFT 6U
#define uart_TX_FIFO_TRIGGER_LEVEL_RESERVED_0_MASK 0xffffffc0U
#define uart_TX_FIFO_TRIGGER_LEVEL_TRIGGER_LSHIFT 0U
#define uart_TX_FIFO_TRIGGER_LEVEL_TRIGGER_MASK 0x3fU
#define uart_TX_FIFO_TRIGGER_LEVEL_MASK 0x3fU


