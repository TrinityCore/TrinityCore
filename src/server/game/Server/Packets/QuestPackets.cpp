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

#include "QuestPackets.h"

void WorldPackets::Quest::QuestGiverStatusQuery::Read()
{
    _worldPacket >> QuestGiverGUID;
}

WorldPacket const* WorldPackets::Quest::QuestGiverStatus::Write()
{
    _worldPacket << QuestGiver.Guid;
    _worldPacket << uint32(QuestGiver.Status);

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
    _worldPacket << uint32(QuestID);

    _worldPacket.WriteBit(Allow);
    _worldPacket.FlushBits();

    if (Allow)
    {
        _worldPacket << int32(Info.QuestID);
        _worldPacket << int32(Info.QuestType);
        _worldPacket << int32(Info.QuestLevel);
        _worldPacket << int32(Info.QuestPackageID);
        _worldPacket << int32(Info.QuestMinLevel);
        _worldPacket << int32(Info.QuestSortID);
        _worldPacket << int32(Info.QuestInfoID);
        _worldPacket << int32(Info.SuggestedGroupNum);
        _worldPacket << int32(Info.RewardNextQuest);
        _worldPacket << int32(Info.RewardXPDifficulty);
        _worldPacket << float(Info.RewardXPMultiplier);
        _worldPacket << int32(Info.RewardMoney);
        _worldPacket << int32(Info.RewardMoneyDifficulty);
        _worldPacket << float(Info.RewardMoneyMultiplier);
        _worldPacket << int32(Info.RewardBonusMoney);
        _worldPacket << int32(Info.RewardDisplaySpell);
        _worldPacket << int32(Info.RewardSpell);
        _worldPacket << int32(Info.RewardHonor);
        _worldPacket << float(Info.RewardKillHonor);
        _worldPacket << int32(Info.StartItem);
        _worldPacket << uint32(Info.Flags);
        _worldPacket << uint32(Info.FlagsEx);

        for (uint32 i = 0; i < QUEST_REWARD_ITEM_COUNT; ++i)
        {
            _worldPacket << int32(Info.RewardItems[i]);
            _worldPacket << int32(Info.RewardAmount[i]);
            _worldPacket << int32(Info.ItemDrop[i]);
            _worldPacket << int32(Info.ItemDropQuantity[i]);
        }

        for (uint32 i = 0; i < QUEST_REWARD_CHOICES_COUNT; ++i)
        {
            _worldPacket << int32(Info.UnfilteredChoiceItems[i].ItemID);
            _worldPacket << int32(Info.UnfilteredChoiceItems[i].Quantity);
            _worldPacket << int32(Info.UnfilteredChoiceItems[i].DisplayID);
        }

        _worldPacket << int32(Info.POIContinent);
        _worldPacket << float(Info.POIx);
        _worldPacket << float(Info.POIy);
        _worldPacket << int32(Info.POIPriority);

        _worldPacket << int32(Info.RewardTitle);
        _worldPacket << int32(Info.RewardTalents);
        _worldPacket << int32(Info.RewardArenaPoints);
        _worldPacket << int32(Info.RewardSkillLineID);
        _worldPacket << int32(Info.RewardNumSkillUps);

        _worldPacket << int32(Info.PortraitGiver);
        _worldPacket << int32(Info.PortraitTurnIn);

        for (uint32 i = 0; i < QUEST_REWARD_REPUTATIONS_COUNT; ++i)
        {
            _worldPacket << int32(Info.RewardFactionID[i]);
            _worldPacket << int32(Info.RewardFactionValue[i]);
            _worldPacket << int32(Info.RewardFactionOverride[i]);
        }

        _worldPacket << int32(Info.RewardFactionFlags);

        for (uint32 i = 0; i < QUEST_REWARD_CURRENCY_COUNT; ++i)
        {
            _worldPacket << int32(Info.RewardCurrencyID[i]);
            _worldPacket << int32(Info.RewardCurrencyQty[i]);
        }

        _worldPacket << int32(Info.AcceptedSoundKitID);
        _worldPacket << int32(Info.CompleteSoundKitID);

        _worldPacket << int32(Info.AreaGroupID);
        _worldPacket << int32(Info.TimeAllowed);

        _worldPacket << int32(Info.Objectives.size());
        _worldPacket << int32(Info.AllowableRaces);

        for (QuestObjective const& questObjective : Info.Objectives)
        {
            _worldPacket << uint32(questObjective.ID);
            _worldPacket << uint8(questObjective.Type);
            _worldPacket << int8(questObjective.StorageIndex);
            _worldPacket << int32(questObjective.ObjectID);
            _worldPacket << int32(questObjective.Amount);
            _worldPacket << uint32(questObjective.Flags);
            _worldPacket << float(questObjective.UnkFloat);

            _worldPacket << int32(questObjective.VisualEffects.size());
            for (int32 visualEffect : questObjective.VisualEffects)
                _worldPacket << int32(visualEffect);

            _worldPacket.WriteBits(questObjective.Description.size(), 8);
            _worldPacket.FlushBits();

            _worldPacket.WriteString(questObjective.Description);
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
    _worldPacket << int32(QuestID);
    _worldPacket << int32(ObjectID);
    _worldPacket << uint16(Count);
    _worldPacket << uint16(Required);
    _worldPacket << uint8(ObjectiveType);

    return &_worldPacket;
};

WorldPacket const* WorldPackets::Quest::QuestUpdateAddPvPCredit::Write()
{
    _worldPacket << int32(QuestID);
    _worldPacket << uint16(Count);

    return &_worldPacket;
}

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
    data << int32(offer.QuestGiverCreatureID);
    data << int32(offer.QuestID);
    data << int32(offer.QuestFlags[0]); // Flags
    data << int32(offer.QuestFlags[1]); // FlagsEx
    data << int32(offer.SuggestedPartyMembers);
    data << offer.Rewards; // WorldPackets::Quest::QuestRewards

    data << int32(offer.Emotes.size());
    for (WorldPackets::Quest::QuestDescEmote const& emote : offer.Emotes)
    {
        data << int32(emote.Type);
        data << uint32(emote.Delay);
    }

    data.WriteBit(offer.AutoLaunched);
    data.FlushBits();

    return data;
}

WorldPacket const* WorldPackets::Quest::QuestGiverOfferRewardMessage::Write()
{
    _worldPacket << QuestData; // WorldPackets::Quest::QuestGiverOfferReward
    _worldPacket << int32(PortraitTurnIn);
    _worldPacket << int32(PortraitGiver);
    _worldPacket << int32(QuestPackageID);

    _worldPacket.WriteBits(QuestTitle.size(), 9);
    _worldPacket.WriteBits(RewardText.size(), 12);
    _worldPacket.WriteBits(PortraitGiverText.size(), 10);
    _worldPacket.WriteBits(PortraitGiverName.size(), 8);
    _worldPacket.WriteBits(PortraitTurnInText.size(), 10);
    _worldPacket.WriteBits(PortraitTurnInName.size(), 8);
    _worldPacket.FlushBits();

    _worldPacket.WriteString(QuestTitle);
    _worldPacket.WriteString(RewardText);
    _worldPacket.WriteString(PortraitGiverText);
    _worldPacket.WriteString(PortraitGiverName);
    _worldPacket.WriteString(PortraitTurnInText);
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
    _worldPacket << int32(QuestID);
    _worldPacket << int32(SkillLineIDReward);
    _worldPacket << int32(MoneyReward);
    _worldPacket << int32(NumSkillUpsReward);
    _worldPacket << int32(XPReward);
    _worldPacket << int32(TalentReward);
    _worldPacket << ItemReward;

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

WorldPacket const* WorldPackets::Quest::QuestGiverQuestDetails::Write()
{
    _worldPacket << QuestGiverGUID;
    _worldPacket << InformUnit;
    _worldPacket << int32(QuestID);
    _worldPacket << int32(QuestPackageID);
    _worldPacket << int32(PortraitGiver);
    _worldPacket << int32(SuggestedPartyMembers);
    _worldPacket << uint32(QuestFlags[0]); // Flags
    _worldPacket << uint32(QuestFlags[1]); // FlagsEx
    _worldPacket << int32(PortraitTurnIn);
    _worldPacket << int32(LearnSpells.size());
    _worldPacket << Rewards; // WorldPackets::Quest::QuestRewards
    _worldPacket << int32(DescEmotes.size());
    _worldPacket << int32(Objectives.size());

    for (int32 spell : LearnSpells)
        _worldPacket << int32(spell);

    for (WorldPackets::Quest::QuestDescEmote const& emote : DescEmotes)
    {
        _worldPacket << int32(emote.Type);
        _worldPacket << uint32(emote.Delay);
    }

    for (WorldPackets::Quest::QuestObjectiveSimple const& obj : Objectives)
    {
        _worldPacket << int32(obj.ID);
        _worldPacket << int32(obj.ObjectID);
        _worldPacket << int32(obj.Amount);
        _worldPacket << uint8(obj.Type);
    }

    _worldPacket.WriteBits(QuestTitle.size(), 9);
    _worldPacket.WriteBits(DescriptionText.size(), 12);
    _worldPacket.WriteBits(LogDescription.size(), 12);
    _worldPacket.WriteBits(PortraitGiverText.size(), 10);
    _worldPacket.WriteBits(PortraitGiverName.size(), 8);
    _worldPacket.WriteBits(PortraitTurnInText.size(), 10);
    _worldPacket.WriteBits(PortraitTurnInName.size(), 8);
    _worldPacket.WriteBit(DisplayPopup);
    _worldPacket.WriteBit(StartCheat);
    _worldPacket.WriteBit(AutoLaunched);
    _worldPacket.FlushBits();

    _worldPacket.WriteString(QuestTitle);
    _worldPacket.WriteString(DescriptionText);
    _worldPacket.WriteString(LogDescription);
    _worldPacket.WriteString(PortraitGiverText);
    _worldPacket.WriteString(PortraitGiverName);
    _worldPacket.WriteString(PortraitTurnInText);
    _worldPacket.WriteString(PortraitTurnInName);

    return &_worldPacket;
}

WorldPacket const* WorldPackets::Quest::QuestGiverRequestItems::Write()
{
    _worldPacket << QuestGiverGUID;
    _worldPacket << int32(QuestGiverCreatureID);
    _worldPacket << int32(QuestID);
    _worldPacket << int32(CompEmoteDelay);
    _worldPacket << int32(CompEmoteType);
    _worldPacket << uint32(QuestFlags[0]);
    _worldPacket << uint32(QuestFlags[1]);
    _worldPacket << int32(SuggestPartyMembers);
    _worldPacket << int32(MoneyToGet);
    _worldPacket << int32(Collect.size());
    _worldPacket << int32(Currency.size());
    _worldPacket << int32(StatusFlags);

    for (QuestObjectiveCollect const& obj : Collect)
    {
        _worldPacket << int32(obj.ObjectID);
        _worldPacket << int32(obj.Amount);
    }

    for (QuestCurrency const& cur : Currency)
    {
        _worldPacket << int32(cur.CurrencyID);
        _worldPacket << int32(cur.Amount);
    }

    _worldPacket.WriteBit(AutoLaunched);
    _worldPacket.FlushBits();

    _worldPacket.WriteBits(QuestTitle.size(), 9);
    _worldPacket.WriteBits(CompletionText.size(), 12);
    _worldPacket.FlushBits();

    _worldPacket.WriteString(QuestTitle);
    _worldPacket.WriteString(CompletionText);

    return &_worldPacket;
}

void WorldPackets::Quest::QuestGiverRequestReward::Read()
{
    _worldPacket >> QuestGiverGUID;
    _worldPacket >> QuestID;
}

void WorldPackets::Quest::QuestGiverQueryQuest::Read()
{
    _worldPacket >> QuestGiverGUID;
    _worldPacket >> QuestID;
    RespondToGiver = _worldPacket.ReadBit();
}

void WorldPackets::Quest::QuestGiverAcceptQuest::Read()
{
    _worldPacket >> QuestGiverGUID;
    _worldPacket >> QuestID;
    StartCheat = _worldPacket.ReadBit();
}

void WorldPackets::Quest::QuestLogRemoveQuest::Read()
{
    _worldPacket >> Entry;
}

WorldPacket const* WorldPackets::Quest::QuestGiverQuestList::Write()
{
    _worldPacket << QuestGiverGUID;
    _worldPacket << uint32(GreetEmoteDelay);
    _worldPacket << uint32(GreetEmoteType);
    _worldPacket << uint32(GossipTexts.size());
    for (GossipTextData const& gossip : GossipTexts)
    {
        _worldPacket << uint32(gossip.QuestID);
        _worldPacket << uint32(gossip.QuestType);
        _worldPacket << uint32(gossip.QuestLevel);
        _worldPacket << uint32(gossip.QuestFlags);
        _worldPacket << uint32(gossip.QuestFlagsEx);
        _worldPacket.WriteBit(gossip.Repeatable);
        _worldPacket.WriteBits(gossip.QuestTitle.size(), 9);
        _worldPacket.FlushBits();
        _worldPacket.WriteString(gossip.QuestTitle);
    }

    _worldPacket.WriteBits(Greeting.size(), 11);
    _worldPacket.FlushBits();
    _worldPacket.WriteString(Greeting);

    return &_worldPacket;
}

WorldPacket const* WorldPackets::Quest::QuestUpdateComplete::Write()
{
    _worldPacket << int32(QuestID);

    return &_worldPacket;
}

WorldPacket const* WorldPackets::Quest::QuestConfirmAcceptResponse::Write()
{
    _worldPacket << uint32(QuestID);
    _worldPacket << InitiatedBy;

    _worldPacket.WriteBits(QuestTitle.size(), 10);
    _worldPacket.FlushBits();

    _worldPacket.WriteString(QuestTitle);

    return &_worldPacket;
}

void WorldPackets::Quest::QuestConfirmAccept::Read()
{
    _worldPacket >> QuestID;
}

WorldPacket const* WorldPackets::Quest::QuestPushResultResponse::Write()
{
    _worldPacket << SenderGUID;
    _worldPacket << uint8(Result);

    return &_worldPacket;
}

void WorldPackets::Quest::QuestPushResult::Read()
{
    _worldPacket >> SenderGUID;
    _worldPacket >> QuestID;
    _worldPacket >> Result;
}

WorldPacket const* WorldPackets::Quest::QuestGiverInvalidQuest::Write()
{
    _worldPacket << uint32(Reason);

    _worldPacket.WriteBit(SendErrorMessage);
    _worldPacket.WriteBits(ReasonText.length(), 9);

    _worldPacket.FlushBits();

    _worldPacket.WriteString(ReasonText);

    return &_worldPacket;
}

WorldPacket const* WorldPackets::Quest::QuestUpdateFailedTimer::Write()
{
    _worldPacket << uint32(QuestID);

    return &_worldPacket;
}

WorldPacket const* WorldPackets::Quest::QuestGiverQuestFailed::Write()
{
    _worldPacket << uint32(QuestID);
    _worldPacket << uint32(Reason);

    return &_worldPacket;
}

void WorldPackets::Quest::PushQuestToParty::Read()
{
    _worldPacket >> QuestID;
}

WorldPacket const* WorldPackets::Quest::DailyQuestsReset::Write()
{
    _worldPacket << int32(Count);

    return &_worldPacket;
}
