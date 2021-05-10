/*
 * PS.c
 *
 *  Created on: May 9, 2021
 *      Author: mostafa
 */

#include "PS.h"


void (*PS_state)();

uint32 PS_pressure = 0;

STATE_define(PS_busy){

	PS_state_id = PS_busy;

	PS_pressure = getPressureVal();

	getPressureValue(PS_pressure);

	PS_state=STATE(PS_busy);
}




