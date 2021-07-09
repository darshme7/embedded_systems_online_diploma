/*
 * atmega32_uart_driver.h
 *
 *  Created on: Jun 8, 2021
 *      Author: Mostafa
 */

//--------------------------------------------------------------------------------------------------------------------
//Includes
//--------------------------------------------------------------------------------------------------------------------

#include "ATmega32.h"
#include "atmega32_gpio_driver.h"

#ifndef INC_ATMEGA32_SPI_DRIVER_H_
#define INC_ATMEGA32_SPI_DRIVER_H_

//---------------------------	-----------------------------------------------------------------------------------------
//User type definitions (structures)
//--------------------------------------------------------------------------------------------------------------------
typedef struct{

	uint8 SPI_SCK;				//specifies the clock rate which is used in transmitting and receiving
								//must be a value of @ref SPI_SCK_define
	
	uint8 SPI_CLKPolartiy;		//specifies the clock rate which is used in transmitting and receiving
								//must be a value of @ref SPI_CPOL_define							

	uint8 SPI_CLKPhase;			//specifies the clock rate which is used in transmitting and receiving
								//must be a value of @ref SPI_CPHA_define

	uint8 SPI_DataOrder;		//specifies the data order (MSB or LSB)
								//must be a value of @ref SPI_DATA_BITS_define

	uint8 SPI_Mode;				//specifies the mode of operation for SPI (Master or Slave)
								//must be a value of @ref SPI_MODE_define
}SPI_config;

//--------------------------------------------------------------------------------------------------------------------
//Macros Configuration References
//--------------------------------------------------------------------------------------------------------------------
//@ref SPI_SCK_define
//Relationship Between SCK and the Oscillator Frequency
/*SPI2X SPR1 SPR0 SCK Frequency
	0	 0	  0		fosc/4
	0	 0	  1		fosc/16
	0	 1	  0		fosc/64
	0	 1	  1		fosc/128
	1	 0	  0		fosc/2
	1	 0	  1		fosc/8
	1	 1	  0		fosc/32
	1	 1	  1		fosc/64
*/
	
#define SPI_SCK_4						0b00
#define SPI_SCK_16						0b01
#define SPI_SCK_64						0b10
#define SPI_SCK_128						0b11

//@ref SPI_CPHA_define

#define SPI_CPHA_SAMPLE					0	//sample on leading edge	
#define SPI_CPHA_SETUP					1	//setup on leading edge 

//@ref SPI_CPOL_define

#define SPI_CPOL_RISING					0	//leading edge is rising
#define SPI_CPOL_FALLING				1	//leading edge is falling

//@ref SPI_DATA_ORDER_define

#define SPI_MSB_FIRST				0
#define SPI_LSB_FIRST				1

//@ref SPI_MODE_define

#define SPI_MODE_SLAVE				0
#define SPI_MODE_MASTER				1


// ====================================================================================================================
//										APIs Supported by "MCAL GPIO DRIVER"
// ====================================================================================================================

void MCAL_SPI_init(SPI_config * cfg);
void MCAL_SPI_deinit(void);


uint8 MCAL_SPI_TransmitReceive(uint8 data);

#endif /* INC_ATMEGA32_UART_DRIVER_H_ */
