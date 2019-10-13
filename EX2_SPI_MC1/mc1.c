/*
 * MC1.c
 *
 *  Created on: Oct 13, 2019
 *      Author: amr ramadan
 */

#include "spi.h"


int main(){
	//uint8 Str[]="I am Micro1";
	SPI_initMaster(Fosc_4);
	_delay_ms(50);
	SPI_sendString("amr#");
	while(1){

	}
}
