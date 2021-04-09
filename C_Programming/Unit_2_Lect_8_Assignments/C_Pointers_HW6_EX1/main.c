/*
 * main.c
 *
 *  Created on: Apr 9, 2021
 *      Author: mosta
 */
//C_Pointers_HW6_EX1
#include "stdio.h"

int main(){
	int m=29;
	printf("Address of m : 0x%p",&m);
	printf("\nValue of m : %d",m);

	int *ab=&m;
	printf("\n\nnow ab is assigned with the address of m");
	printf("\nAddress of pointer ab : 0x%p",ab);
	printf("\nContent of pointer ab : %d",*ab);

	m=34;
	printf("\n\nThe value of m assigned to 34");
	printf("\nAddress of pointer ab : 0x%p",ab);
	printf("\nContent of pointer ab : %d",*ab);
	*ab=7;
	printf("\n\nThe pointer variable ab is assigned with the value 7");
	printf("\nAddress of m : 0x%p",&m);
	printf("\nValue of m : %d",m);

	return 0;
}

