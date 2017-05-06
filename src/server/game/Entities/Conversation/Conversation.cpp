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
#include "ConversationDataStore.h"
#include "DB2Stores.h"
#include "GridNotifiersImpl.h"
#include "Log.h"
#include "Object.h"
#include "Player.h"
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
        RemoveFromWorld();
        AddObjectToRemoveList();
    }
}

bool Conversation::CreateConversation(uint32 conversationEntry, Unit* caster, SpellInfo const* /*spellInfo*/, Position const& pos)
{
    ConversationTemplate const* conversationTemplate = sConversationDataStore->GetConversationTemplate(conversationEntry);
    if (!conversationTemplate)
        return false;

    _casterGuid = caster->GetGUID();

    SetMap(caster->GetMap());
    Relocate(pos);

    Object::_Create(ObjectGuid::Create<HighGuid::Conversation>(GetMapId(), conversationEntry, caster->GetMap()->GenerateLowGuid<HighGuid::Conversation>()));
    SetPhaseMask(caster->GetPhaseMask(), false);
    CopyPhaseFrom(caster);

    SetEntry(conversationEntry);
    SetObjectScale(1.0f);

    SetUInt32Value(CONVERSATION_LAST_LINE_END_TIME, conversationTemplate->LastLineDuration);
    _duration = conversationTemplate->LastLineDuration;

    uint16 actorsIndex = 0;
    for (ConversationActorTemplate const& actor : conversationTemplate->Actors)
        SetDynamicStructuredValue(CONVERSATION_DYNAMIC_FIELD_ACTORS, actorsIndex++, &actor);

    uint16 linesIndex = 0;
    for (ConversationLineTemplate const& line : conversationTemplate->Lines)
    {
        ConversationLineEntry const* lineEntry = sConversationLineStore.LookupEntry(line.Id);
        _duration += line.PreviousLineDuration + lineEntry->LineIntervalMS;

        SetDynamicStructuredValue(CONVERSATION_DYNAMIC_FIELD_LINES, linesIndex++, &line);
    }

    if (!GetMap()->AddToMap(this))
        return false;

    return true;
}
