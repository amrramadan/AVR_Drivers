/*
 * Module: i2c.c
 * Description: source file for I2C Driver
 *  Created on: Oct 10, 2019
 *      Author: Amr Ramadan
 */

#include "i2c.h"

void TWI_init(void) {
	TWCR = (1 << TWEN); // Enable TWI
	//TWSR = 0x00 ; // TWPS1:0 = 00 >> Prescaller Value
	TWBR = 0x02; // Bit Rate: 400.000 kbps  ( Prescaller 00 and F_CPU = 8000000 hz)
	//TWDR = 0;  // Empty Data Register
	TWAR = 0b0000001; // Initiate First Device Address (7-bits Address)
}

void TWI_START(void) {
/*
 * TWEN  = 1 : Enable TWI Protocol
 * TWINT = 1 : Clear Interrupt Flag
 * TWSTA = 1 : Send Start Bit
 */
	TWCR = (1<<TWEN) | (1<<TWINT) | (1<<TWSTA);
	/*wait until Start bit send successfully*/
	while(BIT_IS_CLEAR(TWCR,TWINT));
}

void TWI_stop(void)
{
	/*
	 * TWEN  = 1 : Enable TWI Protocol
	 * TWINT = 1 : Clear Interrupt Flag
	 * TWSTA = 1 : Send Stop Bit
	 */
		TWCR = (1<<TWEN) | (1<<TWINT) | (1<<TWSTO);
}

void TWI_Write(uint8 Data){
	// initiate Data Register With Data
	TWDR = Data;
	/*
	 * TWEN  = 1 : Enable TWI Protocol
	 * TWINT = 1 : Clear Interrupt Flag
	 */

	TWCR = (1<<TWEN) | (1<<TWINT);
	/*wait until data is send successfully*/
	while(BIT_IS_CLEAR(TWCR,TWINT));
}

uint8 TWI_readWithACK(void){
	/*
	 * TWEN  = 1 : Enable TWI Protocol
	 * TWINT = 1 : Clear Interrupt Flag
	 * TWEA  = 1 : Enable Acknowledge Bit
	 */
	TWCR = (1<<TWEN) | (1<<TWINT) | (1<<TWEA);
	/*wait until Ack is received successfully*/
	while(BIT_IS_CLEAR(TWCR,TWINT));
	return TWDR; //Read Data

}
uint8 TWI_readWithNACK(void){
	/*
	 * TWEN  = 1 : Enable TWI Protocol
	 * TWINT = 1 : Clear Interrupt Flag
	 */
	TWCR = (1<<TWEN) | (1<<TWINT);
	/*wait until data is received successfully*/
	while(BIT_IS_CLEAR(TWCR,TWINT));
	return TWDR; //Read Data
}

uint8 TWI_getStatus(void){
	uint8 status;
	status = TWSR & 0xF8;
	return status;
}

