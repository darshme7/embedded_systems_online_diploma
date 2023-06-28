/*
 * stm32f103c6_SPI_driver.h
 *
 *  Created on: Jun 11, 2021
 *      Author: mosta
 */
//--------------------------------------------------------------------------------------------------------------------
//Includes
//--------------------------------------------------------------------------------------------------------------------

#include "STM32F103C6.h"

#ifndef INC_STM32F103C6_SPI_DRIVER_H_
#define INC_STM32F103C6_SPI_DRIVER_H_

//--------------------------------------------------------------------------------------------------------------------
//User type definitions (structures)
//--------------------------------------------------------------------------------------------------------------------

typedef struct{

	uint8 SPI_Mode;						//specifies the mode of the SPI (Master/Slave)
										//must be a value of @ref SPI_MODE_define

	uint32 SPI_BaudRatePrescaler;		//specifies the baud rate prescaler of the SPI
										//must be a value of @ref SPI_BR_PRESCALER_define

	uint8 SPI_ClkPolarity;				//specifies whether the SCK pin of the SPI stays high or low when idle
										//must be a value of @ref SPI_CLKPOL_define

	uint8 SPI_ClkPhase;					//specifies whether the bit capture storbe will be first or second edge of SCK
										//must be a value of @ref SPI_CLKPHA_define

	uint8 SPI_DataFrameBits;			//specifies the number of Data bits in SPI frame (8/16 bits)
										//must be a value of @ref SPI_DFF_define

	uint8 SPI_BitOrder;					//specifies whether to send/receive MSB or LSB first
										//must be a value of @ref SPI_BITORDER_define

	uint8 SPI_NSS;						//specifies whether HW/SW slave select
										//must be a value of @ref SPI_NSS_define

	uint8 IRQ_Enable;					//determine which interrupt is enabled.
										//must be a value of @ref SPI_IRQ_define

	void (* SPI_P_ISR_CallBack)(void);		//pointer to function to be called from interrupt.

}SPI_config;

enum SPI_Polling {Disabled,Enabled};

//--------------------------------------------------------------------------------------------------------------------
//Macros Configuration References
//--------------------------------------------------------------------------------------------------------------------
//@ref SPI_MODE_define

#define SPI_MODE_MASTER		0b1
#define SPI_MODE_SLAVE		0b0

//@ref SPI_BR_PRESCALER_define
/* BR[2:0]: Baud rate control
000: fPCLK/2
001: fPCLK/4
010: fPCLK/8
011: fPCLK/16
100: fPCLK/32
101: fPCLK/64
110: fPCLK/128
111: fPCLK/256 */

#define  SPI_BR_PRESCALER_2				0b000
#define  SPI_BR_PRESCALER_4				0b001
#define  SPI_BR_PRESCALER_8				0b010
#define  SPI_BR_PRESCALER_16			0b011
#define  SPI_BR_PRESCALER_32			0b100
#define  SPI_BR_PRESCALER_64			0b101
#define  SPI_BR_PRESCALER_128			0b110
#define  SPI_BR_PRESCALER_256			0b111

//@ref SPI_CLKPOL_define

#define SPI_CLKPOL_LOW_WHEN_IDLE		0b0
#define SPI_CLKPOL_HIGH_WHEN_IDLE		0b1

//@ref SPI_CLKPHA_define

#define SPI_CLKPHA_FIRST_EDGE_SAMPLE	0b0
#define SPI_CLKPHA_SECOND_EDGE_SAMPLE	0b1

//@ref SPI_DFF_define

#define SPI_DFF_8_BITS					0b0
#define SPI_DFF_16_BITS					0b1

//@ref SPI_BITORDER_define

#define SPI_BITORDER_MSBFIRST			0b0
#define SPI_BITORDER_LSBFIRST			0b1

//@ref SPI_NSS_define

#define SPI_NSS_SOFTWARE_RESET							0	//value of NSS is determined by SSI bit which will be 0
#define SPI_NSS_SOFTWARE_SET							1	//value of NSS is determined by SSI bit which will be 1
#define SPI_NSS_HARDWARE_OUTPUT_ENABLE					2	//only for master mode, NSS pin is driven low when communication starts
#define SPI_NSS_HARDWARE_OUTPUT_DISABLE					3	//for multimaster capability or for slave as classic NSS input


//@ref SPI_IRQ_define

#define SPI_IRQ_DISABLE					0b000
#define SPI_IRQ_TXEIE					0b100
#define SPI_IRQ_RXNEIE					0b010
#define SPI_IRQ_TXEIE_RXNEIE			0b110
#define SPI_IRQ_ERRIE					0b001

// ====================================================================================================================
//										APIs Supported by "MCAL USART DRIVER"
// ====================================================================================================================

void MCAL_SPI_init(SPI_typedef * SPIx ,SPI_config *cfg);
void MCAL_SPI_deinit(SPI_typedef * SPIx);

uint16 MCAL_SPI_TxRx(SPI_typedef * SPIx ,uint16 data,enum SPI_Polling poll);

#endif /* INC_STM32F103C6_SPI_DRIVER_H_ */
