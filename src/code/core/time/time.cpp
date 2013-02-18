//----------------------------------------------------------------------------------------------------------------------
// Arion project autopilot
// Created by Carmelo J. Fernández-Agüera Tortosa (a.k.a. Technik)
// On December 25th, 2012
//----------------------------------------------------------------------------------------------------------------------
// Time measure and control

#include <avr/interrupt.h>

#include "time.h"
#include <core/interrupts/interrupts.h>

SIGNAL(TIMER1_COMPA_vect)
{
	atmega2560::Time::tickTimer();
}

namespace atmega2560
{
	//------------------------------------------------------------------------------------------------------------------
	// Static data definition
	//------------------------------------------------------------------------------------------------------------------
	volatile uint32_t Time::sMillis = 0;

	//------------------------------------------------------------------------------------------------------------------
	void Time::init()
	{
		InterruptMgr::lockInterrupts();
		// Configure timer registers
		//····································
		// Use 16bit-timer Timer1
		// Prescaler: 1/8th of clock frequency
		// Resolution: 1 uS
		//....................................
		OCR1A = 2000; // The timer is configured to tick twice per microsecond, so 2000 ticks mean one millisecond
		TCCR1B = (1<<3) | (1<<1); // Set prescaler to 1:8 and Timer mode to CTC with compare on OCR1A register
		TIMSK1 = (1<<1);
		// Clear power reduction bit to enable the timer?
		InterruptMgr::unlockInterrupts();
	}

	//------------------------------------------------------------------------------------------------------------------
	void Time::delayUs(unsigned _micros)
	{
		unsigned startUs = micros();
		while((micros() - startUs) < _micros)
		{}
	}

	//------------------------------------------------------------------------------------------------------------------
	void Time::delayMs(unsigned _millis)
	{
		unsigned startMs = millis();
		while((millis() - startMs) < _millis)
		{}
	}

	//------------------------------------------------------------------------------------------------------------------
	unsigned Time::micros()
	{
		InterruptMgr::lockInterrupts();
		unsigned temp = TCNT1;
		InterruptMgr::unlockInterrupts();
		return temp >> 1;
	}

	//------------------------------------------------------------------------------------------------------------------
	unsigned Time::millis()
	{
		InterruptMgr::lockInterrupts();
		unsigned temp = unsigned(sMillis);
		InterruptMgr::unlockInterrupts();
		return temp;
	}

	//------------------------------------------------------------------------------------------------------------------
	unsigned Time::seconds()
	{
		InterruptMgr::lockInterrupts();
		uint32_t temp = sMillis;
		InterruptMgr::unlockInterrupts();
		return unsigned (temp/1000);
	}

	//------------------------------------------------------------------------------------------------------------------
	void Time::tickTimer()
	{
		++sMillis;
	}

}	// namespace atmega2560