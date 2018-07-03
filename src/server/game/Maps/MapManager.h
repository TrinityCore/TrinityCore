/*
 * Copyright (C) 2008-2018 TrinityCore <https://www.trinitycore.org/>
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

#ifndef TRINITY_MAPMANAGER_H
#define TRINITY_MAPMANAGER_H

#include "Object.h"
#include "Map.h"
#include "MapInstanced.h"
#include "GridStates.h"
#include "MapUpdater.h"

class PhaseShift;
class Transport;
struct TransportCreatureProto;

class TC_GAME_API MapManager
{
    public:
        static MapManager* instance();

        Map* CreateBaseMap(uint32 mapId);
        Map* FindBaseNonInstanceMap(uint32 mapId) const;
        Map* CreateMap(uint32 mapId, Player* player, uint32 loginInstanceId=0);
        Map* FindMap(uint32 mapId, uint32 instanceId) const;

        uint32 GetAreaId(PhaseShift const& phaseShift, uint32 mapid, float x, float y, float z) const
        {
            Map const* m = const_cast<MapManager*>(this)->CreateBaseMap(mapid);
            return m->GetAreaId(phaseShift, x, y, z);
        }
        uint32 GetZoneId(PhaseShift const& phaseShift, uint32 mapid, float x, float y, float z) const
        {
            Map const* m = const_cast<MapManager*>(this)->CreateBaseMap(mapid);
            return m->GetZoneId(phaseShift, x, y, z);
        }
        void GetZoneAndAreaId(PhaseShift const& phaseShift, uint32& zoneid, uint32& areaid, uint32 mapid, float x, float y, float z)
        {
            Map const* m = const_cast<MapManager*>(this)->CreateBaseMap(mapid);
            m->GetZoneAndAreaId(phaseShift, zoneid, areaid, x, y, z);
        }

        void Initialize(void);
        void InitializeParentMapData(std::unordered_map<uint32, std::vector<uint32>> const& mapData);
        void Update(uint32);

        void SetGridCleanUpDelay(uint32 t)
        {
            if (t < MIN_GRID_DELAY)
                i_gridCleanUpDelay = MIN_GRID_DELAY;
            else
                i_gridCleanUpDelay = t;
        }

        void SetMapUpdateInterval(uint32 t)
        {
            if (t < MIN_MAP_UPDATE_DELAY)
                t = MIN_MAP_UPDATE_DELAY;

            i_timer.SetInterval(t);
            i_timer.Reset();
        }

        //void LoadGrid(int mapid, int instId, float x, float y, const WorldObject* obj, bool no_unload = false);
        void UnloadAll();

        static bool ExistMapAndVMap(uint32 mapid, float x, float y);
        static bool IsValidMAP(uint32 mapid, bool startUp);

        static bool IsValidMapCoord(uint32 mapid, float x, float y)
        {
            return IsValidMAP(mapid, false) && Trinity::IsValidMapCoord(x, y);
        }

        static bool IsValidMapCoord(uint32 mapid, float x, float y, float z)
        {
            return IsValidMAP(mapid, false) && Trinity::IsValidMapCoord(x, y, z);
        }

        static bool IsValidMapCoord(uint32 mapid, float x, float y, float z, float o)
        {
            return IsValidMAP(mapid, false) && Trinity::IsValidMapCoord(x, y, z, o);
        }

        static bool IsValidMapCoord(WorldLocation const& loc)
        {
            return IsValidMapCoord(loc.GetMapId(), loc.GetPositionX(), loc.GetPositionY(), loc.GetPositionZ(), loc.GetOrientation());
        }

        void DoDelayedMovesAndRemoves();

        Map::EnterState PlayerCannotEnter(uint32 mapid, Player* player, bool loginCheck = false);
        void InitializeVisibilityDistanceInfo();

        /* statistics */
        uint32 GetNumInstances();
        uint32 GetNumPlayersInInstances();

        // Instance ID management
        void InitInstanceIds();
        uint32 GenerateInstanceId();
        void RegisterInstanceId(uint32 instanceId);
        void FreeInstanceId(uint32 instanceId);

        uint32 GetNextInstanceId() const { return _nextInstanceId; };
        void SetNextInstanceId(uint32 nextInstanceId) { _nextInstanceId = nextInstanceId; };

        MapUpdater * GetMapUpdater() { return &m_updater; }

        template<typename Worker>
        void DoForAllMaps(Worker&& worker);

        template<typename Worker>
        void DoForAllMapsWithMapId(uint32 mapId, Worker&& worker);

        void IncreaseScheduledScriptsCount() { ++_scheduledScripts; }
        void DecreaseScheduledScriptCount() { --_scheduledScripts; }
        void DecreaseScheduledScriptCount(std::size_t count) { _scheduledScripts -= count; }
        bool IsScriptScheduled() const { return _scheduledScripts > 0; }

    private:
        typedef std::unordered_map<uint32, Map*> MapMapType;
        typedef std::vector<bool> InstanceIds;

        MapManager();
        ~MapManager();

        Map* FindBaseMap(uint32 mapId) const
        {
            MapMapType::const_iterator iter = i_maps.find(mapId);
            return (iter == i_maps.end() ? NULL : iter->second);
        }

        Map* CreateBaseMap_i(MapEntry const* mapEntry);

        MapManager(MapManager const&) = delete;
        MapManager& operator=(MapManager const&) = delete;

        std::mutex _mapsLock;
        uint32 i_gridCleanUpDelay;
        MapMapType i_maps;
        IntervalTimer i_timer;

        InstanceIds _instanceIds;
        uint32 _nextInstanceId;
        MapUpdater m_updater;

        // atomic op counter for active scripts amount
        std::atomic<std::size_t> _scheduledScripts;

        // parent map links
        std::unordered_map<uint32, std::vector<uint32>> _parentMapData;
};

template<typename Worker>
void MapManager::DoForAllMaps(Worker&& worker)
{
    std::lock_guard<std::mutex> lock(_mapsLock);

    for (auto& mapPair : i_maps)
    {
        Map* map = mapPair.second;
        if (MapInstanced* mapInstanced = map->ToMapInstanced())
        {
            MapInstanced::InstancedMaps& instances = mapInstanced->GetInstancedMaps();
            for (auto& instancePair : instances)
                worker(instancePair.second);
        }
        else
            worker(map);
    }
}

template<typename Worker>
inline void MapManager::DoForAllMapsWithMapId(uint32 mapId, Worker&& worker)
{
    std::lock_guard<std::mutex> lock(_mapsLock);

    auto itr = i_maps.find(mapId);
    if (itr != i_maps.end())
    {
        Map* map = itr->second;
        if (MapInstanced* mapInstanced = map->ToMapInstanced())
        {
            MapInstanced::InstancedMaps& instances = mapInstanced->GetInstancedMaps();
            for (auto& p : instances)
                worker(p.second);
        }
        else
            worker(map);
    }
}

#define sMapMgr MapManager::instance()
#endif
