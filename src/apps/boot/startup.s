// much of this is based on the excellent book on arm a9 bare metal setup
// by Daniels Umanovskis https://github.com/umanovskis/

/* Some defines for both interupt and supervisor modes (which we run in)*/
.equ MODE_FIQ, 0x11
.equ MODE_IRQ, 0x12
.equ MODE_SVC, 0x13

.section .vector_table, "x"
.global _Reset
.global _start
_Reset:
    b Reset_Handler
    b Abort_Exception /* 0x4  Undefined Instruction */
    b . /* 0x8  Software Interrupt */
    b Abort_Exception  /* 0xC  Prefetch Abort */
    b Abort_Exception /* 0x10 Data Abort */
    b . /* 0x14 Reserved */
    b . /* 0x18 IRQ */
    b . /* 0x1C FIQ */

.section .text
 Reset_Handler:
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
    ldr sp, =_svc_stack_start
    bl main
    b Abort_Exception

Abort_Exception:
    swi 0xFF
