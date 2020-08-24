#include "ps_init_program.h"
#include "hw/slcr.h"

#define REG(reg)(slcr_##reg##_REG)
#define MASK(field) (slcr_##field##_MASK)
#define VAL(field, val) (val << slcr_##field##_LSHIFT)

#define ASSERT_RESET(reg, field) \
    PSI_WRITE_MASKED32(  REG(reg), \
                        MASK(field), \
                        VAL(field, 0x1) ), \
    PSI_WRITE_MASKED32(  REG(reg), \
                        MASK(field), \
                        VAL(field, 0x0) )

#define POLL(reg, mask) PSI_POLL_MASKED32(  REG(reg), MASK(mask) )

// these values are taking from a vitis project.
static PSI_IWord const slcr_init[] = 
{
    PSI_SET_REGISTER_BANK(slcr_BASE_ADDR),

    PSI_WRITE_32(REG(SLCR_UNLOCK), 0xDF0DU), // unlock

    //---- 
    // MIO 
    //---- 
    PSI_WRITE_N_MASKED32(REG(DDRIOB_ADDR0),
                        2,
                        MASK(DDRIOB_ADDR0_RESERVED_INP_POWER) | 
                        MASK(DDRIOB_ADDR0_INP_TYPE) |
                        MASK(DDRIOB_ADDR0_DCI_UPDATE_B) |
                        MASK(DDRIOB_ADDR0_TERM_EN) |
                        MASK(DDRIOB_ADDR0_DCI_TYPE) |
                        MASK(DDRIOB_ADDR0_IBUF_DISABLE_MODE) |
                        MASK(DDRIOB_ADDR0_TERM_DISABLE_MODE) |
                        MASK(DDRIOB_ADDR0_OUTPUT_EN) |
                        MASK(DDRIOB_ADDR0_PULLUP_EN),
                        VAL(DDRIOB_ADDR0_RESERVED_INP_POWER, 0) | 
                        VAL(DDRIOB_ADDR0_INP_TYPE, 0) |
                        VAL(DDRIOB_ADDR0_DCI_UPDATE_B, 0) |
                        VAL(DDRIOB_ADDR0_TERM_EN, 0) |
                        VAL(DDRIOB_ADDR0_DCI_TYPE, 0) |
                        VAL(DDRIOB_ADDR0_IBUF_DISABLE_MODE, 0) |
                        VAL(DDRIOB_ADDR0_TERM_DISABLE_MODE, 0) |
                        VAL(DDRIOB_ADDR0_OUTPUT_EN, 0x3) |
                        VAL(DDRIOB_ADDR0_PULLUP_EN, 0)                        
                        ),

    PSI_MULTI_WRITE_MASKED32(REG(DDRIOB_DATA0),
                        5,                        
                        MASK(DDRIOB_DATA0_RESERVED_INP_POWER) | 
                        MASK(DDRIOB_DATA0_INP_TYPE) |
                        MASK(DDRIOB_DATA0_DCI_UPDATE_B) |
                        MASK(DDRIOB_DATA0_TERM_EN) |
                        MASK(DDRIOB_DATA0_DCI_TYPE) |
                        MASK(DDRIOB_DATA0_IBUF_DISABLE_MODE) |
                        MASK(DDRIOB_DATA0_TERM_DISABLE_MODE) |
                        MASK(DDRIOB_DATA0_OUTPUT_EN) |
                        MASK(DDRIOB_DATA0_PULLUP_EN),

                        VAL(DDRIOB_DATA0_RESERVED_INP_POWER, 0x0) | 
                        VAL(DDRIOB_DATA0_INP_TYPE, 0x1) |
                        VAL(DDRIOB_DATA0_DCI_UPDATE_B, 0x0) |
                        VAL(DDRIOB_DATA0_TERM_EN, 0x1) |
                        VAL(DDRIOB_DATA0_DCI_TYPE, 0x3) |
                        VAL(DDRIOB_DATA0_IBUF_DISABLE_MODE, 0x0) |
                        VAL(DDRIOB_DATA0_TERM_DISABLE_MODE, 0x0) |
                        VAL(DDRIOB_DATA0_OUTPUT_EN, 0x3) |
                        VAL(DDRIOB_DATA0_PULLUP_EN, 0x0),

                        VAL(DDRIOB_DATA1_RESERVED_INP_POWER, 0x0) | 
                        VAL(DDRIOB_DATA1_INP_TYPE, 0x0) |
                        VAL(DDRIOB_DATA1_DCI_UPDATE_B, 0x0) |
                        VAL(DDRIOB_DATA1_TERM_EN, 0x0) |
                        VAL(DDRIOB_DATA1_DCI_TYPE, 0x0) |
                        VAL(DDRIOB_DATA1_IBUF_DISABLE_MODE, 0x0) |
                        VAL(DDRIOB_DATA1_TERM_DISABLE_MODE, 0x0) |
                        VAL(DDRIOB_DATA1_OUTPUT_EN, 0x0) |
                        VAL(DDRIOB_DATA1_PULLUP_EN, 0x1),

                        VAL(DDRIOB_DIFF0_RESERVED_INP_POWER, 0x0) | 
                        VAL(DDRIOB_DIFF0_INP_TYPE, 0x2) |
                        VAL(DDRIOB_DIFF0_DCI_UPDATE_B, 0x0) |
                        VAL(DDRIOB_DIFF0_TERM_EN, 0x1) |
                        VAL(DDRIOB_DIFF0_DCI_TYPE, 0x3) |
                        VAL(DDRIOB_DIFF0_IBUF_DISABLE_MODE, 0x0) |
                        VAL(DDRIOB_DIFF0_TERM_DISABLE_MODE, 0x0) |
                        VAL(DDRIOB_DIFF0_OUTPUT_EN, 0x3) |
                        VAL(DDRIOB_DIFF0_PULLUP_EN, 0x0),

                        VAL(DDRIOB_DIFF1_RESERVED_INP_POWER, 0x0) | 
                        VAL(DDRIOB_DIFF1_INP_TYPE, 0x0) |
                        VAL(DDRIOB_DIFF1_DCI_UPDATE_B, 0x0) |
                        VAL(DDRIOB_DIFF1_TERM_EN, 0x0) |
                        VAL(DDRIOB_DIFF1_DCI_TYPE, 0x0) |
                        VAL(DDRIOB_DIFF1_IBUF_DISABLE_MODE, 0x0) |
                        VAL(DDRIOB_DIFF1_TERM_DISABLE_MODE, 0x0) |
                        VAL(DDRIOB_DIFF1_OUTPUT_EN, 0x0) |
                        VAL(DDRIOB_DIFF1_PULLUP_EN, 0x1),
                        
                        VAL(DDRIOB_CLOCK_RESERVED_INP_POWER, 0x0) | 
                        VAL(DDRIOB_CLOCK_INP_TYPE, 0x0) |
                        VAL(DDRIOB_CLOCK_DCI_UPDATE_B, 0x0) |
                        VAL(DDRIOB_CLOCK_TERM_EN, 0x0) |
                        VAL(DDRIOB_CLOCK_DCI_TYPE, 0x0) |
                        VAL(DDRIOB_CLOCK_IBUF_DISABLE_MODE, 0x0) |
                        VAL(DDRIOB_CLOCK_TERM_DISABLE_MODE, 0x0) |
                        VAL(DDRIOB_CLOCK_OUTPUT_EN, 0x3) |
                        VAL(DDRIOB_CLOCK_PULLUP_EN, 0x0)
        ),

    // these are all reserved values so we just blindly
    // copy the ps7_init settings rather than making it pretty
    PSI_MULTI_WRITE_MASKED32(REG(DDRIOB_DRIVE_SLEW_ADDR),
                        4, 
                        0xFFFFFFFFU, // mask
                        0x0018C61CU,
                        0x00F9861CU,
                        0x00F9861CU,
                        0x00F9861CU ),
    PSI_WRITE_MASKED32(REG(DDRIOB_DDR_CTRL),
                        MASK(DDRIOB_DDR_CTRL_VREF_INT_EN) |
                        MASK(DDRIOB_DDR_CTRL_VREF_SEL) |
                        MASK(DDRIOB_DDR_CTRL_VREF_EXT_EN) |
                        MASK(DDRIOB_DDR_CTRL_RESERVED_VREF_PULLUP_EN) |
                        MASK(DDRIOB_DDR_CTRL_REFIO_EN) |
                        MASK(DDRIOB_DDR_CTRL_RESERVED_REFIO_TEST) |
                        MASK(DDRIOB_DDR_CTRL_RESERVED_REFIO_PULLUP_EN) |
                        MASK(DDRIOB_DDR_CTRL_RESERVED_DRST_B_PULLUP_EN) |
                        MASK(DDRIOB_DDR_CTRL_RESERVED_CKE_PULLUP_EN),

                        VAL(DDRIOB_DDR_CTRL_VREF_INT_EN, 0x0) |
                        VAL(DDRIOB_DDR_CTRL_VREF_SEL, 0x0) |
                        VAL(DDRIOB_DDR_CTRL_VREF_EXT_EN, 0x1) |
                        VAL(DDRIOB_DDR_CTRL_RESERVED_VREF_PULLUP_EN, 0x0) |
                        VAL(DDRIOB_DDR_CTRL_REFIO_EN, 0x1) |
                        VAL(DDRIOB_DDR_CTRL_RESERVED_REFIO_TEST, 0x0) |
                        VAL(DDRIOB_DDR_CTRL_RESERVED_REFIO_PULLUP_EN, 0x0) |
                        VAL(DDRIOB_DDR_CTRL_RESERVED_DRST_B_PULLUP_EN, 0x0) |
                        VAL(DDRIOB_DDR_CTRL_RESERVED_CKE_PULLUP_EN, 0x0)
    ),
    ASSERT_RESET(DDRIOB_DCI_CTRL, DDRIOB_DCI_CTRL_RESET),
    PSI_WRITE_MASKED32(REG(DDRIOB_DCI_CTRL),
                        MASK(DDRIOB_DCI_CTRL_RESET),
                        VAL(DDRIOB_DCI_CTRL_RESET, 0x1)),
    PSI_WRITE_MASKED32(REG(DDRIOB_DCI_CTRL),
                        MASK(DDRIOB_DCI_CTRL_RESET) |
                        MASK(DDRIOB_DCI_CTRL_RESERVED_VRN_OUT),
                        VAL(DDRIOB_DCI_CTRL_RESET, 0x0) |
                        VAL(DDRIOB_DCI_CTRL_RESERVED_VRN_OUT, 0x1) ),
    PSI_WRITE_MASKED32(REG(DDRIOB_DCI_CTRL),
                        MASK(DDRIOB_DCI_CTRL_RESET) |
                        MASK(DDRIOB_DCI_CTRL_ENABLE) |
                        MASK(DDRIOB_DCI_CTRL_RESERVED_VRP_TRI) |
                        MASK(DDRIOB_DCI_CTRL_RESERVED_VRN_TRI) |
                        MASK(DDRIOB_DCI_CTRL_RESERVED_VRP_OUT) |
                        MASK(DDRIOB_DCI_CTRL_RESERVED_VRN_OUT) |
                        MASK(DDRIOB_DCI_CTRL_NREF_OPT1) |
                        MASK(DDRIOB_DCI_CTRL_NREF_OPT2) |
                        MASK(DDRIOB_DCI_CTRL_NREF_OPT4) |
                        MASK(DDRIOB_DCI_CTRL_PREF_OPT1) |
                        MASK(DDRIOB_DCI_CTRL_PREF_OPT2) |
                        MASK(DDRIOB_DCI_CTRL_UPDATE_CONTROL) |
                        MASK(DDRIOB_DCI_CTRL_RESERVED_INIT_COMPLETE) |
                        MASK(DDRIOB_DCI_CTRL_RESERVED_TST_CLK) |
                        MASK(DDRIOB_DCI_CTRL_RESERVED_TST_HLN) |
                        MASK(DDRIOB_DCI_CTRL_RESERVED_TST_HLP) |
                        MASK(DDRIOB_DCI_CTRL_RESERVED_TST_RST) |
                        MASK(DDRIOB_DCI_CTRL_RESERVED_INT_DCI_EN),

                        VAL(DDRIOB_DCI_CTRL_RESET, 0x1) |
                        VAL(DDRIOB_DCI_CTRL_ENABLE, 0x1) |
                        VAL(DDRIOB_DCI_CTRL_RESERVED_VRP_TRI, 0x0) |
                        VAL(DDRIOB_DCI_CTRL_RESERVED_VRN_TRI, 0x0) |
                        VAL(DDRIOB_DCI_CTRL_RESERVED_VRP_OUT, 0x0) |
                        VAL(DDRIOB_DCI_CTRL_RESERVED_VRN_OUT, 0x1) |
                        VAL(DDRIOB_DCI_CTRL_NREF_OPT1, 0x0) |
                        VAL(DDRIOB_DCI_CTRL_NREF_OPT2, 0x0) |
                        VAL(DDRIOB_DCI_CTRL_NREF_OPT4, 0x1) |
                        VAL(DDRIOB_DCI_CTRL_PREF_OPT1, 0x0) |
                        VAL(DDRIOB_DCI_CTRL_PREF_OPT2, 0x0) |
                        VAL(DDRIOB_DCI_CTRL_UPDATE_CONTROL, 0x0) |
                        VAL(DDRIOB_DCI_CTRL_RESERVED_INIT_COMPLETE, 0x0) |
                        VAL(DDRIOB_DCI_CTRL_RESERVED_TST_CLK, 0x0) |
                        VAL(DDRIOB_DCI_CTRL_RESERVED_TST_HLN, 0x0) |
                        VAL(DDRIOB_DCI_CTRL_RESERVED_TST_HLP, 0x0) |
                        VAL(DDRIOB_DCI_CTRL_RESERVED_TST_RST, 0x0) |
                        VAL(DDRIOB_DCI_CTRL_RESERVED_INT_DCI_EN, 0x0)
    ),
    // there are 54 MIO we set them up to the defaults in a compact manner
    PSI_MULTI_WRITE_MASKED16(REG(MIO_PIN_00),
                            54,
                            0x00003FFFU, // mask
                            PSI_PACK_16(0x1600U, 0x1602U),
                            PSI_PACK_16(0x0602U, 0x0602U),
                            PSI_PACK_16(0x0602U, 0x0602U),
                            PSI_PACK_16(0x0602U, 0x0600U),
                            PSI_PACK_16(0x0602U, 0x1600U),
                            PSI_PACK_16(0x1600U, 0x1600U),
                            PSI_PACK_16(0x1600U, 0x1600U),
                            PSI_PACK_16(0x16E1U, 0x16E0U),
                            PSI_PACK_16(0x1202U, 0x1202U),
                            PSI_PACK_16(0x1202U, 0x1202U),
                            PSI_PACK_16(0x1202U, 0x1202U),
                            PSI_PACK_16(0x1203U, 0x1203U),
                            PSI_PACK_16(0x1203U, 0x1203U),
                            PSI_PACK_16(0x1203U, 0x1203U),
                            PSI_PACK_16(0x1204U, 0x1205U),
                            PSI_PACK_16(0x1204U, 0x1205U),
                            PSI_PACK_16(0x1204U, 0x1204U),
                            PSI_PACK_16(0x1204U, 0x1204U),
                            PSI_PACK_16(0x1205U, 0x1204U),
                            PSI_PACK_16(0x1204U, 0x1204U),
                            PSI_PACK_16(0x1280U, 0x1280U),
                            PSI_PACK_16(0x1280U, 0x1280U),
                            PSI_PACK_16(0x1280U, 0x1280U),
                            PSI_PACK_16(0x1200U, 0x1201U),
                            PSI_PACK_16(0x1200U, 0x1200U),
                            PSI_PACK_16(0x1200U, 0x1200U),
                            PSI_PACK_16(0x1280U, 0x1280U)
    ),

    PSI_WRITE_MASKED32(REG(SD0_WP_CD_SEL),
                        MASK(SD0_WP_CD_SEL_SDIO0_WP_SEL) |
                        MASK(SD0_WP_CD_SEL_SDIO0_CD_SEL),
                        VAL(SD0_WP_CD_SEL_SDIO0_WP_SEL, 55) |
                        VAL(SD0_WP_CD_SEL_SDIO0_CD_SEL, 47)
                        ),

    //---- 
    // PLL
    //---- 

    // START ARM PPL INIT
    PSI_WRITE_MASKED32( REG(ARM_PLL_CFG), 
                        MASK(ARM_PLL_CFG_PLL_RES) | 
                        MASK(ARM_PLL_CFG_PLL_CP) | 
                        MASK(ARM_PLL_CFG_LOCK_CNT),                        
                        VAL(ARM_PLL_CFG_PLL_RES, 0xc) | 
                        VAL(ARM_PLL_CFG_PLL_CP, 0x2U) | 
                        VAL(ARM_PLL_CFG_LOCK_CNT, 0x177) ),
 
    // we write to ARM_PLL_CTRL 2 times in a row (not a bug!)
    // and then assert a reset (2 more times)

    // CPU PLL = 50 Mhz * 26 = ARM_PLL 1300Mhz 
    PSI_WRITE_MASKED32(  REG(ARM_PLL_CTRL),                         
                        MASK(ARM_PLL_CTRL_PLL_FDIV),                         
                        VAL(ARM_PLL_CTRL_PLL_FDIV, 0x1A) ),
    PSI_WRITE_MASKED32(  REG(ARM_PLL_CTRL),                         
                        MASK(ARM_PLL_CTRL_PLL_BYPASS_FORCE),                         
                        VAL(ARM_PLL_CTRL_PLL_BYPASS_FORCE, 0x1) ),
    ASSERT_RESET(ARM_PLL_CTRL, ARM_PLL_CTRL_PLL_RESET),

    // poll and remove the bypass when ready
    POLL(PLL_STATUS, PLL_STATUS_ARM_PLL_LOCK),
    PSI_WRITE_MASKED32(  REG(ARM_PLL_CTRL),                         
                        MASK(ARM_PLL_CTRL_PLL_BYPASS_FORCE),                         
                        VAL(ARM_PLL_CTRL_PLL_BYPASS_FORCE, 0x0) ),

    // ARM clocks (6x ratio mode)
    // CPU 6x4x Clock = 1300Mhz / 2 = 650 Mhz
    // CPU 1x Clock = 650 Mhz / 6 = 108 Mhz
    // CPU 2x Clock = 325 Mhz / 2 = 207 Mhz
    // CPU 3x2x Clock = 650Mhz / 2 = 325 Mhz
    PSI_WRITE_MASKED32(  REG(ARM_CLK_CTRL),                         
                        MASK(ARM_CLK_CTRL_SRCSEL) |
                        MASK(ARM_CLK_CTRL_DIVISOR) |
                        MASK(ARM_CLK_CTRL_CPU_6OR4XCLKACT) |
                        MASK(ARM_CLK_CTRL_CPU_3OR2XCLKACT) |
                        MASK(ARM_CLK_CTRL_CPU_2XCLKACT) |
                        MASK(ARM_CLK_CTRL_CPU_1XCLKACT) |                         
                        MASK(ARM_CLK_CTRL_CPU_PERI_CLKACT),

                        VAL(ARM_CLK_CTRL_SRCSEL, 0x0) |
                        VAL(ARM_CLK_CTRL_DIVISOR, 0x2) | // divide by 2
                        VAL(ARM_CLK_CTRL_CPU_6OR4XCLKACT, 0x1) |
                        VAL(ARM_CLK_CTRL_CPU_3OR2XCLKACT, 0x1) |
                        VAL(ARM_CLK_CTRL_CPU_2XCLKACT, 0x1) |
                        VAL(ARM_CLK_CTRL_CPU_1XCLKACT, 0x1) |                         
                        VAL(ARM_CLK_CTRL_CPU_PERI_CLKACT, 0x1)),
    // FINISH ARM PLL INIT

    // START DDR DDR INIT
    PSI_WRITE_MASKED32( REG(DDR_PLL_CFG),
                        MASK(DDR_PLL_CFG_PLL_RES) |
                        MASK(DDR_PLL_CFG_PLL_CP) |
                        MASK(DDR_PLL_CFG_LOCK_CNT),
                        VAL(DDR_PLL_CFG_PLL_RES, 0xC) |
                        VAL(DDR_PLL_CFG_PLL_CP, 0x2) |
                        VAL(DDR_PLL_CFG_LOCK_CNT, 0x1DBU) ),

    // DDR PLL = 50 Mhz * 21 = 1050 Mhz
    PSI_WRITE_MASKED32( REG(DDR_PLL_CTRL),
                        MASK(DDR_PLL_CTRL_PLL_FDIV),
                        VAL(DDR_PLL_CTRL_PLL_FDIV, 0x15)),
    PSI_WRITE_MASKED32( REG(DDR_PLL_CTRL),
                        MASK(DDR_PLL_CTRL_PLL_BYPASS_FORCE),
                        VAL(DDR_PLL_CTRL_PLL_BYPASS_FORCE, 0x1)),
    ASSERT_RESET(DDR_PLL_CTRL, DDR_PLL_CTRL_PLL_RESET),
    POLL(PLL_STATUS, PLL_STATUS_DDR_PLL_LOCK),

    PSI_WRITE_MASKED32(  REG(DDR_PLL_CTRL),                         
                        MASK(DDR_PLL_CTRL_PLL_BYPASS_FORCE),                         
                        VAL(DDR_PLL_CTRL_PLL_BYPASS_FORCE, 0x0) ),
    // DDR clocks
    // ddr_2x = 1050 Mhz / 3 = 350 Mhz
    // ddr_3x = 1050 Mhz / 2 = 525 Mhz
    PSI_WRITE_MASKED32(  REG(DDR_CLK_CTRL),                         
                        MASK(DDR_CLK_CTRL_DDR_3XCLKACT) |
                        MASK(DDR_CLK_CTRL_DDR_2XCLKACT) |
                        MASK(DDR_CLK_CTRL_DDR_3XCLK_DIVISOR) |
                        MASK(DDR_CLK_CTRL_DDR_2XCLK_DIVISOR),

                        VAL(DDR_CLK_CTRL_DDR_3XCLKACT, 0x1) |
                        VAL(DDR_CLK_CTRL_DDR_2XCLKACT, 0x1) |
                        VAL(DDR_CLK_CTRL_DDR_3XCLK_DIVISOR, 0x2) |
                        VAL(DDR_CLK_CTRL_DDR_2XCLK_DIVISOR, 0x3) ),
/*
    // clock
    // DDR DCI = 1050 Mhz / 52 = 20.2 / 2 = 10.1 Mhz
    PSI_WRITE_MASKED32( REG(DCI_CLK_CTRL),
                        MASK(DCI_CLK_CTRL_CLKACT) |
                        MASK(DCI_CLK_CTRL_DIVISOR0) |
                        MASK(DCI_CLK_CTRL_DIVISOR1),
                        VAL(DCI_CLK_CTRL_CLKACT, 0x1) |
                        VAL(DCI_CLK_CTRL_DIVISOR0, 0x34) |
                        VAL(DCI_CLK_CTRL_DIVISOR1, 0x2) ),
*/-
    // FINISH DDR PLL INIT

    // START IO PLL INIT
    PSI_WRITE_MASKED32( REG(IO_PLL_CFG),
                        MASK(IO_PLL_CFG_PLL_RES) |
                        MASK(IO_PLL_CFG_PLL_CP) |
                        MASK(IO_PLL_CFG_LOCK_CNT),
                        VAL(IO_PLL_CFG_PLL_RES, 0xC) |
                        VAL(IO_PLL_CFG_PLL_CP, 0x2) |
                        VAL(IO_PLL_CFG_LOCK_CNT, 0x1F4) ),

    // IO PLL 50 Mhz * 20 = 1000 Mhz
    PSI_WRITE_MASKED32( REG(IO_PLL_CTRL),
                        MASK(IO_PLL_CTRL_PLL_FDIV),
                        VAL(IO_PLL_CTRL_PLL_FDIV, 0x14)),
    PSI_WRITE_MASKED32( REG(IO_PLL_CTRL),
                        MASK(IO_PLL_CTRL_PLL_BYPASS_FORCE),
                        VAL(IO_PLL_CTRL_PLL_BYPASS_FORCE, 0x1)),
    ASSERT_RESET(IO_PLL_CTRL, IO_PLL_CTRL_PLL_RESET),
    POLL(PLL_STATUS, PLL_STATUS_IO_PLL_LOCK),

    PSI_WRITE_MASKED32(  REG(IO_PLL_CTRL),                         
                        MASK(IO_PLL_CTRL_PLL_BYPASS_FORCE),                         
                        VAL(IO_PLL_CTRL_PLL_BYPASS_FORCE, 0x0) ),

    // lock it back up
    PSI_WRITE_32( REG(SLCR_LOCK), 0x767B ),

    PSI_END_PROGRAM
};

static PSI_IWord const slcr_post_ddr_init[] =
{
    PSI_SET_REGISTER_BANK(slcr_BASE_ADDR),

    PSI_WRITE_32(REG(SLCR_UNLOCK), 0xDF0DU), // unlock

    //----
    // Peripharals
    //----
    // just the slcr portion of peripherals setup

    PSI_WRITE_MASKED32(REG(DDRIOB_DATA0),
                        MASK(DDRIOB_DATA0_IBUF_DISABLE_MODE) |
                        MASK(DDRIOB_DATA0_TERM_DISABLE_MODE),
                        VAL(DDRIOB_DATA0_IBUF_DISABLE_MODE, 0x1) |
                        VAL(DDRIOB_DATA0_TERM_DISABLE_MODE, 0x1)),

    PSI_WRITE_MASKED32(REG(DDRIOB_DATA1),
                        MASK(DDRIOB_DATA1_IBUF_DISABLE_MODE) |
                        MASK(DDRIOB_DATA1_TERM_DISABLE_MODE),
                        VAL(DDRIOB_DATA1_IBUF_DISABLE_MODE, 0x0) |
                        VAL(DDRIOB_DATA1_TERM_DISABLE_MODE, 0x0)),

    PSI_WRITE_MASKED32(REG(DDRIOB_DIFF0),
                        MASK(DDRIOB_DIFF0_IBUF_DISABLE_MODE) |
                        MASK(DDRIOB_DIFF0_TERM_DISABLE_MODE),
                        VAL(DDRIOB_DIFF0_IBUF_DISABLE_MODE, 0x1) |
                        VAL(DDRIOB_DIFF0_TERM_DISABLE_MODE, 0x1)),

    PSI_WRITE_MASKED32(REG(DDRIOB_DIFF1),
                        MASK(DDRIOB_DIFF1_IBUF_DISABLE_MODE) |
                        MASK(DDRIOB_DIFF1_TERM_DISABLE_MODE),
                        VAL(DDRIOB_DIFF1_IBUF_DISABLE_MODE, 0x0) |
                        VAL(DDRIOB_DIFF1_TERM_DISABLE_MODE, 0x0)),

    // GEM0 (Gigabit Ethernet)
    // use EMIO clock for recieve
    PSI_WRITE_MASKED32( REG(GEM0_RCLK_CTRL),
                        MASK(GEM0_RCLK_CTRL_CLKACT) |
                        MASK(GEM0_RCLK_CTRL_SRCSEL),
                        VAL(GEM0_RCLK_CTRL_CLKACT, 0x1) |
                        VAL(GEM0_RCLK_CTRL_SRCSEL, 0x0)),

    // use IO PLL (1000 Mhz)
    // (1000 / 8) = 125 Mhz
    PSI_WRITE_MASKED32( REG(GEM0_CLK_CTRL),
                        MASK(GEM0_CLK_CTRL_CLKACT) |
                        MASK(GEM0_CLK_CTRL_SRCSEL) | 
                        MASK(GEM0_CLK_CTRL_DIVISOR) |
                        MASK(GEM0_CLK_CTRL_DIVISOR1),
                        VAL(GEM0_CLK_CTRL_CLKACT, 0x1) |
                        VAL(GEM0_CLK_CTRL_SRCSEL, 0x0) |
                        VAL(GEM0_CLK_CTRL_DIVISOR, 0x8) |
                        VAL(GEM0_CLK_CTRL_DIVISOR1, 0x1)
                        ),
    // Quad SPI 
    // use IO PLL (10.1 Mhz)
    // 1000 / 5 = 200 Mhz
    PSI_WRITE_MASKED32( REG(LQSPI_CLK_CTRL),
                        MASK(LQSPI_CLK_CTRL_CLKACT) |
                        MASK(LQSPI_CLK_CTRL_SRCSEL) | 
                        MASK(LQSPI_CLK_CTRL_DIVISOR),
                        VAL(LQSPI_CLK_CTRL_CLKACT, 0x1) |
                        VAL(LQSPI_CLK_CTRL_SRCSEL, 0x0) |
                        VAL(LQSPI_CLK_CTRL_DIVISOR, 0x5)
                        ),
    // SDIO
    // uses IO PLL
    // 1000 / 20 = 50 Mhz 
    PSI_WRITE_MASKED32( REG(SDIO_CLK_CTRL),
                        MASK(SDIO_CLK_CTRL_CLKACT0) |
                        MASK(SDIO_CLK_CTRL_CLKACT1) |
                        MASK(SDIO_CLK_CTRL_SRCSEL) | 
                        MASK(SDIO_CLK_CTRL_DIVISOR),
                        VAL(SDIO_CLK_CTRL_CLKACT0, 0x1) |
                        VAL(SDIO_CLK_CTRL_CLKACT1, 0x0) |
                        VAL(SDIO_CLK_CTRL_SRCSEL, 0x0) |
                        VAL(SDIO_CLK_CTRL_DIVISOR, 0x14)
                        ),
    // UART0
    // use IO PLL
    // 1000 Mhz / 10 = 100 Mhz
    PSI_WRITE_MASKED32( REG(UART_CLK_CTRL),
                        MASK(UART_CLK_CTRL_CLKACT0) |
                        MASK(UART_CLK_CTRL_CLKACT1) |
                        MASK(UART_CLK_CTRL_SRCSEL) | 
                        MASK(UART_CLK_CTRL_DIVISOR),
                        VAL(UART_CLK_CTRL_CLKACT0, 0x1) |
                        VAL(UART_CLK_CTRL_CLKACT1, 0x0) |
                        VAL(UART_CLK_CTRL_SRCSEL, 0x0) |
                        VAL(UART_CLK_CTRL_DIVISOR, 0xa)
                        ),
    // PCAP (FPGA config)
    // use IO clock
    // 1000 / 5 = 200 Mhz
    PSI_WRITE_MASKED32( REG(PCAP_CLK_CTRL),
                        MASK(PCAP_CLK_CTRL_CLKACT) |
                        MASK(PCAP_CLK_CTRL_SRCSEL) |
                        MASK(PCAP_CLK_CTRL_DIVISOR),
                        VAL(PCAP_CLK_CTRL_CLKACT, 0x1) |
                        VAL(PCAP_CLK_CTRL_SRCSEL, 0x0) |
                        VAL(PCAP_CLK_CTRL_DIVISOR, 0x5)),

    // FPGA0 clock
    // use IO Pll
    // 1000 / 5 = 200 Mhz
    PSI_WRITE_MASKED32( REG(FPGA0_CLK_CTRL),
                        MASK(FPGA0_CLK_CTRL_SRCSEL) | 
                        MASK(FPGA0_CLK_CTRL_DIVISOR0) |
                        MASK(FPGA0_CLK_CTRL_DIVISOR1),
                        VAL(FPGA0_CLK_CTRL_SRCSEL, 0x0) |
                        VAL(FPGA0_CLK_CTRL_DIVISOR0, 0x5) |
                        VAL(FPGA0_CLK_CTRL_DIVISOR1, 0x2)
                        ),
    // use 6:3:2:1 ratio for CPU clocks
    PSI_WRITE_MASKED32( REG(CLK_621_TRUE),
                        MASK(CLK_621_TRUE_CLK_621_TRUE),
                        VAL(CLK_621_TRUE_CLK_621_TRUE, 0x1) ),                        

    PSI_WRITE_MASKED32( REG(APER_CLK_CTRL),
                        MASK(APER_CLK_CTRL_DMA_CPU_2XCLKACT) |
                        MASK(APER_CLK_CTRL_USB0_CPU_1XCLKACT) |
                        MASK(APER_CLK_CTRL_USB1_CPU_1XCLKACT) |
                        MASK(APER_CLK_CTRL_GEM0_CPU_1XCLKACT) |
                        MASK(APER_CLK_CTRL_GEM1_CPU_1XCLKACT) |
                        MASK(APER_CLK_CTRL_SDI0_CPU_1XCLKACT) |
                        MASK(APER_CLK_CTRL_SDI1_CPU_1XCLKACT) |
                        MASK(APER_CLK_CTRL_SPI0_CPU_1XCLKACT) |
                        MASK(APER_CLK_CTRL_SPI1_CPU_1XCLKACT) |
                        MASK(APER_CLK_CTRL_CAN0_CPU_1XCLKACT) |
                        MASK(APER_CLK_CTRL_CAN1_CPU_1XCLKACT) |
                        MASK(APER_CLK_CTRL_I2C0_CPU_1XCLKACT) |
                        MASK(APER_CLK_CTRL_I2C1_CPU_1XCLKACT) |
                        MASK(APER_CLK_CTRL_UART0_CPU_1XCLKACT) |
                        MASK(APER_CLK_CTRL_UART1_CPU_1XCLKACT) |
                        MASK(APER_CLK_CTRL_GPIO_CPU_1XCLKACT) |
                        MASK(APER_CLK_CTRL_LQSPI_CPU_1XCLKACT) |
                        MASK(APER_CLK_CTRL_SMC_CPU_1XCLKACT),
                        VAL(APER_CLK_CTRL_DMA_CPU_2XCLKACT, 0x1) |
                        VAL(APER_CLK_CTRL_USB0_CPU_1XCLKACT, 0x1) |
                        VAL(APER_CLK_CTRL_USB1_CPU_1XCLKACT, 0x1) |
                        VAL(APER_CLK_CTRL_GEM0_CPU_1XCLKACT, 0x1) |
                        VAL(APER_CLK_CTRL_GEM1_CPU_1XCLKACT, 0x0) |
                        VAL(APER_CLK_CTRL_SDI0_CPU_1XCLKACT, 0x1) |
                        VAL(APER_CLK_CTRL_SDI1_CPU_1XCLKACT, 0x0) |
                        VAL(APER_CLK_CTRL_SPI0_CPU_1XCLKACT, 0x0) |
                        VAL(APER_CLK_CTRL_SPI1_CPU_1XCLKACT, 0x0) |
                        VAL(APER_CLK_CTRL_CAN0_CPU_1XCLKACT, 0x0) |
                        VAL(APER_CLK_CTRL_CAN1_CPU_1XCLKACT, 0x0) |
                        VAL(APER_CLK_CTRL_I2C0_CPU_1XCLKACT, 0x1) |
                        VAL(APER_CLK_CTRL_I2C1_CPU_1XCLKACT, 0x1) |
                        VAL(APER_CLK_CTRL_UART0_CPU_1XCLKACT, 0x1) |
                        VAL(APER_CLK_CTRL_UART1_CPU_1XCLKACT, 0x0) |
                        VAL(APER_CLK_CTRL_GPIO_CPU_1XCLKACT, 0x1) |
                        VAL(APER_CLK_CTRL_LQSPI_CPU_1XCLKACT, 0x1) |
                        VAL(APER_CLK_CTRL_SMC_CPU_1XCLKACT, 0x1)
    ),

    PSI_MULTI_WRITE_MASKED32(REG(DDRIOB_DATA0),
                                4,
                                MASK(DDRIOB_DATA0_IBUF_DISABLE_MODE) | MASK(DDRIOB_DATA0_TERM_DISABLE_MODE),
                                VAL(DDRIOB_DATA0_IBUF_DISABLE_MODE, 0x1) | VAL(DDRIOB_DATA0_TERM_DISABLE_MODE, 0x1),
                                VAL(DDRIOB_DATA1_IBUF_DISABLE_MODE, 0x0) | VAL(DDRIOB_DATA1_TERM_DISABLE_MODE, 0x0),
                                VAL(DDRIOB_DIFF0_IBUF_DISABLE_MODE, 0x1) | VAL(DDRIOB_DIFF0_TERM_DISABLE_MODE, 0x1),
                                VAL(DDRIOB_DIFF1_IBUF_DISABLE_MODE, 0x0) | VAL(DDRIOB_DIFF1_TERM_DISABLE_MODE, 0x0)),

    //----
    // FPGA
    //----
    PSI_WRITE_MASKED32(REG(LVL_SHFTR_EN), 0xF, 0xF),
    PSI_WRITE_MASKED32(REG(FPGA_RST_CTRL), 0xFFFFFFFF, 0x0),

    // lock it back up
    PSI_WRITE_32(REG(SLCR_LOCK), 0x767B),

    PSI_END_PROGRAM
};

void slcrRunInitProgram() 
{
    psi_RunProgram(slcr_init, 0);
}
void slcrRunPostDDRInitProgram()
{
    psi_RunProgram(slcr_post_ddr_init, 0);
}

