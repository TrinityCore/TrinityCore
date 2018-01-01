/*
 * Copyright (C) 2008-2018 TrinityCore <https://www.trinitycore.org/>
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
#include "Creature.h"
#include "IteratorPair.h"
#include "Log.h"
#include "Map.h"
#include "ScriptMgr.h"
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

bool Conversation::IsNeverVisibleFor(WorldObject const* seer) const
{
    if (_participants.find(seer->GetGUID()) == _participants.end())
        return true;

    return WorldObject::IsNeverVisibleFor(seer);
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

Conversation* Conversation::CreateConversation(uint32 conversationEntry, Unit* creator, Position const& pos, GuidUnorderedSet&& participants, SpellInfo const* spellInfo /*= nullptr*/)
{
    ConversationTemplate const* conversationTemplate = sConversationDataStore->GetConversationTemplate(conversationEntry);
    if (!conversationTemplate)
        return nullptr;

    ObjectGuid::LowType lowGuid = creator->GetMap()->GenerateLowGuid<HighGuid::Conversation>();

    Conversation* conversation = new Conversation();
    if (!conversation->Create(lowGuid, conversationEntry, creator->GetMap(), creator, pos, std::move(participants), spellInfo))
    {
        delete conversation;
        return nullptr;
    }

    return conversation;
}

bool Conversation::Create(ObjectGuid::LowType lowGuid, uint32 conversationEntry, Map* map, Unit* creator, Position const& pos, GuidUnorderedSet&& participants, SpellInfo const* /*spellInfo = nullptr*/)
{
    ConversationTemplate const* conversationTemplate = sConversationDataStore->GetConversationTemplate(conversationEntry);
    ASSERT(conversationTemplate);

    _creatorGuid = creator->GetGUID();
    _participants = std::move(participants);

    SetMap(map);
    Relocate(pos);

    Object::_Create(ObjectGuid::Create<HighGuid::Conversation>(GetMapId(), conversationEntry, lowGuid));
    SetPhaseMask(creator->GetPhaseMask(), false);
    CopyPhaseFrom(creator);

    SetEntry(conversationEntry);
    SetObjectScale(1.0f);

    SetUInt32Value(CONVERSATION_LAST_LINE_END_TIME, conversationTemplate->LastLineEndTime);
    _duration = conversationTemplate->LastLineEndTime;

    for (uint16 actorIndex = 0; actorIndex < conversationTemplate->Actors.size(); ++actorIndex)
    {
        if (ConversationActorTemplate const* actor = conversationTemplate->Actors[actorIndex])
        {
            ConversationDynamicFieldActor actorField;
            actorField.ActorTemplate = *actor;
            actorField.Type = ConversationDynamicFieldActor::ActorType::CreatureActor;
            SetDynamicStructuredValue(CONVERSATION_DYNAMIC_FIELD_ACTORS, actorIndex, &actorField);
        }
    }

    for (uint16 actorIndex = 0; actorIndex < conversationTemplate->ActorGuids.size(); ++actorIndex)
    {
        ObjectGuid::LowType const& actorGuid = conversationTemplate->ActorGuids[actorIndex];
        if (!actorGuid)
            continue;

        for (auto const& pair : Trinity::Containers::MapEqualRange(map->GetCreatureBySpawnIdStore(), actorGuid))
        {
            // we just need the last one, overriding is legit
            AddActor(pair.second->GetGUID(), actorIndex);
        }
    }

    std::set<uint16> actorIndices;
    for (ConversationLineTemplate const* line : conversationTemplate->Lines)
    {
        actorIndices.insert(line->ActorIdx);
        AddDynamicStructuredValue(CONVERSATION_DYNAMIC_FIELD_LINES, line);
    }

    sScriptMgr->OnConversationCreate(this, creator);

    // All actors need to be set
    for (uint16 actorIndex : actorIndices)
    {
        ConversationDynamicFieldActor const* actor = GetDynamicStructuredValue<ConversationDynamicFieldActor>(CONVERSATION_DYNAMIC_FIELD_ACTORS, actorIndex);
        if (!actor || actor->IsEmpty())
        {
            TC_LOG_ERROR("entities.conversation", "Failed to create conversation (Id: %u) due to missing actor (Idx: %u).", conversationEntry, actorIndex);
            return false;
        }
    }

    if (!GetMap()->AddToMap(this))
        return false;

    return true;
}

void Conversation::AddActor(ObjectGuid const& actorGuid, uint16 actorIdx)
{
    ConversationDynamicFieldActor actorField;
    actorField.ActorGuid = actorGuid;
    actorField.Type = ConversationDynamicFieldActor::ActorType::WorldObjectActor;
    SetDynamicStructuredValue(CONVERSATION_DYNAMIC_FIELD_ACTORS, actorIdx, &actorField);
}

void Conversation::AddParticipant(ObjectGuid const& participantGuid)
{
    _participants.insert(participantGuid);
}

uint32 Conversation::GetScriptId() const
{
    return sConversationDataStore->GetConversationTemplate(GetEntry())->ScriptId;
}
