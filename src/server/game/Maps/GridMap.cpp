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

#include "GridMap.h"
#include "DBCStores.h"
#include "GridDefines.h"
#include "Log.h"
#include <G3D/Plane.h>
#include <G3D/Ray.h>

static uint16 const holetab_h[4] = { 0x1111, 0x2222, 0x4444, 0x8888 };
static uint16 const holetab_v[4] = { 0x000F, 0x00F0, 0x0F00, 0xF000 };

// *****************************
// Grid function
// *****************************
GridMap::GridMap()
{
    _flags = 0;
    // Area data
    _gridArea = 0;
    _areaMap = nullptr;
    // Height level data
    _gridHeight = INVALID_HEIGHT;
    _gridGetHeight = &GridMap::getHeightFromFlat;
    _gridIntHeightMultiplier = 0;
    m_V9 = nullptr;
    m_V8 = nullptr;
    _minHeightPlanes = nullptr;
    // Liquid data
    _liquidGlobalEntry = 0;
    _liquidGlobalFlags = map_liquidHeaderTypeFlags::NoWater;
    _liquidOffX   = 0;
    _liquidOffY   = 0;
    _liquidWidth  = 0;
    _liquidHeight = 0;
    _liquidLevel = INVALID_HEIGHT;
    _liquidEntry = nullptr;
    _liquidFlags = nullptr;
    _liquidMap  = nullptr;
    _holes = nullptr;
}

GridMap::~GridMap()
{
    unloadData();
}

GridMap::LoadResult GridMap::loadData(const char* filename)
{
    // Unload old data if exist
    unloadData();

    map_fileheader header;
    // Not return error if file not found
    FILE* in = fopen(filename, "rb");
    if (!in)
        return LoadResult::FileDoesNotExist;

    if (fread(&header, sizeof(header), 1, in) != 1)
    {
        fclose(in);
        return LoadResult::InvalidFile;
    }

    if (header.mapMagic == MapMagic && header.versionMagic == MapVersionMagic)
    {
        // load up area data
        if (header.areaMapOffset && !loadAreaData(in, header.areaMapOffset, header.areaMapSize))
        {
            TC_LOG_ERROR("maps", "Error loading map area data\n");
            fclose(in);
            return LoadResult::InvalidFile;
        }
        // load up height data
        if (header.heightMapOffset && !loadHeightData(in, header.heightMapOffset, header.heightMapSize))
        {
            TC_LOG_ERROR("maps", "Error loading map height data\n");
            fclose(in);
            return LoadResult::InvalidFile;
        }
        // load up liquid data
        if (header.liquidMapOffset && !loadLiquidData(in, header.liquidMapOffset, header.liquidMapSize))
        {
            TC_LOG_ERROR("maps", "Error loading map liquids data\n");
            fclose(in);
            return LoadResult::InvalidFile;
        }
        // loadup holes data (if any. check header.holesOffset)
        if (header.holesSize && !loadHolesData(in, header.holesOffset, header.holesSize))
        {
            TC_LOG_ERROR("maps", "Error loading map holes data\n");
            fclose(in);
            return LoadResult::InvalidFile;
        }
        fclose(in);
        return LoadResult::Ok;
    }

    TC_LOG_ERROR("maps", "Map file '%s' is from an incompatible map version (%.*s v%u), %.*s v%u is expected. Please pull your source, recompile tools and recreate maps using the updated mapextractor, then replace your old map files with new files. If you still have problems search on forum for error TCE00018.",
        filename, 4, header.mapMagic.data(), header.versionMagic, 4, MapMagic.data(), MapVersionMagic);
    fclose(in);
    return LoadResult::InvalidFile;
}

void GridMap::unloadData()
{
    delete[] _areaMap;
    delete[] m_V9;
    delete[] m_V8;
    delete[] _minHeightPlanes;
    delete[] _liquidEntry;
    delete[] _liquidFlags;
    delete[] _liquidMap;
    delete[] _holes;
    _areaMap = nullptr;
    m_V9 = nullptr;
    m_V8 = nullptr;
    _minHeightPlanes = nullptr;
    _liquidEntry = nullptr;
    _liquidFlags = nullptr;
    _liquidMap  = nullptr;
    _holes = nullptr;
    _gridGetHeight = &GridMap::getHeightFromFlat;
}

bool GridMap::loadAreaData(FILE* in, uint32 offset, uint32 /*size*/)
{
    map_areaHeader header;
    fseek(in, offset, SEEK_SET);

    if (fread(&header, sizeof(header), 1, in) != 1 || header.areaMagic != MapAreaMagic)
        return false;

    _gridArea = header.gridArea;
    if (!header.flags.HasFlag(map_areaHeaderFlags::NoArea))
    {
        _areaMap = new uint16[16 * 16];
        if (fread(_areaMap, sizeof(uint16), 16 * 16, in) != 16 * 16)
            return false;
    }
    return true;
}

bool GridMap::loadHeightData(FILE* in, uint32 offset, uint32 /*size*/)
{
    map_heightHeader header;
    fseek(in, offset, SEEK_SET);

    if (fread(&header, sizeof(header), 1, in) != 1 || header.heightMagic != MapHeightMagic)
        return false;

    _gridHeight = header.gridHeight;
    if (!header.flags.HasFlag(map_heightHeaderFlags::NoHeight))
    {
        if (header.flags.HasFlag(map_heightHeaderFlags::HeightAsInt16))
        {
            m_uint16_V9 = new uint16 [129*129];
            m_uint16_V8 = new uint16 [128*128];
            if (fread(m_uint16_V9, sizeof(uint16), 129*129, in) != 129*129 ||
                fread(m_uint16_V8, sizeof(uint16), 128*128, in) != 128*128)
                return false;
            _gridIntHeightMultiplier = (header.gridMaxHeight - header.gridHeight) / 65535;
            _gridGetHeight = &GridMap::getHeightFromUint16;
        }
        else if (header.flags.HasFlag(map_heightHeaderFlags::HeightAsInt8))
        {
            m_uint8_V9 = new uint8 [129*129];
            m_uint8_V8 = new uint8 [128*128];
            if (fread(m_uint8_V9, sizeof(uint8), 129*129, in) != 129*129 ||
                fread(m_uint8_V8, sizeof(uint8), 128*128, in) != 128*128)
                return false;
            _gridIntHeightMultiplier = (header.gridMaxHeight - header.gridHeight) / 255;
            _gridGetHeight = &GridMap::getHeightFromUint8;
        }
        else
        {
            m_V9 = new float [129*129];
            m_V8 = new float [128*128];
            if (fread(m_V9, sizeof(float), 129*129, in) != 129*129 ||
                fread(m_V8, sizeof(float), 128*128, in) != 128*128)
                return false;
            _gridGetHeight = &GridMap::getHeightFromFloat;
        }
    }
    else
        _gridGetHeight = &GridMap::getHeightFromFlat;

    if (header.flags.HasFlag(map_heightHeaderFlags::HasFlightBounds))
    {
        std::array<int16, 9> maxHeights;
        std::array<int16, 9> minHeights;
        if (fread(maxHeights.data(), sizeof(int16), maxHeights.size(), in) != maxHeights.size() ||
            fread(minHeights.data(), sizeof(int16), minHeights.size(), in) != minHeights.size())
            return false;

        static uint32 constexpr indices[8][3] =
        {
            { 3, 0, 4 },
            { 0, 1, 4 },
            { 1, 2, 4 },
            { 2, 5, 4 },
            { 5, 8, 4 },
            { 8, 7, 4 },
            { 7, 6, 4 },
            { 6, 3, 4 }
        };

        static float constexpr boundGridCoords[9][2] =
        {
            { 0.0f, 0.0f },
            { 0.0f, -266.66666f },
            { 0.0f, -533.33331f },
            { -266.66666f, 0.0f },
            { -266.66666f, -266.66666f },
            { -266.66666f, -533.33331f },
            { -533.33331f, 0.0f },
            { -533.33331f, -266.66666f },
            { -533.33331f, -533.33331f }
        };

        _minHeightPlanes = new G3D::Plane[8];
        for (uint32 quarterIndex = 0; quarterIndex < 8; ++quarterIndex)
            _minHeightPlanes[quarterIndex] = G3D::Plane(
                G3D::Vector3(boundGridCoords[indices[quarterIndex][0]][0], boundGridCoords[indices[quarterIndex][0]][1], minHeights[indices[quarterIndex][0]]),
                G3D::Vector3(boundGridCoords[indices[quarterIndex][1]][0], boundGridCoords[indices[quarterIndex][1]][1], minHeights[indices[quarterIndex][1]]),
                G3D::Vector3(boundGridCoords[indices[quarterIndex][2]][0], boundGridCoords[indices[quarterIndex][2]][1], minHeights[indices[quarterIndex][2]])
            );
    }

    return true;
}

bool GridMap::loadLiquidData(FILE* in, uint32 offset, uint32 /*size*/)
{
    map_liquidHeader header;
    fseek(in, offset, SEEK_SET);

    if (fread(&header, sizeof(header), 1, in) != 1 || header.liquidMagic != MapLiquidMagic)
        return false;

    _liquidGlobalEntry = header.liquidType;
    _liquidGlobalFlags = header.liquidFlags;
    _liquidOffX  = header.offsetX;
    _liquidOffY  = header.offsetY;
    _liquidWidth = header.width;
    _liquidHeight = header.height;
    _liquidLevel  = header.liquidLevel;

    if (!header.flags.HasFlag(map_liquidHeaderFlags::NoType))
    {
        _liquidEntry = new uint16[16*16];
        if (fread(_liquidEntry, sizeof(uint16), 16*16, in) != 16*16)
            return false;

        _liquidFlags = new map_liquidHeaderTypeFlags[16*16];
        if (fread(_liquidFlags, sizeof(map_liquidHeaderTypeFlags), 16*16, in) != 16*16)
            return false;
    }
    if (!header.flags.HasFlag(map_liquidHeaderFlags::NoHeight))
    {
        _liquidMap = new float[uint32(_liquidWidth) * uint32(_liquidHeight)];
        if (fread(_liquidMap, sizeof(float), _liquidWidth*_liquidHeight, in) != (uint32(_liquidWidth) * uint32(_liquidHeight)))
            return false;
    }
    return true;
}

bool GridMap::loadHolesData(FILE* in, uint32 offset, uint32 /*size*/)
{
    if (fseek(in, offset, SEEK_SET) != 0)
        return false;

    _holes = new uint16[16 * 16];
    if (fread(_holes, sizeof(uint16), 16 * 16, in) != 16 * 16)
        return false;

    return true;
}

uint16 GridMap::getArea(float x, float y) const
{
    if (!_areaMap)
        return _gridArea;

    x = 16 * (CENTER_GRID_ID - x/SIZE_OF_GRIDS);
    y = 16 * (CENTER_GRID_ID - y/SIZE_OF_GRIDS);
    int lx = (int)x & 15;
    int ly = (int)y & 15;
    return _areaMap[lx*16 + ly];
}

float GridMap::getHeightFromFlat(float /*x*/, float /*y*/) const
{
    return _gridHeight;
}

float GridMap::getHeightFromFloat(float x, float y) const
{
    if (!m_V8 || !m_V9)
        return _gridHeight;

    x = MAP_RESOLUTION * (CENTER_GRID_ID - x / SIZE_OF_GRIDS);
    y = MAP_RESOLUTION * (CENTER_GRID_ID - y / SIZE_OF_GRIDS);

    int x_int = (int)x;
    int y_int = (int)y;
    x -= x_int;
    y -= y_int;
    x_int &= (MAP_RESOLUTION - 1);
    y_int &= (MAP_RESOLUTION - 1);

    if (isHole(x_int, y_int))
        return INVALID_HEIGHT;

    // Height stored as: h5 - its v8 grid, h1-h4 - its v9 grid
    // +--------------> X
    // | h1-------h2     Coordinates is:
    // | | \  1  / |     h1 0, 0
    // | |  \   /  |     h2 0, 1
    // | | 2  h5 3 |     h3 1, 0
    // | |  /   \  |     h4 1, 1
    // | | /  4  \ |     h5 1/2, 1/2
    // | h3-------h4
    // V Y
    // For find height need
    // 1 - detect triangle
    // 2 - solve linear equation from triangle points
    // Calculate coefficients for solve h = a*x + b*y + c

    float a, b, c;
    // Select triangle:
    if (x + y < 1)
    {
        if (x > y)
        {
            // 1 triangle (h1, h2, h5 points)
            float h1 = m_V9[(x_int) * 129 + y_int];
            float h2 = m_V9[(x_int + 1) * 129 + y_int];
            float h5 = 2 * m_V8[x_int * 128 + y_int];
            a = h2 - h1;
            b = h5 - h1 - h2;
            c = h1;
        }
        else
        {
            // 2 triangle (h1, h3, h5 points)
            float h1 = m_V9[x_int * 129 + y_int];
            float h3 = m_V9[x_int * 129 + y_int + 1];
            float h5 = 2 * m_V8[x_int * 128 + y_int];
            a = h5 - h1 - h3;
            b = h3 - h1;
            c = h1;
        }
    }
    else
    {
        if (x > y)
        {
            // 3 triangle (h2, h4, h5 points)
            float h2 = m_V9[(x_int + 1) * 129 + y_int];
            float h4 = m_V9[(x_int + 1) * 129 + y_int + 1];
            float h5 = 2 * m_V8[x_int * 128 + y_int];
            a = h2 + h4 - h5;
            b = h4 - h2;
            c = h5 - h4;
        }
        else
        {
            // 4 triangle (h3, h4, h5 points)
            float h3 = m_V9[(x_int) * 129 + y_int + 1];
            float h4 = m_V9[(x_int + 1) * 129 + y_int + 1];
            float h5 = 2 * m_V8[x_int * 128 + y_int];
            a = h4 - h3;
            b = h3 + h4 - h5;
            c = h5 - h4;
        }
    }
    // Calculate height
    return a * x + b * y + c;
}


float GridMap::getHeightFromUint8(float x, float y) const
{
    if (!m_uint8_V8 || !m_uint8_V9)
        return _gridHeight;

    x = MAP_RESOLUTION * (CENTER_GRID_ID - x/SIZE_OF_GRIDS);
    y = MAP_RESOLUTION * (CENTER_GRID_ID - y/SIZE_OF_GRIDS);

    int x_int = (int)x;
    int y_int = (int)y;
    x -= x_int;
    y -= y_int;
    x_int&=(MAP_RESOLUTION - 1);
    y_int&=(MAP_RESOLUTION - 1);

    if (isHole(x_int, y_int))
        return INVALID_HEIGHT;

    int32 a, b, c;
    uint8 *V9_h1_ptr = &m_uint8_V9[x_int*128 + x_int + y_int];
    if (x+y < 1)
    {
        if (x > y)
        {
            // 1 triangle (h1, h2, h5 points)
            int32 h1 = V9_h1_ptr[  0];
            int32 h2 = V9_h1_ptr[129];
            int32 h5 = 2 * m_uint8_V8[x_int*128 + y_int];
            a = h2-h1;
            b = h5-h1-h2;
            c = h1;
        }
        else
        {
            // 2 triangle (h1, h3, h5 points)
            int32 h1 = V9_h1_ptr[0];
            int32 h3 = V9_h1_ptr[1];
            int32 h5 = 2 * m_uint8_V8[x_int*128 + y_int];
            a = h5 - h1 - h3;
            b = h3 - h1;
            c = h1;
        }
    }
    else
    {
        if (x > y)
        {
            // 3 triangle (h2, h4, h5 points)
            int32 h2 = V9_h1_ptr[129];
            int32 h4 = V9_h1_ptr[130];
            int32 h5 = 2 * m_uint8_V8[x_int*128 + y_int];
            a = h2 + h4 - h5;
            b = h4 - h2;
            c = h5 - h4;
        }
        else
        {
            // 4 triangle (h3, h4, h5 points)
            int32 h3 = V9_h1_ptr[  1];
            int32 h4 = V9_h1_ptr[130];
            int32 h5 = 2 * m_uint8_V8[x_int*128 + y_int];
            a = h4 - h3;
            b = h3 + h4 - h5;
            c = h5 - h4;
        }
    }
    // Calculate height
    return (float)((a * x) + (b * y) + c)*_gridIntHeightMultiplier + _gridHeight;
}

float GridMap::getHeightFromUint16(float x, float y) const
{
    if (!m_uint16_V8 || !m_uint16_V9)
        return _gridHeight;

    x = MAP_RESOLUTION * (CENTER_GRID_ID - x/SIZE_OF_GRIDS);
    y = MAP_RESOLUTION * (CENTER_GRID_ID - y/SIZE_OF_GRIDS);

    int x_int = (int)x;
    int y_int = (int)y;
    x -= x_int;
    y -= y_int;
    x_int&=(MAP_RESOLUTION - 1);
    y_int&=(MAP_RESOLUTION - 1);

    if (isHole(x_int, y_int))
        return INVALID_HEIGHT;

    int32 a, b, c;
    uint16 *V9_h1_ptr = &m_uint16_V9[x_int*128 + x_int + y_int];
    if (x+y < 1)
    {
        if (x > y)
        {
            // 1 triangle (h1, h2, h5 points)
            int32 h1 = V9_h1_ptr[  0];
            int32 h2 = V9_h1_ptr[129];
            int32 h5 = 2 * m_uint16_V8[x_int*128 + y_int];
            a = h2-h1;
            b = h5-h1-h2;
            c = h1;
        }
        else
        {
            // 2 triangle (h1, h3, h5 points)
            int32 h1 = V9_h1_ptr[0];
            int32 h3 = V9_h1_ptr[1];
            int32 h5 = 2 * m_uint16_V8[x_int*128 + y_int];
            a = h5 - h1 - h3;
            b = h3 - h1;
            c = h1;
        }
    }
    else
    {
        if (x > y)
        {
            // 3 triangle (h2, h4, h5 points)
            int32 h2 = V9_h1_ptr[129];
            int32 h4 = V9_h1_ptr[130];
            int32 h5 = 2 * m_uint16_V8[x_int*128 + y_int];
            a = h2 + h4 - h5;
            b = h4 - h2;
            c = h5 - h4;
        }
        else
        {
            // 4 triangle (h3, h4, h5 points)
            int32 h3 = V9_h1_ptr[  1];
            int32 h4 = V9_h1_ptr[130];
            int32 h5 = 2 * m_uint16_V8[x_int*128 + y_int];
            a = h4 - h3;
            b = h3 + h4 - h5;
            c = h5 - h4;
        }
    }
    // Calculate height
    return (float)((a * x) + (b * y) + c)*_gridIntHeightMultiplier + _gridHeight;
}

float GridMap::getMinHeight(float x, float y) const
{
    if (!_minHeightPlanes)
        return -500.0f;

    GridCoord gridCoord = Trinity::ComputeGridCoordSimple(x, y);

    int32 doubleGridX = int32(std::floor(-(x - MAP_HALFSIZE) / CENTER_GRID_OFFSET));
    int32 doubleGridY = int32(std::floor(-(y - MAP_HALFSIZE) / CENTER_GRID_OFFSET));

    float gx = x - (int32(gridCoord.x_coord) - CENTER_GRID_ID + 1) * SIZE_OF_GRIDS;
    float gy = y - (int32(gridCoord.y_coord) - CENTER_GRID_ID + 1) * SIZE_OF_GRIDS;

    uint32 quarterIndex = 0;
    if (doubleGridY & 1)
    {
        if (doubleGridX & 1)
            quarterIndex = 4 + (gx <= gy);
        else
            quarterIndex = 2 + ((-SIZE_OF_GRIDS - gx) > gy);
    }
    else if (doubleGridX & 1)
        quarterIndex = 6 + ((-SIZE_OF_GRIDS - gx) <= gy);
    else
        quarterIndex = gx > gy;

    G3D::Ray ray = G3D::Ray::fromOriginAndDirection(G3D::Vector3(gx, gy, 0.0f), G3D::Vector3::unitZ());
    return ray.intersection(_minHeightPlanes[quarterIndex]).z;
}

bool GridMap::isHole(int row, int col) const
{
    if (!_holes)
        return false;

    int cellRow = row / 8;     // 8 squares per cell
    int cellCol = col / 8;
    int holeRow = row % 8 / 2;
    int holeCol = (col - (cellCol * 8)) / 2;

    uint16 hole = _holes[cellRow * 16 + cellCol];

    return (hole & holetab_h[holeCol] & holetab_v[holeRow]) != 0;
}

float GridMap::getLiquidLevel(float x, float y) const
{
    if (!_liquidMap)
        return _liquidLevel;

    x = MAP_RESOLUTION * (CENTER_GRID_ID - x/SIZE_OF_GRIDS);
    y = MAP_RESOLUTION * (CENTER_GRID_ID - y/SIZE_OF_GRIDS);

    int cx_int = ((int)x & (MAP_RESOLUTION-1)) - _liquidOffY;
    int cy_int = ((int)y & (MAP_RESOLUTION-1)) - _liquidOffX;

    if (cx_int < 0 || cx_int >=_liquidHeight)
        return INVALID_HEIGHT;
    if (cy_int < 0 || cy_int >=_liquidWidth)
        return INVALID_HEIGHT;

    return _liquidMap[cx_int*_liquidWidth + cy_int];
}

// Get water state on map
ZLiquidStatus GridMap::GetLiquidStatus(float x, float y, float z, Optional<map_liquidHeaderTypeFlags> ReqLiquidType, LiquidData* data, float collisionHeight) const
{
    // Check water type (if no water return)
    if (_liquidGlobalFlags == map_liquidHeaderTypeFlags::NoWater && !_liquidFlags)
        return LIQUID_MAP_NO_WATER;

    // Get cell
    float cx = MAP_RESOLUTION * (CENTER_GRID_ID - x/SIZE_OF_GRIDS);
    float cy = MAP_RESOLUTION * (CENTER_GRID_ID - y/SIZE_OF_GRIDS);

    int x_int = (int)cx & (MAP_RESOLUTION-1);
    int y_int = (int)cy & (MAP_RESOLUTION-1);

    // Check water type in cell
    int idx=(x_int>>3)*16 + (y_int>>3);
    map_liquidHeaderTypeFlags type = _liquidFlags ? _liquidFlags[idx] : _liquidGlobalFlags;
    uint32 entry = _liquidEntry ? _liquidEntry[idx] : _liquidGlobalEntry;
    if (LiquidTypeEntry const* liquidEntry = sLiquidTypeStore.LookupEntry(entry))
    {
        type &= map_liquidHeaderTypeFlags::DarkWater;
        uint32 liqTypeIdx = liquidEntry->SoundBank;
        if (entry < 21)
        {
            if (AreaTableEntry const* area = sAreaTableStore.LookupEntry(getArea(x, y)))
            {
                uint32 overrideLiquid = area->LiquidTypeID[liquidEntry->SoundBank];
                if (!overrideLiquid && area->ParentAreaID)
                {
                    area = sAreaTableStore.LookupEntry(area->ParentAreaID);
                    if (area)
                        overrideLiquid = area->LiquidTypeID[liquidEntry->SoundBank];
                }

                if (LiquidTypeEntry const* liq = sLiquidTypeStore.LookupEntry(overrideLiquid))
                {
                    entry = overrideLiquid;
                    liqTypeIdx = liq->SoundBank;
                }
            }
        }

        type |= map_liquidHeaderTypeFlags(1 << liqTypeIdx);
    }

    if (type == map_liquidHeaderTypeFlags::NoWater)
        return LIQUID_MAP_NO_WATER;

    // Check req liquid type mask
    if (ReqLiquidType && (*ReqLiquidType & type) == map_liquidHeaderTypeFlags::NoWater)
        return LIQUID_MAP_NO_WATER;

    // Check water level:
    // Check water height map
    int lx_int = x_int - _liquidOffY;
    int ly_int = y_int - _liquidOffX;
    if (lx_int < 0 || lx_int >=_liquidHeight)
        return LIQUID_MAP_NO_WATER;
    if (ly_int < 0 || ly_int >=_liquidWidth)
        return LIQUID_MAP_NO_WATER;

    // Get water level
    float liquid_level = _liquidMap ? _liquidMap[lx_int*_liquidWidth + ly_int] : _liquidLevel;
    // Get ground level (sub 0.2 for fix some errors)
    float ground_level = getHeight(x, y);

    // Check water level and ground level
    if (liquid_level < ground_level || z < ground_level)
        return LIQUID_MAP_NO_WATER;

    // All ok in water -> store data
    if (data)
    {
        data->entry = entry;
        data->type_flags = type;
        data->level = liquid_level;
        data->depth_level = ground_level;
    }

    // For speed check as int values
    float delta = liquid_level - z;

    if (delta > collisionHeight)        // Under water
        return LIQUID_MAP_UNDER_WATER;
    if (delta > 0.0f)                   // In water
        return LIQUID_MAP_IN_WATER;
    if (delta > -0.1f)                  // Walk on water
        return LIQUID_MAP_WATER_WALK;
                                        // Above water
    return LIQUID_MAP_ABOVE_WATER;
}
