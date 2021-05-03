/**
 * @file pushButton.c
 * @brief Implementation of configuration of sw1 and sw2
 *
 * @author Hosni Adel
 * @date Mar 2021
 *
 */

#include "pushButton.h"
#include "TM4C123.h"
#include <stdint.h>
/**************************************************************
					Function Definitions
**************************************************************/

void pushButton_init(pushButton button)
{
		SYSCTL->RCGCGPIO |= 0X20;
		if(SW2 == button)
		{
			GPIOF->LOCK = 0x4C4F434B;   // UnlockGPIOCR register because PF0 is locked pin 
			GPIOF->CR = 0x01;           // Make the corresponding GPIOAFSEL, GPIOPUR, GPIOPDR, or GPIODEN bits can be written
		}

		GPIOF->DIR &= ~button;
		GPIOF->DEN |= button;
		GPIOF->PUR |= button;
}

bool pushButton_status(pushButton button)
{
	return((bool)GPIOF->DATA & button);	
}