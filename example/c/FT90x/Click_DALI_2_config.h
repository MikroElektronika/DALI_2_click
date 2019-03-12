#include "Click_DALI_2_types.h"

#ifdef  ENABLE_SPI
const uint32_t _DALI2_SPI_CFG[ 3 ] = 
{ 
	_SPI_MASTER_CLK_RATIO_256,
	_SPI_CFG_POLARITY_IDLE_HIGH |
	_SPI_CFG_PHASE_CAPTURE_RISING | 
	_SPI_CFG_SS_AUTO_DISABLE | 
	_SPI_CFG_FIFO_DISABLE, 
	_SPI_SS_LINE_NONE 
};
#endif

#ifdef  ENABLE_I2C
const uint32_t _DALI2_I2C_CFG[ 2 ] =  
{
	_I2CM_SPEED_MODE_STANDARD, 
	_I2CM_SWAP_DISABLE
};
#endif

#ifdef ENABLE_UART
const uint32_t _DALI2_UART_CFG[ 1 ] = 
{
	9600
};
#endif
