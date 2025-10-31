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

#ifndef TRINITYCORE_TILE_BUILDER_H
#define TRINITYCORE_TILE_BUILDER_H

#include "Define.h"
#include "StringFormat.h"
#include "TerrainBuilder.h"
#include <DetourNavMesh.h>
#include <Recast.h>

namespace MMAP
{
struct TileConfig;

class TileBuilder
{
public:
    TileBuilder(Optional<float> maxWalkableAngle,
        Optional<float> maxWalkableAngleNotSteep,
        bool skipLiquid,
        bool bigBaseUnit,
        bool debugOutput,
        std::vector<OffMeshData> const* offMeshConnections);

    TileBuilder(TileBuilder const&) = delete;
    TileBuilder(TileBuilder&&) = delete;

    TileBuilder& operator=(TileBuilder const&) = delete;
    TileBuilder& operator=(TileBuilder&&) = delete;

    virtual ~TileBuilder();

    void buildTile(uint32 mapID, uint32 tileX, uint32 tileY, dtNavMesh* navMesh);
    // move map building
    void buildMoveMapTile(uint32 mapID,
        uint32 tileX,
        uint32 tileY,
        MeshData& meshData,
        float (&bmin)[3],
        float (&bmax)[3],
        dtNavMesh* navMesh);

    virtual bool shouldSkipTile(uint32 mapID, uint32 tileX, uint32 tileY) const;

    static void getTileBounds(uint32 tileX, uint32 tileY,
        float* verts, int vertCount,
        float* bmin, float* bmax);

    rcConfig GetMapSpecificConfig(uint32 mapID, float const (&bmin)[3], float const (&bmax)[3], TileConfig const& tileConfig) const;

    virtual std::string GetProgressText() const;

    virtual void OnTileDone() { }

private:
    Optional<float> m_maxWalkableAngle;
    Optional<float> m_maxWalkableAngleNotSteep;
    bool m_bigBaseUnit;
    bool m_debugOutput;

    TerrainBuilder m_terrainBuilder;
    // build performance - not really used for now
    rcContext m_rcContext;
    std::vector<OffMeshData> const* m_offMeshConnections;
};
}

#endif // TRINITYCORE_TILE_BUILDER_H
