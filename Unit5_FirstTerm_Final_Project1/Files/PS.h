/*
 * PS.h
 *
 *  Created on: May 9, 2021
 *      Author: mostafa
 */

#ifndef PS_H_
#define PS_H_

#include"states.h"

enum{
	PS_busy
}PS_state_id;

STATE_define(PS_busy);


extern void (*PS_state)();

#endif /* PS_H_ */



