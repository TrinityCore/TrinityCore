/*
 * Copyright (C) 2005-2009 MaNGOS <http://getmangos.com/>
 *
 * Copyright (C) 2008-2010 Trinity <http://www.trinitycore.org/>
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

#include "Common.h"
#include "UpdateMask.h"
#include "Opcodes.h"
#include "World.h"
#include "ObjectAccessor.h"
#include "DatabaseEnv.h"
#include "GridNotifiers.h"
#include "CellImpl.h"
#include "GridNotifiersImpl.h"

DynamicObject::DynamicObject() : WorldObject()
{
    m_objectType |= TYPEMASK_DYNAMICOBJECT;
    m_objectTypeId = TYPEID_DYNAMICOBJECT;

    m_updateFlag = (UPDATEFLAG_HIGHGUID | UPDATEFLAG_HAS_POSITION | UPDATEFLAG_POSITION);

    m_valuesCount = DYNAMICOBJECT_END;

    m_aura = 0;
    m_duration = 0;
}

void DynamicObject::AddToWorld()
{
    ///- Register the dynamicObject for guid lookup
    if (!IsInWorld())
    {
        sObjectAccessor.AddObject(this);
        WorldObject::AddToWorld();
    }
}

void DynamicObject::RemoveFromWorld()
{
    ///- Remove the dynamicObject from the accessor
    if (IsInWorld())
    {
        if (m_isWorldObject)
        {
            if (Unit *caster = GetCaster())
            {
                if (caster->GetTypeId() == TYPEID_PLAYER)
                    caster->ToPlayer()->SetViewpoint(this, false);
            }
            else
            {
                sLog.outCrash("DynamicObject::RemoveFromWorld cannot find viewpoint owner");
            }
        }
        WorldObject::RemoveFromWorld();
        sObjectAccessor.RemoveObject(this);
    }
}

bool DynamicObject::Create(uint32 guidlow, Unit *caster, uint32 spellId, const Position &pos, float radius, bool active)
{
    SetMap(caster->GetMap());
    Relocate(pos);
    if (!IsPositionValid())
    {
        sLog.outError("DynamicObject (spell %u) not created. Suggested coordinates isn't valid (X: %f Y: %f)",spellId,GetPositionX(),GetPositionY());
        return false;
    }

    WorldObject::_Create(guidlow, HIGHGUID_DYNAMICOBJECT, caster->GetPhaseMask());

    SetEntry(spellId);
    SetFloatValue(OBJECT_FIELD_SCALE_X, 1);
    SetUInt64Value(DYNAMICOBJECT_CASTER, caster->GetGUID());

    // The lower word of DYNAMICOBJECT_BYTES must be 0x0001. This value means that the visual radius will be overriden
    // by client for most of the "ground patch" visual effect spells and a few "skyfall" ones like Hurricane.
    // If any other value is used, the client will _always_ use the radius provided in DYNAMICOBJECT_RADIUS, but
    // precompensation is necessary (eg radius *= 2) for many spells. Anyway, blizz sends 0x0001 for all the spells
    // I saw sniffed...
    SetUInt32Value(DYNAMICOBJECT_BYTES, 0x00000001);
    SetUInt32Value(DYNAMICOBJECT_SPELLID, spellId);
    SetFloatValue(DYNAMICOBJECT_RADIUS, radius);
    SetUInt32Value(DYNAMICOBJECT_CASTTIME, getMSTime());

    m_isWorldObject = active;
    return true;
}

Unit* DynamicObject::GetCaster() const
{
    // can be not found in some cases
    return ObjectAccessor::GetUnit(*this, GetCasterGUID());
}

void DynamicObject::Update(uint32 p_time)
{
    // caster can be not in world at time dynamic object update, but dynamic object not yet deleted in Unit destructor
    Unit* caster = GetCaster();
    if (!caster)
    {
        Delete();
        return;
    }

    bool expired = false;

    if (m_aura)
    {
        if (!m_aura->IsRemoved())
            m_aura->UpdateOwner(p_time, this);

        // m_aura may be set to null in Unit::RemoveGameObject call
        if (m_aura && (m_aura->IsRemoved() || m_aura->IsExpired()))
            expired = true;
    }
    else
    {
        if (GetDuration() > int32(p_time))
            m_duration -= p_time;
        else
            expired = true;
    }

    if (expired)
    {
        caster->RemoveDynObjectWithGUID(GetGUID());
        Delete();
    }
}

void DynamicObject::Delete()
{
    if (m_aura)
    {
        // dynObj may be removed in Aura::Remove - we cannot delete there
        // so recheck aura here
        if (!m_aura->IsRemoved())
            m_aura->_Remove(AURA_REMOVE_BY_DEFAULT);
        delete m_aura;
        m_aura = NULL;
    }
    SendObjectDeSpawnAnim(GetGUID());
    RemoveFromWorld();
    AddObjectToRemoveList();
}

int32 DynamicObject::GetDuration() const
{
    if (!m_aura)
        return m_duration;
    else
        return m_aura->GetDuration();
}

void DynamicObject::SetDuration(int32 newDuration)
{
    if (!m_aura)
        m_duration = newDuration;
    else
        m_aura->SetDuration(newDuration);
}

void DynamicObject::Delay(int32 delaytime)
{
    SetDuration(GetDuration() - delaytime);
}

bool DynamicObject::isVisibleForInState(Player const* u, bool inVisibleList) const
{
    return IsInWorld() && u->IsInWorld()
        && (IsWithinDistInMap(u->m_seer,World::GetMaxVisibleDistanceForObject()+(inVisibleList ? World::GetVisibleObjectGreyDistance() : 0.0f), false));
}
