SPDX-License-Identifier: MIT  
Auto-generated: Fri Sep 25 10:29:41 EEST 2020  

Dissy is a display chip for HDMI output.
Uses multiple clocks :
1 pixel clock of the display resolution.
2.Axi clock for the interface 
    

## Register Summary  

+------------------------------+------------+------+------+------------+------------------------------+
|Register Name                 |Address     |Width |Type  |Reset Value |Description                   |
+==============================+============+======+======+============+==============================+
|**COLOUR**                    |0x00000004  |32    |rw    |0x00000000  | 24 bit colour for background |
+------------------------------+------------+------+------+------------+------------------------------+
|**CTRL0**                     |0x00000000  |32    |rw    |0x00000000  | Parameter for the display ou |
+------------------------------+------------+------+------+------------+------------------------------+

### COLOUR  

Relative Address = 0x00000004  
Width = 32 bits  
Access Type = rw  
Reset Value = 0x00000000  
Description 24 bit colour for background/solid colour  


### CTRL0  

Relative Address = 0x00000000  
Width = 32 bits  
Access Type = rw  
Reset Value = 0x00000000  
Description Parameter for the display output  

