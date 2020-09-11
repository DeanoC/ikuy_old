#pragma once
#include <stdint.h>
#include <stdbool.h>

// zynq has 2 hw i2c buses each with a 16 byte fifo
// i2c is a slow (upto 400KiB/s) but simple bus
// its used in many system as a configuration bus
// HDMI and many cameras use it for this purpose

// peripheral devices (aka slaves) on the bus each have 
// an address either made of 7 or 11 bits
// a polled or interupt mode is supported 

// zynq does support being a peripheral but currently only 
// master mode is supported by this library

// the speed is governed by the CPU_1x clock (108 MHz by default)
// CPU_1x / ((1 to 4) * (1 to 64))
// There are two standard I2C speed 100 KHz and 400 KHz (hispeed i2c)

// for custom mode, you will have to calculate A and B and
// call hw_i2c_set_custom_speed
typedef enum HW_I2C_SPEED
{
  HWI2CS_100KHz = 0,
  HWI2CS_400KHz,
  HWI2CS_CUSTOM
} HW_I2C_SPEED;

void hw_i2c_setup(uint8_t index, uint8_t basepin, HW_I2C_SPEED speed, bool extendedAddress);
void hw_i2c_reset(uint8_t index);
