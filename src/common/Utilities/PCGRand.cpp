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

#include "PCGRand.h"
#include <algorithm>
#include <array>
#include <functional>
#include <random>
#include <emmintrin.h>
#include <ctime>

PCGRand::PCGRand()
{
    _state.seed(pcg_extras::seed_seq_from<std::random_device>());
}

uint32 PCGRand::RandomUInt32()                            // Output random bits
{
    std::uniform_int_distribution<uint32> dist;
    return dist(_state);
}

void* PCGRand::operator new(size_t size, std::nothrow_t const&)
{
    return _mm_malloc(size, 16);
}

void PCGRand::operator delete(void* ptr, std::nothrow_t const&)
{
    _mm_free(ptr);
}

void* PCGRand::operator new(size_t size)
{
    return _mm_malloc(size, 16);
}

void PCGRand::operator delete(void* ptr)
{
    _mm_free(ptr);
}

void* PCGRand::operator new[](size_t size, std::nothrow_t const&)
{
    return _mm_malloc(size, 16);
}

void PCGRand::operator delete[](void* ptr, std::nothrow_t const&)
{
    _mm_free(ptr);
}

void* PCGRand::operator new[](size_t size)
{
    return _mm_malloc(size, 16);
}

void PCGRand::operator delete[](void* ptr)
{
    _mm_free(ptr);
}
