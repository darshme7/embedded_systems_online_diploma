/*
 * stm32f103c6_gpio_driver.h
 *
 *  Created on: Jun 1, 2021
 *      Author: Mostafa
 */

//--------------------------------------------------------------------------------------------------------------------
//Includes
//--------------------------------------------------------------------------------------------------------------------

#include "STM32F103C6.h"

#ifndef INC_STM32F103C6_GPIO_DRIVER_H_
#define INC_STM32F103C6_GPIO_DRIVER_H_

//--------------------------------------------------------------------------------------------------------------------
//User type definitions (structures)
//--------------------------------------------------------------------------------------------------------------------
typedef struct{

	uint8 GPIO_PinNumber;				//specifies the GPIO PIN to be configured
									//this parameter can be a value of @ref GPIO_PIN/PORT_define

	uint8 GPIO_PinMode;					//specifies the Mode for selected pin.
									//this parameter can be a value of @ref GPIO_MODE_define

	uint8 GPIO_OutputSpeed;				//specifies the output speed for selected pin.
									//this parameter can be a value of @ref GPIO_SPEED_define

}GPIO_config;
//--------------------------------------------------------------------------------------------------------------------
//Macros Configuration References
//--------------------------------------------------------------------------------------------------------------------
//@ref GPIO_PIN/PORT_define

#define GPIO_PIN0					(uint8)0x0
#define GPIO_PIN1					(uint8)0x1
#define GPIO_PIN2					(uint8)0x2
#define GPIO_PIN3					(uint8)0x3
#define GPIO_PIN4					(uint8)0x4
#define GPIO_PIN5					(uint8)0x5
#define GPIO_PIN6					(uint8)0x6
#define GPIO_PIN7					(uint8)0x7
#define GPIO_PIN8					(uint8)0x8
#define GPIO_PIN9					(uint8)0x9
#define GPIO_PIN10					(uint8)0xA
#define GPIO_PIN11					(uint8)0xB
#define GPIO_PIN12					(uint8)0xC
#define GPIO_PIN13					(uint8)0xD
#define GPIO_PIN14					(uint8)0xE
#define GPIO_PIN15					(uint8)0xF
#define GPIO_PORT					(uint8)0x10

//@ref GPIO_MODE_define
//0: Analog mode
//1: Floating input (reset state)
//2: Input with pull-up
//3: Input with pull-down
//4: General purpose output push-pull
//5: General purpose output Open-drain
//6: Alternate function output Push-pull
//7: Alternate function output Open-drain

#define GPIO_MODE_ANALOG			(uint8)0x0
#define GPIO_MODE_INPUT_FLO			(uint8)0x1
#define GPIO_MODE_INPUT_PU			(uint8)0x2
#define GPIO_MODE_INPUT_PD			(uint8)0x3
#define GPIO_MODE_OUTPUT_PP			(uint8)0x4
#define GPIO_MODE_OUTPUT_OD			(uint8)0x5
#define GPIO_MODE_OUTPUT_AF_PP		(uint8)0x6
#define GPIO_MODE_OUTPUT_AF_OD		(uint8)0x7

//@ref GPIO_SPEED_define
//0: Input mode
//1: Output mode, max speed 10 MHz.
//2: Output mode, max speed 2 MHz.
//3: Output mode, max speed 50 MHz.

#define GPIO_INPUT					(uint8)0x0
#define GPIO_SPEED_10M				(uint8)0x1
#define GPIO_SPEED_2M				(uint8)0x2
#define GPIO_SPEED_50M				(uint8)0x3

//@ref GPIO_PIN_STATE_define

#define GPIO_HIGH					1
#define GPIO_LOW					0

//@ref GPIO_LOCK_STATE_define

#define GPIO_LOCK_ENABLED			1
#define GPIO_LOCK_FAILED			0
// ====================================================================================================================
//										APIs Supported by "MCAL GPIO DRIVER"
// ====================================================================================================================

void MCAL_GPIO_init(GPIO_typedef * GPIOx,GPIO_config * cfg);
void MCAL_GPIO_deinit(GPIO_typedef * GPIOx);

uint8 MCAL_GPIO_readPin(GPIO_typedef * GPIOx,uint8 PinNumber );
uint16 MCAL_GPIO_readPort(GPIO_typedef * GPIOx);

void MCAL_GPIO_writePin(GPIO_typedef * GPIOx,uint8 PinNumber,uint8 data );
void MCAL_GPIO_writePort(GPIO_typedef * GPIOx,uint16 data );

void MCAL_GPIO_togglePin(GPIO_typedef * GPIOx,uint8 PinNumber);

uint8 MCAL_GPIO_lockPin(GPIO_typedef * GPIOx,uint8 PinNumber);



#endif /* INC_STM32F103C6_GPIO_DRIVER_H_ */
