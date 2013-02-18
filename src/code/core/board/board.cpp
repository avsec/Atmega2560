//----------------------------------------------------------------------------------------------------------------------
// Arion project autopilot
// Created by Carmelo J. Fernández-Agüera Tortosa (a.k.a. Technik)
// On December 23rd, 2012
//----------------------------------------------------------------------------------------------------------------------
// Interface to deal with different boards

#include "board.h"

#include "arduinoMega2560/arduinoMega2560Board.h"

namespace atmega2560
{
	// Static data definition
	Board* Board::sBoard = nullptr;

	//-----------------------------------------------------------------------------------------
	void Board::init()
	{
#ifdef ATMEGA2560
		sBoard = new ArduinoMega2560Board ();
#elif defined(ATMEGA328P)
		sBoard = new ArduinoUnoBoard();
#endif // ATMEGA328P
	}

	//-----------------------------------------------------------------------------------------
	void Board::end()
	{
		delete sBoard;
		sBoard = 0;
	}

}	// namespace atmega2560