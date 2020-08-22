#include <stdint.h>
#include <stdbool.h>

#include "ps_init_program.h"
#include <hw/ddrc.h>
#include "hw/memory_map.h"

#define REG(reg)(ddrc_##reg##_REG)
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

    PSI_MULTI_WRITE_MULTI_MASKED32( REG(ddrc_ctrl),
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
    PSI_WRITE_MASKED32( REG(phy_cmd_timeout_rddata_cpt),
                                0xFF0F8FFFU ,0x77010800U ),

    PSI_MULTI_WRITE_MULTI_MASKED32( REG(DLL_calib),
                                6,
                                0x00010000U ,0x00000000U,
                                0x0000FFFFU ,0x00005003U,
                                0x000017FFU ,0x0000003EU,
                                0x00021FE0U ,0x00020000U,
                                0x03FFFFFFU ,0x00284141U,
                                0x0000FFFFU ,0x00001610U),

    PSI_MULTI_WRITE_MULTI_MASKED32( REG(ctrl_reg5),
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
    PSI_WRITE_MASKED32(REG(CHE_UNCORR_ECC_LOG_REG_OFFSET),
                                0x00000001U ,0x00000000U),

    PSI_MULTI_WRITE_MULTI_MASKED32( REG(CHE_ECC_CONTROL_REG_OFFSET),
                                2,
                                0x00000003U ,0x00000000U,
                                0x000000FFU ,0x00000000U),
    PSI_MULTI_WRITE_MULTI_MASKED32( REG(CHE_ECC_STATS_REG_OFFSET),
                                2,
                                0x000000FFU ,0x00000000U,
                                0x0000000FU ,0x00000008U
                                ),
    PSI_MULTI_WRITE_MULTI_MASKED32( REG(phy_rcvr_enable),
                                5,
                                0x000000FFU ,0x00000000U,
                                0x7FFFFFCFU ,0x40000001U,
                                0x7FFFFFCFU ,0x40000001U,
                                0x7FFFFFCFU ,0x40000000U,
                                0x7FFFFFCFU ,0x40000000U
                               ),
    PSI_MULTI_WRITE_MULTI_MASKED32( REG(phy_init_ratio0),
                                4,
                                0x000FFFFFU ,0x0002A800U,
                                0x000FFFFFU ,0x00029400U,
                                0x000FFFFFU ,0x0001D800U,
                                0x000FFFFFU ,0x0001E000U 
                                ),
    PSI_MULTI_WRITE_MULTI_MASKED32( REG(phy_rd_dqs_cfg0),
                                4,
                                0x000FFFFFU ,0x00000035U,
                                0x000FFFFFU ,0x00000035U,
                                0x000FFFFFU ,0x00000035U,
                                0x000FFFFFU ,0x00000035U),
    PSI_MULTI_WRITE_MULTI_MASKED32( REG(phy_wr_dqs_cfg0),
                                4,
                                0x000FFFFFU ,0x0000007AU,
                                0x000FFFFFU ,0x00000080U,
                                0x000FFFFFU ,0x0000007FU,
                                0x000FFFFFU ,0x0000007CU),
    PSI_MULTI_WRITE_MULTI_MASKED32( REG(phy_we_cfg0),
                                4,
                                0x001FFFFFU ,0x000000FFU,
                                0x001FFFFFU ,0x000000FAU,
                                0x001FFFFFU ,0x000000CBU,
                                0x001FFFFFU ,0x000000CDU),
    PSI_MULTI_WRITE_MULTI_MASKED32( REG(wr_data_slv0),
                                4,
                                0x000FFFFFU ,0x000000BAU,
                                0x000FFFFFU ,0x000000C0U,
                                0x000FFFFFU ,0x000000BFU,
                                0x000FFFFFU ,0x000000BCU),
    PSI_MULTI_WRITE_MULTI_MASKED32( REG(reg_64),
                                2,
                                0x6FFFFEFEU ,0x00040080U,
                                0x000FFFFFU ,0x0001FC82U),
    PSI_MULTI_WRITE_MULTI_MASKED32( REG(page_mask),
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
    PSI_MULTI_WRITE_MULTI_MASKED32( REG(lpddr_ctrl0),
                                4,
                                0x00000FF5U ,0x00000000U,
                                0xFFFFFFFFU ,0x00000000U,
                                0x003FFFFFU ,0x00005125U,
                                0x0003FFFFU ,0x000012A6U),
    PSI_POLL_GLOBAL_MASKED32( 0XF8000B74, 0x00002000U), // POLL slcr.DDRIOB_DCI_STATUS
    PSI_WRITE_MASKED32(REG(ddrc_ctrl), 0x0001FFFFU ,0x00000085U ),
    PSI_POLL_MASKED32(REG(read_data_capture_FIFOmode_sts), 0x00000007U),

    PSI_END_PROGRAM
};

#if DEBUG_WRITES == 1 
static void GeneratePs7initComparator(uint32_t* array)
{
#define EMIT_WRITE(addr, val) array[(addr & 0x0FFF)/4] = val
#define EMIT_MASKWRITE(addr, mask, val) array[(addr & 0x0FFF)/4] = (val & mask) | (array[(addr & 0x0FFF)/4] & (~mask))
#define EMIT_MASKPOLL(addr, mask)
    // DDR v3 silicon
    EMIT_MASKWRITE(0XF8006000, 0x0001FFFFU ,0x00000084U);
    EMIT_MASKWRITE(0XF8006004, 0x0007FFFFU ,0x0000107FU);
    EMIT_MASKWRITE(0XF8006008, 0x03FFFFFFU ,0x03C0780FU);
    EMIT_MASKWRITE(0XF800600C, 0x03FFFFFFU ,0x02001001U);
    EMIT_MASKWRITE(0XF8006010, 0x03FFFFFFU ,0x00014001U);
    EMIT_MASKWRITE(0XF8006014, 0x001FFFFFU ,0x0004279AU);
    EMIT_MASKWRITE(0XF8006018, 0xF7FFFFFFU ,0x44E354D2U);
    EMIT_MASKWRITE(0XF800601C, 0xFFFFFFFFU ,0x720238E5U);
    EMIT_MASKWRITE(0XF8006020, 0x7FDFFFFCU ,0x270872D0U);
    EMIT_MASKWRITE(0XF8006024, 0x0FFFFFC3U ,0x00000000U);
    EMIT_MASKWRITE(0XF8006028, 0x00003FFFU ,0x00002007U);
    EMIT_MASKWRITE(0XF800602C, 0xFFFFFFFFU ,0x00000008U);
    EMIT_MASKWRITE(0XF8006030, 0xFFFFFFFFU ,0x00040930U);
    EMIT_MASKWRITE(0XF8006034, 0x13FF3FFFU ,0x00011674U);
    EMIT_MASKWRITE(0XF8006038, 0x00000003U ,0x00000000U);
    EMIT_MASKWRITE(0XF800603C, 0x000FFFFFU ,0x00000666U);
    EMIT_MASKWRITE(0XF8006040, 0xFFFFFFFFU ,0xFFFF0000U);
    EMIT_MASKWRITE(0XF8006044, 0x0FFFFFFFU ,0x0F555555U);
    EMIT_MASKWRITE(0XF8006048, 0x0003F03FU ,0x0003C008U);
    EMIT_MASKWRITE(0XF8006050, 0xFF0F8FFFU ,0x77010800U);
    EMIT_MASKWRITE(0XF8006058, 0x00010000U ,0x00000000U);
    EMIT_MASKWRITE(0XF800605C, 0x0000FFFFU ,0x00005003U);
    EMIT_MASKWRITE(0XF8006060, 0x000017FFU ,0x0000003EU);
    EMIT_MASKWRITE(0XF8006064, 0x00021FE0U ,0x00020000U);
    EMIT_MASKWRITE(0XF8006068, 0x03FFFFFFU ,0x00284141U);
    EMIT_MASKWRITE(0XF800606C, 0x0000FFFFU ,0x00001610U);
    EMIT_MASKWRITE(0XF8006078, 0x03FFFFFFU ,0x00466111U);
    EMIT_MASKWRITE(0XF800607C, 0x000FFFFFU ,0x00032222U);
    EMIT_MASKWRITE(0XF80060A4, 0xFFFFFFFFU ,0x10200802U);
    EMIT_MASKWRITE(0XF80060A8, 0x0FFFFFFFU ,0x0670C845U);
    EMIT_MASKWRITE(0XF80060AC, 0x000001FFU ,0x000001FEU);
    EMIT_MASKWRITE(0XF80060B0, 0x1FFFFFFFU ,0x1CFFFFFFU);
    EMIT_MASKWRITE(0XF80060B4, 0x00000200U ,0x00000200U);
    EMIT_MASKWRITE(0XF80060B8, 0x01FFFFFFU ,0x00200066U);
    EMIT_MASKWRITE(0XF80060C4, 0x00000003U ,0x00000000U);
    EMIT_MASKWRITE(0XF80060C8, 0x000000FFU ,0x00000000U);
    EMIT_MASKWRITE(0XF80060DC, 0x00000001U ,0x00000000U);
    EMIT_MASKWRITE(0XF80060F0, 0x0000FFFFU ,0x00000000U);
    EMIT_MASKWRITE(0XF80060F4, 0x0000000FU ,0x00000008U);
    EMIT_MASKWRITE(0XF8006114, 0x000000FFU ,0x00000000U);
    EMIT_MASKWRITE(0XF8006118, 0x7FFFFFCFU ,0x40000001U);
    EMIT_MASKWRITE(0XF800611C, 0x7FFFFFCFU ,0x40000001U);
    EMIT_MASKWRITE(0XF8006120, 0x7FFFFFCFU ,0x40000000U);
    EMIT_MASKWRITE(0XF8006124, 0x7FFFFFCFU ,0x40000000U);
    EMIT_MASKWRITE(0XF800612C, 0x000FFFFFU ,0x0002A800U);
    EMIT_MASKWRITE(0XF8006130, 0x000FFFFFU ,0x00029400U);
    EMIT_MASKWRITE(0XF8006134, 0x000FFFFFU ,0x0001D800U);
    EMIT_MASKWRITE(0XF8006138, 0x000FFFFFU ,0x0001E000U);
    EMIT_MASKWRITE(0XF8006140, 0x000FFFFFU ,0x00000035U);
    EMIT_MASKWRITE(0XF8006144, 0x000FFFFFU ,0x00000035U);
    EMIT_MASKWRITE(0XF8006148, 0x000FFFFFU ,0x00000035U);
    EMIT_MASKWRITE(0XF800614C, 0x000FFFFFU ,0x00000035U);
    EMIT_MASKWRITE(0XF8006154, 0x000FFFFFU ,0x0000007AU);
    EMIT_MASKWRITE(0XF8006158, 0x000FFFFFU ,0x00000080U);
    EMIT_MASKWRITE(0XF800615C, 0x000FFFFFU ,0x0000007FU);
    EMIT_MASKWRITE(0XF8006160, 0x000FFFFFU ,0x0000007CU);
    EMIT_MASKWRITE(0XF8006168, 0x001FFFFFU ,0x000000FFU);
    EMIT_MASKWRITE(0XF800616C, 0x001FFFFFU ,0x000000FAU);
    EMIT_MASKWRITE(0XF8006170, 0x001FFFFFU ,0x000000CBU);
    EMIT_MASKWRITE(0XF8006174, 0x001FFFFFU ,0x000000CDU);
    EMIT_MASKWRITE(0XF800617C, 0x000FFFFFU ,0x000000BAU);
    EMIT_MASKWRITE(0XF8006180, 0x000FFFFFU ,0x000000C0U);
    EMIT_MASKWRITE(0XF8006184, 0x000FFFFFU ,0x000000BFU);
    EMIT_MASKWRITE(0XF8006188, 0x000FFFFFU ,0x000000BCU);
    EMIT_MASKWRITE(0XF8006190, 0x6FFFFEFEU ,0x00040080U);
    EMIT_MASKWRITE(0XF8006194, 0x000FFFFFU ,0x0001FC82U);
    EMIT_MASKWRITE(0XF8006204, 0xFFFFFFFFU ,0x00000000U);
    EMIT_MASKWRITE(0XF8006208, 0x000703FFU ,0x000003FFU);
    EMIT_MASKWRITE(0XF800620C, 0x000703FFU ,0x000003FFU);
    EMIT_MASKWRITE(0XF8006210, 0x000703FFU ,0x000003FFU);
    EMIT_MASKWRITE(0XF8006214, 0x000703FFU ,0x000003FFU);
    EMIT_MASKWRITE(0XF8006218, 0x000F03FFU ,0x000003FFU);
    EMIT_MASKWRITE(0XF800621C, 0x000F03FFU ,0x000003FFU);
    EMIT_MASKWRITE(0XF8006220, 0x000F03FFU ,0x000003FFU);
    EMIT_MASKWRITE(0XF8006224, 0x000F03FFU ,0x000003FFU);
    EMIT_MASKWRITE(0XF80062A8, 0x00000FF5U ,0x00000000U);
    EMIT_MASKWRITE(0XF80062AC, 0xFFFFFFFFU ,0x00000000U);
    EMIT_MASKWRITE(0XF80062B0, 0x003FFFFFU ,0x00005125U);
    EMIT_MASKWRITE(0XF80062B4, 0x0003FFFFU ,0x000012A6U);
    EMIT_MASKPOLL(0XF8000B74, 0x00002000U);
    EMIT_MASKWRITE(0XF8006000, 0x0001FFFFU ,0x00000085U);
    EMIT_MASKPOLL(0XF8006054, 0x00000007U);
}

void ddrcRunInitProgram() 
{
    uint32_t array[ 0xFFF ] = {0};
    GeneratePs7initComparator(array);
    psi_RunProgram(ddrc_init, array);
}
#else
void ddrcRunInitProgram() 
{
    psi_RunProgram(ddrc_init, 0);
}
#endif

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