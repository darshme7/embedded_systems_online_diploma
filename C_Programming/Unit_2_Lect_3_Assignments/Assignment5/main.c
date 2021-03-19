/*
 * main.c
 *
 *  Created on: Mar 19, 2021
 *      Author: mosta
 */
#include "stdio.h"

void main()
{
	char x ;
	printf("Enter a character: ");
	fflush(stdout);
	scanf("%c",&x);
	printf("ASCII value of %c = %d",x,x);

}



