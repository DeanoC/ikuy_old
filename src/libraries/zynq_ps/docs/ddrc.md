# DDR Memory Controller  

Module DDR Memory Controller (ddrc)  
SPDX-License-Identifier: MIT  
Auto-generated: Fri Sep 25 10:29:42 EEST 2020  

ddrc Base Address = 0xf8006000  

## Register Summary  

+------------------------------+------------+------+------+------------+------------------------------+
|Register Name                 |Address     |Width |Type  |Reset Value |Description                   |
+==============================+============+======+======+============+==============================+
|**CTRL**                      |0x00000000  |32    |rw    |0x00000200  |DDRC Control                  |
+------------------------------+------------+------+------+------------+------------------------------+
|**TWO_RANK_CFG**              |0x00000004  |29    |rw    |0x000c1076  |Two Rank Configuration        |
+------------------------------+------------+------+------+------------+------------------------------+
|**HPR**                       |0x00000008  |26    |rw    |0x03c0780f  |HPR Queue control             |
+------------------------------+------------+------+------+------------+------------------------------+
|**LPR**                       |0x0000000c  |26    |rw    |0x03c0780f  |LPR Queue control             |
+------------------------------+------------+------+------+------------+------------------------------+
|**WR**                        |0x00000010  |26    |rw    |0x0007f80f  |WR Queue control              |
+------------------------------+------------+------+------+------------+------------------------------+
|**DRAM_PARAM0**               |0x00000014  |21    |rw    |0x00041016  |DRAM Parameters 0             |
+------------------------------+------------+------+------+------------+------------------------------+
|**DRAM_PARAM1**               |0x00000018  |32    |rw    |0x351b48d9  |DRAM Parameters 1             |
+------------------------------+------------+------+------+------------+------------------------------+
|**DRAM_PARAM2**               |0x0000001c  |32    |rw    |0x00000000  |DRAM Parameters 2             |
+------------------------------+------------+------+------+------------+------------------------------+
|**DRAM_PARAM3**               |0x00000020  |32    |mixed |0x250882d0  |DRAM Parameters 3             |
+------------------------------+------------+------+------+------------+------------------------------+
|**DRAM_PARAM4**               |0x00000024  |28    |mixed |0x0000003c  |DRAM Parameters 4             |
+------------------------------+------------+------+------+------------+------------------------------+
|**DRAM_INIT_PARAM**           |0x00000028  |14    |rw    |0x00002007  | DRAM Initialization Paramete |
+------------------------------+------------+------+------+------------+------------------------------+
|**DRAM_EMR**                  |0x0000002c  |32    |rw    |0x00000008  |DRAM EMR2, EMR3 access        |
+------------------------------+------------+------+------+------------+------------------------------+
|**DRAM_EMR_MR**               |0x00000030  |32    |rw    |0x00000940  |DRAM EMR, MR access           |
+------------------------------+------------+------+------+------------+------------------------------+
|**DRAM_BURST8_RDWR**          |0x00000034  |29    |mixed |0x00020034  |DRAM Burst 8 read/write       |
+------------------------------+------------+------+------+------------+------------------------------+
|**DRAM_DISABLE_DQ**           |0x00000038  |13    |mixed |0x00000000  |DRAM Disable DQ               |
+------------------------------+------------+------+------+------------+------------------------------+
|**DRAM_ADDR_MAP_BANK**        |0x0000003c  |20    |rw    |0x00000f77  |Row/Column address bits       |
+------------------------------+------------+------+------+------------+------------------------------+
|**DRAM_ADDR_MAP_COL**         |0x00000040  |32    |rw    |0x00000000  |Column address bits           |
+------------------------------+------------+------+------+------------+------------------------------+
|**DRAM_ADDR_MAP_ROW**         |0x00000044  |28    |rw    |0x0ff55555  |Select DRAM row address bits  |
+------------------------------+------------+------+------+------------+------------------------------+
|**DRAM_ODT**                  |0x00000048  |30    |rw    |0x00000249  |DRAM ODT control              |
+------------------------------+------------+------+------+------------+------------------------------+
|**PHY_DBG**                   |0x0000004c  |20    |ro    |0x00000000  |PHY debug                     |
+------------------------------+------------+------+------+------------+------------------------------+
| **PHY_CMD_TIMEOUT_RDDATA_CPT |0x00000050  |32    |mixed |0x00010200  |PHY command time out and      |
+------------------------------+------------+------+------+------------+------------------------------+
| **READ_DATA_CAPTURE_FIFOMODE |0x00000054  |21    |ro    |0x00000000  | Controller operation mode st |
+------------------------------+------------+------+------+------------+------------------------------+
|**DLL_CALIB**                 |0x00000058  |17    |rw    |0x00000101  |DLL calibration               |
+------------------------------+------------+------+------+------------+------------------------------+
|**ODT_DELAY_HOLD**            |0x0000005c  |16    |rw    |0x0023      |ODT delay and ODT hold        |
+------------------------------+------------+------+------+------------+------------------------------+
|**CTRL1**                     |0x00000060  |13    |mixed |0x0000003e  |Controller 1                  |
+------------------------------+------------+------+------+------------+------------------------------+
|**CTRL2**                     |0x00000064  |18    |mixed |0x00020000  |Controller 2                  |
+------------------------------+------------+------+------+------------+------------------------------+
|**CTRL3**                     |0x00000068  |26    |rw    |0x00284027  |Controller 3                  |
+------------------------------+------------+------+------+------------+------------------------------+
|**CTRL4**                     |0x0000006c  |16    |rw    |0x1610      |Controller 4                  |
+------------------------------+------------+------+------+------------+------------------------------+
|**CTRL5**                     |0x00000078  |32    |mixed |0x00455111  |Controller register 5         |
+------------------------------+------------+------+------+------------+------------------------------+
|**CTRL6**                     |0x0000007c  |32    |mixed |0x00032222  |Controller register 6         |
+------------------------------+------------+------+------+------------+------------------------------+
|**CHE_REFRESH_TIMER01**       |0x000000a0  |24    |rw    |0x00008000  |CHE_REFRESH_TIMER01           |
+------------------------------+------------+------+------+------------+------------------------------+
|**CHE_T_ZQ**                  |0x000000a4  |32    |rw    |0x10300802  |ZQ parameters                 |
+------------------------------+------------+------+------+------------+------------------------------+
| **CHE_T_ZQ_Short_Interval_Re |0x000000a8  |28    |rw    |0x0020003a  |Misc parameters               |
+------------------------------+------------+------+------+------------+------------------------------+
|**DEEP_PWRDWN**               |0x000000ac  |9     |rw    |0x00000000  |Deep powerdown (LPDDR2)       |
+------------------------------+------------+------+------+------------+------------------------------+
|**REG_2C**                    |0x000000b0  |29    |mixed |0x00000000  |Training control              |
+------------------------------+------------+------+------+------------+------------------------------+
|**REG_2D**                    |0x000000b4  |11    |rw    |0x00000200  |Misc Debug                    |
+------------------------------+------------+------+------+------------+------------------------------+
|**DFI_TIMING**                |0x000000b8  |25    |rw    |0x00200067  |DFI timing                    |
+------------------------------+------------+------+------+------------+------------------------------+
|**CHE_ECC_CONTROL**           |0x000000c4  |2     |rw    |0x00000000  |ECC error clear               |
+------------------------------+------------+------+------+------------+------------------------------+
|**CHE_CORR_ECC_LOG**          |0x000000c8  |8     |mixed |0x00        |ECC error correction          |
+------------------------------+------------+------+------+------------+------------------------------+
|**CHE_CORR_ECC_ADDR**         |0x000000cc  |31    |ro    |0x00000000  | ECC error correction address |
+------------------------------+------------+------+------+------------+------------------------------+
|**CHE_CORR_ECC_DATA_31_0**    |0x000000d0  |32    |ro    |0x00000000  | ECC error correction data lo |
+------------------------------+------------+------+------+------------+------------------------------+
|**CHE_CORR_ECC_DATA_63_32**   |0x000000d4  |32    |ro    |0x00000000  | ECC error correction data lo |
+------------------------------+------------+------+------+------------+------------------------------+
|**CHE_CORR_ECC_DATA_71_64**   |0x000000d8  |8     |ro    |0x00        | ECC error correction data lo |
+------------------------------+------------+------+------+------------+------------------------------+
|**CHE_UNCORR_ECC_LOG**        |0x000000dc  |1     | clro |0x00000000  | ECC unrecoverable error stat |
+------------------------------+------------+------+------+------------+------------------------------+
|**CHE_UNCORR_ECC_ADDR**       |0x000000e0  |31    |ro    |0x00000000  | ECC unrecoverable error addr |
+------------------------------+------------+------+------+------------+------------------------------+
|**CHE_UNCORR_ECC_DATA_31_0**  |0x000000e4  |32    |ro    |0x00000000  | ECC unrecoverable error data |
+------------------------------+------------+------+------+------------+------------------------------+
|**CHE_UNCORR_ECC_DATA_63_32** |0x000000e8  |32    |ro    |0x00000000  | ECC unrecoverable error data |
+------------------------------+------------+------+------+------------+------------------------------+
|**CHE_UNCORR_ECC_DATA_71_64** |0x000000ec  |8     |ro    |0x00        | ECC unrecoverable error data |
+------------------------------+------------+------+------+------------+------------------------------+
|**CHE_ECC_STATS**             |0x000000f0  |16    | clro |0x0000      |ECC error count               |
+------------------------------+------------+------+------+------------+------------------------------+
|**ECC_SCRUB**                 |0x000000f4  |4     |rw    |0x00000008  |ECC mode/scrub                |
+------------------------------+------------+------+------+------------+------------------------------+
| **CHE_ECC_CORR_BIT_MASK_31_0 |0x000000f8  |32    |ro    |0x00000000  |ECC data mask low             |
+------------------------------+------------+------+------+------------+------------------------------+
| **CHE_ECC_CORR_BIT_MASK_63_3 |0x000000fc  |32    |ro    |0x00000000  |ECC data mask high            |
+------------------------------+------------+------+------+------------+------------------------------+
|**PHY_RCVR_ENABLE**           |0x00000114  |8     |rw    |0x00        |Phy receiver enable register  |
+------------------------------+------------+------+------+------------+------------------------------+
|**PHY_CONFIG0**               |0x00000118  |31    |rw    |0x40000001  | PHY configuration register f |
+------------------------------+------------+------+------+------------+------------------------------+
|**PHY_CONFIG1**               |0x0000011c  |31    |rw    |0x40000001  | PHY configuration register f |
+------------------------------+------------+------+------+------------+------------------------------+
|**PHY_CONFIG2**               |0x00000120  |31    |rw    |0x40000001  | PHY configuration register f |
+------------------------------+------------+------+------+------------+------------------------------+
|**PHY_CONFIG3**               |0x00000124  |31    |rw    |0x40000001  | PHY configuration register f |
+------------------------------+------------+------+------+------------+------------------------------+
|**PHY_INIT_RATIO0**           |0x0000012c  |20    |rw    |0x00000000  | PHY init ratio register for  |
+------------------------------+------------+------+------+------------+------------------------------+
|**PHY_INIT_RATIO1**           |0x00000130  |20    |rw    |0x00000000  | PHY init ratio register for  |
+------------------------------+------------+------+------+------------+------------------------------+
|**PHY_INIT_RATIO2**           |0x00000134  |20    |rw    |0x00000000  | PHY init ratio register for  |
+------------------------------+------------+------+------+------------+------------------------------+
|**PHY_INIT_RATIO3**           |0x00000138  |20    |rw    |0x00000000  | PHY init ratio register for  |
+------------------------------+------------+------+------+------------+------------------------------+
|**PHY_RD_DQS_CFG0**           |0x00000140  |20    |rw    |0x00000040  | PHY read DQS configuration r |
+------------------------------+------------+------+------+------------+------------------------------+
|**PHY_RD_DQS_CFG1**           |0x00000144  |20    |rw    |0x00000040  | PHY read DQS configuration r |
+------------------------------+------------+------+------+------------+------------------------------+
|**PHY_RD_DQS_CFG2**           |0x00000148  |20    |rw    |0x00000040  | PHY read DQS configuration r |
+------------------------------+------------+------+------+------------+------------------------------+
|**PHY_RD_DQS_CFG3**           |0x0000014c  |20    |rw    |0x00000040  | PHY read DQS configuration r |
+------------------------------+------------+------+------+------------+------------------------------+
|**PHY_WR_DQS_CFG0**           |0x00000154  |20    |rw    |0x00000000  | PHY write DQS configuration  |
+------------------------------+------------+------+------+------------+------------------------------+
|**PHY_WR_DQS_CFG1**           |0x00000158  |20    |rw    |0x00000000  | PHY write DQS configuration  |
+------------------------------+------------+------+------+------------+------------------------------+
|**PHY_WR_DQS_CFG2**           |0x0000015c  |20    |rw    |0x00000000  | PHY write DQS configuration  |
+------------------------------+------------+------+------+------------+------------------------------+
|**PHY_WR_DQS_CFG3**           |0x00000160  |20    |rw    |0x00000000  | PHY write DQS configuration  |
+------------------------------+------------+------+------+------------+------------------------------+
|**PHY_WE_CFG0**               |0x00000168  |21    |rw    |0x00000040  | PHY FIFO write enable config |
+------------------------------+------------+------+------+------------+------------------------------+
|**PHY_WE_CFG1**               |0x0000016c  |21    |rw    |0x00000040  | PHY FIFO write enable config |
+------------------------------+------------+------+------+------------+------------------------------+
|**PHY_WE_CFG2**               |0x00000170  |21    |rw    |0x00000040  | PHY FIFO write enable config |
+------------------------------+------------+------+------+------------+------------------------------+
|**PHY_WE_CFG3**               |0x00000174  |21    |rw    |0x00000040  | PHY FIFO write enable config |
+------------------------------+------------+------+------+------------+------------------------------+
|**WR_DATA_SLV0**              |0x0000017c  |20    |rw    |0x00000080  | PHY write data slave ratio c |
+------------------------------+------------+------+------+------------+------------------------------+
|**WR_DATA_SLV1**              |0x00000180  |20    |rw    |0x00000080  | PHY write data slave ratio c |
+------------------------------+------------+------+------+------------+------------------------------+
|**WR_DATA_SLV2**              |0x00000184  |20    |rw    |0x00000080  | PHY write data slave ratio c |
+------------------------------+------------+------+------+------------+------------------------------+
|**WR_DATA_SLV3**              |0x00000188  |20    |rw    |0x00000080  | PHY write data slave ratio c |
+------------------------------+------------+------+------+------------+------------------------------+
|**REG_64**                    |0x00000190  |32    |rw    |0x10020000  |Training control 2            |
+------------------------------+------------+------+------+------------+------------------------------+
|**REG_65**                    |0x00000194  |20    |rw    |0x00000000  |Training control 3            |
+------------------------------+------------+------+------+------------+------------------------------+
|**REG69_6A0**                 |0x000001a4  |29    |ro    |0x00070000  | Training results for data sl |
+------------------------------+------------+------+------+------------+------------------------------+
|**REG69_6A1**                 |0x000001a8  |29    |ro    |0x00060200  | Training results for data sl |
+------------------------------+------------+------+------+------------+------------------------------+
|**REG6C_6D2**                 |0x000001b0  |28    |ro    |0x00040600  | Training results for data sl |
+------------------------------+------------+------+------+------------+------------------------------+
|**REG6C_6D3**                 |0x000001b4  |28    |ro    |0x00000e00  | Training results for data sl |
+------------------------------+------------+------+------+------------+------------------------------+
|**REG6E_710**                 |0x000001b8  |30    |ro    |0x00000000  | Training results (2) for dat |
+------------------------------+------------+------+------+------------+------------------------------+
|**REG6E_711**                 |0x000001bc  |30    |ro    |0x00000000  | Training results (2) for dat |
+------------------------------+------------+------+------+------------+------------------------------+
|**REG6E_712**                 |0x000001c0  |30    |ro    |0x00000000  | Training results (2) for dat |
+------------------------------+------------+------+------+------------+------------------------------+
|**REG6E_713**                 |0x000001c4  |30    |ro    |0x00000000  | Training results (2) for dat |
+------------------------------+------------+------+------+------------+------------------------------+
|**PHY_DLL_STS0**              |0x000001cc  |27    |ro    |0x00000000  | Slave DLL results for data s |
+------------------------------+------------+------+------+------------+------------------------------+
|**PHY_DLL_STS1**              |0x000001d0  |27    |ro    |0x00000000  | Slave DLL results for data s |
+------------------------------+------------+------+------+------------+------------------------------+
|**PHY_DLL_STS2**              |0x000001d4  |27    |ro    |0x00000000  | Slave DLL results for data s |
+------------------------------+------------+------+------+------------+------------------------------+
|**PHY_DLL_STS3**              |0x000001d8  |27    |ro    |0x00000000  | Slave DLL results for data s |
+------------------------------+------------+------+------+------------+------------------------------+
|**DLL_LOCK_STS**              |0x000001e0  |24    |ro    |0x00f00000  |DLL Lock Status, read         |
+------------------------------+------------+------+------+------------+------------------------------+
|**PHY_CTRL_STS**              |0x000001e4  |30    |ro    |0x00000000  |PHY Control status, read      |
+------------------------------+------------+------+------+------------+------------------------------+
|**PHY_CTRL_STS_REG2**         |0x000001e8  |27    |ro    |0x00000013  |PHY Control status (2), read  |
+------------------------------+------------+------+------+------------+------------------------------+
|**AXI_ID**                    |0x00000200  |26    |ro    |0x00153042  |ID and revision information   |
+------------------------------+------------+------+------+------------+------------------------------+
|**PAGE_MASK**                 |0x00000204  |32    |rw    |0x00000000  |Page mask                     |
+------------------------------+------------+------+------+------------+------------------------------+
|**AXI_PRIORITY_WR_PORT0**     |0x00000208  |20    |mixed |0x000803ff  | AXI Priority control for wri |
+------------------------------+------------+------+------+------------+------------------------------+
|**AXI_PRIORITY_WR_PORT1**     |0x0000020c  |20    |mixed |0x000803ff  | AXI Priority control for wri |
+------------------------------+------------+------+------+------------+------------------------------+
|**AXI_PRIORITY_WR_PORT2**     |0x00000210  |20    |mixed |0x000803ff  | AXI Priority control for wri |
+------------------------------+------------+------+------+------------+------------------------------+
|**AXI_PRIORITY_WR_PORT3**     |0x00000214  |20    |mixed |0x000803ff  | AXI Priority control for wri |
+------------------------------+------------+------+------+------------+------------------------------+
|**AXI_PRIORITY_RD_PORT0**     |0x00000218  |20    |mixed |0x000003ff  | AXI Priority control for rea |
+------------------------------+------------+------+------+------------+------------------------------+
|**AXI_PRIORITY_RD_PORT1**     |0x0000021c  |20    |mixed |0x000003ff  | AXI Priority control for rea |
+------------------------------+------------+------+------+------------+------------------------------+
|**AXI_PRIORITY_RD_PORT2**     |0x00000220  |20    |mixed |0x000003ff  | AXI Priority control for rea |
+------------------------------+------------+------+------+------------+------------------------------+
|**AXI_PRIORITY_RD_PORT3**     |0x00000224  |20    |mixed |0x000003ff  | AXI Priority control for rea |
+------------------------------+------------+------+------+------------+------------------------------+
|**EXCL_ACCESS_CFG0**          |0x00000294  |18    |rw    |0x00000000  | Exclusive access configurati |
+------------------------------+------------+------+------+------------+------------------------------+
|**EXCL_ACCESS_CFG1**          |0x00000298  |18    |rw    |0x00000000  | Exclusive access configurati |
+------------------------------+------------+------+------+------------+------------------------------+
|**EXCL_ACCESS_CFG2**          |0x0000029c  |18    |rw    |0x00000000  | Exclusive access configurati |
+------------------------------+------------+------+------+------------+------------------------------+
|**EXCL_ACCESS_CFG3**          |0x000002a0  |18    |rw    |0x00000000  | Exclusive access configurati |
+------------------------------+------------+------+------+------------+------------------------------+
|**MODE_REG_READ**             |0x000002a4  |32    |ro    |0x00000000  |Mode register read data       |
+------------------------------+------------+------+------+------------+------------------------------+
|**LPDDR_CTRL0**               |0x000002a8  |12    |rw    |0x00000000  |LPDDR2 Control 0              |
+------------------------------+------------+------+------+------------+------------------------------+
|**LPDDR_CTRL1**               |0x000002ac  |32    |rw    |0x00000000  |LPDDR2 Control 1              |
+------------------------------+------------+------+------+------------+------------------------------+
|**LPDDR_CTRL2**               |0x000002b0  |22    |rw    |0x003c0015  |LPDDR2 Control 2              |
+------------------------------+------------+------+------+------------+------------------------------+
|**LPDDR_CTRL3**               |0x000002b4  |18    |rw    |0x00000601  |LPDDR2 Control 3              |
+------------------------------+------------+------+------+------------+------------------------------+

### CTRL  

Relative Address = 0x00000000  
Width = 32 bits  
Access Type = rw  
Reset Value = 0x00000200  
Description DDRC Control  


### TWO_RANK_CFG  

Relative Address = 0x00000004  
Width = 29 bits  
Access Type = rw  
Reset Value = 0x000c1076  
Description Two Rank Configuration  


### HPR  

Relative Address = 0x00000008  
Width = 26 bits  
Access Type = rw  
Reset Value = 0x03c0780f  
Description HPR Queue control  


### LPR  

Relative Address = 0x0000000c  
Width = 26 bits  
Access Type = rw  
Reset Value = 0x03c0780f  
Description LPR Queue control  


### WR  

Relative Address = 0x00000010  
Width = 26 bits  
Access Type = rw  
Reset Value = 0x0007f80f  
Description WR Queue control  


### DRAM_PARAM0  

Relative Address = 0x00000014  
Width = 21 bits  
Access Type = rw  
Reset Value = 0x00041016  
Description DRAM Parameters 0  


### DRAM_PARAM1  

Relative Address = 0x00000018  
Width = 32 bits  
Access Type = rw  
Reset Value = 0x351b48d9  
Description DRAM Parameters 1  


### DRAM_PARAM2  

Relative Address = 0x0000001c  
Width = 32 bits  
Access Type = rw  
Reset Value = 0x00000000  
Description DRAM Parameters 2  


### DRAM_PARAM3  

Relative Address = 0x00000020  
Width = 32 bits  
Access Type = mixed  
Reset Value = 0x250882d0  
Description DRAM Parameters 3  


### DRAM_PARAM4  

Relative Address = 0x00000024  
Width = 28 bits  
Access Type = mixed  
Reset Value = 0x0000003c  
Description DRAM Parameters 4  


### DRAM_INIT_PARAM  

Relative Address = 0x00000028  
Width = 14 bits  
Access Type = rw  
Reset Value = 0x00002007  
Description DRAM Initialization Parameters  


### DRAM_EMR  

Relative Address = 0x0000002c  
Width = 32 bits  
Access Type = rw  
Reset Value = 0x00000008  
Description DRAM EMR2, EMR3 access  


### DRAM_EMR_MR  

Relative Address = 0x00000030  
Width = 32 bits  
Access Type = rw  
Reset Value = 0x00000940  
Description DRAM EMR, MR access  


### DRAM_BURST8_RDWR  

Relative Address = 0x00000034  
Width = 29 bits  
Access Type = mixed  
Reset Value = 0x00020034  
Description DRAM Burst 8 read/write  


### DRAM_DISABLE_DQ  

Relative Address = 0x00000038  
Width = 13 bits  
Access Type = mixed  
Reset Value = 0x00000000  
Description DRAM Disable DQ  


### DRAM_ADDR_MAP_BANK  

Relative Address = 0x0000003c  
Width = 20 bits  
Access Type = rw  
Reset Value = 0x00000f77  
Description Row/Column address bits  


### DRAM_ADDR_MAP_COL  

Relative Address = 0x00000040  
Width = 32 bits  
Access Type = rw  
Reset Value = 0x00000000  
Description Column address bits  


### DRAM_ADDR_MAP_ROW  

Relative Address = 0x00000044  
Width = 28 bits  
Access Type = rw  
Reset Value = 0x0ff55555  
Description Select DRAM row address bits  


### DRAM_ODT  

Relative Address = 0x00000048  
Width = 30 bits  
Access Type = rw  
Reset Value = 0x00000249  
Description DRAM ODT control  


### PHY_DBG  

Relative Address = 0x0000004c  
Width = 20 bits  
Access Type = ro  
Reset Value = 0x00000000  
Description PHY debug  


### PHY_CMD_TIMEOUT_RDDATA_CPT  

Relative Address = 0x00000050  
Width = 32 bits  
Access Type = mixed  
Reset Value = 0x00010200  
Description PHY command time out and  


### READ_DATA_CAPTURE_FIFOMODE_STS  

Relative Address = 0x00000054  
Width = 21 bits  
Access Type = ro  
Reset Value = 0x00000000  
Description Controller operation mode status  


### DLL_CALIB  

Relative Address = 0x00000058  
Width = 17 bits  
Access Type = rw  
Reset Value = 0x00000101  
Description DLL calibration  


### ODT_DELAY_HOLD  

Relative Address = 0x0000005c  
Width = 16 bits  
Access Type = rw  
Reset Value = 0x0023  
Description ODT delay and ODT hold  


### CTRL1  

Relative Address = 0x00000060  
Width = 13 bits  
Access Type = mixed  
Reset Value = 0x0000003e  
Description Controller 1  


### CTRL2  

Relative Address = 0x00000064  
Width = 18 bits  
Access Type = mixed  
Reset Value = 0x00020000  
Description Controller 2  


### CTRL3  

Relative Address = 0x00000068  
Width = 26 bits  
Access Type = rw  
Reset Value = 0x00284027  
Description Controller 3  


### CTRL4  

Relative Address = 0x0000006c  
Width = 16 bits  
Access Type = rw  
Reset Value = 0x1610  
Description Controller 4  


### CTRL5  

Relative Address = 0x00000078  
Width = 32 bits  
Access Type = mixed  
Reset Value = 0x00455111  
Description Controller register 5  


### CTRL6  

Relative Address = 0x0000007c  
Width = 32 bits  
Access Type = mixed  
Reset Value = 0x00032222  
Description Controller register 6  


### CHE_REFRESH_TIMER01  

Relative Address = 0x000000a0  
Width = 24 bits  
Access Type = rw  
Reset Value = 0x00008000  
Description CHE_REFRESH_TIMER01  


### CHE_T_ZQ  

Relative Address = 0x000000a4  
Width = 32 bits  
Access Type = rw  
Reset Value = 0x10300802  
Description ZQ parameters  


### CHE_T_ZQ_Short_Interval_Reg  

Relative Address = 0x000000a8  
Width = 28 bits  
Access Type = rw  
Reset Value = 0x0020003a  
Description Misc parameters  


### DEEP_PWRDWN  

Relative Address = 0x000000ac  
Width = 9 bits  
Access Type = rw  
Reset Value = 0x00000000  
Description Deep powerdown (LPDDR2)  


### REG_2C  

Relative Address = 0x000000b0  
Width = 29 bits  
Access Type = mixed  
Reset Value = 0x00000000  
Description Training control  


### REG_2D  

Relative Address = 0x000000b4  
Width = 11 bits  
Access Type = rw  
Reset Value = 0x00000200  
Description Misc Debug  


### DFI_TIMING  

Relative Address = 0x000000b8  
Width = 25 bits  
Access Type = rw  
Reset Value = 0x00200067  
Description DFI timing  


### CHE_ECC_CONTROL  

Relative Address = 0x000000c4  
Width = 2 bits  
Access Type = rw  
Reset Value = 0x00000000  
Description ECC error clear  


### CHE_CORR_ECC_LOG  

Relative Address = 0x000000c8  
Width = 8 bits  
Access Type = mixed  
Reset Value = 0x00  
Description ECC error correction  


### CHE_CORR_ECC_ADDR  

Relative Address = 0x000000cc  
Width = 31 bits  
Access Type = ro  
Reset Value = 0x00000000  
Description ECC error correction address log  


### CHE_CORR_ECC_DATA_31_0  

Relative Address = 0x000000d0  
Width = 32 bits  
Access Type = ro  
Reset Value = 0x00000000  
Description ECC error correction data log low  


### CHE_CORR_ECC_DATA_63_32  

Relative Address = 0x000000d4  
Width = 32 bits  
Access Type = ro  
Reset Value = 0x00000000  
Description ECC error correction data log mid  


### CHE_CORR_ECC_DATA_71_64  

Relative Address = 0x000000d8  
Width = 8 bits  
Access Type = ro  
Reset Value = 0x00  
Description ECC error correction data log high  


### CHE_UNCORR_ECC_LOG  

Relative Address = 0x000000dc  
Width = 1 bits  
Access Type = clronwr  
Reset Value = 0x00000000  
Description ECC unrecoverable error status  


### CHE_UNCORR_ECC_ADDR  

Relative Address = 0x000000e0  
Width = 31 bits  
Access Type = ro  
Reset Value = 0x00000000  
Description ECC unrecoverable error address  


### CHE_UNCORR_ECC_DATA_31_0  

Relative Address = 0x000000e4  
Width = 32 bits  
Access Type = ro  
Reset Value = 0x00000000  
Description ECC unrecoverable error data low  


### CHE_UNCORR_ECC_DATA_63_32  

Relative Address = 0x000000e8  
Width = 32 bits  
Access Type = ro  
Reset Value = 0x00000000  
Description ECC unrecoverable error data middle  


### CHE_UNCORR_ECC_DATA_71_64  

Relative Address = 0x000000ec  
Width = 8 bits  
Access Type = ro  
Reset Value = 0x00  
Description ECC unrecoverable error data high  


### CHE_ECC_STATS  

Relative Address = 0x000000f0  
Width = 16 bits  
Access Type = clronwr  
Reset Value = 0x0000  
Description ECC error count  


### ECC_SCRUB  

Relative Address = 0x000000f4  
Width = 4 bits  
Access Type = rw  
Reset Value = 0x00000008  
Description ECC mode/scrub  


### CHE_ECC_CORR_BIT_MASK_31_0_REG  

Relative Address = 0x000000f8  
Width = 32 bits  
Access Type = ro  
Reset Value = 0x00000000  
Description ECC data mask low  


### CHE_ECC_CORR_BIT_MASK_63_32_REG  

Relative Address = 0x000000fc  
Width = 32 bits  
Access Type = ro  
Reset Value = 0x00000000  
Description ECC data mask high  


### PHY_RCVR_ENABLE  

Relative Address = 0x00000114  
Width = 8 bits  
Access Type = rw  
Reset Value = 0x00  
Description Phy receiver enable register  


### PHY_CONFIG0  

Relative Address = 0x00000118  
Width = 31 bits  
Access Type = rw  
Reset Value = 0x40000001  
Description PHY configuration register for data slice 0.  


### PHY_CONFIG1  

Relative Address = 0x0000011c  
Width = 31 bits  
Access Type = rw  
Reset Value = 0x40000001  
Description PHY configuration register for data slice 1.  


### PHY_CONFIG2  

Relative Address = 0x00000120  
Width = 31 bits  
Access Type = rw  
Reset Value = 0x40000001  
Description PHY configuration register for data slice 2.  


### PHY_CONFIG3  

Relative Address = 0x00000124  
Width = 31 bits  
Access Type = rw  
Reset Value = 0x40000001  
Description PHY configuration register for data slice 3.  


### PHY_INIT_RATIO0  

Relative Address = 0x0000012c  
Width = 20 bits  
Access Type = rw  
Reset Value = 0x00000000  
Description PHY init ratio register for data slice 0.  


### PHY_INIT_RATIO1  

Relative Address = 0x00000130  
Width = 20 bits  
Access Type = rw  
Reset Value = 0x00000000  
Description PHY init ratio register for data slice 1.  


### PHY_INIT_RATIO2  

Relative Address = 0x00000134  
Width = 20 bits  
Access Type = rw  
Reset Value = 0x00000000  
Description PHY init ratio register for data slice 2.  


### PHY_INIT_RATIO3  

Relative Address = 0x00000138  
Width = 20 bits  
Access Type = rw  
Reset Value = 0x00000000  
Description PHY init ratio register for data slice 3.  


### PHY_RD_DQS_CFG0  

Relative Address = 0x00000140  
Width = 20 bits  
Access Type = rw  
Reset Value = 0x00000040  
Description PHY read DQS configuration register for data slice 0.  


### PHY_RD_DQS_CFG1  

Relative Address = 0x00000144  
Width = 20 bits  
Access Type = rw  
Reset Value = 0x00000040  
Description PHY read DQS configuration register for data slice 1.  


### PHY_RD_DQS_CFG2  

Relative Address = 0x00000148  
Width = 20 bits  
Access Type = rw  
Reset Value = 0x00000040  
Description PHY read DQS configuration register for data slice 2.  


### PHY_RD_DQS_CFG3  

Relative Address = 0x0000014c  
Width = 20 bits  
Access Type = rw  
Reset Value = 0x00000040  
Description PHY read DQS configuration register for data slice 3.  


### PHY_WR_DQS_CFG0  

Relative Address = 0x00000154  
Width = 20 bits  
Access Type = rw  
Reset Value = 0x00000000  
Description PHY write DQS configuration register for data slice 0.  


### PHY_WR_DQS_CFG1  

Relative Address = 0x00000158  
Width = 20 bits  
Access Type = rw  
Reset Value = 0x00000000  
Description PHY write DQS configuration register for data slice 1.  


### PHY_WR_DQS_CFG2  

Relative Address = 0x0000015c  
Width = 20 bits  
Access Type = rw  
Reset Value = 0x00000000  
Description PHY write DQS configuration register for data slice 2.  


### PHY_WR_DQS_CFG3  

Relative Address = 0x00000160  
Width = 20 bits  
Access Type = rw  
Reset Value = 0x00000000  
Description PHY write DQS configuration register for data slice 3.  


### PHY_WE_CFG0  

Relative Address = 0x00000168  
Width = 21 bits  
Access Type = rw  
Reset Value = 0x00000040  
Description PHY FIFO write enable configuration for data slice 0.  


### PHY_WE_CFG1  

Relative Address = 0x0000016c  
Width = 21 bits  
Access Type = rw  
Reset Value = 0x00000040  
Description PHY FIFO write enable configuration for data slice 1.  


### PHY_WE_CFG2  

Relative Address = 0x00000170  
Width = 21 bits  
Access Type = rw  
Reset Value = 0x00000040  
Description PHY FIFO write enable configuration for data slice 2.  


### PHY_WE_CFG3  

Relative Address = 0x00000174  
Width = 21 bits  
Access Type = rw  
Reset Value = 0x00000040  
Description PHY FIFO write enable configuration for data slice 3.  


### WR_DATA_SLV0  

Relative Address = 0x0000017c  
Width = 20 bits  
Access Type = rw  
Reset Value = 0x00000080  
Description PHY write data slave ratio config for data slice 0.  


### WR_DATA_SLV1  

Relative Address = 0x00000180  
Width = 20 bits  
Access Type = rw  
Reset Value = 0x00000080  
Description PHY write data slave ratio config for data slice 1.  


### WR_DATA_SLV2  

Relative Address = 0x00000184  
Width = 20 bits  
Access Type = rw  
Reset Value = 0x00000080  
Description PHY write data slave ratio config for data slice 2.  


### WR_DATA_SLV3  

Relative Address = 0x00000188  
Width = 20 bits  
Access Type = rw  
Reset Value = 0x00000080  
Description PHY write data slave ratio config for data slice 3.  


### REG_64  

Relative Address = 0x00000190  
Width = 32 bits  
Access Type = rw  
Reset Value = 0x10020000  
Description Training control 2  


### REG_65  

Relative Address = 0x00000194  
Width = 20 bits  
Access Type = rw  
Reset Value = 0x00000000  
Description Training control 3  


### REG69_6A0  

Relative Address = 0x000001a4  
Width = 29 bits  
Access Type = ro  
Reset Value = 0x00070000  
Description Training results for data slice 0.  


### REG69_6A1  

Relative Address = 0x000001a8  
Width = 29 bits  
Access Type = ro  
Reset Value = 0x00060200  
Description Training results for data slice 1.  


### REG6C_6D2  

Relative Address = 0x000001b0  
Width = 28 bits  
Access Type = ro  
Reset Value = 0x00040600  
Description Training results for data slice 2.  


### REG6C_6D3  

Relative Address = 0x000001b4  
Width = 28 bits  
Access Type = ro  
Reset Value = 0x00000e00  
Description Training results for data slice 3.  


### REG6E_710  

Relative Address = 0x000001b8  
Width = 30 bits  
Access Type = ro  
Reset Value = 0x00000000  
Description Training results (2) for data slice 0.  


### REG6E_711  

Relative Address = 0x000001bc  
Width = 30 bits  
Access Type = ro  
Reset Value = 0x00000000  
Description Training results (2) for data slice 1.  


### REG6E_712  

Relative Address = 0x000001c0  
Width = 30 bits  
Access Type = ro  
Reset Value = 0x00000000  
Description Training results (2) for data slice 2.  


### REG6E_713  

Relative Address = 0x000001c4  
Width = 30 bits  
Access Type = ro  
Reset Value = 0x00000000  
Description Training results (2) for data slice 3.  


### PHY_DLL_STS0  

Relative Address = 0x000001cc  
Width = 27 bits  
Access Type = ro  
Reset Value = 0x00000000  
Description Slave DLL results for data slice 0.  


### PHY_DLL_STS1  

Relative Address = 0x000001d0  
Width = 27 bits  
Access Type = ro  
Reset Value = 0x00000000  
Description Slave DLL results for data slice 1.  


### PHY_DLL_STS2  

Relative Address = 0x000001d4  
Width = 27 bits  
Access Type = ro  
Reset Value = 0x00000000  
Description Slave DLL results for data slice 2.  


### PHY_DLL_STS3  

Relative Address = 0x000001d8  
Width = 27 bits  
Access Type = ro  
Reset Value = 0x00000000  
Description Slave DLL results for data slice 3.  


### DLL_LOCK_STS  

Relative Address = 0x000001e0  
Width = 24 bits  
Access Type = ro  
Reset Value = 0x00f00000  
Description DLL Lock Status, read  


### PHY_CTRL_STS  

Relative Address = 0x000001e4  
Width = 30 bits  
Access Type = ro  
Reset Value = 0x00000000  
Description PHY Control status, read  


### PHY_CTRL_STS_REG2  

Relative Address = 0x000001e8  
Width = 27 bits  
Access Type = ro  
Reset Value = 0x00000013  
Description PHY Control status (2), read  


### AXI_ID  

Relative Address = 0x00000200  
Width = 26 bits  
Access Type = ro  
Reset Value = 0x00153042  
Description ID and revision information  


### PAGE_MASK  

Relative Address = 0x00000204  
Width = 32 bits  
Access Type = rw  
Reset Value = 0x00000000  
Description Page mask  


### AXI_PRIORITY_WR_PORT0  

Relative Address = 0x00000208  
Width = 20 bits  
Access Type = mixed  
Reset Value = 0x000803ff  
Description AXI Priority control for write port 0.  


### AXI_PRIORITY_WR_PORT1  

Relative Address = 0x0000020c  
Width = 20 bits  
Access Type = mixed  
Reset Value = 0x000803ff  
Description AXI Priority control for write port 1.  


### AXI_PRIORITY_WR_PORT2  

Relative Address = 0x00000210  
Width = 20 bits  
Access Type = mixed  
Reset Value = 0x000803ff  
Description AXI Priority control for write port 2.  


### AXI_PRIORITY_WR_PORT3  

Relative Address = 0x00000214  
Width = 20 bits  
Access Type = mixed  
Reset Value = 0x000803ff  
Description AXI Priority control for write port 3.  


### AXI_PRIORITY_RD_PORT0  

Relative Address = 0x00000218  
Width = 20 bits  
Access Type = mixed  
Reset Value = 0x000003ff  
Description AXI Priority control for read port 0.  


### AXI_PRIORITY_RD_PORT1  

Relative Address = 0x0000021c  
Width = 20 bits  
Access Type = mixed  
Reset Value = 0x000003ff  
Description AXI Priority control for read port 1.  


### AXI_PRIORITY_RD_PORT2  

Relative Address = 0x00000220  
Width = 20 bits  
Access Type = mixed  
Reset Value = 0x000003ff  
Description AXI Priority control for read port 2.  


### AXI_PRIORITY_RD_PORT3  

Relative Address = 0x00000224  
Width = 20 bits  
Access Type = mixed  
Reset Value = 0x000003ff  
Description AXI Priority control for read port 3.  


### EXCL_ACCESS_CFG0  

Relative Address = 0x00000294  
Width = 18 bits  
Access Type = rw  
Reset Value = 0x00000000  
Description Exclusive access configuration for port 0.  


### EXCL_ACCESS_CFG1  

Relative Address = 0x00000298  
Width = 18 bits  
Access Type = rw  
Reset Value = 0x00000000  
Description Exclusive access configuration for port 1.  


### EXCL_ACCESS_CFG2  

Relative Address = 0x0000029c  
Width = 18 bits  
Access Type = rw  
Reset Value = 0x00000000  
Description Exclusive access configuration for port 2.  


### EXCL_ACCESS_CFG3  

Relative Address = 0x000002a0  
Width = 18 bits  
Access Type = rw  
Reset Value = 0x00000000  
Description Exclusive access configuration for port 3.  


### MODE_REG_READ  

Relative Address = 0x000002a4  
Width = 32 bits  
Access Type = ro  
Reset Value = 0x00000000  
Description Mode register read data  


### LPDDR_CTRL0  

Relative Address = 0x000002a8  
Width = 12 bits  
Access Type = rw  
Reset Value = 0x00000000  
Description LPDDR2 Control 0  


### LPDDR_CTRL1  

Relative Address = 0x000002ac  
Width = 32 bits  
Access Type = rw  
Reset Value = 0x00000000  
Description LPDDR2 Control 1  


### LPDDR_CTRL2  

Relative Address = 0x000002b0  
Width = 22 bits  
Access Type = rw  
Reset Value = 0x003c0015  
Description LPDDR2 Control 2  


### LPDDR_CTRL3  

Relative Address = 0x000002b4  
Width = 18 bits  
Access Type = rw  
Reset Value = 0x00000601  
Description LPDDR2 Control 3  

