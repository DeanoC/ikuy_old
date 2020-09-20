# Cortex A9 Performance Monitoring Unit  

Module Cortex A9 Performance Monitoring Unit (cortexa9_pmu)  
SPDX-License-Identifier: MIT  
Auto-generated: Sun Sep 20 15:25:57 EEST 2020  

debug_cpu_pmu0 Base Address = 0xf8891000  
debug_cpu_pmu1 Base Address = 0xf8893000  

## Register Summary  

+------------------------------+------------+------+------+------------+------------------------------+
|Register Name                 |Address     |Width |Type  |Reset Value |Description                   |
+==============================+============+======+======+============+==============================+
|**pmu_PMXEVCNTR0**            |0x00000000  |32    |rw    |0x00000000  |PMU event counter 0           |
+------------------------------+------------+------+------+------------+------------------------------+
|**pmu_PMXEVCNTR1**            |0x00000004  |32    |rw    |0x00000000  |PMU event counter 1           |
+------------------------------+------------+------+------+------------+------------------------------+
|**pmu_PMXEVCNTR2**            |0x00000008  |32    |rw    |0x00000000  |PMU event counter 2           |
+------------------------------+------------+------+------+------------+------------------------------+
|**pmu_PMXEVCNTR3**            |0x0000000c  |32    |rw    |0x00000000  |PMU event counter 3           |
+------------------------------+------------+------+------+------------+------------------------------+
|**pmu_PMXEVCNTR4**            |0x00000010  |32    |rw    |0x00000000  |PMU event counter 4           |
+------------------------------+------------+------+------+------------+------------------------------+
|**pmu_PMXEVCNTR5**            |0x00000014  |32    |rw    |0x00000000  |PMU event counter 5           |
+------------------------------+------------+------+------+------------+------------------------------+
|**pmu_PMCCNTR**               |0x0000007c  |32    |rw    |0x00000000  |pmccntr                       |
+------------------------------+------------+------+------+------------+------------------------------+
|**pmu_PMXEVTYPER0**           |0x00000400  |32    |rw    |0x00000000  |pmevtyper0                    |
+------------------------------+------------+------+------+------------+------------------------------+
|**pmu_PMXEVTYPER1**           |0x00000404  |32    |rw    |0x00000000  |pmevtyper1                    |
+------------------------------+------------+------+------+------------+------------------------------+
|**pmu_PMXEVTYPER2**           |0x00000408  |32    |rw    |0x00000000  |pmevtyper2                    |
+------------------------------+------------+------+------+------------+------------------------------+
|**pmu_PMXEVTYPER3**           |0x0000040c  |32    |rw    |0x00000000  |pmevtyper3                    |
+------------------------------+------------+------+------+------------+------------------------------+
|**pmu_PMXEVTYPER4**           |0x00000410  |32    |rw    |0x00000000  |pmevtyper4                    |
+------------------------------+------------+------+------+------------+------------------------------+
|**pmu_PMXEVTYPER5**           |0x00000414  |32    |rw    |0x00000000  |pmevtyper5                    |
+------------------------------+------------+------+------+------------+------------------------------+
|**pmu_PMCNTENSET**            |0x00000c00  |32    |rw    |0x00000000  |pmcntenset                    |
+------------------------------+------------+------+------+------------+------------------------------+
|**pmu_PMCNTENCLR**            |0x00000c20  |32    |rw    |0x00000000  |pmcntenclr                    |
+------------------------------+------------+------+------+------------+------------------------------+
|**pmu_PMINTENSET**            |0x00000c40  |32    |rw    |0x00000000  |pmintenset                    |
+------------------------------+------------+------+------+------------+------------------------------+
|**pmu_PMINTENCLR**            |0x00000c60  |32    |rw    |0x00000000  |pmintenclr                    |
+------------------------------+------------+------+------+------------+------------------------------+
|**pmu_PMOVSR**                |0x00000c80  |32    |rw    |0x00000000  |pmovsr                        |
+------------------------------+------------+------+------+------------+------------------------------+
|**pmu_PMSWINC**               |0x00000ca0  |32    |wo    |0x00000000  |pmswinc                       |
+------------------------------+------------+------+------+------------+------------------------------+
|**pmu_PMCR**                  |0x00000e04  |32    |rw    |0x41093000  |pmcr                          |
+------------------------------+------------+------+------+------------+------------------------------+
|**pmu_PMUSERENR**             |0x00000e08  |32    |rw    |0x00000000  |pmuserenr                     |
+------------------------------+------------+------+------+------------+------------------------------+

### pmu_PMXEVCNTR0  

Module cortexa9_pmu  
Relative Address = 0x00000000  
Width = 32 bits  
Access Type = rw  
Reset Value = 0x00000000  
Description PMU event counter 0  


### pmu_PMXEVCNTR1  

Module cortexa9_pmu  
Relative Address = 0x00000004  
Width = 32 bits  
Access Type = rw  
Reset Value = 0x00000000  
Description PMU event counter 1  


### pmu_PMXEVCNTR2  

Module cortexa9_pmu  
Relative Address = 0x00000008  
Width = 32 bits  
Access Type = rw  
Reset Value = 0x00000000  
Description PMU event counter 2  


### pmu_PMXEVCNTR3  

Module cortexa9_pmu  
Relative Address = 0x0000000c  
Width = 32 bits  
Access Type = rw  
Reset Value = 0x00000000  
Description PMU event counter 3  


### pmu_PMXEVCNTR4  

Module cortexa9_pmu  
Relative Address = 0x00000010  
Width = 32 bits  
Access Type = rw  
Reset Value = 0x00000000  
Description PMU event counter 4  


### pmu_PMXEVCNTR5  

Module cortexa9_pmu  
Relative Address = 0x00000014  
Width = 32 bits  
Access Type = rw  
Reset Value = 0x00000000  
Description PMU event counter 5  


### pmu_PMCCNTR  

Module cortexa9_pmu  
Relative Address = 0x0000007c  
Width = 32 bits  
Access Type = rw  
Reset Value = 0x00000000  
Description pmccntr  


### pmu_PMXEVTYPER0  

Module cortexa9_pmu  
Relative Address = 0x00000400  
Width = 32 bits  
Access Type = rw  
Reset Value = 0x00000000  
Description pmevtyper0  


### pmu_PMXEVTYPER1  

Module cortexa9_pmu  
Relative Address = 0x00000404  
Width = 32 bits  
Access Type = rw  
Reset Value = 0x00000000  
Description pmevtyper1  


### pmu_PMXEVTYPER2  

Module cortexa9_pmu  
Relative Address = 0x00000408  
Width = 32 bits  
Access Type = rw  
Reset Value = 0x00000000  
Description pmevtyper2  


### pmu_PMXEVTYPER3  

Module cortexa9_pmu  
Relative Address = 0x0000040c  
Width = 32 bits  
Access Type = rw  
Reset Value = 0x00000000  
Description pmevtyper3  


### pmu_PMXEVTYPER4  

Module cortexa9_pmu  
Relative Address = 0x00000410  
Width = 32 bits  
Access Type = rw  
Reset Value = 0x00000000  
Description pmevtyper4  


### pmu_PMXEVTYPER5  

Module cortexa9_pmu  
Relative Address = 0x00000414  
Width = 32 bits  
Access Type = rw  
Reset Value = 0x00000000  
Description pmevtyper5  


### pmu_PMCNTENSET  

Module cortexa9_pmu  
Relative Address = 0x00000c00  
Width = 32 bits  
Access Type = rw  
Reset Value = 0x00000000  
Description pmcntenset  


### pmu_PMCNTENCLR  

Module cortexa9_pmu  
Relative Address = 0x00000c20  
Width = 32 bits  
Access Type = rw  
Reset Value = 0x00000000  
Description pmcntenclr  


### pmu_PMINTENSET  

Module cortexa9_pmu  
Relative Address = 0x00000c40  
Width = 32 bits  
Access Type = rw  
Reset Value = 0x00000000  
Description pmintenset  


### pmu_PMINTENCLR  

Module cortexa9_pmu  
Relative Address = 0x00000c60  
Width = 32 bits  
Access Type = rw  
Reset Value = 0x00000000  
Description pmintenclr  


### pmu_PMOVSR  

Module cortexa9_pmu  
Relative Address = 0x00000c80  
Width = 32 bits  
Access Type = rw  
Reset Value = 0x00000000  
Description pmovsr  


### pmu_PMSWINC  

Module cortexa9_pmu  
Relative Address = 0x00000ca0  
Width = 32 bits  
Access Type = wo  
Reset Value = 0x00000000  
Description pmswinc  


### pmu_PMCR  

Module cortexa9_pmu  
Relative Address = 0x00000e04  
Width = 32 bits  
Access Type = rw  
Reset Value = 0x41093000  
Description pmcr  


### pmu_PMUSERENR  

Module cortexa9_pmu  
Relative Address = 0x00000e08  
Width = 32 bits  
Access Type = rw  
Reset Value = 0x00000000  
Description pmuserenr  

