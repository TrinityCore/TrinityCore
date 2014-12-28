/*
 * Copyright (C) 2008-2014 TrinityCore <http://www.trinitycore.org/>
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

void WorldPackets::Quest::QuestGiverStatusQuery::Read()
{
    _worldPacket >> QuestGiverGUID;
}

WorldPacket const* WorldPackets::Quest::QuestGiverStatus::Write()
{
    _worldPacket << QuestGiver.Guid;
    _worldPacket << QuestGiver.Status;

    return &_worldPacket;
}

WorldPacket const* WorldPackets::Quest::QuestGiverStatusMultiple::Write()
{
    _worldPacket << int32(QuestGiver.size());
    for (QuestGiverInfo const& questGiver : QuestGiver)
    {
        _worldPacket << questGiver.Guid;
        _worldPacket << questGiver.Status;
    }

    return &_worldPacket;
}

void WorldPackets::Quest::QuestGiverHello::Read()
{
    _worldPacket >> QuestGiverGUID;
}

void WorldPackets::Quest::QueryQuestInfo::Read()
{
    _worldPacket >> QuestID;
    _worldPacket >> QuestGiver;
}

WorldPacket const* WorldPackets::Quest::QueryQuestInfoResponse::Write()
{
    _worldPacket << QuestID;

    _worldPacket.WriteBit(Allow);
    _worldPacket.FlushBits();

    if (Allow)
    {
        _worldPacket << Info.QuestID;
        _worldPacket << Info.QuestType;
        _worldPacket << Info.QuestLevel;
        _worldPacket << Info.QuestPackageID;
        _worldPacket << Info.QuestMinLevel;
        _worldPacket << Info.QuestSortID;
        _worldPacket << Info.QuestInfoID;
        _worldPacket << Info.SuggestedGroupNum;
        _worldPacket << Info.RewardNextQuest;
        _worldPacket << Info.RewardXPDifficulty;
        _worldPacket << float(1.0f); // Unk Float10
        _worldPacket << Info.RewardMoney;
        _worldPacket << Info.RewardMoneyDifficulty;
        _worldPacket << float(1.0f); // Unk Float13
        _worldPacket << Info.RewardBonusMoney;
        _worldPacket << Info.RewardDisplaySpell;
        _worldPacket << Info.RewardSpell;
        _worldPacket << Info.RewardHonor;
        _worldPacket << Info.RewardKillHonor;
        _worldPacket << Info.StartItem;
        _worldPacket << Info.Flags;
        _worldPacket << Info.FlagsEx;

        for (uint32 i = 0; i < QUEST_REWARD_ITEM_COUNT; ++i)
        {
            _worldPacket << Info.RewardItems[i];
            _worldPacket << Info.RewardAmount[i];
            _worldPacket << Info.ItemDrop[i];
            _worldPacket << Info.ItemDropQuantity[i];
        }

        for (uint32 i = 0; i < QUEST_REWARD_CHOICES_COUNT; ++i)
        {
            _worldPacket << Info.UnfilteredChoiceItems[i].ItemID;
            _worldPacket << Info.UnfilteredChoiceItems[i].Quantity;
            _worldPacket << Info.UnfilteredChoiceItems[i].DisplayID;
        }

        _worldPacket << Info.POIContinent;
        _worldPacket << Info.POIx;
        _worldPacket << Info.POIy;
        _worldPacket << Info.POIPriority;

        _worldPacket << Info.RewardTitle;
        _worldPacket << Info.RewardTalents;
        _worldPacket << Info.RewardArenaPoints;
        _worldPacket << Info.RewardSkillLineID;
        _worldPacket << Info.RewardNumSkillUps;

        _worldPacket << Info.PortraitGiver;
        _worldPacket << Info.PortraitTurnIn;

        for (uint32 i = 0; i < QUEST_REWARD_REPUTATIONS_COUNT; ++i)
        {
            _worldPacket << Info.RewardFactionID[i];
            _worldPacket << Info.RewardFactionValue[i];
            _worldPacket << Info.RewardFactionOverride[i];
        }

        _worldPacket << Info.RewardFactionFlags;

        for (uint32 i = 0; i < QUEST_REWARD_CURRENCY_COUNT; ++i)
        {
            _worldPacket << Info.RewardCurrencyID[i];
            _worldPacket << Info.RewardCurrencyQty[i];
        }

        _worldPacket << Info.AcceptedSoundKitID;
        _worldPacket << Info.CompleteSoundKitID;

        _worldPacket << Info.AreaGroupID;
        _worldPacket << Info.TimeAllowed;

        _worldPacket << int32(Info.Objectives.size());
        _worldPacket << int32(-1); // Unk Int2950

        for (uint32 i = 0; i < Info.Objectives.size(); ++i)
        {
            _worldPacket << Info.Objectives[i].ID;
            _worldPacket << Info.Objectives[i].Type;
            _worldPacket << Info.Objectives[i].StorageIndex;
            _worldPacket << Info.Objectives[i].ObjectID;
            _worldPacket << Info.Objectives[i].Amount;
            _worldPacket << Info.Objectives[i].Flags;
            _worldPacket << Info.Objectives[i].UnkFloat;

            _worldPacket << int32(Info.Objectives[i].VisualEffects.size());
            for (uint32 j = 0; j < Info.Objectives[i].VisualEffects.size(); ++j)
                _worldPacket << Info.Objectives[i].VisualEffects[i];

            _worldPacket.WriteBits(Info.Objectives[i].Description.size(), 8);
            _worldPacket.WriteString(Info.Objectives[i].Description);
        }

        _worldPacket.WriteBits(Info.LogTitle.size(), 9);
        _worldPacket.WriteBits(Info.LogDescription.size(), 12);
        _worldPacket.WriteBits(Info.QuestDescription.size(), 12);
        _worldPacket.WriteBits(Info.AreaDescription.size(), 9);
        _worldPacket.WriteBits(Info.PortraitGiverText.size(), 10);
        _worldPacket.WriteBits(Info.PortraitGiverName.size(), 8);
        _worldPacket.WriteBits(Info.PortraitTurnInText.size(), 10);
        _worldPacket.WriteBits(Info.PortraitTurnInName.size(), 8);
        _worldPacket.WriteBits(Info.QuestCompletionLog.size(), 11);
        _worldPacket.FlushBits();

        _worldPacket.WriteString(Info.LogTitle);
        _worldPacket.WriteString(Info.LogDescription);
        _worldPacket.WriteString(Info.QuestDescription);
        _worldPacket.WriteString(Info.AreaDescription);
        _worldPacket.WriteString(Info.PortraitGiverText);
        _worldPacket.WriteString(Info.PortraitGiverName);
        _worldPacket.WriteString(Info.PortraitTurnInText);
        _worldPacket.WriteString(Info.PortraitTurnInName);
        _worldPacket.WriteString(Info.QuestCompletionLog);
    }

    return &_worldPacket;
}

WorldPacket const* WorldPackets::Quest::QuestUpdateAddCredit::Write()
{
    _worldPacket << VictimGUID;
    _worldPacket << QuestID;
    _worldPacket << ObjectID;
    _worldPacket << Count;
    _worldPacket << Required;
    _worldPacket << ObjectiveType;

    return &_worldPacket;
};

ByteBuffer& operator<<(ByteBuffer& data, WorldPackets::Quest::QuestRewards const& questRewards)
{
    data << questRewards.ChoiceItemCount;

    for (uint32 i = 0; i < QUEST_REWARD_CHOICES_COUNT; ++i)
    {
        data << questRewards.ChoiceItems[i].ItemID;
        data << questRewards.ChoiceItems[i].Quantity;
    }

    data << questRewards.ItemCount;

    for (uint32 i = 0; i < QUEST_REWARD_ITEM_COUNT; ++i)
    {
        data << questRewards.ItemID[i];
        data << questRewards.ItemQty[i];
    }

    data << questRewards.Money;
    data << questRewards.XP;
    data << questRewards.Title;
    data << questRewards.Talents;
    data << questRewards.FactionFlags;

    for (uint32 i = 0; i < QUEST_REWARD_REPUTATIONS_COUNT; ++i)
    {
        data << questRewards.FactionID[i];
        data << questRewards.FactionValue[i];
        data << questRewards.FactionOverride[i];
    }

    data << questRewards.SpellCompletionDisplayID;
    data << questRewards.SpellCompletionID;

    for (uint32 i = 0; i < QUEST_REWARD_CURRENCY_COUNT; ++i)
    {
        data << questRewards.CurrencyID[i];
        data << questRewards.CurrencyQty[i];
    }

    data << questRewards.SkillLineID;
    data << questRewards.NumSkillUps;

    data.WriteBit(false); // Unk
    data.FlushBits();

    return data;
}

ByteBuffer& operator<<(ByteBuffer& data, WorldPackets::Quest::QuestGiverOfferReward const& offer)
{
    data << offer.QuestGiverGUID;
    data << offer.QuestGiverCreatureID;
    data << offer.QuestID;
    data << offer.QuestFlags[0]; // Flags
    data << offer.QuestFlags[1]; // FlagsEx
    data << offer.SuggestedPartyMembers;
    data << offer.Rewards; // WorldPackets::Quest::QuestRewards

    data << int32(offer.Emotes.size());
    for (WorldPackets::Quest::QuestDescEmote const& emote : offer.Emotes)
    {
        data << emote.Type;
        data << emote.Delay;
    }

    data.WriteBit(offer.AutoLaunched);
    data.FlushBits();

    return data;
}

WorldPacket const* WorldPackets::Quest::QuestGiverOfferRewardMessage::Write()
{
    _worldPacket << QuestData; // WorldPackets::Quest::QuestGiverOfferReward
    _worldPacket << PortraitTurnIn;
    _worldPacket << PortraitGiver;
    _worldPacket << QuestPackageID;

    _worldPacket.WriteBits(QuestTitle.size(), 9);
    _worldPacket.WriteBits(RewardText.size(), 12);
    _worldPacket.WriteBits(PortraitTurnInText.size(), 10);
    _worldPacket.WriteBits(PortraitGiverName.size(), 8);
    _worldPacket.WriteBits(PortraitGiverText.size(), 10);
    _worldPacket.WriteBits(PortraitTurnInName.size(), 8);

    _worldPacket.WriteString(QuestTitle);
    _worldPacket.WriteString(RewardText);
    _worldPacket.WriteString(PortraitTurnInText);
    _worldPacket.WriteString(PortraitGiverName);
    _worldPacket.WriteString(PortraitGiverText);
    _worldPacket.WriteString(PortraitTurnInName);

    return &_worldPacket;
};

void WorldPackets::Quest::QuestGiverChooseReward::Read()
{
    _worldPacket >> QuestGiverGUID;
    _worldPacket >> QuestID;
    _worldPacket >> ItemChoiceID;
}

WorldPacket const* WorldPackets::Quest::QuestGiverQuestComplete::Write()
{
    _worldPacket << QuestID;
    _worldPacket << SkillLineIDReward;
    _worldPacket << MoneyReward;
    _worldPacket << NumSkillUpsReward;
    _worldPacket << XPReward;
    _worldPacket << TalentReward;
    _worldPacket << ItemReward; // WorldPackets::Item::ItemInstance

    _worldPacket.WriteBit(UseQuestReward);
    _worldPacket.WriteBit(LaunchGossip);
    _worldPacket.FlushBits();

    return &_worldPacket;
}

void WorldPackets::Quest::QuestGiverCompleteQuest::Read()
{
    _worldPacket >> QuestGiverGUID;
    _worldPacket >> QuestID;
    FromScript = _worldPacket.ReadBit();
}
