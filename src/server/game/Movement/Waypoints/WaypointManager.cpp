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

#include "WaypointManager.h"
#include "DatabaseEnv.h"
#include "GridDefines.h"
#include "MapManager.h"
#include "Log.h"

void WaypointMgr::Load()
{
    uint32 oldMSTime = getMSTime();

    //                                               0   1      2           3           4           5            6         7          8      9       10
    QueryResult result = WorldDatabase.Query("SELECT id, point, position_x, position_y, position_z, orientation, velocity, move_type, delay, action, action_chance FROM waypoint_data ORDER BY id, point");

    if (!result)
    {
        TC_LOG_INFO("server.loading", ">> Loaded 0 waypoints. DB table `waypoint_data` is empty!");
        return;
    }

    uint32 count = 0;

    do
    {
        Field* fields = result->Fetch();
        uint32 pathId = fields[0].GetUInt32();
        float x = fields[2].GetFloat();
        float y = fields[3].GetFloat();
        float z = fields[4].GetFloat();
        float o = fields[5].GetFloat();
        float velocity = fields[6].GetFloat();

        Trinity::NormalizeMapCoord(x);
        Trinity::NormalizeMapCoord(y);

        WaypointNode waypoint;
        waypoint.Id = fields[1].GetUInt32();
        waypoint.X = x;
        waypoint.Y = y;
        waypoint.Z = z;
        waypoint.Orientation = o;
        waypoint.Velocity = velocity;
        waypoint.MoveType = fields[7].GetUInt32();

        if (waypoint.MoveType >= WAYPOINT_MOVE_TYPE_MAX)
        {
            TC_LOG_ERROR("sql.sql", "Waypoint %u in waypoint_data has invalid move_type, ignoring", waypoint.Id);
            continue;
        }

        waypoint.Delay = fields[8].GetUInt32();
        waypoint.EventId = fields[9].GetUInt32();
        waypoint.EventChance = fields[10].GetInt16();

        WaypointPath& path = _waypointStore[pathId];
        path.Id = pathId;
        path.Nodes.push_back(std::move(waypoint));
        ++count;
    }
    while (result->NextRow());

    TC_LOG_INFO("server.loading", ">> Loaded %u waypoints in %u ms", count, GetMSTimeDiffToNow(oldMSTime));
}

WaypointMgr* WaypointMgr::instance()
{
    static WaypointMgr instance;
    return &instance;
}

void WaypointMgr::ReloadPath(uint32 id)
{
    auto itr = _waypointStore.find(id);
    if (itr != _waypointStore.end())
        _waypointStore.erase(itr);

    WorldDatabasePreparedStatement* stmt = WorldDatabase.GetPreparedStatement(WORLD_SEL_WAYPOINT_DATA_BY_ID);

    stmt->setUInt32(0, id);

    PreparedQueryResult result = WorldDatabase.Query(stmt);

    if (!result)
        return;

    std::vector<WaypointNode> values;
    do
    {
        Field* fields = result->Fetch();
        float x = fields[1].GetFloat();
        float y = fields[2].GetFloat();
        float z = fields[3].GetFloat();
        float o = fields[4].GetFloat();
        float velocity = fields[5].GetFloat();

        Trinity::NormalizeMapCoord(x);
        Trinity::NormalizeMapCoord(y);

        WaypointNode waypoint;
        waypoint.Id = fields[0].GetUInt32();
        waypoint.X = x;
        waypoint.Y = y;
        waypoint.Z = z;
        waypoint.Orientation = o;
        waypoint.Velocity = velocity;
        waypoint.MoveType = fields[6].GetUInt32();

        if (waypoint.MoveType >= WAYPOINT_MOVE_TYPE_MAX)
        {
            TC_LOG_ERROR("sql.sql", "Waypoint %u in waypoint_data has invalid move_type, ignoring", waypoint.Id);
            continue;
        }

        waypoint.Delay = fields[7].GetUInt32();
        waypoint.EventId = fields[8].GetUInt32();
        waypoint.EventChance = fields[9].GetUInt8();

        values.push_back(std::move(waypoint));
    }
    while (result->NextRow());

    _waypointStore[id] = WaypointPath(id, std::move(values));
}

WaypointPath const* WaypointMgr::GetPath(uint32 id) const
{
    auto itr = _waypointStore.find(id);
    if (itr != _waypointStore.end())
        return &itr->second;

    return nullptr;
}
