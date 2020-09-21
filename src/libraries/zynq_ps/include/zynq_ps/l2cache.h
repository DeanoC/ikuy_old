#pragma once
// Copyright Deano Calver
// SPDX-License-Identifier: MIT
// L2 Cache PL310
// Auto-generated on Mon Sep 21 17:18:27 EEST 2020

#include <stdint.h>

// 1 banks of l2cache chips
#define l2cache_BASE_ADDR 0xf8f02000U

// cache ID register, Returns the 32-bit device ID code it reads off the CACHEID input bus.
#define l2cache_CACHE_ID_OFFSET 0x00000000U

// cache type register, Returns the 32-bit cache type.
#define l2cache_CACHE_TYPE_OFFSET 0x00000004U

// control register
#define l2cache_CONTROL_OFFSET 0x00000100U

// auxilary control register
#define l2cache_AUX_CONTROL_OFFSET 0x00000104U

// Configures Tag RAM latencies
#define l2cache_TAG_RAM_CONTROL_OFFSET 0x00000108U

// configures data RAM latencies
#define l2cache_DATA_RAM_CONTROL_OFFSET 0x0000010cU

// Permits the event counters to beenabled and reset.
#define l2cache_EV_COUNTER_CTRL_OFFSET 0x00000200U

// Enables event counter 1 to be driven by a specific event.
#define l2cache_EV_COUNTER1_CFG_OFFSET 0x00000204U

// Enables event counter 0 to be driven by a specific event.
#define l2cache_EV_COUNTER0_CFG_OFFSET 0x00000208U

// Enable the programmer to read off the counter value.
#define l2cache_EV_COUNTER1_OFFSET 0x0000020cU

// Enable the programmer to read off the counter value.
#define l2cache_EV_COUNTER0_OFFSET 0x00000210U

// Enables or masks interrupts from being triggered on the external pins of the cache controller.
#define l2cache_INT_MASK_OFFSET 0x00000214U

// It returns the masked interrupt status.
#define l2cache_INT_MASK_STATUS_OFFSET 0x00000218U

// The Raw Interrupt Status Register enables the interrupt status that excludes the masking logic.
#define l2cache_INT_RAW_STATUS_OFFSET 0x0000021cU

// Clears the Raw Interrupt Status Register bits.
#define l2cache_INT_CLEAR_OFFSET 0x00000220U

// Drain the STB. Operation complete when all buffers, LRB, LFB, STB, and EB, are empty
#define l2cache_CACHE_SYNC_OFFSET 0x00000730U

// Invalidate Line by PA: Specific L2 cache line is marked as not valid
#define l2cache_INV_PA_OFFSET 0x00000770U

// Invalidate by Way Invalidate all data in specified ways, including dirty data.
#define l2cache_INV_WAY_OFFSET 0x0000077cU

// Clean Line by PA Write the specific L2 cache line to L3 main memory if the line is marked as valid and dirty
#define l2cache_CLEAN_PA_OFFSET 0x000007b0U

// Clean Line by Set/Way Write the specific L2 cache line within the specified way to L3 main memory if the line is marked as valid and dirty.
#define l2cache_CLEAN_INDEX_OFFSET 0x000007b8U

// Clean by Way Writes each line of the specified L2 cache ways to L3 main memory if the line is marked as valid and dirty
#define l2cache_CLEAN_WAY_OFFSET 0x000007bcU

// Clean and Invalidate Line by PA Write the specific L2 cache line to L3 main memory if the line is marked as valid and dirty.
#define l2cache_CLEAN_INV_PA_OFFSET 0x000007f0U

// Clean and Invalidate Line by Set/Way Write the specific L2 cache line within the specified way to L3 main memory if the line is marked as valid and dirty.
#define l2cache_CLEAN_INV_INDEX_OFFSET 0x000007f8U

// Clean and Invalidate by Way Writes each line of the specified L2 cache ways to L3 main memory if the line is marked as valid and dirty.
#define l2cache_CLEAN_INV_WAY_OFFSET 0x000007fcU

// All Lockdown registers can prevent new addresses from being allocated and can also prevent data from being evicted out of the L2 cache.
#define l2cache_DATA_LOCKDOWN0_OFFSET 0x00000900U

// Instruction lock down 0
#define l2cache_INST_LOCKDOWN0_OFFSET 0x00000904U

// instruction lock down 1
#define l2cache_INST_LOCKDOWN1_OFFSET 0x0000090cU

// instruction lock down 1
#define l2cache_INST_LOCKDOWN1_OFFSET 0x0000090cU

// data lock down 2
#define l2cache_DATA_LOCKDOWN2_OFFSET 0x00000910U

// instruction lock down 2
#define l2cache_INST_LOCKDOWN2_OFFSET 0x00000914U

// data lock down 3
#define l2cache_DATA_LOCKDOWN3_OFFSET 0x00000918U

// instruction lock down 3
#define l2cache_INST_LOCKDOWN3_OFFSET 0x0000091cU

// data lock down 4
#define l2cache_DATA_LOCKDOWN4_OFFSET 0x00000920U

// instruction lock down 4
#define l2cache_INST_LOCKDOWN4_OFFSET 0x00000924U

// data lock down 5
#define l2cache_DATA_LOCKDOWN5_OFFSET 0x00000928U

// instruction lock down 5
#define l2cache_INST_LOCKDOWN5_OFFSET 0x0000092cU

// data lock down 6
#define l2cache_DATA_LOCKDOWN6_OFFSET 0x00000930U

// instruction lock down 6
#define l2cache_INST_LOCKDOWN6_OFFSET 0x00000934U

// data lock down 7
#define l2cache_DATA_LOCKDOWN7_OFFSET 0x00000938U

// instruction lock down 7
#define l2cache_INST_LOCKDOWN7_OFFSET 0x0000093cU

// Lockdown by Line Enable
#define l2cache_LOCK_LINE_EN_OFFSET 0x00000950U

// Cache lockdown by way
#define l2cache_UNLOCK_WAY_OFFSET 0x00000954U

// Redirect a whole address range to master 1 (M1)
#define l2cache_ADDR_FILTERING_START_OFFSET 0x00000c00U

// Redirect a whole address range to master 1 (M1)
#define l2cache_ADDR_FILTERING_END_OFFSET 0x00000c04U

// The Debug Control Register forces specific cache behavior required for debug.
#define l2cache_DEBUG_CTRL_OFFSET 0x00000f40U

// Purpose Enables prefetch-related features that can improve system performance.
#define l2cache_PREFETCH_CTRL_OFFSET 0x00000f60U

// Purpose Controls the operating mode clock and power modes.
#define l2cache_POWER_CTRL_OFFSET 0x00000f80U
