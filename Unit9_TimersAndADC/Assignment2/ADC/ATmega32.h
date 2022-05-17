/*
 * ATmega32.h
 *
 *  Created on: Jun 8, 2021
 *      Author: Mostafa
 */
//---------------------------------------------------------------------
//Includes
//---------------------------------------------------------------------

#include "Platform_Types.h"

#ifndef INC_ATMEGA32_H_
#define INC_ATMEGA32_H_

//---------------------------------------------------------------------
//Base Addresses for Memories
//---------------------------------------------------------------------

#define FLASH_Memory									0x00
#define SRAM											0x60

//---------------------------------------------------------------------
//Base Addresses Peripherals
//---------------------------------------------------------------------

#define GPIOA_Base										0x39
#define GPIOB_Base										0x36
#define GPIOC_Base										0x33
#define GPIOD_Base										0x30

#define ADC_Base_										0x24
#define USART_Base										0x29
#define TIMER0_Base										0x52


//-*-*-*-*-*-*-*-*-*-*-*-*-	*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*
//Peripheral registers
//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*

//-*-*-*-*-*-*-*-*-*-*-*
//Peripheral register:GPIO
//-*-*-*-*-*-*-*-*-*-*-*

typedef struct{

	volatile	union {
		volatile uint8 PIN;
		struct {
			volatile uint8 PIN0 :1;
			volatile uint8 PIN1 :1;
			volatile uint8 PIN2 :1;
			volatile uint8 PIN3 :1;
			volatile uint8 PIN4 :1;
			volatile uint8 PIN5 :1;
			volatile uint8 PIN6 :1;
			volatile uint8 PIN7 :1;
		}bits;
	}PIN;

	volatile	union {
		volatile uint8 DDR;
		struct {
			volatile uint8 DD0 :1;
			volatile uint8 DD1 :1;
			volatile uint8 DD2 :1;
			volatile uint8 DD3 :1;
			volatile uint8 DD4 :1;
			volatile uint8 DD5 :1;
			volatile uint8 DD6 :1;
			volatile uint8 DD7 :1;
		}bits;
	}DDR;

	volatile	union {
		volatile uint8 PORT;
		struct {
			volatile uint8 PORT0 :1;
			volatile uint8 PORT1 :1;
			volatile uint8 PORT2 :1;
			volatile uint8 PORT3 :1;
			volatile uint8 PORT4 :1;
			volatile uint8 PORT5 :1;
			volatile uint8 PORT6 :1;
			volatile uint8 PORT7 :1;
		}bits;
	}PORT;
}GPIO_typedef;

//-*-*-*-*-*-*-*-*-*-*-*
//Peripheral register:USART
//-*-*-*-*-*-*-*-*-*-*-*

typedef struct{


	volatile uint8 UBRRL;

	volatile	union {
		volatile uint8 UCSRB;
		struct {
			volatile uint8 TXB8 	:1;
			volatile uint8 RXB8 	:1;
			volatile uint8 UCSZ2    :1;
			volatile uint8 TXEN     :1;
			volatile uint8 RXEN     :1;
			volatile uint8 UDRIE    :1;
			volatile uint8 TXCIE    :1;
			volatile uint8 RXCIE    :1;
		}bits;
	}UCSRB;

	volatile	union {
		volatile uint8 UCSRA;
		struct {
			volatile uint8 MPCM :1;
			volatile uint8 U2X  :1;
			volatile uint8 PE   :1;
			volatile uint8 DOR  :1;
			volatile uint8 FE   :1;
			volatile uint8 UDRE :1;
			volatile uint8 TXC  :1;
			volatile uint8 RXC  :1;
		}bits;
	}UCSRA;

	volatile uint8 UDR;

}USART_typedef;

//-*-*-*-*-*-*-*-*-*-*-*
//Peripheral register:Timer0
//-*-*-*-*-*-*-*-*-*-*-*

typedef struct{

	volatile uint8 TCNT0_;
	volatile	union {
		volatile uint8 TCCR0_;
		struct {
			volatile uint8 CS02_00	    :3;
			volatile uint8 WGM01_		:1;
			volatile uint8 COM01_00     :2;
			volatile uint8 WGM00_		:1;
			volatile uint8 FOC0_ 		:1;
		}bits;
	}TCCR0_;
	volatile uint8 reserved0;
	volatile uint8 reserved1;
	volatile uint8 reserved2;
	volatile uint8 reserved3;
	volatile	union {
		volatile uint8 TIFR_;
		struct {
			
			volatile uint8 TOV0_  :1;
			volatile uint8 OCF0_  :1;
			volatile uint8 TOV1_   :1;
			volatile uint8 OCF1B_  :1;
			volatile uint8 OCF1A_  :1;
			volatile uint8 ICF1_   :1;
			volatile uint8 TOV2_	  :1;
			volatile uint8 OCF2_   :1;
		}bits;
	}TIFR_;
	volatile	union {
		volatile uint8 TIMSK_;
		struct {
			
			volatile uint8 OCIE0_TOIE0   :2;
			volatile uint8 TOIE1_		 :1;
			volatile uint8 OCIE1B_		 :1;
			volatile uint8 OCIE1A_		 :1;
			volatile uint8 TICIE1_		 :1;
			volatile uint8 TOIE2_		 :1;
			volatile uint8 OCIE2_		 :1;
		}bits;
	}TIMSK_;
	
	volatile uint8 reserved4;
	volatile uint8 reserved5;
	volatile uint8 OCR0_;

}TIMER0_typedef;

//-*-*-*-*-*-*-*-*-*-*-*
//Peripheral register:ADC
//-*-*-*-*-*-*-*-*-*-*-*

typedef struct{


	volatile uint16 ADCL_H;

	volatile	union {
		volatile uint8 ADCSRA;
		struct {
			volatile uint8 ADPS2_0  :3;
			volatile uint8 ADIE		:1;
			volatile uint8 ADIF		:1;
			volatile uint8 ADATE	:1;
			volatile uint8 ADSC		:1;
			volatile uint8 ADEN		:1;
		}bits;
	}ADCSRA;
	volatile	union {
		volatile uint8 ADMUX;
		struct {
			volatile uint8 MUX4_0		:5;
			volatile uint8 ADLAR		:1;
			volatile uint8 REFS1_0		:2;
			
		}bits;
	}ADMUX;
}ADC_typedef;

//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*
//-*-*-*-*-*-*-*-*-*-*-*-
//Peripheral Instants:
//-*-*-*-*-*-*-*-*-*-*-*

#define GPIOA 							((GPIO_typedef *)(GPIOA_Base))
#define GPIOB 							((GPIO_typedef *)(GPIOB_Base))
#define GPIOC 							((GPIO_typedef *)(GPIOC_Base))
#define GPIOD 							((GPIO_typedef *)(GPIOD_Base))

#define USART							((USART_typedef *)(USART_Base))
#define ADC_								((ADC_typedef   *)(ADC_Base_))
#define TIMER0							((TIMER0_typedef *)(TIMER0_Base))

//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*
//-*-*-*-*-*-*-*-*-*-*-*-
//USART Macros:
//-*-*-*-*-*-*-*-*-*-*-*

#define UBRRH							*((uint8 *)(0x40))

#define UCSRC							*((uint8 *)(0x40))
#define UCPOL							0
#define UCSZ0							1
#define UCSZ1							2
#define USBS							3
#define UPM0							4
#define UPM1							5
#define UMSEL							6
#define URSEL							7



//-*-*-*-*-*-*-*-*-*-*-*-
//Generic Macros:
//-*-*-*-*-*-*-*-*-*-*-*

//Enable Interrupts

#define SREG				*((volatile uint8 *)(0x5F))

#define ENABLE_INT()		SREG |= (1<<7)

#define DISABLE_INT()		SREG &= ~(1<<7)


#endif /* INC_ATMEGA32_H_ */
