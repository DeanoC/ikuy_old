#pragma once
// Copyright Deano Calver
// SPDX-License-Identifier: MIT
// Auto-generated on Mon Sep 21 19:32:27 EEST 2020
// A test chip that is used to check bus is working okay.
// Provides 2 registers, one that can store a 32 bit value
// and the other which returns a constant that is the local
// address of the register (0x4) currently

#include <stdint.h>
#define BuggyBoy_BASE_ADDR 0x40000000U

// A 32 bit R/W register to test bus is working
#define Test0_OFFSET 0x00000000U

// Returns the address of this register
#define Reflect1_OFFSET 0x00000004U
