/*
 * main.c
 *
 *  Created on: May 8, 2021
 *      Author: mosta
 */

#include "DC.h"
int DC_speed=0;

void (*DC_state)();

void DC_init(){
	printf("DC_init \n");
}

void setSpeed(int s){
	DC_speed=s;
	DC_state=STATE(DC_busy);
	printf("MainAlgo-----speed=%d------>DC\n",s);
}
STATE_define(DC_idle){

	DC_state_id=DC_idle;

	printf("DC_idle state: speed=%d\n",DC_speed);


}

STATE_define(DC_busy){

	DC_state_id=DC_busy;
	DC_state=STATE(DC_idle);
	printf("DC_busy state: speed=%d\n",DC_speed);


}


