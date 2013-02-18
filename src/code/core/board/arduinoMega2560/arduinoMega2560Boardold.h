//----------------------------------------------------------------------------------------------------------------------
// Arion project autopilot
// Created by Carmelo J. Fern�ndez-Ag�era Tortosa (a.k.a. Technik)
// On December 13th, 2012
//----------------------------------------------------------------------------------------------------------------------
// Interface to deal with arduino mega 2560 board

#ifndef _ATMEGA2560_CORE_BOARD_ARDUINOMEGA2560_ARDUINOMEGA2560BOARD_H_
#define _ATMEGA2560_CORE_BOARD_ARDUINOMEGA2560_ARDUINOMEGA2560BOARD_H_

#include "../board.h"

namespace atmega2560
{
	class ArduinoMega2560Board : public Board
	{
	public:
		~ArduinoMega2560Board() {}; // Virtual destructor to ensure proper deletion of child classes

		// Digital pins
		void	digitalOn		(unsigned _pin);
		void	digitalOff		(unsigned _pin);
		void	digitalToggle	(unsigned _pin);
		bool	digitalRead		(unsigned _pin);

		// TODO: Analog pins
		// virtual unsigned analogRead(unsigned _pin) = 0;
	};
}	// namespace atmega2560

#endif // _ATMEGA_CORE_BOARD_ARDUINOMEGA2560_ARDUINOMEGA2560BOARD_H_
