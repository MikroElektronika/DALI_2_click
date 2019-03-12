/*
Example for DALI_2 Click

    Date          : Feb 2018.
    Author        : MikroE Team

Test configuration MSP :
    
    MCU              : MSP432
    Dev. Board       : Clicker 2 for MSP432
    ARM Compiler ver : v6.0.0.0

---

Description :

The application is composed of three sections :

- System Initialization - Initializes GPIO pins for TX and RX
- Application Initialization - Initializes driver, initializes DALI master functionality and configures timer
- Application Task - (code snippet) - Application task is composed of three sequences, first sequence toggling
light twice with delay of one second. Second sequence decreases intensity of light by 8 steps with delay of 
half second. Third sequence increases intensity of light by 8 steps with delay of half second.

**Note** This implementation of DALI master requires timer with exact 104 uS interrupt time.

*/

#include "Click_DALI_2_types.h"
#include "Click_DALI_2_config.h"
#include "Click_DALI_2_timer.h"

uint8_t current_state;

void systemInit()
{
    mikrobus_gpioInit( _MIKROBUS1, _MIKROBUS_INT_PIN, _GPIO_OUTPUT );
    mikrobus_gpioInit( _MIKROBUS1, _MIKROBUS_RST_PIN, _GPIO_OUTPUT );
}

void applicationInit()
{
    dali2_gpioDriverInit( (T_DALI2_P)&_MIKROBUS1_GPIO );
    dali2_masterInit();
    dali2_configTimer();
}

void applicationTask()
{
    uint8_t counter;
    
    for (counter = 0; counter < 2; counter++)
    {
        dali2_sendCmd(_DALI2_ADDRESS01, _DALI2_OFF, _DALI2_BROADCAST_CMD, _DALI2_FOLLOWING_COMMAND);
        Delay_ms( 1000 );
        dali2_sendCmd(_DALI2_ADDRESS01, _DALI2_RECALL_MAX_LEVEL, _DALI2_BROADCAST_CMD, _DALI2_FOLLOWING_COMMAND);
        Delay_ms( 1000 );
    }
    
    for (counter = 0; counter < 8; counter++)
    {
        dali2_sendCmd(_DALI2_ADDRESS01, _DALI2_DOWN, _DALI2_BROADCAST_CMD, _DALI2_FOLLOWING_COMMAND);
        Delay_ms( 500 );
    }
    
    for (counter = 0; counter < 8; counter++)
    {
        dali2_sendCmd(_DALI2_ADDRESS01, _DALI2_UP, _DALI2_BROADCAST_CMD, _DALI2_FOLLOWING_COMMAND);
        Delay_ms( 500 );
    }
    
    current_state = dali2_masterStatus();
}

void main()
{
    systemInit();
    applicationInit();

    while (1)
    {
        applicationTask();
    }
}

