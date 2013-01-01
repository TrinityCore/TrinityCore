/*
 * Copyright notice
 * ================
 * GNU General Public License http://www.gnu.org/licenses/gpl.html
 * This C++ implementation of SFMT contains parts of the original C code
 * which was published under the following BSD license, which is therefore
 * in effect in addition to the GNU General Public License.
 * Copyright (c) 2006, 2007 by Mutsuo Saito, Makoto Matsumoto and Hiroshima University.
 * Copyright (c) 2008 by Agner Fog.
 * Copyright (c) 2012 Trinity Core
 * 
 *  BSD License:
 *  Redistribution and use in source and binary forms, with or without 
 * modification, are permitted provided that the following conditions are met:
 *     > Redistributions of source code must retain the above copyright notice, 
 *       this list of conditions and the following disclaimer.
 *     > Redistributions in binary form must reproduce the above copyright notice, 
 *       this list of conditions and the following disclaimer in the documentation
 *       and/or other materials provided with the distribution.
 *     > Neither the name of the Hiroshima University nor the names of its 
 *       contributors may be used to endorse or promote products derived from 
 *       this software without specific prior written permission.
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 * OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef SFMT_H
#define SFMT_H

#include <emmintrin.h>                 // Define SSE2 intrinsics
#include "randomc.h"                   // Define integer types etc
#include <time.h>
#include <new>

// Choose one of the possible Mersenne exponents.
// Higher values give longer cycle length and use more memory:
//#define MEXP   607
//#define MEXP  1279
//#define MEXP  2281
//#define MEXP  4253
  #define MEXP 11213
//#define MEXP 19937
//#define MEXP 44497

// Define constants for the selected Mersenne exponent:
#if MEXP == 44497
#define SFMT_N    348                  // Size of state vector
#define SFMT_M    330                  // Position of intermediate feedback
#define SFMT_SL1    5                  // Left shift of W[N-1], 32-bit words
#define SFMT_SL2	  3                  // Left shift of W[0], *8, 128-bit words
#define SFMT_SR1    9                  // Right shift of W[M], 32-bit words
#define SFMT_SR2	  3                  // Right shift of W[N-2], *8, 128-bit words
#define SFMT_MASK	  0xeffffffb,0xdfbebfff,0xbfbf7bef,0x9ffd7bff // AND mask
#define SFMT_PARITY 1,0,0xa3ac4000,0xecc1327a   // Period certification vector

#elif MEXP == 19937
#define SFMT_N    156                  // Size of state vector
#define SFMT_M    122                  // Position of intermediate feedback
#define SFMT_SL1   18                  // Left shift of W[N-1], 32-bit words
#define SFMT_SL2	  1                  // Left shift of W[0], *8, 128-bit words
#define SFMT_SR1   11                  // Right shift of W[M], 32-bit words
#define SFMT_SR2	  1                  // Right shift of W[N-2], *8, 128-bit words
#define SFMT_MASK	  0xdfffffef,0xddfecb7f,0xbffaffff,0xbffffff6 // AND mask
#define SFMT_PARITY 1,0,0,0x13c9e684   // Period certification vector

#elif MEXP == 11213
#define SFMT_N    88                   // Size of state vector
#define SFMT_M    68                   // Position of intermediate feedback
#define SFMT_SL1	14                   // Left shift of W[N-1], 32-bit words
#define SFMT_SL2	 3                   // Left shift of W[0], *8, 128-bit words
#define SFMT_SR1	 7                   // Right shift of W[M], 32-bit words
#define SFMT_SR2	 3                   // Right shift of W[N-2], *8, 128-bit words
#define SFMT_MASK	 0xeffff7fb,0xffffffef,0xdfdfbfff,0x7fffdbfd // AND mask
#define SFMT_PARITY 1,0,0xe8148000,0xd0c7afa3 // Period certification vector

#elif MEXP == 4253
#define SFMT_N    34                   // Size of state vector
#define SFMT_M    17                   // Position of intermediate feedback
#define SFMT_SL1	20                   // Left shift of W[N-1], 32-bit words
#define SFMT_SL2	 1                   // Left shift of W[0], *8, 128-bit words
#define SFMT_SR1	 7                   // Right shift of W[M], 32-bit words
#define SFMT_SR2	 1                   // Right shift of W[N-2], *8, 128-bit words
#define SFMT_MASK	 0x9f7bffff, 0x9fffff5f, 0x3efffffb, 0xfffff7bb // AND mask
#define SFMT_PARITY 0xa8000001, 0xaf5390a3, 0xb740b3f8, 0x6c11486d // Period certification vector

#elif MEXP == 2281
#define SFMT_N    18                   // Size of state vector
#define SFMT_M    12                   // Position of intermediate feedback
#define SFMT_SL1	19                   // Left shift of W[N-1], 32-bit words
#define SFMT_SL2	 1                   // Left shift of W[0], *8, 128-bit words
#define SFMT_SR1	 5                   // Right shift of W[M], 32-bit words
#define SFMT_SR2	 1                   // Right shift of W[N-2], *8, 128-bit words
#define SFMT_MASK	 0xbff7ffbf, 0xfdfffffe, 0xf7ffef7f, 0xf2f7cbbf // AND mask
#define SFMT_PARITY 0x00000001, 0x00000000, 0x00000000, 0x41dfa600  // Period certification vector

#elif MEXP == 1279
#define SFMT_N    10                   // Size of state vector
#define SFMT_M     7                   // Position of intermediate feedback
#define SFMT_SL1	14                   // Left shift of W[N-1], 32-bit words
#define SFMT_SL2	 3                   // Left shift of W[0], *8, 128-bit words
#define SFMT_SR1	 5                   // Right shift of W[M], 32-bit words
#define SFMT_SR2	 1                   // Right shift of W[N-2], *8, 128-bit words
#define SFMT_MASK	  0xf7fefffd, 0x7fefcfff, 0xaff3ef3f, 0xb5ffff7f  // AND mask
#define SFMT_PARITY 0x00000001, 0x00000000, 0x00000000, 0x20000000  // Period certification vector

#elif MEXP == 607
#define SFMT_N     5                   // Size of state vector
#define SFMT_M     2                   // Position of intermediate feedback
#define SFMT_SL1	15                   // Left shift of W[N-1], 32-bit words
#define SFMT_SL2	 3                   // Left shift of W[0], *8, 128-bit words
#define SFMT_SR1	13                   // Right shift of W[M], 32-bit words
#define SFMT_SR2	 3                   // Right shift of W[N-2], *8, 128-bit words
#define SFMT_MASK	  0xfdff37ff, 0xef7f3f7d, 0xff777b7d, 0x7ff7fb2f  // AND mask
#define SFMT_PARITY 0x00000001, 0x00000000, 0x00000000, 0x5986f054  // Period certification vector
#endif

// Functions used by SFMTRand::RandomInitByArray (UNUSED AND COMMENTED OUT)
/*
static uint32_t func1(uint32_t x) {
    return (x ^ (x >> 27)) * 1664525U;
}

static uint32_t func2(uint32_t x) {
    return (x ^ (x >> 27)) * 1566083941U;
}
*/

// Subfunction for the sfmt algorithm
static inline __m128i sfmt_recursion(__m128i const &a, __m128i const &b, 
__m128i const &c, __m128i const &d, __m128i const &mask) {
    __m128i a1, b1, c1, d1, z1, z2;
    b1 = _mm_srli_epi32(b, SFMT_SR1);
    a1 = _mm_slli_si128(a, SFMT_SL2);
    c1 = _mm_srli_si128(c, SFMT_SR2);
    d1 = _mm_slli_epi32(d, SFMT_SL1);
    b1 = _mm_and_si128(b1, mask);
    z1 = _mm_xor_si128(a, a1);
    z2 = _mm_xor_si128(b1, d1);
    z1 = _mm_xor_si128(z1, c1);
    z2 = _mm_xor_si128(z1, z2);
    return z2;
}

// Class for SFMT generator
class SFMTRand {                              // Encapsulate random number generator
    friend class ACE_TSS<SFMTRand>;

public:
    SFMTRand()
    {
        LastInterval = 0;
        RandomInit((int)(time(0)));
    }

    void RandomInit(int seed)                     // Re-seed
    {
        // Re-seed
        uint32_t i;                         // Loop counter
        uint32_t y = seed;                  // Temporary
        uint32_t statesize = SFMT_N*4;      // Size of state vector

        // Fill state vector with random numbers from seed
        ((uint32_t*)state)[0] = y;
        const uint32_t factor = 1812433253U;// Multiplication factor

        for (i = 1; i < statesize; i++) {
            y = factor * (y ^ (y >> 30)) + i;
            ((uint32_t*)state)[i] = y;
        }

        // Further initialization and period certification
        Init2();
    }

    int32_t IRandom(int32_t min, int32_t max)     // Output random integer
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

    uint32_t URandom(uint32_t min, uint32_t max)
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

    double Random()                               // Output random floating point number
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

    uint32_t BRandom()                            // Output random bits
    {
        // Output 32 random bits
        uint32_t y;

        if (ix >= SFMT_N*4) {
            Generate();
        }
        y = ((uint32_t*)state)[ix++];
        return y;
    }
private:
    void Init2()                                   // Various initializations and period certification
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

    void Generate()                                // Fill state array with new random numbers
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

    void* operator new(size_t size, std::nothrow_t const&)
    {
        return _mm_malloc(size, 16);
    }

    void operator delete(void* ptr, std::nothrow_t const&)
    {
        _mm_free(ptr);
    }

    void* operator new(size_t size)
    {
        return _mm_malloc(size, 16);
    }

    void operator delete(void* ptr)
    {
        _mm_free(ptr);
    }

    void* operator new[](size_t size, std::nothrow_t const&)
    {
        return _mm_malloc(size, 16);
    }

    void operator delete[](void* ptr, std::nothrow_t const&)
    {
        _mm_free(ptr);
    }

    void* operator new[](size_t size)
    {
        return _mm_malloc(size, 16);
    }

    void operator delete[](void* ptr)
    {
        _mm_free(ptr);
    }

    __m128i  mask;                                // AND mask
    __m128i  state[SFMT_N];                       // State vector for SFMT generator
    uint32_t ix;                                  // Index into state array
    uint32_t LastInterval;                        // Last interval length for IRandom
    uint32_t RLimit;                              // Rejection limit used by IRandom
};

#endif // SFMT_H
