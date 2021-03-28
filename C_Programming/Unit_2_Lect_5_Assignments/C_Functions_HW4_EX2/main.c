/*
 * main.c
 *
 *  Created on: Mar 28, 2021
 *      Author: mosta
 */
//C_Functions_HW4_EX2
#include "stdio.h"

int factorial(int x);

int main ()
{
	int x ,y;
	printf("Enter a positive integer:");
	fflush(stdout);
	scanf("%d",&x);
	y=factorial(x);
	printf("Factorial of %d = %d",x,y);
	return 0;
}

int factorial(int x)
{
	if(x>1)
	return x*factorial(x-1);
	else
	return 1;

}





