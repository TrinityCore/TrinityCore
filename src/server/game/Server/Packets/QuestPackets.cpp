/*
 * Copyright (C) 2008-2019 TrinityCore <https://www.trinitycore.org/>
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

#include "QuestPackets.h"
#include "Errors.h"

WorldPacket const* WorldPackets::Quest::QuestGiverRequestItems::Write()
{
    _worldPacket << QuestGiverGUID;
    _worldPacket << uint32(QuestID);
    _worldPacket << QuestTitle;
    _worldPacket << CompletionText;
    _worldPacket << uint32(CompEmoteDelay);
    _worldPacket << uint32(CompEmoteType);
    _worldPacket << uint32(AutoLaunched);
    _worldPacket << uint32(QuestFlags);
    _worldPacket << uint32(SuggestPartyMembers);
    _worldPacket << uint32(MoneyToGet);

    _worldPacket << uint32(Collect.size());
    for (QuestObjectiveCollect const& obj : Collect)
    {
        _worldPacket << uint32(obj.ObjectID);
        _worldPacket << uint32(obj.Amount);
        _worldPacket << uint32(obj.DisplayID);
    }

    _worldPacket << uint32(Currency.size());
    for (QuestCurrency const& cur : Currency)
    {
        _worldPacket << uint32(cur.CurrencyID);
        _worldPacket << uint32(cur.Amount);
    }

    for (uint8 i = 0; i < 5; i++)
        _worldPacket << uint32(StatusFlags[i]);

    return &_worldPacket;
}

void WorldPackets::Quest::QuestGiverAcceptQuest::Read()
{
    _worldPacket >> QuestGiverGUID;
    _worldPacket >> QuestID;
    _worldPacket >> StartCheat;
}

void WorldPackets::Quest::QuestGiverChooseReward::Read()
{
    _worldPacket >> QuestGiverGUID;
    _worldPacket >> QuestID;
    _worldPacket >> ItemChoiceID;
}

void WorldPackets::Quest::QuestGiverCompleteQuest::Read()
{
    _worldPacket >> QuestGiverGUID;
    _worldPacket >> QuestID;
    _worldPacket >> FromScript;
}

void WorldPackets::Quest::QuestGiverHello::Read()
{
    _worldPacket >> QuestGiverGUID;
}

void WorldPackets::Quest::QuestGiverQueryQuest::Read()
{
    _worldPacket >> QuestGiverGUID;
    _worldPacket >> QuestID;
    _worldPacket >> RespondToGiver;
}

void WorldPackets::Quest::QuestGiverRequestReward::Read()
{
    _worldPacket >> QuestGiverGUID;
    _worldPacket >> QuestID;
}

void WorldPackets::Quest::QuestGiverStatusQuery::Read()
{
    _worldPacket >> QuestGiverGUID;
}
