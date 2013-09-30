#include "ContinentBuilder.h"
#include "TileBuilder.h"
#include "Geometry.h"
#include "WorldModelRoot.h"
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
    World(world), X(x), Y(y), MapId(mapId), _Geometry(NULL), DataSize(0), cBuilder(_cBuilder), pmesh(NULL), dmesh(NULL)
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

    memset(&InstanceConfig, 0, sizeof(rcConfig));
    InstanceConfig.cs = 0.2f;
    InstanceConfig.ch = 0.3f;
    InstanceConfig.minRegionArea = 25;
    InstanceConfig.mergeRegionArea = 100;
    InstanceConfig.walkableSlopeAngle = 50.0f;
    InstanceConfig.detailSampleDist = 3.0f;
    InstanceConfig.detailSampleMaxError = 1.5f;
    InstanceConfig.walkableClimb = 1.0f / InstanceConfig.ch;
    InstanceConfig.walkableHeight = 2.1f / InstanceConfig.ch;
    InstanceConfig.walkableRadius = 0.6f / InstanceConfig.cs;
    InstanceConfig.maxEdgeLen = 8 * InstanceConfig.walkableRadius;
    InstanceConfig.maxVertsPerPoly = 6;
    InstanceConfig.maxSimplificationError = 1.25f;
    InstanceConfig.borderSize = 0;

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

void TileBuilder::AddGeometry(WorldModelRoot* root, const WorldModelDefinition& def)
{
    _Geometry = new Geometry();
    _Geometry->Transform = true;

    WorldModelHandler::InsertModelGeometry(_Geometry->Vertices, _Geometry->Triangles, def, root, false);

    OutputDebugVertices();
}

uint8* TileBuilder::BuildInstance( dtNavMeshParams& navMeshParams )
{
    float* bmin = NULL, *bmax = NULL;

    _Geometry->CalculateBoundingBox(bmin, bmax);

    rcVcopy(InstanceConfig.bmax, bmax);
    rcVcopy(InstanceConfig.bmin, bmin);

    uint32 numVerts = _Geometry->Vertices.size();
    uint32 numTris = _Geometry->Triangles.size();
    float* vertices;
    int* triangles;
    uint8* areas;
    _Geometry->GetRawData(vertices, triangles, areas);

    // this sets the dimensions of the heightfield
    rcCalcGridSize(InstanceConfig.bmin, InstanceConfig.bmax, InstanceConfig.cs, &InstanceConfig.width, &InstanceConfig.height);

    rcHeightfield* hf = rcAllocHeightfield();
    rcCreateHeightfield(Context, *hf, InstanceConfig.width, InstanceConfig.height, InstanceConfig.bmin, InstanceConfig.bmax, InstanceConfig.cs, InstanceConfig.ch);

    rcClearUnwalkableTriangles(Context, InstanceConfig.walkableSlopeAngle, vertices, numVerts, triangles, numTris, areas);
    rcRasterizeTriangles(Context, vertices, numVerts, triangles, areas, numTris, *hf, InstanceConfig.walkableClimb);

    rcFilterLowHangingWalkableObstacles(Context, InstanceConfig.walkableClimb, *hf);
    rcFilterLedgeSpans(Context, InstanceConfig.walkableHeight, InstanceConfig.walkableClimb, *hf);
    rcFilterWalkableLowHeightSpans(Context, InstanceConfig.walkableHeight, *hf);

    rcCompactHeightfield* chf = rcAllocCompactHeightfield();
    rcBuildCompactHeightfield(Context, InstanceConfig.walkableHeight, InstanceConfig.walkableClimb, *hf, *chf);

    rcErodeWalkableArea(Context, InstanceConfig.walkableRadius, *chf);
    rcBuildDistanceField(Context, *chf);
    rcBuildRegions(Context, *chf, InstanceConfig.borderSize, InstanceConfig.minRegionArea, InstanceConfig.minRegionArea);

    rcContourSet* contours = rcAllocContourSet();
    rcBuildContours(Context, *chf, InstanceConfig.maxSimplificationError, InstanceConfig.maxEdgeLen, *contours);

    rcPolyMesh* pmesh = rcAllocPolyMesh();
    rcBuildPolyMesh(Context, *contours, InstanceConfig.maxVertsPerPoly, *pmesh);

    rcPolyMeshDetail* dmesh = rcAllocPolyMeshDetail();
    rcBuildPolyMeshDetail(Context, *pmesh, *chf, InstanceConfig.detailSampleDist, InstanceConfig.detailSampleMaxError, *dmesh);

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
    params.ch = InstanceConfig.ch;
    params.cs = InstanceConfig.cs;
    params.walkableClimb = InstanceConfig.walkableClimb * InstanceConfig.ch;
    params.walkableHeight = InstanceConfig.walkableHeight * InstanceConfig.ch;
    params.walkableRadius = InstanceConfig.walkableRadius * InstanceConfig.cs;
    params.tileX = X;
    params.tileY = Y;
    params.tileLayer = 0;
    params.buildBvTree = true;

    rcVcopy(params.bmax, bmax);
    rcVcopy(params.bmin, bmin);

    // Offmesh-connection settings
    params.offMeshConCount = 0; // none for now

    rcFreeHeightField(hf);
    rcFreeCompactHeightfield(chf);
    rcFreeContourSet(contours);
    rcFreePolyMesh(pmesh);
    rcFreePolyMeshDetail(dmesh);
    delete vertices;
    delete triangles;
    delete areas;
    delete bmin;
    delete bmax;

    if (!params.polyCount || !params.polys || Constants::TilesPerMap * Constants::TilesPerMap == params.polyCount)
    {
        // we have flat tiles with no actual geometry - don't build those, its useless
        // keep in mind that we do output those into debug info
        // drop tiles with only exact count - some tiles may have geometry while having less tiles
        printf("No polygons to build on tile, skipping.\n");
        return NULL;
    }

    int navDataSize;
    uint8* navData;
    printf("Creating the navmesh with %i vertices, %i polys, %i triangles!\n", params.vertCount, params.polyCount, params.detailTriCount);
    bool result = dtCreateNavMeshData(&params, &navData, &navDataSize);

    if (result)
    {
        printf("NavMesh created, size %i!\n", navDataSize);
        DataSize = navDataSize;
        return navData;
    }

    return NULL;
}

uint8* TileBuilder::BuildTiled(dtNavMeshParams& navMeshParams)
{
    _Geometry = new Geometry();
    _Geometry->Transform = true;
    ADT* adt = new ADT(Utils::GetAdtPath(World, X, Y), X, Y);
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

            ADT* _adt = new ADT(Utils::GetAdtPath(World, tx, ty), tx, ty);
            // If this condition is met, it means that this WDT does not contain the ADT
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

    OutputDebugVertices();
    
    uint32 numVerts = _Geometry->Vertices.size();
    uint32 numTris = _Geometry->Triangles.size();
    float* vertices;
    int* triangles;
    uint8* areas;
    _Geometry->GetRawData(vertices, triangles, areas);
    _Geometry->Vertices.clear();
    _Geometry->Triangles.clear();

    return NULL;
}

void TileBuilder::OutputDebugVertices()
{
    if (Constants::Debug)
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
}

TileBuilder::~TileBuilder()
{
    delete Context;
    delete _Geometry;
}
