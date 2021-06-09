/*
 * USART_Send_String.c
 *
 * Created: 09-Jun-21 1:22:56 AM
 *  Author: Mostafa
 */ 


#include "atmega32_gpio_driver.h"
#include "atmega32_uart_driver.h"
#include "LCD.h"
int main(void)
{
	USART_config cfg;
	uint8 Rx_string[30];
	LCD_init();
	
	cfg.USART_Baudrate  = USART_BR_9600;
	cfg.USART_Databits  = USART_8_DATA_BITS;
	cfg.USART_Paritybit = USART_NO_PARITY;
	cfg.USART_Stopbits  = USART_1_STOP_BIT;
	cfg.USART_Mode		= USART_MODE_ASYNC;  
	MCAL_USART_init(&cfg);
    
	LCD_printString("USART RX:");
	MCAL_USART_transmitString(((uint8 *)"Hello"));
	MCAL_USART_receiveString(Rx_string);
	LCD_printString(((char *)Rx_string));
	
	while(1)
    {
    }
}