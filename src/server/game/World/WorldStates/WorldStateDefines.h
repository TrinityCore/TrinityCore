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

#ifndef WorldStateDefines_h__
#define WorldStateDefines_h__

#include "Define.h"
#include <unordered_map>
#include <unordered_set>

struct WorldStateTemplate
{
    int32 Id = 0;
    int32 DefaultValue = 0;
    uint32 ScriptId = 0;

    std::unordered_set<uint32> MapIds;
    std::unordered_set<uint32> AreaIds;
};

using WorldStateValueContainer = std::unordered_map<int32 /*worldStateId*/, int32 /*value*/>;

#endif // WorldStateDefines_h__
