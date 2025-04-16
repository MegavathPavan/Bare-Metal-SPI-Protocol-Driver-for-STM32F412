#include "spi_driver.h"



void GPIO_config(void){
	RCC->AHB1ENR |= (1 << 4); // Enable GPIOE clock
	RCC->APB2ENR |= (1 << 13); // Enable SPI4 clock
	GPIOE->MODER =0;
	GPIOE->MODER|=(2<<4);
	GPIOE->MODER|=(2<<8);
	GPIOE->MODER|=(2<<10);
	GPIOE->MODER|=(2<<12);
	GPIOE->AFR[0]=0;	// initially reset and 0101:AF5 (SPI4)
	GPIOE->AFR[0] |= (5<<8); // SPI4_SCK at PE2
	GPIOE->AFR[0] |= (5<<16); // SPI4_CS at PE4
	GPIOE->AFR[0] |= (5<<20); // slave output SPI4_MISO at PE5
	GPIOE->AFR[0] |= (5<<24); // slave input SPI4_MOSI at PE6
}


void SPI_config(void){
	//SSM and SSI
	// MSTR for multi master
	SPI4->CR1 = 0;
	SPI4->CR1 |= 0; //clock phase
	SPI4->CR1 |= (0<<1); //select clock polarity
	SPI4->CR1 |= (0<<7); //LSBFIRST
	SPI4->CR1 |= (0<<8); // Internal slave select
	SPI4->CR1 |= (0<<9); //desable software slave select
	SPI4->CR1 |= (0<<11); // 0 for 8-bit frame format and 1 for 16-bit frame  format
	SPI4->CR1 |= (1<<6); // Enable SPI4
	
}

uint8_t transfer_nbit_SPI(void){

   while(!(SPI4->SR & 0x1)){} // check if buffer is full or not
		 return SPI4->DR; // read recieived data and transfer it
}

