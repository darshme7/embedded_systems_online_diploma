/*
 * main.c
 *
 *  Created on: Apr 30, 2021
 *      Author: mosta
 */

#include "lifo.h"




int main(){

	LIFO_DATA_TYPE container1[LIFO_LENGTH],i,item;
	LIFO_DATA_TYPE * container2;
	LIFO_buffer buff1,buff2;

	container2=(LIFO_DATA_TYPE *)malloc(LIFO_LENGTH*sizeof(LIFO_DATA_TYPE));

	LIFO_Init(container1,&buff1);
	LIFO_Init(container2,&buff2);

	for(i=0;i<7;i++){
		if(LIFO_Push(&buff1,i)==LIFO_NO_ERROR){
			printf("(static buffer)Push success item= %u\n",i);
		}else if(LIFO_Push(&buff1,i)==LIFO_FULL)
			printf("(static buffer)Push fail: Buffer full\n");
		else
			printf("(static buffer)Push fail: Null buffer\n");
	}

	LIFO_Print(&buff1);

	for(i=0;i<7;i++){
		if(LIFO_Pop(&buff1,&item)==LIFO_NO_ERROR){
			printf("(static buffer)Pop success item = %u\n",item);
		}else if(LIFO_Pop(&buff1,&item)==LIFO_EMPTY)
			printf("(static buffer)Pop fail: Buffer empty\n");
		else
			printf("(static buffer)Pop fail: Null buffer\n");
	}

	for(i=0;i<7;i++){
		if(LIFO_Push(&buff2,i)==LIFO_NO_ERROR){
			printf("(dynamic buffer)Push success item= %u\n",i);
		}else if(LIFO_Push(&buff2,i)==LIFO_FULL)
			printf("(dynamic buffer)Push fail: Buffer full\n");
		else
			printf("(dynamic buffer)Push fail: Null buffer\n");
	}



	for(i=0;i<7;i++){
		if(LIFO_Pop(&buff2,&item)==LIFO_NO_ERROR){
			printf("(dynamic buffer)Pop success item = %u\n",item);
		}else if(LIFO_Pop(&buff2,&item)==LIFO_EMPTY)
			printf("(dynamic buffer)Pop fail: Buffer empty\n");
		else
			printf("(dynamic buffer)Pop fail: Null buffer\n");
	}



	return 0;
}
