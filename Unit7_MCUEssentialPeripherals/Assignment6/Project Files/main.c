/*
 * ATmega32.c
 *
 * Created: 17-Jun-21 1:27:37 AM
 * Author : Mostafa
 */ 
#include "HAL/include/LCD.h"

int main(void)
{
	LCD_init();
	LCD_printString("Learn in Depth");
	
	while(1)
	{
		
	}
}