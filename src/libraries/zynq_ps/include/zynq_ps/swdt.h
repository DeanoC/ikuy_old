#pragma once
// Copyright Deano Calver
// SPDX-License-Identifier: MIT
// System Watchdog Timer
// Auto-generated on Fri Sep 25 10:29:41 EEST 2020

#include <stdint.h>

// 1 banks of swdt chips
#define swdt_BASE_ADDR 0xf8005000U

// WD zero mode
#define swdt_ZMR_OFFSET 0x00000000U

// Counter Control
#define swdt_CCR_OFFSET 0x00000004U

// Restart key
#define swdt_RESTART_OFFSET 0x00000008U

// Status
#define swdt_SR_OFFSET 0x0000000cU
