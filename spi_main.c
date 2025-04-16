#include "stm32f4xx.h"
#include "uart.h"
#include "spi_driver.h"

int main(){
	
	UART3Config();
	UART3_SendString("hello----begins from here");
	UART3_SendString("\n\r");
	
	// configure the GPIO ports and pins
	GPIO_config();
	// configure SPI
	SPI_config();

	uint8_t data_byte;
	
	char data[100];	//data buffer
	
	// start
	while(1){
	
	data_byte = transfer_nbit_SPI();
	
	sprintf(data, "%c", data_byte);
	UART3_SendString(data);
	}
}
