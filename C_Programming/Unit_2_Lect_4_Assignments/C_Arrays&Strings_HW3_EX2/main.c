/*
 * main.c
 *
 *  Created on: Mar 22, 2021
 *      Author: mosta
 */


#include "stdio.h"

void main ()
{
	float a[100];
	int i,j;
	printf("Enter the numbers of data: ");
	fflush(stdout);
	scanf("%d",&j);
	a[j]=0;
	for(i=0;i<j;i++){
		printf("%d.Enter number: ",i+1);
		fflush(stdout);
		scanf("%f",&a[i]);
		a[j]+=a[i];
	}

	printf("Average = %.2f\n",a[j]/j);

}




