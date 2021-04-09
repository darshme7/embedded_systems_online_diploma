/*
 * main.c
 *
 *  Created on: Apr 10, 2021
 *      Author: mosta
 */

//C_Pointers_HW6_EX4
#include "stdio.h"
#include "string.h"
int main(){

	int *p_alpha,input[15];
	int i,size;

	printf("Input number of elements to store in array (max 15) : ");
	fflush(stdout);fflush(stdin);
	scanf("%d",&size);
	printf("Input %d number of elements in the array : \n",size);
	for(i=0;i<size;i++){
		printf("element-%d : ",i+1);
		fflush(stdout);fflush(stdin);
		scanf("%d",&input[i]);
	}

	printf("The elements of array in reverse order are : ");
	p_alpha=&input[size-1];
	for(i=size-1;i>=0;i--,p_alpha--)
		printf("\nelement-%d : %d",i+1,*p_alpha);


	return 0;
}



