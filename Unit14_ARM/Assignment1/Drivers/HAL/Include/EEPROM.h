/*
 * LCD.h
 *
 * Created: 27-May-21 7:53:05 PM
 *  Author: Mostafa
 */ 

#include <stm32f103c6_i2c_driver.h>

#ifndef EEPROM_H_
#define EEPROM_H_

#define EEPROM_Slave_Address		0x2A

void EEPROM_init(void);
void EEPROM_WriteNBytes(uint16 memory_address,uint8 * data,uint32 dataLength );
void EEPROM_ReadByte(uint16 memory_address,uint8 * data,uint32 dataLength);

#endif /* EEPROM_H_ */
