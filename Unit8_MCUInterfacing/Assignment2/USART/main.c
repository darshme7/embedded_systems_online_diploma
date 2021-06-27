/*
 * USART.c
 *
 * Created: 27-Jun-21 2:18:10 PM
 * Author : Mostafa
 */ 

#include "ATmega32_Drivers/inc/atmega32_usart_driver.h"
#include "HAL/inc/LCD.h"
uint8 i;
void USART_CallBack(void){
	
	if(USART->UCSRA_.bits.RXC_){
		LCD_goToXY(1,i);
		LCD_printChar((uint8)MCAL_USART_receive(disable));
		i++;
	}		
	else if(USART->UCSRA_.bits.TXC_){}
	
}
int main(void)
{
	uint8 i = 0x30;
    USART_config cfg;
	cfg.USART_Baudrate = USART_BR_9600;
	cfg.USART_Databits = USART_8_DATA_BITS;
	cfg.USART_Paritybit = USART_NO_PARITY;
	cfg.USART_Stopbits  = USART_1_STOP_BIT;
	cfg.USART_Mode		= USART_MODE_ASYNC;
	cfg.USART_InterruptEnable = USART_INTERRUPT_RXCIE;
	cfg.P_CallBack = USART_CallBack;	
	MCAL_USART_init(&cfg);
	LCD_init();
	delay_ms(500);
	LCD_printString("USART RX: ");
	
    
	while (1) 
    {	
		LCD_goToXY(0,11);
		LCD_printChar(i);
		i++;
		if(i == 0x39)i=0x30;
		delay_ms(500);
    }
}

