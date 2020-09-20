set(project blinky_hw)

add_subdirectory(sim)

file(GLOB   SRC_VERILOG_FILES 
            CONFIGURE_DEPENDS 
            verilog/*.v )

file(GLOB   SRC_SCALA_FILES 
            CONFIGURE_DEPENDS 
            spinalHDL/src/main/scala/blinky_hw/*.scala
            spinalHDL/src/main/scala/bus_and_chips/*.scala
            spinalHDL/src/main/scala/bus_and_chips/sim/*.scala
            spinalHDL/src/main/scala/dissy/*.scala
            spinalHDL/build.sbt
            spinalHDL/project/plugins.sbt
            spinalHDL/project/ikuy.scala
            )

set( GEN_DIR ${CMAKE_CURRENT_BINARY_DIR}/workspace )
set( BIN_PATH ${GEN_DIR}/${project}.bin)
set( SIM_PATH ${GEN_DIR}/${project}_sim)

set( FINAL_PATH ${CMAKE_CURRENT_BINARY_DIR}/${project}.bin)

project(${project} NONE)

add_custom_command( 
      OUTPUT ${BIN_PATH}
      COMMAND sbt "runMain blinky.Build"
      WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/spinalHDL
      DEPENDS     ${SRC_VERILOG_FILES} 
                  ${SRC_SCALA_FILES} 
                  ${SRC_SILICE_FILES} 
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
