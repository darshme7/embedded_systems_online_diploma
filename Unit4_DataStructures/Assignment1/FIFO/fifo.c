/*
 * fifo.c
 *
 *  Created on: May 1, 2021
 *      Author: mosta
 */

#include"fifo.h"

FIFO_STATS FIFO_Init(FIFO_DATA_TYPE * container ,FIFO_buffer *buffer){

	if(container==NULL||FIFO_LENGTH<=0)
		return FIFO_NULL;
	buffer->length=FIFO_LENGTH;
	buffer->count=0;
	buffer->base=container;
	buffer->head=buffer->base;
	buffer->tail=buffer->base;
	return FIFO_NO_ERROR;

}

FIFO_STATS FIFO_Enqueue(FIFO_buffer * buffer,FIFO_DATA_TYPE   item){
	if(!buffer||!buffer->base||!buffer->head)
		return FIFO_NULL;

	if(FIFO_Is_Full(buffer)==FIFO_FULL)
		return FIFO_FULL;

	*buffer->head=item;
	buffer->count++;

	if(buffer->head==(buffer->base)+(buffer->length-1)) /* pointer increment is according to the type of pointer,
	                                                     sizeof() operator is not required */
		buffer->head=buffer->base;
	else
		buffer->head++;

	return FIFO_NO_ERROR;

}
FIFO_STATS FIFO_Dequeue(FIFO_buffer *  buffer,FIFO_DATA_TYPE * item){

	if(!buffer||!buffer->base||!buffer->head)
		return FIFO_NULL;

	if(buffer->count==0)
		return FIFO_EMPTY;


	*item=*(buffer->tail);
	buffer->count--;

	if(	buffer->tail==(buffer->base)+(buffer->length-1))
		buffer->tail=buffer->base;
	else
		buffer->tail++;

	return FIFO_NO_ERROR;
}

FIFO_STATS FIFO_Is_Full(FIFO_buffer * buffer){

	if(!buffer||!buffer->base||!buffer->head)
		return FIFO_NULL;

	if(buffer->count==buffer->length)
		return FIFO_FULL;

	return FIFO_NO_ERROR;

}


void FIFO_Print(FIFO_buffer * buffer){

	printf("=======FIFO_Print=======\n");

	if(!buffer||!buffer->base||!buffer->head)
		printf("FIFO NULL\n");

	else if(buffer->count==0)
		printf("FIFO Empty\n");

	else{
		int i;
		FIFO_DATA_TYPE * temp =buffer->tail;

		for(i=0;i<buffer->count;i++){
			printf("\t   %u\n",*temp);

			if(	temp==(buffer->base)+buffer->length-1)
				temp=buffer->base;
			else
				temp++;

		}
	}
	printf("========================\n");
}
