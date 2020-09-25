cmake_minimum_required(VERSION 3.12.4)

set(CMAKE_SYSTEM_NAME Generic)
set(CMAKE_SYSTEM_PROCESSOR arm)
set(CMAKE_CROSSCOMPILING TRUE)
set(CMAKE_C_COMPILER "arm-none-eabi-gcc")
set(CMAKE_ASM_COMPILER "arm-none-eabi-gcc")
set(CMAKE_OBJCOPY "arm-none-eabi-objcopy")
set(CMAKE_ASM_FLAGS "${CMAKE_ASM_FLAGS} -ggdb")
set(CMAKE_ASM_FLAGS "${CMAKE_ASM_FLAGS} -ggdb -fpie -mcpu=cortex-a9")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fpie")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -nostartfiles -nostdlib -nostdinc")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -ggdb -Wno-builtin-declaration-mismatch")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -lgcc")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -mcpu=cortex-a9")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -fpie")

set(project blinky)
project(${project} C ASM)

include_directories(libraries/core/include SYSTEM)

add_subdirectory(hardware)
add_subdirectory(libraries)
add_subdirectory(boot)

file(GLOB LINKSCRIPT CONFIGURE_DEPENDS app.ld)
file(GLOB ASMFILES CONFIGURE_DEPENDS *.S)
file(GLOB SRCLIST CONFIGURE_DEPENDS *.c)

set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -T ${LINKSCRIPT}")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -Wl,-M=${CMAKE_CURRENT_BINARY_DIR}/${project}.map ")

add_executable(${project} ${ASMFILES} ${SRCLIST} ${LINKSCRIPT} )
set_target_properties(${project} PROPERTIES OUTPUT_NAME ${project}.elf)
target_link_libraries(${project} PUBLIC core)
target_link_libraries(${project} PUBLIC serial_debug)
target_link_libraries(${project} PUBLIC hw_fpga)
target_link_libraries(${project} PUBLIC hw_timers)
target_link_libraries(${project} PUBLIC hw_i2c)
target_link_libraries(${project} PUBLIC system_info)
target_link_libraries(${project} PUBLIC zynq_ps)
target_link_libraries(${project} PUBLIC BuggyBoy)
target_link_libraries(${project} PUBLIC Dissy)

add_dependencies(${project} ${project}_hw)

add_custom_command(
    TARGET ${project} PRE_LINK
    COMMAND ${CMAKE_OBJCOPY} 
                --add-section .bitstream=${CMAKE_CURRENT_BINARY_DIR}/hardware/${project}_hw.bin
                --set-section-flags .bitstream=load,readonly
                CMakeFiles/blinky.dir/main.c.obj CMakeFiles/blinky.dir/main.c.obj
    DEPENDS ${CMAKE_CURRENT_BINARY_DIR}/hardware/${project}_hw.bin CMakeFiles/blinky.dir/main.c.obj 
)   
