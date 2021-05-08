/*
 * main.c
 *
 *  Created on: May 8, 2021
 *      Author: mosta
 */

#include"MainAlgo.h"
#include"US.h"
#include"DC.h"
void setup(){

	US_init();
	DC_init();

	MainAlgo_state = STATE(MainAlgo_waiting);
	US_state = STATE(US_busy);
	DC_state = STATE(DC_idle);


}
int main(){
	int i=0;
	setup();

	while(1){
		US_state();
		MainAlgo_state();
		DC_state();
		for(i=0;i<1000;i++);
	}
	return 0;
}
