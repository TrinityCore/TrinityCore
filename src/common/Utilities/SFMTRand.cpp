/*
 * This file is part of the TrinityCore Project. See AUTHORS file for Copyright information
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
#include <algorithm>
#include <array>
#include <functional>
#include <random>
#include <ctime>

#if __has_include(<mm_malloc.h>)
#include <mm_malloc.h>
#elif __has_include(<malloc.h>) && TRINITY_COMPILER == TRINITY_COMPILER_MICROSOFT
#include <malloc.h>
#else
static __inline__ void *__attribute__((__always_inline__, __nodebug__, __malloc__))
_mm_malloc(size_t __size, size_t __align)
{
    if (__align == 1)
    {
        return malloc(__size);
    }

    if (!(__align & (__align - 1)) && __align < sizeof(void *))
        __align = sizeof(void *);

    void *__mallocedMemory;

    if (posix_memalign(&__mallocedMemory, __align, __size))
        return NULL;

    return __mallocedMemory;
}

static __inline__ void __attribute__((__always_inline__, __nodebug__))
_mm_free(void *__p)
{
    free(__p);
}
#endif

SFMTRand::SFMTRand()
{
    std::random_device dev;
    if (dev.entropy() > 0)
    {
        std::array<uint32, SFMT_N32> seed;
        std::generate(seed.begin(), seed.end(), std::ref(dev));

        sfmt_init_by_array(&_state, seed.data(), seed.size());
    }
    else
        sfmt_init_gen_rand(&_state, uint32(time(nullptr)));
}

uint32 SFMTRand::RandomUInt32()                            // Output random bits
{
    return sfmt_genrand_uint32(&_state);
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
