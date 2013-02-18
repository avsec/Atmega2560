//----------------------------------------------------------------------------------------------------------------------
// Arion project autopilot
// Created by Carmelo J. Fernández-Agüera Tortosa (a.k.a. Technik)
// On December 13th, 2012
//----------------------------------------------------------------------------------------------------------------------
// Interrupts control

#ifndef _ATMEGA2560_CORE_INTERRUPTS_INTERRUPTS_H_
#define _ATMEGA2560_INTERRUPTS_INTERRUPTS_H_

#include <stdint.h>

namespace atmega2560
{
	class InterruptMgr
	{
	public:
		// Singleton interface
		static void	lockInterrupts		();
		static void	unlockInterrupts	();

	private:
		// Reference counting
		// Interrupts will keep disabled as long as anybody wants to. Everyone who has disabled
		// interrupts is responsible for enabling them again in order for interrupts to work
		static uint8_t	nLocks;
	};
}	// namespace atmega2560

#endif // _ARION_CORE_INTERRUPTS_INTERRUPTS_H_
