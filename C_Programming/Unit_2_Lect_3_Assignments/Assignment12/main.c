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
	printf("Enter a character: ");
	fflush(stdout);
	scanf("%c",&a);
	if(  a=='a'||a=='A'||a=='b'||a=='B'||a=='c'||a=='C'||a=='d'
	   ||a=='D'||a=='e'||a=='E'||a=='f'||a=='F'||a=='g'||a=='G'
	   ||a=='h'||a=='H'||a=='i'||a=='I'||a=='j'||a=='J'||a=='k'
	   ||a=='K'||a=='l'||a=='L'||a=='m'||a=='M'||a=='n'||a=='N'
	   ||a=='o'||a=='O'||a=='p'||a=='P'||a=='q'||a=='Q'||a=='r'
	   ||a=='R'||a=='s'||a=='S'||a=='t'||a=='T'||a=='u'||a=='U'
	   ||a=='v'||a=='V'||a=='w'||a=='W'||a=='x'||a=='X'||a=='y'
	   ||a=='Y'||a=='z'||a=='Z')
		printf("%c is an alphabet.\n" ,a);
	else
		printf("%c is not an alphabet.\n",a);
}


