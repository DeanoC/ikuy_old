# Gigabit Ethernet Controller  

Module Gigabit Ethernet Controller (gem)  
SPDX-License-Identifier: MIT  
Auto-generated: Mon Sep 21 19:32:28 EEST 2020  

gem0 Base Address = 0xe000b000  
gem1 Base Address = 0xe000c000  

## Register Summary  

+------------------------------+------------+------+------+------------+------------------------------+
|Register Name                 |Address     |Width |Type  |Reset Value |Description                   |
+==============================+============+======+======+============+==============================+
|**NWCTRL**                    |0x00000000  |32    |mixed |0x00000000  |Network Control               |
+------------------------------+------------+------+------+------------+------------------------------+
|**NWCFG**                     |0x00000004  |32    |rw    |0x00080000  |Network Configuration         |
+------------------------------+------------+------+------+------------+------------------------------+
|**NWSR**                      |0x00000008  |32    |ro    |0x00000000  |Network Status                |
+------------------------------+------------+------+------+------------+------------------------------+
|**DMACR**                     |0x00000010  |32    |mixed |0x00020784  |DMA Configuration             |
+------------------------------+------------+------+------+------------+------------------------------+
|**TXSR**                      |0x00000014  |32    |mixed |0x00000000  |Transmit Status               |
+------------------------------+------------+------+------+------------+------------------------------+
|**RXQBASE**                   |0x00000018  |32    |mixed |0x00000000  | Receive Buffer Queue Base Ad |
+------------------------------+------------+------+------+------------+------------------------------+
|**TXQBASE**                   |0x0000001c  |32    |mixed |0x00000000  | Transmit Buffer Queue Base A |
+------------------------------+------------+------+------+------------+------------------------------+
|**RXSR**                      |0x00000020  |32    |mixed |0x00000000  |Receive Status                |
+------------------------------+------------+------+------+------------+------------------------------+
|**ISR**                       |0x00000024  |32    |mixed |0x00000000  |Interrupt Status              |
+------------------------------+------------+------+------+------------+------------------------------+
|**IER**                       |0x00000028  |32    |wo    |0x00000000  |Interrupt Enable              |
+------------------------------+------------+------+------+------------+------------------------------+
|**IDR**                       |0x0000002c  |32    |wo    |0x00000000  |Interrupt Disable             |
+------------------------------+------------+------+------+------------+------------------------------+
|**IMR**                       |0x00000030  |32    |mixed |0x00000000  |Interrupt Mask Status         |
+------------------------------+------------+------+------+------------+------------------------------+
|**PHYMNTNC**                  |0x00000034  |32    |rw    |0x00000000  |PHY Maintenance               |
+------------------------------+------------+------+------+------------+------------------------------+
|**RXPAUSE**                   |0x00000038  |32    |ro    |0x00000000  |Received Pause Quantum        |
+------------------------------+------------+------+------+------------+------------------------------+
|**TXPAUSE**                   |0x0000003c  |32    |rw    |0x0000ffff  |Transmit Pause Quantum        |
+------------------------------+------------+------+------+------------+------------------------------+
|**HASHL**                     |0x00000080  |32    |rw    |0x00000000  |Hash Register Bottom [31:0]   |
+------------------------------+------------+------+------+------------+------------------------------+
|**HASHH**                     |0x00000084  |32    |rw    |0x00000000  |Hash Register Top [63:32]     |
+------------------------------+------------+------+------+------------+------------------------------+
|**LADDR1L**                   |0x00000088  |32    |rw    |0x00000000  | Specific Address 1 Bottom [3 |
+------------------------------+------------+------+------+------------+------------------------------+
|**LADDR1H**                   |0x0000008c  |32    |mixed |0x00000000  | Specific Address 1 Top [47:3 |
+------------------------------+------------+------+------+------------+------------------------------+
|**LADDR2L**                   |0x00000090  |32    |rw    |0x00000000  | Specific Address 2 Bottom [3 |
+------------------------------+------------+------+------+------------+------------------------------+
|**LADDR2H**                   |0x00000094  |32    |mixed |0x00000000  | Specific Address 2 Top [47:3 |
+------------------------------+------------+------+------+------------+------------------------------+
|**LADDR3L**                   |0x00000098  |32    |rw    |0x00000000  | Specific Address 3 Bottom [3 |
+------------------------------+------------+------+------+------------+------------------------------+
|**LADDR3H**                   |0x0000009c  |32    |mixed |0x00000000  | Specific Address 3 Top [47:3 |
+------------------------------+------------+------+------+------------+------------------------------+
|**LADDR4L**                   |0x000000a0  |32    |rw    |0x00000000  | Specific Address 4 Bottom [3 |
+------------------------------+------------+------+------+------------+------------------------------+
|**LADDR4H**                   |0x000000a4  |32    |mixed |0x00000000  | Specific Address 4 Top [47:3 |
+------------------------------+------------+------+------+------------+------------------------------+
|**MATCH1**                    |0x000000a8  |32    |mixed |0x00000000  |Type ID Match 1               |
+------------------------------+------------+------+------+------------+------------------------------+
|**MATCH2**                    |0x000000ac  |32    |mixed |0x00000000  |Type ID Match 2               |
+------------------------------+------------+------+------+------------+------------------------------+
|**MATCH3**                    |0x000000b0  |32    |mixed |0x00000000  |Type ID Match 3               |
+------------------------------+------------+------+------+------------+------------------------------+
|**MATCH4**                    |0x000000b4  |32    |mixed |0x00000000  |Type ID Match 4               |
+------------------------------+------------+------+------+------------+------------------------------+
|**WAKE_ON_LAN**               |0x000000b8  |32    |mixed |0x00000000  |Wake on LAN Register          |
+------------------------------+------------+------+------+------------+------------------------------+
|**STRETCH**                   |0x000000bc  |32    |mixed |0x00000000  |IPG stretch register          |
+------------------------------+------------+------+------+------------+------------------------------+
|**STACKED_VLAN**              |0x000000c0  |32    |mixed |0x00000000  |Stacked VLAN Register         |
+------------------------------+------------+------+------+------------+------------------------------+
|**TX_PFC_PAUSE**              |0x000000c4  |32    |mixed |0x00000000  |Transmit PFC Pause Register   |
+------------------------------+------------+------+------+------------+------------------------------+
|**SPEC_ADDR1_MASK_BOT**       |0x000000c8  |32    |rw    |0x00000000  | Specific Address Mask 1 Bott |
+------------------------------+------------+------+------+------------+------------------------------+
|**SPEC_ADDR1_MASK_TOP**       |0x000000cc  |32    |mixed |0x00000000  | Specific Address Mask 1 Top  |
+------------------------------+------------+------+------+------------+------------------------------+
|**MODULE_ID**                 |0x000000fc  |32    |ro    |0x00020118  |Module ID                     |
+------------------------------+------------+------+------+------------+------------------------------+
|**OCTTXL**                    |0x00000100  |32    |ro    |0x00000000  | Octets transmitted [31:0] (i |
+------------------------------+------------+------+------+------------+------------------------------+
|**OCTTXH**                    |0x00000104  |32    |ro    |0x00000000  | Octets transmitted [47:32] ( |
+------------------------------+------------+------+------+------------+------------------------------+
|**TXCNT**                     |0x00000108  |32    |ro    |0x00000000  |Frames Transmitted            |
+------------------------------+------------+------+------+------------+------------------------------+
|**TXBCCNT**                   |0x0000010c  |32    |ro    |0x00000000  |Broadcast frames Tx           |
+------------------------------+------------+------+------+------------+------------------------------+
|**TXMCCNT**                   |0x00000110  |32    |ro    |0x00000000  |Multicast frames Tx           |
+------------------------------+------------+------+------+------------+------------------------------+
|**TXPAUSECNT**                |0x00000114  |32    |ro    |0x00000000  |Pause frames Tx               |
+------------------------------+------------+------+------+------------+------------------------------+
|**TX64CNT**                   |0x00000118  |32    |ro    |0x00000000  |Frames Tx, 64-byte length     |
+------------------------------+------------+------+------+------------+------------------------------+
|**TX65CNT**                   |0x0000011c  |32    |ro    |0x00000000  | Frames Tx, 65 to 127-byte le |
+------------------------------+------------+------+------+------------+------------------------------+
|**TX128CNT**                  |0x00000120  |32    |ro    |0x00000000  | Frames Tx, 128 to 255-bytele |
+------------------------------+------------+------+------+------------+------------------------------+
|**TX256CNT**                  |0x00000124  |32    |ro    |0x00000000  | Frames Tx, 256 to 511-byte l |
+------------------------------+------------+------+------+------------+------------------------------+
|**TX512CNT**                  |0x00000128  |32    |ro    |0x00000000  | Frames Tx, 512 to 1023-byte  |
+------------------------------+------------+------+------+------------+------------------------------+
|**TX1024CNT**                 |0x0000012c  |32    |ro    |0x00000000  | Frame Tx, 1024 to 1518-byte  |
+------------------------------+------------+------+------+------------+------------------------------+
|**TXURUNCNT**                 |0x00000134  |32    |ro    |0x00000000  |Transmit under runs           |
+------------------------------+------------+------+------+------------+------------------------------+
|**SNGLCOLLCNT**               |0x00000138  |32    |ro    |0x00000000  |Single Collision Frames       |
+------------------------------+------------+------+------+------------+------------------------------+
|**MULTICOLLCNT**              |0x0000013c  |32    |ro    |0x00000000  |Multiple Collision Frames     |
+------------------------------+------------+------+------+------------+------------------------------+
|**EXCESSCOLLCNT**             |0x00000140  |32    |ro    |0x00000000  |Excessive Collisions          |
+------------------------------+------------+------+------+------------+------------------------------+
|**LATECOLLCNT**               |0x00000144  |32    |ro    |0x00000000  |Late Collisions               |
+------------------------------+------------+------+------+------------+------------------------------+
|**TXDEFERCNT**                |0x00000148  |32    |ro    |0x00000000  |Deferred Transmission Frames  |
+------------------------------+------------+------+------+------------+------------------------------+
|**TXCSENSECNT**               |0x0000014c  |32    |ro    |0x00000000  |Carrier Sense Errors.         |
+------------------------------+------------+------+------+------------+------------------------------+
|**OCTRXL**                    |0x00000150  |32    |ro    |0x00000000  |Octets Received [31:0]        |
+------------------------------+------------+------+------+------------+------------------------------+
|**OCTRXH**                    |0x00000154  |32    |ro    |0x00000000  |Octets Received [47:32]       |
+------------------------------+------------+------+------+------------+------------------------------+
|**RXCNT**                     |0x00000158  |32    |ro    |0x00000000  |Frames Received               |
+------------------------------+------------+------+------+------------+------------------------------+
|**RXBROADCNT**                |0x0000015c  |32    |ro    |0x00000000  |Broadcast Frames Rx           |
+------------------------------+------------+------+------+------------+------------------------------+
|**RXMULTICNT**                |0x00000160  |32    |ro    |0x00000000  |Multicast Frames Rx           |
+------------------------------+------------+------+------+------------+------------------------------+
|**RXPAUSECNT**                |0x00000164  |32    |ro    |0x00000000  |Pause Frames Rx               |
+------------------------------+------------+------+------+------------+------------------------------+
|**RX64CNT**                   |0x00000168  |32    |ro    |0x00000000  |Frames Rx, 64-byte length     |
+------------------------------+------------+------+------+------------+------------------------------+
|**RX65CNT**                   |0x0000016c  |32    |ro    |0x00000000  | Frames Rx, 65 to 127-byte le |
+------------------------------+------------+------+------+------------+------------------------------+
|**RX128CNT**                  |0x00000170  |32    |ro    |0x00000000  | Frames Rx, 128 to 255-byte l |
+------------------------------+------------+------+------+------------+------------------------------+
|**RX256CNT**                  |0x00000174  |32    |ro    |0x00000000  | Frames Rx, 256 to 511-byte l |
+------------------------------+------------+------+------+------------+------------------------------+
|**RX512CNT**                  |0x00000178  |32    |ro    |0x00000000  | Frames Rx, 512 to 1023-byte  |
+------------------------------+------------+------+------+------------+------------------------------+
|**RX1024CNT**                 |0x0000017c  |32    |ro    |0x00000000  | Frames Rx, 1024 to 1518-byte |
+------------------------------+------------+------+------+------------+------------------------------+
|**RXUNDRCNT**                 |0x00000184  |32    |ro    |0x00000000  |Undersize frames received     |
+------------------------------+------------+------+------+------------+------------------------------+
|**RXOVRCNT**                  |0x00000188  |32    |ro    |0x00000000  |Oversize frames received      |
+------------------------------+------------+------+------+------------+------------------------------+
|**RXJABCNT**                  |0x0000018c  |32    |ro    |0x00000000  |Jabbers received              |
+------------------------------+------------+------+------+------------+------------------------------+
|**RXFCSCNT**                  |0x00000190  |32    |ro    |0x00000000  |Frame check sequence errors   |
+------------------------------+------------+------+------+------------+------------------------------+
|**RXLENGTHCNT**               |0x00000194  |32    |ro    |0x00000000  |Length field frame errors     |
+------------------------------+------------+------+------+------------+------------------------------+
|**RXSYMBCNT**                 |0x00000198  |32    |ro    |0x00000000  |Receive symbol errors         |
+------------------------------+------------+------+------+------------+------------------------------+
|**RXALIGNCNT**                |0x0000019c  |32    |ro    |0x00000000  |Alignment errors              |
+------------------------------+------------+------+------+------------+------------------------------+
|**RXRESERRCNT**               |0x000001a0  |32    |ro    |0x00000000  |Receive resource errors       |
+------------------------------+------------+------+------+------------+------------------------------+
|**RXORCNT**                   |0x000001a4  |32    |ro    |0x00000000  |Receive overrun errors        |
+------------------------------+------------+------+------+------------+------------------------------+
|**RXIPCCNT**                  |0x000001a8  |32    |ro    |0x00000000  |IP header checksum errors     |
+------------------------------+------------+------+------+------------+------------------------------+
|**RXTCPCCNT**                 |0x000001ac  |32    |ro    |0x00000000  |TCP checksum errors           |
+------------------------------+------------+------+------+------------+------------------------------+
|**RXUDPCCNT**                 |0x000001b0  |32    |ro    |0x00000000  |UDP checksum error            |
+------------------------------+------------+------+------+------------+------------------------------+
|**ROBE_S**                    |0x000001c8  |32    |rw    |0x00000000  | 1588 timer sync strobe secon |
+------------------------------+------------+------+------+------------+------------------------------+
|**ROBE_NS**                   |0x000001cc  |32    |mixed |0x00000000  | 1588 timer sync strobe nanos |
+------------------------------+------------+------+------+------------+------------------------------+
|**TIMER_1588_SEC**            |0x000001d0  |32    |rw    |0x00000000  |1588 timer seconds            |
+------------------------------+------------+------+------+------------+------------------------------+
|**TIMER_1588_NANOSEC**        |0x000001d4  |32    |mixed |0x00000000  |1588 timer nanoseconds        |
+------------------------------+------------+------+------+------------+------------------------------+
|**TIMER_1588_ADJ**            |0x000001d8  |32    |mixed |0x00000000  |1588 timer adjust             |
+------------------------------+------------+------+------+------------+------------------------------+
|**TIMER_1588_INC**            |0x000001dc  |32    |mixed |0x00000000  |1588 timer increment          |
+------------------------------+------------+------+------+------------+------------------------------+
|**PTP_TXSEC**                 |0x000001e0  |32    |ro    |0x00000000  | PTP event frame transmitted  |
+------------------------------+------------+------+------+------------+------------------------------+
|**PTP_TXNANOSEC**             |0x000001e4  |32    |ro    |0x00000000  | PTP event frame transmitted  |
+------------------------------+------------+------+------+------------+------------------------------+
|**PTP_RXSEC**                 |0x000001e8  |32    |ro    |0x00000000  | PTP event frame received sec |
+------------------------------+------------+------+------+------------+------------------------------+
|**PTP_RXNANOSEC**             |0x000001ec  |32    |ro    |0x00000000  | PTP event frame received nan |
+------------------------------+------------+------+------+------------+------------------------------+
|**PTPP_TXSEC**                |0x000001f0  |32    |ro    |0x00000000  | PTP peer event frame transmi |
+------------------------------+------------+------+------+------------+------------------------------+
|**PTPP_TXNANOSEC**            |0x000001f4  |32    |ro    |0x00000000  | PTP peer event frame transmi |
+------------------------------+------------+------+------+------------+------------------------------+
|**PTPP_RXSEC**                |0x000001f8  |32    |ro    |0x00000000  | PTP peer event frame receive |
+------------------------------+------------+------+------+------------+------------------------------+
|**PTPP_RXNANOSEC**            |0x000001fc  |32    |ro    |0x00000000  | PTP peer event frame receive |
+------------------------------+------------+------+------+------------+------------------------------+
|**DESIGN_CFG2**               |0x00000284  |32    |ro    |0x00000000  |Design Configuration 2        |
+------------------------------+------------+------+------+------------+------------------------------+
|**DESIGN_CFG3**               |0x00000288  |32    |ro    |0x00000000  |Design Configuration 3        |
+------------------------------+------------+------+------+------------+------------------------------+
|**DESIGN_CFG4**               |0x0000028c  |32    |ro    |0x00000000  |Design Configuration 4        |
+------------------------------+------------+------+------+------------+------------------------------+
|**DESIGN_CFG5**               |0x00000290  |32    |ro    |0x00000000  |Design Configuration 5        |
+------------------------------+------------+------+------+------------+------------------------------+

### NWCTRL  

Relative Address = 0x00000000  
Width = 32 bits  
Access Type = mixed  
Reset Value = 0x00000000  
Description Network Control  


### NWCFG  

Relative Address = 0x00000004  
Width = 32 bits  
Access Type = rw  
Reset Value = 0x00080000  
Description Network Configuration  


### NWSR  

Relative Address = 0x00000008  
Width = 32 bits  
Access Type = ro  
Reset Value = 0x00000000  
Description Network Status  


### DMACR  

Relative Address = 0x00000010  
Width = 32 bits  
Access Type = mixed  
Reset Value = 0x00020784  
Description DMA Configuration  


### TXSR  

Relative Address = 0x00000014  
Width = 32 bits  
Access Type = mixed  
Reset Value = 0x00000000  
Description Transmit Status  


### RXQBASE  

Relative Address = 0x00000018  
Width = 32 bits  
Access Type = mixed  
Reset Value = 0x00000000  
Description Receive Buffer Queue Base Address  


### TXQBASE  

Relative Address = 0x0000001c  
Width = 32 bits  
Access Type = mixed  
Reset Value = 0x00000000  
Description Transmit Buffer Queue Base Address  


### RXSR  

Relative Address = 0x00000020  
Width = 32 bits  
Access Type = mixed  
Reset Value = 0x00000000  
Description Receive Status  


### ISR  

Relative Address = 0x00000024  
Width = 32 bits  
Access Type = mixed  
Reset Value = 0x00000000  
Description Interrupt Status  


### IER  

Relative Address = 0x00000028  
Width = 32 bits  
Access Type = wo  
Reset Value = 0x00000000  
Description Interrupt Enable  


### IDR  

Relative Address = 0x0000002c  
Width = 32 bits  
Access Type = wo  
Reset Value = 0x00000000  
Description Interrupt Disable  


### IMR  

Relative Address = 0x00000030  
Width = 32 bits  
Access Type = mixed  
Reset Value = 0x00000000  
Description Interrupt Mask Status  


### PHYMNTNC  

Relative Address = 0x00000034  
Width = 32 bits  
Access Type = rw  
Reset Value = 0x00000000  
Description PHY Maintenance  


### RXPAUSE  

Relative Address = 0x00000038  
Width = 32 bits  
Access Type = ro  
Reset Value = 0x00000000  
Description Received Pause Quantum  


### TXPAUSE  

Relative Address = 0x0000003c  
Width = 32 bits  
Access Type = rw  
Reset Value = 0x0000ffff  
Description Transmit Pause Quantum  


### HASHL  

Relative Address = 0x00000080  
Width = 32 bits  
Access Type = rw  
Reset Value = 0x00000000  
Description Hash Register Bottom [31:0]  


### HASHH  

Relative Address = 0x00000084  
Width = 32 bits  
Access Type = rw  
Reset Value = 0x00000000  
Description Hash Register Top [63:32]  


### LADDR1L  

Relative Address = 0x00000088  
Width = 32 bits  
Access Type = rw  
Reset Value = 0x00000000  
Description Specific Address 1 Bottom [31:0]  


### LADDR1H  

Relative Address = 0x0000008c  
Width = 32 bits  
Access Type = mixed  
Reset Value = 0x00000000  
Description Specific Address 1 Top [47:32]  


### LADDR2L  

Relative Address = 0x00000090  
Width = 32 bits  
Access Type = rw  
Reset Value = 0x00000000  
Description Specific Address 2 Bottom [31:0]  


### LADDR2H  

Relative Address = 0x00000094  
Width = 32 bits  
Access Type = mixed  
Reset Value = 0x00000000  
Description Specific Address 2 Top [47:32]  


### LADDR3L  

Relative Address = 0x00000098  
Width = 32 bits  
Access Type = rw  
Reset Value = 0x00000000  
Description Specific Address 3 Bottom [31:0]  


### LADDR3H  

Relative Address = 0x0000009c  
Width = 32 bits  
Access Type = mixed  
Reset Value = 0x00000000  
Description Specific Address 3 Top [47:32]  


### LADDR4L  

Relative Address = 0x000000a0  
Width = 32 bits  
Access Type = rw  
Reset Value = 0x00000000  
Description Specific Address 4 Bottom [31:0]  


### LADDR4H  

Relative Address = 0x000000a4  
Width = 32 bits  
Access Type = mixed  
Reset Value = 0x00000000  
Description Specific Address 4 Top [47:32]  


### MATCH1  

Relative Address = 0x000000a8  
Width = 32 bits  
Access Type = mixed  
Reset Value = 0x00000000  
Description Type ID Match 1  


### MATCH2  

Relative Address = 0x000000ac  
Width = 32 bits  
Access Type = mixed  
Reset Value = 0x00000000  
Description Type ID Match 2  


### MATCH3  

Relative Address = 0x000000b0  
Width = 32 bits  
Access Type = mixed  
Reset Value = 0x00000000  
Description Type ID Match 3  


### MATCH4  

Relative Address = 0x000000b4  
Width = 32 bits  
Access Type = mixed  
Reset Value = 0x00000000  
Description Type ID Match 4  


### WAKE_ON_LAN  

Relative Address = 0x000000b8  
Width = 32 bits  
Access Type = mixed  
Reset Value = 0x00000000  
Description Wake on LAN Register  


### STRETCH  

Relative Address = 0x000000bc  
Width = 32 bits  
Access Type = mixed  
Reset Value = 0x00000000  
Description IPG stretch register  


### STACKED_VLAN  

Relative Address = 0x000000c0  
Width = 32 bits  
Access Type = mixed  
Reset Value = 0x00000000  
Description Stacked VLAN Register  


### TX_PFC_PAUSE  

Relative Address = 0x000000c4  
Width = 32 bits  
Access Type = mixed  
Reset Value = 0x00000000  
Description Transmit PFC Pause Register  


### SPEC_ADDR1_MASK_BOT  

Relative Address = 0x000000c8  
Width = 32 bits  
Access Type = rw  
Reset Value = 0x00000000  
Description Specific Address Mask 1 Bottom [31:0]  


### SPEC_ADDR1_MASK_TOP  

Relative Address = 0x000000cc  
Width = 32 bits  
Access Type = mixed  
Reset Value = 0x00000000  
Description Specific Address Mask 1 Top [47:32]  


### MODULE_ID  

Relative Address = 0x000000fc  
Width = 32 bits  
Access Type = ro  
Reset Value = 0x00020118  
Description Module ID  


### OCTTXL  

Relative Address = 0x00000100  
Width = 32 bits  
Access Type = ro  
Reset Value = 0x00000000  
Description Octets transmitted [31:0] (in frames without error)  


### OCTTXH  

Relative Address = 0x00000104  
Width = 32 bits  
Access Type = ro  
Reset Value = 0x00000000  
Description Octets transmitted [47:32] (in frames without error)  


### TXCNT  

Relative Address = 0x00000108  
Width = 32 bits  
Access Type = ro  
Reset Value = 0x00000000  
Description Frames Transmitted  


### TXBCCNT  

Relative Address = 0x0000010c  
Width = 32 bits  
Access Type = ro  
Reset Value = 0x00000000  
Description Broadcast frames Tx  


### TXMCCNT  

Relative Address = 0x00000110  
Width = 32 bits  
Access Type = ro  
Reset Value = 0x00000000  
Description Multicast frames Tx  


### TXPAUSECNT  

Relative Address = 0x00000114  
Width = 32 bits  
Access Type = ro  
Reset Value = 0x00000000  
Description Pause frames Tx  


### TX64CNT  

Relative Address = 0x00000118  
Width = 32 bits  
Access Type = ro  
Reset Value = 0x00000000  
Description Frames Tx, 64-byte length  


### TX65CNT  

Relative Address = 0x0000011c  
Width = 32 bits  
Access Type = ro  
Reset Value = 0x00000000  
Description Frames Tx, 65 to 127-byte length  


### TX128CNT  

Relative Address = 0x00000120  
Width = 32 bits  
Access Type = ro  
Reset Value = 0x00000000  
Description Frames Tx, 128 to 255-bytelength  


### TX256CNT  

Relative Address = 0x00000124  
Width = 32 bits  
Access Type = ro  
Reset Value = 0x00000000  
Description Frames Tx, 256 to 511-byte length  


### TX512CNT  

Relative Address = 0x00000128  
Width = 32 bits  
Access Type = ro  
Reset Value = 0x00000000  
Description Frames Tx, 512 to 1023-byte length  


### TX1024CNT  

Relative Address = 0x0000012c  
Width = 32 bits  
Access Type = ro  
Reset Value = 0x00000000  
Description Frame Tx, 1024 to 1518-byte length  


### TXURUNCNT  

Relative Address = 0x00000134  
Width = 32 bits  
Access Type = ro  
Reset Value = 0x00000000  
Description Transmit under runs  


### SNGLCOLLCNT  

Relative Address = 0x00000138  
Width = 32 bits  
Access Type = ro  
Reset Value = 0x00000000  
Description Single Collision Frames  


### MULTICOLLCNT  

Relative Address = 0x0000013c  
Width = 32 bits  
Access Type = ro  
Reset Value = 0x00000000  
Description Multiple Collision Frames  


### EXCESSCOLLCNT  

Relative Address = 0x00000140  
Width = 32 bits  
Access Type = ro  
Reset Value = 0x00000000  
Description Excessive Collisions  


### LATECOLLCNT  

Relative Address = 0x00000144  
Width = 32 bits  
Access Type = ro  
Reset Value = 0x00000000  
Description Late Collisions  


### TXDEFERCNT  

Relative Address = 0x00000148  
Width = 32 bits  
Access Type = ro  
Reset Value = 0x00000000  
Description Deferred Transmission Frames  


### TXCSENSECNT  

Relative Address = 0x0000014c  
Width = 32 bits  
Access Type = ro  
Reset Value = 0x00000000  
Description Carrier Sense Errors.  


### OCTRXL  

Relative Address = 0x00000150  
Width = 32 bits  
Access Type = ro  
Reset Value = 0x00000000  
Description Octets Received [31:0]  


### OCTRXH  

Relative Address = 0x00000154  
Width = 32 bits  
Access Type = ro  
Reset Value = 0x00000000  
Description Octets Received [47:32]  


### RXCNT  

Relative Address = 0x00000158  
Width = 32 bits  
Access Type = ro  
Reset Value = 0x00000000  
Description Frames Received  


### RXBROADCNT  

Relative Address = 0x0000015c  
Width = 32 bits  
Access Type = ro  
Reset Value = 0x00000000  
Description Broadcast Frames Rx  


### RXMULTICNT  

Relative Address = 0x00000160  
Width = 32 bits  
Access Type = ro  
Reset Value = 0x00000000  
Description Multicast Frames Rx  


### RXPAUSECNT  

Relative Address = 0x00000164  
Width = 32 bits  
Access Type = ro  
Reset Value = 0x00000000  
Description Pause Frames Rx  


### RX64CNT  

Relative Address = 0x00000168  
Width = 32 bits  
Access Type = ro  
Reset Value = 0x00000000  
Description Frames Rx, 64-byte length  


### RX65CNT  

Relative Address = 0x0000016c  
Width = 32 bits  
Access Type = ro  
Reset Value = 0x00000000  
Description Frames Rx, 65 to 127-byte length  


### RX128CNT  

Relative Address = 0x00000170  
Width = 32 bits  
Access Type = ro  
Reset Value = 0x00000000  
Description Frames Rx, 128 to 255-byte length  


### RX256CNT  

Relative Address = 0x00000174  
Width = 32 bits  
Access Type = ro  
Reset Value = 0x00000000  
Description Frames Rx, 256 to 511-byte length  


### RX512CNT  

Relative Address = 0x00000178  
Width = 32 bits  
Access Type = ro  
Reset Value = 0x00000000  
Description Frames Rx, 512 to 1023-byte length  


### RX1024CNT  

Relative Address = 0x0000017c  
Width = 32 bits  
Access Type = ro  
Reset Value = 0x00000000  
Description Frames Rx, 1024 to 1518-byte length  


### RXUNDRCNT  

Relative Address = 0x00000184  
Width = 32 bits  
Access Type = ro  
Reset Value = 0x00000000  
Description Undersize frames received  


### RXOVRCNT  

Relative Address = 0x00000188  
Width = 32 bits  
Access Type = ro  
Reset Value = 0x00000000  
Description Oversize frames received  


### RXJABCNT  

Relative Address = 0x0000018c  
Width = 32 bits  
Access Type = ro  
Reset Value = 0x00000000  
Description Jabbers received  


### RXFCSCNT  

Relative Address = 0x00000190  
Width = 32 bits  
Access Type = ro  
Reset Value = 0x00000000  
Description Frame check sequence errors  


### RXLENGTHCNT  

Relative Address = 0x00000194  
Width = 32 bits  
Access Type = ro  
Reset Value = 0x00000000  
Description Length field frame errors  


### RXSYMBCNT  

Relative Address = 0x00000198  
Width = 32 bits  
Access Type = ro  
Reset Value = 0x00000000  
Description Receive symbol errors  


### RXALIGNCNT  

Relative Address = 0x0000019c  
Width = 32 bits  
Access Type = ro  
Reset Value = 0x00000000  
Description Alignment errors  


### RXRESERRCNT  

Relative Address = 0x000001a0  
Width = 32 bits  
Access Type = ro  
Reset Value = 0x00000000  
Description Receive resource errors  


### RXORCNT  

Relative Address = 0x000001a4  
Width = 32 bits  
Access Type = ro  
Reset Value = 0x00000000  
Description Receive overrun errors  


### RXIPCCNT  

Relative Address = 0x000001a8  
Width = 32 bits  
Access Type = ro  
Reset Value = 0x00000000  
Description IP header checksum errors  


### RXTCPCCNT  

Relative Address = 0x000001ac  
Width = 32 bits  
Access Type = ro  
Reset Value = 0x00000000  
Description TCP checksum errors  


### RXUDPCCNT  

Relative Address = 0x000001b0  
Width = 32 bits  
Access Type = ro  
Reset Value = 0x00000000  
Description UDP checksum error  


### ROBE_S  

Relative Address = 0x000001c8  
Width = 32 bits  
Access Type = rw  
Reset Value = 0x00000000  
Description 1588 timer sync strobe seconds  


### ROBE_NS  

Relative Address = 0x000001cc  
Width = 32 bits  
Access Type = mixed  
Reset Value = 0x00000000  
Description 1588 timer sync strobe nanoseconds  


### TIMER_1588_SEC  

Relative Address = 0x000001d0  
Width = 32 bits  
Access Type = rw  
Reset Value = 0x00000000  
Description 1588 timer seconds  


### TIMER_1588_NANOSEC  

Relative Address = 0x000001d4  
Width = 32 bits  
Access Type = mixed  
Reset Value = 0x00000000  
Description 1588 timer nanoseconds  


### TIMER_1588_ADJ  

Relative Address = 0x000001d8  
Width = 32 bits  
Access Type = mixed  
Reset Value = 0x00000000  
Description 1588 timer adjust  


### TIMER_1588_INC  

Relative Address = 0x000001dc  
Width = 32 bits  
Access Type = mixed  
Reset Value = 0x00000000  
Description 1588 timer increment  


### PTP_TXSEC  

Relative Address = 0x000001e0  
Width = 32 bits  
Access Type = ro  
Reset Value = 0x00000000  
Description PTP event frame transmitted seconds  


### PTP_TXNANOSEC  

Relative Address = 0x000001e4  
Width = 32 bits  
Access Type = ro  
Reset Value = 0x00000000  
Description PTP event frame transmitted nanoseconds  


### PTP_RXSEC  

Relative Address = 0x000001e8  
Width = 32 bits  
Access Type = ro  
Reset Value = 0x00000000  
Description PTP event frame received seconds  


### PTP_RXNANOSEC  

Relative Address = 0x000001ec  
Width = 32 bits  
Access Type = ro  
Reset Value = 0x00000000  
Description PTP event frame received nanoseconds.  


### PTPP_TXSEC  

Relative Address = 0x000001f0  
Width = 32 bits  
Access Type = ro  
Reset Value = 0x00000000  
Description PTP peer event frame transmitted seconds  


### PTPP_TXNANOSEC  

Relative Address = 0x000001f4  
Width = 32 bits  
Access Type = ro  
Reset Value = 0x00000000  
Description PTP peer event frame transmitted nanoseconds  


### PTPP_RXSEC  

Relative Address = 0x000001f8  
Width = 32 bits  
Access Type = ro  
Reset Value = 0x00000000  
Description PTP peer event frame received seconds  


### PTPP_RXNANOSEC  

Relative Address = 0x000001fc  
Width = 32 bits  
Access Type = ro  
Reset Value = 0x00000000  
Description PTP peer event frame received nanoseconds.  


### DESIGN_CFG2  

Relative Address = 0x00000284  
Width = 32 bits  
Access Type = ro  
Reset Value = 0x00000000  
Description Design Configuration 2  


### DESIGN_CFG3  

Relative Address = 0x00000288  
Width = 32 bits  
Access Type = ro  
Reset Value = 0x00000000  
Description Design Configuration 3  


### DESIGN_CFG4  

Relative Address = 0x0000028c  
Width = 32 bits  
Access Type = ro  
Reset Value = 0x00000000  
Description Design Configuration 4  


### DESIGN_CFG5  

Relative Address = 0x00000290  
Width = 32 bits  
Access Type = ro  
Reset Value = 0x00000000  
Description Design Configuration 5  

