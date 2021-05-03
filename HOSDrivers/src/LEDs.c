/**
 * @file LEDs.c
 * @brief Implementation of configuration of LEDS in the board
 *
 * @author Hosni Adel
 * @date Mar  2021
 *
 */

#include "LEDs.h"
#include "TM4C123.h"
#include <stdint.h>

/**************************************************************
					Function Definitions
**************************************************************/

void LEDs_init(LEDs led)
{
	SYSCTL->RCGCGPIO |= 0X20;		
	GPIOF->DIR |= led;
	GPIOF->DEN |= led;
	GPIOF->DATA = 0;

}

void LED_ON(LEDs led)
{
	GPIOF->DATA |= led; 
}

void LED_OFF(LEDs led)
{
	GPIOF->DATA &= ~led; 
}

void ALL_LEDs_ON()
{
	SYSCTL->RCGCGPIO |= 0x20;	
	GPIOF->DIR |= 0x0E;
	GPIOF->DEN |= 0x0E;
	GPIOF->DATA |= 0x0E; 
}

void ALL_LEDs_OFF()
{
	SYSCTL->RCGCGPIO |= 0x20;		
	GPIOF->DIR |= 0x0E;
	GPIOF->DEN |= 0x0E;
	GPIOF->DATA &= ~0x0E; 
}