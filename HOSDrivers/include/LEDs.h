/**
* @file LEDs.h
* @brief 
*
*
*
* @author Hosni Adel
* @date Mar  2021
*
*/
#ifndef __LEDS_H__
#define __LEDS_H__





typedef enum{
	RED = 0x02,
	BLUE = 0x04,
	GREEN = 0x08
}LEDs;

void LEDs_init(LEDs led);

void LED_ON(LEDs led);
	
void LED_OFF(LEDs led);

void ALL_LEDs_ON();

void ALL_LEDs_OFF();


#endif