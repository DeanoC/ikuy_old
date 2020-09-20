# Fabric Trace  

Module Fabric Trace (itm)  
SPDX-License-Identifier: MIT  
Auto-generated: Sun Sep 20 23:32:01 EEST 2020  

itm Base Address = 0xf8805000  

## Register Summary  

+------------------------------+------------+------+------+------------+------------------------------+
|Register Name                 |Address     |Width |Type  |Reset Value |Description                   |
+==============================+============+======+======+============+==============================+
|**StimPort00**                |0x00000000  |32    |rw    |0x00000000  |Stimulus Port Register 0      |
+------------------------------+------------+------+------+------------+------------------------------+
|**StimPort01**                |0x00000004  |32    |rw    |0x00000000  |Stimulus Port Register 1      |
+------------------------------+------------+------+------+------------+------------------------------+
|**StimPort02**                |0x00000008  |32    |rw    |0x00000000  |Stimulus Port Register 2      |
+------------------------------+------------+------+------+------------+------------------------------+
|**StimPort03**                |0x0000000c  |32    |rw    |0x00000000  |Stimulus Port Register 3      |
+------------------------------+------------+------+------+------------+------------------------------+
|**StimPort04**                |0x00000010  |32    |rw    |0x00000000  |Stimulus Port Register 4      |
+------------------------------+------------+------+------+------------+------------------------------+
|**StimPort05**                |0x00000014  |32    |rw    |0x00000000  |Stimulus Port Register 5      |
+------------------------------+------------+------+------+------------+------------------------------+
|**StimPort06**                |0x00000018  |32    |rw    |0x00000000  |Stimulus Port Register 6      |
+------------------------------+------------+------+------+------------+------------------------------+
|**StimPort07**                |0x0000001c  |32    |rw    |0x00000000  |Stimulus Port Register 7      |
+------------------------------+------------+------+------+------------+------------------------------+
|**StimPort08**                |0x00000020  |32    |rw    |0x00000000  |Stimulus Port Register 8      |
+------------------------------+------------+------+------+------------+------------------------------+
|**StimPort09**                |0x00000024  |32    |rw    |0x00000000  |Stimulus Port Register 9      |
+------------------------------+------------+------+------+------------+------------------------------+
|**StimPort10**                |0x00000028  |32    |rw    |0x00000000  |Stimulus Port Register 10     |
+------------------------------+------------+------+------+------------+------------------------------+
|**StimPort11**                |0x0000002c  |32    |rw    |0x00000000  |Stimulus Port Register 11     |
+------------------------------+------------+------+------+------------+------------------------------+
|**StimPort12**                |0x00000030  |32    |rw    |0x00000000  |Stimulus Port Register 12     |
+------------------------------+------------+------+------+------------+------------------------------+
|**StimPort13**                |0x00000034  |32    |rw    |0x00000000  |Stimulus Port Register 13     |
+------------------------------+------------+------+------+------------+------------------------------+
|**StimPort14**                |0x00000038  |32    |rw    |0x00000000  |Stimulus Port Register 14     |
+------------------------------+------------+------+------+------------+------------------------------+
|**StimPort15**                |0x0000003c  |32    |rw    |0x00000000  |Stimulus Port Register 15     |
+------------------------------+------------+------+------+------------+------------------------------+
|**StimPort16**                |0x00000040  |32    |rw    |0x00000000  |Stimulus Port Register 16     |
+------------------------------+------------+------+------+------------+------------------------------+
|**StimPort17**                |0x00000044  |32    |rw    |0x00000000  |Stimulus Port Register 17     |
+------------------------------+------------+------+------+------------+------------------------------+
|**StimPort18**                |0x00000048  |32    |rw    |0x00000000  |Stimulus Port Register 18     |
+------------------------------+------------+------+------+------------+------------------------------+
|**StimPort19**                |0x0000004c  |32    |rw    |0x00000000  |Stimulus Port Register 19     |
+------------------------------+------------+------+------+------------+------------------------------+
|**StimPort20**                |0x00000050  |32    |rw    |0x00000000  |Stimulus Port Register 20     |
+------------------------------+------------+------+------+------------+------------------------------+
|**StimPort21**                |0x00000054  |32    |rw    |0x00000000  |Stimulus Port Register 21     |
+------------------------------+------------+------+------+------------+------------------------------+
|**StimPort22**                |0x00000058  |32    |rw    |0x00000000  |Stimulus Port Register 22     |
+------------------------------+------------+------+------+------------+------------------------------+
|**StimPort23**                |0x0000005c  |32    |rw    |0x00000000  |Stimulus Port Register 23     |
+------------------------------+------------+------+------+------------+------------------------------+
|**StimPort24**                |0x00000060  |32    |rw    |0x00000000  |Stimulus Port Register 24     |
+------------------------------+------------+------+------+------------+------------------------------+
|**StimPort25**                |0x00000064  |32    |rw    |0x00000000  |Stimulus Port Register 25     |
+------------------------------+------------+------+------+------------+------------------------------+
|**StimPort26**                |0x00000068  |32    |rw    |0x00000000  |Stimulus Port Register 26     |
+------------------------------+------------+------+------+------------+------------------------------+
|**StimPort27**                |0x0000006c  |32    |rw    |0x00000000  |Stimulus Port Register 27     |
+------------------------------+------------+------+------+------------+------------------------------+
|**StimPort28**                |0x00000070  |32    |rw    |0x00000000  |Stimulus Port Register 28     |
+------------------------------+------------+------+------+------------+------------------------------+
|**StimPort29**                |0x00000074  |32    |rw    |0x00000000  |Stimulus Port Register 29     |
+------------------------------+------------+------+------+------------+------------------------------+
|**StimPort30**                |0x00000078  |32    |rw    |0x00000000  |Stimulus Port Register 30     |
+------------------------------+------------+------+------+------------+------------------------------+
|**StimPort31**                |0x0000007c  |32    |rw    |0x00000000  |Stimulus Port Register 31     |
+------------------------------+------------+------+------+------------+------------------------------+
|**TER**                       |0x00000e00  |32    |rw    |0x00000000  |Trace Enable Register         |
+------------------------------+------------+------+------+------------+------------------------------+
|**TTR**                       |0x00000e20  |32    |rw    |0x00000000  |Trace Trigger Register        |
+------------------------------+------------+------+------+------------+------------------------------+
|**CR**                        |0x00000e80  |24    |mixed |0x00000004  |Control Register              |
+------------------------------+------------+------+------+------------+------------------------------+
|**SCR**                       |0x00000e90  |12    |rw    |0x00000400  | Synchronization Control Regi |
+------------------------------+------------+------+------+------------+------------------------------+
|**ITTRIGOUTACK**              |0x00000ee4  |1     |ro    |0x00000000  | Integration Test Trigger Out |
+------------------------------+------------+------+------+------------+------------------------------+
|**ITTRIGOUT**                 |0x00000ee8  |1     |wo    |0x00000000  | Integration Test Trigger Out |
+------------------------------+------------+------+------+------------+------------------------------+
|**ITATBDATA0**                |0x00000eec  |2     |wo    |0x00000000  | Integration Test ATB Data Re |
+------------------------------+------------+------+------+------------+------------------------------+
|**ITATBCTR2**                 |0x00000ef0  |1     |ro    |0x00000001  | Integration Test ATB Control |
+------------------------------+------------+------+------+------------+------------------------------+
|**ITATABCTR1**                |0x00000ef4  |7     |wo    |0x00000000  | Integration Test ATB Control |
+------------------------------+------------+------+------+------------+------------------------------+
|**ITATBCTR0**                 |0x00000ef8  |2     |wo    |0x00000000  | Integration Test ATB Control |
+------------------------------+------------+------+------+------------+------------------------------+
|**IMCR**                      |0x00000f00  |1     |rw    |0x00000000  | Integration Mode Control Reg |
+------------------------------+------------+------+------+------------+------------------------------+
|**CTSR**                      |0x00000fa0  |8     |rw    |0xff        |Claim Tag Set Register        |
+------------------------------+------------+------+------+------------+------------------------------+
|**CTCR**                      |0x00000fa4  |8     |rw    |0x00        |Claim Tag Clear Register      |
+------------------------------+------------+------+------+------------+------------------------------+
|**LAR**                       |0x00000fb0  |32    |wo    |0x00000000  |Lock Access Register          |
+------------------------------+------------+------+------+------------+------------------------------+
|**LSR**                       |0x00000fb4  |3     |ro    |0x00000003  |Lock Status Register          |
+------------------------------+------------+------+------+------------+------------------------------+
|**ASR**                       |0x00000fb8  |8     |ro    |0x88        | Authentication Status Regist |
+------------------------------+------------+------+------+------------+------------------------------+
|**DEVID**                     |0x00000fc8  |13    |ro    |0x00000020  |Device ID                     |
+------------------------------+------------+------+------+------------+------------------------------+
|**DTIR**                      |0x00000fcc  |8     |ro    |0x43        | Device Type Identifier Regis |
+------------------------------+------------+------+------+------------+------------------------------+
|**PERIPHID4**                 |0x00000fd0  |8     |ro    |0x04        |Peripheral ID4                |
+------------------------------+------------+------+------+------------+------------------------------+
|**PERIPHID5**                 |0x00000fd4  |8     |ro    |0x00        |Peripheral ID5                |
+------------------------------+------------+------+------+------------+------------------------------+
|**PERIPHID6**                 |0x00000fd8  |8     |ro    |0x00        |Peripheral ID6                |
+------------------------------+------------+------+------+------------+------------------------------+
|**PERIPHID7**                 |0x00000fdc  |8     |ro    |0x00        |Peripheral ID7                |
+------------------------------+------------+------+------+------------+------------------------------+
|**PERIPHID0**                 |0x00000fe0  |8     |ro    |0x13        |Peripheral ID0                |
+------------------------------+------------+------+------+------------+------------------------------+
|**PERIPHID1**                 |0x00000fe4  |8     |ro    |0xb9        |Peripheral ID1                |
+------------------------------+------------+------+------+------------+------------------------------+
|**PERIPHID2**                 |0x00000fe8  |8     |ro    |0x2b        |Peripheral ID2                |
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

### StimPort00  

Relative Address = 0x00000000  
Width = 32 bits  
Access Type = rw  
Reset Value = 0x00000000  
Description Stimulus Port Register 0  


### StimPort01  

Relative Address = 0x00000004  
Width = 32 bits  
Access Type = rw  
Reset Value = 0x00000000  
Description Stimulus Port Register 1  


### StimPort02  

Relative Address = 0x00000008  
Width = 32 bits  
Access Type = rw  
Reset Value = 0x00000000  
Description Stimulus Port Register 2  


### StimPort03  

Relative Address = 0x0000000c  
Width = 32 bits  
Access Type = rw  
Reset Value = 0x00000000  
Description Stimulus Port Register 3  


### StimPort04  

Relative Address = 0x00000010  
Width = 32 bits  
Access Type = rw  
Reset Value = 0x00000000  
Description Stimulus Port Register 4  


### StimPort05  

Relative Address = 0x00000014  
Width = 32 bits  
Access Type = rw  
Reset Value = 0x00000000  
Description Stimulus Port Register 5  


### StimPort06  

Relative Address = 0x00000018  
Width = 32 bits  
Access Type = rw  
Reset Value = 0x00000000  
Description Stimulus Port Register 6  


### StimPort07  

Relative Address = 0x0000001c  
Width = 32 bits  
Access Type = rw  
Reset Value = 0x00000000  
Description Stimulus Port Register 7  


### StimPort08  

Relative Address = 0x00000020  
Width = 32 bits  
Access Type = rw  
Reset Value = 0x00000000  
Description Stimulus Port Register 8  


### StimPort09  

Relative Address = 0x00000024  
Width = 32 bits  
Access Type = rw  
Reset Value = 0x00000000  
Description Stimulus Port Register 9  


### StimPort10  

Relative Address = 0x00000028  
Width = 32 bits  
Access Type = rw  
Reset Value = 0x00000000  
Description Stimulus Port Register 10  


### StimPort11  

Relative Address = 0x0000002c  
Width = 32 bits  
Access Type = rw  
Reset Value = 0x00000000  
Description Stimulus Port Register 11  


### StimPort12  

Relative Address = 0x00000030  
Width = 32 bits  
Access Type = rw  
Reset Value = 0x00000000  
Description Stimulus Port Register 12  


### StimPort13  

Relative Address = 0x00000034  
Width = 32 bits  
Access Type = rw  
Reset Value = 0x00000000  
Description Stimulus Port Register 13  


### StimPort14  

Relative Address = 0x00000038  
Width = 32 bits  
Access Type = rw  
Reset Value = 0x00000000  
Description Stimulus Port Register 14  


### StimPort15  

Relative Address = 0x0000003c  
Width = 32 bits  
Access Type = rw  
Reset Value = 0x00000000  
Description Stimulus Port Register 15  


### StimPort16  

Relative Address = 0x00000040  
Width = 32 bits  
Access Type = rw  
Reset Value = 0x00000000  
Description Stimulus Port Register 16  


### StimPort17  

Relative Address = 0x00000044  
Width = 32 bits  
Access Type = rw  
Reset Value = 0x00000000  
Description Stimulus Port Register 17  


### StimPort18  

Relative Address = 0x00000048  
Width = 32 bits  
Access Type = rw  
Reset Value = 0x00000000  
Description Stimulus Port Register 18  


### StimPort19  

Relative Address = 0x0000004c  
Width = 32 bits  
Access Type = rw  
Reset Value = 0x00000000  
Description Stimulus Port Register 19  


### StimPort20  

Relative Address = 0x00000050  
Width = 32 bits  
Access Type = rw  
Reset Value = 0x00000000  
Description Stimulus Port Register 20  


### StimPort21  

Relative Address = 0x00000054  
Width = 32 bits  
Access Type = rw  
Reset Value = 0x00000000  
Description Stimulus Port Register 21  


### StimPort22  

Relative Address = 0x00000058  
Width = 32 bits  
Access Type = rw  
Reset Value = 0x00000000  
Description Stimulus Port Register 22  


### StimPort23  

Relative Address = 0x0000005c  
Width = 32 bits  
Access Type = rw  
Reset Value = 0x00000000  
Description Stimulus Port Register 23  


### StimPort24  

Relative Address = 0x00000060  
Width = 32 bits  
Access Type = rw  
Reset Value = 0x00000000  
Description Stimulus Port Register 24  


### StimPort25  

Relative Address = 0x00000064  
Width = 32 bits  
Access Type = rw  
Reset Value = 0x00000000  
Description Stimulus Port Register 25  


### StimPort26  

Relative Address = 0x00000068  
Width = 32 bits  
Access Type = rw  
Reset Value = 0x00000000  
Description Stimulus Port Register 26  


### StimPort27  

Relative Address = 0x0000006c  
Width = 32 bits  
Access Type = rw  
Reset Value = 0x00000000  
Description Stimulus Port Register 27  


### StimPort28  

Relative Address = 0x00000070  
Width = 32 bits  
Access Type = rw  
Reset Value = 0x00000000  
Description Stimulus Port Register 28  


### StimPort29  

Relative Address = 0x00000074  
Width = 32 bits  
Access Type = rw  
Reset Value = 0x00000000  
Description Stimulus Port Register 29  


### StimPort30  

Relative Address = 0x00000078  
Width = 32 bits  
Access Type = rw  
Reset Value = 0x00000000  
Description Stimulus Port Register 30  


### StimPort31  

Relative Address = 0x0000007c  
Width = 32 bits  
Access Type = rw  
Reset Value = 0x00000000  
Description Stimulus Port Register 31  


### TER  

Relative Address = 0x00000e00  
Width = 32 bits  
Access Type = rw  
Reset Value = 0x00000000  
Description Trace Enable Register  


### TTR  

Relative Address = 0x00000e20  
Width = 32 bits  
Access Type = rw  
Reset Value = 0x00000000  
Description Trace Trigger Register  


### CR  

Relative Address = 0x00000e80  
Width = 24 bits  
Access Type = mixed  
Reset Value = 0x00000004  
Description Control Register  


### SCR  

Relative Address = 0x00000e90  
Width = 12 bits  
Access Type = rw  
Reset Value = 0x00000400  
Description Synchronization Control Register  


### ITTRIGOUTACK  

Relative Address = 0x00000ee4  
Width = 1 bits  
Access Type = ro  
Reset Value = 0x00000000  
Description Integration Test Trigger Out Acknowledge Register  


### ITTRIGOUT  

Relative Address = 0x00000ee8  
Width = 1 bits  
Access Type = wo  
Reset Value = 0x00000000  
Description Integration Test Trigger Out Register  


### ITATBDATA0  

Relative Address = 0x00000eec  
Width = 2 bits  
Access Type = wo  
Reset Value = 0x00000000  
Description Integration Test ATB Data Register 0  


### ITATBCTR2  

Relative Address = 0x00000ef0  
Width = 1 bits  
Access Type = ro  
Reset Value = 0x00000001  
Description Integration Test ATB Control Register 2  


### ITATABCTR1  

Relative Address = 0x00000ef4  
Width = 7 bits  
Access Type = wo  
Reset Value = 0x00000000  
Description Integration Test ATB Control Register 1  


### ITATBCTR0  

Relative Address = 0x00000ef8  
Width = 2 bits  
Access Type = wo  
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
Width = 8 bits  
Access Type = rw  
Reset Value = 0xff  
Description Claim Tag Set Register  


### CTCR  

Relative Address = 0x00000fa4  
Width = 8 bits  
Access Type = rw  
Reset Value = 0x00  
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
Reset Value = 0x88  
Description Authentication Status Register  


### DEVID  

Relative Address = 0x00000fc8  
Width = 13 bits  
Access Type = ro  
Reset Value = 0x00000020  
Description Device ID  


### DTIR  

Relative Address = 0x00000fcc  
Width = 8 bits  
Access Type = ro  
Reset Value = 0x43  
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
Reset Value = 0x13  
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
Reset Value = 0x2b  
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

