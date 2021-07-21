/*
 * LEDCube.c
 *
 *  Created on: Jun 7, 2021
 *      Author: mosta
 */
#include "LEDCube.h"

uint8 Layer[]	= {LAYER0,LAYER1,LAYER2};
uint8 Col[]		= {COL0,COL1,COL2,COL3,COL4,COL5,COL6,COL7,COL8,COL9,COL10,COL11,COL12,COL13,COL14,COL15};



void delay(uint32 d){

	uint32 i,j;
	for(i=0;i<d;i++)
		for(j=0;j<255;j++);
}

void LEDCUBE_init(void){
	uint8 i;
	GPIO_config cfg;

	for(i=0;i<16;i++){
		cfg.GPIO_PinNumber 		= Col[i];
		cfg.GPIO_PinMode   		= GPIO_MODE_OUTPUT_PP;
		cfg.GPIO_OutputSpeed	= GPIO_SPEED_10M;
		if(Col[i] == COL11||Col[i] == COL13||Col[i] == COL14||Col[i] == COL15){
			MCAL_GPIO_init(GPIOB,&cfg);
			MCAL_GPIO_writePin(GPIOB, Col[i],GPIO_LOW);
		}
		else{
			MCAL_GPIO_init(GPIOA,&cfg);
			MCAL_GPIO_writePin(GPIOA, Col[i],GPIO_LOW);
		}
	}

	cfg.GPIO_PinNumber 			= GPIO_PIN0 ;
	cfg.GPIO_PinMode   			= GPIO_MODE_OUTPUT_PP;
	cfg.GPIO_OutputSpeed		= GPIO_SPEED_10M;
	MCAL_GPIO_init(GPIOB,&cfg);
	MCAL_GPIO_writePin(GPIOB, LAYER0,GPIO_HIGH);

	cfg.GPIO_PinNumber 			= GPIO_PIN1 ;
	cfg.GPIO_PinMode   			= GPIO_MODE_OUTPUT_PP;
	cfg.GPIO_OutputSpeed		= GPIO_SPEED_10M;
	MCAL_GPIO_init(GPIOB,&cfg);
	MCAL_GPIO_writePin(GPIOB, LAYER1,GPIO_HIGH);

	cfg.GPIO_PinNumber 			= GPIO_PIN12 ;
	cfg.GPIO_PinMode   			= GPIO_MODE_OUTPUT_PP;
	cfg.GPIO_OutputSpeed		= GPIO_SPEED_10M;
	MCAL_GPIO_init(GPIOB,&cfg);
	MCAL_GPIO_writePin(GPIOB, LAYER2,GPIO_HIGH);

}
void LEDCUBE_allOn(void){

	MCAL_GPIO_writePin(GPIOB, LAYER0, GPIO_LOW);
	MCAL_GPIO_writePin(GPIOB, LAYER1, GPIO_LOW);
	MCAL_GPIO_writePin(GPIOB, LAYER2, GPIO_LOW);
	MCAL_GPIO_writePort(GPIOA, 0x17FF);
	MCAL_GPIO_writePin(GPIOB, COL11, GPIO_HIGH);
	MCAL_GPIO_writePin(GPIOB, COL13, GPIO_HIGH);
	MCAL_GPIO_writePin(GPIOB, COL14, GPIO_HIGH);
	MCAL_GPIO_writePin(GPIOB, COL15, GPIO_HIGH);

	delay(1500);

	MCAL_GPIO_writePort(GPIOA, 0x0000);
	MCAL_GPIO_writePin(GPIOB, COL11, GPIO_LOW);
	MCAL_GPIO_writePin(GPIOB, COL13, GPIO_LOW);
	MCAL_GPIO_writePin(GPIOB, COL14, GPIO_LOW);
	MCAL_GPIO_writePin(GPIOB, COL15, GPIO_LOW);
	MCAL_GPIO_writePin(GPIOB, LAYER0, GPIO_HIGH);
	MCAL_GPIO_writePin(GPIOB, LAYER1, GPIO_HIGH);
	MCAL_GPIO_writePin(GPIOB, LAYER2, GPIO_HIGH);
}
void LEDCUBE_layerByLayer(void){

	uint8 i;
	for(i=0;i<3;i++){
		MCAL_GPIO_writePin(GPIOB, Layer[i], GPIO_LOW);
		MCAL_GPIO_writePort(GPIOA, 0x17FF);
		MCAL_GPIO_writePin(GPIOB, COL11, GPIO_HIGH);
		MCAL_GPIO_writePin(GPIOB, COL13, GPIO_HIGH);
		MCAL_GPIO_writePin(GPIOB, COL14, GPIO_HIGH);
		MCAL_GPIO_writePin(GPIOB, COL15, GPIO_HIGH);
		delay(400);
		MCAL_GPIO_writePin(GPIOB, Layer[i], GPIO_HIGH);
		MCAL_GPIO_writePort(GPIOA, 0x0000);
		MCAL_GPIO_writePin(GPIOB, COL11, GPIO_LOW);
		MCAL_GPIO_writePin(GPIOB, COL13, GPIO_LOW);
		MCAL_GPIO_writePin(GPIOB, COL14, GPIO_LOW);
		MCAL_GPIO_writePin(GPIOB, COL15, GPIO_LOW);
	}
	for(i=3;i>0;i--){
		MCAL_GPIO_writePin(GPIOB, Layer[i-1], GPIO_LOW);
		MCAL_GPIO_writePort(GPIOA, 0x17FF);
		MCAL_GPIO_writePin(GPIOB, COL11, GPIO_HIGH);
		MCAL_GPIO_writePin(GPIOB, COL13, GPIO_HIGH);
		MCAL_GPIO_writePin(GPIOB, COL14, GPIO_HIGH);
		MCAL_GPIO_writePin(GPIOB, COL15, GPIO_HIGH);
		delay(400);
		MCAL_GPIO_writePin(GPIOB, Layer[i-1], GPIO_HIGH);
		MCAL_GPIO_writePort(GPIOA, 0x0000);
		MCAL_GPIO_writePin(GPIOB, COL11, GPIO_LOW);
		MCAL_GPIO_writePin(GPIOB, COL13, GPIO_LOW);
		MCAL_GPIO_writePin(GPIOB, COL14, GPIO_LOW);
		MCAL_GPIO_writePin(GPIOB, COL15, GPIO_LOW);
	}
}
void LEDCUBE_colByCol(void){

	uint8 j;
	MCAL_GPIO_writePin(GPIOB, LAYER0, GPIO_LOW);
	MCAL_GPIO_writePin(GPIOB, LAYER1, GPIO_LOW);
	MCAL_GPIO_writePin(GPIOB, LAYER2, GPIO_LOW);

	for(j=0;j<16;j++){
		if(Col[j] == COL11||Col[j] == COL13||Col[j] == COL14||Col[j] == COL15){
			MCAL_GPIO_writePin(GPIOB, Col[j],GPIO_HIGH);
		}
		else{
			MCAL_GPIO_writePin(GPIOA, Col[j],GPIO_HIGH);
		}
		delay(150);
		if(Col[j] == COL11||Col[j] == COL13||Col[j] == COL14||Col[j] == COL15){
			MCAL_GPIO_writePin(GPIOB, Col[j],GPIO_LOW);
		}
		else{
			MCAL_GPIO_writePin(GPIOA, Col[j],GPIO_LOW);
		}
	}
	MCAL_GPIO_writePin(GPIOB, LAYER0, GPIO_HIGH);
	MCAL_GPIO_writePin(GPIOB, LAYER1, GPIO_HIGH);
	MCAL_GPIO_writePin(GPIOB, LAYER2, GPIO_HIGH);
}
void LEDCUBE_ledByLed(void){

	uint8 i,j;
	for(i=0;i<3;i++){
		MCAL_GPIO_writePin(GPIOB, Layer[i], GPIO_LOW);
		for(j=0;j<16;j++){
			if(Col[j] == COL11||Col[j] == COL13||Col[j] == COL14||Col[j] == COL15){
				MCAL_GPIO_writePin(GPIOB, Col[j],GPIO_HIGH);
			}
			else{
				MCAL_GPIO_writePin(GPIOA, Col[j],GPIO_HIGH);
			}
			delay(100);
			if(Col[j] == COL11||Col[j] == COL13||Col[j] == COL14||Col[j] == COL15){
				MCAL_GPIO_writePin(GPIOB, Col[j],GPIO_LOW);
			}
			else{
				MCAL_GPIO_writePin(GPIOA, Col[j],GPIO_LOW);
			}
		}
		MCAL_GPIO_writePin(GPIOB, Layer[i], GPIO_HIGH);
	}
}
void LEDCUBE_smallCubeBigCube(void){
	uint8 i;
	for(i=0;i<4;i++){
		MCAL_GPIO_writePin(GPIOB, Layer[0], GPIO_LOW);
		MCAL_GPIO_writePin(GPIOB, Layer[1], GPIO_LOW);
		MCAL_GPIO_writePin(GPIOA, Col[5], GPIO_HIGH);
		MCAL_GPIO_writePin(GPIOA, Col[6], GPIO_HIGH);
		MCAL_GPIO_writePin(GPIOA, Col[9], GPIO_HIGH);
		MCAL_GPIO_writePin(GPIOA, Col[10], GPIO_HIGH);
		delay(1500);
		MCAL_GPIO_writePin(GPIOB, Layer[0], GPIO_HIGH);
		MCAL_GPIO_writePin(GPIOB, Layer[1], GPIO_HIGH);
		MCAL_GPIO_writePin(GPIOA, Col[5], GPIO_LOW);
		MCAL_GPIO_writePin(GPIOA, Col[6], GPIO_LOW);
		MCAL_GPIO_writePin(GPIOA, Col[9], GPIO_LOW);
		MCAL_GPIO_writePin(GPIOA, Col[10], GPIO_LOW);

		MCAL_GPIO_writePin(GPIOB, Layer[0], GPIO_LOW);
		MCAL_GPIO_writePin(GPIOB, Layer[1], GPIO_LOW);
		MCAL_GPIO_writePin(GPIOB, Layer[2], GPIO_LOW);
		MCAL_GPIO_writePin(GPIOA, Col[0], GPIO_HIGH);
		MCAL_GPIO_writePin(GPIOA, Col[3], GPIO_HIGH);
		MCAL_GPIO_writePin(GPIOA, Col[12], GPIO_HIGH);
		MCAL_GPIO_writePin(GPIOB, Col[15], GPIO_HIGH);
		delay(1500);
		MCAL_GPIO_writePin(GPIOB, Layer[0], GPIO_HIGH);
		MCAL_GPIO_writePin(GPIOB, Layer[1], GPIO_HIGH);
		MCAL_GPIO_writePin(GPIOB, Layer[2], GPIO_HIGH);
		MCAL_GPIO_writePin(GPIOA, Col[0], GPIO_LOW);
		MCAL_GPIO_writePin(GPIOA, Col[3], GPIO_LOW);
		MCAL_GPIO_writePin(GPIOA, Col[12], GPIO_LOW);
		MCAL_GPIO_writePin(GPIOB, Col[15], GPIO_LOW);
	}
}
void LEDCUBE_faces(void){
	uint8 i;
	MCAL_GPIO_writePin(GPIOB, Layer[0], GPIO_LOW);
	MCAL_GPIO_writePin(GPIOB, Layer[1], GPIO_LOW);
	MCAL_GPIO_writePin(GPIOB, Layer[2], GPIO_LOW);
	for(i=0;i<4;i++){
		MCAL_GPIO_writePin(GPIOA, Col[0+i], GPIO_HIGH);
		MCAL_GPIO_writePin(GPIOA, Col[4+i], GPIO_HIGH);
		if(Col[8+i]==COL11)
			MCAL_GPIO_writePin(GPIOB, Col[8+i], GPIO_HIGH);
		else
			MCAL_GPIO_writePin(GPIOA, Col[8+i], GPIO_HIGH);
		if(Col[12+i]==COL13||Col[12+i]==COL14||Col[12+i]==COL15)
			MCAL_GPIO_writePin(GPIOB, Col[12+i], GPIO_HIGH);
		else
			MCAL_GPIO_writePin(GPIOA, Col[12+i], GPIO_HIGH);
		delay(400);

		MCAL_GPIO_writePin(GPIOA, Col[0+i], GPIO_LOW);
		MCAL_GPIO_writePin(GPIOA, Col[4+i], GPIO_LOW);
		if(Col[8+i]==COL11)
			MCAL_GPIO_writePin(GPIOB, Col[8+i], GPIO_LOW);
		else
			MCAL_GPIO_writePin(GPIOA, Col[8+i], GPIO_LOW);
		if(Col[12+i]==COL13||Col[12+i]==COL14||Col[12+i]==COL15)
			MCAL_GPIO_writePin(GPIOB, Col[12+i], GPIO_LOW);
		else
			MCAL_GPIO_writePin(GPIOA, Col[12+i], GPIO_LOW);

	}

	for(i=4;i>0;i--){
		MCAL_GPIO_writePin(GPIOA, Col[0+i-1], GPIO_HIGH);
		MCAL_GPIO_writePin(GPIOA, Col[3+i], GPIO_HIGH);
		if(Col[7+i]==COL11)
			MCAL_GPIO_writePin(GPIOB, Col[7+i], GPIO_HIGH);
		else
			MCAL_GPIO_writePin(GPIOA, Col[7+i], GPIO_HIGH);
		if(Col[11+i]==COL13||Col[11+i]==COL14||Col[11+i]==COL15)
			MCAL_GPIO_writePin(GPIOB, Col[11+i], GPIO_HIGH);
		else
			MCAL_GPIO_writePin(GPIOA, Col[11+i], GPIO_HIGH);
		delay(400);
		MCAL_GPIO_writePin(GPIOA, Col[0+i-1], GPIO_LOW);
		MCAL_GPIO_writePin(GPIOA, Col[3+i], GPIO_LOW);
		if(Col[7+i]==COL11)
			MCAL_GPIO_writePin(GPIOB, Col[7+i], GPIO_LOW);
		else
			MCAL_GPIO_writePin(GPIOA, Col[7+i], GPIO_LOW);
		if(Col[11+i]==COL13||Col[11+i]==COL14||Col[11+i]==COL15)
			MCAL_GPIO_writePin(GPIOB, Col[11+i], GPIO_LOW);
		else
			MCAL_GPIO_writePin(GPIOA, Col[11+i], GPIO_LOW);

	}
	MCAL_GPIO_writePin(GPIOB, Layer[0], GPIO_HIGH);
	MCAL_GPIO_writePin(GPIOB, Layer[1], GPIO_HIGH);
	MCAL_GPIO_writePin(GPIOB, Layer[2], GPIO_HIGH);
}

