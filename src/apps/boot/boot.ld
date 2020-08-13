OUTPUT_FORMAT("elf32-littlearm", "elf32-littlearm", "elf32-littlearm")
OUTPUT_ARCH(arm)

_SVC_STACK_SIZE = DEFINED(_SVC_STACK_SIZE) ? _SVC_STACK_SIZE : 0x1000; /* 4K stack */
_IRQ_STACK_SIZE = DEFINED(_IRQ_STACK_SIZE) ? _IRQ_STACK_SIZE : 0x0400; /* 1K stack */
_FIQ_STACK_SIZE = DEFINED(_FIQ_STACK_SIZE) ? _FIQ_STACK_SIZE : 0x0400; /* 1K stack */

ENTRY(_Reset)

/* At boot znyq use the OCM as its only RAM, 
    192K is mapped low
    64K is mapped high (minus a small bit)

    code and data live in the low chunk
    6K (by default) of stack lives in the top chunk 
*/
MEMORY
{
   ps7_ram_0_S_AXI_BASEADDR : ORIGIN = 0x00000000, LENGTH = 192K
   ps7_ram_1_S_AXI_BASEADDR : ORIGIN = 0xFFFF0000, LENGTH = 0x0000FE00
}

SECTIONS
{
    .text : 
    {
        *(.vector_table)
        *(.text*)
        *(.rodata*)
     } > ps7_ram_0_S_AXI_BASEADDR
    _text_end = .;
    
    .data : AT(ADDR(.text) + SIZEOF(.text))
    {
        _data_start = .;
        *(.data)
        . = ALIGN(8);
        _data_end = .;
    } > ps7_ram_0_S_AXI_BASEADDR
    
    .bss : 
    {
        _bss_start = .;
        *(.bss)
        . = ALIGN(8);
        _bss_end = .;
    } > ps7_ram_0_S_AXI_BASEADDR

    .stack (NOLOAD) : 
    {
        . = ALIGN(16);
        _svc_stack_end = .;
        . += _SVC_STACK_SIZE;
        _svc_stack_start = .;
        . = ALIGN(16);
        _irq_stack_end = .;
        . += _IRQ_STACK_SIZE;
        _irq_stack_start = .;
        _fiq_stack_end = .;
        . += _FIQ_STACK_SIZE;
        . = ALIGN(16);
        _fiq_stack_start = .;
    } > ps7_ram_1_S_AXI_BASEADDR
}

ENTRY(_Reset)