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

#ifndef TRINITY_GRID_MAP_H
#define TRINITY_GRID_MAP_H

#include "Define.h"
#include "MapDefines.h"
#include "Optional.h"
#include <cstdio>

struct LiquidData;
enum ZLiquidStatus : uint32;
namespace G3D { class Plane; }

class TC_GAME_API GridMap
{
    uint32  _flags;
    union{
        float* m_V9;
        uint16* m_uint16_V9;
        uint8* m_uint8_V9;
    };
    union{
        float* m_V8;
        uint16* m_uint16_V8;
        uint8* m_uint8_V8;
    };
    G3D::Plane* _minHeightPlanes;
    // Height level data
    float _gridHeight;
    float _gridIntHeightMultiplier;

    // Area data
    uint16* _areaMap;

    // Liquid data
    float _liquidLevel;
    uint16* _liquidEntry;
    map_liquidHeaderTypeFlags* _liquidFlags;
    float* _liquidMap;
    uint16 _gridArea;
    uint16 _liquidGlobalEntry;
    map_liquidHeaderTypeFlags _liquidGlobalFlags;
    uint8 _liquidOffX;
    uint8 _liquidOffY;
    uint8 _liquidWidth;
    uint8 _liquidHeight;

    uint16* _holes;

    bool loadAreaData(FILE* in, uint32 offset, uint32 size);
    bool loadHeightData(FILE* in, uint32 offset, uint32 size);
    bool loadLiquidData(FILE* in, uint32 offset, uint32 size);
    bool loadHolesData(FILE* in, uint32 offset, uint32 size);
    bool isHole(int row, int col) const;

    // Get height functions and pointers
    typedef float (GridMap::*GetHeightPtr) (float x, float y) const;
    GetHeightPtr _gridGetHeight;
    float getHeightFromFloat(float x, float y) const;
    float getHeightFromUint16(float x, float y) const;
    float getHeightFromUint8(float x, float y) const;
    float getHeightFromFlat(float x, float y) const;

public:
    GridMap();
    ~GridMap();

    enum class LoadResult
    {
        Ok,
        FileDoesNotExist,
        InvalidFile
    };

    LoadResult loadData(const char* filename);
    void unloadData();

    uint16 getArea(float x, float y) const;
    inline float getHeight(float x, float y) const {return (this->*_gridGetHeight)(x, y);}
    float getMinHeight(float x, float y) const;
    float getLiquidLevel(float x, float y) const;
    ZLiquidStatus GetLiquidStatus(float x, float y, float z, Optional<map_liquidHeaderTypeFlags> ReqLiquidType, LiquidData* data = 0, float collisionHeight = 2.03128f) const; // DEFAULT_COLLISION_HEIGHT in Object.h
};

#endif // TRINITY_GRID_MAP_H
