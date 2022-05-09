/*
 * stm32f103c6_usart_driver.h
 *
 *  Created on: Jun 11, 2021
 *      Author: mosta
 */
//--------------------------------------------------------------------------------------------------------------------
//Includes
//--------------------------------------------------------------------------------------------------------------------

#include "STM32F103C6.h"

#ifndef INC_STM32F103C6_I2C_DRIVER_H_
#define INC_STM32F103C6_I2C_DRIVER_H_

//--------------------------------------------------------------------------------------------------------------------
//User type definitions (structures)
//--------------------------------------------------------------------------------------------------------------------

struct I2C_Device_Address{
	uint8  DualMode; 		// 0:Disable 1:Enable
	uint16 PrimaryAddress;
	uint16 SecondaryAddress;
	uint16 I2C_AddressingMode;	//@ref I2C_ADDRESSINGMODE_define
};

typedef enum{
	I2C_EV_STOP,
	I2C_EV_AF,
	I2C_EV_ADDR_Matched,
	I2C_EV_DATA_REQ,
	I2C_EV_DATA_RCV
}Slave_state;

typedef enum{
	with_stop,
	without_stop
}Stop_condition;

typedef enum{
	start,
	repeated_start
}Repeated_start;

typedef enum{
	enable,
	disable
}Functional_state;

typedef enum{
	reset,
	set
}FlagStatus;

typedef enum{
	I2C_busyflag,
	I2C_EV5,   // EV5: SB=1, cleared by reading SR1 register followed by writing DR register with Address.
	I2C_EV6,   // EV6: ADDR=1, cleared by reading SR1 register followed by reading SR2.
	I2C_EV7,   //
	I2C_EV8,   //TxE=1, shift register not empty, d . ata register empty, cleared by writing DR register
	I2C_EV8_1, //EV8_1: TxE=1, shift register empty, data register empty, write Data1 in DR.
	I2C_Master_Transmitting

}Status;

typedef enum{
	I2C_Direction_Transmit,
	I2C_Direction_Recieve
}I2C_direction;

typedef struct{

	uint32 I2C_ClockSpeed;							//specifies the clock frequency.
													//must be a value of @ref I2C_CLOCKSPEED_define

	uint8 I2C_StretchMode;							//specifies wether to use enable clock stretching or not.
													//must be a value of @ref I2C_STRETCHMODE_define

	uint8 I2C_Mode;									//specifies wether to set peripheral to I2C or SMBus.
													//must be a value of @ref I2C_MODE_define

	struct I2C_Device_Address 	I2C_Slave_Address;

	uint8 I2C_GeneralCallAddressDetection;			//specifies wether to enable General call detection or not.
													//must be a value of @ref I2C_ENGC_define

	uint8 I2C_ACK;									//specifies How Ack is sent.
													//must be a value of @ref I2C_ACK_define

	void (*I2C_P_ISR_CallBack)(Slave_state state);	//pointer to function to be called from interrupt.

}I2C_config;

//--------------------------------------------------------------------------------------------------------------------
//Macros Configuration References
//--------------------------------------------------------------------------------------------------------------------

//@ref I2C_CLOCKSPEED_define
//– Standard Speed (up to 100 kHz)
//– Fast Speed (up to 400 kHz)
//• to configure clock before enable the peripheral.
//---FREQ[5:0]: Peripheral clock frequency
//• Configure clock control registers
//		Thigh = CCR * TPCLK
//		Sm or Fm
//• Configure the rise time register

#define I2C_SCKL_SM_50K		(50000)
#define I2C_SCKL_SM_100K	(100000)
#define I2C_SCKL_FM_200K	(200000)
#define I2C_SCKL_FM_400K	(400000)

//@ref I2C_STRETCHMODE_define
//Bit 7 NOSTRETCH: Clock stretching disable (Slave mode)
//0: Clock stretching enabled
//1: Clock stretching disabled

#define I2C_STRETCHMODE_ENABLE		(0b0)
#define I2C_STRETCHMODE_DISABLE		(0b1)

//@ref I2C_MODE_define
//Bit 1 SMBUS: SMBus mode
//0: I2C mode
//1: SMBus mode

#define I2C_MODE_SMBUS		(0b1)
#define I2C_MODE_I2C		(0b0)

//@ref I2C_ADDRESSINGMODE_define
//Bit 15 ADDMODE Addressing mode (slave mode)
//0: 7-bit slave address (10-bit address not acknowledged)
//1: 10-bit slave address (7-bit address not acknowledged)

#define I2C_7BIT_ADDRESS		(0b0)
#define I2C_10BIT_ADDRESS		(0b1)

//@ref I2C_ENGC_define
//Bit 6 ENGC: General call enable
//0: General call disabled. Address 00h is NACKed.
//1: General call enabled. Address 00h is ACKed.

#define I2C_ENGC			(0b1)
#define I2C_NOT_ENGC		(0b0)

//@ref I2C_ACK_define
//Bit 10 ACK: Acknowledge enable
//This bit is set and cleared by software and cleared by hardware when PE=0.
//0: No acknowledge returned
//1: Acknowledge returned after a byte is received (matched address or data)

#define I2C_ACK_ENABLE			(0b1)
#define I2C_ACK_DISABLE			(0b0)

// ====================================================================================================================
//										APIs Supported by "MCAL I2C DRIVER"
// ====================================================================================================================

void MCAL_I2C_init(I2C_typedef * I2Cx,I2C_config * config);
void MCAL_I2C_deinit(I2C_typedef * I2Cx);

//Master polling

void MCAL_I2C_Master_TX(I2C_typedef * I2Cx,uint16 SlaveAddress,uint8 * DataBuffer , uint32 DataLength,Stop_condition stop,Repeated_start Start);
void MCAL_I2C_Master_RX(I2C_typedef * I2Cx,uint16 SlaveAddress,uint8 * DataBuffer , uint32 DataLength,Stop_condition stop,Repeated_start Start);

//Slave Interrupt
void MCAL_I2C_SlaveSendData(I2C_typedef *I2Cx,uint8 data);
uint8 MCAL_I2C_SlaveRecieveData(I2C_typedef *I2Cx);

//Generic APIs
void I2C_GenerateStart(I2C_typedef * I2Cx ,Functional_state state,Repeated_start Start);
void I2C_GenerateStop(I2C_typedef * I2Cx ,Functional_state state);
FlagStatus I2C_GetFlagStatus(I2C_typedef * I2Cx , Status flag);
void I2C_SendAddress(I2C_typedef * I2Cx,uint16 SlaveAddress,I2C_direction Direction);


#endif /* INC_STM32F103C6_USART_DRIVER_H_ */
