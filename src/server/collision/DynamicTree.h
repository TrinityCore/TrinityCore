/*
 * Copyright (C) 2008-2013 TrinityCore <http://www.trinitycore.org/>
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

#include <G3D/Matrix3.h>
#include <G3D/Vector3.h>
#include <G3D/AABox.h>
#include <G3D/Ray.h>

//#include "ModelInstance.h"
#include "Define.h"
//#include "GameObjectModel.h"

namespace G3D
{
    class Vector3;
}

using G3D::Vector3;
class GameObjectModel;

class DynamicMapTree
{
    struct DynTreeImpl& impl;
public:

    DynamicMapTree();
    ~DynamicMapTree();

    bool isInLineOfSight(float x1, float y1, float z1, float x2, float y2, float z2, uint32 phasemask) const;
    bool getIntersectionTime(uint32 phasemask, const G3D::Ray& ray, const Vector3& endPos, float& maxDist) const;
    bool getObjectHitPos(uint32 phasemask, const Vector3& pPos1, const Vector3& pPos2, Vector3& pResultHitPos, float pModifyDist) const;
    float getHeight(float x, float y, float z, float maxSearchDist, uint32 phasemask) const;

    void insert(const GameObjectModel&);
    void remove(const GameObjectModel&);
    bool contains(const GameObjectModel&) const;
    int size() const;

    void balance();
    void update(uint32 diff);
};

#endif // _DYNTREE_H
