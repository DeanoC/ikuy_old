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

  def ensureDirectories(path : String ) : Unit = {
    val directory = new File(path);
    if (! directory.exists()){
        directory.mkdirs();
    }    
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

    val directory = new File(workspacePath);
    if (directory.exists()){
      FileUtils.deleteDirectory(directory)
    }
    ensureDirectories(workspacePath)

    val zc0 = new File("constraints/ps7_constraints.xdc");
    val boardc = new File("boards/pynqz2-z7-20/top.xdc");
    val tcl = new java.io.FileWriter(Paths.get(workspacePath,"doit.tcl").toFile)

    val mergedString = if(mergedPath.isEmpty()) "" else f"read_verilog $mergedPath%n"

    tcl.write(s"""
read_verilog $modulePath
$mergedString
set_msg_config -id "Vivado 12-4739" -suppress
set_msg_config -id "Netlist 29-160" -suppress
set_msg_config -id "Vivado 12-584" -suppress
set_msg_config -id "Common 17-55" -suppress
read_xdc ${zc0.getCanonicalPath}
read_xdc ${boardc.getAbsolutePath}
set_property used_in_synthesis false [get_files ps7_constraints.xdc]
set_property used_in_synthesis false [get_files top.xdc]

synth_design -part $device -top $projectName
opt_design
place_design
route_design
write_bitstream -bin_file -force [string tolower ${projectName}_hw]
""")

    tcl.flush();
    tcl.close();

    doCmd(s"$vivadoPath/vivado -nojournal -log doit.log -mode batch -source doit.tcl", workspacePath)
  }
}

