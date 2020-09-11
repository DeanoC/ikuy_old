#include <assert.h>
#include "hw_i2c/i2c.h"
#include "hw/slcr.h"
#include "hw/reg.h"

void hw_i2c_setup(uint8_t index, uint8_t basepin, HW_I2C_SPEED speed, bool extendedAddress)
{
    assert(index < 2);
    assert(basepin <= 52);

    if (index == 0)
    {
        assert(basepin == 10 || basepin == 14 || basepin == 18 || basepin == 22 ||
               basepin == 26 || basepin == 30 || basepin == 34 || basepin == 38 ||
               basepin == 42 || basepin == 46 || basepin == 50);
    }
    else 
    {
        assert(basepin == 12 || basepin == 16 || basepin == 20 || basepin == 24 ||
               basepin == 28 || basepin == 32 || basepin == 38 || basepin == 40 ||
               basepin == 44 || basepin == 48 || basepin == 52);
    }

    hw_slcr_unlock();

    // i2c is a pair of pins, we have to config MIO for the pair

    // Route I2C 0 SCL signal to pin low num (50 as an example).
    // Route I2C 0 SDA signal to pin high num (51).

    // both pins need the following state set
    // 3-state controlled by I2C (set TRI_ENABLE = 0)
    // LVCMOS18
    // Slow CMOS edge (benign setting).
    // Enable internal pull-up resistor.
    // Disable HSTL receiver.

    // Note L3/2/1/0 have restriction on each pin
    // TODO make enum of this in gpio or a slcr lib?
    // L3
    // b000 GPIO
    // b001 CAN
    // b010 I2C
    // b011 PJTAG
    // b100 SDIO
    // b101 SPI
    // b110 TTC
    // b111 UART
    // L2
    // b00 Level 3 Mux
    // b01 SRAM/NOR
    // b10 NAND
    // b11 SDIO
    // L1
    // b0 Level 2 Mux
    // b1 USB
    // L0
    // b0 Level 1 Mux
    // b1 Ethernet

    // D P IOT S L3  L2 1 0 T
    // 0 1 001 0 010 00 0 0 0 = 0x1240
    // 01 0010 0100 0000
    //  1 | 2  | 4  | 0 |
    uint32_t const mioPinCfg = HW_MAKE_REG_FIELD_VAL(slcr, MIO_PIN_00, DisableRcvr, 0x0) |
                               HW_MAKE_REG_FIELD_VAL(slcr, MIO_PIN_00, PULLUP, 0x1) |
                               HW_MAKE_REG_FIELD_VAL(slcr, MIO_PIN_00, IO_Type, 0x1) | // LVCMOS18
                               HW_MAKE_REG_FIELD_VAL(slcr, MIO_PIN_00, Speed, 0) |
                               HW_MAKE_REG_FIELD_VAL(slcr, MIO_PIN_00, L3_SEL, 0x2) |
                               HW_MAKE_REG_FIELD_VAL(slcr, MIO_PIN_00, L2_SEL, 0) |
                               HW_MAKE_REG_FIELD_VAL(slcr, MIO_PIN_00, L1_SEL, 0) |
                               HW_MAKE_REG_FIELD_VAL(slcr, MIO_PIN_00, L0_SEL, 0) |
                               HW_MAKE_REG_FIELD_VAL(slcr, MIO_PIN_00, TRI_ENABLE, 0);

    *HW_REG_ARRAY(slcr, MIO_PIN_00, basepin) = mioPinCfg;
    *HW_REG_ARRAY(slcr, MIO_PIN_00, basepin + 1) = mioPinCfg;

    // if custom the caller has to set the speed themselves
    if (speed != HWI2CS_CUSTOM)
    {

    }

    hw_slcr_lock();
}
