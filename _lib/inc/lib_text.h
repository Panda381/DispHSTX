
// ****************************************************************************
//
//                               Text strings
//
// ****************************************************************************
// PicoLibSDK - Alternative SDK library for Raspberry Pico and RP2040
// Copyright (c) 2023 Miroslav Nemecek, Panda38@seznam.cz, hardyplotter2@gmail.com
// 	https://github.com/Panda381/PicoLibSDK
//	https://www.breatharian.eu/hw/picolibsdk/index_en.html
//	https://github.com/pajenicko/picopad
//	https://picopad.eu/en/
// License:
//	This source code is freely available for any purpose, including commercial.
//	It is possible to take and modify the code or parts of it, without restriction.

// - use pText as text object
// - before use, initialize text object using TextInit() (constructor)
// - after use, terminate text object using TextTerm() (destructor)

#ifndef _LIB_TEXT_H
#define _LIB_TEXT_H

#if USE_TEXT	// use Text strings, except StrLen and StrComp (lib_text.c, lib_text.h)

#ifdef __cplusplus
extern "C" {
#endif

// get length of ASCIIZ text string
INLINE int StrLen(const char* text) { return strlen(text); }

#ifdef __cplusplus
}
#endif

#endif // USE_TEXT	// use Text strings (lib_text.c, lib_text.h)

#endif // _LIB_TEXT_H
