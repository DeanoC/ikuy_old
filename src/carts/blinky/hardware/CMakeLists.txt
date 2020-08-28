set(project blinky_hw)
project(${project} NONE)

file(GLOB   SRC_VERILOG_FILES 
            CONFIGURE_DEPENDS 
            verilog/*.v )
file(GLOB   SRC_SCALA_FILES 
            CONFIGURE_DEPENDS 
            spinalHDL/src/main/scala/blinky_hw/*.scala)

file(GLOB   SRC_SILICE_FILES 
            CONFIGURE_DEPENDS 
            Silice/*.ice)

set( GEN_DIR ${CMAKE_CURRENT_BINARY_DIR}/workspace )
set( BIN_PATH ${GEN_DIR}/${project}.bin)
set( FINAL_PATH ${CMAKE_CURRENT_BINARY_DIR}/${project}.bin)
set( SLICE_VERILOG_PATH ${CMAKE_CURRENT_SOURCE_DIR}/verilog/silice_main.v )


add_custom_command( 
      OUTPUT ${SLICE_VERILOG_PATH}
      COMMAND /home/deano/ikuy/tools/Silice/bin/silice 
                        ${CMAKE_CURRENT_SOURCE_DIR}/Silice/main.ice 
                        -o ${SLICE_VERILOG_PATH}
                        -f ${CMAKE_CURRENT_SOURCE_DIR}/verilog/silice_framework.v
      DEPENDS ${SRC_SILICE_FILES}
)


add_custom_command( 
      OUTPUT ${BIN_PATH}
      COMMAND sbt "runMain blinky.BuildMain"
      WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/spinalHDL
      DEPENDS ${SRC_VERILOG_FILES} ${SRC_SCALA_FILES} ${SRC_SILICE_FILES} ${SLICE_VERILOG_PATH}
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

add_custom_target(
        ${project} 
        DEPENDS ${FINAL_PATH}
)