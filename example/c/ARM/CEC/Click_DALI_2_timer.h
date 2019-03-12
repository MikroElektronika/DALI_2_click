/*

Use mikroE Timer Calculator to generate proper timer configuration
and timer ISR.

https://www.mikroe.com/timer-calculator

*/
#include "Click_DALI_2_types.h"

#define __DALI_2_TIMER__

static void dali2_confgTimer()
{
    // Configure Timer
}

static void Timer_interrupt()
{
    dali2_isr();
    // Reset Flag
}