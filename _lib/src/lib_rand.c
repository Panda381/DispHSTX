
// ****************************************************************************
//
//                          Random Generator
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

#include "../../global.h"	// globals

#if USE_RAND		// use Random number generator (lib_rand.c, lib_rand.h)

#include "../inc/lib_rand.h"

// Seed of random number generator (for both CPU cores)
u64 RandSeed = 123456789123456789ULL;

// get seed of random number generator (for current CPU core)
u64 RandGet()
{
	return RandSeed;
}

// set seed of random number generator (for current CPU core)
void RandSet(u64 seed)
{
	RandSeed = seed;
}

// shift random number generator and return 32-bit random number (for current CPU core)
u32 RandShift()
{
	// get pointer to the seed
	u64* s = &RandSeed;

	// shift seed
	u64 k = *s;
	k = k * 214013 + 2531011;
	*s = k;

	return (u32)(k >> 32);
}

// generate 8-bit unsigned integer random number
u8 RandU8()
{
	return (u8)(RandShift() >> 24);
}

// generate 16-bit unsigned integer random number
u16 RandU16()
{
	return (u16)(RandShift() >> 16);
}

/*
int rand()
{
	return (int)(RandShift() >> 1);
}
*/
// generate 64-bit unsigned integer random number
u64 RandU64()
{
	u32 n = RandShift();
	return RandShift() | ((u64)n << 32);
}

// generate 8-bit unsigned integer random number in range 0 to MAX (including, signed can be negative)
u8 RandU8Max(u8 max)
{
	u8 res;
	u8 msk;

	// zero maximal value
	if (max == 0) return 0;

	// prepare mask
	msk = (u8)Mask(max);

	// generate random number
	do {
		res = RandU8() & msk;
	} while (res > max);

	return res;
}

// generate 16-bit unsigned integer random number in range 0 to MAX (including)
u16 RandU16Max(u16 max)
{
	u16 res;
	u16 msk;

	// zero maximal value
	if (max == 0) return 0;

	// prepare mask
	msk = (u16)Mask(max);

	// generate random number
	do {
		res = RandU16() & msk;
	} while (res > max);

	return res;
}

// generate 32-bit unsigned integer random number in range 0 to MAX (including)
u32 RandU32Max(u32 max)
{
	u32 res;
	u32 msk;

	// zero maximal value
	if (max == 0) return 0;

	// prepare mask
	msk = (u32)Mask(max);

	// generate random number
	do {
		res = RandU32() & msk;
	} while (res > max);

	return res;
}

// generate 64-bit unsigned integer random number in range 0 to MAX (including)
u64 RandU64Max(u64 max)
{
	u64 res;
	u64 msk;

	// DWORD value
	if (max < 0x100000000ULL) return RandU32Max((u32)max);

	// zero maximal value
	if (max == 0) return 0;

	// prepare mask
	u8 pos = Order((u32)(max >> 32));
	msk = (u64)-1 >> (32 - pos);

	// generate random number
	do {
		res = RandU64() & msk;
	} while (res > max);

	return res;
}

// generate 8-bit signed integer random number in range 0 to MAX (including, 'max' can be negative)
s8 RandS8Max(s8 max)
{
	if (max >= 0)
		return (s8)RandU8Max((u8)max);
	else
		return -(s8)RandU8Max((u8)-max);
}

// generate 16-bit signed integer random number in range 0 to MAX (including, 'max' can be negative)
s16 RandS16Max(s16 max)
{
	if (max >= 0)
		return (s16)RandU16Max((u16)max);
	else
		return -(s16)RandU16Max((u16)-max);
}

// generate 32-bit signed integer random number in range 0 to MAX (including, 'max' can be negative)
s32 RandS32Max(s32 max)
{
	if (max >= 0)
		return (s32)RandU32Max((u32)max);
	else
		return -(s32)RandU32Max((u32)-max);
}

// generate 64-bit signed integer random number in range 0 to MAX (including, 'max' can be negative)
s64 RandS64Max(s64 max)
{
	if (max >= 0)
		return (s64)RandU64Max((u64)max);
	else
		return -(s64)RandU64Max((u64)-max);
}

// generate 8-bit unsigned integer random number in range MIN to MAX (including)
// If MIN > MAX, then number is generated out of interval.
u8 RandU8MinMax(u8 min, u8 max)
{
	return RandU8Max(max - min) + min;
}

// generate 16-bit unsigned integer random number in range MIN to MAX (including)
// If MIN > MAX, then number is generated out of interval.
u16 RandU16MinMax(u16 min, u16 max)
{
	return RandU16Max(max - min) + min;
}

// generate 32-bit unsigned integer random number in range MIN to MAX (including)
// If MIN > MAX, then number is generated out of interval.
u32 RandU32MinMax(u32 min, u32 max)
{
	return RandU32Max(max - min) + min;
}

// generate 64-bit unsigned integer random number in range MIN to MAX (including)
// If MIN > MAX, then number is generated out of interval.
u64 RandU64MinMax(u64 min, u64 max)
{
	return RandU64Max(max - min) + min;
}

// generate 8-bit signed integer random number in range MIN to MAX (including)
// If MIN > MAX, then number is generated out of interval.
s8 RandS8MinMax(s8 min, s8 max)
{
	return (s8)RandU8Max(max - min) + min;
}

// generate 16-bit signed integer random number in range MIN to MAX (including)
// If MIN > MAX, then number is generated out of interval.
s16 RandS16MinMax(s16 min, s16 max)
{
	return (s16)RandU16Max(max - min) + min;
}

// generate 32-bit signed integer random number in range MIN to MAX (including)
// If MIN > MAX, then number is generated out of interval.
s32 RandS32MinMax(s32 min, s32 max)
{
	return (s32)RandU32Max(max - min) + min;
}

// generate 64-bit signed integer random number in range MIN to MAX (including)
// If MIN > MAX, then number is generated out of interval.
s64 RandS64MinMax(s64 min, s64 max)
{
	return (s64)RandU64Max(max - min) + min;
}

#endif // USE_RAND		// use Random number generator (lib_rand.c, lib_rand.h)
