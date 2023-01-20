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

#include "UnitAICommon.h"
#include "Define.h"
#include "SmartEnum.h"
#include <stdexcept>

namespace Trinity::Impl::EnumUtilsImpl
{

/******************************************************************\
|* data for enum 'EvadeReason' in 'UnitAICommon.h' auto-generated *|
\******************************************************************/
template <>
TC_API_EXPORT EnumText EnumUtils<EvadeReason>::ToString(EvadeReason value)
{
    switch (value)
    {
        case EvadeReason::NoHostiles: return { "NoHostiles", "NoHostiles", "the creature's threat list is empty" };
        case EvadeReason::Boundary: return { "Boundary", "Boundary", "the creature has moved outside its evade boundary" };
        case EvadeReason::NoPath: return { "NoPath", "NoPath", "the creature was unable to reach its target for over 5 seconds" };
        case EvadeReason::SequenceBreak: return { "SequenceBreak", "SequenceBreak", "this is a boss and the pre-requisite encounters for engaging it are not defeated yet" };
        case EvadeReason::Other: return { "Other", "Other", "anything else" };
        default: throw std::out_of_range("value");
    }
}

template <>
TC_API_EXPORT size_t EnumUtils<EvadeReason>::Count() { return 5; }

template <>
TC_API_EXPORT EvadeReason EnumUtils<EvadeReason>::FromIndex(size_t index)
{
    switch (index)
    {
        case 0: return EvadeReason::NoHostiles;
        case 1: return EvadeReason::Boundary;
        case 2: return EvadeReason::NoPath;
        case 3: return EvadeReason::SequenceBreak;
        case 4: return EvadeReason::Other;
        default: throw std::out_of_range("index");
    }
}

template <>
TC_API_EXPORT size_t EnumUtils<EvadeReason>::ToIndex(EvadeReason value)
{
    switch (value)
    {
        case EvadeReason::NoHostiles: return 0;
        case EvadeReason::Boundary: return 1;
        case EvadeReason::NoPath: return 2;
        case EvadeReason::SequenceBreak: return 3;
        case EvadeReason::Other: return 4;
        default: throw std::out_of_range("value");
    }
}
}
