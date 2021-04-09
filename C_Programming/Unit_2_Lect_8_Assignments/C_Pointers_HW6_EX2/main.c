/*
 * main.c
 *
 *  Created on: Apr 10, 2021
 *      Author: mosta
 */
//C_Pointers_HW6_EX2
#include "stdio.h"

int main(){

	char *p_alpha="ABCDEFGHIJKLMNOPQRSYUVWXYZ";
	int i;
	printf("The Alphabets are :\n");
	for(i=0;i<26;i++,p_alpha++)
		printf("%c ",*p_alpha);


	return 0;
}



