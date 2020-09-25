#pragma once
// Copyright Deano Calver
// SPDX-License-Identifier: MIT
// Auto-generated on Fri Sep 25 10:29:41 EEST 2020
// Dissy is a display chip for HDMI output.
// Uses multiple clocks :
// 1 pixel clock of the display resolution.
// 2.Axi clock for the interface 
//     

#include <stdint.h>
#define Dissy_BASE_ADDR 0x40000008U

// 24 bit colour for background/solid colour
#define Dissy_BACKGROUND_COLOUR_OFFSET 0x00000004U

// Parameter for the display output
#define Dissy_DISP_CTRL0_OFFSET 0x00000000U
