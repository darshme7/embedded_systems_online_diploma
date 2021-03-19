/*
 * main.c
 *
 *  Created on: Mar 19, 2021
 *      Author: mosta
 */
#include "stdio.h"

void main()
{
	int n,i,fact=1;
	printf("Enter an integer: ");
	fflush(stdout);
	scanf("%d",&n);
	if(n<0)
		printf("Error!!! Factorial of negative number doesn't exist");
	else if(n==0)
		printf("Factorial = 1");
	else
	{
		for(i=1;i<=n;i++)
			fact*=i;
		printf("Factorial = %d",fact);
	}
}





