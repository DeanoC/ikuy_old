SPDX-License-Identifier: MIT  
Auto-generated: Mon Sep 21 19:32:27 EEST 2020  

A test chip that is used to check bus is working okay.
Provides 2 registers, one that can store a 32 bit value
and the other which returns a constant that is the local
address of the register (0x4) currently

## Register Summary  

+------------------------------+------------+------+------+------------+------------------------------+
|Register Name                 |Address     |Width |Type  |Reset Value |Description                   |
+==============================+============+======+======+============+==============================+
|**Test0**                     |0x00000000  |32    |rw    |0xdcdcdcdc  | A 32 bit R/W register to tes |
+------------------------------+------------+------+------+------------+------------------------------+
|**Reflect1**                  |0x00000004  |32    |ro    |0x00000000  | Returns the address of this  |
+------------------------------+------------+------+------+------------+------------------------------+

### Test0  

Relative Address = 0x00000000  
Width = 32 bits  
Access Type = rw  
Reset Value = 0xdcdcdcdc  
Description A 32 bit R/W register to test bus is working  


### Reflect1  

Relative Address = 0x00000004  
Width = 32 bits  
Access Type = ro  
Reset Value = 0x00000000  
Description Returns the address of this register  

