/*
 * main.c
 *
 *  Created on: Oct 13, 2019
 *      Author: amr ramadan
 */

#include "micro_config.h"
#include "external_eeprom.h"

int main(){
	uint8 Data;
	DDRD = 0xFF;
	PORTD = 0x00;
	EEPROM_init(); //initiate a communication
	EEPROM_writeByte(0x0511,0x0F); // access device, memory location and write 0x0F in eeprom
	_delay_ms(10);
	EEPROM_readByte(0x0511,&Data); // access device, memory location and receive data
	while(1){
		PORTD = Data;
	}

}
