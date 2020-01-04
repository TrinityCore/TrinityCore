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
#include <vector>

enum WaypointMoveType
{
    WAYPOINT_MOVE_TYPE_WALK,
    WAYPOINT_MOVE_TYPE_RUN,
    WAYPOINT_MOVE_TYPE_LAND,
    WAYPOINT_MOVE_TYPE_TAKEOFF,

    WAYPOINT_MOVE_TYPE_MAX
};

struct WaypointNode
{
    WaypointNode() : id(0), x(0.f), y(0.f), z(0.f), orientation(0.f), delay(0), eventId(0), moveType(WAYPOINT_MOVE_TYPE_RUN), eventChance(0) { }
    WaypointNode(uint32 _id, float _x, float _y, float _z, float _orientation = 0.f, uint32 _delay = 0)
    {
        id = _id;
        x = _x;
        y = _y;
        z = _z;
        orientation = _orientation;
        delay = _delay;
        eventId = 0;
        moveType = WAYPOINT_MOVE_TYPE_WALK;
        eventChance = 100;
    }

    uint32 id;
    float x, y, z, orientation;
    uint32 delay;
    uint32 eventId;
    uint32 moveType;
    uint8 eventChance;
};

struct WaypointPath
{
    WaypointPath() : id(0) { }
    WaypointPath(uint32 _id, std::vector<WaypointNode>&& _nodes)
    {
        id = _id;
        nodes = _nodes;
    }

    std::vector<WaypointNode> nodes;
    uint32 id;
};

#endif
