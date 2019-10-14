/*
 * main.c
 *
 *  Created on: Oct 13, 2019
 *      Author: amr ramadan
 */


#include "spi.h"
#include "lcd.h"
int main(){
	uint8 var;
	LCD_init();
	SPI_initSlave();

	while(1){
		var=SPI_receiveByte();
		if(var >=0 && var <=9)
			LCD_integerToString(var);
		else LCD_displayChar(var);
	}

}
