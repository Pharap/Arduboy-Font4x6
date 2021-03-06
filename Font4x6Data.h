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

constexpr uint8_t Font4x6ImageWidth = 4;
constexpr uint8_t Font4x6ImageHeight = 8;

const uint8_t Font4x6Image[] PROGMEM =
{
	// Width, Height
	Font4x6ImageWidth, Font4x6ImageHeight,

	// A
	0x3E, 0x09, 0x09, 0x3E,
	// B
	0x3F, 0x25, 0x25, 0x1A,
	// C
	0x1E, 0x21, 0x21, 0x12,
	// D
	0x3F, 0x21, 0x21, 0x1E,
	// E
	0x3F, 0x25, 0x25, 0x21,
	// F
	0x3F, 0x05, 0x05, 0x01,
	// G
	0x1E, 0x21, 0x29, 0x3A,
	// H
	0x3F, 0x04, 0x04, 0x3F,
	// I
	0x21, 0x3F, 0x21, 0x00,
	// J
	0x10, 0x21, 0x21, 0x1F,
	// K
	0x3F, 0x04, 0x0A, 0x31,
	// L
	0x3F, 0x20, 0x20, 0x20,
	// M
	0x3F, 0x02, 0x02, 0x3F,
	// N
	0x3F, 0x02, 0x04, 0x3F,
	// O
	0x1E, 0x21, 0x21, 0x1E,
	// P
	0x3F, 0x09, 0x09, 0x06,
	// Q
	0x1E, 0x21, 0x11, 0x2E,
	// R
	0x3F, 0x09, 0x09, 0x36,
	// S
	0x22, 0x25, 0x25, 0x19,
	// T
	0x01, 0x3F, 0x01, 0x01,
	// U
	0x1F, 0x20, 0x20, 0x1F,
	// V
	0x0F, 0x10, 0x20, 0x1F,
	// W
	0x3F, 0x10, 0x10, 0x3F,
	// X
	0x3B, 0x04, 0x04, 0x3B,
	// Y
	0x03, 0x04, 0x38, 0x07,
	// Z
	0x31, 0x2D, 0x23, 0x21,


	#if !defined(FONT4X6_DISABLE_LOWER_CASE)
	// a
	0x10, 0x2A, 0x2A, 0x3C,
	// b
	0x3F, 0x24, 0x24, 0x18,
	// c
	0x1C, 0x22, 0x22, 0x14,
	// d
	0x18, 0x24, 0x24, 0x3F,
	// e
	0x1C, 0x2A, 0x2A, 0x2C,
	// f
	0x04, 0x7E, 0x05, 0x01,
	// g
	0x4C, 0x52, 0x52, 0x3E,
	// h
	0x3F, 0x04, 0x04, 0x38,
	// i
	0x24, 0x3D, 0x20, 0x00,
	// j
	0x40, 0x40, 0x44, 0x3D,
	// k
	0x3F, 0x08, 0x14, 0x22,
	// l
	0x21, 0x3F, 0x20, 0x00,
	// m
	0x3E, 0x04, 0x04, 0x3E,
	// n
	0x3E, 0x04, 0x02, 0x3C,
	// o
	0x1C, 0x22, 0x22, 0x1C,
	// p
	0x7E, 0x22, 0x22, 0x1C,
	// q
	0x1C, 0x22, 0x22, 0x7E,
	// r
	0x3E, 0x04, 0x02, 0x04,
	// s
	0x24, 0x2A, 0x2A, 0x12,
	// t
	0x02, 0x1F, 0x22, 0x20,
	// u
	0x1E, 0x20, 0x20, 0x1E,
	// v
	0x0E, 0x10, 0x20, 0x1E,
	// w
	0x3E, 0x10, 0x10, 0x3E,
	// x
	0x36, 0x08, 0x08, 0x36,
	// y
	0x4E, 0x50, 0x50, 0x3E,
	// z
	0x32, 0x2A, 0x26, 0x22,
	#endif

	// 0
	0x1E, 0x29, 0x25, 0x1E,
	// 1
	0x22, 0x3F, 0x20, 0x00,
	// 2
	0x32, 0x29, 0x29, 0x26,
	// 3
	0x12, 0x21, 0x25, 0x1A,
	// 4
	0x0C, 0x0A, 0x3F, 0x08,
	// 5
	0x17, 0x25, 0x25, 0x19,
	// 6
	0x1E, 0x25, 0x25, 0x18,
	// 7
	0x01, 0x39, 0x05, 0x03,
	// 8
	0x1A, 0x25, 0x25, 0x1A,
	// 9
	0x06, 0x29, 0x29, 0x1E,

	// !
	0x00, 0x2F, 0x00, 0x00,
	// .
	0x00, 0x20, 0x00, 0x00,
};