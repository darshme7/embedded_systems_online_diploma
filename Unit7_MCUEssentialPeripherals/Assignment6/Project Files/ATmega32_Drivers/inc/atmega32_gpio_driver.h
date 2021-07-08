/*
 * atmega32_gpio_driver.h
 *
 *  Created on: Jun 8, 2021
 *      Author: mosta
 */
//--------------------------------------------------------------------------------------------------------------------
//Includes
//--------------------------------------------------------------------------------------------------------------------

#include "ATmega32.h"

#ifndef INC_ATMEGA32_GPIO_DRIVER_H_
#define INC_ATMEGA32_GPIO_DRIVER_H_

//--------------------------------------------------------------------------------------------------------------------
//User type definitions (structures)
//--------------------------------------------------------------------------------------------------------------------

typedef struct{

	uint8 GPIO_PinNumber;				//specifies the GPIO PIN to be configured
									//this parameter can be a value of @ref GPIO_PIN/PORT_define

	uint8 GPIO_PinMode;					//specifies the Mode for selected pin.
									//this parameter can be a value of @ref GPIO_MODE_define
}GPIO_config;

//--------------------------------------------------------------------------------------------------------------------
//Macros Configuration References
//--------------------------------------------------------------------------------------------------------------------
//@ref GPIO_PIN/PORT_define

#define GPIO_PIN0					0
#define GPIO_PIN1					1
#define GPIO_PIN2					2
#define GPIO_PIN3					3
#define GPIO_PIN4					4
#define GPIO_PIN5					5
#define GPIO_PIN6					6
#define GPIO_PIN7					7

#define GPIO_PORT					8

//@ref GPIO_MODE_define
//0: HI-Z input (reset state)
//1: Input with pull-up
//2: General purpose output push-pull


#define GPIO_MODE_INPUT_HiZ			0
#define GPIO_MODE_INPUT_PU			1
#define GPIO_MODE_OUTPUT_PP			2


//@ref GPIO_PIN_STATE_define

#define GPIO_HIGH					1
#define GPIO_LOW					0

// ====================================================================================================================
//										APIs Supported by "MCAL GPIO DRIVER"
// ====================================================================================================================

void MCAL_GPIO_init(GPIO_typedef * GPIOx,GPIO_config * cfg);
void MCAL_GPIO_deinit(GPIO_typedef * GPIOx);

uint8 MCAL_GPIO_readPin(GPIO_typedef * GPIOx,uint8 PinNumber );
uint8 MCAL_GPIO_readPort(GPIO_typedef * GPIOx);

void MCAL_GPIO_writePin(GPIO_typedef * GPIOx,uint8 PinNumber,uint8 data );
void MCAL_GPIO_writePort(GPIO_typedef * GPIOx,uint8 data );

void MCAL_GPIO_togglePin(GPIO_typedef * GPIOx,uint8 PinNumber);


#endif /* INC_ATMEGA32_GPIO_DRIVER_H_ */
