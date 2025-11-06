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

#include "DynamicMMapTileBuilder.h"
#include "Containers.h"
#include "DB2Stores.h"
#include "DeadlineTimer.h"
#include "GameObjectModel.h"
#include "GameTime.h"
#include "Hash.h"
#include "IoContext.h"
#include "Log.h"
#include "MMapDefines.h"
#include "MMapManager.h"
#include "Map.h"
#include "VMapFactory.h"
#include "VMapManager.h"
#include "World.h"
#include "advstd.h"
#include <thread>

namespace
{
struct TileCacheKeyObject
{
    uint32 DisplayId;
    int16 Scale;
    std::array<int16, 3> Position;
    int64 Rotation;

    friend std::strong_ordering operator<=>(TileCacheKeyObject const&, TileCacheKeyObject const&) = default;
    friend bool operator==(TileCacheKeyObject const&, TileCacheKeyObject const&) = default;
};

struct TileCacheKey
{
    uint32 TerrainMapId;
    uint32 X;
    uint32 Y;
    std::size_t CachedHash; // computing the hash is expensive - store it
    std::vector<TileCacheKeyObject> Objects;

    friend bool operator==(TileCacheKey const&, TileCacheKey const&) = default;
};
}

template <>
struct std::hash<TileCacheKey>
{
    static std::size_t Compute(TileCacheKey const& key) noexcept
    {
        size_t hashVal = 0;
        Trinity::hash_combine(hashVal, key.TerrainMapId);
        Trinity::hash_combine(hashVal, key.X);
        Trinity::hash_combine(hashVal, key.Y);
        for (TileCacheKeyObject const& object : key.Objects)
        {
            Trinity::hash_combine(hashVal, object.DisplayId);
            Trinity::hash_combine(hashVal, object.Scale);
            Trinity::hash_combine(hashVal, object.Position[0]);
            Trinity::hash_combine(hashVal, object.Position[1]);
            Trinity::hash_combine(hashVal, object.Position[2]);
            Trinity::hash_combine(hashVal, object.Rotation);
        }
        return hashVal;
    }

    std::size_t operator()(TileCacheKey const& key) const noexcept
    {
        return key.CachedHash;
    }
};

namespace
{
std::unique_ptr<VMAP::VMapManager> CreateVMapManager(uint32 mapId)
{
    std::unique_ptr<VMAP::VMapManager> vmgr = std::make_unique<VMAP::VMapManager>();

    do
    {
        MapEntry const* mapEntry = sMapStore.AssertEntry(mapId);
        if (!mapEntry)
            break;

        vmgr->InitializeThreadUnsafe(mapId, mapEntry->ParentMapID);
        if (mapEntry->ParentMapID < 0)
            break;

        mapId = mapEntry->ParentMapID;
    } while (true);

    VMAP::VMapManager* globalManager = VMAP::VMapFactory::createOrGetVMapManager();
    vmgr->GetLiquidFlagsPtr = globalManager->GetLiquidFlagsPtr;
    vmgr->IsVMAPDisabledForPtr = globalManager->IsVMAPDisabledForPtr;
    vmgr->LoadPathOnlyModels = globalManager->LoadPathOnlyModels;
    return vmgr;
}

struct TileCache
{
    static TileCache* Instance()
    {
        static TileCache tc;
        return &tc;
    }

    struct Tile
    {
        std::shared_ptr<MMAP::DynamicTileBuilder::AsyncTileResult> Data;
        TimePoint LastAccessed;
    };

    static constexpr TimePoint::duration CACHE_CLEANUP_INTERVAL = 5min;
    static constexpr TimePoint::duration CACHE_MAX_AGE = 30min;

    std::mutex TilesMutex;
    std::unordered_map<TileCacheKey, Tile> Tiles;

    TileCache() :
        _taskContext(1),
        _cacheCleanupTimer(_taskContext, CACHE_CLEANUP_INTERVAL)
    {
        MMAP::CreateVMapManager = &CreateVMapManager;

        // init timer
        OnCacheCleanupTimerTick({});

        // start the worker
        _builderThread = std::thread([this] { _taskContext.run(); });
    }

    TileCache(TileCache const&) = delete;
    TileCache(TileCache&&) = delete;

    TileCache& operator=(TileCache const&) = delete;
    TileCache& operator=(TileCache&&) = delete;

    ~TileCache()
    {
        _cacheCleanupTimer.cancel();
        _builderThread.join();
    }

    template <typename Task>
    auto StartTask(Task&& task)
    {
        return Trinity::Asio::post(_taskContext, std::forward<Task>(task));
    }

private:
    void OnCacheCleanupTimerTick(boost::system::error_code const& error)
    {
        if (error)
            return;

        TimePoint now = GameTime::Now();
        RemoveOldCacheEntries(now - CACHE_MAX_AGE);
        _cacheCleanupTimer.expires_at(now + CACHE_CLEANUP_INTERVAL);
        _cacheCleanupTimer.async_wait([this](boost::system::error_code const& error) { OnCacheCleanupTimerTick(error); });
    }

    void RemoveOldCacheEntries(TimePoint oldestPreservedEntryTimestamp)
    {
        std::lock_guard lock(TilesMutex);
        Trinity::Containers::EraseIf(Tiles, [=](std::unordered_map<TileCacheKey, Tile>::value_type const& kv)
        {
            return kv.second.LastAccessed < oldestPreservedEntryTimestamp;
        });
    }

    Trinity::Asio::IoContext _taskContext;
    Trinity::Asio::DeadlineTimer _cacheCleanupTimer;
    std::thread _builderThread;
};
}

namespace MMAP
{
struct DynamicTileBuilder::TileId
{
    uint32 TerrainMapId;
    uint32 X;
    uint32 Y;

    friend bool operator==(TileId const&, TileId const&) = default;
};

struct TileBuildRequest
{
    DynamicTileBuilder::TileId Id;
    std::weak_ptr<DynamicTileBuilder::AsyncTileResult> Result;
    dtNavMesh* NavMesh;
};

bool InvokeAsyncCallbackIfReady(TileBuildRequest& request)
{
    std::shared_ptr<DynamicTileBuilder::AsyncTileResult> result = request.Result.lock();
    if (!result)
        return true;    // expired, mark as complete and do nothing

    if (!result->IsReady.load(std::memory_order::acquire))
        return false;

    TileBuilder::TileResult const& tileResult = result->Result;
    if (tileResult.data)
    {
        dtMeshHeader const* header = reinterpret_cast<dtMeshHeader const*>(tileResult.data.get());

        if (dtTileRef tileRef = request.NavMesh->getTileRefAt(header->x, header->y, 0))
        {
            TC_LOG_INFO("maps.mmapgen", "[Map {:04}] [{:02},{:02}]: Swapping new tile", request.Id.TerrainMapId, request.Id.Y, request.Id.X);

            request.NavMesh->removeTile(tileRef, nullptr, nullptr);

            unsigned char* data = static_cast<unsigned char*>(dtAlloc(tileResult.size, DT_ALLOC_PERM));
            std::memcpy(data, tileResult.data.get(), tileResult.size);

            request.NavMesh->addTile(data, tileResult.size, DT_TILE_FREE_DATA, tileRef, nullptr);
        }
    }

    return true;
}

static constexpr auto SetAsyncCallbackReady = [](DynamicTileBuilder::AsyncTileResult* result)
{
    result->IsReady.store(true, std::memory_order::release);
};

DynamicTileBuilder::DynamicTileBuilder(Map* map, dtNavMesh* navMesh) : TileBuilder(sWorld->GetDataPath(), sWorld->GetDataPath(), {}, {}, false, false, false, nullptr),
    m_map(map), m_navMesh(navMesh), m_rebuildCheckTimer(1s)
{
}

DynamicTileBuilder::~DynamicTileBuilder() = default;

void DynamicTileBuilder::AddTile(uint32 terrainMapId, uint32 tileX, uint32 tileY)
{
    TileId id = { .TerrainMapId = terrainMapId, .X = tileX, .Y = tileY };
    if (!advstd::ranges::contains(m_tilesToRebuild, id))
        m_tilesToRebuild.push_back(id);
}

void DynamicTileBuilder::Update(Milliseconds diff)
{
    m_rebuildCheckTimer.Update(diff);
    if (m_rebuildCheckTimer.Passed())
    {
        for (TileId const& tileId : m_tilesToRebuild)
            m_tiles.AddCallback({ .Id = tileId, .Result = BuildTile(tileId.TerrainMapId, tileId.X, tileId.Y), .NavMesh = m_navMesh });

        m_tilesToRebuild.clear();
        m_rebuildCheckTimer.Reset(1s);
    }

    m_tiles.ProcessReadyCallbacks();
}

std::weak_ptr<DynamicTileBuilder::AsyncTileResult> DynamicTileBuilder::BuildTile(uint32 terrainMapId, uint32 tileX, uint32 tileY)
{
    std::vector<std::shared_ptr<GameObjectModel const>> gameObjectModelReferences; // hold strong refs to models
    for (GameObjectModel const* gameObjectModel : m_map->GetGameObjectModelsInGrid(tileX, tileY))
    {
        if (!gameObjectModel->IsMapObject() || !gameObjectModel->IsIncludedInNavMesh())
            continue;

        std::shared_ptr<VMAP::WorldModel const> worldModel = gameObjectModel->GetWorldModel();
        if (!worldModel)
            continue;

        gameObjectModelReferences.emplace_back(worldModel, gameObjectModel);
    }

    TileCacheKey cacheKey{ .TerrainMapId = terrainMapId, .X = tileX, .Y = tileY, .CachedHash = 0, .Objects = std::vector<TileCacheKeyObject>(gameObjectModelReferences.size()) };
    for (std::size_t i = 0; i < gameObjectModelReferences.size(); ++i)
    {
        GameObjectModel const* gameObjectModel = gameObjectModelReferences[i].get();
        TileCacheKeyObject& object = cacheKey.Objects[i];
        object.DisplayId = gameObjectModel->GetDisplayId();
        object.Scale = int16(gameObjectModel->GetScale() * 1024.0f);
        object.Position = [](G3D::Vector3 const& pos) -> std::array<int16, 3>
        {
            return { int16(pos.x), int16(pos.y), int16(pos.z) };
        }(gameObjectModel->GetPosition());
        object.Rotation = gameObjectModel->GetPackedRotation();
    }

    // Ensure spawn order is stable after adding/removing gameobjects from the map for hash calculation
    std::ranges::sort(cacheKey.Objects);

    cacheKey.CachedHash = std::hash<TileCacheKey>::Compute(cacheKey);

    TileCache* tileCache = TileCache::Instance();
    std::lock_guard lock(tileCache->TilesMutex);
    auto [itr, isNew] = tileCache->Tiles.try_emplace(std::move(cacheKey));
    itr->second.LastAccessed = GameTime::Now();
    if (!isNew)
        return itr->second.Data;

    itr->second.Data = std::make_shared<AsyncTileResult>();
    tileCache->StartTask([result = itr->second.Data, hash = cacheKey.CachedHash, selfRef = weak_from_this(), terrainMapId, tileX, tileY, gameObjectModelReferences = std::move(gameObjectModelReferences)]() mutable
    {
        auto isReadyGuard = Trinity::make_unique_ptr_with_deleter<SetAsyncCallbackReady>(result.get());

        std::shared_ptr<DynamicTileBuilder> self = selfRef.lock();
        if (!self)
            return;

        // get navmesh params
        dtNavMeshParams params;
        std::vector<OffMeshData> offMeshConnections;
        if (MMapManager::parseNavMeshParamsFile(sWorld->GetDataPath(), terrainMapId, &params, &offMeshConnections) != LoadResult::Success)
            return;

        std::unique_ptr<VMAP::VMapManager> vmapManager = CreateVMapManager(terrainMapId);

        MeshData meshData;

        // get heightmap data
        self->m_terrainBuilder.loadMap(terrainMapId, tileX, tileY, meshData, vmapManager.get());

        // get model data
        self->m_terrainBuilder.loadVMap(terrainMapId, tileX, tileY, meshData, vmapManager.get());

        for (std::shared_ptr<GameObjectModel const> const& gameObjectModel : gameObjectModelReferences)
        {
            G3D::Vector3 position = gameObjectModel->GetPosition();
            position.x = -position.x;
            position.y = -position.y;

            G3D::Matrix3 invRotation = (G3D::Quat(0, 0, 1, 0) * gameObjectModel->GetRotation()).toRotationMatrix().inverse();

            self->m_terrainBuilder.loadVMapModel(gameObjectModel->GetWorldModel().get(), position, invRotation, gameObjectModel->GetScale(),
                meshData, vmapManager.get());
        }

        // if there is no data, give up now
        if (meshData.solidVerts.empty() && meshData.liquidVerts.empty())
            return;

        // remove unused vertices
        TerrainBuilder::cleanVertices(meshData.solidVerts, meshData.solidTris);
        TerrainBuilder::cleanVertices(meshData.liquidVerts, meshData.liquidTris);

        // gather all mesh data for final data check, and bounds calculation
        std::vector<float> allVerts(meshData.liquidVerts.size() + meshData.solidVerts.size());
        std::ranges::copy(meshData.liquidVerts, allVerts.begin());
        std::ranges::copy(meshData.solidVerts, allVerts.begin() + std::ssize(meshData.liquidVerts));

        // get bounds of current tile
        float bmin[3], bmax[3];
        getTileBounds(tileX, tileY, allVerts.data(), allVerts.size() / 3, bmin, bmax);

        self->m_terrainBuilder.loadOffMeshConnections(terrainMapId, tileX, tileY, meshData, offMeshConnections);

        // build navmesh tile
        std::string debugSuffix = Trinity::StringFormat("_{:016X}", hash);

        result->Result = self->buildMoveMapTile(terrainMapId, tileX, tileY, meshData, bmin, bmax, &params);
        if (self->m_debugOutput && result->Result.data)
            self->saveMoveMapTileToFile(terrainMapId, tileX, tileY, nullptr, result->Result, debugSuffix);
    });

    return itr->second.Data;
}
}
