#include "hw/arma9.h"
#include "hw/arma9_cop.h"
#include "hw/l1cache.h"

void l1cache_data_flush_all(void)
{
	uint32_t const currmask = arma9_get_CPSR();

	// don't flush if cache is disabled currently
	if ((arma9_cop_get_SCTLR() & arma9_cop_SCTLR_DCACHE) == 0)
	{
		return;
    }

	// disable interrupts (FIQ still available)
	arma9_set_CPSR(currmask | arma9_CPSR_IRQ_MASKED);

	// Select cache level
	arma9_cop_set_CSSELR(arma9_cop_CSSELR_L1 | arma9_cop_CSSELR_DATA);

	// work our attributes of dcache
	uint32_t const csidReg = arma9_cop_get_CCSIDR();
	uint32_t const cacheSize = (((csidReg >> 13U) & 0x1FFU) + 1U) * 128U;
	uint32_t const numWays = ((csidReg & 0x3ffU) >> 3U)+1U;
	uint32_t const lineSize = (csidReg & 0x07U) + 4U;
	uint32_t const numSet = (cacheSize/numWays) / (0x00000001U << lineSize);

	uint32_t way = 0U;
	uint32_t set = 0U;
	// Invalidate all the cachelines
	for (uint32_t wayIndex = 0U; wayIndex < numWays; wayIndex++)
	{
		for (uint32_t setIndex = 0U; setIndex < numSet; setIndex++)
		{
			// Clean (AKA flush) by Set/Way
			arma9_cop_set_DCCSW(way | set);
			set += (0x00000001U << lineSize);
		}
		set = 0U;
		way += 0x40000000U;
	}

	// Wait for L1 flush to complete
	arma9_dsb();
	// restore interrupts
	arma9_set_CPSR(currmask);
}

void l1cache_data_invalidate_all(void)
{
	uint32_t const currmask = arma9_get_CPSR();

	// disable interrupts (FIQ still available)
	arma9_set_CPSR(currmask | arma9_CPSR_IRQ_MASKED);

	// Select cache level
	arma9_cop_set_CSSELR(arma9_cop_CSSELR_L1 | arma9_cop_CSSELR_DATA);

	// work our attributes of dcache
	uint32_t const csidReg = arma9_cop_get_CCSIDR();
	uint32_t const cacheSize = (((csidReg >> 13U) & 0x1FFU) + 1U) * 128U;
	uint32_t const numWays = ((csidReg & 0x3ffU) >> 3U)+1U;
	uint32_t const lineSize = (csidReg & 0x07U) + 4U;
	uint32_t const numSet = (cacheSize/numWays) / (0x00000001U << lineSize);

	uint32_t way = 0U;
	uint32_t set = 0U;
	// Invalidate all the cachelines
	for (uint32_t wayIndex = 0U; wayIndex < numWays; wayIndex++)
	{
		for (uint32_t setIndex = 0U; setIndex < numSet; setIndex++)
		{
			// Invalidate by Set/Way
			arma9_cop_set_DCISW(way | set);
			set += (0x00000001U << lineSize);
		}
		set = 0U;
		way += 0x40000000U;
	}

	// Wait for L1 invalidate to complete
	arma9_dsb();
	// restore interrupts
	arma9_set_CPSR(currmask);
}

void l1cache_instruction_invalidate_all(void)
{
	arma9_cop_set_CSSELR(arma9_cop_CSSELR_L1 | arma9_cop_CSSELR_INSTRUCTION);
	arma9_cop_set_ICIALLU();
	arma9_dsb();
}

void l1cache_branch_predictor_invalidate_all(void)
{
	arma9_cop_set_BPIALL();
	arma9_dsb();
}

void l1cache_data_enable(bool enable)
{
	uint32_t sysCtrl = arma9_cop_get_SCTLR();

	// already in the state we are requesting?
	if ( (sysCtrl & arma9_cop_SCTLR_DCACHE) && enable)
	{
		return;
	} else if ( !(sysCtrl & arma9_cop_SCTLR_DCACHE) && !enable)
	{
		return;
	}

	// invalidate it to ensure no stale entries
	l1cache_data_invalidate_all();

	if (enable)
	{
		sysCtrl = sysCtrl | arma9_cop_SCTLR_DCACHE;
	}
	else
	{
		sysCtrl = sysCtrl & ~arma9_cop_SCTLR_DCACHE;
	}

	// enable or disable the icache
	arma9_cop_set_SCTLR(sysCtrl);
	arma9_dsb();
}

void l1cache_instruction_enable(bool enable)
{
	uint32_t sysCtrl = arma9_cop_get_SCTLR();

	// already in the state we are requesting?
	if(((sysCtrl & arma9_cop_SCTLR_ICACHE) != 0) == enable)
	{
		return;
	}

	// invalidate it to ensure no stale entries
	l1cache_instruction_invalidate_all();

	if(enable)
	{
		sysCtrl = sysCtrl | arma9_cop_SCTLR_ICACHE;
	} else
	{
		sysCtrl = sysCtrl & ~arma9_cop_SCTLR_ICACHE;
	}

	// enable or disable the icache
	arma9_cop_set_SCTLR(sysCtrl);
	arma9_dsb();
	arma9_isb();
}
void l1cache_data_flush_line(void* addr)
{
	arma9_cop_set_CSSELR(arma9_cop_CSSELR_L1 | arma9_cop_CSSELR_DATA);
	arma9_cop_set_DCCMVAC(((uintptr_t)addr) & L1CACHE_LINE_ADDR_MASK);
	arma9_dsb();
}

void l1cache_data_flush_range(void* addr, uint32_t byteCount)
{
	arma9_cop_set_CSSELR(arma9_cop_CSSELR_L1 | arma9_cop_CSSELR_DATA);
	for(uint32_t i = (uintptr_t)addr; i < (((uintptr_t)addr) + byteCount); i+= L1CACHE_LINE_SIZE)
	{
		arma9_cop_set_DCCMVAC(i & L1CACHE_LINE_ADDR_MASK);
	}
	arma9_dsb();
}
