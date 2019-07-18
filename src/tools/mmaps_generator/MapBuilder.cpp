/*
 * Copyright (C) 2008-2019 TrinityCore <https://www.trinitycore.org/>
 * Copyright (C) 2005-2011 MaNGOS <http://getmangos.com/>
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
#include "MapDefines.h"
#include "MapTree.h"
#include "ModelInstance.h"
#include "PathCommon.h"
#include "StringFormat.h"
#include "VMapFactory.h"
#include "VMapManager2.h"
#include <DetourCommon.h>
#include <DetourNavMesh.h>
#include <DetourNavMeshBuilder.h>
#include <climits>

namespace MMAP
{
    MapBuilder::MapBuilder(float maxWalkableAngle, bool skipLiquid,
        bool skipContinents, bool skipJunkMaps, bool skipBattlegrounds,
        bool debugOutput, bool bigBaseUnit, int mapid, const char* offMeshFilePath) :
        m_terrainBuilder     (NULL),
        m_debugOutput        (debugOutput),
        m_offMeshFilePath    (offMeshFilePath),
        m_skipContinents     (skipContinents),
        m_skipJunkMaps       (skipJunkMaps),
        m_skipBattlegrounds  (skipBattlegrounds),
        m_maxWalkableAngle   (maxWalkableAngle),
        m_bigBaseUnit        (bigBaseUnit),
        m_mapid              (mapid),
        m_totalTiles         (0u),
        m_totalTilesProcessed(0u),
        m_rcContext          (NULL),
        _cancelationToken    (false)
    {
        m_terrainBuilder = new TerrainBuilder(skipLiquid);

        m_rcContext = new rcContext(false);

        discoverTiles();
    }

    /**************************************************************************/
    MapBuilder::~MapBuilder()
    {
        for (TileList::iterator it = m_tiles.begin(); it != m_tiles.end(); ++it)
        {
            (*it).m_tiles->clear();
            delete (*it).m_tiles;
        }

        delete m_terrainBuilder;
        delete m_rcContext;
    }

    /**************************************************************************/
    void MapBuilder::discoverTiles()
    {
        std::vector<std::string> files;
        uint32 mapID, tileX, tileY, tileID, count = 0;

        printf("Discovering maps... ");
        getDirContents(files, "maps");
        for (uint32 i = 0; i < files.size(); ++i)
        {
            mapID = uint32(atoi(files[i].substr(0, 4).c_str()));
            if (std::find(m_tiles.begin(), m_tiles.end(), mapID) == m_tiles.end())
            {
                m_tiles.emplace_back(MapTiles(mapID, new std::set<uint32>));
                count++;
            }
        }

        files.clear();
        getDirContents(files, "vmaps", "*.vmtree");
        for (uint32 i = 0; i < files.size(); ++i)
        {
            mapID = uint32(atoi(files[i].substr(0, 4).c_str()));
            if (std::find(m_tiles.begin(), m_tiles.end(), mapID) == m_tiles.end())
            {
                m_tiles.emplace_back(MapTiles(mapID, new std::set<uint32>));
                count++;
            }
        }
        printf("found %u.\n", count);

        count = 0;
        printf("Discovering tiles... ");
        for (TileList::iterator itr = m_tiles.begin(); itr != m_tiles.end(); ++itr)
        {
            std::set<uint32>* tiles = (*itr).m_tiles;
            mapID = (*itr).m_mapId;

            files.clear();
            getDirContents(files, "vmaps", Trinity::StringFormat("%04u_*.vmtile", mapID));
            for (uint32 i = 0; i < files.size(); ++i)
            {
                tileX = uint32(atoi(files[i].substr(8, 2).c_str()));
                tileY = uint32(atoi(files[i].substr(5, 2).c_str()));
                tileID = StaticMapTree::packTileID(tileY, tileX);

                tiles->insert(tileID);
                count++;
            }

            files.clear();
            getDirContents(files, "maps", Trinity::StringFormat("%04u*", mapID));
            for (uint32 i = 0; i < files.size(); ++i)
            {
                tileY = uint32(atoi(files[i].substr(5, 2).c_str()));
                tileX = uint32(atoi(files[i].substr(8, 2).c_str()));
                tileID = StaticMapTree::packTileID(tileX, tileY);

                if (tiles->insert(tileID).second)
                    count++;
            }

            // make sure we process maps which don't have tiles
            if (tiles->empty())
            {
                // convert coord bounds to grid bounds
                uint32 minX, minY, maxX, maxY;
                getGridBounds(mapID, minX, minY, maxX, maxY);

                // add all tiles within bounds to tile list.
                for (uint32 i = minX; i <= maxX; ++i)
                    for (uint32 j = minY; j <= maxY; ++j)
                        if (tiles->insert(StaticMapTree::packTileID(i, j)).second)
                            count++;
            }
        }
        printf("found %u.\n\n", count);

        // Calculate tiles to process in total
        for (TileList::iterator it = m_tiles.begin(); it != m_tiles.end(); ++it)
        {
            if (!shouldSkipMap(it->m_mapId))
                m_totalTiles += it->m_tiles->size();
        }
    }

    /**************************************************************************/
    std::set<uint32>* MapBuilder::getTileList(uint32 mapID)
    {
        TileList::iterator itr = std::find(m_tiles.begin(), m_tiles.end(), mapID);
        if (itr != m_tiles.end())
            return (*itr).m_tiles;

        std::set<uint32>* tiles = new std::set<uint32>();
        m_tiles.emplace_back(MapTiles(mapID, tiles));
        return tiles;
    }

    /**************************************************************************/

    void MapBuilder::WorkerThread()
    {
        while (1)
        {
            uint32 mapId = 0;

            _queue.WaitAndPop(mapId);

            if (_cancelationToken)
                return;

            buildMap(mapId);
        }
    }

    void MapBuilder::buildAllMaps(unsigned int threads)
    {
        printf("Using %u threads to extract mmaps\n", threads);

        for (unsigned int i = 0; i < threads; ++i)
        {
            _workerThreads.push_back(std::thread(&MapBuilder::WorkerThread, this));
        }

        m_tiles.sort([](MapTiles const& a, MapTiles const& b)
        {
            return a.m_tiles->size() > b.m_tiles->size();
        });

        for (TileList::iterator it = m_tiles.begin(); it != m_tiles.end(); ++it)
        {
            uint32 mapId = it->m_mapId;
            if (!shouldSkipMap(mapId))
            {
                if (threads > 0)
                    _queue.Push(mapId);
                else
                    buildMap(mapId);
            }
        }

        while (!_queue.Empty())
        {
            std::this_thread::sleep_for(std::chrono::milliseconds(1000));
        }

        _cancelationToken = true;

        _queue.Cancel();

        for (auto& thread : _workerThreads)
        {
            thread.join();
        }
    }

    /**************************************************************************/
    void MapBuilder::getGridBounds(uint32 mapID, uint32 &minX, uint32 &minY, uint32 &maxX, uint32 &maxY)
    {
        maxX = INT_MAX;
        maxY = INT_MAX;
        minX = INT_MIN;
        minY = INT_MIN;

        float bmin[3] = { 0, 0, 0 };
        float bmax[3] = { 0, 0, 0 };
        float lmin[3] = { 0, 0, 0 };
        float lmax[3] = { 0, 0, 0 };
        MeshData meshData;

        // make sure we process maps which don't have tiles
        // initialize the static tree, which loads WDT models
        if (!m_terrainBuilder->loadVMap(mapID, 64, 64, meshData))
            return;

        // get the coord bounds of the model data
        if (meshData.solidVerts.size() + meshData.liquidVerts.size() == 0)
            return;

        // get the coord bounds of the model data
        if (meshData.solidVerts.size() && meshData.liquidVerts.size())
        {
            rcCalcBounds(meshData.solidVerts.getCArray(), meshData.solidVerts.size() / 3, bmin, bmax);
            rcCalcBounds(meshData.liquidVerts.getCArray(), meshData.liquidVerts.size() / 3, lmin, lmax);
            rcVmin(bmin, lmin);
            rcVmax(bmax, lmax);
        }
        else if (meshData.solidVerts.size())
            rcCalcBounds(meshData.solidVerts.getCArray(), meshData.solidVerts.size() / 3, bmin, bmax);
        else
            rcCalcBounds(meshData.liquidVerts.getCArray(), meshData.liquidVerts.size() / 3, lmin, lmax);

        // convert coord bounds to grid bounds
        maxX = 32 - bmin[0] / GRID_SIZE;
        maxY = 32 - bmin[2] / GRID_SIZE;
        minX = 32 - bmax[0] / GRID_SIZE;
        minY = 32 - bmax[2] / GRID_SIZE;
    }

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

        dtNavMesh* navMesh = NULL;
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
        int* inds = new int[indicesCount];

        if (fread(verts, sizeof(float), verticesCount, file) != verticesCount)
        {
            fclose(file);
            delete[] verts;
            delete[] inds;
            return;
        }

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
        buildMoveMapTile(mapId, tileX, tileY, data, bmin, bmax, navMesh);
        fclose(file);
    }

    /**************************************************************************/
    void MapBuilder::buildSingleTile(uint32 mapID, uint32 tileX, uint32 tileY)
    {
        dtNavMesh* navMesh = NULL;
        buildNavMesh(mapID, navMesh);
        if (!navMesh)
        {
            printf("Failed creating navmesh!              \n");
            return;
        }

        buildTile(mapID, tileX, tileY, navMesh);
        dtFreeNavMesh(navMesh);
    }

    /**************************************************************************/
    void MapBuilder::buildMap(uint32 mapID)
    {
        std::set<uint32>* tiles = getTileList(mapID);

        if (!tiles->empty())
        {
            // build navMesh
            dtNavMesh* navMesh = NULL;
            buildNavMesh(mapID, navMesh);
            if (!navMesh)
            {
                printf("[Map %04i] Failed creating navmesh!\n", mapID);
                m_totalTilesProcessed += tiles->size();
                return;
            }

            // now start building mmtiles for each tile
            printf("[Map %04i] We have %u tiles.                          \n", mapID, (unsigned int)tiles->size());
            for (std::set<uint32>::iterator it = tiles->begin(); it != tiles->end(); ++it)
            {
                uint32 tileX, tileY;

                // unpack tile coords
                StaticMapTree::unpackTileID((*it), tileX, tileY);

                if (!shouldSkipTile(mapID, tileX, tileY))
                    buildTile(mapID, tileX, tileY, navMesh);
                ++m_totalTilesProcessed;
            }

            dtFreeNavMesh(navMesh);
        }

        printf("[Map %04u] Complete!\n", mapID);
    }

    /**************************************************************************/
    void MapBuilder::buildTile(uint32 mapID, uint32 tileX, uint32 tileY, dtNavMesh* navMesh)
    {
        printf("%u%% [Map %04i] Building tile [%02u,%02u]\n", percentageDone(m_totalTiles, m_totalTilesProcessed), mapID, tileX, tileY);

        MeshData meshData;

        // get heightmap data
        m_terrainBuilder->loadMap(mapID, tileX, tileY, meshData);

        // get model data
        m_terrainBuilder->loadVMap(mapID, tileY, tileX, meshData);

        // if there is no data, give up now
        if (!meshData.solidVerts.size() && !meshData.liquidVerts.size())
            return;

        // remove unused vertices
        TerrainBuilder::cleanVertices(meshData.solidVerts, meshData.solidTris);
        TerrainBuilder::cleanVertices(meshData.liquidVerts, meshData.liquidTris);

        // gather all mesh data for final data check, and bounds calculation
        G3D::Array<float> allVerts;
        allVerts.append(meshData.liquidVerts);
        allVerts.append(meshData.solidVerts);

        if (!allVerts.size())
            return;

        // get bounds of current tile
        float bmin[3], bmax[3];
        getTileBounds(tileX, tileY, allVerts.getCArray(), allVerts.size() / 3, bmin, bmax);

        m_terrainBuilder->loadOffMeshConnections(mapID, tileX, tileY, meshData, m_offMeshFilePath);

        // build navmesh tile
        buildMoveMapTile(mapID, tileX, tileY, meshData, bmin, bmax, navMesh);
    }

    /**************************************************************************/
    void MapBuilder::buildNavMesh(uint32 mapID, dtNavMesh* &navMesh)
    {
        // if map has a parent we use that to generate dtNavMeshParams - worldserver will load all missing tiles from that map
        int32 navMeshParamsMapId = static_cast<VMapManager2*>(VMapFactory::createOrGetVMapManager())->getParentMapId(mapID);
        if (navMeshParamsMapId == -1)
            navMeshParamsMapId = mapID;

        std::set<uint32>* tiles = getTileList(navMeshParamsMapId);

        // old code for non-statically assigned bitmask sizes:
        ///*** calculate number of bits needed to store tiles & polys ***/
        //int tileBits = dtIlog2(dtNextPow2(tiles->size()));
        //if (tileBits < 1) tileBits = 1;                                     // need at least one bit!
        //int polyBits = sizeof(dtPolyRef)*8 - SALT_MIN_BITS - tileBits;

        int polyBits = DT_POLY_BITS;

        int maxTiles = tiles->size();
        int maxPolysPerTile = 1 << polyBits;

        /***          calculate bounds of map         ***/

        uint32 tileXMin = 64, tileYMin = 64, tileXMax = 0, tileYMax = 0, tileX, tileY;
        for (std::set<uint32>::iterator it = tiles->begin(); it != tiles->end(); ++it)
        {
            StaticMapTree::unpackTileID(*it, tileX, tileY);

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
        getTileBounds(tileXMax, tileYMax, NULL, 0, bmin, bmax);

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

        char fileName[25];
        sprintf(fileName, "mmaps/%04u.mmap", mapID);

        FILE* file = fopen(fileName, "wb");
        if (!file)
        {
            dtFreeNavMesh(navMesh);
            navMesh = nullptr;
            char message[1024];
            sprintf(message, "[Map %04u] Failed to open %s for writing!\n", mapID, fileName);
            perror(message);
            return;
        }

        // now that we know navMesh params are valid, we can write them to file
        fwrite(&navMeshParams, sizeof(dtNavMeshParams), 1, file);
        fclose(file);
    }

    /**************************************************************************/
    void MapBuilder::buildMoveMapTile(uint32 mapID, uint32 tileX, uint32 tileY,
        MeshData &meshData, float bmin[3], float bmax[3],
        dtNavMesh* navMesh)
    {
        // console output
        std::string tileString = Trinity::StringFormat("[Map %04u] [%02i,%02i]: ", mapID, tileX, tileY);
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

        // these are WORLD UNIT based metrics
        // this are basic unit dimentions
        // value have to divide GRID_SIZE(533.3333f) ( aka: 0.5333, 0.2666, 0.3333, 0.1333, etc )
        const static float BASE_UNIT_DIM = m_bigBaseUnit ? 0.5333333f : 0.2666666f;

        // All are in UNIT metrics!
        const static int VERTEX_PER_MAP = int(GRID_SIZE/BASE_UNIT_DIM + 0.5f);
        const static int VERTEX_PER_TILE = m_bigBaseUnit ? 40 : 80; // must divide VERTEX_PER_MAP
        const static int TILES_PER_MAP = VERTEX_PER_MAP/VERTEX_PER_TILE;

        rcConfig config;
        memset(&config, 0, sizeof(rcConfig));

        rcVcopy(config.bmin, bmin);
        rcVcopy(config.bmax, bmax);

        config.maxVertsPerPoly = DT_VERTS_PER_POLYGON;
        config.cs = BASE_UNIT_DIM;
        config.ch = BASE_UNIT_DIM;
        config.walkableSlopeAngle = m_maxWalkableAngle;
        config.tileSize = VERTEX_PER_TILE;
        config.walkableRadius = m_bigBaseUnit ? 1 : 2;
        config.borderSize = config.walkableRadius + 3;
        config.maxEdgeLen = VERTEX_PER_TILE + 1;        // anything bigger than tileSize
        config.walkableHeight = m_bigBaseUnit ? 3 : 6;
        // a value >= 3|6 allows npcs to walk over some fences
        // a value >= 4|8 allows npcs to walk over all fences
        config.walkableClimb = m_bigBaseUnit ? 4 : 8;
        config.minRegionArea = rcSqr(60);
        config.mergeRegionArea = rcSqr(50);
        config.maxSimplificationError = 1.8f;           // eliminates most jagged edges (tiny polygons)
        config.detailSampleDist = config.cs * 64;
        config.detailSampleMaxError = config.ch * 2;

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
                tileCfg.bmin[0] = config.bmin[0] + float(x*config.tileSize - config.borderSize)*config.cs;
                tileCfg.bmin[2] = config.bmin[2] + float(y*config.tileSize - config.borderSize)*config.cs;
                tileCfg.bmax[0] = config.bmin[0] + float((x+1)*config.tileSize + config.borderSize)*config.cs;
                tileCfg.bmax[2] = config.bmin[2] + float((y+1)*config.tileSize + config.borderSize)*config.cs;

                // build heightfield
                tile.solid = rcAllocHeightfield();
                if (!tile.solid || !rcCreateHeightfield(m_rcContext, *tile.solid, tileCfg.width, tileCfg.height, tileCfg.bmin, tileCfg.bmax, tileCfg.cs, tileCfg.ch))
                {
                    printf("%s Failed building heightfield!            \n", tileString.c_str());
                    continue;
                }

                // mark all walkable tiles, both liquids and solids
                unsigned char* triFlags = new unsigned char[tTriCount];
                memset(triFlags, NAV_AREA_GROUND, tTriCount*sizeof(unsigned char));
                rcClearUnwalkableTriangles(m_rcContext, tileCfg.walkableSlopeAngle, tVerts, tVertCount, tTris, tTriCount, triFlags);
                rcRasterizeTriangles(m_rcContext, tVerts, tVertCount, tTris, triFlags, tTriCount, *tile.solid, config.walkableClimb);
                delete[] triFlags;

                rcFilterLowHangingWalkableObstacles(m_rcContext, config.walkableClimb, *tile.solid);
                rcFilterLedgeSpans(m_rcContext, tileCfg.walkableHeight, tileCfg.walkableClimb, *tile.solid);
                rcFilterWalkableLowHeightSpans(m_rcContext, tileCfg.walkableHeight, *tile.solid);

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
                tile.solid = NULL;
                rcFreeCompactHeightfield(tile.chf);
                tile.chf = NULL;
                rcFreeContourSet(tile.cset);
                tile.cset = NULL;

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
            if (uint8 area = iv.polyMesh->areas[i] & RC_WALKABLE_AREA)
            {
                if (area >= NAV_AREA_MAGMA_SLIME)
                    iv.polyMesh->flags[i] = 1 << (63 - area);
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
        unsigned char* navData = NULL;
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
            if (!params.polyCount || !params.polys ||
                TILES_PER_MAP*TILES_PER_MAP == params.polyCount)
            {
                // we have flat tiles with no actual geometry - don't build those, its useless
                // keep in mind that we do output those into debug info
                // drop tiles with only exact count - some tiles may have geometry while having less tiles
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
            if (!tileRef || dtResult != DT_SUCCESS)
            {
                printf("%s Failed adding tile to navmesh!           \n", tileString.c_str());
                break;
            }

            // file output
            char fileName[255];
            sprintf(fileName, "mmaps/%04u%02i%02i.mmtile", mapID, tileY, tileX);
            FILE* file = fopen(fileName, "wb");
            if (!file)
            {
                char message[1024];
                sprintf(message, "[Map %04u] Failed to open %s for writing!\n", mapID, fileName);
                perror(message);
                navMesh->removeTile(tileRef, NULL, NULL);
                break;
            }

            printf("%s Writing to file...\n", tileString.c_str());

            // write header
            MmapTileHeader header;
            header.usesLiquids = m_terrainBuilder->usesLiquids();
            header.size = uint32(navDataSize);
            fwrite(&header, sizeof(MmapTileHeader), 1, file);

            // write data
            fwrite(navData, sizeof(unsigned char), navDataSize, file);
            fclose(file);

            // now that tile is written to disk, we can unload it
            navMesh->removeTile(tileRef, NULL, NULL);
        }
        while (0);

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
    void MapBuilder::getTileBounds(uint32 tileX, uint32 tileY, float* verts, int vertCount, float* bmin, float* bmax)
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
    bool MapBuilder::shouldSkipMap(uint32 mapID)
    {
        if (m_mapid >= 0)
            return static_cast<uint32>(m_mapid) != mapID;

        if (m_skipContinents)
            switch (mapID)
            {
                case 0:
                case 1:
                case 530:
                case 571:
                case 870:
                case 1116:
                case 1220:
                    return true;
                default:
                    break;
            }

        if (m_skipJunkMaps)
            switch (mapID)
            {
                case 13:    // test.wdt
                case 25:    // ScottTest.wdt
                case 29:    // Test.wdt
                case 42:    // Colin.wdt
                case 169:   // EmeraldDream.wdt (unused, and very large)
                case 451:   // development.wdt
                case 573:   // ExteriorTest.wdt
                case 597:   // CraigTest.wdt
                case 605:   // development_nonweighted.wdt
                case 606:   // QA_DVD.wdt
                case 651:   // ElevatorSpawnTest.wdt
                case 1060:  // LevelDesignLand-DevOnly.wdt
                case 1181:  // PattyMackTestGarrisonBldgMap.wdt
                case 1264:  // Propland-DevOnly.wdt
                case 1270:  // devland3.wdt
                case 1310:  // Expansion5QAModelMap.wdt
                case 1407:  // GorgrondFinaleScenarioMap.wdt (zzzOld)
                case 1427:  // PattyMackTestGarrisonBldgMap2.wdt
                case 1451:  // TanaanLegionTest.wdt
                case 1454:  // ArtifactAshbringerOrigin.wdt
                case 1457:  // FXlDesignLand-DevOnly.wdt
                case 1471:  // 1466.wdt (Dungeon Test Map 1466)
                case 1499:  // Artifact-Warrior Fury Acquisition.wdt (oldArtifact - Warrior Fury Acquisition)
                case 1537:  // BoostExperience.wdt (zzOLD - Boost Experience)
                case 1538:  // Karazhan Scenario.wdt (test)
                case 1549:  // TechTestSeamlessWorldTransitionA.wdt
                case 1550:  // TechTestSeamlessWorldTransitionB.wdt
                case 1555:  // TransportBoostExperienceAllianceGunship.wdt
                case 1556:  // TransportBoostExperienceHordeGunship.wdt
                case 1561:  // TechTestCosmeticParentPerformance.wdt
                case 1582:  // Artifact�DalaranVaultAcquisition.wdt // no, this weird symbol is not an encoding error.
                case 1584:  // JulienTestLand-DevOnly.wdt
                case 1586:  // AssualtOnStormwind.wdt (Assault on Stormwind - Dev Map)
                case 1588:  // DevMapA.wdt
                case 1589:  // DevMapB.wdt
                case 1590:  // DevMapC.wdt
                case 1591:  // DevMapD.wdt
                case 1592:  // DevMapE.wdt
                case 1593:  // DevMapF.wdt
                case 1594:  // DevMapG.wdt
                case 1603:  // AbyssalMaw_Interior_Scenario.wdt
                case 1670:  // BrokenshorePristine.wdt
                    return true;
                default:
                    if (isTransportMap(mapID))
                        return true;
                    break;
            }

        if (m_skipBattlegrounds)
            switch (mapID)
            {
                case 30:    // Alterac Valley
                case 37:    // ?
                case 489:   // Warsong Gulch
                case 529:   // Arathi Basin
                case 566:   // Eye of the Storm
                case 607:   // Strand of the Ancients
                case 628:   // Isle of Conquest
                case 726:   // Twin Peaks
                case 727:   // Silvershard Mines
                case 761:   // The Battle for Gilneas
                case 968:   // Rated Eye of the Storm
                case 998:   // Temple of Kotmogu
                case 1010:  // CTF3
                case 1105:  // Deepwind Gorge
                case 1280:  // Southshore vs. Tarren Mill
                case 1681:  // Arathi Basin Winter
                case 1803:  // Seething Shore
                    return true;
                default:
                    break;
            }

        return false;
    }

    /**************************************************************************/
    bool MapBuilder::isTransportMap(uint32 mapID)
    {
        switch (mapID)
        {
            // transport maps
            case 582:
            case 584:
            case 586:
            case 587:
            case 588:
            case 589:
            case 590:
            case 591:
            case 592:
            case 593:
            case 594:
            case 596:
            case 610:
            case 612:
            case 613:
            case 614:
            case 620:
            case 621:
            case 622:
            case 623:
            case 641:
            case 642:
            case 647:
            case 662:
            case 672:
            case 673:
            case 674:
            case 712:
            case 713:
            case 718:
            case 738:
            case 739:
            case 740:
            case 741:
            case 742:
            case 743:
            case 747:
            case 748:
            case 749:
            case 750:
            case 762:
            case 763:
            case 765:
            case 766:
            case 767:
            case 1113:
            case 1132:
            case 1133:
            case 1172:
            case 1173:
            case 1192:
            case 1231:
            case 1459:
            case 1476:
            case 1484:
            case 1555:
            case 1556:
            case 1559:
            case 1560:
            case 1628:
            case 1637:
            case 1638:
            case 1639:
            case 1649:
            case 1650:
            case 1711:
            case 1751:
            case 1752:
            case 1856:
            case 1857:
            case 1902:
            case 1903:
                return true;
            default:
                return false;
        }
    }

    /**************************************************************************/
    bool MapBuilder::shouldSkipTile(uint32 mapID, uint32 tileX, uint32 tileY)
    {
        char fileName[255];
        sprintf(fileName, "mmaps/%04u%02i%02i.mmtile", mapID, tileY, tileX);
        FILE* file = fopen(fileName, "rb");
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

    /**************************************************************************/
    uint32 MapBuilder::percentageDone(uint32 totalTiles, uint32 totalTilesBuilt)
    {
        if (totalTiles)
            return totalTilesBuilt * 100 / totalTiles;

        return 0;
    }

}
