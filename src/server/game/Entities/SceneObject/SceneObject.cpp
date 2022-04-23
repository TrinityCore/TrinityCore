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

#include "SceneObject.h"
#include "GameTime.h"
#include "Map.h"
#include "ObjectAccessor.h"
#include "ObjectMgr.h"
#include "PhasingHandler.h"
#include "Player.h"
#include "SpellAuras.h"
#include "UpdateData.h"
#include "Util.h"

SceneObject::SceneObject() : WorldObject(false)
{
    m_objectType |= TYPEMASK_SCENEOBJECT;
    m_objectTypeId = TYPEID_SCENEOBJECT;

    m_updateFlag.Stationary = true;
    m_updateFlag.SceneObject = true;
}

SceneObject::~SceneObject() = default;

void SceneObject::AddToWorld()
{
    if (!IsInWorld())
    {
        GetMap()->GetObjectsStore().Insert<SceneObject>(GetGUID(), this);
        WorldObject::AddToWorld();
    }
}

void SceneObject::RemoveFromWorld()
{
    if (IsInWorld())
    {
        WorldObject::RemoveFromWorld();
        GetMap()->GetObjectsStore().Remove<SceneObject>(GetGUID());
    }
}

void SceneObject::Update(uint32 diff)
{
    WorldObject::Update(diff);

    if (ShouldBeRemoved())
        Remove();
}

void SceneObject::Remove()
{
    if (IsInWorld())
        AddObjectToRemoveList();
}

bool SceneObject::ShouldBeRemoved() const
{
    Unit* creator = ObjectAccessor::GetUnit(*this, GetOwnerGUID());
    if (!creator)
        return true;

    if (!_createdBySpellCast.IsEmpty())
    {
        // search for a dummy aura on creator
        Aura const* linkedAura = creator->GetAura(_createdBySpellCast.GetEntry(), [this](Aura const* aura)
        {
            return aura->GetCastId() == _createdBySpellCast;
        });
        if (!linkedAura)
            return true;
    }

    return false;
}

SceneObject* SceneObject::CreateSceneObject(uint32 sceneId, Unit* creator, Position const& pos, ObjectGuid privateObjectOwner)
{
    SceneTemplate const* sceneTemplate = sObjectMgr->GetSceneTemplate(sceneId);
    if (!sceneTemplate)
        return nullptr;

    ObjectGuid::LowType lowGuid = creator->GetMap()->GenerateLowGuid<HighGuid::SceneObject>();

    SceneObject* sceneObject = new SceneObject();
    if (!sceneObject->Create(lowGuid, SceneType::Normal, sceneId, sceneTemplate ? sceneTemplate->ScenePackageId : 0, creator->GetMap(), creator, pos, privateObjectOwner))
    {
        delete sceneObject;
        return nullptr;
    }

    return sceneObject;
}

bool SceneObject::Create(ObjectGuid::LowType lowGuid, SceneType type, uint32 sceneId, uint32 scriptPackageId, Map* map, Unit* creator,
    Position const& pos, ObjectGuid privateObjectOwner)
{
    SetMap(map);
    Relocate(pos);
    RelocateStationaryPosition(pos);

    SetPrivateObjectOwner(privateObjectOwner);

    Object::_Create(ObjectGuid::Create<HighGuid::SceneObject>(GetMapId(), sceneId, lowGuid));
    PhasingHandler::InheritPhaseShift(this, creator);

    UpdatePositionData();
    SetZoneScript();

    SetEntry(scriptPackageId);
    SetObjectScale(1.0f);

    SetUpdateFieldValue(m_values.ModifyValue(&SceneObject::m_sceneObjectData).ModifyValue(&UF::SceneObjectData::ScriptPackageID), scriptPackageId);
    SetUpdateFieldValue(m_values.ModifyValue(&SceneObject::m_sceneObjectData).ModifyValue(&UF::SceneObjectData::RndSeedVal), GameTime::GetGameTimeMS());
    SetUpdateFieldValue(m_values.ModifyValue(&SceneObject::m_sceneObjectData).ModifyValue(&UF::SceneObjectData::CreatedBy), creator->GetGUID());
    SetUpdateFieldValue(m_values.ModifyValue(&SceneObject::m_sceneObjectData).ModifyValue(&UF::SceneObjectData::SceneType), AsUnderlyingType(type));

    if (!GetMap()->AddToMap(this))
        return false;

    return true;
}

void SceneObject::BuildValuesCreate(ByteBuffer* data, Player const* target) const
{
    UF::UpdateFieldFlag flags = GetUpdateFieldFlagsFor(target);
    std::size_t sizePos = data->wpos();
    *data << uint32(0);
    *data << uint8(flags);
    m_objectData->WriteCreate(*data, flags, this, target);
    m_sceneObjectData->WriteCreate(*data, flags, this, target);
    data->put<uint32>(sizePos, data->wpos() - sizePos - 4);
}

void SceneObject::BuildValuesUpdate(ByteBuffer* data, Player const* target) const
{
    UF::UpdateFieldFlag flags = GetUpdateFieldFlagsFor(target);
    std::size_t sizePos = data->wpos();
    *data << uint32(0);
    *data << uint32(m_values.GetChangedObjectTypeMask());

    if (m_values.HasChanged(TYPEID_OBJECT))
        m_objectData->WriteUpdate(*data, flags, this, target);

    if (m_values.HasChanged(TYPEID_SCENEOBJECT))
        m_sceneObjectData->WriteUpdate(*data, flags, this, target);

    data->put<uint32>(sizePos, data->wpos() - sizePos - 4);
}

void SceneObject::BuildValuesUpdateForPlayerWithMask(UpdateData* data, UF::ObjectData::Mask const& requestedObjectMask,
    UF::SceneObjectData::Mask const& requestedSceneObjectMask, Player const* target) const
{
    UpdateMask<NUM_CLIENT_OBJECT_TYPES> valuesMask;
    if (requestedObjectMask.IsAnySet())
        valuesMask.Set(TYPEID_OBJECT);

    if (requestedSceneObjectMask.IsAnySet())
        valuesMask.Set(TYPEID_SCENEOBJECT);

    ByteBuffer buffer = PrepareValuesUpdateBuffer();
    std::size_t sizePos = buffer.wpos();
    buffer << uint32(0);
    buffer << uint32(valuesMask.GetBlock(0));

    if (valuesMask[TYPEID_OBJECT])
        m_objectData->WriteUpdate(buffer, requestedObjectMask, true, this, target);

    if (valuesMask[TYPEID_SCENEOBJECT])
        m_sceneObjectData->WriteUpdate(buffer, requestedSceneObjectMask, true, this, target);

    buffer.put<uint32>(sizePos, buffer.wpos() - sizePos - 4);

    data->AddUpdateBlock(buffer);
}

void SceneObject::ValuesUpdateForPlayerWithMaskSender::operator()(Player const* player) const
{
    UpdateData udata(Owner->GetMapId());
    WorldPacket packet;

    Owner->BuildValuesUpdateForPlayerWithMask(&udata, ObjectMask.GetChangesMask(), SceneObjectMask.GetChangesMask(), player);

    udata.BuildPacket(&packet);
    player->SendDirectMessage(&packet);
}

void SceneObject::ClearUpdateMask(bool remove)
{
    m_values.ClearChangesMask(&SceneObject::m_sceneObjectData);
    Object::ClearUpdateMask(remove);
}
