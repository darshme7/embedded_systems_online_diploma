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

void execute(uint8 cmd,uint8 data){

	MCAL_GPIO_writePin(GPIOB,GPIO_PIN4,GPIO_LOW);
	MCAL_SPI_TransmitReceive(cmd);
	MCAL_SPI_TransmitReceive(data);
	MCAL_GPIO_writePin(GPIOB,GPIO_PIN4,GPIO_HIGH);
}

int main(void)
{
	uint8 i ,j=0;
	SPI_config cfg;

	cfg.SPI_Mode = SPI_MODE_MASTER;
	cfg.SPI_DataOrder = SPI_MSB_FIRST;
	cfg.SPI_SCK = SPI_SCK_16;
	cfg.SPI_CLKPhase = SPI_CPHA_SAMPLE;
	cfg.SPI_CLKPolartiy = SPI_CPOL_RISING;
	MCAL_SPI_init(&cfg);
	execute(0x09,0xFF);
	execute(0x0A,0xFF);
	execute(0x0B,0xF7);
	execute(0x0C,0x01);
	
	while (1) 
    {
		for(i=1;i<9;i++)
			execute(i,j++);
			delay_ms(300);
		
    }
}

