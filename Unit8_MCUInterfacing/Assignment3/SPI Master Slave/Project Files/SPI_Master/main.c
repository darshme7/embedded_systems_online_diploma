/*
 * SPI_Master.c
 *
 * Created: 08-Jul-21 3:07:51 PM
 * Author : Mostafa
 */ 

#include "ATmega32_Drivers/inc/atmega32_gpio_driver.h"
#include "ATmega32_Drivers/inc/atmega32_spi_driver.h"

void delay_ms(uint32 d){
	volatile uint32 i,j;
	for (i=0;i<d;i++)
		for (j=0;j<64;j++);
}

int main(void)
{
	uint8 i;
    GPIO_config config;
	SPI_config cfg;

	cfg.SPI_Mode = SPI_MODE_MASTER;
	cfg.SPI_DataOrder = SPI_MSB_FIRST;
	cfg.SPI_SCK = SPI_SCK_16;
	cfg.SPI_CLKPhase = SPI_CPHA_SAMPLE;
	cfg.SPI_CLKPolartiy = SPI_CPOL_RISING;
	MCAL_SPI_init(&cfg);
	
	config.GPIO_PinNumber = GPIO_PORT;
	config.GPIO_PinMode  = GPIO_MODE_OUTPUT_PP;
	MCAL_GPIO_init(GPIOA,&config);
    while (1) 
    {
		for(i=0;i<255;i++){
			MCAL_GPIO_writePort(GPIOA,MCAL_SPI_TransmitReceive(i));	
			delay_ms(100);
		}
    }
}

