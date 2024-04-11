/*
 * This file is part of the TrinityCore Project. See AUTHORS file for Copyright information
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

#ifndef _DYNTREE_H
#define _DYNTREE_H

#include "Define.h"
#include "Optional.h"

namespace G3D
{
    class Ray;
    class Vector3;
}

class GameObjectModel;
class PhaseShift;
struct DynTreeImpl;

namespace VMAP
{
    struct AreaAndLiquidData;
}

class TC_COMMON_API DynamicMapTree
{
    DynTreeImpl *impl;

public:

    DynamicMapTree();
    ~DynamicMapTree();

    bool isInLineOfSight(G3D::Vector3 const& startPos, G3D::Vector3 const& endPos, PhaseShift const& phaseShift) const;
    bool getIntersectionTime(G3D::Ray const& ray, G3D::Vector3 const& endPos, PhaseShift const& phaseShift, float& maxDist) const;
    bool getObjectHitPos(G3D::Vector3 const& startPos, G3D::Vector3 const& endPos, G3D::Vector3& resultHitPos, float modifyDist, PhaseShift const& phaseShift) const;

    float getHeight(float x, float y, float z, float maxSearchDist, PhaseShift const& phaseShift) const;
    bool getAreaAndLiquidData(float x, float y, float z, PhaseShift const& phaseShift, Optional<uint8> reqLiquidType, VMAP::AreaAndLiquidData& data) const;

    void insert(GameObjectModel const&);
    void remove(GameObjectModel const&);
    bool contains(GameObjectModel const&) const;

    void balance();
    void update(uint32 diff);
};

#endif // _DYNTREE_H
