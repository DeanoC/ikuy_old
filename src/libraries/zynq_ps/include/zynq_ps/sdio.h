#pragma once
// Copyright Deano Calver
// SPDX-License-Identifier: MIT
// SD2.0/SDIO2.0/MMC3.31
// Auto-generated on Sun Sep 20 15:25:57 EEST 2020

#include <stdint.h>

// 2 banks of sdio chips
#define sd0_BASE_ADDR 0xe0100000
#define sd1_BASE_ADDR 0xe0101000

// System DMA Address Register
#define sdio_SDMA_SYSTEM_ADDRESS_OFFSET 0x00000000

// Block size register
#define sdio_BLOCK_SIZE_OFFSET 0x00000004

// Argument register
#define sdio_ARGUMENT_OFFSET 0x00000008

// Transfer mode register command register
#define sdio_TRANSFER_CMD_OFFSET 0x0000000c

// Response register
#define sdio_RESPONSE0_OFFSET 0x00000010

// Response register
#define sdio_RESPONSE1_OFFSET 0x00000014

// Response register
#define sdio_RESPONSE2_OFFSET 0x00000018

// Response register
#define sdio_RESPONSE3_OFFSET 0x0000001c

// Buffer data port register
#define sdio_BUFFER_DATA_OFFSET 0x00000020

// Present State register
#define sdio_PRESENT_STATE_OFFSET 0x00000024

// Host control register Power control register Block gap control register Wake-up control register
#define sdio_HOST_CTRL_OFFSET 0x00000028

// Clock Control register Timeout control register Software reset register
#define sdio_CLOCK_CTRL_OFFSET 0x0000002c

// Normal interrupt status register
#define sdio_INTERRUPT_STATUS_OFFSET 0x00000030

// Normal interrupt status enable register
#define sdio_INTERRUPT_STATUS_EN_OFFSET 0x00000034

// Normal interrupt signal enable register
#define sdio_INTERRUPT_SIGNAL_E_OFFSET 0x00000038

// Auto CMD12 error status register
#define sdio_AUTO_CMD12_STATUS_OFFSET 0x0000003c

// Capabilities register
#define sdio_CAPABILITIES_OFFSET 0x00000040

// Maximum current capabilities register
#define sdio_CURRENT_CAPS_OFFSET 0x00000048

// Force event register for Auto CMD12 error status register
#define sdio_FORCE_AUTO_CMD12_STATUS_OFFSET 0x00000050

// ADMA error status register
#define sdio_ADMA_ERROR_STATUS_OFFSET 0x00000054

// ADMA system address register
#define sdio_ADMA_SYSTEM_ADDRESS_OFFSET 0x00000058

// Boot Timeout control register
#define sdio_BOOT_TIMEOUT_CTRL_OFFSET 0x00000060

// Debug Selection Register
#define sdio_DEBUG_SEL_OFFSET 0x00000064

// SPI interrupt support register
#define sdio_SPI_INTERRUPT_SUPPORT_OFFSET 0x000000f0

// Slot interrupt status register and Host controller version register
#define sdio_SLOT_INTERRUPT_STATUS_OFFSET 0x000000fc
