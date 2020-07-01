/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  FileName.c
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
#include "Port.h"
#include "mcu_hw.h"

/**********************************************************************************************************************
*  LOCAL MACROS CONSTANT\FUNCTION
*********************************************************************************************************************/
#define CHANNEL_SIZE_IN_PORT               8u
#define MAX_NUMBER_OF_GPIO_PORTS           6u
/**********************************************************************************************************************
 *  LOCAL DATA 
 *********************************************************************************************************************/
static const uint32 Port_BaseAddr[MAX_NUMBER_OF_GPIO_PORTS] = {GPIO_APB_BASE_ADDRESS_A,
	                                                      GPIO_APB_BASE_ADDRESS_B,
	                                                      GPIO_APB_BASE_ADDRESS_C,
	                                                      GPIO_APB_BASE_ADDRESS_D,
	                                                      GPIO_APB_BASE_ADDRESS_E,
	                                                      GPIO_APB_BASE_ADDRESS_F};
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
* \Syntax          : void Port_Init ( const Port_ConfigType* ConfigPtr )        
* \Description     : Initializes the Port Driver module.                                   
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : ConfigPtr       Pointer to configuration set.                     
* \Parameters (out): None                                                      
* \Return value:   : None  
*                                                                      
*******************************************************************************/
void Port_Init ( const Port_ConfigType* ConfigPtr )
{
	Port_PinType                locPinId;
	Port_PinDirectionType       locPinDir;
	Port_PinModeType            locPinMode;
	Port_PinOutputCurrentType   locCurrentStrength;
	Port_PinInternalAttachType  locInternalAttach;
	Port_PinExternalIntType     locExternalInt;
	uint8 PortIndex,PinIndex,i;
	uint32 PortBaseAddr;
	
	for(i=0;i<PORT_ACTIVATED_CHANNELS_SIZE;i++)
	{
		locPinId             = ConfigPtr[i].pinId;
		locPinDir            = ConfigPtr[i].pinDir;
		locPinMode           = ConfigPtr[i].pinMode;
		locCurrentStrength   = ConfigPtr[i].currentStrength;
		locInternalAttach    = ConfigPtr[i].internalAttach;
		locExternalInt       = ConfigPtr[i].externalInt;
		
		PortIndex    = locPinId / CHANNEL_SIZE_IN_PORT ;
		PinIndex     = locPinId % CHANNEL_SIZE_IN_PORT ;
        PortBaseAddr = Port_BaseAddr[PortIndex] ;
		
		GPIODIR(PortBaseAddr) |= (locPinDir<< PinIndex) ; 
		
		
		
		
	}
	
	
}

/**********************************************************************************************************************
 *  END OF FILE: FileName.c
 *********************************************************************************************************************/
