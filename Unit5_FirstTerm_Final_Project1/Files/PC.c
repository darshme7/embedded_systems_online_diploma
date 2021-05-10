/*
 * main.c
 *
 *  Created on: May 9, 2021
 *      Author: mostafa
 */

#include "PC.h"
#include "AA.h"

void (*PC_state)();

uint32 PC_pressure = 0;
uint32 PC_threshold = 20;
enum {
	ON,
	OFF
}PC_alarmstate ;

void getPressureValue(uint32 p){

	PC_pressure = p;

	(PC_pressure > PC_threshold)?(PC_state=STATE(PC_HPdetected)):(PC_state=STATE(PC_waiting));
}

STATE_define(PC_waiting){

	PC_state_id = PC_waiting;
	PC_alarmstate = OFF;
	setAlarm(PC_alarmstate);
	AA_state();
}

STATE_define(PC_HPdetected){

	PC_state_id = PC_HPdetected;
	PC_alarmstate = ON;
	setAlarm(PC_alarmstate);
	AA_state();
	
	Delay(6000000);

	PC_alarmstate = OFF;
	setAlarm(PC_alarmstate);
	AA_state();

	PC_state = STATE(PC_waiting);
}



