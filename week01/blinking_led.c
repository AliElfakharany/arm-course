#include "stm32f4xx_hal.h"
#include "Board_LED.h"
#include <stdint.h>

void delay(void);

int main(void)
{
	LED_Initialize();
	while(1)
	{
		LED_On(0);
		LED_On(1);
		delay();
		LED_Off(0);
		LED_Off(1);
		delay();
	}
	return 0;
}

void delay(void)
{
	volatile uint32_t i =0;
	for(i=0; i<500000; i++);
}
