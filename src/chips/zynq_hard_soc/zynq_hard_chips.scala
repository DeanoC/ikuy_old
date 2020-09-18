package zynq_hard_soc

import spinal.core._
import spinal.lib._
import spinal.lib.io._

// All these 'chips' are hard instances in the Zynq SoC
sealed trait ZynqSocChips { val ChipCount : Int = 1 }

object ZYNQ_ETHERNET extends ZynqSocChips { override val ChipCount = 2 }
object ZYNQ_TRIPLE_TIMER extends ZynqSocChips { override val ChipCount: Int = 2 }
object ZYNQ_WATCH_DOG extends ZynqSocChips { override val ChipCount: Int = 1 }
object ZYNQ_SPI extends ZynqSocChips { override val ChipCount: Int = 2 }
object ZYNQ_I2C extends ZynqSocChips { override val ChipCount = 2 }
object ZYNQ_CAN extends ZynqSocChips { override val ChipCount: Int = 2 }
object ZYNQ_UART extends ZynqSocChips { override val ChipCount: Int = 2 }
object ZYNQ_SDIO extends ZynqSocChips { override val ChipCount: Int = 2 }
object ZYNQ_USB extends ZynqSocChips { override val ChipCount: Int = 2 }
object ZYNQ_DMA extends ZynqSocChips { override val ChipCount: Int = 4 }
