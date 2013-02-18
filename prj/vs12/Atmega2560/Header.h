//----------------------------------------------------------------------------------------------------------------------
// Arion project autopilot
// Created by Juan José Blasco Burguillos
// On February 13th, 2013
//----------------------------------------------------------------------------------------------------------------------
// Serial peripheral interfac, comunication with sensors and other avr

#ifndef _ARION_CORE_BOARD_SPI_SPI_H_
#define _ARION_CORE_BOARD_SPI_SPI_H_

namespace arion
{
	class SPI
	{
	public:

		// Master or Slave initialization
		void	MasterInit		();
		void	SlaveInit		();

		// Trasmit and Recive
		void	TX				(unsigned char byte);
		char	RX				();
	};
}	// namespace arion

#endif //_ARION_CORE_BOARD_SPI_SPI_H_
