#pragma once

#include <stdint.h>
#include <stdbool.h>

typedef enum HW_GPIO_MIO_DIRECTION
{
  HWGMD_IN = 0,
  HWGMD_OUT = 1,
  HWGMD_TRISTATE = 2,
 } HW_GPIO_MIO_DIRECTION;

typedef enum HW_GPIO_EMIO_DIRECTION
{
  HWGED_IN = 0,
  HWGED_OUT = 1,
} HW_GPIO_EMIO_DIRECTION;

typedef enum HW_GPIO_MIO_BANK
{
  HWGMB_BANK0 = 0,
  HWGMB_BANK1 = 1,
} HW_GPIO_MIO_BANK;

typedef enum HW_GPIO_EMIO_BANK
{
  HWGEB_BANK0 = 0,
  HWGEB_BANK1 = 1,
} HW_GPIO_EMIO_BANK;

typedef union HW_GPIO_MASKED_HALF_BANK
{
  struct {
    uint16_t mask;
    uint16_t data;
  };
  uint32_t v;
} HW_GPIO_MASKED_HALF_BANK;

    // mio are 54 pins connected directly to the PS (banks 0 and 1)
    void
    hw_gpio_configure_mio(uint8_t const pin, HW_GPIO_MIO_DIRECTION const direction);

// emio are 64 signals connected via the FPGA (banks 2 and 3)
void hw_gpio_configure_emio(uint8_t const pin, HW_GPIO_EMIO_DIRECTION const direction);

// Note you can always read a gpio pin even when its in output mode
bool hw_gpio_read_mio(uint8_t const pin);
bool hw_gpio_read_emio(uint8_t const pin);

void hw_gpio_write_mio(uint8_t const pin, bool value);
void hw_gpio_write_emio(uint8_t const pin, bool value);

// bank read and write (a bank is continous 32 pins block)
// top 22 bits of MIO should/will be 0 at all time
uint32_t hw_gpio_read_mio_bank(HW_GPIO_MIO_BANK const bank);
void hw_gpio_write_mio_bank(HW_GPIO_MIO_BANK const bank, uint32_t value);

uint32_t hw_gpio_read_emio_bank(HW_GPIO_EMIO_BANK const bank);
void hw_gpio_write_emio_bank(HW_GPIO_EMIO_BANK const bank, uint32_t value);

// half banks write support allow upto 16 pins in half a bank to
// be hardware written in a single register write
// as this is for optimisation purposes this is exposed at a fairly low level
// TODO add inline/asm version to remove the function call cost if required
void hw_gpio_write_masked_half_bank0_msw(HW_GPIO_MASKED_HALF_BANK value);
void hw_gpio_write_masked_half_bank0_lsw(HW_GPIO_MASKED_HALF_BANK value);
void hw_gpio_write_masked_half_bank1_msw(HW_GPIO_MASKED_HALF_BANK value);
void hw_gpio_write_masked_half_bank1_lsw(HW_GPIO_MASKED_HALF_BANK value);
void hw_gpio_write_masked_half_bank2_msw(HW_GPIO_MASKED_HALF_BANK value);
void hw_gpio_write_masked_half_bank2_lsw(HW_GPIO_MASKED_HALF_BANK value);
void hw_gpio_write_masked_half_bank3_msw(HW_GPIO_MASKED_HALF_BANK value);
void hw_gpio_write_masked_half_bank3_lsw(HW_GPIO_MASKED_HALF_BANK value);
