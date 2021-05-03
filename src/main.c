#include <stdint.h>
#include <stdio.h>
#include "TM4C123.h"
#include "pushButton.h"
#include "delayTimer.h"
#include "ultrasonic.h"


void timer1A_init(void);
void timer2A_init(void);

#include <stdio.h>
int main (void)
{
	float distance;
	ultrasonic_portf_conf pin;
	pin.TRIG = 0x80;
	pin.ECHO = 0x40;
	
	//ultrasonic_init(pin);
	while(1)
	{
		distance = ultrasonic_measure();
		//printf("%f\n", distance);
	}
	
		// test SW1
//	SYSCTL->RCGCGPIO |= 0x20;	/* enable clock to GPIOF */
//	GPIOF->DIR &= ~(0x10);	/* PF4 as an input pin */
//	GPIOF->DEN |= 0x10;	/* Enable PF4 as a digital GPIO pins */ 
//	GPIOF->PUR |= 0x10;	/*Enable the pull up resistor to pin PF4*/		 
//    GPIOF->DIR |= 0x0e;
//	GPIOF->DEN |= 0x0e;
//	while(1)
//	{
//		if(!(GPIOF->DATA & 0X10))
//			GPIOF->DATA = 4; /* toggle blue LED */
//		else
//			GPIOF->DATA = 8;
//	}

	
//    SYSCTL->RCGCGPIO |= 0x20;
//	
//		__disable_irq();
//		
//    GPIOF->DIR = 0x0e;
//		GPIOF->DEN = 0x0e;
//		
//    timer1A_init(); 
//    timer2A_init(); 
//	
//    __enable_irq(); 
//	
//    while(1)
//    {

//			GPIOF->DATA |= 4; /* toggle blue LED */

//    }
}

/* Setup Timer1A to create 1 Hz interrupt */
void timer1A_init(void)
{
    SYSCTL->RCGCTIMER |= 2; /* enable clock to Timer Block 1 */
    TIMER1->CTL = 0; /* disable Timer1 before initialization */
    TIMER1->CFG = 0x04; /* 16-bit option */
    TIMER1->TAMR = 0x02; /* periodic mode and down-counter */
    TIMER1->TAPR = 250; /* 16000000 Hz / 250 = 64000 Hz */
    TIMER1->TAILR = 64000; /* 64000 Hz / 64000 = 1 Hz */
    TIMER1->ICR = 0x1; /* clear the Timer1A timeout flag */
    TIMER1->IMR |= 0x01; /* enable Timer1A timeout interrupt */
    TIMER1->CTL |= 0x01; /* enable Timer1A after initialization */
    NVIC->ISER[0] |= 0x00200000; /* enable IRQ21 (D21 of ISER[0]) */
}

/* Setup Timer2A to create 10 Hz interrupt */
void timer2A_init(void)
{
    SYSCTL->RCGCTIMER |= 4; /* enable clock to Timer Block 2 */
    TIMER2->CTL = 0; /* disable Timer2 before initialization */
    TIMER2->CFG = 0x04; /* 16-bit option */
    TIMER2->TAMR = 0x02; /* periodic mode and down-counter */
    TIMER2->TAPR = 250; /* 16000000 Hz / 250 = 64000 Hz */
    TIMER2->TAILR = 6400; /* 64000 Hz / 6400 = 10 Hz */
    TIMER2->ICR = 0x1; /* clear the Timer2A timeout flag */
    TIMER2->IMR |= 0x01; /* enable Timer2A timeout interrupt */
    TIMER2->CTL |= 0x01; /* enable Timer2A after initialization */
    NVIC->ISER[0] |= 0x00800000; /* enable IRQ23 (D23 of ISER[0]) */
}

void TIMER1A_Handler(void)
{
    volatile int readback;
    if (TIMER1->MIS & 0x1) /* Timer1A timeout flag */
    {
        GPIOF->DATA ^= 2; /* toggle red LED */
        TIMER1->ICR = 0x1; /* clear the Timer1A timeout flag */
        readback = TIMER1->ICR; /* a read to force clearing of interrupt flag */
    }
    else
    {   
        /* should not get here, but if we do */
        TIMER1->ICR = TIMER1->MIS; /* clear all flags */
        readback = TIMER1->ICR; /* a read to force clearing of interrupt flag */
    }
}
void TIMER2A_Handler(void)
{
    volatile int readback;
    if (TIMER2->MIS & 0x1) /* Timer2A timeout flag */
    {
        GPIOF->DATA ^= 8; /* toggle green LED */
        TIMER2->ICR = 0x1; /* clear the Timer2A timeout flag */
        readback = TIMER2->ICR; /* a read to force clearing of interrupt flag */
    }
    else
    { 
        /* should not get here, but if we do */
        TIMER2->ICR = TIMER2->MIS; /* clear all flags */
        readback = TIMER2->ICR; /* a read to force clearing of interrupt flag */
    }
}

