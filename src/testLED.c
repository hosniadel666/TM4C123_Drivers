#include <stdint.h>
#include <stdio.h>

#include "TM4C123.h"
#include "delayTimer.h"
#include "LEDs.h"



int main_testLED(void)
{

	LEDs ledR;
	

	ledR = RED;
	
	LEDs_init(ledR);

	while(1)
	{
		LED_ON(ledR);
		delayMs(500);
		LED_OFF(ledR);
		delayMs(500);
	}
	
}