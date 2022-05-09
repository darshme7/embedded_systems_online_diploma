/*
 * Keypad.c
 *
 * Created: 28-May-21 5:51:18 PM
 *  Author: Mostafa
 */ 
#include "EEPROM.h"

void EEPROM_init(void){
	I2C_config cfg;
	cfg.I2C_ACK = I2C_ACK_ENABLE;
	cfg.I2C_ClockSpeed = I2C_SCKL_SM_100K;
	cfg.I2C_GeneralCallAddressDetection = I2C_ENGC;
	cfg.I2C_Mode = I2C_MODE_I2C;
	cfg.I2C_P_ISR_CallBack = NULL;
	cfg.I2C_StretchMode = I2C_STRETCHMODE_ENABLE;
	cfg.I2C_Slave_Address.DualMode = 0;
	cfg.I2C_Slave_Address.I2C_AddressingMode = I2C_7BIT_ADDRESS;
	cfg.I2C_Slave_Address.PrimaryAddress = 0x00;
	cfg.I2C_Slave_Address.SecondaryAddress = (uint32) NULL;
	MCAL_I2C_init(I2C1, &cfg);
}

void EEPROM_WriteNBytes(uint16 memory_address,uint8 * data,uint32 dataLength ){

	uint8 buffer[256];
	uint16 i;
	buffer[0]=memory_address>>8;
	buffer[1]=memory_address;
	for(i=2;	i< (dataLength+2);	i++){
		buffer[i]=data[i-2];
	}
	MCAL_I2C_Master_TX(I2C1, EEPROM_Slave_Address, buffer, (dataLength+2), with_stop, start);
}
void EEPROM_ReadByte(uint16 memory_address,uint8 * data,uint32 dataLength){

	uint8 buffer[2];
	buffer[0]=memory_address>>8;
	buffer[1]=memory_address;
	MCAL_I2C_Master_TX(I2C1, EEPROM_Slave_Address, buffer, 2, without_stop, start);
	MCAL_I2C_Master_RX(I2C1, EEPROM_Slave_Address, data, dataLength, with_stop, repeated_start);

}
