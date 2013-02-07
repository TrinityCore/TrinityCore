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
    static const char* VMAPMagic;
    static const float BaseUnitDim;
    static const int VertexPerMap;
    static const int VertexPerTile;
    static const int TilesPerMap;
};

#endif