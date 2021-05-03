/**
* @file delay.h
* @brief This file contain dealy functions 
*
* we use GPTM to achieve delay
*
* @author Hosni Adel
* @date Mar 25 2021
*
*/
#ifndef __DELAYTIMER_H__
#define __DELAYTIMER_H__
#include <stdint.h>

/**
* @brief Configure the Timer3 to achieve delay in micros 
*
* @param n the time in microsec needed for delay
* 
* @return void
*/
void delayMicros(uint32_t n);

/**
* @brief Configure the Timer2 to achieve delay in millis 
*
* @param n the time in millisec needed for delay
* 
* @return void
*/
void delayMs(uint32_t n);
#endif