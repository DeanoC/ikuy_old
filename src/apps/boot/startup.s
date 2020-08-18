// much of this is based on the excellent book on arm a9 bare metal setup
// by Daniels Umanovskis https://github.com/umanovskis/

// Some defines for both interupt and supervisor modes (which we run in)
// and abort/exception
.equ MODE_FIQ, 0x011
.equ MODE_IRQ, 0x012
.equ MODE_SVC, 0x013
.equ MODE_ABORT, 0x017
.equ MODE_UNDEFINED_INSTRUCTION, 0x01A

.equ DDR_ADDRESS_START, 0x100000 // 1MB
.equ SLCR_LOCK_REG, 0xf8000004
.equ SLCR_UNLOCK_REG, 0xf8000008
.equ SLCR_OCM_CFG, 0xf8000910


.section .vector_table, "x"
.global _reset
.global _asm_start
.global arm_cop_main_id
.global move_ocm_high 
.global abort_exception

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
_asm_start:
clear_fiq_stack:
    /* clear FIQ stack to 0xDC*/
    msr cpsr_c, MODE_FIQ        // switch to FIQ mode
    ldr r1, =_fiq_stack_start
    ldr sp, =_fiq_stack_end
    movw r0, #0xDCDC
    movt r0, #0xDCDC
fiq_loop:
    cmp r1, sp
    strlt r0, [r1], #4
    blt fiq_loop
 clear_irq_stack:
    /* clear IRQ stack to 0xDC*/
    msr cpsr_c, MODE_IRQ        // switch to IRQ mode
    ldr r1, =_irq_stack_start
    ldr sp, =_irq_stack_end
    movw r0, #0xDCDC
    movt r0, #0xDCDC
irq_loop:
    cmp r1, sp
    strlt r0, [r1], #4
    blt irq_loop
 clear_abort_stack:
    /* clear abort stack to 0xDC
        share stack with undefined instuction exception (both fatal)
    */
    msr cpsr_c, MODE_ABORT        // switch to ABORT mode
    ldr r1, =_abort_stack_start
    ldr sp, =_abort_stack_end
    movw r0, #0xDCDC
    movt r0, #0xDCDC
abort_loop:
    cmp r1, sp
    strlt r0, [r1], #4
    blt abort_loop
    msr cpsr_c, MODE_UNDEFINED_INSTRUCTION // switch to MODE_UNDEFINED_INSTRUCTION mode
    ldr sp, =_abort_stack_end

 clear_svc_stack:
    /* clear SVC stack to 0xDC*/
    msr cpsr_c, MODE_SVC        // switch to svc mode
    ldr r1, =_svc_stack_start
    ldr sp, =_svc_stack_end
    movw r0, #0xDCDC
    movt r0, #0xDCDC
svc_loop:
    cmp r1, sp
    strlt r0, [r1], #4
    blt svc_loop



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

    /* we are in supervisor mode */
    ldr sp, = _svc_stack_start

    bl cpu_init

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
arm_cop_main_id:
    mrc	p15, 0, r0, c0, c0, 0
    bx lr

// This relys on -fPIC code for the boot module
move_ocm_high:
   /* Start copying data to ddr*/
    mov r0, #0
    ldr r1, =_bss_end            // last used part of low memory
    mov r2, #DDR_ADDRESS_START  // ddr address 
ocmlo_loop:
    cmp r0, r1
    ldrlt r3, [r0], #4
    strlt r3, [r2], #4
    blt ocmlo_loop

    // now branch to the version in ddr so we can move the ocm
    mov	r0, #DDR_ADDRESS_START
    add lr, r0      // new link address
    mov r1, pc      // get the current pc 
    add r1, r0      // add the ddr base
    add r1, #8      // and offset the instructions since copying pc
    bx r1           // jump to the next instruction to this but in ddr

    /* set VBAR to DDR start (where a copy of the vector table now lives  */
    mov	r0, #DDR_ADDRESS_START
	mcr	p15, 0, r0, c12, c0, 0

    // unlock and update ocm to all high
    ldr r0, =SLCR_UNLOCK_REG
    mov r1, #0xDF0D
    str r1, [r0]
    ldr r0, =SLCR_OCM_CFG
    mov r1, #0x1F
    str r1, [r0]
    ldr r0, =SLCR_LOCK_REG
    mov r1, #0x767B
    str r1, [r0]

    // at this point OCM is now mapped high (low OCM addresses are now 
    // exceptions). the stacks are still mapped into the top of
    // OCM high and CPU1 is waiting for a wake up event there as well.
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
