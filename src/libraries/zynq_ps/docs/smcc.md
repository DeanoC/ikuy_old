# Static Memory Controller  

Module Static Memory Controller (smcc)  
SPDX-License-Identifier: MIT  
Auto-generated: Sun Sep 20 23:32:01 EEST 2020  

smcc Base Address = 0xe000e000  

## Register Summary  

+------------------------------+------------+------+------+------------+------------------------------+
|Register Name                 |Address     |Width |Type  |Reset Value |Description                   |
+==============================+============+======+======+============+==============================+
|**MEMC_STATUS**               |0x00000000  |13    |ro    |0x00000000  | Operating and Interrupt Stat |
+------------------------------+------------+------+------+------------+------------------------------+
|**MEMC_IF_CONFIG**            |0x00000004  |18    |ro    |0x00011205  |SMC configuration information |
+------------------------------+------------+------+------+------------+------------------------------+
|**MEMC_SET_CONFIG**           |0x00000008  |7     |wo    |0x00000000  | Enable interrupts and lower  |
+------------------------------+------------+------+------+------------+------------------------------+
|**MEMC_CLR_CONFIG**           |0x0000000c  |7     |wo    |0x00000000  | Disable interrupts and exit  |
+------------------------------+------------+------+------+------------+------------------------------+
|**DIRECT_CMD**                |0x00000010  |26    |wo    |0x00000000  | Issue mem commands and regis |
+------------------------------+------------+------+------+------------+------------------------------+
|**SET_CYCLES**                |0x00000014  |24    |wo    |0x00000000  | Stage a write to a Cycle reg |
+------------------------------+------------+------+------+------------+------------------------------+
|**SET_OPMODE**                |0x00000018  |16    |mixed |0x0000      | Stage a write to an OpMode r |
+------------------------------+------------+------+------+------------+------------------------------+
|**REFRESH_PERIOD_0**          |0x00000020  |4     |rw    |0x00000000  | Idle cycles between read/wri |
+------------------------------+------------+------+------+------------+------------------------------+
|**REFRESH_PERIOD_1**          |0x00000024  |4     |rw    |0x00000000  | Insert idle cycles between b |
+------------------------------+------------+------+------+------------+------------------------------+
|**IF0_CHIP_0_CONFIG**         |0x00000100  |21    |ro    |0x0002b3cc  | SRAM/NOR chip select 0 timin |
+------------------------------+------------+------+------+------------+------------------------------+
|**OPMODE**                    |0x00000104  |32    |ro    |0x00000000  | SRAM/NOR chip select 0 OpCod |
+------------------------------+------------+------+------+------------+------------------------------+
|**IF0_CHIP_1_CONFIG**         |0x00000120  |21    |ro    |0x0002b3cc  | SRAM/NOR chip select 1 timin |
+------------------------------+------------+------+------+------------+------------------------------+
|**OPMODE0_1**                 |0x00000124  |32    |ro    |0x00000000  | SRAM/NOR chip select 1 OpCod |
+------------------------------+------------+------+------+------------+------------------------------+
|**IF1_CHIP_0_CONFIG**         |0x00000180  |24    |ro    |0x0024abcc  |NAND Flash timing, active     |
+------------------------------+------------+------+------+------------+------------------------------+
|**OPMODE1_0**                 |0x00000184  |32    |ro    |0x00000000  |NAND Flash OpCode, active     |
+------------------------------+------------+------+------+------------+------------------------------+
|**USER_STATUS**               |0x00000200  |8     |ro    |0x00        |User Status                   |
+------------------------------+------------+------+------+------------+------------------------------+
|**USER_CONFIG**               |0x00000204  |8     |wo    |0x00        |User Configuration            |
+------------------------------+------------+------+------+------------+------------------------------+
|**IF1_ECC**                   |0x00000400  |30    |ro    |0x00000000  |ECC Status and Clear          |
+------------------------------+------------+------+------+------------+------------------------------+
|**ECC_MEMCFG_1**              |0x00000404  |13    |rw    |0x00000043  |ECC Memory Configuation       |
+------------------------------+------------+------+------+------------+------------------------------+
|**ECC_MEMCOMMAND1_1**         |0x00000408  |25    |rw    |0x01300080  |ECC Memory Command 1          |
+------------------------------+------------+------+------+------------+------------------------------+
|**ECC_MEMCOMMAND2_1**         |0x0000040c  |25    |rw    |0x01e00585  |ECC Memory Command 2          |
+------------------------------+------------+------+------+------------+------------------------------+
|**ECC_ADDR0_1**               |0x00000410  |32    |ro    |0x00000000  |ECC Address 0                 |
+------------------------------+------------+------+------+------------+------------------------------+
|**ECC_ADDR1_1**               |0x00000414  |24    |ro    |0x00000000  |ECC Address 1                 |
+------------------------------+------------+------+------+------------+------------------------------+
|**ECC_VALUE0_1**              |0x00000418  |32    |ro    |0x00000000  |ECC Value 0                   |
+------------------------------+------------+------+------+------------+------------------------------+
|**ECC_VALUE1_1**              |0x0000041c  |32    |ro    |0x00000000  |ECC Value 1                   |
+------------------------------+------------+------+------+------------+------------------------------+
|**ECC_VALUE2_1**              |0x00000420  |32    |ro    |0x00000000  |ECC Value 2                   |
+------------------------------+------------+------+------+------------+------------------------------+
|**ECC_VALUE3_1**              |0x00000424  |32    |ro    |0x00000000  |ECC Value 3                   |
+------------------------------+------------+------+------+------------+------------------------------+

### MEMC_STATUS  

Relative Address = 0x00000000  
Width = 13 bits  
Access Type = ro  
Reset Value = 0x00000000  
Description Operating and Interrupt Status  


### MEMC_IF_CONFIG  

Relative Address = 0x00000004  
Width = 18 bits  
Access Type = ro  
Reset Value = 0x00011205  
Description SMC configuration information  


### MEMC_SET_CONFIG  

Relative Address = 0x00000008  
Width = 7 bits  
Access Type = wo  
Reset Value = 0x00000000  
Description Enable interrupts and lower power state  


### MEMC_CLR_CONFIG  

Relative Address = 0x0000000c  
Width = 7 bits  
Access Type = wo  
Reset Value = 0x00000000  
Description Disable interrupts and exit from low-power state  


### DIRECT_CMD  

Relative Address = 0x00000010  
Width = 26 bits  
Access Type = wo  
Reset Value = 0x00000000  
Description Issue mem commands and register updates  


### SET_CYCLES  

Relative Address = 0x00000014  
Width = 24 bits  
Access Type = wo  
Reset Value = 0x00000000  
Description Stage a write to a Cycle register  


### SET_OPMODE  

Relative Address = 0x00000018  
Width = 16 bits  
Access Type = mixed  
Reset Value = 0x0000  
Description Stage a write to an OpMode register  


### REFRESH_PERIOD_0  

Relative Address = 0x00000020  
Width = 4 bits  
Access Type = rw  
Reset Value = 0x00000000  
Description Idle cycles between read/write bursts  


### REFRESH_PERIOD_1  

Relative Address = 0x00000024  
Width = 4 bits  
Access Type = rw  
Reset Value = 0x00000000  
Description Insert idle cycles between bursts  


### IF0_CHIP_0_CONFIG  

Relative Address = 0x00000100  
Width = 21 bits  
Access Type = ro  
Reset Value = 0x0002b3cc  
Description SRAM/NOR chip select 0 timing, active  


### OPMODE  

Relative Address = 0x00000104  
Width = 32 bits  
Access Type = ro  
Reset Value = 0x00000000  
Description SRAM/NOR chip select 0 OpCode, active  


### IF0_CHIP_1_CONFIG  

Relative Address = 0x00000120  
Width = 21 bits  
Access Type = ro  
Reset Value = 0x0002b3cc  
Description SRAM/NOR chip select 1 timing, active  


### OPMODE0_1  

Relative Address = 0x00000124  
Width = 32 bits  
Access Type = ro  
Reset Value = 0x00000000  
Description SRAM/NOR chip select 1 OpCode, active  


### IF1_CHIP_0_CONFIG  

Relative Address = 0x00000180  
Width = 24 bits  
Access Type = ro  
Reset Value = 0x0024abcc  
Description NAND Flash timing, active  


### OPMODE1_0  

Relative Address = 0x00000184  
Width = 32 bits  
Access Type = ro  
Reset Value = 0x00000000  
Description NAND Flash OpCode, active  


### USER_STATUS  

Relative Address = 0x00000200  
Width = 8 bits  
Access Type = ro  
Reset Value = 0x00  
Description User Status  


### USER_CONFIG  

Relative Address = 0x00000204  
Width = 8 bits  
Access Type = wo  
Reset Value = 0x00  
Description User Configuration  


### IF1_ECC  

Relative Address = 0x00000400  
Width = 30 bits  
Access Type = ro  
Reset Value = 0x00000000  
Description ECC Status and Clear  


### ECC_MEMCFG_1  

Relative Address = 0x00000404  
Width = 13 bits  
Access Type = rw  
Reset Value = 0x00000043  
Description ECC Memory Configuation  


### ECC_MEMCOMMAND1_1  

Relative Address = 0x00000408  
Width = 25 bits  
Access Type = rw  
Reset Value = 0x01300080  
Description ECC Memory Command 1  


### ECC_MEMCOMMAND2_1  

Relative Address = 0x0000040c  
Width = 25 bits  
Access Type = rw  
Reset Value = 0x01e00585  
Description ECC Memory Command 2  


### ECC_ADDR0_1  

Relative Address = 0x00000410  
Width = 32 bits  
Access Type = ro  
Reset Value = 0x00000000  
Description ECC Address 0  


### ECC_ADDR1_1  

Relative Address = 0x00000414  
Width = 24 bits  
Access Type = ro  
Reset Value = 0x00000000  
Description ECC Address 1  


### ECC_VALUE0_1  

Relative Address = 0x00000418  
Width = 32 bits  
Access Type = ro  
Reset Value = 0x00000000  
Description ECC Value 0  


### ECC_VALUE1_1  

Relative Address = 0x0000041c  
Width = 32 bits  
Access Type = ro  
Reset Value = 0x00000000  
Description ECC Value 1  


### ECC_VALUE2_1  

Relative Address = 0x00000420  
Width = 32 bits  
Access Type = ro  
Reset Value = 0x00000000  
Description ECC Value 2  


### ECC_VALUE3_1  

Relative Address = 0x00000424  
Width = 32 bits  
Access Type = ro  
Reset Value = 0x00000000  
Description ECC Value 3  

