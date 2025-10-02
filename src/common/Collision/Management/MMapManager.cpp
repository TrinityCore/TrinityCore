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
#include "Memory.h"

namespace MMAP
{
    constexpr char MAP_FILE_NAME_FORMAT[] = "{}mmaps/{:04}.mmap";
    constexpr char TILE_FILE_NAME_FORMAT[] = "{}mmaps/{:04}{:02}{:02}.mmtile";

    using NavMeshPtr = std::unique_ptr<dtNavMesh, decltype(Trinity::unique_ptr_deleter<dtNavMesh*, &::dtFreeNavMesh>())>;
    using NavMeshQueryPtr = std::unique_ptr<dtNavMeshQuery, decltype(Trinity::unique_ptr_deleter<dtNavMeshQuery*, &::dtFreeNavMeshQuery>())>;

    typedef std::unordered_map<std::pair<uint32, uint32>, NavMeshQueryPtr> NavMeshQuerySet;
    typedef std::unordered_map<uint32, dtTileRef> MMapTileSet;

    // dummy struct to hold map's mmap data
    struct MMapData
    {
        explicit MMapData(NavMeshPtr&& mesh) : navMesh(std::move(mesh)) { }

        // we have to use single dtNavMeshQuery for every instance, since those are not thread safe
        NavMeshQuerySet navMeshQueries;     // instanceId to query

        NavMeshPtr navMesh;
        MMapTileSet loadedTileRefs;        // maps [map grid coords] to [dtTile]
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
            loadedMMaps.insert(MMapDataSet::value_type(mapId, nullptr));
            for (uint32 childMapId : childMapIds)
                parentMapData[childMapId] = mapId;
        }

        thread_safe_environment = false;
    }

    MMapDataSet::const_iterator MMapManager::GetMMapData(uint32 mapId) const
    {
        // return the iterator if found or end() if not found/NULL
        MMapDataSet::const_iterator itr = loadedMMaps.find(mapId);
        if (itr != loadedMMaps.cend() && !itr->second)
            itr = loadedMMaps.cend();

        return itr;
    }

    LoadResult MMapManager::loadMapData(std::string_view basePath, uint32 mapId)
    {
        // we already have this map loaded?
        MMapDataSet::iterator itr = loadedMMaps.find(mapId);
        if (itr != loadedMMaps.end())
        {
            if (itr->second)
                return LoadResult::AlreadyLoaded;
        }
        else
        {
            if (thread_safe_environment)
                itr = loadedMMaps.insert(MMapDataSet::value_type(mapId, nullptr)).first;
            else
                ABORT_MSG("Invalid mapId %u passed to MMapManager after startup in thread unsafe environment", mapId);
        }

        // load and init dtNavMesh - read parameters from file
        std::string fileName = Trinity::StringFormat(MAP_FILE_NAME_FORMAT, basePath, mapId);
        auto file = Trinity::make_unique_ptr_with_deleter<&::fclose>(fopen(fileName.c_str(), "rb"));
        if (!file)
        {
            TC_LOG_DEBUG("maps", "MMAP:loadMapData: Error: Could not open mmap file '{}'", fileName);
            return LoadResult::FileNotFound;
        }

        dtNavMeshParams params;
        uint32 count = uint32(fread(&params, sizeof(dtNavMeshParams), 1, file.get()));
        if (count != 1)
        {
            TC_LOG_DEBUG("maps", "MMAP:loadMapData: Error: Could not read params from file '{}'", fileName);
            return LoadResult::ReadFromFileFailed;
        }

        NavMeshPtr mesh(dtAllocNavMesh());
        ASSERT(mesh);
        if (dtStatusFailed(mesh->init(&params)))
        {
            TC_LOG_ERROR("maps", "MMAP:loadMapData: Failed to initialize dtNavMesh for mmap {:04} from file {}", mapId, fileName);
            return LoadResult::LibraryError;
        }

        TC_LOG_DEBUG("maps", "MMAP:loadMapData: Loaded {:04}.mmap", mapId);

        // store inside our map list
        itr->second.reset(new MMapData(std::move(mesh)));
        return LoadResult::Success;
    }

    uint32 MMapManager::packTileID(int32 x, int32 y)
    {
        return uint32(x << 16 | y);
    }

    LoadResult MMapManager::loadMap(std::string_view basePath, uint32 mapId, int32 x, int32 y)
    {
        // make sure the mmap is loaded and ready to load tiles
        switch (LoadResult mapResult = loadMapData(basePath, mapId))
        {
            case LoadResult::Success:
            case LoadResult::AlreadyLoaded:
                break;
            default:
                return mapResult;
        }

        // get this mmap data
        MMapData* mmap = loadedMMaps[mapId].get();
        ASSERT(mmap->navMesh);

        // check if we already have this tile loaded
        uint32 packedGridPos = packTileID(x, y);
        if (mmap->loadedTileRefs.contains(packedGridPos))
            return LoadResult::AlreadyLoaded;

        // load this tile :: mmaps/MMMMXXYY.mmtile
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
            TC_LOG_ERROR("maps", "MMAP:loadMap: Bad header in mmap {:04}{:02}{:02}.mmtile", mapId, x, y);
            return LoadResult::ReadFromFileFailed;
        }

        if (fileHeader.mmapMagic != MMAP_MAGIC)
        {
            TC_LOG_ERROR("maps", "MMAP:loadMap: Bad header in mmap {:04}{:02}{:02}.mmtile", mapId, x, y);
            return LoadResult::VersionMismatch;
        }

        if (fileHeader.mmapVersion != MMAP_VERSION)
        {
            TC_LOG_ERROR("maps", "MMAP:loadMap: {:04}{:02}{:02}.mmtile was built with generator v{}, expected v{}",
                mapId, x, y, fileHeader.mmapVersion, MMAP_VERSION);
            return LoadResult::VersionMismatch;
        }

        long pos = ftell(file.get());
        fseek(file.get(), 0, SEEK_END);
        if (pos < 0 || static_cast<int32>(fileHeader.size) > ftell(file.get()) - pos)
        {
            TC_LOG_ERROR("maps", "MMAP:loadMap: {:04}{:02}{:02}.mmtile has corrupted data size", mapId, x, y);
            return LoadResult::ReadFromFileFailed;
        }

        fseek(file.get(), pos, SEEK_SET);

        auto data = Trinity::make_unique_ptr_with_deleter<&::dtFree>(dtAlloc(fileHeader.size, DT_ALLOC_PERM));
        ASSERT(data);

        size_t result = fread(data.get(), fileHeader.size, 1, file.get());
        if (!result)
        {
            TC_LOG_ERROR("maps", "MMAP:loadMap: Bad header or data in mmap {:04}{:02}{:02}.mmtile", mapId, x, y);
            return LoadResult::ReadFromFileFailed;
        }

        dtMeshHeader* header = static_cast<dtMeshHeader*>(data.get());
        dtTileRef tileRef = 0;

        // memory allocated for data is now managed by detour, and will be deallocated when the tile is removed
        if (dtStatusSucceed(mmap->navMesh->addTile(static_cast<unsigned char*>(data.release()), fileHeader.size, DT_TILE_FREE_DATA, 0, &tileRef)))
        {
            mmap->loadedTileRefs.insert(std::pair<uint32, dtTileRef>(packedGridPos, tileRef));
            ++loadedTiles;
            TC_LOG_DEBUG("maps", "MMAP:loadMap: Loaded mmtile {:04}[{:02}, {:02}] into {:04}[{:02}, {:02}]", mapId, x, y, mapId, header->x, header->y);
            return LoadResult::Success;
        }
        else
        {
            TC_LOG_ERROR("maps", "MMAP:loadMap: Could not load {:04}{:02}{:02}.mmtile into navmesh", mapId, x, y);
            return LoadResult::LibraryError;
        }
    }

    bool MMapManager::loadMapInstance(std::string_view basePath, uint32 meshMapId, uint32 instanceMapId, uint32 instanceId)
    {
        switch (loadMapData(basePath, meshMapId))
        {
            case LoadResult::Success:
            case LoadResult::AlreadyLoaded:
                break;
            default:
                return false;
        }

        MMapData* mmap = loadedMMaps[meshMapId].get();
        auto [queryItr, inserted] = mmap->navMeshQueries.try_emplace({ instanceMapId, instanceId }, nullptr);
        if (!inserted)
            return true;

        // allocate mesh query
        NavMeshQueryPtr query(dtAllocNavMeshQuery());
        ASSERT(query);
        if (dtStatusFailed(query->init(mmap->navMesh.get(), 1024)))
        {
            mmap->navMeshQueries.erase(queryItr);
            TC_LOG_ERROR("maps", "MMAP:GetNavMeshQuery: Failed to initialize dtNavMeshQuery for mapId {:04} instanceId {}", instanceMapId, instanceId);
            return false;
        }

        TC_LOG_DEBUG("maps", "MMAP:GetNavMeshQuery: created dtNavMeshQuery for mapId {:04} instanceId {}", instanceMapId, instanceId);
        queryItr->second = std::move(query);
        return true;
    }

    bool MMapManager::unloadMap(uint32 mapId, int32 x, int32 y)
    {
        // check if we have this map loaded
        MMapDataSet::const_iterator itr = GetMMapData(mapId);
        if (itr == loadedMMaps.end())
        {
            // file may not exist, therefore not loaded
            TC_LOG_DEBUG("maps", "MMAP:unloadMap: Asked to unload not loaded navmesh map. {:04}{:02}{:02}.mmtile", mapId, x, y);
            return false;
        }

        MMapData* mmap = itr->second.get();

        // check if we have this tile loaded
        uint32 packedGridPos = packTileID(x, y);
        auto tileRef = mmap->loadedTileRefs.extract(packedGridPos);
        if (!tileRef)
        {
            // file may not exist, therefore not loaded
            TC_LOG_DEBUG("maps", "MMAP:unloadMap: Asked to unload not loaded navmesh tile. {:04}{:02}{:02}.mmtile", mapId, x, y);
            return false;
        }

        // unload, and mark as non loaded
        if (dtStatusFailed(mmap->navMesh->removeTile(tileRef.mapped(), nullptr, nullptr)))
        {
            // this is technically a memory leak
            // if the grid is later reloaded, dtNavMesh::addTile will return error but no extra memory is used
            // we cannot recover from this error - assert out
            TC_LOG_ERROR("maps", "MMAP:unloadMap: Could not unload {:04}{:02}{:02}.mmtile from navmesh", mapId, x, y);
            ABORT();
        }
        else
        {
            --loadedTiles;
            TC_LOG_DEBUG("maps", "MMAP:unloadMap: Unloaded mmtile {:04}[{:02}, {:02}] from {:03}", mapId, x, y, mapId);
            return true;
        }

        return false;
    }

    bool MMapManager::unloadMap(uint32 mapId)
    {
        MMapDataSet::iterator itr = loadedMMaps.find(mapId);
        if (itr == loadedMMaps.end() || !itr->second)
        {
            // file may not exist, therefore not loaded
            TC_LOG_DEBUG("maps", "MMAP:unloadMap: Asked to unload not loaded navmesh map {:04}", mapId);
            return false;
        }

        // unload all tiles from given map
        MMapData* mmap = itr->second.get();
        for (auto const& [tileId, tileRef] : mmap->loadedTileRefs)
        {
            uint32 x = (tileId >> 16);
            uint32 y = (tileId & 0x0000FFFF);
            if (dtStatusFailed(mmap->navMesh->removeTile(tileRef, nullptr, nullptr)))
                TC_LOG_ERROR("maps", "MMAP:unloadMap: Could not unload {:04}{:02}{:02}.mmtile from navmesh", mapId, x, y);
            else
            {
                --loadedTiles;
                TC_LOG_DEBUG("maps", "MMAP:unloadMap: Unloaded mmtile {:04}[{:02}, {:02}] from {:04}", mapId, x, y, mapId);
            }
        }

        itr->second = nullptr;
        TC_LOG_DEBUG("maps", "MMAP:unloadMap: Unloaded {:04}.mmap", mapId);

        return true;
    }

    bool MMapManager::unloadMapInstance(uint32 meshMapId, uint32 instanceMapId, uint32 instanceId)
    {
        // check if we have this map loaded
        MMapDataSet::const_iterator itr = GetMMapData(meshMapId);
        if (itr == loadedMMaps.end())
        {
            // file may not exist, therefore not loaded
            TC_LOG_DEBUG("maps", "MMAP:unloadMapInstance: Asked to unload not loaded navmesh map {:04}", meshMapId);
            return false;
        }

        MMapData* mmap = itr->second.get();
        std::size_t erased = mmap->navMeshQueries.erase({ instanceMapId, instanceId });
        if (!erased)
        {
            TC_LOG_DEBUG("maps", "MMAP:unloadMapInstance: Asked to unload not loaded dtNavMeshQuery mapId {:04} instanceId {}", instanceMapId, instanceId);
            return false;
        }

        TC_LOG_DEBUG("maps", "MMAP:unloadMapInstance: Unloaded mapId {:04} instanceId {}", instanceMapId, instanceId);

        return true;
    }

    dtNavMesh const* MMapManager::GetNavMesh(uint32 mapId)
    {
        MMapDataSet::const_iterator itr = GetMMapData(mapId);
        if (itr == loadedMMaps.end())
            return nullptr;

        return itr->second->navMesh.get();
    }

    dtNavMeshQuery const* MMapManager::GetNavMeshQuery(uint32 meshMapId, uint32 instanceMapId, uint32 instanceId)
    {
        auto itr = GetMMapData(meshMapId);
        if (itr == loadedMMaps.end())
            return nullptr;

        auto queryItr = itr->second->navMeshQueries.find({ instanceMapId, instanceId });
        if (queryItr == itr->second->navMeshQueries.end())
            return nullptr;

        return queryItr->second.get();
    }
}
