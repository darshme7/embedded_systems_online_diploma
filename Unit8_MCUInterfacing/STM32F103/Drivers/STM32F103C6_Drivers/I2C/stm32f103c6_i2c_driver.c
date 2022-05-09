/*
 * stm32f103c6_usart_driver.c
 *
 *  Created on: Jun 11, 2021
 *      Author: mosta
 */

//--------------------------------------------------------------------------------------------------------------------
//Includes
//--------------------------------------------------------------------------------------------------------------------

#include "stm32f103c6_i2c_driver.h"
#include "stm32f103c6_gpio_driver.h"
#include "stm32f103c6_rcc_driver.h"


//--------------------------------------------------------------------------------------------------------------------
//Globals
//--------------------------------------------------------------------------------------------------------------------

void (*I2C_P_ISR_CallBack)(Slave_state state);

// ====================================================================================================================
//															APIs
// ====================================================================================================================

/**================================================================
 * @Fn			-MCAL_I2C_init.
 * @brief	    -initialize the I2Cx according to config instance config.
 * @param [in] 	-I2Cx: x can be (1,2) to select the I2C peripheral.
 * @param [in] 	-cofig: pointer to I2C_config that contains I2C configuration.
 * @retval 		-none
 * Note			-none
 */

void MCAL_I2C_init(I2C_typedef * I2Cx,I2C_config * config){
	GPIO_config cfg;
	if(I2Cx == I2C1){
		cfg.GPIO_PinNumber = GPIO_PIN6;
		cfg.GPIO_PinMode = GPIO_MODE_OUTPUT_AF_OD;
		cfg.GPIO_OutputSpeed = GPIO_SPEED_10M;
		MCAL_GPIO_init(GPIOB, &cfg);

		cfg.GPIO_PinNumber = GPIO_PIN7;
		cfg.GPIO_PinMode = GPIO_MODE_OUTPUT_AF_OD;
		cfg.GPIO_OutputSpeed = GPIO_SPEED_10M;
		MCAL_GPIO_init(GPIOB, &cfg);

		RCC_I2C1_CLK_EN();
		//Interrupt mode(slave)
		if(config->I2C_P_ISR_CallBack != NULL){
			I2Cx->I2C_CR2.bits.ITBUFEN = 0b1;
			I2Cx->I2C_CR2.bits.ITEVTEN = 0b1;
			I2Cx->I2C_CR2.bits.ITERREN = 0b1;
			NVIC_I2C1EV_ENABLE();
			NVIC_I2C1ER_ENABLE();

		}
	}else if(I2Cx == I2C2){
		cfg.GPIO_PinNumber = GPIO_PIN10;
		cfg.GPIO_PinMode = GPIO_MODE_OUTPUT_AF_OD;
		cfg.GPIO_OutputSpeed = GPIO_SPEED_10M;
		MCAL_GPIO_init(GPIOB, &cfg);

		cfg.GPIO_PinNumber = GPIO_PIN11;
		cfg.GPIO_PinMode = GPIO_MODE_OUTPUT_AF_OD;
		cfg.GPIO_OutputSpeed = GPIO_SPEED_10M;
		MCAL_GPIO_init(GPIOB, &cfg);
		RCC_I2C2_CLK_EN();
		if(config->I2C_P_ISR_CallBack != NULL){
			I2Cx->I2C_CR2.bits.ITBUFEN = 0b1;
			I2Cx->I2C_CR2.bits.ITEVTEN = 0b1;
			I2Cx->I2C_CR2.bits.ITERREN = 0b1;
			NVIC_I2C2EV_ENABLE();
			NVIC_I2C2ER_ENABLE();
		}
	}
	I2Cx->I2C_CR1.bits.PE = 0b0;
	I2Cx->I2C_SR1.I2C_SR1=0;
	I2Cx->I2C_SR2.I2C_SR2=0;
	uint32 Pclk1 = MCAL_RCC_PCLCK1Freq();

	if(config->I2C_Mode ==I2C_MODE_I2C){
		//• to configure clock before enable the peripheral.
		I2Cx->I2C_CR2.bits.FERQ = (Pclk1/(1000000));
		//• Configure clock control registers
		if(config->I2C_ClockSpeed == I2C_SCKL_SM_50K||config->I2C_ClockSpeed == I2C_SCKL_SM_100K){
			I2Cx->I2C_CCR.bits.CCR = (Pclk1/((config->I2C_ClockSpeed)<< 1)) ;
			//• Configure the rise time register
			I2Cx->I2C_TRISE.bits.TRISE = I2Cx->I2C_CR2.bits.FERQ+1;

		}else{

			//fast mode not supported
		}

		I2Cx->I2C_CR1.bits.ACK = config->I2C_ACK;
		I2Cx->I2C_CR1.bits.ENGC = config->I2C_GeneralCallAddressDetection;
		I2Cx->I2C_CR1.bits.NOSTRETCH = config->I2C_StretchMode;
		I2Cx->I2C_CR1.bits.SMBU = config->I2C_Mode;

		if(config->I2C_Slave_Address.DualMode){
			I2Cx->I2C_OAR2.bits.ENDUAL = config->I2C_Slave_Address.DualMode;
			I2Cx->I2C_OAR1.bits.ADD7_1 = config->I2C_Slave_Address.PrimaryAddress;
			I2Cx->I2C_OAR2.bits.ADD2 = config->I2C_Slave_Address.SecondaryAddress;
		}
		I2Cx->I2C_OAR1.bits.ADDMODE = config->I2C_Slave_Address.I2C_AddressingMode;
		I2Cx->I2C_OAR1.bits.ADD7_1 = config->I2C_Slave_Address.PrimaryAddress;
	}else{

		//not supported
	}

	I2Cx->I2C_CR1.bits.PE = 0b1;

}

/**================================================================
 * @Fn			-MCAL_I2C_deinit.
 * @brief	    -deinitialize the I2Cx.
 * @param [in] 	-I2Cx: x can be (1,2) to select the I2C peripheral.
 * @retval 		-none
 * Note			-none
 */

void MCAL_I2C_deinit(I2C_typedef * I2Cx){

	if(I2Cx == I2C1){

		NVIC_I2C1EV_DISABLE();
		NVIC_I2C1ER_DISABLE();
		RCC->APB1RSTR.bits.I2C1RST = 0b1;
		RCC->APB1RSTR.bits.I2C1RST = 0b0;

	}else if(I2Cx == I2C2){

		NVIC_I2C2EV_DISABLE();
		NVIC_I2C2ER_DISABLE();
		RCC->APB1RSTR.bits.I2C2RST = 0b1;
		RCC->APB1RSTR.bits.I2C2RST = 0b0;
	}
}


/**================================================================
 * @Fn			-MCAL_I2C_Master_TX.
 * @brief	    -transmit the data passed form user.
 * @param [in] 	-I2Cx: x can be (1,2) to select the I2C peripheral.
 * @param [in] 	-data: data to be transmitted.
 * @retval 		-none
 * Note			-none
 */

void MCAL_I2C_Master_TX(I2C_typedef * I2Cx,uint16 SlaveAddress,uint8 * DataBuffer , uint32 DataLength,Stop_condition Stop,Repeated_start Start){
	uint32 i;
	I2C_GenerateStart(I2Cx, enable, start);
	while(!I2C_GetFlagStatus(I2Cx, I2C_EV5));
	I2C_SendAddress(I2Cx, SlaveAddress, I2C_Direction_Transmit);
	while(!I2C_GetFlagStatus(I2Cx, I2C_EV6));
	while(!I2C_GetFlagStatus(I2Cx, I2C_Master_Transmitting));

	for(i=0;i<DataLength;i++){
		I2Cx->I2C_DR.bits.DR = DataBuffer[i];
		while(!I2C_GetFlagStatus(I2Cx, I2C_EV8));
	}
	if(Stop == with_stop){
		I2C_GenerateStop(I2Cx,enable);
	}
}

/**================================================================
 * @Fn			-MCAL_I2C_Master_RX.
 * @brief	    -reads data received form I2C register.
 * @param [in] 	-I2Cx: x can be (1,2) to select the I2C peripheral.
 * @retval 		-data recevied from I2C register.
 * Note			-none
 */
void MCAL_I2C_Master_RX(I2C_typedef * I2Cx,uint16 SlaveAddress,uint8 * DataBuffer , uint32 DataLength,Stop_condition Stop,Repeated_start start){
	uint32 i;
	uint8 Ack=1;
	if(!(I2Cx->I2C_CR1.bits.ACK)){
		I2Cx->I2C_CR1.bits.ACK = 0b1;
		Ack = 0;
	}
	I2C_GenerateStart(I2Cx, enable, start);
	while(!I2C_GetFlagStatus(I2Cx, I2C_EV5));
	I2C_SendAddress(I2Cx, SlaveAddress, I2C_Direction_Recieve);
	while(!I2C_GetFlagStatus(I2Cx, I2C_EV6));

	if(DataLength){
		for( i=DataLength; i > 1; i--){
			while(!I2C_GetFlagStatus(I2Cx, I2C_EV7));
			*DataBuffer = I2Cx->I2C_DR.bits.DR;
			DataBuffer++;
		}
		I2Cx->I2C_CR1.bits.ACK = 0b1;
	}
	if(Stop == with_stop){
		I2C_GenerateStop(I2Cx,enable);
	}
	if(Ack){
		I2Cx->I2C_CR1.bits.ACK = 0b1;
	}
}

void I2C_GenerateStart(I2C_typedef * I2Cx ,Functional_state state,Repeated_start start){
	if(start  != repeated_start){
		while(I2C_GetFlagStatus(I2Cx, I2C_busyflag));

	}
	//		Bit 8 START: Start generation
	//		This bit is set and cleared by software and cleared by hardware when start is sent or PE=0.
	//		In Master Mode:
	//		0: No Start generation
	//		1: Repeated start generation
	//		In Slave mode:
	//		0: No Start generation
	//		1: Start generation when the bus is free

	if(state != disable){
		I2Cx->I2C_CR1.bits.START = 0b1;
	}else {
		I2Cx->I2C_CR1.bits.START = 0b0;
	}
}

void I2C_SendAddress(I2C_typedef * I2Cx,uint16 SlaveAddress,I2C_direction Direction){

	SlaveAddress = SlaveAddress << 1;

	if(Direction == I2C_Direction_Recieve){
		SlaveAddress |= ((uint8)(1<<0));}
	I2Cx->I2C_DR.I2C_DR = SlaveAddress;
}

void I2C_GenerateStop(I2C_typedef * I2Cx ,Functional_state state){

	if(state !=disable)
		I2Cx->I2C_CR1.bits.STOP = 0b1;
	else
		I2Cx->I2C_CR1.bits.STOP = 0b0;
}

FlagStatus I2C_GetFlagStatus(I2C_typedef * I2Cx , Status flag){
	FlagStatus bitstate = reset;
	uint32 read;
	switch(flag){
	case I2C_busyflag:{
		//		Bit 1 BUSY: Bus busy
		//		0: No communication on the bus
		//		1: Communication ongoing on the bus
		//		– Set by hardware on detection of SDA or SCL low
		//		– cleared by hardware on detection of a Stop condition.
		//		It indicates a communication in progress on the bus. This information is still updated when
		//		the interface is disabled (PE=0).
		if(I2Cx->I2C_SR2.bits.BUSY)
			bitstate =  set;
		else
			bitstate = reset ;
		break;
	}
	case I2C_EV5:{
		//		Bit 0 SB: Start bit (Master mode)
		//		0: No Start condition
		//		1: Start condition generated.
		//		– Set when a Start condition generated.
		//		– Cleared by software by reading the SR1 register followed by writing the DR register, or by
		//		hardware when PE=0
		if(I2Cx->I2C_SR1.bits.SB)
			bitstate =  set;
		else
			bitstate = reset ;
		break;
	}
	case I2C_EV6:{
		//		Bit 1 ADDR: Address sent (master mode)/matched (slave mode)
		//		This bit is cleared by software reading SR1 register followed reading SR2, or by hardware
		//		when PE=0
		if(I2Cx->I2C_SR1.bits.ADDR)
			bitstate =  set;
		else
			bitstate = reset ;

		read = I2Cx->I2C_SR2.I2C_SR2;
		break;
	}
	case I2C_EV7:{
		//		Bit 6 RxNE: Data register not empty (receivers)
		//		0: Data register empty
		//		1: Data register not empty
		//		– Set when data register is not empty in receiver mode. RxNE is not set during address phase.
		//		– Cleared by software reading or writing the DR register or by hardware when PE=0.
		//		RxNE is not set in case of ARLO event.
		//		Note: RxNE is not cleared by reading data when BTF is set, as the data register is still full.
		if(I2Cx->I2C_SR1.bits.RxNE)
			bitstate =  set;
		else
			bitstate = reset ;
		break;
	}
	case I2C_EV8_1:
	case I2C_EV8:{
		//TxE=1, shift register not empty, data register empty, cleared by writing DR register
		if(I2Cx->I2C_SR1.bits.TxE)
			bitstate =  set;
		else
			bitstate = reset ;
		break;
	}

	case I2C_Master_Transmitting:{

		if(I2Cx->I2C_SR1.bits.TxE&&I2Cx->I2C_SR2.bits.BUSY&&I2Cx->I2C_SR2.bits.MSL&&I2Cx->I2C_SR2.bits.TRA)
			bitstate =  set;
		else
			bitstate = reset ;
		break;
	}
	}

	return bitstate;
}


/**================================================================
 * @Fn			-MCAL_USART_receiveString.
 * @brief	    -reads char by char received form USART register.
 * @param [in] 	-USARTx: x can be (1..3) to select the USART peripheral.
 * @retval 		-string recevied from USART register.
 * Note			-none
 */
void MCAL_I2C_SlaveSendData(I2C_typedef *I2Cx,uint8 data){
	I2Cx->I2C_DR.bits.DR = data;
}

uint8 MCAL_I2C_SlaveRecieveData(I2C_typedef *I2Cx){
	 return (uint8)I2Cx->I2C_DR.bits.DR;
}


void I2C1_EV_IRQHandler(void){


}

void I2C2_EV_IRQHandler(void){

}
