#include "stm32f4xx_hal.h"
#include <stdint.h>

void delay(void);

int main(void)
{
	  /* GPIO Ports Clock Enable */
  __GPIOG_CLK_ENABLE();
  __GPIOA_CLK_ENABLE();
	
  /* Configure GPIO pins: PG13 PG14 */
	GPIO_InitTypeDef GPIO_InitStruct;
  GPIO_InitStruct.Pin   = GPIO_PIN_13 | GPIO_PIN_14;
  GPIO_InitStruct.Mode  = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull  = GPIO_PULLDOWN;
  GPIO_InitStruct.Speed = GPIO_SPEED_LOW;
  HAL_GPIO_Init(GPIOG, &GPIO_InitStruct);
	
  /* Configure GPIO pin: PA0 (USER) */
	GPIO_InitTypeDef GPIO_InitStructButton;
  GPIO_InitStructButton.Pin = GPIO_PIN_0;
  GPIO_InitStructButton.Mode = GPIO_MODE_INPUT;
  GPIO_InitStructButton.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStructButton);
	
	while(1)
	{
		if(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_0) == GPIO_PIN_SET)
		{
			HAL_GPIO_WritePin(GPIOG, GPIO_PIN_13, GPIO_PIN_SET);
			HAL_GPIO_WritePin(GPIOG, GPIO_PIN_14, GPIO_PIN_SET);
			delay();
			HAL_GPIO_WritePin(GPIOG, GPIO_PIN_13, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOG, GPIO_PIN_14, GPIO_PIN_RESET);
		}
	}
	return 0;
}

void delay(void)
{
	volatile uint32_t i =0;
	for(i=0; i<1000000; i++);
}
