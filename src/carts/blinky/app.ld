OUTPUT_FORMAT("elf32-littlearm", "elf32-littlearm", "elf32-littlearm")
OUTPUT_ARCH(arm)

ENTRY(start0)
MEMORY
{
   DDR_BASEADDR : ORIGIN = 0x000200000, LENGTH = 511M
   OCM_HI_BASEADDR : ORIGIN = 0xFFFF0000, LENGTH = 64K
}

SECTIONS
{
    .text : 
    {
        *(.text*)
        *(.rodata*)
        *(.igot.plt)
        *(.got.plt)
        *(.got)
     } > DDR_BASEADDR
    _text_end = .;
    
    .data : AT(ADDR(.text) + SIZEOF(.text))
    {
        _data_start = .;
        *(.data)
        . = ALIGN(8);
        _data_end = .;
    } > DDR_BASEADDR

    .bss : 
    {
        _bss_start = .;
        *(.bss)
        . = ALIGN(8);
        _bss_end = .;
    } > DDR_BASEADDR

    .bitstream : AT(ADDR(.bss) + SIZEOF(.bss))
    {
        _bitstream_start = .;
        *(.bitstream)
        . = ALIGN(8);
        _bitstream_end = .;
    } > DDR_BASEADDR

    .hi_ocm_data :
    {
        _mmu_start = .;
        . += (4096*4);
        _mmu_end = .;
        . = ALIGN(16);
        _cpu1_wait_resume = .;
        . += 4;
        debug_uart_lock = .;
        . += 4;
        app_cpu0_address = .;
        . += 4;
        app_cpu1_address = .;
        . += 4;
        . = ALIGN(16);

    } > OCM_HI_BASEADDR

    /DISCARD/ :
    {
        *(.ARM.exidx)
    }    

}
