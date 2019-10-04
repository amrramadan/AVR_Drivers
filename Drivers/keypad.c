/*
 * Module: keypad.c
 * Description: Source file for Keypad Driver
 *  Created on: Oct 4, 2019
 *      Author: Amr Ramadan
 */

#include "keypad.h"

uint8 Keypad_getPressedKey(void)
{
	uint8 col,row;
	for(col=0;col<N_Col;col++)
	{
		KEYPAD_PORT_DIR = (0b00010000<<col);
		KEYPAD_PORT_OUT = (~(0b00010000)<<col);
		for(row=0;row<N_Row;row++)
		{
			if(!(KEYPAD_PORT_IN & (1<<row))){
				return (row*N_Col+col+1);
			}
		}
	}
}
