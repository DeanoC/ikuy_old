OUTPUT_FORMAT("elf32-littlearm", "elf32-littlearm", "elf32-littlearm")
OUTPUT_ARCH(arm)

/* all stack sizes should be aligned to 16 bytes*/
_SVC_STACK_SIZE = DEFINED(_SVC_STACK_SIZE) ? _SVC_STACK_SIZE : 0x1000; /* 4K stack */
_IRQ_STACK_SIZE = DEFINED(_IRQ_STACK_SIZE) ? _IRQ_STACK_SIZE : 0x0800; /* 2K stack */
_FIQ_STACK_SIZE = DEFINED(_FIQ_STACK_SIZE) ? _FIQ_STACK_SIZE : 0x0800; /* 2K stack */
_ABORT_STACK_SIZE = DEFINED(_ABORT_STACK_SIZE) ? _ABORT_STACK_SIZE : 0x0800; /* 2K stack */

ENTRY(_reset)

/* At boot znyq use the OCM as its only RAM, 
    192K is mapped low
    64K is mapped high (minus a small bit)

    code and data live in the low chunk
    10K (by default) of stack lives in the top chunk for both cpu
    total 20K
*/
MEMORY
{
   ps7_ram_0_S_AXI_BASEADDR : ORIGIN = 0x00000000, LENGTH = 192K
   ps7_ram_1_S_AXI_BASEADDR : ORIGIN = 0xFFFF0000, LENGTH = 65024 /* not 64K to leave space for cpu1 jump*/
}

SECTIONS
{
    .text : 
    {
        *(.vector_table)
        *(.text*)
        *(.rodata*)
        *(.igot.plt)
        *(.got.plt)
        *(.got)
     } > ps7_ram_0_S_AXI_BASEADDR
    _text_end = .;
    
    .data : AT(ADDR(.text) + SIZEOF(.text))
    {
        _data_start = .;
        *(.data)
        . = ALIGN(8);
        _data_end = .;
    } > ps7_ram_0_S_AXI_BASEADDR

    .arm : AT(ADDR(.data) + SIZEOF(.data))
    {
        . = ALIGN(8);
        *(.ARM.exidx)
    }  > ps7_ram_0_S_AXI_BASEADDR
    
    .bss : 
    {
        _bss_start = .;
        *(.bss)
        . = ALIGN(8);
        _bss_end = .;
    } > ps7_ram_0_S_AXI_BASEADDR

    .hi_ocm_data :
    {
        _mmu_start = .;
        *(.mmu_tbl)
        _mmu_end = .;
    } > ps7_ram_1_S_AXI_BASEADDR

    .stack (NOLOAD) : AT(ADDR(.hi_ocm_data) + SIZEOF(.hi_ocm_data))
    {
        . = ALIGN(16);
        _cpu1_wait_resume = .;
        . += 4;
        debug_uart_lock = .;
        . += 4;
        ddr_reserved_top = .; /* highest ddr address not used */
        . += 4;
        . = ALIGN(16);
        _svc_stack_end = .;
        . += _SVC_STACK_SIZE;
        _svc_stack_start = .;
        . += _IRQ_STACK_SIZE;
        _irq_stack_start = .;
        . += _FIQ_STACK_SIZE;
        _fiq_stack_start = .;
        . += _ABORT_STACK_SIZE;
        _abort_stack_start = .;

        _cpu1_svc_stack_end = .;
        . += _SVC_STACK_SIZE;
        _cpu1_svc_stack_start = .;
        . += _IRQ_STACK_SIZE;
        _cpu1_irq_stack_start = .;
        . += _FIQ_STACK_SIZE;
        _cpu1_fiq_stack_start = .;
        . += _ABORT_STACK_SIZE;
        _cpu1_abort_stack_start = .;

    } > ps7_ram_1_S_AXI_BASEADDR
}
