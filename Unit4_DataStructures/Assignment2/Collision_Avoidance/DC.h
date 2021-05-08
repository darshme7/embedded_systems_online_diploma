/*
 * DC.h
 *
 *  Created on: May 8, 2021
 *      Author: mosta
 */

#ifndef DC_H_
#define DC_H_
#include "states.h"

enum{
	DC_idle,
	DC_busy
}DC_state_id;

STATE_define(DC_idle);
STATE_define(DC_busy);

void DC_init();

extern void (*DC_state)();

#endif /* DC_H_ */
