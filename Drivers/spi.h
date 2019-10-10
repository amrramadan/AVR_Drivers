/*
 * Module: spi.h
 * Description: Header file for SPI Driver
 *  Created on: Oct 10, 2019
 *      Author: Amr Ramadan
 */

#ifndef SPI_H_
#define SPI_H_
#include "common_macros.h"
#include "std_types.h"
#include "micro_config.h"

typedef enum SCK_Frequency {Fosc_4,Fosc_16,Fosc_64,Fosc_128}SCK;


/*******************Functions Prototypes*************************/
void SPI_initSlave(void);
void SPI_sendByte(uint8 Data);
uint8 SPI_receiveByte(void);
void SPI_sendString(uint8 *Ptr);
void SPI_receiveString(uint8 *Ptr);

#endif /* SPI_H_ */
