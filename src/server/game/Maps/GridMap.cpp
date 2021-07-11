/*
 * This file is part of the TrinityCore Project. See AUTHORS file for Copyright information
 * This file is part of the CMaNGOS Project. See AUTHORS file for Copyright information
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; either version 2 of the License, or (at your
 * option) any later version.
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
 * more details.
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program. If not, see <http://www.gnu.org/licenses/>.
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

#include "MapManager.h"
#include "Log.h"
#include "GridStates.h"
#include "CellImpl.h"
#include "Map.h"
#include "DBCEnums.h"
#include "DBCStores.h"
#include "GridMap.h"
#include "DB2Stores.h"
#include "GridDefines.h"
#include "Log.h"
#include <G3D/Plane.h>
#include <G3D/Ray.h>
#include "VMapFactory.h"
#include "MoveMap.h"
#include "World.h"
#include "Policies/SingletonImp.h"
#include "Util.h"
#include "SQLStorages.h"

// *****************************
// Grid function
// *****************************
char const* MAP_MAGIC         = "MAPS";
char const* MAP_VERSION_MAGIC = "z1.5";
char const* MAP_AREA_MAGIC    = "AREA";
char const* MAP_HEIGHT_MAGIC  = "MHGT";
char const* MAP_LIQUID_MAGIC  = "MLIQ";

GridMap::GridMap()
{
    _flags = 0;
   // m_flags = 0;

    // Area data
    _gridArea = 0;
    _areaMap = nullptr;
    m_gridArea = 0;
    m_area_map = nullptr;

    // Height level data
    _gridHeight = INVALID_HEIGHT;
    _gridGetHeight = &GridMap::getHeightFromFlat;
    _gridIntHeightMultiplier = 0;
    m_gridHeight = INVALID_HEIGHT_VALUE;
    m_gridGetHeight = &GridMap::getHeightFromFlat;
    m_gridIntHeightMultiplier = 0;
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
    m_liquidGlobalEntry = 0;
    m_liquidGlobalFlags = 0;
    m_liquid_offX   = 0;
    m_liquid_offY   = 0;
    m_liquid_width  = 0;
    m_liquid_height = 0;
    m_liquidLevel = INVALID_HEIGHT_VALUE;
    m_liquidFlags = nullptr;
    m_liquidEntry = nullptr;
    m_liquid_map  = nullptr;
}

GridMap::~GridMap()
{
    unloadData();
}

GridMap::LoadResult GridMap::loadData(char const* filename)
bool GridMap::loadData(char const* filename)
{
    // Unload old data if exist
    unloadData();

    map_fileheader header;
    GridMapFileHeader header;
    // Not return error if file not found
    FILE* in = fopen(filename, "rb");
    if (!in)
        return LoadResult::FileDoesNotExist;
        return true;

    if (fread(&header, sizeof(header), 1, in) != 1)
    fread(&header, sizeof(header), 1, in);
    if (header.mapMagic     == *((uint32 const*)(MAP_MAGIC)) &&
            header.versionMagic == *((uint32 const*)(MAP_VERSION_MAGIC)))
    {
        fclose(in);
        return LoadResult::InvalidFile;
    }

    if (header.mapMagic == MapMagic && header.versionMagic == MapVersionMagic)
    {
        // load up area data
        // loadup area data
        if (header.areaMapOffset && !loadAreaData(in, header.areaMapOffset, header.areaMapSize))
        {
            TC_LOG_ERROR("maps", "Error loading map area data\n");
            sLog.outError("Error loading map area data\n");
            fclose(in);
            return LoadResult::InvalidFile;
            return false;
        }
        // load up height data

        // loadup height data
        if (header.heightMapOffset && !loadHeightData(in, header.heightMapOffset, header.heightMapSize))
        {
            TC_LOG_ERROR("maps", "Error loading map height data\n");
            sLog.outError("Error loading map height data\n");
            fclose(in);
            return LoadResult::InvalidFile;
            return false;
        }
        // load up liquid data
        if (header.liquidMapOffset && !loadLiquidData(in, header.liquidMapOffset, header.liquidMapSize))

        // loadup liquid data
        if (header.liquidMapOffset && !loadGridMapLiquidData(in, header.liquidMapOffset, header.liquidMapSize))
        {
            TC_LOG_ERROR("maps", "Error loading map liquids data\n");
            sLog.outError("Error loading map liquids data\n");
            fclose(in);
            return LoadResult::InvalidFile;
            return false;
        }
        // loadup holes data (if any. check header.holesOffset)
        if (header.holesSize && !loadHolesData(in, header.holesOffset, header.holesSize))
        {
            TC_LOG_ERROR("maps", "Error loading map holes data\n");

        fclose(in);
            return LoadResult::InvalidFile;
        return true;
    }
        fclose(in);
        return LoadResult::Ok;
    }

    TC_LOG_ERROR("maps", "Map file '{}' is from an incompatible map version (%.*s v{}), %.*s v{} is expected. Please pull your source, recompile tools and recreate maps using the updated mapextractor, then replace your old map files with new files. If you still have problems search on forum for error TCE00018.",
        filename, 4, header.mapMagic.data(), header.versionMagic, 4, MapMagic.data(), MapVersionMagic);
    sLog.outError("Map file '%s' is non-compatible version (outdated?). Please, create new using ad.exe program.", filename);
    fclose(in);
    return LoadResult::InvalidFile;
    return false;
}

void GridMap::unloadData()
{
    delete[] _areaMap;
    delete[] m_area_map;
    delete[] m_V9;
    delete[] m_V8;
    delete[] _minHeightPlanes;
    delete[] _liquidEntry;
    delete[] _liquidFlags;
    delete[] _liquidMap;
    delete[] _holes;
    _areaMap = nullptr;
    delete[] m_liquidEntry;
    delete[] m_liquidFlags;
    delete[] m_liquid_map;

    m_area_map = nullptr;
    m_V9 = nullptr;
    m_V8 = nullptr;
    _minHeightPlanes = nullptr;
    _liquidEntry = nullptr;
    _liquidFlags = nullptr;
    _liquidMap  = nullptr;
    _holes = nullptr;
    _gridGetHeight = &GridMap::getHeightFromFlat;
    m_liquidEntry = nullptr;
    m_liquidFlags = nullptr;
    m_liquid_map  = nullptr;
    m_gridGetHeight = &GridMap::getHeightFromFlat;
}

bool GridMap::loadAreaData(FILE* in, uint32 offset, uint32 /*size*/)
{
    map_areaHeader header;
    GridMapAreaHeader header;
    fseek(in, offset, SEEK_SET);

    if (fread(&header, sizeof(header), 1, in) != 1 || header.areaMagic != MapAreaMagic)
    fread(&header, sizeof(header), 1, in);
    if (header.fourcc != *((uint32 const*)(MAP_AREA_MAGIC)))
        return false;

    _gridArea = header.gridArea;
    if (!header.flags.HasFlag(map_areaHeaderFlags::NoArea))
    m_gridArea = header.gridArea;
    if (!(header.flags & MAP_AREA_NO_AREA))
    {
        _areaMap = new uint16[16 * 16];
        if (fread(_areaMap, sizeof(uint16), 16*16, in) != 16*16)
            return false;
        m_area_map = new uint16 [16 * 16];
        fread(m_area_map, sizeof(uint16), 16 * 16, in);
    }

    return true;
}

bool GridMap::loadHeightData(FILE* in, uint32 offset, uint32 /*size*/)
{
    map_heightHeader header;
    GridMapHeightHeader header;
    fseek(in, offset, SEEK_SET);

    if (fread(&header, sizeof(header), 1, in) != 1 || header.heightMagic != MapHeightMagic)
    fread(&header, sizeof(header), 1, in);
    if (header.fourcc != *((uint32 const*)(MAP_HEIGHT_MAGIC)))
        return false;

    _gridHeight = header.gridHeight;
    if (!header.flags.HasFlag(map_heightHeaderFlags::NoHeight))
    m_gridHeight = header.gridHeight;
    if (!(header.flags & MAP_HEIGHT_NO_HEIGHT))
    {
        if (header.flags.HasFlag(map_heightHeaderFlags::HeightAsInt16))
        if ((header.flags & MAP_HEIGHT_AS_INT16))
        {
            m_uint16_V9 = new uint16 [129*129];
            m_uint16_V8 = new uint16 [128*128];
            if (fread(m_uint16_V9, sizeof(uint16), 129*129, in) != 129*129 ||
                fread(m_uint16_V8, sizeof(uint16), 128*128, in) != 128*128)
                return false;
            _gridIntHeightMultiplier = (header.gridMaxHeight - header.gridHeight) / 65535;
            _gridGetHeight = &GridMap::getHeightFromUint16;
            m_uint16_V9 = new uint16 [129 * 129];
            m_uint16_V8 = new uint16 [128 * 128];
            fread(m_uint16_V9, sizeof(uint16), 129 * 129, in);
            fread(m_uint16_V8, sizeof(uint16), 128 * 128, in);
            m_gridIntHeightMultiplier = (header.gridMaxHeight - header.gridHeight) / 65535;
            m_gridGetHeight = &GridMap::getHeightFromUint16;
        }
        else if (header.flags.HasFlag(map_heightHeaderFlags::HeightAsInt8))
        else if ((header.flags & MAP_HEIGHT_AS_INT8))
        {
            m_uint8_V9 = new uint8 [129*129];
            m_uint8_V8 = new uint8 [128*128];
            if (fread(m_uint8_V9, sizeof(uint8), 129*129, in) != 129*129 ||
                fread(m_uint8_V8, sizeof(uint8), 128*128, in) != 128*128)
                return false;
            _gridIntHeightMultiplier = (header.gridMaxHeight - header.gridHeight) / 255;
            _gridGetHeight = &GridMap::getHeightFromUint8;
            m_uint8_V9 = new uint8 [129 * 129];
            m_uint8_V8 = new uint8 [128 * 128];
            fread(m_uint8_V9, sizeof(uint8), 129 * 129, in);
            fread(m_uint8_V8, sizeof(uint8), 128 * 128, in);
            m_gridIntHeightMultiplier = (header.gridMaxHeight - header.gridHeight) / 255;
            m_gridGetHeight = &GridMap::getHeightFromUint8;
        }
        else
        {
            m_V9 = new float [129*129];
            m_V8 = new float [128*128];
            if (fread(m_V9, sizeof(float), 129*129, in) != 129*129 ||
                fread(m_V8, sizeof(float), 128*128, in) != 128*128)
                return false;
            _gridGetHeight = &GridMap::getHeightFromFloat;
            m_V9 = new float [129 * 129];
            m_V8 = new float [128 * 128];
            fread(m_V9, sizeof(float), 129 * 129, in);
            fread(m_V8, sizeof(float), 128 * 128, in);
            m_gridGetHeight = &GridMap::getHeightFromFloat;
        }
    }
    else
        _gridGetHeight = &GridMap::getHeightFromFlat;
        m_gridGetHeight = &GridMap::getHeightFromFlat;

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
bool GridMap::loadGridMapLiquidData(FILE* in, uint32 offset, uint32 /*size*/)
{
    map_liquidHeader header;
    GridMapLiquidHeader header;
    fseek(in, offset, SEEK_SET);

    if (fread(&header, sizeof(header), 1, in) != 1 || header.liquidMagic != MapLiquidMagic)
    fread(&header, sizeof(header), 1, in);
    if (header.fourcc != *((uint32 const*)(MAP_LIQUID_MAGIC)))
        return false;

    _liquidGlobalEntry = header.liquidType;
    _liquidGlobalFlags = header.liquidFlags;
    _liquidOffX  = header.offsetX;
    _liquidOffY  = header.offsetY;
    _liquidWidth = header.width;
    _liquidHeight = header.height;
    _liquidLevel  = header.liquidLevel;
    m_liquidGlobalEntry = header.liquidType;
    m_liquidGlobalFlags = header.liquidFlags;
    m_liquid_offX   = header.offsetX;
    m_liquid_offY   = header.offsetY;
    m_liquid_width  = header.width;
    m_liquid_height = header.height;
    m_liquidLevel   = header.liquidLevel;

    if (!header.flags.HasFlag(map_liquidHeaderFlags::NoType))
    if (!(header.flags & MAP_LIQUID_NO_TYPE))
    {
        _liquidEntry = new uint16[16*16];
        if (fread(_liquidEntry, sizeof(uint16), 16*16, in) != 16*16)
            return false;
        m_liquidEntry = new uint16[16 * 16];
        fread(m_liquidEntry, sizeof(uint16), 16 * 16, in);

        _liquidFlags = new map_liquidHeaderTypeFlags[16*16];
        if (fread(_liquidFlags, sizeof(map_liquidHeaderTypeFlags), 16*16, in) != 16*16)
            return false;
        m_liquidFlags = new uint8[16 * 16];
        fread(m_liquidFlags, sizeof(uint8), 16 * 16, in);
    }
    if (!header.flags.HasFlag(map_liquidHeaderFlags::NoHeight))

    if (!(header.flags & MAP_LIQUID_NO_HEIGHT))
    {
        _liquidMap = new float[uint32(_liquidWidth) * uint32(_liquidHeight)];
        if (fread(_liquidMap, sizeof(float), _liquidWidth*_liquidHeight, in) != (uint32(_liquidWidth) * uint32(_liquidHeight)))
            return false;
        m_liquid_map = new float [m_liquid_width * m_liquid_height];
        fread(m_liquid_map, sizeof(float), m_liquid_width * m_liquid_height, in);
    }
    return true;
}

bool GridMap::loadHolesData(FILE* in, uint32 offset, uint32 /*size*/)
{
    if (fseek(in, offset, SEEK_SET) != 0)
        return false;

    _holes = new uint8[16 * 16 * 8];
    if (fread(_holes, sizeof(uint8), 16 * 16 * 8, in) != 16 * 16 * 8)
        return false;

    return true;
}

uint16 GridMap::getArea(float x, float y) const
{
    if (!_areaMap)
        return _gridArea;
    if (!m_area_map)
        return m_gridArea;

    x = 16 * (CENTER_GRID_ID - x/SIZE_OF_GRIDS);
    y = 16 * (CENTER_GRID_ID - y/SIZE_OF_GRIDS);
    x = 16 * (32 - x / SIZE_OF_GRIDS);
    y = 16 * (32 - y / SIZE_OF_GRIDS);
    int lx = (int)x & 15;
    int ly = (int)y & 15;
    return _areaMap[lx*16 + ly];
    return m_area_map[lx * 16 + ly];
}

float GridMap::getHeightFromFlat(float /*x*/, float /*y*/) const
{
    return _gridHeight;
    return m_gridHeight;
}

float GridMap::getHeightFromFloat(float x, float y) const
{
    if (!m_V8 || !m_V9)
        return _gridHeight;
        return m_gridHeight;

    x = MAP_RESOLUTION * (CENTER_GRID_ID - x/SIZE_OF_GRIDS);
    y = MAP_RESOLUTION * (CENTER_GRID_ID - y/SIZE_OF_GRIDS);
    x = MAP_RESOLUTION * (32 - x / SIZE_OF_GRIDS);
    y = MAP_RESOLUTION * (32 - y / SIZE_OF_GRIDS);

    int x_int = (int)x;
    int y_int = (int)y;
    x -= x_int;
    y -= y_int;
    x_int&=(MAP_RESOLUTION - 1);
    y_int&=(MAP_RESOLUTION - 1);
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
    // | | \  1  / |     h1 0,0
    // | |  \   /  |     h2 0,1
    // | | 2  h5 3 |     h3 1,0
    // | |  /   \  |     h4 1,1
    // | | /  4  \ |     h5 1/2,1/2
    // | h3-------h4
    // V Y
    // For find height need
    // 1 - detect triangle
    // 2 - solve linear equation from triangle points
    // Calculate coefficients for solve h = a*x + b*y + c

    float a, b, c;
    // Select triangle:
    if (x+y < 1)
    if (x + y < 1)
    {
        if (x > y)
        {
            // 1 triangle (h1, h2, h5 points)
            float h1 = m_V9[(x_int)*129 + y_int];
            float h2 = m_V9[(x_int+1)*129 + y_int];
            float h5 = 2 * m_V8[x_int*128 + y_int];
            a = h2-h1;
            b = h5-h1-h2;
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
            float h1 = m_V9[x_int*129 + y_int  ];
            float h3 = m_V9[x_int*129 + y_int+1];
            float h5 = 2 * m_V8[x_int*128 + y_int];
            float h1 = m_V9[x_int * 129 + y_int  ];
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
            float h2 = m_V9[(x_int+1)*129 + y_int  ];
            float h4 = m_V9[(x_int+1)*129 + y_int+1];
            float h5 = 2 * m_V8[x_int*128 + y_int];
            float h2 = m_V9[(x_int + 1) * 129 + y_int  ];
            float h4 = m_V9[(x_int + 1) * 129 + y_int + 1];
            float h5 = 2 * m_V8[x_int * 128 + y_int];
            a = h2 + h4 - h5;
            b = h4 - h2;
            c = h5 - h4;
        }
        else
        {
            // 4 triangle (h3, h4, h5 points)
            float h3 = m_V9[(x_int)*129 + y_int+1];
            float h4 = m_V9[(x_int+1)*129 + y_int+1];
            float h5 = 2 * m_V8[x_int*128 + y_int];
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
        return m_gridHeight;

    x = MAP_RESOLUTION * (CENTER_GRID_ID - x/SIZE_OF_GRIDS);
    y = MAP_RESOLUTION * (CENTER_GRID_ID - y/SIZE_OF_GRIDS);
    x = MAP_RESOLUTION * (32 - x / SIZE_OF_GRIDS);
    y = MAP_RESOLUTION * (32 - y / SIZE_OF_GRIDS);

    int x_int = (int)x;
    int y_int = (int)y;
    x -= x_int;
    y -= y_int;
    x_int&=(MAP_RESOLUTION - 1);
    y_int&=(MAP_RESOLUTION - 1);
    x_int &= (MAP_RESOLUTION - 1);
    y_int &= (MAP_RESOLUTION - 1);

    if (isHole(x_int, y_int))
        return INVALID_HEIGHT;

    int32 a, b, c;
    uint8 *V9_h1_ptr = &m_uint8_V9[x_int*128 + x_int + y_int];
    if (x+y < 1)
    uint8* V9_h1_ptr = &m_uint8_V9[x_int * 128 + x_int + y_int];
    if (x + y < 1)
    {
        if (x > y)
        {
            // 1 triangle (h1, h2, h5 points)
            int32 h1 = V9_h1_ptr[  0];
            int32 h2 = V9_h1_ptr[129];
            int32 h5 = 2 * m_uint8_V8[x_int*128 + y_int];
            a = h2-h1;
            b = h5-h1-h2;
            int32 h5 = 2 * m_uint8_V8[x_int * 128 + y_int];
            a = h2 - h1;
            b = h5 - h1 - h2;
            c = h1;
        }
        else
        {
            // 2 triangle (h1, h3, h5 points)
            int32 h1 = V9_h1_ptr[0];
            int32 h3 = V9_h1_ptr[1];
            int32 h5 = 2 * m_uint8_V8[x_int*128 + y_int];
            int32 h5 = 2 * m_uint8_V8[x_int * 128 + y_int];
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
            int32 h5 = 2 * m_uint8_V8[x_int * 128 + y_int];
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
            int32 h5 = 2 * m_uint8_V8[x_int * 128 + y_int];
            a = h4 - h3;
            b = h3 + h4 - h5;
            c = h5 - h4;
        }
    }

    // Calculate height
    return (float)((a * x) + (b * y) + c)*_gridIntHeightMultiplier + _gridHeight;
    return (float)((a * x) + (b * y) + c) * m_gridIntHeightMultiplier + m_gridHeight;
}

float GridMap::getHeightFromUint16(float x, float y) const
{
    if (!m_uint16_V8 || !m_uint16_V9)
        return _gridHeight;
        return m_gridHeight;

    x = MAP_RESOLUTION * (CENTER_GRID_ID - x/SIZE_OF_GRIDS);
    y = MAP_RESOLUTION * (CENTER_GRID_ID - y/SIZE_OF_GRIDS);
    x = MAP_RESOLUTION * (32 - x / SIZE_OF_GRIDS);
    y = MAP_RESOLUTION * (32 - y / SIZE_OF_GRIDS);

    int x_int = (int)x;
    int y_int = (int)y;
    x -= x_int;
    y -= y_int;
    x_int&=(MAP_RESOLUTION - 1);
    y_int&=(MAP_RESOLUTION - 1);
    x_int &= (MAP_RESOLUTION - 1);
    y_int &= (MAP_RESOLUTION - 1);

    if (isHole(x_int, y_int))
        return INVALID_HEIGHT;

    int32 a, b, c;
    uint16 *V9_h1_ptr = &m_uint16_V9[x_int*128 + x_int + y_int];
    if (x+y < 1)
    uint16* V9_h1_ptr = &m_uint16_V9[x_int * 128 + x_int + y_int];
    if (x + y < 1)
    {
        if (x > y)
        {
            // 1 triangle (h1, h2, h5 points)
            int32 h1 = V9_h1_ptr[  0];
            int32 h2 = V9_h1_ptr[129];
            int32 h5 = 2 * m_uint16_V8[x_int*128 + y_int];
            a = h2-h1;
            b = h5-h1-h2;
            int32 h5 = 2 * m_uint16_V8[x_int * 128 + y_int];
            a = h2 - h1;
            b = h5 - h1 - h2;
            c = h1;
        }
        else
        {
            // 2 triangle (h1, h3, h5 points)
            int32 h1 = V9_h1_ptr[0];
            int32 h3 = V9_h1_ptr[1];
            int32 h5 = 2 * m_uint16_V8[x_int*128 + y_int];
            int32 h5 = 2 * m_uint16_V8[x_int * 128 + y_int];
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
            int32 h5 = 2 * m_uint16_V8[x_int * 128 + y_int];
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
            int32 h5 = 2 * m_uint16_V8[x_int * 128 + y_int];
            a = h4 - h3;
            b = h3 + h4 - h5;
            c = h5 - h4;
        }
    }

    // Calculate height
    return (float)((a * x) + (b * y) + c)*_gridIntHeightMultiplier + _gridHeight;
    return (float)((a * x) + (b * y) + c) * m_gridIntHeightMultiplier + m_gridHeight;
}

bool GridMap::isHole(int row, int col) const
float GridMap::getLiquidLevel(float x, float y) const
{
    if (!_holes)
        return false;
    if (!m_liquid_map)
        return m_liquidLevel;

    int cellRow = row / 8;     // 8 squares per cell
    int cellCol = col / 8;
    int holeRow = row % 8;
    int holeCol = col % 8;
    x = MAP_RESOLUTION * (32 - x / SIZE_OF_GRIDS);
    y = MAP_RESOLUTION * (32 - y / SIZE_OF_GRIDS);

    return (_holes[cellRow * 16 * 8 + cellCol * 8 + holeRow] & (1 << holeCol)) != 0;
}
    int cx_int = ((int)x & (MAP_RESOLUTION - 1)) - m_liquid_offY;
    int cy_int = ((int)y & (MAP_RESOLUTION - 1)) - m_liquid_offX;

float GridMap::getMinHeight(float x, float y) const
{
    if (!_minHeightPlanes)
        return -500.0f;
    if (cx_int < 0 || cx_int >= m_liquid_height)
        return INVALID_HEIGHT_VALUE;

    GridCoord gridCoord = Trinity::ComputeGridCoordSimple(x, y);
    if (cy_int < 0 || cy_int >= m_liquid_width)
        return INVALID_HEIGHT_VALUE;

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
    return m_liquid_map[cx_int * m_liquid_width + cy_int];
}
    else if (doubleGridX & 1)
        quarterIndex = 6 + ((-SIZE_OF_GRIDS - gx) <= gy);
    else
        quarterIndex = gx > gy;

    G3D::Ray ray = G3D::Ray::fromOriginAndDirection(G3D::Vector3(gx, gy, 0.0f), G3D::Vector3::unitZ());
    return ray.intersection(_minHeightPlanes[quarterIndex]).z;
}

float GridMap::getLiquidLevel(float x, float y) const
uint8 GridMap::getTerrainType(float x, float y) const
{
    if (!_liquidMap)
        return _liquidLevel;
    if (!m_liquidFlags)
        return (uint8)m_liquidGlobalFlags;

    x = MAP_RESOLUTION * (CENTER_GRID_ID - x/SIZE_OF_GRIDS);
    y = MAP_RESOLUTION * (CENTER_GRID_ID - y/SIZE_OF_GRIDS);

    int cx_int = ((int)x & (MAP_RESOLUTION-1)) - _liquidOffY;
    int cy_int = ((int)y & (MAP_RESOLUTION-1)) - _liquidOffX;

    if (cx_int < 0 || cx_int >=_liquidHeight)
        return INVALID_HEIGHT;
    if (cy_int < 0 || cy_int >=_liquidWidth)
        return INVALID_HEIGHT;

    return _liquidMap[cx_int*_liquidWidth + cy_int];
    x = 16 * (32 - x / SIZE_OF_GRIDS);
    y = 16 * (32 - y / SIZE_OF_GRIDS);
    int lx = (int)x & 15;
    int ly = (int)y & 15;
    return m_liquidFlags[lx * 16 + ly];
}

// Get water state on map
ZLiquidStatus GridMap::GetLiquidStatus(float x, float y, float z, Optional<map_liquidHeaderTypeFlags> ReqLiquidType, LiquidData* data, float collisionHeight) const
GridMapLiquidStatus GridMap::getLiquidStatus(float x, float y, float z, uint8 ReqLiquidType, GridMapLiquidData* data)
{
    // Check water type (if no water return)
    if (_liquidGlobalFlags == map_liquidHeaderTypeFlags::NoWater && !_liquidFlags)
    if (!m_liquidFlags && !m_liquidGlobalFlags)
        return LIQUID_MAP_NO_WATER;

    // Get cell
    float cx = MAP_RESOLUTION * (CENTER_GRID_ID - x/SIZE_OF_GRIDS);
    float cy = MAP_RESOLUTION * (CENTER_GRID_ID - y/SIZE_OF_GRIDS);
    float cx = MAP_RESOLUTION * (32 - x / SIZE_OF_GRIDS);
    float cy = MAP_RESOLUTION * (32 - y / SIZE_OF_GRIDS);

    int x_int = (int)cx & (MAP_RESOLUTION-1);
    int y_int = (int)cy & (MAP_RESOLUTION-1);
    int x_int = (int)cx & (MAP_RESOLUTION - 1);
    int y_int = (int)cy & (MAP_RESOLUTION - 1);

    // Check water type in cell
    int idx=(x_int>>3)*16 + (y_int>>3);
    map_liquidHeaderTypeFlags type = _liquidFlags ? _liquidFlags[idx] : _liquidGlobalFlags;
    uint32 entry = _liquidEntry ? _liquidEntry[idx] : _liquidGlobalEntry;
    if (LiquidTypeEntry const* liquidEntry = sLiquidTypeStore.LookupEntry(entry))
    int idx = (x_int >> 3) * 16 + (y_int >> 3);
    uint8 type = m_liquidFlags ? m_liquidFlags[idx] : m_liquidGlobalFlags;
    uint32 entry = m_liquidEntry ? m_liquidEntry[idx] : m_liquidGlobalEntry;
    if (LiquidTypeEntry const* liquidEntry = sTerrainMgr.GetLiquidType(entry))
    {
        type &= map_liquidHeaderTypeFlags::DarkWater;
        uint32 liqTypeIdx = liquidEntry->SoundBank;
        entry = liquidEntry->Id;
        type &= MAP_LIQUID_TYPE_DEEP_WATER;
        uint32 liqTypeIdx = liquidEntry->Type;
        if (entry < 21)
        {
            if (AreaTableEntry const* area = sAreaTableStore.LookupEntry(getArea(x, y)))
            if (const auto *areaEntry = AreaEntry::GetById(getArea(x, y)))
            {
                uint32 overrideLiquid = area->LiquidTypeID[liquidEntry->SoundBank];
                if (!overrideLiquid && area->ParentAreaID)
                uint32 overrideLiquid = areaEntry->LiquidTypeId;
                if (!overrideLiquid && !areaEntry->IsZone())
                {
                    area = sAreaTableStore.LookupEntry(area->ParentAreaID);
                    if (area)
                        overrideLiquid = area->LiquidTypeID[liquidEntry->SoundBank];
                    areaEntry = AreaEntry::GetById(areaEntry->ZoneId);
                    if (areaEntry)
                        overrideLiquid = areaEntry->LiquidTypeId;
                }

                if (LiquidTypeEntry const* liq = sLiquidTypeStore.LookupEntry(overrideLiquid))
                if (LiquidTypeEntry const* liq = sTerrainMgr.GetLiquidType(overrideLiquid))
                {
                    entry = overrideLiquid;
                    liqTypeIdx = liq->SoundBank;
                    liqTypeIdx = liq->Type;
                }
            }
        }

        type |= map_liquidHeaderTypeFlags(1 << liqTypeIdx);
        type |= (1 << liqTypeIdx) | (type & MAP_LIQUID_TYPE_DEEP_WATER);
    }

    if (type == map_liquidHeaderTypeFlags::NoWater)
    if (type == 0)
        return LIQUID_MAP_NO_WATER;

    // Check req liquid type mask
    if (ReqLiquidType && (*ReqLiquidType & type) == map_liquidHeaderTypeFlags::NoWater)
    if (ReqLiquidType && !(ReqLiquidType & type))
        return LIQUID_MAP_NO_WATER;

    // Check water level:
    // Check water height map
    int lx_int = x_int - _liquidOffY;
    int ly_int = y_int - _liquidOffX;
    if (lx_int < 0 || lx_int >=_liquidHeight)
    int lx_int = x_int - m_liquid_offY;
    if (lx_int < 0 || lx_int >= m_liquid_height)
        return LIQUID_MAP_NO_WATER;
    if (ly_int < 0 || ly_int >=_liquidWidth)

    int ly_int = y_int - m_liquid_offX;
    if (ly_int < 0 || ly_int >= m_liquid_width)
        return LIQUID_MAP_NO_WATER;

    // Get water level
    float liquid_level = _liquidMap ? _liquidMap[lx_int*_liquidWidth + ly_int] : _liquidLevel;
    float liquid_level = m_liquid_map ? m_liquid_map[lx_int * m_liquid_width + ly_int] : m_liquidLevel;

    // Get ground level (sub 0.2 for fix some errors)
    float ground_level = getHeight(x, y);

    // Check water level and ground level
    if (liquid_level < ground_level || z < ground_level)
    if (liquid_level < ground_level || z < ground_level - 2)
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
    int delta = int((liquid_level - z) * 10);

    if (delta > collisionHeight)                   // Under water
    // Get position delta
    if (delta > 20)                                         // Under water
        return LIQUID_MAP_UNDER_WATER;
    if (delta > 0.0f)                   // In water

    if (delta > 0)                                          // In water
        return LIQUID_MAP_IN_WATER;
    if (delta > -0.1f)                   // Walk on water

    if (delta > -1)                                         // Walk on water
        return LIQUID_MAP_WATER_WALK;
    // Above water
    return LIQUID_MAP_ABOVE_WATER;
}

bool GridMap::ExistMap(uint32 mapid, int gx, int gy)
{
    int len = sWorld.GetDataPath().length() + strlen("maps/%03u%02u%02u.map") + 1;
    char* tmp = new char[len];
    snprintf(tmp, len, (char*)(sWorld.GetDataPath() + "maps/%03u%02u%02u.map").c_str(), mapid, gy, gx);

    FILE* pf = fopen(tmp, "rb");

    if (!pf)
    {
        sLog.outError("Check existing of map file '%s': not exist!", tmp);
        delete[] tmp;
        return false;
    }

    GridMapFileHeader header;
    fread(&header, sizeof(header), 1, pf);
    if (header.mapMagic     != *((uint32 const*)(MAP_MAGIC)) ||
            header.versionMagic != *((uint32 const*)(MAP_VERSION_MAGIC)))
    {
        sLog.outError("Map file '%s' is non-compatible version (outdated?). Please, create new using ad.exe program.", tmp);
        delete[] tmp;
        fclose(pf);                                         // close file before return
        return false;
    }

    delete[] tmp;
    fclose(pf);
    return true;
}

bool GridMap::ExistVMap(uint32 mapid, int gx, int gy)
{
    if (VMAP::IVMapManager* vmgr = VMAP::VMapFactory::createOrGetVMapManager())
    {
        if (vmgr->isMapLoadingEnabled())
        {
            // x and y are swapped !! => fixed now
            bool exists = vmgr->existsMap((sWorld.GetDataPath() + "vmaps").c_str(),  mapid, gx, gy);
            if (!exists)
            {
                std::string name = vmgr->getDirFileName(mapid, gx, gy);
                sLog.outError("VMap file '%s' is missing or point to wrong version vmap file, redo vmaps with latest vmap_assembler.exe program", (sWorld.GetDataPath() + "vmaps/" + name).c_str());
                return false;
            }
        }
    }

    return true;
}

//////////////////////////////////////////////////////////////////////////
TerrainInfo::TerrainInfo(uint32 mapid) : m_mapId(mapid)
{
    for (int k = 0; k < MAX_NUMBER_OF_GRIDS; ++k)
    {
        for (int i = 0; i < MAX_NUMBER_OF_GRIDS; ++i)
        {
            m_GridMaps[i][k] = nullptr;
            m_GridRef[i][k] = 0;
        }
    }

    // clean up GridMap objects every minute
    uint32 const iCleanUpInterval = 60;
    // schedule start randlomly
    uint32 const iRandomStart = urand(20, 40);

    i_timer.SetInterval(iCleanUpInterval * 1000);
    i_timer.SetCurrent(iRandomStart * 1000);
}

void TerrainInfo::LoadAll()
{
    for (int k = 0; k < MAX_NUMBER_OF_GRIDS; ++k)
        for (int i = 0; i < MAX_NUMBER_OF_GRIDS; ++i)
            Load(i, k);
}

TerrainInfo::~TerrainInfo()
{
    for (int k = 0; k < MAX_NUMBER_OF_GRIDS; ++k)
        for (const auto& itr : m_GridMaps)
            delete itr[k];

    VMAP::VMapFactory::createOrGetVMapManager()->unloadMap(m_mapId);
    MMAP::MMapFactory::createOrGetMMapManager()->unloadMap(m_mapId);
}

GridMap* TerrainInfo::Load(uint32 const x, uint32 const y)
{
    MANGOS_ASSERT(x < MAX_NUMBER_OF_GRIDS);
    MANGOS_ASSERT(y < MAX_NUMBER_OF_GRIDS);

    // reference grid as a first step
    RefGrid(x, y);

    // quick check if GridMap already loaded
    GridMap* pMap = m_GridMaps[x][y];
    if (!pMap)
        pMap = LoadMapAndVMap(x, y);

    return pMap;
}

// schedule lazy GridMap object cleanup
void TerrainInfo::Unload(uint32 const x, uint32 const y)
{
    MANGOS_ASSERT(x < MAX_NUMBER_OF_GRIDS);
    MANGOS_ASSERT(y < MAX_NUMBER_OF_GRIDS);

    if (m_GridMaps[x][y])
    {
        // decrease grid reference count...
        if (UnrefGrid(x, y) == 0)
        {
            // TODO: add your additional logic here
        }
    }
}

// call this method only
void TerrainInfo::CleanUpGrids(uint32 const diff)
{
    i_timer.Update(diff);
    if (!i_timer.Passed())
        return;

    for (int y = 0; y < MAX_NUMBER_OF_GRIDS; ++y)
    {
        for (int x = 0; x < MAX_NUMBER_OF_GRIDS; ++x)
        {
            int16 const& iRef = m_GridRef[x][y];
            GridMap* pMap = m_GridMaps[x][y];

            // delete those GridMap objects which have refcount = 0
            if (pMap && iRef == 0)
            {
                m_GridMaps[x][y] = nullptr;
                // delete grid data if reference count == 0
                pMap->unloadData();
                delete pMap;

                // unload VMAPS...
                VMAP::VMapFactory::createOrGetVMapManager()->unloadMap(m_mapId, x, y);

                // unload mmap...
                MMAP::MMapFactory::createOrGetMMapManager()->unloadMap(m_mapId, x, y);
            }
        }
    }

    i_timer.Reset();
}

int TerrainInfo::RefGrid(uint32 const& x, uint32 const& y)
{
    MANGOS_ASSERT(x < MAX_NUMBER_OF_GRIDS);
    MANGOS_ASSERT(y < MAX_NUMBER_OF_GRIDS);

    LOCK_GUARD _lock(m_refMutex);
    return (m_GridRef[x][y] += 1);
}

int TerrainInfo::UnrefGrid(uint32 const& x, uint32 const& y)
{
    MANGOS_ASSERT(x < MAX_NUMBER_OF_GRIDS);
    MANGOS_ASSERT(y < MAX_NUMBER_OF_GRIDS);

    int16& iRef = m_GridRef[x][y];

    LOCK_GUARD _lock(m_refMutex);
    if (iRef > 0)
        return (iRef -= 1);

    return 0;
}

float TerrainInfo::GetHeightStatic(float x, float y, float z, bool useVmaps/*=true*/, float maxSearchDist/*=DEFAULT_HEIGHT_SEARCH*/) const
{
    float mapHeight = VMAP_INVALID_HEIGHT_VALUE;            // Store Height obtained by maps
    float vmapHeight = VMAP_INVALID_HEIGHT_VALUE;           // Store Height obtained by vmaps (in "corridor" of z (or slightly above z)

    float z2 = z + 2.f;

    // find raw .map surface under Z coordinates (or well-defined above)
    if (GridMap* gmap = const_cast<TerrainInfo*>(this)->GetGrid(x, y))
        mapHeight = gmap->getHeight(x, y);

    if (useVmaps)
    {
        VMAP::IVMapManager* vmgr = VMAP::VMapFactory::createOrGetVMapManager();
        if (vmgr->isHeightCalcEnabled())
        {
            // if mapHeight has been found search vmap height at least until mapHeight point
            // this prevent case when original Z "too high above ground and vmap height search fail"
            // this will not affect most normal cases (no map in instance, or stay at ground at continent)
            if (mapHeight > INVALID_HEIGHT && z2 - mapHeight > maxSearchDist)
                maxSearchDist = z2 - mapHeight + 1.0f;      // 1.0 make sure that we not fail for case when map height near but above for vamp height

            // look from a bit higher pos to find the floor
            vmapHeight = vmgr->getHeight(GetMapId(), x, y, z2, maxSearchDist);

            // if not found in expected range, look for infinity range (case of far above floor, but below terrain-height)
            if (vmapHeight <= INVALID_HEIGHT)
                vmapHeight = vmgr->getHeight(GetMapId(), x, y, z2, 10000.0f);

            // look upwards
            if (vmapHeight <= INVALID_HEIGHT && mapHeight > z2 && std::abs(z2 - mapHeight) > 30.f)
                vmapHeight = vmgr->getHeight(GetMapId(), x, y, z2, -maxSearchDist);

            // still not found, look near terrain height
            if (vmapHeight <= INVALID_HEIGHT && mapHeight > INVALID_HEIGHT && z2 < mapHeight)
                vmapHeight = vmgr->getHeight(GetMapId(), x, y, mapHeight + 2.0f, DEFAULT_HEIGHT_SEARCH);
        }
    }

    // mapHeight set for any above raw ground Z or <= INVALID_HEIGHT
    // vmapheight set for any under Z value or <= INVALID_HEIGHT
    if (vmapHeight > INVALID_HEIGHT)
    {
        if (mapHeight > INVALID_HEIGHT)
        {
            // we have mapheight and vmapheight and must select more appropriate

            // we are already under the surface or vmap height above map heigt
            if (z < mapHeight || vmapHeight > mapHeight)
                return vmapHeight;
            return mapHeight;                               // better use .map surface height
        }
        else
            return vmapHeight;                              // we have only vmapHeight (if have)
    }

    return mapHeight;
}


inline bool IsOutdoorWMO(uint32 mogpFlags)
{
    return (mogpFlags & 0x8000) != 0;
}

bool TerrainInfo::IsOutdoors(float x, float y, float z) const
{
    uint32 mogpFlags;
    int32 adtId, rootId, groupId;

    // no wmo found? -> outside by default
    if (!GetAreaInfo(x, y, z, mogpFlags, adtId, rootId, groupId))
        return true;

    return IsOutdoorWMO(mogpFlags);
}

bool TerrainInfo::GetAreaInfo(float x, float y, float z, uint32& flags, int32& adtId, int32& rootId, int32& groupId) const
{
    // We build a ray decreasing z and finding the first floor.
    // We need to increase z a bit, if we are slightly undermap
    z += 1.0f;
    float vmap_z = z;
    VMAP::IVMapManager* vmgr = VMAP::VMapFactory::createOrGetVMapManager();
    if (vmgr->getAreaInfo(GetMapId(), x, y, vmap_z, flags, adtId, rootId, groupId))
    {
        // check if there's terrain between player height and object height
        if (GridMap* gmap = const_cast<TerrainInfo*>(this)->GetGrid(x, y))
        {
            float _mapheight = gmap->getHeight(x, y);
            // z + 2.0f condition taken from GetHeightStatic(), not sure if it's such a great choice...
            if (z + 2.0f > _mapheight &&  _mapheight > vmap_z)
                return false;
        }
        return true;
    }
    return false;
}

uint16 TerrainInfo::GetAreaFlag(float x, float y, float z, bool* isOutdoors) const
{
    uint32 mogpFlags;
    int32 adtId, rootId, groupId;
    WMOAreaTableEntry const* wmoEntry = nullptr;
    AreaEntry const* atEntry = nullptr;
    bool haveAreaInfo = false;

    if (GetAreaInfo(x, y, z, mogpFlags, adtId, rootId, groupId))
    {
        haveAreaInfo = true;
        wmoEntry = GetWMOAreaTableEntryByTripple(rootId, adtId, groupId);
        if (wmoEntry)
            atEntry = AreaEntry::GetById(wmoEntry->areaId);
    }

    uint16 areaflag;
    if (atEntry)
        areaflag = atEntry->ExploreFlag;
    else
    {
        if (GridMap* gmap = const_cast<TerrainInfo*>(this)->GetGrid(x, y))
            areaflag = gmap->getArea(x, y);
        // this used while not all *.map files generated (instances)
        else
            areaflag = AreaEntry::GetFlagByMapId(GetMapId());
    }

    if (isOutdoors)
    {
        if (haveAreaInfo)
            *isOutdoors = IsOutdoorWMO(mogpFlags);
        else
            *isOutdoors = true;
    }
    return areaflag;
}

uint8 TerrainInfo::GetTerrainType(float x, float y) const
{
    if (GridMap* gmap = const_cast<TerrainInfo*>(this)->GetGrid(x, y))
        return gmap->getTerrainType(x, y);
    return 0;
}

uint32 TerrainInfo::GetAreaId(float x, float y, float z) const
{
    return TerrainManager::GetAreaIdByAreaFlag(GetAreaFlag(x, y, z), m_mapId);
}

uint32 TerrainInfo::GetZoneId(float x, float y, float z) const
{
    return TerrainManager::GetZoneIdByAreaFlag(GetAreaFlag(x, y, z), m_mapId);
}

void TerrainInfo::GetZoneAndAreaId(uint32& zoneid, uint32& areaid, float x, float y, float z) const
{
    TerrainManager::GetZoneAndAreaIdByAreaFlag(zoneid, areaid, GetAreaFlag(x, y, z), m_mapId);
}

GridMapLiquidStatus TerrainInfo::getLiquidStatus(float x, float y, float z, uint8 ReqLiquidType, GridMapLiquidData* data) const
{
    GridMapLiquidStatus result = LIQUID_MAP_NO_WATER;
    VMAP::IVMapManager* vmgr = VMAP::VMapFactory::createOrGetVMapManager();
    uint32 liquid_type = 0;
    float liquid_level = INVALID_HEIGHT_VALUE;
    float ground_level = GetHeightStatic(x, y, z, true, DEFAULT_WATER_SEARCH);

    if (vmgr->GetLiquidLevel(GetMapId(), x, y, z, ReqLiquidType, liquid_level, ground_level, liquid_type))
    {
        //DEBUG_LOG("getLiquidStatus(): vmap liquid level: %f ground: %f type: %u", liquid_level, ground_level, liquid_type);
        // Check water level and ground level
        if (liquid_level > ground_level && z > ground_level - 2)
        {
            // All ok in water -> store data
            if (data)
            {
                uint32 liquidFlagType = 0;
                if (LiquidTypeEntry const* liq = sTerrainMgr.GetLiquidType(liquid_type))
                {
                    liquidFlagType = 1 << liq->Type;
                }

                data->level = liquid_level;
                data->depth_level = ground_level;

                data->entry = liquid_type;
                data->type_flags = liquidFlagType;
            }

            // For speed check as int values
            int delta = int((liquid_level - z) * 10);

            // Get position delta
            if (delta > 20)                   // Under water
                return LIQUID_MAP_UNDER_WATER;
            if (delta > 0)                    // In water
                return LIQUID_MAP_IN_WATER;
            if (delta > -1)                   // Walk on water
                return LIQUID_MAP_WATER_WALK;
            result = LIQUID_MAP_ABOVE_WATER;
        }
    }
    else if (GridMap* gmap = const_cast<TerrainInfo*>(this)->GetGrid(x, y))
    {
        GridMapLiquidData map_data{};
        GridMapLiquidStatus map_result = gmap->getLiquidStatus(x, y, z, ReqLiquidType, &map_data);
        // Not override LIQUID_MAP_ABOVE_WATER with LIQUID_MAP_NO_WATER:
        if (map_result != LIQUID_MAP_NO_WATER && (map_data.level > ground_level))
        {
            if (data)
                *data = map_data;

            return map_result;
        }
    }
    return result;
}

#define JUMP_HEIGHT 0.6f

// check if creature is in water and have enough space to swim
bool TerrainInfo::IsSwimmable(float x, float y, float z, float radius /*= 1.5f*/, GridMapLiquidData* data /*= 0*/) const
{
    // Check surface in x, y point for liquid
    if (const_cast<TerrainInfo*>(this)->GetGrid(x, y))
    {
        GridMapLiquidData liquid_status;
        GridMapLiquidData* liquid_ptr = data ? data : &liquid_status;
        auto const status = getLiquidStatus(x, y, z, MAP_ALL_LIQUIDS, liquid_ptr);
        if (status == LIQUID_MAP_IN_WATER || status == LIQUID_MAP_UNDER_WATER || status == LIQUID_MAP_WATER_WALK || 
           ((status == LIQUID_MAP_ABOVE_WATER) && (liquid_ptr->level + JUMP_HEIGHT >= z)))
        {
            if (liquid_ptr->level - liquid_ptr->depth_level > radius) // is unit have enough space to swim
                return true;
        }
    }
    return false;
}

bool TerrainInfo::IsInWater(float x, float y, float z, GridMapLiquidData* data) const
{
    // Check surface in x, y point for liquid
    ASSERT(MaNGOS::IsValidMapCoord(x, y, z));
    if (const_cast<TerrainInfo*>(this)->GetGrid(x, y))
    {
        GridMapLiquidData liquid_status;
        GridMapLiquidData* liquid_ptr = data ? data : &liquid_status;
        auto const status = getLiquidStatus(x, y, z, MAP_ALL_LIQUIDS, liquid_ptr);
        if (status == LIQUID_MAP_IN_WATER || status == LIQUID_MAP_UNDER_WATER)
            return true;
    }
    return false;
}

bool TerrainInfo::IsUnderWater(float x, float y, float z) const
{
    ASSERT(MaNGOS::IsValidMapCoord(x, y, z));
    if (const_cast<TerrainInfo*>(this)->GetGrid(x, y))
    {
        if (getLiquidStatus(x, y, z, MAP_LIQUID_TYPE_WATER | MAP_LIQUID_TYPE_OCEAN)&LIQUID_MAP_UNDER_WATER)
            return true;
    }
    return false;
}

/**
 * Function find higher form water or ground height for current floor
 *
 * @param x, y, z    Coordinates original point at floor level
 *
 * @param pGround    optional arg for retrun calculated by function work ground height, it let avoid in caller code recalculate height for point if it need
 *
 * @param swim       z coordinate can be calculated for select above/at or under z coordinate (for fly or swim/walking by bottom)
 *                   in last cases for in water returned under water height for avoid client set swimming unit as saty at water.
 *
 * @return           calculated z coordinate
 */
float TerrainInfo::GetWaterOrGroundLevel(Position const& position, float* pGround, bool swim) const
{
    return GetWaterOrGroundLevel(position.x, position.y, position.z, pGround, swim);
}
float TerrainInfo::GetWaterOrGroundLevel(float x, float y, float z, float* pGround /*= nullptr*/, bool swim /*= false*/) const
{
    if (const_cast<TerrainInfo*>(this)->GetGrid(x, y))
    {
        // we need ground level (including grid height version) for proper return water level in point
        float ground_z = GetHeightStatic(x, y, z, true, DEFAULT_WATER_SEARCH);
        if (pGround)
            *pGround = ground_z;

        GridMapLiquidData liquid_status;

        GridMapLiquidStatus res = getLiquidStatus(x, y, ground_z, MAP_ALL_LIQUIDS, &liquid_status);
        return res ? (swim ? liquid_status.level - 2.0f : liquid_status.level) : ground_z;
    }

    return VMAP_INVALID_HEIGHT_VALUE;
}

GridMap* TerrainInfo::GetGrid(float const x, float const y)
{
    // Giperion Elysium: It's reversed. That's ok
    int gx = (int)(32 - y / SIZE_OF_GRIDS);                 // grid x
    int gy = (int)(32 - x / SIZE_OF_GRIDS);                 // grid y

    // quick check if GridMap already loaded
    GridMap* pMap = m_GridMaps[gx][gy];
    if (!pMap)
        pMap = LoadMapAndVMap(gx, gy);

    return pMap;
}

GridMap* TerrainInfo::LoadMapAndVMap(uint32 const x, uint32 const y)
{
    // double checked lock pattern
    if (!m_GridMaps[x][y])
    {
        LOCK_GUARD lock(m_mutex);

        if (!m_GridMaps[x][y])
        {
            GridMap* map = new GridMap();

            // map file name
            int len = sWorld.GetDataPath().length() + strlen("maps/%03u%02u%02u.map") + 1;
            char* tmp = new char[len];
            snprintf(tmp, len, (char*)(sWorld.GetDataPath() + "maps/%03u%02u%02u.map").c_str(), m_mapId, y, x);

            if (!map->loadData(tmp))
            {
                sLog.outError("Error load map file: \n %s\n", tmp);
                // ASSERT(false);
            }

            delete[] tmp;
            m_GridMaps[x][y] = map;

            // load VMAPs for current map/grid...
            MapEntry const* i_mapEntry = sMapStorage.LookupEntry<MapEntry>(m_mapId);
            char const* mapName = i_mapEntry ? i_mapEntry->name : "UNNAMEDMAP\x0";

            int vmapLoadResult = VMAP::VMapFactory::createOrGetVMapManager()->loadMap((sWorld.GetDataPath() + "vmaps").c_str(),  m_mapId, x, y);
            switch (vmapLoadResult)
            {
                case VMAP::VMAP_LOAD_RESULT_OK:
                    break;
                case VMAP::VMAP_LOAD_RESULT_ERROR:
                    DEBUG_LOG("Could not load VMAP name:%s, id:%d, x:%d, y:%d (vmap rep.: x:%d, y:%d)", mapName, m_mapId, x, y, x, y);
                    break;
                case VMAP::VMAP_LOAD_RESULT_IGNORED:
                    DEBUG_LOG("Ignored VMAP name:%s, id:%d, x:%d, y:%d (vmap rep.: x:%d, y:%d)", mapName, m_mapId, x, y, x, y);
                    break;
            }

            // load navmesh
            MMAP::MMapFactory::createOrGetMMapManager()->loadMap(m_mapId, x, y);
        }
    }

    return  m_GridMaps[x][y];
}

float TerrainInfo::GetWaterLevel(float x, float y, float z, float* pGround /*= nullptr*/) const
{
    if (const_cast<TerrainInfo*>(this)->GetGrid(x, y))
    {
        // we need ground level (including grid height version) for proper return water level in point
        float ground_z = GetHeightStatic(x, y, z, true, DEFAULT_WATER_SEARCH);
        if (pGround)
            *pGround = ground_z;

        GridMapLiquidData liquid_status;

        GridMapLiquidStatus res = getLiquidStatus(x, y, ground_z, MAP_ALL_LIQUIDS, &liquid_status);
        if (!res)
            return VMAP_INVALID_HEIGHT_VALUE;

        return liquid_status.level;
    }

    return VMAP_INVALID_HEIGHT_VALUE;
}

//////////////////////////////////////////////////////////////////////////
typedef MaNGOS::ClassLevelLockable<TerrainManager, std::mutex> TerrainManagerLock;
INSTANTIATE_SINGLETON_2(TerrainManager, TerrainManagerLock);
INSTANTIATE_CLASS_MUTEX(TerrainManager, std::mutex);

TerrainManager::TerrainManager()
{
    mLiquidTypes.resize(22);
    mLiquidTypes[1] = std::make_unique<LiquidTypeEntry>(1, 1, 3, 0);
    mLiquidTypes[2] = std::make_unique<LiquidTypeEntry>(2, 7, 3, 0);
    mLiquidTypes[3] = std::make_unique<LiquidTypeEntry>(3, 13, 0, 0);
    mLiquidTypes[4] = std::make_unique<LiquidTypeEntry>(4, 19, 2, 0);
    mLiquidTypes[21] = std::make_unique<LiquidTypeEntry>(21, 25, 2, 28801);
}

TerrainManager::~TerrainManager()
{
    for (auto& it : i_TerrainMap)
        delete it.second;
}

TerrainInfo* TerrainManager::LoadTerrain(uint32 const mapId)
{
    Guard _guard(*this);

    TerrainInfo* ptr = nullptr;
    TerrainDataMap::const_iterator iter = i_TerrainMap.find(mapId);
    if (iter == i_TerrainMap.end())
    {
        ptr = new TerrainInfo(mapId);
        i_TerrainMap[mapId] = ptr;
    }
    else
        ptr = (*iter).second;

    return ptr;
}

void TerrainManager::UnloadTerrain(uint32 const mapId)
{
    if (sWorld.getConfig(CONFIG_BOOL_GRID_UNLOAD) == 0)
        return;

    Guard _guard(*this);

    TerrainDataMap::iterator iter = i_TerrainMap.find(mapId);
    if (iter != i_TerrainMap.end())
    {
        TerrainInfo* ptr = (*iter).second;
        // lets check if this object can be actually freed
        if (!ptr->IsReferenced())
        {
            i_TerrainMap.erase(iter);
            delete ptr;
        }
    }
}

void TerrainManager::Update(uint32 const diff)
{
    // global garbage collection for GridMap objects and VMaps
    for (auto& iter : i_TerrainMap)
        iter.second->CleanUpGrids(diff);
}

void TerrainManager::UnloadAll()
{
    for (auto& it : i_TerrainMap)
        delete it.second;

    i_TerrainMap.clear();
}

uint32 TerrainManager::GetAreaIdByAreaFlag(uint16 areaflag, uint32 map_id)
{
    const auto *entry = AreaEntry::GetByAreaFlagAndMap(areaflag, map_id);

    if (entry)
        return entry->Id;
    return 0;
}

uint32 TerrainManager::GetZoneIdByAreaFlag(uint16 areaflag, uint32 map_id)
{
    const auto *entry = AreaEntry::GetByAreaFlagAndMap(areaflag, map_id);

    if (entry)
        return !entry->IsZone() ? entry->ZoneId : entry->Id;
    return 0;
}

void TerrainManager::GetZoneAndAreaIdByAreaFlag(uint32& zoneid, uint32& areaid, uint16 areaflag, uint32 map_id)
{
    const auto *entry = AreaEntry::GetByAreaFlagAndMap(areaflag, map_id);

    areaid = entry ? entry->Id : 0;
    zoneid = entry ? (!entry->IsZone() ? entry->ZoneId : entry->Id) : 0;
}
