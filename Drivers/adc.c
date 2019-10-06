/*
 * Module: adc.c
 * Description: Source file for ADC Driver
 *  Created on: Oct 6, 2019
 *      Author: Amr Ramadan
 */

#include "adc.h"

//ADC initialization Function
void ADC_init(enum ADC_prescaller ADC_DF) {

	/* ADMUX : REFS1:0 = 00 External Reference Voltage Vref
	 * 		   ADLAR   =	0  Right Adjusted
	 * 		   MUX4:0  = 0000 to Choose ADC Channel 0
	 */
	ADMUX = 0;
	/*
	 *  ADCSRA : ADEN    = 1 for ADC Enable
	 *  	   : ADIE    = 0 for Interrupt Disable
	 *  	   : ADPS2:0 = User Configurable
	 */
	ADCSRA = (1 << ADEN) | (ADC_DF & 0X07);

}

uint16 ADC_readChannel(uint8 ch_num) {

	ADMUX = (ADMUX & (0xE0)) | (ch_num & 0X07); // Clear First 5-bits in ADUMX Register and SET the required Channel Number
	SET_BIT(ADCSRA, ADSC); //ADC Start Conversion
	while (BIT_IS_CLEAR(ADCSRA, ADIF)); //Wait for Conversion Complete
	SET_BIT(ADCSRA, ADIF); // CLEAR ADIF BIT
	return ADC; // RETURN Data Register
}
