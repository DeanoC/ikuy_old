#pragma once
// Copyright Deano Calver
// SPDX-License-Identifier: MIT
// Cortex A9 Performance Monitoring Unit
// Auto-generated on Mon Sep 21 21:57:55 EEST 2020

#include <stdint.h>

// 2 banks of cortexa9_pmu chips
#define debug_cpu_pmu0_BASE_ADDR 0xf8891000U
#define debug_cpu_pmu1_BASE_ADDR 0xf8893000U

// PMU event counter 0
#define cortexa9_pmu_PMXEVCNTR0_OFFSET 0x00000000U

// PMU event counter 1
#define cortexa9_pmu_PMXEVCNTR1_OFFSET 0x00000004U

// PMU event counter 2
#define cortexa9_pmu_PMXEVCNTR2_OFFSET 0x00000008U

// PMU event counter 3
#define cortexa9_pmu_PMXEVCNTR3_OFFSET 0x0000000cU

// PMU event counter 4
#define cortexa9_pmu_PMXEVCNTR4_OFFSET 0x00000010U

// PMU event counter 5
#define cortexa9_pmu_PMXEVCNTR5_OFFSET 0x00000014U

// pmccntr
#define cortexa9_pmu_PMCCNTR_OFFSET 0x0000007cU

// pmevtyper0
#define cortexa9_pmu_PMXEVTYPER0_OFFSET 0x00000400U

// pmevtyper1
#define cortexa9_pmu_PMXEVTYPER1_OFFSET 0x00000404U

// pmevtyper2
#define cortexa9_pmu_PMXEVTYPER2_OFFSET 0x00000408U

// pmevtyper3
#define cortexa9_pmu_PMXEVTYPER3_OFFSET 0x0000040cU

// pmevtyper4
#define cortexa9_pmu_PMXEVTYPER4_OFFSET 0x00000410U

// pmevtyper5
#define cortexa9_pmu_PMXEVTYPER5_OFFSET 0x00000414U

// pmcntenset
#define cortexa9_pmu_PMCNTENSET_OFFSET 0x00000c00U

// pmcntenclr
#define cortexa9_pmu_PMCNTENCLR_OFFSET 0x00000c20U

// pmintenset
#define cortexa9_pmu_PMINTENSET_OFFSET 0x00000c40U

// pmintenclr
#define cortexa9_pmu_PMINTENCLR_OFFSET 0x00000c60U

// pmovsr
#define cortexa9_pmu_PMOVSR_OFFSET 0x00000c80U

// pmswinc
#define cortexa9_pmu_PMSWINC_OFFSET 0x00000ca0U

// pmcr
#define cortexa9_pmu_PMCR_OFFSET 0x00000e04U

// pmuserenr
#define cortexa9_pmu_PMUSERENR_OFFSET 0x00000e08U
