//----------------------------------------------------------------------------------------------------------------------
// Arion project autopilot
// Created by Carmelo J. Fernández-Agüera Tortosa (a.k.a. Technik)
// On December 25th, 2012
//----------------------------------------------------------------------------------------------------------------------
// Time measure and control

#ifndef _ARION_CORE_TIME_TIME_H_
#define _ARION_CORE_TIME_TIME_H_

#include <stdint.h>

namespace atmega2560
{
	class Time
	{
	public:
		static void		init	();
		static void		delayUs	(unsigned _micros); // Works for maximun delays of 32 milliseconds or so
		static void		delayMs	(unsigned _millis); // Works for maximun delays of about a minute

		static unsigned	seconds	(); // Overflow every 18 hours approx
		static unsigned millis	(); // Overflow every minute or so
		static unsigned	micros	(); // Overflow every 32 milliseconds or so

	private:
		static volatile uint32_t sMillis;

	public:
		// Use for interrupt only
		static void tickTimer();
	};
}	// namespace atmega2560

#endif // _ARION_CORE_TIME_TIME_H_
