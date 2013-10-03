/*
 * Copyright (C) 2008-2013 TrinityCore <http://www.trinitycore.org/>
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

#include "UnorderedMap.h"
#include "DetourAlloc.h"
#include "DetourNavMesh.h"
#include "DetourNavMeshQuery.h"

//  move map related classes
namespace MMAP
{
    typedef UNORDERED_MAP<uint32, dtTileRef> MMapTileSet;
    typedef UNORDERED_MAP<uint32, dtNavMeshQuery*> NavMeshQuerySet;

    // dummy struct to hold map's mmap data
    struct MMapData
    {
        MMapData(dtNavMesh* mesh) : navMesh(mesh) {}
        ~MMapData()
        {
            for (NavMeshQuerySet::iterator i = _navMeshQueries.begin(); i != _navMeshQueries.end(); ++i)
                dtFreeNavMeshQuery(i->second);

            if (navMesh)
                dtFreeNavMesh(navMesh);
        }

        dtNavMesh* navMesh;

        // we have to use single dtNavMeshQuery for every instance, since those are not thread safe
        NavMeshQuerySet _navMeshQueries;     // instanceId to query
        MMapTileSet _loadedTiles;        // maps [map grid coords] to [dtTile]
    };


    typedef UNORDERED_MAP<uint32, MMapData*> MMapDataSet;

    // singleton class
    // holds all all access to mmap loading unloading and meshes
    class MMapManager
    {
        public:
            MMapManager() : _loadedTiles(0) {}
            ~MMapManager();

            bool LoadMapTile(uint32 mapId, int32 x, int32 y);
            bool UnloadMapTile(uint32 mapId, int32 x, int32 y);
            bool UnloadMap(uint32 mapId);
            bool UnloadMapInstance(uint32 mapId, uint32 instanceId);

            // the returned [dtNavMeshQuery const*] is NOT threadsafe
            dtNavMeshQuery const* GetNavMeshQuery(uint32 mapId, uint32 instanceId);
            dtNavMesh const* GetNavMesh(uint32 mapId);

            uint32 GetLoadedTilesCount() const { return _loadedTiles; }
            uint32 GetLoadedMapsCount() const { return _loadedMaps.size(); }
        private:
            bool LoadMap(uint32 mapId);
            uint32 PackTileId(int32 x, int32 y) { return uint32(x << 16 | y); }

            MMapDataSet _loadedMaps;
            uint32 _loadedTiles;
    };
}

#endif