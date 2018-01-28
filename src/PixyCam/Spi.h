/******************************************************************************
*																			  *
*	PixyCam/Spi.h - Declaration of class PixyCam::Spi.						  *
*																			  *
*	PixyCam::Spi implements PixyCam::Channel for use on an SPI link.		  *
*																			  *
*	Author:  JWB															  *
*	Date:	 2018-Jan-25													  *
*																			  *
******************************************************************************/

#pragma once

#include <queue>
#include <SPI.h>
#include "Channel.h"

namespace PixyCam
{
	class Spi : public Channel
	{
	public:
		Spi(frc::SPI::Port port) : _spi{ std::move(port) } { }				// Constructor
		virtual size_t Read(uint8_t* buffer, size_t count) override;		// Read bytes
		virtual size_t Write(const uint8_t* buffer, size_t count) override;	// Write bytes

	private:
		uint16_t GetNextWordToWrite();										// Get the next word to write so that we can read a word

		frc::SPI			_spi;											// Library provided SPI object
		std::queue<uint8_t>	_writeQueue;									// Bytes to write
	};
}