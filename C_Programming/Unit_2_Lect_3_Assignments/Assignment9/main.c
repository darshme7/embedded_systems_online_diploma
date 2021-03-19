/*
 * main.c
 *
 *  Created on: Mar 19, 2021
 *      Author: mosta
 */


#include "stdio.h"

void main()
{
	char a;
	printf("Enter an alphabet: ");
	fflush(stdout);
	scanf("%c",&a);
	switch(a)
	{
	case 'a':
	case 'A':
	case 'e':
	case 'E':
	case 'i':
	case 'I':
	case 'o':
	case 'O':
	case 'u':
	case 'U':
		printf("%c is a vowel.\n",a);
		break;


	default:
		printf("%c is a constant.\n" ,a);
		break;
	}
}
