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

#ifndef SFMTRand_h__
#define SFMTRand_h__

#include "Define.h"
#include <SFMT.h>
#include <new>

/*
 * C++ Wrapper for SFMT
 */
class SFMTRand {
public:
    SFMTRand() noexcept;
    uint32 RandomUInt32() noexcept; // Output random bits
    void* operator new(size_t size) noexcept { return ::operator new (size, std::align_val_t(alignof(SFMTRand)), std::nothrow); }
    void operator delete(void* ptr) noexcept { ::operator delete (ptr, std::align_val_t(alignof(SFMTRand)), std::nothrow); }
    void* operator new[](size_t size) noexcept { return ::operator new[](size, std::align_val_t(alignof(SFMTRand)), std::nothrow); }
    void operator delete[](void* ptr) noexcept { ::operator delete[](ptr, std::align_val_t(alignof(SFMTRand)), std::nothrow); }
private:
    sfmt_t _state;
};

#endif // SFMTRand_h__
