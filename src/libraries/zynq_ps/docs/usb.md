# USB Controller  

Module USB Controller (usb)  
SPDX-License-Identifier: MIT  
Auto-generated: Sun Sep 20 15:25:57 EEST 2020  

usb0 Base Address = 0xe0002000  
usb1 Base Address = 0xe0003000  

## Register Summary  

+------------------------------+------------+------+------+------------+------------------------------+
|Register Name                 |Address     |Width |Type  |Reset Value |Description                   |
+==============================+============+======+======+============+==============================+
|**ID**                        |0x00000000  |32    |ro    |0x00000000  |IP version and revision       |
+------------------------------+------------+------+------+------------+------------------------------+
|**HWGENERAL**                 |0x00000004  |12    |ro    |0x00000083  |Misc IP config constants      |
+------------------------------+------------+------+------+------------+------------------------------+
|**HWHOST**                    |0x00000008  |32    |ro    |0x10020001  |Host Mode IP config constants |
+------------------------------+------------+------+------+------------+------------------------------+
|**HWDEVICE**                  |0x0000000c  |6     |ro    |0x00000019  | Device Mode IP config consta |
+------------------------------+------------+------+------+------------+------------------------------+
|**HWTXBUF**                   |0x00000010  |32    |ro    |0x00000000  |TxBuffer IP config constants  |
+------------------------------+------------+------+------+------------+------------------------------+
|**HWRXBUF**                   |0x00000014  |32    |ro    |0x00000a10  | IP constants, RX buffer cons |
+------------------------------+------------+------+------+------------+------------------------------+
|**GPTIMER0LD**                |0x00000080  |24    |rw    |0x00000000  |GP Timer 0 Load Value.        |
+------------------------------+------------+------+------+------------+------------------------------+
|**GPTIMER0CTRL**              |0x00000084  |32    |mixed |0x00000000  |GP Timer 1 Control.           |
+------------------------------+------------+------+------+------------+------------------------------+
|**GPTIMER1LD**                |0x00000088  |24    |rw    |0x00000000  |GP Timer 1 Load Value         |
+------------------------------+------------+------+------+------------+------------------------------+
|**GPTIMER1CTRL**              |0x0000008c  |32    |mixed |0x00000000  |GP Timer 1 Control            |
+------------------------------+------------+------+------+------------+------------------------------+
|**SBUSCFG**                   |0x00000090  |3     |rw    |0x00000003  |DMA Master AHB Burst Mode     |
+------------------------------+------------+------+------+------------+------------------------------+
|**CAPLENGTH_HCIVERSION**      |0x00000100  |32    |ro    |0x01000040  | EHCI Addr Space and HCI cons |
+------------------------------+------------+------+------+------------+------------------------------+
|**HCSPARAMS**                 |0x00000104  |28    |ro    |0x00010011  | TT counts and EHCI HCS const |
+------------------------------+------------+------+------+------------+------------------------------+
|**HCCPARAMS**                 |0x00000108  |16    |ro    |0x0006      | EHCI Host Configuration Cons |
+------------------------------+------------+------+------+------------+------------------------------+
|**DCIVERSION**                |0x00000120  |16    |ro    |0x0001      | Device Controller Interface  |
+------------------------------+------------+------+------+------------+------------------------------+
|**DCCPARAMS**                 |0x00000124  |9     |ro    |0x0000018c  | EHCI, Device, and EndpointCa |
+------------------------------+------------+------+------+------------+------------------------------+
|**CMD**                       |0x00000140  |24    |mixed |0x00080000  |USB Commands (EHCI extended)  |
+------------------------------+------------+------+------+------------+------------------------------+
|**ISR**                       |0x00000144  |26    |mixed |0x00000000  | Interrupt/Raw Status (EHCI e |
+------------------------------+------------+------+------+------------+------------------------------+
|**IER**                       |0x00000148  |26    |mixed |0x00000000  |Interrrupts and Enables       |
+------------------------------+------------+------+------+------------+------------------------------+
|**FRAME**                     |0x0000014c  |14    |rw    |0x00000000  |Frame List Index              |
+------------------------------+------------+------+------+------------+------------------------------+
|**LISTBASE**                  |0x00000154  |32    |mixed |0x00000000  |Host/Device Address dual-use  |
+------------------------------+------------+------+------+------------+------------------------------+
|**ASYNCLISTADDR**             |0x00000158  |32    |mixed |0x00000000  |Host/Device dual-use          |
+------------------------------+------------+------+------+------------+------------------------------+
|**TTCTRL**                    |0x0000015c  |32    |mixed |0x00000000  |TT Control                    |
+------------------------------+------------+------+------+------------+------------------------------+
|**BURSTSIZE**                 |0x00000160  |17    |rw    |0x00001010  |Burst Size                    |
+------------------------------+------------+------+------+------------+------------------------------+
|**TXFILL**                    |0x00000164  |22    |mixed |0x00000000  |TxFIFO Fill Tuning            |
+------------------------------+------------+------+------+------------+------------------------------+
|**TXTTFILLTUNING**            |0x00000168  |13    |mixed |0x00000000  |TT TX latency FIFO            |
+------------------------------+------------+------+------+------------+------------------------------+
|**IC_USB**                    |0x0000016c  |32    |mixed |0x00000000  | Low and Fast Speed Control c |
+------------------------------+------------+------+------+------------+------------------------------+
|**ULPIVIEW**                  |0x00000170  |32    |mixed |0x08000000  |ULPI Viewport                 |
+------------------------------+------------+------+------+------------+------------------------------+
|**EPNAKISR**                  |0x00000178  |32    |wtc   |0x00000000  |Endpoint NAK (Device mode)    |
+------------------------------+------------+------+------+------------+------------------------------+
|**EPNAKIER**                  |0x0000017c  |32    |rw    |0x00000000  |Endpoint NAK (Device mode)    |
+------------------------------+------------+------+------+------------+------------------------------+
|**CONFIG_FLAG**               |0x00000180  |32    |ro    |0x00000001  |reserved                      |
+------------------------------+------------+------+------+------------+------------------------------+
|**PORTSCR1**                  |0x00000184  |32    |mixed |0x00000000  |Port Status & Control         |
+------------------------------+------------+------+------+------------+------------------------------+
|**OTGCSR**                    |0x000001a4  |32    |mixed |0x00001020  |OTG Status and Control        |
+------------------------------+------------+------+------+------------+------------------------------+
|**MODE**                      |0x000001a8  |32    |mixed |0x00000000  |USB Mode Selection            |
+------------------------------+------------+------+------+------------+------------------------------+
|**EPSTAT**                    |0x000001ac  |16    |wtc   |0x0000      | Endpoint Status Setup (Devic |
+------------------------------+------------+------+------+------------+------------------------------+
|**EPPRIME**                   |0x000001b0  |32    |wtc   |0x00000000  |Endpoint Primer (Device mode) |
+------------------------------+------------+------+------+------------+------------------------------+
|**EPFLUSH**                   |0x000001b4  |32    |wtc   |0x00000000  |Endpoint Flush (Device mode)  |
+------------------------------+------------+------+------+------------+------------------------------+
|**EPRDY**                     |0x000001b8  |32    |ro    |0x00000000  | Endpoint Buffer Ready Status |
+------------------------------+------------+------+------+------------+------------------------------+
|**EPCOMPL**                   |0x000001bc  |32    |rw    |0x00000000  | Endpoint Tx Complete (Device |
+------------------------------+------------+------+------+------------+------------------------------+
|**EPCR0**                     |0x000001c0  |24    |mixed |0x00800080  |Endpoint 0 (Device mode)      |
+------------------------------+------------+------+------+------------+------------------------------+
|**ENDPTCTRL1**                |0x000001c4  |24    |mixed |0x00000000  | Endpoints 1 to 11 (Device mo |
+------------------------------+------------+------+------+------------+------------------------------+
|**ENDPTCTRL2**                |0x000001c8  |24    |mixed |0x00000000  | Endpoints 1 to 11 (Device mo |
+------------------------------+------------+------+------+------------+------------------------------+
|**ENDPTCTRL3**                |0x000001cc  |24    |mixed |0x00000000  | Endpoints 1 to 11 (Device mo |
+------------------------------+------------+------+------+------------+------------------------------+
|**ENDPTCTRL4**                |0x000001d0  |24    |mixed |0x00000000  | Endpoints 1 to 11 (Device mo |
+------------------------------+------------+------+------+------------+------------------------------+
|**ENDPTCTRL5**                |0x000001d4  |24    |mixed |0x00000000  | Endpoints 1 to 11 (Device mo |
+------------------------------+------------+------+------+------------+------------------------------+
|**ENDPTCTRL6**                |0x000001d8  |24    |mixed |0x00000000  | Endpoints 1 to 11 (Device mo |
+------------------------------+------------+------+------+------------+------------------------------+
|**ENDPTCTRL7**                |0x000001dc  |24    |mixed |0x00000000  | Endpoints 1 to 11 (Device mo |
+------------------------------+------------+------+------+------------+------------------------------+
|**ENDPTCTRL8**                |0x000001e0  |24    |mixed |0x00000000  | Endpoints 1 to 11 (Device mo |
+------------------------------+------------+------+------+------------+------------------------------+
|**ENDPTCTRL9**                |0x000001e4  |24    |mixed |0x00000000  | Endpoints 1 to 11 (Device mo |
+------------------------------+------------+------+------+------------+------------------------------+
|**ENDPTCTRL10**               |0x000001e8  |24    |mixed |0x00000000  | Endpoints 1 to 11 (Device mo |
+------------------------------+------------+------+------+------------+------------------------------+
|**ENDPTCTRL11**               |0x000001ec  |24    |mixed |0x00000000  | Endpoints 1 to 11 (Device mo |
+------------------------------+------------+------+------+------------+------------------------------+

### ID  

Module usb  
Relative Address = 0x00000000  
Width = 32 bits  
Access Type = ro  
Reset Value = 0x00000000  
Description IP version and revision  


### HWGENERAL  

Module usb  
Relative Address = 0x00000004  
Width = 12 bits  
Access Type = ro  
Reset Value = 0x00000083  
Description Misc IP config constants  


### HWHOST  

Module usb  
Relative Address = 0x00000008  
Width = 32 bits  
Access Type = ro  
Reset Value = 0x10020001  
Description Host Mode IP config constants  


### HWDEVICE  

Module usb  
Relative Address = 0x0000000c  
Width = 6 bits  
Access Type = ro  
Reset Value = 0x00000019  
Description Device Mode IP config constants  


### HWTXBUF  

Module usb  
Relative Address = 0x00000010  
Width = 32 bits  
Access Type = ro  
Reset Value = 0x00000000  
Description TxBuffer IP config constants  


### HWRXBUF  

Module usb  
Relative Address = 0x00000014  
Width = 32 bits  
Access Type = ro  
Reset Value = 0x00000a10  
Description IP constants, RX buffer constants  


### GPTIMER0LD  

Module usb  
Relative Address = 0x00000080  
Width = 24 bits  
Access Type = rw  
Reset Value = 0x00000000  
Description GP Timer 0 Load Value.  


### GPTIMER0CTRL  

Module usb  
Relative Address = 0x00000084  
Width = 32 bits  
Access Type = mixed  
Reset Value = 0x00000000  
Description GP Timer 1 Control.  


### GPTIMER1LD  

Module usb  
Relative Address = 0x00000088  
Width = 24 bits  
Access Type = rw  
Reset Value = 0x00000000  
Description GP Timer 1 Load Value  


### GPTIMER1CTRL  

Module usb  
Relative Address = 0x0000008c  
Width = 32 bits  
Access Type = mixed  
Reset Value = 0x00000000  
Description GP Timer 1 Control  


### SBUSCFG  

Module usb  
Relative Address = 0x00000090  
Width = 3 bits  
Access Type = rw  
Reset Value = 0x00000003  
Description DMA Master AHB Burst Mode  


### CAPLENGTH_HCIVERSION  

Module usb  
Relative Address = 0x00000100  
Width = 32 bits  
Access Type = ro  
Reset Value = 0x01000040  
Description EHCI Addr Space and HCI constants  


### HCSPARAMS  

Module usb  
Relative Address = 0x00000104  
Width = 28 bits  
Access Type = ro  
Reset Value = 0x00010011  
Description TT counts and EHCI HCS constants  


### HCCPARAMS  

Module usb  
Relative Address = 0x00000108  
Width = 16 bits  
Access Type = ro  
Reset Value = 0x0006  
Description EHCI Host Configuration Constants.  


### DCIVERSION  

Module usb  
Relative Address = 0x00000120  
Width = 16 bits  
Access Type = ro  
Reset Value = 0x0001  
Description Device Controller Interface Version.  


### DCCPARAMS  

Module usb  
Relative Address = 0x00000124  
Width = 9 bits  
Access Type = ro  
Reset Value = 0x0000018c  
Description EHCI, Device, and EndpointCapabilities.  


### CMD  

Module usb  
Relative Address = 0x00000140  
Width = 24 bits  
Access Type = mixed  
Reset Value = 0x00080000  
Description USB Commands (EHCI extended)  


### ISR  

Module usb  
Relative Address = 0x00000144  
Width = 26 bits  
Access Type = mixed  
Reset Value = 0x00000000  
Description Interrupt/Raw Status (EHCI extended) (Host/Device)  


### IER  

Module usb  
Relative Address = 0x00000148  
Width = 26 bits  
Access Type = mixed  
Reset Value = 0x00000000  
Description Interrrupts and Enables  


### FRAME  

Module usb  
Relative Address = 0x0000014c  
Width = 14 bits  
Access Type = rw  
Reset Value = 0x00000000  
Description Frame List Index  


### LISTBASE  

Module usb  
Relative Address = 0x00000154  
Width = 32 bits  
Access Type = mixed  
Reset Value = 0x00000000  
Description Host/Device Address dual-use  


### ASYNCLISTADDR  

Module usb  
Relative Address = 0x00000158  
Width = 32 bits  
Access Type = mixed  
Reset Value = 0x00000000  
Description Host/Device dual-use  


### TTCTRL  

Module usb  
Relative Address = 0x0000015c  
Width = 32 bits  
Access Type = mixed  
Reset Value = 0x00000000  
Description TT Control  


### BURSTSIZE  

Module usb  
Relative Address = 0x00000160  
Width = 17 bits  
Access Type = rw  
Reset Value = 0x00001010  
Description Burst Size  


### TXFILL  

Module usb  
Relative Address = 0x00000164  
Width = 22 bits  
Access Type = mixed  
Reset Value = 0x00000000  
Description TxFIFO Fill Tuning  


### TXTTFILLTUNING  

Module usb  
Relative Address = 0x00000168  
Width = 13 bits  
Access Type = mixed  
Reset Value = 0x00000000  
Description TT TX latency FIFO  


### IC_USB  

Module usb  
Relative Address = 0x0000016c  
Width = 32 bits  
Access Type = mixed  
Reset Value = 0x00000000  
Description Low and Fast Speed Control constants  


### ULPIVIEW  

Module usb  
Relative Address = 0x00000170  
Width = 32 bits  
Access Type = mixed  
Reset Value = 0x08000000  
Description ULPI Viewport  


### EPNAKISR  

Module usb  
Relative Address = 0x00000178  
Width = 32 bits  
Access Type = wtc  
Reset Value = 0x00000000  
Description Endpoint NAK (Device mode)  


### EPNAKIER  

Module usb  
Relative Address = 0x0000017c  
Width = 32 bits  
Access Type = rw  
Reset Value = 0x00000000  
Description Endpoint NAK (Device mode)  


### CONFIG_FLAG  

Module usb  
Relative Address = 0x00000180  
Width = 32 bits  
Access Type = ro  
Reset Value = 0x00000001  
Description reserved  


### PORTSCR1  

Module usb  
Relative Address = 0x00000184  
Width = 32 bits  
Access Type = mixed  
Reset Value = 0x00000000  
Description Port Status & Control  


### OTGCSR  

Module usb  
Relative Address = 0x000001a4  
Width = 32 bits  
Access Type = mixed  
Reset Value = 0x00001020  
Description OTG Status and Control  


### MODE  

Module usb  
Relative Address = 0x000001a8  
Width = 32 bits  
Access Type = mixed  
Reset Value = 0x00000000  
Description USB Mode Selection  


### EPSTAT  

Module usb  
Relative Address = 0x000001ac  
Width = 16 bits  
Access Type = wtc  
Reset Value = 0x0000  
Description Endpoint Status Setup (Device mode)  


### EPPRIME  

Module usb  
Relative Address = 0x000001b0  
Width = 32 bits  
Access Type = wtc  
Reset Value = 0x00000000  
Description Endpoint Primer (Device mode)  


### EPFLUSH  

Module usb  
Relative Address = 0x000001b4  
Width = 32 bits  
Access Type = wtc  
Reset Value = 0x00000000  
Description Endpoint Flush (Device mode)  


### EPRDY  

Module usb  
Relative Address = 0x000001b8  
Width = 32 bits  
Access Type = ro  
Reset Value = 0x00000000  
Description Endpoint Buffer Ready Status (Device mode)  


### EPCOMPL  

Module usb  
Relative Address = 0x000001bc  
Width = 32 bits  
Access Type = rw  
Reset Value = 0x00000000  
Description Endpoint Tx Complete (Device mode)  


### EPCR0  

Module usb  
Relative Address = 0x000001c0  
Width = 24 bits  
Access Type = mixed  
Reset Value = 0x00800080  
Description Endpoint 0 (Device mode)  


### ENDPTCTRL1  

Module usb  
Relative Address = 0x000001c4  
Width = 24 bits  
Access Type = mixed  
Reset Value = 0x00000000  
Description Endpoints 1 to 11 (Device mode)  


### ENDPTCTRL2  

Module usb  
Relative Address = 0x000001c8  
Width = 24 bits  
Access Type = mixed  
Reset Value = 0x00000000  
Description Endpoints 1 to 11 (Device mode)  


### ENDPTCTRL3  

Module usb  
Relative Address = 0x000001cc  
Width = 24 bits  
Access Type = mixed  
Reset Value = 0x00000000  
Description Endpoints 1 to 11 (Device mode)  


### ENDPTCTRL4  

Module usb  
Relative Address = 0x000001d0  
Width = 24 bits  
Access Type = mixed  
Reset Value = 0x00000000  
Description Endpoints 1 to 11 (Device mode)  


### ENDPTCTRL5  

Module usb  
Relative Address = 0x000001d4  
Width = 24 bits  
Access Type = mixed  
Reset Value = 0x00000000  
Description Endpoints 1 to 11 (Device mode)  


### ENDPTCTRL6  

Module usb  
Relative Address = 0x000001d8  
Width = 24 bits  
Access Type = mixed  
Reset Value = 0x00000000  
Description Endpoints 1 to 11 (Device mode)  


### ENDPTCTRL7  

Module usb  
Relative Address = 0x000001dc  
Width = 24 bits  
Access Type = mixed  
Reset Value = 0x00000000  
Description Endpoints 1 to 11 (Device mode)  


### ENDPTCTRL8  

Module usb  
Relative Address = 0x000001e0  
Width = 24 bits  
Access Type = mixed  
Reset Value = 0x00000000  
Description Endpoints 1 to 11 (Device mode)  


### ENDPTCTRL9  

Module usb  
Relative Address = 0x000001e4  
Width = 24 bits  
Access Type = mixed  
Reset Value = 0x00000000  
Description Endpoints 1 to 11 (Device mode)  


### ENDPTCTRL10  

Module usb  
Relative Address = 0x000001e8  
Width = 24 bits  
Access Type = mixed  
Reset Value = 0x00000000  
Description Endpoints 1 to 11 (Device mode)  


### ENDPTCTRL11  

Module usb  
Relative Address = 0x000001ec  
Width = 24 bits  
Access Type = mixed  
Reset Value = 0x00000000  
Description Endpoints 1 to 11 (Device mode)  

