/*

Use mikroE Timer Calculator to generate proper timer configuration
and timer ISR.

https://www.mikroe.com/timer-calculator

*/
#include "Click_DALI_2_types.h"

#define __DALI_2_TIMER__

static void dali2_configTimer()
{
    TIMER32_T32CONTROL1 &= 0xFFFFFFFE;
    TIMER32_T32CONTROL1 |= 0x02;
    TIMER32_T32CONTROL1 |= 0;
    TIMER32_T32CONTROL1 |= 0x20;
    TIMER32_T32CONTROL1 |= 0x40;
    TIMER32_T32LOAD1 = 0x0000BB80;
    NVIC_IntEnable(IVT_INT_T32_INT1);
//    IVT_INT_T32_INT1TIMER32_T32CONTROL1 |= 0x80;
    EnableInterrupts();
}

void Timer_interrupt() iv IVT_INT_T32_INT1
{
    dali2_isr();
    TIMER32_T32INTCLR1 = 1;
}