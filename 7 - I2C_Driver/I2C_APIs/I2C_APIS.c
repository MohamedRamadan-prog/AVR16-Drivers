/*
 * I2C_APIs.c
 *
 * Created: 25/09/2017 11:53:52 م
 * Author : SHIKO
 */ 

#include <avr/io.h>
#include "I2C_Drive.h"

int main(void)
{
    /* Replace with your application code */
    while (1) 
    {
    }
}

void I2C_Init ()
{
	/* calculate  Bit Rate */
	TWBR |= 1<<1 ;
    TWBR |= 1<<5 ;
	TWBR |= 1<<6 ;	
	TWCR |= 1 <<TWEN ; // Enable I2C
	TWSR = 0x00 ; 
}

void I2c_Start ()
{
	TWCR |=1<<7 ; // interrupt flag 
	TWCR |=1<<6 ;  // Enable 
	TWCR |=1<<5 ; // Check ang Start Generation 
	while (!(TWCR & (1<<7))) ; // Wait interrupt Flag
}

void I2C_Write (uint8_t Data )
{
	TWDR |= Data ;  // Write Data 
	TWCR |= 1<<7 ; 
	TWCR |= 1<<6 ;
	while (!(TWCR & (1<<7))) ;
}

uint8_t I2C_Read ()
{
	TWCR |=1<<6 ;
	TWCR |=1<<5 ;
	while (!(TWCR & (1<<7))) ;
	return TWDR ; // Return Read Data
}