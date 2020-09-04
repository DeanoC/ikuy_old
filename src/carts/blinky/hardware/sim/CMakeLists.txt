set(project blinky_hw_sim)
project(${project} NONE)

file(GLOB   SRC_VERILOG_FILES 
            CONFIGURE_DEPENDS 
            ../verilog/*.v )
file(GLOB   SRC_SCALA_FILES 
            CONFIGURE_DEPENDS 
            ../spinalHDL/src/main/scala/blinky_hw/*.scala)

set( GEN_DIR ${CMAKE_CURRENT_BINARY_DIR}/../workspace )
set( SIM_PATH ${GEN_DIR}/${project})

add_custom_command( 
      OUTPUT ${SIM_PATH}
      COMMAND sbt "runMain blinky.DutTests"
      WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/../spinalHDL
      DEPENDS ${SRC_VERILOG_FILES} ${SRC_SCALA_FILES} 
)

add_custom_target(
        ${project} 
        DEPENDS  ${SIM_PATH}
)
