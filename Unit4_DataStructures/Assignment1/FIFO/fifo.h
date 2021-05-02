/*
 * fifo.h
 *
 *  Created on: May 1, 2021
 *      Author: mosta
 */

#ifndef FIFO_H_
#define FIFO_H_

#include"stdio.h"
#include"stdlib.h"

#define FIFO_LENGTH 5               // length of buffer should be set here default is 5

#define FIFO_DATA_TYPE unsigned int //Data type is set here default is unsigned int

typedef struct{
	unsigned int length;
	unsigned int count;
	FIFO_DATA_TYPE *base;
	FIFO_DATA_TYPE *head;
	FIFO_DATA_TYPE *tail;

}FIFO_buffer;

typedef enum{
	FIFO_NULL,
	FIFO_FULL,
	FIFO_EMPTY,
	FIFO_NO_ERROR
}FIFO_STATS;

FIFO_STATS FIFO_Init(FIFO_DATA_TYPE * container,FIFO_buffer * buffer);
FIFO_STATS FIFO_Enqueue(FIFO_buffer * buffer,FIFO_DATA_TYPE   item);
FIFO_STATS FIFO_Dequeue(FIFO_buffer *  buffer,FIFO_DATA_TYPE * item);
FIFO_STATS FIFO_Is_Full(FIFO_buffer * buffer);
void FIFO_Print(FIFO_buffer * buffer);


#endif /* FIFO_H_ */
