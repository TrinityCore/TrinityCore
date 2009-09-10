/*
 * Copyright (C) 2005-2009 MaNGOS <http://getmangos.com/>
 *
 * Copyright (C) 2008-2009 Trinity <http://www.trinitycore.org/>
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

#include "Database/DatabaseEnv.h"
#include "GridDefines.h"
#include "WaypointManager.h"
#include "ProgressBar.h"
#include "MapManager.h"

WaypointPathMap WaypointPathHolder;
WaypointStore WaypointMgr;

void WaypointStore::Free()
{
    WaypointPathHolder.clear();
}

void WaypointStore::Load()
{
    QueryResult *result = WorldDatabase.PQuery("SELECT COUNT(id) FROM waypoint_data");
    if(!result)
    {
        sLog.outError("an error occured while loading the table `waypoint_data` (maybe it doesn't exist ?)");
        exit(1);                                            // Stop server at loading non exited table or not accessable table
    }

    records = (*result)[0].GetUInt32();
    delete result;

    result = WorldDatabase.PQuery("SELECT id,point,position_x,position_y,position_z,move_flag,delay,action,action_chance FROM waypoint_data ORDER BY id, point");
    if(!result)
    {
        sLog.outErrorDb("The table `waypoint_data` is empty or corrupted");
        return;
    }

    WaypointPath* path_data;
    uint32 total_records = result->GetRowCount();

    barGoLink bar( total_records);
    Field *fields;
    uint32 last_id = 0;

    do
    {
        fields = result->Fetch();
        uint32 id = fields[0].GetUInt32();
        bar.step();
        WaypointData *wp = new WaypointData;

        if(last_id != id)
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

        if(id != last_id)
            WaypointPathHolder[id] = path_data;

        last_id = id;

    } while(result->NextRow()) ;

    delete result;
}

void WaypointStore::UpdatePath(uint32 id)
{
    // Prevent memory leak, deallocate allocated memory instead of just clearing from object holder
    WaypointPathMap::iterator itr = WaypointPathHolder.find(id);
    if(itr != WaypointPathHolder.end())
    {
        for(WaypointPath::iterator jtr = WaypointPathHolder[id]->begin(); jtr != WaypointPathHolder[id]->end(); ++jtr)
        {
            delete (*jtr);
        }
        delete itr->second;
    }
    
    QueryResult *result;

    result = WorldDatabase.PQuery("SELECT id,point,position_x,position_y,position_z,move_flag,delay,action,action_chance FROM waypoint_data WHERE id = %u ORDER BY point", id);

    if(!result)
        return;

    WaypointPath* path_data;
    path_data = new WaypointPath;
    Field *fields;

    do
    {
        fields = result->Fetch();
        uint32 id = fields[0].GetUInt32();

        WaypointData *wp = new WaypointData;

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

    }
    while (result->NextRow());

    WaypointPathHolder[id] = path_data;

    delete result;
}

