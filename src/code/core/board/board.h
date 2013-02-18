//----------------------------------------------------------------------------------------------------------------------
// Arion project autopilot
// Created by Carmelo J. Fernández-Agüera Tortosa (a.k.a. Technik)
// On December 4th, 2012
//----------------------------------------------------------------------------------------------------------------------
// Interface to deal with different boards

#ifndef _ATMEGA2560_CORE_BOARD_BOARD_H_
#define _ATMEGA2560_CORE_BOARD_BOARD_H_

namespace atmega2560
{
	class Board
	{
	public:
		static void		init();
		static void		end	();
		static Board*	get	(); // Singleton accessor
	public:
		virtual ~Board() {}; // Virtual destructor to ensure proper deletion of child classes

		// Digital pins
		virtual void	digitalOn		(unsigned _pin) = 0;
		virtual void	digitalOff		(unsigned _pin) = 0;
		virtual void	digitalToggle	(unsigned _pin) = 0;
		virtual bool	digitalRead		(unsigned _pin) = 0;

		// TODO: Analog pins
		// virtual unsigned analogRead(unsigned _pin) = 0;

	protected:
		Board() {}

	private:
		static Board* sBoard;
	};

	//-----------------------------------------------------------------------------------------
	// Inline implementation
	//-----------------------------------------------------------------------------------------
	inline Board* Board::get()
	{
		return sBoard;
	}

}	// namespace atmega2560

#endif // _ARION_CORE_BOARD_BOARD_H_
