/*
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

#ifndef MANGOS_PATH_FINDER_H
#define MANGOS_PATH_FINDER_H

#include "Path.h"
#include "MoveMapSharedDefines.h"
#include "../recastnavigation/Detour/Include/DetourNavMesh.h"
#include "../recastnavigation/Detour/Include/DetourNavMeshQuery.h"
#include "MoveSplineInitArgs.h"


using Movement::Vector3;
using Movement::PointsArray;

class Unit;
class GenericTransport;
struct GridMapLiquidData;

// 64*6.0f=384y  number_of_points*interval = max_path_len
// this is way more than actual evade range
// I think we can safely cut those down even more
#define MAX_PATH_LENGTH         256
#define MAX_POINT_PATH_LENGTH   256

#define VERTEX_SIZE       3
#define INVALID_POLYREF   0

enum PathType
{
    PATHFIND_BLANK          = 0x0000,   // path not built yet
    PATHFIND_NORMAL         = 0x0001,   // normal path
    PATHFIND_SHORTCUT       = 0x0002,   // travel through obstacles, terrain, air, etc (old behavior)
    PATHFIND_INCOMPLETE     = 0x0004,   // we have partial path to follow - getting closer to target
    PATHFIND_NOPATH         = 0x0008,   // no valid path at all or error in generating one
    PATHFIND_NOT_USING_PATH = 0x0010,   // used when we are either flying/swiming or on map w/o mmaps
    PATHFIND_DEST_FORCED    = 0x0020,   // NOSTALRIUS: forced destination
    PATHFIND_FLYPATH        = 0x0040,
    PATHFIND_UNDERWATER     = 0x0080,
    PATHFIND_CASTER         = 0x0100,
};

class PathInfo
{
    public:
        PathInfo(Unit const* owner);
        ~PathInfo();

        // return value : true if new path was calculated
        bool calculate(float destX, float destY, float destZ, bool forceDest = false, bool offsets = false);
        bool calculate(Vector3 const& start, Vector3 dest, bool forceDest = false, bool offsets = false);

        void setUseStrightPath(bool useStraightPath) { m_useStraightPath = useStraightPath; };
        void setPathLengthLimit(float distance);

        inline void getStartPosition(float &x, float &y, float &z) { x = m_startPosition.x; y = m_startPosition.y; z = m_startPosition.z; }
        inline void getEndPosition(float &x, float &y, float &z) { x = m_endPosition.x; y = m_endPosition.y; z = m_endPosition.z; }
        inline void getActualEndPosition(float &x, float &y, float &z) { x = m_actualEndPosition.x; y = m_actualEndPosition.y; z = m_actualEndPosition.z; }

        inline Vector3 getStartPosition() const { return m_startPosition; }
        inline Vector3 getEndPosition() const { return m_endPosition; }
        inline Vector3 getActualEndPosition() const { return m_actualEndPosition; }

        inline PointsArray& getFullPath() { return m_pathPoints; }
        inline PointsArray const& getPath() const { return m_pathPoints; }
        inline PathType getPathType() const { return PathType(m_type); }
        // Nostalrius
        bool UpdateForCaster(Unit* pTarget, float castRange);
        bool UpdateForMelee(Unit* pTarget, float meleeReach);
        void CutPathWithDynamicLoS();
        float Length() const;
        void ExcludeSteepSlopes() { m_filter.setExcludeFlags(NAV_STEEP_SLOPES); }
        static dtPolyRef FindWalkPoly(dtNavMeshQuery const* query, float const* pointYZX, dtQueryFilter const& filter, float* closestPointYZX, float zSearchDist = 10.0f);
        void SetTransport(GenericTransport* t) { m_transport = t; }
        GenericTransport* GetTransport() const { return m_transport; }
        void FillTargetAllowedFlags(Unit* target);
    private:

        dtPolyRef       m_pathPolyRefs[MAX_PATH_LENGTH];   // array of detour polygon references
        uint32          m_polyLength;                      // number of polygons in the path

        PointsArray     m_pathPoints;       // our actual (x,y,z) path to the target
        uint32          m_type;             // tells what kind of path this is

        bool           m_useStraightPath;  // type of path will be generated
        bool           m_forceDestination; // when set, we will always arrive at given point
        uint32         m_pointPathLimit;   // limit point path size; min(this, MAX_POINT_PATH_LENGTH)

        Vector3        m_startPosition;    // {x, y, z} of current location
        Vector3        m_endPosition;      // {x, y, z} of the destination
        Vector3        m_actualEndPosition;  // {x, y, z} of the closest possible point to given destination
        GenericTransport*       m_transport;
        Unit const* const       m_sourceUnit;       // the unit that is moving
        dtNavMesh const*        m_navMesh;          // the nav mesh
        dtNavMeshQuery const*   m_navMeshQuery;     // the nav mesh query used to find the path
        uint32          m_targetAllowedFlags;

        dtQueryFilter m_filter;                     // use single filter for all movements, update it when needed

        inline void setStartPosition(Vector3 const& point) { m_startPosition = point; }
        inline void setEndPosition(Vector3 const& point) { m_actualEndPosition = point; m_endPosition = point; }
        inline void setActualEndPosition(Vector3 const& point) { m_actualEndPosition = point; }

        inline void clear()
        {
            m_polyLength = 0;
            m_pathPoints.clear();
        }
        static bool inRange(Vector3 const& p1, Vector3 const& p2, float r, float h);
        static float dist3DSqr(Vector3 const& p1, Vector3 const& p2);
        static bool inRangeYZX(float const* v1, float const* v2, float r, float h);

        dtPolyRef getPolyByLocation(float const* point, float *distance, uint32 flags = 0);
        bool HaveTiles(Vector3 const& p) const;

        void BuildPolyPath(Vector3 const& startPos, Vector3 const& endPos);
        void BuildPointPath(float const* startPoint, float const* endPoint, float distToStartPoly, float distToEndPoly);
        void BuildShortcut();
        void BuildUnderwaterPath();

        void createFilter();
        void updateFilter();

        // smooth path functions
        static uint32 fixupCorridor(dtPolyRef* path, uint32 const npath, uint32 const maxPath,
                                    dtPolyRef const* visited, uint32 const nvisited);
        bool getSteerTarget(float const* startPos, float const* endPos, float const minTargetDist,
                            dtPolyRef const* path, uint32 const pathSize, float* steerPos,
                            unsigned char& steerPosFlag, dtPolyRef& steerPosRef) const;
        dtStatus findSmoothPath(float const* startPos, float const* endPos,
                                dtPolyRef const* polyPath, uint32 polyPathSize,
                                float* smoothPath, int* smoothPathSize, uint32 maxSmoothPathSize);
};

typedef PathInfo PathFinder;

#endif
