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

#include "InstanceScript.h"
#include "Define.h"
#include "SmartEnum.h"
#include <stdexcept>

namespace Trinity::Impl::EnumUtilsImpl
{

/***********************************************************************\
|* data for enum 'EncounterState' in 'InstanceScript.h' auto-generated *|
\***********************************************************************/
template <>
TC_API_EXPORT EnumText EnumUtils<EncounterState>::ToString(EncounterState value)
{
    switch (value)
    {
        case NOT_STARTED: return { "NOT_STARTED", "NOT_STARTED", "" };
        case IN_PROGRESS: return { "IN_PROGRESS", "IN_PROGRESS", "" };
        case FAIL: return { "FAIL", "FAIL", "" };
        case DONE: return { "DONE", "DONE", "" };
        case SPECIAL: return { "SPECIAL", "SPECIAL", "" };
        case TO_BE_DECIDED: return { "TO_BE_DECIDED", "TO_BE_DECIDED", "" };
        default: throw std::out_of_range("value");
    }
}

template <>
TC_API_EXPORT size_t EnumUtils<EncounterState>::Count() { return 6; }

template <>
TC_API_EXPORT EncounterState EnumUtils<EncounterState>::FromIndex(size_t index)
{
    switch (index)
    {
        case 0: return NOT_STARTED;
        case 1: return IN_PROGRESS;
        case 2: return FAIL;
        case 3: return DONE;
        case 4: return SPECIAL;
        case 5: return TO_BE_DECIDED;
        default: throw std::out_of_range("index");
    }
}

template <>
TC_API_EXPORT size_t EnumUtils<EncounterState>::ToIndex(EncounterState value)
{
    switch (value)
    {
        case NOT_STARTED: return 0;
        case IN_PROGRESS: return 1;
        case FAIL: return 2;
        case DONE: return 3;
        case SPECIAL: return 4;
        case TO_BE_DECIDED: return 5;
        default: throw std::out_of_range("value");
    }
}
}
