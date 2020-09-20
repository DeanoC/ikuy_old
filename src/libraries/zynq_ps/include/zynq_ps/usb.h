#pragma once
// Copyright Deano Calver
// SPDX-License-Identifier: MIT
// USB Controller
// Auto-generated on Sun Sep 20 15:25:57 EEST 2020

#include <stdint.h>

// 2 banks of usb chips
#define usb0_BASE_ADDR 0xe0002000
#define usb1_BASE_ADDR 0xe0003000

// IP version and revision
#define usb_ID_OFFSET 0x00000000

// Misc IP config constants
#define usb_HWGENERAL_OFFSET 0x00000004

// Host Mode IP config constants
#define usb_HWHOST_OFFSET 0x00000008

// Device Mode IP config constants
#define usb_HWDEVICE_OFFSET 0x0000000c

// TxBuffer IP config constants
#define usb_HWTXBUF_OFFSET 0x00000010

// IP constants, RX buffer constants
#define usb_HWRXBUF_OFFSET 0x00000014

// GP Timer 0 Load Value.
#define usb_GPTIMER0LD_OFFSET 0x00000080

// GP Timer 1 Control.
#define usb_GPTIMER0CTRL_OFFSET 0x00000084

// GP Timer 1 Load Value
#define usb_GPTIMER1LD_OFFSET 0x00000088

// GP Timer 1 Control
#define usb_GPTIMER1CTRL_OFFSET 0x0000008c

// DMA Master AHB Burst Mode
#define usb_SBUSCFG_OFFSET 0x00000090

// EHCI Addr Space and HCI constants
#define usb_CAPLENGTH_HCIVERSION_OFFSET 0x00000100

// TT counts and EHCI HCS constants
#define usb_HCSPARAMS_OFFSET 0x00000104

// EHCI Host Configuration Constants.
#define usb_HCCPARAMS_OFFSET 0x00000108

// Device Controller Interface Version.
#define usb_DCIVERSION_OFFSET 0x00000120

// EHCI, Device, and EndpointCapabilities.
#define usb_DCCPARAMS_OFFSET 0x00000124

// USB Commands (EHCI extended)
#define usb_CMD_OFFSET 0x00000140

// Interrupt/Raw Status (EHCI extended) (Host/Device)
#define usb_ISR_OFFSET 0x00000144

// Interrrupts and Enables
#define usb_IER_OFFSET 0x00000148

// Frame List Index
#define usb_FRAME_OFFSET 0x0000014c

// Host/Device Address dual-use
#define usb_LISTBASE_OFFSET 0x00000154

// Host/Device dual-use
#define usb_ASYNCLISTADDR_OFFSET 0x00000158

// TT Control
#define usb_TTCTRL_OFFSET 0x0000015c

// Burst Size
#define usb_BURSTSIZE_OFFSET 0x00000160

// TxFIFO Fill Tuning
#define usb_TXFILL_OFFSET 0x00000164

// TT TX latency FIFO
#define usb_TXTTFILLTUNING_OFFSET 0x00000168

// Low and Fast Speed Control constants
#define usb_IC_USB_OFFSET 0x0000016c

// ULPI Viewport
#define usb_ULPIVIEW_OFFSET 0x00000170

// Endpoint NAK (Device mode)
#define usb_EPNAKISR_OFFSET 0x00000178

// Endpoint NAK (Device mode)
#define usb_EPNAKIER_OFFSET 0x0000017c

// reserved
#define usb_CONFIG_FLAG_OFFSET 0x00000180

// Port Status & Control
#define usb_PORTSCR1_OFFSET 0x00000184

// OTG Status and Control
#define usb_OTGCSR_OFFSET 0x000001a4

// USB Mode Selection
#define usb_MODE_OFFSET 0x000001a8

// Endpoint Status Setup (Device mode)
#define usb_EPSTAT_OFFSET 0x000001ac

// Endpoint Primer (Device mode)
#define usb_EPPRIME_OFFSET 0x000001b0

// Endpoint Flush (Device mode)
#define usb_EPFLUSH_OFFSET 0x000001b4

// Endpoint Buffer Ready Status (Device mode)
#define usb_EPRDY_OFFSET 0x000001b8

// Endpoint Tx Complete (Device mode)
#define usb_EPCOMPL_OFFSET 0x000001bc

// Endpoint 0 (Device mode)
#define usb_EPCR0_OFFSET 0x000001c0

// Endpoints 1 to 11 (Device mode)
#define usb_ENDPTCTRL1_OFFSET 0x000001c4

// Endpoints 1 to 11 (Device mode)
#define usb_ENDPTCTRL2_OFFSET 0x000001c8

// Endpoints 1 to 11 (Device mode)
#define usb_ENDPTCTRL3_OFFSET 0x000001cc

// Endpoints 1 to 11 (Device mode)
#define usb_ENDPTCTRL4_OFFSET 0x000001d0

// Endpoints 1 to 11 (Device mode)
#define usb_ENDPTCTRL5_OFFSET 0x000001d4

// Endpoints 1 to 11 (Device mode)
#define usb_ENDPTCTRL6_OFFSET 0x000001d8

// Endpoints 1 to 11 (Device mode)
#define usb_ENDPTCTRL7_OFFSET 0x000001dc

// Endpoints 1 to 11 (Device mode)
#define usb_ENDPTCTRL8_OFFSET 0x000001e0

// Endpoints 1 to 11 (Device mode)
#define usb_ENDPTCTRL9_OFFSET 0x000001e4

// Endpoints 1 to 11 (Device mode)
#define usb_ENDPTCTRL10_OFFSET 0x000001e8

// Endpoints 1 to 11 (Device mode)
#define usb_ENDPTCTRL11_OFFSET 0x000001ec
