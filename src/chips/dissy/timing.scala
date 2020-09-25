package dissy

import spinal.core._

class DisplayTiming(
  val visibleWidthInPixels : Int = 640,
  val visibleHeightInPixels : Int = 480,

  val leftBorder: Int = 48,
  val rightBorder : Int = 16,
  val hSyncPeriod : Int = 96,

  val topBorder : Int = 10,
  val bottomBorder : Int = 33,
  val vSyncPeriod : Int = 2
)
extends Component
{
  val io = new Bundle
  {
    val hsync = out Bool
    val vsync = out Bool
    val lineEnd = out Bool
    val screenEnd = out Bool
    val visible = out Bool
    val xPos = out UInt(14 bits) // up to 16K more than enough!
    val yPos = out UInt(14 bits)
  }
  // | Active | LeftBorder | Sync | Right Border
  val hSyncStart = visibleWidthInPixels + rightBorder
  val hSyncEnd = hSyncStart + hSyncPeriod
  val hRestart = hSyncEnd + leftBorder - 1

  // | Active |  Top Border | Sync | Bottom Border
  val vSyncStart = visibleHeightInPixels + topBorder
  val vSyncEnd = vSyncStart + vSyncPeriod
  val vRestart = vSyncEnd + bottomBorder - 1

  val x = Reg(UInt(log2Up(hRestart+1) bits)) init 0
  val y = Reg(UInt(log2Up(vRestart+1) bits)) init 0

  x := x + 1
  io.hsync := False
  io.vsync := False

  val xActive = False
  val yActive = False

  when(x < visibleWidthInPixels) { xActive := True }
  when(y < visibleHeightInPixels)  { yActive := True }

  when(x >= hSyncStart && x <= hSyncEnd ) { io.hsync := True }
  when(y >= vSyncStart && y <= vSyncEnd ) { io.vsync := True }

  when(x === hRestart) 
  { 
    x := 0
    io.lineEnd := True
    when(y === vRestart)
    {
      y := 0
      io.screenEnd := True
    }.otherwise
    {
      y := y + 1
      io.screenEnd := False
    }
  }
  .otherwise
  {
    x := x + 1
    io.lineEnd := False
    io.screenEnd := False
}


  io.xPos := x.resize(14)
  io.yPos := y.resize(14)
 
  io.visible := xActive & yActive
}