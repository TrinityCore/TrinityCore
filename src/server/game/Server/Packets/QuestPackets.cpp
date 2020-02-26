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

#include "QuestPackets.h"

void WorldPackets::Quest::QueryQuestInfo::Read()
{
    _worldPacket >> QuestID;
}

WorldPacket const* WorldPackets::Quest::QueryQuestInfoResponse::Write()
{
    _worldPacket << uint32(Info.QuestID);
    _worldPacket << uint32(Info.QuestMethod);
    _worldPacket << uint32(Info.QuestLevel);
    _worldPacket << uint32(Info.QuestMinLevel);
    _worldPacket << uint32(Info.QuestSortID);

    _worldPacket << uint32(Info.QuestType);
    _worldPacket << uint32(Info.SuggestedGroupNum);

    for (uint8 i = 0; i < PVP_TEAMS_COUNT; ++i)
    {
        _worldPacket << uint32(Info.RequiredFactionId[i]);
        _worldPacket << uint32(Info.RequiredFactionValue[i]);
    }

    _worldPacket << uint32(Info.RewardNextQuest);
    _worldPacket << uint32(Info.RewardXPDifficulty);

    if ((Info.Flags & QUEST_FLAGS_HIDDEN_REWARDS) != 0)
        _worldPacket << uint32(0);
    else
        _worldPacket << uint32(Info.RewardMoney);

    _worldPacket << uint32(Info.RewardBonusMoney);
    _worldPacket << uint32(Info.RewardDisplaySpell);
    _worldPacket << int32(Info.RewardSpell);

    _worldPacket << uint32(Info.RewardHonor);
    _worldPacket << float(Info.RewardKillHonor);
    _worldPacket << uint32(Info.StartItem);
    _worldPacket << uint32(Info.Flags & 0xFFFF);
    _worldPacket << uint32(Info.RewardTitleId);
    _worldPacket << uint32(Info.RequiredPlayerKills);
    _worldPacket << uint32(Info.RewardTalents);
    _worldPacket << uint32(Info.RewardArenaPoints);
    _worldPacket << uint32(0);                                    // review rep show mask

    if ((Info.Flags & QUEST_FLAGS_HIDDEN_REWARDS) != 0)
    {
        for (uint8 i = 0; i < QUEST_REWARDS_COUNT; ++i)
            _worldPacket << uint32(0) << uint32(0);
        for (uint8 i = 0; i < QUEST_REWARD_CHOICES_COUNT; ++i)
            _worldPacket << uint32(0) << uint32(0);
    }
    else
    {
        for (uint8 i = 0; i < QUEST_REWARDS_COUNT; ++i)
        {
            _worldPacket << uint32(Info.RewardItems[i]);
            _worldPacket << uint32(Info.RewardAmount[i]);
        }
        for (uint8 i = 0; i < QUEST_REWARD_CHOICES_COUNT; ++i)
        {
            _worldPacket << uint32(Info.UnfilteredChoiceItems[i].ItemID);
            _worldPacket << uint32(Info.UnfilteredChoiceItems[i].Quantity);
        }
    }

    for (uint8 i = 0; i < QUEST_REPUTATIONS_COUNT; ++i)             // reward factions ids
        _worldPacket << uint32(Info.RewardFactionID[i]);

    for (uint8 i = 0; i < QUEST_REPUTATIONS_COUNT; ++i)             // columnid+1 QuestFactionReward.dbc?
        _worldPacket << int32(Info.RewardFactionValue[i]);

    for (uint8 i = 0; i < QUEST_REPUTATIONS_COUNT; ++i)             // unk (0)
        _worldPacket << int32(Info.RewardFactionValueOverride[i]);

    _worldPacket << uint32(Info.POIContinent);
    _worldPacket << float(Info.POIx);
    _worldPacket << float(Info.POIy);
    _worldPacket << uint32(Info.POIPriority);

    _worldPacket << Info.Title;
    _worldPacket << Info.Objectives;
    _worldPacket << Info.Details;
    _worldPacket << Info.AreaDescription;
    _worldPacket << Info.CompletedText;

    for (uint8 i = 0; i < QUEST_OBJECTIVES_COUNT; ++i)
    {
        if (Info.RequiredNpcOrGo[i] < 0)
            _worldPacket << uint32((Info.RequiredNpcOrGo[i] * (-1)) | 0x80000000);    // client expects gameobject template id in form (id|0x80000000)
        else
            _worldPacket << uint32(Info.RequiredNpcOrGo[i]);

        _worldPacket << uint32(Info.RequiredNpcOrGoCount[i]);

        _worldPacket << uint32(Info.ItemDrop[i]);
        _worldPacket << uint32(0);                                     // req source count?
    }

    for (uint8 i = 0; i < QUEST_ITEM_OBJECTIVES_COUNT; ++i)
    {
        _worldPacket << uint32(Info.RequiredItemId[i]);
        _worldPacket << uint32(Info.RequiredItemCount[i]);
    }

    for (uint8 i = 0; i < QUEST_OBJECTIVES_COUNT; ++i)
        _worldPacket << Info.ObjectiveText[i];

    return &_worldPacket;
}
