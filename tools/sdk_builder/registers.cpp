
#include <stdint.h>
#include <vector>
#include <string>
#include <sstream>
#include <map>
#include <algorithm>
#include <assert.h>

#include "xilinx_register_info.h"
#include "mmio.h"
#include "register_bank.h"
#include "register_bank_implementations.h"

const char* ddrcRegisterDefs = 
#include "ddrc_regdef.txt"
;

// TODO ddrc fields defs
const char* ddrcFieldDefs = 
#include "ddrc_fielddef.txt"
;

const char* devcfgRegisterDefs = 
#include "devcfg_regdef.txt"
;
const char* devcfgFieldDefs = 
#include "devcfg_fielddef.txt"
;

const char* sclrRegisterDefs = 
#include "sclr_regdef.txt"
;
const char* sclrFieldDefs = 
#include "sclr_fielddef.txt"
;

const char* uartRegisterDefs = 
#include "uart_regdef.txt"
;
const char* uartFieldDefs = 
#include "uart_fielddef.txt"
;

const char* gpioRegisterDefs = 
#include "gpio_regdef.txt"
;

const char* gpioFieldDefs = 
#include "gpio_fielddef.txt"
;

const char* qspiRegisterDefs = 
#include "qspi_regdef.txt"
;

const char* qspiFieldDefs = 
#include "qspi_fielddef.txt"
;

const char* spiRegisterDefs = 
#include "spi_regdef.txt"
;

const char* spiFieldDefs = 
#include "spi_fielddef.txt"
;

const char* scuRegisterDefs = 
#include "scu_regdef.txt"
;

const char* scuFieldDefs = 
#include "scu_fielddef.txt"
;

void InitRegisterData() {
#define BANK_IMPL(name, addr) std::pair{std::string{#name}, addr} 
#define SINGLE_BANK(name, addr) registerHW.emplace_back( #name, addr, name##RegisterDefs, name##FieldDefs )
#define MULTI_BANK(bankname, ... ) registerHW.emplace_back( std::vector{ __VA_ARGS__ }, #bankname, bankname##RegisterDefs, bankname##FieldDefs )

    std::vector<RegisterBankImplementations> registerHW;

    SINGLE_BANK(ddrc, 0xF8006000);
    SINGLE_BANK(devcfg, 0xF8007000);
    SINGLE_BANK(sclr, 0xF8000000);
    MULTI_BANK(uart, BANK_IMPL(uart0, 0xE0000000), BANK_IMPL(uart1, 0xE0001000) );
    SINGLE_BANK(gpio, 0xE000A000);
    SINGLE_BANK(qspi, 0xE000D000);
    MULTI_BANK(spi, BANK_IMPL(spi0, 0xE0006000), BANK_IMPL(spi1, 0xE0007000) );
    SINGLE_BANK(scu, 0xF8F00000);

    for (auto &&i : registerHW)
    {
        i.GenerateRegisterStructures();
    }
    

}

