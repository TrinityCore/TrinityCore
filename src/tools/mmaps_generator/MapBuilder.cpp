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

#include "MapBuilder.h"
#include "Log.h"
#include "MapDefines.h"
#include "MapTree.h"
#include "MapUtils.h"
#include "Memory.h"
#include "MMapDefines.h"
#include "PathCommon.h"
#include "StringConvert.h"
#include "StringFormat.h"
#include <boost/filesystem/directory.hpp>

namespace FileExtensions
{
static boost::filesystem::path tilelist = ".tilelist";
static boost::filesystem::path vmtile = ".vmtile";
}

namespace MMAP
{
    MapTileBuilder::MapTileBuilder(MapBuilder* mapBuilder, Optional<float> maxWalkableAngle, Optional<float> maxWalkableAngleNotSteep,
        bool skipLiquid, bool bigBaseUnit, bool debugOutput, std::vector<OffMeshData> const* offMeshConnections) :
        TileBuilder(maxWalkableAngle, maxWalkableAngleNotSteep, skipLiquid, bigBaseUnit, debugOutput, offMeshConnections),
        m_mapBuilder(mapBuilder),
        m_workerThread(&MapTileBuilder::WorkerThread, this)
    {
    }

    MapTileBuilder::~MapTileBuilder()
    {
        WaitCompletion();
    }

    void MapTileBuilder::WaitCompletion()
    {
        if (m_workerThread.joinable())
            m_workerThread.join();
    }

    void MapTileBuilder::OnTileDone()
    {
        ++m_mapBuilder->m_totalTilesProcessed;
    }

    MapBuilder::MapBuilder(Optional<float> maxWalkableAngle, Optional<float> maxWalkableAngleNotSteep, bool skipLiquid,
        bool skipContinents, bool skipJunkMaps, bool skipBattlegrounds,
        bool debugOutput, bool bigBaseUnit, int mapid, char const* offMeshFilePath, unsigned int threads) :
        m_debugOutput        (debugOutput),
        m_threads            (threads),
        m_skipContinents     (skipContinents),
        m_skipJunkMaps       (skipJunkMaps),
        m_skipBattlegrounds  (skipBattlegrounds),
        m_skipLiquid         (skipLiquid),
        m_maxWalkableAngle   (maxWalkableAngle),
        m_maxWalkableAngleNotSteep (maxWalkableAngleNotSteep),
        m_bigBaseUnit        (bigBaseUnit),
        m_mapid              (mapid),
        m_totalTiles         (0u),
        m_totalTilesProcessed(0u),
        _cancelationToken    (false)
    {

        // At least 1 thread is needed
        m_threads = std::max(1u, m_threads);

        discoverTiles();

        ParseOffMeshConnectionsFile(offMeshFilePath);
    }

    /**************************************************************************/
    MapBuilder::~MapBuilder()
    {
        _cancelationToken = true;

        _queue.Cancel();

        m_tileBuilders.clear();
        m_tiles.clear();
    }

    /**************************************************************************/
    void MapBuilder::discoverTiles()
    {
        boost::filesystem::directory_iterator end;
        for (auto itr = boost::filesystem::directory_iterator("maps"); itr != end; ++itr)
        {
            if (!boost::filesystem::is_regular_file(*itr))
                continue;

            if (itr->path().extension() != FileExtensions::tilelist)
                continue;

            Optional<uint32> mapId = Trinity::StringTo<uint32>(std::string_view(itr->path().filename().string()).substr(0, 4));
            if (!mapId)
                continue;

            if (shouldSkipMap(*mapId))
                continue;

            if (auto tileList = Trinity::make_unique_ptr_with_deleter<&::fclose>(fopen(itr->path().string().c_str(), "rb")))
            {
                u_map_magic mapMagic = { };
                uint32 versionMagic = { };
                uint32 build;
                char tilesData[64 * 64] = { };
                if (fread(mapMagic.data(), mapMagic.size(), 1, tileList.get()) == 1
                    && mapMagic == MapMagic
                    && fread(&versionMagic, sizeof(versionMagic), 1, tileList.get()) == 1
                    && versionMagic == MapVersionMagic
                    && fread(&build, sizeof(build), 1, tileList.get()) == 1
                    && fread(std::data(tilesData), std::size(tilesData), 1, tileList.get()) == 1)
                {
                    Trinity::Containers::FlatSet<uint32>& tiles = m_tiles[*mapId];
                    for (uint32 tileX = 0; tileX < 64; ++tileX)
                        for (uint32 tileY = 0; tileY < 64; ++tileY)
                            if (tilesData[std::size(tilesData) - 1 - (tileX * 64 + tileY)] == '1')
                                if (tiles.insert(VMAP::StaticMapTree::packTileID(tileX, tileY)).second)
                                    ++m_totalTiles;
                }
            }
        }

        for (auto itr = boost::filesystem::directory_iterator("vmaps"); itr != end; ++itr)
        {
            if (!boost::filesystem::is_directory(*itr))
                continue;

            Optional<uint32> mapId = Trinity::StringTo<uint32>(itr->path().filename().string());
            if (!mapId)
                continue;

            if (shouldSkipMap(*mapId))
                continue;

            Trinity::Containers::FlatSet<uint32>& tiles = m_tiles[*mapId];
            for (auto fileItr = boost::filesystem::directory_iterator(*itr); fileItr != end; ++fileItr)
            {
                if (!boost::filesystem::is_regular_file(*fileItr))
                    continue;

                if (fileItr->path().extension() != FileExtensions::vmtile)
                    continue;

                std::string fileName = fileItr->path().filename().string();

                uint32 tileX = Trinity::StringTo<uint32>(std::string_view(fileName).substr(5, 2)).value_or(0);
                uint32 tileY = Trinity::StringTo<uint32>(std::string_view(fileName).substr(8, 2)).value_or(0);
                uint32 tileID = VMAP::StaticMapTree::packTileID(tileX, tileY);

                if (tiles.insert(tileID).second)
                    ++m_totalTiles;
            }
        }

        TC_LOG_INFO("maps.mmapgen", "Discovering maps... found {}.", m_tiles.size());
        TC_LOG_INFO("maps.mmapgen", "Discovering tiles... found {}.\n", m_totalTiles);
    }

    /**************************************************************************/
    void MapBuilder::ParseOffMeshConnectionsFile(char const* offMeshFilePath)
    {
        // no meshfile input given?
        if (offMeshFilePath == nullptr)
            return;

        auto fp = Trinity::make_unique_ptr_with_deleter<&::fclose>(fopen(offMeshFilePath, "rb"));
        if (!fp)
        {
            TC_LOG_ERROR("maps.mmapgen", "MapBuilder::loadOffMeshConnections:: input file {} not found!", offMeshFilePath);
            return;
        }

        char buf[512] = { };
        while (fgets(buf, 512, fp.get()))
        {
            OffMeshData offMesh;
            int32 scanned = sscanf(buf, "%u %u,%u (%f %f %f) (%f %f %f) %f %hhu %hu", &offMesh.MapId, &offMesh.TileX, &offMesh.TileY,
                &offMesh.From[0], &offMesh.From[1], &offMesh.From[2], &offMesh.To[0], &offMesh.To[1], &offMesh.To[2],
                &offMesh.Radius, &offMesh.AreaId, &offMesh.Flags);
            if (scanned < 10)
                continue;

            offMesh.Bidirectional = true;
            if (scanned < 12)
                offMesh.Flags = NAV_GROUND;

            if (scanned < 11)
                offMesh.AreaId = NAV_AREA_GROUND;

            m_offMeshConnections.push_back(offMesh);
        }
    }

    /**************************************************************************/
    std::span<uint32 const> MapBuilder::getTileList(uint32 mapID) const
    {
        if (Trinity::Containers::FlatSet<uint32> const* tiles = Trinity::Containers::MapGetValuePtr(m_tiles, mapID))
            return *tiles;

        return { };
    }

    /**************************************************************************/

    void MapTileBuilder::WorkerThread()
    {
        while (true)
        {
            TileInfo tileInfo;

            m_mapBuilder->_queue.WaitAndPop(tileInfo);

            if (m_mapBuilder->_cancelationToken)
                return;

            dtNavMesh* navMesh = dtAllocNavMesh();
            if (!navMesh->init(&tileInfo.m_navMeshParams))
            {
                TC_LOG_ERROR("maps.mmapgen", "[Map {:04}] Failed creating navmesh for tile {},{} !", tileInfo.m_mapId, tileInfo.m_tileX, tileInfo.m_tileY);
                dtFreeNavMesh(navMesh);
                return;
            }

            buildTile(tileInfo.m_mapId, tileInfo.m_tileX, tileInfo.m_tileY, navMesh);

            dtFreeNavMesh(navMesh);
        }
    }

    void MapBuilder::buildMaps(Optional<uint32> mapID)
    {
        TC_LOG_INFO("maps.mmapgen", "Using {} threads to generate mmaps", m_threads);

        m_tileBuilders.resize(m_threads);
        for (unsigned int i = 0; i < m_threads; ++i)
            m_tileBuilders[i].reset(new MapTileBuilder(this, m_maxWalkableAngle, m_maxWalkableAngleNotSteep,
                m_skipLiquid, m_bigBaseUnit, m_debugOutput, &m_offMeshConnections));

        if (mapID)
        {
            buildMap(*mapID);
        }
        else
        {
            // Build all maps if no map id has been specified
            for (auto& [mapId, _] : m_tiles)
                buildMap(mapId);
        }

        while (!_queue.Empty())
        {
            std::this_thread::sleep_for(std::chrono::milliseconds(1000));
        }

        _cancelationToken = true;

        _queue.Cancel();

        m_tileBuilders.clear();
    }

    /**************************************************************************/
    void MapBuilder::buildMeshFromFile(char* name)
    {
        auto file = Trinity::make_unique_ptr_with_deleter<&::fclose>(fopen(name, "rb"));
        if (!file)
            return;

        TC_LOG_INFO("maps.mmapgen", "Building mesh from file");
        int tileX, tileY, mapId;
        if (fread(&mapId, sizeof(int), 1, file.get()) != 1)
            return;

        if (fread(&tileX, sizeof(int), 1, file.get()) != 1)
            return;

        if (fread(&tileY, sizeof(int), 1, file.get()) != 1)
            return;

        dtNavMesh* navMesh = nullptr;
        buildNavMesh(mapId, navMesh);
        if (!navMesh)
        {
            TC_LOG_ERROR("maps.mmapgen", "Failed creating navmesh!");
            return;
        }

        uint32 verticesCount, indicesCount;
        if (fread(&verticesCount, sizeof(uint32), 1, file.get()) != 1)
            return;

        if (fread(&indicesCount, sizeof(uint32), 1, file.get()) != 1)
            return;

        MeshData data;

        data.solidVerts.resize(verticesCount);
        if (fread(data.solidVerts.data(), sizeof(float), verticesCount, file.get()) != verticesCount)
            return;

        data.solidTris.resize(indicesCount);
        if (fread(data.solidTris.data(), sizeof(int), indicesCount, file.get()) != indicesCount)
            return;

        TerrainBuilder::cleanVertices(data.solidVerts, data.solidTris);
        // get bounds of current tile
        float bmin[3], bmax[3];
        TileBuilder::getTileBounds(tileX, tileY, data.solidVerts.data(), data.solidVerts.size() / 3, bmin, bmax);

        // build navmesh tile
        MapTileBuilder tileBuilder(this, m_maxWalkableAngle, m_maxWalkableAngleNotSteep,
            m_skipLiquid, m_bigBaseUnit, m_debugOutput, &m_offMeshConnections);
        tileBuilder.buildMoveMapTile(mapId, tileX, tileY, data, bmin, bmax, navMesh);
    }

    /**************************************************************************/
    void MapBuilder::buildSingleTile(uint32 mapID, uint32 tileX, uint32 tileY)
    {
        dtNavMesh* navMesh = nullptr;
        buildNavMesh(mapID, navMesh);
        if (!navMesh)
        {
            TC_LOG_ERROR("maps.mmapgen", "Failed creating navmesh!");
            return;
        }

        // ToDo: delete the old tile as the user clearly wants to rebuild it

        MapTileBuilder tileBuilder(this, m_maxWalkableAngle, m_maxWalkableAngleNotSteep,
            m_skipLiquid, m_bigBaseUnit, m_debugOutput, &m_offMeshConnections);
        tileBuilder.buildTile(mapID, tileX, tileY, navMesh);
        dtFreeNavMesh(navMesh);

        _cancelationToken = true;

        _queue.Cancel();
    }

    /**************************************************************************/
    void MapBuilder::buildMap(uint32 mapID)
    {
        std::span<uint32 const> tiles = getTileList(mapID);

        if (!tiles.empty())
        {
            // build navMesh
            dtNavMesh* navMesh = nullptr;
            buildNavMesh(mapID, navMesh);
            if (!navMesh)
            {
                TC_LOG_ERROR("maps.mmapgen", "[Map {:04}] Failed creating navmesh!", mapID);
                m_totalTilesProcessed += tiles.size();
                return;
            }

            // now start building mmtiles for each tile
            TC_LOG_INFO("maps.mmapgen", "[Map {:04}] We have {} tiles.", mapID, tiles.size());
            for (uint32 packedTile : tiles)
            {
                uint32 tileX, tileY;

                // unpack tile coords
                VMAP::StaticMapTree::unpackTileID(packedTile, tileX, tileY);

                TileInfo tileInfo;
                tileInfo.m_mapId = mapID;
                tileInfo.m_tileX = tileX;
                tileInfo.m_tileY = tileY;
                memcpy(&tileInfo.m_navMeshParams, navMesh->getParams(), sizeof(dtNavMeshParams));
                _queue.Push(tileInfo);
            }

            dtFreeNavMesh(navMesh);
        }
    }

    /**************************************************************************/
    void MapBuilder::buildNavMesh(uint32 mapID, dtNavMesh* &navMesh)
    {
        // if map has a parent we use that to generate dtNavMeshParams - worldserver will load all missing tiles from that map
        int32 navMeshParamsMapId = mapID;
        int32 parentMapId = sMapStore[mapID].ParentMapID;
        while (parentMapId != -1)
        {
            navMeshParamsMapId = parentMapId;
            parentMapId = sMapStore[parentMapId].ParentMapID;
        }

        std::span<uint32 const> tiles = getTileList(navMeshParamsMapId);

        // old code for non-statically assigned bitmask sizes:
        ///*** calculate number of bits needed to store tiles & polys ***/
        //int tileBits = dtIlog2(dtNextPow2(tiles->size()));
        //if (tileBits < 1) tileBits = 1;                                     // need at least one bit!
        //int polyBits = sizeof(dtPolyRef)*8 - SALT_MIN_BITS - tileBits;

        int polyBits = DT_POLY_BITS;

        int maxTiles = tiles.size();
        int maxPolysPerTile = 1 << polyBits;

        /***          calculate bounds of map         ***/

        uint32 tileXMin = 64, tileYMin = 64, tileXMax = 0, tileYMax = 0, tileX, tileY;
        for (uint32 packedTile : tiles)
        {
            VMAP::StaticMapTree::unpackTileID(packedTile, tileX, tileY);

            if (tileX > tileXMax)
                tileXMax = tileX;
            else if (tileX < tileXMin)
                tileXMin = tileX;

            if (tileY > tileYMax)
                tileYMax = tileY;
            else if (tileY < tileYMin)
                tileYMin = tileY;
        }

        // use Max because '32 - tileX' is negative for values over 32
        float bmin[3], bmax[3];
        TileBuilder::getTileBounds(tileXMax, tileYMax, nullptr, 0, bmin, bmax);

        /***       now create the navmesh       ***/

        // navmesh creation params
        dtNavMeshParams navMeshParams;
        memset(&navMeshParams, 0, sizeof(dtNavMeshParams));
        navMeshParams.tileWidth = GRID_SIZE;
        navMeshParams.tileHeight = GRID_SIZE;
        rcVcopy(navMeshParams.orig, bmin);
        navMeshParams.maxTiles = maxTiles;
        navMeshParams.maxPolys = maxPolysPerTile;

        navMesh = dtAllocNavMesh();
        TC_LOG_INFO("maps.mmapgen", "[Map {:04}] Creating navMesh...", mapID);
        if (!navMesh->init(&navMeshParams))
        {
            TC_LOG_ERROR("maps.mmapgen", "[Map {:04}] Failed creating navmesh!", mapID);
            return;
        }

        std::string fileName = Trinity::StringFormat("mmaps/{:04}.mmap", mapID);

        auto file = Trinity::make_unique_ptr_with_deleter<&::fclose>(fopen(fileName.c_str(), "wb"));
        if (!file)
        {
            dtFreeNavMesh(navMesh);
            navMesh = nullptr;
            TC_LOG_ERROR("maps.mmapgen", "{}: [Map {:04}] Failed to open {} for writing!\n", strerror(errno), mapID, fileName);
            return;
        }

        // now that we know navMesh params are valid, we can write them to file
        fwrite(&navMeshParams, sizeof(dtNavMeshParams), 1, file.get());
    }

    /**************************************************************************/
    bool MapBuilder::shouldSkipMap(uint32 mapID) const
    {
        if (m_mapid >= 0)
        {
            int32 parentMapId = m_mapid;
            do
            {
                if (static_cast<uint32>(parentMapId) == mapID)
                    return false;

                parentMapId = sMapStore[parentMapId].ParentMapID;

            } while (parentMapId != -1);

            return true;
        }

        if (m_skipContinents)
            if (isContinentMap(mapID))
                return true;

        if (m_skipJunkMaps)
        {
            if (isDevMap(mapID))
                return true;

            if (isTransportMap(mapID))
                return true;
        }

        if (m_skipBattlegrounds)
        {
            if (isBattlegroundMap(mapID))
                return true;
        }

        return false;
    }

    /**************************************************************************/
    bool MapBuilder::isTransportMap(uint32 mapID) const
    {
        if (MapEntry const* map = Trinity::Containers::MapGetValuePtr(sMapStore, mapID))
            return map->MapType == 3;

        return false;
    }

    bool MapBuilder::isDevMap(uint32 mapID) const
    {
        if (MapEntry const* map = Trinity::Containers::MapGetValuePtr(sMapStore, mapID))
            return (map->Flags & 0x2) != 0;

        return false;
    }

    bool MapBuilder::isBattlegroundMap(uint32 mapID) const
    {
        if (MapEntry const* map = Trinity::Containers::MapGetValuePtr(sMapStore, mapID))
            return map->InstanceType == 3;

        return false;
    }

    bool MapBuilder::isContinentMap(uint32 mapID) const
    {
        switch (mapID)
        {
            case 0:
            case 1:
            case 530:
            case 571:
            case 870:
            case 1116:
            case 1220:
            case 1642:
            case 1643:
            case 2222:
                return true;
            default:
                return false;
        }
    }

    /**************************************************************************/
    bool MapTileBuilder::shouldSkipTile(uint32 mapID, uint32 tileX, uint32 tileY) const
    {
        std::string fileName = Trinity::StringFormat("mmaps/{:04}{:02}{:02}.mmtile", mapID, tileX, tileY);
        auto file = Trinity::make_unique_ptr_with_deleter<&::fclose>(fopen(fileName.c_str(), "rb"));
        if (!file)
            return false;

        MmapTileHeader header;
        int count = fread(&header, sizeof(MmapTileHeader), 1, file.get());
        if (count != 1)
            return false;

        if (header.mmapMagic != MMAP_MAGIC || header.dtVersion != uint32(DT_NAVMESH_VERSION))
            return false;

        if (header.mmapVersion != MMAP_VERSION)
            return false;

        return TileBuilder::shouldSkipTile(mapID, tileX, tileY);
    }

    std::string MapTileBuilder::GetProgressText() const
    {
        return Trinity::StringFormat("{}%", m_mapBuilder->currentPercentageDone());
    }

    /**************************************************************************/
    uint32 MapBuilder::percentageDone(uint32 totalTiles, uint32 totalTilesBuilt) const
    {
        if (totalTiles)
            return totalTilesBuilt * 100 / totalTiles;

        return 0;
    }

    uint32 MapBuilder::currentPercentageDone() const
    {
        return percentageDone(m_totalTiles, m_totalTilesProcessed);
    }

}
