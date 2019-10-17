/*
 * main.c
 *
 *  Created on: Oct 13, 2019
 *      Author: amr ramadan
 */


#include "uart.h"

int main(){
uint8 val;
uint8 data;
UART_init();
//CLEAR_BIT(DDRD,PD0);
//SET_BIT(DDRD,PD1);
while(1){
	UART_receiveByte();
}


}
