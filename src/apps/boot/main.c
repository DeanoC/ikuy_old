#include <hw/devcfg.h>
#include <hw/uart.h>
#include <hw/reg.h>
#include <stdbool.h>

#include "serial_debug/uart_control.h"
#include "serial_debug/debug_print.h"
#include "hw_timers/global.h"
#include "system_info/cpu.h"
#include "hw/arm_cop.h"

#include "hw/slcr.h"
#include "hw/scu.h"
#include "hw/reg.h"
#include "hw/memory_map.h"

extern void slcrRunInitProgram();
extern void slcrRunPostDDRInitProgram();
extern void ddrcRunInitProgram();
extern void uartRunInitProgram();

extern void move_ocm_high(void);

bool ddrEarlyMemTest();


void software_interrupt()
{
    debug_print(DEBUG_RED_PEN "SOFTWARE INTERRUPT\n");
    while (1)
    {
    }
}

void irq_interrupt()
{
    debug_print(DEBUG_RED_PEN "SOFTWARE INTERRUPT\n");
    while (1)
    {
    }
}

void fiq_interrupt()
{
    debug_print(DEBUG_RED_PEN "SOFTWARE INTERRUPT\n");
    while (1)
    {
    }
}

void program_scu_to_move_ocm_high()
{
    *HW_REG(slcr, SLCR_UNLOCK) = 0xDF0DU;
    *HW_REG(slcr, OCM_CFG) = 0xF;
    *HW_REG(slcr, SLCR_LOCK) = 0x767B;
}

int main(int argc, char const *argv[])
{
    // init uart early for debugging
    uartRunInitProgram();

    // step up our debug uart baud to 921600!
    // make the uart fifo as big as allowed
    debug_set_uart_freq(DUF_BAUD_921600);
    debug_set_uart_fifo_size(0x2F);

    debug_print(DEBUG_CLR_SCREEN);
    debug_print(DEBUG_WHITE_PEN "** ikuy booting **\n");

    debug_print(DEBUG_WHITE_PEN "System Level Configuration Init ");
    // slcr requires the uart tx fifo is empty
    debug_uart_stall_till_transmit_fifo_is_empty();

    // System Level Control Registers
    slcrRunInitProgram();
    debug_print(DEBUG_GREEN_PEN "OK\n");

    // ddr
    debug_print(DEBUG_WHITE_PEN "DDR Init ");
    ddrcRunInitProgram();
    slcrRunPostDDRInitProgram();
    debug_print(DEBUG_GREEN_PEN "OK\n");

    // log clocks 
    system_info_log_clocks();

    // reset and kick off the global timer
    hw_timers_global_reset();
    uint64_t timeStart = hw_timers_global_get();

    debug_print(DEBUG_WHITE_PEN "DDR Early MemTest ");

    bool ddrEarlyMemTestOk = ddrEarlyMemTest();
    uint64_t timeEnd = hw_timers_global_get();
    if (ddrEarlyMemTestOk)
    {
        debug_print(DEBUG_GREEN_PEN "OK ");
    } else 
    {
        debug_print(DEBUG_RED_PEN "FAIL ");
    }

    debug_printf(DEBUG_YELLOW_PEN "Time = %fs\n", hw_timers_global_get_elapsed(timeStart, timeEnd));

    debug_printf(DEBUG_WHITE_PEN "Moving boot low OCM to DDR ");
    move_ocm_high();
    // low ocm doesn't exist now and we are running from DDR   
 
    debug_print(DEBUG_GREEN_PEN "OK\n");
/*
    uint32_t v = arm_cop_main_id();
    debug_printf("main id 0x%.08x\n", v);
*/
    while (1)
    {
        // infinite loop
    }
}

void abort_exception(uint32_t type, uint32_t lr)
{
    debug_print(DEBUG_RED_PEN "ABORT EXCEPTION\n");
    while(1){}
}
