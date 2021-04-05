/*
 * main.c
 *
 *  Created on: Apr 5, 2021
 *      Author: mosta
 */
/*C_StructUnion&Enum_HW5_EX3*/

#include "stdio.h"

struct Scomplex{
	float real;
	float imag;
};

int main(){

	struct Scomplex num1,num2,sum;
	printf("For 1st complex number\n");

	printf("Enter real and imaginary respectively: ");
	fflush(stdout);
	scanf("%f%f",&num1.real,&num1.imag);

	printf("\nFor 2nd complex number\n");

	printf("Enter real and imaginary respectively: ");
	fflush(stdout);
	scanf("%f%f",&num2.real,&num2.imag);

	sum.real=num1.real+num2.real;
	sum.imag=num1.imag+num2.imag;

	printf("Sum=%.1f+%.1fi\n",sum.real,sum.imag);

	return 0;
}


