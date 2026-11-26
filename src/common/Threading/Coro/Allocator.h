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

#ifndef TRINITYCORE_CORO_ALLOCATOR_H
#define TRINITYCORE_CORO_ALLOCATOR_H

#include "./CoroutineFwd.h"
#include "Define.h"

namespace Trinity::Coro::Impl
{
struct Allocator;

namespace CurrentAllocator
{
TC_COMMON_API Allocator* Get();
TC_COMMON_API void Set(Allocator* allocator);

TC_COMMON_API void* Allocate(std::size_t size);
TC_COMMON_API void Free(void* data, std::size_t size);
}
}

#endif // TRINITYCORE_CORO_ALLOCATOR_H
