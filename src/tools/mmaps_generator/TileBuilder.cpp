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

#include "TileBuilder.h"
#include "IntermediateValues.h"
#include "Log.h"
#include "MMapDefines.h"
#include "PathCommon.h"
#include "StringFormat.h"
#include "VMapManager2.h"
#include <DetourNavMeshBuilder.h>

namespace
{
    struct Tile
    {
        Tile() : chf(nullptr), solid(nullptr), cset(nullptr), pmesh(nullptr), dmesh(nullptr) {}
        ~Tile()
        {
            rcFreeCompactHeightfield(chf);
            rcFreeContourSet(cset);
            rcFreeHeightField(solid);
            rcFreePolyMesh(pmesh);
            rcFreePolyMeshDetail(dmesh);
        }
        rcCompactHeightfield* chf;
        rcHeightfield* solid;
        rcContourSet* cset;
        rcPolyMesh* pmesh;
        rcPolyMeshDetail* dmesh;
    };
}

namespace MMAP
{
    struct TileConfig
    {
        TileConfig(bool bigBaseUnit)
        {
            // these are WORLD UNIT based metrics
            // this are basic unit dimentions
            // value have to divide GRID_SIZE(533.3333f) ( aka: 0.5333, 0.2666, 0.3333, 0.1333, etc )
            BASE_UNIT_DIM = bigBaseUnit ? 0.5333333f : 0.2666666f;

            // All are in UNIT metrics!
            VERTEX_PER_MAP = int(GRID_SIZE / BASE_UNIT_DIM + 0.5f);
            VERTEX_PER_TILE = bigBaseUnit ? 40 : 80; // must divide VERTEX_PER_MAP
            TILES_PER_MAP = VERTEX_PER_MAP / VERTEX_PER_TILE;
        }

        float BASE_UNIT_DIM;
        int VERTEX_PER_MAP;
        int VERTEX_PER_TILE;
        int TILES_PER_MAP;
    };

    TileBuilder::TileBuilder(Optional<float> maxWalkableAngle, Optional<float> maxWalkableAngleNotSteep,
        bool skipLiquid, bool bigBaseUnit, bool debugOutput, std::vector<OffMeshData> const* offMeshConnections) :
        m_maxWalkableAngle(maxWalkableAngle),
        m_maxWalkableAngleNotSteep(maxWalkableAngleNotSteep),
        m_bigBaseUnit(bigBaseUnit),
        m_debugOutput(debugOutput),
        m_terrainBuilder(skipLiquid),
        m_rcContext(false),
        m_offMeshConnections(offMeshConnections)
    {
    }

    TileBuilder::~TileBuilder() = default;

    /**************************************************************************/
    void TileBuilder::buildTile(uint32 mapID, uint32 tileX, uint32 tileY, dtNavMesh* navMesh)
    {
        if (shouldSkipTile(mapID, tileX, tileY))
        {
            OnTileDone();
            return;
        }

        TC_LOG_INFO("maps.mmapgen", "{} [Map {:04}] Building tile [{:02},{:02}]", GetProgressText(), mapID, tileX, tileY);

        MeshData meshData;

        std::unique_ptr<VMAP::VMapManager2> vmapManager = VMapFactory::CreateVMapManager(mapID);

        // get heightmap data
        m_terrainBuilder.loadMap(mapID, tileX, tileY, meshData, vmapManager.get());

        // get model data
        m_terrainBuilder.loadVMap(mapID, tileY, tileX, meshData, vmapManager.get());

        // if there is no data, give up now
        if (!meshData.solidVerts.size() && !meshData.liquidVerts.size())
        {
            OnTileDone();
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
            OnTileDone();
            return;
        }

        // get bounds of current tile
        float bmin[3], bmax[3];
        getTileBounds(tileX, tileY, allVerts.getCArray(), allVerts.size() / 3, bmin, bmax);

        if (m_offMeshConnections)
            m_terrainBuilder.loadOffMeshConnections(mapID, tileX, tileY, meshData, *m_offMeshConnections);

        // build navmesh tile
        buildMoveMapTile(mapID, tileX, tileY, meshData, bmin, bmax, navMesh);

        OnTileDone();
    }

    /**************************************************************************/
    void TileBuilder::buildMoveMapTile(uint32 mapID, uint32 tileX, uint32 tileY,
        MeshData& meshData, float (&bmin)[3], float (&bmax)[3],
        dtNavMesh* navMesh)
    {
        // console output
        std::string tileString = Trinity::StringFormat("[Map {:04}] [{:02},{:02}]:", mapID, tileX, tileY);
        TC_LOG_INFO("maps.mmapgen", "{} Building movemap tile...", tileString);

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
        rcConfig config = GetMapSpecificConfig(mapID, bmin, bmax, tileConfig);

        // this sets the dimensions of the heightfield - should maybe happen before border padding
        rcCalcGridSize(config.bmin, config.bmax, config.cs, &config.width, &config.height);

        // allocate subregions : tiles
        Tile* tiles = new Tile[TILES_PER_MAP * TILES_PER_MAP];

        // Initialize per tile config.
        rcConfig tileCfg = config;
        tileCfg.width = config.tileSize + config.borderSize * 2;
        tileCfg.height = config.tileSize + config.borderSize * 2;

        // merge per tile poly and detail meshes
        rcPolyMesh** pmmerge = new rcPolyMesh * [TILES_PER_MAP * TILES_PER_MAP];
        rcPolyMeshDetail** dmmerge = new rcPolyMeshDetail * [TILES_PER_MAP * TILES_PER_MAP];
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
                if (!tile.solid || !rcCreateHeightfield(&m_rcContext, *tile.solid, tileCfg.width, tileCfg.height, tileCfg.bmin, tileCfg.bmax, tileCfg.cs, tileCfg.ch))
                {
                    TC_LOG_ERROR("maps.mmapgen", "{} Failed building heightfield!", tileString);
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
                memset(triFlags, NAV_AREA_GROUND_STEEP, tTriCount * sizeof(unsigned char));
                rcClearUnwalkableTriangles(&m_rcContext, tileCfg.walkableSlopeAngle, tVerts, tVertCount, tTris, tTriCount, triFlags);
                rcMarkWalkableTriangles(&m_rcContext, tileCfg.walkableSlopeAngleNotSteep, tVerts, tVertCount, tTris, tTriCount, triFlags, NAV_AREA_GROUND);
                rcRasterizeTriangles(&m_rcContext, tVerts, tVertCount, tTris, triFlags, tTriCount, *tile.solid, config.walkableClimb);
                delete[] triFlags;

                rcFilterLowHangingWalkableObstacles(&m_rcContext, config.walkableClimb, *tile.solid);
                rcFilterLedgeSpans(&m_rcContext, tileCfg.walkableHeight, tileCfg.walkableClimb, *tile.solid);
                rcFilterWalkableLowHeightSpans(&m_rcContext, tileCfg.walkableHeight, *tile.solid);

                // add liquid triangles
                rcRasterizeTriangles(&m_rcContext, lVerts, lVertCount, lTris, lTriFlags, lTriCount, *tile.solid, config.walkableClimb);

                // compact heightfield spans
                tile.chf = rcAllocCompactHeightfield();
                if (!tile.chf || !rcBuildCompactHeightfield(&m_rcContext, tileCfg.walkableHeight, tileCfg.walkableClimb, *tile.solid, *tile.chf))
                {
                    TC_LOG_ERROR("maps.mmapgen", "{} Failed compacting heightfield!", tileString);
                    continue;
                }

                // build polymesh intermediates
                if (!rcErodeWalkableArea(&m_rcContext, config.walkableRadius, *tile.chf))
                {
                    TC_LOG_ERROR("maps.mmapgen", "{} Failed eroding area!", tileString);
                    continue;
                }

                if (!rcMedianFilterWalkableArea(&m_rcContext, *tile.chf))
                {
                    TC_LOG_ERROR("maps.mmapgen", "{} Failed filtering area!", tileString);
                    continue;
                }

                if (!rcBuildDistanceField(&m_rcContext, *tile.chf))
                {
                    TC_LOG_ERROR("maps.mmapgen", "{} Failed building distance field!", tileString);
                    continue;
                }

                if (!rcBuildRegions(&m_rcContext, *tile.chf, tileCfg.borderSize, tileCfg.minRegionArea, tileCfg.mergeRegionArea))
                {
                    TC_LOG_ERROR("maps.mmapgen", "{} Failed building regions!", tileString);
                    continue;
                }

                tile.cset = rcAllocContourSet();
                if (!tile.cset || !rcBuildContours(&m_rcContext, *tile.chf, tileCfg.maxSimplificationError, tileCfg.maxEdgeLen, *tile.cset))
                {
                    TC_LOG_ERROR("maps.mmapgen", "{} Failed building contours!", tileString);
                    continue;
                }

                // build polymesh
                tile.pmesh = rcAllocPolyMesh();
                if (!tile.pmesh || !rcBuildPolyMesh(&m_rcContext, *tile.cset, tileCfg.maxVertsPerPoly, *tile.pmesh))
                {
                    TC_LOG_ERROR("maps.mmapgen", "{} Failed building polymesh!", tileString);
                    continue;
                }

                tile.dmesh = rcAllocPolyMeshDetail();
                if (!tile.dmesh || !rcBuildPolyMeshDetail(&m_rcContext, *tile.pmesh, *tile.chf, tileCfg.detailSampleDist, tileCfg.detailSampleMaxError, *tile.dmesh))
                {
                    TC_LOG_ERROR("maps.mmapgen", "{} Failed building polymesh detail!", tileString);
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
            TC_LOG_ERROR("maps.mmapgen", "{} alloc iv.polyMesh FAILED!", tileString);
            delete[] pmmerge;
            delete[] dmmerge;
            delete[] tiles;
            return;
        }
        rcMergePolyMeshes(&m_rcContext, pmmerge, nmerge, *iv.polyMesh);

        iv.polyMeshDetail = rcAllocPolyMeshDetail();
        if (!iv.polyMeshDetail)
        {
            TC_LOG_ERROR("maps.mmapgen", "{} alloc m_dmesh FAILED!", tileString);
            delete[] pmmerge;
            delete[] dmmerge;
            delete[] tiles;
            return;
        }
        rcMergePolyMeshDetails(&m_rcContext, dmmerge, nmerge, *iv.polyMeshDetail);

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
        dtNavMeshCreateParams params = {};
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
        params.offMeshConCount = meshData.offMeshConnections.size() / 6;
        params.offMeshConRad = meshData.offMeshConnectionRads.getCArray();
        params.offMeshConDir = meshData.offMeshConnectionDirs.getCArray();
        params.offMeshConAreas = meshData.offMeshConnectionsAreas.getCArray();
        params.offMeshConFlags = meshData.offMeshConnectionsFlags.getCArray();

        params.walkableHeight = BASE_UNIT_DIM * config.walkableHeight;    // agent height
        params.walkableRadius = BASE_UNIT_DIM * config.walkableRadius;    // agent radius
        params.walkableClimb = BASE_UNIT_DIM * config.walkableClimb;      // keep less that walkableHeight (aka agent height)!
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
                TC_LOG_ERROR("maps.mmapgen", "{} Invalid verts-per-polygon value!", tileString);
                break;
            }
            if (params.vertCount >= 0xffff)
            {
                TC_LOG_ERROR("maps.mmapgen", "{} Too many vertices!", tileString);
                break;
            }
            if (!params.vertCount || !params.verts)
            {
                // occurs mostly when adjacent tiles have models
                // loaded but those models don't span into this tile

                // message is an annoyance
                //TC_LOG_ERROR("maps.mmapgen", "{} No vertices to build tile!", tileString);
                break;
            }
            if (!params.polyCount || !params.polys)
            {
                // we have flat tiles with no actual geometry - don't build those, its useless
                // keep in mind that we do output those into debug info
                TC_LOG_ERROR("maps.mmapgen", "{} No polygons to build on tile!", tileString);
                break;
            }
            if (!params.detailMeshes || !params.detailVerts || !params.detailTris)
            {
                TC_LOG_ERROR("maps.mmapgen", "{} No detail mesh to build tile!", tileString);
                break;
            }

            TC_LOG_DEBUG("maps.mmapgen", "{} Building navmesh tile...", tileString);
            if (!dtCreateNavMeshData(&params, &navData, &navDataSize))
            {
                TC_LOG_ERROR("maps.mmapgen", "{} Failed building navmesh tile!", tileString);
                break;
            }

            dtTileRef tileRef = 0;
            TC_LOG_DEBUG("maps.mmapgen", "{} Adding tile to navmesh...", tileString);
            // DT_TILE_FREE_DATA tells detour to unallocate memory when the tile
            // is removed via removeTile()
            dtStatus dtResult = navMesh->addTile(navData, navDataSize, DT_TILE_FREE_DATA, 0, &tileRef);
            if (!tileRef || !dtStatusSucceed(dtResult))
            {
                TC_LOG_ERROR("maps.mmapgen", "{} Failed adding tile to navmesh!", tileString);
                break;
            }

            // file output
            std::string fileName = Trinity::StringFormat("mmaps/{:04}{:02}{:02}.mmtile", mapID, tileY, tileX);
            FILE* file = fopen(fileName.c_str(), "wb");
            if (!file)
            {
                TC_LOG_ERROR("maps.mmapgen", "{}: [Map {:04}] Failed to open {} for writing!", strerror(errno), mapID, fileName);
                navMesh->removeTile(tileRef, nullptr, nullptr);
                break;
            }

            TC_LOG_DEBUG("maps.mmapgen", "{} Writing to file...", tileString);

            // write header
            MmapTileHeader header;
            header.usesLiquids = m_terrainBuilder.usesLiquids();
            header.size = uint32(navDataSize);
            fwrite(&header, sizeof(MmapTileHeader), 1, file);

            // write data
            fwrite(navData, sizeof(unsigned char), navDataSize, file);
            fclose(file);

            // now that tile is written to disk, we can unload it
            navMesh->removeTile(tileRef, nullptr, nullptr);
        } while (false);

        if (m_debugOutput)
        {
            // restore padding so that the debug visualization is correct
            for (int i = 0; i < iv.polyMesh->nverts; ++i)
            {
                unsigned short* v = &iv.polyMesh->verts[i * 3];
                v[0] += (unsigned short)config.borderSize;
                v[2] += (unsigned short)config.borderSize;
            }

            iv.generateObjFile(mapID, tileX, tileY, meshData);
            iv.writeIV(mapID, tileX, tileY);
        }
    }

    /**************************************************************************/
    void TileBuilder::getTileBounds(uint32 tileX, uint32 tileY, float* verts, int vertCount, float* bmin, float* bmax)
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
    bool TileBuilder::shouldSkipTile(uint32 /*mapID*/, uint32 /*tileX*/, uint32 /*tileY*/) const
    {
        if (m_debugOutput)
            return false;

        return true;
    }

    rcConfig TileBuilder::GetMapSpecificConfig(uint32 mapID, float const (&bmin)[3], float const (&bmax)[3], TileConfig const& tileConfig) const
    {
        rcConfig config { };

        rcVcopy(config.bmin, bmin);
        rcVcopy(config.bmax, bmax);

        config.maxVertsPerPoly = DT_VERTS_PER_POLYGON;
        config.cs = tileConfig.BASE_UNIT_DIM;
        config.ch = tileConfig.BASE_UNIT_DIM;
        // Keeping these 2 slope angles the same reduces a lot the number of polys.
        // 55 should be the minimum, maybe 70 is ok (keep in mind blink uses mmaps), 85 is too much for players
        config.walkableSlopeAngle = m_maxWalkableAngle.value_or(55.0f);
        config.walkableSlopeAngleNotSteep = m_maxWalkableAngleNotSteep.value_or(55.0f);
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

    std::string TileBuilder::GetProgressText() const
    {
        return "";
    }
}
