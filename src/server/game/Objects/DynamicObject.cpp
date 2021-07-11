/*
 * Copyright (C) 2005-2011 MaNGOS <http://getmangos.com/>
 * Copyright (C) 2009-2011 MaNGOSZero <https://github.com/mangos/zero>
 * Copyright (C) 2011-2016 Nostalrius <https://nostalrius.org>
 * Copyright (C) 2016-2017 Elysium Project <https://github.com/elysium-project>
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
#include "World.h"
#include "ObjectAccessor.h"
#include "GridNotifiers.h"
#include "CellImpl.h"
#include "GridNotifiersImpl.h"
#include "SpellMgr.h"

DynamicObject::DynamicObject() : WorldObject(), m_spellId(0), m_effIndex(EFFECT_INDEX_0), m_aliveDuration(0), m_radius(0), m_positive(false), m_channeled(false)
{
    m_objectType |= TYPEMASK_DYNAMICOBJECT;
    m_objectTypeId = TYPEID_DYNAMICOBJECT;
#if SUPPORTED_CLIENT_BUILD > CLIENT_BUILD_1_8_4
    m_updateFlag = (UPDATEFLAG_ALL | UPDATEFLAG_HAS_POSITION);
#endif
    m_valuesCount = DYNAMICOBJECT_END;
}

void DynamicObject::AddToWorld()
{
    ///- Register the dynamicObject for guid lookup
    if (!IsInWorld())
        GetMap()->InsertObject<DynamicObject>(GetObjectGuid(), this);

    Object::AddToWorld();
}

void DynamicObject::RemoveFromWorld()
{
    ///- Remove the dynamicObject from the accessor
    if (IsInWorld())
    {
        GetMap()->EraseObject<DynamicObject>(GetObjectGuid());
        GetViewPoint().Event_RemovedFromWorld();
    }

    Object::RemoveFromWorld();
}

bool DynamicObject::Create(uint32 guidlow, WorldObject* caster, uint32 spellId, SpellEffectIndex effIndex, float x, float y, float z, int32 duration, float radius, DynamicObjectType type)
{
    WorldObject::_Create(guidlow, HIGHGUID_DYNAMICOBJECT);
    SetMap(caster->GetMap());
    Relocate(x, y, z, 0);

    if (!IsPositionValid())
    {
        sLog.outError("DynamicObject (spell %u eff %u) not created. Suggested coordinates isn't valid (X: %f Y: %f)", spellId, effIndex, GetPositionX(), GetPositionY());
        return false;
    }

    SetEntry(spellId);
    SetObjectScale(DEFAULT_OBJECT_SCALE);

    SetGuidValue(DYNAMICOBJECT_CASTER, caster->GetObjectGuid());

    /* Bytes field, so it's really 4 bit fields. These flags are unknown, but we do know that 0x00000001 is set for most.
       Farsight for example, does not have this flag, instead it has 0x80000002.
       Flags are set dynamically with some conditions, so one spell may have different flags set, depending on those conditions.
       The size of the visual may be controlled to some degree with these flags.

    uint32 bytes = 0x00000000;
    bytes |= 0x01;
    bytes |= 0x00 << 8;
    bytes |= 0x00 << 16;
    bytes |= 0x00 << 24;
    */
    uint32 bytes = type;

    // Nostalrius: fusee eclairante. Fix diametre visuel.
    if (spellId == 1543)
        bytes = 0x10; // Aucune idee de ce que ca represente ...

    SetUInt32Value(DYNAMICOBJECT_BYTES, bytes);
    SetUInt32Value(DYNAMICOBJECT_SPELLID, spellId);

    if (bytes == 0x10)
        SetFloatValue(DYNAMICOBJECT_RADIUS, radius * 2.0f); // Serait-ce enfait le diametre dans ce cas ?
    else
        SetFloatValue(DYNAMICOBJECT_RADIUS, radius);

    SetFloatValue(DYNAMICOBJECT_POS_X, x);
    SetFloatValue(DYNAMICOBJECT_POS_Y, y);
    SetFloatValue(DYNAMICOBJECT_POS_Z, z);

    SpellEntry const* spellProto = sSpellMgr.GetSpellEntry(spellId);
    if (!spellProto)
    {
        sLog.outError("DynamicObject (spell %u) not created. Spell not exist!", spellId, GetPositionX(), GetPositionY());
        return false;
    }

    m_aliveDuration = duration;
    m_radius = radius;
    m_effIndex = effIndex;
    m_spellId = spellId;
    m_positive = spellProto->IsPositiveEffect(m_effIndex);
    m_channeled = spellProto->IsChanneledSpell();

    return true;
}

SpellCaster* DynamicObject::GetCaster() const
{
    if (ObjectGuid guid = GetCasterGuid())
    {
        if (!guid.IsEmpty())
        {
            if (guid.IsUnit())
                return ObjectAccessor::GetUnit(*this, guid);
            else if (guid.IsGameObject())
            {
                return GetMap()->GetGameObject(guid);
            }
        }
    }
    // can be not found in some cases
    return nullptr;
}

Unit* DynamicObject::GetUnitCaster() const
{
    WorldObject* pCaster = GetCaster();
    if (!pCaster)
        return nullptr;

    if (pCaster->IsUnit())
        return static_cast<Unit*>(pCaster);
    
    if (GameObject* pGo = pCaster->ToGameObject())
        return pGo->GetOwner();

    // can be not found in some cases
    return nullptr;
}

uint32 DynamicObject::GetFactionTemplateId() const
{
    return GetCaster()->GetFactionTemplateId();
}

void DynamicObject::Update(uint32 update_diff, uint32 p_time)
{
    WorldObject::Update(update_diff, p_time);
    // caster can be not in world at time dynamic object update, but dynamic object not yet deleted in Unit destructor
    SpellCaster* caster = GetCaster();
    if (!caster)
    {
        Delete();
        return;
    }

    if (_deleted)
        return;

    // If this object is from the current channeled spell, do not delete it. Otherwise
    // we can lose the last tick of the effect due to differeng updates. The spell
    // itself will call for the object to be removed at the end of the cast
    bool deleteThis = false;

    m_aliveDuration -= p_time;
    if (m_aliveDuration <= 0)
        m_aliveDuration = 0;

    if (m_aliveDuration == 0 && (!m_channeled || (caster->IsUnit() && static_cast<Unit*>(caster)->GetChannelObjectGuid() != GetObjectGuid())))
        deleteThis = true;

    for (auto& iter : m_affected)
        iter.second += update_diff;

    // have radius and work as persistent effect
    if (m_radius)
    {
        // TODO: make a timer and update this in larger intervals
        MaNGOS::DynamicObjectUpdater notifier(*this, caster, m_positive);
        Cell::VisitAllObjects(this, notifier, m_radius);

        // Nostalrius
        // Hackfix pour Piege explosif. Ne doit s'activer qu'une fois.
        switch (m_spellId)
        {
            case 13812: // rang 1
            case 14314: // rang 2
            case 14315: // rang 3
                m_radius = 0.0f;
                break;
        }
    }

    if (deleteThis)
    {
        caster->RemoveDynObjectWithGUID(GetObjectGuid());
        Delete();
    }
}

void DynamicObject::Delete()
{
    SendObjectDeSpawnAnim();
    AddObjectToRemoveList();
}

void DynamicObject::AddAffected(Unit* unit)
{
    m_affected[unit->GetObjectGuid()] = 0;
}

void DynamicObject::RemoveAffected(Unit* unit)
{
    m_affected.erase(unit->GetObjectGuid());
}

void DynamicObject::Delay(int32 delaytime)
{
    m_aliveDuration -= delaytime;
    for (AffectedMap::iterator iter = m_affected.begin(); iter != m_affected.end();)
    {
        Unit* target = GetMap()->GetUnit(iter->first);
        if (target)
        {
            SpellAuraHolder* holder = target->GetSpellAuraHolder(m_spellId, GetCasterGuid());
            if (!holder)
            {
                ++iter;
                continue;
            }

            bool foundAura = false;
            for (int32 i = m_effIndex + 1; i < MAX_EFFECT_INDEX; ++i)
            {
                if ((holder->GetSpellProto()->Effect[i] == SPELL_EFFECT_PERSISTENT_AREA_AURA || holder->GetSpellProto()->Effect[i] == SPELL_EFFECT_ADD_FARSIGHT) && holder->m_auras[i])
                {
                    foundAura = true;
                    break;
                }
            }

            if (foundAura)
            {
                ++iter;
                continue;
            }

            target->DelaySpellAuraHolder(m_spellId, delaytime, GetCasterGuid());
            ++iter;
        }
        else
            m_affected.erase(iter++);
    }
}

bool DynamicObject::IsVisibleForInState(WorldObject const* pDetector, WorldObject const* viewPoint, bool inVisibleList) const
{
    if (!IsInWorld() || !pDetector->IsInWorld())
        return false;

    // always seen by owner
    if (GetCasterGuid() == pDetector->GetObjectGuid())
        return true;

    // normal case
    return IsWithinDistInMap(viewPoint, std::max(GetMap()->GetVisibilityDistance() + (inVisibleList ? World::GetVisibleObjectGreyDistance() : 0.0f), GetVisibilityModifier()), false);
}

bool DynamicObject::IsHostileTo(WorldObject const* target) const
{
    if (WorldObject* owner = GetCaster())
        return owner->IsHostileTo(target);
    else
        return false;
}

bool DynamicObject::IsFriendlyTo(WorldObject const* target) const
{
    if (WorldObject* owner = GetCaster())
        return owner->IsFriendlyTo(target);
    else
        return true;
}

bool DynamicObject::NeedsRefresh(Unit* unit) const
{
    AffectedMap::const_iterator it = m_affected.find(unit->GetObjectGuid());
    return it == m_affected.end() || it->second > 2000;
}
