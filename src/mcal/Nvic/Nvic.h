#ifndef NVIC_H
#define NVIC_H

typedef enum
{
	NVIC_GPIO_Port_A,
	NVIC_GPIO_Port_B,
	NVIC_GPIO_Port_C,
	NVIC_GPIO_Port_D,
	NVIC_GPIO_Port_E,
	
	NVIC_System_Control = 28,
	
}NVIC_IntType;

typedef struct
{
	NVIC_IntType Interrupt_Number;
	uint8        Group_Priority;
	uint8        SubGroup_Priority
	
	
}NVIC_CfgType;


void NVIC_init(void);




#endif