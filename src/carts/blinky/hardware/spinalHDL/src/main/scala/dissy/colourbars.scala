package dissy

import spinal.core._

class DissyColourBars(
  val horizontalResolution : Int = 640,
  val verticalResolution : Int = 480
) extends Component
{
  val io = new Bundle{
    val newLine = in Bool
    val stall = in Bool
    val writeEnable = out Bool
    val writeData = out Bits( 24 bits)    
  }
  when(!io.stall) 
  {
    io.writeEnable := True
    io.writeData := B"24'xFF00FF"
  }.otherwise
  {
    io.writeEnable := False
    io.writeData := 0 
  }
 
}