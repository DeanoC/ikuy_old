#include <stdbool.h>

#include "serial_debug/uart_control.h"
#include "serial_debug/debug_print.h"
#include "hw_timers/global.h"
#include "system_info/cpu.h"

#include "hw/arma9_cop.h"
#include "hw/l1cache.h"
#include "hw/devcfg.h"
#include "hw/uart.h"
#include "hw/reg.h"
#include "hw/slcr.h"
#include "hw/scu.h"
#include "hw/reg.h"
#include "hw/memory_map.h"

extern void slcrRunInitProgram(void);
extern void slcrRunPostDDRInitProgram(void);
extern void debugRunInitProgram(void);
extern void ddrcRunInitProgram(void);
extern void uartRunInitProgram(void);
extern void mmuInit(void);
int ps7_init(void);
int ps7_post_config(void);

extern void move_ocm_high(void);
extern void wake_cpu1();
extern void* check_app_cpu0_loaded();
extern void* check_app_cpu1_loaded();


void cpu1_main();

bool ddrEarlyMemTest();


void software_interrupt()
{
    debug_unsafe_print(DEBUG_RED_PEN "SOFTWARE INTERRUPT\n");
}

void irq_interrupt()
{
    debug_unsafe_print(DEBUG_RED_PEN "IRQ INTERRUPT\n");
}

void fiq_interrupt()
{
    debug_unsafe_print(DEBUG_RED_PEN "FIQ INTERRUPT\n");
}

int main(int argc, char const *argv[])
{
    // assert the FCLKs reset line (to stop hopefully all PL action)
    {
        HW_REG_SET_BIT(devcfg, XDCFG_CTRL, PCFG_PROG_B);

        *HW_REG(slcr, SLCR_UNLOCK) = 0xDF0DU;
        *HW_REG(slcr, FPGA_RST_CTRL) = 0xF;
        *HW_REG(slcr, SLCR_LOCK) = 0x767B;

        HW_REG_CLR_BIT(devcfg, XDCFG_CTRL, PCFG_PROG_B);
    }

    // init uart early for debugging
    uartRunInitProgram();

    // step up our debug uart baud to 921600!
    // make the uart fifo as big as allowed
    debug_set_uart_freq(DUF_BAUD_921600);
    debug_set_uart_fifo_size(0x2F);

    debug_unsafe_print(DEBUG_CLR_SCREEN);
    debug_unsafe_print(DEBUG_WHITE_PEN "** ikuy booting **\n");

    // System Level Control Registers
    debug_unsafe_print(DEBUG_WHITE_PEN "System Level Configuration Init ");
    // slcr requires the uart tx fifo is empty
    debug_uart_stall_till_transmit_fifo_is_empty();

    slcrRunInitProgram();
    debug_unsafe_print(DEBUG_GREEN_PEN "OK\n");

    // ddr
    debug_unsafe_print(DEBUG_WHITE_PEN "DDR Init ");
    ddrcRunInitProgram();
    slcrRunPostDDRInitProgram();
    debug_unsafe_print(DEBUG_GREEN_PEN "OK\n");

    // reset and kick off the global timer
    hw_timers_global_reset();
    uint64_t timeStart = hw_timers_global_get();

    debug_unsafe_print(DEBUG_WHITE_PEN "DDR Early MemTest ");

    bool ddrEarlyMemTestOk = ddrEarlyMemTest();
    uint64_t timeEnd = hw_timers_global_get();
    if (ddrEarlyMemTestOk)
    {
        debug_unsafe_print(DEBUG_GREEN_PEN "OK ");
    } else 
    {
        debug_unsafe_print(DEBUG_RED_PEN "FAIL ");
    }
    debug_unsafe_printf(DEBUG_YELLOW_PEN "Time = %fs\n", hw_timers_global_get_elapsed(timeStart, timeEnd));

    debug_unsafe_print(DEBUG_WHITE_PEN "Moving boot low OCM to DDR ");
    move_ocm_high();
    debug_unsafe_print(DEBUG_GREEN_PEN "OK\n");
    // low ocm doesn't exist now and we are running from DDR   

    debug_unsafe_print(DEBUG_WHITE_PEN "CPU1 being woken\n");
    wake_cpu1();
    debug_unsafe_printf(DEBUG_GREEN_PEN "GO GO GO\n");

    debug_uart_stall_till_transmit_fifo_is_empty();

    while (1)
    {
        void (*jumpaddr)() = check_app_cpu0_loaded();
        if( jumpaddr != 0)
        {
            jumpaddr();
        }
    }
}

void cpu1_main()
{
    debug_unsafe_printf("cpu1 up\n");
    debug_uart_stall_till_transmit_fifo_is_empty();
    while (1)
    {
        void (*jumpaddr)() = check_app_cpu1_loaded();
        if( jumpaddr != 0)
        {
            jumpaddr();
        }
    }
}

void abort_exception(uint32_t type, uint32_t lr)
{
    debug_unsafe_printf(DEBUG_RED_PEN "ABORT EXCEPTION %u at 0x%.8x\n", type, lr);
    while(1)
    {
    }
}
