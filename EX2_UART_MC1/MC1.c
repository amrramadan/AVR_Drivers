/*
 * main.c
 *
 *  Created on: Oct 13, 2019
 *      Author: amr ramadan
 */


#include "uart.h"
#include "keypad.h"
int main(){
uint8 var;
UART_init();
KEYPAD_PORT_DIR = 0x00;

while(1){
	var = Keypad_getPressedKey();
	if(var>=0 && var<=9)
		UART_sendByte(var);
	_delay_ms(500);
}


}
