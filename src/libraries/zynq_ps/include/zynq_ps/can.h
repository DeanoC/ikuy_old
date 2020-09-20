#pragma once
// Copyright Deano Calver
// SPDX-License-Identifier: MIT
// Controller Area Network
// Auto-generated on Sun Sep 20 15:25:57 EEST 2020

#include <stdint.h>

// 2 banks of can chips
#define can0_BASE_ADDR 0xe0008000
#define can1_BASE_ADDR 0xe0009000

// Software Reset Register
#define can_XCANPS_SRR_OFFSET_OFFSET 0x00000000

// Mode Select Register
#define can_XCANPS_MSR_OFFSET_OFFSET 0x00000004

// Baud Rate Prescaler Register
#define can_XCANPS_BRPR_OFFSET_OFFSET 0x00000008

// Bit Timing Register
#define can_XCANPS_BTR_OFFSET_OFFSET 0x0000000c

// Error Counter Register
#define can_XCANPS_ECR_OFFSET_OFFSET 0x00000010

// Error Status Register
#define can_XCANPS_ESR_OFFSET_OFFSET 0x00000014

// Status Register
#define can_XCANPS_SR_OFFSET_OFFSET 0x00000018

// Interrupt Status Register
#define can_XCANPS_ISR_OFFSET_OFFSET 0x0000001c

// Interrupt Enable Register
#define can_XCANPS_IER_OFFSET_OFFSET 0x00000020

// Interrupt Clear Register
#define can_XCANPS_ICR_OFFSET_OFFSET 0x00000024

// Timestamp Control Register
#define can_XCANPS_TCR_OFFSET_OFFSET 0x00000028

// Watermark Interrupt Register
#define can_XCANPS_WIR_OFFSET_OFFSET 0x0000002c

// transmit message fifo message identifier
#define can_XCANPS_TXFIFO_ID_OFFSET_OFFSET 0x00000030

// transmit message fifo data length code
#define can_XCANPS_TXFIFO_DLC_OFFSET_OFFSET 0x00000034

// transmit message fifo data word 1
#define can_XCANPS_TXFIFO_DW1_OFFSET_OFFSET 0x00000038

// transmit message fifo data word 2
#define can_XCANPS_TXFIFO_DW2_OFFSET_OFFSET 0x0000003c

// transmit high priority buffer message identifier
#define can_XCANPS_TXHPB_ID_OFFSET_OFFSET 0x00000040

// transmit high priority buffer data length code
#define can_XCANPS_TXHPB_DLC_OFFSET_OFFSET 0x00000044

// transmit high priority buffer data word 1
#define can_XCANPS_TXHPB_DW1_OFFSET_OFFSET 0x00000048

// transmit high priority buffer data word 2
#define can_XCANPS_TXHPB_DW2_OFFSET_OFFSET 0x0000004c

// receive message fifo message identifier
#define can_XCANPS_RXFIFO_ID_OFFSET_OFFSET 0x00000050

// receive message fifo data length code
#define can_XCANPS_RXFIFO_DLC_OFFSET_OFFSET 0x00000054

// receive message fifo data word 1
#define can_XCANPS_RXFIFO_DW1_OFFSET_OFFSET 0x00000058

// receive message fifo data word 2
#define can_XCANPS_RXFIFO_DW2_OFFSET_OFFSET 0x0000005c

// Acceptance Filter Register
#define can_XCANPS_AFR_OFFSET_OFFSET 0x00000060

// Acceptance Filter Mask Register 1
#define can_XCANPS_AFMR1_OFFSET_OFFSET 0x00000064

// Acceptance Filter ID Register 1
#define can_XCANPS_AFIR1_OFFSET_OFFSET 0x00000068

// Acceptance Filter Mask Register 2
#define can_XCANPS_AFMR2_OFFSET_OFFSET 0x0000006c

// Acceptance Filter ID Register 2
#define can_XCANPS_AFIR2_OFFSET_OFFSET 0x00000070

// Acceptance Filter Mask Register 3
#define can_XCANPS_AFMR3_OFFSET_OFFSET 0x00000074

// Acceptance Filter ID Register 3
#define can_XCANPS_AFIR3_OFFSET_OFFSET 0x00000078

// Acceptance Filter Mask Register 4
#define can_XCANPS_AFMR4_OFFSET_OFFSET 0x0000007c

// Acceptance Filter ID Register 4
#define can_XCANPS_AFIR4_OFFSET_OFFSET 0x00000080
