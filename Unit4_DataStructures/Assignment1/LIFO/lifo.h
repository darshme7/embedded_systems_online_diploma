/*
 * lifo.h
 *
 *  Created on: Apr 30, 2021
 *      Author: mosta
 */

#ifndef LIFO_H_
#define LIFO_H_

#include"stdio.h"
#include "stdlib.h"


#define LIFO_LENGTH 5               // length of buffer should be set here

#define LIFO_DATA_TYPE unsigned int //Data type is set here

typedef struct{
	unsigned int length;
	unsigned int count;
	LIFO_DATA_TYPE *base;
	LIFO_DATA_TYPE *head;
}LIFO_buffer;

typedef enum{
	LIFO_NULL,
	LIFO_FULL,
	LIFO_EMPTY,
	LIFO_NO_ERROR
}LIFO_STATS;

LIFO_STATS LIFO_Init(LIFO_DATA_TYPE * container,LIFO_buffer * buffer);
LIFO_STATS LIFO_Push(LIFO_buffer * buffer,LIFO_DATA_TYPE   item);
LIFO_STATS LIFO_Pop(LIFO_buffer *  buffer,LIFO_DATA_TYPE * item);
LIFO_STATS LIFO_Is_Full(LIFO_buffer * buffer);
void LIFO_Print(LIFO_buffer * buffer);

#endif /* LIFO_H_ */
