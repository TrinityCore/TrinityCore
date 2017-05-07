/*
 * Copyright (C) 2008-2017 TrinityCore <http://www.trinitycore.org/>
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
#include "ConversationDataStore.h"
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
    ///- Register the Conversation for guid lookup and for caster
    if (!IsInWorld())
    {
        GetMap()->GetObjectsStore().Insert<Conversation>(GetGUID(), this);
        WorldObject::AddToWorld();
    }
}

void Conversation::RemoveFromWorld()
{
    ///- Remove the Conversation from the accessor and from all lists of objects in world
    if (IsInWorld())
    {
        WorldObject::RemoveFromWorld();
        GetMap()->GetObjectsStore().Remove<Conversation>(GetGUID());
    }
}

void Conversation::Update(uint32 diff)
{
    if (GetDuration() > int32(diff))
        _duration -= diff;
    else
        Remove(); // expired

    WorldObject::Update(diff);
}

void Conversation::Remove()
{
    if (IsInWorld())
    {
        AddObjectToRemoveList(); // calls RemoveFromWorld
    }
}

bool Conversation::CreateConversation(uint32 conversationEntry, Unit* creator, Position const& pos, SpellInfo const* /*spellInfo = nullptr*/)
{
    ConversationTemplate const* conversationTemplate = sConversationDataStore->GetConversationTemplate(conversationEntry);
    if (!conversationTemplate)
        return false;

    _creatorGuid = creator->GetGUID();

    SetMap(creator->GetMap());
    Relocate(pos);

    Object::_Create(ObjectGuid::Create<HighGuid::Conversation>(GetMapId(), conversationEntry, creator->GetMap()->GenerateLowGuid<HighGuid::Conversation>()));
    SetPhaseMask(creator->GetPhaseMask(), false);
    CopyPhaseFrom(creator);

    SetEntry(conversationEntry);
    SetObjectScale(1.0f);

    SetUInt32Value(CONVERSATION_LAST_LINE_END_TIME, conversationTemplate->LastLineEndTime);
    _duration = conversationTemplate->LastLineEndTime;

    uint16 actorsIndex = 0;
    for (ConversationActorTemplate const* actor : conversationTemplate->Actors)
    {
        if (actor)
        {
            ConversationDynamicFieldActor actorField;
            actorField.ActorTemplate = *actor;
            actorField.Type = ConversationDynamicFieldActor::ActorType::CreatureActor;
            SetDynamicStructuredValue(CONVERSATION_DYNAMIC_FIELD_ACTORS, actorsIndex++, &actorField);
        }
        else
            ++actorsIndex;
    }

    uint16 linesIndex = 0;
    for (ConversationLineTemplate const* line : conversationTemplate->Lines)
        SetDynamicStructuredValue(CONVERSATION_DYNAMIC_FIELD_LINES, linesIndex++, line);

    if (!GetMap()->AddToMap(this))
        return false;

    return true;
}

void Conversation::AddActor(ObjectGuid const& actorGuid, int16 actorIdx /*= -1*/)
{
    ConversationDynamicFieldActor actorField;
    actorField.ActorGuid = actorGuid;
    actorField.Type = ConversationDynamicFieldActor::ActorType::WorldObjectActor;
    if (actorIdx < 0)
        AddDynamicStructuredValue(CONVERSATION_DYNAMIC_FIELD_ACTORS, &actorField);
    else
        SetDynamicStructuredValue(CONVERSATION_DYNAMIC_FIELD_ACTORS, actorIdx, &actorField);
}
