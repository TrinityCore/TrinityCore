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

#include "SpawnData.h"
#include "Define.h"
#include "SmartEnum.h"
#include <stdexcept>

namespace Trinity
{
namespace Impl
{

/*******************************************************************\
|* data for enum 'SpawnObjectType' in 'SpawnData.h' auto-generated *|
\*******************************************************************/
template <>
TC_API_EXPORT EnumText EnumUtils<SpawnObjectType>::ToString(SpawnObjectType value)
{
    switch (value)
    {
        case SPAWN_TYPE_CREATURE: return { "SPAWN_TYPE_CREATURE", "Creature", "" };
        case SPAWN_TYPE_GAMEOBJECT: return { "SPAWN_TYPE_GAMEOBJECT", "Gameobject", "" };
        default: throw std::out_of_range("value");
    }
}

template <>
TC_API_EXPORT size_t EnumUtils<SpawnObjectType>::Count() { return 2; }

template <>
TC_API_EXPORT SpawnObjectType EnumUtils<SpawnObjectType>::FromIndex(size_t index)
{
    switch (index)
    {
        case 0: return SPAWN_TYPE_CREATURE;
        case 1: return SPAWN_TYPE_GAMEOBJECT;
        default: throw std::out_of_range("index");
    }
}
}
}
