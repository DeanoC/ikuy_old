
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

const char* ctiRegisterDefs = 
#include "cti_regdef.txt"
;

const char* ctiFieldDefs = 
#include "cti_fielddef.txt"
;

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

const char* slcrRegisterDefs = 
#include "slcr_regdef.txt"
;
const char* slcrFieldDefs = 
#include "slcr_fielddef.txt"
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
#define SINGLE_BANK(name, description, addr) registerHW.emplace_back( #name, #description, addr, name##RegisterDefs, name##FieldDefs )
#define MULTI_BANK(bankname, description, ... ) registerHW.emplace_back( std::vector{ __VA_ARGS__ }, #bankname, #description, bankname##RegisterDefs, bankname##FieldDefs )

    std::vector<RegisterBankImplementations> registerHW;

    MULTI_BANK(cti, CoreSight Cross Trigger Interface, 
                BANK_IMPL(debug_cpu_cti0,       0xF8898000 ), 
                BANK_IMPL(debug_cpu_cti1,       0xF8899000 ),
                BANK_IMPL(debug_cti_etb_tpiu,   0xF8802000 ),
                BANK_IMPL(debug_cti_ftm,        0xF8809000 ) );
    SINGLE_BANK(ddrc, DDR Memory Controller, 0xF8006000);
    SINGLE_BANK(devcfg, Device (PL) Config, 0xF8007000);
    SINGLE_BANK(slcr, System Level Control, 0xF8000000);
    MULTI_BANK(uart, UART (serial), BANK_IMPL(uart0, 0xE0000000), BANK_IMPL(uart1, 0xE0001000) );
    SINGLE_BANK(gpio, GPIO, 0xE000A000);
    SINGLE_BANK(qspi, Quad SPI, 0xE000D000);
    MULTI_BANK(spi, SPI, BANK_IMPL(spi0, 0xE0006000), BANK_IMPL(spi1, 0xE0007000) );
    SINGLE_BANK(scu, CPU Configuration (mpcore), 0xF8F00000);

    for (auto &&i : registerHW)
    {
        i.GenerateRegisterStructures();
    }
    

}

