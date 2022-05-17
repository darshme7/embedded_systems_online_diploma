/*
 * ADC.c
 *
 * Created: 16-May-22 9:55:33 PM
 * Author : mosta
 */ 

#include "LCD.h"
#include "atmega32_adc_driver.h"

void intToString(uint32 number,uint8 * string){
		uint8 i;
	if(number >=100){
		string[0] = number/100+'0';
		for(i=1;i<3;i++){
			string[i] = number%10+'0';
			number=number/10;
		}
		string[3] = '\0';
	}else{
		
		string[0] = number/10+'0';
		string[1] = number%10+'0';
		string[2] = ' ' ;
		string[3] = '\0';
	}
}

int main(void)
{
	volatile uint32 temp=0,temp2=1026;
	uint8 NumberString [4];
	uint8 i ;
	LCD_init();
	ADC_config cfg;	
	cfg.ADC_AdjustResult = ADC_RIGHT_ADJUST;
	cfg.ADC_Channel = ADC_CHANNEL7;
	cfg.ADC_Interrupt = ADC_DISABLE_INTERRUPT;
	cfg.ADC_Prescaler = ADC_64_PRESCALER;
	cfg.ADC_RefSelect = ADC_AVSS_REFERENCE;
	cfg.P_ADC_CallBack_Fn = NULL;
    MCAL_ADC_Init(&cfg);
	LCD_printString("Percent: ");
	while (1) 
    {	
	   temp = MCAL_ADC_Read();
	   if(temp!=temp2){
		 LCD_goToXY(1,0);
		  for(i=0;i<16;i++){
			   LCD_printChar(0x00);
		  }
		 LCD_goToXY(0,9);
		 temp2 =temp;
		 temp=((temp*100)/1023);
		 intToString(temp,NumberString);
		 LCD_printString((char*)NumberString);
		 LCD_printChar('%');
		 LCD_goToXY(1,0);
		 for(i=0;i<(temp/6);i++){
		   LCD_printChar(0xff);
		 } 
	}
}

}