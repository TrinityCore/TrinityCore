/*
 * Copyright (C) 2008-2018 TrinityCore <https://www.trinitycore.org/>
 * Copyright (C) 2005-2010 MaNGOS <http://getmangos.com/>
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

#ifndef _MMAP_MANAGER_H
#define _MMAP_MANAGER_H

#include "Define.h"
#include "DetourAlloc.h"
#include "DetourNavMesh.h"
#include "DetourNavMeshQuery.h"
#include "MapDefines.h"
#include <string>
#include <unordered_map>
#include <set>
#include <vector>

//  move map related classes
namespace MMAP
{
    typedef std::unordered_map<uint32, dtTileRef> MMapTileSet;
    typedef std::unordered_map<uint32, dtNavMeshQuery*> NavMeshQuerySet;


    typedef std::set<uint32> TerrainSet;

    struct TC_COMMON_API NavMeshHolder
    {
        // Pre-built navMesh
        dtNavMesh* navMesh;

        // List of terrain swap map ids used to build the navMesh
        TerrainSet terrainIds;

        MMapTileSet loadedTileRefs;
    };

    struct TC_COMMON_API PhasedTile
    {
        unsigned char* data;
        MmapTileHeader fileHeader;
        int32 dataSize;
    };

    typedef std::unordered_map<uint32, PhasedTile*> PhaseTileContainer;
    typedef std::unordered_map<uint32, PhaseTileContainer> PhaseTileMap;


    typedef std::unordered_map<uint32, TerrainSet> TerrainSetMap;

    class TC_COMMON_API MMapData
    {
    public:
        MMapData(dtNavMesh* mesh, uint32 mapId);
        ~MMapData();

        dtNavMesh* GetNavMesh(TerrainSet swaps);

        void AddBaseTile(uint32 packedGridPos, unsigned char* data, MmapTileHeader const& fileHeader, int32 dataSize);
        void DeleteBaseTile(uint32 packedGridPos);

        // we have to use single dtNavMeshQuery for every instance, since those are not thread safe
        NavMeshQuerySet navMeshQueries;     // instanceId to query

        dtNavMesh* navMesh;
        MMapTileSet loadedTileRefs;
        TerrainSetMap loadedPhasedTiles;

    private:
        uint32 _mapId;
        PhaseTileContainer _baseTiles;
        std::set<uint32> _activeSwaps;
        void RemoveSwap(PhasedTile* ptile, uint32 swap, uint32 packedXY);
        void AddSwap(PhasedTile* tile, uint32 swap, uint32 packedXY);
    };


    typedef std::unordered_map<uint32, MMapData*> MMapDataSet;

    // singleton class
    // holds all all access to mmap loading unloading and meshes
    class TC_COMMON_API MMapManager
    {
        public:
            MMapManager() : loadedTiles(0), thread_safe_environment(true) {}
            ~MMapManager();

            void InitializeThreadUnsafe(std::unordered_map<uint32, std::vector<uint32>> const& mapData);
            bool loadMap(const std::string& basePath, uint32 mapId, int32 x, int32 y);
            bool unloadMap(uint32 mapId, int32 x, int32 y);
            bool unloadMap(uint32 mapId);
            bool unloadMapInstance(uint32 mapId, uint32 instanceId);

            // the returned [dtNavMeshQuery const*] is NOT threadsafe
            dtNavMeshQuery const* GetNavMeshQuery(uint32 mapId, uint32 instanceId, TerrainSet swaps);
            dtNavMesh const* GetNavMesh(uint32 mapId, TerrainSet swaps);

            uint32 getLoadedTilesCount() const { return loadedTiles; }
            uint32 getLoadedMapsCount() const { return uint32(loadedMMaps.size()); }

            typedef std::unordered_map<uint32, std::vector<uint32>> PhaseChildMapContainer;
            void LoadPhaseTiles(PhaseChildMapContainer::const_iterator phasedMapData, int32 x, int32 y);
            void UnloadPhaseTile(PhaseChildMapContainer::const_iterator phasedMapData, int32 x, int32 y);
            PhaseTileContainer const* GetPhaseTileContainer(uint32 mapId) const
            {
                auto itr = _phaseTiles.find(mapId);
                if (itr != _phaseTiles.end())
                    return &itr->second;
                return nullptr;
            }

        private:
            bool loadMapData(uint32 mapId);
            uint32 packTileID(int32 x, int32 y);

            MMapDataSet::const_iterator GetMMapData(uint32 mapId) const;
            MMapDataSet loadedMMaps;
            PhaseChildMapContainer phaseMapData;
            uint32 loadedTiles;
            bool thread_safe_environment;

            PhasedTile* LoadTile(uint32 mapId, int32 x, int32 y);
            PhaseTileMap _phaseTiles;
    };
}

#endif
