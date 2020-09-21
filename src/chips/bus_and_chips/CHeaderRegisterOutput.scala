package bus_and_chips
import java.io._
import scala.collection.mutable.StringBuilder
import java.util.Calendar

object CHeaderRegisterOutput
{
  def generateHeaders(chip : Chip) : Unit =
  {
    ensureDirectories(f"${chip.LibraryPath}/${chip.chipID.name}/include/${chip.chipID.name}/")
    ensureDirectories(f"${chip.LibraryPath}/${chip.chipID.name}/src/")
    
    if(chip.isHard) 
    {
      generateHardHeaders(chip.asInstanceOf[HardChip])
    }
    else
    {
      generateCustomHeaders(chip.asInstanceOf[CustomChip])
    }
    generateCMakeList(chip)
    copyCHeaderFiles(chip)
    copyCSrcFiles(chip)
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

  private def copyCHeaderFiles(chip : Chip) : Unit = 
  {
    var s : StringBuilder = new StringBuilder()
    val path = f"${chip.LibraryPath}/${chip.chipID.name}/include/${chip.chipID.name}/"

    chip.cHeaderSrc.foreach{ case (fileName, cSrc) => {
      writeFile(path + fileName, cSrc)
    }}
  }

  private def copyCSrcFiles(chip : Chip) : Unit = 
  {
    var s : StringBuilder = new StringBuilder()
    val path = f"${chip.LibraryPath}/${chip.chipID.name}/src/"
    chip.cSrc.foreach{ case (fileName, cSrc) => {
      writeFile(path + fileName, cSrc)
    }}
  }

  private def generateCMakeList(chip : Chip) : Unit =
  {
    var s : StringBuilder = new StringBuilder()
    val dT = Calendar.getInstance()
    s ++= f"set(project ${chip.chipID.name})%n"
    s ++= f"project($${project} C ASM)%n"
    if(chip.cSrc.length > 0)
      s ++= f"file(GLOB_RECURSE SRCLIST CONFIGURE_DEPENDS src/*.c)%n"

    s ++= f"file(GLOB_RECURSE HEADERLIST CONFIGURE_DEPENDS include/*.h)%n"
    if(chip.cSrc.length > 0)
    {
      s ++= f"add_library($${project} $${SRCLIST} $${HEADERLIST})%n"
      s ++= f"target_include_directories($${project} PUBLIC include)%n"
      s ++= f"target_link_libraries($${project} PUBLIC core)%n"
      s ++= f"target_link_libraries($${project} PUBLIC serial_debug)%n"
    }
    else {
      s ++= f"add_library($${project} INTERFACE)%n"
      s ++= f"target_include_directories($${project} INTERFACE include)%n"
    }

    val cmakefilename = f"${chip.LibraryPath}/${chip.chipID.name}/CMakeLists.txt"
    writeFile(cmakefilename, s.result)
  }

  private def generateHardHeaders(chip : HardChip) : Unit =
  {
    val dT = Calendar.getInstance()
    chip.registerBanks.foreach( rb => {
      val filename = f"${chip.LibraryPath}/${chip.chipID.name}/include/${chip.chipID.name}/${rb.name}.h"
      var s : StringBuilder = new StringBuilder()
      s ++= f"#pragma once%n"
      s ++= f"// Copyright Deano Calver%n"
      s ++= f"// SPDX-License-Identifier: MIT%n"
      s ++= f"// ${rb.description}%n"
      s ++= f"// Auto-generated on ${dT.getTime()}%n"
      s ++= f"%n#include <stdint.h>%n";
      s ++= f"%n// ${rb.banks.length} banks of ${rb.name} chips%n"

      if(rb.banks.length < 2) s ++= f"#define ${rb.name}%s_BASE_ADDR ${rb.banks(0)._2}%#010xU%n"
      else rb.banks.foreach( b => {
        s ++= f"#define ${b._1}%s_BASE_ADDR ${b._2 & 0xFFFFFFFFL}%#010xU%n"
      })

      rb.registers.foreach( r => {
        val register = chip.getRegisterByName(r)
        s ++= outputRegister(register)
      })

      writeFile(filename, s.result)
    })

    // generate the primary config header
    var sb : StringBuilder = new StringBuilder()

    sb ++= f"#pragma once%n"
    sb ++= f"// Copyright Deano Calver%n"
    sb ++= f"// SPDX-License-Identifier: MIT%n"
    chip.description.split("\n").foreach(l => sb ++= f"// $l%n")
    sb ++= f"#define ${chip.chipID.name.toUpperCase} 1"

    val chipfilename = f"${chip.LibraryPath}/${chip.chipID.name}/include/${chip.chipID.name}/${chip.chipID.name}.h"
    writeFile(chipfilename, sb.result)
  }

  private def outputRegister(register : Register) : String = {
    var s : StringBuilder = new StringBuilder()
    s ++= f"%n// ${register.defi.description}%n"
    s ++= f"#define ${register.defi.name}_OFFSET ${register.address}%#010xU%n"

    var totalUserMask : Long = 0

    register.defi.fields.foreach( f => {
      if(!f.desc.describe().isEmpty && f.desc.describe()!="Reserved") 
        s++= f"// ${f.desc.describe}%n"
      else if(f.desc.describe().isEmpty)
        totalUserMask |= f.bits.mask

      s++= f"#define ${register.defi.name}_${f.name}_LSHIFT ${f.bits.lo}%#010xU%n"
      if(f.bits.singleBit) s++= f"#define ${register.defi.name}_${f.name} ${f.bits.mask}%#10xU%n"
      s++= f"#define ${register.defi.name}_${f.name}_MASK ${f.bits.mask}%#010xU%n"
    })
    if(totalUserMask != 0)
      s++= f"#define ${register.defi.name}_MASK ${totalUserMask & 0xFFFFFFFF}%#010xU%n"

    s.result
  }

  private def generateCustomHeaders(chip : CustomChip) : Unit =
  {
    val filename = f"${chip.LibraryPath}/${chip.chipID.name}/include/${chip.chipID.name}/${chip.chipID.name}.h"
    val dT = Calendar.getInstance()
    var s : StringBuilder = new StringBuilder()
    s ++= f"#pragma once%n"
    s ++= f"// Copyright Deano Calver%n"
    s ++= f"// SPDX-License-Identifier: MIT%n"
    s ++= f"// Auto-generated on ${dT.getTime()}%n"
    chip.description.split("\n").foreach(l => s ++= f"// $l%n")
    s ++= f"%n#include <stdint.h>%n";

    val mb = chip.motherboard
    // TODO s ++= f"#define ${rb.name}%s_BASE_ADDR ${rb.banks(0)._2}%#010x%n"
    // TODO need to work out if this bus/chip is exposed to particular CPUs
    val buses = mb.getBusesConnectedToChip(chip.chipID).map(c => mb.getBusByID(c))
    if(buses.length > 1)
      buses.foreach( b => {
        s ++= f"#define ${chip.chipID.name}_${b.busID.name}_BASE_ADDR ${b.getAbsoluteChipAddress(chip.chipID)}%#010xU%n"
      })
    else if(buses.length == 1) s ++= f"#define ${chip.chipID.name}_BASE_ADDR ${buses(0).getAbsoluteChipAddress(chip.chipID)}%#010xU%n"

    chip.registers.foreach( r => s ++= outputRegister(r._2) )
    
    writeFile(filename, s.result)
  }

}