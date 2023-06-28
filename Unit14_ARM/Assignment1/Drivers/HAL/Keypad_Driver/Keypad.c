/*
 * Keypad.c
 *
 * Created: 28-May-21 5:51:18 PM
 *  Author: Mostafa
 */ 
#include "Keypad.h"


uint8 KEYPAD_row[]={R0,R1,R2,R3};
uint8 KEYPAD_col[]={C0,C1,C2,C3};

void KEYPAD_init(void){

	uint8 i;
	GPIO_config cfg;
	for(i=0;i<4;i++){
		cfg.GPIO_PinNumber 	= KEYPAD_row[i];
		cfg.GPIO_PinMode   	= GPIO_MODE_INPUT_PD;
		cfg.GPIO_OutputSpeed	= GPIO_INPUT;
		MCAL_GPIO_init(KEYPAD_Port, &cfg);
		cfg.GPIO_PinNumber 	= KEYPAD_col[i];
		cfg.GPIO_PinMode   	= GPIO_MODE_OUTPUT_PP;
		cfg.GPIO_OutputSpeed	= GPIO_SPEED_10M;
		MCAL_GPIO_init(KEYPAD_Port, &cfg);
		MCAL_GPIO_writePin(KEYPAD_Port, KEYPAD_col[i], GPIO_LOW);
	}
}

char KEYPAD_getChar(void){

	uint8 i,j;
	for(i=0;i<4;i++){
		MCAL_GPIO_writePin(KEYPAD_Port, KEYPAD_col[i], GPIO_HIGH);
		for(j=0;j<4;j++){
			if(MCAL_GPIO_readPin(KEYPAD_Port, KEYPAD_row[j])){
				while(MCAL_GPIO_readPin(KEYPAD_Port, KEYPAD_row[j]));
				switch(i){
				case 0:{
					switch(j){
					case 0:
						return '7';
						break;
					case 1:
						return '4';
						break;
					case 2:
						return '1';
						break;
					case 3:
						return '!';
						break;
					}
					break;
				}
				case 1:{
					switch(j){
					case 0:
						return '8';
						break;
					case 1:
						return '5';
						break;
					case 2:
						return '2';
						break;
					case 3:
						return '0';
						break;
					}
					break;
				}
				case 2:{
					switch(j){
					case 0:
						return '9';
						break;
					case 1:
						return '6';
						break;
					case 2:
						return '3';
						break;
					case 3:
						return '=';
						break;

					}
					break;
				}
				case 3:{
					switch(j){
					case 0:
						return '/';
						break;
					case 1:
						return '*';
						break;
					case 2:
						return '-';
						break;
					case 3:
						return '+';
						break;
					}

					break;
				}
				}

			}
		}
		MCAL_GPIO_writePin(KEYPAD_Port, KEYPAD_col[i],GPIO_LOW);

	}
	return '\0';
}																	
