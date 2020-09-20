#pragma once
// Copyright Deano Calver
// SPDX-License-Identifier: MIT
// L2 Cache PL310
// Auto-generated on Sun Sep 20 15:25:57 EEST 2020

#include <stdint.h>

// 1 banks of l2cache chips
#define l2cache_BASE_ADDR 0xf8f02000

// cache ID register, Returns the 32-bit device ID code it reads off the CACHEID input bus.
#define l2cache_CACHE_ID_OFFSET 0x00000000

// cache type register, Returns the 32-bit cache type.
#define l2cache_CACHE_TYPE_OFFSET 0x00000004

// control register
#define l2cache_CONTROL_OFFSET 0x00000100

// auxilary control register
#define l2cache_AUX_CONTROL_OFFSET 0x00000104

// Configures Tag RAM latencies
#define l2cache_TAG_RAM_CONTROL_OFFSET 0x00000108

// configures data RAM latencies
#define l2cache_DATA_RAM_CONTROL_OFFSET 0x0000010c

// Permits the event counters to beenabled and reset.
#define l2cache_EV_COUNTER_CTRL_OFFSET 0x00000200

// Enables event counter 1 to be driven by a specific event.
#define l2cache_EV_COUNTER1_CFG_OFFSET 0x00000204

// Enables event counter 0 to be driven by a specific event.
#define l2cache_EV_COUNTER0_CFG_OFFSET 0x00000208

// Enable the programmer to read off the counter value.
#define l2cache_EV_COUNTER1_OFFSET 0x0000020c

// Enable the programmer to read off the counter value.
#define l2cache_EV_COUNTER0_OFFSET 0x00000210

// Enables or masks interrupts from being triggered on the external pins of the cache controller.
#define l2cache_INT_MASK_OFFSET 0x00000214

// It returns the masked interrupt status.
#define l2cache_INT_MASK_STATUS_OFFSET 0x00000218

// The Raw Interrupt Status Register enables the interrupt status that excludes the masking logic.
#define l2cache_INT_RAW_STATUS_OFFSET 0x0000021c

// Clears the Raw Interrupt Status Register bits.
#define l2cache_INT_CLEAR_OFFSET 0x00000220

// Drain the STB. Operation complete when all buffers, LRB, LFB, STB, and EB, are empty
#define l2cache_CACHE_SYNC_OFFSET 0x00000730

// Invalidate Line by PA: Specific L2 cache line is marked as not valid
#define l2cache_INV_PA_OFFSET 0x00000770

// Invalidate by Way Invalidate all data in specified ways, including dirty data.
#define l2cache_INV_WAY_OFFSET 0x0000077c

// Clean Line by PA Write the specific L2 cache line to L3 main memory if the line is marked as valid and dirty
#define l2cache_CLEAN_PA_OFFSET 0x000007b0

// Clean Line by Set/Way Write the specific L2 cache line within the specified way to L3 main memory if the line is marked as valid and dirty.
#define l2cache_CLEAN_INDEX_OFFSET 0x000007b8

// Clean by Way Writes each line of the specified L2 cache ways to L3 main memory if the line is marked as valid and dirty
#define l2cache_CLEAN_WAY_OFFSET 0x000007bc

// Clean and Invalidate Line by PA Write the specific L2 cache line to L3 main memory if the line is marked as valid and dirty.
#define l2cache_CLEAN_INV_PA_OFFSET 0x000007f0

// Clean and Invalidate Line by Set/Way Write the specific L2 cache line within the specified way to L3 main memory if the line is marked as valid and dirty.
#define l2cache_CLEAN_INV_INDEX_OFFSET 0x000007f8

// Clean and Invalidate by Way Writes each line of the specified L2 cache ways to L3 main memory if the line is marked as valid and dirty.
#define l2cache_CLEAN_INV_WAY_OFFSET 0x000007fc

// All Lockdown registers can prevent new addresses from being allocated and can also prevent data from being evicted out of the L2 cache.
#define l2cache_DATA_LOCKDOWN0_OFFSET 0x00000900

// Instruction lock down 0
#define l2cache_INST_LOCKDOWN0_OFFSET 0x00000904

// instruction lock down 1
#define l2cache_INST_LOCKDOWN1_OFFSET 0x0000090c

// instruction lock down 1
#define l2cache_INST_LOCKDOWN1_OFFSET 0x0000090c

// data lock down 2
#define l2cache_DATA_LOCKDOWN2_OFFSET 0x00000910

// instruction lock down 2
#define l2cache_INST_LOCKDOWN2_OFFSET 0x00000914

// data lock down 3
#define l2cache_DATA_LOCKDOWN3_OFFSET 0x00000918

// instruction lock down 3
#define l2cache_INST_LOCKDOWN3_OFFSET 0x0000091c

// data lock down 4
#define l2cache_DATA_LOCKDOWN4_OFFSET 0x00000920

// instruction lock down 4
#define l2cache_INST_LOCKDOWN4_OFFSET 0x00000924

// data lock down 5
#define l2cache_DATA_LOCKDOWN5_OFFSET 0x00000928

// instruction lock down 5
#define l2cache_INST_LOCKDOWN5_OFFSET 0x0000092c

// data lock down 6
#define l2cache_DATA_LOCKDOWN6_OFFSET 0x00000930

// instruction lock down 6
#define l2cache_INST_LOCKDOWN6_OFFSET 0x00000934

// data lock down 7
#define l2cache_DATA_LOCKDOWN7_OFFSET 0x00000938

// instruction lock down 7
#define l2cache_INST_LOCKDOWN7_OFFSET 0x0000093c

// Lockdown by Line Enable
#define l2cache_LOCK_LINE_EN_OFFSET 0x00000950

// Cache lockdown by way
#define l2cache_UNLOCK_WAY_OFFSET 0x00000954

// Redirect a whole address range to master 1 (M1)
#define l2cache_ADDR_FILTERING_START_OFFSET 0x00000c00

// Redirect a whole address range to master 1 (M1)
#define l2cache_ADDR_FILTERING_END_OFFSET 0x00000c04

// The Debug Control Register forces specific cache behavior required for debug.
#define l2cache_DEBUG_CTRL_OFFSET 0x00000f40

// Purpose Enables prefetch-related features that can improve system performance.
#define l2cache_PREFETCH_CTRL_OFFSET 0x00000f60

// Purpose Controls the operating mode clock and power modes.
#define l2cache_POWER_CTRL_OFFSET 0x00000f80
