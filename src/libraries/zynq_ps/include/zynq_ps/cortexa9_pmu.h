#pragma once
// Copyright Deano Calver
// SPDX-License-Identifier: MIT
// Cortex A9 Performance Monitoring Unit
// Auto-generated on Sun Sep 20 15:25:57 EEST 2020

#include <stdint.h>

// 2 banks of cortexa9_pmu chips
#define debug_cpu_pmu0_BASE_ADDR 0xf8891000
#define debug_cpu_pmu1_BASE_ADDR 0xf8893000

// PMU event counter 0
#define cortexa9_pmu_PMXEVCNTR0_OFFSET 0x00000000

// PMU event counter 1
#define cortexa9_pmu_PMXEVCNTR1_OFFSET 0x00000004

// PMU event counter 2
#define cortexa9_pmu_PMXEVCNTR2_OFFSET 0x00000008

// PMU event counter 3
#define cortexa9_pmu_PMXEVCNTR3_OFFSET 0x0000000c

// PMU event counter 4
#define cortexa9_pmu_PMXEVCNTR4_OFFSET 0x00000010

// PMU event counter 5
#define cortexa9_pmu_PMXEVCNTR5_OFFSET 0x00000014

// pmccntr
#define cortexa9_pmu_PMCCNTR_OFFSET 0x0000007c

// pmevtyper0
#define cortexa9_pmu_PMXEVTYPER0_OFFSET 0x00000400

// pmevtyper1
#define cortexa9_pmu_PMXEVTYPER1_OFFSET 0x00000404

// pmevtyper2
#define cortexa9_pmu_PMXEVTYPER2_OFFSET 0x00000408

// pmevtyper3
#define cortexa9_pmu_PMXEVTYPER3_OFFSET 0x0000040c

// pmevtyper4
#define cortexa9_pmu_PMXEVTYPER4_OFFSET 0x00000410

// pmevtyper5
#define cortexa9_pmu_PMXEVTYPER5_OFFSET 0x00000414

// pmcntenset
#define cortexa9_pmu_PMCNTENSET_OFFSET 0x00000c00

// pmcntenclr
#define cortexa9_pmu_PMCNTENCLR_OFFSET 0x00000c20

// pmintenset
#define cortexa9_pmu_PMINTENSET_OFFSET 0x00000c40

// pmintenclr
#define cortexa9_pmu_PMINTENCLR_OFFSET 0x00000c60

// pmovsr
#define cortexa9_pmu_PMOVSR_OFFSET 0x00000c80

// pmswinc
#define cortexa9_pmu_PMSWINC_OFFSET 0x00000ca0

// pmcr
#define cortexa9_pmu_PMCR_OFFSET 0x00000e04

// pmuserenr
#define cortexa9_pmu_PMUSERENR_OFFSET 0x00000e08
