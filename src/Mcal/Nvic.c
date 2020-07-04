/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  Nvic.c
 *        \brief  Nested Vector Interrupt Controller Driver
 *
 *      \details  The Driver Configure All MCU interrupts Priority into gorups and subgroups
 *                Enable and Disable Navic Interrupt Gate for Peripherals
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"
#include "Nvic.h"
#include "Mcu_Hw.h"

/**********************************************************************************************************************
*  LOCAL MACROS CONSTANT\FUNCTION
*********************************************************************************************************************/
#define NVIC_GROUPING_SYSTEM_XXX    4
#define NVIC_GROUPING_SYSTEM_XXY    5
#define NVIC_GROUPING_SYSTEM_XYY    6
#define NVIC_GROUPING_SYSTEM_YYY    7

#define APINT_VECTKEY                0x05FA
#define PRIGROUP_FIELD_OFFSET        0x8u
#define APINT_VECTKEY_FIELD_OFFSET   16u
#define NVIC_REG_NUM_OF_PRI_FIELDS   4u
	

/**********************************************************************************************************************
 *  LOCAL DATA 
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/


/******************************************************************************
* \Syntax          : void Nvic_Init(void)                                      
* \Description     : initialize Nvic Module by parsing the Configuration 
*                    into Nvic registers                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : None                     
* \Parameters (out): None                                                      
* \Return value:   : None
*******************************************************************************/
void Nvic_Init(void)
{
	Nvic_IntType intNum;
	uint8 locGroup,locSubGroup,i,locGroupingField;
	uint32 enRegOffset,enBitOffset,priRegOffset,priBitOffset;
	/*TODO COnfigure Grouping\SubGrouping System in APINT register in SCB*/
	
	APINT = (APINT_VECTKEY<<APINT_VECTKEY_FIELD_OFFSET) |
	        (NVIC_GROUPING_SYSTEM<<PRIGROUP_FIELD_OFFSET);
	
	for(i=0;i< NVIC_ACTIVATED_INT_SIZE;i++)
	{
		intNum = Nvic_Cfg[i].interruptNumber;
		locGroup = Nvic_Cfg[i].groupPriority;
		locSubGroup = Nvic_Cfg[i].subgroupPriority;
		
		/*TODO : Enable\Disable based on user configurations in ENx Nvic Registers */
	
        /*NVIC_ENx Register*/
        enRegOffset = (intNum/WORD_LENGTH_BITS)*WORD_LENGTH_BYTES;
		enBitOffset = intNum%WORD_LENGTH_BITS;
		GET_HWREG(NVIC_ENABLE_BASE_ADDRESS,enRegOffset) |= (1<<enBitOffset);
		
		/* Create Grouping Field */
#if (NVIC_GROUPING_SYSTEM == NVIC_GROUPING_SYSTEM_XXX)
	    locGroupingField = locGroup;
#elif (NVIC_GROUPING_SYSTEM == NVIC_GROUPING_SYSTEM_XXY) 
        locGroupingField = ((locGroup<<1)&0x6) | (locSubGroup&0x1);
#elif (NVIC_GROUPING_SYSTEM == NVIC_GROUPING_SYSTEM_XYY) 
        locGroupingField = ((locGroup<<2)&0x4) | (locSubGroup&0x3);
#elif (NVIC_GROUPING_SYSTEM == NVIC_GROUPING_SYSTEM_YYY) 
        locGroupingField = locSubGroup;
#else
     #error INVALID GROUPING SELECTION
#endif 	/*NVIC_GROUPING_SYSTEM*/
		
		/*TODO : Assign Group\Subgroup priority in PRIx Nvic Registers*/
		
	    priRegOffset = (intNum / NVIC_REG_NUM_OF_PRI_FIELDS)*WORD_LENGTH_BYTES;
		priBitOffset = 5+((intNum % NVIC_REG_NUM_OF_PRI_FIELDS) *8 );
	    GET_HWREG(NVIC_PRI_BASE_ADDRESS,priRegOffset) |= (locGroupingField << priBitOffset);
	
		
	}	
}

/**********************************************************************************************************************
 *  END OF FILE: Nvic.c
 *********************************************************************************************************************/
