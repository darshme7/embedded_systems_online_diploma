/*
 * PC.h
 *
 *  Created on: May 9, 2021
 *      Author: mostafa
 */

#ifndef PC_H_
#define PC_H_

#include "states.h"

enum {
	PC_waiting,
	PC_HPdetected
}PC_state_id;

STATE_define(PC_waiting);
STATE_define(PC_HPdetected);

extern void (*PC_state)();

#endif /* PC_H_ */


