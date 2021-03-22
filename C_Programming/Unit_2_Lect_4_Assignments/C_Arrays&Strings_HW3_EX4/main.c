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
		a[j]=j+1;
		printf("%d ",a[j]);
	}

	printf("\n\nEnter the element to be inserted : ");
	fflush(stdout);
	scanf("%d",&a[i]);

	printf("\nEnter the location : ");
	fflush(stdout);
	scanf("%d",&a[i+1]);

	a[a[i+1]-1]=a[i];

	for(j=a[i+1];j<i+1;j++)
		a[j]=j;

	printf("\n");

	for(j=0;j<i+1;j++){

		printf("%d  ",a[j]);
	}
}
