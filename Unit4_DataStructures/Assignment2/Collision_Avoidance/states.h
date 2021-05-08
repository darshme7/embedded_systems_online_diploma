/*
 * states.h
 *
 *  Created on: May 8, 2021
 *      Author: mosta
 */

#ifndef STATES_H_
#define STATES_H_
#include"stdio.h"
#include"stdlib.h"

#define STATE_define(_statFUN_) void ST_##_statFUN_()
#define STATE(_statFUN_) ST_##_statFUN_

void getDistance(int d);
void setSpeed(int s);

#endif /* STATES_H_ */
