/*
/ * atmega32_uart_driver.c
 *
 *  Created on: Jun 8, 2021
 *      Author: Mostafa
 */

#include "../inc/atmega32_usart_driver.h"
#include "avr/interrupt.h"

void (*GP_CallBack)(void);

/**================================================================
 * @Fn			-MCAL_USART_init.
 * @brief	    -initialize the USART according to config instance cfg.
 * @param [in] 	-cfg: pointer to USART_config that contains USART configuration.
 * @retval 		-none
 * Note			-none
 */

void MCAL_USART_init(USART_config * cfg){

	USART->UBRRL_ =cfg->USART_Baudrate;
	USART->UCSRA_.bits.U2X_ =0b0;

	switch(cfg->USART_Databits){
	case USART_5_DATA_BITS:{
		UCSRC |= (1<<URSEL);
		UCSRC &= ~(1<<UCSZ0);
		UCSRC &= ~(1<<UCSZ1);
		USART->UCSRB_.bits.UCSZ2_ =0b0;
		break;
	}
	case USART_6_DATA_BITS:{
		UCSRC |= (1<<URSEL);
		UCSRC |= (1<<UCSZ0);
		UCSRC &= ~(1<<UCSZ1);
		USART->UCSRB_.bits.UCSZ2_ =0b0;
		break;
	}
	case USART_7_DATA_BITS:{
		UCSRC |= (1<<URSEL);
		UCSRC &= ~(1<<UCSZ0);
		UCSRC |= (1<<UCSZ1);
		USART->UCSRB_.bits.UCSZ2_ =0b0;
		break;
	}
	case USART_8_DATA_BITS:{
		UCSRC |= (1<<URSEL);
		UCSRC |= (1<<UCSZ0);
		UCSRC |= (1<<UCSZ1);
		USART->UCSRB_.bits.UCSZ2_ =0b0;
		break;
	}
	case USART_9_DATA_BITS:{
		UCSRC |= (1<<URSEL);
		UCSRC |= (1<<UCSZ0);
		UCSRC |= ((1<<UCSZ1));
		USART->UCSRB_.bits.UCSZ2_ =0b1;
		break;
	}}

	switch(cfg->USART_Paritybit){
	case USART_NO_PARITY:{
		UCSRC |= (1<<URSEL);
		UCSRC &= ~(1<<UPM0);
		UCSRC &= ~(1<<UPM1);
		break;
	}
	case USART_ODD_PARITY:{
		UCSRC |= (1<<URSEL);
		UCSRC |= (1<<UPM0);
		UCSRC |= (1<<UPM1);
		break;
	}
	case USART_EVEN_PARITY:{
		UCSRC |= (1<<URSEL);
		UCSRC &= ~(1<<UPM0);
		UCSRC |= (1<<UPM1);
		break;
	}}

	if(cfg->USART_Stopbits){
		UCSRC |=(1<<URSEL);
		UCSRC |=(1<<USBS);
	}else{
		UCSRC |= (1<<URSEL);
		UCSRC &= ~(1<<USBS);
	}

	if(cfg->USART_Mode){
		UCSRC |=(1<<URSEL);
		UCSRC |=(1<<UMSEL);
	}else{
		UCSRC |= (1<<URSEL);
		UCSRC &= ~(1<<UMSEL);
	}
	switch(cfg->USART_InterruptEnable){
		case USART_INTERRUPT_DISABLE:
			USART->UCSRB_.bits.RXCIE_ =0b0;
			USART->UCSRB_.bits.TXCIE_ =0b0;
			GP_CallBack = (void *)(0x0);
			DISABLE_INT();
			break;
		case USART_INTERRUPT_TXCIE:
			USART->UCSRB_.bits.RXCIE_ =0b0;
			USART->UCSRB_.bits.TXCIE_ =0b1;
			GP_CallBack = cfg->P_CallBack;
			ENABLE_INT();
			break;
		case USART_INTERRUPT_RXCIE:
			USART->UCSRB_.bits.RXCIE_ =0b1;
			USART->UCSRB_.bits.TXCIE_ =0b0;
			GP_CallBack = cfg->P_CallBack;
			ENABLE_INT();
			break;
		case USART_INTERRUPT_TXCIE_RXCIE:
			USART->UCSRB_.bits.RXCIE_ =0b1;
			USART->UCSRB_.bits.TXCIE_ =0b1;
			GP_CallBack = cfg->P_CallBack;
			ENABLE_INT();
			break;


	}

	USART->UCSRB_.bits.RXEN_ = 0b1;
	USART->UCSRB_.bits.TXEN_ = 0b1;

}

/**================================================================
 * @Fn			-MCAL_USART_deinit.
 * @brief	    -deinitialize the USART.
 * @param [in] 	-none
 * @retval 		-none
 * Note			-none
 */

void MCAL_USART_deinit(void){

	while(!(USART->UCSRA_.bits.UDRE_));
	USART->UBRRL_ 		   = 0x00;
	USART->UCSRA_.bits.MPCM_ = 0b0;
	USART->UCSRA_.bits.U2X_  = 0b0;
	USART->UCSRA_.bits.TXC_  = 0b0;
	USART->UCSRB_.UCSRB_     &= ~(0x02);
	UCSRC 				   = 0x86;
	USART->UBRRL_		   = 0x00;
	UBRRH 				   = 0x00;
}

/**================================================================
 * @Fn			-MCAL_USART_receive.
 * @brief	    -reads the data received by USART.
 * @param [in] 	-none
 * @retval 		-data: data received by USART.
 * Note			-none
 */

uint16 MCAL_USART_receive(enum Polling poll){

	uint16 data=0;
	if(poll){
	while(!(USART->UCSRA_.bits.RXC_));
	}
	if(USART->UCSRB_.bits.UCSZ2_){
		data |= ((USART->UCSRB_.bits.RXB8_)<<8);
		data |= USART->UDR_;
	}
	else
		data = USART->UDR_;
	return data;
}

/**================================================================
 * @Fn			-MCAL_USART_transmit.
 * @brief	    -transmits the data through USART.
 * @param [in] 	-data: data to be transmitted.
 * @retval 		-none
 * Note			-none
 */

void MCAL_USART_transmit(uint16 data,enum Polling poll){

	if(poll){
		while(!(USART->UCSRA_.bits.UDRE_));
	}
	if(USART->UCSRB_.bits.UCSZ2_){
		USART->UCSRB_.bits.TXB8_ = ((data & (1<<8))>>8);
		USART->UDR_			   = ((uint8)data);
	}
	else
		USART->UDR_ = (uint8)data;
}

/**================================================================
 * @Fn			-MCAL_USART_receiveString.
 * @brief	    -reads the received string by USART char by char.
 * @param [in] 	-data: pointer to array of char to store received string.
 * @retval 		-none
 * Note			-to work properly it is preferred to use 8bit data in frame
 */

void MCAL_USART_receiveString(uint8 * data){

	while(1){
		while(!(USART->UCSRA_.bits.RXC_));
				*data = USART->UDR_;
				if(*data == '\0')
					break;
				else
					data++;
	}
}


/**================================================================
 * @Fn			-MCAL_USART_transmitString.
 * @brief	    -transmits a string through USART.
 * @param [in] 	-data: pointer to the string to be transmitted.
 * @retval 		-none
 * Note			-to work properly it is preferred to use 8bit data in frame
 */

void MCAL_USART_transmitString(uint8 * data){

	while(*data !='\0'){
		while(!(USART->UCSRA_.bits.UDRE_));
		if(USART->UCSRB_.bits.UCSZ2_){
			USART->UCSRB_.bits.TXB8_ = 0;
			USART->UDR_			   = ((uint8)(*data));
		}
		else
			USART->UDR_ = (*data);
		data++;
	}
	while(!(USART->UCSRA_.bits.UDRE_));
	USART->UDR_ = '\0';
}

ISR(USART_RXC_vect){
	
	GP_CallBack();
}

ISR(USART_TXC_vect){

	GP_CallBack();
	
}