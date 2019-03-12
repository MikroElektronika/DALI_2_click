/*

Use mikroE Timer Calculator to generate proper timer configuration
and timer ISR.

https://www.mikroe.com/timer-calculator

*/
#include "Click_DALI_2_types.h"

#define __DALI_2_TIMER__

static void dali2_confgTimer()
{
    SIM_SCGC6 |= (1 << PIT);
    NVIC_IntEnable(IVT_INT_PIT0);
    PIT_MCR = 0x00;
    PIT_LDVAL0 = 6239;
    PIT_TCTRL0 |= 2;
    PIT_TCTRL0 |= 1;
}

void Timer_interrupt() iv IVT_INT_PIT0
{
    dali2_isr();
    PIT_TFLG0.TIF = 1;
}