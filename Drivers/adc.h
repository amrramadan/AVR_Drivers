/*
 * Module: adc.h
 * Description: Header file for ADC Driver
 *  Created on: Oct 6, 2019
 *      Author: Amr Ramadan
 */

#ifndef ADC_H_
#define ADC_H_

#include "common_macros.h"
#include "std_types.h"
#include "micro_config.h"

//ADC PRESCALLER SELECT BITS  ( ADC Division Factor )
typedef enum ADC_prescaller {
	DF1, DF2, DF4, DF8, DF16, DF32, DF64, DF128
} ADC_DF;

/************************Functions Prototypes*************************/
//ADC initialization Function with user User Configurable Division Factor
void ADC_init(enum ADC_prescaller ADC_DF);

uint16 ADC_readChannel(uint8 ch_num);
#endif /* ADC_H_ */

