//----------------------------------------------------------------------------------------------------------------------
// Arion project autopilot
// Created by Carmelo J. Fern�ndez-Ag�era Tortosa (a.k.a. Technik)
// On December 13th, 2012
//----------------------------------------------------------------------------------------------------------------------
// Interrupts control

#include "interrupts.h"

#include <avr/interrupt.h>

namespace atmega2560
{
	//------------------------------------------------------------------------------------------------------------------
	// Global static data
	//------------------------------------------------------------------------------------------------------------------
	uint8_t InterruptMgr::nLocks = 0;

	//------------------------------------------------------------------------------------------------------------------
	void InterruptMgr::lockInterrupts()
	{
		cli();
		++nLocks;
	}

	//------------------------------------------------------------------------------------------------------------------
	void InterruptMgr::unlockInterrupts()
	{
		--nLocks;
		if(0 == nLocks)
		{
			sei();
		}
	}

}	// namespace atmega2560