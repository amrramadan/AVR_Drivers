/*
 * MC2.c
 *
 *  Created on: Oct 13, 2019
 *      Author: amr ramadan
 */

#include "spi.h"

#define ON  1
#define OFF 0

int main(){
	uint8 val;
	SPI_initSlave();
	SET_BIT(DDRC,PC3);
	//CLEAR_BIT(PORTC,PC3);
	while(1){
		val=SPI_receiveByte();
		if(val == ON)
			SET_BIT(PORTC,PC3);
		else if (val == OFF)
			CLEAR_BIT(PORTC,PC3);
	}
}
