/*
 * states.h
 *
 *  Created on: May 9, 2021
 *      Author: mostafa
 */

#ifndef STATES_H_
#define STATES_H_

#include"Platform_Types.h"
#include"driver.h"


#define STATE_define(_statFUN_) void ST_##_statFUN_()
#define STATE(_statFUN_) ST_##_statFUN_

void getPressureValue(uint32 p);
void setAlarm(uint32 st);

#endif /* STATES_H_ */


