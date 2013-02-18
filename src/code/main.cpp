//----------------------------------------------------------------------------------------------------------------------
// Arion project autopilot
// Created by Carmelo J. Fernández-Agüera Tortosa (a.k.a. Technik)
// On December 4th, 2012
//----------------------------------------------------------------------------------------------------------------------
// Entry point

#include <avr/io.h>

#include <core/board/board.h>
#include <core/time/time.h>

using namespace atmega2560;

//------------------------------------------------------------------------
void initSystem()
{
	Board::init(); // Initialize hardware board singleton
	Time::init();
}

//----------------------------------------------------------------------------------------------------------------------
int main ()
{
	initSystem();
	// Board initialization
	Board * board = Board::get();
	board->digitalOff(13); 
	board->digitalOn(28);
	board->digitalOff(8);

	while(1) // Keep looping forever
	{
		if (board->digitalRead(7) == 1)
		{
			board->digitalOn(13);
		}
		else
		{
			board->digitalOff(13);
		}

	}
	return 0;
}