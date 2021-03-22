/*
 * main.c
 *
 *  Created on: Mar 22, 2021
 *      Author: mosta
 */
#include "stdio.h"

void main(){

	char string[100];
	int i=0;

	printf("Enter a string: ");
	fflush(stdout);
	gets(string);

	while(string[i]!='\0'){
		i++;
	}

	printf("\nLength of string: %d",i);


}


