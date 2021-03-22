/*
 * main.c
 *
 *  Created on: Mar 22, 2021
 *      Author: mosta
 */
#include "stdio.h"


void main ()
{
	int a[50][50],b[50][50];
	int i,j,k,l;

	printf("Enter rows and column of matrix: ");
	fflush(stdout);
	scanf("%d%d",&i,&j);

	printf("Enter elements of matrix: \n");
	for(k=0;k<i;k++)
		for(l=0;l<j;l++)
		{
			printf("Enter elements a%d%d: ",k+1,l+1);
			fflush(stdout);
			scanf("%d",&a[k][l]);
		}

	printf("\nEntered Matrix: \n");
	for(k=0;k<i;k++)
	{for(l=0;l<j;l++)
	{
		b[l][k]=a[k][l];
		printf("%d  ",a[k][l]);
	}
	printf("\n\n");

	}

	printf("\nTranspose of Matrix: \n");
	for(l=0;l<j;l++){
		for(k=0;k<i;k++)
		{
			printf("%d  ",b[l][k]);
		}
		printf("\n\n");
	}
}
