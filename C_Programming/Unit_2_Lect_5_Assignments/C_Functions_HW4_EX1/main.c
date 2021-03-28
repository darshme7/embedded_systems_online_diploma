/*
 * main.c
 *
 *  Created on: Mar 28, 2021
 *      Author: mosta
 */
//C_Functions_HW4_EX1

#include "stdio.h"

void primeNumbers(int x,int y);

int main ()
{
	int x,y;
	printf("Enter two numbers(intervals):");
	fflush(stdout);
	scanf("%d%d",&x,&y);
	primeNumbers(x,y);
	return 0;
}

void primeNumbers(int x,int y)
{
	int i;
	printf("Prime numbers between %d and %d are: ",x,y);
	for(i=x;i<=y;i++){

		if((i%2)>0&&(i%3)>0&&(i%5)>0&&(i%7)>0){
			printf("%d ",i);
		}
	}
}



