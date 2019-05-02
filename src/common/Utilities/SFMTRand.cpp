/*
 * Copyright (C) 2008-2013 TrinityCore <https://www.trinitycore.org/>
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

SFMTRand::SFMTRand()
{
    LastInterval = 0;
    RandomInit((int)(time(0)));
}

void SFMTRand::RandomInit(int seed)                     // Re-seed
{
    // Re-seed
    uint32_t i;                         // Loop counter
    uint32_t y = seed;                  // Temporary
    uint32_t statesize = SFMT_N*4;      // Size of state vector

    // Fill state vector with random numbers from seed
    uint32_t* s = (uint32_t*)&state;
    s[0] = y;
    const uint32_t factor = 1812433253U;// Multiplication factor

    for (i = 1; i < statesize; i++) {
        y = factor * (y ^ (y >> 30)) + i;
        ((uint32_t*)state)[i] = y;
    }

    // Further initialization and period certification
    Init2();
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
    // Output random floating point number
    if (ix >= SFMT_N*4-1) {
        // Make sure we have at least two 32-bit numbers
        Generate();
    }
    uint64_t r = *(uint64_t*)((uint32_t*)state+ix);
    ix += 2;
    // 52 bits resolution for compatibility with assembly version:
    return (int64_t)(r >> 12) * (1./(67108864.0*67108864.0));
}

uint32_t SFMTRand::BRandom()                            // Output random bits
{
    // Output 32 random bits
    uint32_t y;

    if (ix >= SFMT_N*4) {
        Generate();
    }
    y = ((uint32_t*)state)[ix++];
    return y;
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

void SFMTRand::Init2()                                   // Various initializations and period certification
{
    // Various initializations and period certification
    uint32_t i, j, temp;

    // Initialize mask
    static const uint32_t maskinit[4] = {SFMT_MASK};
    mask = _mm_loadu_si128((__m128i*)maskinit);

    // Period certification
    // Define period certification vector
    static const uint32_t parityvec[4] = {SFMT_PARITY};

    // Check if parityvec & state[0] has odd parity
    temp = 0;
    for (i = 0; i < 4; i++)
        temp ^= parityvec[i] & ((uint32_t*)state)[i];

    for (i = 16; i > 0; i >>= 1) temp ^= temp >> i;
    if (!(temp & 1)) {
        // parity is even. Certification failed
        // Find a nonzero bit in period certification vector
        for (i = 0; i < 4; i++) {
            if (parityvec[i]) {
                for (j = 1; j; j <<= 1) {
                    if (parityvec[i] & j) {
                        // Flip the corresponding bit in state[0] to change parity
                        ((uint32_t*)state)[i] ^= j;
                        // Done. Exit i and j loops
                        i = 5;  break;
                    }
                }
            }
        }
    }

    // Generate first random numbers and set ix = 0
    Generate();
}

void SFMTRand::Generate()                                // Fill state array with new random numbers
{
    // Fill state array with new random numbers
    int i;
    __m128i r, r1, r2;

    r1 = state[SFMT_N - 2];
    r2 = state[SFMT_N - 1];
    for (i = 0; i < SFMT_N - SFMT_M; i++) {
        r = sfmt_recursion(state[i], state[i + SFMT_M], r1, r2, mask);
        state[i] = r;
        r1 = r2;
        r2 = r;
    }
    for (; i < SFMT_N; i++) {
        r = sfmt_recursion(state[i], state[i + SFMT_M - SFMT_N], r1, r2, mask);
        state[i] = r;
        r1 = r2;
        r2 = r;
    }
    ix = 0;
}
