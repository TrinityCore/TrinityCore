#include "TileBuilder.h"
#include "Constants.h"

TileBuilder::TileBuilder(std::string world, int x, int y) : _Geometry(NULL), World(world), X(x), Y(y), MapId(608)
{
    // Cell Size = TileSize / TileVoxelSize
    // 1800 = TileVoxelSize
    Config.cs = Constants::TileSize / 1800; 
    // Cell Height
    Config.ch = 0.3f;
    // Min Region Area = 6^2
    Config.minRegionArea = 36;
    // Merge Region Area = 12^2
    Config.mergeRegionArea = 144;
    Config.walkableSlopeAngle = 50.0f;
    Config.detailSampleDist = 3.0f;
    Config.detailSampleMaxError = 1.25f;
    Config.walkableClimb = 1.0f / Config.ch;
    Config.walkableHeight = 2.1f / Config.ch;
    Config.walkableRadius = 0.6f / Config.cs;
    Config.maxEdgeLen = Config.walkableRadius * 8;
    Config.borderSize = Config.walkableRadius + 8;
    Config.width = 1800;
    Config.maxVertsPerPoly = 6;
    Config.maxSimplificationError = 1.3f;
}

void TileBuilder::CalculateTileBounds( float*& bmin, float*& bmax )
{
    float origin[3] = Constants::Origin;
    bmin = new float[3];
    bmax = new float[3];
    bmin[0] = origin[0] + (Constants::TileSize * X);
    bmin[2] = origin[2] + (Constants::TileSize * Y);
    bmax[0] = origin[0] + (Constants::TileSize * (X + 1));
    bmax[2] = origin[2] + (Constants::TileSize * (Y + 1));
}