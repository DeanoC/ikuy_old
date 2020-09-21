#pragma once
// Copyright Deano Calver
// SPDX-License-Identifier: MIT
// SD2.0/SDIO2.0/MMC3.31
// Auto-generated on Mon Sep 21 19:32:27 EEST 2020

#include <stdint.h>

// 2 banks of sdio chips
#define sd0_BASE_ADDR 0xe0100000U
#define sd1_BASE_ADDR 0xe0101000U

// System DMA Address Register
#define sdio_SDMA_SYSTEM_ADDRESS_OFFSET 0x00000000U

// Block size register
#define sdio_BLOCK_SIZE_OFFSET 0x00000004U

// Argument register
#define sdio_ARGUMENT_OFFSET 0x00000008U

// Transfer mode register command register
#define sdio_TRANSFER_CMD_OFFSET 0x0000000cU

// Response register
#define sdio_RESPONSE0_OFFSET 0x00000010U

// Response register
#define sdio_RESPONSE1_OFFSET 0x00000014U

// Response register
#define sdio_RESPONSE2_OFFSET 0x00000018U

// Response register
#define sdio_RESPONSE3_OFFSET 0x0000001cU

// Buffer data port register
#define sdio_BUFFER_DATA_OFFSET 0x00000020U

// Present State register
#define sdio_PRESENT_STATE_OFFSET 0x00000024U

// Host control register Power control register Block gap control register Wake-up control register
#define sdio_HOST_CTRL_OFFSET 0x00000028U

// Clock Control register Timeout control register Software reset register
#define sdio_CLOCK_CTRL_OFFSET 0x0000002cU

// Normal interrupt status register
#define sdio_INTERRUPT_STATUS_OFFSET 0x00000030U

// Normal interrupt status enable register
#define sdio_INTERRUPT_STATUS_EN_OFFSET 0x00000034U

// Normal interrupt signal enable register
#define sdio_INTERRUPT_SIGNAL_E_OFFSET 0x00000038U

// Auto CMD12 error status register
#define sdio_AUTO_CMD12_STATUS_OFFSET 0x0000003cU

// Capabilities register
#define sdio_CAPABILITIES_OFFSET 0x00000040U

// Maximum current capabilities register
#define sdio_CURRENT_CAPS_OFFSET 0x00000048U

// Force event register for Auto CMD12 error status register
#define sdio_FORCE_AUTO_CMD12_STATUS_OFFSET 0x00000050U

// ADMA error status register
#define sdio_ADMA_ERROR_STATUS_OFFSET 0x00000054U

// ADMA system address register
#define sdio_ADMA_SYSTEM_ADDRESS_OFFSET 0x00000058U

// Boot Timeout control register
#define sdio_BOOT_TIMEOUT_CTRL_OFFSET 0x00000060U

// Debug Selection Register
#define sdio_DEBUG_SEL_OFFSET 0x00000064U

// SPI interrupt support register
#define sdio_SPI_INTERRUPT_SUPPORT_OFFSET 0x000000f0U

// Slot interrupt status register and Host controller version register
#define sdio_SLOT_INTERRUPT_STATUS_OFFSET 0x000000fcU
