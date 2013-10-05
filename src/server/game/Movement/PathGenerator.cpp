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

////////////////// PathGenerator //////////////////
PathGenerator::PathGenerator(const Unit* owner) :
    _type(PATHFIND_BLANK), _endPosition(G3D::Vector3::zero()),
    _sourceUnit(owner), _navMesh(NULL), _navMeshQuery(NULL)
{
    TC_LOG_DEBUG(LOG_FILTER_MAPS, "PathGenerator::PathGenerator for %u \n", _sourceUnit->GetGUIDLow());

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
    TC_LOG_DEBUG(LOG_FILTER_MAPS, "PathGenerator::~PathGenerator() for %u \n", _sourceUnit->GetGUIDLow());
}

bool PathGenerator::CalculatePath(float destX, float destY, float destZ, bool forceDest)
{
    float x, y, z;
    _sourceUnit->GetPosition(x, y, z);

    if (!Trinity::IsValidMapCoord(destX, destY, destZ) || !Trinity::IsValidMapCoord(x, y, z))
        return false;

    G3D::Vector3 dest(destX, destY, destZ);
    SetEndPosition(dest);

    G3D::Vector3 start(x, y, z);
    SetStartPosition(start);

    TC_LOG_DEBUG(LOG_FILTER_MAPS, "PathGenerator::CalculatePath() for %u \n", _sourceUnit->GetGUIDLow());

    // make sure navMesh works - we can run on map w/o mmap
    // check if the start and end point have a .mmtile loaded (can we pass via not loaded tile on the way?)
    if (!_navMesh || !_navMeshQuery || _sourceUnit->HasUnitState(UNIT_STATE_IGNORE_PATHFINDING))
    {
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
        TC_LOG_DEBUG(LOG_FILTER_MAPS, "PathGenerator::CalculatePath() for %u no polygons found for start and end locations\n", _sourceUnit->GetGUIDLow());
        _type = PATHFIND_NOPATH;
        return false;
    }

    int hops;
    dtPolyRef* hopBuffer = new dtPolyRef[8192];
    dtStatus status = _navMeshQuery->findPath(startRef, endRef, startPos, endPos, &_filter, hopBuffer, &hops, 8192);
    
    if (!dtStatusSucceed(status))
    {
        TC_LOG_DEBUG(LOG_FILTER_MAPS, "PathGenerator::CalculatePath() for %u no path found for start and end locations\n", _sourceUnit->GetGUIDLow());
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
        TC_LOG_DEBUG(LOG_FILTER_MAPS, "PathGenerator::CalculatePath() for %u no straight path found for start and end locations\n", _sourceUnit->GetGUIDLow());
        _type = PATHFIND_NOPATH;
        return false;
    }

    for (uint32 i = 0; i < resultHopCount; ++i)
        _pathPoints.push_back(G3D::Vector3(-straightPath[i * 3 + 2], -straightPath[i * 3 + 0], straightPath[i * 3 + 1]));

    return true;
}

void PathGenerator::CreateFilter()
{
    uint16 includeFlags = 1 | 2;
    uint16 excludeFlags = 0;
    
    if (_sourceUnit->GetTypeId() == TYPEID_UNIT && !_sourceUnit->ToCreature()->CanSwim())
    {
        includeFlags = 1;
        excludeFlags = 2;
    }

    _filter.setIncludeFlags(includeFlags);
    _filter.setExcludeFlags(excludeFlags);

    UpdateFilter();
}

void PathGenerator::UpdateFilter()
{
    
}