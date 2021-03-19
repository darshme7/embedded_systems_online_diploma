/*
 * main.c
 *
 *  Created on: Mar 19, 2021
 *      Author: mosta
 */
#include "stdio.h"

void main()
{
	int x ,y;
	printf("Enter two integers: ");
	fflush(stdout);
	scanf("%d%d",&x,&y);
	printf("sum: %d",x+y);

}

