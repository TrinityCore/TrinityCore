#include "ContinentBuilder.h"
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

#include <ace/Synch.h>

TileBuilder::TileBuilder(ContinentBuilder* _cBuilder, std::string world, int x, int y, uint32 mapId) :
    World(world), X(x), Y(y), MapId(mapId), _Geometry(NULL), DataSize(0), cBuilder(_cBuilder)
{
    /*
        Test, non-working values
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
    */

    // All are in UNIT metrics!
    memset(&Config, 0, sizeof(rcConfig));

    Config.maxVertsPerPoly = DT_VERTS_PER_POLYGON;
    Config.cs = Constants::BaseUnitDim;
    Config.ch = Constants::BaseUnitDim;
    Config.walkableSlopeAngle = 60.0f;
    Config.tileSize = Constants::VertexPerTile;
    Config.walkableRadius = 1;
    Config.borderSize = Config.walkableRadius + 3;
    Config.maxEdgeLen = Constants::VertexPerTile + 1;        //anything bigger than tileSize
    Config.walkableHeight = 3;
    Config.walkableClimb = 2;                      // keep less than walkableHeight
    Config.minRegionArea = rcSqr(60);
    Config.mergeRegionArea = rcSqr(50);
    Config.maxSimplificationError = 2.0f;       // eliminates most jagged edges (tinny polygons)
    Config.detailSampleDist = Config.cs * 64;
    Config.detailSampleMaxError = Config.ch * 2;

    Context = new rcContext;
}

void TileBuilder::CalculateTileBounds( float*& bmin, float*& bmax, dtNavMeshParams& /*navMeshParams*/ )
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
        for (uint32 i = 0; i < _Geometry->Vertices.size(); ++i)
        {
            const Vector3& vector = _Geometry->Vertices[i];
            fprintf(debug, "v %f %f %f\n", vector.x, vector.y, vector.z);
        }
        for (uint32 i = 0; i < _Geometry->Triangles.size(); ++i)
        {
            const Triangle<uint32>& triangle = _Geometry->Triangles[i];
            fprintf(debug, "f %u %u %u\n", triangle.V0 + 1, triangle.V1 + 1, triangle.V2 + 1);
        }
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


    rcVcopy(Config.bmin, cBuilder->bmin);
    rcVcopy(Config.bmax, cBuilder->bmax);

    // this sets the dimensions of the heightfield - should maybe happen before border padding
    rcCalcGridSize(Config.bmin, Config.bmax, Config.cs, &Config.width, &Config.height);

    // Initialize per tile config.
    rcConfig tileCfg = Config;
    tileCfg.width = Config.tileSize + Config.borderSize * 2;
    tileCfg.height = Config.tileSize + Config.borderSize * 2;

    // merge per tile poly and detail meshes
    rcPolyMesh** pmmerge = new rcPolyMesh*[Constants::TilesPerMap * Constants::TilesPerMap];
    rcPolyMeshDetail** dmmerge = new rcPolyMeshDetail*[Constants::TilesPerMap * Constants::TilesPerMap];

    int nmerge = 0;
    for (int y = 0; y < Constants::TilesPerMap; ++y)
    {
        for (int x = 0; x < Constants::TilesPerMap; ++x)
        {
            // Calculate the per tile bounding box.
            tileCfg.bmin[0] = Config.bmin[0] + float(x * Config.tileSize - Config.borderSize) * Config.cs;
            tileCfg.bmin[2] = Config.bmin[2] + float(y * Config.tileSize - Config.borderSize) * Config.cs;
            tileCfg.bmax[0] = Config.bmin[0] + float((x + 1) * Config.tileSize + Config.borderSize) * Config.cs;
            tileCfg.bmax[2] = Config.bmin[2] + float((y + 1) * Config.tileSize + Config.borderSize) * Config.cs;


            rcHeightfield* hf = rcAllocHeightfield();
            rcCreateHeightfield(Context, *hf, tileCfg.width, tileCfg.height, tileCfg.bmin, tileCfg.bmax, tileCfg.cs, tileCfg.ch);
            rcClearUnwalkableTriangles(Context, tileCfg.walkableSlopeAngle, vertices, numVerts, triangles, numTris, areas);
            rcRasterizeTriangles(Context, vertices, numVerts, triangles, areas, numTris, *hf, Config.walkableClimb);

            // Once all geometry is rasterized, we do initial pass of filtering to
            // remove unwanted overhangs caused by the conservative rasterization
            // as well as filter spans where the character cannot possibly stand.
            rcFilterLowHangingWalkableObstacles(Context, Config.walkableClimb, *hf);
            rcFilterLedgeSpans(Context, tileCfg.walkableHeight, tileCfg.walkableClimb, *hf);
            rcFilterWalkableLowHeightSpans(Context, tileCfg.walkableHeight, *hf);

            // Compact the heightfield so that it is faster to handle from now on.
            // This will result in more cache coherent data as well as the neighbours
            // between walkable cells will be calculated.
            rcCompactHeightfield* chf = rcAllocCompactHeightfield();
            rcBuildCompactHeightfield(Context, tileCfg.walkableHeight, tileCfg.walkableClimb, *hf, *chf);

            rcFreeHeightField(hf);

            // Erode the walkable area by agent radius.
            rcErodeWalkableArea(Context, Config.walkableRadius, *chf);
            // Prepare for region partitioning, by calculating distance field along the walkable surface.
            rcBuildDistanceField(Context, *chf);
            // Partition the walkable surface into simple regions without holes.
            rcBuildRegions(Context, *chf, tileCfg.borderSize, tileCfg.minRegionArea, tileCfg.mergeRegionArea);

            // Create contours.
            rcContourSet* cset = rcAllocContourSet();
            rcBuildContours(Context, *chf, tileCfg.maxSimplificationError, tileCfg.maxEdgeLen, *cset);

            // Build polygon navmesh from the contours.
            rcPolyMesh* pmesh = rcAllocPolyMesh();
            rcBuildPolyMesh(Context, *cset, tileCfg.maxVertsPerPoly, *pmesh);

            // Build detail mesh.
            rcPolyMeshDetail* dmesh = rcAllocPolyMeshDetail();
            rcBuildPolyMeshDetail(Context, *pmesh, *chf, tileCfg.detailSampleDist, tileCfg.detailSampleMaxError, *dmesh);

            // Free memory
            rcFreeCompactHeightfield(chf);
            rcFreeContourSet(cset);

            pmmerge[nmerge] = pmesh;
            dmmerge[nmerge] = dmesh;
            ++nmerge;
        }
    }

    rcPolyMesh* pmesh = rcAllocPolyMesh();
    rcMergePolyMeshes(Context, pmmerge, nmerge, *pmesh);

    rcPolyMeshDetail* dmesh = rcAllocPolyMeshDetail();
    rcMergePolyMeshDetails(Context, dmmerge, nmerge, *dmesh);

    delete[] pmmerge;
    delete[] dmmerge;

    printf("[%02i,%02i] Meshes merged!\n", X, Y);

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
        else if (pmesh->areas[i] == Constants::POLY_AREA_WATER)
            pmesh->flags[i] = Constants::POLY_FLAG_SWIM;
    }

    dtNavMeshCreateParams params;
    memset(&params, 0, sizeof(params));
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
    rcVcopy(params.bmin, pmesh->bmin);
    rcVcopy(params.bmax, pmesh->bmax);
    // General settings
    params.ch = Config.ch;
    params.cs = Config.cs;
    params.walkableClimb = Constants::BaseUnitDim * Config.walkableClimb;
    params.walkableHeight = Constants::BaseUnitDim * Config.walkableHeight;
    params.walkableRadius = Constants::BaseUnitDim * Config.walkableRadius;
    params.tileX = (((cBuilder->bmin[0] + cBuilder->bmax[0]) / 2) - navMeshParams.orig[0]) / Constants::TileSize;
    params.tileY = (((cBuilder->bmin[2] + cBuilder->bmax[2]) / 2) - navMeshParams.orig[2]) / Constants::TileSize;

    rcVcopy(params.bmin, cBuilder->bmin);
    rcVcopy(params.bmax, cBuilder->bmax);

    // Offmesh-connection settings
    params.offMeshConCount = 0; // none for now

    //params.tileSize = Constants::VertexPerMap;

    if (!params.polyCount || !params.polys || Constants::TilesPerMap * Constants::TilesPerMap == params.polyCount)
    {
        // we have flat tiles with no actual geometry - don't build those, its useless
        // keep in mind that we do output those into debug info
        // drop tiles with only exact count - some tiles may have geometry while having less tiles
        printf("[%02i,%02i] No polygons to build on tile, skipping.\n", X, Y);
        rcFreePolyMesh(pmesh);
        rcFreePolyMeshDetail(dmesh);
        delete areas;
        delete triangles;
        delete vertices;
        return NULL;
    }

    int navDataSize;
    uint8* navData;
    printf("[%02i,%02i] Creating the navmesh with %i vertices, %i polys, %i triangles!\n", X, Y, pmesh->nverts, pmesh->npolys, dmesh->ntris);
    bool result = dtCreateNavMeshData(&params, &navData, &navDataSize);

    // Free some memory
    rcFreePolyMesh(pmesh);
    rcFreePolyMeshDetail(dmesh);
    delete areas;
    delete triangles;
    delete vertices;

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
