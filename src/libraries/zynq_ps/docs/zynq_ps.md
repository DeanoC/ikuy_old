This chip represents the hard Arm A9 mpcore SoC in Zynq FPGAs.  
The SoC contains a lot of other hard cores apart from just the ARM processors themselves.  
You can choose which parts of the SoC are exposed to the FPGA via the ZynqSoCConfig.  
It has a total of 9 AXI3+ buses. These aren't quite AXI4 in HW but are close enough that simple adaptions allow them to connect to AXI4.  
There are 3 bundles that must be connected at the toplevel.  
Normaly at least a AXI bus and an FCLK would be needed, these are PS_CLOCK_AND_RESET, DDR and MIO.  
This also produces the CPU C headers and documentation for the SoC cores that are exposed on the CPU side. Your board probably doesn't connect all of these externally. Linking with CMAKE with the zynq_ps project to use these from ARMs.  
