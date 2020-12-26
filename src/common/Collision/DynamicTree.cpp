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

#include "DynamicTree.h"
#include "BoundingIntervalHierarchyWrapper.h"
#include "GameObjectModel.h"
#include "Log.h"
#include "MapTree.h"
#include "ModelIgnoreFlags.h"
#include "ModelInstance.h"
#include "RegularGrid.h"
#include "Timer.h"
#include "VMapFactory.h"
#include "VMapManager2.h"
#include "WorldModel.h"
#include <G3D/AABox.h>
#include <G3D/Ray.h>
#include <G3D/Vector3.h>

using VMAP::ModelInstance;

namespace {

int CHECK_TREE_PERIOD = 200;

} // namespace

template<> struct HashTrait< GameObjectModel>{
    static size_t hashCode(GameObjectModel const& g) { return (size_t)(void*)&g; }
};

template<> struct PositionTrait< GameObjectModel> {
    static void getPosition(GameObjectModel const& g, G3D::Vector3& p) { p = g.getPosition(); }
};

template<> struct BoundsTrait< GameObjectModel> {
    static void getBounds(GameObjectModel const& g, G3D::AABox& out) { out = g.getBounds();}
    static void getBounds2(GameObjectModel const* g, G3D::AABox& out) { out = g->getBounds();}
};

/*
static bool operator==(GameObjectModel const& mdl, GameObjectModel const& mdl2){
    return &mdl == &mdl2;
}
*/

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

    void insert(Model const& mdl)
    {
        base::insert(mdl);
        ++unbalanced_times;
    }

    void remove(Model const& mdl)
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
        if (empty())
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

DynamicMapTree::DynamicMapTree() : impl(new DynTreeImpl()) { }

DynamicMapTree::~DynamicMapTree()
{
    delete impl;
}

void DynamicMapTree::insert(GameObjectModel const& mdl)
{
    impl->insert(mdl);
}

void DynamicMapTree::remove(GameObjectModel const& mdl)
{
    impl->remove(mdl);
}

bool DynamicMapTree::contains(GameObjectModel const& mdl) const
{
    return impl->contains(mdl);
}

void DynamicMapTree::balance()
{
    impl->balance();
}

void DynamicMapTree::update(uint32 t_diff)
{
    impl->update(t_diff);
}

struct DynamicTreeIntersectionCallback
{
    DynamicTreeIntersectionCallback(PhaseShift const& phaseShift) : _didHit(false), _phaseShift(phaseShift) { }

    bool operator()(G3D::Ray const& r, GameObjectModel const& obj, float& distance)
    {
        _didHit = obj.intersectRay(r, distance, true, _phaseShift, VMAP::ModelIgnoreFlags::Nothing);
        return _didHit;
    }

    bool didHit() const { return _didHit; }

private:
    bool _didHit;
    PhaseShift const& _phaseShift;
};

struct DynamicTreeAreaInfoCallback
{
    DynamicTreeAreaInfoCallback(PhaseShift const& phaseShift) : _phaseShift(phaseShift) {}

    void operator()(G3D::Vector3 const& p, GameObjectModel const& obj)
    {
        obj.intersectPoint(p, _areaInfo, _phaseShift);
    }

    VMAP::AreaInfo const& GetAreaInfo() const { return _areaInfo; }

private:
    PhaseShift const& _phaseShift;
    VMAP::AreaInfo _areaInfo;
};

struct DynamicTreeLocationInfoCallback
{
    DynamicTreeLocationInfoCallback(PhaseShift const& phaseShift) : _phaseShift(phaseShift), _hitModel(nullptr) {}

    void operator()(G3D::Vector3 const& p, GameObjectModel const& obj)
    {
        if (obj.GetLocationInfo(p, _locationInfo, _phaseShift))
            _hitModel = &obj;
    }

    VMAP::LocationInfo& GetLocationInfo() { return _locationInfo; }
    GameObjectModel const* GetHitModel() const { return _hitModel; }

private:
    PhaseShift const& _phaseShift;
    VMAP::LocationInfo _locationInfo;
    GameObjectModel const* _hitModel;
};

bool DynamicMapTree::getIntersectionTime(G3D::Ray const& ray, G3D::Vector3 const& endPos, PhaseShift const& phaseShift, float& maxDist) const
{
    float distance = maxDist;
    DynamicTreeIntersectionCallback callback(phaseShift);
    impl->intersectRay(ray, callback, distance, endPos);
    if (callback.didHit())
        maxDist = distance;
    return callback.didHit();
}

bool DynamicMapTree::getObjectHitPos(G3D::Vector3 const& startPos, G3D::Vector3 const& endPos, G3D::Vector3& resultHitPos, float modifyDist, PhaseShift const& phaseShift) const
{
    bool result = false;
    float maxDist = (endPos - startPos).magnitude();
    // valid map coords should *never ever* produce float overflow, but this would produce NaNs too
    ASSERT(maxDist < std::numeric_limits<float>::max());
    // prevent NaN values which can cause BIH intersection to enter infinite loop
    if (maxDist < 1e-10f)
    {
        resultHitPos = endPos;
        return false;
    }
    G3D::Vector3 dir = (endPos - startPos)/maxDist;              // direction with length of 1
    G3D::Ray ray(startPos, dir);
    float dist = maxDist;
    if (getIntersectionTime(ray, endPos, phaseShift, dist))
    {
        resultHitPos = startPos + dir * dist;
        if (modifyDist < 0)
        {
            if ((resultHitPos - startPos).magnitude() > -modifyDist)
                resultHitPos += dir * modifyDist;
            else
                resultHitPos = startPos;
        }
        else
            resultHitPos += dir * modifyDist;

        result = true;
    }
    else
    {
        resultHitPos = endPos;
        result = false;
    }
    return result;
}

bool DynamicMapTree::isInLineOfSight(G3D::Vector3 const& startPos, G3D::Vector3 const& endPos, PhaseShift const& phaseShift) const
{
    float maxDist = (endPos - startPos).magnitude();

    if (!G3D::fuzzyGt(maxDist, 0) )
        return true;

    G3D::Ray r(startPos, (endPos - startPos) / maxDist);
    DynamicTreeIntersectionCallback callback(phaseShift);
    impl->intersectRay(r, callback, maxDist, endPos);

    return !callback.didHit();
}

float DynamicMapTree::getHeight(float x, float y, float z, float maxSearchDist, PhaseShift const& phaseShift) const
{
    G3D::Vector3 v(x, y, z + 0.5f);
    G3D::Ray r(v, G3D::Vector3(0, 0, -1));
    DynamicTreeIntersectionCallback callback(phaseShift);
    impl->intersectZAllignedRay(r, callback, maxSearchDist);

    if (callback.didHit())
        return v.z - maxSearchDist;
    else
        return -G3D::finf();
}

bool DynamicMapTree::getAreaInfo(float x, float y, float& z, PhaseShift const& phaseShift, uint32& flags, int32& adtId, int32& rootId, int32& groupId) const
{
    G3D::Vector3 v(x, y, z + 0.5f);
    DynamicTreeAreaInfoCallback intersectionCallBack(phaseShift);
    impl->intersectPoint(v, intersectionCallBack);
    if (intersectionCallBack.GetAreaInfo().result)
    {
        flags = intersectionCallBack.GetAreaInfo().flags;
        adtId = intersectionCallBack.GetAreaInfo().adtId;
        rootId = intersectionCallBack.GetAreaInfo().rootId;
        groupId = intersectionCallBack.GetAreaInfo().groupId;
        z = intersectionCallBack.GetAreaInfo().ground_Z;
        return true;
    }
    return false;
}

void DynamicMapTree::getAreaAndLiquidData(float x, float y, float z, PhaseShift const& phaseShift, uint8 reqLiquidType, VMAP::AreaAndLiquidData& data) const
{
    G3D::Vector3 v(x, y, z + 0.5f);
    DynamicTreeLocationInfoCallback intersectionCallBack(phaseShift);
    impl->intersectPoint(v, intersectionCallBack);
    if (intersectionCallBack.GetLocationInfo().hitModel)
    {
        data.floorZ = intersectionCallBack.GetLocationInfo().ground_Z;
        uint32 liquidType = intersectionCallBack.GetLocationInfo().hitModel->GetLiquidType();
        float liquidLevel;
        if (!reqLiquidType || (dynamic_cast<VMAP::VMapManager2*>(VMAP::VMapFactory::createOrGetVMapManager())->GetLiquidFlagsPtr(liquidType) & reqLiquidType))
            if (intersectionCallBack.GetHitModel()->GetLiquidLevel(v, intersectionCallBack.GetLocationInfo(), liquidLevel))
                data.liquidInfo = boost::in_place(liquidType, liquidLevel);

        data.areaInfo = boost::in_place(intersectionCallBack.GetHitModel()->GetNameSetId(),
            intersectionCallBack.GetLocationInfo().rootId,
            intersectionCallBack.GetLocationInfo().hitModel->GetWmoID(),
            intersectionCallBack.GetLocationInfo().hitModel->GetMogpFlags());
    }
}
