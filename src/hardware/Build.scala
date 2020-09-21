package blinky
import spinal.core._
import spinal.lib.io._
import java.io.File

object Build {
  def ensureDirectories(path : String ) : Unit = {
    val directory = new File(path);
    if (! directory.exists()){
        directory.mkdirs();
    }    
  }

  val sc = SpinalConfig(
    mode = Verilog,
    mergeAsyncProcess = true,
    defaultConfigForClockDomains = ClockDomainConfig(resetKind = BOOT),
    defaultClockDomainFrequency = FixedFrequency(125 MHz),
    targetDirectory = "~/ikuy/build/"
  )

  def main(args: Array[String]): Unit = {
    ensureDirectories("../../build/")

    var rtl = sc.generate(InOutWrapper(new Blinky))
    rtl.mergeRTLSource("../../build/external")
    rtl.printPruned()

    val vivadoFile = new File("/opt/Xilinx/Vivado/2020.1/bin");
    assert(vivadoFile.exists) 
    val workspaceFile = new File("../../build/hardware/workspace")
    ensureDirectories(workspaceFile.getAbsolutePath)
    val moduleFile = new File("../../build/Blinky.v")
    val mergedFile = new File("../../build/external.v")


    MyVivadoFlow(
      vivadoPath = vivadoFile.getAbsolutePath,
      workspacePath = workspaceFile.getAbsolutePath,
      modulePath = moduleFile.getCanonicalPath,
      mergedPath = if(mergedFile.exists) mergedFile.getAbsolutePath else "",
      family = "Artix 7",
      device = "xc7z020clg400-1"
    )
  }
}
