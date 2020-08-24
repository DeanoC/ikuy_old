
.global start0
.global start1
.global own_uart
.global release_uart
.global cpu0_main
.global cpu1_main
.global get_bitstream_start_address
.global get_bitstream_end_address

.section .text
start0: b elf_setup
start1: b cpu1_main

elf_setup:
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
    b cpu0_main

own_uart:
    MOV r1, #0x0                // free at the moment
    MOV r3, #0x1                // some one owns it
uart_lock:
    bx lr
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
    bx lr
    ldr r2, =debug_uart_lock
rel_uart_lock_retry:
    LDREX r0, [r2]              // fetch with tag
    CMP r0, r1                  // is the lock free?
    BNE rel_uart_lock_retry
    STREXEQ r0, r3, [r2]        // try and claim the lock
    CMPEQ r0, #0                // did this succeed?
    BNE rel_uart_lock_retry         // no – try again
    bx lr
get_bitstream_start_address:
    ldr r0, =_bitstream_start
    bx lr
get_bitstream_end_address:
    ldr r0, =_bitstream_end
    bx lr
