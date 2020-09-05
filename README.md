# ikuy

# vivado source 
source /opt/Xilinx/Vivado/2020.1/settings64.sh
# update to latest spinalHDL from local git repo
sbt publishLocal
# to start the openocd with the correct settings
openocd -f pynq-z2.cfg
# telnet into openocd and run a cartridge
telnet 127.0.0.1 4444
run_cart blinky
