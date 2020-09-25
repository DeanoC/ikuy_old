#pragma once
// Copyright Deano Calver
// SPDX-License-Identifier: MIT
// Controller Area Network
// Auto-generated on Fri Sep 25 10:29:41 EEST 2020

#include <stdint.h>

// 2 banks of can chips
#define can0_BASE_ADDR 0xe0008000U
#define can1_BASE_ADDR 0xe0009000U

// Software Reset Register
#define can_XCANPS_SRR_OFFSET_OFFSET 0x00000000U

// Mode Select Register
#define can_XCANPS_MSR_OFFSET_OFFSET 0x00000004U

// Baud Rate Prescaler Register
#define can_XCANPS_BRPR_OFFSET_OFFSET 0x00000008U

// Bit Timing Register
#define can_XCANPS_BTR_OFFSET_OFFSET 0x0000000cU

// Error Counter Register
#define can_XCANPS_ECR_OFFSET_OFFSET 0x00000010U

// Error Status Register
#define can_XCANPS_ESR_OFFSET_OFFSET 0x00000014U

// Status Register
#define can_XCANPS_SR_OFFSET_OFFSET 0x00000018U

// Interrupt Status Register
#define can_XCANPS_ISR_OFFSET_OFFSET 0x0000001cU

// Interrupt Enable Register
#define can_XCANPS_IER_OFFSET_OFFSET 0x00000020U

// Interrupt Clear Register
#define can_XCANPS_ICR_OFFSET_OFFSET 0x00000024U

// Timestamp Control Register
#define can_XCANPS_TCR_OFFSET_OFFSET 0x00000028U

// Watermark Interrupt Register
#define can_XCANPS_WIR_OFFSET_OFFSET 0x0000002cU

// transmit message fifo message identifier
#define can_XCANPS_TXFIFO_ID_OFFSET_OFFSET 0x00000030U

// transmit message fifo data length code
#define can_XCANPS_TXFIFO_DLC_OFFSET_OFFSET 0x00000034U

// transmit message fifo data word 1
#define can_XCANPS_TXFIFO_DW1_OFFSET_OFFSET 0x00000038U

// transmit message fifo data word 2
#define can_XCANPS_TXFIFO_DW2_OFFSET_OFFSET 0x0000003cU

// transmit high priority buffer message identifier
#define can_XCANPS_TXHPB_ID_OFFSET_OFFSET 0x00000040U

// transmit high priority buffer data length code
#define can_XCANPS_TXHPB_DLC_OFFSET_OFFSET 0x00000044U

// transmit high priority buffer data word 1
#define can_XCANPS_TXHPB_DW1_OFFSET_OFFSET 0x00000048U

// transmit high priority buffer data word 2
#define can_XCANPS_TXHPB_DW2_OFFSET_OFFSET 0x0000004cU

// receive message fifo message identifier
#define can_XCANPS_RXFIFO_ID_OFFSET_OFFSET 0x00000050U

// receive message fifo data length code
#define can_XCANPS_RXFIFO_DLC_OFFSET_OFFSET 0x00000054U

// receive message fifo data word 1
#define can_XCANPS_RXFIFO_DW1_OFFSET_OFFSET 0x00000058U

// receive message fifo data word 2
#define can_XCANPS_RXFIFO_DW2_OFFSET_OFFSET 0x0000005cU

// Acceptance Filter Register
#define can_XCANPS_AFR_OFFSET_OFFSET 0x00000060U

// Acceptance Filter Mask Register 1
#define can_XCANPS_AFMR1_OFFSET_OFFSET 0x00000064U

// Acceptance Filter ID Register 1
#define can_XCANPS_AFIR1_OFFSET_OFFSET 0x00000068U

// Acceptance Filter Mask Register 2
#define can_XCANPS_AFMR2_OFFSET_OFFSET 0x0000006cU

// Acceptance Filter ID Register 2
#define can_XCANPS_AFIR2_OFFSET_OFFSET 0x00000070U

// Acceptance Filter Mask Register 3
#define can_XCANPS_AFMR3_OFFSET_OFFSET 0x00000074U

// Acceptance Filter ID Register 3
#define can_XCANPS_AFIR3_OFFSET_OFFSET 0x00000078U

// Acceptance Filter Mask Register 4
#define can_XCANPS_AFMR4_OFFSET_OFFSET 0x0000007cU

// Acceptance Filter ID Register 4
#define can_XCANPS_AFIR4_OFFSET_OFFSET 0x00000080U
