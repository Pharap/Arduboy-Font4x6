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

#pragma once

#include <Arduino.h>

class Font4x6 : public Print
{
public:
	// Constants
	static constexpr uint8_t CharWidth = 4;
	static constexpr uint8_t CharHeight = 6;

private:
	// Member variables
	int8_t baseX = 0;
	int8_t cursorX = 0;
	int8_t cursorY = 0;

	// Zero is black, nonzero values are white
	uint8_t textColour = ~0;

	// letterSpacing controls the distance between letters
	uint8_t letterSpacing = 1;

	// lineSpacing controls the height between lines
	uint8_t lineSpacing = 8;

public:
	// Constructors
	Font4x6(void) = default;

	// Getters
	uint8_t getCursorX(void) const;
	uint8_t getCursorY(void) const;
	uint8_t getTextColour(void) const;
	uint8_t getLineSpacing(void) const;
	uint8_t getLetterSpacing(void) const;
	uint8_t getLineHeight(void) const;

	// Setters
	void setCursorX(int8_t x);
	void setCursorY(int8_t y);
	void setCursor(int8_t x, int8_t y);
	void setTextColour(uint8_t colour);
	void setLineSpacing(uint8_t lineSpacing);
	void setLetterSpacing(uint8_t letterSpacing);

	// Print functionality
	size_t write(uint8_t) override;

private:
	static int8_t getCharIndex(char c);
	static void printChar(char c, int8_t x, int8_t y, uint8_t textColour);
};
