/*
 * LCD.h
 *
 * Created: 27-May-21 7:53:05 PM
 *  Author: Mostafa
 */ 

#include <stm32f103c6_gpio_driver.h>

#ifndef LCD_H_
#define LCD_H_

#define RS		GPIO_PIN0
#define RW		GPIO_PIN1
#define EN		GPIO_PIN2

#define LCD_control						GPIOA
#define LCD_PORT						GPIOA

#define BUSY 								0

#define LCD_8BITS_2LINES_5X8			(0x38)
#define LCD_4BITS_2LINES_5X8			(0x28) //0010 1000
#define LCD_CLEAR_DISPLAY				(0x01)
#define LCD_RETURN_HOME					(0x02) //0000 0010
#define LCD_ENTRY_DEC					(0x04)
#define LCD_ENTRY_INC					(0x06) //0000 0110
#define LCD_ENTRY_DEC_SHIFT				(0x05)
#define LCD_ENTRY_INC_SHIFT				(0x07)
#define LCD_DISPLAY_OFF					(0x08)
#define LCD_DISPLAY_ON					(0x0C)
#define LCD_DISPLAY_ON_CURSOR			(0x0E)
#define LCD_DISPLAY_ON_CURSOR_BLINK		(0x0F) //0000 1111
#define LCD_DISPLAY_SHIFT_RIGHT			(0x1C)
#define LCD_DISPLAY_SHIFT_LEFT			(0x18)
#define LCD_CURSOR_SHIFT_RIGHT			(0x14)
#define LCD_CURSOR_SHIFT_LEFT			(0x10)
#define LCD_FIRST_LINE					(0x80) //1000 0000
#define LCD_SECOND_LINE					(0xC0)
#define LCD_THIRD_LINE					(0x90)
#define LCD_FOURTH_LINE					(0xD0)


#define LCD_4_BIT_MODE				4

#ifndef	LCD_4_BIT_MODE
#define LCD_8_BIT_MODE					8
#define SHIFT							8
#endif

#ifdef	LCD_4_BIT_MODE
#define SHIFT							4
#endif

void LCD_init(void);
void LCD_printChar(uint8 data);
void LCD_printString(char * data);
void LCD_goToXY(uint8 line ,uint8 position);
void LCD_clearScreen(void);
void delay_ms(uint32 d);

#endif /* LCD_H_ */
