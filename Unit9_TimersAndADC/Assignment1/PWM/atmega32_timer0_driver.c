/*
 * atmega32_timer0_driver.c
 *
 * Created: 14-May-22 1:56:10 AM
 *  Author: Mostafa
 */ 
//--------------------------------------------------------------------------------------------------------------------
//														Includes
//--------------------------------------------------------------------------------------------------------------------
#include "atmega32_timer0_driver.h"
#include "atmega32_gpio_driver.h"
#include <avr/interrupt.h>
//--------------------------------------------------------------------------------------------------------------------
//														Globals
//--------------------------------------------------------------------------------------------------------------------

void (*P_TIMER0_CallBack)(State state);


/**================================================================
 * @Fn			-MCAL_TIMER0_init.
 * @brief	    -initialize the TIMER0 according to config instance cfg.
 * @param [in] 	-TIMERx: x can be (0) 
 * @param [in] 	-cfg: pointer to TIMER0_config that contains TIMER0 configuration.
 * @retval 		-none
 * Note			-none
 */

void MCAL_TIMER0_init(TIMER0_typedef * TIMERx,TIMER0_config * cfg){
	switch(cfg->TIMER0_Mode){
		case TIMER0_NORMAL_MODE:
			TIMERx->TCCR0_.bits.WGM00_ =  0b0;
			TIMERx->TCCR0_.bits.WGM01_ =	0b0;
			break;
		case TIMER0_CTC_MODE:
			TIMERx->TCCR0_.bits.WGM00_ =  0b0;
			TIMERx->TCCR0_.bits.WGM01_ =	0b1;
			break;
		case TIMER0_PHASECORRECTPWM_MODE:
			TIMERx->TCCR0_.bits.WGM00_ =  0b1;
			TIMERx->TCCR0_.bits.WGM01_ =	0b0;
			break;
		case TIMER0_FASTPWM_MODE:
			TIMERx->TCCR0_.bits.WGM00_ =  0b1;
			TIMERx->TCCR0_.bits.WGM01_ =	0b1;
			break;
	}
	TIMERx->TCCR0_.bits.COM01_00 = cfg->TIMER0_OC_Config;
	TIMERx->TCCR0_.bits.CS02_00  = cfg->TIMER0_Prescaler;
	TIMERx->TIMSK_.bits.OCIE0_TOIE0 = cfg->TIMER0_Interrupt;
	P_TIMER0_CallBack = cfg->PTR_TIMER0_Callback_Fn;
	ENABLE_INT();		
}

void MCAL_TIMER0_deinit(TIMER0_typedef * TIMERx){
	TIMERx->OCR0_ = 0x00;
	TIMERx->TCCR0_.TCCR0_ = 0x00;
	TIMERx->TIMSK_.bits.OCIE0_TOIE0 = 0b00; 
}
void MCAL_TIMER0_GetOCR(TIMER0_typedef * TIMERx,uint8 * p_OCRValue){
	if(TIMERx->TCCR0_.bits.CS02_00 !=0b000)
	*p_OCRValue=TIMERx->OCR0_;
}
void MCAL_TIMER0_SetOCR(TIMER0_typedef * TIMERx,uint8 OCRValue){
	if(TIMERx->TCCR0_.bits.CS02_00 !=0b000)
		TIMERx->OCR0_ = OCRValue;
} 

ISR(TIMER0_COMP_vect){
	P_TIMER0_CallBack(OC) ;
}
ISR(TIMER0_OVF_vect){
	P_TIMER0_CallBack(TOV);
}	