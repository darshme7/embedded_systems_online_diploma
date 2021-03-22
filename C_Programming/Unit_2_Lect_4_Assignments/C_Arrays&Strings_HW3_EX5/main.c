/*
 * main.c
 *
 *  Created on: Mar 22, 2021
 *      Author: mosta
 */
#include "stdio.h"


void main ()
{
	int a[100];
	int i,j;

	printf("Enter no of elements : ");
	fflush(stdout);
	scanf("%d",&i);

	printf("\n");
	for(j=0;j<i;j++){
		a[j]=(j+1)*11;
		printf("%d ",a[j]);
	}

	printf("\n\nEnter the element to be searched for : ");
	fflush(stdout);
	scanf("%d",&a[i]);

	for(j=0;j<i;j++){

		if(a[j]==a[i]){

			printf("\nnumber found at location = %d",j+1);
			break;
		}
	}
}


