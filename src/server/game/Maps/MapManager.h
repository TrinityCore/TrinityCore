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

#ifndef TRINITY_MAPMANAGER_H
#define TRINITY_MAPMANAGER_H

#include "GridDefines.h"
#include "IteratorPair.h"
#include "MapUpdater.h"
#include "Position.h"
#include "SharedDefines.h"
#include <boost/dynamic_bitset_fwd.hpp>
#include <map>
#include <shared_mutex>

class Battleground;
class BattlegroundMap;
class Group;
class InstanceLock;
class InstanceMap;
class Map;
class Player;
enum Difficulty : uint8;

class TC_GAME_API MapManager
{
        MapManager();
        ~MapManager();

    public:
        MapManager(MapManager const&) = delete;
        MapManager(MapManager&&) = delete;
        MapManager& operator=(MapManager const&) = delete;
        MapManager& operator=(MapManager&&) = delete;

        static MapManager* instance();

        Map* CreateMap(uint32 mapId, Player* player);
        Map* FindMap(uint32 mapId, uint32 instanceId) const;
        uint32 FindInstanceIdForPlayer(uint32 mapId, Player const* player) const;

        void Initialize();
        void Update(uint32 diff);

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

        void UnloadAll();

        static bool IsValidMAP(uint32 mapId);

        static bool IsValidMapCoord(uint32 mapid, float x, float y)
        {
            return IsValidMAP(mapid) && Trinity::IsValidMapCoord(x, y);
        }

        static bool IsValidMapCoord(uint32 mapid, float x, float y, float z)
        {
            return IsValidMAP(mapid) && Trinity::IsValidMapCoord(x, y, z);
        }

        static bool IsValidMapCoord(uint32 mapid, float x, float y, float z, float o)
        {
            return IsValidMAP(mapid) && Trinity::IsValidMapCoord(x, y, z, o);
        }

        static bool IsValidMapCoord(uint32 mapid, Position const& pos)
        {
            return IsValidMapCoord(mapid, pos.GetPositionX(), pos.GetPositionY(), pos.GetPositionZ(), pos.GetOrientation());
        }

        static bool IsValidMapCoord(WorldLocation const& loc)
        {
            return IsValidMapCoord(loc.GetMapId(), loc);
        }

        void InitializeVisibilityDistanceInfo();

        /* statistics */
        uint32 GetNumInstances() const;
        uint32 GetNumPlayersInInstances() const;

        // Instance ID management
        void InitInstanceIds();
        uint32 GenerateInstanceId();
        void RegisterInstanceId(uint32 instanceId);
        void FreeInstanceId(uint32 instanceId);

        MapUpdater * GetMapUpdater() { return &m_updater; }

        template<typename Worker>
        void DoForAllMaps(Worker&& worker);

        template<typename Worker>
        void DoForAllMapsWithMapId(uint32 mapId, Worker&& worker);

        void IncreaseScheduledScriptsCount() { ++_scheduledScripts; }
        void DecreaseScheduledScriptCount() { --_scheduledScripts; }
        void DecreaseScheduledScriptCount(std::size_t count) { _scheduledScripts -= count; }
        bool IsScriptScheduled() const { return _scheduledScripts > 0; }

        void AddSC_BuiltInScripts();

    private:
        using MapKey = std::pair<uint32, uint32>;
        typedef std::map<MapKey, Map*> MapMapType;
        typedef boost::dynamic_bitset<size_t> InstanceIds;

        Map* FindMap_i(uint32 mapId, uint32 instanceId) const;

        Map* CreateWorldMap(uint32 mapId, uint32 instanceId);
        InstanceMap* CreateInstance(uint32 mapId, uint32 instanceId, InstanceLock* instanceLock, Difficulty difficulty, TeamId team, Group* group);
        BattlegroundMap* CreateBattleground(uint32 mapId, uint32 instanceId, Battleground* bg);

        bool DestroyMap(Map* map);

        mutable std::shared_mutex _mapsLock;
        uint32 i_gridCleanUpDelay;
        MapMapType i_maps;
        IntervalTimer i_timer;

        std::unique_ptr<InstanceIds> _freeInstanceIds;
        uint32 _nextInstanceId;
        MapUpdater m_updater;

        // atomic op counter for active scripts amount
        std::atomic<std::size_t> _scheduledScripts;
};

template<typename Worker>
void MapManager::DoForAllMaps(Worker&& worker)
{
    std::shared_lock<std::shared_mutex> lock(_mapsLock);

    for (auto const& [key, map] : i_maps)
        worker(map);
}

template<typename Worker>
void MapManager::DoForAllMapsWithMapId(uint32 mapId, Worker&& worker)
{
    std::shared_lock<std::shared_mutex> lock(_mapsLock);

    auto range = Trinity::Containers::MakeIteratorPair(
        i_maps.lower_bound({ mapId, 0 }),
        i_maps.upper_bound({ mapId, std::numeric_limits<uint32>::max() })
    );

    for (auto const& [key, map] : range)
        worker(map);
}

#define sMapMgr MapManager::instance()

#endif
