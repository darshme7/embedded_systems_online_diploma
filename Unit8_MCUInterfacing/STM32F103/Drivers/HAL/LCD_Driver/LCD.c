/*
 * LCD.c
 *
 * Created: 27-May-21 7:53:16 PM
 *  Author: Mostafa
 */ 

#include "LCD.h"

GPIO_config cfg;

uint8 LCD_cursor_position;
uint8 LCD_Pins[]= {GPIO_PIN3,GPIO_PIN4,GPIO_PIN5,GPIO_PIN6,RS,RW,EN};

void delay_ms(uint32 d){

	uint32 i,j;
	for(i=0;i<d;i++)
		for(j=0;j<255;j++);
}

void LCD_kick(void){

	MCAL_GPIO_writePin(LCD_control, EN, GPIO_HIGH);
	delay_ms(10);
	MCAL_GPIO_writePin(LCD_control, EN, GPIO_LOW);
}

void LCD_isBusy(void){

	uint8 i;
	for(i=0;i<SHIFT;i++){
		cfg.GPIO_PinNumber 		= LCD_Pins[i];
		cfg.GPIO_PinMode   		= GPIO_MODE_INPUT_PD;
		cfg.GPIO_OutputSpeed 	= GPIO_INPUT;
		MCAL_GPIO_init(LCD_PORT,&cfg);
	}

	MCAL_GPIO_writePin(LCD_control, RS, GPIO_LOW);
	MCAL_GPIO_writePin(LCD_control, RW, GPIO_HIGH);
	LCD_kick();
	while(MCAL_GPIO_readPin(LCD_PORT, LCD_Pins[SHIFT-1]) == BUSY)LCD_kick();
	MCAL_GPIO_writePin(LCD_control, RW, GPIO_LOW);
	for(i=0;i<SHIFT;i++){
		cfg.GPIO_PinNumber 		= LCD_Pins[i];
		cfg.GPIO_PinMode   		= GPIO_MODE_OUTPUT_PP;
		cfg.GPIO_OutputSpeed 	= GPIO_SPEED_10M;
		MCAL_GPIO_init(LCD_PORT,&cfg);
	}
}

void LCD_sendCommand(uint8 command){

#ifdef LCD_8_BIT_MODE
	LCD_isBusy();
	MCAL_GPIO_writePort(LCD_PORT,command);
#endif

#ifdef LCD_4_BIT_MODE
	LCD_isBusy();
	MCAL_GPIO_writePort(LCD_PORT,(command>>1));
	MCAL_GPIO_writePin(LCD_control, RS, GPIO_LOW);
	MCAL_GPIO_writePin(LCD_control, RW, GPIO_LOW);
	LCD_kick();
    MCAL_GPIO_writePort(LCD_PORT,(command<<3));
#endif
	MCAL_GPIO_writePin(LCD_control, RS, GPIO_LOW);
	MCAL_GPIO_writePin(LCD_control, RW, GPIO_LOW);
	LCD_kick();
}

void LCD_clearScreen(void){
	LCD_sendCommand(LCD_CLEAR_DISPLAY);
	LCD_cursor_position = 0;
}

void LCD_init(void){

	uint8 i;
	delay_ms(250);

	for(i=0;i<(SHIFT+3);i++){
		cfg.GPIO_PinNumber 		= LCD_Pins[i];
		cfg.GPIO_PinMode   		= GPIO_MODE_OUTPUT_PP;
		cfg.GPIO_OutputSpeed 	= GPIO_SPEED_10M;
		MCAL_GPIO_init(LCD_PORT,&cfg);
		MCAL_GPIO_writePin(LCD_PORT, LCD_Pins[i], GPIO_LOW);
	}

	delay_ms(150);

#ifdef LCD_8_BIT_MODE
	LCD_sendCommand(LCD_8BITS_2LINES_5X8);
#endif

#ifdef LCD_4_BIT_MODE
	LCD_sendCommand(LCD_4BITS_2LINES_5X8);
#endif

	LCD_sendCommand(LCD_ENTRY_INC);
	LCD_sendCommand(LCD_FIRST_LINE);
	LCD_sendCommand(LCD_DISPLAY_ON_CURSOR_BLINK);
	LCD_sendCommand(LCD_RETURN_HOME);

	//1000 0000 =0x80 	 1100 0000	= 0xC0		 1001 0100=0x94		1101 1000 = 0xD4
}

void LCD_printChar(uint8 data){

	if(LCD_cursor_position == 64){
		LCD_clearScreen();
		LCD_goToXY(0,0);
	}

#ifdef LCD_8_BIT_MODE
	LCD_isBusy();
	MCAL_GPIO_writePort(LCD_PORT,data);
#endif

#ifdef LCD_4_BIT_MODE
	LCD_isBusy();
	MCAL_GPIO_writePort(LCD_PORT,(data>>1));
	MCAL_GPIO_writePin(LCD_control, RS, GPIO_HIGH);
	MCAL_GPIO_writePin(LCD_control, RW, GPIO_LOW);
	LCD_kick();
	MCAL_GPIO_writePort(LCD_PORT,(data<<3));
#endif
	MCAL_GPIO_writePin(LCD_control, RS, GPIO_HIGH);
	MCAL_GPIO_writePin(LCD_control, RW, GPIO_LOW);
	LCD_kick();
	LCD_cursor_position++;

	if( LCD_cursor_position == 16){

		LCD_goToXY(1,0);
	}else if( LCD_cursor_position == 32){

		LCD_goToXY(2,0);
	}else if( LCD_cursor_position == 48){

		LCD_goToXY(3,0);
	}
}


void LCD_printString(char * data){

	while(*data != '\0'){
		LCD_printChar(*data);
		data++;
	}
}
void LCD_goToXY(unsigned char line ,unsigned char position){

	switch(line){
	case 0:{
		if(position < 16 && position >=0){
			LCD_sendCommand(LCD_FIRST_LINE+position);
			LCD_cursor_position = position;
		}
		break;
	}

	case 1:{

		if(position <16 && position>=0){
			LCD_sendCommand(LCD_SECOND_LINE+position);
			LCD_cursor_position = position+16;
		}
		break;
	}
	case 2:{

		if(position <16 && position>=0){
			LCD_sendCommand(LCD_THIRD_LINE+position);
			LCD_cursor_position = position+32;
		}
		break;
	}

	case 3:{

		if(position <16 && position>=0){
			LCD_sendCommand(LCD_FOURTH_LINE+position);
			LCD_cursor_position = position+48;
		}
		break;
	}

	}
}
