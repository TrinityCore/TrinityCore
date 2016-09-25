/*
 * Copyright (C) 2008-2016 TrinityCore <http://www.trinitycore.org/>
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

#include "Conversation.h"
#include "CellImpl.h"
#include "Chat.h"
#include "DB2Stores.h"
#include "GridNotifiersImpl.h"
#include "Log.h"
#include "Object.h"
#include "ObjectMgr.h"
#include "Player.h"
#include "SpellInfo.h"
#include "Unit.h"
#include "UpdateData.h"

Conversation::Conversation() : WorldObject(false), _duration(0)
{
    m_objectType |= TYPEMASK_CONVERSATION;
    m_objectTypeId = TYPEID_CONVERSATION;

    m_updateFlag = UPDATEFLAG_STATIONARY_POSITION;

    m_valuesCount = CONVERSATION_END;
    _dynamicValuesCount = CONVERSATION_DYNAMIC_END;
}

Conversation::~Conversation()
{
}

void Conversation::AddToWorld()
{
    ///- Register the AreaTrigger for guid lookup and for caster
    if (!IsInWorld())
    {
        GetMap()->GetObjectsStore().Insert<Conversation>(GetGUID(), this);
        WorldObject::AddToWorld();
    }
}

void Conversation::RemoveFromWorld()
{
    ///- Remove the AreaTrigger from the accessor and from all lists of objects in world
    if (IsInWorld())
    {
        WorldObject::RemoveFromWorld();
        GetMap()->GetObjectsStore().Remove<Conversation>(GetGUID());
    }
}

void Conversation::Update(uint32 p_time)
{
    if (GetDuration() > int32(p_time))
        _duration -= p_time;
    else
        Remove(); // expired

    WorldObject::Update(p_time);
}

void Conversation::Remove()
{
    if (IsInWorld())
    {
        SendObjectDeSpawnAnim(GetGUID());
        RemoveFromWorld();
        AddObjectToRemoveList();
    }
}


bool Conversation::CreateConversation(ObjectGuid::LowType guidlow, uint32 conversationEntry, Unit* caster, Position const& pos)
{
    _casterGuid = caster->GetGUID();

    SetMap(caster->GetMap());
    Relocate(pos);

    Object::_Create(ObjectGuid::Create<HighGuid::Conversation>(GetMapId(), conversationEntry, guidlow));
    SetPhaseMask(caster->GetPhaseMask(), false);
    CopyPhaseFrom(caster);

    SetEntry(conversationEntry);
    SetObjectScale(1);

    ConversationTemplate const* conversationTemplate = sObjectMgr->GetConversationTemplate(conversationEntry);

    if (!conversationTemplate)
        return false;

    SetUInt32Value(CONVERSATION_FIELD_LAST_LINE_DURATION, conversationTemplate->LastLineDuration);
    _duration = (conversationTemplate->Lines.size() - 1) * 10000 + conversationTemplate->LastLineDuration; // Estimated duration, need further investigation

    for (ConversationActorTemplate actor : conversationTemplate->Actors)
    {
        AddDynamicValue(CONVERSATION_DYNAMIC_FIELD_ACTORS, actor.Id);
        AddDynamicValue(CONVERSATION_DYNAMIC_FIELD_ACTORS, actor.CreatureId);
        AddDynamicValue(CONVERSATION_DYNAMIC_FIELD_ACTORS, actor.Unk1);
        AddDynamicValue(CONVERSATION_DYNAMIC_FIELD_ACTORS, actor.Unk2);
        AddDynamicValue(CONVERSATION_DYNAMIC_FIELD_ACTORS, actor.Unk3);
        AddDynamicValue(CONVERSATION_DYNAMIC_FIELD_ACTORS, actor.Unk4);
    }

    for (ConversationLineTemplate line : conversationTemplate->Lines)
    {
        AddDynamicValue(CONVERSATION_DYNAMIC_FIELD_LINES, line.Id);
        AddDynamicValue(CONVERSATION_DYNAMIC_FIELD_LINES, line.Unk1);
        AddDynamicValue(CONVERSATION_DYNAMIC_FIELD_LINES, line.Unk2);
        AddDynamicValue(CONVERSATION_DYNAMIC_FIELD_LINES, line.Unk3);
    }

    if (!GetMap()->AddToMap(this))
        return false;

    return true;
}
