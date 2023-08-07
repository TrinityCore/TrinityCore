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

#ifndef TERRAIN_MGR_H
#define TERRAIN_MGR_H

#include "Define.h"
#include "Duration.h"
#include "GridDefines.h"
#include "MapDefines.h"
#include "Position.h"
#include "Timer.h"
#include <atomic>
#include <bitset>
#include <memory>
#include <mutex>
#include <unordered_map>
#include <vector>

class DynamicMapTree;
class GridMap;
class PhaseShift;

class TC_GAME_API TerrainInfo
{
public:
    explicit TerrainInfo(uint32 mapId);
    TerrainInfo(TerrainInfo const&) = delete;
    TerrainInfo(TerrainInfo&&) = delete;
    TerrainInfo& operator=(TerrainInfo const&) = delete;
    TerrainInfo& operator=(TerrainInfo&&) = delete;
    ~TerrainInfo();

    uint32 GetId() const { return _mapId; }
    char const* GetMapName() const;

    void DiscoverGridMapFiles();

    static bool ExistMap(uint32 mapid, int32 gx, int32 gy, bool log = true);
    static bool ExistVMap(uint32 mapid, int32 gx, int32 gy);

    bool HasChildTerrainGridFile(uint32 mapId, int32 gx, int32 gy) const;
    void AddChildTerrain(std::shared_ptr<TerrainInfo> childTerrain);

    void LoadMapAndVMap(int32 gx, int32 gy);
    void LoadMMapInstance(uint32 mapId, uint32 instanceId);

private:
    void LoadMapAndVMapImpl(int32 gx, int32 gy);
    void LoadMMapInstanceImpl(uint32 mapId, uint32 instanceId);
    void LoadMap(int32 gx, int32 gy);
    void LoadVMap(int32 gx, int32 gy);
    void LoadMMap(int32 gx, int32 gy);

public:
    void UnloadMap(int32 gx, int32 gy);
    void UnloadMMapInstance(uint32 mapId, uint32 instanceId);

private:
    void UnloadMapImpl(int32 gx, int32 gy);
    void UnloadMMapInstanceImpl(uint32 mapId, uint32 instanceId);

    GridMap* GetGrid(uint32 mapId, float x, float y, bool loadIfMissing = true);

public:
    void CleanUpGrids(uint32 diff);

    void GetFullTerrainStatusForPosition(PhaseShift const& phaseShift, uint32 mapId, float x, float y, float z, PositionFullTerrainStatus& data, map_liquidHeaderTypeFlags reqLiquidType = map_liquidHeaderTypeFlags::AllLiquids, float collisionHeight = 2.03128f); // DEFAULT_COLLISION_HEIGHT in Object.h
    ZLiquidStatus GetLiquidStatus(PhaseShift const& phaseShift, uint32 mapId, float x, float y, float z, map_liquidHeaderTypeFlags ReqLiquidType, LiquidData* data = nullptr, float collisionHeight = 2.03128f); // DEFAULT_COLLISION_HEIGHT in Object.h

    bool GetAreaInfo(PhaseShift const& phaseShift, uint32 mapId, float x, float y, float z, uint32& mogpflags, int32& adtId, int32& rootId, int32& groupId);
    uint32 GetAreaId(PhaseShift const& phaseShift, uint32 mapId, float x, float y, float z);
    uint32 GetAreaId(PhaseShift const& phaseShift, uint32 mapId, Position const& pos) { return GetAreaId(phaseShift, mapId, pos.GetPositionX(), pos.GetPositionY(), pos.GetPositionZ()); }
    uint32 GetZoneId(PhaseShift const& phaseShift, uint32 mapId, float x, float y, float z);
    uint32 GetZoneId(PhaseShift const& phaseShift, uint32 mapId, Position const& pos) { return GetZoneId(phaseShift, mapId, pos.GetPositionX(), pos.GetPositionY(), pos.GetPositionZ()); }
    void GetZoneAndAreaId(PhaseShift const& phaseShift, uint32 mapId, uint32& zoneid, uint32& areaid, float x, float y, float z);
    void GetZoneAndAreaId(PhaseShift const& phaseShift, uint32 mapId, uint32& zoneid, uint32& areaid, Position const& pos) { GetZoneAndAreaId(phaseShift, mapId, zoneid, areaid, pos.GetPositionX(), pos.GetPositionY(), pos.GetPositionZ()); }

    float GetMinHeight(PhaseShift const& phaseShift, uint32 mapId, float x, float y);
    float GetGridHeight(PhaseShift const& phaseShift, uint32 mapId, float x, float y);
    float GetStaticHeight(PhaseShift const& phaseShift, uint32 mapId, float x, float y, float z, bool checkVMap = true, float maxSearchDist = DEFAULT_HEIGHT_SEARCH);
    float GetStaticHeight(PhaseShift const& phaseShift, uint32 mapId, Position const& pos, bool checkVMap = true, float maxSearchDist = DEFAULT_HEIGHT_SEARCH) { return GetStaticHeight(phaseShift, mapId, pos.GetPositionX(), pos.GetPositionY(), pos.GetPositionZ(), checkVMap, maxSearchDist); }

    float GetWaterLevel(PhaseShift const& phaseShift, uint32 mapId, float x, float y);
    bool IsInWater(PhaseShift const& phaseShift, uint32 mapId, float x, float y, float z, LiquidData* data = nullptr);
    bool IsUnderWater(PhaseShift const& phaseShift, uint32 mapId, float x, float y, float z);

    float GetWaterOrGroundLevel(PhaseShift const& phaseShift, uint32 mapId, float x, float y, float z, float* ground = nullptr, bool swim = false, float collisionHeight = 2.03128f, DynamicMapTree const* dynamicMapTree = nullptr); // DEFAULT_COLLISION_HEIGHT in Object.h

private:
        static constexpr int32 GetBitsetIndex(int32 gx, int32 gy) { return gx * MAX_NUMBER_OF_GRIDS + gy; }

    uint32 _mapId;

    TerrainInfo* _parentTerrain;
    std::vector<std::shared_ptr<TerrainInfo>> _childTerrain;

    std::mutex _loadMutex;
    std::unique_ptr<GridMap> _gridMap[MAX_NUMBER_OF_GRIDS][MAX_NUMBER_OF_GRIDS];
    std::atomic<uint16> _referenceCountFromMap[MAX_NUMBER_OF_GRIDS][MAX_NUMBER_OF_GRIDS];
    std::bitset<MAX_NUMBER_OF_GRIDS* MAX_NUMBER_OF_GRIDS> _loadedGrids;
    std::bitset<MAX_NUMBER_OF_GRIDS* MAX_NUMBER_OF_GRIDS> _gridFileExists; // cache what grids are available for this map (not including parent/child maps)

    static constexpr Milliseconds CleanupInterval = 1min;

    // global garbage collection timer
    TimeTracker _cleanupTimer;
};

class TC_GAME_API TerrainMgr
{
    TerrainMgr();
    ~TerrainMgr();
public:
    TerrainMgr(TerrainMgr const&) = delete;
    TerrainMgr(TerrainMgr&&) = delete;
    TerrainMgr& operator=(TerrainMgr const&) = delete;
    TerrainMgr& operator=(TerrainMgr&&) = delete;

    static TerrainMgr& Instance();

    void InitializeParentMapData(std::unordered_map<uint32, std::vector<uint32>> const& mapData);

    std::shared_ptr<TerrainInfo> LoadTerrain(uint32 mapId);
    void UnloadAll();

    void Update(uint32 diff);

    uint32 GetAreaId(PhaseShift const& phaseShift, uint32 mapid, float x, float y, float z);
    uint32 GetAreaId(PhaseShift const& phaseShift, uint32 mapid, Position const& pos) { return GetAreaId(phaseShift, mapid, pos.GetPositionX(), pos.GetPositionY(), pos.GetPositionZ()); }
    uint32 GetAreaId(PhaseShift const& phaseShift, WorldLocation const& loc) { return GetAreaId(phaseShift, loc.GetMapId(), loc); }

    uint32 GetZoneId(PhaseShift const& phaseShift, uint32 mapid, float x, float y, float z);
    uint32 GetZoneId(PhaseShift const& phaseShift, uint32 mapid, Position const& pos) { return GetZoneId(phaseShift, mapid, pos.GetPositionX(), pos.GetPositionY(), pos.GetPositionZ()); }
    uint32 GetZoneId(PhaseShift const& phaseShift, WorldLocation const& loc) { return GetZoneId(phaseShift, loc.GetMapId(), loc); }

    void GetZoneAndAreaId(PhaseShift const& phaseShift, uint32& zoneid, uint32& areaid, uint32 mapid, float x, float y, float z);
    void GetZoneAndAreaId(PhaseShift const& phaseShift, uint32& zoneid, uint32& areaid, uint32 mapid, Position const& pos) { GetZoneAndAreaId(phaseShift, zoneid, areaid, mapid, pos.GetPositionX(), pos.GetPositionY(), pos.GetPositionZ()); }
    void GetZoneAndAreaId(PhaseShift const& phaseShift, uint32& zoneid, uint32& areaid, WorldLocation const& loc) { GetZoneAndAreaId(phaseShift, zoneid, areaid, loc.GetMapId(), loc); }

    static bool ExistMapAndVMap(uint32 mapid, float x, float y);

private:
    std::shared_ptr<TerrainInfo> LoadTerrainImpl(uint32 mapId);

    std::unordered_map<uint32, std::weak_ptr<TerrainInfo>> _terrainMaps;

    // parent map links
    std::unordered_map<uint32, std::vector<uint32>> _parentMapData;
};

#define sTerrainMgr TerrainMgr::Instance()

#endif // TERRAIN_MGR_H
