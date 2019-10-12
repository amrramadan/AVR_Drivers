/*
 * Module: External EEPROM
 * Description: source file for EEPROM Driver
 *  Created on: Oct 12, 2019
 *      Author: Amr Ramadan
 */

#include "i2c.h"
#include "external_eeprom.h"

void EEPROM_init(void)
{
	TWI_init();
}

uint8 EEPROM_writeByte(uint16 Address, uint8 Data){
	/* Send Start Bit */
	TWI_START();
	if(TWI_getStatus() != TW_START)
		return ERROR;
	/*Send the Device Address*/
	/*
	 * NOTE: We get bits A10, A9, A8 and R/W = 0 (WRITE)
	 */
	TWI_Write((uint8)(0xA0 |((Address & 0x700)>>7)));
	if(TWI_getStatus() != TW_MT_SLA_W_ACK)
			return ERROR;
	/* Send Required Memory Location */
	TWI_Write((uint8) Address);
	if(TWI_getStatus() != TW_MT_DATA_ACK)
			return ERROR;
	/* Send Byte (Data) */
	TWI_Write(Data);
	if(TWI_getStatus() != TW_MT_DATA_ACK)
			return ERROR;
	/*Send Stop Bit*/
	TWI_stop();
	return SUCCESS;

}

uint8 EEPROM_ReadByte(uint16 Address, uint8 *Data){
	/* Send Start Bit */
	TWI_START();
	if(TWI_getStatus() != TW_START)
		return ERROR;

	/*Send the Device Address*/
	/*
	 * NOTE: We get bits A10, A9, A8 and R/W = 0 (WRITE)
	 */
	TWI_Write((uint8)(0xA0 |((Address & 0x700)>>7)));
	if(TWI_getStatus() != TW_MT_SLA_W_ACK)
			return ERROR;

	/* Send Required Memory Location */
	TWI_Write((uint8) Address);
	if(TWI_getStatus() != TW_MT_DATA_ACK)
			return ERROR;

	/* Send Start Bit */
	TWI_START();
	if(TWI_getStatus() != TW_REP_START)
		return ERROR;

	/*
	 * NOTE: We get bits A10, A9, A8 and R/W = 1 (Read)
	 */
	TWI_Write((uint8)(0xA0 |((Address & 0x700)>>7)|1));
	if(TWI_getStatus() != TW_MT_SLA_R_ACK)
			return ERROR;

	/* Read Byte from Memory with NACK */
	*Data = TWI_readWithNACK();
	if(TWI_getStatus() != TW_MR_DATA_NACK)
			return ERROR;
	/*Send Stop Bit*/
	TWI_stop();
	return SUCCESS;

}
