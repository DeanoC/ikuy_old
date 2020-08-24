set(project blinky)
project(${project} C ASM)

add_subdirectory(hardware)

file(GLOB LINKSCRIPT CONFIGURE_DEPENDS app.ld)
file(GLOB ASMFILES CONFIGURE_DEPENDS *.S)
file(GLOB SRCLIST CONFIGURE_DEPENDS *.c)

set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -T ${LINKSCRIPT}")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -Wl,-M=${CMAKE_CURRENT_BINARY_DIR}/${project}.map ")

add_executable(${project} ${ASMFILES} ${SRCLIST} ${LINKSCRIPT} )
set_target_properties(${project} PROPERTIES OUTPUT_NAME ${project}.elf)
target_link_libraries(${project} PUBLIC a9sdk)
target_link_libraries(${project} PUBLIC core)
target_link_libraries(${project} PUBLIC serial_debug)
target_link_libraries(${project} PUBLIC hw_fpga)
target_link_libraries(${project} PUBLIC hw_timers)
target_link_libraries(${project} PUBLIC system_info)
add_dependencies(${project} ${project}_hw)

add_custom_command(
    TARGET ${project} PRE_LINK
    COMMAND ${CMAKE_OBJCOPY} 
                --add-section .bitstream=hardware/mkTop.bin
                --set-section-flags .bitstream=load,readonly
                --add-symbol bitstream=.bitstream:0
                CMakeFiles/blinky.dir/main.c.obj CMakeFiles/blinky.dir/main.c.obj
    DEPENDS ${project}_hw
)   
