/*
 * US.h
 *
 *  Created on: May 8, 2021
 *      Author: mosta
 */

#ifndef US_H_
#define US_H_
#include "states.h"

enum{
	US_busy
}US_state_id;

STATE_define(US_busy);

void US_init();


extern void (*US_state)();

#endif /* US_H_ */
