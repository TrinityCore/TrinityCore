#ifndef TILE_BUILD_H
#define TILE_BUILD_H
#include <string>
#include "Recast.h"

#include "Geometry.h"

class ContinentBuilder;
class WDT;

class TileBuilder
{
public:
    TileBuilder(ContinentBuilder* _cBuilder, std::string world, int x, int y, uint32 mapId);
    ~TileBuilder();

    void CalculateTileBounds(float*& bmin, float*& bmax, dtNavMeshParams& navMeshParams);
    uint8* Build(dtNavMeshParams& navMeshParams);

    std::string World;
    int X;
    int Y;
    int MapId;
    rcConfig Config;
    rcContext* Context;
    Geometry* _Geometry;
    uint32 DataSize;
    ContinentBuilder* cBuilder;
};
#endif