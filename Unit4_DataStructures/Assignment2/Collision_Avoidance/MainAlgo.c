/*
 * main.c
 *
 *  Created on: May 8, 2021
 *      Author: mosta
 */

#include"MainAlgo.h"

int MainAlgo_distance=0;
int MainAlgo_threshold=50;
int MainAlgo_speed=0;

void (*MainAlgo_state) ();

void getDistance(int d){

	MainAlgo_distance=d;
	(MainAlgo_distance<=MainAlgo_threshold)? (MainAlgo_state=STATE(MainAlgo_waiting)):(MainAlgo_state=STATE(MainAlgo_driving));
	printf("US-----distance=%d------>MainAlgo\n",d);
}

STATE_define(MainAlgo_waiting){

	MainAlgo_state_id=MainAlgo_waiting;

	printf("MainAlgo_waiting state: distance=%d speed=%d\n",MainAlgo_distance,MainAlgo_speed);

	MainAlgo_speed=0;
	setSpeed(MainAlgo_speed);

}
STATE_define(MainAlgo_driving){

	MainAlgo_state_id=MainAlgo_driving;

	printf("MainAlgo_driving state: distance=%d speed=%d\n",MainAlgo_distance,MainAlgo_speed);

	MainAlgo_speed=30;
	setSpeed(MainAlgo_speed);

}


