# Direct Memory Access Controller (PL330)  

Module Direct Memory Access Controller (PL330) (dmac)  
SPDX-License-Identifier: MIT  
Auto-generated: Sun Sep 20 23:32:01 EEST 2020  

dmac0_s Base Address = 0xf8003000  
dmac0_ns Base Address = 0xf8004000  

## Register Summary  

+------------------------------+------------+------+------+------------+------------------------------+
|Register Name                 |Address     |Width |Type  |Reset Value |Description                   |
+==============================+============+======+======+============+==============================+
|**DS**                        |0x00000000  |32    |mixed |0x00000000  |DMA Manager Status            |
+------------------------------+------------+------+------+------------+------------------------------+
|**DPC**                       |0x00000004  |32    |mixed |0x00000000  |DMA Program Counter           |
+------------------------------+------------+------+------+------------+------------------------------+
|**INTEN**                     |0x00000020  |32    |mixed |0x00000000  | DMASEV Instruction Response  |
+------------------------------+------------+------+------+------------+------------------------------+
|**ES**                        |0x00000024  |32    |mixed |0x00000000  |Event Interrupt Raw Status    |
+------------------------------+------------+------+------+------------+------------------------------+
|**INTSTATUS**                 |0x00000028  |32    |mixed |0x00000000  |Interrupt Status              |
+------------------------------+------------+------+------+------------+------------------------------+
|**INTCLR**                    |0x0000002c  |32    |mixed |0x00000000  |Interrupt Clear               |
+------------------------------+------------+------+------+------------+------------------------------+
|**FSM**                       |0x00000030  |32    |mixed |0x00000000  |Fault Status DMA Manager      |
+------------------------------+------------+------+------+------------+------------------------------+
|**FSC**                       |0x00000034  |32    |mixed |0x00000000  |Fault Status DMA Channel      |
+------------------------------+------------+------+------+------------+------------------------------+
|**FTM**                       |0x00000038  |32    |mixed |0x00000000  |Fault Type DMA Manager        |
+------------------------------+------------+------+------+------------+------------------------------+
|**FTC0**                      |0x00000040  |32    |mixed |0x00000000  |Default Type DMA Channel 0    |
+------------------------------+------------+------+------+------------+------------------------------+
|**FTCN_1**                    |0x00000044  |32    |mixed |0x00000000  |Default Type DMA Channel 1    |
+------------------------------+------------+------+------+------------+------------------------------+
|**FTCN_2**                    |0x00000048  |32    |mixed |0x00000000  |Default Type DMA Channel 2    |
+------------------------------+------------+------+------+------------+------------------------------+
|**FTCN_3**                    |0x0000004c  |32    |mixed |0x00000000  |Default Type DMA Channel 3    |
+------------------------------+------------+------+------+------------+------------------------------+
|**FTCN_4**                    |0x00000050  |32    |mixed |0x00000000  |Default Type DMA Channel 4    |
+------------------------------+------------+------+------+------------+------------------------------+
|**FTCN_5**                    |0x00000054  |32    |mixed |0x00000000  |Default Type DMA Channel 5    |
+------------------------------+------------+------+------+------------+------------------------------+
|**FTCN_6**                    |0x00000058  |32    |mixed |0x00000000  |Default Type DMA Channel 6    |
+------------------------------+------------+------+------+------------+------------------------------+
|**FTCN_7**                    |0x0000005c  |32    |mixed |0x00000000  |Default Type DMA Channel 7    |
+------------------------------+------------+------+------+------------+------------------------------+
|**CS0**                       |0x00000100  |32    |mixed |0x00000000  |Channel Status DMA Channel 0  |
+------------------------------+------------+------+------+------------+------------------------------+
|**CPC0**                      |0x00000104  |32    |mixed |0x00000000  |Channel PC for DMA Channel 0  |
+------------------------------+------------+------+------+------------+------------------------------+
|**CSN_1**                     |0x00000108  |32    |mixed |0x00000000  |Channel Status DMA Channel 1  |
+------------------------------+------------+------+------+------------+------------------------------+
|**CPCN_1**                    |0x0000010c  |32    |mixed |0x00000000  |Channel PC for DMA Channel 1  |
+------------------------------+------------+------+------+------------+------------------------------+
|**CSN_2**                     |0x00000110  |32    |mixed |0x00000000  |Channel Status DMA Channel 2  |
+------------------------------+------------+------+------+------------+------------------------------+
|**CPCN_2**                    |0x00000114  |32    |mixed |0x00000000  |Channel PC for DMA Channel 2  |
+------------------------------+------------+------+------+------------+------------------------------+
|**CSN_3**                     |0x00000118  |32    |mixed |0x00000000  |Channel Status DMA Channel 3  |
+------------------------------+------------+------+------+------------+------------------------------+
|**CPCN_3**                    |0x0000011c  |32    |mixed |0x00000000  |Channel PC for DMA Channel 3  |
+------------------------------+------------+------+------+------------+------------------------------+
|**CSN_4**                     |0x00000120  |32    |mixed |0x00000000  |Channel Status DMA Channel 4  |
+------------------------------+------------+------+------+------------+------------------------------+
|**CPCN_4**                    |0x00000124  |32    |mixed |0x00000000  |Channel PC for DMA Channel 4  |
+------------------------------+------------+------+------+------------+------------------------------+
|**CSN_5**                     |0x00000128  |32    |mixed |0x00000000  |Channel Status DMA Channel 5  |
+------------------------------+------------+------+------+------------+------------------------------+
|**CPCN_5**                    |0x0000012c  |32    |mixed |0x00000000  |Channel PC for DMA Channel 5  |
+------------------------------+------------+------+------+------------+------------------------------+
|**CSN_6**                     |0x00000130  |32    |mixed |0x00000000  |Channel Status DMA Channel 6  |
+------------------------------+------------+------+------+------------+------------------------------+
|**CPCN_6**                    |0x00000134  |32    |mixed |0x00000000  |Channel PC for DMA Channel 6  |
+------------------------------+------------+------+------+------------+------------------------------+
|**CSN_7**                     |0x00000138  |32    |mixed |0x00000000  |Channel Status DMA Channel 7  |
+------------------------------+------------+------+------+------------+------------------------------+
|**CPCN_7**                    |0x0000013c  |32    |mixed |0x00000000  |Channel PC for DMA Channel 7  |
+------------------------------+------------+------+------+------------+------------------------------+
|**SA_0**                      |0x00000400  |32    |mixed |0x00000000  |Source Address DMA Channel 0  |
+------------------------------+------------+------+------+------------+------------------------------+
|**DA_0**                      |0x00000404  |32    |mixed |0x00000000  | Destination Addr DMA Channel |
+------------------------------+------------+------+------+------------+------------------------------+
|**CC_0**                      |0x00000408  |32    |mixed |0x00000000  |Channel Control DMA Channel 0 |
+------------------------------+------------+------+------+------------+------------------------------+
|**LC0_0**                     |0x0000040c  |32    |mixed |0x00000000  |Loop Counter 0 DMA Channel 0  |
+------------------------------+------------+------+------+------------+------------------------------+
|**LC1_0**                     |0x00000410  |32    |mixed |0x00000000  |Loop Counter 1 DMA Channel 0  |
+------------------------------+------------+------+------+------------+------------------------------+
|**SA_N_1**                    |0x00000420  |32    |mixed |0x00000000  |Source address DMA Channel 1  |
+------------------------------+------------+------+------+------------+------------------------------+
|**DA_N_1**                    |0x00000424  |32    |mixed |0x00000000  | Destination Addr DMA Channel |
+------------------------------+------------+------+------+------------+------------------------------+
|**CC_N_1**                    |0x00000428  |32    |mixed |0x00000000  |Channel Control DMA Channel 1 |
+------------------------------+------------+------+------+------------+------------------------------+
|**LC0_N_1**                   |0x0000042c  |32    |mixed |0x00000000  |Loop Counter 0 DMA Channel 1  |
+------------------------------+------------+------+------+------------+------------------------------+
|**LC1_N_1**                   |0x00000430  |32    |mixed |0x00000000  |Loop Counter 1 DMA Channel 1  |
+------------------------------+------------+------+------+------------+------------------------------+
|**SA_N_2**                    |0x00000440  |32    |mixed |0x00000000  |Source Address DMA Channel 2  |
+------------------------------+------------+------+------+------------+------------------------------+
|**DA_N_2**                    |0x00000444  |32    |mixed |0x00000000  | Destination Addr DMA Channel |
+------------------------------+------------+------+------+------------+------------------------------+
|**CC_N_2**                    |0x00000448  |32    |mixed |0x00000000  |Channel Control DMA Channel 2 |
+------------------------------+------------+------+------+------------+------------------------------+
|**LC0_N_2**                   |0x0000044c  |32    |mixed |0x00000000  |Loop Counter 0 DMA Channel 2  |
+------------------------------+------------+------+------+------------+------------------------------+
|**LC1_N_2**                   |0x00000450  |32    |mixed |0x00000000  |Loop Counter 1 DMA Channel 2  |
+------------------------------+------------+------+------+------------+------------------------------+
|**SA_N_3**                    |0x00000460  |32    |mixed |0x00000000  |Source Address DMA Channel 3  |
+------------------------------+------------+------+------+------------+------------------------------+
|**DA_N_3**                    |0x00000464  |32    |mixed |0x00000000  | Destination Addr DMA Channel |
+------------------------------+------------+------+------+------------+------------------------------+
|**CC_N_3**                    |0x00000468  |32    |mixed |0x00000000  |Channel Control DMA Channel 3 |
+------------------------------+------------+------+------+------------+------------------------------+
|**LC0_N_3**                   |0x0000046c  |32    |mixed |0x00000000  |Loop Counter 0 DMA Channel 3  |
+------------------------------+------------+------+------+------------+------------------------------+
|**LC1_N_3**                   |0x00000470  |32    |mixed |0x00000000  |Loop Counter 1 DMA Channel 3  |
+------------------------------+------------+------+------+------------+------------------------------+
|**SA_N_4**                    |0x00000480  |32    |mixed |0x00000000  |Source Address DMA Channel 4  |
+------------------------------+------------+------+------+------------+------------------------------+
|**DA_N_4**                    |0x00000484  |32    |mixed |0x00000000  | Destination Addr DMA Channel |
+------------------------------+------------+------+------+------------+------------------------------+
|**CC_N_4**                    |0x00000488  |32    |mixed |0x00000000  |Channel Control DMA Channel 4 |
+------------------------------+------------+------+------+------------+------------------------------+
|**LC0_N_4**                   |0x0000048c  |32    |mixed |0x00000000  |Loop Counter 0 DMA Channel 4  |
+------------------------------+------------+------+------+------------+------------------------------+
|**LC1_N_4**                   |0x00000490  |32    |mixed |0x00000000  |Loop Counter 1 DMA Channel 4  |
+------------------------------+------------+------+------+------------+------------------------------+
|**SA_N_5**                    |0x000004a0  |32    |mixed |0x00000000  |Source Address DMA Channel 5  |
+------------------------------+------------+------+------+------------+------------------------------+
|**DA_N_5**                    |0x000004a4  |32    |mixed |0x00000000  | Destination Addr DMA Channel |
+------------------------------+------------+------+------+------------+------------------------------+
|**CC_N_5**                    |0x000004a8  |32    |mixed |0x00000000  |Channel Control DMA Channel 5 |
+------------------------------+------------+------+------+------------+------------------------------+
|**LC0_N_5**                   |0x000004ac  |32    |mixed |0x00000000  |Loop Counter 0 DMA Channel 5  |
+------------------------------+------------+------+------+------------+------------------------------+
|**LC1_N_5**                   |0x000004b0  |32    |mixed |0x00000000  |Loop Counter 1 DMA Channel 5  |
+------------------------------+------------+------+------+------------+------------------------------+
|**SA_N_6**                    |0x000004c0  |32    |mixed |0x00000000  |Source Address DMA Channel 6  |
+------------------------------+------------+------+------+------------+------------------------------+
|**DA_N_6**                    |0x000004c4  |32    |mixed |0x00000000  | Destination Addr DMA Channel |
+------------------------------+------------+------+------+------------+------------------------------+
|**CC_N_6**                    |0x000004c8  |32    |mixed |0x00000000  |Channel Control DMA Channel 6 |
+------------------------------+------------+------+------+------------+------------------------------+
|**LC0_N_6**                   |0x000004cc  |32    |mixed |0x00000000  |Loop Counter 0 DMA Channel 6  |
+------------------------------+------------+------+------+------------+------------------------------+
|**LC1_N_6**                   |0x000004d0  |32    |mixed |0x00000000  |Loop Counter 1 DMA Channel 6  |
+------------------------------+------------+------+------+------------+------------------------------+
|**SA_N_7**                    |0x000004e0  |32    |mixed |0x00000000  |Source Address DMA Channel 7  |
+------------------------------+------------+------+------+------------+------------------------------+
|**DA_N_7**                    |0x000004e4  |32    |mixed |0x00000000  | Destination Addr DMA Channel |
+------------------------------+------------+------+------+------------+------------------------------+
|**CC_N_7**                    |0x000004e8  |32    |mixed |0x00000000  |Channel Control DMA Channel 7 |
+------------------------------+------------+------+------+------------+------------------------------+
|**LC0_N_7**                   |0x000004ec  |32    |mixed |0x00000000  |Loop Counter 0 DMA Channel 7  |
+------------------------------+------------+------+------+------------+------------------------------+
|**LC1_N_7**                   |0x000004f0  |32    |mixed |0x00000000  |Loop Counter 1 DMA Channel 7  |
+------------------------------+------------+------+------+------------+------------------------------+
|**DBGSTATUS**                 |0x00000d00  |32    |mixed |0x00000000  |DMA Manager Execution Status  |
+------------------------------+------------+------+------+------------+------------------------------+
|**DBGCMD**                    |0x00000d04  |32    |mixed |0x00000000  |DMA Manager Instr. Command    |
+------------------------------+------------+------+------+------------+------------------------------+
|**DBGINST0**                  |0x00000d08  |32    |mixed |0x00000000  | DMA Manager Instruction Part |
+------------------------------+------------+------+------+------------+------------------------------+
|**DBGINST1**                  |0x00000d0c  |32    |mixed |0x00000000  | DMA Manager Instruction Part |
+------------------------------+------------+------+------+------------+------------------------------+
|**CR0**                       |0x00000e00  |32    |mixed |0x00000000  | Config. 0: Events, Periphera |
+------------------------------+------------+------+------+------------+------------------------------+
|**CR1**                       |0x00000e04  |32    |mixed |0x00000000  |Config. 1: Instruction Cache  |
+------------------------------+------------+------+------+------------+------------------------------+
|**CR2**                       |0x00000e08  |32    |mixed |0x00000000  |Config. 2: DMA Mgr Boot Addr  |
+------------------------------+------------+------+------+------------+------------------------------+
|**CR3**                       |0x00000e0c  |32    |mixed |0x00000000  | Config. 3: Security state of |
+------------------------------+------------+------+------+------------+------------------------------+
|**CR4**                       |0x00000e10  |32    |mixed |0x00000000  | Config 4, Security of Periph |
+------------------------------+------------+------+------+------------+------------------------------+
|**CRDN**                      |0x00000e14  |32    |mixed |0x00000000  |DMA configuration             |
+------------------------------+------------+------+------+------------+------------------------------+
|**WD**                        |0x00000e80  |32    |mixed |0x00000000  |Watchdog Timer                |
+------------------------------+------------+------+------+------------+------------------------------+
|**PERIPH_ID_0**               |0x00000fe0  |32    |mixed |0x00000000  | Peripheral Idenfication regi |
+------------------------------+------------+------+------+------------+------------------------------+
|**PERIPH_ID_1**               |0x00000fe4  |32    |mixed |0x00000000  | Peripheral Idenfication regi |
+------------------------------+------------+------+------+------------+------------------------------+
|**PERIPH_ID_2**               |0x00000fe8  |32    |mixed |0x00000000  | Peripheral Idenfication regi |
+------------------------------+------------+------+------+------------+------------------------------+
|**PERIPH_ID_3**               |0x00000fec  |32    |mixed |0x00000000  | Peripheral Idenfication regi |
+------------------------------+------------+------+------+------------+------------------------------+
|**PCELL_ID_0**                |0x00000ff0  |32    |mixed |0x00000000  | Compontent Idenfication regi |
+------------------------------+------------+------+------+------------+------------------------------+
|**PCELL_ID_1**                |0x00000ff4  |32    |mixed |0x00000000  | Compontent Idenfication regi |
+------------------------------+------------+------+------+------------+------------------------------+
|**PCELL_ID_2**                |0x00000ff8  |32    |mixed |0x00000000  | Compontent Idenfication regi |
+------------------------------+------------+------+------+------------+------------------------------+
|**PCELL_ID_3**                |0x00000ffc  |32    |mixed |0x00000000  | Compontent Idenfication regi |
+------------------------------+------------+------+------+------------+------------------------------+

### DS  

Relative Address = 0x00000000  
Width = 32 bits  
Access Type = mixed  
Reset Value = 0x00000000  
Description DMA Manager Status  


### DPC  

Relative Address = 0x00000004  
Width = 32 bits  
Access Type = mixed  
Reset Value = 0x00000000  
Description DMA Program Counter  


### INTEN  

Relative Address = 0x00000020  
Width = 32 bits  
Access Type = mixed  
Reset Value = 0x00000000  
Description DMASEV Instruction Response Control  


### ES  

Relative Address = 0x00000024  
Width = 32 bits  
Access Type = mixed  
Reset Value = 0x00000000  
Description Event Interrupt Raw Status  


### INTSTATUS  

Relative Address = 0x00000028  
Width = 32 bits  
Access Type = mixed  
Reset Value = 0x00000000  
Description Interrupt Status  


### INTCLR  

Relative Address = 0x0000002c  
Width = 32 bits  
Access Type = mixed  
Reset Value = 0x00000000  
Description Interrupt Clear  


### FSM  

Relative Address = 0x00000030  
Width = 32 bits  
Access Type = mixed  
Reset Value = 0x00000000  
Description Fault Status DMA Manager  


### FSC  

Relative Address = 0x00000034  
Width = 32 bits  
Access Type = mixed  
Reset Value = 0x00000000  
Description Fault Status DMA Channel  


### FTM  

Relative Address = 0x00000038  
Width = 32 bits  
Access Type = mixed  
Reset Value = 0x00000000  
Description Fault Type DMA Manager  


### FTC0  

Relative Address = 0x00000040  
Width = 32 bits  
Access Type = mixed  
Reset Value = 0x00000000  
Description Default Type DMA Channel 0  


### FTCN_1  

Relative Address = 0x00000044  
Width = 32 bits  
Access Type = mixed  
Reset Value = 0x00000000  
Description Default Type DMA Channel 1  


### FTCN_2  

Relative Address = 0x00000048  
Width = 32 bits  
Access Type = mixed  
Reset Value = 0x00000000  
Description Default Type DMA Channel 2  


### FTCN_3  

Relative Address = 0x0000004c  
Width = 32 bits  
Access Type = mixed  
Reset Value = 0x00000000  
Description Default Type DMA Channel 3  


### FTCN_4  

Relative Address = 0x00000050  
Width = 32 bits  
Access Type = mixed  
Reset Value = 0x00000000  
Description Default Type DMA Channel 4  


### FTCN_5  

Relative Address = 0x00000054  
Width = 32 bits  
Access Type = mixed  
Reset Value = 0x00000000  
Description Default Type DMA Channel 5  


### FTCN_6  

Relative Address = 0x00000058  
Width = 32 bits  
Access Type = mixed  
Reset Value = 0x00000000  
Description Default Type DMA Channel 6  


### FTCN_7  

Relative Address = 0x0000005c  
Width = 32 bits  
Access Type = mixed  
Reset Value = 0x00000000  
Description Default Type DMA Channel 7  


### CS0  

Relative Address = 0x00000100  
Width = 32 bits  
Access Type = mixed  
Reset Value = 0x00000000  
Description Channel Status DMA Channel 0  


### CPC0  

Relative Address = 0x00000104  
Width = 32 bits  
Access Type = mixed  
Reset Value = 0x00000000  
Description Channel PC for DMA Channel 0  


### CSN_1  

Relative Address = 0x00000108  
Width = 32 bits  
Access Type = mixed  
Reset Value = 0x00000000  
Description Channel Status DMA Channel 1  


### CPCN_1  

Relative Address = 0x0000010c  
Width = 32 bits  
Access Type = mixed  
Reset Value = 0x00000000  
Description Channel PC for DMA Channel 1  


### CSN_2  

Relative Address = 0x00000110  
Width = 32 bits  
Access Type = mixed  
Reset Value = 0x00000000  
Description Channel Status DMA Channel 2  


### CPCN_2  

Relative Address = 0x00000114  
Width = 32 bits  
Access Type = mixed  
Reset Value = 0x00000000  
Description Channel PC for DMA Channel 2  


### CSN_3  

Relative Address = 0x00000118  
Width = 32 bits  
Access Type = mixed  
Reset Value = 0x00000000  
Description Channel Status DMA Channel 3  


### CPCN_3  

Relative Address = 0x0000011c  
Width = 32 bits  
Access Type = mixed  
Reset Value = 0x00000000  
Description Channel PC for DMA Channel 3  


### CSN_4  

Relative Address = 0x00000120  
Width = 32 bits  
Access Type = mixed  
Reset Value = 0x00000000  
Description Channel Status DMA Channel 4  


### CPCN_4  

Relative Address = 0x00000124  
Width = 32 bits  
Access Type = mixed  
Reset Value = 0x00000000  
Description Channel PC for DMA Channel 4  


### CSN_5  

Relative Address = 0x00000128  
Width = 32 bits  
Access Type = mixed  
Reset Value = 0x00000000  
Description Channel Status DMA Channel 5  


### CPCN_5  

Relative Address = 0x0000012c  
Width = 32 bits  
Access Type = mixed  
Reset Value = 0x00000000  
Description Channel PC for DMA Channel 5  


### CSN_6  

Relative Address = 0x00000130  
Width = 32 bits  
Access Type = mixed  
Reset Value = 0x00000000  
Description Channel Status DMA Channel 6  


### CPCN_6  

Relative Address = 0x00000134  
Width = 32 bits  
Access Type = mixed  
Reset Value = 0x00000000  
Description Channel PC for DMA Channel 6  


### CSN_7  

Relative Address = 0x00000138  
Width = 32 bits  
Access Type = mixed  
Reset Value = 0x00000000  
Description Channel Status DMA Channel 7  


### CPCN_7  

Relative Address = 0x0000013c  
Width = 32 bits  
Access Type = mixed  
Reset Value = 0x00000000  
Description Channel PC for DMA Channel 7  


### SA_0  

Relative Address = 0x00000400  
Width = 32 bits  
Access Type = mixed  
Reset Value = 0x00000000  
Description Source Address DMA Channel 0  


### DA_0  

Relative Address = 0x00000404  
Width = 32 bits  
Access Type = mixed  
Reset Value = 0x00000000  
Description Destination Addr DMA Channel 0  


### CC_0  

Relative Address = 0x00000408  
Width = 32 bits  
Access Type = mixed  
Reset Value = 0x00000000  
Description Channel Control DMA Channel 0  


### LC0_0  

Relative Address = 0x0000040c  
Width = 32 bits  
Access Type = mixed  
Reset Value = 0x00000000  
Description Loop Counter 0 DMA Channel 0  


### LC1_0  

Relative Address = 0x00000410  
Width = 32 bits  
Access Type = mixed  
Reset Value = 0x00000000  
Description Loop Counter 1 DMA Channel 0  


### SA_N_1  

Relative Address = 0x00000420  
Width = 32 bits  
Access Type = mixed  
Reset Value = 0x00000000  
Description Source address DMA Channel 1  


### DA_N_1  

Relative Address = 0x00000424  
Width = 32 bits  
Access Type = mixed  
Reset Value = 0x00000000  
Description Destination Addr DMA Channel 1  


### CC_N_1  

Relative Address = 0x00000428  
Width = 32 bits  
Access Type = mixed  
Reset Value = 0x00000000  
Description Channel Control DMA Channel 1  


### LC0_N_1  

Relative Address = 0x0000042c  
Width = 32 bits  
Access Type = mixed  
Reset Value = 0x00000000  
Description Loop Counter 0 DMA Channel 1  


### LC1_N_1  

Relative Address = 0x00000430  
Width = 32 bits  
Access Type = mixed  
Reset Value = 0x00000000  
Description Loop Counter 1 DMA Channel 1  


### SA_N_2  

Relative Address = 0x00000440  
Width = 32 bits  
Access Type = mixed  
Reset Value = 0x00000000  
Description Source Address DMA Channel 2  


### DA_N_2  

Relative Address = 0x00000444  
Width = 32 bits  
Access Type = mixed  
Reset Value = 0x00000000  
Description Destination Addr DMA Channel 2  


### CC_N_2  

Relative Address = 0x00000448  
Width = 32 bits  
Access Type = mixed  
Reset Value = 0x00000000  
Description Channel Control DMA Channel 2  


### LC0_N_2  

Relative Address = 0x0000044c  
Width = 32 bits  
Access Type = mixed  
Reset Value = 0x00000000  
Description Loop Counter 0 DMA Channel 2  


### LC1_N_2  

Relative Address = 0x00000450  
Width = 32 bits  
Access Type = mixed  
Reset Value = 0x00000000  
Description Loop Counter 1 DMA Channel 2  


### SA_N_3  

Relative Address = 0x00000460  
Width = 32 bits  
Access Type = mixed  
Reset Value = 0x00000000  
Description Source Address DMA Channel 3  


### DA_N_3  

Relative Address = 0x00000464  
Width = 32 bits  
Access Type = mixed  
Reset Value = 0x00000000  
Description Destination Addr DMA Channel 3  


### CC_N_3  

Relative Address = 0x00000468  
Width = 32 bits  
Access Type = mixed  
Reset Value = 0x00000000  
Description Channel Control DMA Channel 3  


### LC0_N_3  

Relative Address = 0x0000046c  
Width = 32 bits  
Access Type = mixed  
Reset Value = 0x00000000  
Description Loop Counter 0 DMA Channel 3  


### LC1_N_3  

Relative Address = 0x00000470  
Width = 32 bits  
Access Type = mixed  
Reset Value = 0x00000000  
Description Loop Counter 1 DMA Channel 3  


### SA_N_4  

Relative Address = 0x00000480  
Width = 32 bits  
Access Type = mixed  
Reset Value = 0x00000000  
Description Source Address DMA Channel 4  


### DA_N_4  

Relative Address = 0x00000484  
Width = 32 bits  
Access Type = mixed  
Reset Value = 0x00000000  
Description Destination Addr DMA Channel 4  


### CC_N_4  

Relative Address = 0x00000488  
Width = 32 bits  
Access Type = mixed  
Reset Value = 0x00000000  
Description Channel Control DMA Channel 4  


### LC0_N_4  

Relative Address = 0x0000048c  
Width = 32 bits  
Access Type = mixed  
Reset Value = 0x00000000  
Description Loop Counter 0 DMA Channel 4  


### LC1_N_4  

Relative Address = 0x00000490  
Width = 32 bits  
Access Type = mixed  
Reset Value = 0x00000000  
Description Loop Counter 1 DMA Channel 4  


### SA_N_5  

Relative Address = 0x000004a0  
Width = 32 bits  
Access Type = mixed  
Reset Value = 0x00000000  
Description Source Address DMA Channel 5  


### DA_N_5  

Relative Address = 0x000004a4  
Width = 32 bits  
Access Type = mixed  
Reset Value = 0x00000000  
Description Destination Addr DMA Channel 5  


### CC_N_5  

Relative Address = 0x000004a8  
Width = 32 bits  
Access Type = mixed  
Reset Value = 0x00000000  
Description Channel Control DMA Channel 5  


### LC0_N_5  

Relative Address = 0x000004ac  
Width = 32 bits  
Access Type = mixed  
Reset Value = 0x00000000  
Description Loop Counter 0 DMA Channel 5  


### LC1_N_5  

Relative Address = 0x000004b0  
Width = 32 bits  
Access Type = mixed  
Reset Value = 0x00000000  
Description Loop Counter 1 DMA Channel 5  


### SA_N_6  

Relative Address = 0x000004c0  
Width = 32 bits  
Access Type = mixed  
Reset Value = 0x00000000  
Description Source Address DMA Channel 6  


### DA_N_6  

Relative Address = 0x000004c4  
Width = 32 bits  
Access Type = mixed  
Reset Value = 0x00000000  
Description Destination Addr DMA Channel 6  


### CC_N_6  

Relative Address = 0x000004c8  
Width = 32 bits  
Access Type = mixed  
Reset Value = 0x00000000  
Description Channel Control DMA Channel 6  


### LC0_N_6  

Relative Address = 0x000004cc  
Width = 32 bits  
Access Type = mixed  
Reset Value = 0x00000000  
Description Loop Counter 0 DMA Channel 6  


### LC1_N_6  

Relative Address = 0x000004d0  
Width = 32 bits  
Access Type = mixed  
Reset Value = 0x00000000  
Description Loop Counter 1 DMA Channel 6  


### SA_N_7  

Relative Address = 0x000004e0  
Width = 32 bits  
Access Type = mixed  
Reset Value = 0x00000000  
Description Source Address DMA Channel 7  


### DA_N_7  

Relative Address = 0x000004e4  
Width = 32 bits  
Access Type = mixed  
Reset Value = 0x00000000  
Description Destination Addr DMA Channel 7  


### CC_N_7  

Relative Address = 0x000004e8  
Width = 32 bits  
Access Type = mixed  
Reset Value = 0x00000000  
Description Channel Control DMA Channel 7  


### LC0_N_7  

Relative Address = 0x000004ec  
Width = 32 bits  
Access Type = mixed  
Reset Value = 0x00000000  
Description Loop Counter 0 DMA Channel 7  


### LC1_N_7  

Relative Address = 0x000004f0  
Width = 32 bits  
Access Type = mixed  
Reset Value = 0x00000000  
Description Loop Counter 1 DMA Channel 7  


### DBGSTATUS  

Relative Address = 0x00000d00  
Width = 32 bits  
Access Type = mixed  
Reset Value = 0x00000000  
Description DMA Manager Execution Status  


### DBGCMD  

Relative Address = 0x00000d04  
Width = 32 bits  
Access Type = mixed  
Reset Value = 0x00000000  
Description DMA Manager Instr. Command  


### DBGINST0  

Relative Address = 0x00000d08  
Width = 32 bits  
Access Type = mixed  
Reset Value = 0x00000000  
Description DMA Manager Instruction Part A  


### DBGINST1  

Relative Address = 0x00000d0c  
Width = 32 bits  
Access Type = mixed  
Reset Value = 0x00000000  
Description DMA Manager Instruction Part B  


### CR0  

Relative Address = 0x00000e00  
Width = 32 bits  
Access Type = mixed  
Reset Value = 0x00000000  
Description Config. 0: Events, Peripheral Interfaces, PC, Mode  


### CR1  

Relative Address = 0x00000e04  
Width = 32 bits  
Access Type = mixed  
Reset Value = 0x00000000  
Description Config. 1: Instruction Cache  


### CR2  

Relative Address = 0x00000e08  
Width = 32 bits  
Access Type = mixed  
Reset Value = 0x00000000  
Description Config. 2: DMA Mgr Boot Addr  


### CR3  

Relative Address = 0x00000e0c  
Width = 32 bits  
Access Type = mixed  
Reset Value = 0x00000000  
Description Config. 3: Security state of IRQs  


### CR4  

Relative Address = 0x00000e10  
Width = 32 bits  
Access Type = mixed  
Reset Value = 0x00000000  
Description Config 4, Security of Periph Interfaces  


### CRDN  

Relative Address = 0x00000e14  
Width = 32 bits  
Access Type = mixed  
Reset Value = 0x00000000  
Description DMA configuration  


### WD  

Relative Address = 0x00000e80  
Width = 32 bits  
Access Type = mixed  
Reset Value = 0x00000000  
Description Watchdog Timer  


### PERIPH_ID_0  

Relative Address = 0x00000fe0  
Width = 32 bits  
Access Type = mixed  
Reset Value = 0x00000000  
Description Peripheral Idenfication register 0  


### PERIPH_ID_1  

Relative Address = 0x00000fe4  
Width = 32 bits  
Access Type = mixed  
Reset Value = 0x00000000  
Description Peripheral Idenfication register 1  


### PERIPH_ID_2  

Relative Address = 0x00000fe8  
Width = 32 bits  
Access Type = mixed  
Reset Value = 0x00000000  
Description Peripheral Idenfication register 2  


### PERIPH_ID_3  

Relative Address = 0x00000fec  
Width = 32 bits  
Access Type = mixed  
Reset Value = 0x00000000  
Description Peripheral Idenfication register 3  


### PCELL_ID_0  

Relative Address = 0x00000ff0  
Width = 32 bits  
Access Type = mixed  
Reset Value = 0x00000000  
Description Compontent Idenfication register 0  


### PCELL_ID_1  

Relative Address = 0x00000ff4  
Width = 32 bits  
Access Type = mixed  
Reset Value = 0x00000000  
Description Compontent Idenfication register 1  


### PCELL_ID_2  

Relative Address = 0x00000ff8  
Width = 32 bits  
Access Type = mixed  
Reset Value = 0x00000000  
Description Compontent Idenfication register 2  


### PCELL_ID_3  

Relative Address = 0x00000ffc  
Width = 32 bits  
Access Type = mixed  
Reset Value = 0x00000000  
Description Compontent Idenfication register 3  

