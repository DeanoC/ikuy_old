# CoreSight Trace Funnel  

Module CoreSight Trace Funnel (funnel)  
SPDX-License-Identifier: MIT  
Auto-generated: Sun Sep 20 15:25:57 EEST 2020  

funnel Base Address = 0xf8804000  

## Register Summary  

+------------------------------+------------+------+------+------------+------------------------------+
|Register Name                 |Address     |Width |Type  |Reset Value |Description                   |
+==============================+============+======+======+============+==============================+
|**CONTROL**                   |0x00000000  |12    |rw    |0x00000300  |CSTF Control Register         |
+------------------------------+------------+------+------+------------+------------------------------+
|**PRICONTROL**                |0x00000004  |24    |rw    |0x00fac688  | CSTF Priority Control Regist |
+------------------------------+------------+------+------+------------+------------------------------+
|**ITATBDATA0**                |0x00000eec  |5     |rw    |0x00000000  | Integration Test ATB Data 0  |
+------------------------------+------------+------+------+------------+------------------------------+
|**ITATBCTR2**                 |0x00000ef0  |2     |rw    |0x00000000  | Integration Test ATB Control |
+------------------------------+------------+------+------+------------+------------------------------+
|**ITATBCTR1**                 |0x00000ef4  |7     |rw    |0x00000000  | Integration Test ATB Control |
+------------------------------+------------+------+------+------------+------------------------------+
|**ITATBCTR0**                 |0x00000ef8  |10    |mixed |0x00000000  | Integration Test ATB Control |
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
|**DEVID**                     |0x00000fc8  |8     |ro    |0x28        |Device ID                     |
+------------------------------+------------+------+------+------------+------------------------------+
|**DTIR**                      |0x00000fcc  |8     |ro    |0x12        | Device Type Identifier Regis |
+------------------------------+------------+------+------+------------+------------------------------+
|**PERIPHID4**                 |0x00000fd0  |8     |ro    |0x04        |Peripheral ID4                |
+------------------------------+------------+------+------+------------+------------------------------+
|**PERIPHID5**                 |0x00000fd4  |8     |ro    |0x00        |Peripheral ID5                |
+------------------------------+------------+------+------+------------+------------------------------+
|**PERIPHID6**                 |0x00000fd8  |8     |ro    |0x00        |Peripheral ID6                |
+------------------------------+------------+------+------+------------+------------------------------+
|**PERIPHID7**                 |0x00000fdc  |8     |ro    |0x00        |Peripheral ID7                |
+------------------------------+------------+------+------+------------+------------------------------+
|**PERIPHID0**                 |0x00000fe0  |8     |ro    |0x08        |Peripheral ID0                |
+------------------------------+------------+------+------+------------+------------------------------+
|**PERIPHID1**                 |0x00000fe4  |8     |ro    |0xb9        |Peripheral ID1                |
+------------------------------+------------+------+------+------------+------------------------------+
|**PERIPHID2**                 |0x00000fe8  |8     |ro    |0x1b        |Peripheral ID2                |
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

### CONTROL  

Module funnel  
Relative Address = 0x00000000  
Width = 12 bits  
Access Type = rw  
Reset Value = 0x00000300  
Description CSTF Control Register  


### PRICONTROL  

Module funnel  
Relative Address = 0x00000004  
Width = 24 bits  
Access Type = rw  
Reset Value = 0x00fac688  
Description CSTF Priority Control Register  


### ITATBDATA0  

Module funnel  
Relative Address = 0x00000eec  
Width = 5 bits  
Access Type = rw  
Reset Value = 0x00000000  
Description Integration Test ATB Data 0 Register  


### ITATBCTR2  

Module funnel  
Relative Address = 0x00000ef0  
Width = 2 bits  
Access Type = rw  
Reset Value = 0x00000000  
Description Integration Test ATB Control 2 Register  


### ITATBCTR1  

Module funnel  
Relative Address = 0x00000ef4  
Width = 7 bits  
Access Type = rw  
Reset Value = 0x00000000  
Description Integration Test ATB Control 1 Register  


### ITATBCTR0  

Module funnel  
Relative Address = 0x00000ef8  
Width = 10 bits  
Access Type = mixed  
Reset Value = 0x00000000  
Description Integration Test ATB Control 0 Register  


### IMCR  

Module funnel  
Relative Address = 0x00000f00  
Width = 1 bits  
Access Type = rw  
Reset Value = 0x00000000  
Description Integration Mode Control Register  


### CTSR  

Module funnel  
Relative Address = 0x00000fa0  
Width = 4 bits  
Access Type = rw  
Reset Value = 0x0000000f  
Description Claim Tag Set Register  


### CTCR  

Module funnel  
Relative Address = 0x00000fa4  
Width = 4 bits  
Access Type = rw  
Reset Value = 0x00000000  
Description Claim Tag Clear Register  


### LAR  

Module funnel  
Relative Address = 0x00000fb0  
Width = 32 bits  
Access Type = wo  
Reset Value = 0x00000000  
Description Lock Access Register  


### LSR  

Module funnel  
Relative Address = 0x00000fb4  
Width = 3 bits  
Access Type = ro  
Reset Value = 0x00000003  
Description Lock Status Register  


### ASR  

Module funnel  
Relative Address = 0x00000fb8  
Width = 8 bits  
Access Type = ro  
Reset Value = 0x00  
Description Authentication Status Register  


### DEVID  

Module funnel  
Relative Address = 0x00000fc8  
Width = 8 bits  
Access Type = ro  
Reset Value = 0x28  
Description Device ID  


### DTIR  

Module funnel  
Relative Address = 0x00000fcc  
Width = 8 bits  
Access Type = ro  
Reset Value = 0x12  
Description Device Type Identifier Register  


### PERIPHID4  

Module funnel  
Relative Address = 0x00000fd0  
Width = 8 bits  
Access Type = ro  
Reset Value = 0x04  
Description Peripheral ID4  


### PERIPHID5  

Module funnel  
Relative Address = 0x00000fd4  
Width = 8 bits  
Access Type = ro  
Reset Value = 0x00  
Description Peripheral ID5  


### PERIPHID6  

Module funnel  
Relative Address = 0x00000fd8  
Width = 8 bits  
Access Type = ro  
Reset Value = 0x00  
Description Peripheral ID6  


### PERIPHID7  

Module funnel  
Relative Address = 0x00000fdc  
Width = 8 bits  
Access Type = ro  
Reset Value = 0x00  
Description Peripheral ID7  


### PERIPHID0  

Module funnel  
Relative Address = 0x00000fe0  
Width = 8 bits  
Access Type = ro  
Reset Value = 0x08  
Description Peripheral ID0  


### PERIPHID1  

Module funnel  
Relative Address = 0x00000fe4  
Width = 8 bits  
Access Type = ro  
Reset Value = 0xb9  
Description Peripheral ID1  


### PERIPHID2  

Module funnel  
Relative Address = 0x00000fe8  
Width = 8 bits  
Access Type = ro  
Reset Value = 0x1b  
Description Peripheral ID2  


### PERIPHID3  

Module funnel  
Relative Address = 0x00000fec  
Width = 8 bits  
Access Type = ro  
Reset Value = 0x00  
Description Peripheral ID3  


### COMPID0  

Module funnel  
Relative Address = 0x00000ff0  
Width = 8 bits  
Access Type = ro  
Reset Value = 0x0d  
Description Component ID0  


### COMPID1  

Module funnel  
Relative Address = 0x00000ff4  
Width = 8 bits  
Access Type = ro  
Reset Value = 0x90  
Description Component ID1  


### COMPID2  

Module funnel  
Relative Address = 0x00000ff8  
Width = 8 bits  
Access Type = ro  
Reset Value = 0x05  
Description Component ID2  


### COMPID3  

Module funnel  
Relative Address = 0x00000ffc  
Width = 8 bits  
Access Type = ro  
Reset Value = 0xb1  
Description Component ID3  

