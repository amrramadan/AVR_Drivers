/*
 * mc1.c
 *
 *  Created on: Oct 13, 2019
 *      Author: amr ramadan
 */

#include "spi.h"

#define ON  1
#define OFF 0

int main(){

	SPI_initMaster(Fosc_4);
	CLEAR_BIT(DDRA,PA0);
	//CLEAR_BIT(PORTA,PA0);

	while(1)
	{
		if(BIT_IS_SET(PINA,PA0))
			SPI_sendByte(ON);
		else
			SPI_sendByte(OFF);
	}

}
