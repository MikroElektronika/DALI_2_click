![MikroE](http://www.mikroe.com/img/designs/beta/logo_small.png)

---

# DALI_2 Click

- **CIC Prefix**  : DALI2
- **Author**      : MikroE Team
- **Verison**     : 1.0.0
- **Date**        : Feb 2018.

---

### Software Support

We provide a library for the DALI_2 Click on our [LibStock](https://libstock.mikroe.com/projects/view/2333/dali-2-click) 
page, as well as a demo application (example), developed using MikroElektronika 
[compilers](http://shop.mikroe.com/compilers). The demo can run on all the main 
MikroElektronika [development boards](http://shop.mikroe.com/development-boards).

**Library Description**

Library implements DALI master functionalities. 

Key functions :

- ``` void dali2_sendCmd(const uint8_t balAddress, const uint8_t cmd, const uint8_t cmdType, const uint8_t folType) ``` - Executes DALI command
- ``` void dali2_masterInit() ``` - Initializes master functionality
- ``` uint8_t dali2_masterStatus() ``` - Returns master status

**Examples Description**

The application is composed of three sections :

- System Initialization - Initializes GPIO pins for TX and RX
- Application Initialization - Initializes driver, initializes DALI master functionality and configures timer
- Application Task - (code snippet) - Application task is composed of three sequences, first sequence toggling
light twice with delay of one second. Second sequence decreases intensity of light by 8 steps with delay of 
half second. Third sequence increases intensity of light by 8 steps with delay of half second.


```.c
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
```

**Note** 

This implementation of DALI master requires timer with exact 104 uS interrupt time. The MCU used 
for example must be cappable to execute ```void dali2_isr()``` function in time less than 104 uS.
In theory it is usable on faster MCUs but before usage you should check does your MCU is cappable to 
acomplish dali2_isr function call for less than 104us.


The full application code, and ready to use projects can be found on our 
[LibStock](https://libstock.mikroe.com/projects/view/2333/dali-2-click) page.

---
---
