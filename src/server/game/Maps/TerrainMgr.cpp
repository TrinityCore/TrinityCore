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

#include "TerrainMgr.h"
#include "DB2Stores.h"
#include "DisableMgr.h"
#include "DynamicTree.h"
#include "GridMap.h"
#include "Log.h"
#include "Memory.h"
#include "MMapFactory.h"
#include "PhasingHandler.h"
#include "Random.h"
#include "ScriptMgr.h"
#include "Util.h"
#include "VMapFactory.h"
#include "VMapManager2.h"
#include "World.h"
#include <G3D/g3dmath.h>

TerrainInfo::TerrainInfo(uint32 mapId) : _mapId(mapId), _parentTerrain(nullptr), _cleanupTimer(randtime(CleanupInterval / 2, CleanupInterval))
{
}

TerrainInfo::~TerrainInfo()
{
    VMAP::VMapFactory::createOrGetVMapManager()->unloadMap(GetId());
    MMAP::MMapFactory::createOrGetMMapManager()->unloadMap(GetId());
}

char const* TerrainInfo::GetMapName() const
{
    return sMapStore.AssertEntry(GetId())->MapName[sWorld->GetDefaultDbcLocale()];
}

void TerrainInfo::DiscoverGridMapFiles()
{
    std::string tileListName = Trinity::StringFormat("{}maps/{:04}.tilelist", sWorld->GetDataPath(), GetId());
    // tile list is optional
    if (auto tileList = Trinity::make_unique_ptr_with_deleter(fopen(tileListName.c_str(), "rb"), &::fclose))
    {
        u_map_magic mapMagic = { };
        uint32 versionMagic = { };
        uint32 build;
        char tilesData[MAX_NUMBER_OF_GRIDS * MAX_NUMBER_OF_GRIDS] = { };
        if (fread(mapMagic.data(), mapMagic.size(), 1, tileList.get()) == 1
            && mapMagic == MapMagic
            && fread(&versionMagic, sizeof(versionMagic), 1, tileList.get()) == 1
            && versionMagic == MapVersionMagic
            && fread(&build, sizeof(build), 1, tileList.get()) == 1
            && fread(&tilesData[0], MAX_NUMBER_OF_GRIDS * MAX_NUMBER_OF_GRIDS, 1, tileList.get()) == 1)
        {
            _gridFileExists = std::bitset<MAX_NUMBER_OF_GRIDS* MAX_NUMBER_OF_GRIDS>(tilesData, std::size(tilesData));
            return;
        }
    }

    for (int32 gx = 0; gx < MAX_NUMBER_OF_GRIDS; ++gx)
        for (int32 gy = 0; gy < MAX_NUMBER_OF_GRIDS; ++gy)
            _gridFileExists[GetBitsetIndex(gx, gy)] = ExistMap(GetId(), gx, gy, false);
}

bool TerrainInfo::ExistMap(uint32 mapid, int32 gx, int32 gy, bool log /*= true*/)
{
    std::string fileName = Trinity::StringFormat("{}maps/{:04}_{:02}_{:02}.map", sWorld->GetDataPath(), mapid, gx, gy);

    bool ret = false;
    auto file = Trinity::make_unique_ptr_with_deleter(fopen(fileName.c_str(), "rb"), &::fclose);
    if (!file)
    {
        if (log)
        {
            TC_LOG_ERROR("maps", "Map file '{}' does not exist!", fileName);
            TC_LOG_ERROR("maps", "Please place MAP-files (*.map) in the appropriate directory ({}), or correct the DataDir setting in your worldserver.conf file.", (sWorld->GetDataPath() + "maps/"));
        }
    }
    else
    {
        map_fileheader header{ };
        if (fread(&header, sizeof(header), 1, file.get()) == 1)
        {
            if (header.mapMagic != MapMagic || header.versionMagic != MapVersionMagic)
            {
                if (log)
                    TC_LOG_ERROR("maps", "Map file '{}' is from an incompatible map version (%.*s v{}), %.*s v{} is expected. Please pull your source, recompile tools and recreate maps using the updated mapextractor, then replace your old map files with new files. If you still have problems search on forum for error TCE00018.",
                        fileName, 4, header.mapMagic.data(), header.versionMagic, 4, MapMagic.data(), MapVersionMagic);
            }
            else
                ret = true;
        }
    }

    return ret;
}

bool TerrainInfo::ExistVMap(uint32 mapid, int32 gx, int32 gy)
{
    if (VMAP::IVMapManager* vmgr = VMAP::VMapFactory::createOrGetVMapManager())
    {
        if (vmgr->isMapLoadingEnabled())
        {
            VMAP::LoadResult result = vmgr->existsMap((sWorld->GetDataPath() + "vmaps").c_str(), mapid, gx, gy);
            std::string name = vmgr->getDirFileName(mapid, gx, gy);
            switch (result)
            {
                case VMAP::LoadResult::Success:
                    break;
                case VMAP::LoadResult::FileNotFound:
                    TC_LOG_ERROR("maps", "VMap file '{}' does not exist", (sWorld->GetDataPath() + "vmaps/" + name));
                    TC_LOG_ERROR("maps", "Please place VMAP files (*.vmtree and *.vmtile) in the vmap directory ({}), or correct the DataDir setting in your worldserver.conf file.", (sWorld->GetDataPath() + "vmaps/"));
                    return false;
                case VMAP::LoadResult::VersionMismatch:
                    TC_LOG_ERROR("maps", "VMap file '{}' couldn't be loaded", (sWorld->GetDataPath() + "vmaps/" + name));
                    TC_LOG_ERROR("maps", "This is because the version of the VMap file and the version of this module are different, please re-extract the maps with the tools compiled with this module.");
                    return false;
                case VMAP::LoadResult::ReadFromFileFailed:
                    TC_LOG_ERROR("maps", "VMap file '{}' couldn't be loaded", (sWorld->GetDataPath() + "vmaps/" + name));
                    TC_LOG_ERROR("maps", "This is because VMAP files are corrupted, please re-extract the maps with the tools compiled with this module.");
                    return false;
                case VMAP::LoadResult::DisabledInConfig:
                    TC_LOG_ERROR("maps", "VMap file '{}' couldn't be loaded", (sWorld->GetDataPath() + "vmaps/" + name));
                    TC_LOG_ERROR("maps", "This is because VMAP is disabled in config file.");
                    return false;
            }
        }
    }

    return true;
}

bool TerrainInfo::HasChildTerrainGridFile(uint32 mapId, int32 gx, int32 gy) const
{
    auto childMapItr = std::find_if(_childTerrain.begin(), _childTerrain.end(), [mapId](std::shared_ptr<TerrainInfo> const& childTerrain) { return childTerrain->GetId() == mapId; });
    return childMapItr != _childTerrain.end() && (*childMapItr)->_gridFileExists[GetBitsetIndex(gx, gy)];
}

void TerrainInfo::AddChildTerrain(std::shared_ptr<TerrainInfo> childTerrain)
{
    childTerrain->_parentTerrain = this;
    _childTerrain.emplace_back(std::move(childTerrain));
}

void TerrainInfo::LoadMapAndVMap(int32 gx, int32 gy)
{
    if (++_referenceCountFromMap[gx][gy] != 1)    // check if already loaded
        return;

    std::lock_guard<std::mutex> lock(_loadMutex);
    LoadMapAndVMapImpl(gx, gy);
}

void TerrainInfo::LoadMMapInstance(uint32 mapId, uint32 instanceId)
{
    LoadMMapInstanceImpl(mapId, instanceId);

    for (std::shared_ptr<TerrainInfo> const& childTerrain : _childTerrain)
        childTerrain->LoadMMapInstanceImpl(mapId, instanceId);
}

void TerrainInfo::LoadMapAndVMapImpl(int32 gx, int32 gy)
{
    LoadMap(gx, gy);
    LoadVMap(gx, gy);
    LoadMMap(gx, gy);

    for (std::shared_ptr<TerrainInfo> const& childTerrain : _childTerrain)
        childTerrain->LoadMapAndVMapImpl(gx, gy);

    _loadedGrids[GetBitsetIndex(gx, gy)] = true;
}

void TerrainInfo::LoadMMapInstanceImpl(uint32 mapId, uint32 instanceId)
{
    MMAP::MMapFactory::createOrGetMMapManager()->loadMapInstance(sWorld->GetDataPath(), _mapId, mapId, instanceId);
}

void TerrainInfo::LoadMap(int32 gx, int32 gy)
{
    if (_gridMap[gx][gy])
        return;

    if (!_gridFileExists[GetBitsetIndex(gx, gy)])
        return;

    // map file name
    std::string fileName = Trinity::StringFormat("{}maps/{:04}_{:02}_{:02}.map", sWorld->GetDataPath(), GetId(), gx, gy);
    TC_LOG_DEBUG("maps", "Loading map {}", fileName);
    // loading data
    std::unique_ptr<GridMap> gridMap = std::make_unique<GridMap>();
    GridMap::LoadResult gridMapLoadResult = gridMap->loadData(fileName.c_str());
    if (gridMapLoadResult == GridMap::LoadResult::Ok)
        _gridMap[gx][gy] = std::move(gridMap);
    else
        _gridFileExists[GetBitsetIndex(gx, gy)] = false;

    if (gridMapLoadResult == GridMap::LoadResult::InvalidFile)
        TC_LOG_ERROR("maps", "Error loading map file: {}", fileName);
}

void TerrainInfo::LoadVMap(int32 gx, int32 gy)
{
    if (!VMAP::VMapFactory::createOrGetVMapManager()->isMapLoadingEnabled())
        return;
                                                            // x and y are swapped !!
    VMAP::LoadResult vmapLoadResult = VMAP::VMapFactory::createOrGetVMapManager()->loadMap((sWorld->GetDataPath() + "vmaps").c_str(), GetId(), gx, gy);
    switch (vmapLoadResult)
    {
        case VMAP::LoadResult::Success:
            TC_LOG_DEBUG("maps", "VMAP loaded name:{}, id:{}, x:{}, y:{} (vmap rep.: x:{}, y:{})", GetMapName(), GetId(), gx, gy, gx, gy);
            break;
        case VMAP::LoadResult::VersionMismatch:
        case VMAP::LoadResult::ReadFromFileFailed:
            TC_LOG_ERROR("maps", "Could not load VMAP name:{}, id:{}, x:{}, y:{} (vmap rep.: x:{}, y:{})", GetMapName(), GetId(), gx, gy, gx, gy);
            break;
        case VMAP::LoadResult::DisabledInConfig:
            TC_LOG_DEBUG("maps", "Ignored VMAP name:{}, id:{}, x:{}, y:{} (vmap rep.: x:{}, y:{})", GetMapName(), GetId(), gx, gy, gx, gy);
            break;
        default:
            break;
    }
}

void TerrainInfo::LoadMMap(int32 gx, int32 gy)
{
    if (!DisableMgr::IsPathfindingEnabled(GetId()))
        return;

    bool mmapLoadResult = MMAP::MMapFactory::createOrGetMMapManager()->loadMap(sWorld->GetDataPath(), GetId(), gx, gy);

    if (mmapLoadResult)
        TC_LOG_DEBUG("mmaps.tiles", "MMAP loaded name:{}, id:{}, x:{}, y:{} (mmap rep.: x:{}, y:{})", GetMapName(), GetId(), gx, gy, gx, gy);
    else
        TC_LOG_WARN("mmaps.tiles", "Could not load MMAP name:{}, id:{}, x:{}, y:{} (mmap rep.: x:{}, y:{})", GetMapName(), GetId(), gx, gy, gx, gy);
}

void TerrainInfo::UnloadMap(int32 gx, int32 gy)
{
    --_referenceCountFromMap[gx][gy];
    // unload later
}

void TerrainInfo::UnloadMMapInstance(uint32 mapId, uint32 instanceId)
{
    UnloadMMapInstanceImpl(mapId, instanceId);

    for (std::shared_ptr<TerrainInfo> const& childTerrain : _childTerrain)
        childTerrain->UnloadMMapInstanceImpl(mapId, instanceId);
}

void TerrainInfo::UnloadMapImpl(int32 gx, int32 gy)
{
    _gridMap[gx][gy] = nullptr;
    VMAP::VMapFactory::createOrGetVMapManager()->unloadMap(GetId(), gx, gy);
    MMAP::MMapFactory::createOrGetMMapManager()->unloadMap(GetId(), gx, gy);

    for (std::shared_ptr<TerrainInfo> const& childTerrain : _childTerrain)
        childTerrain->UnloadMapImpl(gx, gy);

    _loadedGrids[GetBitsetIndex(gx, gy)] = false;
}

void TerrainInfo::UnloadMMapInstanceImpl(uint32 mapId, uint32 instanceId)
{
    MMAP::MMapFactory::createOrGetMMapManager()->unloadMapInstance(_mapId, mapId, instanceId);
}

GridMap* TerrainInfo::GetGrid(uint32 mapId, float x, float y, bool loadIfMissing /*= true*/)
{
    // half opt method
    int32 gx = (int)(CENTER_GRID_ID - x / SIZE_OF_GRIDS);                   //grid x
    int32 gy = (int)(CENTER_GRID_ID - y / SIZE_OF_GRIDS);                   //grid y

    // ensure GridMap is loaded
    if (!_loadedGrids[GetBitsetIndex(gx, gy)] && loadIfMissing)
    {
        std::lock_guard<std::mutex> lock(_loadMutex);
        LoadMapAndVMapImpl(gx, gy);
    }

    GridMap* grid = _gridMap[gx][gy].get();
    if (mapId != GetId())
    {
        auto childMapItr = std::find_if(_childTerrain.begin(), _childTerrain.end(), [mapId](std::shared_ptr<TerrainInfo> const& childTerrain) { return childTerrain->GetId() == mapId; });
        if (childMapItr != _childTerrain.end() && (*childMapItr)->_gridMap[gx][gy])
            grid = (*childMapItr)->GetGrid(mapId, x, y, false);
    }

    return grid;
}

void TerrainInfo::CleanUpGrids(uint32 diff)
{
    _cleanupTimer.Update(diff);
    if (!_cleanupTimer.Passed())
        return;

    // delete those GridMap objects which have refcount = 0
    for (int32 x = 0; x < MAX_NUMBER_OF_GRIDS; ++x)
        for (int32 y = 0; y < MAX_NUMBER_OF_GRIDS; ++y)
            if (_loadedGrids[GetBitsetIndex(x, y)] && !_referenceCountFromMap[x][y])
                UnloadMapImpl(x, y);

    _cleanupTimer.Reset(CleanupInterval);
}

static bool IsInWMOInterior(uint32 mogpFlags)
{
    return (mogpFlags & 0x2000) != 0;
}

void TerrainInfo::GetFullTerrainStatusForPosition(PhaseShift const& phaseShift, uint32 mapId, float x, float y, float z, PositionFullTerrainStatus& data, map_liquidHeaderTypeFlags reqLiquidType, float collisionHeight, DynamicMapTree const* dynamicMapTree)
{
    VMAP::IVMapManager* vmgr = VMAP::VMapFactory::createOrGetVMapManager();
    VMAP::AreaAndLiquidData vmapData;
    VMAP::AreaAndLiquidData dynData;
    VMAP::AreaAndLiquidData* wmoData = nullptr;
    uint32 terrainMapId = PhasingHandler::GetTerrainMapId(phaseShift, mapId, this, x, y);
    GridMap* gmap = GetGrid(terrainMapId, x, y);
    vmgr->getAreaAndLiquidData(terrainMapId, x, y, z, AsUnderlyingType(reqLiquidType), vmapData);
    if (dynamicMapTree)
        dynamicMapTree->getAreaAndLiquidData(x, y, z, phaseShift, AsUnderlyingType(reqLiquidType), dynData);

    uint32 gridAreaId = 0;
    float gridMapHeight = INVALID_HEIGHT;
    if (gmap)
    {
        gridAreaId = gmap->getArea(x, y);
        gridMapHeight = gmap->getHeight(x, y);
    }

    bool useGridLiquid = true;

    // floor is the height we are closer to (but only if above)
    data.floorZ = VMAP_INVALID_HEIGHT;
    if (gridMapHeight > INVALID_HEIGHT && G3D::fuzzyGe(z, gridMapHeight - GROUND_HEIGHT_TOLERANCE))
        data.floorZ = gridMapHeight;
    if (vmapData.floorZ > VMAP_INVALID_HEIGHT &&
        G3D::fuzzyGe(z, vmapData.floorZ - GROUND_HEIGHT_TOLERANCE) &&
        (G3D::fuzzyLt(z, gridMapHeight - GROUND_HEIGHT_TOLERANCE) || vmapData.floorZ > gridMapHeight))
    {
        data.floorZ = vmapData.floorZ;
        wmoData = &vmapData;
    }
    // NOTE: Objects will not detect a case when a wmo providing area/liquid despawns from under them
    // but this is fine as these kind of objects are not meant to be spawned and despawned a lot
    // example: Lich King platform
    if (dynData.floorZ > VMAP_INVALID_HEIGHT &&
        G3D::fuzzyGe(z, dynData.floorZ - GROUND_HEIGHT_TOLERANCE) &&
        (G3D::fuzzyLt(z, gridMapHeight - GROUND_HEIGHT_TOLERANCE) || dynData.floorZ > gridMapHeight) &&
        (G3D::fuzzyLt(z, vmapData.floorZ - GROUND_HEIGHT_TOLERANCE) || dynData.floorZ > vmapData.floorZ))
    {
        data.floorZ = dynData.floorZ;
        wmoData = &dynData;
    }

    if (wmoData)
    {
        if (wmoData->areaInfo)
        {
            data.areaInfo.emplace(wmoData->areaInfo->adtId, wmoData->areaInfo->rootId, wmoData->areaInfo->groupId, wmoData->areaInfo->mogpFlags);
            // wmo found
            WMOAreaTableEntry const* wmoEntry = sDB2Manager.GetWMOAreaTable(wmoData->areaInfo->rootId, wmoData->areaInfo->adtId, wmoData->areaInfo->groupId);
            if (!wmoEntry)
                wmoEntry = sDB2Manager.GetWMOAreaTable(wmoData->areaInfo->rootId, wmoData->areaInfo->adtId, -1);

            data.outdoors = (wmoData->areaInfo->mogpFlags & 0x8) != 0;
            if (wmoEntry)
            {
                data.areaId = wmoEntry->AreaTableID;
                if (wmoEntry->Flags & 4)
                    data.outdoors = true;
                else if (wmoEntry->Flags & 2)
                    data.outdoors = false;
            }

            if (!data.areaId)
                data.areaId = gridAreaId;

            useGridLiquid = !IsInWMOInterior(wmoData->areaInfo->mogpFlags);
        }
    }
    else
    {
        data.outdoors = true;
        data.areaId = gridAreaId;
        if (AreaTableEntry const* areaEntry = sAreaTableStore.LookupEntry(data.areaId))
            data.outdoors = areaEntry->GetFlags().HasFlag(AreaFlags::ForceOutdoors) || !areaEntry->GetFlags().HasFlag(AreaFlags::ForceIndoors);
    }

    if (!data.areaId)
        data.areaId = sMapStore.AssertEntry(GetId())->AreaTableID;

    AreaTableEntry const* areaEntry = sAreaTableStore.LookupEntry(data.areaId);

    // liquid processing
    data.liquidStatus = LIQUID_MAP_NO_WATER;
    if (wmoData && wmoData->liquidInfo && wmoData->liquidInfo->level > wmoData->floorZ)
    {
        uint32 liquidType = wmoData->liquidInfo->type;
        if (GetId() == 530 && liquidType == 2) // gotta love hacks
            liquidType = 15;

        uint32 liquidFlagType = 0;
        if (LiquidTypeEntry const* liquidData = sLiquidTypeStore.LookupEntry(liquidType))
            liquidFlagType = liquidData->SoundBank;

        if (liquidType && liquidType < 21 && areaEntry)
        {
            uint32 overrideLiquid = areaEntry->LiquidTypeID[liquidFlagType];
            if (!overrideLiquid && areaEntry->ParentAreaID)
            {
                AreaTableEntry const* zoneEntry = sAreaTableStore.LookupEntry(areaEntry->ParentAreaID);
                if (zoneEntry)
                    overrideLiquid = zoneEntry->LiquidTypeID[liquidFlagType];
            }

            if (LiquidTypeEntry const* overrideData = sLiquidTypeStore.LookupEntry(overrideLiquid))
            {
                liquidType = overrideLiquid;
                liquidFlagType = overrideData->SoundBank;
            }
        }

        data.liquidInfo.emplace();
        data.liquidInfo->level = wmoData->liquidInfo->level;
        data.liquidInfo->depth_level = wmoData->floorZ;
        data.liquidInfo->entry = liquidType;
        data.liquidInfo->type_flags = map_liquidHeaderTypeFlags(1 << liquidFlagType);

        float delta = wmoData->liquidInfo->level - z;
        uint32 status = LIQUID_MAP_ABOVE_WATER;
        if (delta > collisionHeight)
            status = LIQUID_MAP_UNDER_WATER;
        else if (delta > 0.0f)
            status = LIQUID_MAP_IN_WATER;
        else if (delta > -0.1f)
            status = LIQUID_MAP_WATER_WALK;

        if (status != LIQUID_MAP_ABOVE_WATER)
            if (std::fabs(wmoData->floorZ - z) <= GROUND_HEIGHT_TOLERANCE)
                status |= LIQUID_MAP_OCEAN_FLOOR;

        data.liquidStatus = static_cast<ZLiquidStatus>(status);
    }
    // look up liquid data from grid map
    if (gmap && useGridLiquid)
    {
        LiquidData gridMapLiquid;
        ZLiquidStatus gridMapStatus = gmap->GetLiquidStatus(x, y, z, reqLiquidType, &gridMapLiquid, collisionHeight);
        if (gridMapStatus != LIQUID_MAP_NO_WATER && (!wmoData || gridMapLiquid.level > wmoData->floorZ))
        {
            if (GetId() == 530 && gridMapLiquid.entry == 2)
                gridMapLiquid.entry = 15;
            data.liquidInfo = gridMapLiquid;
            data.liquidStatus = gridMapStatus;
        }
    }
}

ZLiquidStatus TerrainInfo::GetLiquidStatus(PhaseShift const& phaseShift, uint32 mapId, float x, float y, float z, map_liquidHeaderTypeFlags ReqLiquidType, LiquidData* data, float collisionHeight)
{
    ZLiquidStatus result = LIQUID_MAP_NO_WATER;
    VMAP::IVMapManager* vmgr = VMAP::VMapFactory::createOrGetVMapManager();
    float liquid_level = INVALID_HEIGHT;
    float ground_level = INVALID_HEIGHT;
    uint32 liquid_type = 0;
    uint32 mogpFlags = 0;
    bool useGridLiquid = true;
    uint32 terrainMapId = PhasingHandler::GetTerrainMapId(phaseShift, mapId, this, x, y);
    if (vmgr->GetLiquidLevel(terrainMapId, x, y, z, AsUnderlyingType(ReqLiquidType), liquid_level, ground_level, liquid_type, mogpFlags))
    {
        useGridLiquid = !IsInWMOInterior(mogpFlags);
        TC_LOG_DEBUG("maps", "GetLiquidStatus(): vmap liquid level: {} ground: {} type: {}", liquid_level, ground_level, liquid_type);
        // Check water level and ground level
        if (liquid_level > ground_level && G3D::fuzzyGe(z, ground_level - GROUND_HEIGHT_TOLERANCE))
        {
            // All ok in water -> store data
            if (data)
            {
                // hardcoded in client like this
                if (GetId() == 530 && liquid_type == 2)
                    liquid_type = 15;

                uint32 liquidFlagType = 0;
                if (LiquidTypeEntry const* liq = sLiquidTypeStore.LookupEntry(liquid_type))
                    liquidFlagType = liq->SoundBank;

                if (liquid_type && liquid_type < 21)
                {
                    if (AreaTableEntry const* area = sAreaTableStore.LookupEntry(GetAreaId(phaseShift, mapId, x, y, z)))
                    {
                        uint32 overrideLiquid = area->LiquidTypeID[liquidFlagType];
                        if (!overrideLiquid && area->ParentAreaID)
                        {
                            area = sAreaTableStore.LookupEntry(area->ParentAreaID);
                            if (area)
                                overrideLiquid = area->LiquidTypeID[liquidFlagType];
                        }

                        if (LiquidTypeEntry const* liq = sLiquidTypeStore.LookupEntry(overrideLiquid))
                        {
                            liquid_type = overrideLiquid;
                            liquidFlagType = liq->SoundBank;
                        }
                    }
                }

                data->level = liquid_level;
                data->depth_level = ground_level;

                data->entry = liquid_type;
                data->type_flags = map_liquidHeaderTypeFlags(1 << liquidFlagType);
            }

            float delta = liquid_level - z;

            // Get position delta
            uint32 status = LIQUID_MAP_ABOVE_WATER;
            if (delta > collisionHeight)            // Under water
                status = LIQUID_MAP_UNDER_WATER;
            else if (delta > 0.0f)                  // In water
                status = LIQUID_MAP_IN_WATER;
            else if (delta > -0.1f)                 // Walk on water
                status = LIQUID_MAP_WATER_WALK;

            if (status != LIQUID_MAP_ABOVE_WATER)
            {
                if (status != LIQUID_MAP_ABOVE_WATER)
                    if (std::fabs(ground_level - z) <= GROUND_HEIGHT_TOLERANCE)
                        status |= LIQUID_MAP_OCEAN_FLOOR;

                return static_cast<ZLiquidStatus>(status);
            }

            result = LIQUID_MAP_ABOVE_WATER;
        }
    }

    if (useGridLiquid)
    {
        if (GridMap const* gmap = GetGrid(terrainMapId, x, y))
        {
            LiquidData map_data;
            ZLiquidStatus map_result = gmap->GetLiquidStatus(x, y, z, ReqLiquidType, &map_data, collisionHeight);
            // Not override LIQUID_MAP_ABOVE_WATER with LIQUID_MAP_NO_WATER:
            if (map_result != LIQUID_MAP_NO_WATER && (map_data.level > ground_level))
            {
                if (data)
                {
                    // hardcoded in client like this
                    if (GetId() == 530 && map_data.entry == 2)
                        map_data.entry = 15;

                    *data = map_data;
                }
                return map_result;
            }
        }
    }
    return result;
}

bool TerrainInfo::GetAreaInfo(PhaseShift const& phaseShift, uint32 mapId, float x, float y, float z, uint32& mogpflags, int32& adtId, int32& rootId, int32& groupId, DynamicMapTree const* dynamicMapTree)
{
    float vmap_z = z;
    float dynamic_z = z;
    float check_z = z;
    uint32 terrainMapId = PhasingHandler::GetTerrainMapId(phaseShift, mapId, this, x, y);
    VMAP::IVMapManager* vmgr = VMAP::VMapFactory::createOrGetVMapManager();
    uint32 vflags;
    int32 vadtId;
    int32 vrootId;
    int32 vgroupId;
    uint32 dflags;
    int32 dadtId;
    int32 drootId;
    int32 dgroupId;

    bool hasVmapAreaInfo = vmgr->getAreaInfo(terrainMapId, x, y, vmap_z, vflags, vadtId, vrootId, vgroupId);
    bool hasDynamicAreaInfo = dynamicMapTree ? dynamicMapTree->getAreaInfo(x, y, dynamic_z, phaseShift, dflags, dadtId, drootId, dgroupId) : false;
    auto useVmap = [&]() { check_z = vmap_z; mogpflags = vflags; adtId = vadtId; rootId = vrootId; groupId = vgroupId; };
    auto useDyn = [&]() { check_z = dynamic_z; mogpflags = dflags; adtId = dadtId; rootId = drootId; groupId = dgroupId; };

    if (hasVmapAreaInfo)
    {
        if (hasDynamicAreaInfo && dynamic_z > vmap_z)
            useDyn();
        else
            useVmap();
    }
    else if (hasDynamicAreaInfo)
    {
        useDyn();
    }

    if (hasVmapAreaInfo || hasDynamicAreaInfo)
    {
        // check if there's terrain between player height and object height
        if (GridMap* gmap = GetGrid(terrainMapId, x, y))
        {
            float mapHeight = gmap->getHeight(x, y);
            // z + 2.0f condition taken from GetHeight(), not sure if it's such a great choice...
            if (z + 2.0f > mapHeight && mapHeight > check_z)
                return false;
        }
        return true;
    }
    return false;
}

uint32 TerrainInfo::GetAreaId(PhaseShift const& phaseShift, uint32 mapId, float x, float y, float z, DynamicMapTree const* dynamicMapTree)
{
    uint32 mogpFlags;
    int32 adtId, rootId, groupId;
    float vmapZ = z;
    bool hasVmapArea = GetAreaInfo(phaseShift, mapId, x, y, vmapZ, mogpFlags, adtId, rootId, groupId, dynamicMapTree);

    uint32 gridAreaId = 0;
    float gridMapHeight = INVALID_HEIGHT;
    if (GridMap* gmap = GetGrid(PhasingHandler::GetTerrainMapId(phaseShift, mapId, this, x, y), x, y))
    {
        gridAreaId = gmap->getArea(x, y);
        gridMapHeight = gmap->getHeight(x, y);
    }

    uint32 areaId = 0;

    // floor is the height we are closer to (but only if above)
    if (hasVmapArea && G3D::fuzzyGe(z, vmapZ - GROUND_HEIGHT_TOLERANCE) && (G3D::fuzzyLt(z, gridMapHeight - GROUND_HEIGHT_TOLERANCE) || vmapZ > gridMapHeight))
    {
        // wmo found
        if (WMOAreaTableEntry const* wmoEntry = sDB2Manager.GetWMOAreaTable(rootId, adtId, groupId))
            areaId = wmoEntry->AreaTableID;

        if (!areaId)
            areaId = gridAreaId;
    }
    else
        areaId = gridAreaId;

    if (!areaId)
        areaId = sMapStore.AssertEntry(GetId())->AreaTableID;

    return areaId;
}

uint32 TerrainInfo::GetZoneId(PhaseShift const& phaseShift, uint32 mapId, float x, float y, float z, DynamicMapTree const* dynamicMapTree)
{
    uint32 areaId = GetAreaId(phaseShift, mapId, x, y, z, dynamicMapTree);
    if (AreaTableEntry const* area = sAreaTableStore.LookupEntry(areaId))
        if (area->ParentAreaID && area->GetFlags().HasFlag(AreaFlags::IsSubzone))
            return area->ParentAreaID;

    return areaId;
}

void TerrainInfo::GetZoneAndAreaId(PhaseShift const& phaseShift, uint32 mapId, uint32& zoneid, uint32& areaid, float x, float y, float z, DynamicMapTree const* dynamicMapTree)
{
    areaid = zoneid = GetAreaId(phaseShift, mapId, x, y, z, dynamicMapTree);
    if (AreaTableEntry const* area = sAreaTableStore.LookupEntry(areaid))
        if (area->ParentAreaID && area->GetFlags().HasFlag(AreaFlags::IsSubzone))
            zoneid = area->ParentAreaID;
}

float TerrainInfo::GetMinHeight(PhaseShift const& phaseShift, uint32 mapId, float x, float y)
{
    if (GridMap const* grid = GetGrid(PhasingHandler::GetTerrainMapId(phaseShift, mapId, this, x, y), x, y))
        return grid->getMinHeight(x, y);

    return -500.0f;
}

float TerrainInfo::GetGridHeight(PhaseShift const& phaseShift, uint32 mapId, float x, float y)
{
    if (GridMap* gmap = GetGrid(PhasingHandler::GetTerrainMapId(phaseShift, mapId, this, x, y), x, y))
        return gmap->getHeight(x, y);

    return VMAP_INVALID_HEIGHT_VALUE;
}

float TerrainInfo::GetStaticHeight(PhaseShift const& phaseShift, uint32 mapId, float x, float y, float z, bool checkVMap /*= true*/, float maxSearchDist /*= DEFAULT_HEIGHT_SEARCH*/)
{
    // find raw .map surface under Z coordinates
    float mapHeight = VMAP_INVALID_HEIGHT_VALUE;
    uint32 terrainMapId = PhasingHandler::GetTerrainMapId(phaseShift, mapId, this, x, y);
    float gridHeight = GetGridHeight(phaseShift, mapId, x, y);
    if (G3D::fuzzyGe(z, gridHeight - GROUND_HEIGHT_TOLERANCE))
        mapHeight = gridHeight;

    float vmapHeight = VMAP_INVALID_HEIGHT_VALUE;
    if (checkVMap)
    {
        VMAP::IVMapManager* vmgr = VMAP::VMapFactory::createOrGetVMapManager();
        if (vmgr->isHeightCalcEnabled())
            vmapHeight = vmgr->getHeight(terrainMapId, x, y, z, maxSearchDist);
    }

    // mapHeight set for any above raw ground Z or <= INVALID_HEIGHT
    // vmapheight set for any under Z value or <= INVALID_HEIGHT
    if (vmapHeight > INVALID_HEIGHT)
    {
        if (mapHeight > INVALID_HEIGHT)
        {
            // we have mapheight and vmapheight and must select more appropriate

            // vmap height above map height
            // or if the distance of the vmap height is less the land height distance
            if (vmapHeight > mapHeight || std::fabs(mapHeight - z) > std::fabs(vmapHeight - z))
                return vmapHeight;

            return mapHeight;                           // better use .map surface height
        }

        return vmapHeight;                              // we have only vmapHeight (if have)
    }

    return mapHeight;                               // explicitly use map data
}

float TerrainInfo::GetWaterLevel(PhaseShift const& phaseShift, uint32 mapId, float x, float y)
{
    if (GridMap* gmap = GetGrid(PhasingHandler::GetTerrainMapId(phaseShift, mapId, this, x, y), x, y))
        return gmap->getLiquidLevel(x, y);

    return 0;
}

bool TerrainInfo::IsInWater(PhaseShift const& phaseShift, uint32 mapId, float x, float y, float pZ, LiquidData* data)
{
    LiquidData liquid_status;
    LiquidData* liquid_ptr = data ? data : &liquid_status;
    return (GetLiquidStatus(phaseShift, mapId, x, y, pZ, map_liquidHeaderTypeFlags::AllLiquids, liquid_ptr) & (LIQUID_MAP_IN_WATER | LIQUID_MAP_UNDER_WATER)) != 0;
}

bool TerrainInfo::IsUnderWater(PhaseShift const& phaseShift, uint32 mapId, float x, float y, float z)
{
    return (GetLiquidStatus(phaseShift, mapId, x, y, z, map_liquidHeaderTypeFlags::Water | map_liquidHeaderTypeFlags::Ocean) & LIQUID_MAP_UNDER_WATER) != 0;
}

float TerrainInfo::GetWaterOrGroundLevel(PhaseShift const& phaseShift, uint32 mapId, float x, float y, float z, float* ground /*= nullptr*/, bool /*swim = false*/, float collisionHeight /*= DEFAULT_COLLISION_HEIGHT*/, DynamicMapTree const* dynamicMapTree /*= nullptr*/)
{
    if (GetGrid(PhasingHandler::GetTerrainMapId(phaseShift, mapId, this, x, y), x, y))
    {
        // we need ground level (including grid height version) for proper return water level in point
        float ground_z = GetStaticHeight(phaseShift, mapId, x, y, z + Z_OFFSET_FIND_HEIGHT, true, 50.0f);
        if (dynamicMapTree)
            ground_z = std::max(ground_z, dynamicMapTree->getHeight(x, y, z + Z_OFFSET_FIND_HEIGHT, 50.0f, phaseShift));

        if (ground)
            *ground = ground_z;

        LiquidData liquid_status;

        ZLiquidStatus res = GetLiquidStatus(phaseShift, mapId, x, y, ground_z, map_liquidHeaderTypeFlags::AllLiquids, &liquid_status, collisionHeight);
        switch (res)
        {
            case LIQUID_MAP_ABOVE_WATER:
                return std::max<float>(liquid_status.level, ground_z);
            case LIQUID_MAP_NO_WATER:
                return ground_z;
            default:
                return liquid_status.level;
        }
    }

    return VMAP_INVALID_HEIGHT_VALUE;
}

TerrainMgr::TerrainMgr() = default;

TerrainMgr::~TerrainMgr() = default;

TerrainMgr& TerrainMgr::Instance()
{
    static TerrainMgr instance;
    return instance;
}

void TerrainMgr::InitializeParentMapData(std::unordered_map<uint32, std::vector<uint32>> const& mapData)
{
    _parentMapData = mapData;
}

std::shared_ptr<TerrainInfo> TerrainMgr::LoadTerrain(uint32 mapId)
{
    MapEntry const* entry = sMapStore.LookupEntry(mapId);
    if (!entry)
        return nullptr;

    while (entry->ParentMapID != -1 || entry->CosmeticParentMapID != -1)
    {
        uint32 parentMapId = entry->ParentMapID != -1 ? entry->ParentMapID : entry->CosmeticParentMapID;
        entry = sMapStore.LookupEntry(parentMapId);
        if (!entry)
            break;

        mapId = parentMapId;
    }

    auto itr = _terrainMaps.find(mapId);
    if (itr != _terrainMaps.end())
        if (std::shared_ptr<TerrainInfo> terrain = itr->second.lock())
            return terrain;

    std::shared_ptr<TerrainInfo> terrainInfo = LoadTerrainImpl(mapId);
    _terrainMaps[mapId] = terrainInfo;
    return terrainInfo;
}

void TerrainMgr::UnloadAll()
{
    _terrainMaps.clear();
}

void TerrainMgr::Update(uint32 diff)
{
    // global garbage collection
    for (auto& [mapId, terrainRef] : _terrainMaps)
        if (std::shared_ptr<TerrainInfo> terrain = terrainRef.lock())
            terrain->CleanUpGrids(diff);
}

uint32 TerrainMgr::GetAreaId(PhaseShift const& phaseShift, uint32 mapid, float x, float y, float z)
{
    if (std::shared_ptr<TerrainInfo> t = LoadTerrain(mapid))
        return t->GetAreaId(phaseShift, mapid, x, y, z);
    return 0;
}

uint32 TerrainMgr::GetZoneId(PhaseShift const& phaseShift, uint32 mapid, float x, float y, float z)
{
    if (std::shared_ptr<TerrainInfo> t = LoadTerrain(mapid))
        return t->GetZoneId(phaseShift, mapid, x, y, z);
    return 0;
}

void TerrainMgr::GetZoneAndAreaId(PhaseShift const& phaseShift, uint32& zoneid, uint32& areaid, uint32 mapid, float x, float y, float z)
{
    if (std::shared_ptr<TerrainInfo> t = LoadTerrain(mapid))
        t->GetZoneAndAreaId(phaseShift, mapid, zoneid, areaid, x, y, z);
}

std::shared_ptr<TerrainInfo> TerrainMgr::LoadTerrainImpl(uint32 mapId)
{
    std::shared_ptr<TerrainInfo> rootTerrain(new TerrainInfo(mapId)); // intentionally not using make_shared, don't want control block allocated together, will be relying on weak_ptr

    rootTerrain->DiscoverGridMapFiles();

    for (uint32 childMapId : _parentMapData[mapId])
        rootTerrain->AddChildTerrain(LoadTerrainImpl(childMapId));

    return rootTerrain;
}

bool TerrainMgr::ExistMapAndVMap(uint32 mapid, float x, float y)
{
    GridCoord p = Trinity::ComputeGridCoord(x, y);

    int32 gx = (MAX_NUMBER_OF_GRIDS - 1) - p.x_coord;
    int32 gy = (MAX_NUMBER_OF_GRIDS - 1) - p.y_coord;

    return TerrainInfo::ExistMap(mapid, gx, gy) && TerrainInfo::ExistVMap(mapid, gx, gy);
}
