/**
 * @file UART.c
 * @brief Abstraction of sending and recieving data using UART
 *
 * @author Hosni Adel
 * @date Mar 26 2021
 *
 */
#include "TM4C123.h"
#include "UART.h"
#include "delayTimer.h"
#include <string.h>
#include <stdint.h>


#define BR 11520.0   // Baud Rate

/**************************************************************
				Function Definitions
**************************************************************/

void UART0_init(void)
{
	float I_FBRD;
	SYSCTL->RCGCUART |= 1; // provide clock to UART0 
	SYSCTL->RCGCGPIO |= 1; // enable clock to PORTA 
	
	// UART0 initialization 
	UART0->CTL = 0; 	   // disable UART0 
	
	I_FBRD = (SystemCoreClock / 16.0) / BR;
	UART0->IBRD = (uint32_t) I_FBRD;	// Integer baudrate devisor
	
	I_FBRD = (I_FBRD - (uint32_t)I_FBRD) * 1000;
	UART0->FBRD = (uint32_t) I_FBRD;    // float baudrate devisor
	
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
	UART0->DR = c; 					// before giving it another byte 
}


uint8_t UART0Rx(void)
{
	uint8_t c;
	
	while((UART0->FR & 0x10) != 0); // wait until the buffer is not empty 
	c = UART0->DR; 					// read the received data 
	
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