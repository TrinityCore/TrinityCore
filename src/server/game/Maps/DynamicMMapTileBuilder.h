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

#ifndef TRINITYCORE_DYNAMIC_MMAP_TILE_BUILDER_H
#define TRINITYCORE_DYNAMIC_MMAP_TILE_BUILDER_H

#include "AsyncCallbackProcessor.h"
#include "TileBuilder.h"
#include "Timer.h"
#include <atomic>

class Map;

namespace MMAP
{
struct TileBuildRequest;
bool InvokeAsyncCallbackIfReady(TileBuildRequest& request);

class DynamicTileBuilder : public TileBuilder, public std::enable_shared_from_this<DynamicTileBuilder>
{
public:
    explicit DynamicTileBuilder(Map* map, dtNavMesh* navMesh);
    DynamicTileBuilder(DynamicTileBuilder const& other) = delete;
    DynamicTileBuilder(DynamicTileBuilder&& other) = delete;
    DynamicTileBuilder& operator=(DynamicTileBuilder const& other) = delete;
    DynamicTileBuilder& operator=(DynamicTileBuilder&& other) = delete;
    ~DynamicTileBuilder();

    void AddTile(uint32 terrainMapId, uint32 tileX, uint32 tileY);

    void Update(Milliseconds diff);

    struct AsyncTileResult
    {
        TileResult Result;
        std::atomic<bool> IsReady;
    };

private:
    std::weak_ptr<AsyncTileResult> BuildTile(uint32 terrainMapId, uint32 tileX, uint32 tileY);

    Map* m_map;
    dtNavMesh* m_navMesh;

    struct TileId;
    std::vector<TileId> m_tilesToRebuild;

    TimeTracker m_rebuildCheckTimer;

    friend TileBuildRequest;
    AsyncCallbackProcessor<TileBuildRequest> m_tiles;
};
}

#endif // TRINITYCORE_DYNAMIC_MMAP_TILE_BUILDER_H
