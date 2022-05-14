/*
 * PWM.c
 *
 * Created: 14-May-22 1:37:01 AM
 * Author : Mostafa
 */ 

#include "atmega32_timer0_driver.h"
#include "atmega32_gpio_driver.h"

void TIMER0_CallBack(State state){
}
int main(void)
{	TIMER0_config cfg;
	GPIO_config cfg2;
	cfg2.GPIO_PinMode	= GPIO_MODE_OUTPUT_PP;
	cfg2.GPIO_PinNumber = GPIO_PIN3;
	MCAL_GPIO_init(GPIOB,&cfg2);
	MCAL_GPIO_writePin(GPIOD,GPIO_PIN4,GPIO_LOW);
	cfg.TIMER0_Mode = TIMER0_PHASECORRECTPWM_MODE;
	cfg.TIMER0_OC_Config = TIMER0_OC_NON_INVERTING_PWM;
	cfg.TIMER0_Prescaler = TIMER0_8_PRESCALER;
	cfg.TIMER0_Interrupt = TIMER0_NO_INTERRUPT;
	cfg.PTR_TIMER0_Callback_Fn = NULL;
    MCAL_TIMER0_init(TIMER0,&cfg);
	MCAL_TIMER0_SetOCR(TIMER0,32);
	while (1) 
    {			
    }
}

