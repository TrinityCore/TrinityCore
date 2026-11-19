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
#include "Duration.h"
#include "EnumFlag.h"
#include "Optional.h"
#include <vector>

static inline constexpr std::size_t WAYPOINT_PATH_FLAG_FOLLOW_PATH_BACKWARDS_MINIMUM_NODES = 2;

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
    ExactSplinePath                     = 0x02, // Points are going to be merged into single packets and pathfinding is disabled

    FlyingPath                          = ExactSplinePath   // flying paths are always exact splines
};

DEFINE_ENUM_FLAG(WaypointPathFlags);

struct WaypointNode
{
    constexpr WaypointNode() = default;
    constexpr WaypointNode(uint32 id, float x, float y, float z, Optional<float> orientation = {}, Optional<Milliseconds> delay = {}, Optional<WaypointMoveType> moveType = {})
        : Id(id), X(x), Y(y), Z(z), Orientation(orientation), Delay(delay), MoveType(moveType) { }

    uint32 Id = 0;
    float X = 0.0f;
    float Y = 0.0f;
    float Z = 0.0f;
    Optional<float> Orientation = {};
    Optional<Milliseconds> Delay = {};
    Optional<WaypointMoveType> MoveType = {};
};

struct WaypointPath
{
    WaypointPath() = default;
    WaypointPath(uint32 id, std::vector<WaypointNode>&& nodes, WaypointMoveType moveType = WaypointMoveType::Walk, WaypointPathFlags flags = WaypointPathFlags::None)
        : Nodes(std::move(nodes)), Id(id), MoveType(moveType), Flags(flags) { }

    std::vector<WaypointNode> Nodes;
    std::vector<std::pair<std::size_t, std::size_t>> ContinuousSegments;
    uint32 Id = 0;
    WaypointMoveType MoveType = WaypointMoveType::Walk;
    EnumFlag<WaypointPathFlags> Flags = WaypointPathFlags::None;
    Optional<float> Velocity;

    void BuildSegments();
};

#endif
