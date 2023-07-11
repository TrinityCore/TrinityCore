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

void WorldPackets::Quest::QuestLogRemoveQuest::Read()
{
    _worldPacket >> Entry;
}

void WorldPackets::Quest::QuestConfirmAccept::Read()
{
    _worldPacket >> QuestID;
}

void WorldPackets::Quest::QueryQuestInfo::Read()
{
    _worldPacket >> QuestID;
}

WorldPacket const* WorldPackets::Quest::QuestGiverQuestListMessage::Write()
{
    _worldPacket << QuestGiverGUID;
    _worldPacket << Greeting;
    _worldPacket << uint32(GreetEmoteDelay);
    _worldPacket << uint32(GreetEmoteType);

    _worldPacket << uint8(QuestDataText.size());
    for (GossipText const& gossip : QuestDataText)
    {
        _worldPacket << uint32(gossip.QuestID);
        _worldPacket << uint32(gossip.QuestType);
        _worldPacket << int32(gossip.QuestLevel);
        _worldPacket << uint32(gossip.QuestFlags);
        _worldPacket << uint8(gossip.Repeatable);
        _worldPacket << gossip.QuestTitle;
    }

    return &_worldPacket;
}

WorldPacket const* WorldPackets::Quest::QuestGiverStatus::Write()
{
    _worldPacket << QuestGiver.Guid;
    _worldPacket << uint32(QuestGiver.Status);

    return &_worldPacket;
}

WorldPacket const* WorldPackets::Quest::QuestGiverQuestDetails::Write()
{
    _worldPacket << QuestGiverGUID;
    _worldPacket << InformUnit;
    _worldPacket << uint32(QuestID);
    _worldPacket << QuestTitle;
    _worldPacket << LogDescription;
    _worldPacket << Objectives;
    _worldPacket << PortraitGiverText;
    _worldPacket << PortraitGiverName;
    _worldPacket << PortraitTurnInText;
    _worldPacket << PortraitTurnInName;
    _worldPacket << uint32(PortraitGiver);
    _worldPacket << uint32(PortraitTurnIn);
    _worldPacket << uint8(AutoLaunched);
    _worldPacket << uint32(QuestFlags);
    _worldPacket << uint32(SuggestedPartyMembers);
    _worldPacket << uint8(StartCheat);
    _worldPacket << uint8(DisplayPopup);
    _worldPacket << uint32(RequiredSpellID);

    _worldPacket << Rewards;

    _worldPacket << uint32(DescEmotes.size());
    for (WorldPackets::Quest::QuestDescEmote const& emote : DescEmotes)
    {
        _worldPacket << uint32(emote.Type);
        _worldPacket << uint32(emote.Delay);
    }

    return &_worldPacket;
}

WorldPacket const* WorldPackets::Quest::QuestGiverQuestComplete::Write()
{
    _worldPacket << uint32(TalentReward);
    _worldPacket << uint32(NumSkillUpsReward);
    _worldPacket << uint32(MoneyReward);
    _worldPacket << uint32(XPReward);
    _worldPacket << uint32(QuestID);
    _worldPacket << uint32(SkillLineIDReward);

    _worldPacket.WriteBit(LaunchGossip);
    _worldPacket.WriteBit(UseQuestReward);
    _worldPacket.FlushBits();

    return &_worldPacket;
}

WorldPacket const* WorldPackets::Quest::QuestConfirmAcceptResponse::Write()
{
    _worldPacket << uint32(QuestID);
    _worldPacket << QuestTitle;
    _worldPacket << InitiatedBy;

    return &_worldPacket;
}

WorldPacket const* WorldPackets::Quest::QuestUpdateAddCredit::Write()
{
    _worldPacket << uint32(QuestID);
    _worldPacket << uint32(ObjectID);
    _worldPacket << uint32(Count);
    _worldPacket << uint32(Required);
    _worldPacket << VictimGUID;

    return &_worldPacket;
}

WorldPacket const* WorldPackets::Quest::QuestUpdateAddPvPCredit::Write()
{
    _worldPacket << uint32(QuestID);
    _worldPacket << uint32(Count);
    _worldPacket << uint32(Required);

    return &_worldPacket;
}

WorldPacket const* WorldPackets::Quest::QuestUpdateComplete::Write()
{
    _worldPacket << uint32(QuestID);

    return &_worldPacket;
}

WorldPacket const* WorldPackets::Quest::QuestUpdateFailedTimer::Write()
{
    _worldPacket << uint32(QuestID);

    return &_worldPacket;
}

WorldPacket const* WorldPackets::Quest::QuestGiverInvalidQuest::Write()
{
    _worldPacket << uint32(Reason);

    return &_worldPacket;
}

WorldPacket const* WorldPackets::Quest::QuestGiverQuestFailed::Write()
{
    _worldPacket << uint32(QuestID);
    _worldPacket << uint32(Reason);

    return &_worldPacket;
}

WorldPacket const* WorldPackets::Quest::QuestPushResultResponse::Write()
{
    _worldPacket << SenderGUID;
    _worldPacket << uint8(Result);

    return &_worldPacket;
}

WorldPacket const* WorldPackets::Quest::QuestGiverStatusMultiple::Write()
{
    _worldPacket << int32(QuestGiver.size());
    for (QuestGiverInfo const& questGiver : QuestGiver)
    {
        _worldPacket << questGiver.Guid;
        _worldPacket << uint32(questGiver.Status);
    }

    return &_worldPacket;
}

WorldPacket const* WorldPackets::Quest::QuestGiverOfferRewardMessage::Write()
{
    _worldPacket << QuestData.QuestGiverGUID;
    _worldPacket << uint32(QuestData.QuestID);

    _worldPacket << QuestTitle;
    _worldPacket << RewardText;
    _worldPacket << PortraitGiverText;
    _worldPacket << PortraitGiverName;
    _worldPacket << PortraitTurnInText;
    _worldPacket << PortraitTurnInName;

    _worldPacket << uint32(PortraitGiver);
    _worldPacket << uint32(PortraitTurnIn);
    _worldPacket << uint8(QuestData.AutoLaunched);
    _worldPacket << uint32(QuestData.QuestFlags);
    _worldPacket << uint32(QuestData.SuggestedPartyMembers);

    _worldPacket << uint32(QuestData.Emotes.size());
    for (WorldPackets::Quest::QuestDescEmote const& emote : QuestData.Emotes)
    {
        _worldPacket << uint32(emote.Delay);
        _worldPacket << uint32(emote.Type);
    }

    _worldPacket << QuestData.Rewards;

    return &_worldPacket;
}

WorldPacket const* WorldPackets::Quest::QueryQuestInfoResponse::Write()
{
    _worldPacket << uint32(Info.QuestID);
    _worldPacket << int32(Info.QuestType);
    _worldPacket << int32(Info.QuestLevel);
    _worldPacket << int32(Info.QuestMinLevel);
    _worldPacket << int32(Info.QuestSortID);
    _worldPacket << int32(Info.QuestInfoID);
    _worldPacket << uint32(Info.SuggestedGroupNum);

    for (uint8 i = 0; i < BG_TEAMS_COUNT; ++i)
    {
        _worldPacket << uint32(Info.RequiredFactionId[i]);
        _worldPacket << int32(Info.RequiredFactionValue[i]);
    }

    _worldPacket << int32(Info.RewardNextQuest);
    _worldPacket << uint32(Info.RewardXPDifficulty);

    if ((Info.Flags & QUEST_FLAGS_HIDE_REWARD) != 0)
        _worldPacket << int32(0);
    else
        _worldPacket << int32(Info.RewardMoney);

    _worldPacket << uint32(Info.RewardBonusMoney);
    _worldPacket << int32(Info.RewardDisplaySpell);
    _worldPacket << int32(Info.RewardSpell);
    _worldPacket << int32(Info.RewardHonor);
    _worldPacket << float(Info.RewardKillHonor);
    _worldPacket << uint32(Info.StartItem);
    _worldPacket << uint32(Info.Flags);
    _worldPacket << uint32(Info.MinimapTargetMark);
    _worldPacket << uint32(Info.RewardTitle);
    _worldPacket << uint32(Info.RequiredPlayerKills);
    _worldPacket << uint32(Info.RewardTalents);
    _worldPacket << uint32(Info.RewardArenaPoints);
    _worldPacket << uint32(Info.RewardSkillLineID);
    _worldPacket << uint32(Info.RewardNumSkillUps);
    _worldPacket << uint32(Info.RewardReputationMask);
    _worldPacket << uint32(Info.PortraitGiver);
    _worldPacket << uint32(Info.PortraitTurnIn);

    if ((Info.Flags & QUEST_FLAGS_HIDE_REWARD) != 0)
    {
        for (uint8 i = 0; i < QUEST_REWARDS_COUNT; ++i)
            _worldPacket << int32(0) << uint32(0);
        for (uint8 i = 0; i < QUEST_REWARD_CHOICES_COUNT; ++i)
            _worldPacket << int32(0) << uint32(0);
    }
    else
    {
        for (uint8 i = 0; i < QUEST_REWARDS_COUNT; ++i)
        {
            _worldPacket << int32(Info.RewardItems[i]);
            _worldPacket << uint32(Info.RewardAmount[i]);
        }

        for (uint8 i = 0; i < QUEST_REWARD_CHOICES_COUNT; ++i)
        {
            _worldPacket << int32(Info.UnfilteredChoiceItems[i].ItemID);
            _worldPacket << uint32(Info.UnfilteredChoiceItems[i].Quantity);
        }
    }

    for (uint8 i = 0; i < QUEST_REPUTATIONS_COUNT; ++i)
        _worldPacket << uint32(Info.RewardFactionID[i]);

    for (uint8 i = 0; i < QUEST_REPUTATIONS_COUNT; ++i)
        _worldPacket << int32(Info.RewardFactionValue[i]);

    for (uint8 i = 0; i < QUEST_REPUTATIONS_COUNT; ++i)
        _worldPacket << uint32(Info.RewardFactionValueOverride[i]);

    _worldPacket << uint32(Info.POIContinent);
    _worldPacket << float(Info.POIx);
    _worldPacket << float(Info.POIy);
    _worldPacket << uint32(Info.POIPriority);

    _worldPacket << Info.LogTitle;
    _worldPacket << Info.LogDescription;
    _worldPacket << Info.QuestDescription;
    _worldPacket << Info.AreaDescription;
    _worldPacket << Info.QuestCompletionLog;

    for (uint8 i = 0; i < QUEST_OBJECTIVES_COUNT; ++i)
    {
        if (Info.RequiredNpcOrGo[i] < 0)
            _worldPacket << uint32((Info.RequiredNpcOrGo[i] * (-1)) | 0x80000000);    // client expects gameobject template id in form (id|0x80000000)
        else
            _worldPacket << uint32(Info.RequiredNpcOrGo[i]);

        _worldPacket << uint32(Info.RequiredNpcOrGoCount[i]);

        _worldPacket << int32(Info.ItemDrop[i]);
        _worldPacket << uint32(Info.ItemDropQuantity[i]);
    }

    for (uint8 i = 0; i < QUEST_ITEM_OBJECTIVES_COUNT; ++i)
    {
        _worldPacket << int32(Info.RequiredItemId[i]);
        _worldPacket << uint32(Info.RequiredItemCount[i]);
    }

    _worldPacket << uint32(Info.RequiredSpell);

    for (uint8 i = 0; i < QUEST_OBJECTIVES_COUNT; ++i)
        _worldPacket << Info.ObjectiveText[i];

    for (uint32 i = 0; i < QUEST_REWARD_CURRENCY_COUNT; ++i)
    {
        _worldPacket << uint32(Info.RewardCurrencyID[i]);
        _worldPacket << uint32(Info.RewardCurrencyQty[i]);
    }

    for (uint32 i = 0; i < QUEST_REQUIRED_CURRENCY_COUNT; ++i)
    {
        _worldPacket << uint32(Info.RequiredCurrencyID[i]);
        _worldPacket << uint32(Info.RequiredCurrencyQty[i]);
    }

    _worldPacket << Info.PortraitGiverText;
    _worldPacket << Info.PortraitGiverName;
    _worldPacket << Info.PortraitTurnintext;
    _worldPacket << Info.PortraitTurnInName;


    _worldPacket << uint32(Info.AcceptedSoundKitID);
    _worldPacket << uint32(Info.CompleteSoundKitID);

    return &_worldPacket;
}

ByteBuffer& operator<<(ByteBuffer& data, WorldPackets::Quest::QuestRewards const& questRewards)
{
    data << uint32(questRewards.ChoiceItemCount);
    for (uint32 i = 0; i < QUEST_REWARD_CHOICES_COUNT; ++i)
        data << uint32(questRewards.ChoiceItems[i].ItemID);
    for (uint32 i = 0; i < QUEST_REWARD_CHOICES_COUNT; ++i)
        data << uint32(questRewards.ChoiceItems[i].Quantity);
    for (uint32 i = 0; i < QUEST_REWARD_CHOICES_COUNT; ++i)
        data << uint32(questRewards.ChoiceItems[i].DisplayID);

    data << uint32(questRewards.ItemCount);
    for (uint32 i = 0; i < QUEST_REWARDS_COUNT; ++i)
        data << uint32(questRewards.ItemID[i]);
    for (uint32 i = 0; i < QUEST_REWARDS_COUNT; ++i)
        data << uint32(questRewards.ItemQty[i]);
    for (uint32 i = 0; i < QUEST_REWARDS_COUNT; ++i)
        data << uint32(questRewards.ItemDisplayID[i]);

    data << uint32(questRewards.Money);
    data << uint32(questRewards.XP);
    data << uint32(questRewards.Title);
    data << uint32(0); // unkown
    data << float(0.0f); // unknown
    data << uint32(questRewards.NumBonusTalents);
    data << uint32(0); // unkown
    data << uint32(questRewards.FactionFlags);


    for (uint32 i = 0; i < QUEST_REPUTATIONS_COUNT; ++i)
        data << uint32(questRewards.FactionID[i]);

    for (uint32 i = 0; i < QUEST_REPUTATIONS_COUNT; ++i)
        data << int32(questRewards.FactionValue[i]);

    for (uint32 i = 0; i < QUEST_REPUTATIONS_COUNT; ++i)
        data << uint32(questRewards.FactionOverride[i]);

    data << uint32(questRewards.SpellCompletionDisplayID);
    data << uint32(questRewards.SpellCompletionID);

    for (uint32 i = 0; i < QUEST_REWARD_CURRENCY_COUNT; ++i)
        data << uint32(questRewards.CurrencyID[i]);

    for (uint32 i = 0; i < QUEST_REWARD_CURRENCY_COUNT; ++i)
        data << uint32(questRewards.CurrencyQty[i]);

    data << uint32(questRewards.SkillLineID);
    data << uint32(questRewards.NumSkillUps);

    return data;
}
