/*
 * LCD.c
 *
 * Created: 27-May-21 7:53:16 PM
 *  Author: Mostafa
 */ 

#include "LCD.h"

GPIO_config cfg;

uint8 LCD_cursor_position;
uint8 LCD_Pins[]= {GPIO_PIN0,GPIO_PIN1, GPIO_PIN2,GPIO_PIN3,GPIO_PIN4,GPIO_PIN5,GPIO_PIN6,GPIO_PIN7,RS,RW,EN};

void delay(uint32 d){

	uint32 i,j;
	for(i=0;i<d;i++)
		for(j=0;j<255;j++);
}

void LCD_kick(void){

	MCAL_GPIO_writePin(LCD_control, EN, GPIO_HIGH);
	delay(1);
	MCAL_GPIO_writePin(LCD_control, EN, GPIO_LOW);
}

void LCD_isBusy(void){

	uint8 i;
	for(i=0;i<8;i++){
		cfg.GPIO_PinNumber 		= LCD_Pins[i];
		cfg.GPIO_PinMode   		= GPIO_MODE_INPUT_FLO;
		cfg.GPIO_OutputSpeed 	= GPIO_INPUT;
		MCAL_GPIO_init(LCD_PORT,&cfg);
	}

	MCAL_GPIO_writePin(LCD_control, RS, GPIO_LOW);
	MCAL_GPIO_writePin(LCD_control, RW, GPIO_HIGH);
	LCD_kick();	
	while(MCAL_GPIO_readPin(LCD_PORT, GPIO_PIN7) == BUSY)LCD_kick();

	MCAL_GPIO_writePin(LCD_control, RW, GPIO_LOW);
	for(i=0;i<8;i++){
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
	MCAL_GPIO_writePort(LCD_PORT,(command & 0xF0));
	MCAL_GPIO_writePin(LCD_control, RS, GPIO_LOW);
	MCAL_GPIO_writePin(LCD_control, RW, GPIO_LOW);
	LCD_kick();
	MCAL_GPIO_writePort(LCD_PORT,(command<<SHIFT_4));
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
	delay(20);

	for(i=0;i<11;i++){
		cfg.GPIO_PinNumber 		= LCD_Pins[i];
		cfg.GPIO_PinMode   		= GPIO_MODE_OUTPUT_PP;
		cfg.GPIO_OutputSpeed 	= GPIO_SPEED_10M;
		MCAL_GPIO_init(LCD_PORT,&cfg);
		MCAL_GPIO_writePin(LCD_PORT, LCD_Pins[i], GPIO_LOW);
	}

	delay(15);

#ifdef LCD_8_BIT_MODE
	LCD_sendCommand(LCD_8BITS_2LINES_5X8);
#endif

#ifdef LCD_4_BIT_MODE
	LCD_sendCommand(LCD_RETURN_HOME);
	LCD_sendCommand(LCD_4BITS_2LINES_5X8);
#endif
	LCD_sendCommand(LCD_ENTRY_INC);
	LCD_sendCommand(LCD_DISPLAY_ON_CURSOR_BLINK);
}

void LCD_printChar(uint8 data){

	if(LCD_cursor_position == 32){
		LCD_clearScreen();
		LCD_goToXY(1,0);
	}

#ifdef LCD_8_BIT_MODE
	LCD_isBusy();
	MCAL_GPIO_writePort(LCD_PORT,data);
#endif

#ifdef LCD_4_BIT_MODE
	MCAL_GPIO_writePort(LCD_PORT,(data & 0xF0));
	MCAL_GPIO_writePin(LCD_control, RS, GPIO_HIGH);
	MCAL_GPIO_writePin(LCD_control, RW, GPIO_LOW);
	LCD_kick();
	MCAL_GPIO_writePort(LCD_PORT,((data & 0x0F)<<SHIFT_4));
#endif
	MCAL_GPIO_writePin(LCD_control, RS, GPIO_HIGH);
	MCAL_GPIO_writePin(LCD_control, RW, GPIO_LOW);
	LCD_kick();
	LCD_cursor_position++;

	if( LCD_cursor_position == 16){

		LCD_goToXY(2,0);
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
	case 1:{
		if(position < 16 && position >=0){
			LCD_sendCommand(LCD_FIRST_LINE+position);
			LCD_cursor_position = position;
		}
		break;
	}

	case 2:{

		if(position <16 && position>=0){
			LCD_sendCommand(LCD_SECOND_LINE+position);
			LCD_cursor_position = position+16;
		}
		break;
	}
	}
}
