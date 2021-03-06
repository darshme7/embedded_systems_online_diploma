/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Auto-generated by STM32CubeIDE
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * <h2><center>&copy; Copyright (c) 2021 STMicroelectronics.
 * All rights reserved.</center></h2>
 *
 * This software component is licensed by ST under BSD 3-Clause license,
 * the "License"; You may not use this file except in compliance with the
 * License. You may obtain a copy of the License at:
 *                        opensource.org/licenses/BSD-3-Clause
 *
 ******************************************************************************
 */

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
#warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif

#include "LCD.h"
#include "Keypad.h"
#include "7segment.h"
#include "stm32f103c6_exti_driver.h"

void IRQ0_Handler(void){

	LCD_printString("IRQ_9 Has Happened");
	delay(150);
}


void clockInit(void){

	RCC_GPIOA_CLK_EN();
	RCC_GPIOB_CLK_EN();
	RCC_AFIO_CLK_EN();
}

int main(void)
{
	EXTI_config cfg;
	clockInit();
	LCD_init();
	KEYPAD_init();


	cfg.EXTI_Map		 = EXTI9PB9;
	cfg.EXTI_Trigger	 = EXTI_RISING;
	cfg.EXTI_EnableState = EXTI_ENABLE;
	cfg.P_IRQHandler	 = IRQ0_Handler;
	MCAL_EXTI_init(&cfg);

	char data;
	LCD_printString("Hello");
	delay(300);
	LCD_clearScreen();

	while(1){

		data = KEYPAD_getChar();
		switch(data){
		case '!':
			LCD_clearScreen();
			break;
		case '\0':
			break;
		default:
			LCD_printChar(data);
		}
	}
}

