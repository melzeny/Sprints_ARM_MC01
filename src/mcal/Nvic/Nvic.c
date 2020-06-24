#include "Nvic.h"
#include "mcu_hw.h"

#define NVCI_GROUPING_SYSTEM_XXX    4
#define NVCI_GROUPING_SYSTEM_XXY    5
#define NVCI_GROUPING_SYSTEM_XYY    6
#define NVCI_GROUPING_SYSTEM_YYY    7


void NVIC_init(void)
{
	NVIC_IntType IntNum;
	uint8 LocGroup,LocSubGroup;
	/*TODO COnfigure Grouping\SubGrouping System in APINT register in SCB*/
	
	
	for(i=0;i< NVIC_ACTIVATED_INT_SIZE;i++)
	{
		IntNum = NVIC_Cfg[i].Interrupt_Number;
		LocGroup = NVIC_Cfg[i].Group_Priority;
		LocSubGroup = NVIC_Cfg[i].SubGroup_Priority;
		
		/*TODO : Enable\Disable based on user configurations in ENx Nvic Registers */
	
		            /*which NVIC_ENx Register*/
		
		
		            /*which Bit in this Register*/
		
		
		/*TODO : Assign Group\Subgroup priority in PRIx Nvic Registers*/
	
	
	
		
	}

	
}