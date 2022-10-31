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

#ifndef PCGRand_h__
#define PCGRand_h__

#include "Define.h"
#include "pcg_random.hpp"
#include <new>

 /*
  * C++ Wrapper for PCG
  */
class PCGRand
{
public:
    PCGRand();
    uint32 RandomUInt32(); // Output random bits
    void* operator new(size_t size, std::nothrow_t const&);
    void operator delete(void* ptr, std::nothrow_t const&);
    void* operator new(size_t size);
    void operator delete(void* ptr);
    void* operator new[](size_t size, std::nothrow_t const&);
    void operator delete[](void* ptr, std::nothrow_t const&);
    void* operator new[](size_t size);
    void operator delete[](void* ptr);
private:

    pcg64 _state;
};

#endif // PCGRand_h__
