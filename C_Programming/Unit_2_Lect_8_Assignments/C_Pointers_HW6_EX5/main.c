/*
 ============================================================================
 Name        : C_Pointers_HW6_EX5.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include "stdio.h"
#include "string.h"

struct Semployee{
	char name[50];
	int id;
};
int main(){
	struct Semployee employees,*P_employees[10],*(*employee)[10]=&P_employees;

	strcpy(employees.name,"Alex");
	employees.id=1002;

	P_employees[0]=&employees;

	printf("Employee Name : %s",(*(*employee))->name);
	printf("\n\nEmployee ID : %d",(*(*employee))->id);


	return 0;
}

