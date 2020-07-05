#include "Mcu.h"
extern const Mcu_ConfigType McuConfig[];
void McuUser(void)
{
	Mcu_Init(McuConfig);
	Mcu_InitClock(0);
	while(Mcu_GetPllStatus() == MCU_PLL_UNLOCKED);
	Mcu_DistributePllClock();
	
	while(1)
	{
	
	}
	
}
