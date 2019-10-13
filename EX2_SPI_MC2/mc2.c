/*
 * MC2.c
 *
 *  Created on: Oct 13, 2019
 *      Author: amr ramadan
 */

#include "spi.h"
#include "lcd.h"

int main(){
	uint8 Str[20];
	LCD_init();
	SPI_initSlave();
	SPI_receiveString(Str);
	LCD_displayString(Str);
	while(1){

	}
}
