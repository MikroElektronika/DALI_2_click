#include "Click_DALI_2_types.h"

#ifdef  ENABLE_SPI
const uint32_t _DALI2_SPI_CFG[ 7 ] = 
{ 
	_SPI_MASTER, 
	64, 
	_SPI_CLOCKSOURCE_SMCLK, 
	_SPI_MSB_FIRST, 
	_SPI_PHASE_DATA_CHANGE_FIRST_CAPTURE_NEXT, 
	_SPI_CLK_IDLE_HIGH, 
	_SPI_3PIN 
};
#endif

#ifdef  ENABLE_I2C
const uint32_t _DALI2_I2C_CFG[ 1 ] = 
{
	100000
};
#endif

#ifdef ENABLE_UART
const uint32_t _DALI2_UART_CFG[ 1 ] = 
{
	9600
};
#endif
