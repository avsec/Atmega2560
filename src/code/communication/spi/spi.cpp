//----------------------------------------------------------------------------------------------------------------------
// Atmega2560 project
// Created by Juan José Blasco Burguillos
// On February 13th, 2013
//----------------------------------------------------------------------------------------------------------------------
// Interface to deal with arduino mega 2560 board

#include <avr/io.h>
#include <communication/spi/spi.h>

//Pin Names
#define SS		PB0
#define SCK		PB1
#define MOSI	PB2
#define MISO	PB3

namespace atmega2560
{
	void MasterInit()			//SPI Master initialization
	{
		SPCR = 1<<MSTR | 1<<SPE;				// Set device as Master
												// Enable SPI

		//TODO: SPCR = 1<<DORD;		// DORD=1, LSB will be transmitted first
									// DORD=0, MSB will be transmitted first
	
		DDRB	 = 1<<MOSI | 1<<SS | 1<<SCK;	// set MOSI, SS and SCK as output in order to make the device as Master

		PORTB	|= 1<<SS;						// set SS high in order to make the device as Master

		//TODO: SCK frequency?
	}

	void SlaveInit() // Turn On Slave SPI mode
	{

	 DDRB = 1<<MOSI;	// Configure MOSI Pin as an output in order to make the device as Slave.
						// MISO, SS, and SCK Pins as input.

	 SPCR |= (1<<SPE);
	}

	void TX(unsigned char byte)
	{
		SPDR = byte;					// Load byte to Data register
		while(!(SPSR & (1<<SPIF))); 	// Wait for transmission complete 
	}

	char RX()
	{
		while(!(SPSR & (1<<SPIF))); 	// Wait for transmission complete 
		return SPDR;
	}

}//namespace atmega2560