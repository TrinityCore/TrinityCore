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

#ifndef TRINITY_WAYPOINTMANAGER_H
#define TRINITY_WAYPOINTMANAGER_H

#include <ace/Singleton.h>
#include <ace/Null_Mutex.h>
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

class WaypointStore
{
    private :
        uint32  records;
        UNORDERED_MAP<uint32, WaypointPath*> waypoint_map;

    public:
        // Null Mutex is OK because WaypointMgr is initialized in the World thread before World is initialized
        static WaypointStore* instance() { return ACE_Singleton<WaypointStore, ACE_Null_Mutex>::instance(); }

        ~WaypointStore() { Free(); }
        void UpdatePath(uint32 id);
        void Load();
        void Free();

        WaypointPath* GetPath(uint32 id)
        {
            if (waypoint_map.find(id) != waypoint_map.end())
                return waypoint_map[id];
            else return 0;
        }

        inline uint32 GetRecordsCount() const { return records; }
};

#define sWaypointMgr WaypointStore::instance()

#endif

