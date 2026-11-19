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

#include "ArenaTeam.h"
#include "Define.h"
#include "SmartEnum.h"
#include <stdexcept>

namespace Trinity::Impl::EnumUtilsImpl
{

/******************************************************************\
|* data for enum 'ArenaTeamTypes' in 'ArenaTeam.h' auto-generated *|
\******************************************************************/
template <>
TC_API_EXPORT EnumText EnumUtils<ArenaTeamTypes>::ToString(ArenaTeamTypes value)
{
    switch (value)
    {
        case ARENA_TEAM_2v2: return { "ARENA_TEAM_2v2", "ARENA_TEAM_2v2", "" };
        case ARENA_TEAM_3v3: return { "ARENA_TEAM_3v3", "ARENA_TEAM_3v3", "" };
        case ARENA_TEAM_5v5: return { "ARENA_TEAM_5v5", "ARENA_TEAM_5v5", "" };
        default: throw std::out_of_range("value");
    }
}

template <>
TC_API_EXPORT size_t EnumUtils<ArenaTeamTypes>::Count() { return 3; }

template <>
TC_API_EXPORT ArenaTeamTypes EnumUtils<ArenaTeamTypes>::FromIndex(size_t index)
{
    switch (index)
    {
        case 0: return ARENA_TEAM_2v2;
        case 1: return ARENA_TEAM_3v3;
        case 2: return ARENA_TEAM_5v5;
        default: throw std::out_of_range("index");
    }
}

template <>
TC_API_EXPORT size_t EnumUtils<ArenaTeamTypes>::ToIndex(ArenaTeamTypes value)
{
    switch (value)
    {
        case ARENA_TEAM_2v2: return 0;
        case ARENA_TEAM_3v3: return 1;
        case ARENA_TEAM_5v5: return 2;
        default: throw std::out_of_range("value");
    }
}
}
