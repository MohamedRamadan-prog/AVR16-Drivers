/*
 * SPI_Drive.c
 *
 * Created: 25/09/2017 10:39:49 م
 * Author : SHIKO
 */ 

#include <avr/io.h>
#include "SPI_Cfg.h"

int main(void)
{
    /* Replace with your application code */
    while (1) 
    {
    }
}

void MasterMode_SPI_Inti ()
{
	DDRB|= 1<<7; // Clock Out
    DDRB|= 1<<5; // MOSI Out
	DDRB|= 1<<4; // SS Out
	
	SPCR |= 1 < 6 ;  // Enable s pi 
	SPCR |= 1 < 5 ;  // LSF Transfer 
	SPCR |= 1 < 4 ;  // Master Mode 
	SPCR |= 1 < 1 ; // fosc/128
	SPCR |= 1 < 0 ; // fosc/128 
	
	SPSR = 0x00 ;
}
void SlaveMode_SPI_Inti ()
{
	DDRB &= ~(1<<7); // Clock input
    DDRB |= 1<<6 ;   // MISO Out
	DDRB &= ~(1<<5); // MOSI Input 
	DDRB &= ~(1<<4); // SS input
	
	SPCR |= 1 < 6 ;  // Enable s pi
	SPCR |= 1 < 5 ;  // LSF Transfer
	SPCR &=~ (1 < 4 ) ;  // Slave Mode
	SPCR |= 1 < 1 ; // fosc/128
	SPCR |= 1 < 0 ; // fosc/128
	
	SPSR = 0x00 ;
}

void SPI_Send (uint8_t Data)
{
	SPDR = Data ; 
	while ( (SPSR & 1<<7)==0 ) ; //Wait Until Flag set 
}


uint8_t SPI_Received ()
{
	while ( (SPSR & 1<<7) ==0  ) ;// Wait Until Flag set
	return SPDR ; 
}