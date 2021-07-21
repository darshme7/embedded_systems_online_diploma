/*
 * LEDCube.h
 *
 *  Created on: Jun 7, 2021
 *      Author: mosta
 */

#include "stm32f103c6_gpio_driver.h"

#ifndef INCLUDE_LEDCUBE_H_
#define INCLUDE_LEDCUBE_H_

#define LAYER0						GPIO_PIN0
#define LAYER1						GPIO_PIN1
#define LAYER2						GPIO_PIN12

#define COL0						GPIO_PIN0
#define COL1						GPIO_PIN1
#define COL2						GPIO_PIN2
#define COL3						GPIO_PIN3
#define COL4						GPIO_PIN4
#define COL5						GPIO_PIN5
#define COL6						GPIO_PIN6
#define COL7						GPIO_PIN7
#define COL8						GPIO_PIN8
#define COL9						GPIO_PIN9
#define COL10						GPIO_PIN10
#define COL12						GPIO_PIN12

#define COL11						GPIO_PIN11
#define COL13						GPIO_PIN13
#define COL14						GPIO_PIN14
#define COL15						GPIO_PIN15

void LEDCUBE_init(void);
void LEDCUBE_allOn(void);
void LEDCUBE_layerByLayer(void);
void LEDCUBE_colByCol(void);
void LEDCUBE_ledByLed(void);
void LEDCUBE_faces(void);
void LEDCUBE_smallCubeBigCube(void);


#endif /* INCLUDE_LEDCUBE_H_ */
