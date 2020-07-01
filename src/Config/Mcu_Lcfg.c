#include "Std_Types.h"
#include "Mcu.h"

/* Configuartion file */
#define MCU_CLOCK_GATE_GPIOA     00u
#define MCU_CLOCK_GATE_GPIOB     01u
#define MCU_CLOCK_GATE_GPIOE     04u
#define MCU_CLOCK_GATE_UART0     30u
#define MCU_CLOCK_GATE_SSI2      42u

uint8 Mcu_ActivatedClockGates[MCU_ACTIVATED_CLOCK_GATES_SIZE]=
{
	MCU_CLOCK_GATE_GPIOA,
	MCU_CLOCK_GATE_GPIOB,
	MCU_CLOCK_GATE_GPIOE,
	MCU_CLOCK_GATE_UART0,
	MCU_CLOCK_GATE_SSI2
};
