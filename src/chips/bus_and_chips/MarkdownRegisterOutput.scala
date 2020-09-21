package bus_and_chips
import java.io._
import scala.collection.mutable.StringBuilder
import java.util.Calendar

object MarkdownRegisterOutput
{
  def generateMarkdowns(chip : Chip) : Unit =
  {
    ensureDirectories(f"${chip.LibraryPath}/${chip.chipID.name}/docs/")

    if(chip.isHard) 
    {
      generateHardMarkdowns(chip.asInstanceOf[HardChip])
    }
    else
    {
      generateCustomMarkdowns(chip.asInstanceOf[CustomChip])
    }
  }
  def ensureDirectories(path : String ) : Unit = {
    val directory = new File(path);
    if (! directory.exists()){
        directory.mkdirs();
    }    
  }

  private def writeFile(filename: String, s: String): Unit = {
      val file = new File(filename)
      val bw = new BufferedWriter(new FileWriter(file))
      bw.write(s)
      bw.close()
  }

  private def repeatChar(c: Char, n: Int): String = c.toString * n
  
  private def makeField(s: String, w: Int) : String = {
    if(s.length() >= w) s"| ${s.substring(0, w-2)} " 
    else s"|$s${repeatChar(' ', w - s.length)}"
  }

  private def makeHeader(fields : Vector[(String, Int)]) : String = {
    var s : StringBuilder = new StringBuilder()
    fields.foreach( f => s ++= f"+${repeatChar('-', f._2)}")
    s ++= f"+%n"
    fields.foreach( f => s ++= f"${makeField(f._1, f._2)}")
    s ++= f"|%n"
    fields.foreach( f => s ++= f"+${repeatChar('=', f._2)}")
    s ++= f"+%n"
    s.result
  }

  private def outputTOC(registers : Iterator[Register]) : String = {
    val s = new StringBuilder()
    // fixed sized fields are needed for the table
    val regWidth = 30
    val addressWidth = 12
    val widthWidth = 6
    val rtypeWidth = 6
    val resetWidth = 12
    val rdescWidth = 30

    s ++= makeHeader( Vector[(String,Int)](
      ("Register Name", regWidth),
      ("Address", addressWidth),
      ("Width", widthWidth),
      ("Type", rtypeWidth),
      ("Reset Value", resetWidth),
      ("Description", rdescWidth)
    ))

    registers.foreach( register => {
      val shortName = register.defi.name.substring(register.defi.name.indexOf("_")+1)
//        s ++= makeField(f"[$r](#$r)", regWidth)
      s ++= makeField(f"**$shortName**", regWidth)
      s ++= makeField(f"${(register.address) & 0xFFFFFFFFL}%#010x", addressWidth)
      s ++= makeField(f"${register.defi.width}", widthWidth)
      s ++= makeField(f"${register.defi.rtype.typeString}", rtypeWidth)
      if(register.defi.width == 8)
        s ++= makeField(f"${register.defi.default & 0xFFL}%#04x", resetWidth)
      else if(register.defi.width == 16)
        s ++= makeField(f"${register.defi.default & 0xFFFFL}%#06x", resetWidth)
      else
        s ++= makeField(f"${register.defi.default & 0xFFFFFFFFL}%#010x", resetWidth)

      s ++= makeField(f"${register.defi.description}", rdescWidth)
      s ++= f"|%n"
      s ++= f"+${repeatChar('-', regWidth)}"
      s ++= f"+${repeatChar('-', addressWidth)}"
      s ++= f"+${repeatChar('-', widthWidth)}"
      s ++= f"+${repeatChar('-', rtypeWidth)}"
      s ++= f"+${repeatChar('-', resetWidth)}"
      s ++= f"+${repeatChar('-', rdescWidth)}+%n"
    })
    s.result
  }
  
  private def outputRegisters(registers : Iterator[Register]) : String = {
    val s = new StringBuilder()
    registers.foreach{ register => {
      val shortName = register.defi.name.substring(register.defi.name.indexOf("_")+1)
      // fixed sized fields are needed for the table
      val fieldWidth = 20
      val bitsWidth = 8
      val typeWidth = 6
      val descWidth = 52

      s ++= f"%n### ${shortName}  %n%n"
      s ++= f"Relative Address = ${(register.address) & 0xFFFFFFFFL}%#010x  %n"
      s ++= f"Width = ${register.defi.width} bits  %n"
      s ++= f"Access Type = ${register.defi.rtype.typeString}  %n"
      if(register.defi.width == 8)
        s ++= f"Reset Value = ${register.defi.default & 0xFFL}%#04x  %n"
      else if(register.defi.width == 16)
        s ++= f"Reset Value = ${register.defi.default & 0xFFFFL}%#06x  %n"
      else
        s ++= f"Reset Value = ${register.defi.default & 0xFFFFFFFFL}%#010x  %n"

      s ++= f"Description ${register.defi.description}  %n%n"
      if(!register.defi.fields.isEmpty)
      {
        s ++= makeHeader( Vector[(String,Int)](
          ("FieldName", fieldWidth),
          ("Bits", bitsWidth),
          ("Type", typeWidth),
          ("Description", descWidth)
        ))
        register.defi.fields.foreach( f => {
          s ++= makeField(s"${f.name}", fieldWidth)
          s ++= makeField( (if(f.bits.singleBit) f"${f.bits.lo} " 
                            else f"${f.bits.hi}:${f.bits.lo} " ), bitsWidth)
          s ++= makeField(f"${f.fieldType.typeString}", typeWidth)
          if(!f.desc.describe().isEmpty) s ++= makeField(f"${f.desc.describe}", descWidth)
          else if(!f.desc.longDescribe().isEmpty) s ++= makeField(f"", descWidth)
          else s ++= makeField(f"No Description", descWidth)

          s ++= "|\n"
          if(!f.desc.longDescribe().isEmpty) 
          {
            val lines = f.desc.longDescribe.split("\n")
            lines.foreach( l => {
              s ++= f"|${repeatChar(' ', fieldWidth)}"
              s ++= f"|${repeatChar(' ', bitsWidth)}"
              s ++= f"|${repeatChar(' ', typeWidth)}"
              s ++= makeField( l, descWidth )
              s ++= f"|%n"
            })
          }
          s ++= f"+${repeatChar('-', fieldWidth)}"
          s ++= f"+${repeatChar('-', bitsWidth)}"
          s ++= f"+${repeatChar('-', typeWidth)}"
          s ++= f"+${repeatChar('-', descWidth)}+%n"
        })
      }
    }}
    s.result
  }
  private def generateHardMarkdowns(chip : HardChip) : Unit =
  {

    chip.registerBanks.foreach( rb => {
      var str = ""
      val dT = Calendar.getInstance()
      var s = new StringBuilder()
      s ++= f"# ${rb.description}  %n%n"
      s ++= f"Module ${rb.description} (${rb.name})  %n"
      s ++= f"SPDX-License-Identifier: MIT  %n"
      s ++= f"Auto-generated: ${dT.getTime()}  %n%n"
      rb.banks.foreach( b =>{
        s ++= f"${b._1} Base Address = ${b._2 & 0xFFFFFFFFL}%#010x  %n"
      })
      s ++= f"%n## Register Summary  %n%n"

      str = s.result
      s = null

      val regs = rb.registers.map( r => chip.getRegisterByName(r) )
      
      str += outputTOC(regs.toIterator)
      str += outputRegisters(regs.toIterator)

      val filename = f"${chip.LibraryPath}/${chip.chipID.name}/docs/${rb.name}.md"
      writeFile(filename, str)
    })

    // generate the primary doc
    var sb : StringBuilder = new StringBuilder()
    chip.description.split("\n").foreach(l => sb ++= f"$l  %n")

    val chipfilename = f"${chip.LibraryPath}/${chip.chipID.name}/docs/${chip.chipID.name}.md"
    writeFile(chipfilename, sb.result)
  }

  private def generateCustomMarkdowns(chip : CustomChip) : Unit =
  {
    var str = ""
    val dT = Calendar.getInstance()
    var s = new StringBuilder()
    s ++= f"SPDX-License-Identifier: MIT  %n"
    s ++= f"Auto-generated: ${dT.getTime()}  %n%n"
    chip.description.split("\n").foreach(l => s ++= f"$l%n")
    s ++= f"%n## Register Summary  %n%n"

    str = s.result
    s = null

    val regs = chip.registers.map(_._2)
    
    str += outputTOC(regs.toIterator)
    str += outputRegisters(regs.toIterator) 

    val filename = f"${chip.LibraryPath}/${chip.chipID.name}/docs/${chip.chipID.name}.md"
    writeFile(filename, str)
  }

}