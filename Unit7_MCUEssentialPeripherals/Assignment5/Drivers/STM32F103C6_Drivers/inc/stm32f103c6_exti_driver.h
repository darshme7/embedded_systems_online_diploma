/*
 * stm32f103c6_exti_driver.h
 *
 *  Created on: Jun 3, 2021
 *      Author: Mostafa
 */

#ifndef INC_STM32F103C6_EXTI_DRIVER_H_
#define INC_STM32F103C6_EXTI_DRIVER_H_

//--------------------------------------------------------------------------------------------------------------------
//Includes
//--------------------------------------------------------------------------------------------------------------------

#include "STM32F103C6.h"
#include "stm32f103c6_gpio_driver.h"
//--------------------------------------------------------------------------------------------------------------------
//User type definitions (structures)
//--------------------------------------------------------------------------------------------------------------------

typedef struct{

	uint8  		 	EXTI_GPIO_PinNumber;			//specifies which pin  (0....15)

	GPIO_typedef *	EXTI_GPIO_PORT;					//specifies which port (A....D)

	uint8 			EXTI_IRQLineNumber;			//specifies which Interrupt line (0....15)

}EXTI_GPIO_Mapping;

typedef struct{

	EXTI_GPIO_Mapping EXTI_Map;				 		//specifes which interrupt line on which port and which pin
													//must be a value of @ref EXTI_GPIO_define

	uint8	EXTI_Trigger;							//specifes the triggering condition either rising, falling or both
													//must be a value of @ref EXTI_TRIGGER_define

	uint8	EXTI_EnableState;						//specifes wether to enable or disable interrupt
													//must be a value of @ref EXTI_ENABLESTATE_define

	void	(*P_IRQHandler)(void);					//the pointer to the user's interrupt handler function
													//to be called when interrupt occur

}EXTI_config;



//--------------------------------------------------------------------------------------------------------------------
//Macros Configuration References
//--------------------------------------------------------------------------------------------------------------------
//@ref EXTI_GPIO_define

#define EXTI0PA0									((EXTI_GPIO_Mapping){GPIO_PIN0,GPIOA,EXTI_L0})
#define EXTI0PB0									((EXTI_GPIO_Mapping){GPIO_PIN0,GPIOB,EXTI_L0})
#define EXTI0PC0									((EXTI_GPIO_Mapping){GPIO_PIN0,GPIOC,EXTI_L0})
#define EXTI0PD0									((EXTI_GPIO_Mapping){GPIO_PIN0,GPIOD,EXTI_L0})

#define EXTI1PA1									((EXTI_GPIO_Mapping){GPIO_PIN1,GPIOA,EXTI_L1})
#define EXTI1PB1									((EXTI_GPIO_Mapping){GPIO_PIN1,GPIOB,EXTI_L1})
#define EXTI1PC1									((EXTI_GPIO_Mapping){GPIO_PIN1,GPIOC,EXTI_L1})
#define EXTI1PD1									((EXTI_GPIO_Mapping){GPIO_PIN1,GPIOD,EXTI_L1})

#define EXTI2PA2									((EXTI_GPIO_Mapping){GPIO_PIN2,GPIOA,EXTI_L2})
#define EXTI2PB2									((EXTI_GPIO_Mapping){GPIO_PIN2,GPIOB,EXTI_L2})
#define EXTI2PC2									((EXTI_GPIO_Mapping){GPIO_PIN2,GPIOC,EXTI_L2})
#define EXTI2PD2									((EXTI_GPIO_Mapping){GPIO_PIN2,GPIOD,EXTI_L2})

#define EXTI3PA3									((EXTI_GPIO_Mapping){GPIO_PIN3,GPIOA,EXTI_L3})
#define EXTI3PB3									((EXTI_GPIO_Mapping){GPIO_PIN3,GPIOB,EXTI_L3})
#define EXTI3PC3									((EXTI_GPIO_Mapping){GPIO_PIN3,GPIOC,EXTI_L3})
#define EXTI3PD3									((EXTI_GPIO_Mapping){GPIO_PIN3,GPIOD,EXTI_L3})

#define EXTI4PA4									((EXTI_GPIO_Mapping){GPIO_PIN4,GPIOA,EXTI_L4})
#define EXTI4PB4									((EXTI_GPIO_Mapping){GPIO_PIN4,GPIOB,EXTI_L4})
#define EXTI4PC4									((EXTI_GPIO_Mapping){GPIO_PIN4,GPIOC,EXTI_L4})
#define EXTI4PD4									((EXTI_GPIO_Mapping){GPIO_PIN4,GPIOD,EXTI_L4})

#define EXTI5PA5									((EXTI_GPIO_Mapping){GPIO_PIN5,GPIOA,EXTI_L5})
#define EXTI5PB5									((EXTI_GPIO_Mapping){GPIO_PIN5,GPIOB,EXTI_L5})
#define EXTI5PC5									((EXTI_GPIO_Mapping){GPIO_PIN5,GPIOC,EXTI_L5})
#define EXTI5PD5									((EXTI_GPIO_Mapping){GPIO_PIN5,GPIOD,EXTI_L5})

#define EXTI6PA6									((EXTI_GPIO_Mapping){GPIO_PIN6,GPIOA,EXTI_L6})
#define EXTI6PB6									((EXTI_GPIO_Mapping){GPIO_PIN6,GPIOB,EXTI_L6})
#define EXTI6PC6									((EXTI_GPIO_Mapping){GPIO_PIN6,GPIOC,EXTI_L6})
#define EXTI6PD6									((EXTI_GPIO_Mapping){GPIO_PIN6,GPIOD,EXTI_L6})

#define EXTI7PA7									((EXTI_GPIO_Mapping){GPIO_PIN7,GPIOA,EXTI_L7})
#define EXTI7PB7									((EXTI_GPIO_Mapping){GPIO_PIN7,GPIOB,EXTI_L7})
#define EXTI7PC7									((EXTI_GPIO_Mapping){GPIO_PIN7,GPIOC,EXTI_L7})
#define EXTI7PD7									((EXTI_GPIO_Mapping){GPIO_PIN7,GPIOD,EXTI_L7})

#define EXTI8PA8									((EXTI_GPIO_Mapping){GPIO_PIN8,GPIOA,EXTI_L8})
#define EXTI8PB8									((EXTI_GPIO_Mapping){GPIO_PIN8,GPIOB,EXTI_L8})
#define EXTI8PC8									((EXTI_GPIO_Mapping){GPIO_PIN8,GPIOC,EXTI_L8})
#define EXTI8PD8									((EXTI_GPIO_Mapping){GPIO_PIN8,GPIOD,EXTI_L8})

#define EXTI9PA9									((EXTI_GPIO_Mapping){GPIO_PIN9,GPIOA,EXTI_L9})
#define EXTI9PB9									((EXTI_GPIO_Mapping){GPIO_PIN9,GPIOB,EXTI_L9})
#define EXTI9PC9									((EXTI_GPIO_Mapping){GPIO_PIN9,GPIOC,EXTI_L9})
#define EXTI9PD9									((EXTI_GPIO_Mapping){GPIO_PIN9,GPIOD,EXTI_L9})

#define EXTI10PA10									((EXTI_GPIO_Mapping){GPIO_PIN10,GPIOA,EXTI_L10})
#define EXTI10PB10									((EXTI_GPIO_Mapping){GPIO_PIN10,GPIOB,EXTI_L10})
#define EXTI10PC10									((EXTI_GPIO_Mapping){GPIO_PIN10,GPIOC,EXTI_L10})
#define EXTI10PD10									((EXTI_GPIO_Mapping){GPIO_PIN10,GPIOD,EXTI_L10})

#define EXTI11PA11									((EXTI_GPIO_Mapping){GPIO_PIN11,GPIOA,EXTI_L11})
#define EXTI11PB11									((EXTI_GPIO_Mapping){GPIO_PIN11,GPIOB,EXTI_L11})
#define EXTI11PC11									((EXTI_GPIO_Mapping){GPIO_PIN11,GPIOC,EXTI_L11})
#define EXTI11PD11									((EXTI_GPIO_Mapping){GPIO_PIN11,GPIOD,EXTI_L11})

#define EXTI12PA12									((EXTI_GPIO_Mapping){GPIO_PIN12,GPIOA,EXTI_L12})
#define EXTI12PB12									((EXTI_GPIO_Mapping){GPIO_PIN12,GPIOB,EXTI_L12})
#define EXTI12PC12									((EXTI_GPIO_Mapping){GPIO_PIN12,GPIOC,EXTI_L12})
#define EXTI12PD12									((EXTI_GPIO_Mapping){GPIO_PIN12,GPIOD,EXTI_L12})

#define EXTI13PA13									((EXTI_GPIO_Mapping){GPIO_PIN13,GPIOA,EXTI_L13})
#define EXTI13PB13									((EXTI_GPIO_Mapping){GPIO_PIN13,GPIOB,EXTI_L13})
#define EXTI13PC13									((EXTI_GPIO_Mapping){GPIO_PIN13,GPIOC,EXTI_L13})
#define EXTI13PD13									((EXTI_GPIO_Mapping){GPIO_PIN13,GPIOD,EXTI_L13})

#define EXTI14PA14									((EXTI_GPIO_Mapping){GPIO_PIN14,GPIOA,EXTI_L14})
#define EXTI14PB14									((EXTI_GPIO_Mapping){GPIO_PIN14,GPIOB,EXTI_L14})
#define EXTI14PC14									((EXTI_GPIO_Mapping){GPIO_PIN14,GPIOC,EXTI_L14})
#define EXTI14PD14									((EXTI_GPIO_Mapping){GPIO_PIN14,GPIOD,EXTI_L14})

#define EXTI15PA15									((EXTI_GPIO_Mapping){GPIO_PIN15,GPIOA,EXTI_L15})
#define EXTI15PB15									((EXTI_GPIO_Mapping){GPIO_PIN15,GPIOB,EXTI_L15})
#define EXTI15PC15									((EXTI_GPIO_Mapping){GPIO_PIN15,GPIOC,EXTI_L15})
#define EXTI15PD15									((EXTI_GPIO_Mapping){GPIO_PIN15,GPIOD,EXTI_L15})

#define EXTI_L0										0
#define EXTI_L1										1
#define EXTI_L2										2
#define EXTI_L3										3
#define EXTI_L4										4
#define EXTI_L5										5
#define EXTI_L6										6
#define EXTI_L7										7
#define EXTI_L8										8
#define EXTI_L9										9
#define EXTI_L10									10
#define EXTI_L11									11
#define EXTI_L12									12
#define EXTI_L13									13
#define EXTI_L14									14
#define EXTI_L15									15

// @ref EXTI_TRIGGER_define

#define EXTI_FALLING										0
#define EXTI_RISING											1
#define EXTI_RISING_FALLING									2

// @ref EXTI_ENABLESTATE_define

#define  EXTI_DISABLE										0
#define  EXTI_ENABLE										1

// ====================================================================================================================
//										APIs Supported by "MCAL GPIO DRIVER"
// ====================================================================================================================

void MCAL_EXTI_init(EXTI_config * cfg);
void MCAL_EXTI_deInit(void);
void MCAL_EXTI_update(EXTI_config * cfg);



#endif /* INC_STM32F103C6_EXTI_DRIVER_H_ */
