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
#include "ConditionMgr.h"
#include "Containers.h"
#include "ConversationDataStore.h"
#include "Creature.h"
#include "DB2Stores.h"
#include "IteratorPair.h"
#include "Log.h"
#include "Map.h"
#include "PhasingHandler.h"
#include "Player.h"
#include "ScriptMgr.h"
#include "UpdateData.h"

Conversation::Conversation() : WorldObject(false), _duration(0), _textureKitId(0)
{
    m_objectType |= TYPEMASK_CONVERSATION;
    m_objectTypeId = TYPEID_CONVERSATION;

    m_updateFlag.Stationary = true;
    m_updateFlag.Conversation = true;

    _lastLineEndTimes.fill(Milliseconds::zero());
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

void Conversation::Update(uint32 diff)
{
    if (GetDuration() > Milliseconds(diff))
    {
        _duration -= Milliseconds(diff);
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

Conversation* Conversation::CreateConversation(uint32 conversationEntry, Unit* creator, Position const& pos, ObjectGuid privateObjectOwner, SpellInfo const* spellInfo /*= nullptr*/)
{
    ConversationTemplate const* conversationTemplate = sConversationDataStore->GetConversationTemplate(conversationEntry);
    if (!conversationTemplate)
        return nullptr;

    ObjectGuid::LowType lowGuid = creator->GetMap()->GenerateLowGuid<HighGuid::Conversation>();

    Conversation* conversation = new Conversation();
    if (!conversation->Create(lowGuid, conversationEntry, creator->GetMap(), creator, pos, privateObjectOwner, spellInfo))
    {
        delete conversation;
        return nullptr;
    }

    return conversation;
}

struct ConversationActorFillVisitor
{
    explicit ConversationActorFillVisitor(Conversation* conversation, Unit const* creator, Map const* map, ConversationActorTemplate const& actor)
        : _conversation(conversation), _creator(creator), _map(map), _actor(actor)
    {
    }

    void operator()(ConversationActorWorldObjectTemplate const& worldObject) const
    {
        Creature const* bestFit = nullptr;

        for (auto const& [_, creature] : Trinity::Containers::MapEqualRange(_map->GetCreatureBySpawnIdStore(), worldObject.SpawnId))
        {
            bestFit = creature;

            // If creature is in a personal phase then we pick that one specifically
            if (creature->GetPhaseShift().GetPersonalGuid() == _creator->GetGUID())
                break;
        }

        if (bestFit)
            _conversation->AddActor(_actor.Id, _actor.Index, bestFit->GetGUID());
    }

    void operator()(ConversationActorNoObjectTemplate const& noObject) const
    {
        _conversation->AddActor(_actor.Id, _actor.Index, ConversationActorType::WorldObject, noObject.CreatureId, noObject.CreatureDisplayInfoId);
    }

    void operator()([[maybe_unused]] ConversationActorActivePlayerTemplate const& activePlayer) const
    {
        _conversation->AddActor(_actor.Id, _actor.Index, ObjectGuid::Create<HighGuid::Player>(0xFFFFFFFFFFFFFFFF));
    }

    void operator()(ConversationActorTalkingHeadTemplate const& talkingHead) const
    {
        _conversation->AddActor(_actor.Id, _actor.Index, ConversationActorType::TalkingHead, talkingHead.CreatureId, talkingHead.CreatureDisplayInfoId);
    }

private:
    Conversation* _conversation;
    Unit const* _creator;
    ::Map const* _map;
    ConversationActorTemplate const& _actor;
};

bool Conversation::Create(ObjectGuid::LowType lowGuid, uint32 conversationEntry, Map* map, Unit* creator, Position const& pos, ObjectGuid privateObjectOwner, SpellInfo const* /*spellInfo = nullptr*/)
{
    ConversationTemplate const* conversationTemplate = sConversationDataStore->GetConversationTemplate(conversationEntry);
    ASSERT(conversationTemplate);

    _creatorGuid = creator->GetGUID();
    SetPrivateObjectOwner(privateObjectOwner);

    SetMap(map);
    Relocate(pos);
    RelocateStationaryPosition(pos);

    Object::_Create(ObjectGuid::Create<HighGuid::Conversation>(GetMapId(), conversationEntry, lowGuid));
    PhasingHandler::InheritPhaseShift(this, creator);

    SetEntry(conversationEntry);
    SetObjectScale(1.0f);

    _textureKitId = conversationTemplate->TextureKitId;

    for (ConversationActorTemplate const& actor : conversationTemplate->Actors)
        std::visit(ConversationActorFillVisitor(this, creator, map, actor), actor.Data);

    std::set<uint16> actorIndices;
    std::vector<UF::ConversationLine> lines;
    for (ConversationLineTemplate const* line : conversationTemplate->Lines)
    {
        if (!sConditionMgr->IsObjectMeetingNotGroupedConditions(CONDITION_SOURCE_TYPE_CONVERSATION_LINE, line->Id, creator))
            continue;

        actorIndices.insert(line->ActorIdx);
        lines.emplace_back();

        UF::ConversationLine& lineField = lines.back();
        lineField.ConversationLineID = line->Id;
        lineField.UiCameraID = line->UiCameraID;
        lineField.ActorIndex = line->ActorIdx;
        lineField.Flags = line->Flags;

        ConversationLineEntry const* convoLine = sConversationLineStore.LookupEntry(line->Id); // never null for conversationTemplate->Lines

        for (LocaleConstant locale = LOCALE_enUS; locale < TOTAL_LOCALES; locale = LocaleConstant(locale + 1))
        {
            if (locale == LOCALE_none)
                continue;

            _lineStartTimes[{ locale, line->Id }] = _lastLineEndTimes[locale];
            if (locale == DEFAULT_LOCALE)
                lineField.StartTime = _lastLineEndTimes[locale].count();

            if (int32 const* broadcastTextDuration = sDB2Manager.GetBroadcastTextDuration(convoLine->BroadcastTextID, locale))
                _lastLineEndTimes[locale] += Milliseconds(*broadcastTextDuration);

            _lastLineEndTimes[locale] += Milliseconds(convoLine->AdditionalDuration);
        }
    }

    _duration = Milliseconds(*std::max_element(_lastLineEndTimes.begin(), _lastLineEndTimes.end()));
    SetUpdateFieldValue(m_values.ModifyValue(&Conversation::m_conversationData).ModifyValue(&UF::ConversationData::LastLineEndTime), _duration.count());
    SetUpdateFieldValue(m_values.ModifyValue(&Conversation::m_conversationData).ModifyValue(&UF::ConversationData::Lines), std::move(lines));

    // conversations are despawned 5-20s after LastLineEndTime
    _duration += 10s;

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

void Conversation::AddActor(int32 actorId, uint32 actorIdx, ObjectGuid const& actorGuid)
{
    auto actorField = m_values.ModifyValue(&Conversation::m_conversationData).ModifyValue(&UF::ConversationData::Actors, actorIdx);
    SetUpdateFieldValue(actorField.ModifyValue(&UF::ConversationActor::CreatureID), 0);
    SetUpdateFieldValue(actorField.ModifyValue(&UF::ConversationActor::CreatureDisplayInfoID), 0);
    SetUpdateFieldValue(actorField.ModifyValue(&UF::ConversationActor::ActorGUID), actorGuid);
    SetUpdateFieldValue(actorField.ModifyValue(&UF::ConversationActor::Id), actorId);
    SetUpdateFieldValue(actorField.ModifyValue(&UF::ConversationActor::Type), AsUnderlyingType(ConversationActorType::WorldObject));
    SetUpdateFieldValue(actorField.ModifyValue(&UF::ConversationActor::NoActorObject), 0);
}

void Conversation::AddActor(int32 actorId, uint32 actorIdx, ConversationActorType type, uint32 creatureId, uint32 creatureDisplayInfoId)
{
    auto actorField = m_values.ModifyValue(&Conversation::m_conversationData).ModifyValue(&UF::ConversationData::Actors, actorIdx);
    SetUpdateFieldValue(actorField.ModifyValue(&UF::ConversationActor::CreatureID), creatureId);
    SetUpdateFieldValue(actorField.ModifyValue(&UF::ConversationActor::CreatureDisplayInfoID), creatureDisplayInfoId);
    SetUpdateFieldValue(actorField.ModifyValue(&UF::ConversationActor::ActorGUID), ObjectGuid::Empty);
    SetUpdateFieldValue(actorField.ModifyValue(&UF::ConversationActor::Id), actorId);
    SetUpdateFieldValue(actorField.ModifyValue(&UF::ConversationActor::Type), AsUnderlyingType(type));
    SetUpdateFieldValue(actorField.ModifyValue(&UF::ConversationActor::NoActorObject), type == ConversationActorType::WorldObject ? 1 : 0);
}

Milliseconds const* Conversation::GetLineStartTime(LocaleConstant locale, int32 lineId) const
{
    return Trinity::Containers::MapGetValuePtr(_lineStartTimes, { locale, lineId });
}

Milliseconds Conversation::GetLastLineEndTime(LocaleConstant locale) const
{
    return _lastLineEndTimes[locale];
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

void Conversation::ValuesUpdateForPlayerWithMaskSender::operator()(Player const* player) const
{
    UpdateData udata(Owner->GetMapId());
    WorldPacket packet;

    Owner->BuildValuesUpdateForPlayerWithMask(&udata, ObjectMask.GetChangesMask(), ConversationMask.GetChangesMask(), player);

    udata.BuildPacket(&packet);
    player->SendDirectMessage(&packet);
}

void Conversation::ClearUpdateMask(bool remove)
{
    m_values.ClearChangesMask(&Conversation::m_conversationData);
    Object::ClearUpdateMask(remove);
}
