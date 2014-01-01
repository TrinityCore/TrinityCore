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

#ifndef CONSTANTS_H
#define CONSTANTS_H

class Constants
{
public:
    enum TriangleType
    {
        TRIANGLE_TYPE_UNKNOWN,
        TRIANGLE_TYPE_TERRAIN,
        TRIANGLE_TYPE_WATER,
        TRIANGLE_TYPE_MAGMA,
        TRIANGLE_TYPE_SLIME,
        TRIANGLE_TYPE_DOODAD,
        TRIANGLE_TYPE_WMO
    };

    enum PolyArea
    {
        POLY_AREA_TERRAIN = 1,
        POLY_AREA_WATER = 2,
        POLY_AREA_ROAD = 3,
        POLY_AREA_DANGER = 4,
    };

    enum PolyFlag
    {
        POLY_FLAG_WALK  = 1,
        POLY_FLAG_SWIM  = 2,
        POLY_FLAG_FLIGHTMASTER = 4
    };

    enum ExtractFlags
    {
        EXTRACT_FLAG_DBC            = 0x01,
        EXTRACT_FLAG_MAPS           = 0x02,
        EXTRACT_FLAG_VMAPS          = 0x04,
        EXTRACT_FLAG_GOB_MODELS     = 0x08,
        EXTRACT_FLAG_MMAPS          = 0x10,
        EXTRACT_FLAG_TEST           = 0x20,
        EXTRACT_FLAG_ALLOWED        = EXTRACT_FLAG_DBC | EXTRACT_FLAG_MAPS | EXTRACT_FLAG_VMAPS | EXTRACT_FLAG_GOB_MODELS | EXTRACT_FLAG_MMAPS | EXTRACT_FLAG_TEST
    };

    static const float TileSize;
    static const float MaxXY;
    static const float ChunkSize;
    static const float UnitSize;
    static const float Origin[];
    static const float PI;
    static const float MaxStandableHeight;
    static bool ToWoWCoords;
    static bool Debug;
    static const char* VMAPMagic;
    static const float BaseUnitDim;
    static const int VertexPerMap;
    static const int VertexPerTile;
    static const int TilesPerMap;
};

#endif