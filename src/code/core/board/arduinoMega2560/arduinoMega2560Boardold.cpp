//----------------------------------------------------------------------------------------------------------------------
// Arion project autopilot
// Created by Carmelo J. Fernández-Agüera Tortosa (a.k.a. Technik)
// On December 13th, 2012
//----------------------------------------------------------------------------------------------------------------------
// Interface to deal with arduino mega 2560 board

// Atmega2560 project
// Pins mapped by Álvaro Fernandez Cobo and Juan José Blasco Burguillos
// on February 11th, 2013

#include <stdint.h>
#include <avr/io.h>

#include "arduinoMega2560Board.h"
#ifdef ATMEGA2560

namespace atmega2560
{
	//------------------------------------------------------------------------------------------------------------------
	void ArduinoMega2560Board::digitalOn(unsigned _pin)
	{
		if(_pin < 16)
		{
			if(_pin < 6)
			{
				if(_pin < 4)
				{
					if(_pin <2) //0-1, PE0-PE1
					{
						uint8_t offset =  _pin;
						DDRE |= 1<<offset;
						PORTE |= 1<<offset;

					}
					else //2-3, PE4-PE5
					{
						uint8_t offset =  _pin+2;				
						DDRE |= 1<<offset;
						PORTE |= 1<<offset;
					}
				}
				else
				{
					if(_pin < 5) //4, PG5
					{
						DDRG |= 1<<5;
						PORTG |= 1<<5;
					}
					else //5, PE3
					{
						DDRE |= 1<<3;
						PORTE |= 1<<3;
					}
				}
			}
			else
			{
				if(_pin < 10) // 6-9, PH3-PH6
				{
					uint8_t offset =  _pin-3;	
					DDRH |= 1<<offset;
					PORTH |= 1<<offset;
				}
				else
				{
					if(_pin < 14) // 10 - 13, PB4 - PB7
					{
						uint8_t offset = _pin - 6;
						DDRB |= 1<<offset;
						PORTB |= 1<<offset;
					}
					else // 14 - 15, PJ1-PJ0
					{
						uint8_t offset = -1*(_pin-15);	
						DDRJ |= 1<<offset;
						PORTJ |= 1<<offset;
					}
				}
			}
		}
		else
		{
			if(_pin < 38)
			{
				if(_pin < 22)
				{
					if(_pin < 18) // 16 - 17, PH1 - PH0
					{
						uint8_t offset = 17 - _pin;
						DDRH |= 1<<offset;
						PORTH |= 1<<offset;
					}
					else // 18 - 21, PD3 - PD0
					{
						uint8_t offset = 21 - _pin;
						DDRD |= 1<<offset;
						PORTD |= 1<<offset;
					}
				}
				else
				{
					if(_pin < 30) // 22 - 29, PA0 - PA7
					{
						uint8_t offset = _pin - 22;
						DDRA |= 1<<offset;
						PORTA |= 1<<offset;
					}
					else // 30 - 37, PC7 - PC0
					{
						uint8_t offset = 37 - _pin;
						DDRC |= 1<<offset;
						PORTC |= 1<<offset;
					}
				}
			}
			else
			{
				if(_pin < 42)
				{
					if(_pin < 39) // 38, PD7
					{
						DDRD |= 1<<7;
						PORTD |= 1<<7;
					}
					else // 39 - 41, PG2 - PG0
					{	
						uint8_t offset = 41 - _pin;
						DDRG |= 1<<offset;
						PORTG |= 1<<offset;
					}
				}
				else
				{
					if(_pin < 50) // 42 - 49, PL7 - PL0
					{
						uint8_t offset = 49 - _pin;
						DDRL |= 1<<offset;
						PORTL |= 1<<offset;
					}
					else // 50 - 53, PB3 - PB0
					{
						uint8_t offset = 53 - _pin;
						DDRB |= 1<<offset;
						PORTB |= 1<<offset;
					}
				}
			}
		}

	}
					
	//------------------------------------------------------------------------------------------------------------------
	void ArduinoMega2560Board::digitalOff(unsigned _pin)
	{
		if(_pin < 16)
		{
			if(_pin < 6)
			{
				if(_pin < 4)
				{
					if(_pin <2) //0-1, PE0-PE1
					{
						uint8_t offset =  _pin;
						DDRE |= 1<<offset;
						PORTE &= ~(1<<offset);

					}
					else //2-3, PE4-PE5
					{
						uint8_t offset =  _pin+2;				
						DDRE |= 1<<offset;
						PORTE &= ~(1<<offset);

					}
				}
				else
				{
					if(_pin < 5) //4, PG5
					{
						DDRG |= 1<<5;
						PORTG &= ~(1<<5);
					}
					else //5, PE3
					{
						DDRE |= 1<<3;
						PORTE &= ~(1<<3);
					}
				}
			}
			else
			{
				if(_pin < 10) // 6-9, PH3-PH6
				{
					uint8_t offset =  _pin-3;	
					DDRH |= 1<<offset;
					PORTH &= ~(1<<offset);
				}
				else
				{
					if(_pin < 14) // 10 - 13, PB4 - PB7
					{
						uint8_t offset = _pin - 6;
						DDRB |= 1<<offset;
						PORTB &= ~(1<<offset);
					}
					else // 14 - 15, PJ1-PJ0
					{
						uint8_t offset = -1*(_pin-15);		
						DDRJ |= 1<<offset;
						PORTJ &= ~(1<<offset);
					}
				}
			}
		}
		else
		{
			if(_pin < 38)
			{
				if(_pin < 22)
				{
					if(_pin < 18) // 16 - 17, PH1 - PH0
					{
						uint8_t offset = 17 - _pin;
						DDRH |= 1<<offset;
						PORTH &= ~(1<<offset);
					}
					else // 18 - 21, PD3 - PD0
					{
						uint8_t offset = 21 - _pin;
						DDRD |= 1<<offset;
						PORTD &= ~(1<<offset);
					}
				}
				else
				{
					if(_pin < 30) // 22 - 29, PA0 - PA7
					{
						uint8_t offset = _pin - 22;
						DDRA |= 1<<offset;
						PORTA &= ~(1<<offset);
					}
					else // 30 - 37, PC7 - PC0
					{
						uint8_t offset = 37 - _pin;
						DDRC |= 1<<offset;
						PORTC &= ~(1<<offset);
					}
				}
			}
			else
			{
				if(_pin < 42)
				{
					if(_pin < 39) // 38, PD7
					{
						DDRD |= 1<<7;
						PORTD &= ~(1<<7);
					}
					else // 39 - 41, PG2 - PG0
					{	
						uint8_t offset = 41 - _pin;
						DDRG |= 1<<offset;
						PORTG &= ~(1<<offset);
					}
				}
				else
				{
					if(_pin < 50) // 42 - 49, PL7 - PL0
					{
						uint8_t offset = 49 - _pin;
						DDRL |= 1<<offset;
						PORTL &= ~(1<<offset);
					}
					else // 50 - 53, PB3 - PB0
					{
						uint8_t offset = 53 - _pin;
						DDRB |= 1<<offset;
						PORTB &= ~(1<<offset);
					}
				}
			}
		}

	}

	//------------------------------------------------------------------------------------------------------------------
	void ArduinoMega2560Board::digitalToggle(unsigned _pin)
	{
		if(_pin < 16)
		{
			if(_pin < 6)
			{
				if(_pin < 4)
				{
					if(_pin <2) //0-1, PE0-PE1
					{
						uint8_t offset =  _pin;
						DDRE |= 1<<offset;
						PORTE ^= 1<<offset;

					}
					else //2-3, PE4-PE5
					{
						uint8_t offset =  _pin+2;				
						DDRE |= 1<<offset;
						PORTE ^= 1<<offset;
					}
				}
				else
				{
					if(_pin < 5) //4, PG5
					{
						DDRG |= 1<<5;
						PORTG ^= 1<<5;
					}
					else //5, PE3
					{
						DDRE |= 1<<3;
						PORTE ^= 1<<3;
					}
				}
			}
			else
			{
				if(_pin < 10) // 6-9, PH3-PH6
				{
					uint8_t offset =  _pin-3;	
					DDRH |= 1<<offset;
					PORTH ^= 1<<offset;
				}
				else
				{
					if(_pin < 14) // 10 - 13, PB4 - PB7
					{
						uint8_t offset = _pin - 6;
						DDRB |= 1<<offset;
						PORTB ^= 1<<offset;
					}
					else // 14 - 15, PJ1-PJ0
					{
						uint8_t offset = -1*(_pin-15);	
						DDRJ |= 1<<offset;
						PORTJ ^= 1<<offset;
					}
				}
			}
		}
		else
		{
			if(_pin < 38)
			{
				if(_pin < 22)
				{
					if(_pin < 18) // 16 - 17, PH1 - PH0
					{
						uint8_t offset = 17 - _pin;
						DDRH |= 1<<offset;
						PORTH ^= 1<<offset;
					}
					else // 18 - 21, PD3 - PD0
					{
						uint8_t offset = 21 - _pin;
						DDRD |= 1<<offset;
						PORTD ^= 1<<offset;
					}
				}
				else
				{
					if(_pin < 30) // 22 - 29, PA0 - PA7
					{
						uint8_t offset = _pin - 22;
						DDRA |= 1<<offset;
						PORTA ^= 1<<offset;
					}
					else // 30 - 37, PC7 - PC0
					{
						uint8_t offset = 37 - _pin;
						DDRC |= 1<<offset;
						PORTC ^= 1<<offset;
					}
				}
			}
			else
			{
				if(_pin < 42)
				{
					if(_pin < 39) // 38, PD7
					{
						DDRD |= 1<<7;
						PORTD ^= 1<<7;
					}
					else // 39 - 41, PG2 - PG0
					{	
						uint8_t offset = 41 - _pin;
						DDRG |= 1<<offset;
						PORTG ^= 1<<offset;
					}
				}
				else
				{
					if(_pin < 50) // 42 - 49, PL7 - PL0
					{
						uint8_t offset = 49 - _pin;
						DDRL |= 1<<offset;
						PORTL ^= 1<<offset;
					}
					else // 50 - 53, PB3 - PB0
					{
						uint8_t offset = 53 - _pin;
						DDRB |= 1<<offset;
						PORTB ^= 1<<offset;
					}
				}
			}
		}
	}

	//------------------------------------------------------------------------------------------------------------------
	bool ArduinoMega2560Board::digitalRead(unsigned /*_pin*/)
	{
		return false;
	}
}	// namespace atmega2560

#endif // ATMEGA2560