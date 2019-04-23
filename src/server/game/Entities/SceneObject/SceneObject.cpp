/*
 * Copyright (C) 2017-2018 AshamaneProject <https://github.com/AshamaneProject>
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
#include "Creature.h"
#include "IteratorPair.h"
#include "Log.h"
#include "Map.h"
#include "PhasingHandler.h"
#include "ScriptMgr.h"
#include "Unit.h"
#include "UpdateData.h"

SceneObject::SceneObject() : WorldObject(false), _duration(0)
{
    m_objectType |= TYPEMASK_SCENEOBJECT;
    m_objectTypeId = TYPEID_SCENEOBJECT;

    m_updateFlag.MovementUpdate = true;

    m_valuesCount = SCENEOBJECT_END;
    _dynamicValuesCount = SCENEOBJECT_DYNAMIC_END;
}

SceneObject::~SceneObject()
{
}

void SceneObject::AddToWorld()
{
    ///- Register the Scene for guid lookup and for caster
    if (!IsInWorld())
    {
        GetMap()->GetObjectsStore().Insert<SceneObject>(GetGUID(), this);
        WorldObject::AddToWorld();
    }
}

void SceneObject::RemoveFromWorld()
{
    ///- Remove the Scene from the accessor and from all lists of objects in world
    if (IsInWorld())
    {
        WorldObject::RemoveFromWorld();
        GetMap()->GetObjectsStore().Remove<SceneObject>(GetGUID());
    }
}

bool SceneObject::IsNeverVisibleFor(WorldObject const* seer) const
{
    if (_participants.find(seer->GetGUID()) == _participants.end())
        return true;

    return WorldObject::IsNeverVisibleFor(seer);
}

void SceneObject::Update(uint32 diff)
{
    if (GetDuration() > int32(diff))
        _duration -= diff;
    else
        Remove(); // expired

    WorldObject::Update(diff);
}

void SceneObject::Remove()
{
    if (IsInWorld())
    {
        AddObjectToRemoveList(); // calls RemoveFromWorld
    }
}

SceneObject* SceneObject::CreateScene(uint32 SceneId, Unit* creator, Position const& pos, GuidUnorderedSet&& participants, SpellInfo const* spellInfo /*= nullptr*/)
{
    ObjectGuid::LowType lowGuid = creator->GetMap()->GenerateLowGuid<HighGuid::SceneObject>();

    SceneObject* Scene = new SceneObject();
    if (!Scene->Create(lowGuid, SceneId, creator->GetMap(), creator, pos, std::move(participants), spellInfo))
    {
        delete Scene;
        return nullptr;
    }

    return Scene;
}

bool SceneObject::Create(ObjectGuid::LowType lowGuid, uint32 SceneId, Map* map, Unit* creator, Position const& pos, GuidUnorderedSet&& participants, SpellInfo const* /*spellInfo = nullptr*/)
{
    _creatorGuid = creator->GetGUID();
    _participants = std::move(participants);

    SetMap(map);
    Relocate(pos);

    Object::_Create(ObjectGuid::Create<HighGuid::SceneObject>(GetMapId(), SceneId, lowGuid));
    PhasingHandler::InheritPhaseShift(this, creator);

    SetEntry(SceneId);
    SetObjectScale(1.0f);

    if (!GetMap()->AddToMap(this))
        return false;

    return true;
}

void SceneObject::AddParticipant(ObjectGuid const& participantGuid)
{
    _participants.insert(participantGuid);
}
