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

#include "DynamicObject.h"
#include "Common.h"
#include "DBCStores.h"
#include "GameTime.h"
#include "Log.h"
#include "Map.h"
#include "ObjectAccessor.h"
#include "PhasingHandler.h"
#include "Player.h"
#include "SpellAuras.h"
#include "SpellMgr.h"
#include "ScriptMgr.h"
#include "Transport.h"
#include "Unit.h"
#include "UpdateData.h"

DynamicObject::DynamicObject(bool isWorldObject) : WorldObject(isWorldObject),
    _aura(nullptr), _removedAura(nullptr), _caster(nullptr), _duration(0), _isViewpoint(false)
{
    m_objectType |= TYPEMASK_DYNAMICOBJECT;
    m_objectTypeId = TYPEID_DYNAMICOBJECT;

    m_updateFlag = UPDATEFLAG_STATIONARY_POSITION;

    m_valuesCount = DYNAMICOBJECT_END;
}

DynamicObject::~DynamicObject()
{
    // make sure all references were properly removed
    ASSERT(!_aura);
    ASSERT(!_caster);
    ASSERT(!_isViewpoint);
    delete _removedAura;
}

void DynamicObject::AddToWorld()
{
    ///- Register the dynamicObject for guid lookup and for caster
    if (!IsInWorld())
    {
        GetMap()->GetObjectsStore().Insert<DynamicObject>(GetGUID(), this);
        WorldObject::AddToWorld();
        BindToCaster();
    }
}

void DynamicObject::RemoveFromWorld()
{
    ///- Remove the dynamicObject from the accessor and from all lists of objects in world
    if (IsInWorld())
    {
        if (_isViewpoint)
            RemoveCasterViewpoint();

        if (_aura)
            RemoveAura();

        // dynobj could get removed in Aura::RemoveAura
        if (!IsInWorld())
            return;

        UnbindFromCaster();
        WorldObject::RemoveFromWorld();
        GetMap()->GetObjectsStore().Remove<DynamicObject>(GetGUID());

    }
}

bool DynamicObject::CreateDynamicObject(ObjectGuid::LowType guidlow, Unit* caster, SpellInfo const* spell, Position const& pos, float radius, DynamicObjectType type)
{
    SetMap(caster->GetMap());
    Relocate(pos);
    if (!IsPositionValid())
    {
        TC_LOG_ERROR("misc", "DynamicObject (spell %u) not created. Suggested coordinates isn't valid (X: %f Y: %f)", spell->Id, GetPositionX(), GetPositionY());
        return false;
    }

    WorldObject::_Create(guidlow, HighGuid::DynamicObject);
    PhasingHandler::InheritPhaseShift(this, caster);

    SetEntry(spell->Id);
    SetObjectScale(1);
    SetGuidValue(DYNAMICOBJECT_CASTER, caster->GetGUID());
    SetUInt32Value(DYNAMICOBJECT_BYTES, spell->SpellVisual[0] | (type << 28));
    SetUInt32Value(DYNAMICOBJECT_SPELLID, spell->Id);
    SetFloatValue(DYNAMICOBJECT_RADIUS, radius);
    SetUInt32Value(DYNAMICOBJECT_CASTTIME, GameTime::GetGameTimeMS());

    if (IsWorldObject())
        setActive(true);    //must before add to map to be put in world container

    TransportBase* transport = caster->GetTransport();
    if (transport)
    {
        float x, y, z, o;
        pos.GetPosition(x, y, z, o);
        transport->CalculatePassengerOffset(x, y, z, &o);
        m_movementInfo.transport.pos.Relocate(x, y, z, o);

        // This object must be added to transport before adding to map for the client to properly display it
        transport->AddPassenger(this);
    }

    if (!GetMap()->AddToMap(this))
    {
        // Returning false will cause the object to be deleted - remove from transport
        if (transport)
            transport->RemovePassenger(this);
        return false;
    }

    return true;
}

void DynamicObject::Update(uint32 p_time)
{
    // caster has to be always available and in the same map
    ASSERT(_caster);
    ASSERT(_caster->GetMap() == GetMap());

    bool expired = false;

    if (_aura)
    {
        if (!_aura->IsRemoved())
            _aura->UpdateOwner(p_time, this);

        // _aura may be set to null in Aura::UpdateOwner call
        if (_aura && (_aura->IsRemoved() || _aura->IsExpired()))
            expired = true;
    }
    else
    {
        if (GetDuration() > int32(p_time))
            _duration -= p_time;
        else
            expired = true;
    }

    if (expired)
        Remove();
    else
        sScriptMgr->OnDynamicObjectUpdate(this, p_time);
}

void DynamicObject::Remove()
{
    if (IsInWorld())
        AddObjectToRemoveList();
}

void DynamicObject::BuildValuesUpdate(uint8 updateType, ByteBuffer* data, Player* target) const
{
    if (!target)
        return;

    ByteBuffer fieldBuffer;
    UpdateMaskPacketBuilder updateMask(m_valuesCount);

    uint32* flags = nullptr;
    uint32 visibleFlag = GetUpdateFieldData(target, flags);
    ASSERT(flags);

    for (uint16 index = 0; index < m_valuesCount; ++index)
    {
        if (_fieldNotifyFlags & flags[index] ||
            ((updateType == UPDATETYPE_VALUES ? _changesMask.GetBit(index) : m_uint32Values[index]) && (flags[index] & visibleFlag)))
        {
            updateMask.SetBit(index);

            if (index == DYNAMICOBJECT_BYTES)
            {
                if (Unit* caster = GetCaster())
                {
                    if (SpellInfo const* spellInfo = GetSpellInfo())
                    {
                        SpellVisualEntry const* rootVisual = sSpellVisualStore.LookupEntry(spellInfo->SpellVisual[0]);
                        if (rootVisual && rootVisual->AlternativeVisualID)
                        {
                            SpellVisualEntry const* alternativeVisual = sSpellVisualStore.LookupEntry(rootVisual->AlternativeVisualID);
                            if (alternativeVisual && !caster->IsFriendlyTo(target))
                            {
                                fieldBuffer << (rootVisual->AlternativeVisualID | (DYNAMIC_OBJECT_AREA_SPELL << 28));
                                continue;
                            }
                        }
                    }
                }
            }

            fieldBuffer << m_uint32Values[index];
        }
    }

    updateMask.AppendToPacket(data);
    data->append(fieldBuffer);
}

int32 DynamicObject::GetDuration() const
{
    if (!_aura)
        return _duration;
    else
        return _aura->GetDuration();
}

void DynamicObject::SetDuration(int32 newDuration)
{
    if (!_aura)
        _duration = newDuration;
    else
        _aura->SetDuration(newDuration);
}

void DynamicObject::Delay(int32 delaytime)
{
    SetDuration(GetDuration() - delaytime);
}

void DynamicObject::SetAura(Aura* aura)
{
    ASSERT(!_aura && aura);
    _aura = aura;
}

void DynamicObject::RemoveAura()
{
    ASSERT(_aura && !_removedAura);
    _removedAura = _aura;
    _aura = nullptr;
    if (!_removedAura->IsRemoved())
        _removedAura->_Remove(AuraRemoveFlags::ByDefault);
}

void DynamicObject::SetCasterViewpoint()
{
    if (Player* caster = _caster->ToPlayer())
    {
        caster->SetViewpoint(this, true);
        _isViewpoint = true;
    }
}

void DynamicObject::RemoveCasterViewpoint()
{
    if (Player* caster = _caster->ToPlayer())
    {
        caster->SetViewpoint(this, false);
        _isViewpoint = false;
    }
}

uint32 DynamicObject::GetFaction() const
{
    ASSERT(_caster);
    return _caster->GetFaction();
}

void DynamicObject::BindToCaster()
{
    ASSERT(!_caster);
    _caster = ObjectAccessor::GetUnit(*this, GetCasterGUID());
    ASSERT(_caster);
    ASSERT(_caster->GetMap() == GetMap());
    _caster->_RegisterDynObject(this);
}

void DynamicObject::UnbindFromCaster()
{
    ASSERT(_caster);
    _caster->_UnregisterDynObject(this);
    _caster = nullptr;
}

SpellInfo const* DynamicObject::GetSpellInfo() const
{
    return sSpellMgr->GetSpellInfo(GetSpellId());
}
