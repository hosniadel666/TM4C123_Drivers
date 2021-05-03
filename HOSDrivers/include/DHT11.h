/**
* @file DHT11.h
* @brief 
*
* @author Hosni Adel
* @date Mar  2021
*
*/
#ifndef __DHT11_H__
#define __DHT11_H__

#include "TM4C123.h"
#include <stdint.h>


/**
* @brief 
* 
*
* @param 
* 
* @return 
*/
void DHT11_init(void);

/**
* @brief 
* 
* @param 
* 
* @return 
*/
void UART0Tx(uint8_t c);

/**
* @brief 
* 
* @param 
* 
* @return 
*/
uint8_t UART0Rx(void);

/**
* @brief Print msg using uart
* 
* @param pointer to char
* 
* @return void
*/
void printMsg(char *msg);

#endif