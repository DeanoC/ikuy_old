#include <stdint.h>
#include <stdbool.h>

#include "ps_init_program.h"
#include "zynq_ps/ddrc.h"
#include "zynq_ps/memory_map.h"

#define REG(reg)(ddrc_##reg##_OFFSET)
#define MASK(field) (ddrc_##field##_MASK)
#define VAL(field, val) (val << ddrc_##field##_LSHIFT)

#define ASSERT_RESET(reg, field) \
    PSI_WRITE_MASKED32(  REG(reg), \
                        MASK(field), \
                        VAL(field, 0x1) ), \
    PSI_WRITE_MASKED32(  REG(reg), \
                        MASK(field), \
                        VAL(field, 0x0) )

#define POLL(reg, mask) PSI_POLL_MASKED32(  REG(reg), MASK(mask) )

// these values are taking from a vitis project.
static PSI_IWord const ddrc_init[] = 
{
    PSI_SET_REGISTER_BANK(ddrc_BASE_ADDR),

    //----
    // DDR
    //----
    // for now just blast ps7_init values into the registers

    PSI_MULTI_WRITE_MULTI_MASKED32( REG(CTRL),
                                19,
                                0x0001FFFFU ,0x00000084U,
                                0x0007FFFFU ,0x0000107FU,
                                0x03FFFFFFU ,0x03C0780FU,
                                0x03FFFFFFU ,0x02001001U,
                                0x03FFFFFFU ,0x00014001U,
                                0x001FFFFFU ,0x0004279AU,
                                0xF7FFFFFFU ,0x44E354D2U,
                                0xFFFFFFFFU ,0x720238E5U,
                                0x7FDFFFFCU ,0x270872D0U,
                                0x0FFFFFC3U ,0x00000000U,
                                0x00003FFFU ,0x00002007U,
                                0xFFFFFFFFU ,0x00000008U,
                                0xFFFFFFFFU ,0x00040930U,
                                0x13FF3FFFU ,0x00011674U,
                                0x00000003U ,0x00000000U,
                                0x000FFFFFU ,0x00000666U,
                                0xFFFFFFFFU ,0xFFFF0000U,
                                0x0FFFFFFFU ,0x0F555555U,
                                0x0003F03FU ,0x0003C008U),
    PSI_WRITE_MASKED32( REG(PHY_CMD_TIMEOUT_RDDATA_CPT),
                                0xFF0F8FFFU ,0x77010800U ),

    PSI_MULTI_WRITE_MULTI_MASKED32( REG(DLL_CALIB),
                                6,
                                0x00010000U ,0x00000000U,
                                0x0000FFFFU ,0x00005003U,
                                0x000017FFU ,0x0000003EU,
                                0x00021FE0U ,0x00020000U,
                                0x03FFFFFFU ,0x00284141U,
                                0x0000FFFFU ,0x00001610U),

    PSI_MULTI_WRITE_MULTI_MASKED32( REG(CTRL5),
                                2,
                                0x03FFFFFFU ,0x00466111U,
                                0x000FFFFFU ,0x00032222U),

    PSI_MULTI_WRITE_MULTI_MASKED32( REG(CHE_T_ZQ),
                                8,
                                0xFFFFFFFFU ,0x10200802U,
                                0x0FFFFFFFU ,0x0670C845U,
                                0x000001FFU ,0x000001FEU,
                                0x1FFFFFFFU ,0x1CFFFFFFU,
                                0x00000200U ,0x00000200U,
                                0x01FFFFFFU ,0x00200066U,
                                0x00000003U ,0x00000000U,
                                0x000000FFU ,0x00000000U ),
    PSI_WRITE_MASKED32(REG(CHE_UNCORR_ECC_LOG),
                                0x00000001U ,0x00000000U),

    PSI_MULTI_WRITE_MULTI_MASKED32( REG(CHE_ECC_CONTROL),
                                2,
                                0x00000003U ,0x00000000U,
                                0x000000FFU ,0x00000000U),
    PSI_MULTI_WRITE_MULTI_MASKED32( REG(CHE_ECC_STATS),
                                2,
                                0x000000FFU ,0x00000000U,
                                0x0000000FU ,0x00000008U
                                ),
    PSI_MULTI_WRITE_MULTI_MASKED32( REG(PHY_RCVR_ENABLE),
                                5,
                                0x000000FFU ,0x00000000U,
                                0x7FFFFFCFU ,0x40000001U,
                                0x7FFFFFCFU ,0x40000001U,
                                0x7FFFFFCFU ,0x40000000U,
                                0x7FFFFFCFU ,0x40000000U
                               ),
    PSI_MULTI_WRITE_MULTI_MASKED32( REG(PHY_INIT_RATIO0),
                                4,
                                0x000FFFFFU ,0x0002A800U,
                                0x000FFFFFU ,0x00029400U,
                                0x000FFFFFU ,0x0001D800U,
                                0x000FFFFFU ,0x0001E000U 
                                ),
    PSI_MULTI_WRITE_MULTI_MASKED32( REG(PHY_RD_DQS_CFG0),
                                4,
                                0x000FFFFFU ,0x00000035U,
                                0x000FFFFFU ,0x00000035U,
                                0x000FFFFFU ,0x00000035U,
                                0x000FFFFFU ,0x00000035U),
    PSI_MULTI_WRITE_MULTI_MASKED32( REG(PHY_WR_DQS_CFG0),
                                4,
                                0x000FFFFFU ,0x0000007AU,
                                0x000FFFFFU ,0x00000080U,
                                0x000FFFFFU ,0x0000007FU,
                                0x000FFFFFU ,0x0000007CU),
    PSI_MULTI_WRITE_MULTI_MASKED32( REG(PHY_WE_CFG0),
                                4,
                                0x001FFFFFU ,0x000000FFU,
                                0x001FFFFFU ,0x000000FAU,
                                0x001FFFFFU ,0x000000CBU,
                                0x001FFFFFU ,0x000000CDU),
    PSI_MULTI_WRITE_MULTI_MASKED32( REG(WR_DATA_SLV0),
                                4,
                                0x000FFFFFU ,0x000000BAU,
                                0x000FFFFFU ,0x000000C0U,
                                0x000FFFFFU ,0x000000BFU,
                                0x000FFFFFU ,0x000000BCU),
    PSI_MULTI_WRITE_MULTI_MASKED32( REG(REG_64),
                                2,
                                0x6FFFFEFEU ,0x00040080U,
                                0x000FFFFFU ,0x0001FC82U),
    PSI_MULTI_WRITE_MULTI_MASKED32( REG(PAGE_MASK),
                                9,
                                0xFFFFFFFFU ,0x00000000U,
                                0x000703FFU ,0x000003FFU,
                                0x000703FFU ,0x000003FFU,
                                0x000703FFU ,0x000003FFU,
                                0x000703FFU ,0x000003FFU,
                                0x000F03FFU ,0x000003FFU,
                                0x000F03FFU ,0x000003FFU,
                                0x000F03FFU ,0x000003FFU,
                                0x000F03FFU ,0x000003FFU),
    PSI_MULTI_WRITE_MULTI_MASKED32( REG(LPDDR_CTRL0),
                                4,
                                0x00000FF5U ,0x00000000U,
                                0xFFFFFFFFU ,0x00000000U,
                                0x003FFFFFU ,0x00005125U,
                                0x0003FFFFU ,0x000012A6U),
    PSI_POLL_GLOBAL_MASKED32( 0XF8000B74, 0x00002000U), // POLL slcr.DDRIOB_DCI_STATUS
    PSI_WRITE_MASKED32(REG(CTRL), 0x0001FFFFU ,0x00000085U ),
    PSI_POLL_MASKED32(REG(READ_DATA_CAPTURE_FIFOMODE_STS), 0x00000007U),

    PSI_END_PROGRAM
};

void ddrcRunInitProgram() 
{
    psi_RunProgram(ddrc_init, 0);
}

bool ddrEarlyMemTest()
{
    // the early test just does a MB as we the CPU might be 
    // throttled down at this point

    uint32_t const TEST_AMOUNT = (1024 * 1024 * 1);

    uint8_t *addr = (uint8_t *)MEM_MAP_DDR_START;
    for (uint32_t i = 0; i < TEST_AMOUNT;++i)
    {
        *addr = 0xdc;
        if ((*addr) != 0xdc)
        {
            return false;
        }
        addr++;
    }

    addr = (uint8_t*)MEM_MAP_DDR_START;
    for (uint32_t i = 0; i < TEST_AMOUNT; ++i)
    {
        if((*addr) != 0xdc) 
        {
            return false;
        }
        addr++;
    }

    return true;
}