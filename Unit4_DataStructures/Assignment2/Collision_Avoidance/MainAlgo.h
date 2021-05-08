/*
 * MainAlgo.h
 *
 *  Created on: May 8, 2021
 *      Author: mosta
 */

#ifndef MAINALGO_H_
#define MAINALGO_H_
#include "states.h"

enum{
	MainAlgo_waiting,
	MainAlgo_driving
}MainAlgo_state_id;

STATE_define(MainAlgo_waiting);
STATE_define(MainAlgo_driving);

extern void (*MainAlgo_state)();

#endif /* DC_H_ */
