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

#ifndef SpellPacketsCommon_h__
#define SpellPacketsCommon_h__

#include "ObjectGuid.h"
#include "Optional.h"
#include "MovementInfo.h"
#include "Position.h"
#include "SharedDefines.h"
#include <array>

namespace WorldPackets
{
    namespace Spells
    {
        struct TargetLocation
        {
            ObjectGuid Transport;
            Position Location;
        };

        struct SpellTargetData
        {
            uint32 Flags = 0;
            Optional<ObjectGuid> Unit;
            Optional<ObjectGuid> Item;
            Optional<TargetLocation> SrcLocation;
            Optional<TargetLocation> DstLocation;
            Optional<std::string> Name;
        };

        struct MissileTrajectoryRequest
        {
            float Pitch = 0.0f;
            float Speed = 0.0f;
        };

        struct SpellWeight
        {
            uint8 Type = 0;
            int32 ID = 0;
            uint32 Quantity = 0;
        };

        struct SpellCastRequest
        {
            uint8 CastID = 0;
            uint8 SendCastFlags = 0;
            int32 SpellID = 0;
            int32 Misc = 0;
            SpellTargetData Target;
            MissileTrajectoryRequest MissileTrajectory;
            Optional<MovementInfo> MoveUpdate;
            std::vector<SpellWeight> Weight;
        };
    }
}

#endif
