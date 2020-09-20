#pragma once
// Copyright Deano Calver
// SPDX-License-Identifier: MIT
// Triple Timer Counter
// Auto-generated on Sun Sep 20 15:25:57 EEST 2020

#include <stdint.h>

// 2 banks of ttc chips
#define ttc0_BASE_ADDR 0xf8001000
#define ttc1_BASE_ADDR 0xf8002000

// Clock Control register
#define ttc_CLK_CNTRL_0_OFFSET 0x00000000

// Clock Control register
#define ttc_CLK_CNTRL_1_OFFSET 0x00000004

// Clock Control register
#define ttc_CLK_CNTRL_2_OFFSET 0x00000008

// Operational mode and reset
#define ttc_CNT_CNTRL_0_OFFSET 0x0000000c

// Operational mode and reset
#define ttc_CNT_CNTRL_1_OFFSET 0x00000010

// Operational mode and reset
#define ttc_CNT_CNTRL_2_OFFSET 0x00000014

// Current counter value
#define ttc_CNT_0_OFFSET 0x00000018

// Current counter value
#define ttc_CNT_1_OFFSET 0x0000001c

// Current counter value
#define ttc_CNT_2_OFFSET 0x00000020

// Interval value
#define ttc_INTERVAL_0_OFFSET 0x00000024

// Interval value
#define ttc_INTERVAL_1_OFFSET 0x00000028

// Interval value
#define ttc_INTERVAL_2_OFFSET 0x0000002c

// Match value
#define ttc_MATCH_0_CNT_0_OFFSET 0x00000030

// Match value
#define ttc_MATCH_0_CNT_1_OFFSET 0x00000034

// Match value
#define ttc_MATCH_0_CNT_2_OFFSET 0x00000038

// Match value
#define ttc_MATCH_1_CNT_0_OFFSET 0x0000003c

// Match value
#define ttc_MATCH_1_CNT_1_OFFSET 0x00000040

// Match value
#define ttc_MATCH_1_CNT_2_OFFSET 0x00000044

// Match value
#define ttc_MATCH_2_CNT_0_OFFSET 0x00000048

// Match value
#define ttc_MATCH_2_CNT_1_OFFSET 0x0000004c

// Match value
#define ttc_MATCH_2_CNT_2_OFFSET 0x00000050

// Counter 1 Interval, Match, Overflow and Event interrupts
#define ttc_ISR_0_OFFSET 0x00000054

// Counter 2 Interval, Match, Overflow and Event interrupts
#define ttc_ISR_1_OFFSET 0x00000058

// Counter 3 Interval, Match, Overflow and Event interrupts
#define ttc_ISR_2_OFFSET 0x0000005c

// ANDed with corresponding Interrupt
#define ttc_IER_0_OFFSET 0x00000060

// ANDed with corresponding Interrupt
#define ttc_IER_1_OFFSET 0x00000064

// ANDed with corresponding Interrupt
#define ttc_IER_2_OFFSET 0x00000068

// Enable, pulse and overflow
#define ttc_EVENT_TIMER_0_OFFSET 0x0000006c

// Enable, pulse and overflow
#define ttc_EVENT_TIMER_1_OFFSET 0x00000070

// Enable, pulse and overflow
#define ttc_EVENT_TIMER_2_OFFSET 0x00000074

// pclk cycle count for event
#define ttc_EVENT_0_OFFSET 0x00000078

// pclk cycle count for event
#define ttc_EVENT_1_OFFSET 0x0000007c

// pclk cycle count for event
#define ttc_EVENT_2_OFFSET 0x00000080
