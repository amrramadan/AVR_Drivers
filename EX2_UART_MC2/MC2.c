/*
 * main.c
 *
 *  Created on: Oct 13, 2019
 *      Author: amr ramadan
 */


#include "uart.h"

int main(){
uint8 var;
UART_init();
DDRC = 0xFF;
while(1){
	var=UART_receiveByte();
	PORTC =(1<<var);
}
}
