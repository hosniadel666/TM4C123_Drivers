#include <stdint.h>
#include <stdio.h>
#include "TM4C123.h"

#include "UART.h"
#include "delayTimer.h"


int main(void)
{	
	char *name = "hosni";
	UART0_init();
	while(1)
	{
		for(int i = 0; i < 5; i++)
		{
			UART0Tx(name[i]);		

		}
		UART0Tx('\n');
		UART0Tx('\r');
		delayMs(500);
	}
}
