/*
 * stm32f103c6_usart_driver.c
 *
 *  Created on: Jun 11, 2021
 *      Author: mosta
 */

//--------------------------------------------------------------------------------------------------------------------
//Includes
//--------------------------------------------------------------------------------------------------------------------

#include "stm32f103c6_usart_driver.h"
#include "stm32f103c6_gpio_driver.h"
#include "stm32f103c6_rcc_driver.h"


//--------------------------------------------------------------------------------------------------------------------
//Globals
//--------------------------------------------------------------------------------------------------------------------

void (*GP_CallBack)(void);


/**================================================================
 * @Fn			-MCAL_USART_init.
 * @brief	    -initialize the USARTx according to config instance cfg.
 * @param [in] 	-USARTx: x can be (1..3) to select the USART peripheral.
 * @param [in] 	-cfg: pointer to USART_config that contains USART configuration.
 * @retval 		-none
 * Note			-none
 */

void MCAL_USART_init(USART_typedef * USARTx ,USART_config *cfg){

	GPIO_config conf;
	uint32 CLK,br;
	if(USARTx == USART1){
		conf.GPIO_PinNumber 	= GPIO_PIN9;
		conf.GPIO_PinMode  		= GPIO_MODE_OUTPUT_AF_PP;
		conf.GPIO_OutputSpeed 	= GPIO_SPEED_10M;
		MCAL_GPIO_init(GPIOA, &conf);
		conf.GPIO_PinNumber 	= GPIO_PIN10;
		conf.GPIO_PinMode  		= GPIO_MODE_INPUT_FLO;
		conf.GPIO_OutputSpeed 	= GPIO_INPUT;
		MCAL_GPIO_init(GPIOA, &conf);
		CLK = MCAL_RCC_PCLCK2Freq();
		if(cfg->USART_ISREnable != USART_ISR_ENABLE_NONE) NVIC_USART1_ENABLE();
	}
	else if(USARTx == USART2){
		conf.GPIO_PinNumber 	= GPIO_PIN2;
		conf.GPIO_PinMode  		= GPIO_MODE_OUTPUT_AF_PP;
		conf.GPIO_OutputSpeed 	= GPIO_SPEED_10M;
		MCAL_GPIO_init(GPIOA, &conf);
		conf.GPIO_PinNumber 	= GPIO_PIN3;
		conf.GPIO_PinMode  		= GPIO_MODE_INPUT_FLO;
		conf.GPIO_OutputSpeed 	= GPIO_INPUT;
		MCAL_GPIO_init(GPIOA, &conf);
		if(cfg->USART_ISREnable != USART_ISR_ENABLE_NONE)NVIC_USART2_ENABLE();
		CLK = MCAL_RCC_PCLCK1Freq();
	}
	else if(USARTx == USART3){
		conf.GPIO_PinNumber 	= GPIO_PIN10;
		conf.GPIO_PinMode  		= GPIO_MODE_OUTPUT_AF_PP;
		conf.GPIO_OutputSpeed 	= GPIO_SPEED_10M;
		MCAL_GPIO_init(GPIOB, &conf);
		conf.GPIO_PinNumber 	= GPIO_PIN11;
		conf.GPIO_PinMode  		= GPIO_MODE_INPUT_FLO;
		conf.GPIO_OutputSpeed 	= GPIO_INPUT;
		MCAL_GPIO_init(GPIOB, &conf);
		if(cfg->USART_ISREnable != USART_ISR_ENABLE_NONE)NVIC_USART3_ENABLE();
		CLK = MCAL_RCC_PCLCK1Freq();
	}

	br=(CLK*100)/(cfg->USART_BaudRate*16);
	USARTx->USART_CR1.bits.UE 						= 0b1;
	USARTx->USART_BRR.bits.DIV_Mantissa				= (CLK/(16*cfg->USART_BaudRate));
	USARTx->USART_BRR.bits.DIV_Fraction				= ((br-((USARTx->USART_BRR.bits.DIV_Mantissa)*100))*16)/100;
	USARTx->USART_CR1.bits.M    					= cfg->USART_DataBits;
	USARTx->USART_CR1.bits.PCE_PS					= cfg->USART_ParityBit;
	USARTx->USART_CR2.bits.STOP 					= cfg->USART_StopBits;
	USARTx->USART_CR1.bits.RXNEIE_TCIE_TXEIE_PEIE	= cfg->USART_ISREnable;
	GP_CallBack 									= cfg->USART_P_ISR_CallBack;
	USARTx->USART_CR1.bits.TE_RE					= cfg->USART_Mode;
}

/**================================================================
 * @Fn			-MCAL_USART_deinit.
 * @brief	    -deinitialize the USARTx.
 * @param [in] 	-USARTx: x can be (1..3) to select the USART peripheral.
 * @retval 		-none
 * Note			-none
 */

void MCAL_USART_deinit(USART_typedef * USARTx){

	if(USARTx == USART1){
		RCC->APB2RSTR.bits.USART1RST = 0b1;
		RCC->APB2RSTR.bits.USART1RST = 0b0;
	}else if(USARTx == USART2){
		RCC->APB1RSTR.bits.USART2RST = 0b1;
		RCC->APB1RSTR.bits.USART2RST = 0b0;
	}else if(USARTx == USART3){
		RCC->APB1RSTR.bits.USART3RST = 0b1;
		RCC->APB1RSTR.bits.USART3RST = 0b0;
	}
}


/**================================================================
 * @Fn			-MCAL_USART_transmit.
 * @brief	    -transmit the data passed form user.
 * @param [in] 	-USARTx: x can be (1..3) to select the USART peripheral.
 * @param [in] 	-data: data to be transmitted.
 * @retval 		-none
 * Note			-none
 */

void MCAL_USART_transmit(USART_typedef * USARTx ,uint16 data,enum USART_Polling PollingEN){

	if(PollingEN)
		while(!(USARTx->USART_SR.bits.TXE));

	if(USARTx->USART_CR1.bits.M)
		USARTx->USART_DR.bits.DR = (data & ((uint16)(0x01FF)));
	else
		USARTx->USART_DR.bits.DR = (data & ((uint8)(0xFF)));
}

/**================================================================
 * @Fn			-MCAL_USART_receive.
 * @brief	    -reads data received form USART register.
 * @param [in] 	-USARTx: x can be (1..3) to select the USART peripheral.
 * @retval 		-data recevied from USART register.
 * Note			-none
 */

uint16 MCAL_USART_receive(USART_typedef * USARTx,enum USART_Polling PollingEN){

	uint16 data;
	if(PollingEN)
		while(!(USARTx->USART_SR.bits.RXNE));

	if(USARTx->USART_CR1.bits.M){
		if (USARTx->USART_CR1.bits.PCE_PS)
			data = (USARTx->USART_DR.bits.DR & ((uint8)(0xFF)));
		else
			data = USARTx->USART_DR.bits.DR;
	}else{
		if(USARTx->USART_CR1.bits.PCE_PS)
			data = (USARTx->USART_DR.bits.DR & ((uint8)(0x7F)));
		else
			data = (USARTx->USART_DR.bits.DR & ((uint8)(0xFF)));
	}
	return data;
}

/**================================================================
 * @Fn			-MCAL_USART_transmitString.
 * @brief	    -transmit the String passed form user.
 * @param [in] 	-USARTx: x can be (1..3) to select the USART peripheral.
 * @param [in] 	-data: pointer to string to be transmitted.
 * @retval 		-none
 * Note			-none
 */

void MCAL_USART_transmitString(USART_typedef * USARTx ,char * data){

	while(*data != '\0'){
		while(!(USARTx->USART_SR.bits.TXE));
		USARTx->USART_DR.USART_DR = *data;
		data++;
	}
	while(!(USARTx->USART_SR.bits.TXE));
	USARTx->USART_DR.USART_DR = '\0';
}

/**================================================================
 * @Fn			-MCAL_USART_receiveString.
 * @brief	    -reads char by char received form USART register.
 * @param [in] 	-USARTx: x can be (1..3) to select the USART peripheral.
 * @retval 		-string recevied from USART register.
 * Note			-none
 */

void MCAL_USART_receiveString(USART_typedef * USARTx,char * data){
	while(1){
		while(!(USARTx->USART_SR.bits.RXNE));
		*data = USARTx->USART_DR.USART_DR;
		if(*data == '#')break;
		else data++;
	}
}

void USART1_IRQHandler(void){

	GP_CallBack();
}

void USART2_IRQHandler(void){

	GP_CallBack();
}

void USART3_IRQHandler(void){

	GP_CallBack();
}
