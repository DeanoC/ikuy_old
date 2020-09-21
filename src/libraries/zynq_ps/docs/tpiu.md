# Trace Port Interface  

Module Trace Port Interface (tpiu)  
SPDX-License-Identifier: MIT  
Auto-generated: Mon Sep 21 19:32:28 EEST 2020  

tpiu Base Address = 0xf8803000  

## Register Summary  

+------------------------------+------------+------+------+------------+------------------------------+
|Register Name                 |Address     |Width |Type  |Reset Value |Description                   |
+==============================+============+======+======+============+==============================+
|**SuppSize**                  |0x00000000  |32    |rw    |0x00000000  |Supported Port Size Register  |
+------------------------------+------------+------+------+------------+------------------------------+
|**CurrentSize**               |0x00000004  |32    |rw    |0x00000001  |Current Port Size Register    |
+------------------------------+------------+------+------+------------+------------------------------+
|**SuppTrigMode**              |0x00000100  |18    |ro    |0x0000011f  | Supported Trigger Modes Regi |
+------------------------------+------------+------+------+------------+------------------------------+
|**TrigCount**                 |0x00000104  |8     |rw    |0x00        |Trigger Counter Register      |
+------------------------------+------------+------+------+------------+------------------------------+
|**TrigMult**                  |0x00000108  |5     |rw    |0x00000000  |Trigger Multiplier Register   |
+------------------------------+------------+------+------+------------+------------------------------+
|**SuppTest**                  |0x00000200  |18    |ro    |0x0003000f  | Supported Test Patterns/Mode |
+------------------------------+------------+------+------+------------+------------------------------+
|**CurrentTest**               |0x00000204  |18    |mixed |0x00000000  | Current Test Patterns/Modes  |
+------------------------------+------------+------+------+------------+------------------------------+
|**TestRepeatCount**           |0x00000208  |8     |rw    |0x00        | TPIU Test Pattern Repeat Cou |
+------------------------------+------------+------+------+------------+------------------------------+
|**FFSR**                      |0x00000300  |3     |ro    |0x00000006  | Formatter and Flush Status R |
+------------------------------+------------+------+------+------------+------------------------------+
|**FFCR**                      |0x00000304  |14    |mixed |0x00000000  | Formatter and Flush Control  |
+------------------------------+------------+------+------+------------+------------------------------+
|**FormatSyncCount**           |0x00000308  |12    |rw    |0x00000040  | Formatter Synchronization Co |
+------------------------------+------------+------+------+------------+------------------------------+
|**EXTCTLIn**                  |0x00000400  |8     |ro    |0x00        |EXTCTL In Port                |
+------------------------------+------------+------+------+------------+------------------------------+
|**EXTCTLOut**                 |0x00000404  |8     |rw    |0x00        |EXTCTL Out Port               |
+------------------------------+------------+------+------+------------+------------------------------+
|**ITTRFLINACK**               |0x00000ee4  |2     |wo    |0x00000000  | Integration Test Trigger In  |
+------------------------------+------------+------+------+------------+------------------------------+
|**ITTRFLIN**                  |0x00000ee8  |2     |ro    |0x00000000  | Integration Test Trigger In  |
+------------------------------+------------+------+------+------------+------------------------------+
|**ITATBDATA0**                |0x00000eec  |5     |ro    |0x00000000  | Integration Test ATB Data Re |
+------------------------------+------------+------+------+------------+------------------------------+
|**ITATBCTR2**                 |0x00000ef0  |2     |wo    |0x00000000  | Integration Test ATB Control |
+------------------------------+------------+------+------+------------+------------------------------+
|**ITATBCTR1**                 |0x00000ef4  |7     |ro    |0x00000000  | Integration Test ATB Control |
+------------------------------+------------+------+------+------------+------------------------------+
|**ITATBCTR0**                 |0x00000ef8  |10    |ro    |0x00000000  | Integration Test ATB Control |
+------------------------------+------------+------+------+------------+------------------------------+
|**IMCR**                      |0x00000f00  |1     |rw    |0x00000000  | Integration Mode Control Reg |
+------------------------------+------------+------+------+------------+------------------------------+
|**CTSR**                      |0x00000fa0  |4     |rw    |0x0000000f  |Claim Tag Set Register        |
+------------------------------+------------+------+------+------------+------------------------------+
|**CTCR**                      |0x00000fa4  |4     |rw    |0x00000000  |Claim Tag Clear Register      |
+------------------------------+------------+------+------+------------+------------------------------+
|**LAR**                       |0x00000fb0  |32    |wo    |0x00000000  |Lock Access Register          |
+------------------------------+------------+------+------+------------+------------------------------+
|**LSR**                       |0x00000fb4  |3     |ro    |0x00000003  |Lock Status Register          |
+------------------------------+------------+------+------+------------+------------------------------+
|**ASR**                       |0x00000fb8  |8     |ro    |0x00        | Authentication Status Regist |
+------------------------------+------------+------+------+------------+------------------------------+
|**DEVID**                     |0x00000fc8  |12    |ro    |0x000000a0  |Device ID                     |
+------------------------------+------------+------+------+------------+------------------------------+
|**DTIR**                      |0x00000fcc  |8     |ro    |0x11        | Device Type Identifier Regis |
+------------------------------+------------+------+------+------------+------------------------------+
|**PERIPHID4**                 |0x00000fd0  |8     |ro    |0x04        |Peripheral ID4                |
+------------------------------+------------+------+------+------------+------------------------------+
|**PERIPHID5**                 |0x00000fd4  |8     |ro    |0x00        |Peripheral ID5                |
+------------------------------+------------+------+------+------------+------------------------------+
|**PERIPHID6**                 |0x00000fd8  |8     |ro    |0x00        |Peripheral ID6                |
+------------------------------+------------+------+------+------------+------------------------------+
|**PERIPHID7**                 |0x00000fdc  |8     |ro    |0x00        |Peripheral ID7                |
+------------------------------+------------+------+------+------------+------------------------------+
|**PERIPHID0**                 |0x00000fe0  |8     |ro    |0x12        |Peripheral ID0                |
+------------------------------+------------+------+------+------------+------------------------------+
|**PERIPHID1**                 |0x00000fe4  |8     |ro    |0xb9        |Peripheral ID1                |
+------------------------------+------------+------+------+------------+------------------------------+
|**PERIPHID2**                 |0x00000fe8  |8     |ro    |0x4b        |Peripheral ID2                |
+------------------------------+------------+------+------+------------+------------------------------+
|**PERIPHID3**                 |0x00000fec  |8     |ro    |0x00        |Peripheral ID3                |
+------------------------------+------------+------+------+------------+------------------------------+
|**COMPID0**                   |0x00000ff0  |8     |ro    |0x0d        |Component ID0                 |
+------------------------------+------------+------+------+------------+------------------------------+
|**COMPID1**                   |0x00000ff4  |8     |ro    |0x90        |Component ID1                 |
+------------------------------+------------+------+------+------------+------------------------------+
|**COMPID2**                   |0x00000ff8  |8     |ro    |0x05        |Component ID2                 |
+------------------------------+------------+------+------+------------+------------------------------+
|**COMPID3**                   |0x00000ffc  |8     |ro    |0xb1        |Component ID3                 |
+------------------------------+------------+------+------+------------+------------------------------+

### SuppSize  

Relative Address = 0x00000000  
Width = 32 bits  
Access Type = rw  
Reset Value = 0x00000000  
Description Supported Port Size Register  


### CurrentSize  

Relative Address = 0x00000004  
Width = 32 bits  
Access Type = rw  
Reset Value = 0x00000001  
Description Current Port Size Register  


### SuppTrigMode  

Relative Address = 0x00000100  
Width = 18 bits  
Access Type = ro  
Reset Value = 0x0000011f  
Description Supported Trigger Modes Register  


### TrigCount  

Relative Address = 0x00000104  
Width = 8 bits  
Access Type = rw  
Reset Value = 0x00  
Description Trigger Counter Register  


### TrigMult  

Relative Address = 0x00000108  
Width = 5 bits  
Access Type = rw  
Reset Value = 0x00000000  
Description Trigger Multiplier Register  


### SuppTest  

Relative Address = 0x00000200  
Width = 18 bits  
Access Type = ro  
Reset Value = 0x0003000f  
Description Supported Test Patterns/Modes Register  


### CurrentTest  

Relative Address = 0x00000204  
Width = 18 bits  
Access Type = mixed  
Reset Value = 0x00000000  
Description Current Test Patterns/Modes Register  


### TestRepeatCount  

Relative Address = 0x00000208  
Width = 8 bits  
Access Type = rw  
Reset Value = 0x00  
Description TPIU Test Pattern Repeat Counter Register  


### FFSR  

Relative Address = 0x00000300  
Width = 3 bits  
Access Type = ro  
Reset Value = 0x00000006  
Description Formatter and Flush Status Register  


### FFCR  

Relative Address = 0x00000304  
Width = 14 bits  
Access Type = mixed  
Reset Value = 0x00000000  
Description Formatter and Flush Control Register  


### FormatSyncCount  

Relative Address = 0x00000308  
Width = 12 bits  
Access Type = rw  
Reset Value = 0x00000040  
Description Formatter Synchronization Counter Register  


### EXTCTLIn  

Relative Address = 0x00000400  
Width = 8 bits  
Access Type = ro  
Reset Value = 0x00  
Description EXTCTL In Port  


### EXTCTLOut  

Relative Address = 0x00000404  
Width = 8 bits  
Access Type = rw  
Reset Value = 0x00  
Description EXTCTL Out Port  


### ITTRFLINACK  

Relative Address = 0x00000ee4  
Width = 2 bits  
Access Type = wo  
Reset Value = 0x00000000  
Description Integration Test Trigger In and Flush In Acknowledge Register  


### ITTRFLIN  

Relative Address = 0x00000ee8  
Width = 2 bits  
Access Type = ro  
Reset Value = 0x00000000  
Description Integration Test Trigger In and Flush In Register  


### ITATBDATA0  

Relative Address = 0x00000eec  
Width = 5 bits  
Access Type = ro  
Reset Value = 0x00000000  
Description Integration Test ATB Data Register 0  


### ITATBCTR2  

Relative Address = 0x00000ef0  
Width = 2 bits  
Access Type = wo  
Reset Value = 0x00000000  
Description Integration Test ATB Control Register 2  


### ITATBCTR1  

Relative Address = 0x00000ef4  
Width = 7 bits  
Access Type = ro  
Reset Value = 0x00000000  
Description Integration Test ATB Control Register 1  


### ITATBCTR0  

Relative Address = 0x00000ef8  
Width = 10 bits  
Access Type = ro  
Reset Value = 0x00000000  
Description Integration Test ATB Control Register 0  


### IMCR  

Relative Address = 0x00000f00  
Width = 1 bits  
Access Type = rw  
Reset Value = 0x00000000  
Description Integration Mode Control Register  


### CTSR  

Relative Address = 0x00000fa0  
Width = 4 bits  
Access Type = rw  
Reset Value = 0x0000000f  
Description Claim Tag Set Register  


### CTCR  

Relative Address = 0x00000fa4  
Width = 4 bits  
Access Type = rw  
Reset Value = 0x00000000  
Description Claim Tag Clear Register  


### LAR  

Relative Address = 0x00000fb0  
Width = 32 bits  
Access Type = wo  
Reset Value = 0x00000000  
Description Lock Access Register  


### LSR  

Relative Address = 0x00000fb4  
Width = 3 bits  
Access Type = ro  
Reset Value = 0x00000003  
Description Lock Status Register  


### ASR  

Relative Address = 0x00000fb8  
Width = 8 bits  
Access Type = ro  
Reset Value = 0x00  
Description Authentication Status Register  


### DEVID  

Relative Address = 0x00000fc8  
Width = 12 bits  
Access Type = ro  
Reset Value = 0x000000a0  
Description Device ID  


### DTIR  

Relative Address = 0x00000fcc  
Width = 8 bits  
Access Type = ro  
Reset Value = 0x11  
Description Device Type Identifier Register  


### PERIPHID4  

Relative Address = 0x00000fd0  
Width = 8 bits  
Access Type = ro  
Reset Value = 0x04  
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
Reset Value = 0x12  
Description Peripheral ID0  


### PERIPHID1  

Relative Address = 0x00000fe4  
Width = 8 bits  
Access Type = ro  
Reset Value = 0xb9  
Description Peripheral ID1  


### PERIPHID2  

Relative Address = 0x00000fe8  
Width = 8 bits  
Access Type = ro  
Reset Value = 0x4b  
Description Peripheral ID2  


### PERIPHID3  

Relative Address = 0x00000fec  
Width = 8 bits  
Access Type = ro  
Reset Value = 0x00  
Description Peripheral ID3  


### COMPID0  

Relative Address = 0x00000ff0  
Width = 8 bits  
Access Type = ro  
Reset Value = 0x0d  
Description Component ID0  


### COMPID1  

Relative Address = 0x00000ff4  
Width = 8 bits  
Access Type = ro  
Reset Value = 0x90  
Description Component ID1  


### COMPID2  

Relative Address = 0x00000ff8  
Width = 8 bits  
Access Type = ro  
Reset Value = 0x05  
Description Component ID2  


### COMPID3  

Relative Address = 0x00000ffc  
Width = 8 bits  
Access Type = ro  
Reset Value = 0xb1  
Description Component ID3  

