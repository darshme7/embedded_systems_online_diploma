/*
 * 7segment.c
 *
 *  Created on: Jun 2, 2021
 *      Author: Mostafa
 */

#include "7segment.h"

uint8 numbers[] =
{		ZERO,
		ONE,
		TWO,
		THREE,
		FOUR,
		FIVE,
		SIX,
		SEVEN,
		EIGHT,
		NINE
};

void _7segment_init(){

	GPIO_config cfg;

	cfg.GPIO_PinNumber 		= _7SEGMENT_A;
	cfg.GPIO_PinMode   		= GPIO_MODE_OUTPUT_PP;
	cfg.GPIO_OutputSpeed	= GPIO_SPEED_10M;
	MCAL_GPIO_init(_7SEGMENT_Port, &cfg);
	cfg.GPIO_PinNumber 		= _7SEGMENT_B;
	cfg.GPIO_PinMode   		= GPIO_MODE_OUTPUT_PP;
	cfg.GPIO_OutputSpeed	= GPIO_SPEED_10M;
	MCAL_GPIO_init(_7SEGMENT_Port, &cfg);
	cfg.GPIO_PinNumber 		= _7SEGMENT_C;
	cfg.GPIO_PinMode   		= GPIO_MODE_OUTPUT_PP;
	cfg.GPIO_OutputSpeed	= GPIO_SPEED_10M;
	MCAL_GPIO_init(_7SEGMENT_Port, &cfg);
	cfg.GPIO_PinNumber 		= _7SEGMENT_D;
	cfg.GPIO_PinMode   		= GPIO_MODE_OUTPUT_PP;
	cfg.GPIO_OutputSpeed	= GPIO_SPEED_10M;
	MCAL_GPIO_init(_7SEGMENT_Port, &cfg);
	cfg.GPIO_PinNumber 		= _7SEGMENT_E;
	cfg.GPIO_PinMode   		= GPIO_MODE_OUTPUT_PP;
	cfg.GPIO_OutputSpeed	= GPIO_SPEED_10M;
	MCAL_GPIO_init(_7SEGMENT_Port, &cfg);
	cfg.GPIO_PinNumber 		= _7SEGMENT_F;
	cfg.GPIO_PinMode   		= GPIO_MODE_OUTPUT_PP;
	cfg.GPIO_OutputSpeed	= GPIO_SPEED_10M;
	MCAL_GPIO_init(_7SEGMENT_Port, &cfg);
	cfg.GPIO_PinNumber 		= _7SEGMENT_G;
	cfg.GPIO_PinMode   		= GPIO_MODE_OUTPUT_PP;
	cfg.GPIO_OutputSpeed	= GPIO_SPEED_10M;
	MCAL_GPIO_init(_7SEGMENT_Port, &cfg);

	MCAL_GPIO_writePort(_7SEGMENT_Port,((0x7F)<<_7SEGMENT_A));

}

void _7segment_printNumber(uint8 number){

	MCAL_GPIO_writePort(_7SEGMENT_Port, numbers[number]<<_7SEGMENT_A);
}

