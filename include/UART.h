/**
* @file UART.h
* @brief This file should use the uart peripherals
*
* This header file provides configuration of UARTS
* and send and recieve data
*
* @author Hosni Adel
* @date Mar 26 2021
*
*/
#ifndef __UART_H__
#define __UART_H__

#include "TM4C123.h"
#include <stdint.h>

/**
* @brief Configure the uart pins to use them
* 
* Here we will configure the UART0 which connected
* to the ICDL (UART0RX --> PA0, UART0TX --> PA1)
*
* @param void
* 
* @return void
*/
void UART0_init(void);

/**
* @brief Transfer the data using TX pin of UART0
* 
* @param c 8-bits variable which hold data need to send
* 
* @return void
*/
void UART0Tx(uint8_t c);

/**
* @brief Recieve the data using RX pin of UART0
* 
* @param void
* 
* @return 8-bits variable which hold data need to recieve
*/
uint8_t UART0Rx(void);


#endif