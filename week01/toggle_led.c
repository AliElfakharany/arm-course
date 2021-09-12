#include "stm32f4xx_hal.h"

#include <stdint.h>

void delay(void);

int main(void)
{
	 GPIO_InitTypeDef GPIO_InitStruct;
  /* GPIO Ports Clock Enable */
  __GPIOG_CLK_ENABLE();
  /* Configure GPIO pins: PG13 PG14 */
  GPIO_InitStruct.Pin   = GPIO_PIN_13 | GPIO_PIN_14;
  GPIO_InitStruct.Mode  = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull  = GPIO_PULLDOWN;
  GPIO_InitStruct.Speed = GPIO_SPEED_LOW;
  HAL_GPIO_Init(GPIOG, &GPIO_InitStruct);
	
	while(1)
	{
		HAL_GPIO_TogglePin(GPIOG, GPIO_PIN_13);
		HAL_GPIO_TogglePin(GPIOG, GPIO_PIN_14);
		delay();
	}
	return 0;
}

void delay(void)
{
	volatile uint32_t i =0;
	for(i=0; i<500000; i++);
}
