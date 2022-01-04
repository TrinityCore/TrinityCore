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

#ifndef _MAP_BUILDER_H
#define _MAP_BUILDER_H

#include "TerrainBuilder.h"

#include "Recast.h"
#include "DetourNavMesh.h"
#include "Optional.h"
#include "ProducerConsumerQueue.h"

#include <vector>
#include <set>
#include <list>
#include <atomic>
#include <thread>

using namespace VMAP;

namespace MMAP
{
    struct MapTiles
    {
        MapTiles() : m_mapId(uint32(-1)), m_tiles(nullptr) {}

        MapTiles(uint32 id, std::set<uint32>* tiles) : m_mapId(id), m_tiles(tiles) {}
        ~MapTiles() {}

        uint32 m_mapId;
        std::set<uint32>* m_tiles;

        bool operator==(uint32 id)
        {
            return m_mapId == id;
        }
    };

    typedef std::list<MapTiles> TileList;

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

        struct TileInfo
    {
        TileInfo() : m_mapId(uint32(-1)), m_tileX(), m_tileY(), m_navMeshParams() {}

        uint32 m_mapId;
        uint32 m_tileX;
        uint32 m_tileY;
        dtNavMeshParams m_navMeshParams;
    };

    // ToDo: move this to its own file. For now it will stay here to keep the changes to a minimum, especially in the cpp file
    class MapBuilder;
    class TileBuilder
    {
        public:
            TileBuilder(MapBuilder* mapBuilder,
                bool skipLiquid,
                bool bigBaseUnit,
                bool debugOutput);

            TileBuilder(TileBuilder&&) = default;
            ~TileBuilder();

            void WorkerThread();
            void WaitCompletion();

            void buildTile(uint32 mapID, uint32 tileX, uint32 tileY, dtNavMesh* navMesh);
            // move map building
            void buildMoveMapTile(uint32 mapID,
                uint32 tileX,
                uint32 tileY,
                MeshData& meshData,
                float bmin[3],
                float bmax[3],
                dtNavMesh* navMesh);

            bool shouldSkipTile(uint32 mapID, uint32 tileX, uint32 tileY) const;

        private:
            bool m_bigBaseUnit;
            bool m_debugOutput;

            MapBuilder* m_mapBuilder;
            TerrainBuilder* m_terrainBuilder;
            std::thread m_workerThread;
            // build performance - not really used for now
            rcContext* m_rcContext;
    };

    class MapBuilder
    {
        friend class TileBuilder;

        public:
            MapBuilder(Optional<float> maxWalkableAngle,
                Optional<float> maxWalkableAngleNotSteep,
                bool skipLiquid,
                bool skipContinents,
                bool skipJunkMaps,
                bool skipBattlegrounds,
                bool debugOutput,
                bool bigBaseUnit,
                int mapid,
                char const* offMeshFilePath,
                unsigned int threads);

            ~MapBuilder();

            void buildMeshFromFile(char* name);

            // builds an mmap tile for the specified map and its mesh
            void buildSingleTile(uint32 mapID, uint32 tileX, uint32 tileY);

            // builds list of maps, then builds all of mmap tiles (based on the skip settings)
            void buildMaps(Optional<uint32> mapID);

        private:
            // builds all mmap tiles for the specified map id (ignores skip settings)
            void buildMap(uint32 mapID);
            // detect maps and tiles
            void discoverTiles();
            std::set<uint32>* getTileList(uint32 mapID);

            void buildNavMesh(uint32 mapID, dtNavMesh* &navMesh);

            void getTileBounds(uint32 tileX, uint32 tileY,
                float* verts, int vertCount,
                float* bmin, float* bmax) const;
            void getGridBounds(uint32 mapID, uint32 &minX, uint32 &minY, uint32 &maxX, uint32 &maxY) const;

            bool shouldSkipMap(uint32 mapID) const;
            bool isTransportMap(uint32 mapID) const;
            bool isContinentMap(uint32 mapID) const;

            rcConfig GetMapSpecificConfig(uint32 mapID, float bmin[3], float bmax[3], const TileConfig &tileConfig) const;

            uint32 percentageDone(uint32 totalTiles, uint32 totalTilesDone) const;
            uint32 currentPercentageDone() const;

            TerrainBuilder* m_terrainBuilder;
            TileList m_tiles;

            bool m_debugOutput;

            char const* m_offMeshFilePath;
            unsigned int m_threads;
            bool m_skipContinents;
            bool m_skipJunkMaps;
            bool m_skipBattlegrounds;
            bool m_skipLiquid;

            Optional<float> m_maxWalkableAngle;
            Optional<float> m_maxWalkableAngleNotSteep;
            bool m_bigBaseUnit;

            int32 m_mapid;

            std::atomic<uint32> m_totalTiles;
            std::atomic<uint32> m_totalTilesProcessed;

            // build performance - not really used for now
            rcContext* m_rcContext;

            std::vector<TileBuilder*> m_tileBuilders;
            ProducerConsumerQueue<TileInfo> _queue;
            std::atomic<bool> _cancelationToken;
    };
}

#endif
