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

    enum PolyFlag
    {
        POLY_FLAG_WALK  = 1,
        POLY_FLAG_SWIM  = 2,
        POLY_FLAG_FLIGHTMASTER = 4
    };

    enum ExtractFlags
    {
        EXTRACT_FLAG_DBC            = 1,
        EXTRACT_FLAG_MAPS           = 2,
        EXTRACT_FLAG_VMAPS          = 4,
        EXTRACT_FLAG_GOB_MODELS     = 8,
        EXTRACT_FLAG_MMAPS          = 16,
        EXTRACT_FLAG_ALLOWED        = EXTRACT_FLAG_DBC | EXTRACT_FLAG_MAPS | EXTRACT_FLAG_VMAPS | EXTRACT_FLAG_GOB_MODELS | EXTRACT_FLAG_MMAPS
    };

    static const float TileSize;
    static const float MaxXY;
    static const float ChunkSize;
    static const float UnitSize;
    static const float Origin[];
    static const float PI;
    static const float MaxStandableHeight;
};

#endif