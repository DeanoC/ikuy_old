// much of this is based on the excellent book on arm a9 bare metal setup
// by Daniels Umanovskis https://github.com/umanovskis/

#include "board_parameters.h"

// Some defines for both interupt and supervisor modes (which we run in)
// and abort/exception
.equ MODE_FIQ, 0x011
.equ MODE_IRQ, 0x012
.equ MODE_SVC, 0x013
.equ MODE_ABORT, 0x017
.equ MODE_UNDEFINED_INSTRUCTION, 0x01A

.equ SLCR_LOCK_REG, 0xf8000004
.equ SLCR_UNLOCK_REG, 0xf8000008
.equ SLCR_OCM_CFG, 0xf8000910


.section .vector_table, "x"
.global _reset
.global _asm_start
.global move_ocm_high 
.global abort_exception
.global cpu1_wait_loop
.global get_core_id
.global wake_cpu1
.global own_uart
.global release_uart

_reset:
    b _asm_start
    b undefined_instruction_handler       /* 0x4  Undefined Instruction */
    b software_interrupt_handler     /* 0x8  Software Interrupt */
    b prefetch_abort_exception       /* 0xC  Prefetch Abort */
    b data_abort_handler           /* 0x10 Data Abort */
    b . /* 0x14 Reserved */
    b irq_interrupt /* 0x18 IRQ */
    b fiq_interrupt /* 0x1C FIQ */

    .section .text
.set CRValMmuCac,	0b0100000000000001	/* Enable IDC, and MMU */

_asm_start:
    ldr r0, =_cpu1_wait_resume
    mov r1, #0
    str r1, [r0]

    // if cpu 1 get here jump to cpu_setup
	mrc	p15,0,r0,c0,c0,5
	and	r0, r0, #0xf
    cmp	r0, #1
    beq cpu1_wait_loop

    // if we got here we are cpu 0   
    ldr r0, = debug_uart_lock
    mov r1, #0
    str r1, [r0]

clear_ocm_stacks:
    // clear all stack memory to 0xDCDCDCDC
    ldr r0, =_svc_stack_end
    ldr r1, =_cpu1_abort_stack_start
    ldr r2, =#0xDCDCDCDC
clear_stack_loop:
    cmp r0, r1
    strlt r2, [r0], #4
    blt clear_stack_loop

    // setup stacks 
    msr cpsr_c, MODE_FIQ
    ldr sp, =_fiq_stack_start
    msr cpsr_c, MODE_IRQ
    ldr sp, =_irq_stack_start
    // these two share a stack
    msr cpsr_c, MODE_ABORT
    ldr sp, =_abort_stack_start
    msr cpsr_c, MODE_UNDEFINED_INSTRUCTION
    ldr sp, =_abort_stack_start

    // our 'real' stack (SUPERVISOR mode)
    msr cpsr_c, MODE_SVC       
    ldr sp, =_svc_stack_start
    /* Start copying data */
    ldr r0, =_text_end
    ldr r1, =_data_start
    ldr r2, =_data_end
data_loop:
    cmp r1, r2
    ldrlt r3, [r0], #4
    strlt r3, [r1], #4
    blt data_loop

    /* Initialize .bss */
    mov r0, #0
    ldr r1, =_bss_start
    ldr r2, =_bss_end
bss_loop:
    cmp r1, r2
    strlt r0, [r1], #4
    blt bss_loop

    bl cpu_init
    bl ready_cpu1 // if a cold boot wake up cpu1 to move it to our wait area

    b main
cpu_init:
    /* Clear cp15 regs with unknown reset values */
	mov	r0, #0x0
	mcr	p15, 0, r0, c5, c0, 0	/* DFSR */
	mcr	p15, 0, r0, c5, c0, 1	/* IFSR */
	mcr	p15, 0, r0, c6, c0, 0	/* DFAR */
	mcr	p15, 0, r0, c6, c0, 2	/* IFAR */
	mcr	p15, 0, r0, c9, c13, 2	/* PMXEVCNTR */
	mcr	p15, 0, r0, c13, c0, 2	/* TPIDRURW */
	mcr	p15, 0, r0, c13, c0, 3	/* TPIDRURO */
    bx lr 

    // This relys on -fPIC code for the boot module
move_ocm_high:
    // Start copying code and data to ddr
    ldr r0, =_bss_end           // last used part of low memory
    mov r1, #0                  // src
    ldr	r2, =#DDR_START         // dest = ddr start addess
ocmlo_loop:
    cmp r1, r0
    ldrlt r3, [r1], #4
    strlt r3, [r2], #4
    blt ocmlo_loop

    // move cpu1 to a ddr wait space (address are pc relative)
    // as we haven't jumped to ddr yet, we have to fix cpu1
    // addresses manually
    ldr	r0, =#DDR_START         // dest = ddr start addess
    ldr r2, =_cpu1_wait_resume  // r2 = ocm cpu1 wait resume variable
    mov r3, r2
    add r3, r3, r0              // r3 = ddr cpu1 wait resume variable
    mov r0, #0
    str r0, [r3]                // ensure its zer0 

    ldr	r0, =#DDR_START         // dest = ddr start addess
    ldr r1, =cpu1_setup
    add r1, r1, r0              // compute new wait loop address
    str r1, [r2]                // set ocm jump to to the ddr wait code
    sev                         // wake up cpu1 so it can jump to ddr

    wfe                         // wait for cpu1 to signal us

    ldr	r0, =#DDR_START         // dest = ddr start addess
    // cpu1 relocated, now do ourselves in cpu0
    // branch to the same code in ddr so we can move the ocm
    add lr, r0      // new link address
    mov r1, pc      // get the current pc 
    add r1, r0      // add the ddr base
    add r1, #8      // and offset the instructions since copying pc
    bx r1           // jump to the next instruction to this but in ddr

     /* set VBAR to DDR start (where a copy of the vector table now lives  */
    ldr	r0, =#DDR_START
	mcr	p15, 0, r0, c12, c0, 0

    // unlock and update ocm to all high
    ldr r0, =SLCR_UNLOCK_REG
    ldr r1, =#0x0000DF0D
    str r1, [r0]
    ldr r0, =SLCR_OCM_CFG
    mov r1, #0x1F
    str r1, [r0]
    ldr r0, =SLCR_LOCK_REG
    ldr r1, =#0x0000767B
    str r1, [r0]

    // set the ddr reserve top to 0
    ldr r0, =ddr_reserved_top
    mov r1, #0
    str r1, [r0]

    // at this point OCM is now mapped high (low OCM addresses are now 
    // exceptions). the stacks are still mapped into the top of
    // OCM high and CPU1 is waiting for a wake up event there as well.

	// set scu enable bit in scu
	ldr	r1, =0xf8f00000
	ldr	r0, [r1]
	orr	r0, r0, #0x1
	str	r0, [r1]

    // enable smp mode for both cores
	ldr	r1, =0xf8f00004
	ldr	r0, [r1]
	orr	r0, r0, #0x30
	str	r0, [r1]

	// enable MMU
	ldr	r0,=MMUTable			// Load MMU translation table base */
	orr	r0, r0, #0x5B			// Outer-cacheable, WB */
	mcr	15, 0, r0, c2, c0, 0	// TTB0
	mvn	r0,#0				    // Load MMU domains -- all ones=manager
	mcr	p15,0,r0, c3, c0,0
	ldr	r0,=#0x1                // mmu only
	mcr	p15,0,r0,c1,c0,0		
	dsb					        // dsb	allow the MMU to start up
	isb					        // isb	flush prefetch buffer

	/* Write to ACTLR */
	mrc	p15, 0, r0, c1, c0, 1		// Read ACTLR
	orr	r0, r0, #(0x01 << 6)		// set SMP bit
	orr	r0, r0, #(0x01 )		    // Cache/TLB maintenance broadcast
	mcr	p15, 0, r0, c1, c0, 1		// Write ACTLR

    bx lr

    // called from cpu0 to move cpu1 out of the bootrom wait area on
    // cold boot. On warm boot isn't neccessary but doesn't hurt
ready_cpu1:
    mvn r0, #0xF // address cpu1 will jump on cold boot
    ldr r1, =cpu1_setup
    str r1, [r0]
    sev
    bx lr

cpu1_setup:
    msr cpsr_c, MODE_FIQ
    ldr sp, =_cpu1_fiq_stack_start
    msr cpsr_c, MODE_IRQ
    ldr sp, =_cpu1_irq_stack_start
    // these two share a stack
    msr cpsr_c, MODE_ABORT
    ldr sp, =_cpu1_abort_stack_start
    msr cpsr_c, MODE_UNDEFINED_INSTRUCTION
    ldr sp, =_cpu1_abort_stack_start
    // our 'real' stack (SUPERVISOR mode)
    msr cpsr_c, MODE_SVC       
    ldr sp, =_cpu1_svc_stack_start

    ldr	r0, =#DDR_START
	mcr	p15, 0, r0, c12, c0, 0

	// enable MMU
	ldr	r0,=MMUTable			// Load MMU translation table base */
	orr	r0, r0, #0x5B			// Outer-cacheable, WB */
	mcr	15, 0, r0, c2, c0, 0	// TTB0
	mvn	r0,#0				    // Load MMU domains -- all ones=manager
	mcr	p15,0,r0, c3, c0,0
	ldr	r0,=#0x1                // mmu only
	mcr	p15,0,r0,c1,c0,0		
	dsb					        // dsb	allow the MMU to start up
	isb					        // isb	flush prefetch buffer

	/* Write to ACTLR */
	mrc	p15, 0, r0, c1, c0, 1		// Read ACTLR
	orr	r0, r0, #(0x01 << 6)		// set SMP bit
	orr	r0, r0, #(0x01 )		    // Cache/TLB maintenance broadcast
	mcr	p15, 0, r0, c1, c0, 1		// Write ACTLR

    bl cpu_init
    sev
cpu1_wait_loop:
    ldr r0, =_cpu1_wait_resume
    ldr r0, [r0]
    cmp r0, #0
    bne cpu1_jump
    wfe
    b cpu1_wait_loop
cpu1_jump:
    bx r0

get_core_id:
	mrc	p15,0,r0,c0,c0,5
	and	r0, r0, #0xf
    bx lr


// r0 address of routine to wake and run
wake_cpu1:
    ldr r0, =cpu1_main
    ldr	r1, =#DDR_START
    add r0, r1
    ldr r2, =_cpu1_wait_resume 
    str r0, [r2]                
    sev
    bx lr

own_uart:
    MOV r1, #0x0                // free at the moment
    MOV r3, #0x1                // some one owns it
uart_lock:
    ldr r2, =debug_uart_lock
uart_lock_retry:
    LDREX r0, [r2]              // fetch with tag
    CMP r0, r1                  // is the lock free?
    BNE uart_lock_retry
    STREXEQ r0, r3, [r2]        // try and claim the lock
    CMPEQ r0, #0                // did this succeed?
    BNE uart_lock_retry         // no – try again
    bx lr

release_uart:
    MOV r1, #0x1                // we own it                
    MOV r3, #0x0                // free again
rel_uart_lock:
    ldr r2, =debug_uart_lock
rel_uart_lock_retry:
    LDREX r0, [r2]              // fetch with tag
    CMP r0, r1                  // is the lock free?
    BNE rel_uart_lock_retry
    STREXEQ r0, r3, [r2]        // try and claim the lock
    CMPEQ r0, #0                // did this succeed?
    BNE rel_uart_lock_retry         // no – try again
    bx lr

one_infinite_loop:
    b one_infinite_loop

software_interrupt_handler:
    sub lr, lr, #4
    stmfd sp!, {r0-r12, lr}
    mov r0, #0
    mov r1, lr
    bl software_interrupt
    ldmfd sp!, {r0-r12, lr}
    b one_infinite_loop

data_abort_handler:
    sub lr, lr, #4
    stmfd sp!, {r0-r12, lr}
    mov r0, #0
    mov r1, lr
    bl abort_exception
    ldmfd sp!, {r0-r12, lr}
    b one_infinite_loop

undefined_instruction_handler:
    sub lr, lr, #4
    stmfd sp!, {r0-r12, lr}
    mov r0, #1
    mov r1, lr
    bl abort_exception
    ldmfd sp!, {r0-r12, lr}
    b one_infinite_loop

prefetch_abort_exception:
    sub lr, lr, #4
    stmfd sp!, {r0-r12, lr}
    mov r0, #2
    mov r1, lr
    bl abort_exception
    ldmfd sp!, {r0-r12, lr}
    b one_infinite_loop
   