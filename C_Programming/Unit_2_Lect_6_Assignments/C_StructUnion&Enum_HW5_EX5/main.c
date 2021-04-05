/*
 * main.c
 *
 *  Created on: Apr 5, 2021
 *      Author: mosta
 */
/*C_StructUnion&Enum_HW5_EX5*/
#define area(a) a*3.141*a

#include "stdio.h"

int main(){

	float i;
	printf("Enter the radius: ");
	fflush(stdout);
	scanf("%f",&i);

	printf("Area=%.2f\n",area(i));

	return 0;
}




