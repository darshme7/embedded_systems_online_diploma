/*
 * Keypad.h
 *
 * Created: 28-May-21 5:51:02 PM
 *  Author: Mostafa
 */ 

#include <stm32f103c6_gpio_driver.h>

#ifndef KEYPAD_H_
#define KEYPAD_H_


#define KEYPAD_Port				GPIOB

#define R0						GPIO_PIN0
#define R1						GPIO_PIN1
#define R2						GPIO_PIN3
#define R3						GPIO_PIN4
#define C0						GPIO_PIN5
#define C1						GPIO_PIN6
#define C2						GPIO_PIN7
#define C3						GPIO_PIN8

void KEYPAD_init(void);
char KEYPAD_getChar(void);


#endif /* KEYPAD_H_ */
