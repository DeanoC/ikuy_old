package bus_and_chips
import java.io._
import scala.collection.mutable.StringBuilder
import java.util.Calendar

object CHeaderRegisterOutput
{
  def generateHeaders(chip : Chip, headerPath : String) : Unit =
  {
    if(chip.isHard) 
    {
      generateHardHeaders(chip.asInstanceOf[HardChip], headerPath)
    }
    else
    {
      generateCustomHeaders(chip.asInstanceOf[CustomChip], headerPath)
    }
  }

  private def writeFile(filename: String, s: String): Unit = {
      val file = new File(filename)
      val bw = new BufferedWriter(new FileWriter(file))
      bw.write(s)
      bw.close()
  }
  private def generateHardHeaders(chip : HardChip, headerPath : String) : Unit =
  {
    chip.registerBanks.foreach( rb => {
      val filename = headerPath + rb.name + ".h"
      val dT = Calendar.getInstance()
      var s : StringBuilder = new StringBuilder()
      s ++= f"#pragma once%n"
      s ++= f"// Copyright Deano Calver%n"
      s ++= f"// SPDX-License-Identifier: MIT%n"
      s ++= f"// ${rb.description}%n"
      s ++= f"// Auto-generated on ${dT.getTime()}%n"
      s ++= f"%n#include <stdint.h>%n";
      s ++= f"%n// ${rb.banks.length} banks of ${rb.name} chips%n"

      if(rb.banks.length < 2) s ++= f"#define ${rb.name}%s_BASE_ADDR ${rb.banks(0)._2}%#010x%n"
      else rb.banks.foreach( b => {
        s ++= f"#define ${b._1}%s_BASE_ADDR ${b._2 & 0xFFFFFFFFL}%#010x%n"
      })

      rb.registers.foreach( r => {
        val register = chip.getRegisterByName(r)
        s ++= f"%n// ${register.defi.description}%n"
        s ++= f"#define ${r}_OFFSET ${register.address}%#010x%n"

        var totalUserMask : Long = 0

        register.defi.fields.foreach( f => {
          if(!f.desc.describe().isEmpty && f.desc.describe()!="Reserved") 
            s++= f"// ${f.desc.describe}%n"
          else if(f.desc.describe().isEmpty)
            totalUserMask |= f.bits.mask

          s++= f"#define ${r}_${f.name}_LSHIFT ${f.bits.lo}%#010xU%n"
          if(f.bits.singleBit) s++= f"#define ${r}_${f.name} ${f.bits.mask}%#10xU%n"
          s++= f"#define ${r}_${f.name}_MASK ${f.bits.mask}%#010xU%n"
        })
        if(totalUserMask != 0)
          s++= f"#define ${r}_MASK ${totalUserMask & 0xFFFFFFFF}%#010xU%n"
      })

      writeFile(filename, s.result)
    })

  }

  private def generateCustomHeaders(chip : CustomChip, path : String) : Unit =
  {

  }

}