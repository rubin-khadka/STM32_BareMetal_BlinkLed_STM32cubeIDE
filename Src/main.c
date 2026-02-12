/**
 ******************************************************************************
 * @file           	: main.c
 * @author          : Rubin Khadka
 * @brief          	: Main program body
 * @date			: Feb 12, 2026
 ******************************************************************************
 */

#include "STM32F103xB.h"
#include <stdint.h>

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
  #warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif

int main(void)
{
    /* Loop forever */
	while(1)
	{

	}
}
