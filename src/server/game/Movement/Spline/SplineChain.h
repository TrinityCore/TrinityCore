/*
* Copyright (C) 2008-2018 TrinityCore <https://www.trinitycore.org/>
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

#ifndef TRINITY_SPLINECHAIN_H
#define TRINITY_SPLINECHAIN_H

#include "MoveSplineInitArgs.h"
#include <G3D/Vector3.h>

struct TC_GAME_API SplineChainLink
{
    SplineChainLink(Movement::PointsArray const& points, uint32 expectedDuration, uint32 msToNext) : Points(points), ExpectedDuration(expectedDuration), TimeToNext(msToNext) { }
    template <typename iteratorType> SplineChainLink(iteratorType begin, iteratorType end, uint32 expectedDuration, uint32 msToNext) : Points(begin, end), ExpectedDuration(expectedDuration), TimeToNext(msToNext) { }
    SplineChainLink(uint32 expectedDuration, uint32 msToNext) : Points(), ExpectedDuration(expectedDuration), TimeToNext(msToNext) { }
    Movement::PointsArray Points;
    uint32 ExpectedDuration;
    uint32 TimeToNext;
};

struct TC_GAME_API SplineChainResumeInfo
{
    SplineChainResumeInfo() : PointID(0), Chain(nullptr), IsWalkMode(false), SplineIndex(0), PointIndex(0), TimeToNext(0) { }
    SplineChainResumeInfo(uint32 id, std::vector<SplineChainLink> const* chain, bool walk, uint8 splineIndex, uint8 wpIndex, uint32 msToNext) :
        PointID(id), Chain(chain), IsWalkMode(walk), SplineIndex(splineIndex), PointIndex(wpIndex), TimeToNext(msToNext) { }
    bool Empty() const { return Chain == nullptr; }
    void Clear() { Chain = nullptr; }
    uint32 PointID;
    std::vector<SplineChainLink> const* Chain;
    bool IsWalkMode;
    uint8 SplineIndex;
    uint8 PointIndex;
    uint32 TimeToNext;
};

#endif
