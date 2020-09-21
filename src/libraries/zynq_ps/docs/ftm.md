# Instrumentation Trace  

Module Instrumentation Trace (ftm)  
SPDX-License-Identifier: MIT  
Auto-generated: Mon Sep 21 21:57:55 EEST 2020  

ftm Base Address = 0xf880b000  

## Register Summary  

+------------------------------+------------+------+------+------------+------------------------------+
|Register Name                 |Address     |Width |Type  |Reset Value |Description                   |
+==============================+============+======+======+============+==============================+
|**GLBCTRL**                   |0x00000000  |1     |rw    |0x00000000  |FTM Global Control.           |
+------------------------------+------------+------+------+------------+------------------------------+
|**STATUS**                    |0x00000004  |8     |ro    |0x82        |FTM Status Register           |
+------------------------------+------------+------+------+------------+------------------------------+
|**CONTROL**                   |0x00000008  |3     |rw    |0x00000000  |FTM Configuration             |
+------------------------------+------------+------+------+------------+------------------------------+
|**P2FDBG0**                   |0x0000000c  |8     |rw    |0x00        |FPGA Debug Register P2F0      |
+------------------------------+------------+------+------+------------+------------------------------+
|**P2FDBG1**                   |0x00000010  |8     |rw    |0x00        |FPGA Debug Register P2F1      |
+------------------------------+------------+------+------+------------+------------------------------+
|**P2FDBG2**                   |0x00000014  |8     |rw    |0x00        |FPGA Debug Register P2F2      |
+------------------------------+------------+------+------+------------+------------------------------+
|**P2FDBG3**                   |0x00000018  |8     |rw    |0x00        |FPGA Debug Register P2F3      |
+------------------------------+------------+------+------+------------+------------------------------+
|**F2PDBG0**                   |0x0000001c  |8     |ro    |0x00        |FPGA Debug Register F2P0      |
+------------------------------+------------+------+------+------------+------------------------------+
|**F2PDBG1**                   |0x00000020  |8     |ro    |0x00        |FPGA Debug Register F2P1      |
+------------------------------+------------+------+------+------------+------------------------------+
|**F2PDBG2**                   |0x00000024  |8     |ro    |0x00        |FPGA Debug Register F2P2      |
+------------------------------+------------+------+------+------------+------------------------------+
|**F2PDBG3**                   |0x00000028  |8     |ro    |0x00        |FPGA Debug Register F2P3      |
+------------------------------+------------+------+------+------------+------------------------------+
|**CYCOUNTPRE**                |0x0000002c  |4     |rw    |0x00000000  | AXI Cycle Count clock pre-sc |
+------------------------------+------------+------+------+------------+------------------------------+
|**SYNCRELOAD**                |0x00000030  |12    |rw    |0x00000000  | FTM Synchronization Counter  |
+------------------------------+------------+------+------+------------+------------------------------+
|**SYNCCOUT**                  |0x00000034  |12    |ro    |0x00000000  | FTM Synchronization Counter  |
+------------------------------+------------+------+------+------------+------------------------------+
|**ATID**                      |0x00000400  |7     |rw    |0x00000000  |FTM ATID Value Register       |
+------------------------------+------------+------+------+------------+------------------------------+
|**ITTRIGOUTACK**              |0x00000ed0  |4     |ro    |0x00000000  | Trigger Output Acknowledge I |
+------------------------------+------------+------+------+------------+------------------------------+
|**ITTRIGGER**                 |0x00000ed4  |4     |wo    |0x00000000  | Trigger Output Integration T |
+------------------------------+------------+------+------+------------+------------------------------+
|**ITTRACEDIS**                |0x00000ed8  |1     |ro    |0x00000000  | External Trace Disable Integ |
+------------------------------+------------+------+------+------------+------------------------------+
|**ITCYCCOUNT**                |0x00000edc  |32    |rw    |0x00000001  |Cycle Counter Test Register   |
+------------------------------+------------+------+------+------------+------------------------------+
|**ITATBDATA0**                |0x00000eec  |5     |wo    |0x00000000  | ATB Data Integration Test Re |
+------------------------------+------------+------+------+------------+------------------------------+
|**ITATBCTR2**                 |0x00000ef0  |2     |ro    |0x00000001  | ATB Control Integration Test |
+------------------------------+------------+------+------+------------+------------------------------+
|**ITATBCTR1**                 |0x00000ef4  |7     |rw    |0x00000000  | ATB Control Integration Test |
+------------------------------+------------+------+------+------------+------------------------------+
|**ITATBCTR0**                 |0x00000ef8  |10    |wo    |0x00000000  | ATB Control Integration Test |
+------------------------------+------------+------+------+------------+------------------------------+
|**ITCR**                      |0x00000f00  |1     |rw    |0x00000000  |FTM Test Control Register     |
+------------------------------+------------+------+------+------------+------------------------------+
|**CLAIMTAGSET**               |0x00000fa0  |8     |rw    |0xff        |Claim Tag Set Register        |
+------------------------------+------------+------+------+------------+------------------------------+
|**CLAIMTAGCLR**               |0x00000fa4  |8     |rw    |0x00        |Claim Tag Clear Register      |
+------------------------------+------------+------+------+------------+------------------------------+
|**LOCK_ACCESS**               |0x00000fb0  |32    |wo    |0x00000000  |Lock Access Register          |
+------------------------------+------------+------+------+------------+------------------------------+
|**LOCK_STATUS**               |0x00000fb4  |3     |ro    |0x00000003  |Lock Status Register          |
+------------------------------+------------+------+------+------------+------------------------------+
|**AUTHSTATUS**                |0x00000fb8  |8     |ro    |0x88        | Authentication Status Regist |
+------------------------------+------------+------+------+------------+------------------------------+
|**DEVID**                     |0x00000fc8  |1     |ro    |0x00000000  |Device Configuration Register |
+------------------------------+------------+------+------+------------+------------------------------+
|**DEV_TYPE**                  |0x00000fcc  |8     |ro    |0x33        | Device Type Identification R |
+------------------------------+------------+------+------+------------+------------------------------+
|**PERIPHID4**                 |0x00000fd0  |8     |ro    |0x00        |Peripheral ID4                |
+------------------------------+------------+------+------+------------+------------------------------+
|**PERIPHID5**                 |0x00000fd4  |8     |ro    |0x00        |Peripheral ID5                |
+------------------------------+------------+------+------+------------+------------------------------+
|**PERIPHID6**                 |0x00000fd8  |8     |ro    |0x00        |Peripheral ID6                |
+------------------------------+------------+------+------+------------+------------------------------+
|**PERIPHID7**                 |0x00000fdc  |8     |ro    |0x00        |Peripheral ID7                |
+------------------------------+------------+------+------+------------+------------------------------+
|**PERIPHID0**                 |0x00000fe0  |8     |ro    |0x01        |Peripheral ID0                |
+------------------------------+------------+------+------+------------+------------------------------+
|**PERIPHID1**                 |0x00000fe4  |8     |ro    |0x90        |Peripheral ID1                |
+------------------------------+------------+------+------+------------+------------------------------+
|**PERIPHID2**                 |0x00000fe8  |8     |ro    |0x0c        |Peripheral ID2                |
+------------------------------+------------+------+------+------------+------------------------------+
|**PERIPHID3**                 |0x00000fec  |8     |ro    |0x00        |Peripheral ID3                |
+------------------------------+------------+------+------+------------+------------------------------+
|**COMPONID0**                 |0x00000ff0  |8     |ro    |0x0d        |Component ID0                 |
+------------------------------+------------+------+------+------------+------------------------------+
|**COMPONID1**                 |0x00000ff4  |8     |ro    |0x90        |Component ID1                 |
+------------------------------+------------+------+------+------------+------------------------------+
|**COMPONID2**                 |0x00000ff8  |8     |ro    |0x05        |Component ID2                 |
+------------------------------+------------+------+------+------------+------------------------------+
|**COMPONID3**                 |0x00000ffc  |8     |ro    |0xb1        |Component ID3                 |
+------------------------------+------------+------+------+------------+------------------------------+

### GLBCTRL  

Relative Address = 0x00000000  
Width = 1 bits  
Access Type = rw  
Reset Value = 0x00000000  
Description FTM Global Control.  


### STATUS  

Relative Address = 0x00000004  
Width = 8 bits  
Access Type = ro  
Reset Value = 0x82  
Description FTM Status Register  


### CONTROL  

Relative Address = 0x00000008  
Width = 3 bits  
Access Type = rw  
Reset Value = 0x00000000  
Description FTM Configuration  


### P2FDBG0  

Relative Address = 0x0000000c  
Width = 8 bits  
Access Type = rw  
Reset Value = 0x00  
Description FPGA Debug Register P2F0  


### P2FDBG1  

Relative Address = 0x00000010  
Width = 8 bits  
Access Type = rw  
Reset Value = 0x00  
Description FPGA Debug Register P2F1  


### P2FDBG2  

Relative Address = 0x00000014  
Width = 8 bits  
Access Type = rw  
Reset Value = 0x00  
Description FPGA Debug Register P2F2  


### P2FDBG3  

Relative Address = 0x00000018  
Width = 8 bits  
Access Type = rw  
Reset Value = 0x00  
Description FPGA Debug Register P2F3  


### F2PDBG0  

Relative Address = 0x0000001c  
Width = 8 bits  
Access Type = ro  
Reset Value = 0x00  
Description FPGA Debug Register F2P0  


### F2PDBG1  

Relative Address = 0x00000020  
Width = 8 bits  
Access Type = ro  
Reset Value = 0x00  
Description FPGA Debug Register F2P1  


### F2PDBG2  

Relative Address = 0x00000024  
Width = 8 bits  
Access Type = ro  
Reset Value = 0x00  
Description FPGA Debug Register F2P2  


### F2PDBG3  

Relative Address = 0x00000028  
Width = 8 bits  
Access Type = ro  
Reset Value = 0x00  
Description FPGA Debug Register F2P3  


### CYCOUNTPRE  

Relative Address = 0x0000002c  
Width = 4 bits  
Access Type = rw  
Reset Value = 0x00000000  
Description AXI Cycle Count clock pre-scaler  


### SYNCRELOAD  

Relative Address = 0x00000030  
Width = 12 bits  
Access Type = rw  
Reset Value = 0x00000000  
Description FTM Synchronization Counter reload value  


### SYNCCOUT  

Relative Address = 0x00000034  
Width = 12 bits  
Access Type = ro  
Reset Value = 0x00000000  
Description FTM Synchronization Counter value  


### ATID  

Relative Address = 0x00000400  
Width = 7 bits  
Access Type = rw  
Reset Value = 0x00000000  
Description FTM ATID Value Register  


### ITTRIGOUTACK  

Relative Address = 0x00000ed0  
Width = 4 bits  
Access Type = ro  
Reset Value = 0x00000000  
Description Trigger Output Acknowledge Integration Test Register  


### ITTRIGGER  

Relative Address = 0x00000ed4  
Width = 4 bits  
Access Type = wo  
Reset Value = 0x00000000  
Description Trigger Output Integration Test Register  


### ITTRACEDIS  

Relative Address = 0x00000ed8  
Width = 1 bits  
Access Type = ro  
Reset Value = 0x00000000  
Description External Trace Disable Integration Test Register  


### ITCYCCOUNT  

Relative Address = 0x00000edc  
Width = 32 bits  
Access Type = rw  
Reset Value = 0x00000001  
Description Cycle Counter Test Register  


### ITATBDATA0  

Relative Address = 0x00000eec  
Width = 5 bits  
Access Type = wo  
Reset Value = 0x00000000  
Description ATB Data Integration Test Register 0  


### ITATBCTR2  

Relative Address = 0x00000ef0  
Width = 2 bits  
Access Type = ro  
Reset Value = 0x00000001  
Description ATB Control Integration Test Register 2  


### ITATBCTR1  

Relative Address = 0x00000ef4  
Width = 7 bits  
Access Type = rw  
Reset Value = 0x00000000  
Description ATB Control Integration Test Register 1  


### ITATBCTR0  

Relative Address = 0x00000ef8  
Width = 10 bits  
Access Type = wo  
Reset Value = 0x00000000  
Description ATB Control Integration Test Register 0  


### ITCR  

Relative Address = 0x00000f00  
Width = 1 bits  
Access Type = rw  
Reset Value = 0x00000000  
Description FTM Test Control Register  


### CLAIMTAGSET  

Relative Address = 0x00000fa0  
Width = 8 bits  
Access Type = rw  
Reset Value = 0xff  
Description Claim Tag Set Register  


### CLAIMTAGCLR  

Relative Address = 0x00000fa4  
Width = 8 bits  
Access Type = rw  
Reset Value = 0x00  
Description Claim Tag Clear Register  


### LOCK_ACCESS  

Relative Address = 0x00000fb0  
Width = 32 bits  
Access Type = wo  
Reset Value = 0x00000000  
Description Lock Access Register  


### LOCK_STATUS  

Relative Address = 0x00000fb4  
Width = 3 bits  
Access Type = ro  
Reset Value = 0x00000003  
Description Lock Status Register  


### AUTHSTATUS  

Relative Address = 0x00000fb8  
Width = 8 bits  
Access Type = ro  
Reset Value = 0x88  
Description Authentication Status Register  


### DEVID  

Relative Address = 0x00000fc8  
Width = 1 bits  
Access Type = ro  
Reset Value = 0x00000000  
Description Device Configuration Register  


### DEV_TYPE  

Relative Address = 0x00000fcc  
Width = 8 bits  
Access Type = ro  
Reset Value = 0x33  
Description Device Type Identification Register  


### PERIPHID4  

Relative Address = 0x00000fd0  
Width = 8 bits  
Access Type = ro  
Reset Value = 0x00  
Description Peripheral ID4  


### PERIPHID5  

Relative Address = 0x00000fd4  
Width = 8 bits  
Access Type = ro  
Reset Value = 0x00  
Description Peripheral ID5  


### PERIPHID6  

Relative Address = 0x00000fd8  
Width = 8 bits  
Access Type = ro  
Reset Value = 0x00  
Description Peripheral ID6  


### PERIPHID7  

Relative Address = 0x00000fdc  
Width = 8 bits  
Access Type = ro  
Reset Value = 0x00  
Description Peripheral ID7  


### PERIPHID0  

Relative Address = 0x00000fe0  
Width = 8 bits  
Access Type = ro  
Reset Value = 0x01  
Description Peripheral ID0  


### PERIPHID1  

Relative Address = 0x00000fe4  
Width = 8 bits  
Access Type = ro  
Reset Value = 0x90  
Description Peripheral ID1  


### PERIPHID2  

Relative Address = 0x00000fe8  
Width = 8 bits  
Access Type = ro  
Reset Value = 0x0c  
Description Peripheral ID2  


### PERIPHID3  

Relative Address = 0x00000fec  
Width = 8 bits  
Access Type = ro  
Reset Value = 0x00  
Description Peripheral ID3  


### COMPONID0  

Relative Address = 0x00000ff0  
Width = 8 bits  
Access Type = ro  
Reset Value = 0x0d  
Description Component ID0  


### COMPONID1  

Relative Address = 0x00000ff4  
Width = 8 bits  
Access Type = ro  
Reset Value = 0x90  
Description Component ID1  


### COMPONID2  

Relative Address = 0x00000ff8  
Width = 8 bits  
Access Type = ro  
Reset Value = 0x05  
Description Component ID2  


### COMPONID3  

Relative Address = 0x00000ffc  
Width = 8 bits  
Access Type = ro  
Reset Value = 0xb1  
Description Component ID3  

