/*
 * Module: i2c.h
 * Description: Header file for I2C Driver
 *  Created on: Oct 10, 2019
 *      Author: Amr Ramadan
 */



#include "common_macros.h"
#include "std_types.h"
#include "micro_config.h"

#ifndef I2C_H_
#define I2C_H_

/*******************Preprocessor Macros*************************/

/*TWSR Register status BITS*/
#define TW_START 		0x08 //start condition has been transmitted
#define TW_REP_START	0x10 //repeated start condition has been transmitted
#define TW_MT_SLA_W_ACK	0x18 //master transmitted (slave address + write request) to slave and Ack received from slave
#define TW_MT_SLA_R_ACK 0x40 //master transmitted (slave address + read request) to slave and Ack received from slave

/*******************Functions Prototypes*************************/
void TWI_init(void);
void TWI_START(void);
void TWI_stop(void);
void TWI_Write(uint8 Data);
uint8 TWI_readWithACK(void);
uint8 TWI_readWithNACK(void);
uint8 TWI_getStatus(void);

#endif /* I2C_H_ */
