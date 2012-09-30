#include "TileBuilder.h"
#include "Geometry.h"
#include "Constants.h"
#include "Utils.h"
#include "Cache.h"
#include "ADT.h"
#include "WDT.h"
#include "Recast.h"
#include "RecastAlloc.h"
#include "DetourNavMeshBuilder.h"

#include "ace/Synch.h"

TileBuilder::TileBuilder(std::string world, int x, int y, uint32 mapId) : _Geometry(NULL), World(world), X(x), Y(y), MapId(mapId), DataSize(0)
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

    Context = new rcContext;
}

void TileBuilder::CalculateTileBounds( float*& bmin, float*& bmax )
{
    bmin = new float[3];
    bmax = new float[3];
    bmin[0] = Constants::Origin[0] + (Constants::TileSize * X);
    bmin[2] = Constants::Origin[2] + (Constants::TileSize * Y);
    bmax[0] = Constants::Origin[0] + (Constants::TileSize * (X + 1));
    bmax[2] = Constants::Origin[2] + (Constants::TileSize * (Y + 1));
}

uint8* TileBuilder::Build()
{
    _Geometry = new Geometry();
    _Geometry->Transform = true;
    ADT* adt = new ADT(Utils::GetAdtPath(World, X, Y));
    adt->Read();
    _Geometry->AddAdt(adt);
    delete adt;

    if (_Geometry->Vertices.empty() && _Geometry->Triangles.empty())
        return NULL;

    float* bbMin;
    float* bbMax;
    CalculateTileBounds(bbMin, bbMax);
    _Geometry->CalculateMinMaxHeight(bbMin[1], bbMax[1]);

    // again, we load everything - wasteful but who cares
    for (int ty = Y - 1; ty <= Y + 1; ty++)
    {
        for (int tx = X - 1; tx <= X + 1; tx++)
        {
            // don't load main tile again
            if (tx == X && ty == Y)
                continue;
            
            ADT* _adt = new ADT(Utils::GetAdtPath(World, tx, ty));
            // If this condition is met, it means that this wdt does not contain the ADT
            if (!_adt->Data->Stream)
            {
                delete _adt;
                continue;
            }
            _adt->Read();
            _Geometry->AddAdt(_adt);
            delete _adt;
        }
    }
    uint32 numVerts = _Geometry->Vertices.size();
    uint32 numTris = _Geometry->Triangles.size();
    float* vertices;
    int* triangles;
    uint8* areas;
    _Geometry->GetRawData(vertices, triangles, areas);
    _Geometry->Vertices.clear();
    _Geometry->Triangles.clear();

    bbMin[0] -= Config.borderSize * Config.cs;
    bbMin[2] -= Config.borderSize * Config.cs;
    bbMax[0] += Config.borderSize * Config.cs;
    bbMax[0] += Config.borderSize * Config.cs;

    rcHeightfield* hf = rcAllocHeightfield();
    int width = Config.width + (Config.borderSize * 2);
    rcCreateHeightfield(Context, *hf, width, width, bbMin, bbMax, Config.cs, Config.ch);
    rcClearUnwalkableTriangles(Context, Config.walkableSlopeAngle, vertices, numVerts, triangles, numTris, areas);
    rcRasterizeTriangles(Context, vertices, numVerts, triangles, areas, numTris, *hf, Config.walkableClimb);
    
    printf("[%02i,%02i] Triangles rasterized!\n", X, Y);

    // Once all geometry is rasterized, we do initial pass of filtering to
    // remove unwanted overhangs caused by the conservative rasterization
    // as well as filter spans where the character cannot possibly stand.
    rcFilterLowHangingWalkableObstacles(Context, Config.walkableClimb, *hf);
    rcFilterLedgeSpans(Context, Config.walkableHeight, Config.walkableClimb, *hf);
    rcFilterWalkableLowHeightSpans(Context, Config.walkableHeight, *hf);
    
    printf("[%02i,%02i] Filtering done!\n", X, Y);

    // Compact the heightfield so that it is faster to handle from now on.
    // This will result in more cache coherent data as well as the neighbours
    // between walkable cells will be calculated.
    rcCompactHeightfield* chf = rcAllocCompactHeightfield();
    rcBuildCompactHeightfield(Context, Config.walkableHeight, Config.walkableClimb, *hf, *chf);

    rcFreeHeightField(hf);

    printf("[%02i,%02i] Heightfield compressed!\n", X, Y);

    // Erode the walkable area by agent radius.
    rcErodeWalkableArea(Context, Config.walkableRadius, *chf);
    // Prepare for region partitioning, by calculating distance field along the walkable surface.
    rcBuildDistanceField(Context, *chf);
    // Partition the walkable surface into simple regions without holes.
    rcBuildRegions(Context, *chf, Config.borderSize, Config.minRegionArea, Config.mergeRegionArea);
    
    printf("[%02i,%02i] Regions built!\n", X, Y);

    // Create contours.
    rcContourSet* cset = rcAllocContourSet();
    rcBuildContours(Context, *chf, Config.maxSimplificationError, Config.maxEdgeLen, *cset);
    
    // Build polygon navmesh from the contours.
    rcPolyMesh* pmesh = rcAllocPolyMesh();
    rcBuildPolyMesh(Context, *cset, Config.maxVertsPerPoly, *pmesh);

    printf("[%02i,%02i] Polymesh built!\n", X, Y);

    // Build detail mesh.
    rcPolyMeshDetail* dmesh = rcAllocPolyMeshDetail();
    rcBuildPolyMeshDetail(Context, *pmesh, *chf, Config.detailSampleDist, Config.detailSampleMaxError, *dmesh);

    printf("[%02i,%02i] Polymesh detail built!\n", X, Y);

    rcFreeCompactHeightfield(chf);
    rcFreeContourSet(cset);

    // Remove padding from the polymesh data. (Remove this odditity)
    for (int i = 0; i < pmesh->nverts; ++i)
    {
        unsigned short* v = &pmesh->verts[i * 3];
        v[0] -= (unsigned short)Config.borderSize;
        v[2] -= (unsigned short)Config.borderSize;
    }

    // Set flags according to area types (e.g. Swim for Water)
    for (int i = 0; i < pmesh->npolys; i++)
    {
        if (pmesh->areas[i] == Constants::POLY_AREA_ROAD || pmesh->areas[i] == Constants::POLY_AREA_TERRAIN)
            pmesh->flags[i] = Constants::POLY_FLAG_WALK;
        else if (pmesh->areas[i] == (int)Constants::POLY_AREA_WATER)
            pmesh->flags[i] = Constants::POLY_FLAG_SWIM;
    }

    // get original bounds
    float* tilebMin;
    float* tilebMax;
    CalculateTileBounds(tilebMin, tilebMax);
    tilebMin[1] = bbMin[1];
    tilebMax[1] = bbMax[1];

    dtNavMeshCreateParams params;
    // PolyMesh data
    params.verts = pmesh->verts;
    params.vertCount = pmesh->nverts;
    params.polys = pmesh->polys;
    params.polyAreas = pmesh->areas;
    params.polyFlags = pmesh->flags;
    params.polyCount = pmesh->npolys;
    params.nvp = pmesh->nvp;
    // PolyMeshDetail data
    params.detailMeshes = dmesh->meshes;
    params.detailVerts = dmesh->verts;
    params.detailVertsCount = dmesh->nverts;
    params.detailTris = dmesh->tris;
    params.detailTriCount = dmesh->ntris;
    // Copy bounding box
    params.bmin[0] = tilebMin[0];
    params.bmin[1] = tilebMin[1];
    params.bmin[2] = tilebMin[2];
    params.bmax[0] = tilebMax[0];
    params.bmax[1] = tilebMax[1];
    params.bmax[2] = tilebMax[2];
    // General settings
    params.ch = Config.ch;
    params.cs = Config.cs;
    params.walkableClimb = Config.walkableClimb;
    params.walkableHeight = Config.walkableHeight;
    params.walkableRadius = Config.walkableRadius;
    params.tileX = X;
    params.tileY = Y;
    params.tileSize = Config.width;

    // Offmesh-connection settings
    params.offMeshConCount = 0; // none for now

    int navDataSize;
    uint8* navData;
    printf("[%02i,%02i] Creating the navmesh!\n", X, Y);
    bool result = dtCreateNavMeshData(&params, &navData, &navDataSize);
	
	// Free some memory
	rcFreePolyMesh(pmesh);
	rcFreePolyMeshDetail(dmesh);
	delete tilebMax;
	delete tilebMin;
	delete areas;
	delete triangles;
	delete vertices;
	delete bbMax;
	delete bbMin;

	if (result)
    {
        printf("[%02i,%02i] NavMesh created, size %i!\n", X, Y, navDataSize);
        DataSize = navDataSize;
        return navData;
    }

    return NULL;
}

TileBuilder::~TileBuilder()
{
	delete Context;
	delete _Geometry;
}
