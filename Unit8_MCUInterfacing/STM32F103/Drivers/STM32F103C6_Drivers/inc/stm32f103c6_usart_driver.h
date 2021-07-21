/*
 * stm32f103c6_usart_driver.h
 *
 *  Created on: Jun 11, 2021
 *      Author: mosta
 */
//--------------------------------------------------------------------------------------------------------------------
//Includes
//--------------------------------------------------------------------------------------------------------------------

#include "STM32F103C6.h"

#ifndef INC_STM32F103C6_USART_DRIVER_H_
#define INC_STM32F103C6_USART_DRIVER_H_

//--------------------------------------------------------------------------------------------------------------------
//User type definitions (structures)
//--------------------------------------------------------------------------------------------------------------------
typedef struct{

	uint32 USART_BaudRate;				//specifies the baud rate of the USART
										//must be a value of @ref USART_BAUD_RATE_define

	uint8 USART_DataBits;				//specifies the no. of data bits in USART frame (8/9bits).
										//must be a value of @ref USART_DATA_BITS_define

	uint8 USART_ParityBit;				//specifies the parity either no parrity , odd or even .
										//must be a value of @ref USART_PARITY_BIT_define

	uint8 USART_StopBits;				//specifies the no. of stop bits (1/2bits).
										//must be a value of @ref USART_STOP_BITS_define

	uint8 USART_Mode;					//specifies the mode of USART (Tx, Rx, Tx/Rx).
										//must be a value of @ref USART_MODE_define

	uint8 USART_ISREnable;				//specifies whether and which interrupt to be used.
										//must be a value of @ref USART_ISR_ENABLE_define

	void (*USART_P_ISR_CallBack)(void);		//pointer to function to be called from interrupt.

}USART_config;

enum USART_Polling {disable,enable};

//--------------------------------------------------------------------------------------------------------------------
//Macros Configuration References
//--------------------------------------------------------------------------------------------------------------------
//@ref USART_BAUD_RATE_define

#define USART_BR_2400					2400
#define USART_BR_9600					9600
#define USART_BR_19200					19200
#define USART_BR_57600					57600
#define USART_BR_115200					115200
#define USART_BR_230400					230400
#define USART_BR_460800					460800
#define USART_BR_921600					921600
#define USART_BR_2250000				2250000
#define USART_BR_4500000				4500000

//@ref USART_DATA_BITS_define
//When the parity control is enabled,
//the computed parity is inserted at the MSB position (9th bit ; 8th bit).

#define USART_8_DATA_BITS				0b0
#define USART_9_DATA_BITS				0b1

//@ref USART_PARITY_BIT_define

#define USART_NO_PARITY					0b00
#define USART_ODD_PARITY				0b11
#define USART_EVEN_PARITY				0b10

//@ref USART_STOP_BITS_define

#define USART_1_STOP_BIT				0b00
#define USART_2_STOP_BIT				0b10

//@ref USART_MODE_define

#define USART_MODE_TX					0b10
#define USART_MODE_RX					0b01
#define USART_MODE_TX_RX				0b11

//@ref USART_ISR_ENABLE_define

#define USART_ISR_ENABLE_PE				0b1000
#define USART_ISR_ENABLE_TXE			0b0100
#define USART_ISR_ENABLE_TC				0b0010
#define USART_ISR_ENABLE_RXNE			0b0001
#define USART_ISR_ENABLE_NONE			0b0000

// ====================================================================================================================
//										APIs Supported by "MCAL USART DRIVER"
// ====================================================================================================================

void MCAL_USART_init(USART_typedef * USARTx ,USART_config *cfg);
void MCAL_USART_deinit(USART_typedef * USARTx);

void MCAL_USART_transmit(USART_typedef * USARTx ,uint16 data,enum USART_Polling PollingEN);
uint16 MCAL_USART_receive(USART_typedef * USARTx,enum USART_Polling PollingEN);


void MCAL_USART_transmitString(USART_typedef * USARTx ,char * data);
void MCAL_USART_receiveString(USART_typedef * USARTx,char * data);


#endif /* INC_STM32F103C6_USART_DRIVER_H_ */
