/*
 * main.c
 *
 *  Created on: Apr 10, 2021
 *      Author: mosta
 */

//C_Pointers_HW6_EX3
#include "stdio.h"
#include "string.h"
int main(){

	char *p_alpha,input[100];
	int i;

	printf("Input a String : ");
	fflush(stdout);fflush(stdin);
	gets(input);

	printf("Reverse of the string : ");
	int size=strlen(input);
	p_alpha=&input[size-1];
	for(i=0;i<size-1;i++,p_alpha--)
		printf("%c",*p_alpha);


	return 0;
}

