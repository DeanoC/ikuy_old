#pragma once
// Copyright Deano Calver
// SPDX-License-Identifier: MIT
// System Watchdog Timer
// Auto-generated on Sun Sep 20 15:25:57 EEST 2020

#include <stdint.h>

// 1 banks of swdt chips
#define swdt_BASE_ADDR 0xf8005000

// WD zero mode
#define swdt_ZMR_OFFSET 0x00000000

// Counter Control
#define swdt_CCR_OFFSET 0x00000004

// Restart key
#define swdt_RESTART_OFFSET 0x00000008

// Status
#define swdt_SR_OFFSET 0x0000000c
