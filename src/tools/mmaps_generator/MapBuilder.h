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

#include "FlatSet.h"
#include "Optional.h"
#include "ProducerConsumerQueue.h"
#include "TerrainBuilder.h"
#include "TileBuilder.h"
#include <DetourNavMesh.h>
#include <atomic>
#include <span>
#include <thread>
#include <vector>

namespace MMAP
{
    typedef std::unordered_map<uint32, Trinity::Containers::FlatSet<uint32>> TileList;

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

    class MapTileBuilder : public TileBuilder
    {
        public:
            MapTileBuilder(MapBuilder* mapBuilder,
                Optional<float> maxWalkableAngle,
                Optional<float> maxWalkableAngleNotSteep,
                bool skipLiquid,
                bool bigBaseUnit,
                bool debugOutput,
                std::vector<OffMeshData> const* offMeshConnections);
            ~MapTileBuilder();

            void WorkerThread();
            void WaitCompletion();

            bool shouldSkipTile(uint32 mapID, uint32 tileX, uint32 tileY) const override;

            std::string GetProgressText() const override;

            void OnTileDone() override;

        private:
            MapBuilder* m_mapBuilder;
            std::thread m_workerThread;
    };

    class MapBuilder
    {
        friend class TileBuilder;
        friend class MapTileBuilder;

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
            std::span<uint32 const> getTileList(uint32 mapID) const;

            void buildNavMesh(uint32 mapID, dtNavMesh* &navMesh);

            bool shouldSkipMap(uint32 mapID) const;
            bool isTransportMap(uint32 mapID) const;
            bool isDevMap(uint32 mapID) const;
            bool isBattlegroundMap(uint32 mapID) const;
            bool isContinentMap(uint32 mapID) const;

            uint32 percentageDone(uint32 totalTiles, uint32 totalTilesDone) const;
            uint32 currentPercentageDone() const;

            void ParseOffMeshConnectionsFile(char const* offMeshFilePath);

            TileList m_tiles;

            bool m_debugOutput;

            std::vector<OffMeshData> m_offMeshConnections;
            unsigned int m_threads;
            bool m_skipContinents;
            bool m_skipJunkMaps;
            bool m_skipBattlegrounds;
            bool m_skipLiquid;

            Optional<float> m_maxWalkableAngle;
            Optional<float> m_maxWalkableAngleNotSteep;
            bool m_bigBaseUnit;

            int32 m_mapid;

            uint32 m_totalTiles;
            std::atomic<uint32> m_totalTilesProcessed;

            std::vector<TileBuilder*> m_tileBuilders;
            ProducerConsumerQueue<TileInfo> _queue;
            std::atomic<bool> _cancelationToken;
    };
}

#endif
