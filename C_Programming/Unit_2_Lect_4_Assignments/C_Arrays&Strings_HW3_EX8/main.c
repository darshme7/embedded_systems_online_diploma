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
	int i,len=0;

	printf("Enter the string  : ");
	fflush(stdout);
	gets(string);
	len=strlen(string)-1;

	for(i=0;i<=len/2;i++){
		c=string[i];
		string[i]=string[len-i];
		string[len-i]=c;
	}
	printf("\nReverse string is : %s",string);


}




