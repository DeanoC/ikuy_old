#pragma once
// Copyright Deano Calver
// SPDX-License-Identifier: MIT
// USB Controller
// Auto-generated on Fri Sep 25 10:29:41 EEST 2020

#include <stdint.h>

// 2 banks of usb chips
#define usb0_BASE_ADDR 0xe0002000U
#define usb1_BASE_ADDR 0xe0003000U

// IP version and revision
#define usb_ID_OFFSET 0x00000000U

// Misc IP config constants
#define usb_HWGENERAL_OFFSET 0x00000004U

// Host Mode IP config constants
#define usb_HWHOST_OFFSET 0x00000008U

// Device Mode IP config constants
#define usb_HWDEVICE_OFFSET 0x0000000cU

// TxBuffer IP config constants
#define usb_HWTXBUF_OFFSET 0x00000010U

// IP constants, RX buffer constants
#define usb_HWRXBUF_OFFSET 0x00000014U

// GP Timer 0 Load Value.
#define usb_GPTIMER0LD_OFFSET 0x00000080U

// GP Timer 1 Control.
#define usb_GPTIMER0CTRL_OFFSET 0x00000084U

// GP Timer 1 Load Value
#define usb_GPTIMER1LD_OFFSET 0x00000088U

// GP Timer 1 Control
#define usb_GPTIMER1CTRL_OFFSET 0x0000008cU

// DMA Master AHB Burst Mode
#define usb_SBUSCFG_OFFSET 0x00000090U

// EHCI Addr Space and HCI constants
#define usb_CAPLENGTH_HCIVERSION_OFFSET 0x00000100U

// TT counts and EHCI HCS constants
#define usb_HCSPARAMS_OFFSET 0x00000104U

// EHCI Host Configuration Constants.
#define usb_HCCPARAMS_OFFSET 0x00000108U

// Device Controller Interface Version.
#define usb_DCIVERSION_OFFSET 0x00000120U

// EHCI, Device, and EndpointCapabilities.
#define usb_DCCPARAMS_OFFSET 0x00000124U

// USB Commands (EHCI extended)
#define usb_CMD_OFFSET 0x00000140U

// Interrupt/Raw Status (EHCI extended) (Host/Device)
#define usb_ISR_OFFSET 0x00000144U

// Interrrupts and Enables
#define usb_IER_OFFSET 0x00000148U

// Frame List Index
#define usb_FRAME_OFFSET 0x0000014cU

// Host/Device Address dual-use
#define usb_LISTBASE_OFFSET 0x00000154U

// Host/Device dual-use
#define usb_ASYNCLISTADDR_OFFSET 0x00000158U

// TT Control
#define usb_TTCTRL_OFFSET 0x0000015cU

// Burst Size
#define usb_BURSTSIZE_OFFSET 0x00000160U

// TxFIFO Fill Tuning
#define usb_TXFILL_OFFSET 0x00000164U

// TT TX latency FIFO
#define usb_TXTTFILLTUNING_OFFSET 0x00000168U

// Low and Fast Speed Control constants
#define usb_IC_USB_OFFSET 0x0000016cU

// ULPI Viewport
#define usb_ULPIVIEW_OFFSET 0x00000170U

// Endpoint NAK (Device mode)
#define usb_EPNAKISR_OFFSET 0x00000178U

// Endpoint NAK (Device mode)
#define usb_EPNAKIER_OFFSET 0x0000017cU

// reserved
#define usb_CONFIG_FLAG_OFFSET 0x00000180U

// Port Status & Control
#define usb_PORTSCR1_OFFSET 0x00000184U

// OTG Status and Control
#define usb_OTGCSR_OFFSET 0x000001a4U

// USB Mode Selection
#define usb_MODE_OFFSET 0x000001a8U

// Endpoint Status Setup (Device mode)
#define usb_EPSTAT_OFFSET 0x000001acU

// Endpoint Primer (Device mode)
#define usb_EPPRIME_OFFSET 0x000001b0U

// Endpoint Flush (Device mode)
#define usb_EPFLUSH_OFFSET 0x000001b4U

// Endpoint Buffer Ready Status (Device mode)
#define usb_EPRDY_OFFSET 0x000001b8U

// Endpoint Tx Complete (Device mode)
#define usb_EPCOMPL_OFFSET 0x000001bcU

// Endpoint 0 (Device mode)
#define usb_EPCR0_OFFSET 0x000001c0U

// Endpoints 1 to 11 (Device mode)
#define usb_ENDPTCTRL1_OFFSET 0x000001c4U

// Endpoints 1 to 11 (Device mode)
#define usb_ENDPTCTRL2_OFFSET 0x000001c8U

// Endpoints 1 to 11 (Device mode)
#define usb_ENDPTCTRL3_OFFSET 0x000001ccU

// Endpoints 1 to 11 (Device mode)
#define usb_ENDPTCTRL4_OFFSET 0x000001d0U

// Endpoints 1 to 11 (Device mode)
#define usb_ENDPTCTRL5_OFFSET 0x000001d4U

// Endpoints 1 to 11 (Device mode)
#define usb_ENDPTCTRL6_OFFSET 0x000001d8U

// Endpoints 1 to 11 (Device mode)
#define usb_ENDPTCTRL7_OFFSET 0x000001dcU

// Endpoints 1 to 11 (Device mode)
#define usb_ENDPTCTRL8_OFFSET 0x000001e0U

// Endpoints 1 to 11 (Device mode)
#define usb_ENDPTCTRL9_OFFSET 0x000001e4U

// Endpoints 1 to 11 (Device mode)
#define usb_ENDPTCTRL10_OFFSET 0x000001e8U

// Endpoints 1 to 11 (Device mode)
#define usb_ENDPTCTRL11_OFFSET 0x000001ecU
