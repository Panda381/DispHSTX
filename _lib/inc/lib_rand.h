
// ****************************************************************************
//
//                          Random number generator
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

// 64-bit LCG random number generator
// Each CPU core uses its own random generator to avoid the need to lock access to the generator.

#if USE_RAND		// use Random number generator (lib_rand.c, lib_rand.h)

#ifndef _LIB_RAND_H
#define _LIB_RAND_H

#ifdef __cplusplus
extern "C" {
#endif

// Seed of random number generator (for both CPU cores)
extern u64 RandSeed;

// get seed of random number generator (for current CPU core)
u64 RandGet();

// set seed of random number generator (for current CPU core)
void RandSet(u64 seed);

// shift random number generator and return 32-bit random number (for current CPU core)
//  Takes 1 us
u32 RandShift();

// generate 8-bit unsigned integer random number
//  Takes 1 us
u8 RandU8();

// generate 16-bit unsigned integer random number
//  Takes 1 us
u16 RandU16();

//#ifndef RAND_MAX
//#define RAND_MAX 0x7fffffff
//#endif

// generate 32-bit unsigned integer random number
//  Takes 1 us
INLINE u32 RandU32() { return RandShift(); }

// generate 64-bit unsigned integer random number
//  Takes 2 us
u64 RandU64();

// generate 8-bit signed integer random number
//  Takes 1 us
INLINE s8 RandS8() { return (s8)RandU8(); }

// generate 16-bit signed integer random number
//  Takes 1 us
INLINE s16 RandS16() { return (s16)RandU16(); }

// generate 32-bit signed integer random number
//  Takes 1 us
INLINE s32 RandS32() { return (s32)RandShift(); }

// generate 64-bit signed integer random number
//  Takes 2 us
INLINE s64 RandS64() { return (s64)RandU64(); }

// generate 8-bit unsigned integer random number in range 0 to MAX (including)
//  Takes 2 us
u8 RandU8Max(u8 max);

// generate 16-bit unsigned integer random number in range 0 to MAX (including)
//  Takes 2 us
u16 RandU16Max(u16 max);

// generate 32-bit unsigned integer random number in range 0 to MAX (including)
//  Takes 2 us
u32 RandU32Max(u32 max);

// generate 64-bit unsigned integer random number in range 0 to MAX (including)
//  Takes 3 us
u64 RandU64Max(u64 max);

// generate 8-bit signed integer random number in range 0 to MAX (including, 'max' can be negative)
//  Takes 2 us
s8 RandS8Max(s8 max);

// generate 16-bit signed integer random number in range 0 to MAX (including, 'max' can be negative)
//  Takes 2 us
s16 RandS16Max(s16 max);

// generate 32-bit signed integer random number in range 0 to MAX (including, 'max' can be negative)
//  Takes 2 us
s32 RandS32Max(s32 max);

// generate 64-bit signed integer random number in range 0 to MAX (including, 'max' can be negative)
//  Takes 3 us
s64 RandS64Max(s64 max);

// generate 8-bit unsigned integer random number in range MIN to MAX (including)
// If MIN > MAX, then number is generated out of interval.
//  Takes 2 us
u8 RandU8MinMax(u8 min, u8 max);

// generate 16-bit unsigned integer random number in range MIN to MAX (including)
// If MIN > MAX, then number is generated out of interval.
//  Takes 2 us
u16 RandU16MinMax(u16 min, u16 max);

// generate 32-bit unsigned integer random number in range MIN to MAX (including)
// If MIN > MAX, then number is generated out of interval.
//  Takes 2 us
u32 RandU32MinMax(u32 min, u32 max);

// generate 64-bit unsigned integer random number in range MIN to MAX (including)
// If MIN > MAX, then number is generated out of interval.
//  Takes 3 us
u64 RandU64MinMax(u64 min, u64 max);

// generate 8-bit signed integer random number in range MIN to MAX (including)
// If MIN > MAX, then number is generated out of interval.
//  Takes 2 us
s8 RandS8MinMax(s8 min, s8 max);

// generate 16-bit signed integer random number in range MIN to MAX (including)
// If MIN > MAX, then number is generated out of interval.
//  Takes 2 us
s16 RandS16MinMax(s16 min, s16 max);

// generate 32-bit signed integer random number in range MIN to MAX (including)
// If MIN > MAX, then number is generated out of interval.
//  Takes 2 us
s32 RandS32MinMax(s32 min, s32 max);

// generate 64-bit signed integer random number in range MIN to MAX (including)
// If MIN > MAX, then number is generated out of interval.
//  Takes 3 us
s64 RandS64MinMax(s64 min, s64 max);

#ifdef __cplusplus
}
#endif

#endif // _LIB_RAND_H

#endif // USE_RAND		// use Random number generator (lib_rand.c, lib_rand.h)
