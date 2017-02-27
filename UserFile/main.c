#include "stm8s.h"
#include "mystm8sxxx.h"


/* Declaring Global Variables */
volatile uint32_t clock_frequency=0;


/* Declaring Function Prototype */
void delay(uint32_t time);

void main(void)
{

	clk_config_16MHz_hse();
	clock_frequency = CLK_GetClockFreq();

	GPIO_Init(GPIOC,
			(GPIO_Pin_TypeDef)(GPIO_PIN_1 | GPIO_PIN_2 | GPIO_PIN_3 | GPIO_PIN_4),
			GPIO_MODE_OUT_PP_HIGH_FAST);

	while (1)
	{
		GPIO_WriteReverse(GPIOC,
				(GPIO_Pin_TypeDef)(GPIO_PIN_1 | GPIO_PIN_2 | GPIO_PIN_3 | GPIO_PIN_4));
		delay(40000);
	}
}

/* User Function */
void delay(uint32_t time)
{
	while(time--);
}



#ifdef USE_FULL_ASSERT

/**
 * @brief  Reports the name of the source file and the source line number
 *   where the assert_param error has occurred.
 * @param file: pointer to the source file name
 * @param line: assert_param error line source number
 * @retval : None
 */
void assert_failed(u8* file, u32 line)
{ 
	/* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */

	/* Infinite loop */
	while (1)
	{
	}
}
#endif


/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
