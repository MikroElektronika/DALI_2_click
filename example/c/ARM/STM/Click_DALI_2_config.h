#include "Click_DALI_2_types.h"

#ifdef  ENABLE_SPI
const uint32_t _DALI2_SPI_CFG[ 2 ] = 
{ 
	_SPI_FPCLK_DIV256, 
	_SPI_FIRST_CLK_EDGE_TRANSITION | 
	_SPI_CLK_IDLE_LOW | 
	_SPI_MASTER | 
	_SPI_MSB_FIRST |
	_SPI_8_BIT | 
	_SPI_SSM_ENABLE | 
	_SPI_SS_DISABLE | 
	_SPI_SSI_1
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
