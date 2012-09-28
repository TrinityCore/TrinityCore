#ifndef CONSTANTS_H
#define CONSTANTS_H

#include "Common.h"

class Constants
{
public:
    enum TriangleType
    {
        TRIANGLE_TYPE_UNKNOWN,
        TRIANGLE_TYPE_TERRAIN,
        TRIANGLE_TYPE_WATER,
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
    static const float TileSize;
    static const float MaxXY;
    static const float ChunkSize;
    static const float UnitSize;
    static const float Origin[];
    static const float PI;
};

#endif