/*
 * Copyright (C) 2008-2013 TrinityCore <http://www.trinitycore.org/>
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; either version 2 of the License, or (at your
 * option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program. If not, see <http://www.gnu.org/licenses/>.
 */

/**
* @file cs_mmaps.cpp
* @brief .mmap related commands
*
* This file contains the CommandScripts for all
* mmap sub-commands
*/

#include "ScriptMgr.h"
#include "Chat.h"
#include "ObjectMgr.h"
#include "Player.h"
#include "PointMovementGenerator.h"
#include "PathGenerator.h"
#include "MMapFactory.h"
#include "DetourCommon.h"
#include "Map.h"
#include "TargetedMovementGenerator.h"
#include "GridNotifiers.h"
#include "GridNotifiersImpl.h"
#include "CellImpl.h"
#include "MMapManager.h"

class mmaps_commandscript : public CommandScript
{
public:
    mmaps_commandscript() : CommandScript("mmaps_commandscript") { }

    ChatCommand* GetCommands() const OVERRIDE
    {
        static ChatCommand mmapCommandTable[] =
        {
            { "loadedtiles", rbac::RBAC_PERM_COMMAND_MMAP_LOADEDTILES, false, &HandleMmapLoadedTilesCommand, "", NULL },
            { "loc",         rbac::RBAC_PERM_COMMAND_MMAP_LOC,         false, &HandleMmapLocCommand,         "", NULL },
            { "path",        rbac::RBAC_PERM_COMMAND_MMAP_PATH,        false, &HandleMmapPathCommand,        "", NULL },
            { "stats",       rbac::RBAC_PERM_COMMAND_MMAP_STATS,       false, &HandleMmapStatsCommand,       "", NULL },
            { "testarea",    rbac::RBAC_PERM_COMMAND_MMAP_TESTAREA,    false, &HandleMmapTestArea,           "", NULL },
            { NULL,          0,                                  false, NULL,                          "", NULL }
        };

        static ChatCommand commandTable[] =
        {
            { "mmap", rbac::RBAC_PERM_COMMAND_MMAP, true, NULL, "", mmapCommandTable  },
            { NULL,   0,                     false, NULL, "", NULL }
        };
        return commandTable;
    }

    static float Fix_GetXZArea(float* verts, int nv)
    {
        float area = 0;
        for(int i=0; i<nv-1; i++)
            area+=(verts[i*3]*verts[i*3+5]-verts[i*3+3]*verts[i*3+2]);
        area += (verts[(nv-1)*3]*verts[2] - verts[0]*verts[(nv-1)*3+2]);
        return area*0.5f;
    }


    //dtPointInPolygon will return false when the point is too close to the edge,so we rewite the test function.
    static bool Fix_PointIsInPoly(float* pos,float* verts,int nv,float err)
    {
        //poly area
        float area = abs(Fix_GetXZArea(verts,nv));

        //calculate each area of triangles
        float TestTri[9];
        memcpy(TestTri,pos,sizeof(float)*3);
        float area1 = 0;
        for(int i=0;i<nv-1;++i)
        {
            memcpy(&TestTri[3],&verts[i*3],sizeof(float)*3);
            memcpy(&TestTri[6],&verts[i*3+3],sizeof(float)*3);
            area1+= abs(Fix_GetXZArea(TestTri,3));
            if(area1-err>area)
                return false;
        }

        //last one
        memcpy(&TestTri[3],verts,sizeof(float)*3);
        memcpy(&TestTri[6],&verts[nv*3-3],sizeof(float)*3);
        area1+= abs(Fix_GetXZArea(TestTri,3));

        return abs(area1-area)<err;
    }


    static float DistanceToWall(dtNavMeshQuery* navQuery, dtNavMesh* navMesh, float* polyPickExt, dtQueryFilter& filter, float* pos,float* hitPos,float* hitNormal)
    {
        float distanceToWall=0;
        dtPolyRef ref;
        if(dtStatusSucceed(navQuery->findNearestPoly(pos, polyPickExt, &filter, &ref, 0))==false || ref ==0)
            return -1;

        const dtMeshTile* tile = 0;
        const dtPoly* poly = 0;
        if (dtStatusFailed(navMesh->getTileAndPolyByRef(ref, &tile, &poly)))
            return -1;

        // Collect vertices.
        float verts[DT_VERTS_PER_POLYGON*3];
        int nv = 0;
        for (int i = 0; i < (int)poly->vertCount; ++i)
        {
            dtVcopy(&verts[nv*3], &tile->verts[poly->verts[i]*3]);
            nv++;
        }		

        bool inside = Fix_PointIsInPoly(pos, verts, nv,0.05f);
        if(inside == false)
            return -1;

        if(dtStatusSucceed(navQuery->findDistanceToWall(ref, pos, 100.0f, &filter, &distanceToWall, hitPos, hitNormal))==false)
            return -1;

        return distanceToWall;
    }

    #define MIN_WALL_DISTANCE 1.5f    //set this value bigger to make the path point far way from wall

    //Try to fix the path,
    static void FixPath(dtNavMesh* navMesh, dtNavMeshQuery* navQuery, float* polyPickExt, dtQueryFilter& filter, int pathLength, float*& straightPath)
    {
        float hitPos[3];
        float hitNormal[3];
        float TestPos[3];
        float distanceToWall=0;
        float up[3]={0,1,0};
        float origDis = 0;

        for(int i=1;i<pathLength-1;++i)
        {
            dtPolyRef pt;
            float* pCurPoi=&straightPath[i*3];
            distanceToWall = DistanceToWall(navQuery, navMesh, polyPickExt, filter, pCurPoi,hitPos,hitNormal);

            if(distanceToWall<MIN_WALL_DISTANCE && distanceToWall>=0)
            {
                float vec[3];
                dtVsub(vec,&straightPath[i*3-3],&straightPath[i*3]);
                //distanceToWall is 0 means the point is in the edge.so we can't get the hitpos.
                if(distanceToWall == 0)
                {
                    //test left side
                    dtVcross(TestPos,vec,up);
                    dtVadd(TestPos,TestPos,pCurPoi);
                    float ft = MIN_WALL_DISTANCE/dtVdist(TestPos,pCurPoi);
                    dtVlerp(TestPos,pCurPoi,TestPos,ft);
                    distanceToWall = DistanceToWall(navQuery, navMesh, polyPickExt, filter,TestPos,hitPos,hitNormal);
                    if(abs(MIN_WALL_DISTANCE - distanceToWall)>0.1f)
                    {
                        //test right side
                        dtVcross(TestPos,up,vec);
                        dtVadd(TestPos,TestPos,pCurPoi);
                        ft = MIN_WALL_DISTANCE/dtVdist(TestPos,pCurPoi);
                        dtVlerp(TestPos,pCurPoi,TestPos,ft);
                        distanceToWall = DistanceToWall(navQuery, navMesh, polyPickExt, filter,TestPos,hitPos,hitNormal);
                    }

                    //if test point is better than the orig point,replace it.
                    if(abs(distanceToWall-MIN_WALL_DISTANCE)<0.1f)
                        dtVcopy(pCurPoi,TestPos);
                }
                else
                {
                    //ok,we get the hitpos,just make a ray
                    float ft = MIN_WALL_DISTANCE/distanceToWall;
                    dtVlerp(TestPos,hitPos,pCurPoi,ft);
                    distanceToWall = DistanceToWall(navQuery, navMesh, polyPickExt, filter, TestPos,hitPos,hitNormal);

                    if(abs(distanceToWall-MIN_WALL_DISTANCE)<0.1f)
                        dtVcopy(pCurPoi,TestPos);
                }
            }
        }
    }

    static bool HandleMmapPathCommand(ChatHandler* handler, char const* args)
    {
        if (!MMAP::MMapFactory::CreateOrGetMMapManager()->GetNavMesh(handler->GetSession()->GetPlayer()->GetMapId()))
        {
            handler->PSendSysMessage("NavMesh not loaded for current map.");
            return true;
        }

        handler->PSendSysMessage("mmap path:");

        // units
        Player* player = handler->GetSession()->GetPlayer();
        Unit* target = handler->getSelectedUnit();
        if (!player || !target)
        {
            handler->PSendSysMessage("Invalid target/source selection.");
            return true;
        }

        char* para = strtok((char*)args, " ");

        bool useStraightPath = false;
        if (para && strcmp(para, "true") == 0)
            useStraightPath = true;

        // unit locations
        float x, y, z;
        player->GetPosition(x, y, z);

        // path
        /*PathGenerator path(target);
        path.SetUseStraightPath(useStraightPath);
        bool result = path.CalculatePath(x, y, z);
        
        Movement::PointsArray const& pointPath = path.GetPath();
        handler->PSendSysMessage("%s's path to %s:", target->GetName().c_str(), player->GetName().c_str());
        handler->PSendSysMessage("Building: %s", useStraightPath ? "StraightPath" : "SmoothPath");
        handler->PSendSysMessage("Result: %s - Length: " SIZEFMTD " - Type: %u", (result ? "true" : "false"), pointPath.size(), path.GetPathType());

        G3D::Vector3 const &start = path.GetStartPosition();
        G3D::Vector3 const &end = path.GetEndPosition();
        G3D::Vector3 const &actualEnd = path.GetActualEndPosition();

        handler->PSendSysMessage("StartPosition     (%.3f, %.3f, %.3f)", start.x, start.y, start.z);
        handler->PSendSysMessage("EndPosition       (%.3f, %.3f, %.3f)", end.x, end.y, end.z);
        handler->PSendSysMessage("ActualEndPosition (%.3f, %.3f, %.3f)", actualEnd.x, actualEnd.y, actualEnd.z);
        */
        float m_spos[3];
        m_spos[0] = -y;
        m_spos[1] = z;
        m_spos[2] = -x;

        //
        float m_epos[3];
        m_epos[0] = -target->GetPositionY();
        m_epos[1] = target->GetPositionZ();
        m_epos[2] = -target->GetPositionX();

        //
        dtQueryFilter m_filter;
        m_filter.setIncludeFlags(3);
        m_filter.setExcludeFlags(2);

        //
        float m_polyPickExt[3];
        m_polyPickExt[0] = 2.5f;
        m_polyPickExt[1] = 2.5f;
        m_polyPickExt[2] = 2.5f;

        //
        dtPolyRef m_startRef;
        dtPolyRef m_endRef;

        const dtNavMesh* navMesh = MMAP::MMapFactory::CreateOrGetMMapManager()->GetNavMesh(player->GetMapId());
        const dtNavMeshQuery* navMeshQuery = MMAP::MMapFactory::CreateOrGetMMapManager()->GetNavMeshQuery(player->GetMapId(), handler->GetSession()->GetPlayer()->GetInstanceId());

        float nearestPt[3];

        navMeshQuery->findNearestPoly(m_spos, m_polyPickExt, &m_filter, &m_startRef, nearestPt);
        navMeshQuery->findNearestPoly(m_epos, m_polyPickExt, &m_filter, &m_endRef, nearestPt);

        if ( !m_startRef || !m_endRef )
        {
            std::cerr << "Could not find any nearby poly's (" << m_startRef << "," << m_endRef << ")" << std::endl;
            return 0;
        }

        int hops;
        dtPolyRef* hopBuffer = new dtPolyRef[8192];
        dtStatus status = navMeshQuery->findPath(m_startRef, m_endRef, m_spos, m_epos, &m_filter, hopBuffer, &hops, 8192);

        int resultHopCount;
        float* straightPath = new float[2048*3];
        unsigned char* pathFlags = new unsigned char[2048];
        dtPolyRef* pathRefs = new dtPolyRef[2048];

        status = navMeshQuery->findStraightPath(m_spos, m_epos, hopBuffer, hops, straightPath, pathFlags, pathRefs, &resultHopCount, 2048);
        FixPath(const_cast<dtNavMesh*>(navMesh), const_cast<dtNavMeshQuery*>(navMeshQuery), m_polyPickExt, m_filter, resultHopCount, straightPath);
        for (uint32 i = 0; i < resultHopCount; ++i)
            player->SummonCreature(VISUAL_WAYPOINT, -straightPath[i * 3 + 2], -straightPath[i * 3 + 0], straightPath[i * 3 + 1], 0, TEMPSUMMON_TIMED_DESPAWN, 9000);

        if (!player->IsGameMaster())
            handler->PSendSysMessage("Enable GM mode to see the path points.");

        return true;
    }

    static bool HandleMmapLocCommand(ChatHandler* handler, char const* /*args*/)
    {
        handler->PSendSysMessage("mmap tileloc:");

        // grid tile location
        Player* player = handler->GetSession()->GetPlayer();

        int32 gx = 32 - player->GetPositionX() / SIZE_OF_GRIDS;
        int32 gy = 32 - player->GetPositionY() / SIZE_OF_GRIDS;

        handler->PSendSysMessage("%03u%02i%02i.mmtile", player->GetMapId(), gy, gx);
        handler->PSendSysMessage("gridloc [%i, %i]", gx, gy);

        // calculate navmesh tile location
        dtNavMesh const* navmesh = MMAP::MMapFactory::CreateOrGetMMapManager()->GetNavMesh(handler->GetSession()->GetPlayer()->GetMapId());
        dtNavMeshQuery const* navmeshquery = MMAP::MMapFactory::CreateOrGetMMapManager()->GetNavMeshQuery(handler->GetSession()->GetPlayer()->GetMapId(), player->GetInstanceId());
        if (!navmesh || !navmeshquery)
        {
            handler->PSendSysMessage("NavMesh not loaded for current map.");
            return true;
        }

        float const* min = navmesh->getParams()->orig;
        float x, y, z;
        player->GetPosition(x, y, z);
        float location[] = {y, z, x};
        float extents[] = {3.0f, 5.0f, 3.0f};

        int32 tilex = int32((y - min[0]) / SIZE_OF_GRIDS);
        int32 tiley = int32((x - min[2]) / SIZE_OF_GRIDS);

        handler->PSendSysMessage("Calc   [%02i, %02i]", tilex, tiley);

        // navmesh poly -> navmesh tile location
        dtQueryFilter filter = dtQueryFilter();
        dtPolyRef polyRef = 0;
        if (dtStatusFailed(navmeshquery->findNearestPoly(location, extents, &filter, &polyRef, NULL)))
        {
            handler->PSendSysMessage("Dt     [??,??] (invalid poly, probably no tile loaded)");
            return true;
        }

        if (polyRef == 0)
            handler->PSendSysMessage("Dt     [??, ??] (invalid poly, probably no tile loaded)");
        else
        {
            dtMeshTile const* tile;
            dtPoly const* poly;
            if (dtStatusSucceed(navmesh->getTileAndPolyByRef(polyRef, &tile, &poly)))
            {
                if (tile)
                {
                    handler->PSendSysMessage("Dt     [%02i,%02i]", tile->header->x, tile->header->y);
                    return false;
                }
            }

            handler->PSendSysMessage("Dt     [??,??] (no tile loaded)");
        }

        return true;
    }

    static bool HandleMmapLoadedTilesCommand(ChatHandler* handler, char const* /*args*/)
    {
        uint32 mapid = handler->GetSession()->GetPlayer()->GetMapId();
        dtNavMesh const* navmesh = MMAP::MMapFactory::CreateOrGetMMapManager()->GetNavMesh(mapid);
        dtNavMeshQuery const* navmeshquery = MMAP::MMapFactory::CreateOrGetMMapManager()->GetNavMeshQuery(mapid, handler->GetSession()->GetPlayer()->GetInstanceId());
        if (!navmesh || !navmeshquery)
        {
            handler->PSendSysMessage("NavMesh not loaded for current map.");
            return true;
        }

        handler->PSendSysMessage("mmap loadedtiles:");

        for (int32 i = 0; i < navmesh->getMaxTiles(); ++i)
        {
            dtMeshTile const* tile = navmesh->getTile(i);
            if (!tile || !tile->header)
                continue;

            handler->PSendSysMessage("[%02i, %02i]", tile->header->x, tile->header->y);
        }

        return true;
    }

    static bool HandleMmapStatsCommand(ChatHandler* handler, char const* /*args*/)
    {
        uint32 mapId = handler->GetSession()->GetPlayer()->GetMapId();
        handler->PSendSysMessage("mmap stats:");
        handler->PSendSysMessage("  global mmap pathfinding is %sabled", MMAP::MMapFactory::IsPathfindingEnabled(mapId) ? "en" : "dis");

        MMAP::MMapManager* manager = MMAP::MMapFactory::CreateOrGetMMapManager();
        handler->PSendSysMessage(" %u maps loaded with %u tiles overall", manager->GetLoadedMapsCount(), manager->GetLoadedTilesCount());

        dtNavMesh const* navmesh = manager->GetNavMesh(handler->GetSession()->GetPlayer()->GetMapId());
        if (!navmesh)
        {
            handler->PSendSysMessage("NavMesh not loaded for current map.");
            return true;
        }

        uint32 tileCount = 0;
        uint32 nodeCount = 0;
        uint32 polyCount = 0;
        uint32 vertCount = 0;
        uint32 triCount = 0;
        uint32 triVertCount = 0;
        uint32 dataSize = 0;
        for (int32 i = 0; i < navmesh->getMaxTiles(); ++i)
        {
            dtMeshTile const* tile = navmesh->getTile(i);
            if (!tile || !tile->header)
                continue;

            tileCount++;
            nodeCount += tile->header->bvNodeCount;
            polyCount += tile->header->polyCount;
            vertCount += tile->header->vertCount;
            triCount += tile->header->detailTriCount;
            triVertCount += tile->header->detailVertCount;
            dataSize += tile->dataSize;
        }

        handler->PSendSysMessage("Navmesh stats:");
        handler->PSendSysMessage(" %u tiles loaded", tileCount);
        handler->PSendSysMessage(" %u BVTree nodes", nodeCount);
        handler->PSendSysMessage(" %u polygons (%u vertices)", polyCount, vertCount);
        handler->PSendSysMessage(" %u triangles (%u vertices)", triCount, triVertCount);
        handler->PSendSysMessage(" %.2f MB of data (not including pointers)", ((float)dataSize / sizeof(unsigned char)) / 1048576);

        return true;
    }

    static bool HandleMmapTestArea(ChatHandler* handler, char const* /*args*/)
    {
        float radius = 40.0f;
        WorldObject* object = handler->GetSession()->GetPlayer();

        CellCoord pair(Trinity::ComputeCellCoord(object->GetPositionX(), object->GetPositionY()));
        Cell cell(pair);
        cell.SetNoCreate();

        std::list<Creature*> creatureList;

        Trinity::AnyUnitInObjectRangeCheck go_check(object, radius);
        Trinity::CreatureListSearcher<Trinity::AnyUnitInObjectRangeCheck> go_search(object, creatureList, go_check);
        TypeContainerVisitor<Trinity::CreatureListSearcher<Trinity::AnyUnitInObjectRangeCheck>, GridTypeMapContainer> go_visit(go_search);

        // Get Creatures
        cell.Visit(pair, go_visit, *(object->GetMap()), *object, radius);

        if (!creatureList.empty())
        {
            handler->PSendSysMessage("Found " SIZEFMTD " Creatures.", creatureList.size());

            uint32 paths = 0;
            uint32 uStartTime = getMSTime();

            float gx, gy, gz;
            object->GetPosition(gx, gy, gz);
            for (std::list<Creature*>::iterator itr = creatureList.begin(); itr != creatureList.end(); ++itr)
            {
                PathGenerator path(*itr);
                path.CalculatePath(gx, gy, gz);
                ++paths;
            }

            uint32 uPathLoadTime = getMSTimeDiff(uStartTime, getMSTime());
            handler->PSendSysMessage("Generated %i paths in %i ms", paths, uPathLoadTime);
        }
        else
            handler->PSendSysMessage("No creatures in %f yard range.", radius);

        return true;
    }
};

void AddSC_mmaps_commandscript()
{
    new mmaps_commandscript();
}
