//----------------------------------------------------------------------------------------------------------------------
// Arion project autopilot
// Created by Carmelo J. Fernández-Agüera Tortosa (a.k.a. Technik)
// On December 13th, 2012
//----------------------------------------------------------------------------------------------------------------------
// Interface to deal with arduino mega 2560 board

#ifndef _ARION_CORE_BOARD_ARDUINOMEGA2560_ARDUINOMEGA2560BOARD_H_
#define _ARION_CORE_BOARD_ARDUINOMEGA2560_ARDUINOMEGA2560BOARD_H_

#include "../board.h"
#include <stdint.h>

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

	private:

		static				uint8_t		sBitMask[];
		static	volatile	uint8_t		*sPORT[]; 
		static	volatile	uint8_t		*sDDR[];
		static	volatile	uint8_t		*sPIN[];
	};
}	// namespace arion

#endif // _ARION_CORE_BOARD_ARDUINOMEGA2560_ARDUINOMEGA2560BOARD_H_
