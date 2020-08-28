package blinky

import java.io.File
import java.nio.file.Paths

import org.apache.commons.io.FileUtils
import spinal.core._
import spinal.lib.eda.bench.Report

import scala.sys.process._

object MyVivadoFlow {
  def doCmd(cmd : String): Unit ={
    println(cmd)
    if(isWindows)
      Process("cmd /C " + cmd) !
    else
      Process(cmd) !
  }
  def doCmd(cmd : String, path : String): Unit ={
    println(cmd)
    if(isWindows)
      Process("cmd /C " + cmd, new java.io.File(path)) !
    else
      Process(cmd, new java.io.File(path)) !

  }

  val isWindows = System.getProperty("os.name").toLowerCase().contains("win")

  def apply(vivadoPath : String,
            workspacePath : String,
            modulePath : String,
            mergedPath : String,
            family : String,
            device : String) : Unit = {

    val projectName = modulePath.split("/").last.split("[.]").head

    val workspacePathFile = new File(workspacePath)
    FileUtils.deleteDirectory(workspacePathFile)
    workspacePathFile.mkdir()

    val tcl = new java.io.FileWriter(Paths.get(workspacePath,"doit.tcl").toFile)
    tcl.write(
    s"""
read_verilog $modulePath
read_verilog $mergedPath
read_xdc /home/deano/ikuy/src/carts/blinky/hardware/constraints/ps7_constraints.xdc -cells ps7/ps7_lo_i/inst
read_xdc /home/deano/ikuy/src/carts/blinky/hardware/boards/pynqz2-z7-20/top.xdc
set_property used_in_synthesis false [get_files ps7_constraints.xdc]
set_property used_in_synthesis false [get_files top.xdc]

synth_design -part $device -top main 
opt_design
place_design
route_design
write_bitstream -bin_file -force [string tolower ${projectName}_hw]
"""
    )

    tcl.flush();
    tcl.close();

    doCmd(s"$vivadoPath/vivado -nojournal -log doit.log -mode batch -source doit.tcl", workspacePath)
  }
}

