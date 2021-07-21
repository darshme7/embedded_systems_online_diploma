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
				MCAL_GPIO_writePin(KEYPAD_Port, KEYPAD_col[i], GPIO_LOW);
				switch(i){
				case 0:{
					switch(j){
					case 3:
						return 'A';
					case 2:
						return 'B';
					case 1:
						return 'C';
					case 0:
						return 'D';
					}
					break;
				}
				case 1:{
					switch(j){
					case 3:
						return '3';
					case 2:
						return '6';
					case 1:
						return '9';
					case 0:
						return '#';
					}
					break;
				}
				case 2:{
					switch(j){
					case 3:
						return '2';
					case 2:
						return '5';
					case 1:
						return '8';
					case 0:
						return '0';
					}
					break;
				}
				case 3:{
					switch(j){
					case 3:
						return '1';
					case 2:
						return '4';
					case 1:
						return '7';
					case 0:
						return '*';
					}
					break;
				}}
			}
		}
		MCAL_GPIO_writePin(KEYPAD_Port, KEYPAD_col[i], GPIO_LOW);
	}
	return '\0';
}																	
