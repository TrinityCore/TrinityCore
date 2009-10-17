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
#ifndef TRINITY_WAYPOINTMANAGER_H
#define TRINITY_WAYPOINTMANAGER_H
#include <vector>
struct WaypointData
{
    uint32 id;
    float x,y,z;
    bool run;
    uint32 delay;
    uint32 event_id;
    uint8 event_chance;
};
typedef std::vector<WaypointData*> WaypointPath;
extern UNORDERED_MAP<uint32, WaypointPath*> waypoint_map;
class WaypointStore
{
    private :
        uint32  records;
    public:
        void UpdatePath(uint32 id);
        void Load();
        void Free();
        WaypointPath* GetPath(uint32 id)
        {
            if(waypoint_map.find(id) != waypoint_map.end())
                return waypoint_map[id];
            else return 0;
        }
        inline uint32 GetRecordsCount() { return records; }
};
extern WaypointStore WaypointMgr;
#endif

