/*
 * main.c
 *
 *  Created on: Mar 19, 2021
 *      Author: mosta
 */
#include "stdio.h"

void main()
{
	int n,i,sum=0;
	printf("Enter an integer: ");
	fflush(stdout);
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		sum+=i;
	printf("Sum = %d",sum);

}



