/*
 * stm32f103c8_gpio_driver.c
 *
 *  Created on: May 31, 2021
 *      Author: mosta
 */

#include "stm32f103c8_gpio_driver.h"




/**================================================================
 * @Fn			-MCAL_GPIO_deinit.
 * @brief	    -initialize the GPIOx PINy according to Config instance cfg.
 * @param [in] 	-GPIOx: x can be (A...E) to select the GPIO peripheral.
 * @param [in] 	-cfg: pointer to GPIO_config that contains pin/port confiquration.
 * @retval 		-none
 * Note			-none
 */

void MCAL_GPIO_init(GPIO_typedef * GPIOx,GPIO_config * cfg){
	switch(cfg->GPIO_PinNumber){
	case GPIO_PIN0:
		if(cfg->GPIO_OutputSpeed == GPIO_SPEED_10M)
			GPIOx->CRL.bits.MODE0 = 0b01;
		else if(cfg->GPIO_OutputSpeed == GPIO_SPEED_2M)
			GPIOx->CRL.bits.MODE0 = 0b010;
		else if(cfg->GPIO_OutputSpeed == GPIO_SPEED_50M)
			GPIOx->CRL.bits.MODE0 = 0b11;
		if(cfg->GPIO_PinMode ==GPIO_MODE_ANALOG||cfg->GPIO_PinMode ==GPIO_MODE_INPUT_FLO||cfg->GPIO_PinMode ==GPIO_MODE_INPUT_PU||cfg->GPIO_PinMode ==GPIO_MODE_INPUT_PD)
			GPIOx->CRL.bits.MODE0 = 0b00;

		switch(cfg->GPIO_PinMode){
		case GPIO_MODE_ANALOG:
			GPIOx->CRL.bits.CNF0 = 0b00;
			break;
		case GPIO_MODE_INPUT_FLO:
			GPIOx->CRL.bits.CNF0 = 0b01;
			break;
		case GPIO_MODE_INPUT_PU:
			GPIOx->CRL.bits.CNF0 = 0b10;
			GPIOx->BSRR.bits.BS0 = 0b1;
			break;
		case GPIO_MODE_INPUT_PD:
			GPIOx->CRL.bits.CNF0 = 0b10;
			GPIOx->BRR.bits.BR0  = 0b1;
			break;
		case GPIO_MODE_OUTPUT_PP:
			GPIOx->CRL.bits.CNF0 = 0b00;
			break;
		case GPIO_MODE_OUTPUT_OD:
			GPIOx->CRL.bits.CNF0 = 0b01;
			break;
		case GPIO_MODE_OUTPUT_AF_PP:
			GPIOx->CRL.bits.CNF0 = 0b10;
			break;
		case GPIO_MODE_OUTPUT_AF_OD:
			GPIOx->CRL.bits.CNF0 = 0b11;
			break;
		}
		break;

	case GPIO_PIN1:
		if(cfg->GPIO_OutputSpeed == GPIO_SPEED_10M)
			GPIOx->CRL.bits.MODE1 = 0b01;
		else if(cfg->GPIO_OutputSpeed == GPIO_SPEED_2M)
			GPIOx->CRL.bits.MODE1 = 0b010;
		else if(cfg->GPIO_OutputSpeed == GPIO_SPEED_50M)
			GPIOx->CRL.bits.MODE1 = 0b11;
		if(cfg->GPIO_PinMode ==GPIO_MODE_ANALOG||cfg->GPIO_PinMode ==GPIO_MODE_INPUT_FLO||cfg->GPIO_PinMode ==GPIO_MODE_INPUT_PU||cfg->GPIO_PinMode ==GPIO_MODE_INPUT_PD)
			GPIOx->CRL.bits.MODE1 = 0b00;

		switch(cfg->GPIO_PinMode){
		case GPIO_MODE_ANALOG:
			GPIOx->CRL.bits.CNF1 = 0b00;
			break;
		case GPIO_MODE_INPUT_FLO:
			GPIOx->CRL.bits.CNF1 = 0b01;
			break;
		case GPIO_MODE_INPUT_PU:
			GPIOx->CRL.bits.CNF1 = 0b10;
			GPIOx->BSRR.bits.BS1 = 0b1;
			break;
		case GPIO_MODE_INPUT_PD:
			GPIOx->CRL.bits.CNF1 = 0b10;
			GPIOx->BRR.bits.BR1  = 0b1;
			break;
		case GPIO_MODE_OUTPUT_PP:
			GPIOx->CRL.bits.CNF1 = 0b00;
			break;
		case GPIO_MODE_OUTPUT_OD:
			GPIOx->CRL.bits.CNF1 = 0b01;
			break;
		case GPIO_MODE_OUTPUT_AF_PP:
			GPIOx->CRL.bits.CNF1 = 0b10;
			break;
		case GPIO_MODE_OUTPUT_AF_OD:
			GPIOx->CRL.bits.CNF1 = 0b11;
			break;
		}
		break;
	case GPIO_PIN2:
		if(cfg->GPIO_OutputSpeed == GPIO_SPEED_10M)
			GPIOx->CRL.bits.MODE2 = 0b01;
		else if(cfg->GPIO_OutputSpeed == GPIO_SPEED_2M)
			GPIOx->CRL.bits.MODE2 = 0b010;
		else if(cfg->GPIO_OutputSpeed == GPIO_SPEED_50M)
			GPIOx->CRL.bits.MODE2 = 0b11;
		if(cfg->GPIO_PinMode ==GPIO_MODE_ANALOG||cfg->GPIO_PinMode ==GPIO_MODE_INPUT_FLO||cfg->GPIO_PinMode ==GPIO_MODE_INPUT_PU||cfg->GPIO_PinMode ==GPIO_MODE_INPUT_PD)
			GPIOx->CRL.bits.MODE2 = 0b00;

		switch(cfg->GPIO_PinMode){
		case GPIO_MODE_ANALOG:
			GPIOx->CRL.bits.CNF2 = 0b00;
			break;
		case GPIO_MODE_INPUT_FLO:
			GPIOx->CRL.bits.CNF2 = 0b01;
			break;
		case GPIO_MODE_INPUT_PU:
			GPIOx->CRL.bits.CNF2 = 0b10;
			GPIOx->BSRR.bits.BS2 = 0b1;
			break;
		case GPIO_MODE_INPUT_PD:
			GPIOx->CRL.bits.CNF2 = 0b10;
			GPIOx->BRR.bits.BR2  = 0b1;
			break;
		case GPIO_MODE_OUTPUT_PP:
			GPIOx->CRL.bits.CNF2 = 0b00;
			break;
		case GPIO_MODE_OUTPUT_OD:
			GPIOx->CRL.bits.CNF2 = 0b01;
			break;
		case GPIO_MODE_OUTPUT_AF_PP:
			GPIOx->CRL.bits.CNF2 = 0b10;
			break;
		case GPIO_MODE_OUTPUT_AF_OD:
			GPIOx->CRL.bits.CNF2 = 0b11;
			break;
		}
		break;

	case GPIO_PIN3:
		if(cfg->GPIO_OutputSpeed == GPIO_SPEED_10M)
			GPIOx->CRL.bits.MODE3 = 0b01;
		else if(cfg->GPIO_OutputSpeed == GPIO_SPEED_2M)
			GPIOx->CRL.bits.MODE3 = 0b010;
		else if(cfg->GPIO_OutputSpeed == GPIO_SPEED_50M)
			GPIOx->CRL.bits.MODE3 = 0b11;
		if(cfg->GPIO_PinMode ==GPIO_MODE_ANALOG||cfg->GPIO_PinMode ==GPIO_MODE_INPUT_FLO||cfg->GPIO_PinMode ==GPIO_MODE_INPUT_PU||cfg->GPIO_PinMode ==GPIO_MODE_INPUT_PD)
			GPIOx->CRL.bits.MODE3 = 0b00;

		switch(cfg->GPIO_PinMode){
		case GPIO_MODE_ANALOG:
			GPIOx->CRL.bits.CNF3 = 0b00;
			break;
		case GPIO_MODE_INPUT_FLO:
			GPIOx->CRL.bits.CNF3 = 0b01;
			break;
		case GPIO_MODE_INPUT_PU:
			GPIOx->CRL.bits.CNF3 = 0b10;
			GPIOx->BSRR.bits.BS3 = 0b1;
			break;
		case GPIO_MODE_INPUT_PD:
			GPIOx->CRL.bits.CNF3 = 0b10;
			GPIOx->BRR.bits.BR3  = 0b1;
			break;
		case GPIO_MODE_OUTPUT_PP:
			GPIOx->CRL.bits.CNF3 = 0b00;
			break;
		case GPIO_MODE_OUTPUT_OD:
			GPIOx->CRL.bits.CNF3 = 0b01;
			break;
		case GPIO_MODE_OUTPUT_AF_PP:
			GPIOx->CRL.bits.CNF3 = 0b10;
			break;
		case GPIO_MODE_OUTPUT_AF_OD:
			GPIOx->CRL.bits.CNF3 = 0b11;
			break;
		}
		break;

	case GPIO_PIN4:
		if(cfg->GPIO_OutputSpeed == GPIO_SPEED_10M)
			GPIOx->CRL.bits.MODE4 = 0b01;
		else if(cfg->GPIO_OutputSpeed == GPIO_SPEED_2M)
			GPIOx->CRL.bits.MODE4 = 0b010;
		else if(cfg->GPIO_OutputSpeed == GPIO_SPEED_50M)
			GPIOx->CRL.bits.MODE4 = 0b11;
		if(cfg->GPIO_PinMode ==GPIO_MODE_ANALOG||cfg->GPIO_PinMode ==GPIO_MODE_INPUT_FLO||cfg->GPIO_PinMode ==GPIO_MODE_INPUT_PU||cfg->GPIO_PinMode ==GPIO_MODE_INPUT_PD)
			GPIOx->CRL.bits.MODE4 = 0b00;

		switch(cfg->GPIO_PinMode){
		case GPIO_MODE_ANALOG:
			GPIOx->CRL.bits.CNF4 = 0b00;
			break;
		case GPIO_MODE_INPUT_FLO:
			GPIOx->CRL.bits.CNF4 = 0b01;
			break;
		case GPIO_MODE_INPUT_PU:
			GPIOx->CRL.bits.CNF4 = 0b10;
			GPIOx->BSRR.bits.BS4 = 0b1;
			break;
		case GPIO_MODE_INPUT_PD:
			GPIOx->CRL.bits.CNF4 = 0b10;
			GPIOx->BRR.bits.BR4  = 0b1;
			break;
		case GPIO_MODE_OUTPUT_PP:
			GPIOx->CRL.bits.CNF4 = 0b00;
			break;
		case GPIO_MODE_OUTPUT_OD:
			GPIOx->CRL.bits.CNF4 = 0b01;
			break;
		case GPIO_MODE_OUTPUT_AF_PP:
			GPIOx->CRL.bits.CNF4 = 0b10;
			break;
		case GPIO_MODE_OUTPUT_AF_OD:
			GPIOx->CRL.bits.CNF4 = 0b11;
			break;
		}
		break;

	case GPIO_PIN5:
		if(cfg->GPIO_OutputSpeed == GPIO_SPEED_10M)
			GPIOx->CRL.bits.MODE5 = 0b01;
		else if(cfg->GPIO_OutputSpeed == GPIO_SPEED_2M)
			GPIOx->CRL.bits.MODE5 = 0b010;
		else if(cfg->GPIO_OutputSpeed == GPIO_SPEED_50M)
			GPIOx->CRL.bits.MODE5 = 0b11;
		if(cfg->GPIO_PinMode ==GPIO_MODE_ANALOG||cfg->GPIO_PinMode ==GPIO_MODE_INPUT_FLO||cfg->GPIO_PinMode ==GPIO_MODE_INPUT_PU||cfg->GPIO_PinMode ==GPIO_MODE_INPUT_PD)
			GPIOx->CRL.bits.MODE5 = 0b00;

		switch(cfg->GPIO_PinMode){
		case GPIO_MODE_ANALOG:
			GPIOx->CRL.bits.CNF5 = 0b00;
			break;
		case GPIO_MODE_INPUT_FLO:
			GPIOx->CRL.bits.CNF5 = 0b01;
			break;
		case GPIO_MODE_INPUT_PU:
			GPIOx->CRL.bits.CNF5 = 0b10;
			GPIOx->BSRR.bits.BS5 = 0b1;
			break;
		case GPIO_MODE_INPUT_PD:
			GPIOx->CRL.bits.CNF5 = 0b10;
			GPIOx->BRR.bits.BR5  = 0b1;
			break;
		case GPIO_MODE_OUTPUT_PP:
			GPIOx->CRL.bits.CNF5 = 0b00;
			break;
		case GPIO_MODE_OUTPUT_OD:
			GPIOx->CRL.bits.CNF5 = 0b01;
			break;
		case GPIO_MODE_OUTPUT_AF_PP:
			GPIOx->CRL.bits.CNF5 = 0b10;
			break;
		case GPIO_MODE_OUTPUT_AF_OD:
			GPIOx->CRL.bits.CNF5 = 0b11;
			break;
		}
		break;

	case GPIO_PIN6:
		if(cfg->GPIO_OutputSpeed == GPIO_SPEED_10M)
			GPIOx->CRL.bits.MODE6 = 0b01;
		else if(cfg->GPIO_OutputSpeed == GPIO_SPEED_2M)
			GPIOx->CRL.bits.MODE6 = 0b010;
		else if(cfg->GPIO_OutputSpeed == GPIO_SPEED_50M)
			GPIOx->CRL.bits.MODE6 = 0b11;
		if(cfg->GPIO_PinMode ==GPIO_MODE_ANALOG||cfg->GPIO_PinMode ==GPIO_MODE_INPUT_FLO||cfg->GPIO_PinMode ==GPIO_MODE_INPUT_PU||cfg->GPIO_PinMode ==GPIO_MODE_INPUT_PD)
			GPIOx->CRL.bits.MODE6 = 0b00;

		switch(cfg->GPIO_PinMode){
		case GPIO_MODE_ANALOG:
			GPIOx->CRL.bits.CNF6 = 0b00;
			break;
		case GPIO_MODE_INPUT_FLO:
			GPIOx->CRL.bits.CNF6 = 0b01;
			break;
		case GPIO_MODE_INPUT_PU:
			GPIOx->CRL.bits.CNF6 = 0b10;
			GPIOx->BSRR.bits.BS6 = 0b1;
			break;
		case GPIO_MODE_INPUT_PD:
			GPIOx->CRL.bits.CNF6 = 0b10;
			GPIOx->BRR.bits.BR6  = 0b1;
			break;
		case GPIO_MODE_OUTPUT_PP:
			GPIOx->CRL.bits.CNF6 = 0b00;
			break;
		case GPIO_MODE_OUTPUT_OD:
			GPIOx->CRL.bits.CNF6 = 0b01;
			break;
		case GPIO_MODE_OUTPUT_AF_PP:
			GPIOx->CRL.bits.CNF6 = 0b10;
			break;
		case GPIO_MODE_OUTPUT_AF_OD:
			GPIOx->CRL.bits.CNF6 = 0b11;
			break;
		}
		break;

	case GPIO_PIN7:
		if(cfg->GPIO_OutputSpeed == GPIO_SPEED_10M)
			GPIOx->CRL.bits.MODE7 = 0b01;
		else if(cfg->GPIO_OutputSpeed == GPIO_SPEED_2M)
			GPIOx->CRL.bits.MODE7 = 0b010;
		else if(cfg->GPIO_OutputSpeed == GPIO_SPEED_50M)
			GPIOx->CRL.bits.MODE7 = 0b11;
		if(cfg->GPIO_PinMode ==GPIO_MODE_ANALOG||cfg->GPIO_PinMode ==GPIO_MODE_INPUT_FLO||cfg->GPIO_PinMode ==GPIO_MODE_INPUT_PU||cfg->GPIO_PinMode ==GPIO_MODE_INPUT_PD)
			GPIOx->CRL.bits.MODE7 = 0b00;

		switch(cfg->GPIO_PinMode){
		case GPIO_MODE_ANALOG:
			GPIOx->CRL.bits.CNF7 = 0b00;
			break;
		case GPIO_MODE_INPUT_FLO:
			GPIOx->CRL.bits.CNF7 = 0b01;
			break;
		case GPIO_MODE_INPUT_PU:
			GPIOx->CRL.bits.CNF7 = 0b10;
			GPIOx->BSRR.bits.BS7 = 0b1;
			break;
		case GPIO_MODE_INPUT_PD:
			GPIOx->CRL.bits.CNF7 = 0b10;
			GPIOx->BRR.bits.BR7  = 0b1;
			break;
		case GPIO_MODE_OUTPUT_PP:
			GPIOx->CRL.bits.CNF7 = 0b00;
			break;
		case GPIO_MODE_OUTPUT_OD:
			GPIOx->CRL.bits.CNF7 = 0b01;
			break;
		case GPIO_MODE_OUTPUT_AF_PP:
			GPIOx->CRL.bits.CNF7 = 0b10;
			break;
		case GPIO_MODE_OUTPUT_AF_OD:
			GPIOx->CRL.bits.CNF7 = 0b11;
			break;
		}
		break;
	case GPIO_PIN8:
		if(cfg->GPIO_OutputSpeed == GPIO_SPEED_10M)
			GPIOx->CRH.bits.MODE8 = 0b01;
		else if(cfg->GPIO_OutputSpeed == GPIO_SPEED_2M)
			GPIOx->CRH.bits.MODE8 = 0b010;
		else if(cfg->GPIO_OutputSpeed == GPIO_SPEED_50M)
			GPIOx->CRH.bits.MODE8 = 0b11;
		if(cfg->GPIO_PinMode ==GPIO_MODE_ANALOG||cfg->GPIO_PinMode ==GPIO_MODE_INPUT_FLO||cfg->GPIO_PinMode ==GPIO_MODE_INPUT_PU||cfg->GPIO_PinMode ==GPIO_MODE_INPUT_PD)
			GPIOx->CRH.bits.MODE8 = 0b00;

		switch(cfg->GPIO_PinMode){
		case GPIO_MODE_ANALOG:
			GPIOx->CRH.bits.CNF8 = 0b00;
			break;
		case GPIO_MODE_INPUT_FLO:
			GPIOx->CRH.bits.CNF8 = 0b01;
			break;
		case GPIO_MODE_INPUT_PU:
			GPIOx->CRH.bits.CNF8 = 0b10;
			GPIOx->BSRR.bits.BS8 = 0b1;
			break;
		case GPIO_MODE_INPUT_PD:
			GPIOx->CRH.bits.CNF8 = 0b10;
			GPIOx->BRR.bits.BR8  = 0b1;
			break;
		case GPIO_MODE_OUTPUT_PP:
			GPIOx->CRH.bits.CNF8 = 0b00;
			break;
		case GPIO_MODE_OUTPUT_OD:
			GPIOx->CRH.bits.CNF8 = 0b01;
			break;
		case GPIO_MODE_OUTPUT_AF_PP:
			GPIOx->CRH.bits.CNF8 = 0b10;
			break;
		case GPIO_MODE_OUTPUT_AF_OD:
			GPIOx->CRH.bits.CNF8 = 0b11;
			break;
		}
		break;
	case GPIO_PIN9:
		if(cfg->GPIO_OutputSpeed == GPIO_SPEED_10M)
			GPIOx->CRH.bits.MODE9 = 0b01;
		else if(cfg->GPIO_OutputSpeed == GPIO_SPEED_2M)
			GPIOx->CRH.bits.MODE9 = 0b010;
		else if(cfg->GPIO_OutputSpeed == GPIO_SPEED_50M)
			GPIOx->CRH.bits.MODE9 = 0b11;
		if(cfg->GPIO_PinMode ==GPIO_MODE_ANALOG||cfg->GPIO_PinMode ==GPIO_MODE_INPUT_FLO||cfg->GPIO_PinMode ==GPIO_MODE_INPUT_PU||cfg->GPIO_PinMode ==GPIO_MODE_INPUT_PD)
			GPIOx->CRH.bits.MODE9 = 0b00;

		switch(cfg->GPIO_PinMode){
		case GPIO_MODE_ANALOG:
			GPIOx->CRH.bits.CNF9 = 0b00;
			break;
		case GPIO_MODE_INPUT_FLO:
			GPIOx->CRH.bits.CNF9 = 0b01;
			break;
		case GPIO_MODE_INPUT_PU:
			GPIOx->CRH.bits.CNF9 = 0b10;
			GPIOx->BSRR.bits.BS9 = 0b1;
			break;
		case GPIO_MODE_INPUT_PD:
			GPIOx->CRH.bits.CNF9 = 0b10;
			GPIOx->BRR.bits.BR9 = 0b1;
			break;
		case GPIO_MODE_OUTPUT_PP:
			GPIOx->CRH.bits.CNF9 = 0b00;
			break;
		case GPIO_MODE_OUTPUT_OD:
			GPIOx->CRH.bits.CNF9 = 0b01;
			break;
		case GPIO_MODE_OUTPUT_AF_PP:
			GPIOx->CRH.bits.CNF9 = 0b10;
			break;
		case GPIO_MODE_OUTPUT_AF_OD:
			GPIOx->CRH.bits.CNF9 = 0b11;
			break;
		}
		break;
	case GPIO_PIN10:
		if(cfg->GPIO_OutputSpeed == GPIO_SPEED_10M)
			GPIOx->CRH.bits.MODE10 = 0b01;
		else if(cfg->GPIO_OutputSpeed == GPIO_SPEED_2M)
			GPIOx->CRH.bits.MODE10 = 0b010;
		else if(cfg->GPIO_OutputSpeed == GPIO_SPEED_50M)
			GPIOx->CRH.bits.MODE10 = 0b11;
		if(cfg->GPIO_PinMode ==GPIO_MODE_ANALOG||cfg->GPIO_PinMode ==GPIO_MODE_INPUT_FLO||cfg->GPIO_PinMode ==GPIO_MODE_INPUT_PU||cfg->GPIO_PinMode ==GPIO_MODE_INPUT_PD)
			GPIOx->CRH.bits.MODE10 = 0b00;

		switch(cfg->GPIO_PinMode){
		case GPIO_MODE_ANALOG:
			GPIOx->CRH.bits.CNF10 = 0b00;
			break;
		case GPIO_MODE_INPUT_FLO:
			GPIOx->CRH.bits.CNF10 = 0b01;
			break;
		case GPIO_MODE_INPUT_PU:
			GPIOx->CRH.bits.CNF10 = 0b10;
			GPIOx->BSRR.bits.BS10 = 0b1;
			break;
		case GPIO_MODE_INPUT_PD:
			GPIOx->CRH.bits.CNF10 = 0b10;
			GPIOx->BRR.bits.BR10 = 0b1;
			break;
		case GPIO_MODE_OUTPUT_PP:
			GPIOx->CRH.bits.CNF10 = 0b00;
			break;
		case GPIO_MODE_OUTPUT_OD:
			GPIOx->CRH.bits.CNF10 = 0b01;
			break;
		case GPIO_MODE_OUTPUT_AF_PP:
			GPIOx->CRH.bits.CNF10 = 0b10;
			break;
		case GPIO_MODE_OUTPUT_AF_OD:
			GPIOx->CRH.bits.CNF10 = 0b11;
			break;
		}
		break;

		case GPIO_PIN11:
			if(cfg->GPIO_OutputSpeed == GPIO_SPEED_10M)
				GPIOx->CRH.bits.MODE11 = 0b01;
			else if(cfg->GPIO_OutputSpeed == GPIO_SPEED_2M)
				GPIOx->CRH.bits.MODE11 = 0b010;
			else if(cfg->GPIO_OutputSpeed == GPIO_SPEED_50M)
				GPIOx->CRH.bits.MODE11 = 0b11;
			if(cfg->GPIO_PinMode ==GPIO_MODE_ANALOG||cfg->GPIO_PinMode ==GPIO_MODE_INPUT_FLO||cfg->GPIO_PinMode ==GPIO_MODE_INPUT_PU||cfg->GPIO_PinMode ==GPIO_MODE_INPUT_PD)
				GPIOx->CRH.bits.MODE11 = 0b00;

			switch(cfg->GPIO_PinMode){
			case GPIO_MODE_ANALOG:
				GPIOx->CRH.bits.CNF11 = 0b00;
				break;
			case GPIO_MODE_INPUT_FLO:
				GPIOx->CRH.bits.CNF11 = 0b01;
				break;
			case GPIO_MODE_INPUT_PU:
				GPIOx->CRH.bits.CNF11 = 0b10;
				GPIOx->BSRR.bits.BS11 = 0b1;
				break;
			case GPIO_MODE_INPUT_PD:
				GPIOx->CRH.bits.CNF11 = 0b10;
				GPIOx->BRR.bits.BR11  = 0b1;
				break;
			case GPIO_MODE_OUTPUT_PP:
				GPIOx->CRH.bits.CNF11 = 0b00;
				break;
			case GPIO_MODE_OUTPUT_OD:
				GPIOx->CRH.bits.CNF11 = 0b01;
				break;
			case GPIO_MODE_OUTPUT_AF_PP:
				GPIOx->CRH.bits.CNF11 = 0b10;
				break;
			case GPIO_MODE_OUTPUT_AF_OD:
				GPIOx->CRH.bits.CNF11 = 0b11;
				break;
			}
			break;
	case GPIO_PIN12:
		if(cfg->GPIO_OutputSpeed == GPIO_SPEED_10M)
			GPIOx->CRH.bits.MODE12 = 0b01;
		else if(cfg->GPIO_OutputSpeed == GPIO_SPEED_2M)
			GPIOx->CRH.bits.MODE12 = 0b010;
		else if(cfg->GPIO_OutputSpeed == GPIO_SPEED_50M)
			GPIOx->CRH.bits.MODE12 = 0b11;
		if(cfg->GPIO_PinMode ==GPIO_MODE_ANALOG||cfg->GPIO_PinMode ==GPIO_MODE_INPUT_FLO||cfg->GPIO_PinMode ==GPIO_MODE_INPUT_PU||cfg->GPIO_PinMode ==GPIO_MODE_INPUT_PD)
			GPIOx->CRH.bits.MODE12 = 0b00;

		switch(cfg->GPIO_PinMode){
		case GPIO_MODE_ANALOG:
			GPIOx->CRH.bits.CNF12 = 0b00;
			break;
		case GPIO_MODE_INPUT_FLO:
			GPIOx->CRH.bits.CNF12 = 0b01;
			break;
		case GPIO_MODE_INPUT_PU:
			GPIOx->CRH.bits.CNF12 = 0b10;
			GPIOx->BSRR.bits.BS12 = 0b1;
			break;
		case GPIO_MODE_INPUT_PD:
			GPIOx->CRH.bits.CNF12 = 0b10;
			GPIOx->BRR.bits.BR12  = 0b1;
			break;
		case GPIO_MODE_OUTPUT_PP:
			GPIOx->CRH.bits.CNF12 = 0b00;
			break;
		case GPIO_MODE_OUTPUT_OD:
			GPIOx->CRH.bits.CNF12 = 0b01;
			break;
		case GPIO_MODE_OUTPUT_AF_PP:
			GPIOx->CRH.bits.CNF12 = 0b10;
			break;
		case GPIO_MODE_OUTPUT_AF_OD:
			GPIOx->CRH.bits.CNF12 = 0b11;
			break;
		}
		break;
		case GPIO_PIN13:
			if(cfg->GPIO_OutputSpeed == GPIO_SPEED_10M)
				GPIOx->CRH.bits.MODE13 = 0b01;
			else if(cfg->GPIO_OutputSpeed == GPIO_SPEED_2M)
				GPIOx->CRH.bits.MODE13 = 0b010;
			else if(cfg->GPIO_OutputSpeed == GPIO_SPEED_50M)
				GPIOx->CRH.bits.MODE13 = 0b11;
			if(cfg->GPIO_PinMode ==GPIO_MODE_ANALOG||cfg->GPIO_PinMode ==GPIO_MODE_INPUT_FLO||cfg->GPIO_PinMode ==GPIO_MODE_INPUT_PU||cfg->GPIO_PinMode ==GPIO_MODE_INPUT_PD)
				GPIOx->CRH.bits.MODE13 = 0b00;

			switch(cfg->GPIO_PinMode){
			case GPIO_MODE_ANALOG:
				GPIOx->CRH.bits.CNF13 = 0b00;
				break;
			case GPIO_MODE_INPUT_FLO:
				GPIOx->CRH.bits.CNF13 = 0b01;
				break;
			case GPIO_MODE_INPUT_PU:
				GPIOx->CRH.bits.CNF13 = 0b10;
				GPIOx->BSRR.bits.BS13 = 0b1;
				break;
			case GPIO_MODE_INPUT_PD:
				GPIOx->CRH.bits.CNF13 = 0b10;
				GPIOx->BRR.bits.BR13 = 0b1;
				break;
			case GPIO_MODE_OUTPUT_PP:
				GPIOx->CRH.bits.CNF13 = 0b00;
				break;
			case GPIO_MODE_OUTPUT_OD:
				GPIOx->CRH.bits.CNF13 = 0b01;
				break;
			case GPIO_MODE_OUTPUT_AF_PP:
				GPIOx->CRH.bits.CNF13 = 0b10;
				break;
			case GPIO_MODE_OUTPUT_AF_OD:
				GPIOx->CRH.bits.CNF13 = 0b11;
				break;
			}
			break;

	case GPIO_PIN14:
		if(cfg->GPIO_OutputSpeed == GPIO_SPEED_10M)
			GPIOx->CRH.bits.MODE14 = 0b01;
		else if(cfg->GPIO_OutputSpeed == GPIO_SPEED_2M)
			GPIOx->CRH.bits.MODE14 = 0b010;
		else if(cfg->GPIO_OutputSpeed == GPIO_SPEED_50M)
			GPIOx->CRH.bits.MODE14 = 0b11;
		if(cfg->GPIO_PinMode ==GPIO_MODE_ANALOG||cfg->GPIO_PinMode ==GPIO_MODE_INPUT_FLO||cfg->GPIO_PinMode ==GPIO_MODE_INPUT_PU||cfg->GPIO_PinMode ==GPIO_MODE_INPUT_PD)
			GPIOx->CRH.bits.MODE14 = 0b00;

		switch(cfg->GPIO_PinMode){
		case GPIO_MODE_ANALOG:
			GPIOx->CRH.bits.CNF14 = 0b00;
			break;
		case GPIO_MODE_INPUT_FLO:
			GPIOx->CRH.bits.CNF14 = 0b01;
			break;
		case GPIO_MODE_INPUT_PU:
			GPIOx->CRH.bits.CNF14 = 0b10;
			GPIOx->BSRR.bits.BS14 = 0b1;
			break;
		case GPIO_MODE_INPUT_PD:
			GPIOx->CRH.bits.CNF14 = 0b10;
			GPIOx->BRR.bits.BR14 = 0b1;
			break;
		case GPIO_MODE_OUTPUT_PP:
			GPIOx->CRH.bits.CNF14 = 0b00;
			break;
		case GPIO_MODE_OUTPUT_OD:
			GPIOx->CRH.bits.CNF14 = 0b01;
			break;
		case GPIO_MODE_OUTPUT_AF_PP:
			GPIOx->CRH.bits.CNF14 = 0b10;
			break;
		case GPIO_MODE_OUTPUT_AF_OD:
			GPIOx->CRH.bits.CNF14 = 0b11;
			break;
		}
		break;

	case GPIO_PIN15:
		if(cfg->GPIO_OutputSpeed == GPIO_SPEED_10M)
			GPIOx->CRH.bits.MODE15 = 0b01;
		else if(cfg->GPIO_OutputSpeed == GPIO_SPEED_2M)
			GPIOx->CRH.bits.MODE15 = 0b010;
		else if(cfg->GPIO_OutputSpeed == GPIO_SPEED_50M)
			GPIOx->CRH.bits.MODE15 = 0b11;
		if(cfg->GPIO_PinMode ==GPIO_MODE_ANALOG||cfg->GPIO_PinMode ==GPIO_MODE_INPUT_FLO||cfg->GPIO_PinMode ==GPIO_MODE_INPUT_PU||cfg->GPIO_PinMode ==GPIO_MODE_INPUT_PD)
			GPIOx->CRH.bits.MODE15 = 0b00;

		switch(cfg->GPIO_PinMode){
		case GPIO_MODE_ANALOG:
			GPIOx->CRH.bits.CNF15 = 0b00;
			break;
		case GPIO_MODE_INPUT_FLO:
			GPIOx->CRH.bits.CNF15 = 0b01;
			break;
		case GPIO_MODE_INPUT_PU:
			GPIOx->CRH.bits.CNF15 = 0b10;
			GPIOx->BSRR.bits.BS15 = 0b1;
			break;
		case GPIO_MODE_INPUT_PD:
			GPIOx->CRH.bits.CNF15 = 0b10;
			GPIOx->BRR.bits.BR15 = 0b1;
			break;
		case GPIO_MODE_OUTPUT_PP:
			GPIOx->CRH.bits.CNF15 = 0b00;
			break;
		case GPIO_MODE_OUTPUT_OD:
			GPIOx->CRH.bits.CNF15 = 0b01;
			break;
		case GPIO_MODE_OUTPUT_AF_PP:
			GPIOx->CRH.bits.CNF15 = 0b10;
			break;
		case GPIO_MODE_OUTPUT_AF_OD:
			GPIOx->CRH.bits.CNF15 = 0b11;
			break;
		}
		break;

	case GPIO_PORT:
		switch(cfg->GPIO_PinMode){
		case GPIO_MODE_ANALOG:
			GPIOx->CRL.CRL = 0x00000000;
			GPIOx->CRH.CRH = 0x00000000;
			break;
		case GPIO_MODE_INPUT_FLO:
			GPIOx->CRL.CRL = 0x44444444;
			GPIOx->CRH.CRH = 0x44444444;
			break;
		case GPIO_MODE_INPUT_PU:
			GPIOx->CRL.CRL  = 0x88888888;
			GPIOx->CRH.CRH = 0x88888888;
			GPIOx->BSRR.BSRR = 0x0000FFFF;
			break;
		case GPIO_MODE_INPUT_PD:
			GPIOx->CRL.CRL = 0x88888888;
			GPIOx->CRH.CRH = 0x88888888;
			GPIOx->BRR.BRR = 0x0000FFFF;
			break;
		case GPIO_MODE_OUTPUT_PP:
			if(cfg->GPIO_OutputSpeed == GPIO_SPEED_10M){
				GPIOx->CRL.CRL = 0x11111111;
				GPIOx->CRH.CRH = 0x11111111;
			}
			else if(cfg->GPIO_OutputSpeed == GPIO_SPEED_2M){
				GPIOx->CRH.CRH = 0x22222222;
				GPIOx->CRL.CRL = 0x22222222;
			}
			else if(cfg->GPIO_OutputSpeed == GPIO_SPEED_50M){
				GPIOx->CRH.CRH= 0x33333333;
				GPIOx->CRL.CRL = 0x33333333;
			}
			break;
		case GPIO_MODE_OUTPUT_OD:
			if(cfg->GPIO_OutputSpeed == GPIO_SPEED_10M){
				GPIOx->CRL.CRL = 0x55555555;
				GPIOx->CRH.CRH = 0x55555555;
			}
			else if(cfg->GPIO_OutputSpeed == GPIO_SPEED_2M){
				GPIOx->CRH.CRH = 0x66666666;
				GPIOx->CRL.CRL = 0x66666666;
			}
			else if(cfg->GPIO_OutputSpeed == GPIO_SPEED_50M){
				GPIOx->CRH.CRH = 0x77777777;
				GPIOx->CRL.CRL = 0x77777777;
			}
			break;
		case GPIO_MODE_OUTPUT_AF_PP:
			if(cfg->GPIO_OutputSpeed == GPIO_SPEED_10M){
				GPIOx->CRL.CRL = 0x99999999;
				GPIOx->CRH.CRH = 0x99999999;
			}
			else if(cfg->GPIO_OutputSpeed == GPIO_SPEED_2M){
				GPIOx->CRH.CRH = 0xAAAAAAAA;
				GPIOx->CRL.CRL = 0xAAAAAAAA;
			}
			else if(cfg->GPIO_OutputSpeed == GPIO_SPEED_50M){
				GPIOx->CRH.CRH = 0xBBBBBBBB;
				GPIOx->CRL.CRL = 0xBBBBBBBB;
			}
			break;
		case GPIO_MODE_OUTPUT_AF_OD:
			if(cfg->GPIO_OutputSpeed == GPIO_SPEED_10M){
				GPIOx->CRL.CRL = 0xDDDDDDDD;
				GPIOx->CRH.CRH = 0xDDDDDDDD;
			}
			else if(cfg->GPIO_OutputSpeed == GPIO_SPEED_2M){
				GPIOx->CRH.CRH = 0xEEEEEEEE;
				GPIOx->CRL.CRL = 0xEEEEEEEE;
			}
			else if(cfg->GPIO_OutputSpeed == GPIO_SPEED_50M){
				GPIOx->CRH.CRH = 0xFFFFFFFF;
				GPIOx->CRL.CRL = 0xFFFFFFFF;
			}
			break;
		}
		break;
	}
}


/**================================================================
 * @Fn			-MCAL_GPIO_deinit.
 * @brief	    -Reset the GPIOx registers.
 * @param [in] 	-GPIOx: x can be (A...E) to select the GPIO peripheral.
 * @retval 		-none
 * Note			-none
 */
void MCAL_GPIO_deinit(GPIO_typedef * GPIOx){

	if(GPIOx == GPIOA){
		RCC->APB2RSTR.bits.IOPARST = 0b1;
		RCC->APB2RSTR.bits.IOPARST = 0b0;
	}
	else if(GPIOx == GPIOB){
		RCC->APB2RSTR.bits.IOPBRST = 0b1;
		RCC->APB2RSTR.bits.IOPBRST = 0b0;
	}
	else if(GPIOx == GPIOC){
		RCC->APB2RSTR.bits.IOPCRST = 0b1;
		RCC->APB2RSTR.bits.IOPCRST = 0b0;
	}
	else if(GPIOx == GPIOD){
		RCC->APB2RSTR.bits.IOPDRST = 0b1;
		RCC->APB2RSTR.bits.IOPDRST = 0b0;
	}
	else if(GPIOx == GPIOE){
		RCC->APB2RSTR.bits.IOPERST = 0b1;
		RCC->APB2RSTR.bits.IOPERST = 0b0;
	}


}

/**================================================================
 * @Fn			-MCAL_GPIO_readPin.
 * @brief	    -Reads the GPIOx PINy input value.
 * @param [in] 	-GPIOx: x can be (A...E) to select the GPIO peripheral.
 * @param [in] 	-PinNumber: Specifies the PIN to be read.
 * @retval 		-either one of two states check: @ref GPIO_PIN_STATE_define
 * Note			-none
 */
uint8 MCAL_GPIO_readPin(GPIO_typedef * GPIOx,uint8 PinNumber ){

	uint8 state;
	switch(PinNumber){
	case GPIO_PIN0:
		state =(uint8)GPIOx->IDR.bits.IDR0;
		return state ;
	case GPIO_PIN1:
		state =(uint8)GPIOx->IDR.bits.IDR1;
		return state ;
	case GPIO_PIN2:
		state =(uint8)GPIOx->IDR.bits.IDR2;
		return state ;
	case GPIO_PIN3:
		state =(uint8)GPIOx->IDR.bits.IDR3;
		return state ;
	case GPIO_PIN4:
		state =(uint8)GPIOx->IDR.bits.IDR4;
		return state ;
	case GPIO_PIN5:
		state =(uint8)GPIOx->IDR.bits.IDR5;
		return state ;
	case GPIO_PIN6:
		state =(uint8)GPIOx->IDR.bits.IDR6;
		return state ;
	case GPIO_PIN7:
		state =(uint8)GPIOx->IDR.bits.IDR7;
		return state ;
	case GPIO_PIN8:
		state =(uint8)GPIOx->IDR.bits.IDR8;
		return state ;
	case GPIO_PIN9:
		state =(uint8)GPIOx->IDR.bits.IDR9;
		return state ;
	case GPIO_PIN10:
		state =(uint8)GPIOx->IDR.bits.IDR10;
		return state ;
	case GPIO_PIN11:
		state =(uint8)GPIOx->IDR.bits.IDR11;
		return state ;
	case GPIO_PIN12:
		state =(uint8)GPIOx->IDR.bits.IDR12;
		return state ;
	case GPIO_PIN13:
		state =(uint8)GPIOx->IDR.bits.IDR13;
		return state ;
	case GPIO_PIN14:
		state =(uint8)GPIOx->IDR.bits.IDR14;
		return state ;
	case GPIO_PIN15:
		state =(uint8)GPIOx->IDR.bits.IDR15;
		return state ;
	}
	return 0;
}
/**================================================================
 * @Fn			-MCAL_GPIO_readPort.
 * @brief	    -Reads the GPIOx input value.
 * @param [in] 	-GPIOx: x can be (A...E) to select the GPIO peripheral.
 * @retval 		-the input value on GPIOx
 * Note			-none
 */
uint16 MCAL_GPIO_readPort(GPIO_typedef * GPIOx){

	uint16 value = (uint16)GPIOx->IDR.IDR;
	return value;
}
/**================================================================
 * @Fn			-MCAL_GPIO_writePin.
 * @brief	    -writes either one of @ref GPIO_PIN_STATE_define value on the GPIOx PINy.
 * @param [in] 	-GPIOx: x can be (A...E) to select the GPIO peripheral.
 * @param [in] 	-PinNumber: Specifies the PIN to be read.
 * @param [in]  -data: Specifies one of @ref GPIO_PIN_STATE_define to be written.
 * @retval 		-none
 * Note			-none
 */
void MCAL_GPIO_writePin(GPIO_typedef * GPIOx,uint8 PinNumber,uint8 data ){

	switch(PinNumber){
	case GPIO_PIN0:
		if(data)
			GPIOx->BSRR.bits.BS0 = 0b1 ;
		else
			GPIOx->BRR.bits.BR0 = 0b1 ;
		break;
	case GPIO_PIN1:
		if(data)
			GPIOx->BSRR.bits.BS1 = 0b1 ;
		else
			GPIOx->BRR.bits.BR1 = 0b1 ;
		break;
	case GPIO_PIN2:
		if(data)
			GPIOx->BSRR.bits.BS2 = 0b1 ;
		else
			GPIOx->BRR.bits.BR2= 0b1 ;
		break;
	case GPIO_PIN3:
		if(data)
			GPIOx->BSRR.bits.BS3 = 0b1 ;
		else
			GPIOx->BRR.bits.BR3 = 0b1 ;
		break;
	case GPIO_PIN4:
		if(data)
			GPIOx->BSRR.bits.BS4 = 0b1 ;
		else
			GPIOx->BRR.bits.BR4 = 0b1 ;
		break;
	case GPIO_PIN5:
		if(data)
			GPIOx->BSRR.bits.BS5 = 0b1 ;
		else
			GPIOx->BRR.bits.BR5 = 0b1 ;
		break;
	case GPIO_PIN6:
		if(data)
			GPIOx->BSRR.bits.BS6 = 0b1 ;
		else
			GPIOx->BRR.bits.BR6 = 0b1 ;
		break;
	case GPIO_PIN7:
		if(data)
			GPIOx->BSRR.bits.BS7 = 0b1 ;
		else
			GPIOx->BRR.bits.BR7 = 0b1 ;
		break;
	case GPIO_PIN8:
		if(data)
			GPIOx->BSRR.bits.BS8 = 0b1 ;
		else
			GPIOx->BRR.bits.BR8 = 0b1 ;
		break;
	case GPIO_PIN9:
		if(data)
			GPIOx->BSRR.bits.BS9 = 0b1 ;
		else
			GPIOx->BRR.bits.BR9 = 0b1 ;
		break;
	case GPIO_PIN10:
		if(data)
			GPIOx->BSRR.bits.BS10 = 0b1 ;
		else
			GPIOx->BRR.bits.BR10 = 0b1 ;
		break;
	case GPIO_PIN11:
		if(data)
			GPIOx->BSRR.bits.BS11 = 0b1 ;
		else
			GPIOx->BRR.bits.BR11 = 0b1 ;
		break;
	case GPIO_PIN12:
		if(data)
			GPIOx->BSRR.bits.BS12 = 0b1 ;
		else
			GPIOx->BRR.bits.BR12 = 0b1 ;
		break;
	case GPIO_PIN13:
		if(data)
			GPIOx->BSRR.bits.BS13 = 0b1 ;
		else
			GPIOx->BRR.bits.BR13 = 0b1 ;
		break;
	case GPIO_PIN14:
		if(data)
			GPIOx->BSRR.bits.BR14 = 0b1 ;
		else
			GPIOx->BRR.bits.BR14 = 0b1 ;
		break;
	case GPIO_PIN15:
		if(data)
			GPIOx->BSRR.bits.BS15 = 0b1 ;
		else
			GPIOx->BRR.bits.BR15 = 0b1 ;
		break;
	}
}
/**================================================================
 * @Fn			-MCAL_GPIO_writePort.
 * @brief	    -writes data on the GPIOx.
 * @param [in] 	-GPIOx: x can be (A...E) to select the GPIO peripheral.
 * @param [in] 	-data: Specifies the data to be written.
 * @retval 		-none
 * Note			-none
 */
void MCAL_GPIO_writePort(GPIO_typedef * GPIOx,uint16 data ){

	GPIOx->ODR.ODR = (uint32) data;
}
/**================================================================
 * @Fn			-MCAL_GPIO_togglePin.
 * @brief	    -toggle the GPIOx PINy .
 * @param [in] 	-GPIOx: x can be (A...E) to select the GPIO peripheral.
 * @param [in] 	-PinNumber: Specifies the PIN to be toggled.
 * @retval 		-none
 * Note			-none
 */
void MCAL_GPIO_togglePin(GPIO_typedef * GPIOx,uint8 PinNumber){
	switch(PinNumber){
	case GPIO_PIN0:
		GPIOx->ODR.bits.ODR0 ^= 0b1 ;
		break;
	case GPIO_PIN1:
		GPIOx->ODR.bits.ODR1 ^= 0b1 ;
		break;
	case GPIO_PIN2:
		GPIOx->ODR.bits.ODR2 ^= 0b1 ;
		break;
	case GPIO_PIN3:
		GPIOx->ODR.bits.ODR3 ^= 0b1 ;
		break;
	case GPIO_PIN4:
		GPIOx->ODR.bits.ODR4 ^= 0b1 ;
		break;
	case GPIO_PIN5:
		GPIOx->ODR.bits.ODR5 ^= 0b1 ;
		break;
	case GPIO_PIN6:
		GPIOx->ODR.bits.ODR6 ^= 0b1 ;
		break;
	case GPIO_PIN7:
		GPIOx->ODR.bits.ODR7 ^= 0b1 ;
		break;
	case GPIO_PIN8:
		GPIOx->ODR.bits.ODR8 ^= 0b1 ;
		break;
	case GPIO_PIN9:
		GPIOx->ODR.bits.ODR9 ^= 0b1 ;
		break;
	case GPIO_PIN10:
		GPIOx->ODR.bits.ODR10 ^= 0b1 ;
		break;
	case GPIO_PIN11:
		GPIOx->ODR.bits.ODR11 ^= 0b1 ;
		break;
	case GPIO_PIN12:
		GPIOx->ODR.bits.ODR12 ^= 0b1 ;
		break;
	case GPIO_PIN13:
		GPIOx->ODR.bits.ODR13 ^= 0b1 ;
		break;
	case GPIO_PIN14:
		GPIOx->ODR.bits.ODR14 ^= 0b1 ;
		break;
	case GPIO_PIN15:
		GPIOx->ODR.bits.ODR15 ^= 0b1 ;
		break;
	}
}
/**================================================================
 * @Fn			-MCAL_GPIO_lockPin.
 * @brief	    -Lock the GPIOx PINy.
 * @param [in] 	-GPIOx: x can be (A...E) to select the GPIO peripheral.
 * @param [in] 	-PinNumber: Specifies the PIN to be locked.
 * @retval 		-returns one of @ref GPIO_LOCK_STATE_define
 * Note			-none
 */
uint8 MCAL_GPIO_lockPin(GPIO_typedef * GPIOx,uint8 PinNumber){

	//LCKK: Lock key
	//This bit can be read anytime. It can only be modified using the Lock Key Writing Sequence.
	//0: Port configuration lock key not active
	//1: Port configuration lock key active. GPIOx_LCKR register is locked until the next reset.
	//	LOCK key writing sequence:
	//	Write 1
	//	Write 0
	//	Write 1
	//	Read 0
	//	Read 1 (this read is optional but confirms that the lock is active)
	//		Note: During the LOCK Key Writing sequence, the value of LCK[15:0] must not change.
	//		Any error in the lock sequence will abort the lock

	switch(PinNumber){
	case GPIO_PIN0:
		GPIOx->LCKR.bits.LCK0 = 0b1 ;
		break;
	case GPIO_PIN1:
		GPIOx->LCKR.bits.LCK1 = 0b1 ;
		break;
	case GPIO_PIN2:
		GPIOx->LCKR.bits.LCK2 = 0b1 ;
		break;
	case GPIO_PIN3:
		GPIOx->LCKR.bits.LCK3 = 0b1 ;
		break;
	case GPIO_PIN4:
		GPIOx->LCKR.bits.LCK4 = 0b1 ;
		break;
	case GPIO_PIN5:
		GPIOx->LCKR.bits.LCK5 = 0b1 ;
		break;
	case GPIO_PIN6:
		GPIOx->LCKR.bits.LCK6 = 0b1 ;
		break;
	case GPIO_PIN7:
		GPIOx->LCKR.bits.LCK7 = 0b1 ;
		break;
	case GPIO_PIN8:
		GPIOx->LCKR.bits.LCK8 = 0b1 ;
		break;
	case GPIO_PIN9:
		GPIOx->LCKR.bits.LCK9 = 0b1 ;
		break;
	case GPIO_PIN10:
		GPIOx->LCKR.bits.LCK10 = 0b1 ;
		break;
	case GPIO_PIN11:
		GPIOx->LCKR.bits.LCK11 = 0b1 ;
		break;
	case GPIO_PIN12:
		GPIOx->LCKR.bits.LCK12 = 0b1 ;
		break;
	case GPIO_PIN13:
		GPIOx->LCKR.bits.LCK13 = 0b1 ;
		break;
	case GPIO_PIN14:
		GPIOx->LCKR.bits.LCK14 = 0b1 ;
		break;
	case GPIO_PIN15:
		GPIOx->LCKR.bits.LCK15 = 0b1 ;
		break;
	}
	GPIOx->LCKR.bits.LCKK = 0b1 ;
	GPIOx->LCKR.bits.LCKK = 0b0 ;
	GPIOx->LCKR.bits.LCKK = 0b1 ;
	if(!(GPIOx->LCKR.bits.LCKK)){
		GPIOx->LCKR.bits.LCKK ;
		return GPIO_LOCK_ENABLED;
	}
	else
		return GPIO_LOCK_FAILED;

}
