#include <stdint.h>
#include <stdio.h>

#include "TM4C123.h"
#include "pushButton.h"
#include "delayTimer.h"
#include "LEDs.h"



int main_testPushButton(void)
{
	pushButton pb1;
	LEDs ledR;
	
	pb1 = SW1;
	pushButton_init(pb1); // Equivellant to pushButton_init(SW1)
	
	ledR = RED;
	
	LEDs_init(ledR);

	
	while(1)
	{
		if(!pushButton_status(pb1))
		{	
			LED_ON(ledR);

		}
		else
		{	
			LED_OFF(ledR);
		}
	}
	
}