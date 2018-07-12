// BSD 3-Clause License
//
// Copyright (c) 2018, Filmote
// Copyright (c) 2018, Pharap
// All rights reserved.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are met:
//
// * Redistributions of source code must retain the above copyright notice, this
//   list of conditions and the following disclaimer.
//
// * Redistributions in binary form must reproduce the above copyright notice,
//   this list of conditions and the following disclaimer in the documentation
//   and/or other materials provided with the distribution.
//
// * Neither the name of the copyright holder nor the names of its
//   contributors may be used to endorse or promote products derived from
//   this software without specific prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
// AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
// IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
// DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
// FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
// DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
// SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
// CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
// OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
// OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

#include "Font4x6.h"
#include "Font4x6Data.h"

#include <Arduino.h>
#include <Arduboy2.h>

// To enable SpritesB support
// #define FONT4X6_USE_SPRITES_B

// To disable lowercase letters
// #define FONT4X6_DISABLE_LOWER_CASE

namespace Font4x6Constants
{
	static constexpr uint8_t UppercaseIndex = 0;
	static constexpr uint8_t UppercaseCount = 26;

	#if !defined(FONT4X6_DISABLE_LOWER_CASE)
	static constexpr uint8_t LowercaseIndex = (UppercaseIndex + UppercaseCount);
	static constexpr uint8_t LowercaseCount = 26;
	#endif

	#if !defined(FONT4X6_DISABLE_LOWER_CASE)
	static constexpr bool LowercaseEnabled = true;
	#else
	static constexpr bool LowercaseEnabled = false;
	#endif

	static constexpr uint8_t DigitIndex = (LowercaseEnabled) ? (LowercaseIndex + LowercaseCount) : (UppercaseIndex + UppercaseCount);
	static constexpr uint8_t DigitCount = 10;

	static constexpr uint8_t ExclamationIndex = DigitIndex + 10;
	static constexpr uint8_t PeriodIndex = ExclamationIndex + 1;
}

uint8_t Font4x6::getCursorX(void) const
{
	return this->cursorX;
}

uint8_t Font4x6::getCursorY(void) const
{
	return this->cursorY;
}

uint8_t Font4x6::getTextColour(void) const
{
	return this->textColour;
}

uint8_t Font4x6::getLineSpacing(void) const
{
	return this->lineSpacing;
}

uint8_t Font4x6::getLetterSpacing(void) const
{
	return this->letterSpacing;
}

uint8_t Font4x6::getLineHeight(void) const
{
	return (CharHeight + this->lineSpacing);
}

void Font4x6::setCursorX(int8_t x)
{
	this->baseX = x;
	this->cursorX = x;
}

void Font4x6::setCursorY(int8_t y)
{
	this->cursorY = y;
}

void Font4x6::setCursor(int8_t x, int8_t y)
{
	this->baseX = x;
	this->cursorX = x;
	this->cursorY = y;
}

void Font4x6::setTextColour(uint8_t colour)
{
	this->textColour = colour;
}

void Font4x6::setLineSpacing(uint8_t lineSpacing)
{
	this->lineSpacing = lineSpacing;
}

void Font4x6::setLetterSpacing(uint8_t letterSpacing)
{
	this->letterSpacing = letterSpacing;
}

size_t Font4x6::write(uint8_t c)
{
	if (c == '\n')
	{
		this->cursorX = this->baseX;
		this->cursorY += this->lineSpacing;
	}
	else
	{
		printChar(c, this->cursorX, this->cursorY, this->textColour);
		this->cursorX += (CharWidth + this->letterSpacing);
	}
	return 1;
}

int8_t Font4x6::getCharIndex(char c)
{
	using namespace Font4x6Constants;

	if(c >= 'A' && c <= 'Z')
	{
		return UppercaseIndex + (c - 'A');
	}
	#if !defined(FONT4X6_DISABLE_LOWER_CASE)
	else if(c >= 'a' && c <= 'z')
	{
		return LowercaseIndex + (c - 'a');
	}
	#endif
	else if(c >= '0' && c <= '9')
	{
		return DigitIndex + (c - '0');
	}
	else if(c == '!')
	{
		return ExclamationIndex;
	}
	else if(c == '.')
	{
		return PeriodIndex;
	}

	return -1;
}

void Font4x6::printChar(char c, int8_t x, int8_t y, uint8_t textColour)
{
	using namespace Font4x6Constants;

	#if defined(FONT4X6_USE_SPRITES_B)
	using Render = SpritesB;
	#else
	using Render = Sprites;
	#endif

	const int8_t index = getCharIndex(c);

	if(index < 0)
		return;

	if (textColour != 0)
	{
		Render::drawSelfMasked(x, (y + 1), Font4x6Image, index);
	}
	else
	{
		Render::drawErase(x, (y + 1), Font4x6Image, index);
	}
}
