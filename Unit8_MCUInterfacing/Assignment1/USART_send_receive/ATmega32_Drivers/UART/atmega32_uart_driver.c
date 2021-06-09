/*
/ * atmega32_uart_driver.c
 *
 *  Created on: Jun 8, 2021
 *      Author: mosta
 */

#include "atmega32_uart_driver.h"


/**================================================================
 * @Fn			-MCAL_USART_init.
 * @brief	    -initialize the USART according to config instance cfg.
 * @param [in] 	-cfg: pointer to USART_config that contains USART configuration.
 * @retval 		-none
 * Note			-none
 */

void MCAL_USART_init(USART_config * cfg){

	USART->UBRRL =cfg->USART_Baudrate;
	USART->UCSRA.bits.U2X =0b0;

	switch(cfg->USART_Databits){
	case USART_5_DATA_BITS:{
		UCSRC |= (1<<URSEL);
		UCSRC &= ~(1<<UCSZ0);
		UCSRC &= ~(1<<UCSZ1);
		USART->UCSRB.bits.UCSZ2 =0b0;
		break;
	}
	case USART_6_DATA_BITS:{
		UCSRC |= (1<<URSEL);
		UCSRC |= (1<<UCSZ0);
		UCSRC &= ~(1<<UCSZ1);
		USART->UCSRB.bits.UCSZ2 =0b0;
		break;
	}
	case USART_7_DATA_BITS:{
		UCSRC |= (1<<URSEL);
		UCSRC &= ~(1<<UCSZ0);
		UCSRC |= (1<<UCSZ1);
		USART->UCSRB.bits.UCSZ2 =0b0;
		break;
	}
	case USART_8_DATA_BITS:{
		UCSRC |= (1<<URSEL);
		UCSRC |= (1<<UCSZ0);
		UCSRC |= (1<<UCSZ1);
		USART->UCSRB.bits.UCSZ2 =0b0;
		break;
	}
	case USART_9_DATA_BITS:{
		UCSRC |= (1<<URSEL);
		UCSRC |= (1<<UCSZ0);
		UCSRC |= ((1<<UCSZ1));
		USART->UCSRB.bits.UCSZ2 =0b1;
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

	USART->UCSRB.bits.RXEN = 0b1;
	USART->UCSRB.bits.TXEN = 0b1;

}

/**================================================================
 * @Fn			-MCAL_USART_deinit.
 * @brief	    -deinitialize the USART.
 * @param [in] 	-none
 * @retval 		-none
 * Note			-none
 */

void MCAL_USART_deinit(void){

	while(!(USART->UCSRA.bits.UDRE));
	USART->UBRRL 		   = 0x00;
	USART->UCSRA.bits.MPCM = 0b0;
	USART->UCSRA.bits.U2X  = 0b0;
	USART->UCSRA.bits.TXC  = 0b0;
	USART->UCSRB.UCSRB     &= ~(0x02);
	UCSRC 				   = 0x86;
	USART->UBRRL		   = 0x00;
	UBRRH 				   = 0x00;
}

/**================================================================
 * @Fn			-MCAL_USART_receive.
 * @brief	    -reads the data received by USART.
 * @param [in] 	-none
 * @retval 		-data: data received by USART.
 * Note			-none
 */

uint16 MCAL_USART_receive(void){

	uint16 data=0;
	while(!(USART->UCSRA.bits.RXC));
	if(USART->UCSRB.bits.UCSZ2){
		data |= ((USART->UCSRB.bits.RXB8)<<8);
		data |= USART->UDR;
	}
	else
		data = USART->UDR;
	return data;
}

/**================================================================
 * @Fn			-MCAL_USART_transmit.
 * @brief	    -transmits the data through USART.
 * @param [in] 	-data: data to be transmitted.
 * @retval 		-none
 * Note			-none
 */

void MCAL_USART_transmit(uint16 data){


	while(!(USART->UCSRA.bits.UDRE));
	if(USART->UCSRB.bits.UCSZ2){
		USART->UCSRB.bits.TXB8 = ((data & (1<<8))>>8);
		USART->UDR			   = ((uint8)data);
	}
	else
		USART->UDR = data;
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
		while(!(USART->UCSRA.bits.RXC));
				*data = USART->UDR;
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
		while(!(USART->UCSRA.bits.UDRE));
		if(USART->UCSRB.bits.UCSZ2){
			USART->UCSRB.bits.TXB8 = 0;
			USART->UDR			   = ((uint8)(*data));
		}
		else
			USART->UDR = (*data);
		data++;
	}
	while(!(USART->UCSRA.bits.UDRE));
	USART->UDR = '\0';
}

