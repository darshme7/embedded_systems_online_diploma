/*
 * stm32f103c6_exti_driver.c
 *
 *  Created on: Jun 3, 2021
 *      Author: Mostafa
 */

#include "stm32f103c6_exti_driver.h"


void (*GP_IRQHanderler[16])(void);

void update_EXTI(EXTI_config * cfg){

	GPIO_config conf;
	conf.GPIO_PinNumber 	= 	cfg->EXTI_Map.EXTI_GPIO_PinNumber;
	conf.GPIO_PinMode		=	GPIO_MODE_INPUT_FLO;
	conf.GPIO_OutputSpeed	=	GPIO_INPUT;
	MCAL_GPIO_init(cfg->EXTI_Map.EXTI_GPIO_PORT, &conf);

	switch(cfg->EXTI_Trigger){
	case EXTI_FALLING:
		EXTI->RTSR.RTSR &= ~(1<<(cfg->EXTI_Map.EXTI_IRQLineNumber));
		EXTI->FTSR.FTSR |= (1<<(cfg->EXTI_Map.EXTI_IRQLineNumber));
		break;
	case EXTI_RISING:
		EXTI->RTSR.RTSR |= (1<<(cfg->EXTI_Map.EXTI_IRQLineNumber));
		EXTI->FTSR.FTSR &= ~(1<<(cfg->EXTI_Map.EXTI_IRQLineNumber));
		break;
	case EXTI_RISING_FALLING:
		EXTI->RTSR.RTSR |= (1<<(cfg->EXTI_Map.EXTI_IRQLineNumber));
		EXTI->FTSR.FTSR |= (1<<(cfg->EXTI_Map.EXTI_IRQLineNumber));
		break;
	}

	uint8 index	 	=	(cfg->EXTI_Map.EXTI_IRQLineNumber) / 4;
	uint8 position  =	(cfg->EXTI_Map.EXTI_IRQLineNumber) % 4;

	if(index ==	0){
		AFIO->EXITCR1.EXITCR1 |= 1<<(4*position);
	}else if(index == 1){
		AFIO->EXITCR2.EXITCR2 |= 1<<(4*position);
	}else if(index == 2){
		AFIO->EXITCR3.EXITCR3 |= 1<<(4*position);
	}else if(index == 3){
		AFIO->EXITCR4.EXITCR4 |= 1<<(4*position);
	}

	GP_IRQHanderler[cfg->EXTI_Map.EXTI_IRQLineNumber] =cfg->P_IRQHandler;

	if(cfg->EXTI_EnableState == EXTI_ENABLE){

		EXTI->IMR.IMR |= (1<<(cfg->EXTI_Map.EXTI_IRQLineNumber));
		switch(cfg->EXTI_Map.EXTI_IRQLineNumber){
		case EXTI_L0:
			NVIC_EXTI0_ENABLE;
			break;
		case EXTI_L1:
			NVIC_EXTI1_ENABLE;
			break;
		case EXTI_L2:
			NVIC_EXTI2_ENABLE;
			break;
		case EXTI_L3:
			NVIC_EXTI1_ENABLE;
			break;
		case EXTI_L4:
			NVIC_EXTI1_ENABLE;
			break;
		case EXTI_L5:
		case EXTI_L6:
		case EXTI_L7:
		case EXTI_L8:
		case EXTI_L9:
			NVIC_EXTI9_5_ENABLE;
			break;
		case EXTI_L10:
		case EXTI_L11:
		case EXTI_L12:
		case EXTI_L13:
		case EXTI_L14:
		case EXTI_L15:
			NVIC_EXTI15_10_ENABLE;
			break;
		}

	}else{
		EXTI->IMR.IMR &= ~(1<<(cfg->EXTI_Map.EXTI_IRQLineNumber));
		switch(cfg->EXTI_Map.EXTI_IRQLineNumber){
		case EXTI_L0:
			NVIC_EXTI0_DISABLE;
			break;
		case EXTI_L1:
			NVIC_EXTI1_DISABLE;
			break;
		case EXTI_L2:
			NVIC_EXTI2_DISABLE;
			break;
		case EXTI_L3:
			NVIC_EXTI1_DISABLE;
			break;
		case EXTI_L4:
			NVIC_EXTI1_DISABLE;
			break;
		case EXTI_L5:
		case EXTI_L6:
		case EXTI_L7:
		case EXTI_L8:
		case EXTI_L9:
			NVIC_EXTI9_5_DISABLE;
			break;
		case EXTI_L10:
		case EXTI_L11:
		case EXTI_L12:
		case EXTI_L13:
		case EXTI_L14:
		case EXTI_L15:
			NVIC_EXTI15_10_DISABLE;
			break;
		}

	}
}


/**================================================================
 * @Fn			-MCAL_GPIO_deinit.
 * @brief	    -Resets the EXTI regiters.
 * @param [in] 	-none
 * @retval 		-none
 * Note			-none
 */

void MCAL_EXTI_deInit(void){

	EXTI->IMR.IMR		=	0x00000000;
	EXTI->EMR.EMR		=	0x00000000;
	EXTI->RTSR.RTSR		=	0x00000000;
	EXTI->FTSR.FTSR		=	0x00000000;
	EXTI->SWIER.SWIER	=	0x00000000;
	EXTI->PR.PR			=	0x000FFFFF;

	AFIO->EXITCR1.EXITCR1 = 0x00000000;
	AFIO->EXITCR2.EXITCR2 = 0x00000000;
	AFIO->EXITCR3.EXITCR3 = 0x00000000;
	AFIO->EXITCR4.EXITCR4 = 0x00000000;


	NVIC_EXTI0_DISABLE;
	NVIC_EXTI1_DISABLE;
	NVIC_EXTI2_DISABLE;
	NVIC_EXTI3_DISABLE;
	NVIC_EXTI4_DISABLE;
	NVIC_EXTI9_5_DISABLE;
	NVIC_EXTI15_10_DISABLE;

}





/**================================================================
 * @Fn			-MCAL_GPIO_init.
 * @brief	    -initiallize the EXTI according to EXTI_config.
 * @param [in] 	-cfg: contains the configuration for EXTI Module.
 * @retval 		-none
 * Note			-none
 */

void MCAL_EXTI_init(EXTI_config * cfg){

	update_EXTI(cfg);
}


/**================================================================
 * @Fn			-MCAL_GPIO_init.
 * @brief	    -update the EXTI according to EXTI_config.
 * @param [in] 	-cfg: contains the updated configuration for EXTI Module.
 * @retval 		-none
 * Note			-none
 */

void MCAL_EXTI_update(EXTI_config * cfg){

	update_EXTI(cfg);

}

void EXTI0_IRQHandler(){

	EXTI->PR.bits.PR0 = 0b1;
	GP_IRQHanderler[0]();
}
void EXTI1_IRQHandler(){

	EXTI->PR.bits.PR1 = 0b1;
	GP_IRQHanderler[1]();

}
void EXTI2_IRQHandler(){
	EXTI->PR.bits.PR2 = 0b1;
	GP_IRQHanderler[2]();
}
void EXTI3_IRQHandler(){
	EXTI->PR.bits.PR3 = 0b1;
	GP_IRQHanderler[3]();
}
void EXTI4_IRQHandler(){
	EXTI->PR.bits.PR4 = 0b1;
	GP_IRQHanderler[4]();
}
void EXTI9_5_IRQHandler(){

	if(EXTI->PR.bits.PR5){
		EXTI->PR.bits.PR5 = 0b1;
		GP_IRQHanderler[5]();
	}else if(EXTI->PR.bits.PR6){
		EXTI->PR.bits.PR6 = 0b1;
		GP_IRQHanderler[6]();
	}else if(EXTI->PR.bits.PR7){
		EXTI->PR.bits.PR7 = 0b1;
		GP_IRQHanderler[7]();
	}else if(EXTI->PR.bits.PR8){
		EXTI->PR.bits.PR8 = 0b1;
		GP_IRQHanderler[8]();
	}else if(EXTI->PR.bits.PR9){
		GP_IRQHanderler[9]();
		EXTI->PR.bits.PR9 = 0b1;
	}
}
void EXTI15_10_IRQHandler(){
	if(EXTI->PR.bits.PR10){
		EXTI->PR.bits.PR10 = 0b1;
		GP_IRQHanderler[10]();
	}else if(EXTI->PR.bits.PR11){
		EXTI->PR.bits.PR11 = 0b1;
		GP_IRQHanderler[11]();
	}else if(EXTI->PR.bits.PR12){
		EXTI->PR.bits.PR12 = 0b1;
		GP_IRQHanderler[12]();
	}else if(EXTI->PR.bits.PR13){
		EXTI->PR.bits.PR13 = 0b1;
		GP_IRQHanderler[13]();
	}else if(EXTI->PR.bits.PR14){
		EXTI->PR.bits.PR14 = 0b1;
		GP_IRQHanderler[14]();
	}else if(EXTI->PR.bits.PR15){
		EXTI->PR.bits.PR15 = 0b1;
		GP_IRQHanderler[15]();
	}

}
