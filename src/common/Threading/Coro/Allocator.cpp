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

#include "./Allocator.h"
#include "./AllocatorImpl.h"

namespace Trinity::Coro::Impl
{
namespace CurrentAllocator
{
namespace
{
thread_local Allocator* Instance;
}

Allocator* Get()
{
    return Instance;
}

void Set(Allocator* allocator)
{
    Instance = allocator;
}

void* Allocate(std::size_t size)
{
    return Instance->allocate(size);
}

void Free(void* data, std::size_t size)
{
    Instance->deallocate(data, size);
}
}
}
