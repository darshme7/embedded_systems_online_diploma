/*
 * main.c
 *
 *  Created on: Mar 19, 2021
 *      Author: mostafa
 */

#include "stdio.h"

void main()
{
	int i,j;
	for(i=0;i<10;i++)
	{
		for(j=0;j<10;j++)
		{
			if(j<i)
				continue;
			printf("%d ",j);

		}
		printf("\n");
	}




}

