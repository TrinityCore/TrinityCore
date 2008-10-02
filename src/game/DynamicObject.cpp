/*
 * Copyright (C) 2005-2008 MaNGOS <http://www.mangosproject.org/>
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
#include "GameObject.h"
#include "UpdateMask.h"
#include "Opcodes.h"
#include "WorldPacket.h"
#include "WorldSession.h"
#include "World.h"
#include "ObjectAccessor.h"
#include "Database/DatabaseEnv.h"
#include "SpellAuras.h"
#include "MapManager.h"
#include "GridNotifiers.h"
#include "CellImpl.h"
#include "GridNotifiersImpl.h"

DynamicObject::DynamicObject() : WorldObject()
{
    m_objectType |= TYPEMASK_DYNAMICOBJECT;
    m_objectTypeId = TYPEID_DYNAMICOBJECT;
                                                            // 2.3.2 - 0x58
    m_updateFlag = (UPDATEFLAG_LOWGUID | UPDATEFLAG_HIGHGUID | UPDATEFLAG_HASPOSITION);

    m_valuesCount = DYNAMICOBJECT_END;
}

void DynamicObject::AddToWorld()
{
    ///- Register the dynamicObject for guid lookup
    if(!IsInWorld()) ObjectAccessor::Instance().AddObject(this);
    Object::AddToWorld();
}

void DynamicObject::RemoveFromWorld()
{
    ///- Remove the dynamicObject from the accessor
    if(IsInWorld()) ObjectAccessor::Instance().RemoveObject(this);
    Object::RemoveFromWorld();
}

bool DynamicObject::Create( uint32 guidlow, Unit *caster, uint32 spellId, uint32 effIndex, float x, float y, float z, int32 duration, float radius )
{
    SetInstanceId(caster->GetInstanceId());

    WorldObject::_Create(guidlow, HIGHGUID_DYNAMICOBJECT, caster->GetMapId());
    Relocate(x,y,z,0);

    if(!IsPositionValid())
    {
        sLog.outError("ERROR: DynamicObject (spell %u eff %u) not created. Suggested coordinates isn't valid (X: %f Y: %f)",spellId,effIndex,GetPositionX(),GetPositionY());
        return false;
    }

    SetUInt32Value( OBJECT_FIELD_ENTRY, spellId );
    SetFloatValue( OBJECT_FIELD_SCALE_X, 1 );
    SetUInt64Value( DYNAMICOBJECT_CASTER, caster->GetGUID() );
    SetUInt32Value( DYNAMICOBJECT_BYTES, 0x00000001 );
    SetUInt32Value( DYNAMICOBJECT_SPELLID, spellId );
    SetFloatValue( DYNAMICOBJECT_RADIUS, radius);
    SetFloatValue( DYNAMICOBJECT_POS_X, x );
    SetFloatValue( DYNAMICOBJECT_POS_Y, y );
    SetFloatValue( DYNAMICOBJECT_POS_Z, z );
    SetUInt32Value( DYNAMICOBJECT_CASTTIME, getMSTime() );  // new 2.4.0

    m_aliveDuration = duration;
    m_radius = radius;
    m_effIndex = effIndex;
    m_spellId = spellId;
    m_casterGuid = caster->GetGUID();
    return true;
}

Unit* DynamicObject::GetCaster() const
{
    // can be not found in some cases
    return ObjectAccessor::GetUnit(*this,m_casterGuid);
}

void DynamicObject::Update(uint32 p_time)
{
    // caster can be not in world at time dynamic object update, but dynamic object not yet deleted in Unit destructor
    Unit* caster = GetCaster();
    if(!caster)
    {
        Delete();
        return;
    }

    bool deleteThis = false;

    if(m_aliveDuration > int32(p_time))
        m_aliveDuration -= p_time;
    else
        deleteThis = true;

    // TODO: make a timer and update this in larger intervals
    CellPair p(MaNGOS::ComputeCellPair(GetPositionX(), GetPositionY()));
    Cell cell(p);
    cell.data.Part.reserved = ALL_DISTRICT;
    cell.SetNoCreate();

    MaNGOS::DynamicObjectUpdater notifier(*this,caster);

    TypeContainerVisitor<MaNGOS::DynamicObjectUpdater, WorldTypeMapContainer > world_object_notifier(notifier);
    TypeContainerVisitor<MaNGOS::DynamicObjectUpdater, GridTypeMapContainer > grid_object_notifier(notifier);

    CellLock<GridReadGuard> cell_lock(cell, p);
    cell_lock->Visit(cell_lock, world_object_notifier, *MapManager::Instance().GetMap(GetMapId(), this));
    cell_lock->Visit(cell_lock, grid_object_notifier,  *MapManager::Instance().GetMap(GetMapId(), this));

    if(deleteThis)
    {
        caster->RemoveDynObjectWithGUID(GetGUID());
        Delete();
    }
}

void DynamicObject::Delete()
{
    SendObjectDeSpawnAnim(GetGUID());
    AddObjectToRemoveList();
}

void DynamicObject::Delay(int32 delaytime)
{
    m_aliveDuration -= delaytime;
    for(AffectedSet::iterator iunit= m_affected.begin();iunit != m_affected.end();++iunit)
        if (*iunit)
            (*iunit)->DelayAura(m_spellId, m_effIndex, delaytime);
}

bool DynamicObject::isVisibleForInState(Player const* u, bool inVisibleList) const
{
    return IsInWorld() && u->IsInWorld() && IsWithinDistInMap(u,World::GetMaxVisibleDistanceForObject()+(inVisibleList ? World::GetVisibleObjectGreyDistance() : 0.0f));
}
