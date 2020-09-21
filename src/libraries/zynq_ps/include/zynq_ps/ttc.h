#pragma once
// Copyright Deano Calver
// SPDX-License-Identifier: MIT
// Triple Timer Counter
// Auto-generated on Mon Sep 21 21:57:55 EEST 2020

#include <stdint.h>

// 2 banks of ttc chips
#define ttc0_BASE_ADDR 0xf8001000U
#define ttc1_BASE_ADDR 0xf8002000U

// Clock Control register
#define ttc_CLK_CNTRL_0_OFFSET 0x00000000U

// Clock Control register
#define ttc_CLK_CNTRL_1_OFFSET 0x00000004U

// Clock Control register
#define ttc_CLK_CNTRL_2_OFFSET 0x00000008U

// Operational mode and reset
#define ttc_CNT_CNTRL_0_OFFSET 0x0000000cU

// Operational mode and reset
#define ttc_CNT_CNTRL_1_OFFSET 0x00000010U

// Operational mode and reset
#define ttc_CNT_CNTRL_2_OFFSET 0x00000014U

// Current counter value
#define ttc_CNT_0_OFFSET 0x00000018U

// Current counter value
#define ttc_CNT_1_OFFSET 0x0000001cU

// Current counter value
#define ttc_CNT_2_OFFSET 0x00000020U

// Interval value
#define ttc_INTERVAL_0_OFFSET 0x00000024U

// Interval value
#define ttc_INTERVAL_1_OFFSET 0x00000028U

// Interval value
#define ttc_INTERVAL_2_OFFSET 0x0000002cU

// Match value
#define ttc_MATCH_0_CNT_0_OFFSET 0x00000030U

// Match value
#define ttc_MATCH_0_CNT_1_OFFSET 0x00000034U

// Match value
#define ttc_MATCH_0_CNT_2_OFFSET 0x00000038U

// Match value
#define ttc_MATCH_1_CNT_0_OFFSET 0x0000003cU

// Match value
#define ttc_MATCH_1_CNT_1_OFFSET 0x00000040U

// Match value
#define ttc_MATCH_1_CNT_2_OFFSET 0x00000044U

// Match value
#define ttc_MATCH_2_CNT_0_OFFSET 0x00000048U

// Match value
#define ttc_MATCH_2_CNT_1_OFFSET 0x0000004cU

// Match value
#define ttc_MATCH_2_CNT_2_OFFSET 0x00000050U

// Counter 1 Interval, Match, Overflow and Event interrupts
#define ttc_ISR_0_OFFSET 0x00000054U

// Counter 2 Interval, Match, Overflow and Event interrupts
#define ttc_ISR_1_OFFSET 0x00000058U

// Counter 3 Interval, Match, Overflow and Event interrupts
#define ttc_ISR_2_OFFSET 0x0000005cU

// ANDed with corresponding Interrupt
#define ttc_IER_0_OFFSET 0x00000060U

// ANDed with corresponding Interrupt
#define ttc_IER_1_OFFSET 0x00000064U

// ANDed with corresponding Interrupt
#define ttc_IER_2_OFFSET 0x00000068U

// Enable, pulse and overflow
#define ttc_EVENT_TIMER_0_OFFSET 0x0000006cU

// Enable, pulse and overflow
#define ttc_EVENT_TIMER_1_OFFSET 0x00000070U

// Enable, pulse and overflow
#define ttc_EVENT_TIMER_2_OFFSET 0x00000074U

// pclk cycle count for event
#define ttc_EVENT_0_OFFSET 0x00000078U

// pclk cycle count for event
#define ttc_EVENT_1_OFFSET 0x0000007cU

// pclk cycle count for event
#define ttc_EVENT_2_OFFSET 0x00000080U
