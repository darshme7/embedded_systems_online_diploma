/*
 * STM32F103C6.h
 *
 *  Created on: Jun 1, 2021
 *      Author: mosta
 */
//---------------------------------------------------------------------
//Includes
//---------------------------------------------------------------------

#include "Platform_Types.h"

#ifndef INC_STM32F103C6_H_
#define INC_STM32F103C6_H_

//---------------------------------------------------------------------
//Base Addresses for Memories
//---------------------------------------------------------------------

#define Flash_Memory_Base				0x08000000UL
#define System_Memory_Base				0x1FFFF000UL
#define SRAM_Memory_Base				0x20000000UL

#define Peripherals_Base				0x40000000UL
#define CoreM3_Peripherals_Base			0xE0000000UL

#define NVIC_Base						0xE000E100UL

//---------------------------------------------------------------------
//Base Addresses for BUS Peripherals
//---------------------------------------------------------------------

//---------------------------------------------------------------------
//Base Addresses for AHB Peripherals
//---------------------------------------------------------------------

#define RCC_Base						0x40021000UL

//---------------------------------------------------------------------
//Base Addresses for APB2 Peripherals
//---------------------------------------------------------------------

//A,B are fully included in LQFP48 Package
#define GPIOA_Base						0x40010800UL
#define GPIOB_Base						0x40010C00UL
//C,D are Partially included in LQFP48 Package
#define GPIOC_Base						0x40011000UL
#define GPIOD_Base						0x40011400UL
//E is not included in LQFP48 Package
#define GPIOE_Base						0x40011800UL

#define EXTI_Base						0x40010400UL

#define USART1_Base						0x40013800UL

#define SPI1_Base						0x40013000UL

#define AFIO_Base						0x40010000UL

//---------------------------------------------------------------------
//Base Addresses for APB1 Peripherals
//---------------------------------------------------------------------

#define USART2_Base						0x40004400UL
#define USART3_Base						0x40004800UL

#define SPI2_Base						0x40003800UL
#define I2C1_Base						0x40005400UL
#define I2C2_Base						0x40005800UL
//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*
//Peripheral registers
//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*

//-*-*-*-*-*-*-*-*-*-*-*
//Peripheral register:NVIC
//-*-*-*-*-*-*-*-*-*-*-*

typedef struct{
	volatile	union {
		volatile uint32 NVIC_ISER0;
		struct {
			volatile uint32 SETENA0 :1;
			volatile uint32 SETENA1 :1;
			volatile uint32 SETENA2 :1;
			volatile uint32 SETENA3 :1;
			volatile uint32 SETENA4 :1;
			volatile uint32 SETENA5 :1;
			volatile uint32 SETENA6 :1;
			volatile uint32 SETENA7 :1;
			volatile uint32 SETENA8 :1;
			volatile uint32 SETENA9 :1;
			volatile uint32 SETENA10 :1;
			volatile uint32 SETENA11 :1;
			volatile uint32 SETENA12 :1;
			volatile uint32 SETENA13 :1;
			volatile uint32 SETENA14 :1;
			volatile uint32 SETENA15 :1;
			volatile uint32 SETENA16 :1;
			volatile uint32 SETENA17 :1;
			volatile uint32 SETENA18 :1;
			volatile uint32 SETENA19 :1;
			volatile uint32 SETENA20 :1;
			volatile uint32 SETENA21 :1;
			volatile uint32 SETENA22 :1;
			volatile uint32 SETENA23 :1;
			volatile uint32 SETENA24 :1;
			volatile uint32 SETENA25 :1;
			volatile uint32 SETENA26 :1;
			volatile uint32 SETENA27 :1;
			volatile uint32 SETENA28 :1;
			volatile uint32 SETENA29 :1;
			volatile uint32 SETENA30 :1;
			volatile uint32 SETENA31 :1;
		}bits;
	}NVIC_ISER0;
	volatile	union {
		volatile uint32 NVIC_ISER1;
		struct {
			volatile uint32 SETENA32 :1;
			volatile uint32 SETENA33 :1;
			volatile uint32 SETENA34 :1;
			volatile uint32 SETENA35 :1;
			volatile uint32 SETENA36 :1;
			volatile uint32 SETENA37 :1;
			volatile uint32 SETENA38 :1;
			volatile uint32 SETENA39 :1;
			volatile uint32 SETENA40 :1;
			volatile uint32 SETENA41 :1;
			volatile uint32 SETENA42 :1;
			volatile uint32 SETENA43 :1;
			volatile uint32 SETENA44 :1;
			volatile uint32 SETENA45 :1;
			volatile uint32 SETENA46 :1;
			volatile uint32 SETENA47 :1;
			volatile uint32 SETENA48 :1;
			volatile uint32 SETENA49 :1;
			volatile uint32 SETENA50 :1;
			volatile uint32 SETENA51 :1;
			volatile uint32 SETENA52 :1;
			volatile uint32 SETENA53 :1;
			volatile uint32 SETENA54 :1;
			volatile uint32 SETENA55 :1;
			volatile uint32 SETENA56 :1;
			volatile uint32 SETENA57 :1;
			volatile uint32 SETENA58 :1;
			volatile uint32 SETENA59 :1;
			volatile uint32 SETENA60 :1;
			volatile uint32 SETENA61 :1;
			volatile uint32 SETENA62 :1;
			volatile uint32 SETENA63 :1;
		}bits;
	}NVIC_ISER1;
	volatile	union {
		volatile uint32 NVIC_ISER2;
		struct {
			volatile uint32 SETENA64 :1;
			volatile uint32 SETENA65 :1;
			volatile uint32 SETENA66 :1;
			volatile uint32 SETENA67 :1;
			volatile uint32 SETENA68 :1;
			volatile uint32 SETENA69 :1;
			volatile uint32 SETENA70 :1;
			volatile uint32 SETENA71 :1;
			volatile uint32 SETENA72 :1;
			volatile uint32 SETENA73 :1;
			volatile uint32 SETENA74 :1;
			volatile uint32 SETENA75 :1;
			volatile uint32 SETENA76 :1;
			volatile uint32 SETENA77 :1;
			volatile uint32 SETENA78 :1;
			volatile uint32 SETENA79 :1;
			volatile uint32 SETENA80 :1;
			volatile uint32 Reserved0 :15;
		}bits;
	}NVIC_ISER2;
}NVIC_ISER_typedef;

typedef struct{

	volatile	union {
		volatile uint32 NVIC_ICER0;
		struct {
			volatile uint32 CLRENA0 :1;
			volatile uint32 CLRENA1 :1;
			volatile uint32 CLRENA2 :1;
			volatile uint32 CLRENA3 :1;
			volatile uint32 CLRENA4 :1;
			volatile uint32 CLRENA5 :1;
			volatile uint32 CLRENA6 :1;
			volatile uint32 CLRENA7 :1;
			volatile uint32 CLRENA8 :1;
			volatile uint32 CLRENA9 :1;
			volatile uint32 CLRENA10 :1;
			volatile uint32 CLRENA11 :1;
			volatile uint32 CLRENA12 :1;
			volatile uint32 CLRENA13 :1;
			volatile uint32 CLRENA14 :1;
			volatile uint32 CLRENA15 :1;
			volatile uint32 CLRENA16 :1;
			volatile uint32 CLRENA17 :1;
			volatile uint32 CLRENA18 :1;
			volatile uint32 CLRENA19 :1;
			volatile uint32 CLRENA20 :1;
			volatile uint32 CLRENA21 :1;
			volatile uint32 CLRENA22 :1;
			volatile uint32 CLRENA23 :1;
			volatile uint32 CLRENA24 :1;
			volatile uint32 CLRENA25 :1;
			volatile uint32 CLRENA26 :1;
			volatile uint32 CLRENA27 :1;
			volatile uint32 CLRENA28 :1;
			volatile uint32 CLRENA29 :1;
			volatile uint32 CLRENA30 :1;
			volatile uint32 CLRENA31 :1;
		}bits;
	}NVIC_ICER0;
	volatile	union {
		volatile uint32 NVIC_ICER1;
		struct {
			volatile uint32 CLRENA32 :1;
			volatile uint32 CLRENA33 :1;
			volatile uint32 CLRENA34 :1;
			volatile uint32 CLRENA35 :1;
			volatile uint32 CLRENA36 :1;
			volatile uint32 CLRENA37 :1;
			volatile uint32 CLRENA38 :1;
			volatile uint32 CLRENA39 :1;
			volatile uint32 CLRENA40 :1;
			volatile uint32 CLRENA41 :1;
			volatile uint32 CLRENA42 :1;
			volatile uint32 CLRENA43 :1;
			volatile uint32 CLRENA44 :1;
			volatile uint32 CLRENA45 :1;
			volatile uint32 CLRENA46 :1;
			volatile uint32 CLRENA47 :1;
			volatile uint32 CLRENA48 :1;
			volatile uint32 CLRENA49 :1;
			volatile uint32 CLRENA50 :1;
			volatile uint32 CLRENA51 :1;
			volatile uint32 CLRENA52 :1;
			volatile uint32 CLRENA53 :1;
			volatile uint32 CLRENA54 :1;
			volatile uint32 CLRENA55 :1;
			volatile uint32 CLRENA56 :1;
			volatile uint32 CLRENA57 :1;
			volatile uint32 CLRENA58 :1;
			volatile uint32 CLRENA59 :1;
			volatile uint32 CLRENA60 :1;
			volatile uint32 CLRENA61 :1;
			volatile uint32 CLRENA62 :1;
			volatile uint32 CLRENA63 :1;
		}bits;
	}NVIC_ICER1;
	volatile	union {
		volatile uint32 NVIC_ICER2;
		struct {
			volatile uint32 CLRENA64 :1;
			volatile uint32 CLRENA65 :1;
			volatile uint32 CLRENA66 :1;
			volatile uint32 CLRENA67 :1;
			volatile uint32 CLRENA68 :1;
			volatile uint32 CLRENA69 :1;
			volatile uint32 CLRENA70 :1;
			volatile uint32 CLRENA71 :1;
			volatile uint32 CLRENA72 :1;
			volatile uint32 CLRENA73 :1;
			volatile uint32 CLRENA74 :1;
			volatile uint32 CLRENA75 :1;
			volatile uint32 CLRENA76 :1;
			volatile uint32 CLRENA77 :1;
			volatile uint32 CLRENA78 :1;
			volatile uint32 CLRENA79 :1;
			volatile uint32 CLRENA80 :1;
			volatile uint32 Reserved0 :15;
		}bits;
	}NVIC_ICER2;
}NVIC_ICER_typedef;

//-*-*-*-*-*-*-*-*-*-*-*
//Peripheral register:GPIO
//-*-*-*-*-*-*-*-*-*-*-*

typedef struct{
	volatile	union {
		volatile uint32 CRL;
		struct {
			volatile uint32 MODE0 :2;
			volatile uint32 CNF0 :2;
			volatile uint32 MODE1 :2;
			volatile uint32 CNF1 :2;
			volatile uint32 MODE2 :2;
			volatile uint32 CNF2:2;
			volatile uint32 MODE3 :2;
			volatile uint32 CNF3 :2;
			volatile uint32 MODE4 :2;
			volatile uint32 CNF4 :2;
			volatile uint32 MODE5 :2;
			volatile uint32 CNF5 :2;
			volatile uint32 MODE6 :2;
			volatile uint32 CNF6 :2;
			volatile uint32 MODE7 :2;
			volatile uint32 CNF7 :2;
		}bits;
	}CRL;
	volatile union {
		volatile uint32 CRH;
		struct {
			volatile uint32 MODE8 :2;
			volatile uint32 CNF8 :2;
			volatile uint32 MODE9 :2;
			volatile uint32 CNF9 :2;
			volatile uint32 MODE10 :2;
			volatile uint32 CNF10 :2;
			volatile uint32 MODE11 :2;
			volatile uint32 CNF11 :2;
			volatile uint32 MODE12 :2;
			volatile uint32 CNF12 :2;
			volatile uint32 MODE13 :2;
			volatile uint32 CNF13 :2;
			volatile uint32 MODE14 :2;
			volatile uint32 CNF14 :2;
			volatile uint32 MODE15 :2;
			volatile uint32 CNF15 :2;
		}bits;
	}CRH;
	volatile union {
		volatile uint32 IDR;
		struct {
			volatile uint32 IDR0:1;
			volatile uint32 IDR1:1;
			volatile uint32 IDR2:1;
			volatile uint32 IDR3:1;
			volatile uint32 IDR4:1;
			volatile uint32 IDR5:1;
			volatile uint32 IDR6:1;
			volatile uint32 IDR7:1;
			volatile uint32 IDR8:1;
			volatile uint32 IDR9:1;
			volatile uint32 IDR10:1;
			volatile uint32 IDR11:1;
			volatile uint32 IDR12:1;
			volatile uint32 IDR13:1;
			volatile uint32 IDR14:1;
			volatile uint32 IDR15:1;
			volatile uint32 reserved:16;

		}bits;
	}IDR;

	volatile union {
		volatile uint32 ODR;
		struct {
			volatile uint32 ODR0:1;
			volatile uint32 ODR1:1;
			volatile uint32 ODR2:1;
			volatile uint32 ODR3:1;
			volatile uint32 ODR4:1;
			volatile uint32 ODR5:1;
			volatile uint32 ODR6:1;
			volatile uint32 ODR7:1;
			volatile uint32 ODR8:1;
			volatile uint32 ODR9:1;
			volatile uint32 ODR10:1;
			volatile uint32 ODR11:1;
			volatile uint32 ODR12:1;
			volatile uint32 ODR13:1;
			volatile uint32 ODR14:1;
			volatile uint32 ODR15:1;
			volatile uint32 reserved:16;
		}bits;
	}ODR;


	volatile union {
		volatile uint32 BSRR;
		struct {
			volatile uint32 BS0:1;
			volatile uint32 BS1:1;
			volatile uint32 BS2:1;
			volatile uint32 BS3:1;
			volatile uint32 BS4:1;
			volatile uint32 BS5:1;
			volatile uint32 BS6:1;
			volatile uint32 BS7:1;
			volatile uint32 BS8:1;
			volatile uint32 BS9:1;
			volatile uint32 BS10:1;
			volatile uint32 BS11:1;
			volatile uint32 BS12:1;
			volatile uint32 BS13:1;
			volatile uint32 BS14:1;
			volatile uint32 BS15:1;
			volatile uint32 BR0:1;
			volatile uint32 BR1:1;
			volatile uint32 BR2:1;
			volatile uint32 BR3:1;
			volatile uint32 BR4:1;
			volatile uint32 BR5:1;
			volatile uint32 BR6:1;
			volatile uint32 BR7:1;
			volatile uint32 BR8:1;
			volatile uint32 BR9:1;
			volatile uint32 BR10:1;
			volatile uint32 BR11:1;
			volatile uint32 BR12:1;
			volatile uint32 BR13:1;
			volatile uint32 BR14:1;
			volatile uint32 BR15:1;
		}bits;
	}BSRR;

	volatile union {
		volatile uint32 BRR;
		struct {
			volatile uint32 BR0:1;
			volatile uint32 BR1:1;
			volatile uint32 BR2:1;
			volatile uint32 BR3:1;
			volatile uint32 BR4:1;
			volatile uint32 BR5:1;
			volatile uint32 BR6:1;
			volatile uint32 BR7:1;
			volatile uint32 BR8:1;
			volatile uint32 BR9:1;
			volatile uint32 BR10:1;
			volatile uint32 BR11:1;
			volatile uint32 BR12:1;
			volatile uint32 BR13:1;
			volatile uint32 BR14:1;
			volatile uint32 BR15:1;
			volatile uint32 reserved:16;
		}bits;
	}BRR;
	volatile union {
		volatile uint32 LCKR;
		struct {
			volatile uint32 LCK0:1;
			volatile uint32 LCK1:1;
			volatile uint32 LCK2:1;
			volatile uint32 LCK3:1;
			volatile uint32 LCK4:1;
			volatile uint32 LCK5:1;
			volatile uint32 LCK6:1;
			volatile uint32 LCK7:1;
			volatile uint32 LCK8:1;
			volatile uint32 LCK9:1;
			volatile uint32 LCK10:1;
			volatile uint32 LCK11:1;
			volatile uint32 LCK12:1;
			volatile uint32 LCK13:1;
			volatile uint32 LCK14:1;
			volatile uint32 LCK15:1;
			volatile uint32 LCKK:1;
			volatile uint32 reserved:15;
		}bits;
	}LCKR;

}GPIO_typedef;

//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*

//-*-*-*-*-*-*-*-*-*-*-*
//Peripheral register:AFIO
//-*-*-*-*-*-*-*-*-*-*-*

typedef struct{
	volatile union{
		volatile uint32 EVCR;
		struct{
			volatile uint32 PIN:4;
			volatile uint32 PORT:3;
			volatile uint32 EVOE:1;
			volatile uint32 reserved:24;
		}bits;
	}EVCR;
	volatile union{
		volatile uint32 MAPR;
		struct{
			volatile uint32 SPI1_REMAP:1;
			volatile uint32 I2C1_REMAP:1;
			volatile uint32 USART1_REMAP:1;
			volatile uint32 USART2_REMAP:1;
			volatile uint32 USART3_REMAP:2;
			volatile uint32 TIM1_REMAP:2;
			volatile uint32 TIM2_REMAP:2;
			volatile uint32 TIM3_REMAP:2;
			volatile uint32 TIM4_REMAP:1;
			volatile uint32 CAN_REMAP:2;
			volatile uint32 PD01_REMAP:1;
			volatile uint32 TIM5CH4_IREMAP:1;
			volatile uint32 ADC1_ETRGINJ_REMAP:1;
			volatile uint32 ADC1_ETRGREG_REMAP:1;
			volatile uint32 ADC2_ETRGINJ_REMAP:1;
			volatile uint32 ADC2_ETRGREG_REMAP:1;
			volatile uint32 Reserved0:3;
			volatile uint32 SWJ_CFG:3;
			volatile uint32 Reserved1:5;
		}bits;
	}MAPR;
	volatile union{
		volatile uint32 EXITCR1;
		struct{
			volatile uint32 EXIT0:4;
			volatile uint32 EXIT1:4;
			volatile uint32 EXIT2:4;
			volatile uint32 EXIT3:4;
			volatile uint32 Reserved:16;
		}bits;
	}EXITCR1;
	volatile union{
		volatile uint32 EXITCR2;
		struct{
			volatile uint32 EXIT4:4;
			volatile uint32 EXIT5:4;
			volatile uint32 EXIT6:4;
			volatile uint32 EXIT7:4;
			volatile uint32 Reserved:16;
		}bits;
	}EXITCR2;
	volatile union{
		volatile uint32 EXITCR3;
		struct{
			volatile uint32 EXIT8:4;
			volatile uint32 EXIT9:4;
			volatile uint32 EXIT10:4;
			volatile uint32 EXIT11:4;
			volatile uint32 Reserved:16;
		}bits;
	}EXITCR3;
	volatile union{
		volatile uint32 EXITCR4;
		struct{
			volatile uint32 EXIT12:4;
			volatile uint32 EXIT13:4;
			volatile uint32 EXIT14:4;
			volatile uint32 EXIT15:4;
			volatile uint32 Reserved:16;
		}bits;
	}EXITCR4;

	uint32 Reserved0;

	volatile union{
		volatile uint32 MAPR2;
		struct{
			volatile uint32 Reserved0:5;
			volatile uint32 TIM9_REMAP:1;
			volatile uint32 TIM10_REMAP:1;
			volatile uint32 TIM11_REMAP:1;
			volatile uint32 TIM13_REMAP:1;
			volatile uint32 TIM14_REMAP:1;
			volatile uint32 FSMC_NADV:1;
			volatile uint32 Reserved1:21;
		}bits;
	}MAPR2;

}AFIO_typedef;

//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*

//-*-*-*-*-*-*-*-*-*-*-*
//Peripheral register:EXTI
//-*-*-*-*-*-*-*-*-*-*-*

typedef struct{
	volatile union{
		volatile uint32 IMR;
		struct{
			volatile uint32 MR0:1;
			volatile uint32 MR1:1;
			volatile uint32 MR2:1;
			volatile uint32 MR3:1;
			volatile uint32 MR4:1;
			volatile uint32 MR5:1;
			volatile uint32 MR6:1;
			volatile uint32 MR7:1;
			volatile uint32 MR8:1;
			volatile uint32 MR9:1;
			volatile uint32 MR10:1;
			volatile uint32 MR11:1;
			volatile uint32 MR12:1;
			volatile uint32 MR13:1;
			volatile uint32 MR14:1;
			volatile uint32 MR15:1;
			volatile uint32 MR16:1;
			volatile uint32 MR17:1;
			volatile uint32 MR18:1;
			volatile uint32 MR19:1;
			volatile uint32 Reserved:12;
		}bits;
	}IMR;
	volatile union{
		volatile uint32 EMR;
		struct{
			volatile uint32 MR0:1;
			volatile uint32 MR1:1;
			volatile uint32 MR2:1;
			volatile uint32 MR3:1;
			volatile uint32 MR4:1;
			volatile uint32 MR5:1;
			volatile uint32 MR6:1;
			volatile uint32 MR7:1;
			volatile uint32 MR8:1;
			volatile uint32 MR9:1;
			volatile uint32 MR10:1;
			volatile uint32 MR11:1;
			volatile uint32 MR12:1;
			volatile uint32 MR13:1;
			volatile uint32 MR14:1;
			volatile uint32 MR15:1;
			volatile uint32 MR16:1;
			volatile uint32 MR17:1;
			volatile uint32 MR18:1;
			volatile uint32 MR19:1;
			volatile uint32 Reserved:12;
		}bits;
	}EMR;
	volatile union{
		volatile uint32 RTSR;
		struct{
			volatile uint32 TR0:1;
			volatile uint32 TR1:1;
			volatile uint32 TR2:1;
			volatile uint32 TR3:1;
			volatile uint32 TR4:1;
			volatile uint32 TR5:1;
			volatile uint32 TR6:1;
			volatile uint32 TR7:1;
			volatile uint32 TR8:1;
			volatile uint32 TR9:1;
			volatile uint32 TR10:1;
			volatile uint32 TR11:1;
			volatile uint32 TR12:1;
			volatile uint32 TR13:1;
			volatile uint32 TR14:1;
			volatile uint32 TR15:1;
			volatile uint32 TR16:1;
			volatile uint32 TR17:1;
			volatile uint32 TR18:1;
			volatile uint32 TR19:1;
			volatile uint32 Reserved:12;
		}bits;
	}RTSR;
	volatile union{
		volatile uint32 FTSR;
		struct{
			volatile uint32 TR0:1;
			volatile uint32 TR1:1;
			volatile uint32 TR2:1;
			volatile uint32 TR3:1;
			volatile uint32 TR4:1;
			volatile uint32 TR5:1;
			volatile uint32 TR6:1;
			volatile uint32 TR7:1;
			volatile uint32 TR8:1;
			volatile uint32 TR9:1;
			volatile uint32 TR10:1;
			volatile uint32 TR11:1;
			volatile uint32 TR12:1;
			volatile uint32 TR13:1;
			volatile uint32 TR14:1;
			volatile uint32 TR15:1;
			volatile uint32 TR16:1;
			volatile uint32 TR17:1;
			volatile uint32 TR18:1;
			volatile uint32 TR19:1;
			volatile uint32 Reserved:12;
		}bits;
	}FTSR;
	volatile union{
		volatile uint32 SWIER;
		struct{
			volatile uint32 SWIER0:1;
			volatile uint32 SWIER1:1;
			volatile uint32 SWIER2:1;
			volatile uint32 SWIER3:1;
			volatile uint32 SWIER4:1;
			volatile uint32 SWIER5:1;
			volatile uint32 SWIER6:1;
			volatile uint32 SWIER7:1;
			volatile uint32 SWIER8:1;
			volatile uint32 SWIER9:1;
			volatile uint32 SWIER10:1;
			volatile uint32 SWIER11:1;
			volatile uint32 SWIER12:1;
			volatile uint32 SWIER13:1;
			volatile uint32 SWIER14:1;
			volatile uint32 SWIER15:1;
			volatile uint32 SWIER16:1;
			volatile uint32 SWIER17:1;
			volatile uint32 SWIER18:1;
			volatile uint32 SWIER19:1;
			volatile uint32 Reserved:12;
		}bits;
	}SWIER;
	volatile union{
		volatile uint32 PR;
		struct{
			volatile uint32 PR0:1;
			volatile uint32 PR1:1;
			volatile uint32 PR2:1;
			volatile uint32 PR3:1;
			volatile uint32 PR4:1;
			volatile uint32 PR5:1;
			volatile uint32 PR6:1;
			volatile uint32 PR7:1;
			volatile uint32 PR8:1;
			volatile uint32 PR9:1;
			volatile uint32 PR10:1;
			volatile uint32 PR11:1;
			volatile uint32 PR12:1;
			volatile uint32 PR13:1;
			volatile uint32 PR14:1;
			volatile uint32 PR15:1;
			volatile uint32 PR16:1;
			volatile uint32 PR17:1;
			volatile uint32 PR18:1;
			volatile uint32 PR19:1;
			volatile uint32 Reserved:12;
		}bits;
	}PR;
}EXTI_typedef;

//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*

//-*-*-*-*-*-*-*-*-*-*-*
//Peripheral register:RCC
//-*-*-*-*-*-*-*-*-*-*-*

typedef struct{
	volatile union{
		volatile uint32 CR;
		struct{
			volatile uint32 HSION:1;
			volatile uint32 HSIRDY:1;
			volatile uint32 Reserved0:1;
			volatile uint32 HSITRIM:5;
			volatile uint32 HSICAL:8;
			volatile uint32 HSEON:1;
			volatile uint32 HSERDY:1;
			volatile uint32 HSEBYP:1;
			volatile uint32 CSSON:1;
			volatile uint32 Reserved1:4;
			volatile uint32 PLLON:1;
			volatile uint32 PLLRDY:1;
			volatile uint32 Reserved2:6;
		}bits;
	}CR;
	volatile union{
		volatile uint32 CFGR;
		struct{
			volatile uint32 SW:2;
			volatile uint32 SWS:2;
			volatile uint32 HPRE:4;
			volatile uint32 PPRE1:3;
			volatile uint32 PPRE2:3;
			volatile uint32 ADCPRE:2;
			volatile uint32 PLLSRC:1;
			volatile uint32 PLLXTPRE:1;
			volatile uint32 PLLMUL:4;
			volatile uint32 USBPRE:1;
			volatile uint32 Reserved0:1;
			volatile uint32 MCO:3;
			volatile uint32 Reserved1:5;
		}bits;
	}CFGR;
	volatile union{
		volatile uint32 CIR;
		struct{
			volatile uint32 LSIRDYF:1;
			volatile uint32 LSERDYF:1;
			volatile uint32 HSIRDYF:1;
			volatile uint32 HSERDYF:1;
			volatile uint32 PLLRDYF:1;
			volatile uint32 Reserved0:2;
			volatile uint32 CSSF:1;
			volatile uint32 LSIRDYIE:1;
			volatile uint32 LSERDYIE:1;
			volatile uint32 HSIRDYIE:1;
			volatile uint32 HSERDYIE:1;
			volatile uint32 PLLRDYIE:1;
			volatile uint32 Reserved1:3;
			volatile uint32 LSIRDYC:1;
			volatile uint32 LSERDYC:1;
			volatile uint32 HSIRDYC:1;
			volatile uint32 HSERDYC:1;
			volatile uint32 PLLRDYC:1;
			volatile uint32 Reserved2:2;
			volatile uint32 CSSC:1;
			volatile uint32 Reserved:8;
		}bits;
	}CIR;
	volatile union{
		volatile uint32 APB2RSTR;
		struct{
			volatile uint32 AFIORST:1;
			volatile uint32 Reserved0:1;
			volatile uint32 IOPARST:1;
			volatile uint32 IOPBRST:1;
			volatile uint32 IOPCRST:1;
			volatile uint32 IOPDRST:1;
			volatile uint32 IOPERST:1;
			volatile uint32 IOPFRST:1;
			volatile uint32 IOPGRST:1;
			volatile uint32 ADC1RST:1;
			volatile uint32 ADC2RST:1;
			volatile uint32 TIM1RST:1;
			volatile uint32 SPI1RST:1;
			volatile uint32 TIM8RST:1;
			volatile uint32 USART1RST:1;
			volatile uint32 ADC3RST:1;
			volatile uint32 Resserved1:3;
			volatile uint32 TIM9RST:1;
			volatile uint32 TIM10RST:1;
			volatile uint32 TIM11RST:1;
			volatile uint32 Reserved2:10;
		}bits;
	}APB2RSTR;
	volatile union{
		volatile uint32 APB1RSTR;
		struct{
			volatile uint32 TIM2RST:1;
			volatile uint32 TIM3RST:1;
			volatile uint32 TIM4RST:1;
			volatile uint32 TIM5RST:1;
			volatile uint32 TIM6RST:1;
			volatile uint32 TIM7RST:1;
			volatile uint32 TIM12RST:1;
			volatile uint32 TIM13RST:1;
			volatile uint32 TIM14RST:1;
			volatile uint32 Reserved0:2;
			volatile uint32 WWDGRST:1;
			volatile uint32 Reserved1:2;
			volatile uint32 SPI2RST:1;
			volatile uint32 SPI3RST:1;
			volatile uint32 Reserved2:1;
			volatile uint32 USART2RST:1;
			volatile uint32 USART3RST:1;
			volatile uint32 UART4RST:1;
			volatile uint32 UART5RST:1;
			volatile uint32 I2C1RST:1;
			volatile uint32 I2C2RST:1;
			volatile uint32 USBRST:1;
			volatile uint32 Reserved3:1;
			volatile uint32 CANRST:1;
			volatile uint32 Reserved4:1;
			volatile uint32 BKPRST:1;
			volatile uint32 PWRRST:1;
			volatile uint32 DACRST:1;
			volatile uint32 Reserved5:2;

		}bits;
	}APB1RSTR;
	volatile union{
		volatile uint32 AHBENR;
		struct{
			volatile uint32 DMA1EN:1;
			volatile uint32 DMA2EN:1;
			volatile uint32 SRAMEN:1;
			volatile uint32 Reserved0:1;
			volatile uint32 FLITFEN:1;
			volatile uint32 Reserved1:1;
			volatile uint32 CRCEN:1;
			volatile uint32 Reserved2:1;
			volatile uint32 FSMCEN:1;
			volatile uint32 Reserved3:1;
			volatile uint32 SDIOEN:1;
			volatile uint32 Reserve4:21;
		}bits;
	}AHBENR;
	volatile union{
		volatile uint32 APB2ENR;
		struct{
			volatile uint32 AFIOEN:1;
			volatile uint32 Reserved0:1;
			volatile uint32 IOPAEN:1;
			volatile uint32 IOPBEN:1;
			volatile uint32 IOPCEN:1;
			volatile uint32 IOPDEN:1;
			volatile uint32 IOPEEN:1;
			volatile uint32 IOPFEN:1;
			volatile uint32 IOPGEN:1;
			volatile uint32 ADC1EN:1;
			volatile uint32 ADC2EN:1;
			volatile uint32 TIM1EN:1;
			volatile uint32 SPI1EN:1;
			volatile uint32 TIM8EN:1;
			volatile uint32 USART1EN:1;
			volatile uint32 ADC3EN:1;
			volatile uint32 Resserved1:3;
			volatile uint32 TIM9EN:1;
			volatile uint32 TIM10EN:1;
			volatile uint32 TIM11EN:1;
			volatile uint32 Reserved2:10;
		}bits;
	}APB2ENR;
	volatile union{
		volatile uint32 APB1ENR;
		struct{
			volatile uint32 TIM2EN:1;
			volatile uint32 TIM3EN:1;
			volatile uint32 TIM4EN:1;
			volatile uint32 TIM5EN:1;
			volatile uint32 TIM6EN:1;
			volatile uint32 TIM7EN:1;
			volatile uint32 TIM12EN:1;
			volatile uint32 TIM13EN:1;
			volatile uint32 TIM14EN:1;
			volatile uint32 Reserved0:2;
			volatile uint32 WWDGEN:1;
			volatile uint32 Reserved1:2;
			volatile uint32 SPI2EN:1;
			volatile uint32 SPI3EN:1;
			volatile uint32 Reserved2:1;
			volatile uint32 USART2EN:1;
			volatile uint32 USART3EN:1;
			volatile uint32 UART4EN:1;
			volatile uint32 UART5EN:1;
			volatile uint32 I2C1EN:1;
			volatile uint32 I2C2EN:1;
			volatile uint32 USBEN:1;
			volatile uint32 Reserved3:1;
			volatile uint32 CANEN:1;
			volatile uint32 Reserved4:1;
			volatile uint32 BKPEN:1;
			volatile uint32 PWREN:1;
			volatile uint32 DACEN:1;
			volatile uint32 Reserved5:2;
		}bits;
	}APB1ENR;
	volatile union{
		volatile uint32 BDCR;
		struct{
			volatile uint32 LSEON:1;
			volatile uint32 LSERDY:1;
			volatile uint32 LSEBYP:1;
			volatile uint32 Reserved0:5;
			volatile uint32 RTCSEL:2;
			volatile uint32 Reserved1:5;
			volatile uint32 RTCEN:1;
			volatile uint32 BDRST:1;
			volatile uint32 Reserved2:15;
		}bits;
	}BDCR;
	volatile union{
		volatile uint32 CSR;
		struct{
			volatile uint32 LSION:1;
			volatile uint32 LSIRDY:1;
			volatile uint32 Reserved0:22;
			volatile uint32 RMVF:1;
			volatile uint32 Reserved1:1;
			volatile uint32 PINRSTF:1;
			volatile uint32 PORRSTF:1;
			volatile uint32 SFTRSTF:1;
			volatile uint32 IWDGRSTF:1;
			volatile uint32 WWDGRSTF:1;
			volatile uint32 LPWRRSTF:1;
		}bits;
	}CSR;
}RCC_typedef;


//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*
//-*-*-*-*-*-*-*-*-*-*-*
//Peripheral register:USART
//-*-*-*-*-*-*-*-*-*-*-*

typedef struct{
	volatile union{
		volatile uint32 USART_SR;
		struct{
			volatile uint32 PE:1;
			volatile uint32 FE:1;
			volatile uint32 NE:1;
			volatile uint32 ORE:1;
			volatile uint32 IDLE:1;
			volatile uint32 RXNE:1;
			volatile uint32 TC:1;
			volatile uint32 TXE:1;
			volatile uint32 LBD:1;
			volatile uint32 CTS:1;
			volatile uint32 Reserved0:22;
		}bits;
	}USART_SR;
	volatile union{
		volatile uint32 USART_DR;
		struct{
			volatile uint32 DR:9;
			volatile uint32 Reserved0:23;
		}bits;
	}USART_DR;
	volatile union{
		volatile uint32 USART_BRR;
		struct{
			volatile uint32 DIV_Fraction:4;
			volatile uint32 DIV_Mantissa:12;
			volatile uint32 Reserved0:16;
		}bits;
	}USART_BRR;
	volatile union{
		volatile uint32 USART_CR1;
		struct{
			volatile uint32 SBK:1;
			volatile uint32 RWU:1;
			volatile uint32 TE_RE:2;
			volatile uint32 IDLEIE:1;
			volatile uint32 RXNEIE_TCIE_TXEIE_PEIE:4;
			volatile uint32 PCE_PS:2;
			volatile uint32 WAKE:1;
			volatile uint32 M:1;
			volatile uint32 UE:1;
			volatile uint32 Reserved0:18;
		}bits;
	}USART_CR1;
	volatile union{
		volatile uint32 USART_CR2;
		struct{
			volatile uint32 ADD:4;
			volatile uint32 Reserved0:1;
			volatile uint32 LBDL:1;
			volatile uint32 LBDIE:1;
			volatile uint32 Reserved1:1;
			volatile uint32 LBCL:1;
			volatile uint32 CPHA:1;
			volatile uint32 CPOL:1;
			volatile uint32 CLKEN:1;
			volatile uint32 STOP:2;
			volatile uint32 LINEN:1;
			volatile uint32 Reserved2:17;
		}bits;
	}USART_CR2;
	volatile union{
		volatile uint32 USART_CR3;
		struct{
			volatile uint32 EIE:1;
			volatile uint32 IREN:1;
			volatile uint32 IRLP:1;
			volatile uint32 HDSEL:1;
			volatile uint32 NACK:1;
			volatile uint32 SCEN:1;
			volatile uint32 DMAR:1;
			volatile uint32 DMAT:1;
			volatile uint32 RTSE:1;
			volatile uint32 CTSE:1;
			volatile uint32 CTSIE:1;
			volatile uint32 Reserve0:21;
		}bits;
	}USART_CR3;
	volatile union{
		volatile uint32 USART_GTPR;
		struct{
			volatile uint32 PSC:8;
			volatile uint32 GT:8;
			volatile uint32 Reserved2:16;
		}bits;
	}USART_GTPR;
}USART_typedef;

//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*
//-*-*-*-*-*-*-*-*-*-*-*
//Peripheral register:SPI
//-*-*-*-*-*-*-*-*-*-*-*

typedef struct{
	volatile union{
		volatile uint32 SPI_CR1;
		struct{
			volatile uint32 CPHA:1;
			volatile uint32 CPOL:1;
			volatile uint32 MSTR:1;
			volatile uint32 BR:3;
			volatile uint32 SPE:1;
			volatile uint32 LSBFIRST:1;
			volatile uint32 SSI:1;
			volatile uint32 SSM:1;
			volatile uint32 RXONLY:1;
			volatile uint32 DFF:1;
			volatile uint32 CRCNEXT:1;
			volatile uint32 CRCEN:1;
			volatile uint32 BIDIOE:1;
			volatile uint32 BIDIMODE:1;
			volatile uint32 Reserved0:16;
		}bits;
	}SPI_CR1;
	volatile union{
		volatile uint32 SPI_CR2;
		struct{
			volatile uint32 RXDMAEN:1;
			volatile uint32 TXDMAEN:1;
			volatile uint32 SSOE:1;
			volatile uint32 Reserved0:2;
			volatile uint32 ERRIE_RXNEIE_TXEIE:3;
			volatile uint32 Reserved1:24;
		}bits;
	}SPI_CR2;
	volatile union{
		volatile uint32 SPI_SR;
		struct{
			volatile uint32 RXNE:1;
			volatile uint32 TXE:1;
			volatile uint32 CHSIDE:1;
			volatile uint32 UDR:1;
			volatile uint32 CRCERR:1;
			volatile uint32 MODF:1;
			volatile uint32 OVR:1;
			volatile uint32 BSY:1;
			volatile uint32 Reserved0:24;
		}bits;
	}SPI_SR;
	volatile union{
		volatile uint32 SPI_DR;
		struct{
			volatile uint32 DR:16;
			volatile uint32 Reserved0:16;
		}bits;
	}SPI_DR;
	volatile union{
		volatile uint32 SPI_CRCPR;
		struct{
			volatile uint32 CRCPOLY:16;
			volatile uint32 Reserved0:16;
		}bits;
	}SPI_CRCPR;

	volatile union{
		volatile uint32 SPI_RXCRCR;
		struct{
			volatile uint32 RxCRC:16;
			volatile uint32 Reserved0:16;
		}bits;
	}SPI_RXCRCR;

	volatile union{
		volatile uint32 SPI_TXCRCR;
		struct{
			volatile uint32 TxCRC:16;
			volatile uint32 Reserved0:16;
		}bits;
	}SPI_TXCRCR;


}SPI_typedef;

//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*
//-*-*-*-*-*-*-*-*-*-*-*
//Peripheral register:I2C
//-*-*-*-*-*-*-*-*-*-*-*
typedef struct{
	volatile union{
		volatile uint32 I2C_CR1;
		struct{
			volatile uint32 PE:1;
			volatile uint32 SMBU:1;
			volatile uint32 Reserved0:1;
			volatile uint32 SMBTYPE:1;
			volatile uint32 ENARP:1;
			volatile uint32 ENPEC:1;
			volatile uint32 ENGC:1;
			volatile uint32 NOSTRETCH:1;
			volatile uint32 START:1;
			volatile uint32 STOP:1;
			volatile uint32 ACK:1;
			volatile uint32 POS:1;
			volatile uint32 PEC:1;
			volatile uint32 ALERT:1;
			volatile uint32 Reserved1:1;
			volatile uint32 SWRST:1;
			volatile uint32 Reserved2:16;
		}bits;
	}I2C_CR1;
	volatile union{
		volatile uint32 I2C_CR2;
		struct{
			volatile uint32 FERQ:6;
			volatile uint32 Reserved0:2;
			volatile uint32 ITERREN:1;
			volatile uint32 ITEVTEN:1;
			volatile uint32 ITBUFEN:1;
			volatile uint32 DMAEN:1;
			volatile uint32 LAST:1;
			volatile uint32 Reserved1:19;
		}bits;
	}I2C_CR2;
	volatile union{
		volatile uint32 I2C_OAR1;
		struct{
			volatile uint32 ADD0:1;
			volatile uint32 ADD7_1:7;
			volatile uint32 ADD9_8:2;
			volatile uint32 Reserved0:5;
			volatile uint32 ADDMODE:1;
			volatile uint32 Reserved1:16;
		}bits;
	}I2C_OAR1;
	volatile union{
		volatile uint32 I2C_OAR2;
		struct{
			volatile uint32 ENDUAL:1;
			volatile uint32 ADD2:7;
			volatile uint32 Reserved0:24;
		}bits;
	}I2C_OAR2;
	volatile union{
		volatile uint32 I2C_DR;
		struct{
			volatile uint32 DR:8;
			volatile uint32 Reserved0:24;
		}bits;
	}I2C_DR;

	volatile union{
		volatile uint32 I2C_SR1;
		struct{
			volatile uint32 SB:1;
			volatile uint32 ADDR:1;
			volatile uint32 BTF:1;
			volatile uint32 ADD10:1;
			volatile uint32 STOPF:1;
			volatile uint32 Reserved0:1;
			volatile uint32 RxNE:1;
			volatile uint32 TxE:1;
			volatile uint32 BERR:1;
			volatile uint32 ARLO:1;
			volatile uint32 AF:1;
			volatile uint32 OVR:1;
			volatile uint32 PECERR:1;
			volatile uint32 Reserved1:1;
			volatile uint32 TIMEOUT:1;
			volatile uint32 SMBALERT:1;
			volatile uint32 Reserved2:16;
		}bits;
	}I2C_SR1;
	volatile union{
		volatile uint32 I2C_SR2;
		struct{
			volatile uint32 MSL:1;
			volatile uint32 BUSY:1;
			volatile uint32 TRA:1;
			volatile uint32 Reseved0:1;
			volatile uint32 GENCALL:1;
			volatile uint32 SMBDEFAULT:1;
			volatile uint32 SMBHOST:1;
			volatile uint32 DUALF:1;
			volatile uint32 PEC:8;
			volatile uint32 Reserved1:16;
		}bits;
	}I2C_SR2;
	volatile union{
		volatile uint32 I2C_CCR;
		struct{
			volatile uint32 CCR:12;
			volatile uint32 Reserved0:2;
			volatile uint32 DUTY:1;
			volatile uint32 F_S:1;
			volatile uint32 Reserved1:16;
		}bits;
	}I2C_CCR;

	volatile union{
		volatile uint32 I2C_TRISE;
		struct{
			volatile uint32 TRISE:6;
			volatile uint32 Reserved0:26;
		}bits;
	}I2C_TRISE;


}I2C_typedef;

//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*
//-*-*-*-*-*-*-*-*-*-*-*-
//Peripheral Instants:
//-*-*-*-*-*-*-*-*-*-*-*

#define GPIOA 							((GPIO_typedef *)(GPIOA_Base))
#define GPIOB 							((GPIO_typedef *)(GPIOB_Base))
#define GPIOC 							((GPIO_typedef *)(GPIOC_Base))
#define GPIOD 							((GPIO_typedef *)(GPIOD_Base))
#define GPIOE 							((GPIO_typedef *)(GPIOE_Base))

#define AFIO							((AFIO_typedef *)(AFIO_Base))

#define EXTI							((EXTI_typedef *)(EXTI_Base))

#define RCC								((RCC_typedef *)(RCC_Base))

#define USART1 							((USART_typedef *)(USART1_Base))
#define USART2 							((USART_typedef *)(USART2_Base))
#define USART3 							((USART_typedef *)(USART3_Base))

#define SPI1 							((SPI_typedef *)(SPI1_Base))
#define SPI2 							((SPI_typedef *)(SPI2_Base))

#define I2C1 							((I2C_typedef *)(I2C1_Base))
#define I2C2 							((I2C_typedef *)(I2C2_Base))

#define NVIC_ISER						((NVIC_ISER_typedef *)(NVIC_Base +0x000))
#define NVIC_ICER						((NVIC_ICER_typedef *)(NVIC_Base +0x080))

//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*
//-*-*-*-*-*-*-*-*-*-*-*-
//clock enable Macros:
//-*-*-*-*-*-*-*-*-*-*-*

#define RCC_GPIOA_CLK_EN()				(RCC->APB2ENR.bits.IOPAEN = 0b1)
#define RCC_GPIOB_CLK_EN()				(RCC->APB2ENR.bits.IOPBEN = 0b1)
#define RCC_GPIOC_CLK_EN()				(RCC->APB2ENR.bits.IOPCEN = 0b1)
#define RCC_GPIOD_CLK_EN()				(RCC->APB2ENR.bits.IOPDEN = 0b1)
#define RCC_GPIOE_CLK_EN()				(RCC->APB2ENR.bits.IOPEEN = 0b1)

#define RCC_AFIO_CLK_EN()				(RCC->APB2ENR.bits.AFIOEN = 0b1)


#define RCC_USART1_CLK_EN()				(RCC->APB2ENR.bits.USART1EN = 0b1)
#define RCC_USART2_CLK_EN()				(RCC->APB1ENR.bits.USART2EN = 0b1)
#define RCC_USART3_CLK_EN()				(RCC->APB1ENR.bits.USART3EN = 0b1)

#define RCC_SPI1_CLK_EN()				(RCC->APB2ENR.bits.SPI1EN = 0b1)
#define RCC_SPI2_CLK_EN()				(RCC->APB1ENR.bits.SPI2EN = 0b1)

#define RCC_I2C1_CLK_EN()				(RCC->APB1ENR.bits.I2C1EN = 0b1)
#define RCC_I2C2_CLK_EN()				(RCC->APB1ENR.bits.I2C2EN = 0b1)

//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*
//-*-*-*-*-*-*-*-*-*-*-*-
//EXTI Macros:
//-*-*-*-*-*-*-*-*-*-*-*

#define NVIC_EXTI0_ENABLE					(NVIC_ISER->NVIC_ISER0.bits.SETENA6   = 0b1)
#define NVIC_EXTI1_ENABLE					(NVIC_ISER->NVIC_ISER0.bits.SETENA7   = 0b1)
#define NVIC_EXTI2_ENABLE					(NVIC_ISER->NVIC_ISER0.bits.SETENA8   = 0b1)
#define NVIC_EXTI3_ENABLE					(NVIC_ISER->NVIC_ISER0.bits.SETENA9   = 0b1)
#define NVIC_EXTI4_ENABLE					(NVIC_ISER->NVIC_ISER0.bits.SETENA10  = 0b1)
#define NVIC_EXTI9_5_ENABLE					(NVIC_ISER->NVIC_ISER0.bits.SETENA23  = 0b1)
#define NVIC_EXTI15_10_ENABLE				(NVIC_ISER->NVIC_ISER1.bits.SETENA40  = 0b1)

#define NVIC_EXTI0_DISABLE					(NVIC_ICER->NVIC_ICER0.bits.CLRENA6   = 0b1)
#define NVIC_EXTI1_DISABLE					(NVIC_ICER->NVIC_ICER0.bits.CLRENA7   = 0b1)
#define NVIC_EXTI2_DISABLE					(NVIC_ICER->NVIC_ICER0.bits.CLRENA8   = 0b1)
#define NVIC_EXTI3_DISABLE					(NVIC_ICER->NVIC_ICER0.bits.CLRENA9   = 0b1)
#define NVIC_EXTI4_DISABLE					(NVIC_ICER->NVIC_ICER0.bits.CLRENA10  = 0b1)
#define NVIC_EXTI9_5_DISABLE				(NVIC_ICER->NVIC_ICER0.bits.CLRENA23  = 0b1)
#define NVIC_EXTI15_10_DISABLE				(NVIC_ICER->NVIC_ICER1.bits.CLRENA40  = 0b1)

//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*
//-*-*-*-*-*-*-*-*-*-*-*-
//Interrupt Macros:
//-*-*-*-*-*-*-*-*-*-*-*

#define NVIC_I2C1EV_ENABLE()				(NVIC_ISER->NVIC_ISER0.bits.SETENA31 = 0b1)
#define NVIC_I2C1ER_ENABLE()				(NVIC_ISER->NVIC_ISER1.bits.SETENA32 = 0b1)
#define NVIC_I2C2EV_ENABLE()				(NVIC_ISER->NVIC_ISER1.bits.SETENA33 = 0b1)
#define NVIC_I2C2ER_ENABLE()				(NVIC_ISER->NVIC_ISER1.bits.SETENA34 = 0b1)

#define NVIC_SPI1_ENABLE()					(NVIC_ISER->NVIC_ISER1.bits.SETENA35 = 0b1)
#define NVIC_SPI2_ENABLE()					(NVIC_ISER->NVIC_ISER1.bits.SETENA36 = 0b1)

#define NVIC_USART1_ENABLE()				(NVIC_ISER->NVIC_ISER1.bits.SETENA37 = 0b1)
#define NVIC_USART2_ENABLE()				(NVIC_ISER->NVIC_ISER1.bits.SETENA38 = 0b1)
#define NVIC_USART3_ENABLE()				(NVIC_ISER->NVIC_ISER1.bits.SETENA39 = 0b1)


#define NVIC_I2C1EV_DISABLE()				(NVIC_ICER->NVIC_ICER0.bits.CLRENA31 = 0b1)
#define NVIC_I2C1ER_DISABLE()				(NVIC_ICER->NVIC_ICER1.bits.CLRENA32 = 0b1)
#define NVIC_I2C2EV_DISABLE()				(NVIC_ICER->NVIC_ICER1.bits.CLRENA33 = 0b1)
#define NVIC_I2C2ER_DISABLE()				(NVIC_ICER->NVIC_ICER1.bits.CLRENA34 = 0b1)

#define NVIC_SPI1_DISABLE()					(NVIC_ICER->NVIC_ICER1.bits.CLRENA35 = 0b1)
#define NVIC_SPI2_DISABLE()					(NVIC_ICER->NVIC_ICER1.bits.CLRENA36 = 0b1)

#define NVIC_USART1_DISABLE()				(NVIC_ICER->NVIC_ICER1.bits.CLRENA37 = 0b1)
#define NVIC_USART2_DISABLE()				(NVIC_ICER->NVIC_ICER1.bits.CLRENA38 = 0b1)
#define NVIC_USART3_DISABLE()				(NVIC_ICER->NVIC_ICER1.bits.CLRENA39 = 0b1)


//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*
//-*-*-*-*-*-*-*-*-*-*-*-
//Generic Macros:
//-*-*-*-*-*-*-*-*-*-*-*




#endif /* INC_STM32F103C6_H_ */
