package dissy

import spinal.core._
import spinal.lib.{ Counter }
class DissyColourBars(val height : Int,
                      val width : Int  )
extends Component
{
  val io = new Bundle
  {
    val stall = in Bool
    val lineEnd = in Bool
    val screenEnd = in Bool
    val enable = out Bool
    val data = out Bits(24 bits)    
  }
  val curLineEnd = Reg(Bool)
  val nextLineEnd = RegNext(curLineEnd)
  curLineEnd.setWhen(io.lineEnd)

  val curScreenEnd = Reg(Bool)
  val nextScreenEnd = RegNext(curScreenEnd)
  curScreenEnd.setWhen(io.screenEnd)

  val xCounter = Counter(0, width)
  val yCounter = Counter(0, height)

  when(curLineEnd === nextLineEnd) 
  {
    xCounter.increment
  }
  .otherwise
  {
    xCounter.clear
  }

  when(curScreenEnd === nextScreenEnd) 
  {
    yCounter.increment
  }
  .otherwise
  {
    yCounter.clear
  }

  when(!io.stall)
  {
    io.enable := True
  }.otherwise
  {
    io.enable := False
  }

  when(yCounter(3 until 4) === 0)
  {
    io.data := B(0xFF0000, 24 bits)
  }
  .otherwise
  {
    io.data := B(0x00FF00, 24 bits)
  }

}