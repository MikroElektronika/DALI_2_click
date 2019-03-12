#include "Click_DALI_2_types.h"

#ifdef  ENABLE_SPI
const uint32_t _DALI2_SPI_CFG[ 2 ] = 
{ 
	1000000,
	_SPI_CFG_CLK_PHASE_CAPT_LEADING | 
	_SPI_CFG_CLK_IDLE_LOW |
	_SPI_CFG_MASTER | 
	_SPI_CFG_MSB_FIRST |
	_SPI_CFG_FRAME_SIZE_8BITS | 
	_SPI_CFG_SELECT_CTAR0
};
#endif

#ifdef  ENABLE_I2C
const uint32_t _DALI2_I2C_CFG[ 1 ] = 
{
	100000
};
#endif

#ifdef ENABLE_UART
const uint32_t _DALI2_UART_CFG [ 4 ] = 
{
	9600,  
	_UART_8_BIT_DATA, 
	_UART_NOPARITY, 
	_UART_ONE_STOPBIT
};
#endif
