#ifndef __PUSHBUTTON_H__
#define __PUSHBUTTON_H__

#include "TM4C123.h"
#include <stdint.h>

/**
* @file SW.h
* @brief Configure sw1 and sw2 in tiva-c board
* 
* Here we will configure the sw1 which connected
* to PF4 and sw2 which connected to PF0
* SW1 --> PF4
* SW2 --> PF0
*
* @author Hosni Adel
* @date Mar 25 2021
*
*/

typedef enum{
	SW1 = 0x10,
	SW2 = 0x01
}pushButton;


typedef enum{
    false,
	true
}bool;



void pushButton_init(pushButton button);

bool pushButton_status(pushButton button);

#endif

