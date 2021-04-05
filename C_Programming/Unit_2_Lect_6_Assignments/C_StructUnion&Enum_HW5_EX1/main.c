/*
 * main.c
 *
 *  Created on: Apr 5, 2021
 *      Author: mosta
 */
/*C_StructUnion&Enum_HW5_EX1*/

#include "stdio.h"

struct Sstudent{
	char name[50];
	int roll;
	float marks;
};

int main(){

	struct Sstudent student1;
	printf("Enter information of students:\n\n");

	printf("Enter name: ");
	fflush(stdout);
	gets(student1.name);

	printf("Enter roll number: ");
	fflush(stdout);
	scanf("%d",&student1.roll);

	printf("Enter marks: ");
	fflush(stdout);
	scanf("%f",&student1.marks);

	printf("\nDisplaying Information\n");
	printf("name: %s\n",student1.name);
	printf("Roll: %d\n",student1.roll);
	printf("Marks: %.2f\n",student1.marks);

	return 0;
}
