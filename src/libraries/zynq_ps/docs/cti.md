# CoreSight Cross Trigger Interface  

Module CoreSight Cross Trigger Interface (cti)  
SPDX-License-Identifier: MIT  
Auto-generated: Mon Sep 21 21:57:55 EEST 2020  

debug_cpu_cti0 Base Address = 0xf8898000  
debug_cpu_cti1 Base Address = 0xf8899000  
debug_cpu_etb_tpiu Base Address = 0xf8802000  
debug_cpu_ftm Base Address = 0xf8809000  

## Register Summary  

+------------------------------+------------+------+------+------------+------------------------------+
|Register Name                 |Address     |Width |Type  |Reset Value |Description                   |
+==============================+============+======+======+============+==============================+
|**CTICONTROL**                |0x00000000  |1     |rw    |0x00000000  |CTI Control Register          |
+------------------------------+------------+------+------+------------+------------------------------+
|**CTIINTACK**                 |0x00000010  |8     |wo    |0x00        | CTI Interrupt Acknowledge Re |
+------------------------------+------------+------+------+------------+------------------------------+
|**CTIAPPSET**                 |0x00000014  |4     |rw    |0x00000000  | CTI Application Trigger Set  |
+------------------------------+------------+------+------+------------+------------------------------+
|**CTIAPPCLEAR**               |0x00000018  |4     |wo    |0x00000000  | CTI Application Trigger Clea |
+------------------------------+------------+------+------+------------+------------------------------+
|**CTIAPPPULSE**               |0x0000001c  |4     |wo    |0x00000000  | CTI Application Pulse Regist |
+------------------------------+------------+------+------+------------+------------------------------+
|**CTIINEN0**                  |0x00000020  |4     |rw    |0x00000000  | CTI Trigger to Channel Enabl |
+------------------------------+------------+------+------+------------+------------------------------+
|**CTIINEN1**                  |0x00000024  |4     |rw    |0x00000000  | CTI Trigger to Channel Enabl |
+------------------------------+------------+------+------+------------+------------------------------+
|**CTIINEN2**                  |0x00000028  |4     |rw    |0x00000000  | CTI Trigger to Channel Enabl |
+------------------------------+------------+------+------+------------+------------------------------+
|**CTIINEN3**                  |0x0000002c  |4     |rw    |0x00000000  | CTI Trigger to Channel Enabl |
+------------------------------+------------+------+------+------------+------------------------------+
|**CTIINEN4**                  |0x00000030  |4     |rw    |0x00000000  | CTI Trigger to Channel Enabl |
+------------------------------+------------+------+------+------------+------------------------------+
|**CTIINEN5**                  |0x00000034  |4     |rw    |0x00000000  | CTI Trigger to Channel Enabl |
+------------------------------+------------+------+------+------------+------------------------------+
|**CTIINEN6**                  |0x00000038  |4     |rw    |0x00000000  | CTI Trigger to Channel Enabl |
+------------------------------+------------+------+------+------------+------------------------------+
|**CTIINEN7**                  |0x0000003c  |4     |rw    |0x00000000  | CTI Trigger to Channel Enabl |
+------------------------------+------------+------+------+------------+------------------------------+
|**CTIOUTEN0**                 |0x000000a0  |4     |rw    |0x00000000  | CTI Channel to Trigger Enabl |
+------------------------------+------------+------+------+------------+------------------------------+
|**CTIOUTEN1**                 |0x000000a4  |4     |rw    |0x00000000  | CTI Channel to Trigger Enabl |
+------------------------------+------------+------+------+------------+------------------------------+
|**CTIOUTEN2**                 |0x000000a8  |4     |rw    |0x00000000  | CTI Channel to Trigger Enabl |
+------------------------------+------------+------+------+------------+------------------------------+
|**CTIOUTEN3**                 |0x000000ac  |4     |rw    |0x00000000  | CTI Channel to Trigger Enabl |
+------------------------------+------------+------+------+------------+------------------------------+
|**CTIOUTEN4**                 |0x000000b0  |4     |rw    |0x00000000  | CTI Channel to Trigger Enabl |
+------------------------------+------------+------+------+------------+------------------------------+
|**CTIOUTEN5**                 |0x000000b4  |4     |rw    |0x00000000  | CTI Channel to Trigger Enabl |
+------------------------------+------------+------+------+------------+------------------------------+
|**CTIOUTEN6**                 |0x000000b8  |4     |rw    |0x00000000  | CTI Channel to Trigger Enabl |
+------------------------------+------------+------+------+------------+------------------------------+
|**CTIOUTEN7**                 |0x000000bc  |4     |rw    |0x00000000  | CTI Channel to Trigger Enabl |
+------------------------------+------------+------+------+------------+------------------------------+
|**CTITRIGINSTATUS**           |0x00000130  |8     |ro    |0x00        | CTI Trigger In Status Regist |
+------------------------------+------------+------+------+------------+------------------------------+
|**CTITRIGOUTSTATUS**          |0x00000134  |8     |ro    |0x00        | CTI Trigger Out Status Regis |
+------------------------------+------------+------+------+------------+------------------------------+
|**CTICHINSTATUS**             |0x00000138  |4     |ro    |0x00000000  | CTI Channel In Status Regist |
+------------------------------+------------+------+------+------------+------------------------------+
|**CTICHOUTSTATUS**            |0x0000013c  |4     |ro    |0x00000000  | CTI Channel Out Status Regis |
+------------------------------+------------+------+------+------------+------------------------------+
|**CTIGATE**                   |0x00000140  |4     |rw    |0x0000000f  | Enable CTI Channel Gate Regi |
+------------------------------+------------+------+------+------------+------------------------------+
|**ASICCTL**                   |0x00000144  |8     |rw    |0x00        | External Multiplexor Control |
+------------------------------+------------+------+------+------------+------------------------------+
|**ITCHINACK**                 |0x00000edc  |4     |wo    |0x00000000  |ITCHINACK Register            |
+------------------------------+------------+------+------+------------+------------------------------+
|**ITTRIGINACK**               |0x00000ee0  |8     |wo    |0x00        |ITTRIGINACK Register          |
+------------------------------+------------+------+------+------------+------------------------------+
|**ITCHOUT**                   |0x00000ee4  |4     |wo    |0x00000000  |ITCHOUT Register              |
+------------------------------+------------+------+------+------------+------------------------------+
|**ITTRIGOUT**                 |0x00000ee8  |8     |wo    |0x00        |ITTRIGOUT Register            |
+------------------------------+------------+------+------+------------+------------------------------+
|**ITCHOUTACK**                |0x00000eec  |4     |ro    |0x00000000  |ITCHOUTACK Register           |
+------------------------------+------------+------+------+------------+------------------------------+
|**ITTRIGOUTACK**              |0x00000ef0  |8     |ro    |0x00        |ITTRIGOUTACK Register         |
+------------------------------+------------+------+------+------------+------------------------------+
|**ITCHIN**                    |0x00000ef4  |4     |ro    |0x00000000  |ITCHIN Register               |
+------------------------------+------------+------+------+------------+------------------------------+
|**ITTRIGIN**                  |0x00000ef8  |8     |ro    |0x00        |ITTRIGIN Register             |
+------------------------------+------------+------+------+------------+------------------------------+
|**ITCTRL**                    |0x00000f00  |1     |rw    |0x00000000  |IT Control Register           |
+------------------------------+------------+------+------+------------+------------------------------+
|**CTSR**                      |0x00000fa0  |4     |rw    |0x0000000f  |Claim Tag Set Register        |
+------------------------------+------------+------+------+------------+------------------------------+
|**CTCR**                      |0x00000fa4  |4     |rw    |0x00000000  |Claim Tag Clear Register      |
+------------------------------+------------+------+------+------------+------------------------------+
|**LAR**                       |0x00000fb0  |32    |wo    |0x00000000  |Lock Access Register          |
+------------------------------+------------+------+------+------------+------------------------------+
|**LSR**                       |0x00000fb4  |3     |ro    |0x00000003  |Lock Status Register          |
+------------------------------+------------+------+------+------------+------------------------------+
|**ASR**                       |0x00000fb8  |4     |ro    |0x00000000  | Authentication Status Regist |
+------------------------------+------------+------+------+------------+------------------------------+
|**DEVID**                     |0x00000fc8  |20    |ro    |0x00040800  |Device ID                     |
+------------------------------+------------+------+------+------------+------------------------------+
|**DTIR**                      |0x00000fcc  |8     |ro    |0x14        | Device Type Identifier Regis |
+------------------------------+------------+------+------+------------+------------------------------+
|**PERIPHID4**                 |0x00000fd0  |8     |ro    |0x04        |Peripheral ID4                |
+------------------------------+------------+------+------+------------+------------------------------+
|**PERIPHID5**                 |0x00000fd4  |8     |ro    |0x00        |Peripheral ID5                |
+------------------------------+------------+------+------+------------+------------------------------+
|**PERIPHID6**                 |0x00000fd8  |8     |ro    |0x00        |Peripheral ID6                |
+------------------------------+------------+------+------+------------+------------------------------+
|**PERIPHID7**                 |0x00000fdc  |8     |ro    |0x00        |Peripheral ID7                |
+------------------------------+------------+------+------+------------+------------------------------+
|**PERIPHID0**                 |0x00000fe0  |8     |ro    |0x06        |Peripheral ID0                |
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

### CTICONTROL  

Relative Address = 0x00000000  
Width = 1 bits  
Access Type = rw  
Reset Value = 0x00000000  
Description CTI Control Register  


### CTIINTACK  

Relative Address = 0x00000010  
Width = 8 bits  
Access Type = wo  
Reset Value = 0x00  
Description CTI Interrupt Acknowledge Register  


### CTIAPPSET  

Relative Address = 0x00000014  
Width = 4 bits  
Access Type = rw  
Reset Value = 0x00000000  
Description CTI Application Trigger Set Register  


### CTIAPPCLEAR  

Relative Address = 0x00000018  
Width = 4 bits  
Access Type = wo  
Reset Value = 0x00000000  
Description CTI Application Trigger Clear Register  


### CTIAPPPULSE  

Relative Address = 0x0000001c  
Width = 4 bits  
Access Type = wo  
Reset Value = 0x00000000  
Description CTI Application Pulse Register  


### CTIINEN0  

Relative Address = 0x00000020  
Width = 4 bits  
Access Type = rw  
Reset Value = 0x00000000  
Description CTI Trigger to Channel Enable 0 Register  


### CTIINEN1  

Relative Address = 0x00000024  
Width = 4 bits  
Access Type = rw  
Reset Value = 0x00000000  
Description CTI Trigger to Channel Enable 1 Register  


### CTIINEN2  

Relative Address = 0x00000028  
Width = 4 bits  
Access Type = rw  
Reset Value = 0x00000000  
Description CTI Trigger to Channel Enable 2 Register  


### CTIINEN3  

Relative Address = 0x0000002c  
Width = 4 bits  
Access Type = rw  
Reset Value = 0x00000000  
Description CTI Trigger to Channel Enable 3 Register  


### CTIINEN4  

Relative Address = 0x00000030  
Width = 4 bits  
Access Type = rw  
Reset Value = 0x00000000  
Description CTI Trigger to Channel Enable 4 Register  


### CTIINEN5  

Relative Address = 0x00000034  
Width = 4 bits  
Access Type = rw  
Reset Value = 0x00000000  
Description CTI Trigger to Channel Enable 5 Register  


### CTIINEN6  

Relative Address = 0x00000038  
Width = 4 bits  
Access Type = rw  
Reset Value = 0x00000000  
Description CTI Trigger to Channel Enable 6 Register  


### CTIINEN7  

Relative Address = 0x0000003c  
Width = 4 bits  
Access Type = rw  
Reset Value = 0x00000000  
Description CTI Trigger to Channel Enable 7 Register  


### CTIOUTEN0  

Relative Address = 0x000000a0  
Width = 4 bits  
Access Type = rw  
Reset Value = 0x00000000  
Description CTI Channel to Trigger Enable 0 Register  


### CTIOUTEN1  

Relative Address = 0x000000a4  
Width = 4 bits  
Access Type = rw  
Reset Value = 0x00000000  
Description CTI Channel to Trigger Enable 1 Register  


### CTIOUTEN2  

Relative Address = 0x000000a8  
Width = 4 bits  
Access Type = rw  
Reset Value = 0x00000000  
Description CTI Channel to Trigger Enable 2 Register  


### CTIOUTEN3  

Relative Address = 0x000000ac  
Width = 4 bits  
Access Type = rw  
Reset Value = 0x00000000  
Description CTI Channel to Trigger Enable 3 Register  


### CTIOUTEN4  

Relative Address = 0x000000b0  
Width = 4 bits  
Access Type = rw  
Reset Value = 0x00000000  
Description CTI Channel to Trigger Enable 4 Register  


### CTIOUTEN5  

Relative Address = 0x000000b4  
Width = 4 bits  
Access Type = rw  
Reset Value = 0x00000000  
Description CTI Channel to Trigger Enable 5 Register  


### CTIOUTEN6  

Relative Address = 0x000000b8  
Width = 4 bits  
Access Type = rw  
Reset Value = 0x00000000  
Description CTI Channel to Trigger Enable 6 Register  


### CTIOUTEN7  

Relative Address = 0x000000bc  
Width = 4 bits  
Access Type = rw  
Reset Value = 0x00000000  
Description CTI Channel to Trigger Enable 7 Register  


### CTITRIGINSTATUS  

Relative Address = 0x00000130  
Width = 8 bits  
Access Type = ro  
Reset Value = 0x00  
Description CTI Trigger In Status Register  


### CTITRIGOUTSTATUS  

Relative Address = 0x00000134  
Width = 8 bits  
Access Type = ro  
Reset Value = 0x00  
Description CTI Trigger Out Status Register  


### CTICHINSTATUS  

Relative Address = 0x00000138  
Width = 4 bits  
Access Type = ro  
Reset Value = 0x00000000  
Description CTI Channel In Status Register  


### CTICHOUTSTATUS  

Relative Address = 0x0000013c  
Width = 4 bits  
Access Type = ro  
Reset Value = 0x00000000  
Description CTI Channel Out Status Register  


### CTIGATE  

Relative Address = 0x00000140  
Width = 4 bits  
Access Type = rw  
Reset Value = 0x0000000f  
Description Enable CTI Channel Gate Register  


### ASICCTL  

Relative Address = 0x00000144  
Width = 8 bits  
Access Type = rw  
Reset Value = 0x00  
Description External Multiplexor Control Register  


### ITCHINACK  

Relative Address = 0x00000edc  
Width = 4 bits  
Access Type = wo  
Reset Value = 0x00000000  
Description ITCHINACK Register  


### ITTRIGINACK  

Relative Address = 0x00000ee0  
Width = 8 bits  
Access Type = wo  
Reset Value = 0x00  
Description ITTRIGINACK Register  


### ITCHOUT  

Relative Address = 0x00000ee4  
Width = 4 bits  
Access Type = wo  
Reset Value = 0x00000000  
Description ITCHOUT Register  


### ITTRIGOUT  

Relative Address = 0x00000ee8  
Width = 8 bits  
Access Type = wo  
Reset Value = 0x00  
Description ITTRIGOUT Register  


### ITCHOUTACK  

Relative Address = 0x00000eec  
Width = 4 bits  
Access Type = ro  
Reset Value = 0x00000000  
Description ITCHOUTACK Register  


### ITTRIGOUTACK  

Relative Address = 0x00000ef0  
Width = 8 bits  
Access Type = ro  
Reset Value = 0x00  
Description ITTRIGOUTACK Register  


### ITCHIN  

Relative Address = 0x00000ef4  
Width = 4 bits  
Access Type = ro  
Reset Value = 0x00000000  
Description ITCHIN Register  


### ITTRIGIN  

Relative Address = 0x00000ef8  
Width = 8 bits  
Access Type = ro  
Reset Value = 0x00  
Description ITTRIGIN Register  


### ITCTRL  

Relative Address = 0x00000f00  
Width = 1 bits  
Access Type = rw  
Reset Value = 0x00000000  
Description IT Control Register  


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
Width = 4 bits  
Access Type = ro  
Reset Value = 0x00000000  
Description Authentication Status Register  


### DEVID  

Relative Address = 0x00000fc8  
Width = 20 bits  
Access Type = ro  
Reset Value = 0x00040800  
Description Device ID  


### DTIR  

Relative Address = 0x00000fcc  
Width = 8 bits  
Access Type = ro  
Reset Value = 0x14  
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
Reset Value = 0x06  
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

