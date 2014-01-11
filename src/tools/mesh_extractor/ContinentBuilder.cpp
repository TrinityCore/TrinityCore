/*
 * Copyright (C) 2008-2014 TrinityCore <http://www.trinitycore.org/>
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

#include "ContinentBuilder.h"
#include "WDT.h"
#include "Utils.h"
#include "DetourNavMesh.h"
#include "Cache.h"
#include "Recast.h"
#include "DetourCommon.h"

void ContinentBuilder::getTileBounds(uint32 tileX, uint32 tileY, float* verts, int vertCount, float* bmin, float* bmax) const
{
    // this is for elevation
    if (verts && vertCount)
        rcCalcBounds(verts, vertCount, bmin, bmax);
    else
    {
        bmin[1] = -FLT_MAX;
        bmax[1] = FLT_MAX;
    }

    // this is for width and depth
    bmax[0] = (32 - int(tileX)) * Constants::TileSize;
    bmax[2] = (32 - int(tileY)) * Constants::TileSize;
    bmin[0] = bmax[0] - Constants::TileSize;
    bmin[2] = bmax[2] - Constants::TileSize;
}

void ContinentBuilder::CalculateTileBounds()
{
    for (std::vector<TilePos>::iterator itr = TileMap->TileTable.begin(); itr != TileMap->TileTable.end(); ++itr)
    {
        tileXMax = std::max(itr->X, tileXMax);
        tileXMin = std::min(itr->X, tileXMin);

        tileYMax = std::max(itr->Y, tileYMax);
        tileYMin = std::min(itr->Y, tileYMin);
    }
    getTileBounds(tileXMax, tileYMax, NULL, 0, bmin, bmax);
}

void ContinentBuilder::Build()
{
    char buff[50];
    sprintf(buff, "mmaps/%03u.mmap", MapId);
    FILE* mmap = fopen(buff, "wb");
    if (!mmap)
    {
        printf("Could not create file %s. Check that you have write permissions to the destination folder and try again\n", buff);
        return;
    }

    CalculateTileBounds();

    dtNavMeshParams params;
    
    if (TileMap->IsGlobalModel)
    {
        printf("Map %s ( %u ) is a WMO. Building with 1 thread.\n", Continent.c_str(), MapId);
        
        TileBuilder* builder = new TileBuilder(this, Continent, 0, 0, MapId);
        builder->AddGeometry(TileMap->Model, TileMap->ModelDefinition);
        uint8* nav = builder->BuildInstance(params);
        if (nav)
        {
            // Set some params for the navmesh
            dtMeshHeader* header = (dtMeshHeader*)nav;
            dtVcopy(params.orig, header->bmin);
            params.tileWidth = header->bmax[0] - header->bmin[0];
            params.tileHeight = header->bmax[2] - header->bmin[2];
            params.maxTiles = 1;
            params.maxPolys = header->polyCount;
            fwrite(&params, sizeof(dtNavMeshParams), 1, mmap);
            fclose(mmap);

            char buff[100];
            sprintf(buff, "mmaps/%03u%02i%02i.mmtile", MapId, 0, 0);
            FILE* f = fopen(buff, "wb");
            if (!f)
            {
                printf("Could not create file %s. Check that you have write permissions to the destination folder and try again\n", buff);
                return;
            }

            MmapTileHeader mheader;
            Utils::InitializeMmapTileHeader(mheader);
            mheader.size = builder->DataSize;
            fwrite(&mheader, sizeof(MmapTileHeader), 1, f);
            fwrite(nav, sizeof(unsigned char), builder->DataSize, f);
            fclose(f);
        }

        dtFree(nav);
        delete builder;
    }
    else
    {
        params.maxPolys = 1024;
        params.maxTiles = TileMap->TileTable.size();
        rcVcopy(params.orig, Constants::Origin);
        params.tileHeight = Constants::TileSize;
        params.tileWidth = Constants::TileSize;
        fwrite(&params, sizeof(dtNavMeshParams), 1, mmap);
        fclose(mmap);

        std::vector<BuilderThread*> _threads;
        BuilderThreadPool* pool = NumberOfThreads > 0 ? new BuilderThreadPool() : NULL;

        printf("Map %s ( %u ) has %u tiles. Building them with %u threads\n", Continent.c_str(), MapId, uint32(TileMap->TileTable.size()), NumberOfThreads);

        for (std::vector<TilePos>::iterator itr = TileMap->TileTable.begin(); itr != TileMap->TileTable.end(); ++itr)
            pool->Enqueue(new TileBuildRequest(this, Continent, itr->X, itr->Y, MapId, params));

        for (uint32 i = 0; i < NumberOfThreads; ++i)
            _threads.push_back(new BuilderThread(this, pool->Queue()));

        // Free memory
        for (std::vector<BuilderThread*>::iterator _th = _threads.begin(); _th != _threads.end(); ++_th)
        {
            (*_th)->wait();
            delete *_th;
        }

        delete pool;
    }

    Cache->Clear();
}

int TileBuildRequest::call()
{
    printf("[%02i,%02i] Building tile\n", X, Y);
    // Build the tile and return negative on error
    TileBuilder tile(_builder, _continent, X, Y, _mapId);
    char buff[100];
    sprintf(buff, "mmaps/%03u%02i%02i.mmtile", _mapId, Y, X);
    FILE* f = fopen(buff, "r");
    if (f) // Check if file already exists.
    {
        printf("[%02i,%02i] Tile skipped, file already exists\n", X, Y);
        fclose(f);
        return 0;
    }
    uint8* nav = tile.BuildTiled(_params);
    if (nav)
    {
        f = fopen(buff, "wb");
        if (!f)
        {
            printf("Could not create file %s. Check that you have write permissions to the destination folder and try again\n", buff);
            dtFree(nav);
            return -1;
        }
        MmapTileHeader header;
        Utils::InitializeMmapTileHeader(header);
        header.size = tile.DataSize;
        fwrite(&header, sizeof(MmapTileHeader), 1, f);
        fwrite(nav, sizeof(unsigned char), tile.DataSize, f);
        fclose(f);
    }
    dtFree(nav);
    printf("[%02i,%02i] Tile Built!\n", X, Y);
    return 0;
}
