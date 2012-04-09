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

#ifndef _PATH_INFO_H
#define _PATH_INFO_H

#include "SharedDefines.h"
#include "DetourNavMesh.h"
#include "DetourNavMeshQuery.h"
#include "MoveSplineInitArgs.h"

using Movement::Vector3;
using Movement::PointsArray;

class Unit;

// 74*4.0f=296y  number_of_points*interval = max_path_len
// this is way more than actual evade range
// I think we can safely cut those down even more
#define MAX_PATH_LENGTH         74
#define MAX_POINT_PATH_LENGTH   74

#define SMOOTH_PATH_STEP_SIZE   4.0f
#define SMOOTH_PATH_SLOP        0.3f

#define VERTEX_SIZE       3
#define INVALID_POLYREF   0

enum PathType
{
    PATHFIND_BLANK          = 0x0000,   // path not built yet
    PATHFIND_NORMAL         = 0x0001,   // normal path
    PATHFIND_SHORTCUT       = 0x0002,   // travel through obstacles, terrain, air, etc (old behavior)
    PATHFIND_INCOMPLETE     = 0x0004,   // we have partial path to follow - getting closer to target
    PATHFIND_NOPATH         = 0x0008,   // no valid path at all or error in generating one
    PATHFIND_NOT_USING_PATH = 0x0010    // used when we are either flying/swiming or on map w/o mmaps
};

class PathFinderMovementGenerator
{
    public:
        PathFinderMovementGenerator(Unit const* owner);
        ~PathFinderMovementGenerator();

        // Calculate the path from owner to given destination
        // return: true if new path was calculated, false otherwise (no change needed)
        bool calculate(float destX, float destY, float destZ, bool forceDest = false);

        // option setters - use optional
        void setUseStrightPath(bool useStraightPath) { m_useStraightPath = useStraightPath; };
        void setPathLengthLimit(float distance) { m_pointPathLimit = std::min<uint32>(uint32(distance/SMOOTH_PATH_STEP_SIZE), MAX_POINT_PATH_LENGTH); };

        // result getters
        Vector3 getStartPosition()      const { return m_startPosition; }
        Vector3 getEndPosition()        const { return m_endPosition; }
        Vector3 getActualEndPosition()  const { return m_actualEndPosition; }

        PointsArray& getPath() { return m_pathPoints; }
        PathType getPathType() const { return m_type; }

    private:

        dtPolyRef      m_pathPolyRefs[MAX_PATH_LENGTH];   // array of detour polygon references
        uint32         m_polyLength;                      // number of polygons in the path

        PointsArray    m_pathPoints;       // our actual (x,y,z) path to the target
        PathType       m_type;             // tells what kind of path this is

        bool           m_useStraightPath;  // type of path will be generated
        bool           m_forceDestination; // when set, we will always arrive at given point
        uint32         m_pointPathLimit;   // limit point path size; min(this, MAX_POINT_PATH_LENGTH)

        Vector3        m_startPosition;    // {x, y, z} of current location
        Vector3        m_endPosition;      // {x, y, z} of the destination
        Vector3        m_actualEndPosition;// {x, y, z} of the closest possible point to given destination

        const Unit* const       m_sourceUnit;       // the unit that is moving
        const dtNavMesh*        m_navMesh;          // the nav mesh
        const dtNavMeshQuery*   m_navMeshQuery;     // the nav mesh query used to find the path

        dtQueryFilter m_filter;                     // use single filter for all movements, update it when needed

        void setStartPosition(Vector3 point) { m_startPosition = point; }
        void setEndPosition(Vector3 point) { m_actualEndPosition = point; m_endPosition = point; }
        void setActualEndPosition(Vector3 point) { m_actualEndPosition = point; }

        void clear()
        {
            m_polyLength = 0;
            m_pathPoints.clear();
        }

        bool inRange(const Vector3 &p1, const Vector3 &p2, float r, float h) const;
        float dist3DSqr(const Vector3 &p1, const Vector3 &p2) const;
        bool inRangeYZX(const float* v1, const float* v2, float r, float h) const;

        dtPolyRef getPathPolyByPosition(const dtPolyRef *polyPath, uint32 polyPathSize, const float* point, float *distance = NULL) const;
        dtPolyRef getPolyByLocation(const float* point, float *distance) const;
        bool HaveTile(const Vector3 &p) const;

        void BuildPolyPath(const Vector3 &startPos, const Vector3 &endPos);
        void BuildPointPath(const float *startPoint, const float *endPoint);
        void BuildShortcut();

        NavTerrain getNavTerrain(float x, float y, float z);
        void createFilter();
        void updateFilter();

        // smooth path aux functions
        uint32 fixupCorridor(dtPolyRef* path, uint32 npath, uint32 maxPath,
                             const dtPolyRef* visited, uint32 nvisited);
        bool getSteerTarget(const float* startPos, const float* endPos, float minTargetDist,
                            const dtPolyRef* path, uint32 pathSize, float* steerPos,
                            unsigned char& steerPosFlag, dtPolyRef& steerPosRef);
        dtStatus findSmoothPath(const float* startPos, const float* endPos,
                              const dtPolyRef* polyPath, uint32 polyPathSize,
                              float* smoothPath, int* smoothPathSize, uint32 smoothPathMaxSize);
};

#endif
