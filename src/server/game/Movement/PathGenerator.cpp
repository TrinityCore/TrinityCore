/*
 * Copyright (C) 2008-2013 TrinityCore <http://www.trinitycore.org/>
 * Copyright (C) 2005-2011 MaNGOS <http://getmangos.com/>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

#include "PathGenerator.h"
#include "Map.h"
#include "Creature.h"
#include "MMapFactory.h"
#include "MMapManager.h"
#include "Log.h"

#include "DetourCommon.h"
#include "DetourNavMeshQuery.h"

float PathGenerator::MinWallDistance = 2.5f;

////////////////// PathGenerator //////////////////
PathGenerator::PathGenerator(const Unit* owner) :
    _type(PATHFIND_BLANK), _endPosition(G3D::Vector3::zero()),
    _sourceUnit(owner), _navMesh(NULL), _navMeshQuery(NULL)
{
    TC_LOG_DEBUG("maps", "PathGenerator::PathGenerator for %u \n", _sourceUnit->GetGUIDLow());

    uint32 mapId = _sourceUnit->GetMapId();
    if (MMAP::MMapFactory::IsPathfindingEnabled(mapId))
    {
        MMAP::MMapManager* mmap = MMAP::MMapFactory::CreateOrGetMMapManager();
        _navMesh = mmap->GetNavMesh(mapId);
        _navMeshQuery = mmap->GetNavMeshQuery(mapId, _sourceUnit->GetInstanceId());
    }

    CreateFilter();
}

PathGenerator::~PathGenerator()
{
    TC_LOG_DEBUG("maps", "PathGenerator::~PathGenerator() for %u \n", _sourceUnit->GetGUIDLow());
}

bool PathGenerator::CalculatePath(float destX, float destY, float destZ, bool forceDest)
{
    float x, y, z;
    _sourceUnit->GetPosition(x, y, z);

    if (!Trinity::IsValidMapCoord(destX, destY, destZ) || !Trinity::IsValidMapCoord(x, y, z))
    {
        TC_LOG_DEBUG("maps", "PathGenerator::CalculatePath() called with invalid map coords, destX: %f destY: %f destZ: %f x: %f y: %f z: %f for creature %u", destX, destY, destZ, x, y, z, _sourceUnit->GetGUIDLow());
        return false;
    }

    G3D::Vector3 dest(destX, destY, destZ);
    SetEndPosition(dest);

    G3D::Vector3 start(x, y, z);
    SetStartPosition(start);

    TC_LOG_DEBUG("maps", "PathGenerator::CalculatePath() for %u \n", _sourceUnit->GetGUIDLow());

    // make sure navMesh works - we can run on map w/o mmap
    // check if the start and end point have a .mmtile loaded (can we pass via not loaded tile on the way?)
    if (!_navMesh || !_navMeshQuery || _sourceUnit->HasUnitState(UNIT_STATE_IGNORE_PATHFINDING))
    {
        TC_LOG_DEBUG("maps", "PathGenerator::CalculatePath() navmesh is not initialized for %u \n", _sourceUnit->GetGUIDLow());
        _type = PathType(PATHFIND_NORMAL | PATHFIND_NOT_USING_PATH);
        return true;
    }

    UpdateFilter();

    float startPos[3];
    startPos[0] = -y;
    startPos[1] = z;
    startPos[2] = -x;

    float endPos[3];
    endPos[0] = -destY;
    endPos[1] = destZ;
    endPos[2] = -destX;

    float polyPickExt[3];
    polyPickExt[0] = 2.5f;
    polyPickExt[1] = 2.5f;
    polyPickExt[2] = 2.5f;

    //
    dtPolyRef startRef;
    dtPolyRef endRef;

    float nearestPt[3];

    _navMeshQuery->findNearestPoly(startPos, polyPickExt, &_filter, &startRef, nearestPt);
    _navMeshQuery->findNearestPoly(endPos, polyPickExt, &_filter, &endRef, nearestPt);

    if (!startRef || !endRef)
    {
        TC_LOG_DEBUG("maps", "PathGenerator::CalculatePath() for %u no polygons found for start and end locations\n", _sourceUnit->GetGUIDLow());
        _type = PATHFIND_NOPATH;
        return false;
    }

    int hops;
    dtPolyRef* hopBuffer = new dtPolyRef[8192];
    dtStatus status = _navMeshQuery->findPath(startRef, endRef, startPos, endPos, &_filter, hopBuffer, &hops, 8192);

    if (!dtStatusSucceed(status))
    {
        TC_LOG_DEBUG("maps", "PathGenerator::CalculatePath() for %u no path found for start and end locations\n", _sourceUnit->GetGUIDLow());
        _type = PATHFIND_NOPATH;
        return false;
    }

    int resultHopCount;
    float* straightPath = new float[2048 * 3];
    unsigned char* pathFlags = new unsigned char[2048];
    dtPolyRef* pathRefs = new dtPolyRef[2048];

    status = _navMeshQuery->findStraightPath(startPos, endPos, hopBuffer, hops, straightPath, pathFlags, pathRefs, &resultHopCount, 2048);
    if (!dtStatusSucceed(status))
    {
        TC_LOG_DEBUG("maps", "PathGenerator::CalculatePath() for %u no straight path found for start and end locations\n", _sourceUnit->GetGUIDLow());
        _type = PATHFIND_NOPATH;
        return false;
    }

    SmoothPath(polyPickExt, resultHopCount, straightPath); // Separate the path from the walls

    for (uint32 i = 0; i < resultHopCount; ++i)
    {
        _pathPoints.push_back(G3D::Vector3(-straightPath[i * 3 + 2], -straightPath[i * 3 + 0], straightPath[i * 3 + 1]));
        TC_LOG_DEBUG("maps", "PathGenerator::CalculatePath() for %u path point %u: (%f, %f, %f)", _sourceUnit->GetGUIDLow(), i, _pathPoints[i].x, _pathPoints[i].y, _pathPoints[i].z);
    }

    return true;
}

void PathGenerator::CreateFilter()
{
    uint16 includeFlags = POLY_FLAG_WALK | POLY_FLAG_SWIM;
    uint16 excludeFlags = 0;

    if (_sourceUnit->GetTypeId() == TYPEID_UNIT && !_sourceUnit->ToCreature()->CanSwim())
    {
        includeFlags = POLY_FLAG_WALK;
        excludeFlags = POLY_FLAG_SWIM;
    }

    _filter.setIncludeFlags(includeFlags);
    _filter.setExcludeFlags(excludeFlags);

    UpdateFilter();
}

void PathGenerator::UpdateFilter()
{

}

float PathGenerator::GetTriangleArea(float* verts, int nv)
{
    float area = 0;
    for (int i = 0; i < nv - 1; i++)
        area += verts[i * 3] * verts[i * 3 + 5] - verts[i * 3 + 3] * verts[i * 3 + 2];
    area += verts[(nv - 1) * 3] * verts[2] - verts[0] * verts[(nv - 1) * 3 + 2];
    return area * 0.5f;
}

bool PathGenerator::PointInPoly(float* pos, float* verts, int nv, float err)
{
    // Poly area
    float area = abs(PathGenerator::GetTriangleArea(verts, nv));

    // Calculate each area of the triangles
    float testTri[9];
    memcpy(testTri, pos, sizeof(float) * 3);
    float area1 = 0;
    for(int i = 0; i < nv - 1; ++i)
    {
        memcpy(&testTri[3], &verts[i * 3], sizeof(float) * 3);
        memcpy(&testTri[6], &verts[i * 3 + 3], sizeof(float) * 3);
        area1 += abs(PathGenerator::GetTriangleArea(testTri, 3));
        if (area1 - err > area)
            return false;
    }

    // Last one
    memcpy(&testTri[3], verts, sizeof(float) * 3);
    memcpy(&testTri[6], &verts[nv * 3 - 3] , sizeof(float) * 3);
    area1 += abs(PathGenerator::GetTriangleArea(testTri, 3));

    return abs(area1 - area) < err;
}

float PathGenerator::DistanceToWall(float* polyPickExt, float* pos, float* hitPos, float* hitNormal)
{
    float distanceToWall = 0;
    dtPolyRef ref;

    dtStatus status = _navMeshQuery->findNearestPoly(pos, polyPickExt, &_filter, &ref, 0);

    if (!dtStatusSucceed(status) || ref == 0)
        return -1;

    const dtMeshTile* tile = 0;
    const dtPoly* poly = 0;
    if (dtStatusFailed(_navMesh->getTileAndPolyByRef(ref, &tile, &poly)))
        return -1;

    // Collect vertices.
    float verts[DT_VERTS_PER_POLYGON * 3];
    int nv = 0;
    for (unsigned char i = 0; i < poly->vertCount; ++i)
    {
        dtVcopy(&verts[nv * 3], &tile->verts[poly->verts[i] * 3]);
        nv++;
    }

    bool inside = PathGenerator::PointInPoly(pos, verts, nv, 0.05f);
    if (!inside)
        return -1;

    if (!dtStatusSucceed(_navMeshQuery->findDistanceToWall(ref, pos, 100.0f, &_filter, &distanceToWall, hitPos, hitNormal)))
        return -1;

    return distanceToWall;
}

void PathGenerator::SmoothPath(float* polyPickExt, int pathLength, float*& straightPath)
{
    float hitPos[3];
    float hitNormal[3];
    float testPos[3];
    float distanceToWall = 0;
    float up[]= { 0, 1, 0 };
    float origDis = 0;

    for (int i = 1; i < pathLength - 1; ++i)
    {
        dtPolyRef pt;
        float* curPoi = &straightPath[i * 3];
        distanceToWall = DistanceToWall(polyPickExt, curPoi, hitPos, hitNormal);

        if (distanceToWall < PathGenerator::MinWallDistance && distanceToWall >= 0)
        {
            float vec[3];
            dtVsub(vec, &straightPath[i * 3 - 3], &straightPath[i * 3]);
            // If distanceToWall is 0 means the point is in the edge, so we can't get the hitpos.
            if (distanceToWall == 0)
            {
                // Test the left side
                dtVcross(testPos, vec, up);
                dtVadd(testPos, testPos, curPoi);
                float ft = PathGenerator::MinWallDistance / dtVdist(testPos, curPoi);
                dtVlerp(testPos, curPoi, testPos, ft);
                distanceToWall = DistanceToWall(polyPickExt, testPos, hitPos, hitNormal);
                if (abs(PathGenerator::MinWallDistance - distanceToWall) > 0.1f)
                {
                    // Test the right side
                    dtVcross(testPos, up, vec);
                    dtVadd(testPos, testPos, curPoi);
                    ft = PathGenerator::MinWallDistance / dtVdist(testPos, curPoi);
                    dtVlerp(testPos, curPoi, testPos, ft);
                    distanceToWall = DistanceToWall(polyPickExt, testPos, hitPos, hitNormal);
                }

                // If the test point is better than the orig point, replace it.
                if (abs(distanceToWall - PathGenerator::MinWallDistance) < 0.1f)
                    dtVcopy(curPoi, testPos);
            }
            else
            {
                // We get the hitpos with a ray
                float ft = PathGenerator::MinWallDistance / distanceToWall;
                dtVlerp(testPos, hitPos, curPoi, ft);
                distanceToWall = DistanceToWall(polyPickExt, testPos, hitPos, hitNormal);

                if (abs(distanceToWall - PathGenerator::MinWallDistance) < 0.1f)
                    dtVcopy(curPoi, testPos);
            }
        }
    }
}
