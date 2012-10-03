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
    Config.ch = 0.4f;
    // Min Region Area = 20^2
    Config.minRegionArea = 20*20;
    // Merge Region Area = 40^2
    Config.mergeRegionArea = 40*40;
    Config.tileSize = Constants::TileSize / 4;
    Config.walkableSlopeAngle = 50.0f;
    Config.detailSampleDist = 3.0f;
    Config.detailSampleMaxError = 1.25f;
    Config.walkableClimb = floorf(1.0f / Config.ch);
    Config.walkableHeight = ceilf(1.652778f / Config.ch);
    Config.walkableRadius = ceilf(0.2951389f / Config.cs);
    Config.maxEdgeLen = Config.walkableRadius * 8;
    Config.borderSize = Config.walkableRadius + 4;
    Config.width = 1800 + Config.borderSize * 2;
    Config.height = 1800 + Config.borderSize * 2;
    Config.maxVertsPerPoly = 6;
    Config.maxSimplificationError = 1.3f;

    Context = new rcContext;
}

void TileBuilder::CalculateTileBounds( float*& bmin, float*& bmax, dtNavMeshParams& navMeshParams )
{
    bmin = new float[3];
    bmax = new float[3];
    bmin[0] = Constants::Origin[0] /*navMeshParams.orig[0]*/ + (Constants::TileSize * X);
    bmin[2] = Constants::Origin[2] /*navMeshParams.orig[2]*/ + (Constants::TileSize * Y);
    bmax[0] = Constants::Origin[0] /*navMeshParams.orig[0]*/ + (Constants::TileSize * (X + 1));
    bmax[2] = Constants::Origin[2] /*navMeshParams.orig[2]*/ + (Constants::TileSize * (Y + 1));
}

uint8* TileBuilder::Build(bool dbg, dtNavMeshParams& navMeshParams)
{
    _Geometry = new Geometry();
    _Geometry->Transform = true;
    ADT* adt = new ADT(Utils::GetAdtPath(World, X, Y));
    adt->Read();
    _Geometry->AddAdt(adt);
    delete adt;

    if (_Geometry->Vertices.empty() && _Geometry->Triangles.empty())
        return NULL;

    // again, we load everything - wasteful but who cares
    for (int ty = Y - 2; ty <= Y + 2; ty++)
    {
        for (int tx = X - 2; tx <= X + 2; tx++)
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

    if (dbg)
    {
        char buff[100];
        sprintf(buff, "mmaps/%s_%02u%02u.obj", World.c_str(), Y, X);
        FILE* debug = fopen(buff, "wb");
        for (int i = 0; i < _Geometry->Vertices.size(); ++i)
            fprintf(debug, "v %f %f %f\n", _Geometry->Vertices[i].x, _Geometry->Vertices[i].y, _Geometry->Vertices[i].z);
        for (int i = 0; i < _Geometry->Triangles.size(); ++i)
            fprintf(debug, "f %i %i %i\n", _Geometry->Triangles[i].V0 + 1, _Geometry->Triangles[i].V1 + 1, _Geometry->Triangles[i].V2 + 1);
        fclose(debug);
    }
    
    uint32 numVerts = _Geometry->Vertices.size();
    uint32 numTris = _Geometry->Triangles.size();
    float* vertices;
    int* triangles;
    uint8* areas;
    _Geometry->GetRawData(vertices, triangles, areas);
    _Geometry->Vertices.clear();
    _Geometry->Triangles.clear();

    float bbMin[3];
    float bbMax[3];
    // CalculateTileBounds(bbMin, bbMax, navMeshParams);
    rcCalcBounds(vertices, numVerts, bbMin, bbMax);
    // _Geometry->CalculateMinMaxHeight(bbMin[1], bbMax[1]);

    /*bbMin[0] -= Config.borderSize * Config.cs;
    bbMin[2] -= Config.borderSize * Config.cs;
    bbMax[0] += Config.borderSize * Config.cs;
    bbMax[0] += Config.borderSize * Config.cs;*/


    rcHeightfield* hf = rcAllocHeightfield();
    int height, width;
    rcCalcGridSize(bbMin, bbMax, Config.cs, &width, &height);
    printf("Config values: Height: %i, Width: %i. Calculated values: Height: %i, Width: %i\n", Config.height, Config.width, height, width);
    rcCreateHeightfield(Context, *hf, width, height, bbMin, bbMax, Config.cs, Config.ch);
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

    /*
    * Removed with RecastNavigation v292
    // Remove padding from the polymesh data. (Remove this odditity)
    for (int i = 0; i < pmesh->nverts; ++i)
    {
        unsigned short* v = &pmesh->verts[i * 3];
        v[0] -= (unsigned short)Config.borderSize;
        v[2] -= (unsigned short)Config.borderSize;
    }*/

    // Set flags according to area types (e.g. Swim for Water)
    for (int i = 0; i < pmesh->npolys; i++)
    {
        if (pmesh->areas[i] == Constants::POLY_AREA_ROAD || pmesh->areas[i] == Constants::POLY_AREA_TERRAIN)
            pmesh->flags[i] = Constants::POLY_FLAG_WALK;
        else if (pmesh->areas[i] == Constants::POLY_AREA_WATER)
            pmesh->flags[i] = Constants::POLY_FLAG_SWIM;
    }

    // get original bounds
    /*float* tilebMin;
    float* tilebMax;
    CalculateTileBounds(tilebMin, tilebMax, navMeshParams);
    tilebMin[1] = bbMin[1];
    tilebMax[1] = bbMax[1];*/

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
    /*params.bmin[0] = tilebMin[0];
    params.bmin[1] = tilebMin[1];
    params.bmin[2] = tilebMin[2];
    params.bmax[0] = tilebMax[0];
    params.bmax[1] = tilebMax[1];
    params.bmax[2] = tilebMax[2];*/
    rcVcopy(params.bmin, pmesh->bmin);
    rcVcopy(params.bmax, pmesh->bmax);
    // General settings
    params.ch = Config.ch;
    params.cs = Config.cs;
    params.walkableClimb = Config.walkableClimb;
    params.walkableHeight = Config.walkableHeight;
    params.walkableRadius = Config.walkableRadius;
    params.tileX = X;
    params.tileY = Y;
    int _x = (((pmesh->bmin[0] + pmesh->bmax[0]) / 2) - Constants::Origin[0]) / Constants::TileSize;
    int _y = (((pmesh->bmin[2] + pmesh->bmax[2]) / 2) - Constants::Origin[2]) / Constants::TileSize;
    printf("[%02i,%02i] Generated with TileX: %i and TileY: %i\nbmin[0] %f bmin[1] %f bmin[2] %f bmax[0] %f bmax[1] %f bmax[2] %f\n", X, Y, _x, _y, params.bmin[0], params.bmin[1], params.bmin[2], params.bmax[0], params.bmax[1], params.bmax[2]);
    params.buildBvTree = true;
    params.tileLayer = 0;

    // Offmesh-connection settings
    params.offMeshConCount = 0; // none for now

    int navDataSize;
    uint8* navData;
    printf("[%02i,%02i] Creating the navmesh with %i vertices, %i polys, %i triangles!\n", X, Y, pmesh->nverts, pmesh->npolys, dmesh->ntris);
    bool result = dtCreateNavMeshData(&params, &navData, &navDataSize);

    // Free some memory
    rcFreePolyMesh(pmesh);
    rcFreePolyMeshDetail(dmesh);
    //delete tilebMax;
    //delete tilebMin;
    delete areas;
    delete triangles;
    delete vertices;
    //delete bbMax;
    //delete bbMin;

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
