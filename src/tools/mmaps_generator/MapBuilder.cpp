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
#include "IntermediateValues.h"
#include "MapDefines.h"
#include "MapTree.h"
#include "MapUtils.h"
#include "Memory.h"
#include "MMapDefines.h"
#include "ModelInstance.h"
#include "PathCommon.h"
#include "StringConvert.h"
#include "StringFormat.h"
#include <DetourNavMesh.h>
#include <DetourNavMeshBuilder.h>
#include <boost/filesystem/directory.hpp>
#include <climits>

namespace FileExtensions
{
static boost::filesystem::path tilelist = ".tilelist";
static boost::filesystem::path vmtile = ".vmtile";
}

namespace MMAP
{
    TileBuilder::TileBuilder(MapBuilder* mapBuilder, bool skipLiquid, bool bigBaseUnit, bool debugOutput) :
        m_bigBaseUnit(bigBaseUnit),
        m_debugOutput(debugOutput),
        m_mapBuilder(mapBuilder),
        m_terrainBuilder(nullptr),
        m_workerThread(&TileBuilder::WorkerThread, this),
        m_rcContext(nullptr)
    {
        m_terrainBuilder = new TerrainBuilder(skipLiquid);
        m_rcContext = new rcContext(false);
    }

    TileBuilder::~TileBuilder()
    {
        WaitCompletion();

        delete m_terrainBuilder;
        delete m_rcContext;
    }

    void TileBuilder::WaitCompletion()
    {
        if (m_workerThread.joinable())
            m_workerThread.join();
    }

    MapBuilder::MapBuilder(Optional<float> maxWalkableAngle, Optional<float> maxWalkableAngleNotSteep, bool skipLiquid,
        bool skipContinents, bool skipJunkMaps, bool skipBattlegrounds,
        bool debugOutput, bool bigBaseUnit, int mapid, char const* offMeshFilePath, unsigned int threads) :
        m_terrainBuilder     (nullptr),
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
        m_rcContext          (nullptr),
        _cancelationToken    (false)
    {
        m_terrainBuilder = new TerrainBuilder(skipLiquid);

        m_rcContext = new rcContext(false);

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

        for (auto& builder : m_tileBuilders)
            delete builder;

        m_tileBuilders.clear();
        m_tiles.clear();

        delete m_terrainBuilder;
        delete m_rcContext;
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
                    && fread(std::data(tilesData), 64 * 64, 1, tileList.get()) == 1)
                {
                    Trinity::Containers::FlatSet<uint32>& tiles = m_tiles[*mapId];
                    for (uint32 tileX = 0; tileX < 64; ++tileX)
                        for (uint32 tileY = 0; tileY < 64; ++tileY)
                            if (tilesData[tileX * 64 + tileY] == '1')
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

                uint32 tileX = Trinity::StringTo<uint32>(std::string_view(fileName).substr(8, 2)).value_or(0);
                uint32 tileY = Trinity::StringTo<uint32>(std::string_view(fileName).substr(5, 2)).value_or(0);
                uint32 tileID = VMAP::StaticMapTree::packTileID(tileY, tileX);

                if (tiles.insert(tileID).second)
                    ++m_totalTiles;
            }
        }

        printf("Discovering maps... found %u.\n", uint32(m_tiles.size()));
        printf("Discovering tiles... found %u.\n\n", m_totalTiles);
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
            printf(" loadOffMeshConnections:: input file %s not found!\n", offMeshFilePath);
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

    void TileBuilder::WorkerThread()
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
                printf("[Map %04i] Failed creating navmesh for tile %i,%i !\n", tileInfo.m_mapId, tileInfo.m_tileX, tileInfo.m_tileY);
                dtFreeNavMesh(navMesh);
                return;
            }

            buildTile(tileInfo.m_mapId, tileInfo.m_tileX, tileInfo.m_tileY, navMesh);

            dtFreeNavMesh(navMesh);
        }
    }

    void MapBuilder::buildMaps(Optional<uint32> mapID)
    {
        printf("Using %u threads to generate mmaps\n", m_threads);

        for (unsigned int i = 0; i < m_threads; ++i)
        {
            m_tileBuilders.push_back(new TileBuilder(this, m_skipLiquid, m_bigBaseUnit, m_debugOutput));
        }

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

        for (auto& builder : m_tileBuilders)
            delete builder;

        m_tileBuilders.clear();
    }

    /**************************************************************************/
    void MapBuilder::buildMeshFromFile(char* name)
    {
        FILE* file = fopen(name, "rb");
        if (!file)
            return;

        printf("Building mesh from file\n");
        int tileX, tileY, mapId;
        if (fread(&mapId, sizeof(int), 1, file) != 1)
        {
            fclose(file);
            return;
        }
        if (fread(&tileX, sizeof(int), 1, file) != 1)
        {
            fclose(file);
            return;
        }
        if (fread(&tileY, sizeof(int), 1, file) != 1)
        {
            fclose(file);
            return;
        }

        dtNavMesh* navMesh = nullptr;
        buildNavMesh(mapId, navMesh);
        if (!navMesh)
        {
            printf("Failed creating navmesh!              \n");
            fclose(file);
            return;
        }

        uint32 verticesCount, indicesCount;
        if (fread(&verticesCount, sizeof(uint32), 1, file) != 1)
        {
            fclose(file);
            return;
        }

        if (fread(&indicesCount, sizeof(uint32), 1, file) != 1)
        {
            fclose(file);
            return;
        }

        float* verts = new float[verticesCount];

        if (fread(verts, sizeof(float), verticesCount, file) != verticesCount)
        {
            fclose(file);
            delete[] verts;
            return;
        }

        int* inds = new int[indicesCount];
        if (fread(inds, sizeof(int), indicesCount, file) != indicesCount)
        {
            fclose(file);
            delete[] verts;
            delete[] inds;
            return;
        }

        MeshData data;

        for (uint32 i = 0; i < verticesCount; ++i)
            data.solidVerts.append(verts[i]);
        delete[] verts;

        for (uint32 i = 0; i < indicesCount; ++i)
            data.solidTris.append(inds[i]);
        delete[] inds;

        TerrainBuilder::cleanVertices(data.solidVerts, data.solidTris);
        // get bounds of current tile
        float bmin[3], bmax[3];
        getTileBounds(tileX, tileY, data.solidVerts.getCArray(), data.solidVerts.size() / 3, bmin, bmax);

        // build navmesh tile
        TileBuilder tileBuilder = TileBuilder(this, m_skipLiquid, m_bigBaseUnit, m_debugOutput);
        tileBuilder.buildMoveMapTile(mapId, tileX, tileY, data, bmin, bmax, navMesh);
        fclose(file);
    }

    /**************************************************************************/
    void MapBuilder::buildSingleTile(uint32 mapID, uint32 tileX, uint32 tileY)
    {
        dtNavMesh* navMesh = nullptr;
        buildNavMesh(mapID, navMesh);
        if (!navMesh)
        {
            printf("Failed creating navmesh!              \n");
            return;
        }

        // ToDo: delete the old tile as the user clearly wants to rebuild it

        TileBuilder tileBuilder = TileBuilder(this, m_skipLiquid, m_bigBaseUnit, m_debugOutput);
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
                printf("[Map %04u] Failed creating navmesh!\n", mapID);
                m_totalTilesProcessed += tiles.size();
                return;
            }

            // now start building mmtiles for each tile
            printf("[Map %04u] We have %u tiles.                          \n", mapID, uint32(tiles.size()));
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
    void TileBuilder::buildTile(uint32 mapID, uint32 tileX, uint32 tileY, dtNavMesh* navMesh)
    {
        if(shouldSkipTile(mapID, tileX, tileY))
        {
            ++m_mapBuilder->m_totalTilesProcessed;
            return;
        }

        printf("%u%% [Map %04i] Building tile [%02u,%02u]\n", m_mapBuilder->currentPercentageDone(), mapID, tileX, tileY);

        MeshData meshData;

        // get heightmap data
        m_terrainBuilder->loadMap(mapID, tileX, tileY, meshData);

        // get model data
        m_terrainBuilder->loadVMap(mapID, tileY, tileX, meshData);

        // if there is no data, give up now
        if (!meshData.solidVerts.size() && !meshData.liquidVerts.size())
        {
            ++m_mapBuilder->m_totalTilesProcessed;
            return;
        }

        // remove unused vertices
        TerrainBuilder::cleanVertices(meshData.solidVerts, meshData.solidTris);
        TerrainBuilder::cleanVertices(meshData.liquidVerts, meshData.liquidTris);

        // gather all mesh data for final data check, and bounds calculation
        G3D::Array<float> allVerts;
        allVerts.append(meshData.liquidVerts);
        allVerts.append(meshData.solidVerts);

        if (!allVerts.size())
        {
            ++m_mapBuilder->m_totalTilesProcessed;
            return;
        }

        // get bounds of current tile
        float bmin[3], bmax[3];
        m_mapBuilder->getTileBounds(tileX, tileY, allVerts.getCArray(), allVerts.size() / 3, bmin, bmax);

        m_terrainBuilder->loadOffMeshConnections(mapID, tileX, tileY, meshData, m_mapBuilder->m_offMeshConnections);

        // build navmesh tile
        buildMoveMapTile(mapID, tileX, tileY, meshData, bmin, bmax, navMesh);

        ++m_mapBuilder->m_totalTilesProcessed;
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
        getTileBounds(tileXMax, tileYMax, nullptr, 0, bmin, bmax);

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
        printf("[Map %04u] Creating navMesh...\n", mapID);
        if (!navMesh->init(&navMeshParams))
        {
            printf("[Map %04u] Failed creating navmesh!                \n", mapID);
            return;
        }

        std::string fileName = Trinity::StringFormat("mmaps/{:04}.mmap", mapID);

        FILE* file = fopen(fileName.c_str(), "wb");
        if (!file)
        {
            dtFreeNavMesh(navMesh);
            navMesh = nullptr;
            perror(Trinity::StringFormat("[Map {:04}] Failed to open {} for writing!\n", mapID, fileName).c_str());
            return;
        }

        // now that we know navMesh params are valid, we can write them to file
        fwrite(&navMeshParams, sizeof(dtNavMeshParams), 1, file);
        fclose(file);
    }

    /**************************************************************************/
    void TileBuilder::buildMoveMapTile(uint32 mapID, uint32 tileX, uint32 tileY,
        MeshData &meshData, float bmin[3], float bmax[3],
        dtNavMesh* navMesh)
    {
        // console output
        std::string tileString = Trinity::StringFormat("[Map {:04}] [{:02},{:02}]: ", mapID, tileX, tileY);
        printf("%s Building movemap tiles...\n", tileString.c_str());

        IntermediateValues iv;

        float* tVerts = meshData.solidVerts.getCArray();
        int tVertCount = meshData.solidVerts.size() / 3;
        int* tTris = meshData.solidTris.getCArray();
        int tTriCount = meshData.solidTris.size() / 3;

        float* lVerts = meshData.liquidVerts.getCArray();
        int lVertCount = meshData.liquidVerts.size() / 3;
        int* lTris = meshData.liquidTris.getCArray();
        int lTriCount = meshData.liquidTris.size() / 3;
        uint8* lTriFlags = meshData.liquidType.getCArray();

        const TileConfig tileConfig = TileConfig(m_bigBaseUnit);
        int TILES_PER_MAP = tileConfig.TILES_PER_MAP;
        float BASE_UNIT_DIM = tileConfig.BASE_UNIT_DIM;
        rcConfig config = m_mapBuilder->GetMapSpecificConfig(mapID, bmin, bmax, tileConfig);

        // this sets the dimensions of the heightfield - should maybe happen before border padding
        rcCalcGridSize(config.bmin, config.bmax, config.cs, &config.width, &config.height);

        // allocate subregions : tiles
        Tile* tiles = new Tile[TILES_PER_MAP * TILES_PER_MAP];

        // Initialize per tile config.
        rcConfig tileCfg = config;
        tileCfg.width = config.tileSize + config.borderSize*2;
        tileCfg.height = config.tileSize + config.borderSize*2;

        // merge per tile poly and detail meshes
        rcPolyMesh** pmmerge = new rcPolyMesh*[TILES_PER_MAP * TILES_PER_MAP];
        rcPolyMeshDetail** dmmerge = new rcPolyMeshDetail*[TILES_PER_MAP * TILES_PER_MAP];
        int nmerge = 0;
        // build all tiles
        for (int y = 0; y < TILES_PER_MAP; ++y)
        {
            for (int x = 0; x < TILES_PER_MAP; ++x)
            {
                Tile& tile = tiles[x + y * TILES_PER_MAP];

                // Calculate the per tile bounding box.
                tileCfg.bmin[0] = config.bmin[0] + x * float(config.tileSize * config.cs);
                tileCfg.bmin[2] = config.bmin[2] + y * float(config.tileSize * config.cs);
                tileCfg.bmax[0] = config.bmin[0] + (x + 1) * float(config.tileSize * config.cs);
                tileCfg.bmax[2] = config.bmin[2] + (y + 1) * float(config.tileSize * config.cs);

                tileCfg.bmin[0] -= tileCfg.borderSize * tileCfg.cs;
                tileCfg.bmin[2] -= tileCfg.borderSize * tileCfg.cs;
                tileCfg.bmax[0] += tileCfg.borderSize * tileCfg.cs;
                tileCfg.bmax[2] += tileCfg.borderSize * tileCfg.cs;

                // build heightfield
                tile.solid = rcAllocHeightfield();
                if (!tile.solid || !rcCreateHeightfield(m_rcContext, *tile.solid, tileCfg.width, tileCfg.height, tileCfg.bmin, tileCfg.bmax, tileCfg.cs, tileCfg.ch))
                {
                    printf("%s Failed building heightfield!            \n", tileString.c_str());
                    continue;
                }

                // mark all walkable tiles, both liquids and solids

                /* we want to have triangles with slope less than walkableSlopeAngleNotSteep (<= 55) to have NAV_AREA_GROUND
                 * and with slope between walkableSlopeAngleNotSteep and walkableSlopeAngle (55 < .. <= 70) to have NAV_AREA_GROUND_STEEP.
                 * we achieve this using recast API: memset everything to NAV_AREA_GROUND_STEEP, call rcClearUnwalkableTriangles with 70 so
                 * any area above that will get RC_NULL_AREA (unwalkable), then call rcMarkWalkableTriangles with 55 to set NAV_AREA_GROUND
                 * on anything below 55 . Players and idle Creatures can use NAV_AREA_GROUND, while Creatures in combat can use NAV_AREA_GROUND_STEEP.
                 */
                unsigned char* triFlags = new unsigned char[tTriCount];
                memset(triFlags, NAV_AREA_GROUND_STEEP, tTriCount*sizeof(unsigned char));
                rcClearUnwalkableTriangles(m_rcContext, tileCfg.walkableSlopeAngle, tVerts, tVertCount, tTris, tTriCount, triFlags);
                rcMarkWalkableTriangles(m_rcContext, tileCfg.walkableSlopeAngleNotSteep, tVerts, tVertCount, tTris, tTriCount, triFlags, NAV_AREA_GROUND);
                rcRasterizeTriangles(m_rcContext, tVerts, tVertCount, tTris, triFlags, tTriCount, *tile.solid, config.walkableClimb);
                delete[] triFlags;

                rcFilterLowHangingWalkableObstacles(m_rcContext, config.walkableClimb, *tile.solid);
                rcFilterLedgeSpans(m_rcContext, tileCfg.walkableHeight, tileCfg.walkableClimb, *tile.solid);
                rcFilterWalkableLowHeightSpans(m_rcContext, tileCfg.walkableHeight, *tile.solid);

                // add liquid triangles
                rcRasterizeTriangles(m_rcContext, lVerts, lVertCount, lTris, lTriFlags, lTriCount, *tile.solid, config.walkableClimb);

                // compact heightfield spans
                tile.chf = rcAllocCompactHeightfield();
                if (!tile.chf || !rcBuildCompactHeightfield(m_rcContext, tileCfg.walkableHeight, tileCfg.walkableClimb, *tile.solid, *tile.chf))
                {
                    printf("%s Failed compacting heightfield!            \n", tileString.c_str());
                    continue;
                }

                // build polymesh intermediates
                if (!rcErodeWalkableArea(m_rcContext, config.walkableRadius, *tile.chf))
                {
                    printf("%s Failed eroding area!                    \n", tileString.c_str());
                    continue;
                }

                if (!rcMedianFilterWalkableArea(m_rcContext, *tile.chf))
                {
                    printf("%s Failed filtering area!                  \n", tileString.c_str());
                    continue;
                }

                if (!rcBuildDistanceField(m_rcContext, *tile.chf))
                {
                    printf("%s Failed building distance field!         \n", tileString.c_str());
                    continue;
                }

                if (!rcBuildRegions(m_rcContext, *tile.chf, tileCfg.borderSize, tileCfg.minRegionArea, tileCfg.mergeRegionArea))
                {
                    printf("%s Failed building regions!                \n", tileString.c_str());
                    continue;
                }

                tile.cset = rcAllocContourSet();
                if (!tile.cset || !rcBuildContours(m_rcContext, *tile.chf, tileCfg.maxSimplificationError, tileCfg.maxEdgeLen, *tile.cset))
                {
                    printf("%s Failed building contours!               \n", tileString.c_str());
                    continue;
                }

                // build polymesh
                tile.pmesh = rcAllocPolyMesh();
                if (!tile.pmesh || !rcBuildPolyMesh(m_rcContext, *tile.cset, tileCfg.maxVertsPerPoly, *tile.pmesh))
                {
                    printf("%s Failed building polymesh!               \n", tileString.c_str());
                    continue;
                }

                tile.dmesh = rcAllocPolyMeshDetail();
                if (!tile.dmesh || !rcBuildPolyMeshDetail(m_rcContext, *tile.pmesh, *tile.chf, tileCfg.detailSampleDist, tileCfg.detailSampleMaxError, *tile.dmesh))
                {
                    printf("%s Failed building polymesh detail!        \n", tileString.c_str());
                    continue;
                }

                // free those up
                // we may want to keep them in the future for debug
                // but right now, we don't have the code to merge them
                rcFreeHeightField(tile.solid);
                tile.solid = nullptr;
                rcFreeCompactHeightfield(tile.chf);
                tile.chf = nullptr;
                rcFreeContourSet(tile.cset);
                tile.cset = nullptr;

                pmmerge[nmerge] = tile.pmesh;
                dmmerge[nmerge] = tile.dmesh;
                nmerge++;
            }
        }

        iv.polyMesh = rcAllocPolyMesh();
        if (!iv.polyMesh)
        {
            printf("%s alloc iv.polyMesh FAILED!\n", tileString.c_str());
            delete[] pmmerge;
            delete[] dmmerge;
            delete[] tiles;
            return;
        }
        rcMergePolyMeshes(m_rcContext, pmmerge, nmerge, *iv.polyMesh);

        iv.polyMeshDetail = rcAllocPolyMeshDetail();
        if (!iv.polyMeshDetail)
        {
            printf("%s alloc m_dmesh FAILED!\n", tileString.c_str());
            delete[] pmmerge;
            delete[] dmmerge;
            delete[] tiles;
            return;
        }
        rcMergePolyMeshDetails(m_rcContext, dmmerge, nmerge, *iv.polyMeshDetail);

        // free things up
        delete[] pmmerge;
        delete[] dmmerge;
        delete[] tiles;

        // set polygons as walkable
        // TODO: special flags for DYNAMIC polygons, ie surfaces that can be turned on and off
        for (int i = 0; i < iv.polyMesh->npolys; ++i)
        {
            if (uint8 area = iv.polyMesh->areas[i] & NAV_AREA_ALL_MASK)
            {
                if (area >= NAV_AREA_MIN_VALUE)
                    iv.polyMesh->flags[i] = 1 << (NAV_AREA_MAX_VALUE - area);
                else
                    iv.polyMesh->flags[i] = NAV_GROUND; // TODO: these will be dynamic in future
            }
        }

        // setup mesh parameters
        dtNavMeshCreateParams params;
        memset(&params, 0, sizeof(params));
        params.verts = iv.polyMesh->verts;
        params.vertCount = iv.polyMesh->nverts;
        params.polys = iv.polyMesh->polys;
        params.polyAreas = iv.polyMesh->areas;
        params.polyFlags = iv.polyMesh->flags;
        params.polyCount = iv.polyMesh->npolys;
        params.nvp = iv.polyMesh->nvp;
        params.detailMeshes = iv.polyMeshDetail->meshes;
        params.detailVerts = iv.polyMeshDetail->verts;
        params.detailVertsCount = iv.polyMeshDetail->nverts;
        params.detailTris = iv.polyMeshDetail->tris;
        params.detailTriCount = iv.polyMeshDetail->ntris;

        params.offMeshConVerts = meshData.offMeshConnections.getCArray();
        params.offMeshConCount = meshData.offMeshConnections.size()/6;
        params.offMeshConRad = meshData.offMeshConnectionRads.getCArray();
        params.offMeshConDir = meshData.offMeshConnectionDirs.getCArray();
        params.offMeshConAreas = meshData.offMeshConnectionsAreas.getCArray();
        params.offMeshConFlags = meshData.offMeshConnectionsFlags.getCArray();

        params.walkableHeight = BASE_UNIT_DIM*config.walkableHeight;    // agent height
        params.walkableRadius = BASE_UNIT_DIM*config.walkableRadius;    // agent radius
        params.walkableClimb = BASE_UNIT_DIM*config.walkableClimb;      // keep less that walkableHeight (aka agent height)!
        params.tileX = (((bmin[0] + bmax[0]) / 2) - navMesh->getParams()->orig[0]) / GRID_SIZE;
        params.tileY = (((bmin[2] + bmax[2]) / 2) - navMesh->getParams()->orig[2]) / GRID_SIZE;
        rcVcopy(params.bmin, bmin);
        rcVcopy(params.bmax, bmax);
        params.cs = config.cs;
        params.ch = config.ch;
        params.tileLayer = 0;
        params.buildBvTree = true;

        // will hold final navmesh
        unsigned char* navData = nullptr;
        int navDataSize = 0;

        do
        {
            // these values are checked within dtCreateNavMeshData - handle them here
            // so we have a clear error message
            if (params.nvp > DT_VERTS_PER_POLYGON)
            {
                printf("%s Invalid verts-per-polygon value!        \n", tileString.c_str());
                break;
            }
            if (params.vertCount >= 0xffff)
            {
                printf("%s Too many vertices!                      \n", tileString.c_str());
                break;
            }
            if (!params.vertCount || !params.verts)
            {
                // occurs mostly when adjacent tiles have models
                // loaded but those models don't span into this tile

                // message is an annoyance
                //printf("%sNo vertices to build tile!              \n", tileString.c_str());
                break;
            }
            if (!params.polyCount || !params.polys)
            {
                // we have flat tiles with no actual geometry - don't build those, its useless
                // keep in mind that we do output those into debug info
                printf("%s No polygons to build on tile!              \n", tileString.c_str());
                break;
            }
            if (!params.detailMeshes || !params.detailVerts || !params.detailTris)
            {
                printf("%s No detail mesh to build tile!           \n", tileString.c_str());
                break;
            }

            printf("%s Building navmesh tile...\n", tileString.c_str());
            if (!dtCreateNavMeshData(&params, &navData, &navDataSize))
            {
                printf("%s Failed building navmesh tile!           \n", tileString.c_str());
                break;
            }

            dtTileRef tileRef = 0;
            printf("%s Adding tile to navmesh...\n", tileString.c_str());
            // DT_TILE_FREE_DATA tells detour to unallocate memory when the tile
            // is removed via removeTile()
            dtStatus dtResult = navMesh->addTile(navData, navDataSize, DT_TILE_FREE_DATA, 0, &tileRef);
            if (!tileRef || !dtStatusSucceed(dtResult))
            {
                printf("%s Failed adding tile to navmesh!           \n", tileString.c_str());
                break;
            }

            // file output
            std::string fileName = Trinity::StringFormat("mmaps/{:04}{:02}{:02}.mmtile", mapID, tileY, tileX);
            FILE* file = fopen(fileName.c_str(), "wb");
            if (!file)
            {
                perror(Trinity::StringFormat("[Map {:04}] Failed to open {} for writing!\n", mapID, fileName).c_str());
                navMesh->removeTile(tileRef, nullptr, nullptr);
                break;
            }

            printf("%s Writing to file...\n", tileString.c_str());

            // write header
            MmapTileHeader header;
            header.usesLiquids = m_terrainBuilder->usesLiquids();
            header.size = uint32(navDataSize);
            fwrite(&header, sizeof(MmapTileHeader), 1, file);

            /*
            dtMeshHeader* navDataHeader = (dtMeshHeader*)navData;
            printf("Poly count: %d\n", navDataHeader->polyCount);
            */

            // write data
            fwrite(navData, sizeof(unsigned char), navDataSize, file);
            fclose(file);

            // now that tile is written to disk, we can unload it
            navMesh->removeTile(tileRef, nullptr, nullptr);
        }
        while (false);

        if (m_debugOutput)
        {
            // restore padding so that the debug visualization is correct
            for (int i = 0; i < iv.polyMesh->nverts; ++i)
            {
                unsigned short* v = &iv.polyMesh->verts[i*3];
                v[0] += (unsigned short)config.borderSize;
                v[2] += (unsigned short)config.borderSize;
            }

            iv.generateObjFile(mapID, tileX, tileY, meshData);
            iv.writeIV(mapID, tileX, tileY);
        }
    }

    /**************************************************************************/
    void MapBuilder::getTileBounds(uint32 tileX, uint32 tileY, float* verts, int vertCount, float* bmin, float* bmax) const
    {
        // this is for elevation
        if (verts && vertCount)
            rcCalcBounds(verts, vertCount, bmin, bmax);
        else
        {
            bmin[1] = FLT_MIN;
            bmax[1] = FLT_MAX;
        }

        // this is for width and depth
        bmax[0] = (32 - int(tileX)) * GRID_SIZE;
        bmax[2] = (32 - int(tileY)) * GRID_SIZE;
        bmin[0] = bmax[0] - GRID_SIZE;
        bmin[2] = bmax[2] - GRID_SIZE;
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
    bool TileBuilder::shouldSkipTile(uint32 mapID, uint32 tileX, uint32 tileY) const
    {
        std::string fileName = Trinity::StringFormat("mmaps/{:04}{:02}{:02}.mmtile", mapID, tileY, tileX);
        FILE* file = fopen(fileName.c_str(), "rb");
        if (!file)
            return false;

        MmapTileHeader header;
        int count = fread(&header, sizeof(MmapTileHeader), 1, file);
        fclose(file);
        if (count != 1)
            return false;

        if (header.mmapMagic != MMAP_MAGIC || header.dtVersion != uint32(DT_NAVMESH_VERSION))
            return false;

        if (header.mmapVersion != MMAP_VERSION)
            return false;

        return true;
    }

    rcConfig MapBuilder::GetMapSpecificConfig(uint32 mapID, float bmin[3], float bmax[3], const TileConfig &tileConfig) const
    {
        rcConfig config;
        memset(&config, 0, sizeof(rcConfig));

        rcVcopy(config.bmin, bmin);
        rcVcopy(config.bmax, bmax);

        config.maxVertsPerPoly = DT_VERTS_PER_POLYGON;
        config.cs = tileConfig.BASE_UNIT_DIM;
        config.ch = tileConfig.BASE_UNIT_DIM;
        // Keeping these 2 slope angles the same reduces a lot the number of polys.
        // 55 should be the minimum, maybe 70 is ok (keep in mind blink uses mmaps), 85 is too much for players
        config.walkableSlopeAngle = m_maxWalkableAngle ? *m_maxWalkableAngle : 55;
        config.walkableSlopeAngleNotSteep = m_maxWalkableAngleNotSteep ? *m_maxWalkableAngleNotSteep : 55;
        config.tileSize = tileConfig.VERTEX_PER_TILE;
        config.walkableRadius = m_bigBaseUnit ? 1 : 2;
        config.borderSize = config.walkableRadius + 3;
        config.maxEdgeLen = tileConfig.VERTEX_PER_TILE + 1;        // anything bigger than tileSize
        config.walkableHeight = m_bigBaseUnit ? 3 : 6;
        // a value >= 3|6 allows npcs to walk over some fences
        // a value >= 4|8 allows npcs to walk over all fences
        config.walkableClimb = m_bigBaseUnit ? 3 : 6;
        config.minRegionArea = rcSqr(60);
        config.mergeRegionArea = rcSqr(50);
        config.maxSimplificationError = 1.8f;           // eliminates most jagged edges (tiny polygons)
        config.detailSampleDist = config.cs * 16;
        config.detailSampleMaxError = config.ch * 1;

        switch (mapID)
        {
            // Blade's Edge Arena
            case 562:
                // This allows to walk on the ropes to the pillars
                config.walkableRadius = 0;
                break;
            // Blackfathom Deeps
            case 48:
                // Reduce the chance to have underground levels
                config.ch *= 2;
                break;
            default:
                break;
        }

        return config;
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
