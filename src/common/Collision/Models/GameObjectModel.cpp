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

#include "VMapFactory.h"
#include "VMapManager2.h"
#include "VMapDefinitions.h"
#include "WorldModel.h"
#include "GameObjectModel.h"
#include "Log.h"
#include "MapTree.h"
#include "Memory.h"
#include "Timer.h"
#include <G3D/Quat.h>

using G3D::Vector3;
using G3D::Ray;
using G3D::AABox;

struct GameobjectModelData
{
    GameobjectModelData(char const* name_, uint32 nameLength, Vector3 const& lowBound, Vector3 const& highBound) :
        bound(lowBound, highBound), name(name_, nameLength) { }

    AABox bound;
    std::string name;
};

typedef std::unordered_map<uint32, GameobjectModelData> ModelList;
ModelList model_list;

bool LoadGameObjectModelList(std::string const& dataPath)
{
    uint32 oldMSTime = getMSTime();

    auto model_list_file = Trinity::make_unique_ptr_with_deleter(fopen((dataPath + "vmaps/" + VMAP::GAMEOBJECT_MODELS).c_str(), "rb"), &::fclose);
    if (!model_list_file)
    {
        TC_LOG_ERROR("misc", "Unable to open '{}' file.", VMAP::GAMEOBJECT_MODELS);
        return false;
    }

    char magic[8];
    if (fread(magic, 1, 8, model_list_file.get()) != 8
        || memcmp(magic, VMAP::VMAP_MAGIC, 8) != 0)
    {
        TC_LOG_ERROR("misc", "File '{}' has wrong header, expected {}.", VMAP::GAMEOBJECT_MODELS, VMAP::VMAP_MAGIC);
        return false;
    }

    uint32 name_length, displayId;
    char buff[500];
    while (true)
    {
        Vector3 v1, v2;
        if (fread(&displayId, sizeof(uint32), 1, model_list_file.get()) != 1)
            if (feof(model_list_file.get()))  // EOF flag is only set after failed reading attempt
                break;

        if (fread(&name_length, sizeof(uint32), 1, model_list_file.get()) != 1
            || name_length >= sizeof(buff)
            || fread(&buff, sizeof(char), name_length, model_list_file.get()) != name_length
            || fread(&v1, sizeof(Vector3), 1, model_list_file.get()) != 1
            || fread(&v2, sizeof(Vector3), 1, model_list_file.get()) != 1)
        {
            TC_LOG_ERROR("misc", "File '{}' seems to be corrupted!", VMAP::GAMEOBJECT_MODELS);
            break;
        }

        if (v1.isNaN() || v2.isNaN())
        {
            TC_LOG_ERROR("misc", "File '{}' Model '{}' has invalid v1{} v2{} values!", VMAP::GAMEOBJECT_MODELS, std::string(buff, name_length), v1.toString(), v2.toString());
            continue;
        }

        model_list.emplace(std::piecewise_construct, std::forward_as_tuple(displayId), std::forward_as_tuple(&buff[0], name_length, v1, v2));
    }

    TC_LOG_INFO("server.loading", ">> Loaded {} GameObject models in {} ms", uint32(model_list.size()), GetMSTimeDiffToNow(oldMSTime));
    return true;
}

GameObjectModel::~GameObjectModel() = default;

bool GameObjectModel::initialize(std::unique_ptr<GameObjectModelOwnerBase> modelOwner, std::string const& dataPath)
{
    ModelList::const_iterator it = model_list.find(modelOwner->GetDisplayId());
    if (it == model_list.end())
        return false;

    G3D::AABox mdl_box(it->second.bound);
    // ignore models with no bounds
    if (mdl_box == G3D::AABox::zero())
    {
        TC_LOG_ERROR("misc", "GameObject model {} has zero bounds, loading skipped", it->second.name);
        return false;
    }

    iModel = VMAP::VMapFactory::createOrGetVMapManager()->acquireModelInstance(dataPath + "vmaps/", it->second.name);

    if (!iModel)
        return false;

    iPos = modelOwner->GetPosition();
    iScale = modelOwner->GetScale();
    iInvScale = 1.f / iScale;

    G3D::Matrix3 iRotation = modelOwner->GetRotation().toRotationMatrix();
    iInvRot = iRotation.inverse();
    // transform bounding box:
    mdl_box = AABox(mdl_box.low() * iScale, mdl_box.high() * iScale);
    AABox rotated_bounds;
    for (int i = 0; i < 8; ++i)
        rotated_bounds.merge(iRotation * mdl_box.corner(i));

    iBound = rotated_bounds + iPos;
#ifdef SPAWN_CORNERS
    // test:
    for (int i = 0; i < 8; ++i)
    {
        Vector3 pos(iBound.corner(i));
        modelOwner->DebugVisualizeCorner(pos);
    }
#endif

    owner = std::move(modelOwner);
    return true;
}

GameObjectModel* GameObjectModel::Create(std::unique_ptr<GameObjectModelOwnerBase> modelOwner, std::string const& dataPath)
{
    GameObjectModel* mdl = new GameObjectModel();
    if (!mdl->initialize(std::move(modelOwner), dataPath))
    {
        delete mdl;
        return nullptr;
    }

    return mdl;
}

bool GameObjectModel::IsMapObject() const
{
    return !iModel->IsM2();
}

bool GameObjectModel::IntersectRay(G3D::Ray const& ray, float& maxDist, bool stopAtFirstHit, PhaseShift const& phaseShift, VMAP::ModelIgnoreFlags ignoreFlags) const
{
    if (!IsCollisionEnabled() || !owner->IsSpawned())
        return false;

    if (!owner->IsInPhase(phaseShift))
        return false;

    float time = ray.intersectionTime(iBound);
    if (time == G3D::finf())
        return false;

    // child bounds are defined in object space:
    Vector3 p = iInvRot * (ray.origin() - iPos) * iInvScale;
    Ray modRay(p, iInvRot * ray.direction());
    float distance = maxDist * iInvScale;
    bool hit = iModel->IntersectRay(modRay, distance, stopAtFirstHit, ignoreFlags);
    if (hit)
    {
        distance *= iScale;
        maxDist = distance;
    }
    return hit;
}

bool GameObjectModel::GetLocationInfo(G3D::Vector3 const& point, VMAP::LocationInfo& info, PhaseShift const& phaseShift) const
{
    if (!IsCollisionEnabled() || !owner->IsSpawned() || !IsMapObject())
        return false;

    if (!owner->IsInPhase(phaseShift))
        return false;

    if (!iBound.contains(point))
        return false;

    // child bounds are defined in object space:
    Vector3 pModel = iInvRot * (point - iPos) * iInvScale;
    Vector3 zDirModel = iInvRot * Vector3(0.f, 0.f, -1.f);
    float zDist;

    VMAP::GroupLocationInfo groupInfo;
    if (iModel->GetLocationInfo(pModel, zDirModel, zDist, groupInfo))
    {
        Vector3 modelGround = pModel + zDist * zDirModel;
        float world_Z = ((modelGround * iInvRot) * iScale + iPos).z;
        if (info.ground_Z < world_Z)
        {
            info.ground_Z = world_Z;
            return true;
        }
    }

    return false;
}

bool GameObjectModel::GetLiquidLevel(G3D::Vector3 const& point, VMAP::LocationInfo& info, float& liqHeight) const
{
    // child bounds are defined in object space:
    Vector3 pModel = iInvRot * (point - iPos) * iInvScale;
    //Vector3 zDirModel = iInvRot * Vector3(0.f, 0.f, -1.f);
    float zDist;
    if (info.hitModel->GetLiquidLevel(pModel, zDist))
    {
        // calculate world height (zDist in model coords):
        // assume WMO not tilted (wouldn't make much sense anyway)
        liqHeight = zDist * iScale + iPos.z;
        return true;
    }
    return false;
}

bool GameObjectModel::UpdatePosition()
{
    if (!iModel)
        return false;

    ModelList::const_iterator it = model_list.find(owner->GetDisplayId());
    if (it == model_list.end())
        return false;

    G3D::AABox mdl_box(it->second.bound);
    // ignore models with no bounds
    if (mdl_box == G3D::AABox::zero())
    {
        TC_LOG_ERROR("misc", "GameObject model {} has zero bounds, loading skipped", it->second.name);
        return false;
    }

    iPos = owner->GetPosition();

    G3D::Matrix3 iRotation = owner->GetRotation().toRotationMatrix();
    iInvRot = iRotation.inverse();
    // transform bounding box:
    mdl_box = AABox(mdl_box.low() * iScale, mdl_box.high() * iScale);
    AABox rotated_bounds;
    for (int i = 0; i < 8; ++i)
        rotated_bounds.merge(iRotation * mdl_box.corner(i));

    iBound = rotated_bounds + iPos;
#ifdef SPAWN_CORNERS
    // test:
    for (int i = 0; i < 8; ++i)
    {
        Vector3 pos(iBound.corner(i));
        owner->DebugVisualizeCorner(pos);
    }
#endif

    return true;
}
