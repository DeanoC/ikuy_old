#include "stdint.h"
#include "stdbool.h"

#include "hw/slcr.h"
#include "hw/devcfg.h"
#include "hw/reg.h"
#include "hw/l1cache.h"
#include "hw_timers/global.h"
#include "serial_debug/debug_print.h"

// full bitstreams are fixed size depending on FPGA size. z7020 are 4MB (32Mb)
//#define BITSTREAM_WORD_LEN ((4 * 1024 * 1024)/4)
// for some reason vivado is preducing binary bitstream of this size
// a little short of the 4MB. Prehaps because it doesn't have 
// a bit file header?
//#define BITSTREAM_WORD_LEN (4045564 / 4)

extern uintptr_t get_bitstream_start_address(void);
extern uintptr_t get_bitstream_end_address(void);

#define BITSTREAM_WORD_LEN ((get_bitstream_end_address() - get_bitstream_start_address())/4)

#define LOG_PCAP_REGISTER(reg) \
	debug_printf(DEBUG_WHITE_PEN "devcfg_" #reg ": " DEBUG_CYAN_PEN "0x%08x\n", *HW_REG(devcfg, reg));

#define LOG_REG_FIELD(reg, field) \
        debug_printf(DEBUG_WHITE_PEN #reg "." #field DEBUG_CYAN_PEN" = 0x%.8x\n", HW_REG_GET_FIELD(devcfg, reg, field))

#define LOG_REG_BIT(reg, field) \
        debug_printf(DEBUG_WHITE_PEN #reg  "." #field DEBUG_CYAN_PEN" = %s\n", HW_REG_GET_BIT(devcfg, reg, field) ? "true":"false")

void hw_fpga_pcap_log_XDCFG_CTRL()
{
    LOG_REG_BIT(XDCFG_CTRL, PCFG_PROG_B);
    LOG_REG_BIT(XDCFG_CTRL, PCFG_POR_CNT_4K);
    LOG_REG_BIT(XDCFG_CTRL, PCAP_PR);
    LOG_REG_BIT(XDCFG_CTRL, PCAP_MODE);
    LOG_REG_BIT(XDCFG_CTRL, PCAP_RATE_EN);
    LOG_REG_BIT(XDCFG_CTRL, MULTIBOOT_EN);
    LOG_REG_BIT(XDCFG_CTRL, JTAG_CHAIN_DIS);
    LOG_REG_BIT(XDCFG_CTRL, PCFG_AES_FUSE);
    LOG_REG_FIELD(XDCFG_CTRL, PCFG_AES_EN);
    LOG_REG_BIT(XDCFG_CTRL, SEU_EN);
    LOG_REG_BIT(XDCFG_CTRL, SEC_EN);
    LOG_REG_BIT(XDCFG_CTRL, SPNIDEN);
    LOG_REG_BIT(XDCFG_CTRL, SPIDEN);
    LOG_REG_BIT(XDCFG_CTRL, NIDEN);
    LOG_REG_BIT(XDCFG_CTRL, DBGEN);
    LOG_REG_FIELD(XDCFG_CTRL, DAP_EN);

}

void hw_fpga_pcap_log_XDCFG_CFG()
{
    LOG_REG_FIELD(XDCFG_CFG, RFIFO_TH);
    LOG_REG_FIELD(XDCFG_CFG, WFIFO_TH);
    LOG_REG_BIT(XDCFG_CFG, RCLK_EDGE);
    LOG_REG_BIT(XDCFG_CFG, WCLK_EDGE);
    LOG_REG_BIT(XDCFG_CFG, DISABLE_SRC_INC);
    LOG_REG_BIT(XDCFG_CFG, DISABLE_DST_INC);
}

void hw_fpga_pcap_log_XDCFG_INT_STS()
{
    LOG_REG_BIT(XDCFG_INT_STS, PSS_GTS_USR_B_INT);
    LOG_REG_BIT(XDCFG_INT_STS, PSS_FST_CFG_B_INT);
    LOG_REG_BIT(XDCFG_INT_STS, PSS_GPWRDWN_B_INT);
    LOG_REG_BIT(XDCFG_INT_STS, PSS_GTS_CFG_B_INT);
    LOG_REG_BIT(XDCFG_INT_STS, PSS_CFG_RESET_B_INT);
    LOG_REG_BIT(XDCFG_INT_STS, IXR_AXI_WERR);
    LOG_REG_BIT(XDCFG_INT_STS, IXR_AXI_RTO);
    LOG_REG_BIT(XDCFG_INT_STS, IXR_AXI_RERR);
    LOG_REG_BIT(XDCFG_INT_STS, IXR_RX_FIFO_OV);
    LOG_REG_BIT(XDCFG_INT_STS, IXR_WR_FIFO_LVL);
    LOG_REG_BIT(XDCFG_INT_STS, IXR_RD_FIFO_LVL);
    LOG_REG_BIT(XDCFG_INT_STS, IXR_DMA_CMD_ERR);
    LOG_REG_BIT(XDCFG_INT_STS, IXR_DMA_Q_OV);
    LOG_REG_BIT(XDCFG_INT_STS, IXR_DMA_DONE);
    LOG_REG_BIT(XDCFG_INT_STS, IXR_D_P_DONE);
    LOG_REG_BIT(XDCFG_INT_STS, IXR_P2D_LEN_ERR);
    LOG_REG_BIT(XDCFG_INT_STS, IXR_PCFG_HMAC_ERR);
    LOG_REG_BIT(XDCFG_INT_STS, IXR_PCFG_SEU_ERR);
    LOG_REG_BIT(XDCFG_INT_STS, IXR_PCFG_POR_B);
    LOG_REG_BIT(XDCFG_INT_STS, IXR_PCFG_CFG_RST);
    LOG_REG_BIT(XDCFG_INT_STS, IXR_PCFG_DONE);
    LOG_REG_BIT(XDCFG_INT_STS, IXR_PCFG_INIT_PE);
    LOG_REG_BIT(XDCFG_INT_STS, IXR_PCFG_INIT_NE);
}

void hw_fpga_pcap_log_XDCFG_STATUS()
{
    LOG_REG_BIT(XDCFG_STATUS, DMA_CMD_Q_F);
    LOG_REG_BIT(XDCFG_STATUS, DMA_CMD_Q_E);
    LOG_REG_FIELD(XDCFG_STATUS, DMA_DONE_CNT);
    LOG_REG_FIELD(XDCFG_STATUS, RX_FIFO_LVL);
    LOG_REG_FIELD(XDCFG_STATUS, TX_FIFO_LVL);
    LOG_REG_BIT(XDCFG_STATUS, PSS_GTS_USR_B);
    LOG_REG_BIT(XDCFG_STATUS, PSS_FST_CFG_B);
    LOG_REG_BIT(XDCFG_STATUS, PSS_GPWRDWN_B);
    LOG_REG_BIT(XDCFG_STATUS, PSS_GTS_CFG_B);
    LOG_REG_BIT(XDCFG_STATUS, SECURE_RST);
    LOG_REG_BIT(XDCFG_STATUS, ILLEGAL_APB_ACCESS);
    LOG_REG_BIT(XDCFG_STATUS, PSS_CFG_RESET_B);
    LOG_REG_BIT(XDCFG_STATUS, PCFG_INIT);
    LOG_REG_BIT(XDCFG_STATUS, EFUSE_SW_RESERVE);
    LOG_REG_BIT(XDCFG_STATUS, EFUSE_SEC_EN);
    LOG_REG_BIT(XDCFG_STATUS, EFUSE_JTAG_DIS);
}

#undef LOG_REG_FIELD
#undef LOG_REG_BIT

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

    hw_fpga_pcap_log_XDCFG_CTRL();
    hw_fpga_pcap_log_XDCFG_CFG();
    hw_fpga_pcap_log_XDCFG_INT_STS();
    hw_fpga_pcap_log_XDCFG_STATUS();
}
#undef LOG_PCAP_REGISTER

bool hw_fpga_is_devcfg_dma_busy()
{
    return(!HW_REG_GET_BIT(devcfg, XDCFG_INT_STS, IXR_DMA_DONE));
}

/* Fix for #672779 */
#define FSBL_XDCFG_IXR_ERROR_FLAGS_MASK (\
                        devcfg_XDCFG_INT_STS_IXR_AXI_WERR_MASK | \
						devcfg_XDCFG_INT_STS_IXR_AXI_RTO_MASK |  \
						devcfg_XDCFG_INT_STS_IXR_AXI_RERR_MASK | \
						devcfg_XDCFG_INT_STS_IXR_RX_FIFO_OV_MASK | \
						devcfg_XDCFG_INT_STS_IXR_DMA_CMD_ERR_MASK |\
						devcfg_XDCFG_INT_STS_IXR_DMA_Q_OV_MASK |   \
						devcfg_XDCFG_INT_STS_IXR_P2D_LEN_ERR_MASK |\
						devcfg_XDCFG_INT_STS_IXR_PCFG_HMAC_ERR_MASK)


bool ClearPcapStatus(void)
{

	uint32_t StatusReg;
	uint32_t IntStatusReg;

	/*
	 * Clear it all, so if Boot ROM comes back, it can proceed
	 */
    *HW_REG(devcfg, XDCFG_INT_STS) = 0xFFFFFFFF;

	/*
	 * Get PCAP Interrupt Status Register
	 */
    IntStatusReg = *HW_REG(devcfg, XDCFG_INT_STS);
	if (IntStatusReg & FSBL_XDCFG_IXR_ERROR_FLAGS_MASK) {
		debug_printf("FATAL errors in PCAP 0x%.8x\n", IntStatusReg);
		return false;
	}

	/*
	 * Read the PCAP status register for DMA status
	 */
	StatusReg = *HW_REG(devcfg, XDCFG_STATUS);

	debug_printf("PCAP:StatusReg = 0x%.8x\n", StatusReg);

	/*
	 * If the queue is full, return w/ XST_DEVICE_BUSY
	 */
	if ((StatusReg & devcfg_XDCFG_STATUS_DMA_CMD_Q_F_MASK) ==
			devcfg_XDCFG_STATUS_DMA_CMD_Q_F_MASK) {

		debug_printf("PCAP_DEVICE_BUSY\n");
		return false;
	}

	debug_printf("PCAP:device ready\n");

	/*
	 * There are unacknowledged DMA commands outstanding
	 */
	if ((StatusReg & devcfg_XDCFG_STATUS_DMA_CMD_Q_E_MASK) !=
			devcfg_XDCFG_STATUS_DMA_CMD_Q_E_MASK) {

        IntStatusReg = *HW_REG(devcfg, XDCFG_INT_STS);

		if ((IntStatusReg & devcfg_XDCFG_INT_STS_IXR_DMA_DONE_MASK) !=
				devcfg_XDCFG_INT_STS_IXR_DMA_DONE_MASK){
			/*
			 * Error state, transfer cannot occur
			 */
			debug_printf("PCAP:IntStatus indicates error\n");
			return false;
		}
		else {
			/*
			 * clear out the status
			 */
            IntStatusReg = *HW_REG(devcfg, XDCFG_INT_STS);
		}
	}

	if ((StatusReg & devcfg_XDCFG_STATUS_DMA_DONE_CNT_MASK) != 0) {
        *HW_REG(devcfg, XDCFG_STATUS) = StatusReg | devcfg_XDCFG_STATUS_DMA_DONE_CNT_MASK;

	}

	debug_printf("PCAP:Clear done\n");
    return true;
}

bool FabricInit(void)
{
	uint32_t TimerExpired = 0;
	uint64_t tCur = 0;
	uint64_t tEnd = 0;


	/*
	 * Set Level Shifters DT618760 - PS to PL enabling
	 */
    *HW_REG(slcr, LVL_SHFTR_EN) = 0x0000000A;

	/*
	 * Check the PL power status
	 */
    if(!HW_REG_GET_BIT(devcfg, XDCFG_MCTRL, PCFG_POR_B) )
    {
        debug_print("Fabric not powered up\n");
        return false;
    }

TryAgain:
    HW_REG_SET_BIT(devcfg, XDCFG_CTRL, PCFG_PROG_B);
    HW_REG_CLR_BIT(devcfg, XDCFG_CTRL, PCFG_PROG_B);
    tCur = hw_timers_global_get();
	do
	{
		if(!HW_REG_GET_BIT(devcfg, XDCFG_STATUS, PCFG_INIT))
		{
			break;
		}
        tEnd = hw_timers_global_get();

		if(hw_timers_global_get_elapsed(tCur, tEnd) > 1.0f)
		{
            if(TimerExpired < 2)
            {
    			TimerExpired++;
                goto TryAgain;
            } else 
            {
                debug_print("Fabric Init failed\n");
                return false;
            }
		}

	} while(1);

	/*
	 * Setting PCFG_PROG_B signal to high
	 */
    HW_REG_SET_BIT(devcfg, XDCFG_CTRL, PCFG_PROG_B); 

	/*
	 * Polling the PCAP_INIT status for Set
	 */
	while(!HW_REG_GET_BIT(devcfg, XDCFG_STATUS, PCFG_INIT));

	//	debug_printf("Devcfg Status register = 0x%x\n",StatusReg);
    hw_fpga_pcap_log_XDCFG_STATUS();
	debug_print("PCAP:Fabric is Initialized done\n");

	return true;
}

/******************************************************************************/
/**
*
* This function Polls for the DMA done or FPGA done.
*
* @param	none
*
* @return
*		- XST_SUCCESS if polling for DMA/FPGA done is successful
*		- XST_FAILURE if polling for DMA/FPGA done fails
*
* @note		none
*
****************************************************************************/
bool XDcfgPollDone(uint32_t MaskValue)
{
	uint32_t IntrStsReg = 0;
    uint64_t time_start = hw_timers_global_get();
    uint64_t dbg_time_start = hw_timers_global_get();
	/*
	 * poll for the DMA done
	 */
	IntrStsReg = *HW_REG(devcfg, XDCFG_INT_STS);
	while ((IntrStsReg & MaskValue) != MaskValue) {
		IntrStsReg = *HW_REG(devcfg, XDCFG_INT_STS);

		if (IntrStsReg & FSBL_XDCFG_IXR_ERROR_FLAGS_MASK) {
				debug_printf(DEBUG_RED_PEN "FATAL errors in PCAP %x\r\n", IntrStsReg);
                hw_fpga_pcap_log_registers();
				return false;
		}

        if(hw_timers_global_get_elapsed(time_start, hw_timers_global_get()) > 30.0f)
        {
        	debug_print(DEBUG_RED_PEN"PCAP transfer timed out\n");
			return false;
		}

        if(hw_timers_global_get_elapsed(dbg_time_start, hw_timers_global_get()) > 0.3f)
        {
            debug_print(DEBUG_GREEN_PEN ".");
            dbg_time_start = hw_timers_global_get();
        }
	}

	debug_print("\n");

	*HW_REG(devcfg, XDCFG_INT_STS) = IntrStsReg & MaskValue;

	return true;
}


bool hw_fpga_pcap_upload_bitstream(uintptr_t addr)
{
/*    // reset
	*HW_REG(devcfg, XDCFG_CFG) = 0x508;
    // unlock devcfg
    *HW_REG(devcfg, XDCFG_UNLOCK) = 0x757BDF0D;
    // disable devcfg interrupts
    *HW_REG(devcfg, XDCFG_INT_MASK) = 0xFFFFFFFF;
    // clear interrupts
    *HW_REG(devcfg, XDCFG_INT_STS) = *HW_REG(devcfg, XDCFG_INT_STS); // all bits write to clear

    // flush d1 cache
    l1cache_data_flush_all();

    // level shifter already enabled in boot     
    HW_REG_CLR_BIT(devcfg, XDCFG_CTRL, PCFG_POR_CNT_4K);

    // check fpga fabric is powered up
    if( HW_REG_GET_FIELD(devcfg, XDCFG_MCTRL, PCFG_POR_B) == 0)
    {
        debug_print(DEBUG_RED_PEN "ERROR: FPGA Fabric not powered up!\n");
        return false;
    }
*/
    // temp hack endianswap TODO do as cart attach process 
    uint8_t* ptr = (uint8_t*)addr;
    for(int i=0;i < BITSTREAM_WORD_LEN;++i)
    {
        uint8_t a = ptr[0];
        uint8_t b = ptr[1];
        uint8_t c = ptr[2];
        uint8_t d = ptr[3];
        ptr[0] = d;
        ptr[1] = c;
        ptr[2] = b;
        ptr[3] = a;
        ptr+=4;
    }

    if (!ClearPcapStatus()) {
		debug_printf(DEBUG_RED_PEN "PCAP_CLEAR_STATUS_FAIL\n");
		return false;
	}
    if(!FabricInit()) {
		debug_printf(DEBUG_RED_PEN "PCAP Fabric Init Failed!\n");
		return false;
    }

    // enable pcap mode
    HW_REG_SET_BIT(devcfg, XDCFG_CTRL, PCAP_MODE);

    // disable loop back
    HW_REG_CLR_BIT(devcfg, XDCFG_MCTRL, PCAP_LPBK);
    // full speed
    HW_REG_CLR_BIT(devcfg, XDCFG_CTRL, PCAP_RATE_EN);
/*
    if(hw_fpga_is_devcfg_dma_busy())
    {
        debug_print(DEBUG_YELLOW_PEN "WARN: FPGA DMA is busy before upload!\n");
    }*/

    // now issue the dma
    *HW_REG(devcfg, XDCFG_DMA_SRC_ADDR) = addr | 0x01;
    *HW_REG(devcfg, XDCFG_DMA_DEST_ADDR) = 0xFFFFFFFF; // special marker for FPGA configuration
    *HW_REG(devcfg, XDCFG_DMA_SRC_LEN) = BITSTREAM_WORD_LEN;
    *HW_REG(devcfg, XDCFG_DMA_DEST_LEN) = 0;

    //hw_fpga_pcap_log_registers();

    debug_print(DEBUG_WHITE_PEN "FPGA DMA ");
    uint64_t dma_time_start = hw_timers_global_get();
    uint64_t dbg_time_start = dma_time_start;
    do
    {
        if( hw_timers_global_get_elapsed(dma_time_start, hw_timers_global_get()) > 20.0f)
        {
            debug_print(DEBUG_RED_PEN "\nERROR: bitstream upload dma timed out!\n");
            hw_fpga_pcap_log_registers();
            return false;
        } 
        if(HW_REG_GET_BIT(devcfg, XDCFG_INT_STS, IXR_DMA_CMD_ERR))
        {
            debug_print(DEBUG_RED_PEN "\nERROR: bitstream upload dma CMD ERR!\n");
            hw_fpga_pcap_log_registers();
            return false;
        }
        if(HW_REG_GET_BIT(devcfg, XDCFG_INT_STS, IXR_AXI_WERR))
        {
            debug_print(DEBUG_RED_PEN "\nERROR: bitstream upload dma AXI_WERR!\n");
            hw_fpga_pcap_log_registers();
            return false;
        }
        if(HW_REG_GET_BIT(devcfg, XDCFG_INT_STS, IXR_AXI_RERR))
        {
            debug_print(DEBUG_RED_PEN "\nERROR: bitstream upload dma AXI_RERR!\n");
            hw_fpga_pcap_log_registers();
            return false;
        }
        if(hw_timers_global_get_elapsed(dbg_time_start, hw_timers_global_get()) > 0.3f)
        {
            debug_print(DEBUG_GREEN_PEN ".");
            dbg_time_start = hw_timers_global_get();
        }
    } while(hw_fpga_is_devcfg_dma_busy());

    debug_printf(DEBUG_GREEN_PEN " OK " DEBUG_CYAN_PEN " Time = %fms\n", hw_timers_global_get_elapsed(dma_time_start, hw_timers_global_get()) * 1000.0f );

    debug_print(DEBUG_WHITE_PEN "FPGA DONE ");
	if (!XDcfgPollDone(devcfg_XDCFG_INT_STS_IXR_PCFG_DONE_MASK)) {
		debug_printf("PCAP_FPGA_DONE_FAIL\r\n");
		return false;
	}

/*    dma_time_start = hw_timers_global_get();
    do
    {
        if( hw_timers_global_get_elapsed(dma_time_start, hw_timers_global_get()) > 20.0f)
        {
            debug_print(DEBUG_RED_PEN "\nERROR: bitstream DONE timed out!\n");
            hw_fpga_pcap_log_registers();

            return false;
        } 
    } while( !HW_REG_GET_BIT(devcfg, XDCFG_INT_STS, IXR_PCFG_DONE) );*/
    debug_print(DEBUG_GREEN_PEN " OK\n");

    return true;
}