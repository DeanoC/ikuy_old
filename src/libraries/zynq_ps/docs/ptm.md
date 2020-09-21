# CoreSight PTM-A9  

Module CoreSight PTM-A9 (ptm)  
SPDX-License-Identifier: MIT  
Auto-generated: Mon Sep 21 21:57:55 EEST 2020  

debug_cpu_ptm0 Base Address = 0xf889c000  
debug_cpu_ptm1 Base Address = 0xf889d000  

## Register Summary  

+------------------------------+------------+------+------+------------+------------------------------+
|Register Name                 |Address     |Width |Type  |Reset Value |Description                   |
+==============================+============+======+======+============+==============================+
|**CR**                        |0x00000000  |30    |rw    |0x00000401  |Main Control Register         |
+------------------------------+------------+------+------+------------+------------------------------+
|**CCR**                       |0x00000004  |32    |ro    |0x00000000  |Configuration Code Register   |
+------------------------------+------------+------+------+------------+------------------------------+
|**TRIGGER**                   |0x00000008  |17    |rw    |0x00000000  |Trigger Event Register        |
+------------------------------+------------+------+------+------------+------------------------------+
|**SR**                        |0x00000010  |4     |mixed |0x00000002  |Status Register               |
+------------------------------+------------+------+------+------------+------------------------------+
|**SCR**                       |0x00000014  |15    |ro    |0x00000000  |System Configuration Register |
+------------------------------+------------+------+------+------------+------------------------------+
|**TSSCR**                     |0x00000018  |24    |rw    |0x00000000  | TraceEnable Start/Stop Contr |
+------------------------------+------------+------+------+------------+------------------------------+
|**TEEVR**                     |0x00000020  |32    |rw    |0x00000000  |TraceEnable Event             |
+------------------------------+------------+------+------+------------+------------------------------+
|**TECR1**                     |0x00000024  |26    |rw    |0x00000000  | TraceEnable Control Register |
+------------------------------+------------+------+------+------------+------------------------------+
|**ACVR1**                     |0x00000040  |32    |rw    |0x00000000  | Address Comparator Value Reg |
+------------------------------+------------+------+------+------------+------------------------------+
|**ACVR2**                     |0x00000044  |32    |rw    |0x00000000  | Address Comparator Value Reg |
+------------------------------+------------+------+------+------------+------------------------------+
|**ACVR3**                     |0x00000048  |32    |rw    |0x00000000  | Address Comparator Value Reg |
+------------------------------+------------+------+------+------------+------------------------------+
|**ACVR4**                     |0x0000004c  |32    |rw    |0x00000000  | Address Comparator Value Reg |
+------------------------------+------------+------+------+------------+------------------------------+
|**ACVR5**                     |0x00000050  |32    |rw    |0x00000000  | Address Comparator Value Reg |
+------------------------------+------------+------+------+------------+------------------------------+
|**ACVR6**                     |0x00000054  |32    |rw    |0x00000000  | Address Comparator Value Reg |
+------------------------------+------------+------+------+------------+------------------------------+
|**ACVR7**                     |0x00000058  |32    |rw    |0x00000000  | Address Comparator Value Reg |
+------------------------------+------------+------+------+------------+------------------------------+
|**ACVR8**                     |0x0000005c  |32    |rw    |0x00000000  | Address Comparator Value Reg |
+------------------------------+------------+------+------+------------+------------------------------+
|**ACTR1**                     |0x00000080  |12    |mixed |0x00000001  | Address Comparator Access Ty |
+------------------------------+------------+------+------+------------+------------------------------+
|**ACTR2**                     |0x00000084  |12    |mixed |0x00000001  | Address Comparator Access Ty |
+------------------------------+------------+------+------+------------+------------------------------+
|**ACTR3**                     |0x00000088  |12    |mixed |0x00000001  | Address Comparator Access Ty |
+------------------------------+------------+------+------+------------+------------------------------+
|**ACTR4**                     |0x0000008c  |12    |mixed |0x00000001  | Address Comparator Access Ty |
+------------------------------+------------+------+------+------------+------------------------------+
|**ACTR5**                     |0x00000090  |12    |mixed |0x00000001  | Address Comparator Access Ty |
+------------------------------+------------+------+------+------------+------------------------------+
|**ACTR6**                     |0x00000094  |12    |mixed |0x00000001  | Address Comparator Access Ty |
+------------------------------+------------+------+------+------------+------------------------------+
|**ACTR7**                     |0x00000098  |12    |mixed |0x00000001  | Address Comparator Access Ty |
+------------------------------+------------+------+------+------------+------------------------------+
|**ACTR8**                     |0x0000009c  |12    |mixed |0x00000001  | Address Comparator Access Ty |
+------------------------------+------------+------+------+------------+------------------------------+
|**CNTRLDVR1**                 |0x00000140  |16    |rw    |0x0000      | Counter Reload Value Registe |
+------------------------------+------------+------+------+------------+------------------------------+
|**CNTRLDVR2**                 |0x00000144  |16    |rw    |0x0000      | Counter Reload Value Registe |
+------------------------------+------------+------+------+------------+------------------------------+
|**CNTENR1**                   |0x00000150  |18    |mixed |0x00020000  | Counter Enable Event Registe |
+------------------------------+------------+------+------+------------+------------------------------+
|**CNTENR2**                   |0x00000154  |18    |mixed |0x00020000  | Counter Enable Event Registe |
+------------------------------+------------+------+------+------------+------------------------------+
|**CNTRLDEVR1**                |0x00000160  |17    |rw    |0x00000000  | Counter Reload Event Registe |
+------------------------------+------------+------+------+------------+------------------------------+
|**CNTRLDEVR2**                |0x00000164  |17    |rw    |0x00000000  | Counter Reload Event Registe |
+------------------------------+------------+------+------+------------+------------------------------+
|**CNTVR1**                    |0x00000170  |16    |rw    |0x0000      |Counter Value Register 1      |
+------------------------------+------------+------+------+------------+------------------------------+
|**CNTVR2**                    |0x00000174  |16    |rw    |0x0000      |Counter Value Register 2      |
+------------------------------+------------+------+------+------------+------------------------------+
|**SQ12EVR**                   |0x00000180  |17    |rw    |0x00000000  | Sequencer State Transition E |
+------------------------------+------------+------+------+------------+------------------------------+
|**SQ21EVR**                   |0x00000184  |17    |rw    |0x00000000  | Sequencer State Transition E |
+------------------------------+------------+------+------+------------+------------------------------+
|**SQ23EVR**                   |0x00000188  |17    |rw    |0x00000000  | Sequencer State Transition E |
+------------------------------+------------+------+------+------------+------------------------------+
|**SQ31EVR**                   |0x0000018c  |17    |rw    |0x00000000  | Sequencer State Transition E |
+------------------------------+------------+------+------+------------+------------------------------+
|**SQ32EVR**                   |0x00000190  |17    |rw    |0x00000000  | Sequencer State Transition E |
+------------------------------+------------+------+------+------------+------------------------------+
|**SQ13EVR**                   |0x00000194  |17    |rw    |0x00000000  | Sequencer State Transition E |
+------------------------------+------------+------+------+------------+------------------------------+
|**SQR**                       |0x0000019c  |2     |rw    |0x00000000  | Current Sequencer State Regi |
+------------------------------+------------+------+------+------------+------------------------------+
|**EXTOUTEVR1**                |0x000001a0  |17    |rw    |0x00000000  | External Output Event Regist |
+------------------------------+------------+------+------+------------+------------------------------+
|**EXTOUTEVR2**                |0x000001a4  |17    |rw    |0x00000000  | External Output Event Regist |
+------------------------------+------------+------+------+------------+------------------------------+
|**CIDCVR1**                   |0x000001b0  |32    |rw    |0x00000000  | Context ID Comparator Value  |
+------------------------------+------------+------+------+------------+------------------------------+
|**CIDCMR**                    |0x000001bc  |32    |rw    |0x00000000  | Context ID Comparator Mask R |
+------------------------------+------------+------+------+------------+------------------------------+
|**SYNCFR**                    |0x000001e0  |12    |mixed |0x00000400  | Synchronization Frequency Re |
+------------------------------+------------+------+------+------------+------------------------------+
|**IDR**                       |0x000001e4  |32    |ro    |0x411cf301  |ID Register                   |
+------------------------------+------------+------+------+------------+------------------------------+
|**CCER**                      |0x000001e8  |26    |ro    |0x000008ea  | Configuration Code Extension |
+------------------------------+------------+------+------+------------+------------------------------+
|**EXTINSELR**                 |0x000001ec  |14    |rw    |0x00000000  | Extended External Input Sele |
+------------------------------+------------+------+------+------------+------------------------------+
|**TSEVR**                     |0x000001f8  |32    |rw    |0x00000000  |Timestamp Event               |
+------------------------------+------------+------+------+------------+------------------------------+
|**AUXCR**                     |0x000001fc  |4     |rw    |0x00000000  |Auxiliary Control Register    |
+------------------------------+------------+------+------+------------+------------------------------+
|**TRACEIDR**                  |0x00000200  |7     |rw    |0x00000000  |CoreSight Trace ID Register   |
+------------------------------+------------+------+------+------------+------------------------------+
|**OSLSR**                     |0x00000304  |32    |ro    |0x00000000  |OS Lock Status Register       |
+------------------------------+------------+------+------+------------+------------------------------+
|**PDSR**                      |0x00000314  |32    |ro    |0x00000001  | Device Powerdown Status Regi |
+------------------------------+------------+------+------+------------+------------------------------+
|**ITMISCOUT**                 |0x00000edc  |10    |wo    |0x00000000  | Miscellaneous Outputs Regist |
+------------------------------+------------+------+------+------------+------------------------------+
|**ITMISCIN**                  |0x00000ee0  |7     |ro    |0x00000000  |Miscellaneous Inputs Register |
+------------------------------+------------+------+------+------------+------------------------------+
|**ITTRIGGER**                 |0x00000ee8  |1     |wo    |0x00000000  |Trigger Register              |
+------------------------------+------------+------+------+------------+------------------------------+
|**ITATBDATA0**                |0x00000eec  |5     |wo    |0x00000000  |ATB Data 0 Register           |
+------------------------------+------------+------+------+------------+------------------------------+
|**ITATBCTR2**                 |0x00000ef0  |2     |ro    |0x00000000  |ATB Control 2 Register        |
+------------------------------+------------+------+------+------------+------------------------------+
|**ITATBID**                   |0x00000ef4  |7     |wo    |0x00000000  |ATB Identification Register   |
+------------------------------+------------+------+------+------------+------------------------------+
|**ITATBCTR0**                 |0x00000ef8  |10    |wo    |0x00000000  |ATB Control 0 Register        |
+------------------------------+------------+------+------+------------+------------------------------+
|**ITCTRL**                    |0x00000f00  |1     |rw    |0x00000000  | Integration Mode Control Reg |
+------------------------------+------------+------+------+------------+------------------------------+
|**CTSR**                      |0x00000fa0  |8     |rw    |0xff        |Claim Tag Set Register        |
+------------------------------+------------+------+------+------------+------------------------------+
|**CTCR**                      |0x00000fa4  |8     |rw    |0x00        |Claim Tag Clear Register      |
+------------------------------+------------+------+------+------------+------------------------------+
|**LAR**                       |0x00000fb0  |32    |wo    |0x00000000  |Lock Access Register          |
+------------------------------+------------+------+------+------------+------------------------------+
|**LSR**                       |0x00000fb4  |3     |ro    |0x00000003  |Lock Status Register          |
+------------------------------+------------+------+------+------------+------------------------------+
|**ASR**                       |0x00000fb8  |8     |ro    |0x00        | Authentication Status Regist |
+------------------------------+------------+------+------+------------+------------------------------+
|**DEVID**                     |0x00000fc8  |32    |ro    |0x00000000  |Device ID                     |
+------------------------------+------------+------+------+------------+------------------------------+
|**DTIR**                      |0x00000fcc  |32    |ro    |0x00000013  | Device Type Identifier (ETMD |
+------------------------------+------------+------+------+------------+------------------------------+
|**PERIPHID4**                 |0x00000fd0  |8     |ro    |0x04        |Peripheral ID4                |
+------------------------------+------------+------+------+------------+------------------------------+
|**PERIPHID5**                 |0x00000fd4  |8     |ro    |0x00        |Peripheral ID5                |
+------------------------------+------------+------+------+------------+------------------------------+
|**PERIPHID6**                 |0x00000fd8  |8     |ro    |0x00        |Peripheral ID6                |
+------------------------------+------------+------+------+------------+------------------------------+
|**PERIPHID7**                 |0x00000fdc  |8     |ro    |0x00        |Peripheral ID7                |
+------------------------------+------------+------+------+------------+------------------------------+
|**PERIPHID0**                 |0x00000fe0  |8     |ro    |0x50        |Peripheral ID0                |
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

### CR  

Relative Address = 0x00000000  
Width = 30 bits  
Access Type = rw  
Reset Value = 0x00000401  
Description Main Control Register  


### CCR  

Relative Address = 0x00000004  
Width = 32 bits  
Access Type = ro  
Reset Value = 0x00000000  
Description Configuration Code Register  


### TRIGGER  

Relative Address = 0x00000008  
Width = 17 bits  
Access Type = rw  
Reset Value = 0x00000000  
Description Trigger Event Register  


### SR  

Relative Address = 0x00000010  
Width = 4 bits  
Access Type = mixed  
Reset Value = 0x00000002  
Description Status Register  


### SCR  

Relative Address = 0x00000014  
Width = 15 bits  
Access Type = ro  
Reset Value = 0x00000000  
Description System Configuration Register  


### TSSCR  

Relative Address = 0x00000018  
Width = 24 bits  
Access Type = rw  
Reset Value = 0x00000000  
Description TraceEnable Start/Stop Control Register  


### TEEVR  

Relative Address = 0x00000020  
Width = 32 bits  
Access Type = rw  
Reset Value = 0x00000000  
Description TraceEnable Event  


### TECR1  

Relative Address = 0x00000024  
Width = 26 bits  
Access Type = rw  
Reset Value = 0x00000000  
Description TraceEnable Control Register 1  


### ACVR1  

Relative Address = 0x00000040  
Width = 32 bits  
Access Type = rw  
Reset Value = 0x00000000  
Description Address Comparator Value Register 1  


### ACVR2  

Relative Address = 0x00000044  
Width = 32 bits  
Access Type = rw  
Reset Value = 0x00000000  
Description Address Comparator Value Register 2  


### ACVR3  

Relative Address = 0x00000048  
Width = 32 bits  
Access Type = rw  
Reset Value = 0x00000000  
Description Address Comparator Value Register 3  


### ACVR4  

Relative Address = 0x0000004c  
Width = 32 bits  
Access Type = rw  
Reset Value = 0x00000000  
Description Address Comparator Value Register 4  


### ACVR5  

Relative Address = 0x00000050  
Width = 32 bits  
Access Type = rw  
Reset Value = 0x00000000  
Description Address Comparator Value Register 5  


### ACVR6  

Relative Address = 0x00000054  
Width = 32 bits  
Access Type = rw  
Reset Value = 0x00000000  
Description Address Comparator Value Register 6  


### ACVR7  

Relative Address = 0x00000058  
Width = 32 bits  
Access Type = rw  
Reset Value = 0x00000000  
Description Address Comparator Value Register 7  


### ACVR8  

Relative Address = 0x0000005c  
Width = 32 bits  
Access Type = rw  
Reset Value = 0x00000000  
Description Address Comparator Value Register 8  


### ACTR1  

Relative Address = 0x00000080  
Width = 12 bits  
Access Type = mixed  
Reset Value = 0x00000001  
Description Address Comparator Access Type Register 1  


### ACTR2  

Relative Address = 0x00000084  
Width = 12 bits  
Access Type = mixed  
Reset Value = 0x00000001  
Description Address Comparator Access Type Register 2  


### ACTR3  

Relative Address = 0x00000088  
Width = 12 bits  
Access Type = mixed  
Reset Value = 0x00000001  
Description Address Comparator Access Type Register 3  


### ACTR4  

Relative Address = 0x0000008c  
Width = 12 bits  
Access Type = mixed  
Reset Value = 0x00000001  
Description Address Comparator Access Type Register 4  


### ACTR5  

Relative Address = 0x00000090  
Width = 12 bits  
Access Type = mixed  
Reset Value = 0x00000001  
Description Address Comparator Access Type Register 5  


### ACTR6  

Relative Address = 0x00000094  
Width = 12 bits  
Access Type = mixed  
Reset Value = 0x00000001  
Description Address Comparator Access Type Register 6  


### ACTR7  

Relative Address = 0x00000098  
Width = 12 bits  
Access Type = mixed  
Reset Value = 0x00000001  
Description Address Comparator Access Type Register 7  


### ACTR8  

Relative Address = 0x0000009c  
Width = 12 bits  
Access Type = mixed  
Reset Value = 0x00000001  
Description Address Comparator Access Type Register 8  


### CNTRLDVR1  

Relative Address = 0x00000140  
Width = 16 bits  
Access Type = rw  
Reset Value = 0x0000  
Description Counter Reload Value Register 1  


### CNTRLDVR2  

Relative Address = 0x00000144  
Width = 16 bits  
Access Type = rw  
Reset Value = 0x0000  
Description Counter Reload Value Register 2  


### CNTENR1  

Relative Address = 0x00000150  
Width = 18 bits  
Access Type = mixed  
Reset Value = 0x00020000  
Description Counter Enable Event Register 1  


### CNTENR2  

Relative Address = 0x00000154  
Width = 18 bits  
Access Type = mixed  
Reset Value = 0x00020000  
Description Counter Enable Event Register 2  


### CNTRLDEVR1  

Relative Address = 0x00000160  
Width = 17 bits  
Access Type = rw  
Reset Value = 0x00000000  
Description Counter Reload Event Register 1  


### CNTRLDEVR2  

Relative Address = 0x00000164  
Width = 17 bits  
Access Type = rw  
Reset Value = 0x00000000  
Description Counter Reload Event Register 2  


### CNTVR1  

Relative Address = 0x00000170  
Width = 16 bits  
Access Type = rw  
Reset Value = 0x0000  
Description Counter Value Register 1  


### CNTVR2  

Relative Address = 0x00000174  
Width = 16 bits  
Access Type = rw  
Reset Value = 0x0000  
Description Counter Value Register 2  


### SQ12EVR  

Relative Address = 0x00000180  
Width = 17 bits  
Access Type = rw  
Reset Value = 0x00000000  
Description Sequencer State Transition Event Register 12  


### SQ21EVR  

Relative Address = 0x00000184  
Width = 17 bits  
Access Type = rw  
Reset Value = 0x00000000  
Description Sequencer State Transition Event Register 21  


### SQ23EVR  

Relative Address = 0x00000188  
Width = 17 bits  
Access Type = rw  
Reset Value = 0x00000000  
Description Sequencer State Transition Event Register 23  


### SQ31EVR  

Relative Address = 0x0000018c  
Width = 17 bits  
Access Type = rw  
Reset Value = 0x00000000  
Description Sequencer State Transition Event Register 31  


### SQ32EVR  

Relative Address = 0x00000190  
Width = 17 bits  
Access Type = rw  
Reset Value = 0x00000000  
Description Sequencer State Transition Event Register 32  


### SQ13EVR  

Relative Address = 0x00000194  
Width = 17 bits  
Access Type = rw  
Reset Value = 0x00000000  
Description Sequencer State Transition Event Register 13  


### SQR  

Relative Address = 0x0000019c  
Width = 2 bits  
Access Type = rw  
Reset Value = 0x00000000  
Description Current Sequencer State Register  


### EXTOUTEVR1  

Relative Address = 0x000001a0  
Width = 17 bits  
Access Type = rw  
Reset Value = 0x00000000  
Description External Output Event Register 1  


### EXTOUTEVR2  

Relative Address = 0x000001a4  
Width = 17 bits  
Access Type = rw  
Reset Value = 0x00000000  
Description External Output Event Register 2  


### CIDCVR1  

Relative Address = 0x000001b0  
Width = 32 bits  
Access Type = rw  
Reset Value = 0x00000000  
Description Context ID Comparator Value Register  


### CIDCMR  

Relative Address = 0x000001bc  
Width = 32 bits  
Access Type = rw  
Reset Value = 0x00000000  
Description Context ID Comparator Mask Register  


### SYNCFR  

Relative Address = 0x000001e0  
Width = 12 bits  
Access Type = mixed  
Reset Value = 0x00000400  
Description Synchronization Frequency Register  


### IDR  

Relative Address = 0x000001e4  
Width = 32 bits  
Access Type = ro  
Reset Value = 0x411cf301  
Description ID Register  


### CCER  

Relative Address = 0x000001e8  
Width = 26 bits  
Access Type = ro  
Reset Value = 0x000008ea  
Description Configuration Code Extension Register  


### EXTINSELR  

Relative Address = 0x000001ec  
Width = 14 bits  
Access Type = rw  
Reset Value = 0x00000000  
Description Extended External Input Selection Register  


### TSEVR  

Relative Address = 0x000001f8  
Width = 32 bits  
Access Type = rw  
Reset Value = 0x00000000  
Description Timestamp Event  


### AUXCR  

Relative Address = 0x000001fc  
Width = 4 bits  
Access Type = rw  
Reset Value = 0x00000000  
Description Auxiliary Control Register  


### TRACEIDR  

Relative Address = 0x00000200  
Width = 7 bits  
Access Type = rw  
Reset Value = 0x00000000  
Description CoreSight Trace ID Register  


### OSLSR  

Relative Address = 0x00000304  
Width = 32 bits  
Access Type = ro  
Reset Value = 0x00000000  
Description OS Lock Status Register  


### PDSR  

Relative Address = 0x00000314  
Width = 32 bits  
Access Type = ro  
Reset Value = 0x00000001  
Description Device Powerdown Status Register  


### ITMISCOUT  

Relative Address = 0x00000edc  
Width = 10 bits  
Access Type = wo  
Reset Value = 0x00000000  
Description Miscellaneous Outputs Register  


### ITMISCIN  

Relative Address = 0x00000ee0  
Width = 7 bits  
Access Type = ro  
Reset Value = 0x00000000  
Description Miscellaneous Inputs Register  


### ITTRIGGER  

Relative Address = 0x00000ee8  
Width = 1 bits  
Access Type = wo  
Reset Value = 0x00000000  
Description Trigger Register  


### ITATBDATA0  

Relative Address = 0x00000eec  
Width = 5 bits  
Access Type = wo  
Reset Value = 0x00000000  
Description ATB Data 0 Register  


### ITATBCTR2  

Relative Address = 0x00000ef0  
Width = 2 bits  
Access Type = ro  
Reset Value = 0x00000000  
Description ATB Control 2 Register  


### ITATBID  

Relative Address = 0x00000ef4  
Width = 7 bits  
Access Type = wo  
Reset Value = 0x00000000  
Description ATB Identification Register  


### ITATBCTR0  

Relative Address = 0x00000ef8  
Width = 10 bits  
Access Type = wo  
Reset Value = 0x00000000  
Description ATB Control 0 Register  


### ITCTRL  

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
Reset Value = 0x00  
Description Authentication Status Register  


### DEVID  

Relative Address = 0x00000fc8  
Width = 32 bits  
Access Type = ro  
Reset Value = 0x00000000  
Description Device ID  


### DTIR  

Relative Address = 0x00000fcc  
Width = 32 bits  
Access Type = ro  
Reset Value = 0x00000013  
Description Device Type Identifier (ETMDEVTYPE)  


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
Reset Value = 0x50  
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
Reset Value = 0x1b  
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

