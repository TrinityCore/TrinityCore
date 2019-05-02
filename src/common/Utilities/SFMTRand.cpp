/*
 * Copyright (C) 2008-2019 TrinityCore <https://www.trinitycore.org/>
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; either version 2 of the License, or (at your
 * option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#include "SFMTRand.h"

#include <exception>
#include <emmintrin.h>

SFMTRand::SFMTRand()
{
    RandomInit((uint32_t)(time(0)));
}

void SFMTRand::RandomInit(uint32_t seed)                     // Re-seed
{
    sfmt_init_gen_rand(&state, seed);
}

int32_t SFMTRand::IRandom(int32_t min, int32_t max)     // Output random integer
{
    // Output random integer in the interval min <= x <= max
    // Slightly inaccurate if (max-min+1) is not a power of 2
    if (max <= min) {
        if (max == min) return min; else return 0x80000000;
    }
    // Assume 64 bit integers supported. Use multiply and shift method
    uint32_t interval;                  // Length of interval
    uint64_t longran;                   // Random bits * interval
    uint32_t iran;                      // Longran / 2^32

    interval = (uint32_t)(max - min + 1);
    longran  = (uint64_t)BRandom() * interval;
    iran = (uint32_t)(longran >> 32);
    // Convert back to signed and return result
    return (int32_t)iran + min;
}

uint32_t SFMTRand::URandom(uint32_t min, uint32_t max)
{
    // Output random integer in the interval min <= x <= max
    // Slightly inaccurate if (max-min+1) is not a power of 2
    if (max <= min) {
        if (max == min) return min; else return 0;
    }
    // Assume 64 bit integers supported. Use multiply and shift method
    uint32_t interval;                  // Length of interval
    uint64_t longran;                   // Random bits * interval
    uint32_t iran;                      // Longran / 2^32

    interval = (uint32_t)(max - min + 1);
    longran  = (uint64_t)BRandom() * interval;
    iran = (uint32_t)(longran >> 32);
    // Convert back to signed and return result
    return iran + min;
}

double SFMTRand::Random()                               // Output random floating point number
{
    return sfmt_genrand_real1(&state);
}

uint32_t SFMTRand::BRandom()                            // Output random bits
{
    return sfmt_genrand_uint32(&state);
}

void* SFMTRand::operator new(size_t size, std::nothrow_t const&)
{
    return _mm_malloc(size, 16);
}

    void SFMTRand::operator delete(void* ptr, std::nothrow_t const&)
{
    _mm_free(ptr);
}

void* SFMTRand::operator new(size_t size)
{
    return _mm_malloc(size, 16);
}

void SFMTRand::operator delete(void* ptr)
{
    _mm_free(ptr);
}

void* SFMTRand::operator new[](size_t size, std::nothrow_t const&)
{
    return _mm_malloc(size, 16);
}

    void SFMTRand::operator delete[](void* ptr, std::nothrow_t const&)
{
    _mm_free(ptr);
}

    void* SFMTRand::operator new[](size_t size)
{
    return _mm_malloc(size, 16);
}

    void SFMTRand::operator delete[](void* ptr)
{
    _mm_free(ptr);
}
