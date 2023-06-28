/*
 * stm32f103c6_SPI_driver.c
 *
 *  Created on: Jun 11, 2021
 *      Author: mostafa
 */

//--------------------------------------------------------------------------------------------------------------------
//Includes
//--------------------------------------------------------------------------------------------------------------------


#include "stm32f103c6_spi_driver.h"
#include "stm32f103c6_gpio_driver.h"

//--------------------------------------------------------------------------------------------------------------------
//Globals
//--------------------------------------------------------------------------------------------------------------------

void (* P_ISR_CallBack_SPI)(void);


/**================================================================
 * @Fn			-MCAL_SPI_init.
 * @brief	    -initialize the SPIx according to config instance cfg.
 * @param [in] 	-SPIx: x can be (1,2) to select the SPI peripheral.
 * @param [in] 	-cfg: pointer to SPI_config that contains SPI configuration.
 * @retval 		-none
 * Note			-none
 */
void MCAL_SPI_init(SPI_typedef * SPIx ,SPI_config *cfg){

	GPIO_config conf;
	if(SPIx == SPI1){

		if(cfg->IRQ_Enable !=SPI_IRQ_DISABLE)NVIC_SPI1_ENABLE();
		if(cfg->SPI_Mode == SPI_MODE_MASTER){

			conf.GPIO_PinNumber = GPIO_PIN4;
			if(cfg->SPI_NSS == SPI_NSS_HARDWARE_OUTPUT_ENABLE){
				conf.GPIO_PinMode = GPIO_MODE_OUTPUT_AF_PP;
				conf.GPIO_OutputSpeed = GPIO_SPEED_10M;
			}else {
				conf.GPIO_PinMode = GPIO_MODE_INPUT_FLO;
				conf.GPIO_OutputSpeed = GPIO_INPUT;
			}
			MCAL_GPIO_init(GPIOA, &conf);

			conf.GPIO_PinNumber = GPIO_PIN5;
			conf.GPIO_PinMode = GPIO_MODE_OUTPUT_AF_PP;
			conf.GPIO_OutputSpeed = GPIO_SPEED_10M;
			MCAL_GPIO_init(GPIOA, &conf);

			conf.GPIO_PinNumber = GPIO_PIN6;
			conf.GPIO_PinMode = GPIO_MODE_INPUT_FLO;
			conf.GPIO_OutputSpeed = GPIO_INPUT;
			MCAL_GPIO_init(GPIOA, &conf);

			conf.GPIO_PinNumber = GPIO_PIN7;
			conf.GPIO_PinMode = GPIO_MODE_OUTPUT_AF_PP;
			conf.GPIO_OutputSpeed = GPIO_SPEED_10M;
			MCAL_GPIO_init(GPIOA, &conf);

		}else{
			conf.GPIO_PinNumber = GPIO_PIN4;
			conf.GPIO_PinMode = GPIO_MODE_INPUT_FLO;
			conf.GPIO_OutputSpeed = GPIO_INPUT;
			MCAL_GPIO_init(GPIOA, &conf);

			conf.GPIO_PinNumber = GPIO_PIN5;
			conf.GPIO_PinMode = GPIO_MODE_INPUT_FLO;
			conf.GPIO_OutputSpeed = GPIO_INPUT;
			MCAL_GPIO_init(GPIOA, &conf);

			conf.GPIO_PinNumber = GPIO_PIN6;
			conf.GPIO_PinMode = GPIO_MODE_OUTPUT_AF_PP;
			conf.GPIO_OutputSpeed = GPIO_SPEED_10M;
			MCAL_GPIO_init(GPIOA, &conf);

			conf.GPIO_PinNumber = GPIO_PIN7;
			conf.GPIO_PinMode = GPIO_MODE_INPUT_FLO;
			conf.GPIO_OutputSpeed = GPIO_INPUT;
			MCAL_GPIO_init(GPIOA, &conf);
		}

	}else if(SPIx == SPI2){

		if(cfg->IRQ_Enable !=SPI_IRQ_DISABLE)NVIC_SPI2_ENABLE();
		if(cfg->SPI_Mode == SPI_MODE_MASTER){

			conf.GPIO_PinNumber = GPIO_PIN12;
			if(cfg->SPI_NSS == SPI_NSS_HARDWARE_OUTPUT_ENABLE){
				conf.GPIO_PinMode = GPIO_MODE_OUTPUT_AF_PP;
				conf.GPIO_OutputSpeed = GPIO_SPEED_10M;
			}else {
				conf.GPIO_PinMode = GPIO_MODE_INPUT_FLO;
				conf.GPIO_OutputSpeed = GPIO_INPUT;
			}
			MCAL_GPIO_init(GPIOB, &conf);

			conf.GPIO_PinNumber = GPIO_PIN13;
			conf.GPIO_PinMode = GPIO_MODE_OUTPUT_AF_PP;
			conf.GPIO_OutputSpeed = GPIO_SPEED_10M;
			MCAL_GPIO_init(GPIOB, &conf);

			conf.GPIO_PinNumber = GPIO_PIN14;
			conf.GPIO_PinMode = GPIO_MODE_INPUT_FLO;
			conf.GPIO_OutputSpeed = GPIO_INPUT;
			MCAL_GPIO_init(GPIOB, &conf);

			conf.GPIO_PinNumber = GPIO_PIN15;
			conf.GPIO_PinMode = GPIO_MODE_OUTPUT_AF_PP;
			conf.GPIO_OutputSpeed = GPIO_SPEED_10M;
			MCAL_GPIO_init(GPIOB, &conf);

		}else{
			conf.GPIO_PinNumber = GPIO_PIN12;
			conf.GPIO_PinMode = GPIO_MODE_INPUT_FLO;
			conf.GPIO_OutputSpeed = GPIO_INPUT;
			MCAL_GPIO_init(GPIOB, &conf);

			conf.GPIO_PinNumber = GPIO_PIN13;
			conf.GPIO_PinMode = GPIO_MODE_INPUT_FLO;
			conf.GPIO_OutputSpeed = GPIO_INPUT;
			MCAL_GPIO_init(GPIOB, &conf);

			conf.GPIO_PinNumber = GPIO_PIN14;
			conf.GPIO_PinMode = GPIO_MODE_OUTPUT_AF_PP;
			conf.GPIO_OutputSpeed = GPIO_SPEED_10M;
			MCAL_GPIO_init(GPIOB, &conf);

			conf.GPIO_PinNumber = GPIO_PIN15;
			conf.GPIO_PinMode = GPIO_MODE_INPUT_FLO;
			conf.GPIO_OutputSpeed = GPIO_INPUT;
			MCAL_GPIO_init(GPIOB, &conf);
		}

	}

	SPIx->SPI_CR1.bits.MSTR  = cfg->SPI_Mode;
	SPIx->SPI_CR1.bits.BR  = cfg->SPI_BaudRatePrescaler;
	SPIx->SPI_CR1.bits.CPOL  = cfg->SPI_ClkPolarity;
	SPIx->SPI_CR1.bits.CPHA  = cfg->SPI_ClkPhase;
	SPIx->SPI_CR1.bits.DFF  = cfg->SPI_DataFrameBits;
	SPIx->SPI_CR1.bits.LSBFIRST  = cfg->SPI_BitOrder;
	SPIx->SPI_CR2.bits.ERRIE_RXNEIE_TXEIE=cfg->IRQ_Enable;
	switch(cfg->SPI_NSS){
	case SPI_NSS_SOFTWARE_SET:
		SPIx->SPI_CR1.bits.SSM = 0b1;
		SPIx->SPI_CR1.bits.SSI = 0b1;
		break;
	case SPI_NSS_SOFTWARE_RESET:
		SPIx->SPI_CR1.bits.SSM = 0b1;
		SPIx->SPI_CR1.bits.SSI = 0b0;
		break;
	case SPI_NSS_HARDWARE_OUTPUT_DISABLE:
		SPIx->SPI_CR1.bits.SSM = 0b0;
		SPIx->SPI_CR2.bits.SSOE = 0b0;
		break;
	case SPI_NSS_HARDWARE_OUTPUT_ENABLE:
		SPIx->SPI_CR1.bits.SSM = 0b0;
		SPIx->SPI_CR2.bits.SSOE = 0b1;
		break;
	}
	P_ISR_CallBack_SPI = cfg->SPI_P_ISR_CallBack;
	SPIx->SPI_CR1.bits.SPE  = 0b1;
}

/**================================================================
 * @Fn			-MCAL_SPI_deinit.
 * @brief	    -deinitialize the SPIx
 * @param [in] 	-SPIx: x can be (1,2) to select the SPI peripheral.
 * @retval 		-none
 * Note			-none
 */
void MCAL_SPI_deinit(SPI_typedef * SPIx){
	if(SPIx==SPI1)
		RCC->APB2RSTR.bits.SPI1RST;
	else if(SPIx==SPI2)
		RCC->APB1RSTR.bits.SPI2RST;

}

/**================================================================
 * @Fn			-MCAL_SPI_TxRx.
 * @brief	    -initialize the SPIx according to config instance cfg.
 * @param [in] 	-SPIx: x can be (1,2) to select the SPI peripheral.
 * @param [in] 	-cfg: pointer to SPI_config that contains SPI configuration.
 * @retval 		-none
 * Note			-none
 */
uint16 MCAL_SPI_TxRx(SPI_typedef * SPIx ,uint16 data,enum SPI_Polling poll){

	uint16 rx;
	if(poll)
		while(!SPIx->SPI_SR.bits.TXE);
	SPIx->SPI_DR.SPI_DR=data;

	if(poll)
		while(!SPIx->SPI_SR.bits.RXNE);
	rx=SPIx->SPI_DR.bits.DR;

	return rx;
}


void SPI1_IRQHandler(void){

	P_ISR_CallBack_SPI();
}

void SPI2_IRQHandler(void){
	P_ISR_CallBack_SPI();
}
