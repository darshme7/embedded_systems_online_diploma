/*
 * main.c
 *
 *  Created on: May 9, 2021
 *      Author: mostafa
 */

#include "PS.h"
#include "PC.h"


void setup(void){

	GPIO_INITIALIZATION();
	PS_state=STATE(PS_busy);
	PC_state=STATE(PC_waiting);

}

int main(void){

	setup();
	while(1){

		PS_state();
		PC_state();
	}

	return 0;
}
