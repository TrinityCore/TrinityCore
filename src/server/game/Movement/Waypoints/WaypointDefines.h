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

#ifndef TRINITY_WAYPOINTDEFINES_H
#define TRINITY_WAYPOINTDEFINES_H

#include "Define.h"
#include "EnumFlag.h"
#include "Optional.h"
#include <vector>

#define WAYPOINT_PATH_FLAG_FOLLOW_PATH_BACKWARDS_MINIMUM_NODES 2

enum class WaypointMoveType : uint8
{
    Walk        = 0,
    Run         = 1,
    Land        = 2,
    TakeOff     = 3,

    Max
};

enum class WaypointPathFlags : uint8
{
    None                                = 0x00,
    FollowPathBackwardsFromEndToStart   = 0x01,
};

DEFINE_ENUM_FLAG(WaypointPathFlags);

struct WaypointNode
{
    WaypointNode() : Id(0), X(0.f), Y(0.f), Z(0.f), Delay(0), MoveType(WaypointMoveType::Walk) { }
    WaypointNode(uint32 id, float x, float y, float z, Optional<float> orientation = { }, uint32 delay = 0)
    {
        Id = id;
        X = x;
        Y = y;
        Z = z;
        Orientation = orientation;
        Delay = delay;
        MoveType = WaypointMoveType::Walk;
    }

    uint32 Id;
    float X;
    float Y;
    float Z;
    Optional<float> Orientation;
    uint32 Delay;
    WaypointMoveType MoveType;
};

struct WaypointPath
{
    WaypointPath() = default;
    WaypointPath(uint32 id, std::vector<WaypointNode>&& nodes, WaypointMoveType moveType = WaypointMoveType::Walk, WaypointPathFlags flags = WaypointPathFlags::None)
    {
        Id = id;
        Nodes = std::move(nodes);
        Flags = flags;
        MoveType = moveType;
    }

    std::vector<WaypointNode> Nodes;
    uint32 Id = 0;
    WaypointMoveType MoveType = WaypointMoveType::Walk;
    EnumFlag<WaypointPathFlags> Flags = WaypointPathFlags::None;
    Optional<float> Velocity;
};

#endif
