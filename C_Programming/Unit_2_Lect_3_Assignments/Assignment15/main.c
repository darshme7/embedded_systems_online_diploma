/*
 * main.c
 *
 *  Created on: Mar 19, 2021
 *      Author: mosta
 */
#include "stdio.h"

void main()
{
	float a,b;
	char o;
	printf("Enter operator either + or - or * or / : ");
	fflush(stdout);
	scanf("%c",&o);
	printf("Enter two operands: ");
	fflush(stdout);
	scanf("%f%f",&a,&b);
	switch(o){
	case '+':
		printf("%.1f %c %.1f = %.1f",a,o,b,a+b);
		break;
	case '-':
		printf("%.1f %c %.1f = %.1f",a,o,b,a-b);
		break;
	case '*':
		printf("%.1f %c %.1f = %.1f",a,o,b,a*b);
		break;
	case '/':
		printf("%.1f %c %.1f = %.1f",a,o,b,a/b);
		break;
	default:
		printf("wrong entry");
		break;
	}
}


