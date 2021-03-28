/*
 * main.c
 *
 *  Created on: Mar 28, 2021
 *      Author: mosta
 */
//C_Functions_HW4_EX3

#include "stdio.h"
#include "string.h"
void reverseSentence(char str[],int string_length ,int index_);

int main ()
{
	char str_in[100];
	int	i=0;
	printf("Enter a sentence:");
	fflush(stdout);
	gets(str_in);
	reverseSentence(str_in,strlen(str_in),i);
	printf("\n%s",str_in);
	return 0;
}

void reverseSentence(char str[],int string_length,int index_)
{
	char temp;

	if(string_length-1>index_){

		temp =str[index_];
		str[index_]=str[string_length-1];
		str[string_length-1]=temp;
		reverseSentence(str,--string_length,++index_);
	}


}

