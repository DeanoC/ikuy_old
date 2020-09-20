# SD2.0/SDIO2.0/MMC3.31  

Module SD2.0/SDIO2.0/MMC3.31 (sdio)  
SPDX-License-Identifier: MIT  
Auto-generated: Sun Sep 20 15:25:57 EEST 2020  

sd0 Base Address = 0xe0100000  
sd1 Base Address = 0xe0101000  

## Register Summary  

+------------------------------+------------+------+------+------------+------------------------------+
|Register Name                 |Address     |Width |Type  |Reset Value |Description                   |
+==============================+============+======+======+============+==============================+
|**SDMA_SYSTEM_ADDRESS**       |0x00000000  |32    |rw    |0x00000000  |System DMA Address Register   |
+------------------------------+------------+------+------+------------+------------------------------+
|**BLOCK_SIZE**                |0x00000004  |32    |mixed |0x00000000  |Block size register           |
+------------------------------+------------+------+------+------------+------------------------------+
|**ARGUMENT**                  |0x00000008  |32    |rw    |0x00000000  |Argument register             |
+------------------------------+------------+------+------+------------+------------------------------+
|**TRANSFER_CMD**              |0x0000000c  |32    |mixed |0x00000000  | Transfer mode register comma |
+------------------------------+------------+------+------+------------+------------------------------+
|**RESPONSE0**                 |0x00000010  |32    |ro    |0x00000000  |Response register             |
+------------------------------+------------+------+------+------------+------------------------------+
|**RESPONSE1**                 |0x00000014  |32    |ro    |0x00000000  |Response register             |
+------------------------------+------------+------+------+------------+------------------------------+
|**RESPONSE2**                 |0x00000018  |32    |ro    |0x00000000  |Response register             |
+------------------------------+------------+------+------+------------+------------------------------+
|**RESPONSE3**                 |0x0000001c  |32    |ro    |0x00000000  |Response register             |
+------------------------------+------------+------+------+------------+------------------------------+
|**BUFFER_DATA**               |0x00000020  |32    |rw    |0x00000000  |Buffer data port register     |
+------------------------------+------------+------+------+------------+------------------------------+
|**PRESENT_STATE**             |0x00000024  |25    |ro    |0x01f20000  |Present State register        |
+------------------------------+------------+------+------+------------+------------------------------+
|**HOST_CTRL**                 |0x00000028  |32    |mixed |0x00000000  | Host control register Power  |
+------------------------------+------------+------+------+------------+------------------------------+
|**CLOCK_CTRL**                |0x0000002c  |27    |mixed |0x00000000  | Clock Control register Timeo |
+------------------------------+------------+------+------+------------+------------------------------+
|**INTERRUPT_STATUS**          |0x00000030  |30    |mixed |0x00000000  | Normal interrupt status regi |
+------------------------------+------------+------+------+------------+------------------------------+
|**INTERRUPT_STATUS_EN**       |0x00000034  |30    |mixed |0x00000000  | Normal interrupt status enab |
+------------------------------+------------+------+------+------------+------------------------------+
|**INTERRUPT_SIGNAL_E**        |0x00000038  |30    |mixed |0x00000000  | Normal interrupt signal enab |
+------------------------------+------------+------+------+------------+------------------------------+
|**AUTO_CMD12_STATUS**         |0x0000003c  |8     |ro    |0x00        | Auto CMD12 error status regi |
+------------------------------+------------+------+------+------------+------------------------------+
|**CAPABILITIES**              |0x00000040  |31    |ro    |0x69ec0080  |Capabilities register         |
+------------------------------+------------+------+------+------------+------------------------------+
|**CURRENT_CAPS**              |0x00000048  |24    |ro    |0x00000001  | Maximum current capabilities |
+------------------------------+------------+------+------+------------+------------------------------+
|**FORCE_AUTO_CMD12_STATUS**   |0x00000050  |32    |mixed |0x00000000  | Force event register for Aut |
+------------------------------+------------+------+------+------------+------------------------------+
|**ADMA_ERROR_STATUS**         |0x00000054  |3     |mixed |0x00000000  |ADMA error status register    |
+------------------------------+------------+------+------+------------+------------------------------+
|**ADMA_SYSTEM_ADDRESS**       |0x00000058  |32    |rw    |0x00000000  |ADMA system address register  |
+------------------------------+------------+------+------+------------+------------------------------+
|**BOOT_TIMEOUT_CTRL**         |0x00000060  |32    |rw    |0x00000000  |Boot Timeout control register |
+------------------------------+------------+------+------+------------+------------------------------+
|**DEBUG_SEL**                 |0x00000064  |1     |wo    |0x00000000  |Debug Selection Register      |
+------------------------------+------------+------+------+------------+------------------------------+
|**SPI_INTERRUPT_SUPPORT**     |0x000000f0  |8     |rw    |0x00        | SPI interrupt support regist |
+------------------------------+------------+------+------+------------+------------------------------+
|**SLOT_INTERRUPT_STATUS**     |0x000000fc  |32    |ro    |0x00000000  | Slot interrupt status regist |
+------------------------------+------------+------+------+------------+------------------------------+

### SDMA_SYSTEM_ADDRESS  

Module sdio  
Relative Address = 0x00000000  
Width = 32 bits  
Access Type = rw  
Reset Value = 0x00000000  
Description System DMA Address Register  


### BLOCK_SIZE  

Module sdio  
Relative Address = 0x00000004  
Width = 32 bits  
Access Type = mixed  
Reset Value = 0x00000000  
Description Block size register  


### ARGUMENT  

Module sdio  
Relative Address = 0x00000008  
Width = 32 bits  
Access Type = rw  
Reset Value = 0x00000000  
Description Argument register  


### TRANSFER_CMD  

Module sdio  
Relative Address = 0x0000000c  
Width = 32 bits  
Access Type = mixed  
Reset Value = 0x00000000  
Description Transfer mode register command register  


### RESPONSE0  

Module sdio  
Relative Address = 0x00000010  
Width = 32 bits  
Access Type = ro  
Reset Value = 0x00000000  
Description Response register  


### RESPONSE1  

Module sdio  
Relative Address = 0x00000014  
Width = 32 bits  
Access Type = ro  
Reset Value = 0x00000000  
Description Response register  


### RESPONSE2  

Module sdio  
Relative Address = 0x00000018  
Width = 32 bits  
Access Type = ro  
Reset Value = 0x00000000  
Description Response register  


### RESPONSE3  

Module sdio  
Relative Address = 0x0000001c  
Width = 32 bits  
Access Type = ro  
Reset Value = 0x00000000  
Description Response register  


### BUFFER_DATA  

Module sdio  
Relative Address = 0x00000020  
Width = 32 bits  
Access Type = rw  
Reset Value = 0x00000000  
Description Buffer data port register  


### PRESENT_STATE  

Module sdio  
Relative Address = 0x00000024  
Width = 25 bits  
Access Type = ro  
Reset Value = 0x01f20000  
Description Present State register  


### HOST_CTRL  

Module sdio  
Relative Address = 0x00000028  
Width = 32 bits  
Access Type = mixed  
Reset Value = 0x00000000  
Description Host control register Power control register Block gap control register Wake-up control register  


### CLOCK_CTRL  

Module sdio  
Relative Address = 0x0000002c  
Width = 27 bits  
Access Type = mixed  
Reset Value = 0x00000000  
Description Clock Control register Timeout control register Software reset register  


### INTERRUPT_STATUS  

Module sdio  
Relative Address = 0x00000030  
Width = 30 bits  
Access Type = mixed  
Reset Value = 0x00000000  
Description Normal interrupt status register  


### INTERRUPT_STATUS_EN  

Module sdio  
Relative Address = 0x00000034  
Width = 30 bits  
Access Type = mixed  
Reset Value = 0x00000000  
Description Normal interrupt status enable register  


### INTERRUPT_SIGNAL_E  

Module sdio  
Relative Address = 0x00000038  
Width = 30 bits  
Access Type = mixed  
Reset Value = 0x00000000  
Description Normal interrupt signal enable register  


### AUTO_CMD12_STATUS  

Module sdio  
Relative Address = 0x0000003c  
Width = 8 bits  
Access Type = ro  
Reset Value = 0x00  
Description Auto CMD12 error status register  


### CAPABILITIES  

Module sdio  
Relative Address = 0x00000040  
Width = 31 bits  
Access Type = ro  
Reset Value = 0x69ec0080  
Description Capabilities register  


### CURRENT_CAPS  

Module sdio  
Relative Address = 0x00000048  
Width = 24 bits  
Access Type = ro  
Reset Value = 0x00000001  
Description Maximum current capabilities register  


### FORCE_AUTO_CMD12_STATUS  

Module sdio  
Relative Address = 0x00000050  
Width = 32 bits  
Access Type = mixed  
Reset Value = 0x00000000  
Description Force event register for Auto CMD12 error status register  


### ADMA_ERROR_STATUS  

Module sdio  
Relative Address = 0x00000054  
Width = 3 bits  
Access Type = mixed  
Reset Value = 0x00000000  
Description ADMA error status register  


### ADMA_SYSTEM_ADDRESS  

Module sdio  
Relative Address = 0x00000058  
Width = 32 bits  
Access Type = rw  
Reset Value = 0x00000000  
Description ADMA system address register  


### BOOT_TIMEOUT_CTRL  

Module sdio  
Relative Address = 0x00000060  
Width = 32 bits  
Access Type = rw  
Reset Value = 0x00000000  
Description Boot Timeout control register  


### DEBUG_SEL  

Module sdio  
Relative Address = 0x00000064  
Width = 1 bits  
Access Type = wo  
Reset Value = 0x00000000  
Description Debug Selection Register  


### SPI_INTERRUPT_SUPPORT  

Module sdio  
Relative Address = 0x000000f0  
Width = 8 bits  
Access Type = rw  
Reset Value = 0x00  
Description SPI interrupt support register  


### SLOT_INTERRUPT_STATUS  

Module sdio  
Relative Address = 0x000000fc  
Width = 32 bits  
Access Type = ro  
Reset Value = 0x00000000  
Description Slot interrupt status register and Host controller version register  

