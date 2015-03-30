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

#include "MMapManager.h"
#include "Log.h"
#include "World.h"
#include "DBCStores.h"
#include "MMapFactory.h"

namespace MMAP
{
    // ######################## MMapManager ########################
    MMapManager::~MMapManager()
    {
        for (MMapDataSet::iterator i = loadedMMaps.begin(); i != loadedMMaps.end(); ++i)
            delete i->second;

        // by now we should not have maps loaded
        // if we had, tiles in MMapData->mmapLoadedTiles, their actual data is lost!
    }

    bool MMapManager::loadMapData(uint32 mapId)
    {
        // we already have this map loaded?
        if (loadedMMaps.find(mapId) != loadedMMaps.end())
            return true;

        // load and init dtNavMesh - read parameters from file
        uint32 pathLen = uint32(sWorld->GetDataPath().length() + strlen("mmaps/%03i.mmap") + 1);
        char *fileName = new char[pathLen];
        snprintf(fileName, pathLen, (sWorld->GetDataPath()+"mmaps/%03i.mmap").c_str(), mapId);

        FILE* file = fopen(fileName, "rb");
        if (!file)
        {
            TC_LOG_DEBUG("maps", "MMAP:loadMapData: Error: Could not open mmap file '%s'", fileName);
            delete [] fileName;
            return false;
        }

        dtNavMeshParams params;
        uint32 count = uint32(fread(&params, sizeof(dtNavMeshParams), 1, file));
        fclose(file);
        if (count != 1)
        {
            TC_LOG_DEBUG("maps", "MMAP:loadMapData: Error: Could not read params from file '%s'", fileName);
            delete [] fileName;
            return false;
        }

        dtNavMesh* mesh = dtAllocNavMesh();
        ASSERT(mesh);
        if (dtStatusFailed(mesh->init(&params)))
        {
            dtFreeNavMesh(mesh);
            TC_LOG_ERROR("maps", "MMAP:loadMapData: Failed to initialize dtNavMesh for mmap %03u from file %s", mapId, fileName);
            delete [] fileName;
            return false;
        }

        delete [] fileName;

        TC_LOG_DEBUG("maps", "MMAP:loadMapData: Loaded %03i.mmap", mapId);

        // store inside our map list
        MMapData* mmap_data = new MMapData(mesh, mapId);

        loadedMMaps.insert(std::pair<uint32, MMapData*>(mapId, mmap_data));
        return true;
    }

    uint32 MMapManager::packTileID(int32 x, int32 y)
    {
        return uint32(x << 16 | y);
    }

    bool MMapManager::loadMap(const std::string& /*basePath*/, uint32 mapId, int32 x, int32 y)
    {
        // make sure the mmap is loaded and ready to load tiles
        if (!loadMapData(mapId))
            return false;

        // get this mmap data
        MMapData* mmap = loadedMMaps[mapId];
        ASSERT(mmap->navMesh);

        // check if we already have this tile loaded
        uint32 packedGridPos = packTileID(x, y);
        if (mmap->loadedTileRefs.find(packedGridPos) != mmap->loadedTileRefs.end())
            return false;

        // load this tile :: mmaps/MMMXXYY.mmtile
        uint32 pathLen = uint32(sWorld->GetDataPath().length() + strlen("mmaps/%03i%02i%02i.mmtile") + 1);
        char *fileName = new char[pathLen];

        snprintf(fileName, pathLen, (sWorld->GetDataPath()+"mmaps/%03i%02i%02i.mmtile").c_str(), mapId, x, y);

        FILE* file = fopen(fileName, "rb");
        if (!file)
        {
            TC_LOG_DEBUG("maps", "MMAP:loadMap: Could not open mmtile file '%s'", fileName);
            delete [] fileName;
            return false;
        }
        delete [] fileName;

        // read header
        MmapTileHeader fileHeader;
        if (fread(&fileHeader, sizeof(MmapTileHeader), 1, file) != 1 || fileHeader.mmapMagic != MMAP_MAGIC)
        {
            TC_LOG_ERROR("maps", "MMAP:loadMap: Bad header in mmap %03u%02i%02i.mmtile", mapId, x, y);
            fclose(file);
            return false;
        }

        if (fileHeader.mmapVersion != MMAP_VERSION)
        {
            TC_LOG_ERROR("maps", "MMAP:loadMap: %03u%02i%02i.mmtile was built with generator v%i, expected v%i",
                mapId, x, y, fileHeader.mmapVersion, MMAP_VERSION);
            fclose(file);
            return false;
        }

        unsigned char* data = (unsigned char*)dtAlloc(fileHeader.size, DT_ALLOC_PERM);
        ASSERT(data);

        size_t result = fread(data, fileHeader.size, 1, file);
        if (!result)
        {
            TC_LOG_ERROR("maps", "MMAP:loadMap: Bad header or data in mmap %03u%02i%02i.mmtile", mapId, x, y);
            fclose(file);
            return false;
        }

        fclose(file);

        dtMeshHeader* header = (dtMeshHeader*)data;
        dtTileRef tileRef = 0;

        // memory allocated for data is now managed by detour, and will be deallocated when the tile is removed
        if (dtStatusSucceed(mmap->navMesh->addTile(data, fileHeader.size, NULL/*DT_TILE_FREE_DATA*/, 0, &tileRef)))
        {
            mmap->loadedTileRefs.insert(std::pair<uint32, dtTileRef>(packedGridPos, tileRef));
            ++loadedTiles;
            TC_LOG_DEBUG("maps", "MMAP:loadMap: Loaded mmtile %03i[%02i, %02i] into %03i[%02i, %02i]", mapId, x, y, mapId, header->x, header->y);

            LoadPhaseTiles(mapId, x, y);

            return true;
        }
        else
        {
            TC_LOG_ERROR("maps", "MMAP:loadMap: Could not load %03u%02i%02i.mmtile into navmesh", mapId, x, y);
            dtFree(data);
            return false;
        }

        return false;
    }

    PhasedTile* MMapManager::LoadTile(uint32 mapId, int32 x, int32 y)
    {
        // load this tile :: mmaps/MMMXXYY.mmtile
        uint32 pathLen = sWorld->GetDataPath().length() + strlen("mmaps/%03i%02i%02i.mmtile") + 1;
        char *fileName = new char[pathLen];

        snprintf(fileName, pathLen, (sWorld->GetDataPath() + "mmaps/%03i%02i%02i.mmtile").c_str(), mapId, x, y);

        FILE* file = fopen(fileName, "rb");
        if (!file)
        {
            // Not all tiles have phased versions, don't flood this msg
            //TC_LOG_DEBUG("phase", "MMAP:LoadTile: Could not open mmtile file '%s'", fileName);
            delete[] fileName;
            return NULL;
        }
        delete[] fileName;

        PhasedTile* pTile = new PhasedTile();

        // read header
        if (fread(&pTile->fileHeader, sizeof(MmapTileHeader), 1, file) != 1 || pTile->fileHeader.mmapMagic != MMAP_MAGIC)
        {
            TC_LOG_ERROR("phase", "MMAP:LoadTile: Bad header in mmap %03u%02i%02i.mmtile", mapId, x, y);
            fclose(file);
            return NULL;
        }

        if (pTile->fileHeader.mmapVersion != MMAP_VERSION)
        {
            TC_LOG_ERROR("phase", "MMAP:LoadTile: %03u%02i%02i.mmtile was built with generator v%i, expected v%i",
                mapId, x, y, pTile->fileHeader.mmapVersion, MMAP_VERSION);
            fclose(file);
            return NULL;
        }

        pTile->data = (unsigned char*)dtAlloc(pTile->fileHeader.size, DT_ALLOC_PERM);
        ASSERT(pTile->data);

        size_t result = fread(pTile->data, pTile->fileHeader.size, 1, file);
        if (!result)
        {
            TC_LOG_ERROR("phase", "MMAP:LoadTile: Bad header or data in mmap %03u%02i%02i.mmtile", mapId, x, y);
            fclose(file);
            return NULL;
        }

        fclose(file);

        return pTile;
    }

    void MMapManager::LoadPhaseTiles(uint32 mapId, int32 x, int32 y)
    {
        TC_LOG_DEBUG("phase", "MMAP:LoadPhaseTiles: Loading phased mmtiles for map %u, x: %i, y: %i", mapId, x, y);

        uint32 packedGridPos = packTileID(x, y);

        for (uint32 i = 0; i < sMapStore.GetNumRows(); ++i)
        {
            if (const MapEntry* const map = sMapStore.LookupEntry(i))
            {
                if (map->ParentMapID == mapId)
                {
                    PhasedTile* data = LoadTile(map->ID, x, y);
                    // only a few tiles have terrain swaps, do not write error for them
                    if (data)
                    {
                        TC_LOG_DEBUG("phase", "MMAP:LoadPhaseTiles: Loaded phased %03u%02i%02i.mmtile for root phase map %u", map->ID, x, y, mapId);
                        _phaseTiles[map->ID][packedGridPos] = data;
                    }
                }
            }
        }
    }

    void MMapManager::UnloadPhaseTile(uint32 mapId, int32 x, int32 y)
    {
        TC_LOG_DEBUG("phase", "MMAP:UnloadPhaseTile: Unloading phased mmtile for map %u, x: %i, y: %i", mapId, x, y);

        uint32 packedGridPos = packTileID(x, y);

        const MapEntry* const map = sMapStore.LookupEntry(mapId); // map existence already checked when loading
        uint32 rootMapId = map->ParentMapID;

        if (_phaseTiles[mapId][packedGridPos])
        {
            TC_LOG_DEBUG("phase", "MMAP:UnloadPhaseTile: Unloaded phased %03u%02i%02i.mmtile for root phase map %u", mapId, x, y, rootMapId);
            delete _phaseTiles[mapId][packedGridPos]->data;
            delete _phaseTiles[mapId][packedGridPos];
            _phaseTiles[mapId].erase(packedGridPos);
        }
    }

    bool MMapManager::unloadMap(uint32 mapId, int32 x, int32 y)
    {
        // check if we have this map loaded
        if (loadedMMaps.find(mapId) == loadedMMaps.end())
        {
            // file may not exist, therefore not loaded
            TC_LOG_DEBUG("maps", "MMAP:unloadMap: Asked to unload not loaded navmesh map. %03u%02i%02i.mmtile", mapId, x, y);
            return false;
        }

        MMapData* mmap = loadedMMaps[mapId];

        // check if we have this tile loaded
        uint32 packedGridPos = packTileID(x, y);
        if (mmap->loadedTileRefs.find(packedGridPos) == mmap->loadedTileRefs.end())
        {
            // file may not exist, therefore not loaded
            TC_LOG_DEBUG("maps", "MMAP:unloadMap: Asked to unload not loaded navmesh tile. %03u%02i%02i.mmtile", mapId, x, y);
            return false;
        }

        dtTileRef tileRef = mmap->loadedTileRefs[packedGridPos];

        // unload, and mark as non loaded
        if (dtStatusFailed(mmap->navMesh->removeTile(tileRef, NULL, NULL)))
        {
            // this is technically a memory leak
            // if the grid is later reloaded, dtNavMesh::addTile will return error but no extra memory is used
            // we cannot recover from this error - assert out
            TC_LOG_ERROR("maps", "MMAP:unloadMap: Could not unload %03u%02i%02i.mmtile from navmesh", mapId, x, y);
            ASSERT(false);
        }
        else
        {
            mmap->loadedTileRefs.erase(packedGridPos);
            --loadedTiles;
            TC_LOG_DEBUG("maps", "MMAP:unloadMap: Unloaded mmtile %03i[%02i, %02i] from %03i", mapId, x, y, mapId);

            UnloadPhaseTile(mapId, x, y);
            return true;
        }

        return false;
    }

    bool MMapManager::unloadMap(uint32 mapId)
    {
        if (loadedMMaps.find(mapId) == loadedMMaps.end())
        {
            // file may not exist, therefore not loaded
            TC_LOG_DEBUG("maps", "MMAP:unloadMap: Asked to unload not loaded navmesh map %03u", mapId);
            return false;
        }

        // unload all tiles from given map
        MMapData* mmap = loadedMMaps[mapId];
        for (MMapTileSet::iterator i = mmap->loadedTileRefs.begin(); i != mmap->loadedTileRefs.end(); ++i)
        {
            uint32 x = (i->first >> 16);
            uint32 y = (i->first & 0x0000FFFF);
            if (dtStatusFailed(mmap->navMesh->removeTile(i->second, NULL, NULL)))
                TC_LOG_ERROR("maps", "MMAP:unloadMap: Could not unload %03u%02i%02i.mmtile from navmesh", mapId, x, y);
            else
            {
                UnloadPhaseTile(mapId, x, y);
                --loadedTiles;
                TC_LOG_DEBUG("maps", "MMAP:unloadMap: Unloaded mmtile %03i[%02i, %02i] from %03i", mapId, x, y, mapId);
            }
        }

        delete mmap;
        loadedMMaps.erase(mapId);
        TC_LOG_DEBUG("maps", "MMAP:unloadMap: Unloaded %03i.mmap", mapId);

        return true;
    }

    bool MMapManager::unloadMapInstance(uint32 mapId, uint32 instanceId)
    {
        // check if we have this map loaded
        if (loadedMMaps.find(mapId) == loadedMMaps.end())
        {
            // file may not exist, therefore not loaded
            TC_LOG_DEBUG("maps", "MMAP:unloadMapInstance: Asked to unload not loaded navmesh map %03u", mapId);
            return false;
        }

        MMapData* mmap = loadedMMaps[mapId];
        if (mmap->navMeshQueries.find(instanceId) == mmap->navMeshQueries.end())
        {
            TC_LOG_DEBUG("maps", "MMAP:unloadMapInstance: Asked to unload not loaded dtNavMeshQuery mapId %03u instanceId %u", mapId, instanceId);
            return false;
        }

        dtNavMeshQuery* query = mmap->navMeshQueries[instanceId];

        dtFreeNavMeshQuery(query);
        mmap->navMeshQueries.erase(instanceId);
        TC_LOG_DEBUG("maps", "MMAP:unloadMapInstance: Unloaded mapId %03u instanceId %u", mapId, instanceId);

        return true;
    }

    dtNavMesh const* MMapManager::GetNavMesh(uint32 mapId, TerrainSet swaps)
    {
        if (loadedMMaps.find(mapId) == loadedMMaps.end())
            return NULL;

        return loadedMMaps[mapId]->GetNavMesh(swaps);
    }

    dtNavMeshQuery const* MMapManager::GetNavMeshQuery(uint32 mapId, uint32 instanceId, TerrainSet swaps)
    {
        if (loadedMMaps.find(mapId) == loadedMMaps.end())
            return NULL;

        MMapData* mmap = loadedMMaps[mapId];
        if (mmap->navMeshQueries.find(instanceId) == mmap->navMeshQueries.end())
        {
            // allocate mesh query
            dtNavMeshQuery* query = dtAllocNavMeshQuery();
            ASSERT(query);
            if (dtStatusFailed(query->init(mmap->GetNavMesh(swaps), 1024)))
            {
                dtFreeNavMeshQuery(query);
                TC_LOG_ERROR("maps", "MMAP:GetNavMeshQuery: Failed to initialize dtNavMeshQuery for mapId %03u instanceId %u", mapId, instanceId);
                return NULL;
            }

            TC_LOG_DEBUG("maps", "MMAP:GetNavMeshQuery: created dtNavMeshQuery for mapId %03u instanceId %u", mapId, instanceId);
            mmap->navMeshQueries.insert(std::pair<uint32, dtNavMeshQuery*>(instanceId, query));
        }

        return mmap->navMeshQueries[instanceId];
    }

    MMapData::MMapData(dtNavMesh* mesh, uint32 mapId)
    {
        navMesh = mesh;
        _mapId = mapId;
    }

    MMapData::~MMapData()
    {
        for (NavMeshQuerySet::iterator i = navMeshQueries.begin(); i != navMeshQueries.end(); ++i)
            dtFreeNavMeshQuery(i->second);

        dtFreeNavMesh(navMesh);

        for (PhaseTileContainer::iterator i = _baseTiles.begin(); i != _baseTiles.end(); ++i)
        {
            delete (*i).second->data;
            delete (*i).second;
        }
    }

    void MMapData::RemoveSwap(PhasedTile* ptile, uint32 swap, uint32 packedXY)
    {
        uint32 x = (packedXY >> 16);
        uint32 y = (packedXY & 0x0000FFFF);

        if (loadedPhasedTiles[swap].find(packedXY) == loadedPhasedTiles[swap].end())
        {
            TC_LOG_DEBUG("phase", "MMapData::RemoveSwap: mmtile %03u[%02i, %02i] unload skipped, due to not loaded", swap, x, y);
            return;
        }
        dtMeshHeader* header = (dtMeshHeader*)ptile->data;

        // remove old tile
        if (dtStatusFailed(navMesh->removeTile(loadedTileRefs[packedXY], NULL, NULL)))
            TC_LOG_ERROR("phase", "MMapData::RemoveSwap: Could not unload phased %03u%02i%02i.mmtile from navmesh", swap, x, y);
        else
        {
            TC_LOG_DEBUG("phase", "MMapData::RemoveSwap: Unloaded phased %03u%02i%02i.mmtile from navmesh", swap, x, y);

            // restore base tile
            if (dtStatusSucceed(navMesh->addTile(_baseTiles[packedXY]->data, _baseTiles[packedXY]->dataSize, NULL, 0, &loadedTileRefs[packedXY])))
            {
                TC_LOG_DEBUG("phase", "MMapData::RemoveSwap: Loaded base mmtile %03u[%02i, %02i] into %03i[%02i, %02i]", _mapId, x, y, _mapId, header->x, header->y);
            }
            else
                TC_LOG_ERROR("phase", "MMapData::RemoveSwap: Could not load base %03u%02i%02i.mmtile to navmesh", _mapId, x, y);
        }

        loadedPhasedTiles[swap].erase(packedXY);

        if (loadedPhasedTiles[swap].empty())
        {
            _activeSwaps.erase(swap);
            TC_LOG_DEBUG("phase", "MMapData::RemoveSwap: Fully removed swap %u from map %u", swap, _mapId);
        }
    }

    void MMapData::AddSwap(PhasedTile* ptile, uint32 swap, uint32 packedXY)
    {

        uint32 x = (packedXY >> 16);
        uint32 y = (packedXY & 0x0000FFFF);

        if (loadedTileRefs.find(packedXY) == loadedTileRefs.end())
        {
            TC_LOG_DEBUG("phase", "MMapData::AddSwap: phased mmtile %03u[%02i, %02i] load skipped, due to not loaded base tile on map %u", swap, x, y, _mapId);
            return;
        }
        if (loadedPhasedTiles[swap].find(packedXY) != loadedPhasedTiles[swap].end())
        {
            TC_LOG_DEBUG("phase", "MMapData::AddSwap: WARNING! phased mmtile %03u[%02i, %02i] load skipped, due to already loaded on map %u", swap, x, y, _mapId);
            return;
        }


        dtMeshHeader* header = (dtMeshHeader*)ptile->data;

        const dtMeshTile* oldTile = navMesh->getTileByRef(loadedTileRefs[packedXY]);

        if (!oldTile)
        {
            TC_LOG_DEBUG("phase", "MMapData::AddSwap: phased mmtile %03u[%02i, %02i] load skipped, due to not loaded base tile ref on map %u", swap, x, y, _mapId);
            return;
        }

        uint32 old_x = oldTile->header->x;
        uint32 old_y = oldTile->header->y;

        // header xy is based on the swap map's tile set, wich doesn't have all the same tiles as root map, so copy the xy from the orignal header
        memcpy(ptile->data + 8, (char*)&old_x, 4);
        memcpy(ptile->data + 12, (char*)&old_y, 4);

        // the removed tile's data
        PhasedTile* pt = new PhasedTile();
        // remove old tile
        if (dtStatusFailed(navMesh->removeTile(loadedTileRefs[packedXY], &pt->data, &pt->dataSize)))
            TC_LOG_ERROR("phase", "MMapData::AddSwap: Could not unload %03u%02i%02i.mmtile from navmesh", _mapId, x, y);
        else
        {
            TC_LOG_DEBUG("phase", "MMapData::AddSwap: Unloaded %03u%02i%02i.mmtile from navmesh", _mapId, x, y);

            // store the removed data first time, this is the origonal, non-phased tile
            if (_baseTiles.find(packedXY) == _baseTiles.end())
                _baseTiles[packedXY] = pt;

            _activeSwaps.insert(swap);
            loadedPhasedTiles[swap].insert(packedXY);

            // add new swapped tile
            if (dtStatusSucceed(navMesh->addTile(ptile->data, ptile->fileHeader.size, NULL, 0, &loadedTileRefs[packedXY])))
            {
                TC_LOG_DEBUG("phase", "MMapData::AddSwap: Loaded phased mmtile %03u[%02i, %02i] into %03i[%02i, %02i]", swap, x, y, _mapId, header->x, header->y);
            }
            else
                TC_LOG_ERROR("phase", "MMapData::AddSwap: Could not load %03u%02i%02i.mmtile to navmesh", swap, x, y);
        }
    }

    dtNavMesh* MMapData::GetNavMesh(TerrainSet swaps)
    {
        for (uint32 swap : _activeSwaps)
        {
            if (swaps.find(swap) == swaps.end()) // swap not active
            {
                PhaseTileContainer ptc = MMAP::MMapFactory::createOrGetMMapManager()->GetPhaseTileContainer(swap);
                for (PhaseTileContainer::const_iterator itr = ptc.begin(); itr != ptc.end(); ++itr)
                {
                    RemoveSwap(itr->second, swap, itr->first); // remove swap
                }
            }
        }
        
        if (!swaps.empty())
        {
            // for each of the calling unit's terrain swaps
            for (uint32 swap : swaps)
            {
                // for each of the terrain swap's xy tiles
                PhaseTileContainer ptc = MMAP::MMapFactory::createOrGetMMapManager()->GetPhaseTileContainer(swap);
                for (PhaseTileContainer::const_iterator itr = ptc.begin(); itr != ptc.end(); ++itr)
                {
                    if (_activeSwaps.find(swap) == _activeSwaps.end()) // swap not active
                    {
                        AddSwap(itr->second, swap, itr->first); // add swap
                    }
                }
            }
        }
        return navMesh;
    }
}
