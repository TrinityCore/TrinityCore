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

#include "MMapManager.h"
#include "Log.h"
#include "World.h"

namespace MMAP
{
    MMapManager::~MMapManager()
    {
        for (MMapDataSet::iterator i = _loadedMaps.begin(); i != _loadedMaps.end(); ++i)
            delete i->second;
    }

    bool MMapManager::LoadMap(uint32 mapId)
    {
        // Do not load a map twice.
        if (_loadedMaps.find(mapId) != _loadedMaps.end())
            return true;

        // load and init dtNavMesh - read parameters from file
        std::string basePath = sWorld->GetDataPath();
        uint32 pathLen = basePath.length() + strlen("mmaps/%03i.mmap") + 1;
        char* fileName = new char[pathLen];
        snprintf(fileName, pathLen, (basePath + "mmaps/%03i.mmap").c_str(), mapId);

        FILE* file = fopen(fileName, "rb");
        if (!file)
        {
            TC_LOG_DEBUG("maps", "MMAP::LoadMap: Error: Could not open mmap file '%s'", fileName);
            delete[] fileName;
            return false;
        }

        dtNavMeshParams params;
        int count = fread(&params, sizeof(dtNavMeshParams), 1, file);
        fclose(file);
        if (count != 1)
        {
            TC_LOG_DEBUG("maps", "MMAP::LoadMap: Error: Could not read params from file '%s'", fileName);
            delete[] fileName;
            return false;
        }

        dtNavMesh* mesh = dtAllocNavMesh();
        if (dtStatusFailed(mesh->init(&params)))
        {
            dtFreeNavMesh(mesh);
            TC_LOG_ERROR("maps", "MMAP::LoadMap: Failed to initialize dtNavMesh for mmap %03u from file %s", mapId, fileName);
            delete[] fileName;
            return false;
        }

        delete[] fileName;

        TC_LOG_INFO("maps", "MMAP::LoadMap: Loaded %03i.mmap", mapId);

        // store inside our map list
        MMapData* mmapData = new MMapData(mesh);
        mmapData->_loadedTiles.clear();

        _loadedMaps.insert(std::pair<uint32, MMapData*>(mapId, mmapData));
        return true;
    }

    bool MMapManager::LoadMapTile(uint32 mapId, int32 x, int32 y)
    {
        // make sure the mmap is loaded and ready to load tiles
        if (!LoadMap(mapId))
            return false;

        // get this mmap data
        MMapData* mmap = _loadedMaps[mapId];
        ASSERT(mmap->navMesh);

        // Check if we already have this tile loaded
        uint32 pos = PackTileId(x, y);
        if (mmap->_loadedTiles.find(pos) != mmap->_loadedTiles.end())
            return false;

        std::string basePath = sWorld->GetDataPath();
        uint32 pathLen = basePath.length() + strlen("mmaps/%03i%02i%02i.mmtile") + 1;
        char* fileName = new char[pathLen];

        snprintf(fileName, pathLen, (basePath + "mmaps/%03i%02i%02i.mmtile").c_str(), mapId, x, y);

        FILE* file = fopen(fileName, "rb");
        if (!file)
        {
            TC_LOG_DEBUG("maps", "MMAP::LoadMapTile: Could not open mmtile file '%s'", fileName);
            delete[] fileName;
            return false;
        }

        delete[] fileName;

        // read header
        MmapTileHeader fileHeader;
        if (fread(&fileHeader, sizeof(MmapTileHeader), 1, file) != 1 || fileHeader.mmapMagic != MMAP_MAGIC)
        {
            TC_LOG_ERROR("maps", "MMAP::LoadMapTile: Bad header in mmap %03u%02i%02i.mmtile", mapId, x, y);
            fclose(file);
            return false;
        }

        if (fileHeader.mmapVersion != MMAP_VERSION)
        {
            TC_LOG_ERROR("maps", "MMAP::LoadMapTile: %03u%02i%02i.mmtile was built with generator v%i, expected v%i",
                mapId, x, y, fileHeader.mmapVersion, MMAP_VERSION);
            fclose(file);
            return false;
        }

        unsigned char* data = (unsigned char*)dtAlloc(fileHeader.size, DT_ALLOC_PERM);
        ASSERT(data);

        size_t result = fread(data, fileHeader.size, 1, file);
        if (result != 1)
        {
            TC_LOG_ERROR("maps", "MMAP::LoadMapTile: Bad header or data in mmap %03u%02i%02i.mmtile", mapId, x, y);
            fclose(file);
            return false;
        }

        fclose(file);

        dtMeshHeader* header = (dtMeshHeader*)data;
        dtTileRef tileRef = 0;

        // memory allocated for data is now managed by detour, and will be deallocated when the tile is removed
        if (dtStatusSucceed(mmap->navMesh->addTile(data, fileHeader.size, DT_TILE_FREE_DATA, 0, &tileRef)))
        {
            mmap->_loadedTiles.insert(std::pair<uint32, dtTileRef>(pos, tileRef));
            ++_loadedTiles;
            TC_LOG_INFO("maps", "MMAP::LoadMapTile: Loaded mmtile %03i[%02i, %02i] into %03i[%02i, %02i]", mapId, x, y, mapId, header->x, header->y);
            return true;
        }
        else
        {
            TC_LOG_ERROR("maps", "MMAP::LoadMapTile: Could not load %03u%02i%02i.mmtile into navmesh", mapId, x, y);
            dtFree(data);
            return false;
        }

        return false;
    }

    bool MMapManager::UnloadMapTile(uint32 mapId, int32 x, int32 y)
    {
        // Do not attempt to remove tiles from a not-loaded map
        if (_loadedMaps.find(mapId) == _loadedMaps.end())
        {
            TC_LOG_DEBUG("maps", "MMAP::UnloadMapTile: Asked to unload not loaded navmesh map. %03u%02i%02i.mmtile", mapId, x, y);
            return false;
        }

        MMapData* mmap = _loadedMaps[mapId];

        // check if we have this tile loaded
        uint32 pos = PackTileId(x, y);
        if (mmap->_loadedTiles.find(pos) == mmap->_loadedTiles.end())
        {
            TC_LOG_DEBUG("maps", "MMAP::UnloadMapTile: Asked to unload not loaded navmesh tile. %03u%02i%02i.mmtile", mapId, x, y);
            return false;
        }

        dtTileRef tileRef = mmap->_loadedTiles[pos];

        // unload, and mark as non loaded
        if (dtStatusFailed(mmap->navMesh->removeTile(tileRef, NULL, NULL)))
        {
            // this is technically a memory leak
            // if the grid is later reloaded, dtNavMesh::addTile will return error but no extra memory is used
            // we cannot recover from this error - assert out
            TC_LOG_ERROR("maps", "MMAP::UnloadMapTile: Could not unload %03u%02i%02i.mmtile from navmesh", mapId, x, y);
            ASSERT(false);
        }
        else
        {
            mmap->_loadedTiles.erase(pos);
            --_loadedTiles;
            TC_LOG_INFO("maps", "MMAP::UnloadMapTile: Unloaded mmtile [%02i, %02i] from %03i", x, y, mapId);
            return true;
        }

        return false;
    }

    bool MMapManager::UnloadMap(uint32 mapId)
    {
        if (_loadedMaps.find(mapId) == _loadedMaps.end())
        {
            // file may not exist, therefore not loaded
            TC_LOG_DEBUG("maps", "MMAP::UnloadMap: Asked to unload not loaded navmesh map %03u", mapId);
            return false;
        }

        // unload all tiles from given map
        MMapData* mmap = _loadedMaps[mapId];
        for (MMapTileSet::iterator i = mmap->_loadedTiles.begin(); i != mmap->_loadedTiles.end(); ++i)
        {
            uint32 x = (i->first >> 16);
            uint32 y = (i->first & 0x0000FFFF);
            if (dtStatusFailed(mmap->navMesh->removeTile(i->second, NULL, NULL)))
                TC_LOG_ERROR("maps", "MMAP::UnloadMap: Could not unload %03u%02u%02u.mmtile from navmesh", mapId, x, y);
            else
            {
                --_loadedTiles;
                TC_LOG_INFO("maps", "MMAP::UnloadMap: Unloaded mmtile [%02u, %02u] from %03u", x, y, mapId);
            }
        }

        delete mmap;
        _loadedMaps.erase(mapId);
        TC_LOG_INFO("maps", "MMAP::UnloadMap: Unloaded %03u.mmap", mapId);

        return true;
    }

    bool MMapManager::UnloadMapInstance(uint32 mapId, uint32 instanceId)
    {
        // check if we have this map loaded
        if (_loadedMaps.find(mapId) == _loadedMaps.end())
        {
            // file may not exist, therefore not loaded
            TC_LOG_DEBUG("maps", "MMAP::UnloadMapInstance: Asked to unload not loaded navmesh map %03u", mapId);
            return false;
        }

        MMapData* mmap = _loadedMaps[mapId];
        if (mmap->_navMeshQueries.find(instanceId) == mmap->_navMeshQueries.end())
        {
            TC_LOG_DEBUG("maps", "MMAP::UnloadMapInstance: Asked to unload not loaded dtNavMeshQuery mapId %03u instanceId %u", mapId, instanceId);
            return false;
        }

        dtNavMeshQuery* query = mmap->_navMeshQueries[instanceId];

        dtFreeNavMeshQuery(query);
        mmap->_navMeshQueries.erase(instanceId);
        TC_LOG_INFO("maps", "MMAP::UnloadMapInstance: Unloaded mapId %03u instanceId %u", mapId, instanceId);

        return true;
    }

    dtNavMesh const* MMapManager::GetNavMesh(uint32 mapId)
    {
        if (_loadedMaps.find(mapId) == _loadedMaps.end())
            return NULL;

        return _loadedMaps[mapId]->navMesh;
    }

    dtNavMeshQuery const* MMapManager::GetNavMeshQuery(uint32 mapId, uint32 instanceId)
    {
        if (_loadedMaps.find(mapId) == _loadedMaps.end())
            return NULL;

        MMapData* mmap = _loadedMaps[mapId];
        if (mmap->_navMeshQueries.find(instanceId) == mmap->_navMeshQueries.end())
        {
            // allocate mesh query
            dtNavMeshQuery* query = dtAllocNavMeshQuery();
            if (dtStatusFailed(query->init(mmap->navMesh, 2048)))
            {
                dtFreeNavMeshQuery(query);
                TC_LOG_ERROR("maps", "MMAP::GetNavMeshQuery: Failed to initialize dtNavMeshQuery for mapId %03u instanceId %u", mapId, instanceId);
                return NULL;
            }

            TC_LOG_INFO("maps", "MMAP:GetNavMeshQuery: created dtNavMeshQuery for mapId %03u instanceId %u", mapId, instanceId);
            mmap->_navMeshQueries.insert(std::pair<uint32, dtNavMeshQuery*>(instanceId, query));
        }

        return mmap->_navMeshQueries[instanceId];
    }
}
