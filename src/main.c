#include <assert.h>
#include "hwreg.h"
#include "zynq_ps/l1cache.h"
#include "serial_debug/debug_print.h"
#include "hw_fpga/pcap.h"
#include "hw_i2c/i2c.h"
#include "hw_slcr/slcr.h"
#include "system_info/cpu.h"
#include "BuggyBoy/BuggyBoy.h"
#include "Dissy/Dissy.h"

extern uintptr_t get_bitstream_start_address(void);
extern uintptr_t get_bitstream_end_address(void);

int cpu0_main()
{
    debug_print(DEBUG_WHITE_PEN "\nBlinky cpu0 starting\n");

    hw_fpga_pcap_upload_bitstream(get_bitstream_start_address());

    debug_print(DEBUG_WHITE_PEN "AXI GP0 PS Master test ");

    assert(*HW_REG(BuggyBoy, Test0) == 0xDCDCDCDC);
    *HW_REG(BuggyBoy, Test0) = 0xDEA0DEA0;
    assert(*HW_REG(BuggyBoy, Test0) == 0xDEA0DEA0);
    assert(*HW_REG(BuggyBoy, Reflect1) == 0x00000004);

    // write to the test register (its a simple 32 bit register)
    *HW_REG(BuggyBoy, Test0) = 0x0A0B0C0D;
    assert(*HW_REG(BuggyBoy, Test0) == 0x0A0B0C0D);
    debug_print(DEBUG_GREEN_PEN "PASS\n");
  
    l1cache_instruction_enable(true);
    l1cache_data_enable(true);

    system_info_log_clocks();

    *HW_REG(Dissy, DISP_CTRL0) = 0x0;
    *HW_REG(Dissy, BACKGROUND_COLOUR) = 0x00FFFF00;

    /*    while(true)
    {
        uint32_t beamPos = *HW_REG(Dissy, BeamPosition);
        uint32_t syncs = *HW_REG(Dissy, Syncs);
        if (syncs & 0x2) {
            debug_printf("beampos %i, %i\n", (beamPos & 0xFFFF0000) >> 16, beamPos & 0xFFFF);
            debug_printf("hsync %i vsync %i dispay %i\n", (syncs & 0x1), (syncs & 0x2), (syncs & 0x4));
        }
    }*/

    // setup i2c on hdmi_rx ddc channel
    //   hw_i2c_setup(0, 50, HWI2CS_100KHz, false);

    while (1)
    {
    }
}
int cpu1_main()
{
//    l1cache_instruction_enable(true);
//    l1cache_data_enable(true);

//    debug_print("Blinky cpu1 starting\n");

    while(1)
    {
    }
}