#include <stdint.h>
#include <stdio.h>
#include <string.h>


#include "TM4C123.h"
#include "pushButton.h"
#include "delayTimer.h"
#include "ultrasonic.h"
#include "UART.h"
#include "LEDs.h"


int main_testUltrasonic(void)
{	
	float distance;
	char str[100];
	
	ultrasonicPFConfig x;
	x.ECHO = 0x40;			// pin PF6
	x.TRIG = 0x80;			// pin PF7
	
	ultrasonic_init(x);

	while(1)
	{	
		distance = ultrasonic_measure();

		sprintf(str,"distance: %f cm \n\r", distance);
		printMsg(str);
	}

}
