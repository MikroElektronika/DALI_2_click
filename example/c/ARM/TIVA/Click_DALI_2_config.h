#include "Click_DALI_2_types.h"

#ifdef  ENABLE_SPI
const uint32_t _DALI2_SPI_CFG[ 3 ] = 
{ 
	1000000, 
	_SPI_MASTER, 
	_SPI_8_BIT | 
	_SPI_CLK_IDLE_HIGH |
	_SPI_SECOND_CLK_EDGE_TRANSITION 
};
#endif

#ifdef  ENABLE_I2C
const uint32_t _DALI2_I2C_CFG[ 1 ] = 
{ 
	_I2C_BITRATE_STANDARD_MODE 
};
#endif

#ifdef ENABLE_UART
const uint32_t _DALI2_UART_CFG[ 6 ] = 
{
	9600, 
	0,                        // CPU FQ Parameter will be replaced during init call
	_UART_8_BIT_DATA, 
	_UART_NOPARITY,
    _UART_ONE_STOPBIT, 
    _UART_HIGH_SPEED
};
#endif
