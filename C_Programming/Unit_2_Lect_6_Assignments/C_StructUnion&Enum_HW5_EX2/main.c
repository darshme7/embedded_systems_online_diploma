/*
 * main.c
 *
 *  Created on: Apr 5, 2021
 *      Author: mosta
 */
/*C_StructUnion&Enum_HW5_EX2*/

#include "stdio.h"

struct Sdistance{
	float inch;
	float feet;
};

int main(){

	struct Sdistance distance1,distance2,sum;
	printf("Enter information for 1st distance:\n");

	printf("Enter feet: ");
	fflush(stdout);
	scanf("%f",&distance1.feet);

	printf("Enter inch: ");
	fflush(stdout);
	scanf("%f",&distance1.inch);

	printf("Enter information for 2nd distance:\n");

	printf("Enter feet: ");
	fflush(stdout);
	scanf("%f",&distance2.feet);

	printf("Enter inch: ");
	fflush(stdout);
	scanf("%f",&distance2.inch);

	sum.inch=distance1.inch+distance2.inch;
	sum.feet=distance1.feet+distance2.feet;
	if(sum.inch>12){
		sum.inch-=12;
		sum.feet++;
	}
	printf("\nSum of distances=%.0f\'-%.1f\"\n",sum.feet,sum.inch);

	return 0;
}


