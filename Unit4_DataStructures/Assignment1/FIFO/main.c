#include "fifo.h"


int main(){

	FIFO_DATA_TYPE container1[FIFO_LENGTH],i,item;
	FIFO_buffer buff1;


	FIFO_Init(container1,&buff1);

	for(i=0;i<7;i++){
		if(FIFO_Enqueue(&buff1,i)==FIFO_NO_ERROR){
			printf("Enqueue success item= %u\n",i);
		}else if(FIFO_Enqueue(&buff1,i)==FIFO_FULL)
			printf("Enqueue fail: Buffer full\n");
		else
			printf("Enqueue fail: Null buffer\n");
	}

	FIFO_Print(&buff1);

	FIFO_Dequeue(&buff1,&item);
	printf("Dequeue success, item = %u\n",item);

	FIFO_Dequeue(&buff1,&item);
	printf("Dequeue success, item = %u\n",item);

	for(i=5;i<7;i++){
			if(FIFO_Enqueue(&buff1,i)==FIFO_NO_ERROR){
				printf("Enqueue success item= %u\n",i);
			}else if(FIFO_Enqueue(&buff1,i)==FIFO_FULL)
				printf("Enqueue fail: Buffer full\n");
			else
				printf("Enqueue fail: Null buffer\n");
		}

	for(i=0;i<7;i++){
		if(FIFO_Dequeue(&buff1,&item)==FIFO_NO_ERROR){
			printf("Dequeue success, item = %u\n",item);
		}else if(FIFO_Dequeue(&buff1,&item)==FIFO_EMPTY)
			printf("Dequeue fail: Buffer empty\n");
		else
			printf("Dequeue fail: Null buffer\n");
	}


	return 0;
}
