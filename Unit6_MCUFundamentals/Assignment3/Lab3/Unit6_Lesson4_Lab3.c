/*
 * Unit6_Lesson4_Lab3.c
 *
 * Created: 22-May-21 5:54:42 AM
 *  Author: mostafa
 */ 
#define F_CPU 1000000UL
#include "avr/interrupt.h"
#include "util/delay.h"

#define SREG_BASE   0x5F
#define MCUCR_BASE  0x55
#define MCUCSR_BASE 0x54
#define GICR_BASE   0x5B
#define GIFR_BASE   0x5A
#define PORTB_BASE	0x38
#define DDRB_BASE	0x37
#define PORTD_BASE	0x32
#define DDRD_BASE	0x31


	
typedef union{
	volatile unsigned char ALL_FIELDS;
	struct{
		volatile unsigned char C_:1;
		volatile unsigned char Z_:1;
		volatile unsigned char N_:1;
		volatile unsigned char V_:1;
		volatile unsigned char S_:1;
		volatile unsigned char H_:1;
		volatile unsigned char T_:1;
		volatile unsigned char I_:1;
		}bits;
}SREG_t;

typedef union{
	volatile unsigned char ALL_FIELDS;
	struct{
		volatile unsigned char ISC00_:1;
		volatile unsigned char ISC01_:1;
		volatile unsigned char ISC10_:1;
		volatile unsigned char ISC11_:1;
	}bits;
}MCUCR_t;

typedef union{
	volatile unsigned char ALL_FIELDS;
	struct{
		volatile unsigned char :6;
		volatile unsigned char ISC2_:1;
	}bits;
}MCUCSR_t;

typedef union{
	volatile unsigned char ALL_FIELDS;
	struct{
		volatile unsigned char :5;
		volatile unsigned char INT2_:1;
		volatile unsigned char INT0_:1;
		volatile unsigned char INT1_:1;
	}bits;
}GICR_t;

typedef union{
	volatile unsigned char ALL_FIELDS;
	struct{
		volatile unsigned char :5;
		volatile unsigned char INTF2_:1;
		volatile unsigned char INTF0_:1;
		volatile unsigned char INTF1_:1;
	}bits;
}GIFR_t;

typedef union{
	volatile unsigned char ALL_FIELDS;
	struct{
		volatile unsigned char PB0_:1;
		volatile unsigned char PB1_:1;
		volatile unsigned char PB2_:1;
		volatile unsigned char PB3_:1;
		volatile unsigned char PB4_:1;
		volatile unsigned char PB5_:1;
		volatile unsigned char PB6_:1;
		volatile unsigned char PB7_:1;
	}bits;
}PORTB_t;

typedef union{
	volatile unsigned char ALL_FIELDS;
	struct{
		volatile unsigned char DDB0_:1;
		volatile unsigned char DDB1_:1;
		volatile unsigned char DDB2_:1;
		volatile unsigned char DDB3_:1;
		volatile unsigned char DDB4_:1;
		volatile unsigned char DDB5_:1;
		volatile unsigned char DDB6_:1;
		volatile unsigned char DDB7_:1;
	}bits;
}DDRB_t;

typedef union{
	volatile unsigned char ALL_FIELDS;
	struct{
		volatile unsigned char PD0_:1;
		volatile unsigned char PD1_:1;
		volatile unsigned char PD2_:1;
		volatile unsigned char PD3_:1;
		volatile unsigned char PD4_:1;
		volatile unsigned char PD5_:1;
		volatile unsigned char PD6_:1;
		volatile unsigned char PD7_:1;
	}bits;
}PORTD_t;

typedef union{
	volatile unsigned char ALL_FIELDS;
	struct{
		volatile unsigned char DDD0_:1;
		volatile unsigned char DDD1_:1;
		volatile unsigned char DDD2_:1;
		volatile unsigned char DDD3_:1;
		volatile unsigned char DDD4_:1;
		volatile unsigned char DDD5_:1;
		volatile unsigned char DDD6_:1;
		volatile unsigned char DDD7_:1;
	}bits;
}DDRD_t;

volatile SREG_t * SREG_ =(volatile SREG_t *)(SREG_BASE);
volatile MCUCR_t * MCUCR_ =(volatile MCUCR_t *)(MCUCR_BASE);
volatile MCUCSR_t * MCUCSR_ =(volatile MCUCSR_t *)(MCUCSR_BASE);
volatile GICR_t * GICR_ = (volatile GICR_t *)(GICR_BASE);
volatile GIFR_t * GIFR_ = (volatile GIFR_t *)(GIFR_BASE);
volatile PORTB_t * PORTB_ = (volatile PORTB_t *)(PORTB_BASE);
volatile DDRB_t * DDRB_ = (volatile DDRB_t *)(DDRB_BASE);
volatile PORTD_t * PORTD_ = (volatile PORTD_t *)(PORTD_BASE);
volatile DDRD_t * DDRD_ = (volatile DDRD_t *)(DDRD_BASE);



int main(void)
{
//setting PB2,PD2 and PD3 as input
	DDRB_->bits.DDB2_ = 0b0;
	PORTB_->bits.PB2_ = 0b0;
	DDRD_->bits.DDD2_ = 0b0;
	PORTD_->bits.PD2_ = 0b0;
	DDRD_->bits.DDD3_ = 0b0;
	PORTD_->bits.PD3_ = 0b0;

//setting PD5~PD7 as output
	DDRD_->bits.DDD5_ = 0b1;
	PORTD_->bits.PD5_ = 0b0;
	DDRD_->bits.DDD6_ = 0b1;
	PORTD_->bits.PD6_ = 0b0;
	DDRD_->bits.DDD7_ = 0b1;
	PORTD_->bits.PD7_ = 0b0;
	
//Enabling and setting EINT0 to any logical change
	MCUCR_->bits.ISC00_ = 0b1;
	MCUCR_->bits.ISC01_ = 0b0;
	GICR_->bits.INT0_ = 0b1;

//Enabling and setting EINT1 to Rising edge
	MCUCR_->bits.ISC10_ = 0b1;
	MCUCR_->bits.ISC11_ = 0b1;
	GICR_->bits.INT1_ = 0b1;

//Enabling and setting EINT2 to Falling edge
	MCUCSR_->bits.ISC2_ = 0b0;
	GICR_->bits.INT2_ = 0b1;
	
	_delay_ms(100);
	SREG_->bits.I_ = 0b1;
	
    while(1)
    {
		PORTD_->bits.PD5_ = 0b0;
		PORTD_->bits.PD6_ = 0b0;
        PORTD_->bits.PD7_ = 0b0;
    }
}
 ISR(INT0_vect){
	   PORTD_->bits.PD5_ = 0b1;
	   _delay_ms(1000);
}

ISR(INT1_vect){
	PORTD_->bits.PD6_ = 0b1;
	_delay_ms(1000);
}

ISR(INT2_vect){
	PORTD_->bits.PD7_ = 0b1;
	_delay_ms(1000);
}