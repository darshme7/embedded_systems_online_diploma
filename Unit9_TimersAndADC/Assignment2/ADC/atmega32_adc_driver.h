/*
 * atmega32_adc_driver.h
 *
 * Created: 16-May-22 9:35:08 PM
 *  Author:
 */ 
//--------------------------------------------------------------------------------------------------------------------
//Includes
//--------------------------------------------------------------------------------------------------------------------

#include "ATmega32.h"

#ifndef ATMEGA32_ADC_DRIVER_H_
#define ATMEGA32_ADC_DRIVER_H_

//--------------------------------------------------------------------------------------------------------------------
//User type definitions (structures)
//--------------------------------------------------------------------------------------------------------------------

typedef struct{

	uint8 ADC_Channel;				//specifies the ADC_Channel to be configured
									//this parameter can be a value of @ref ADC_Channel_define

	uint8 ADC_AdjustResult;			//Adjusts The orientation of Result Registers(left or right).
									//this parameter can be a value of @ref ADC_ADJUST_define
	
	uint8 ADC_RefSelect;			//sets The REF of The ADC Peripheral (AVSS,Internal Vref2.56 or AREF external).
									//this parameter can be a value of @ref ADC_REFERENCE_define

	uint8 ADC_Prescaler;			//specifies the ADC Prescaler to be configured
									//this parameter can be a value of @ref ADC_PRESCALER_define


	uint8 ADC_Interrupt;			//enables or disables Interrupt.
									//this parameter can be a value of @ref ADC_INTERRUPT_define
	
	void (*P_ADC_CallBack_Fn)();	//pointer to the callback function  							
									
}ADC_config;

//--------------------------------------------------------------------------------------------------------------------
//Macros Configuration References
//--------------------------------------------------------------------------------------------------------------------
//@ref ADC_Channel_define
//• Bits 4:0 – MUX4:0: Analog Channel and Gain Selection Bits
// MUX4..0		Single Ended Input
//  00000 				ADC0
//  00001				ADC1
//  00010				ADC2
//  00011				ADC3
//  00100				ADC4
//  00101				ADC5
//  00110				ADC6
//  00111				ADC7

#define ADC_CHANNEL0					0b00000
#define ADC_CHANNEL1					0b00001
#define ADC_CHANNEL2					0b00010
#define ADC_CHANNEL3					0b00011
#define ADC_CHANNEL4					0b00100
#define ADC_CHANNEL5					0b00101
#define ADC_CHANNEL6					0b00110
#define ADC_CHANNEL7					0b00111


//@ref ADC_ADJUST_define
//• Bit 5 – ADLAR: ADC Left Adjust Result
//Write one to ADLAR to left adjust the result. Otherwise, the result is right adjusted.

#define ADC_LEFT_ADJUST					    0b1
#define ADC_RIGHT_ADJUST					0b0

//@ref ADC_REFERENCE_define
//• Bit 7:6 – REFS1:0: Reference Selection Bits
//REFS1 REFS0	Voltage Reference Selection
// 0	 0			AREF, Internal Vref turned off
// 0	 1			AVCC with external capacitor at AREF pin
// 1     1			Internal 2.56V Voltage Reference with external capacitor at AREF pin.

#define ADC_AREF_EXTERNAL_REFERENCE					0b00
#define ADC_AVSS_REFERENCE							0b01
#define ADC_AREF_INTERNAL_REFERENCE					0b11

//@ref ADC_PRESCALER_define
//• Bits 2:0 – ADPS2:0: ADC Prescaler Select Bits
//These bits determine the division factor between the XTAL frequency and the input clock to the ADC.
//ADPS2 ADPS1 ADPS0 Division Factor
// 0	  0		1		  2
// 0	  1		0		  4
// 0	  1		1		  8
// 1	  0		0		  16
// 1	  0		1		  32
// 1	  1		0		  64
// 1	  1		1		  128

#define  ADC_2_PRESCALER		0b001
#define  ADC_4_PRESCALER		0b010
#define  ADC_8_PRESCALER		0b011
#define  ADC_16_PRESCALER		0b100
#define  ADC_32_PRESCALER		0b101
#define  ADC_64_PRESCALER		0b110
#define  ADC_128_PRESCALER		0b111


//@ref ADC_INTERRUPT_define
//Bit 3 – ADIE: ADC Interrupt Enable
//When this bit is written to one and the I-bit in SREG is set, the ADC Conversion Complete Interrupt is activated.

#define ADC_DISABLE_INTERRUPT					0b0
#define ADC_ENABLE_INTERRUPT					0b1

// ====================================================================================================================
//										APIs Supported by "MCAL ADC DRIVER"
// ====================================================================================================================

void MCAL_ADC_Init(ADC_config * cfg);
void MCAL_ADC_Deinit();

void MCAL_ADC_ChangeChannel(uint8 ChannelNo );
uint16 MCAL_ADC_Read();


#endif /* ATMEGA32_ADC_DRIVER_H_ */