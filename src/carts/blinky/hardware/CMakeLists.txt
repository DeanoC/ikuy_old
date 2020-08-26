set(project blinky_hw)
project(${project} NONE)

set(SRC_VERILOG_PATH ${CMAKE_CURRENT_SOURCE_DIR}/spinalHDL/verilog )
set(GLOB SRC_VERILOG_FILES CONFIGURE_DEPENDS ${SRC_VERILOG_PATH}/*.v )

set(SRC_SCALA_PATH ${CMAKE_CURRENT_SOURCE_DIR}/spinalHDL/src/main/scala/blinky_hw )
set(GLOB SRC_SCALA_FILES CONFIGURE_DEPENDS ${SRC_VERILOG_PATH}/*.scala)

set(SRC_FILES ${SRC_VERILOG_FILES} ${SRC_SCALA_FILES})

set( GEN_DIR ${CMAKE_CURRENT_BINARY_DIR}/workspace )
set( BIN_PATH ${GEN_DIR}/${project}.bin)
set( FINAL_PATH ${CMAKE_CURRENT_BINARY_DIR}/${project}.bin)

add_custom_command( 
      OUTPUT ${BIN_PATH}
      COMMAND ./gradlew runVerilog
      DEPENDS ${SRC_FILES} 
      WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/spinalHDL
)

add_custom_command(
    OUTPUT ${FINAL_PATH}

    COMMAND ${CMAKE_OBJCOPY} 
                -I binary -O binary 
                --reverse-bytes=4 
                ${BIN_PATH} 
                ${FINAL_PATH}
    DEPENDS ${BIN_PATH}
)

add_custom_target(${project} DEPENDS ${FINAL_PATH})