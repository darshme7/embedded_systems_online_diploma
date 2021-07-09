/*
 * atmega32_gpio_driver.c
 *
 *  Created on: Jun 8, 2021
 *      Author: Mostafa
 */

#include "../inc/atmega32_gpio_driver.h"



/**================================================================
 * @Fn			-MCAL_GPIO_init.
 * @brief	    -initialize the GPIOx PINy according to config instance cfg.
 * @param [in] 	-GPIOx: x can be (A...D) to select the GPIO peripheral.
 * @param [in] 	-cfg: pointer to GPIO_config that contains pin/port configuration.
 * @retval 		-none
 * Note			-none
 */
void MCAL_GPIO_init(GPIO_typedef * GPIOx,GPIO_config * cfg){

	switch(cfg->GPIO_PinNumber){
	case GPIO_PIN0:{
		switch(cfg->GPIO_PinMode){
		case GPIO_MODE_INPUT_HiZ:{
			GPIOx->DDR.bits.DD0 = 0b0;
			GPIOx->PORT.bits.PORT0 = 0b0;
			break;
		}
		case GPIO_MODE_INPUT_PU:{
			GPIOx->DDR.bits.DD0 = 0b0;
			GPIOx->PORT.bits.PORT0 = 0b1;
			break;
		}
		case GPIO_MODE_OUTPUT_PP:{
			GPIOx->DDR.bits.DD0 = 0b1;
			GPIOx->PORT.bits.PORT0 = 0b0;
			break;
		}
		}
		break;
	}
	case GPIO_PIN1:{
		switch(cfg->GPIO_PinMode){
		case GPIO_MODE_INPUT_HiZ:{
			GPIOx->DDR.bits.DD1 = 0b0;
			GPIOx->PORT.bits.PORT1 = 0b0;
			break;
		}
		case GPIO_MODE_INPUT_PU:{
			GPIOx->DDR.bits.DD1 = 0b0;
			GPIOx->PORT.bits.PORT1 = 0b1;
			break;
		}
		case GPIO_MODE_OUTPUT_PP:{
			GPIOx->DDR.bits.DD1 = 0b1;
			GPIOx->PORT.bits.PORT1 = 0b0;
			break;
		}
		}
		break;
	}
	case GPIO_PIN2:{
		switch(cfg->GPIO_PinMode){
		case GPIO_MODE_INPUT_HiZ:{
			GPIOx->DDR.bits.DD2 = 0b0;
			GPIOx->PORT.bits.PORT2 = 0b0;
			break;
		}
		case GPIO_MODE_INPUT_PU:{
			GPIOx->DDR.bits.DD2 = 0b0;
			GPIOx->PORT.bits.PORT2 = 0b1;
			break;
		}
		case GPIO_MODE_OUTPUT_PP:{
			GPIOx->DDR.bits.DD2 = 0b1;
			GPIOx->PORT.bits.PORT2 = 0b0;
			break;
		}
		}
		break;
	}
	case GPIO_PIN3:{
		switch(cfg->GPIO_PinMode){
		case GPIO_MODE_INPUT_HiZ:{
			GPIOx->DDR.bits.DD3 = 0b0;
			GPIOx->PORT.bits.PORT3 = 0b0;
			break;
		}
		case GPIO_MODE_INPUT_PU:{
			GPIOx->DDR.bits.DD3 = 0b0;
			GPIOx->PORT.bits.PORT3 = 0b1;
			break;
		}
		case GPIO_MODE_OUTPUT_PP:{
			GPIOx->DDR.bits.DD3 = 0b1;
			GPIOx->PORT.bits.PORT3 = 0b0;
			break;
		}
		}
		break;
	}
	case GPIO_PIN4:{
		switch(cfg->GPIO_PinMode){
		case GPIO_MODE_INPUT_HiZ:{
			GPIOx->DDR.bits.DD4 = 0b0;
			GPIOx->PORT.bits.PORT4 = 0b0;
			break;
		}
		case GPIO_MODE_INPUT_PU:{
			GPIOx->DDR.bits.DD4 = 0b0;
			GPIOx->PORT.bits.PORT4 = 0b1;
			break;
		}
		case GPIO_MODE_OUTPUT_PP:{
			GPIOx->DDR.bits.DD4 = 0b1;
			GPIOx->PORT.bits.PORT4 = 0b0;
			break;
		}
		}
		break;
	}
	case GPIO_PIN5:{
		switch(cfg->GPIO_PinMode){
		case GPIO_MODE_INPUT_HiZ:{
			GPIOx->DDR.bits.DD5 = 0b0;
			GPIOx->PORT.bits.PORT5 = 0b0;
			break;
		}
		case GPIO_MODE_INPUT_PU:{
			GPIOx->DDR.bits.DD5 = 0b0;
			GPIOx->PORT.bits.PORT5 = 0b1;
			break;
		}
		case GPIO_MODE_OUTPUT_PP:{
			GPIOx->DDR.bits.DD5 = 0b1;
			GPIOx->PORT.bits.PORT5 = 0b0;
			break;
		}
		}
		break;
	}
	case GPIO_PIN6:{
		switch(cfg->GPIO_PinMode){
		case GPIO_MODE_INPUT_HiZ:{
			GPIOx->DDR.bits.DD6 = 0b0;
			GPIOx->PORT.bits.PORT6 = 0b0;
			break;
		}
		case GPIO_MODE_INPUT_PU:{
			GPIOx->DDR.bits.DD6 = 0b0;
			GPIOx->PORT.bits.PORT6 = 0b1;
			break;
		}
		case GPIO_MODE_OUTPUT_PP:{
			GPIOx->DDR.bits.DD6 = 0b1;
			GPIOx->PORT.bits.PORT6 = 0b0;
			break;
		}
		}
		break;
	}
	case GPIO_PIN7:{
		switch(cfg->GPIO_PinMode){
		case GPIO_MODE_INPUT_HiZ:{
			GPIOx->DDR.bits.DD7 = 0b0;
			GPIOx->PORT.bits.PORT7 = 0b0;
			break;
		}
		case GPIO_MODE_INPUT_PU:{
			GPIOx->DDR.bits.DD7 = 0b0;
			GPIOx->PORT.bits.PORT7 = 0b1;
			break;
		}
		case GPIO_MODE_OUTPUT_PP:{
			GPIOx->DDR.bits.DD7 = 0b1;
			GPIOx->PORT.bits.PORT7 = 0b0;
			break;
		}
		}
		break;
	}
	case GPIO_PORT:{
		switch(cfg->GPIO_PinMode){
		case GPIO_MODE_INPUT_HiZ:{
			GPIOx->DDR.DDR = 0x00;
			GPIOx->PORT.PORT = 0x00;
			break;
		}
		case GPIO_MODE_INPUT_PU:{
			GPIOx->DDR.DDR = 0x00;
			GPIOx->PORT.PORT = 0xFF;
			break;
		}
		case GPIO_MODE_OUTPUT_PP:{
			GPIOx->DDR.DDR = 0xFF;
			GPIOx->PORT.PORT = 0x00;
			break;
		}
		}
		break;
	}
	}
}

/**================================================================
 * @Fn			-MCAL_GPIO_deinit.
 * @brief	    -Reset the GPIOx registers.
 * @param [in] 	-GPIOx: x can be (A...D) to select the GPIO peripheral.
 * @retval 		-none
 * Note			-none
 */
void MCAL_GPIO_deinit(GPIO_typedef * GPIOx){

	GPIOx->DDR.DDR = 0x00;
	GPIOx->PORT.PORT =0x00;
}

/**================================================================
 * @Fn			-MCAL_GPIO_readPin.
 * @brief	    -Reads the GPIOx PINy input value.
 * @param [in] 	-GPIOx: x can be (A...D) to select the GPIO peripheral.
 * @param [in] 	-PinNumber: Specifies the PIN to be read.
 * @retval 		-either one of two states check: @ref GPIO_PIN_STATE_define
 * Note			-none
 */

uint8 MCAL_GPIO_readPin(GPIO_typedef * GPIOx,uint8 PinNumber ){

	uint8 PinState=0;
	switch(PinNumber){
	case GPIO_PIN0:{
		PinState = (uint8)(GPIOx->PIN.bits.PIN0);
		break;
	}
	case GPIO_PIN1:{
		PinState = (uint8)(GPIOx->PIN.bits.PIN1);
		break;
	}
	case GPIO_PIN2:{
		PinState = (uint8)(GPIOx->PIN.bits.PIN2);
		break;
	}
	case GPIO_PIN3:{
		PinState = (uint8)(GPIOx->PIN.bits.PIN3);
		break;
	}
	case GPIO_PIN4:{
		PinState = (uint8)(GPIOx->PIN.bits.PIN4);
		break;
	}
	case GPIO_PIN5:{
		PinState = (uint8)(GPIOx->PIN.bits.PIN5);
		break;
	}
	case GPIO_PIN6:{
		PinState = (uint8)(GPIOx->PIN.bits.PIN6);
		break;
	}
	case GPIO_PIN7:{
		PinState = (uint8)(GPIOx->PIN.bits.PIN7);
		break;
	}}
	return PinState;
}


/**================================================================
 * @Fn			-MCAL_GPIO_readPort.
 * @brief	    -Reads the GPIOx input value.
 * @param [in] 	-GPIOx: x can be (A...D) to select the GPIO peripheral.
 * @retval 		-the input value on GPIOx
 * Note			-none
 */

uint8 MCAL_GPIO_readPort(GPIO_typedef * GPIOx){

	uint8 PortState = 0x00;
	PortState = (uint8)(GPIOx->PIN.PIN);
	return PortState;
}

/**================================================================
 * @Fn			-MCAL_GPIO_writePin.
 * @brief	    -writes either one of @ref GPIO_PIN_STATE_define value on the GPIOx PINy.
 * @param [in] 	-GPIOx: x can be (A...D) to select the GPIO peripheral.
 * @param [in] 	-PinNumber: Specifies the PIN to be read.
 * @param [in]  -data: Specifies one of @ref GPIO_PIN_STATE_define to be written.
 * @retval 		-none
 * Note			-none
 */

void MCAL_GPIO_writePin(GPIO_typedef * GPIOx,uint8 PinNumber,uint8 data ){

	switch(PinNumber){
	case GPIO_PIN0:{
		if(data)
			GPIOx->PORT.bits.PORT0 = 0b1;
		else
			GPIOx->PORT.bits.PORT0 = 0b0;
		break;
	}
	case GPIO_PIN1:{
		if(data)
			GPIOx->PORT.bits.PORT1 = 0b1;
		else
			GPIOx->PORT.bits.PORT1 = 0b0;
		break;
	}
	case GPIO_PIN2:{
		if(data)
			GPIOx->PORT.bits.PORT2 = 0b1;
		else
			GPIOx->PORT.bits.PORT2 = 0b0;
		break;
	}
	case GPIO_PIN3:{
		if(data)
			GPIOx->PORT.bits.PORT3 = 0b1;
		else
			GPIOx->PORT.bits.PORT3 = 0b0;
		break;
	}
	case GPIO_PIN4:{
		if(data)
			GPIOx->PORT.bits.PORT4 = 0b1;
		else
			GPIOx->PORT.bits.PORT4 = 0b0;
		break;
	}
	case GPIO_PIN5:{
		if(data)
			GPIOx->PORT.bits.PORT5 = 0b1;
		else
			GPIOx->PORT.bits.PORT5 = 0b0;
		break;
	}
	case GPIO_PIN6:{
		if(data)
			GPIOx->PORT.bits.PORT6 = 0b1;
		else
			GPIOx->PORT.bits.PORT6 = 0b0;
		break;
	}
	case GPIO_PIN7:{
		if(data)
			GPIOx->PORT.bits.PORT7 = 0b1;
		else
			GPIOx->PORT.bits.PORT7 = 0b0;
		break;
	}}
}

/**================================================================
 * @Fn			-MCAL_GPIO_writePort.
 * @brief	    -writes data on the GPIOx.
 * @param [in] 	-GPIOx: x can be (A...D) to select the GPIO peripheral.
 * @param [in] 	-data: Specifies the data to be written.
 * @retval 		-none
 * Note			-none
 */

void MCAL_GPIO_writePort(GPIO_typedef * GPIOx,uint8 data ){

	GPIOx->PORT.PORT = data;
}

/**================================================================
 * @Fn			-MCAL_GPIO_togglePin.
 * @brief	    -toggle the GPIOx PINy .
 * @param [in] 	-GPIOx: x can be (A...D) to select the GPIO peripheral.
 * @param [in] 	-PinNumber: Specifies the PIN to be toggled.
 * @retval 		-none
 * Note			-none
 */

void MCAL_GPIO_togglePin(GPIO_typedef * GPIOx,uint8 PinNumber){

	switch(PinNumber){
	case GPIO_PIN0:{
		GPIOx->PORT.bits.PORT0 ^= 0b1;
		break;
	}
	case GPIO_PIN1:{
		GPIOx->PORT.bits.PORT1 ^= 0b1;
		break;
	}
	case GPIO_PIN2:{
		GPIOx->PORT.bits.PORT2 ^= 0b1;
		break;
	}
	case GPIO_PIN3:{
		GPIOx->PORT.bits.PORT3 ^= 0b1;
		break;
	}
	case GPIO_PIN4:{
		GPIOx->PORT.bits.PORT4 ^= 0b1;
		break;
	}
	case GPIO_PIN5:{
		GPIOx->PORT.bits.PORT5 ^= 0b1;
		break;
	}
	case GPIO_PIN6:{
		GPIOx->PORT.bits.PORT6 ^= 0b1;
		break;
	}
	case GPIO_PIN7:{
		GPIOx->PORT.bits.PORT7 ^= 0b1;
		break;
	}}
}
