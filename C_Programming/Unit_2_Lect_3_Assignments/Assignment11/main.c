/*
 * main.c
 *
 *  Created on: Mar 19, 2021
 *      Author: mosta
 */
#include "stdio.h"

void main()
{
	float a;
	printf("Enter a number: ");
	fflush(stdout);
	scanf("%f",&a);
	if(a>0)
		printf("%.2f is positive.\n" ,a);

	else if(a<0)
		printf("%.2f is negative.\n",a);
	else
		printf("You entered zero.\n");
}

