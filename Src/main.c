/**
 ******************************************************************************
 * @file           	: main.c
 * @author          : Rubin Khadka
 * @brief          	: Main program body
 * @date			: Feb 12, 2026
 ******************************************************************************
 */

#include "stm32f103xb.h"
#include "gpio.h"

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
  #warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif

int main(void)
{
	// GPIO PC13 initialization
	LED_init();

	while(1)
	{
		LED_ON();
		Delay_ms(500);
		LED_OFF();
		Delay_ms(500);
	}
}

