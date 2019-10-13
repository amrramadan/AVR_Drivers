/*
 * Module: spi.c
 * Description: Source file for SPI Driver
 *  Created on: Oct 10, 2019
 *      Author: Amr Ramadan
 */

#include "spi.h"

void SPI_initMaster(enum SCK_Frequency SCK) {

	DDRB |= (1 << PB4); 	//SS Output
	DDRB |= (1 << PB5);	 	//MOSI Output
	DDRB &= (~(1 << PB6));	//MISO Input
	DDRB |= (1 << PB7); 	//SCK Output

	/*
	 * SPE =1 : Enable SPE
	 * MSTR=1 : Master Configuration
	 * SPR1:0 = User Configure
	 */
	SPCR = (1 << SPE) | (1 << MSTR) | (SCK & 0x03);

}

void SPI_initSlave(void) {
	DDRB &= (~(1 << PB4));	//SS Input
	DDRB &= (~(1 << PB5));	//MISO Input
	DDRB |= (1 << PB6);	 	//MOSI Output
	DDRB &= (~(1 << PB7));	//SCK Input

	/*
	 * SPE =1 : Enable SPE
	 * Slave Configuration
	 */
	SPCR = (1 << SPE);
}

void SPI_sendByte(uint8 Data){
	SPDR = Data; //Send Data to SPI
	/* wait until data sent ( flag =1 )*/
	while(BIT_IS_CLEAR(SPSR,SPIF));
}

uint8 SPI_receiveByte(void)
{	/* wait until data received ( flag = 1 )*/
	while(BIT_IS_CLEAR(SPSR,SPIF));
	return SPDR; //return data
}

void SPI_sendString(const uint8 *Ptr) {
	uint8 i = 0;
	while(Ptr[i] != '\0')
	{
		SPI_sendByte(Ptr[i]);
		i++;
	}
}

void SPI_receiveString(uint8 *Ptr){
	unsigned char i = 0;
	Ptr[i] = SPI_receiveByte();
	while(Ptr[i] != '#')
	{
		i++;
		Ptr[i] = SPI_receiveByte();
	}
	Ptr[i] = '\0';
}
