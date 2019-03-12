/*

Use mikroE Timer Calculator to generate proper timer configuration
and timer ISR.

https://www.mikroe.com/timer-calculator

*/
#include "Click_DALI_2_types.h"

#define __DALI_2_TIMER__

static void dali2_configTimer()
{
    T1CON      = 0x8000;
    T1IP0_bit  = 1;
    T1IP1_bit  = 1;
    T1IP2_bit  = 1;
    T1IF_bit   = 0;
    T1IE_bit   = 1;
    PR1        = 8320;
    TMR1       = 0;
    EnableInterrupts();
}

void Timer_interrupt() iv IVT_TIMER_1 ilevel 7 ics ICS_SRS
{
    T1IF_bit     = 0;
    dali2_isr();
}