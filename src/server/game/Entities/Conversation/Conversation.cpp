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

#include "Conversation.h"
#include "Creature.h"
#include "IteratorPair.h"
#include "Log.h"
#include "Map.h"
#include "PhasingHandler.h"
#include "ScriptMgr.h"
#include "Unit.h"
#include "UpdateData.h"

Conversation::Conversation() : WorldObject(false), _duration(0), _textureKitId(0)
{
    m_objectType |= TYPEMASK_CONVERSATION;
    m_objectTypeId = TYPEID_CONVERSATION;

    m_updateFlag.Stationary = true;
    m_updateFlag.Conversation = true;
}

Conversation::~Conversation() = default;

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
    {
        _duration -= diff;
        DoWithSuppressingObjectUpdates([&]()
        {
            // Only sent in CreateObject
            ApplyModUpdateFieldValue(m_values.ModifyValue(&Conversation::m_conversationData).ModifyValue(&UF::ConversationData::Progress), int32(diff), true);
            const_cast<UF::ConversationData&>(*m_conversationData).ClearChanged(&UF::ConversationData::Progress);
        });
    }
    else
    {
        Remove(); // expired
        return;
    }

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
    RelocateStationaryPosition(pos);

    Object::_Create(ObjectGuid::Create<HighGuid::Conversation>(GetMapId(), conversationEntry, lowGuid));
    PhasingHandler::InheritPhaseShift(this, creator);

    SetEntry(conversationEntry);
    SetObjectScale(1.0f);

    SetUpdateFieldValue(m_values.ModifyValue(&Conversation::m_conversationData).ModifyValue(&UF::ConversationData::LastLineEndTime), conversationTemplate->LastLineEndTime);
    _duration = conversationTemplate->LastLineEndTime;
    _textureKitId = conversationTemplate->TextureKitId;

    for (ConversationActorTemplate const* actor : conversationTemplate->Actors)
    {
        if (actor)
        {
            UF::ConversationActor& actorField = AddDynamicUpdateFieldValue(m_values.ModifyValue(&Conversation::m_conversationData).ModifyValue(&UF::ConversationData::Actors));
            actorField.CreatureID = actor->CreatureId;
            actorField.CreatureDisplayInfoID = actor->CreatureModelId;
            actorField.Id = actor->Id;
            actorField.Type = AsUnderlyingType(ActorType::CreatureActor);
        }
    }

    for (uint16 actorIndex = 0; actorIndex < conversationTemplate->ActorGuids.size(); ++actorIndex)
    {
        ObjectGuid::LowType actorGuid = conversationTemplate->ActorGuids[actorIndex];
        if (!actorGuid)
            continue;

        for (auto const& pair : Trinity::Containers::MapEqualRange(map->GetCreatureBySpawnIdStore(), actorGuid))
        {
            // we just need the last one, overriding is legit
            AddActor(pair.second->GetGUID(), actorIndex);
        }
    }

    std::set<uint16> actorIndices;
    std::vector<UF::ConversationLine> lines;
    for (ConversationLineTemplate const* line : conversationTemplate->Lines)
    {
        actorIndices.insert(line->ActorIdx);
        lines.emplace_back();
        UF::ConversationLine& lineField = lines.back();
        lineField.ConversationLineID = line->Id;
        lineField.StartTime = line->StartTime;
        lineField.UiCameraID = line->UiCameraID;
        lineField.ActorIndex = line->ActorIdx;
        lineField.Flags = line->Flags;
    }

    SetUpdateFieldValue(m_values.ModifyValue(&Conversation::m_conversationData).ModifyValue(&UF::ConversationData::Lines), std::move(lines));

    sScriptMgr->OnConversationCreate(this, creator);

    // All actors need to be set
    for (uint16 actorIndex : actorIndices)
    {
        UF::ConversationActor const* actor = actorIndex < m_conversationData->Actors.size() ? &m_conversationData->Actors[actorIndex] : nullptr;
        if (!actor || (!actor->CreatureID && actor->ActorGUID.IsEmpty() && !actor->NoActorObject))
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
    auto actorField = m_values.ModifyValue(&Conversation::m_conversationData).ModifyValue(&UF::ConversationData::Actors, actorIdx);
    SetUpdateFieldValue(actorField.ModifyValue(&UF::ConversationActor::ActorGUID), actorGuid);
    SetUpdateFieldValue(actorField.ModifyValue(&UF::ConversationActor::Type), AsUnderlyingType(ActorType::WorldObjectActor));
}

void Conversation::AddParticipant(ObjectGuid const& participantGuid)
{
    _participants.insert(participantGuid);
}

uint32 Conversation::GetScriptId() const
{
    return sConversationDataStore->GetConversationTemplate(GetEntry())->ScriptId;
}

void Conversation::BuildValuesCreate(ByteBuffer* data, Player const* target) const
{
    UF::UpdateFieldFlag flags = GetUpdateFieldFlagsFor(target);
    std::size_t sizePos = data->wpos();
    *data << uint32(0);
    *data << uint8(flags);
    m_objectData->WriteCreate(*data, flags, this, target);
    m_conversationData->WriteCreate(*data, flags, this, target);
    data->put<uint32>(sizePos, data->wpos() - sizePos - 4);
}

void Conversation::BuildValuesUpdate(ByteBuffer* data, Player const* target) const
{
    UF::UpdateFieldFlag flags = GetUpdateFieldFlagsFor(target);
    std::size_t sizePos = data->wpos();
    *data << uint32(0);
    *data << uint32(m_values.GetChangedObjectTypeMask());

    if (m_values.HasChanged(TYPEID_OBJECT))
        m_objectData->WriteUpdate(*data, flags, this, target);

    if (m_values.HasChanged(TYPEID_CONVERSATION))
        m_conversationData->WriteUpdate(*data, flags, this, target);

    data->put<uint32>(sizePos, data->wpos() - sizePos - 4);
}

void Conversation::BuildValuesUpdateForPlayerWithMask(UpdateData* data, UF::ObjectData::Mask const& requestedObjectMask,
    UF::ConversationData::Mask const& requestedConversationMask, Player const* target) const
{
    UpdateMask<NUM_CLIENT_OBJECT_TYPES> valuesMask;
    if (requestedObjectMask.IsAnySet())
        valuesMask.Set(TYPEID_OBJECT);

    if (requestedConversationMask.IsAnySet())
        valuesMask.Set(TYPEID_CONVERSATION);

    ByteBuffer buffer = PrepareValuesUpdateBuffer();
    std::size_t sizePos = buffer.wpos();
    buffer << uint32(0);
    buffer << uint32(valuesMask.GetBlock(0));

    if (valuesMask[TYPEID_OBJECT])
        m_objectData->WriteUpdate(buffer, requestedObjectMask, true, this, target);

    if (valuesMask[TYPEID_CONVERSATION])
        m_conversationData->WriteUpdate(buffer, requestedConversationMask, true, this, target);

    buffer.put<uint32>(sizePos, buffer.wpos() - sizePos - 4);

    data->AddUpdateBlock(buffer);
}

void Conversation::ClearUpdateMask(bool remove)
{
    m_values.ClearChangesMask(&Conversation::m_conversationData);
    Object::ClearUpdateMask(remove);
}
