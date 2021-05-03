#include <stdint.h>
#include <stdio.h>
#include "TM4C123.h"
#include <string.h>
#include "UART.h"
#include "delayTimer.h"


int main_uart(void)
{	
	char *name = "hosni";
	
	while(1)
	{
		printMsg(name);
		printMsg("\n\r");
		delayMs(500);
	}
}
