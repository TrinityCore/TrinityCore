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

#ifndef TILE_BUILD_H
#define TILE_BUILD_H
#include <string>
#include "Recast.h"

#include "Geometry.h"
#include "WorldModelRoot.h"

class ContinentBuilder;
class WDT;

class TileBuilder
{
public:
    TileBuilder(ContinentBuilder* _cBuilder, std::string world, int x, int y, uint32 mapId);
    ~TileBuilder();

    void CalculateTileBounds(float*& bmin, float*& bmax, dtNavMeshParams& navMeshParams) const;
    uint8* BuildTiled(dtNavMeshParams& navMeshParams);
    uint8* BuildInstance(dtNavMeshParams& navMeshParams);
    void AddGeometry(WorldModelRoot const* root, const WorldModelDefinition& def);
    void OutputDebugVertices() const;
    std::string World;
    int X;
    int Y;
    int MapId;
    rcConfig Config;
    rcConfig InstanceConfig;
    rcContext* Context;
    Geometry* _Geometry;
    uint32 DataSize;
    ContinentBuilder* cBuilder;
};
#endif