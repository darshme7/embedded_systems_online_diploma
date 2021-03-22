/*
 * main.c
 *
 *  Created on: Mar 22, 2021
 *      Author: mosta
 */
#include "stdio.h"
#include "string.h"

void main(){

	char string[100],c;
	int i,j=0;

	printf("Enter a string: ");
	fflush(stdout);
	gets(string);
	printf("\nEnter a character to find frequency: ");
	fflush(stdout);
	c=getchar();

	for(i=0;i<strlen(string);i++)

		if(string[i]==c)
			j++;
printf("\nFrequency of %c = %d",c,j);

}

