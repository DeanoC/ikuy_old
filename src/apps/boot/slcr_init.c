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
    PSI_WRITE_MASKED32(  REG(ARM_PLL_CTRL),                         
                        MASK(ARM_PLL_CTRL_PLL_FDIV),                         
                        VAL(ARM_PLL_CTRL_PLL_FDIV, 0x1a) ),
    PSI_WRITE_MASKED32(  REG(ARM_PLL_CTRL),                         
                        MASK(ARM_PLL_CTRL_PLL_BYPASS_FORCE),                         
                        VAL(ARM_PLL_CTRL_PLL_BYPASS_FORCE, 0x1) ),
    ASSERT_RESET(ARM_PLL_CTRL, ARM_PLL_CTRL_PLL_RESET),

    // poll and remove the bypass when ready
    POLL(PLL_STATUS, PLL_STATUS_ARM_PLL_LOCK),
    PSI_WRITE_MASKED32(  REG(ARM_PLL_CTRL),                         
                        MASK(ARM_PLL_CTRL_PLL_BYPASS_FORCE),                         
                        VAL(ARM_PLL_CTRL_PLL_BYPASS_FORCE, 0x0) ),
    // ARM clocks
    PSI_WRITE_MASKED32(  REG(ARM_CLK_CTRL),                         
                        MASK(ARM_CLK_CTRL_SRCSEL) |
                        MASK(ARM_CLK_CTRL_DIVISOR) |
                        MASK(ARM_CLK_CTRL_CPU_6OR4XCLKACT) |
                        MASK(ARM_CLK_CTRL_CPU_3OR2XCLKACT) |
                        MASK(ARM_CLK_CTRL_CPU_2XCLKACT) |
                        MASK(ARM_CLK_CTRL_CPU_1XCLKACT) |                         
                        MASK(ARM_CLK_CTRL_CPU_PERI_CLKACT),

                        VAL(ARM_CLK_CTRL_SRCSEL, 0x0) |
                        VAL(ARM_CLK_CTRL_DIVISOR, 0x2) |
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
    PSI_WRITE_MASKED32(  REG(DDR_CLK_CTRL),                         
                        MASK(DDR_CLK_CTRL_DDR_3XCLKACT) |
                        MASK(DDR_CLK_CTRL_DDR_2XCLKACT) |
                        MASK(DDR_CLK_CTRL_DDR_3XCLK_DIVISOR) |
                        MASK(DDR_CLK_CTRL_DDR_2XCLK_DIVISOR),

                        VAL(DDR_CLK_CTRL_DDR_3XCLKACT, 0x1) |
                        VAL(DDR_CLK_CTRL_DDR_2XCLKACT, 0x1) |
                        VAL(DDR_CLK_CTRL_DDR_3XCLK_DIVISOR, 0x2) |
                        VAL(DDR_CLK_CTRL_DDR_2XCLK_DIVISOR, 0x3) ),
    // FINISH DDR PLL INIT

    // START IO PLL INIT
    PSI_WRITE_MASKED32( REG(IO_PLL_CFG),
                        MASK(IO_PLL_CFG_PLL_RES) |
                        MASK(IO_PLL_CFG_PLL_CP) |
                        MASK(IO_PLL_CFG_LOCK_CNT),
                        VAL(IO_PLL_CFG_PLL_RES, 0xC) |
                        VAL(IO_PLL_CFG_PLL_CP, 0x2) |
                        VAL(IO_PLL_CFG_LOCK_CNT, 0x1F4) ),

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
    //---- 
    // CLOCK
    //---- 
    PSI_WRITE_MASKED32( REG(DCI_CLK_CTRL),
                        MASK(DCI_CLK_CTRL_CLKACT) |
                        MASK(DCI_CLK_CTRL_DIVISOR0) |
                        MASK(DCI_CLK_CTRL_DIVISOR1),
                        VAL(DCI_CLK_CTRL_CLKACT, 0x1) |
                        VAL(DCI_CLK_CTRL_DIVISOR0, 0x34) |
                        VAL(DCI_CLK_CTRL_DIVISOR1, 0x2) ),

    PSI_WRITE_MASKED32( REG(GEM0_RCLK_CTRL),
                        MASK(GEM0_RCLK_CTRL_CLKACT) |
                        MASK(GEM0_RCLK_CTRL_SRCSEL),
                        VAL(GEM0_RCLK_CTRL_CLKACT, 0x1) |
                        VAL(GEM0_RCLK_CTRL_SRCSEL, 0x0)),

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

    PSI_WRITE_MASKED32( REG(LQSPI_CLK_CTRL),
                        MASK(LQSPI_CLK_CTRL_CLKACT) |
                        MASK(LQSPI_CLK_CTRL_SRCSEL) | 
                        MASK(LQSPI_CLK_CTRL_DIVISOR),
                        VAL(LQSPI_CLK_CTRL_CLKACT, 0x1) |
                        VAL(LQSPI_CLK_CTRL_SRCSEL, 0x0) |
                        VAL(LQSPI_CLK_CTRL_DIVISOR, 0x5)
                        ),

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

    PSI_WRITE_MASKED32( REG(PCAP_CLK_CTRL),
                        MASK(PCAP_CLK_CTRL_CLKACT) |
                        MASK(PCAP_CLK_CTRL_SRCSEL) |
                        MASK(PCAP_CLK_CTRL_DIVISOR),
                        VAL(PCAP_CLK_CTRL_CLKACT, 0x1) |
                        VAL(PCAP_CLK_CTRL_SRCSEL, 0x0) |
                        VAL(PCAP_CLK_CTRL_DIVISOR, 0x5)),

    PSI_WRITE_MASKED32( REG(FPGA0_CLK_CTRL),
                        MASK(FPGA0_CLK_CTRL_SRCSEL) | 
                        MASK(FPGA0_CLK_CTRL_DIVISOR0) |
                        MASK(FPGA0_CLK_CTRL_DIVISOR1),
                        VAL(FPGA0_CLK_CTRL_SRCSEL, 0x0) |
                        VAL(FPGA0_CLK_CTRL_DIVISOR0, 0x5) |
                        VAL(FPGA0_CLK_CTRL_DIVISOR1, 0x2)
                        ),

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
    PSI_MULTI_WRITE_MASKED32(REG(DDRIOB_DATA0),
                                4,
                                MASK(DDRIOB_DATA0_IBUF_DISABLE_MODE) | MASK(DDRIOB_DATA0_TERM_DISABLE_MODE),
                                VAL(DDRIOB_DATA0_IBUF_DISABLE_MODE, 0x1) | VAL(DDRIOB_DATA0_TERM_DISABLE_MODE, 0x1),
                                VAL(DDRIOB_DATA1_IBUF_DISABLE_MODE, 0x0) | VAL(DDRIOB_DATA1_TERM_DISABLE_MODE, 0x0),
                                VAL(DDRIOB_DIFF0_IBUF_DISABLE_MODE, 0x1) | VAL(DDRIOB_DIFF0_TERM_DISABLE_MODE, 0x1),
                                VAL(DDRIOB_DIFF1_IBUF_DISABLE_MODE, 0x0) | VAL(DDRIOB_DIFF1_TERM_DISABLE_MODE, 0x0)),

    // lock it back up
    PSI_WRITE_32(REG(SLCR_LOCK), 0x767B),

    PSI_END_PROGRAM
};

#if DEBUG_WRITES == 1
static void GeneratePs7initComparator(uint32_t * array)
{
#define EMIT_WRITE(addr, val) array[(addr & 0x0FFF)/4] = val
#define EMIT_MASKWRITE(addr, mask, val) array[(addr & 0x0FFF)/4] = (val & mask) | (array[(addr & 0x0FFF)/4] & (~mask))
#define EMIT_MASKPOLL(addr, mask)

    // MIO v3 silicon
    EMIT_WRITE(0XF8000008, 0x0000DF0DU);
    EMIT_MASKWRITE(0XF8000B40, 0x00000FFFU ,0x00000600U);
    EMIT_MASKWRITE(0XF8000B44, 0x00000FFFU ,0x00000600U);
    EMIT_MASKWRITE(0XF8000B48, 0x00000FFFU ,0x00000672U);
    EMIT_MASKWRITE(0XF8000B4C, 0x00000FFFU ,0x00000800U);
    EMIT_MASKWRITE(0XF8000B50, 0x00000FFFU ,0x00000674U);
    EMIT_MASKWRITE(0XF8000B54, 0x00000FFFU ,0x00000800U);
    EMIT_MASKWRITE(0XF8000B58, 0x00000FFFU ,0x00000600U);
    EMIT_MASKWRITE(0XF8000B5C, 0xFFFFFFFFU ,0x0018C61CU);
    EMIT_MASKWRITE(0XF8000B60, 0xFFFFFFFFU ,0x00F9861CU);
    EMIT_MASKWRITE(0XF8000B64, 0xFFFFFFFFU ,0x00F9861CU);
    EMIT_MASKWRITE(0XF8000B68, 0xFFFFFFFFU ,0x00F9861CU);
    EMIT_MASKWRITE(0XF8000B6C, 0x00007FFFU ,0x00000220U);
    EMIT_MASKWRITE(0XF8000B70, 0x00000001U ,0x00000001U);
    EMIT_MASKWRITE(0XF8000B70, 0x00000021U ,0x00000020U);
    EMIT_MASKWRITE(0XF8000B70, 0x07FEFFFFU ,0x00000823U);
    EMIT_MASKWRITE(0XF8000700, 0x00003FFFU ,0x00001600U);
    EMIT_MASKWRITE(0XF8000704, 0x00003FFFU ,0x00001602U);
    EMIT_MASKWRITE(0XF8000708, 0x00003FFFU ,0x00000602U);
    EMIT_MASKWRITE(0XF800070C, 0x00003FFFU ,0x00000602U);
    EMIT_MASKWRITE(0XF8000710, 0x00003FFFU ,0x00000602U);
    EMIT_MASKWRITE(0XF8000714, 0x00003FFFU ,0x00000602U);
    EMIT_MASKWRITE(0XF8000718, 0x00003FFFU ,0x00000602U);
    EMIT_MASKWRITE(0XF800071C, 0x00003FFFU ,0x00000600U);
    EMIT_MASKWRITE(0XF8000720, 0x00003FFFU ,0x00000602U);
    EMIT_MASKWRITE(0XF8000724, 0x00003FFFU ,0x00001600U);
    EMIT_MASKWRITE(0XF8000728, 0x00003FFFU ,0x00001600U);
    EMIT_MASKWRITE(0XF800072C, 0x00003FFFU ,0x00001600U);
    EMIT_MASKWRITE(0XF8000730, 0x00003FFFU ,0x00001600U);
    EMIT_MASKWRITE(0XF8000734, 0x00003FFFU ,0x00001600U);
    EMIT_MASKWRITE(0XF8000738, 0x00003FFFU ,0x000016E1U);
    EMIT_MASKWRITE(0XF800073C, 0x00003FFFU ,0x000016E0U);
    EMIT_MASKWRITE(0XF8000740, 0x00003FFFU ,0x00001202U);
    EMIT_MASKWRITE(0XF8000744, 0x00003FFFU ,0x00001202U);
    EMIT_MASKWRITE(0XF8000748, 0x00003FFFU ,0x00001202U);
    EMIT_MASKWRITE(0XF800074C, 0x00003FFFU ,0x00001202U);
    EMIT_MASKWRITE(0XF8000750, 0x00003FFFU ,0x00001202U);
    EMIT_MASKWRITE(0XF8000754, 0x00003FFFU ,0x00001202U);
    EMIT_MASKWRITE(0XF8000758, 0x00003FFFU ,0x00001203U);
    EMIT_MASKWRITE(0XF800075C, 0x00003FFFU ,0x00001203U);
    EMIT_MASKWRITE(0XF8000760, 0x00003FFFU ,0x00001203U);
    EMIT_MASKWRITE(0XF8000764, 0x00003FFFU ,0x00001203U);
    EMIT_MASKWRITE(0XF8000768, 0x00003FFFU ,0x00001203U);
    EMIT_MASKWRITE(0XF800076C, 0x00003FFFU ,0x00001203U);
    EMIT_MASKWRITE(0XF8000770, 0x00003FFFU ,0x00001204U);
    EMIT_MASKWRITE(0XF8000774, 0x00003FFFU ,0x00001205U);
    EMIT_MASKWRITE(0XF8000778, 0x00003FFFU ,0x00001204U);
    EMIT_MASKWRITE(0XF800077C, 0x00003FFFU ,0x00001205U);
    EMIT_MASKWRITE(0XF8000780, 0x00003FFFU ,0x00001204U);
    EMIT_MASKWRITE(0XF8000784, 0x00003FFFU ,0x00001204U);
    EMIT_MASKWRITE(0XF8000788, 0x00003FFFU ,0x00001204U);
    EMIT_MASKWRITE(0XF800078C, 0x00003FFFU ,0x00001204U);
    EMIT_MASKWRITE(0XF8000790, 0x00003FFFU ,0x00001205U);
    EMIT_MASKWRITE(0XF8000794, 0x00003FFFU ,0x00001204U);
    EMIT_MASKWRITE(0XF8000798, 0x00003FFFU ,0x00001204U);
    EMIT_MASKWRITE(0XF800079C, 0x00003FFFU ,0x00001204U);
    EMIT_MASKWRITE(0XF80007A0, 0x00003FFFU ,0x00001280U);
    EMIT_MASKWRITE(0XF80007A4, 0x00003FFFU ,0x00001280U);
    EMIT_MASKWRITE(0XF80007A8, 0x00003FFFU ,0x00001280U);
    EMIT_MASKWRITE(0XF80007AC, 0x00003FFFU ,0x00001280U);
    EMIT_MASKWRITE(0XF80007B0, 0x00003FFFU ,0x00001280U);
    EMIT_MASKWRITE(0XF80007B4, 0x00003FFFU ,0x00001280U);
    EMIT_MASKWRITE(0XF80007B8, 0x00003FFFU ,0x00001200U);
    EMIT_MASKWRITE(0XF80007BC, 0x00003F01U ,0x00001201U);
    EMIT_MASKWRITE(0XF80007C0, 0x00003FFFU ,0x00001200U);
    EMIT_MASKWRITE(0XF80007C4, 0x00003FFFU ,0x00001200U);
    EMIT_MASKWRITE(0XF80007C8, 0x00003FFFU ,0x00001200U);
    EMIT_MASKWRITE(0XF80007CC, 0x00003FFFU ,0x00001200U);
    EMIT_MASKWRITE(0XF80007D0, 0x00003FFFU ,0x00001280U);
    EMIT_MASKWRITE(0XF80007D4, 0x00003FFFU ,0x00001280U);
    EMIT_MASKWRITE(0XF8000830, 0x003F003FU ,0x002F0037U);
    EMIT_WRITE(0XF8000004, 0x0000767BU);

    // PLL v3 silicon
    EMIT_WRITE(0XF8000008, 0x0000DF0DU);
    EMIT_MASKWRITE(0XF8000110, 0x003FFFF0U ,0x001772C0U);
    EMIT_MASKWRITE(0XF8000100, 0x0007F000U ,0x0001A000U);
    EMIT_MASKWRITE(0XF8000100, 0x00000010U ,0x00000010U);
    EMIT_MASKWRITE(0XF8000100, 0x00000001U ,0x00000001U);
    EMIT_MASKWRITE(0XF8000100, 0x00000001U ,0x00000000U);
    EMIT_MASKPOLL(0XF800010C, 0x00000001U);
    EMIT_MASKWRITE(0XF8000100, 0x00000010U ,0x00000000U);
    EMIT_MASKWRITE(0XF8000120, 0x1F003F30U ,0x1F000200U);
    EMIT_MASKWRITE(0XF8000114, 0x003FFFF0U ,0x001DB2C0U);
    EMIT_MASKWRITE(0XF8000104, 0x0007F000U ,0x00015000U);
    EMIT_MASKWRITE(0XF8000104, 0x00000010U ,0x00000010U);
    EMIT_MASKWRITE(0XF8000104, 0x00000001U ,0x00000001U);
    EMIT_MASKWRITE(0XF8000104, 0x00000001U ,0x00000000U);
    EMIT_MASKPOLL(0XF800010C, 0x00000002U);
    EMIT_MASKWRITE(0XF8000104, 0x00000010U ,0x00000000U);
    EMIT_MASKWRITE(0XF8000124, 0xFFF00003U ,0x0C200003U);
    EMIT_MASKWRITE(0XF8000118, 0x003FFFF0U ,0x001F42C0U);
    EMIT_MASKWRITE(0XF8000108, 0x0007F000U ,0x00014000U);
    EMIT_MASKWRITE(0XF8000108, 0x00000010U ,0x00000010U);
    EMIT_MASKWRITE(0XF8000108, 0x00000001U ,0x00000001U);
    EMIT_MASKWRITE(0XF8000108, 0x00000001U ,0x00000000U);
    EMIT_MASKPOLL(0XF800010C, 0x00000004U);
    EMIT_MASKWRITE(0XF8000108, 0x00000010U ,0x00000000U);
    EMIT_WRITE(0XF8000004, 0x0000767BU);

    // CLOCK v 3 silicon
    EMIT_WRITE(0XF8000008, 0x0000DF0DU);
    EMIT_MASKWRITE(0XF8000128, 0x03F03F01U ,0x00203401U);
    EMIT_MASKWRITE(0XF8000138, 0x00000011U ,0x00000001U);
    EMIT_MASKWRITE(0XF8000140, 0x03F03F71U ,0x00100801U);
    EMIT_MASKWRITE(0XF800014C, 0x00003F31U ,0x00000501U);
    EMIT_MASKWRITE(0XF8000150, 0x00003F33U ,0x00001401U);
    EMIT_MASKWRITE(0XF8000154, 0x00003F33U ,0x00000A01U);
    EMIT_MASKWRITE(0XF8000168, 0x00003F31U ,0x00000501U);
    EMIT_MASKWRITE(0XF8000170, 0x03F03F30U ,0x00200500U);
    EMIT_MASKWRITE(0XF80001C4, 0x00000001U ,0x00000001U);
    EMIT_MASKWRITE(0XF800012C, 0x01FFCCCDU ,0x01DC044DU);
    EMIT_WRITE(0XF8000004, 0x0000767BU);

    // peripherals
    // most of peripherals is in its on module
    // this is just the slcr parts
//    EMIT_WRITE(0XF8000008, 0x0000DF0DU);
//    EMIT_MASKWRITE(0XF8000B48, 0x00000180U ,0x00000180U);
//    EMIT_MASKWRITE(0XF8000B4C, 0x00000180U ,0x00000000U);
//    EMIT_MASKWRITE(0XF8000B50, 0x00000180U ,0x00000180U);
//    EMIT_MASKWRITE(0XF8000B54, 0x00000180U ,0x00000000U);
//    EMIT_WRITE(0XF8000004, 0x0000767BU);
}

void sclrRunInitProgram() 
{
    uint32_t array[ 0xFFFF ] = {0};
    GeneratePs7initComparator(array);
    psi_RunProgram(slcr_init, array);
}
#else
void slcrRunInitProgram() 
{
    psi_RunProgram(slcr_init, 0);
}
void slcrRunPostDDRInitProgram()
{
    psi_RunProgram(slcr_post_ddr_init, 0);
}
#endif

