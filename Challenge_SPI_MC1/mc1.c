/*
 * main.c
 *
 *  Created on: Oct 13, 2019
 *      Author: amr ramadan
 */


#include "spi.h"
#include "keypad.h"
int main(){
	uint8 var;
	SPI_initMaster(Fosc_4);
   KEYPAD_PORT_DIR = 0x00; //configure keypad switches as input pins
   KEYPAD_PORT_IN = 0xFF;
	while(1)
	{
		var=Keypad_getPressedKey();
		SPI_sendByte(var);
		_delay_ms(500);
	}

}
