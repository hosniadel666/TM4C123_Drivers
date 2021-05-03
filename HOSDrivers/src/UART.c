/**
 * @file UART.c
 * @brief Abstraction of sending and recieving data using UART
 *
 * @author Hosni Adel
 * @date Mar  2021
 *
 */
#include "TM4C123.h"
#include "UART.h"
#include "delayTimer.h"
#include <string.h>
#include <stdint.h>

/**************************************************************
				Function Definitions
**************************************************************/

void UART0_init(void)
{
	// Enable clock to required ports
	SYSCTL->RCGCUART |= 1; 
	SYSCTL->RCGCGPIO |= 1;  
	
	// UART0 initialization 
	UART0->CTL = 0; 	   // disable UART0 
	UART0->IBRD = 104; 	   // 16MHz/16=1MHz, 1MHz/104=9600 baud rate 
	UART0->FBRD = 11; 	   // fraction part, see Example 4-4 
	UART0->CC = 0; 		   // use system clock 
	
	UART0->LCRH = 0x60;    // 8-bit, no parity, 1-stop bit, no FIFO 
	UART0->CTL = 0x301;    // enable UART0, TXE, RXE 

	
	// UART0 TX0 and RX0 use PA0 and PA1. Set them up. 
	GPIOA->DEN = 0x03; 	   // Make PA0 and PA1 as digital 
	GPIOA->AFSEL = 0x03;   // Use PA0,PA1 alternate function 
	GPIOA->PCTL = 0x11;    // configure PA0 and PA1 for UART 
	
	delayMs(1); 		   // wait for output line to stabilize 
}

void UART0Tx(uint8_t c)
{
	while((UART0->FR & 0x20) != 0); // wait until Tx buffer not full 
	UART0->DR = c; 					
}


uint8_t UART0Rx(void)
{
	uint8_t c;
	
	while((UART0->FR & 0x10) != 0); // wait until the buffer is not empty 
	c = UART0->DR; 					
	
	return c; 
}

void printMsg(char *msg)
{
	UART0_init();
	for(uint32_t i = 0; i < strlen(msg); i++)
	{
		UART0Tx(msg[i]);
	}
}