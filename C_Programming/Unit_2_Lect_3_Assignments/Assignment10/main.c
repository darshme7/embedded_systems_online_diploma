/*
 * main.c
 *
 *  Created on: Mar 19, 2021
 *      Author: mosta
 */
#include "stdio.h"

void main()
{
	float a ,b,c;
	printf("Enter three numbers: ");
	fflush(stdout);
	scanf("%f%f%f",&a,&b,&c);
	if(a>b){

		if(a>c)
			printf("Largest number = %2.2f\n",a);
		else
			printf("Largest number = %2.2f\n" ,c);
	}
	else{
		if(b>c)
			printf("Largest number = %2.2f",b);
		else
			printf("Largest number = %2.2f",c);
	}

}
