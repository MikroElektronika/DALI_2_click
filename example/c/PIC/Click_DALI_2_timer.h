/*

Use mikroE Timer Calculator to generate proper timer configuration
and timer ISR.

https://www.mikroe.com/timer-calculator

*/
#include "Click_DALI_2_types.h"

#define __DALI_2_TIMER__

static void dali2_configTimer()
{
    T0CON  = 0xC2;
    TMR0L  = 0x30;
    GIE_bit        = 1;
    TMR0IE_bit     = 1;
}

void Interrupt()
{
    if (TMR0IF_bit)
    { 
        TMR0IF_bit = 0;
        TMR0L      = 0x30;
        dali2_isr();
    }
}