/**
 * @file Keypad.c
 * @brief Implementation of the interfacing of 4x3 keypad
 *
 * This implementation file provides an initialization the 
 * keypad and some functionality and
 *
 * @author Hosni Hosni
 * @date Mar 26 2021
 *
 */
#include "TM4C123.h"
#include "Keypad.h"
#include "delayTimer.h"

/*********************************************
			Function Definitions
**********************************************/

void keypad_init(void)
{
	SYSCTL->RCGCGPIO |= 0x14;   // Enable Clock to GPIO C&E 

	KEYPAD_ROW->DIR |= 0x0F;    // set row pins 3-0 as output
	KEYPAD_ROW->DEN |= 0x0F;    // set row pins 3-0 as digital pins 
	KEYPAD_ROW->ODR |= 0x0F;    // set row pins 3-0 as open drain 

	KEYPAD_COL->DIR &= ~(0xE0); // set column pin 7-5 as input
	KEYPAD_COL->DEN |= 0xE0;    // set column pin 7-5 as digital pins 
	KEYPAD_COL->PUR |= 0xE0;    // enable pull-ups for pin 7-5
}

uint8_t keypadIspressed(void)
{
	int col;

	// check to see any key pressed 
	KEYPAD_ROW->DATA = 0;           // enable all rows 
	col = KEYPAD_COL->DATA & 0xE0;  // read all columns 

	if (col == 0xE0)
		return 0;                   // no key pressed 
	else
		return 1;                   // a key is pressed 
}

uint8_t keypadGetkey(void)
{

	uint8_t row, col;

	// check to see any key pressed first 
	KEYPAD_ROW->DATA = 0;               // enable all rows 

	col = KEYPAD_COL->DATA & 0xE0;      // read all columns 
	if (col == 0xE0) return 0;          // no key pressed 

	while (1)
	{
		row = 0;
		KEYPAD_ROW->DATA = 0x0E;        // enable row 0 
		delayMs(2);                     // wait for signal to settle 
		col = KEYPAD_COL->DATA & 0xE0;
		if (col != 0xE0) break;

		row = 1;
		KEYPAD_ROW->DATA = 0x0D;        // enable row 1 
		delayMs(2);                     // wait for signal to settle 
		col = KEYPAD_COL->DATA & 0xE0;
		if (col != 0xE0) break;

		row = 2;
		KEYPAD_ROW->DATA = 0x0B;        // enable row 2 
		delayMs(2);                     // wait for signal to settle 
		col = KEYPAD_COL->DATA & 0xE0;
		if (col != 0xE0) break;

		row = 3;
		KEYPAD_ROW->DATA = 0x07;        // enable row 3 
		delayMs(2);                     // wait for signal to settle 
		col = KEYPAD_COL->DATA & 0xE0;
		if (col != 0xE0) break;

		return 0;                       // if no key is pressed 
	}

	// gets here when one of the rows has key pressed 
	if (col == 0x60) return keymap[row][0]; // key in column 0 
	if (col == 0xA0) return keymap[row][1]; // key in column 1 
	if (col == 0xC0) return keymap[row][2]; // key in column 2 

	return 0;
}
 
