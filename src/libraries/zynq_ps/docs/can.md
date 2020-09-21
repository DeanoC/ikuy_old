# Controller Area Network  

Module Controller Area Network (can)  
SPDX-License-Identifier: MIT  
Auto-generated: Mon Sep 21 21:57:55 EEST 2020  

can0 Base Address = 0xe0008000  
can1 Base Address = 0xe0009000  

## Register Summary  

+------------------------------+------------+------+------+------------+------------------------------+
|Register Name                 |Address     |Width |Type  |Reset Value |Description                   |
+==============================+============+======+======+============+==============================+
|**XCANPS_SRR_OFFSET**         |0x00000000  |32    |rw    |0x00000000  |Software Reset Register       |
+------------------------------+------------+------+------+------------+------------------------------+
|**XCANPS_MSR_OFFSET**         |0x00000004  |32    |rw    |0x00000000  |Mode Select Register          |
+------------------------------+------------+------+------+------------+------------------------------+
|**XCANPS_BRPR_OFFSET**        |0x00000008  |32    |rw    |0x00000000  |Baud Rate Prescaler Register  |
+------------------------------+------------+------+------+------------+------------------------------+
|**XCANPS_BTR_OFFSET**         |0x0000000c  |32    |rw    |0x00000000  |Bit Timing Register           |
+------------------------------+------------+------+------+------------+------------------------------+
|**XCANPS_ECR_OFFSET**         |0x00000010  |32    |ro    |0x00000000  |Error Counter Register        |
+------------------------------+------------+------+------+------------+------------------------------+
|**XCANPS_ESR_OFFSET**         |0x00000014  |32    |mixed |0x00000000  |Error Status Register         |
+------------------------------+------------+------+------+------------+------------------------------+
|**XCANPS_SR_OFFSET**          |0x00000018  |32    |mixed |0x00000001  |Status Register               |
+------------------------------+------------+------+------+------------+------------------------------+
|**XCANPS_ISR_OFFSET**         |0x0000001c  |32    |mixed |0x00006000  |Interrupt Status Register     |
+------------------------------+------------+------+------+------------+------------------------------+
|**XCANPS_IER_OFFSET**         |0x00000020  |32    |rw    |0x00000000  |Interrupt Enable Register     |
+------------------------------+------------+------+------+------------+------------------------------+
|**XCANPS_ICR_OFFSET**         |0x00000024  |32    |mixed |0x00000000  |Interrupt Clear Register      |
+------------------------------+------------+------+------+------------+------------------------------+
|**XCANPS_TCR_OFFSET**         |0x00000028  |32    |mixed |0x00000000  |Timestamp Control Register    |
+------------------------------+------------+------+------+------------+------------------------------+
|**XCANPS_WIR_OFFSET**         |0x0000002c  |32    |rw    |0x00003f3f  |Watermark Interrupt Register  |
+------------------------------+------------+------+------+------------+------------------------------+
|**XCANPS_TXFIFO_ID_OFFSET**   |0x00000030  |32    |wo    |0x00000000  | transmit message fifo messag |
+------------------------------+------------+------+------+------------+------------------------------+
|**XCANPS_TXFIFO_DLC_OFFSET**  |0x00000034  |32    |rw    |0x00000000  | transmit message fifo data l |
+------------------------------+------------+------+------+------------+------------------------------+
|**XCANPS_TXFIFO_DW1_OFFSET**  |0x00000038  |32    |rw    |0x00000000  | transmit message fifo data w |
+------------------------------+------------+------+------+------------+------------------------------+
|**XCANPS_TXFIFO_DW2_OFFSET**  |0x0000003c  |32    |rw    |0x00000000  | transmit message fifo data w |
+------------------------------+------------+------+------+------------+------------------------------+
|**XCANPS_TXHPB_ID_OFFSET**    |0x00000040  |32    |wo    |0x00000000  | transmit high priority buffe |
+------------------------------+------------+------+------+------------+------------------------------+
|**XCANPS_TXHPB_DLC_OFFSET**   |0x00000044  |32    |rw    |0x00000000  | transmit high priority buffe |
+------------------------------+------------+------+------+------------+------------------------------+
|**XCANPS_TXHPB_DW1_OFFSET**   |0x00000048  |32    |rw    |0x00000000  | transmit high priority buffe |
+------------------------------+------------+------+------+------------+------------------------------+
|**XCANPS_TXHPB_DW2_OFFSET**   |0x0000004c  |32    |rw    |0x00000000  | transmit high priority buffe |
+------------------------------+------------+------+------+------------+------------------------------+
|**XCANPS_RXFIFO_ID_OFFSET**   |0x00000050  |32    |ro    |0x00000000  | receive message fifo message |
+------------------------------+------------+------+------+------------+------------------------------+
|**XCANPS_RXFIFO_DLC_OFFSET**  |0x00000054  |32    |rw    |0x00000000  | receive message fifo data le |
+------------------------------+------------+------+------+------------+------------------------------+
|**XCANPS_RXFIFO_DW1_OFFSET**  |0x00000058  |32    |rw    |0x00000000  | receive message fifo data wo |
+------------------------------+------------+------+------+------------+------------------------------+
|**XCANPS_RXFIFO_DW2_OFFSET**  |0x0000005c  |32    |rw    |0x00000000  | receive message fifo data wo |
+------------------------------+------------+------+------+------------+------------------------------+
|**XCANPS_AFR_OFFSET**         |0x00000060  |32    |rw    |0x00000000  |Acceptance Filter Register    |
+------------------------------+------------+------+------+------------+------------------------------+
|**XCANPS_AFMR1_OFFSET**       |0x00000064  |32    |rw    |0x00000000  | Acceptance Filter Mask Regis |
+------------------------------+------------+------+------+------------+------------------------------+
|**XCANPS_AFIR1_OFFSET**       |0x00000068  |32    |rw    |0x00000000  | Acceptance Filter ID Registe |
+------------------------------+------------+------+------+------------+------------------------------+
|**XCANPS_AFMR2_OFFSET**       |0x0000006c  |32    |rw    |0x00000000  | Acceptance Filter Mask Regis |
+------------------------------+------------+------+------+------------+------------------------------+
|**XCANPS_AFIR2_OFFSET**       |0x00000070  |32    |rw    |0x00000000  | Acceptance Filter ID Registe |
+------------------------------+------------+------+------+------------+------------------------------+
|**XCANPS_AFMR3_OFFSET**       |0x00000074  |32    |rw    |0x00000000  | Acceptance Filter Mask Regis |
+------------------------------+------------+------+------+------------+------------------------------+
|**XCANPS_AFIR3_OFFSET**       |0x00000078  |32    |rw    |0x00000000  | Acceptance Filter ID Registe |
+------------------------------+------------+------+------+------------+------------------------------+
|**XCANPS_AFMR4_OFFSET**       |0x0000007c  |32    |rw    |0x00000000  | Acceptance Filter Mask Regis |
+------------------------------+------------+------+------+------------+------------------------------+
|**XCANPS_AFIR4_OFFSET**       |0x00000080  |32    |rw    |0x00000000  | Acceptance Filter ID Registe |
+------------------------------+------------+------+------+------------+------------------------------+

### XCANPS_SRR_OFFSET  

Relative Address = 0x00000000  
Width = 32 bits  
Access Type = rw  
Reset Value = 0x00000000  
Description Software Reset Register  


### XCANPS_MSR_OFFSET  

Relative Address = 0x00000004  
Width = 32 bits  
Access Type = rw  
Reset Value = 0x00000000  
Description Mode Select Register  


### XCANPS_BRPR_OFFSET  

Relative Address = 0x00000008  
Width = 32 bits  
Access Type = rw  
Reset Value = 0x00000000  
Description Baud Rate Prescaler Register  


### XCANPS_BTR_OFFSET  

Relative Address = 0x0000000c  
Width = 32 bits  
Access Type = rw  
Reset Value = 0x00000000  
Description Bit Timing Register  


### XCANPS_ECR_OFFSET  

Relative Address = 0x00000010  
Width = 32 bits  
Access Type = ro  
Reset Value = 0x00000000  
Description Error Counter Register  


### XCANPS_ESR_OFFSET  

Relative Address = 0x00000014  
Width = 32 bits  
Access Type = mixed  
Reset Value = 0x00000000  
Description Error Status Register  


### XCANPS_SR_OFFSET  

Relative Address = 0x00000018  
Width = 32 bits  
Access Type = mixed  
Reset Value = 0x00000001  
Description Status Register  


### XCANPS_ISR_OFFSET  

Relative Address = 0x0000001c  
Width = 32 bits  
Access Type = mixed  
Reset Value = 0x00006000  
Description Interrupt Status Register  


### XCANPS_IER_OFFSET  

Relative Address = 0x00000020  
Width = 32 bits  
Access Type = rw  
Reset Value = 0x00000000  
Description Interrupt Enable Register  


### XCANPS_ICR_OFFSET  

Relative Address = 0x00000024  
Width = 32 bits  
Access Type = mixed  
Reset Value = 0x00000000  
Description Interrupt Clear Register  


### XCANPS_TCR_OFFSET  

Relative Address = 0x00000028  
Width = 32 bits  
Access Type = mixed  
Reset Value = 0x00000000  
Description Timestamp Control Register  


### XCANPS_WIR_OFFSET  

Relative Address = 0x0000002c  
Width = 32 bits  
Access Type = rw  
Reset Value = 0x00003f3f  
Description Watermark Interrupt Register  


### XCANPS_TXFIFO_ID_OFFSET  

Relative Address = 0x00000030  
Width = 32 bits  
Access Type = wo  
Reset Value = 0x00000000  
Description transmit message fifo message identifier  


### XCANPS_TXFIFO_DLC_OFFSET  

Relative Address = 0x00000034  
Width = 32 bits  
Access Type = rw  
Reset Value = 0x00000000  
Description transmit message fifo data length code  


### XCANPS_TXFIFO_DW1_OFFSET  

Relative Address = 0x00000038  
Width = 32 bits  
Access Type = rw  
Reset Value = 0x00000000  
Description transmit message fifo data word 1  


### XCANPS_TXFIFO_DW2_OFFSET  

Relative Address = 0x0000003c  
Width = 32 bits  
Access Type = rw  
Reset Value = 0x00000000  
Description transmit message fifo data word 2  


### XCANPS_TXHPB_ID_OFFSET  

Relative Address = 0x00000040  
Width = 32 bits  
Access Type = wo  
Reset Value = 0x00000000  
Description transmit high priority buffer message identifier  


### XCANPS_TXHPB_DLC_OFFSET  

Relative Address = 0x00000044  
Width = 32 bits  
Access Type = rw  
Reset Value = 0x00000000  
Description transmit high priority buffer data length code  


### XCANPS_TXHPB_DW1_OFFSET  

Relative Address = 0x00000048  
Width = 32 bits  
Access Type = rw  
Reset Value = 0x00000000  
Description transmit high priority buffer data word 1  


### XCANPS_TXHPB_DW2_OFFSET  

Relative Address = 0x0000004c  
Width = 32 bits  
Access Type = rw  
Reset Value = 0x00000000  
Description transmit high priority buffer data word 2  


### XCANPS_RXFIFO_ID_OFFSET  

Relative Address = 0x00000050  
Width = 32 bits  
Access Type = ro  
Reset Value = 0x00000000  
Description receive message fifo message identifier  


### XCANPS_RXFIFO_DLC_OFFSET  

Relative Address = 0x00000054  
Width = 32 bits  
Access Type = rw  
Reset Value = 0x00000000  
Description receive message fifo data length code  


### XCANPS_RXFIFO_DW1_OFFSET  

Relative Address = 0x00000058  
Width = 32 bits  
Access Type = rw  
Reset Value = 0x00000000  
Description receive message fifo data word 1  


### XCANPS_RXFIFO_DW2_OFFSET  

Relative Address = 0x0000005c  
Width = 32 bits  
Access Type = rw  
Reset Value = 0x00000000  
Description receive message fifo data word 2  


### XCANPS_AFR_OFFSET  

Relative Address = 0x00000060  
Width = 32 bits  
Access Type = rw  
Reset Value = 0x00000000  
Description Acceptance Filter Register  


### XCANPS_AFMR1_OFFSET  

Relative Address = 0x00000064  
Width = 32 bits  
Access Type = rw  
Reset Value = 0x00000000  
Description Acceptance Filter Mask Register 1  


### XCANPS_AFIR1_OFFSET  

Relative Address = 0x00000068  
Width = 32 bits  
Access Type = rw  
Reset Value = 0x00000000  
Description Acceptance Filter ID Register 1  


### XCANPS_AFMR2_OFFSET  

Relative Address = 0x0000006c  
Width = 32 bits  
Access Type = rw  
Reset Value = 0x00000000  
Description Acceptance Filter Mask Register 2  


### XCANPS_AFIR2_OFFSET  

Relative Address = 0x00000070  
Width = 32 bits  
Access Type = rw  
Reset Value = 0x00000000  
Description Acceptance Filter ID Register 2  


### XCANPS_AFMR3_OFFSET  

Relative Address = 0x00000074  
Width = 32 bits  
Access Type = rw  
Reset Value = 0x00000000  
Description Acceptance Filter Mask Register 3  


### XCANPS_AFIR3_OFFSET  

Relative Address = 0x00000078  
Width = 32 bits  
Access Type = rw  
Reset Value = 0x00000000  
Description Acceptance Filter ID Register 3  


### XCANPS_AFMR4_OFFSET  

Relative Address = 0x0000007c  
Width = 32 bits  
Access Type = rw  
Reset Value = 0x00000000  
Description Acceptance Filter Mask Register 4  


### XCANPS_AFIR4_OFFSET  

Relative Address = 0x00000080  
Width = 32 bits  
Access Type = rw  
Reset Value = 0x00000000  
Description Acceptance Filter ID Register 4  

