//----------------------------------------------------------------------------------------------------------------------
// Arion project autopilot
// Created by Carmelo J. Fernández-Agüera Tortosa (a.k.a. Technik)
// On December 13th, 2012
//----------------------------------------------------------------------------------------------------------------------
// Pins mapped by Álvaro Fernandez Cobo and Juan José Blasco Burguillos
// on February 11th, 2013
//----------------------------------------------------------------------------------------------------------------------
// Interface to deal with arduino mega 2560 board

#include <stdint.h>
#include <avr/io.h>

#include "arduinoMega2560Board.h"


namespace atmega2560
{
	//----------------------------------------------------------------------------------------------------------------------
	//Static data definition 
	//----------------------------------------------------------------------------------------------------------------------

	//sBitMask table contains the bit position of the register that corresponds to the desired Digital Pin in the board
	uint8_t ArduinoMega2560Board::sBitMask[] = 
	{
		/*0 =*/	PE0,	/*1 =*/	PE1,	/*2 =*/	PE4,	/*3 =*/	PE5,	/*4 =*/	PG5, 	
		/*5 =*/	PE3,	/*6 =*/	PH3,	/*7 =*/	PH4,	/*8 =*/	PH5,	/*9 =*/	PH6,
		/*10=*/ PB4,	/*11=*/	PB5,	/*12=*/	PB6,	/*13=*/	PB7,	/*14=*/	PJ1, 	
		/*15=*/	PJ0,	/*16=*/	PH1,	/*17=*/	PH0,	/*18=*/	PD3,	/*19=*/	PD2,
		/*20=*/	PD1,	/*21=*/	PD0,	/*22=*/	PA0,	/*23=*/	PA1,	/*24=*/	PA2, 	
		/*25=*/	PA3,	/*26=*/	PA4,	/*27=*/	PA5,	/*28=*/	PA6,	/*29=*/	PA7,
		/*30=*/	PC7,	/*31=*/	PC6,	/*32=*/	PC5,	/*33=*/	PC4,	/*34=*/	PC3, 	
		/*35=*/	PC2,	/*36=*/	PC1,	/*37=*/	PC0,	/*38=*/	PD7,	/*39=*/	PG2,
		/*40=*/	PG1,	/*41=*/	PG0,	/*42=*/	PL7,	/*43=*/	PL6,	/*44=*/	PL5, 	
		/*45=*/	PL4,	/*46=*/	PL3,	/*47=*/	PL2,	/*48=*/	PL1,	/*49=*/	PL0,
		/*50=*/	PB3,	/*51=*/	PB2,	/*52=*/	PB1,	/*53=*/	PB0
	};

	//sPORT table contains PORT register address that corresponds to the desired Digital Pin in the board
	volatile uint8_t *ArduinoMega2560Board::sPORT[] = 
	{
		/*0 =*/	&PORTE,	/*1 =*/	&PORTE,	/*2 =*/	&PORTE,	/*3 =*/	&PORTE,	/*4 =*/	&PORTG, 	
		/*5 =*/	&PORTE,	/*6 =*/	&PORTH,	/*7 =*/	&PORTH,	/*8 =*/	&PORTH,	/*9 =*/	&PORTH,
		/*10=*/	&PORTB,	/*11=*/	&PORTB,	/*12=*/	&PORTB,	/*13=*/	&PORTB,	/*14=*/	&PORTJ, 	
		/*15=*/	&PORTJ,	/*16=*/	&PORTH,	/*17=*/	&PORTH,	/*18=*/	&PORTD,	/*19=*/	&PORTD,
		/*20=*/	&PORTD,	/*21=*/	&PORTD,	/*22=*/	&PORTA,	/*23=*/	&PORTA,	/*24=*/	&PORTA, 	
		/*25=*/	&PORTA,	/*26=*/	&PORTA,	/*27=*/	&PORTA,	/*28=*/	&PORTA,	/*29=*/	&PORTA,
		/*30=*/	&PORTC,	/*31=*/	&PORTC,	/*32=*/	&PORTC,	/*33=*/	&PORTC,	/*34=*/	&PORTC, 	
		/*35=*/	&PORTC,	/*36=*/	&PORTC,	/*37=*/	&PORTC,	/*38=*/	&PORTD,	/*39=*/	&PORTG,
		/*40=*/	&PORTG,	/*41=*/	&PORTG,	/*42=*/	&PORTL,	/*43=*/	&PORTL,	/*44=*/	&PORTL, 	
		/*45=*/	&PORTL,	/*46=*/	&PORTL,	/*47=*/	&PORTL,	/*48=*/	&PORTL,	/*49=*/	&PORTL,
		/*50=*/	&PORTB,	/*51=*/	&PORTB,	/*52=*/	&PORTB,	/*53=*/	&PORTB
	};

	//sDDR table contains DDR register address that corresponds to the desired Digital Pin in the board
	volatile uint8_t *ArduinoMega2560Board::sDDR[] = 
	{
		/*0 =*/	&DDRE,	/*1 =*/	&DDRE,	/*2 =*/	&DDRE,	/*3 =*/	&DDRE,	/*4 =*/	&DDRG, 	
		/*5 =*/	&DDRE,	/*6 =*/	&DDRH,	/*7 =*/	&DDRH,	/*8 =*/	&DDRH,	/*9 =*/	&DDRH,
		/*10=*/	&DDRB,	/*11=*/	&DDRB,	/*12=*/	&DDRB,	/*13=*/	&DDRB,	/*14=*/	&DDRJ, 	
		/*15=*/	&DDRJ,	/*16=*/	&DDRH,	/*17=*/	&DDRH,	/*18=*/	&DDRD,	/*19=*/	&DDRD,
		/*20=*/	&DDRD,	/*21=*/	&DDRD,	/*22=*/	&DDRA,	/*23=*/	&DDRA,	/*24=*/	&DDRA, 	
		/*25=*/	&DDRA,	/*26=*/	&DDRA,	/*27=*/	&DDRA,	/*28=*/	&DDRA,	/*29=*/	&DDRA,
		/*30=*/	&DDRC,	/*31=*/	&DDRC,	/*32=*/	&DDRC,	/*33=*/	&DDRC,	/*34=*/	&DDRC, 	
		/*35=*/	&DDRC,	/*36=*/	&DDRC,	/*37=*/	&DDRC,	/*38=*/	&DDRD,	/*39=*/	&DDRG,
		/*40=*/	&DDRG,	/*41=*/	&DDRG,	/*42=*/	&DDRL,	/*43=*/	&DDRL,	/*44=*/	&DDRL, 	
		/*45=*/	&DDRL,	/*46=*/	&DDRL,	/*47=*/	&DDRL,	/*48=*/	&DDRL,	/*49=*/	&DDRL,
		/*50=*/	&DDRB,	/*51=*/	&DDRB,	/*52=*/	&DDRB,	/*53=*/	&DDRB
	};

	//sPIN table contains the PIN register address that corresponds to the desired Digital Pin in the board
	volatile uint8_t *ArduinoMega2560Board::sPIN[] = 
	{
		/*0 =*/	&PINE,	/*1 =*/	&PINE,	/*2 =*/	&PINE,	/*3 =*/	&PINE,	/*4 =*/	&PING, 	
		/*5 =*/	&PINE,	/*6 =*/	&PINH,	/*7 =*/	&PINH,	/*8 =*/	&PINH,	/*9 =*/	&PINH,
		/*10=*/	&PINB,	/*11=*/	&PINB,	/*12=*/	&PINB,	/*13=*/	&PINB,	/*14=*/	&PINJ, 	
		/*15=*/	&PINJ,	/*16=*/	&PINH,	/*17=*/	&PINH,	/*18=*/	&PIND,	/*19=*/	&PIND,
		/*20=*/	&PIND,	/*21=*/	&PIND,	/*22=*/	&PINA,	/*23=*/	&PINA,	/*24=*/	&PINA, 	
		/*25=*/	&PINA,	/*26=*/	&PINA,	/*27=*/	&PINA,	/*28=*/	&PINA,	/*29=*/	&PINA,
		/*30=*/	&PINC,	/*31=*/	&PINC,	/*32=*/	&PINC,	/*33=*/	&PINC,	/*34=*/	&PINC, 	
		/*35=*/	&PINC,	/*36=*/	&PINC,	/*37=*/	&PINC,	/*38=*/	&PIND,	/*39=*/	&PING,
		/*40=*/	&PING,	/*41=*/	&PING,	/*42=*/	&PINL,	/*43=*/	&PINL,	/*44=*/	&PINL, 	
		/*45=*/	&PINL,	/*46=*/	&PINL,	/*47=*/	&PINL,	/*48=*/	&PINL,	/*49=*/	&PINL,
		/*50=*/	&PINB,	/*51=*/	&PINB,	/*52=*/	&PINB,	/*53=*/	&PINB
	};


	//------------------------------------------------------------------------------------------------------------------
	void ArduinoMega2560Board::digitalOn(unsigned _pin)
	{
		*sDDR[_pin]		|=	1<<sBitMask[_pin];								//Set pin as output
		*sPORT[_pin]	|=	1<<sBitMask[_pin];								//Set pin as high
	}

	void ArduinoMega2560Board::digitalOff(unsigned _pin)
	{
		*sDDR[_pin]		|=	1<<sBitMask[_pin];								//Set pin as output
		*sPORT[_pin]	&=	~(1<<sBitMask[_pin]);							//Set pin as low
	}

	//------------------------------------------------------------------------------------------------------------------
	void ArduinoMega2560Board::digitalToggle(unsigned _pin)
	{
		*sDDR[_pin]		|=	1<<sBitMask[_pin];								//Set pin as output
		*sPORT[_pin]	^=	1<<sBitMask[_pin];								//Toggle the state of the pin
	}

	//------------------------------------------------------------------------------------------------------------------
	bool ArduinoMega2560Board::digitalRead(unsigned _pin)
	{
		*sDDR[_pin]	&=	~(1<<sBitMask[_pin]);							//Set pin as input
		return (*sPIN[_pin] & 1<<sBitMask[_pin]) && (1<<sBitMask[_pin]);	//Return the bit of the pin satate
		
	}
} //namespace arion

