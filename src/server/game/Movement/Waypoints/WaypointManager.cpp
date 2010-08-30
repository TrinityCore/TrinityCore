/*
 * Copyright (C) 2005-2009 MaNGOS <http://getmangos.com/>
 *
 * Copyright (C) 2008-2010 Trinity <http://www.trinitycore.org/>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
 */

#include "DatabaseEnv.h"
#include "GridDefines.h"
#include "WaypointManager.h"
#include "ProgressBar.h"
#include "MapManager.h"

void WaypointStore::Free()
{
    for (UNORDERED_MAP<uint32, WaypointPath*>::const_iterator itr = waypoint_map.begin(); itr != waypoint_map.end(); ++itr)
    {
        for (WaypointPath::const_iterator it = itr->second->begin(); it != itr->second->end(); ++it)
            delete *it;
        itr->second->clear();
        delete itr->second;
    }
    waypoint_map.clear();
}

void WaypointStore::Load()
{
    QueryResult_AutoPtr result = WorldDatabase.Query("SELECT COUNT(id) FROM waypoint_data");
    if (!result)
    {
        sLog.outError("an error occured while loading the table `waypoint_data` (maybe it doesn't exist ?)");
        exit(1);                                            // Stop server at loading non exited table or not accessable table
    }

    records = (*result)[0].GetUInt32();

    result = WorldDatabase.Query("SELECT id,point,position_x,position_y,position_z,move_flag,delay,action,action_chance FROM waypoint_data ORDER BY id, point");
    if (!result)
    {
        sLog.outErrorDb("The table `waypoint_data` is empty or corrupted");
        return;
    }

    WaypointPath* path_data = NULL;

    barGoLink bar(result->GetRowCount());
    uint32 count = 0;
    Field *fields;
    uint32 last_id = 0;

    do
    {
        fields = result->Fetch();
        uint32 id = fields[0].GetUInt32();
        bar.step();
        count++;
        WaypointData *wp = new WaypointData;

        if (last_id != id)
            path_data = new WaypointPath;

        float x,y,z;
        x = fields[2].GetFloat();
        y = fields[3].GetFloat();
        z = fields[4].GetFloat();

        Trinity::NormalizeMapCoord(x);
        Trinity::NormalizeMapCoord(y);

        wp->id = fields[1].GetUInt32();
        wp->x = x;
        wp->y = y;
        wp->z = z;
        wp->run = fields[5].GetBool();
        wp->delay = fields[6].GetUInt32();
        wp->event_id = fields[7].GetUInt32();
        wp->event_chance = fields[8].GetUInt8();

        path_data->push_back(wp);

        if (id != last_id)
            waypoint_map[id] = path_data;

        last_id = id;

    } while (result->NextRow()) ;

    sLog.outString();
    sLog.outString(">> Loaded %u waypoints", count);
}

void WaypointStore::UpdatePath(uint32 id)
{
    if (waypoint_map.find(id)!= waypoint_map.end())
        waypoint_map[id]->clear();

    QueryResult_AutoPtr result;

    result = WorldDatabase.PQuery("SELECT point,position_x,position_y,position_z,move_flag,delay,action,action_chance FROM waypoint_data WHERE id = %u ORDER BY point", id);

    if (!result)
        return;

    WaypointPath* path_data;
    path_data = new WaypointPath;
    Field *fields;

    do
    {
        fields = result->Fetch();

        WaypointData *wp = new WaypointData;

        float x,y,z;
        x = fields[1].GetFloat();
        y = fields[2].GetFloat();
        z = fields[3].GetFloat();

        Trinity::NormalizeMapCoord(x);
        Trinity::NormalizeMapCoord(y);

        wp->id = fields[0].GetUInt32();
        wp->x = x;
        wp->y = y;
        wp->z = z;
        wp->run = fields[4].GetBool();
        wp->delay = fields[5].GetUInt32();
        wp->event_id = fields[6].GetUInt32();
        wp->event_chance = fields[7].GetUInt8();

        path_data->push_back(wp);

    }
    while (result->NextRow());

    waypoint_map[id] = path_data;
}

