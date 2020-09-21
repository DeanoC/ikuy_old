# L2 Cache PL310  

Module L2 Cache PL310 (l2cache)  
SPDX-License-Identifier: MIT  
Auto-generated: Mon Sep 21 21:57:55 EEST 2020  

l2cache Base Address = 0xf8f02000  

## Register Summary  

+------------------------------+------------+------+------+------------+------------------------------+
|Register Name                 |Address     |Width |Type  |Reset Value |Description                   |
+==============================+============+======+======+============+==============================+
|**CACHE_ID**                  |0x00000000  |32    |mixed |0x410000c8  | cache ID register, Returns t |
+------------------------------+------------+------+------+------------+------------------------------+
|**CACHE_TYPE**                |0x00000004  |32    |mixed |0x00000000  | cache type register, Returns |
+------------------------------+------------+------+------+------------+------------------------------+
|**CONTROL**                   |0x00000100  |32    |mixed |0x00000000  |control register              |
+------------------------------+------------+------+------+------------+------------------------------+
|**AUX_CONTROL**               |0x00000104  |32    |mixed |0x02060000  |auxilary control register     |
+------------------------------+------------+------+------+------------+------------------------------+
|**TAG_RAM_CONTROL**           |0x00000108  |32    |mixed |0x00000777  |Configures Tag RAM latencies  |
+------------------------------+------------+------+------+------------+------------------------------+
|**DATA_RAM_CONTROL**          |0x0000010c  |32    |mixed |0x00000777  |configures data RAM latencies |
+------------------------------+------------+------+------+------------+------------------------------+
|**EV_COUNTER_CTRL**           |0x00000200  |32    |mixed |0x00000000  | Permits the event counters t |
+------------------------------+------------+------+------+------------+------------------------------+
|**EV_COUNTER1_CFG**           |0x00000204  |32    |mixed |0x00000000  | Enables event counter 1 to b |
+------------------------------+------------+------+------+------------+------------------------------+
|**EV_COUNTER0_CFG**           |0x00000208  |32    |mixed |0x00000000  | Enables event counter 0 to b |
+------------------------------+------------+------+------+------------+------------------------------+
|**EV_COUNTER1**               |0x0000020c  |32    |rw    |0x00000000  | Enable the programmer to rea |
+------------------------------+------------+------+------+------------+------------------------------+
|**EV_COUNTER0**               |0x00000210  |32    |rw    |0x00000000  | Enable the programmer to rea |
+------------------------------+------------+------+------+------------+------------------------------+
|**INT_MASK**                  |0x00000214  |32    |mixed |0x00000000  | Enables or masks interrupts  |
+------------------------------+------------+------+------+------------+------------------------------+
|**INT_MASK_STATUS**           |0x00000218  |32    |ro    |0x00000000  | It returns the masked interr |
+------------------------------+------------+------+------+------------+------------------------------+
|**INT_RAW_STATUS**            |0x0000021c  |32    |mixed |0x00000000  | The Raw Interrupt Status Reg |
+------------------------------+------------+------+------+------------+------------------------------+
|**INT_CLEAR**                 |0x00000220  |32    |mixed |0x00000000  | Clears the Raw Interrupt Sta |
+------------------------------+------------+------+------+------------+------------------------------+
|**CACHE_SYNC**                |0x00000730  |32    |mixed |0x00000000  | Drain the STB. Operation com |
+------------------------------+------------+------+------+------------+------------------------------+
|**INV_PA**                    |0x00000770  |32    |mixed |0x00000000  | Invalidate Line by PA: Speci |
+------------------------------+------------+------+------+------------+------------------------------+
|**INV_WAY**                   |0x0000077c  |32    |mixed |0x00000000  | Invalidate by Way Invalidate |
+------------------------------+------------+------+------+------------+------------------------------+
|**CLEAN_PA**                  |0x000007b0  |32    |mixed |0x00000000  | Clean Line by PA Write the s |
+------------------------------+------------+------+------+------------+------------------------------+
|**CLEAN_INDEX**               |0x000007b8  |32    |mixed |0x00000000  | Clean Line by Set/Way Write  |
+------------------------------+------------+------+------+------------+------------------------------+
|**CLEAN_WAY**                 |0x000007bc  |32    |mixed |0x00000000  | Clean by Way Writes each lin |
+------------------------------+------------+------+------+------------+------------------------------+
|**CLEAN_INV_PA**              |0x000007f0  |32    |mixed |0x00000000  | Clean and Invalidate Line by |
+------------------------------+------------+------+------+------------+------------------------------+
|**CLEAN_INV_INDEX**           |0x000007f8  |32    |mixed |0x00000000  | Clean and Invalidate Line by |
+------------------------------+------------+------+------+------------+------------------------------+
|**CLEAN_INV_WAY**             |0x000007fc  |32    |mixed |0x00000000  | Clean and Invalidate by Way  |
+------------------------------+------------+------+------+------------+------------------------------+
|**DATA_LOCKDOWN0**            |0x00000900  |32    |mixed |0x00000000  | All Lockdown registers can p |
+------------------------------+------------+------+------+------------+------------------------------+
|**INST_LOCKDOWN0**            |0x00000904  |32    |mixed |0x00000000  |Instruction lock down 0       |
+------------------------------+------------+------+------+------------+------------------------------+
|**INST_LOCKDOWN1**            |0x0000090c  |32    |mixed |0x00000000  |instruction lock down 1       |
+------------------------------+------------+------+------+------------+------------------------------+
|**INST_LOCKDOWN1**            |0x0000090c  |32    |mixed |0x00000000  |instruction lock down 1       |
+------------------------------+------------+------+------+------------+------------------------------+
|**DATA_LOCKDOWN2**            |0x00000910  |32    |mixed |0x00000000  |data lock down 2              |
+------------------------------+------------+------+------+------------+------------------------------+
|**INST_LOCKDOWN2**            |0x00000914  |32    |mixed |0x00000000  |instruction lock down 2       |
+------------------------------+------------+------+------+------------+------------------------------+
|**DATA_LOCKDOWN3**            |0x00000918  |32    |mixed |0x00000000  |data lock down 3              |
+------------------------------+------------+------+------+------------+------------------------------+
|**INST_LOCKDOWN3**            |0x0000091c  |32    |mixed |0x00000000  |instruction lock down 3       |
+------------------------------+------------+------+------+------------+------------------------------+
|**DATA_LOCKDOWN4**            |0x00000920  |32    |mixed |0x00000000  |data lock down 4              |
+------------------------------+------------+------+------+------------+------------------------------+
|**INST_LOCKDOWN4**            |0x00000924  |32    |mixed |0x00000000  |instruction lock down 4       |
+------------------------------+------------+------+------+------------+------------------------------+
|**DATA_LOCKDOWN5**            |0x00000928  |32    |mixed |0x00000000  |data lock down 5              |
+------------------------------+------------+------+------+------------+------------------------------+
|**INST_LOCKDOWN5**            |0x0000092c  |32    |mixed |0x00000000  |instruction lock down 5       |
+------------------------------+------------+------+------+------------+------------------------------+
|**DATA_LOCKDOWN6**            |0x00000930  |32    |mixed |0x00000000  |data lock down 6              |
+------------------------------+------------+------+------+------------+------------------------------+
|**INST_LOCKDOWN6**            |0x00000934  |32    |mixed |0x00000000  |instruction lock down 6       |
+------------------------------+------------+------+------+------------+------------------------------+
|**DATA_LOCKDOWN7**            |0x00000938  |32    |mixed |0x00000000  |data lock down 7              |
+------------------------------+------------+------+------+------------+------------------------------+
|**INST_LOCKDOWN7**            |0x0000093c  |32    |mixed |0x00000000  |instruction lock down 7       |
+------------------------------+------------+------+------+------------+------------------------------+
|**LOCK_LINE_EN**              |0x00000950  |32    |mixed |0x00000000  |Lockdown by Line Enable       |
+------------------------------+------------+------+------+------------+------------------------------+
|**UNLOCK_WAY**                |0x00000954  |32    |mixed |0x00000000  |Cache lockdown by way         |
+------------------------------+------------+------+------+------------+------------------------------+
|**ADDR_FILTERING_START**      |0x00000c00  |32    |mixed |0x40000001  | Redirect a whole address ran |
+------------------------------+------------+------+------+------------+------------------------------+
|**ADDR_FILTERING_END**        |0x00000c04  |32    |mixed |0x00000000  | Redirect a whole address ran |
+------------------------------+------------+------+------+------------+------------------------------+
|**DEBUG_CTRL**                |0x00000f40  |32    |mixed |0x00000000  | The Debug Control Register f |
+------------------------------+------------+------+------+------------+------------------------------+
|**PREFETCH_CTRL**             |0x00000f60  |32    |mixed |0x00000000  | Purpose Enables prefetch-rel |
+------------------------------+------------+------+------+------------+------------------------------+
|**POWER_CTRL**                |0x00000f80  |32    |mixed |0x00000000  | Purpose Controls the operati |
+------------------------------+------------+------+------+------------+------------------------------+

### CACHE_ID  

Relative Address = 0x00000000  
Width = 32 bits  
Access Type = mixed  
Reset Value = 0x410000c8  
Description cache ID register, Returns the 32-bit device ID code it reads off the CACHEID input bus.  


### CACHE_TYPE  

Relative Address = 0x00000004  
Width = 32 bits  
Access Type = mixed  
Reset Value = 0x00000000  
Description cache type register, Returns the 32-bit cache type.  


### CONTROL  

Relative Address = 0x00000100  
Width = 32 bits  
Access Type = mixed  
Reset Value = 0x00000000  
Description control register  


### AUX_CONTROL  

Relative Address = 0x00000104  
Width = 32 bits  
Access Type = mixed  
Reset Value = 0x02060000  
Description auxilary control register  


### TAG_RAM_CONTROL  

Relative Address = 0x00000108  
Width = 32 bits  
Access Type = mixed  
Reset Value = 0x00000777  
Description Configures Tag RAM latencies  


### DATA_RAM_CONTROL  

Relative Address = 0x0000010c  
Width = 32 bits  
Access Type = mixed  
Reset Value = 0x00000777  
Description configures data RAM latencies  


### EV_COUNTER_CTRL  

Relative Address = 0x00000200  
Width = 32 bits  
Access Type = mixed  
Reset Value = 0x00000000  
Description Permits the event counters to beenabled and reset.  


### EV_COUNTER1_CFG  

Relative Address = 0x00000204  
Width = 32 bits  
Access Type = mixed  
Reset Value = 0x00000000  
Description Enables event counter 1 to be driven by a specific event.  


### EV_COUNTER0_CFG  

Relative Address = 0x00000208  
Width = 32 bits  
Access Type = mixed  
Reset Value = 0x00000000  
Description Enables event counter 0 to be driven by a specific event.  


### EV_COUNTER1  

Relative Address = 0x0000020c  
Width = 32 bits  
Access Type = rw  
Reset Value = 0x00000000  
Description Enable the programmer to read off the counter value.  


### EV_COUNTER0  

Relative Address = 0x00000210  
Width = 32 bits  
Access Type = rw  
Reset Value = 0x00000000  
Description Enable the programmer to read off the counter value.  


### INT_MASK  

Relative Address = 0x00000214  
Width = 32 bits  
Access Type = mixed  
Reset Value = 0x00000000  
Description Enables or masks interrupts from being triggered on the external pins of the cache controller.  


### INT_MASK_STATUS  

Relative Address = 0x00000218  
Width = 32 bits  
Access Type = ro  
Reset Value = 0x00000000  
Description It returns the masked interrupt status.  


### INT_RAW_STATUS  

Relative Address = 0x0000021c  
Width = 32 bits  
Access Type = mixed  
Reset Value = 0x00000000  
Description The Raw Interrupt Status Register enables the interrupt status that excludes the masking logic.  


### INT_CLEAR  

Relative Address = 0x00000220  
Width = 32 bits  
Access Type = mixed  
Reset Value = 0x00000000  
Description Clears the Raw Interrupt Status Register bits.  


### CACHE_SYNC  

Relative Address = 0x00000730  
Width = 32 bits  
Access Type = mixed  
Reset Value = 0x00000000  
Description Drain the STB. Operation complete when all buffers, LRB, LFB, STB, and EB, are empty  


### INV_PA  

Relative Address = 0x00000770  
Width = 32 bits  
Access Type = mixed  
Reset Value = 0x00000000  
Description Invalidate Line by PA: Specific L2 cache line is marked as not valid  


### INV_WAY  

Relative Address = 0x0000077c  
Width = 32 bits  
Access Type = mixed  
Reset Value = 0x00000000  
Description Invalidate by Way Invalidate all data in specified ways, including dirty data.  


### CLEAN_PA  

Relative Address = 0x000007b0  
Width = 32 bits  
Access Type = mixed  
Reset Value = 0x00000000  
Description Clean Line by PA Write the specific L2 cache line to L3 main memory if the line is marked as valid and dirty  


### CLEAN_INDEX  

Relative Address = 0x000007b8  
Width = 32 bits  
Access Type = mixed  
Reset Value = 0x00000000  
Description Clean Line by Set/Way Write the specific L2 cache line within the specified way to L3 main memory if the line is marked as valid and dirty.  


### CLEAN_WAY  

Relative Address = 0x000007bc  
Width = 32 bits  
Access Type = mixed  
Reset Value = 0x00000000  
Description Clean by Way Writes each line of the specified L2 cache ways to L3 main memory if the line is marked as valid and dirty  


### CLEAN_INV_PA  

Relative Address = 0x000007f0  
Width = 32 bits  
Access Type = mixed  
Reset Value = 0x00000000  
Description Clean and Invalidate Line by PA Write the specific L2 cache line to L3 main memory if the line is marked as valid and dirty.  


### CLEAN_INV_INDEX  

Relative Address = 0x000007f8  
Width = 32 bits  
Access Type = mixed  
Reset Value = 0x00000000  
Description Clean and Invalidate Line by Set/Way Write the specific L2 cache line within the specified way to L3 main memory if the line is marked as valid and dirty.  


### CLEAN_INV_WAY  

Relative Address = 0x000007fc  
Width = 32 bits  
Access Type = mixed  
Reset Value = 0x00000000  
Description Clean and Invalidate by Way Writes each line of the specified L2 cache ways to L3 main memory if the line is marked as valid and dirty.  


### DATA_LOCKDOWN0  

Relative Address = 0x00000900  
Width = 32 bits  
Access Type = mixed  
Reset Value = 0x00000000  
Description All Lockdown registers can prevent new addresses from being allocated and can also prevent data from being evicted out of the L2 cache.  


### INST_LOCKDOWN0  

Relative Address = 0x00000904  
Width = 32 bits  
Access Type = mixed  
Reset Value = 0x00000000  
Description Instruction lock down 0  


### INST_LOCKDOWN1  

Relative Address = 0x0000090c  
Width = 32 bits  
Access Type = mixed  
Reset Value = 0x00000000  
Description instruction lock down 1  


### INST_LOCKDOWN1  

Relative Address = 0x0000090c  
Width = 32 bits  
Access Type = mixed  
Reset Value = 0x00000000  
Description instruction lock down 1  


### DATA_LOCKDOWN2  

Relative Address = 0x00000910  
Width = 32 bits  
Access Type = mixed  
Reset Value = 0x00000000  
Description data lock down 2  


### INST_LOCKDOWN2  

Relative Address = 0x00000914  
Width = 32 bits  
Access Type = mixed  
Reset Value = 0x00000000  
Description instruction lock down 2  


### DATA_LOCKDOWN3  

Relative Address = 0x00000918  
Width = 32 bits  
Access Type = mixed  
Reset Value = 0x00000000  
Description data lock down 3  


### INST_LOCKDOWN3  

Relative Address = 0x0000091c  
Width = 32 bits  
Access Type = mixed  
Reset Value = 0x00000000  
Description instruction lock down 3  


### DATA_LOCKDOWN4  

Relative Address = 0x00000920  
Width = 32 bits  
Access Type = mixed  
Reset Value = 0x00000000  
Description data lock down 4  


### INST_LOCKDOWN4  

Relative Address = 0x00000924  
Width = 32 bits  
Access Type = mixed  
Reset Value = 0x00000000  
Description instruction lock down 4  


### DATA_LOCKDOWN5  

Relative Address = 0x00000928  
Width = 32 bits  
Access Type = mixed  
Reset Value = 0x00000000  
Description data lock down 5  


### INST_LOCKDOWN5  

Relative Address = 0x0000092c  
Width = 32 bits  
Access Type = mixed  
Reset Value = 0x00000000  
Description instruction lock down 5  


### DATA_LOCKDOWN6  

Relative Address = 0x00000930  
Width = 32 bits  
Access Type = mixed  
Reset Value = 0x00000000  
Description data lock down 6  


### INST_LOCKDOWN6  

Relative Address = 0x00000934  
Width = 32 bits  
Access Type = mixed  
Reset Value = 0x00000000  
Description instruction lock down 6  


### DATA_LOCKDOWN7  

Relative Address = 0x00000938  
Width = 32 bits  
Access Type = mixed  
Reset Value = 0x00000000  
Description data lock down 7  


### INST_LOCKDOWN7  

Relative Address = 0x0000093c  
Width = 32 bits  
Access Type = mixed  
Reset Value = 0x00000000  
Description instruction lock down 7  


### LOCK_LINE_EN  

Relative Address = 0x00000950  
Width = 32 bits  
Access Type = mixed  
Reset Value = 0x00000000  
Description Lockdown by Line Enable  


### UNLOCK_WAY  

Relative Address = 0x00000954  
Width = 32 bits  
Access Type = mixed  
Reset Value = 0x00000000  
Description Cache lockdown by way  


### ADDR_FILTERING_START  

Relative Address = 0x00000c00  
Width = 32 bits  
Access Type = mixed  
Reset Value = 0x40000001  
Description Redirect a whole address range to master 1 (M1)  


### ADDR_FILTERING_END  

Relative Address = 0x00000c04  
Width = 32 bits  
Access Type = mixed  
Reset Value = 0x00000000  
Description Redirect a whole address range to master 1 (M1)  


### DEBUG_CTRL  

Relative Address = 0x00000f40  
Width = 32 bits  
Access Type = mixed  
Reset Value = 0x00000000  
Description The Debug Control Register forces specific cache behavior required for debug.  


### PREFETCH_CTRL  

Relative Address = 0x00000f60  
Width = 32 bits  
Access Type = mixed  
Reset Value = 0x00000000  
Description Purpose Enables prefetch-related features that can improve system performance.  


### POWER_CTRL  

Relative Address = 0x00000f80  
Width = 32 bits  
Access Type = mixed  
Reset Value = 0x00000000  
Description Purpose Controls the operating mode clock and power modes.  

