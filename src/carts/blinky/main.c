#include <assert.h>
#include "serial_debug/debug_print.h"
#include "zynq_ps/l1cache.h"
#include "hw_fpga/pcap.h"
#include "hw_i2c/i2c.h"
#include "system_info/cpu.h"

extern uintptr_t get_bitstream_start_address(void);
extern uintptr_t get_bitstream_end_address(void);

int cpu0_main()
{
    debug_print(DEBUG_WHITE_PEN "\nBlinky cpu0 starting\n");

    hw_fpga_pcap_upload_bitstream(get_bitstream_start_address());

    debug_print(DEBUG_WHITE_PEN "AXI GP0 PS Master test ");
    // reset isn't occuring properly at the moment...
    (*(uint32_t *)0x40000000) = 0xDEA0DEA0;
    assert(*(uint32_t *)0x40000000 == 0xDEA0DEA0);
    assert(*(uint32_t *)0x40000004 == 0x00000004);

    // write to the test register (its a simple 32 bit register)
    *(uint32_t *)0x40000000 = 0x0A0B0C0D;
    assert(*(uint32_t *)0x40000000 == 0x0A0B0C0D);
    debug_print(DEBUG_GREEN_PEN "PASS\n");
    /*
    debug_print(DEBUG_WHITE_PEN "AXI GP1 PS Master test ");
    assert(*(uint32_t *)0x80000000 == 0xDCDCDCDC);
    assert(*(uint32_t *)0x80000004 == 0x00000004);

    // write to the test register (its a simple 32 bit register)
    *(uint32_t *)0x80000000 = 0x0A0B0C0D;
    assert(*(uint32_t *)0x80000000 == 0x0A0B0C0D);
    debug_print(DEBUG_GREEN_PEN "PASS\n");
*/
    l1cache_instruction_enable(true);
    l1cache_data_enable(true);

    system_info_log_clocks();

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