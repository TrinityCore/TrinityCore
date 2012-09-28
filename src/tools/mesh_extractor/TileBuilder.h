#ifndef TILE_BUILD_H
#define TILE_BUILD_H
#include <string>
#include "Recast.h"

#include "Geometry.h"

class TileBuilder
{
public:
    TileBuilder(std::string world, int x, int y);
    void CalculateTileBounds(float*& bmin, float*& bmax);
    uint8* Build();

    std::string World;
    int X;
    int Y;
    int MapId;
    rcConfig Config;
    Geometry* _Geometry;
};
#endif