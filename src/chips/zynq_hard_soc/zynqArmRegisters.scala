package zynq_hard_soc
import bus_and_chips._
import spinal.core._
import scala.io.Source
import scala.util.Try
import scala.collection.mutable.HashMap
import java.io.{ File, FileNotFoundException, IOException }

object ZynqArmRegisters
{
  // this is shit, tried resources but couldn't get it to work...
  private val registerBasePath = "../chips/zynq_hard_soc/registers/"

  def parseRegisters(c : HardChip)
  {
    parseMultiBanks(c, "uart", Vector(
        ("uart0", 0xE0000000L),
        ("uart1", 0xE0001000L)
      ), "UART (serial)"
    )
    parseMultiBanks(c, "usb", Vector(
        ("usb0", 0xE0002000L),
        ("usb1", 0xE0003000L)
      ), "USB Controller"
    )
    parseMultiBanks(c, "i2c", Vector(
        ("i2c0", 0xE0004000L),
        ("i2c1", 0xE0005000L)
      ), "Inter Integrated Circuit(I2C)"
    )
    parseMultiBanks(c, "spi", Vector(
        ("spi0", 0xE0006000L),
        ("spi1", 0xE0007000L)
      ), "Serial Peripheral Interface"
    )
    parseMultiBanks(c, "can", Vector(
        ("can0", 0xE0008000L),
        ("can1", 0xE0009000L)
      ), "Controller Area Network"
    )
    parseSingleBank(c, "gpio", 0xE000A000L, "General Purpose Input/Output")
    parseMultiBanks(c, "gem", Vector(
        ("gem0", 0xE000B000L),
        ("gem1", 0xE000C000L)
      ), "Gigabit Ethernet Controller"
    )
    parseSingleBank(c, "qspi", 0xE000D000L, "Quad SPI")
    parseSingleBank(c, "smcc", 0xE000E000L, "Static Memory Controller")
    parseMultiBanks(c, "sdio", Vector(
        ("sd0", 0xE0100000L),
        ("sd1", 0xE0101000L)
      ), "SD2.0/SDIO2.0/MMC3.31"
    )

    parseSingleBank(c, "slcr", 0xF8000000L, "System Level Control Registers")
    parseMultiBanks(c, "ttc", Vector(
        ("ttc0", 0xF8001000L),
        ("ttc1", 0xF8002000L)
      ), "Triple Timer Counter"
    )
    parseMultiBanks(c, "dmac", Vector(
        ("dmac0_s",  0xF8003000L),
        ("dmac0_ns", 0xF8004000L)
      ), "Direct Memory Access Controller (PL330)"
    )
    parseSingleBank(c, "swdt", 0xF8005000L, "System Watchdog Timer")
    parseSingleBank(c, "ddrc", 0xF8006000L, "DDR Memory Controller")
    parseSingleBank(c, "devcfg", 0xF8007000L, "Device (PL) Config")
    parseMultiBanks(c, "axi_hp", Vector(
        ("axi_hp0",  0xF8008000L),
        ("axi_hp1",  0xF8009000L),
        ("axi_hp2",  0xF800A000L),
        ("axi_hp3",  0xF800B000L)
      ), "AXI_HP Interface (AFI)"
    )

    parseSingleBank(c, "dap", 0xF8800000L, "Debug Access Port ROM Table")
    parseSingleBank(c, "etb", 0xF8801000L, "Embedded Trace Buffer")
    parseSingleBank(c, "tpiu", 0xF8803000L, "Trace Port Interface")
    parseSingleBank(c, "funnel", 0xF8804000L, "CoreSight Trace Funnel")
    parseSingleBank(c, "itm", 0xF8805000L, "Fabric Trace")
    parseSingleBank(c, "ftm", 0xF880B000L, "Instrumentation Trace")
    parseMultiBanks(c, "cti", Vector(
        ("debug_cpu_cti0",      0xF8898000L),
        ("debug_cpu_cti1",      0xF8899000L),
        ("debug_cpu_etb_tpiu",  0xF8802000L),
        ("debug_cpu_ftm",       0xF8809000L)
      ), "CoreSight Cross Trigger Interface"
    )
    parseMultiBanks(c, "cortexa9_pmu", Vector(
        ("debug_cpu_pmu0",      0xF8891000L),
        ("debug_cpu_pmu1",      0xF8893000L)
    ), "Cortex A9 Performance Monitoring Unit")
    parseMultiBanks(c, "ptm", Vector(
        ("debug_cpu_ptm0",      0xF889C000L),
        ("debug_cpu_ptm1",      0xF889D000L)
    ), "CoreSight PTM-A9")

    parseSingleBank(c, "scu", 0xF8F00000L, "CPU Configuration (mpcore)")
    parseSingleBank(c, "l2cache", 0xF8F02000L, "L2 Cache PL310")
  }

  private def parseRegisterLines(c : HardChip, chipName : String, regLines : Iterator[String])
  {
    regLines.foreach(l => {
      val words = l.split(" ").map(_.trim).filter(_!=" ")
      if(words.length < 6)
      {
        if(words.length > 0)
        {
          println(s"${words(0)} register hasn't a valid doc line!")
        }
      }
      else
      {
        var defa : Long = if(words(4)(0) == 'x') 0L
          else Try(
              Integer.parseInt(words(4).slice(2, words(4).length), 16)
            ).toOption.getOrElse[Int](0) & 0xFFFFFFFFL

        try {
          val register = HardRegister( RegisterDef(
                      name = words(0),
                      rtype = AccessType.fromString(words(3)),
                      width = words(2).toInt,
                      description = words.slice(5, words.length).mkString(" "),
                      default = defa ) )

          val address : Long = Try(
                Integer.parseInt(words(1).slice(2, words(1).length), 16)
              ).toOption.getOrElse[Int](0) & 0xFFFFFFFFL
          register.address = address.toInt
          c.addRegister(register)
        } catch {
            case _ : Throwable => println(f"Error decoding ${words(0)} doc line")
        }

      }
    })
  }

  private def parseFieldLongDescs(c : Chip, chipName : String, lines : Iterator[String]) : HashMap[String, String] =
  {
    var name : String = ""
    var longText : String = ""
    var hm = HashMap[String, String]()
    lines.foreach(l => {
      val words = l.split(" ").map(_.trim)
      if(words(0).isEmpty)
      {
        // end if long description
        hm += name -> longText
        longText = ""
        name = ""
      } else if(words.length == 3 && words(0) == "**")
      {
        // start of long description
        name = words(1) + "_" + words(2)
      } else
      {
        // more text for the long description
        longText += l + "\n"
      }
    })
    hm
  }


  private def parseFields(c : Chip, chipName : String, fieldLines : Iterator[String], longDescs : HashMap[String, String]) =
  {
    var registerName : String = ""
    var register : Register = null
    var bitsSumForRegister : Int = 0
    var reservedCount = 0
    fieldLines.foreach(l => {
      val words = l.split(" ").map(_.trim)
      words.length match {
        case 0 => {
          assert(false)
        }
        case 1 => if(words(0).isEmpty)
          {
            if(register != null && bitsSumForRegister != register.defi.width)
              println(f"${register.defi.name} has ${bitsSumForRegister}%d bits in fields but is ${register.defi.width}%d bits wide!")

            // end of a registers field defs
            registerName = ""
            register = null
            reservedCount = 0
          }
          else
          {
            // start of a registers field defs
            registerName = chipName + "_" + words(0)
            register = c.getRegisterByName(registerName)
            bitsSumForRegister = 0
          }
        case len => if(len < 4)
          {
            println(s"${register.defi.name}.${words(0)} hasn't got a valid doc line!")
          }
          else
          {
            val regFieldKey = registerName + "_" + words(0)
            val shortDesc = words.slice(4, words.length).mkString(" ")
            val longDesc = if(longDescs.contains(regFieldKey)) longDescs(regFieldKey) else ""

            val field = if(words(0).toLowerCase().contains("reserved"))
            {
              if(words(0).toLowerCase() == "reserved")
              {
                val fd = FieldDoc( f"${words(0)}_$reservedCount", BitsDesc(words(1)), AccessType.fromString(words(2)), StringFieldDesc("Reserved"))
                reservedCount = reservedCount + 1
                fd
              } else
                FieldDoc( f"${words(0)}", BitsDesc(words(1)), AccessType.fromString(words(2)), StringFieldDesc("Reserved"))

            }
            else FieldDoc( words(0), BitsDesc(words(1)), AccessType.fromString(words(2)), StringFieldDesc(shortDesc, longDesc))
            bitsSumForRegister = bitsSumForRegister + field.bits.bitCount
            register.defi.fields += field
          }
      }
    })
  }
  private def parseMultiBanks(c : HardChip, chipName : String, banks : Vector[(String, Long)], desc : String)
  {
    c.addRegisterBanks(chipName, banks, desc)
    try {
      val regFile = Source.fromFile(s"${registerBasePath}${chipName}_regdef.txt")
      parseRegisterLines(c, chipName, regFile.getLines)
    } catch {
      case e: FileNotFoundException => {println(s"${chipName}_regdef.txt doesn't exists. No Docs for you!"); return }
      case e: IOException => { println("Had an IOException trying to read that file"); return }
    }

    var fieldLines : Iterator[String] = null
    try {
      val fieldFile =Source.fromFile(s"${registerBasePath}${chipName}_fielddef.txt")
      fieldLines = fieldFile.getLines
    } catch {
      case e: FileNotFoundException => return
      case e: IOException => { println("Had an IOException trying to read that file"); return }
    }
    var fieldLongDescLines = Iterator[String]()
    try {
      val fieldLongDescFile = Source.fromFile(s"${registerBasePath}${chipName}_field_long_desc_def.txt")
      fieldLongDescLines = fieldLongDescFile.getLines
    } catch {
      case e: FileNotFoundException =>
      case e: IOException => println("Had an IOException trying to read that file")
    }

    parseFields(c, chipName, fieldLines, parseFieldLongDescs(c, chipName, fieldLongDescLines))
  }
  private def parseSingleBank(c : HardChip, chipName : String, baseAddress : Long, desc : String)
  {
    parseMultiBanks(c, chipName, Vector((chipName, baseAddress)), desc)
  }
}