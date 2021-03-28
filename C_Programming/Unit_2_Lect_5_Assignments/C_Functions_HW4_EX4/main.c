/*
 * main.c
 *
 *  Created on: Mar 28, 2021
 *      Author: mosta
 */
//C_Functions_HW4_EX4

#include "stdio.h"

int powerOfNum(int num,int pow);

int main ()
{
	int	num,pow,res;
	printf("Enter base number:");
	fflush(stdout);
	scanf("%d",&num);
	printf("Enter power number(positive integer): ");
	fflush(stdout);
	scanf("%d",&pow);
	res=powerOfNum(num,pow);
	printf("%d^%d = %d",num,pow,res);


	return 0;
}

int powerOfNum(int num,int pow)
{
	if(pow>0){
		pow--;
		return num*powerOfNum(num,pow);
	}
	else
		return 1;
}
