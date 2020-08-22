#include "stdint.h"
#include "stdbool.h"

#include "hw/slcr.h"
#include "hw/devcfg.h"
#include "hw/reg.h"
#include "hw_timers/global.h"
#include "serial_debug/debug_print.h"

// full bitstreams are fixed size depending on FPGA size. z7020 are 4MB (32Mb)
//#define BITSTREAM_SIZE (4 * 1024 * 1024)
// for some reason vivado is preducming binart bitstream of this size/
// a little short of the 4MB is mean to be??
#define BITSTREAM_SIZE 4045564

#define LOG_PCAP_REGISTER(reg) \
	debug_printf(DEBUG_WHITE_PEN "devcfg_" #reg ": " DEBUG_GREEN_PEN "0x%08x\n", *HW_REG(devcfg, reg));

void hw_fpga_pcap_log_registers()
{
    debug_print(DEBUG_WHITE_PEN "PCAP register dump\n------\n");
    LOG_PCAP_REGISTER(XDCFG_CTRL);
    LOG_PCAP_REGISTER(XDCFG_CFG);
    LOG_PCAP_REGISTER(XDCFG_INT_STS);
    LOG_PCAP_REGISTER(XDCFG_INT_MASK);
    LOG_PCAP_REGISTER(XDCFG_STATUS);
    LOG_PCAP_REGISTER(XDCFG_DMA_SRC_ADDR);
    LOG_PCAP_REGISTER(XDCFG_DMA_DEST_ADDR);
    LOG_PCAP_REGISTER(XDCFG_DMA_SRC_LEN);
    LOG_PCAP_REGISTER(XDCFG_DMA_DEST_LEN);
    LOG_PCAP_REGISTER(XDCFG_MCTRL);
}

bool hw_fpga_pcap_upload_bitstream(uintptr_t addr)
{
    // enable all level shifters
    HW_REG_MERGE(slcr, LVL_SHFTR_EN, slcr_LVL_SHFTR_EN_USER_LVL_SHFTR_EN_MASK, 0xF);

    // check fpga fabric is powered up
    if( HW_REG_GET_FIELD(devcfg, XDCFG_MCTRL, PCFG_POR_B) == 0)
    {
        debug_print(DEBUG_RED_PEN "ERROR: FPGA Fabric not powered up!\n");
        return false;
    }
    // set program bit high
    HW_REG_SET_BIT(devcfg, XDCFG_CTRL, PCFG_PROG_B);
    // set program bit low
    HW_REG_CLR_BIT(devcfg, XDCFG_CTRL, PCFG_PROG_B);

    uint64_t init_time_start = hw_timers_global_get();

    while(HW_REG_GET_BIT(devcfg, XDCFG_STATUS, PCFG_INIT))
    {
        if( hw_timers_global_get_elapsed(init_time_start, hw_timers_global_get()) > 1.0f)
        {
            debug_print(DEBUG_RED_PEN "ERROR: FPGA Fabric init timed out!\n");
            return false;
        }
    }
    HW_REG_SET_BIT(devcfg, XDCFG_CTRL, PCFG_PROG_B);
    while(!HW_REG_GET_FIELD(devcfg, XDCFG_STATUS, PCFG_INIT));

    // disable loop back
    HW_REG_CLR_BIT(devcfg, XDCFG_MCTRL, PCAP_LPBK);
    // full speed
    HW_REG_CLR_BIT(devcfg, XDCFG_CTRL, PCAP_RATE_EN);

    // now issue the dma
    *HW_REG(devcfg, XDCFG_DMA_SRC_ADDR) = addr;
    *HW_REG(devcfg, XDCFG_DMA_DEST_ADDR) = 0xFFFFFFFF; // special marker for FPGA configuration
    *HW_REG(devcfg, XDCFG_DMA_SRC_LEN) = BITSTREAM_SIZE;
    *HW_REG(devcfg, XDCFG_DMA_DEST_LEN) = BITSTREAM_SIZE;

    uint64_t dma_time_start = hw_timers_global_get();
    while(HW_REG_GET_BIT(devcfg, XDCFG_INT_STS, IXR_D_P_DONE))
    {
        if( hw_timers_global_get_elapsed(dma_time_start, hw_timers_global_get()) > 1.0f)
        {
            debug_print(DEBUG_RED_PEN "ERROR: bitstream upload dma timed out!\n");
            return false;
        }
    }

    return true;
}