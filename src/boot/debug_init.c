#include "ps_init_program.h"
#include "zynq_ps/cti.h"

#define REG(reg)(cti_##reg##_OFFSET)
#define MASK(field) (field##_MASK)
#define VAL(field, val) (val << field##_LSHIFT)

static PSI_IWord const debug_cpu_cti0_init[] = 
{
    PSI_SET_REGISTER_BANK(debug_cpu_cti0_BASE_ADDR),
    PSI_WRITE_32( REG(LAR), 0xC5ACCE55 ),
    PSI_END_PROGRAM
};

static PSI_IWord const debug_cpu_cti1_init[] = 
{
    PSI_SET_REGISTER_BANK(debug_cpu_cti1_BASE_ADDR),
    PSI_WRITE_32(REG(LAR), 0xC5ACCE55 ),
    PSI_END_PROGRAM
};

static PSI_IWord const debug_cti_etb_tpiu_init[] = 
{
    PSI_SET_REGISTER_BANK(debug_cpu_etb_tpiu_BASE_ADDR),
    PSI_WRITE_32(REG(LAR), 0xC5ACCE55 ),
    PSI_END_PROGRAM
};


void debugRunInitProgram() 
{
    psi_RunProgram(debug_cpu_cti0_init, 0);
    psi_RunProgram(debug_cpu_cti1_init, 0);
    psi_RunProgram(debug_cti_etb_tpiu_init, 0);
}
