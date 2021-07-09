/*
/ * atmega32_uart_driver.c
 *
 *  Created on: Jun 8, 2021
 *      Author: Mostafa
 */

#include "../inc/atmega32_spi_driver.h"


/**================================================================
 * @Fn			-MCAL_SPI_init.
 * @brief	    -initialize the SPI according to config instance cfg.
 * @param [in] 	-cfg: pointer to SPI_config that contains SPI configuration.
 * @retval 		-none
 * Note			-none
 */

void MCAL_SPI_init(SPI_config * cfg){

	

	GPIO_config conf ;
	if(cfg->SPI_Mode){
	conf.GPIO_PinMode = GPIO_MODE_OUTPUT_PP;
	conf.GPIO_PinNumber = GPIO_PIN4;
	MCAL_GPIO_init(GPIOB,&conf);
	MCAL_GPIO_writePin(GPIOB,GPIO_PIN4,GPIO_HIGH);
	conf.GPIO_PinMode = GPIO_MODE_OUTPUT_PP;
	conf.GPIO_PinNumber = GPIO_PIN5;
	MCAL_GPIO_init(GPIOB,&conf);
	conf.GPIO_PinMode = GPIO_MODE_INPUT_HiZ;
	conf.GPIO_PinNumber = GPIO_PIN6;
	MCAL_GPIO_init(GPIOB,&conf);
	conf.GPIO_PinMode = GPIO_MODE_OUTPUT_PP;
	conf.GPIO_PinNumber = GPIO_PIN7;
	MCAL_GPIO_init(GPIOB,&conf);
	}else{
	conf.GPIO_PinMode = GPIO_MODE_INPUT_HiZ;
	conf.GPIO_PinNumber = GPIO_PIN4;
	MCAL_GPIO_init(GPIOB,&conf);
	conf.GPIO_PinMode = GPIO_MODE_INPUT_HiZ;
	conf.GPIO_PinNumber = GPIO_PIN5;
	MCAL_GPIO_init(GPIOB,&conf);
	conf.GPIO_PinMode = GPIO_MODE_OUTPUT_PP;
	conf.GPIO_PinNumber = GPIO_PIN6;
	MCAL_GPIO_init(GPIOB,&conf);
	conf.GPIO_PinMode = GPIO_MODE_INPUT_HiZ;
	conf.GPIO_PinNumber = GPIO_PIN7;
	MCAL_GPIO_init(GPIOB,&conf);
	}
	SPI->SPCR.bits.SPR01 = cfg->SPI_SCK;
	SPI->SPCR.bits.DORD  = cfg->SPI_DataOrder;
	SPI->SPCR.bits.CPOL  = cfg->SPI_CLKPolartiy;
	SPI->SPCR.bits.CPHA  = cfg->SPI_CLKPhase;
	SPI->SPCR.bits.MSTR  = cfg->SPI_Mode; 
	SPI->SPCR.bits.SPE	 = 0b1;
}

/**================================================================
 * @Fn			-MCAL_SPI_deinit.
 * @brief	    -deinitialize the SPI.
 * @param [in] 	-none
 * @retval 		-none
 * Note			-none
 */

void MCAL_SPI_deinit(void){

	while(!(SPI->SPSR.bits.SPIF));
	SPI->SPCR.SPCR 		 = 0x00;
	SPI->SPSR.bits.SPI2X	 = 0b1;
}

/**================================================================
 * @Fn			-MCAL_SPI_TransmitReceive.
 * @brief	    -transmits and receives the data through SPI.
 * @param [in] 	-data: data to be transmitted.
 * @retval 		-Received data
 * Note			-none
 */

uint8 MCAL_SPI_TransmitReceive(uint8 data){
			
	SPI->SPDR = data; 
	while(!(SPI->SPSR.bits.SPIF));
	 data=SPI->SPDR ;
	return data;
}
