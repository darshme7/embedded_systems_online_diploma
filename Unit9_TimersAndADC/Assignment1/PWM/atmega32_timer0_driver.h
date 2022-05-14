/*
 * atmega32_pwm_driver.h
 *
 * Created: 14-May-22 1:55:33 AM
 *  Author: Mostafa
 */ 

#ifndef ATMEGA32_TIMER0_DRIVER_H_
#define ATMEGA32_TIMER0_DRIVER_H_
//--------------------------------------------------------------------------------------------------------------------
//Includes
//--------------------------------------------------------------------------------------------------------------------

#include "ATmega32.h"
#define F_CPU 8000000UL


//--------------------------------------------------------------------------------------------------------------------
//User type definitions (structures)
//--------------------------------------------------------------------------------------------------------------------
typedef enum {
	TOV,
	OC
	}State;
	
typedef struct{

	uint8 TIMER0_Mode;									//specifies the Mode of operation of TIMER0 
														//this parameter must be a value of @ref TIMER0_MODE_define.
	uint8 TIMER0_OC_Config;								//specifies the OC0 mode of operation
														//this parameter must be a value of @ref TIMER0_OC_define.
	uint8 TIMER0_Prescaler;								//specifies the Prescaler of TIMER0
														//this parameter must be a value of @ref TIMER0_PRESCALER_define.
	uint8 TIMER0_Interrupt;								//specifies the Interrupt of TIMER0
														//this parameter must be a value of @ref TIMER0_Interrupt_define.
	void (*PTR_TIMER0_Callback_Fn)(State state);		// pointer to the callback function to be called when interrupt occurs.

}TIMER0_config;

//--------------------------------------------------------------------------------------------------------------------
//Macros Configuration References
//--------------------------------------------------------------------------------------------------------------------
//@ref TIMER0_MODE_define.
//Bit 6, 3 – WGM01:0: Waveform Generation Mode
//These bits control the counting sequence of the counter, the source for the maximum (TOP)
//counter value, and what type of Waveform Generation to be used. 
//Modes of operation supported by the Timer/Counter unit are: Normal mode, 
//Clear Timer on Compare Match (CTC) mode, and two types of Pulse Width Modulation (PWM) modes.
// 0 0 Normal 
// 0 1 PWM
// 1 0 CTC
// 1 1 Fast 

#define TIMER0_NORMAL_MODE					0b00
#define TIMER0_CTC_MODE						0b10
#define TIMER0_FASTPWM_MODE					0b11
#define TIMER0_PHASECORRECTPWM_MODE			0b01

//@ref TIMER0_OC_define.
//• Bit 5:4 – COM01:0: Compare Match Output Mode
//These bits control the Output Compare pin (OC0) behavior. If one or both of the COM01:0 bits
//are set, the OC0 output overrides the normal port functionality of the I/O pin it is connected to.
//Compare Output Mode, non-PWM Mode						Compare Output Mode, Fast PWM Mode	                    Compare Output Mode, Phase Correct PWM Mode
//COM01 COM00												
// 0	 0	     									  Normal port operation, OC0 disconnected
// 0	 1 Toggle OC0 on compare match																	Reserved
// 1	 0 Clear OC0 on compare match					 Clear OC0 on compare match, set OC0 at BOTTOM,(non-inverting mode)     Clear OC0 on compare match when up-counting. Set OC0 on compare match when downcounting.    
// 1	 1 Set OC0 on compare match						 Set OC0 on compare match, clear OC0 at BOTTOM,(inverting mode)			Set OC0 on compare match when up-counting. Clear OC0 on compare match when downcounting.

#define TIMER0_NO_OC								0b00
#define TIMER0_OC_TOGGLE			            	0b01
#define TIMER0_OC_NON_INVERTING_PWM					0b10
#define TIMER0_OC_INVERTING_PWM						0b11

//@ref TIMER0_PRESCALER_define.
//• Bit 2:0 – CS02:0: Clock Select
//The three Clock Select bits select the clock source to be used by the Timer/Counter.
//CS02 CS01 CS00 
// 0	0	 0 No clock source (Timer/Counter stopped).
// 0	0	 1 clk(No prescaling)
// 0	1	 0 clk/8 (From prescaler)
// 0	1	 1 clk/64 (From prescaler)
// 1	0	 0 clk/256 (From prescaler)
// 1	0	 1 clkI/1024 (From prescaler)
// 1	1    0 External clock source on T0 pin. Clock on falling edge.
// 1	1	 1 External clock  source on T0 pin. Clock on rising edge.

#define TIMER0_NO_CLK						0b000
#define TIMER0_NO_PRESCALER					0b001
#define TIMER0_8_PRESCALER					0b010
#define TIMER0_64_PRESCALER					0b011
#define TIMER0_256_PRESCALER				0b100
#define TIMER0_1024_PRESCALER				0b101
#define TIMER0_EXT_CLK_FALLING				0b110
#define TIMER0_EXT_CLK_RISING				0b111

//@ref TIMER0_Interrupt_define.
//• Bit 1 – OCIE0: Timer/Counter0 Output Compare Match Interrupt Enable
//When the OCIE0 bit is written to one, and the I-bit in the Status Register is set (one), the
//Timer/Counter0 Compare Match interrupt is enabled.
//• Bit 0 – TOIE0: Timer/Counter0 Overflow Interrupt Enable
//When the TOIE0 bit is written to one, and the I-bit in the Status Register is set (one), the
//Timer/Counter0 Overflow interrupt is enabled.

#define TIMER0_NO_INTERRUPT							0b00
#define TIMER0_TOV_INTERRUPT_ONLY					0b01
#define TIMER0_OCR_INTERRUPT_ONLY					0b10
#define TIMER0_OCR_TOV_INTERRUPT					0b11
// ====================================================================================================================
//										APIs Supported by "MCAL TIMER0 DRIVER"
// ====================================================================================================================

void MCAL_TIMER0_init(TIMER0_typedef * TIMERx,TIMER0_config * cfg);
void MCAL_TIMER0_deinit(TIMER0_typedef * TIMERx);
void MCAL_TIMER0_GetOCR(TIMER0_typedef * TIMERx,uint8 * p_OCRValue);
void MCAL_TIMER0_SetOCR(TIMER0_typedef * TIMERx,uint8 OCRValue);

#endif /* ATMEGA32_PWM_DRIVER_H_ */