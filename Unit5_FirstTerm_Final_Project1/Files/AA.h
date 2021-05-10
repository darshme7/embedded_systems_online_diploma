/*
 * AA.h
 *
 *  Created on: May 9, 2021
 *      Author: mostafa
 */


#ifndef AA_H_
#define AA_H_

#include"states.h"

enum{
	AA_alarmON,
	AA_alarmOFF
}AA_state_id;

STATE_define(AA_alarmOn);
STATE_define(AA_alarmOff);

extern void (*AA_state)();
#endif /* AA_H_ */

