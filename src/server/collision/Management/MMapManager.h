/*
 * Copyright (C) 2008-2015 TrinityCore <http://www.trinitycore.org/>
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
#include "World.h"
#include <string>
#include <unordered_map>
#include <set>

//  move map related classes
namespace MMAP
{
    typedef std::unordered_map<uint32, dtTileRef> MMapTileSet;
    typedef std::unordered_map<uint32, dtNavMeshQuery*> NavMeshQuerySet;


    typedef std::set<uint32> TerrainSet;

    struct NavMeshHolder
    {
        // Pre-built navMesh
        dtNavMesh* navMesh;

        // List of terrain swap map ids used to build the navMesh
        TerrainSet terrainIds;

        MMapTileSet loadedTileRefs;
    };

    struct PhasedTile
    {
        unsigned char* data;
        MmapTileHeader fileHeader;
        int32 dataSize;
    };

    typedef std::unordered_map<uint32, PhasedTile*> PhaseTileContainer;
    typedef std::unordered_map<uint32, PhaseTileContainer> PhaseTileMap;


    typedef std::unordered_map<uint32, TerrainSet> TerrainSetMap;

    class MMapData
    {
    public:
        MMapData(dtNavMesh* mesh, uint32 mapId);
        ~MMapData();

        dtNavMesh* GetNavMesh(TerrainSet swaps);

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
    class MMapManager
    {
        public:
            MMapManager() : loadedTiles(0) { }
            ~MMapManager();

            bool loadMap(const std::string& basePath, uint32 mapId, int32 x, int32 y);
            bool unloadMap(uint32 mapId, int32 x, int32 y);
            bool unloadMap(uint32 mapId);
            bool unloadMapInstance(uint32 mapId, uint32 instanceId);

            // the returned [dtNavMeshQuery const*] is NOT threadsafe
            dtNavMeshQuery const* GetNavMeshQuery(uint32 mapId, uint32 instanceId, TerrainSet swaps);
            dtNavMesh const* GetNavMesh(uint32 mapId, TerrainSet swaps);

            uint32 getLoadedTilesCount() const { return loadedTiles; }
            uint32 getLoadedMapsCount() const { return loadedMMaps.size(); }

            void LoadPhaseTiles(uint32 mapId, int32 x, int32 y);
            void UnloadPhaseTile(uint32 mapId, int32 x, int32 y);
            PhaseTileContainer GetPhaseTileContainer(uint32 mapId) { return _phaseTiles[mapId]; }

        private:
            bool loadMapData(uint32 mapId);
            uint32 packTileID(int32 x, int32 y);

            MMapDataSet loadedMMaps;
            uint32 loadedTiles;

            PhasedTile* LoadTile(uint32 mapId, int32 x, int32 y);
            PhaseTileMap _phaseTiles;
    };
}

#endif