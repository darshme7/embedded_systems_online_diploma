/*
 * atmega32_uart_driver.h
 *
 *  Created on: Jun 8, 2021
 *      Author: mosta
 */

//--------------------------------------------------------------------------------------------------------------------
//Includes
//--------------------------------------------------------------------------------------------------------------------

#include "ATmega32.h"

#ifndef INC_ATMEGA32_UART_DRIVER_H_
#define INC_ATMEGA32_UART_DRIVER_H_

//--------------------------------------------------------------------------------------------------------------------
//User type definitions (structures)
//--------------------------------------------------------------------------------------------------------------------
typedef struct{

	uint8 USART_Baudrate;				//specifies the baud rate which is used in transmitting and receiving
										//must be a value of @ref USART_BAUD_RATE_define

	uint8 USART_Databits;				//specifies the no. of data bits (5,6,7,8 or 9 bits)
											//must be a value of @ref USART_DATA_BITS_define

	uint8 USART_Paritybit;				//specifies the parity bit whether no parity, even parity or odd parity
										//must be a value of @ref USART_PARITY_BIT_define

	uint8 USART_Stopbits;				//specifies the no. of stop bits (1 or 2 bits)
										//must be a value of @ref USART_STOP_BITS_define

	uint8 USART_Mode;					//specifies the mode of operation for USART (synchronous or asynchronous)
										//must be a value of @ref USART_MODE_define
}USART_config;

//--------------------------------------------------------------------------------------------------------------------
//Macros Configuration References
//--------------------------------------------------------------------------------------------------------------------
//@ref USART_BAUD_RATE_define
//Baud rate (bps) @ Fosc = 8Mhz
//9600   51
//14.4k  34
//19.2k  25
//28.8k  16
//38.4k  12
//57.6k  8
//76.8k  6
//115.2k 3

#define USART_BR_9600					51
#define USART_BR_14400					34
#define USART_BR_19200					25
#define USART_BR_28800					16
#define USART_BR_38400					12
#define USART_BR_57600					8
#define USART_BR_76800					6
#define USART_BR_115200					3

//@ref USART_DATA_BITS_define

#define USART_5_DATA_BITS				0
#define USART_6_DATA_BITS				1
#define USART_7_DATA_BITS				2
#define USART_8_DATA_BITS				3
#define USART_9_DATA_BITS				4

//@ref USART_PARITY_BIT_define

#define USART_NO_PARITY					0
#define USART_ODD_PARITY				1
#define USART_EVEN_PARITY				2

//@refUSART_STOP_BITS_define

#define USART_1_STOP_BIT				0
#define USART_2_STOP_BIT				1

//@ref USART_MODE_define

#define USART_MODE_ASYNC				0
#define USART_MODE_SYNC					1


// ====================================================================================================================
//										APIs Supported by "MCAL GPIO DRIVER"
// ====================================================================================================================

void MCAL_USART_init(USART_config * cfg);
void MCAL_USART_deinit(void);

uint16 MCAL_USART_receive(void);
void MCAL_USART_transmit(uint16 data);

void MCAL_USART_receiveString(uint8 * data);
void MCAL_USART_transmitString(uint8 * data);


#endif /* INC_ATMEGA32_UART_DRIVER_H_ */
