set(project blinky_hw)
project(${project} NONE)

set( BOARD pynqz2-z7-20)
set( PART xc7z020clg400-1)

set(SRC_VERILOG_PATH ${CMAKE_CURRENT_SOURCE_DIR}/verilog )
file(GLOB SRC_FILES CONFIGURE_DEPENDS verilog/*.v )
set( CONSTRAINTS ${CMAKE_CURRENT_SOURCE_DIR}/boards/${BOARD}/top.xdc)

set( GEN_DIR ${CMAKE_CURRENT_BINARY_DIR} )
set( BIN_PATH ${GEN_DIR}/mkTop.bin)

add_custom_command(
  OUTPUT ${BIN_PATH}  
  COMMAND ${CMAKE_CURRENT_SOURCE_DIR}/fpgamake ${BOARD} ${PART} ${CONSTRAINTS} ${GEN_DIR} ${SRC_VERILOG_PATH}
  DEPENDS ${SRC_FILES}
)

add_custom_target(${project} DEPENDS ${BIN_PATH})