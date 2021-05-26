/*
 * sequential_LED.c
 *
 * Created: 26-May-21 11:10:01 AM
 *  Author: mostafa
 */ 
#define F_CPU 1000000UL
#include "util/delay.h"

#define PORTD_BASE	0x32
#define DDRD_BASE	0x31

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

volatile PORTx * PORTD  = (volatile PORTx *)(PORTD_BASE);
volatile DDRx  * DDRD   = (volatile DDRx  *)(DDRD_BASE);

int main(void){
	
	DDRD->bits.DDP5 = 0b1;
	DDRD->bits.DDP6 = 0b1;
	DDRD->bits.DDP7 = 0b1;  
	PORTD->ALL_FIELDS = 0x00;
	
	while(1){
		
		//on
		PORTD->bits.P5 = 0b1;
		_delay_ms(1000);
		
		PORTD->bits.P6 = 0b1;
		_delay_ms(1000);
		
		PORTD->bits.P7 = 0b1;		
		_delay_ms(1000);
		
		//off
		PORTD->bits.P7 = 0b0;
		_delay_ms(1000);
		
		PORTD->bits.P6 = 0b0;
		_delay_ms(1000);
		
		PORTD->bits.P5 = 0b0;
		_delay_ms(1000);
		}
}
