# Triple Timer Counter  

Module Triple Timer Counter (ttc)  
SPDX-License-Identifier: MIT  
Auto-generated: Fri Sep 25 10:29:42 EEST 2020  

ttc0 Base Address = 0xf8001000  
ttc1 Base Address = 0xf8002000  

## Register Summary  

+------------------------------+------------+------+------+------------+------------------------------+
|Register Name                 |Address     |Width |Type  |Reset Value |Description                   |
+==============================+============+======+======+============+==============================+
|**CLK_CNTRL_0**               |0x00000000  |7     |rw    |0x00000000  |Clock Control register        |
+------------------------------+------------+------+------+------------+------------------------------+
|**CLK_CNTRL_1**               |0x00000004  |7     |rw    |0x00000000  |Clock Control register        |
+------------------------------+------------+------+------+------------+------------------------------+
|**CLK_CNTRL_2**               |0x00000008  |7     |rw    |0x00000000  |Clock Control register        |
+------------------------------+------------+------+------+------------+------------------------------+
|**CNT_CNTRL_0**               |0x0000000c  |7     |rw    |0x00000021  |Operational mode and reset    |
+------------------------------+------------+------+------+------------+------------------------------+
|**CNT_CNTRL_1**               |0x00000010  |7     |rw    |0x00000021  |Operational mode and reset    |
+------------------------------+------------+------+------+------------+------------------------------+
|**CNT_CNTRL_2**               |0x00000014  |7     |rw    |0x00000021  |Operational mode and reset    |
+------------------------------+------------+------+------+------------+------------------------------+
|**CNT_0**                     |0x00000018  |16    |ro    |0x0000      |Current counter value         |
+------------------------------+------------+------+------+------------+------------------------------+
|**CNT_1**                     |0x0000001c  |16    |ro    |0x0000      |Current counter value         |
+------------------------------+------------+------+------+------------+------------------------------+
|**CNT_2**                     |0x00000020  |16    |ro    |0x0000      |Current counter value         |
+------------------------------+------------+------+------+------------+------------------------------+
|**INTERVAL_0**                |0x00000024  |16    |rw    |0x0000      |Interval value                |
+------------------------------+------------+------+------+------------+------------------------------+
|**INTERVAL_1**                |0x00000028  |16    |rw    |0x0000      |Interval value                |
+------------------------------+------------+------+------+------------+------------------------------+
|**INTERVAL_2**                |0x0000002c  |16    |rw    |0x0000      |Interval value                |
+------------------------------+------------+------+------+------------+------------------------------+
|**MATCH_0_CNT_0**             |0x00000030  |16    |rw    |0x0000      |Match value                   |
+------------------------------+------------+------+------+------------+------------------------------+
|**MATCH_0_CNT_1**             |0x00000034  |16    |rw    |0x0000      |Match value                   |
+------------------------------+------------+------+------+------------+------------------------------+
|**MATCH_0_CNT_2**             |0x00000038  |16    |rw    |0x0000      |Match value                   |
+------------------------------+------------+------+------+------------+------------------------------+
|**MATCH_1_CNT_0**             |0x0000003c  |16    |rw    |0x0000      |Match value                   |
+------------------------------+------------+------+------+------------+------------------------------+
|**MATCH_1_CNT_1**             |0x00000040  |16    |rw    |0x0000      |Match value                   |
+------------------------------+------------+------+------+------------+------------------------------+
|**MATCH_1_CNT_2**             |0x00000044  |16    |rw    |0x0000      |Match value                   |
+------------------------------+------------+------+------+------------+------------------------------+
|**MATCH_2_CNT_0**             |0x00000048  |16    |rw    |0x0000      |Match value                   |
+------------------------------+------------+------+------+------------+------------------------------+
|**MATCH_2_CNT_1**             |0x0000004c  |16    |rw    |0x0000      |Match value                   |
+------------------------------+------------+------+------+------------+------------------------------+
|**MATCH_2_CNT_2**             |0x00000050  |16    |rw    |0x0000      |Match value                   |
+------------------------------+------------+------+------+------------+------------------------------+
|**ISR_0**                     |0x00000054  |6     | clro |0x00000000  | Counter 1 Interval, Match, O |
+------------------------------+------------+------+------+------------+------------------------------+
|**ISR_1**                     |0x00000058  |6     | clro |0x00000000  | Counter 2 Interval, Match, O |
+------------------------------+------------+------+------+------------+------------------------------+
|**ISR_2**                     |0x0000005c  |6     | clro |0x00000000  | Counter 3 Interval, Match, O |
+------------------------------+------------+------+------+------------+------------------------------+
|**IER_0**                     |0x00000060  |6     |rw    |0x00000000  | ANDed with corresponding Int |
+------------------------------+------------+------+------+------------+------------------------------+
|**IER_1**                     |0x00000064  |6     |rw    |0x00000000  | ANDed with corresponding Int |
+------------------------------+------------+------+------+------------+------------------------------+
|**IER_2**                     |0x00000068  |6     |rw    |0x00000000  | ANDed with corresponding Int |
+------------------------------+------------+------+------+------------+------------------------------+
|**EVENT_TIMER_0**             |0x0000006c  |3     |rw    |0x00000000  |Enable, pulse and overflow    |
+------------------------------+------------+------+------+------------+------------------------------+
|**EVENT_TIMER_1**             |0x00000070  |3     |rw    |0x00000000  |Enable, pulse and overflow    |
+------------------------------+------------+------+------+------------+------------------------------+
|**EVENT_TIMER_2**             |0x00000074  |3     |rw    |0x00000000  |Enable, pulse and overflow    |
+------------------------------+------------+------+------+------------+------------------------------+
|**EVENT_0**                   |0x00000078  |16    |ro    |0x0000      |pclk cycle count for event    |
+------------------------------+------------+------+------+------------+------------------------------+
|**EVENT_1**                   |0x0000007c  |16    |ro    |0x0000      |pclk cycle count for event    |
+------------------------------+------------+------+------+------------+------------------------------+
|**EVENT_2**                   |0x00000080  |16    |ro    |0x0000      |pclk cycle count for event    |
+------------------------------+------------+------+------+------------+------------------------------+

### CLK_CNTRL_0  

Relative Address = 0x00000000  
Width = 7 bits  
Access Type = rw  
Reset Value = 0x00000000  
Description Clock Control register  


### CLK_CNTRL_1  

Relative Address = 0x00000004  
Width = 7 bits  
Access Type = rw  
Reset Value = 0x00000000  
Description Clock Control register  


### CLK_CNTRL_2  

Relative Address = 0x00000008  
Width = 7 bits  
Access Type = rw  
Reset Value = 0x00000000  
Description Clock Control register  


### CNT_CNTRL_0  

Relative Address = 0x0000000c  
Width = 7 bits  
Access Type = rw  
Reset Value = 0x00000021  
Description Operational mode and reset  


### CNT_CNTRL_1  

Relative Address = 0x00000010  
Width = 7 bits  
Access Type = rw  
Reset Value = 0x00000021  
Description Operational mode and reset  


### CNT_CNTRL_2  

Relative Address = 0x00000014  
Width = 7 bits  
Access Type = rw  
Reset Value = 0x00000021  
Description Operational mode and reset  


### CNT_0  

Relative Address = 0x00000018  
Width = 16 bits  
Access Type = ro  
Reset Value = 0x0000  
Description Current counter value  


### CNT_1  

Relative Address = 0x0000001c  
Width = 16 bits  
Access Type = ro  
Reset Value = 0x0000  
Description Current counter value  


### CNT_2  

Relative Address = 0x00000020  
Width = 16 bits  
Access Type = ro  
Reset Value = 0x0000  
Description Current counter value  


### INTERVAL_0  

Relative Address = 0x00000024  
Width = 16 bits  
Access Type = rw  
Reset Value = 0x0000  
Description Interval value  


### INTERVAL_1  

Relative Address = 0x00000028  
Width = 16 bits  
Access Type = rw  
Reset Value = 0x0000  
Description Interval value  


### INTERVAL_2  

Relative Address = 0x0000002c  
Width = 16 bits  
Access Type = rw  
Reset Value = 0x0000  
Description Interval value  


### MATCH_0_CNT_0  

Relative Address = 0x00000030  
Width = 16 bits  
Access Type = rw  
Reset Value = 0x0000  
Description Match value  


### MATCH_0_CNT_1  

Relative Address = 0x00000034  
Width = 16 bits  
Access Type = rw  
Reset Value = 0x0000  
Description Match value  


### MATCH_0_CNT_2  

Relative Address = 0x00000038  
Width = 16 bits  
Access Type = rw  
Reset Value = 0x0000  
Description Match value  


### MATCH_1_CNT_0  

Relative Address = 0x0000003c  
Width = 16 bits  
Access Type = rw  
Reset Value = 0x0000  
Description Match value  


### MATCH_1_CNT_1  

Relative Address = 0x00000040  
Width = 16 bits  
Access Type = rw  
Reset Value = 0x0000  
Description Match value  


### MATCH_1_CNT_2  

Relative Address = 0x00000044  
Width = 16 bits  
Access Type = rw  
Reset Value = 0x0000  
Description Match value  


### MATCH_2_CNT_0  

Relative Address = 0x00000048  
Width = 16 bits  
Access Type = rw  
Reset Value = 0x0000  
Description Match value  


### MATCH_2_CNT_1  

Relative Address = 0x0000004c  
Width = 16 bits  
Access Type = rw  
Reset Value = 0x0000  
Description Match value  


### MATCH_2_CNT_2  

Relative Address = 0x00000050  
Width = 16 bits  
Access Type = rw  
Reset Value = 0x0000  
Description Match value  


### ISR_0  

Relative Address = 0x00000054  
Width = 6 bits  
Access Type = clronrd  
Reset Value = 0x00000000  
Description Counter 1 Interval, Match, Overflow and Event interrupts  


### ISR_1  

Relative Address = 0x00000058  
Width = 6 bits  
Access Type = clronrd  
Reset Value = 0x00000000  
Description Counter 2 Interval, Match, Overflow and Event interrupts  


### ISR_2  

Relative Address = 0x0000005c  
Width = 6 bits  
Access Type = clronrd  
Reset Value = 0x00000000  
Description Counter 3 Interval, Match, Overflow and Event interrupts  


### IER_0  

Relative Address = 0x00000060  
Width = 6 bits  
Access Type = rw  
Reset Value = 0x00000000  
Description ANDed with corresponding Interrupt  


### IER_1  

Relative Address = 0x00000064  
Width = 6 bits  
Access Type = rw  
Reset Value = 0x00000000  
Description ANDed with corresponding Interrupt  


### IER_2  

Relative Address = 0x00000068  
Width = 6 bits  
Access Type = rw  
Reset Value = 0x00000000  
Description ANDed with corresponding Interrupt  


### EVENT_TIMER_0  

Relative Address = 0x0000006c  
Width = 3 bits  
Access Type = rw  
Reset Value = 0x00000000  
Description Enable, pulse and overflow  


### EVENT_TIMER_1  

Relative Address = 0x00000070  
Width = 3 bits  
Access Type = rw  
Reset Value = 0x00000000  
Description Enable, pulse and overflow  


### EVENT_TIMER_2  

Relative Address = 0x00000074  
Width = 3 bits  
Access Type = rw  
Reset Value = 0x00000000  
Description Enable, pulse and overflow  


### EVENT_0  

Relative Address = 0x00000078  
Width = 16 bits  
Access Type = ro  
Reset Value = 0x0000  
Description pclk cycle count for event  


### EVENT_1  

Relative Address = 0x0000007c  
Width = 16 bits  
Access Type = ro  
Reset Value = 0x0000  
Description pclk cycle count for event  


### EVENT_2  

Relative Address = 0x00000080  
Width = 16 bits  
Access Type = ro  
Reset Value = 0x0000  
Description pclk cycle count for event  

