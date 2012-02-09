/*
 * Copyright (C) 2008-2012 TrinityCore <http://www.trinitycore.org/>
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

#include "DynamicTree.h"
//#include "QuadTree.h"
//#include "RegularGrid.h"
#include "BoundingIntervalHierarchyWrapper.h"

#include "Log.h"
#include "RegularGrid.h"
#include "Timer.h"
#include "GameObjectModel.h"
#include "ModelInstance.h"

using VMAP::ModelInstance;
using G3D::Ray;

template<> struct HashTrait< GameObjectModel>{
    static size_t hashCode(const GameObjectModel& g) { return (size_t)(void*)&g; }
};

template<> struct PositionTrait< GameObjectModel> {
    static void getPosition(const GameObjectModel& g, Vector3& p) { p = g.getPosition(); }
};

template<> struct BoundsTrait< GameObjectModel> {
    static void getBounds(const GameObjectModel& g, G3D::AABox& out) { out = g.getBounds();}
    static void getBounds2(const GameObjectModel* g, G3D::AABox& out) { out = g->getBounds();}
};

static bool operator == (const GameObjectModel& mdl, const GameObjectModel& mdl2){
    return &mdl == &mdl2;
}


int valuesPerNode = 5, numMeanSplits = 3;

int UNBALANCED_TIMES_LIMIT = 5;
int CHECK_TREE_PERIOD = 200;

typedef RegularGrid2D<GameObjectModel, BIHWrap<GameObjectModel> > ParentTree;

struct DynTreeImpl : public ParentTree/*, public Intersectable*/
{
    typedef GameObjectModel Model;
    typedef ParentTree base;

    DynTreeImpl() :
        rebalance_timer(CHECK_TREE_PERIOD),
        unbalanced_times(0)
    {
    }

    void insert(const Model& mdl)
    {
        base::insert(mdl);
        ++unbalanced_times;
    }

    void remove(const Model& mdl)
    {
        base::remove(mdl);
        ++unbalanced_times;
    }

    void balance()
    {
        base::balance();
        unbalanced_times = 0;
    }

    void update(uint32 difftime)
    {
        if (!size())
            return;

        rebalance_timer.Update(difftime);
        if (rebalance_timer.Passed())
        {
            rebalance_timer.Reset(CHECK_TREE_PERIOD);
            if (unbalanced_times > 0)
                balance();
        }
    }

    TimeTrackerSmall rebalance_timer;
    int unbalanced_times;
};

DynamicMapTree::DynamicMapTree() : impl(*new DynTreeImpl())
{
}

DynamicMapTree::~DynamicMapTree()
{
    delete &impl;
}

void DynamicMapTree::insert(const GameObjectModel& mdl)
{
    impl.insert(mdl);
}

void DynamicMapTree::remove(const GameObjectModel& mdl)
{
    impl.remove(mdl);
}

bool DynamicMapTree::contains(const GameObjectModel& mdl) const
{
    return impl.contains(mdl);
}

void DynamicMapTree::balance()
{
    impl.balance();
}

int DynamicMapTree::size() const
{
    return impl.size();
}

void DynamicMapTree::update(uint32 t_diff)
{
    impl.update(t_diff);
}

struct DynamicTreeIntersectionCallback
{
    bool did_hit;
    uint32 phase_mask;
    DynamicTreeIntersectionCallback(uint32 phasemask) : did_hit(false), phase_mask(phasemask) {}
    bool operator()(const Ray& r, const GameObjectModel& obj, float& distance)
    {
        did_hit = obj.intersectRay(r, distance, true, phase_mask);
        return did_hit;
    }
    bool didHit() const { return did_hit;}
};

struct DynamicTreeIntersectionCallback_WithLogger
{
    bool did_hit;
    uint32 phase_mask;
    DynamicTreeIntersectionCallback_WithLogger(uint32 phasemask) : did_hit(false), phase_mask(phasemask)
    {
        sLog->outDebug(LOG_FILTER_MAPS, "Dynamic Intersection log");
    }
    bool operator()(const Ray& r, const GameObjectModel& obj, float& distance)
    {
        sLog->outDebug(LOG_FILTER_MAPS, "testing intersection with %s", obj.name.c_str());
        bool hit = obj.intersectRay(r, distance, true, phase_mask);
        if (hit)
        {
            did_hit = true;
            sLog->outDebug(LOG_FILTER_MAPS, "result: intersects");
        }
        return hit;
    }
    bool didHit() const { return did_hit;}
};

bool DynamicMapTree::isInLineOfSight(float x1, float y1, float z1, float x2, float y2, float z2, uint32 phasemask) const
{
    Vector3 v1(x1,y1,z1), v2(x2,y2,z2);

    float maxDist = (v2 - v1).magnitude();

    if (!G3D::fuzzyGt(maxDist, 0) )
        return true;

    Ray r(v1, (v2-v1) / maxDist);
    DynamicTreeIntersectionCallback callback(phasemask);
    impl.intersectRay(r, callback, maxDist, v2);

    return !callback.did_hit;
}

float DynamicMapTree::getHeight(float x, float y, float z, float maxSearchDist, uint32 phasemask) const
{
    Vector3 v(x,y,z);
    Ray r(v, Vector3(0,0,-1));
    DynamicTreeIntersectionCallback callback(phasemask);
    impl.intersectZAllignedRay(r, callback, maxSearchDist);

    if (callback.didHit())
        return v.z - maxSearchDist;
    else
        return -G3D::inf();
}