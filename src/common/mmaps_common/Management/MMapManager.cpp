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

#include "MMapManager.h"
#include "Errors.h"
#include "Hash.h"
#include "Log.h"
#include "MMapDefines.h"
#include "MapUtils.h"
#include "Memory.h"
#include <algorithm>

namespace MMAP
{
    constexpr char MAP_FILE_NAME_FORMAT[] = "{}mmaps/{:04}.mmap";
    constexpr char TILE_FILE_NAME_FORMAT[] = "{}mmaps/{:04}_{:02}_{:02}.mmtile";

    using NavMeshQuerySet = std::unordered_map<std::pair<uint32, uint32>, dtNavMeshQuery>;
    using MMapTileSet = std::unordered_map<uint32, dtTileRef>;

    struct MMapMapData
    {
        dtNavMesh navMesh;
        MMapTileSet loadedTileRefs;        // maps [map grid coords] to [dtTile]
    };

    using MeshDataMap = std::unordered_map<uint32, MMapMapData>;

    // dummy struct to hold map's mmap data
    struct MMapData
    {
        MeshDataMap meshData;

        // we have to use single dtNavMeshQuery for every instance, since those are not thread safe
        NavMeshQuerySet navMeshQueries;     // instanceId to query

        static uint32 GetInstanceIdForMeshLookup(uint32 mapId, uint32 instanceId)
        {
            switch (mapId)
            {
                case 0: case 1: case 571: case 603: case 607: case 609: case 616: case 628: case 631: case 644: case 649: case 720:
                case 732: case 754: case 755: case 861: case 938: case 940: case 962: case 967: case 1064: case 1076: case 1098:
                case 1122: case 1126: case 1182: case 1205: case 1220: case 1265: case 1492: case 1523: case 1530: case 1579: case 1676:
                case 1704: case 1705: case 1706: case 1707: case 1734: case 1756: case 1943: case 2076: case 2118: case 2160: case 2161:
                case 2187: case 2212: case 2235: case 2237: case 2264: case 2450: case 2512: case 2586: case 2601: case 2654: case 2657:
                case 2660: case 2669: case 2819: case 2828:
                    return instanceId;
                default:
                    break;
            }

            // for maps that won't have dynamic mesh, return 0 to reuse the same mesh across all instances
            return 0;
        }

        std::pair<MeshDataMap::iterator, bool> GetMeshData(uint32 mapId, uint32 instanceId)
        {
            return meshData.try_emplace(GetInstanceIdForMeshLookup(mapId, instanceId));
        }

        MeshDataMap::iterator FindMeshData(uint32 mapId, uint32 instanceId)
        {
            return meshData.find(GetInstanceIdForMeshLookup(mapId, instanceId));
        }

        MeshDataMap::node_type RemoveMeshData(uint32 mapId, uint32 instanceId)
        {
            return meshData.extract(GetInstanceIdForMeshLookup(mapId, instanceId));
        }
    };

    // ######################## MMapManager ########################
    MMapManager::MMapManager() = default;
    MMapManager::~MMapManager() = default;

    MMapManager* MMapManager::instance()
    {
        static MMapManager instance;
        return &instance;
    }

    void MMapManager::InitializeThreadUnsafe(std::unordered_map<uint32, std::vector<uint32>> const& mapData)
    {
        // the caller must pass the list of all mapIds that will be used in the MMapManager lifetime
        for (auto const& [mapId, childMapIds] : mapData)
        {
            loadedMMaps.try_emplace(mapId, new MMapData());
            for (uint32 childMapId : childMapIds)
                parentMapData[childMapId] = mapId;
        }
    }

    MMapDataSet::const_iterator MMapManager::GetMMapData(uint32 mapId) const
    {
        // return the iterator if found or end() if not found/NULL
        MMapDataSet::const_iterator itr = loadedMMaps.find(mapId);
        if (itr != loadedMMaps.cend() && !itr->second)
            itr = loadedMMaps.cend();

        return itr;
    }

    bool MMapManager::isRebuildingTilesEnabledOnMap(uint32 mapId)
    {
        return MMapData::GetInstanceIdForMeshLookup(mapId, 1) != 0;
    }

    LoadResult MMapManager::loadMapData(std::string_view basePath, uint32 mapId, uint32 instanceId)
    {
        // we already have this map loaded?
        MMapDataSet::iterator itr = loadedMMaps.find(mapId);
        ASSERT(itr != loadedMMaps.end(), "Invalid mapId %u passed to MMapManager after startup in thread unsafe environment", mapId);

        auto [meshItr, needsLoading] = itr->second->GetMeshData(mapId, instanceId);
        if (!needsLoading)
            return LoadResult::AlreadyLoaded;

        auto loadGuard = Trinity::make_unique_ptr_with_deleter(&meshItr, [&](MeshDataMap::iterator* m)
        {
            itr->second->meshData.erase(*m);
        });

        // load and init dtNavMesh - read parameters from file
        dtNavMeshParams params;
        if (LoadResult paramsResult = parseNavMeshParamsFile(basePath, mapId, &params); paramsResult != LoadResult::Success)
            return paramsResult;

        if (dtStatusFailed(meshItr->second.navMesh.init(&params)))
        {
            TC_LOG_ERROR("maps", "MMAP:loadMapData: Failed to initialize dtNavMesh for mmap {:04}", mapId);
            return LoadResult::LibraryError;
        }

        TC_LOG_DEBUG("maps", "MMAP:loadMapData: Loaded {:04}.mmap", mapId);
        (void)loadGuard.release();

        return LoadResult::Success;
    }

    LoadResult MMapManager::parseNavMeshParamsFile(std::string_view basePath, uint32 mapId, dtNavMeshParams* params,
        std::vector<OffMeshData>* offmeshConnections /*= nullptr*/)
    {
        std::string fileName = Trinity::StringFormat(MAP_FILE_NAME_FORMAT, basePath, mapId);
        auto file = Trinity::make_unique_ptr_with_deleter<&::fclose>(fopen(fileName.c_str(), "rb"));
        if (!file)
        {
            TC_LOG_DEBUG("maps", "MMAP:loadMapData: Error: Could not open mmap file '{}'", fileName);
            return LoadResult::FileNotFound;
        }

        MmapNavMeshHeader fileHeader;
        if (fread(&fileHeader, sizeof(MmapNavMeshHeader), 1, file.get()) != 1)
        {
            TC_LOG_DEBUG("maps", "MMAP:loadMapData: Error: Could not read params from file '{}'", fileName);
            return LoadResult::ReadFromFileFailed;
        }

        if (fileHeader.mmapMagic != MMAP_MAGIC)
        {
            TC_LOG_ERROR("maps", "MMAP:loadMap: Bad header in mmap {:04}.mmap", mapId);
            return LoadResult::VersionMismatch;
        }

        if (fileHeader.mmapVersion != MMAP_VERSION)
        {
            TC_LOG_ERROR("maps", "MMAP:loadMap: {:04}.mmap was built with generator v{}, expected v{}",
                mapId, fileHeader.mmapVersion, MMAP_VERSION);
            return LoadResult::VersionMismatch;
        }

        memcpy(params, &fileHeader.params, sizeof(dtNavMeshParams));

        if (offmeshConnections)
        {
            offmeshConnections->resize(fileHeader.offmeshConnectionCount);
            if (fread(offmeshConnections->data(), sizeof(OffMeshData), offmeshConnections->size(), file.get()) != offmeshConnections->size())
            {
                offmeshConnections->clear();
                TC_LOG_DEBUG("maps", "MMAP:loadMapData: Error: Could not read offmesh connections from file '{}'", fileName);
                return LoadResult::ReadFromFileFailed;
            }
        }

        return LoadResult::Success;
    }

    uint32 MMapManager::packTileID(int32 x, int32 y)
    {
        return uint32(x << 16 | y);
    }

    LoadResult MMapManager::loadMap(std::string_view basePath, uint32 mapId, uint32 instanceId, int32 x, int32 y)
    {
        // make sure the mmap is loaded and ready to load tiles
        switch (LoadResult mapResult = loadMapData(basePath, mapId, instanceId))
        {
            case LoadResult::Success:
            case LoadResult::AlreadyLoaded:
                break;
            default:
                return mapResult;
        }

        // get this mmap data
        MMapData* mmap = Trinity::Containers::MapGetValuePtr(loadedMMaps, mapId);
        MMapMapData& meshData = mmap->GetMeshData(mapId, instanceId).first->second;

        // check if we already have this tile loaded
        uint32 packedGridPos = packTileID(x, y);
        if (meshData.loadedTileRefs.contains(packedGridPos))
            return LoadResult::AlreadyLoaded;

        // load this tile :: mmaps/MMMM_XX_YY.mmtile
        std::string fileName = Trinity::StringFormat(TILE_FILE_NAME_FORMAT, basePath, mapId, x, y);
        auto file = Trinity::make_unique_ptr_with_deleter<&::fclose>(fopen(fileName.c_str(), "rb"));
        if (!file)
        {
            auto parentMapItr = parentMapData.find(mapId);
            if (parentMapItr != parentMapData.end())
            {
                fileName = Trinity::StringFormat(TILE_FILE_NAME_FORMAT, basePath, parentMapItr->second, x, y);
                file.reset(fopen(fileName.c_str(), "rb"));
            }
        }

        if (!file)
        {
            TC_LOG_DEBUG("maps", "MMAP:loadMap: Could not open mmtile file '{}'", fileName);
            return LoadResult::FileNotFound;
        }

        // read header
        MmapTileHeader fileHeader;
        if (fread(&fileHeader, sizeof(MmapTileHeader), 1, file.get()) != 1)
        {
            TC_LOG_ERROR("maps", "MMAP:loadMap: Bad header in mmap {:04}_{:02}_{:02}.mmtile", mapId, x, y);
            return LoadResult::ReadFromFileFailed;
        }

        if (fileHeader.mmapMagic != MMAP_MAGIC)
        {
            TC_LOG_ERROR("maps", "MMAP:loadMap: Bad header in mmap {:04}_{:02}_{:02}.mmtile", mapId, x, y);
            return LoadResult::VersionMismatch;
        }

        if (fileHeader.mmapVersion != MMAP_VERSION)
        {
            TC_LOG_ERROR("maps", "MMAP:loadMap: {:04}_{:02}_{:02}.mmtile was built with generator v{}, expected v{}",
                mapId, x, y, fileHeader.mmapVersion, MMAP_VERSION);
            return LoadResult::VersionMismatch;
        }

        long pos = ftell(file.get());
        fseek(file.get(), 0, SEEK_END);
        if (pos < 0 || static_cast<int32>(fileHeader.size) > ftell(file.get()) - pos)
        {
            TC_LOG_ERROR("maps", "MMAP:loadMap: {:04}_{:02}_{:02}.mmtile has corrupted data size", mapId, x, y);
            return LoadResult::ReadFromFileFailed;
        }

        fseek(file.get(), pos, SEEK_SET);

        auto data = Trinity::make_unique_ptr_with_deleter<&::dtFree>(dtAlloc(fileHeader.size, DT_ALLOC_PERM));
        ASSERT(data);

        size_t result = fread(data.get(), fileHeader.size, 1, file.get());
        if (!result)
        {
            TC_LOG_ERROR("maps", "MMAP:loadMap: Bad header or data in mmap {:04}_{:02}_{:02}.mmtile", mapId, x, y);
            return LoadResult::ReadFromFileFailed;
        }

        dtMeshHeader* header = static_cast<dtMeshHeader*>(data.get());
        dtTileRef tileRef = 0;

        // memory allocated for data is now managed by detour, and will be deallocated when the tile is removed
        if (dtStatusSucceed(meshData.navMesh.addTile(static_cast<unsigned char*>(data.release()), fileHeader.size, DT_TILE_FREE_DATA, 0, &tileRef)))
        {
            meshData.loadedTileRefs[packedGridPos] = tileRef;
            ++loadedTiles;
            TC_LOG_DEBUG("maps", "MMAP:loadMap: Loaded mmtile {:04}[{:02}, {:02}] into {:04}[{:02}, {:02}]", mapId, x, y, mapId, header->x, header->y);
            return LoadResult::Success;
        }
        else
        {
            TC_LOG_ERROR("maps", "MMAP:loadMap: Could not load {:04}_{:02}_{:02}.mmtile into navmesh", mapId, x, y);
            return LoadResult::LibraryError;
        }
    }

    bool MMapManager::loadMapInstance(std::string_view basePath, uint32 meshMapId, uint32 instanceMapId, uint32 instanceId)
    {
        switch (loadMapData(basePath, meshMapId, instanceId))
        {
            case LoadResult::Success:
            case LoadResult::AlreadyLoaded:
                break;
            default:
                return false;
        }

        MMapData* mmap = Trinity::Containers::MapGetValuePtr(loadedMMaps, meshMapId);
        auto [queryItr, inserted] = mmap->navMeshQueries.try_emplace({ instanceMapId, instanceId });
        if (!inserted)
            return true;

        auto loadGuard = Trinity::make_unique_ptr_with_deleter(&queryItr, [&](NavMeshQuerySet::iterator* m)
        {
            mmap->navMeshQueries.erase(*m);
        });

        // allocate mesh query
        if (dtStatusFailed(queryItr->second.init(&mmap->GetMeshData(meshMapId, instanceId).first->second.navMesh, 1024)))
        {
            TC_LOG_ERROR("maps", "MMAP:GetNavMeshQuery: Failed to initialize dtNavMeshQuery for mapId {:04} instanceId {}", instanceMapId, instanceId);
            return false;
        }

        TC_LOG_DEBUG("maps", "MMAP:GetNavMeshQuery: created dtNavMeshQuery for mapId {:04} instanceId {}", instanceMapId, instanceId);
        (void)loadGuard.release();
        return true;
    }

    void MMapManager::unloadMap(uint32 mapId, int32 x, int32 y)
    {
        // check if we have this map loaded
        MMapDataSet::const_iterator itr = GetMMapData(mapId);
        if (itr == loadedMMaps.end())
        {
            // file may not exist, therefore not loaded
            TC_LOG_DEBUG("maps", "MMAP:unloadMap: Asked to unload not loaded navmesh map. {:04}_{:02}_{:02}.mmtile", mapId, x, y);
            return;
        }

        MMapData* mmap = itr->second.get();
        uint32 packedGridPos = packTileID(x, y);
        for (auto& [instanceId, meshData] : mmap->meshData)
        {
            // check if we have this tile loaded
            auto tileRef = meshData.loadedTileRefs.extract(packedGridPos);
            if (!tileRef)
                continue;

            // unload, and mark as non loaded
            if (dtStatusFailed(meshData.navMesh.removeTile(tileRef.mapped(), nullptr, nullptr)))
            {
                // this is technically a memory leak
                // if the grid is later reloaded, dtNavMesh::addTile will return error but no extra memory is used
                // we cannot recover from this error - assert out
                TC_LOG_ERROR("maps", "MMAP:unloadMap: Could not unload {:04}_{:02}_{:02}.mmtile from navmesh", mapId, x, y);
                ABORT();
            }
            else
            {
                --loadedTiles;
                TC_LOG_DEBUG("maps", "MMAP:unloadMap: Unloaded mmtile {:04}[{:02}, {:02}] from {:03}", mapId, x, y, mapId);
            }
        }
    }

    void MMapManager::unloadMap(uint32 mapId)
    {
        MMapDataSet::iterator itr = loadedMMaps.find(mapId);
        if (itr == loadedMMaps.end() || !itr->second)
        {
            // file may not exist, therefore not loaded
            TC_LOG_DEBUG("maps", "MMAP:unloadMap: Asked to unload not loaded navmesh map {:04}", mapId);
            return;
        }

        if (!isRebuildingTilesEnabledOnMap(mapId))
        {
            if (MeshDataMap::node_type meshNode = itr->second->RemoveMeshData(mapId, 0))
            {
                for (auto const& [tileId, tileRef] : meshNode.mapped().loadedTileRefs)
                {
                    uint32 x = (tileId >> 16);
                    uint32 y = (tileId & 0x0000FFFF);
                    if (dtStatusFailed(meshNode.mapped().navMesh.removeTile(tileRef, nullptr, nullptr)))
                        TC_LOG_ERROR("maps", "MMAP:unloadMap: Could not unload {:04}_{:02}_{:02}.mmtile from navmesh", mapId, x, y);
                    else
                    {
                        --loadedTiles;
                        TC_LOG_DEBUG("maps", "MMAP:unloadMap: Unloaded mmtile {:04}[{:02}, {:02}] from {:04}", mapId, x, y, mapId);
                    }
                }
            }
        }
        else // require all tiles to be already unloaded
            ASSERT(std::ranges::all_of(itr->second->meshData, [](MMapMapData const& mesh) { return mesh.loadedTileRefs.empty(); }, Trinity::Containers::MapValue));

        TC_LOG_DEBUG("maps", "MMAP:unloadMap: Unloaded {:04}.mmap", mapId);
    }

    void MMapManager::unloadMapInstance(uint32 meshMapId, uint32 instanceMapId, uint32 instanceId)
    {
        // check if we have this map loaded
        MMapDataSet::const_iterator itr = GetMMapData(meshMapId);
        if (itr == loadedMMaps.end())
        {
            // file may not exist, therefore not loaded
            TC_LOG_DEBUG("maps", "MMAP:unloadMapInstance: Asked to unload not loaded navmesh map {:04}", meshMapId);
            return;
        }

        MMapData* mmap = itr->second.get();
        std::size_t erased = mmap->navMeshQueries.erase({ instanceMapId, instanceId });
        if (!erased)
            TC_LOG_DEBUG("maps", "MMAP:unloadMapInstance: Asked to unload not loaded dtNavMeshQuery mapId {:04} instanceId {}", instanceMapId, instanceId);

        if (isRebuildingTilesEnabledOnMap(meshMapId))
        {
            if (MeshDataMap::node_type meshNode = mmap->RemoveMeshData(meshMapId, instanceId))
            {
                // unload all tiles from given map
                for (auto const& [tileId, tileRef] : meshNode.mapped().loadedTileRefs)
                {
                    uint32 x = (tileId >> 16);
                    uint32 y = (tileId & 0x0000FFFF);
                    if (dtStatusFailed(meshNode.mapped().navMesh.removeTile(tileRef, nullptr, nullptr)))
                        TC_LOG_ERROR("maps", "MMAP:unloadMap: Could not unload {:04}_{:02}_{:02}.mmtile from navmesh", meshMapId, x, y);
                    else
                    {
                        --loadedTiles;
                        TC_LOG_DEBUG("maps", "MMAP:unloadMap: Unloaded mmtile {:04}[{:02}, {:02}] from {:04}", meshMapId, x, y, meshMapId);
                    }
                }
            }
        }

        TC_LOG_DEBUG("maps", "MMAP:unloadMapInstance: Unloaded mapId {:04} instanceId {}", instanceMapId, instanceId);
    }

    dtNavMesh* MMapManager::GetNavMesh(uint32 mapId, uint32 instanceId)
    {
        MMapDataSet::const_iterator itr = GetMMapData(mapId);
        if (itr == loadedMMaps.end())
            return nullptr;

        MeshDataMap::iterator meshItr = itr->second->FindMeshData(mapId, instanceId);
        if (meshItr == itr->second->meshData.end())
            return nullptr;

        return &meshItr->second.navMesh;
    }

    dtNavMeshQuery const* MMapManager::GetNavMeshQuery(uint32 meshMapId, uint32 instanceMapId, uint32 instanceId)
    {
        MMapDataSet::const_iterator itr = GetMMapData(meshMapId);
        if (itr == loadedMMaps.end())
            return nullptr;

        auto queryItr = itr->second->navMeshQueries.find({ instanceMapId, instanceId });
        if (queryItr == itr->second->navMeshQueries.end())
            return nullptr;

        return &queryItr->second;
    }
}
