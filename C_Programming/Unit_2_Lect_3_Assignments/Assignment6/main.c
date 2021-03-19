/*
 * main.c
 *
 *  Created on: Mar 19, 2021
 *      Author: mosta
 */
#include "stdio.h"

void main()
{
	float a,b,c ;
	printf("Enter value of a: ");
	fflush(stdout);
	scanf("%f",&a);
	printf("Enter value of b: ");
	fflush(stdout);
	scanf("%f",&b);
	c=a;
	a=b;
	b=c;
	printf("\nafter swapping, value of a= %1.2f \n",a);
	printf("after swapping, value of b= %1.1f",b);

}





