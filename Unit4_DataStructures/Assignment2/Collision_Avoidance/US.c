/*
 * main.c
 *
 *  Created on: May 8, 2021
 *      Author: mosta
 */
#include"US.h"
int US_distance=0;

int setDistance(){
	int x = 45+(rand()%11);
	return x;
}

void US_init(){
	printf("US_init \n");
}
void (*US_state)();

STATE_define(US_busy){

	US_state_id=US_busy;
	US_distance=setDistance();
	getDistance(US_distance);

	US_state=STATE(US_busy);
	printf("US_busy state: distance=%d\n",US_distance);

}
