/*
 * AA.c
 *
 *  Created on: May 9, 2021
 *      Author: mostafa
 */
#include"AA.h"

void (*AA_state)();

enum {
	ON,
	OFF
}AA_alarmstate;

void setAlarm(uint32 st){

	AA_alarmstate = st;

	(AA_alarmstate == ON)?(AA_state = STATE(AA_alarmOn)):(AA_state = STATE(AA_alarmOff));
	
}


STATE_define(AA_alarmOn){

	AA_state_id = AA_alarmON;

	Set_Alarm_actuator(AA_alarmstate);

}

STATE_define(AA_alarmOff){

	AA_state_id = AA_alarmOFF;

	Set_Alarm_actuator(AA_alarmstate);

}

