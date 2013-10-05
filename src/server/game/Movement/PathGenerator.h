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

#ifndef _PATH_GENERATOR_H
#define _PATH_GENERATOR_H

#include "SharedDefines.h"
#include "DetourNavMesh.h"
#include "DetourNavMeshQuery.h"
#include "MoveSplineInitArgs.h"

class Unit;

enum PathType
{
    PATHFIND_BLANK          = 0x00,   // path not built yet
    PATHFIND_NORMAL         = 0x01,   // normal path
    PATHFIND_SHORTCUT       = 0x02,   // travel through obstacles, terrain, air, etc (old behavior)
    PATHFIND_INCOMPLETE     = 0x04,   // we have partial path to follow - getting closer to target
    PATHFIND_NOPATH         = 0x08,   // no valid path at all or error in generating one
    PATHFIND_NOT_USING_PATH = 0x10,   // used when we are either flying/swiming or on map w/o mmaps
    PATHFIND_SHORT          = 0x20,   // path is longer or equal to its limited path length
};

enum PolyFlag
{
    POLY_FLAG_WALK  = 1,
    POLY_FLAG_SWIM  = 2
};

class PathGenerator
{
    public:
        explicit PathGenerator(Unit const* owner);
        ~PathGenerator();

        // Calculate the path from owner to given destination
        // return: true if new path was calculated, false otherwise (no change needed)
        bool CalculatePath(float destX, float destY, float destZ, bool forceDest = false);

        // result getters
        G3D::Vector3 const& GetStartPosition() const { return _startPosition; }
        G3D::Vector3 const& GetEndPosition() const { return _endPosition; }
        G3D::Vector3 const& GetActualEndPosition() const { return _actualEndPosition; }

        Movement::PointsArray const& GetPath() const { return _pathPoints; }

        PathType GetPathType() const { return _type; }

    private:
        Movement::PointsArray _pathPoints;  // our actual (x,y,z) path to the target
        PathType _type;                     // tells what kind of path this is

        G3D::Vector3 _startPosition;        // {x, y, z} of current location
        G3D::Vector3 _endPosition;          // {x, y, z} of the destination
        G3D::Vector3 _actualEndPosition;    // {x, y, z} of the closest possible point to given destination

        Unit const* const _sourceUnit;          // the unit that is moving
        dtNavMesh const* _navMesh;              // the nav mesh
        dtNavMeshQuery const* _navMeshQuery;    // the nav mesh query used to find the path

        dtQueryFilter _filter;  // use single filter for all movements, update it when needed

        void SetStartPosition(G3D::Vector3 const& point) { _startPosition = point; }
        void SetEndPosition(G3D::Vector3 const& point) { _actualEndPosition = point; _endPosition = point; }
        void SetActualEndPosition(G3D::Vector3 const& point) { _actualEndPosition = point; }

        void CreateFilter();
        void UpdateFilter();
};

#endif
