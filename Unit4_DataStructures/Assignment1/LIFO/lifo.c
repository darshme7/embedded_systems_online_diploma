/*
 * lifo.c
 *
 *  Created on: Apr 30, 2021
 *      Author: mosta
 */
#include"lifo.h"

LIFO_STATS LIFO_Init(LIFO_DATA_TYPE * container ,LIFO_buffer *buffer){

	if(container==NULL||LIFO_LENGTH<=0)
		return LIFO_NULL;

	buffer->length=LIFO_LENGTH;
	buffer->count=0;
	buffer->base=container;
	buffer->head=buffer->base;
	return LIFO_NO_ERROR;

}
LIFO_STATS LIFO_Push(LIFO_buffer * buffer,LIFO_DATA_TYPE   item){
	if(!buffer||!buffer->base||!buffer->head)
		return LIFO_NULL;

	if(LIFO_Is_Full(buffer)==LIFO_FULL)
		return LIFO_FULL;

	*buffer->head=item;
	buffer->count++;
	buffer->head++;
	return LIFO_NO_ERROR;

}
LIFO_STATS LIFO_Pop(LIFO_buffer *  buffer,LIFO_DATA_TYPE * item){

	if(!buffer||!buffer->base||!buffer->head)
		return LIFO_NULL;

	if(buffer->base==buffer->head)
		return LIFO_EMPTY;

	buffer->head--;
	*item=*(buffer->head);
	buffer->count--;

	return LIFO_NO_ERROR;
}
LIFO_STATS LIFO_Is_Full(LIFO_buffer * buffer){

	if(!buffer||!buffer->base||!buffer->head)
		return LIFO_NULL;

	if(buffer->count==buffer->length)
		return LIFO_FULL;

	return LIFO_NO_ERROR;

}
void LIFO_Print(LIFO_buffer * buffer){

	printf("=======LIFO_Print=======\n");

	if(!buffer||!buffer->base||!buffer->head)
		printf("LIFO NULL\n");

	else if(buffer->count==0)
		printf("LIFO Empty\n");

	else{
		int i;
		LIFO_DATA_TYPE * temp =buffer->base;

		for(i=0;i<buffer->count;i++){
			printf("\t   %u\n",*temp);
			temp++;
		}
	}
	printf("========================\n");
}
