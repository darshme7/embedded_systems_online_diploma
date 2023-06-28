/*
 * stm32f103c6_usart_driver.c
 *
 *  Created on: Jun 11, 2021
 *      Author: mosta
 */

//--------------------------------------------------------------------------------------------------------------------
//Includes
//--------------------------------------------------------------------------------------------------------------------

#include "stm32f103c6_rcc_driver.h"

uint8 AHBPre[8]={0,0,0,0,1,2,3,4};
uint8 APBPre[16]={0,0,0,0,0,0,0,0,1,2,3,4,6,7,8,9};

uint32 MCAL_RCC_SYSCLCKFreq(void){

	switch (RCC->CFGR.bits.SWS) {
		case 1:
			return HSE_Clk;
		default:
			return HSI_RC_Clk;
	}
}
uint32 MCAL_RCC_HCLCKFreq(void){

	return((MCAL_RCC_SYSCLCKFreq())>>AHBPre[RCC->CFGR.bits.HPRE]);
}
uint32 MCAL_RCC_PCLCK1Freq(void){

	return((MCAL_RCC_HCLCKFreq())>>APBPre[RCC->CFGR.bits.PPRE1]);
}
uint32 MCAL_RCC_PCLCK2Freq(void){

	return((MCAL_RCC_HCLCKFreq())>>APBPre[RCC->CFGR.bits.PPRE2]);

}
