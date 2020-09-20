# Embedded Trace Buffer  

Module Embedded Trace Buffer (etb)  
SPDX-License-Identifier: MIT  
Auto-generated: Sun Sep 20 23:32:01 EEST 2020  

etb Base Address = 0xf8801000  

## Register Summary  

+------------------------------+------------+------+------+------------+------------------------------+
|Register Name                 |Address     |Width |Type  |Reset Value |Description                   |
+==============================+============+======+======+============+==============================+
|**RDP**                       |0x00000004  |32    |ro    |0x00000400  |RAM Depth Register            |
+------------------------------+------------+------+------+------------+------------------------------+
|**STS**                       |0x0000000c  |4     |ro    |0x00000000  |Status Register               |
+------------------------------+------------+------+------+------------+------------------------------+
|**RRD**                       |0x00000010  |32    |ro    |0x00000000  |RAM Read Data Register        |
+------------------------------+------------+------+------+------------+------------------------------+
|**RRP**                       |0x00000014  |10    |rw    |0x00000000  |RAM Read Pointer Register     |
+------------------------------+------------+------+------+------------+------------------------------+
|**RWP**                       |0x00000018  |10    |rw    |0x00000000  |RAM Write Pointer Register    |
+------------------------------+------------+------+------+------------+------------------------------+
|**TRG**                       |0x0000001c  |10    |rw    |0x00000000  |Trigger Counter Register      |
+------------------------------+------------+------+------+------------+------------------------------+
|**CTL**                       |0x00000020  |1     |rw    |0x00000000  |Control Register              |
+------------------------------+------------+------+------+------------+------------------------------+
|**RWD**                       |0x00000024  |32    |rw    |0x00000000  |RAM Write Data Register       |
+------------------------------+------------+------+------+------------+------------------------------+
|**FFSR**                      |0x00000300  |2     |ro    |0x00000002  | Formatter and Flush Status R |
+------------------------------+------------+------+------+------------+------------------------------+
|**FFCR**                      |0x00000304  |14    |mixed |0x00000200  | Formatter and Flush Control  |
+------------------------------+------------+------+------+------------+------------------------------+
|**ITMISCOP0**                 |0x00000ee0  |2     |wo    |0x00000000  | Integration Test Miscellaneo |
+------------------------------+------------+------+------+------------+------------------------------+
|**ITTRFLINACK**               |0x00000ee4  |2     |wo    |0x00000000  | Integration Test Trigger In  |
+------------------------------+------------+------+------+------------+------------------------------+
|**ITTRFLIN**                  |0x00000ee8  |2     |wo    |0x00000000  | Integration Test Trigger In  |
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
|**DEVID**                     |0x00000fc8  |6     |ro    |0x00000000  |Device ID                     |
+------------------------------+------------+------+------+------------+------------------------------+
|**DTIR**                      |0x00000fcc  |8     |ro    |0x21        | Device Type Identifier Regis |
+------------------------------+------------+------+------+------------+------------------------------+
|**PERIPHID4**                 |0x00000fd0  |8     |ro    |0x04        |Peripheral ID4                |
+------------------------------+------------+------+------+------------+------------------------------+
|**PERIPHID5**                 |0x00000fd4  |8     |ro    |0x00        |Peripheral ID5                |
+------------------------------+------------+------+------+------------+------------------------------+
|**PERIPHID6**                 |0x00000fd8  |8     |ro    |0x00        |Peripheral ID6                |
+------------------------------+------------+------+------+------------+------------------------------+
|**PERIPHID7**                 |0x00000fdc  |8     |ro    |0x00        |Peripheral ID7                |
+------------------------------+------------+------+------+------------+------------------------------+
|**PERIPHID0**                 |0x00000fe0  |8     |ro    |0x07        |Peripheral ID0                |
+------------------------------+------------+------+------+------------+------------------------------+
|**PERIPHID1**                 |0x00000fe4  |8     |ro    |0xb9        |Peripheral ID1                |
+------------------------------+------------+------+------+------------+------------------------------+
|**PERIPHID2**                 |0x00000fe8  |8     |ro    |0x3b        |Peripheral ID2                |
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

### RDP  

Relative Address = 0x00000004  
Width = 32 bits  
Access Type = ro  
Reset Value = 0x00000400  
Description RAM Depth Register  


### STS  

Relative Address = 0x0000000c  
Width = 4 bits  
Access Type = ro  
Reset Value = 0x00000000  
Description Status Register  


### RRD  

Relative Address = 0x00000010  
Width = 32 bits  
Access Type = ro  
Reset Value = 0x00000000  
Description RAM Read Data Register  


### RRP  

Relative Address = 0x00000014  
Width = 10 bits  
Access Type = rw  
Reset Value = 0x00000000  
Description RAM Read Pointer Register  


### RWP  

Relative Address = 0x00000018  
Width = 10 bits  
Access Type = rw  
Reset Value = 0x00000000  
Description RAM Write Pointer Register  


### TRG  

Relative Address = 0x0000001c  
Width = 10 bits  
Access Type = rw  
Reset Value = 0x00000000  
Description Trigger Counter Register  


### CTL  

Relative Address = 0x00000020  
Width = 1 bits  
Access Type = rw  
Reset Value = 0x00000000  
Description Control Register  


### RWD  

Relative Address = 0x00000024  
Width = 32 bits  
Access Type = rw  
Reset Value = 0x00000000  
Description RAM Write Data Register  


### FFSR  

Relative Address = 0x00000300  
Width = 2 bits  
Access Type = ro  
Reset Value = 0x00000002  
Description Formatter and Flush Status Register  


### FFCR  

Relative Address = 0x00000304  
Width = 14 bits  
Access Type = mixed  
Reset Value = 0x00000200  
Description Formatter and Flush Control Register  


### ITMISCOP0  

Relative Address = 0x00000ee0  
Width = 2 bits  
Access Type = wo  
Reset Value = 0x00000000  
Description Integration Test Miscellaneous Output Register 0  


### ITTRFLINACK  

Relative Address = 0x00000ee4  
Width = 2 bits  
Access Type = wo  
Reset Value = 0x00000000  
Description Integration Test Trigger In and Flush In Acknowledge Register  


### ITTRFLIN  

Relative Address = 0x00000ee8  
Width = 2 bits  
Access Type = wo  
Reset Value = 0x00000000  
Description Integration Test Trigger In and Flush In Register  


### ITATBDATA0  

Relative Address = 0x00000eec  
Width = 5 bits  
Access Type = ro  
Reset Value = 0x00000000  
Description Integration Test ATB Data Register  


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
Width = 6 bits  
Access Type = ro  
Reset Value = 0x00000000  
Description Device ID  


### DTIR  

Relative Address = 0x00000fcc  
Width = 8 bits  
Access Type = ro  
Reset Value = 0x21  
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
Reset Value = 0x07  
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
Reset Value = 0x3b  
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

