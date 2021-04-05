/*
 * main.c
 *
 *  Created on: Apr 5, 2021
 *      Author: mosta
 */
/*C_StructUnion&Enum_HW5_EX6*/

#include "stdio.h"
union job {
	char name[32];
	float salary;
	int worker_no;
}u;
struct job1 {
	char name[32];
	float salary;
	int worker_no;
}s;
int main(){

	printf("size of union=%d",sizeof(u));
	printf("\nsize of structure=%d",sizeof(s));

	return 0;
}




