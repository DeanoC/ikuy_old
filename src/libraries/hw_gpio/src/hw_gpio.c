#include <assert.h>
#include "hw_gpio/hw_gpio.h"
#include "hw/gpio.h"
#include "hw/reg.h"

void hw_gpio_configure_mio(uint8_t pin, HW_GPIO_MIO_DIRECTION const direction)
{
  assert(pin < 54);
  // pin 7 and 8 of bank 0 are always outputs
  assert((pin != 7 && pin != 8) || (direction == HWGMD_OUT));

  if(pin > 31)
  {
    pin -= 32;

    switch (direction)
    {
    case HWGMD_IN:
      *HW_REG(gpio, DIRM_1) = *HW_REG(gpio, DIRM_1) & ~(1 << pin);
      break;
    case HWGMD_OUT:
      *HW_REG(gpio, DIRM_1) = *HW_REG(gpio, DIRM_1) | (1 << pin);
      break;
    case HWGMD_TRISTATE:
      *HW_REG(gpio, OEN_1) = *HW_REG(gpio, OEN_1) & ~(1 << pin);
      *HW_REG(gpio, DIRM_1) = *HW_REG(gpio, DIRM_1) | (1 << pin);
      break;
    }
  } else 
  {
    switch (direction)
    {
    case HWGMD_IN:
      *HW_REG(gpio, DIRM_0) = *HW_REG(gpio, DIRM_0) & ~(1 << pin);
      break;
    case HWGMD_OUT:
      *HW_REG(gpio, DIRM_0) = *HW_REG(gpio, DIRM_0) | (1 << pin);
      break;
    case HWGMD_TRISTATE:
      *HW_REG(gpio, OEN_0) = *HW_REG(gpio, OEN_0) & ~(1 << pin);
      *HW_REG(gpio, DIRM_0) = *HW_REG(gpio, DIRM_0) | (1 << pin);
      break;
    }
  }
}

void hw_gpio_configure_emio(uint8_t pin, HW_GPIO_EMIO_DIRECTION const direction)
{
  if (pin > 31)
  {
    pin -= 32;

    switch (direction)
    {
    case HWGED_IN:
      *HW_REG(gpio, DIRM_3) = *HW_REG(gpio, DIRM_3) & ~(1 << pin);
      break;
    case HWGED_OUT:
      *HW_REG(gpio, DIRM_3) = *HW_REG(gpio, DIRM_3) | (1 << pin);
      break;
    }
  }
  else
  {
    switch (direction)
    {
    case HWGED_IN:
      *HW_REG(gpio, DIRM_2) = *HW_REG(gpio, DIRM_2) & ~(1 << pin);
      break;
    case HWGED_OUT:
      *HW_REG(gpio, DIRM_2) = *HW_REG(gpio, DIRM_2) | (1 << pin);
      break;
    }
  }
}

bool hw_gpio_read_mio(uint8_t pin)
{
  assert(pin < 54);
  if (pin > 31)
  {
    pin -= 32;
    return !!((*HW_REG(gpio, DATA_1_RO)) & (1 << pin));
  } else
  {
    return !!((*HW_REG(gpio, DATA_0_RO)) & (1 << pin));
  }
}

bool hw_gpio_read_emio(uint8_t pin)
{
  if (pin > 31)
  {
    pin -= 32;
    return !!((*HW_REG(gpio, DATA_3_RO)) & (1 << pin));
  }
  else
  {
    return !!((*HW_REG(gpio, DATA_2_RO)) & (1 << pin));
  }
}

void hw_gpio_write_mio(uint8_t pin, bool value)
{
  assert(pin < 54);
  if (pin > 31)
  {
    pin -= 32;
    if (value)
    {
      *HW_REG(gpio, DATA_1) = *HW_REG(gpio, DATA_1) | (1 << pin);
    }
    else
    {
      *HW_REG(gpio, DATA_1) = *HW_REG(gpio, DATA_1) & (~(1 << pin));
    }
  }
  else
  {
    if (value)
    {
      *HW_REG(gpio, DATA_0) = *HW_REG(gpio, DATA_0) | (1 << pin);
    }
    else
    {
      *HW_REG(gpio, DATA_0) = *HW_REG(gpio, DATA_0) & (~(1 << pin));
    }
  }
}

void hw_gpio_write_emio(uint8_t pin, bool value)
{
  if (pin > 31)
  {
    pin -= 32;
    if(value)
    {
      *HW_REG(gpio, DATA_3) = *HW_REG(gpio, DATA_3) | (1 << pin);
    } 
    else
    {
      *HW_REG(gpio, DATA_3) = *HW_REG(gpio, DATA_3) & (~(1 << pin));
    }
  }
  else
  {
    if (value)
    {
      *HW_REG(gpio, DATA_2) = *HW_REG(gpio, DATA_2) | (1 << pin);
    }
    else
    {
      *HW_REG(gpio, DATA_2) = *HW_REG(gpio, DATA_2) & (~(1 << pin));
    }
  }
}

uint32_t hw_gpio_read_mio_bank(HW_GPIO_MIO_BANK const bank)
{
  if(bank == HWGMB_BANK0)
  {
    return *HW_REG(gpio, DATA_0_RO);
  } else
  {
    return *HW_REG(gpio, DATA_1_RO);
  }
}

uint32_t hw_gpio_read_emio_bank(HW_GPIO_EMIO_BANK const bank)
{
  if (bank == HWGEB_BANK0)
  {
    return *HW_REG(gpio, DATA_2_RO);
  }
  else
  {
    return *HW_REG(gpio, DATA_3_RO);
  }
}

void hw_gpio_write_mio_bank(HW_GPIO_MIO_BANK const bank, uint32_t value)
{
  if (bank == HWGMB_BANK0)
  {
    *HW_REG(gpio, DATA_0) = value;
  }
  else
  {
    *HW_REG(gpio, DATA_1) = value;
  }
}

void hw_gpio_write_emio_bank(HW_GPIO_EMIO_BANK const bank, uint32_t value)
{
  if (bank == HWGEB_BANK0)
  {
    *HW_REG(gpio, DATA_2) = value;
  }
  else
  {
    *HW_REG(gpio, DATA_3) = value;
  }
}

void hw_gpio_write_masked_half_bank0_msw(HW_GPIO_MASKED_HALF_BANK value)
{
  *HW_REG(gpio, MASK_DATA_0_MSW) = value.v;
}
void hw_gpio_write_masked_half_bank0_lsw(HW_GPIO_MASKED_HALF_BANK value)
{
  *HW_REG(gpio, MASK_DATA_0_LSW) = value.v;
}
void hw_gpio_write_masked_half_bank1_msw(HW_GPIO_MASKED_HALF_BANK value)
{
  *HW_REG(gpio, MASK_DATA_1_MSW) = value.v;
}
void hw_gpio_write_masked_half_bank1_lsw(HW_GPIO_MASKED_HALF_BANK value)
{
  *HW_REG(gpio, MASK_DATA_1_LSW) = value.v;
}
void hw_gpio_write_masked_half_bank2_msw(HW_GPIO_MASKED_HALF_BANK value)
{
  *HW_REG(gpio, MASK_DATA_2_MSW) = value.v;
}
void hw_gpio_write_masked_half_bank2_lsw(HW_GPIO_MASKED_HALF_BANK value)
{
  *HW_REG(gpio, MASK_DATA_2_LSW) = value.v;
}
void hw_gpio_write_masked_half_bank3_msw(HW_GPIO_MASKED_HALF_BANK value)
{
  *HW_REG(gpio, MASK_DATA_3_MSW) = value.v;
}
void hw_gpio_write_masked_half_bank3_lsw(HW_GPIO_MASKED_HALF_BANK value)
{
  *HW_REG(gpio, MASK_DATA_3_LSW) = value.v;
}