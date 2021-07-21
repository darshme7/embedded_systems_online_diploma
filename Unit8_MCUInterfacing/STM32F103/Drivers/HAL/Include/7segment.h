/*
 * 7segment.h
 *
 *  Created on: Jun 2, 2021
 *      Author: Mostafa
 */

#include <stm32f103c6_gpio_driver.h>

#ifndef _7SEGMENT_H_
#define _7SEGMENT_H_

#define _7SEGMENT_Port 					GPIOD

#define _7SEGMENT_A 					GPIO_PIN0
#define _7SEGMENT_B 					GPIO_PIN1
#define _7SEGMENT_C 					GPIO_PIN2
#define _7SEGMENT_D 					GPIO_PIN3
#define _7SEGMENT_E 					GPIO_PIN4
#define _7SEGMENT_F 					GPIO_PIN5
#define _7SEGMENT_G 					GPIO_PIN6

#define ZERO 							0x40
#define ONE 							0x79
#define TWO 							0x24
#define THREE 							0x30
#define FOUR							0x19
#define FIVE 							0x12
#define SIX 							0x02
#define SEVEN 							0x58
#define EIGHT 							0x00
#define NINE 							0x10

void _7segment_init();
void _7segment_printNumber(uint8 number);

#endif /* 7SEGMENT_H_ */
