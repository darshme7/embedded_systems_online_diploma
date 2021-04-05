/*
 * main.c
 *
 *  Created on: Apr 5, 2021
 *      Author: mosta
 */
/*C_StructUnion&Enum_HW5_EX4*/

#include "stdio.h"

struct Sstudent{
	char name[50];
	int roll;
	float marks;
};

int main(){

	struct Sstudent students[2];
	int i;
	printf("Enter information of students:\n\n");
	for(i=0;i<2;i++){
		printf("For roll number %d\n",students[i].roll=i+1);

		printf("Enter name: ");
		fflush(stdout);fflush(stdin);
		gets(students[i].name);
		fflush(stdout);fflush(stdin);

		printf("Enter marks: ");
		fflush(stdout);
		scanf("%f",&students[i].marks);
		printf("\n");
	}
	printf("\nDisplaying information of students:\n");
	for(i=0;i<2;i++){

		printf("Information for roll number %d\n",students[i].roll);

		printf("Name: %s\n",students[i].name);

		printf("Marks: %.0f\n\n",students[i].marks);

	}
	return 0;
}


