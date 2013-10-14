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

    void CalculateTileBounds(float*& bmin, float*& bmax, dtNavMeshParams& navMeshParams);
    uint8* BuildTiled(dtNavMeshParams& navMeshParams);
    uint8* BuildInstance(dtNavMeshParams& navMeshParams);
    void AddGeometry(WorldModelRoot* root, const WorldModelDefinition& def);
    void OutputDebugVertices();
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