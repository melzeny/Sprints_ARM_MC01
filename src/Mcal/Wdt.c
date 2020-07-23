/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  Wdt.c
 *        \brief  
 *
 *      \details  
 *
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"

/**********************************************************************************************************************
*  LOCAL MACROS CONSTANT\FUNCTION
*********************************************************************************************************************/

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
* \Syntax          : void Wdg_Init ( const Wdg_ConfigType* ConfigPtr )        
* \Description     : Describe this service                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : parameterName   Parameter Describtion                     
* \Parameters (out): None                                                      
* \Return value:   : void  
*******************************************************************************/
void Wdg_Init ( const Wdg_ConfigType* ConfigPtr )
{
	/* TODO 1. Load the WDTLOAD register with the WdgInitialTimeout in configuration struct  */
	
	/* TODO 2 wait for the WRC bit in the WDTCTL register to be set. */
	
	/* TODO 3. set the RESEN bit in the WDTCTL register. */
	
	/* TODO 4. If WDT1, wait for the WRC bit in the WDTCTL register to be set. */
	
	
	/* TODO 5. Set the INTEN bit in the WDTCTL register to enable the Watchdog  enable interrupts

    /* TODO 6 lock  TODO the control register. */
	
	
	
	
}

/******************************************************************************
* \Syntax          : void Wdg_SetTriggerCondition ( uint16 timeout )        
* \Description     : Describe this service                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) :                        
* \Parameters (out): None                                                      
* \Return value:   : void  
*******************************************************************************/
void Wdg_SetTriggerCondition ( uint16 timeout )
{
	/*The timeout value passed shall be interpreted as 'milliseconds'.
	The conversion from milliseconds to the corresponding counter value shall be done internally by the Wdg module*/
	
	/* In case the counter value stored inside watchdog has the value "0", 
	the service Wdg_SetTriggerCondition shall do nothing,
	which means it shall ignore the counter passed by the parameter*/
	
	
	/*TODO check if timeout < WdgMaxTimeout */
	if(timeout > WdgMaxTimeout)
	{
		/*Report to Det*/
	}
	
	/* TODO  Load the WDTLOAD register with the timeout value */
	
	
	
}

/**********************************************************************************************************************
 *  END OF FILE: FileName.c
 *********************************************************************************************************************/
