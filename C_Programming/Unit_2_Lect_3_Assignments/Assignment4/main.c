/*
 * main.c
 *
 *  Created on: Mar 19, 2021
 *      Author: mosta
 */
#include "stdio.h"

void main()
{
	float x ,y;
	printf("Enter two numbers: ");
	fflush(stdout);
	scanf("%f%f",&x,&y);
	printf("product: %f",x*y);

}

