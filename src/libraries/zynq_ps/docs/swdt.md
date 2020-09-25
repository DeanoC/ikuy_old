# System Watchdog Timer  

Module System Watchdog Timer (swdt)  
SPDX-License-Identifier: MIT  
Auto-generated: Fri Sep 25 10:29:42 EEST 2020  

swdt Base Address = 0xf8005000  

## Register Summary  

+------------------------------+------------+------+------+------------+------------------------------+
|Register Name                 |Address     |Width |Type  |Reset Value |Description                   |
+==============================+============+======+======+============+==============================+
|**ZMR**                       |0x00000000  |24    |mixed |0x000001c0  |WD zero mode                  |
+------------------------------+------------+------+------+------------+------------------------------+
|**CCR**                       |0x00000004  |26    |mixed |0x00003ffc  |Counter Control               |
+------------------------------+------------+------+------+------------+------------------------------+
|**RESTART**                   |0x00000008  |16    |wo    |0x0000      |Restart key                   |
+------------------------------+------------+------+------+------------+------------------------------+
|**SR**                        |0x0000000c  |1     |ro    |0x00000000  |Status                        |
+------------------------------+------------+------+------+------------+------------------------------+

### ZMR  

Relative Address = 0x00000000  
Width = 24 bits  
Access Type = mixed  
Reset Value = 0x000001c0  
Description WD zero mode  


### CCR  

Relative Address = 0x00000004  
Width = 26 bits  
Access Type = mixed  
Reset Value = 0x00003ffc  
Description Counter Control  


### RESTART  

Relative Address = 0x00000008  
Width = 16 bits  
Access Type = wo  
Reset Value = 0x0000  
Description Restart key  


### SR  

Relative Address = 0x0000000c  
Width = 1 bits  
Access Type = ro  
Reset Value = 0x00000000  
Description Status  

