/*
 * Copyright (C) 2008-2011 TrinityCore <http://www.trinitycore.org/>
 * Copyright (C) 2005-2009 MaNGOS <http://getmangos.com/>
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

#include "DatabaseEnv.h"
#include "GridDefines.h"
#include "WaypointManager.h"
#include "MapManager.h"
#include "Log.h"

WaypointMgr::WaypointMgr()
{
}

WaypointMgr::~WaypointMgr()
{
    for (WaypointPathContainer::iterator itr = _waypointStore.begin(); itr != _waypointStore.end(); ++itr)
    {
        for (WaypointPath::const_iterator it = itr->second.begin(); it != itr->second.end(); ++it)
            delete *it;

        itr->second.clear();
    }

    _waypointStore.clear();
}

void WaypointMgr::Load()
{
    uint32 oldMSTime = getMSTime();

    QueryResult result = WorldDatabase.Query("SELECT id, point, position_x, position_y, position_z, orientation, move_flag, delay, action, action_chance FROM waypoint_data ORDER BY id, point");

    if (!result)
    {
        sLog->outErrorDb(">> Loaded 0 waypoints. DB table `waypoint_data` is empty!");
        sLog->outString();
        return;
    }

    uint32 count = 0;

    do
    {
        Field* fields = result->Fetch();
        WaypointData* wp = new WaypointData();

        uint32 pathId = fields[0].GetUInt32();
        WaypointPath& path = _waypointStore[pathId];

        float x = fields[2].GetFloat();
        float y = fields[3].GetFloat();
        float z = fields[4].GetFloat();
        float o = fields[5].GetFloat();

        Trinity::NormalizeMapCoord(x);
        Trinity::NormalizeMapCoord(y);

        wp->id = fields[1].GetUInt32();
        wp->x = x;
        wp->y = y;
        wp->z = z;
        wp->orientation = o;
        wp->run = fields[6].GetBool();
        wp->delay = fields[7].GetUInt32();
        wp->event_id = fields[8].GetUInt32();
        wp->event_chance = fields[9].GetUInt8();

        path.push_back(wp);
        ++count;
    }
    while (result->NextRow());

    sLog->outString(">> Loaded %u waypoints in %u ms", count, GetMSTimeDiffToNow(oldMSTime));
    sLog->outString();
}

void WaypointMgr::ReloadPath(uint32 id)
{
    WaypointPathContainer::iterator itr = _waypointStore.find(id);
    if (itr != _waypointStore.end())
    {
        for (WaypointPath::const_iterator it = itr->second.begin(); it != itr->second.end(); ++it)
            delete *it;

        _waypointStore.erase(itr);
    }

    QueryResult result = WorldDatabase.PQuery("SELECT point, position_x, position_y, position_z, orientation, move_flag, delay, action, action_chance FROM waypoint_data WHERE id = %u ORDER BY point", id);
    if (!result)
        return;

    WaypointPath& path = _waypointStore[id];

    do
    {
        Field* fields = result->Fetch();
        WaypointData* wp = new WaypointData();

        float x = fields[1].GetFloat();
        float y = fields[2].GetFloat();
        float z = fields[3].GetFloat();
        float o = fields[4].GetFloat();

        Trinity::NormalizeMapCoord(x);
        Trinity::NormalizeMapCoord(y);

        wp->id = fields[0].GetUInt32();
        wp->x = x;
        wp->y = y;
        wp->z = z;
        wp->orientation = o;
        wp->run = fields[5].GetBool();
        wp->delay = fields[6].GetUInt32();
        wp->event_id = fields[7].GetUInt32();
        wp->event_chance = fields[8].GetUInt8();

        path.push_back(wp);

    }
    while (result->NextRow());
}
