set(project boot)
project(${project} C ASM)

file(GLOB LINKSCRIPT boot.ld)
set(ASMFILES startup.S
            mmu_table.S
)
set(SRCLIST main.c
            ps_init_program.c
            slcr_init.c
            ddrc_init.c
            uart_init.c
            ${LINKSCRIPT}
)


set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -Wl,-M=output.map -T ${LINKSCRIPT}")

add_executable(${project} ${SRCLIST} ${ASMFILES})
set_target_properties(${project} PROPERTIES OUTPUT_NAME ${project}.elf)
target_link_libraries(${project} PUBLIC a9sdk)
target_link_libraries(${project} PUBLIC core)
target_link_libraries(${project} PUBLIC serial_debug)
target_link_libraries(${project} PUBLIC hw_timers)
target_link_libraries(${project} PUBLIC system_info)

