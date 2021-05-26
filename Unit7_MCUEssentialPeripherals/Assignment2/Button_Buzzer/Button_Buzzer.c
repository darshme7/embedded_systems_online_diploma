/*
 * Button_Buzzer.c
 *
 * Created: 26-May-21 12:39:33 PM
 *  Author: mostafa
 */ 

#include "avr/delay.h"

#define F_CPU	1000000UL

#define PORTD_BASE	0x32
#define DDRD_BASE	0x31
#define PIND_BASE	0x30

typedef union{
	volatile unsigned char ALL_FIELDS;
	struct{
		volatile unsigned char P0:1;
		volatile unsigned char P1:1;
		volatile unsigned char P2:1;
		volatile unsigned char P3:1;
		volatile unsigned char P4:1;
		volatile unsigned char P5:1;
		volatile unsigned char P6:1;
		volatile unsigned char P7:1;
	}bits;
}PORTx;

typedef union{
	volatile unsigned char ALL_FIELDS;
	struct{
		volatile unsigned char DDP0:1;
		volatile unsigned char DDP1:1;
		volatile unsigned char DDP2:1;
		volatile unsigned char DDP3:1;
		volatile unsigned char DDP4:1;
		volatile unsigned char DDP5:1;
		volatile unsigned char DDP6:1;
		volatile unsigned char DDP7:1;
	}bits;
}DDRx;

typedef union{
	volatile unsigned char ALL_FIELDS;
	struct{
		volatile unsigned char P0:1;
		volatile unsigned char P1:1;
		volatile unsigned char P2:1;
		volatile unsigned char P3:1;
		volatile unsigned char P4:1;
		volatile unsigned char P5:1;
		volatile unsigned char P6:1;
		volatile unsigned char P7:1;
	}bits;
}PINx;



volatile PORTx		* PORTD  = (volatile PORTx *)(PORTD_BASE);
volatile DDRx		* DDRD   = (volatile DDRx  *)(DDRD_BASE);
volatile const PINx * PIND	 = (volatile PINx  *)(PIND_BASE);

int main(void){

	unsigned char flag = 0;
	
	//set PD0 as input
	DDRD->bits.DDP0 = 0b0;
	//set PD4 as output
	DDRD->bits.DDP4 = 0b1;
	//set PD4 output to 0
	PORTD->bits.P4 = 0b0;

	while(1){
		
		if(PIND->bits.P0 == 1 && flag == 0){
	
			PORTD->bits.P4 =0b1;
			_delay_ms(1000);
			PORTD->bits.P4 =0b0;			
			flag = 1;
		}
		
		else if(PIND->bits.P0 == 0){
			flag = 0;
		}
	}
}
