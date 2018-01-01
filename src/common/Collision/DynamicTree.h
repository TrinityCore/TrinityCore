/*
 * Copyright (C) 2008-2018 TrinityCore <https://www.trinitycore.org/>
 * Copyright (C) 2005-2009 MaNGOS <http://getmangos.com/>
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
#include <set>

namespace G3D
{
    class Ray;
    class Vector3;
}

class GameObjectModel;
struct DynTreeImpl;

class TC_COMMON_API DynamicMapTree
{
    DynTreeImpl *impl;

public:

    DynamicMapTree();
    ~DynamicMapTree();

    bool isInLineOfSight(G3D::Vector3 const& startPos, G3D::Vector3 const& endPos, std::set<uint32> const& phases) const;
    bool getIntersectionTime(std::set<uint32> const& phases, G3D::Ray const& ray, G3D::Vector3 const& endPos, float& maxDist) const;
    bool getObjectHitPos(std::set<uint32> const& phases, G3D::Vector3 const& startPos, G3D::Vector3 const& endPos, G3D::Vector3& resultHitPos, float modifyDist) const;

    float getHeight(float x, float y, float z, float maxSearchDist, std::set<uint32> const& phases) const;

    void insert(const GameObjectModel&);
    void remove(const GameObjectModel&);
    bool contains(const GameObjectModel&) const;
    int size() const;

    void balance();
    void update(uint32 diff);
};

#endif // _DYNTREE_H
