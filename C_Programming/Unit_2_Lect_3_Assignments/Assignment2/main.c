/*
 * main.c
 *
 *  Created on: Mar 19, 2021
 *      Author: mosta
 */
#include "stdio.h"

void main()
{
	int x;
	printf("Enter an integer:");
	fflush(stdout);
	scanf("%d",&x);
	printf("You entered: %d",x);
}

