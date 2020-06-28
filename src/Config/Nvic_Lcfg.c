#include "Nvic.h"




const Nvic_CfgType Nvic_Cfg[NVIC_ACTIVATED_INT_SIZE] ={
/* Interrupt_Number	    Group_Priority          SubGroup_Priority */
 { NVIC_GPIO_Port_B,    2,                       0                  },
 { NVIC_GPIO_Port_C,    3,                       1                  },
 { NVIC_GPIO_Port_D,    0,                       0                  }
	
};
