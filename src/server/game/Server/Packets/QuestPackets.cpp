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
        _worldPacket << int32(Info.QuestMaxScalingLevel);
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
        _worldPacket.append(Info.RewardDisplaySpell, QUEST_REWARD_DISPLAY_SPELL_COUNT);
        _worldPacket << int32(Info.RewardSpell);
        _worldPacket << int32(Info.RewardHonor);
        _worldPacket << float(Info.RewardKillHonor);
        _worldPacket << int32(Info.RewardArtifactXPDifficulty);
        _worldPacket << float(Info.RewardArtifactXPMultiplier);
        _worldPacket << int32(Info.RewardArtifactCategoryID);
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
            _worldPacket << int32(Info.RewardFactionCapIn[i]);
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

        _worldPacket << uint32(Info.Objectives.size());
        _worldPacket << uint64(Info.AllowableRaces);
        _worldPacket << int32(Info.QuestRewardID);
        _worldPacket << int32(Info.Expansion);

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

        for (QuestObjective const& questObjective : Info.Objectives)
        {
            _worldPacket << uint32(questObjective.ID);
            _worldPacket << uint8(questObjective.Type);
            _worldPacket << int8(questObjective.StorageIndex);
            _worldPacket << int32(questObjective.ObjectID);
            _worldPacket << int32(questObjective.Amount);
            _worldPacket << uint32(questObjective.Flags);
            _worldPacket << uint32(questObjective.Flags2);
            _worldPacket << float(questObjective.ProgressBarWeight);

            _worldPacket << int32(questObjective.VisualEffects.size());
            for (int32 visualEffect : questObjective.VisualEffects)
                _worldPacket << int32(visualEffect);

            _worldPacket.WriteBits(questObjective.Description.size(), 8);
            _worldPacket.FlushBits();

            _worldPacket.WriteString(questObjective.Description);
        }

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

WorldPacket const* WorldPackets::Quest::QuestUpdateAddCreditSimple::Write()
{
    _worldPacket << int32(QuestID);
    _worldPacket << int32(ObjectID);
    _worldPacket << uint8(ObjectiveType);

    return &_worldPacket;
}

WorldPacket const* WorldPackets::Quest::QuestUpdateAddPvPCredit::Write()
{
    _worldPacket << int32(QuestID);
    _worldPacket << uint16(Count);

    return &_worldPacket;
}

ByteBuffer& operator<<(ByteBuffer& data, WorldPackets::Quest::QuestRewards const& questRewards)
{
    data << int32(questRewards.ChoiceItemCount);

    for (uint32 i = 0; i < QUEST_REWARD_CHOICES_COUNT; ++i)
    {
        data << int32(questRewards.ChoiceItems[i].ItemID);
        data << int32(questRewards.ChoiceItems[i].Quantity);
    }

    data << int32(questRewards.ItemCount);

    for (uint32 i = 0; i < QUEST_REWARD_ITEM_COUNT; ++i)
    {
        data << int32(questRewards.ItemID[i]);
        data << int32(questRewards.ItemQty[i]);
    }

    data << int32(questRewards.Money);
    data << int32(questRewards.XP);
    data << int64(questRewards.ArtifactXP);
    data << int32(questRewards.ArtifactCategoryID);
    data << int32(questRewards.Honor);
    data << int32(questRewards.Title);
    data << int32(questRewards.FactionFlags);

    for (uint32 i = 0; i < QUEST_REWARD_REPUTATIONS_COUNT; ++i)
    {
        data << int32(questRewards.FactionID[i]);
        data << int32(questRewards.FactionValue[i]);
        data << int32(questRewards.FactionOverride[i]);
        data << int32(questRewards.FactionCapIn[i]);
    }

    for (uint32 i = 0; i < QUEST_REWARD_DISPLAY_SPELL_COUNT; ++i)
        data << int32(questRewards.SpellCompletionDisplayID[i]);

    data << int32(questRewards.SpellCompletionID);

    for (uint32 i = 0; i < QUEST_REWARD_CURRENCY_COUNT; ++i)
    {
        data << int32(questRewards.CurrencyID[i]);
        data << int32(questRewards.CurrencyQty[i]);
    }

    data << int32(questRewards.SkillLineID);
    data << int32(questRewards.NumSkillUps);
    data << int32(questRewards.RewardID);

    data.WriteBit(questRewards.IsBoostSpell);
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
    data << int32(offer.Emotes.size());
    for (WorldPackets::Quest::QuestDescEmote const& emote : offer.Emotes)
    {
        data << int32(emote.Type);
        data << uint32(emote.Delay);
    }

    data.WriteBit(offer.AutoLaunched);
    data.FlushBits();

    data << offer.Rewards; // WorldPackets::Quest::QuestRewards

    return data;
}

WorldPacket const* WorldPackets::Quest::QuestGiverOfferRewardMessage::Write()
{
    _worldPacket << QuestData; // WorldPackets::Quest::QuestGiverOfferReward
    _worldPacket << int32(QuestPackageID);
    _worldPacket << int32(PortraitGiver);
    _worldPacket << int32(PortraitTurnIn);

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
    _worldPacket << int32(XPReward);
    _worldPacket << int64(MoneyReward);
    _worldPacket << int32(SkillLineIDReward);
    _worldPacket << int32(NumSkillUpsReward);
    _worldPacket.WriteBit(UseQuestReward);
    _worldPacket.WriteBit(LaunchGossip);
    _worldPacket.WriteBit(LaunchQuest);
    _worldPacket.WriteBit(HideChatMessage);

    _worldPacket << ItemReward;

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
    _worldPacket << int32(PortraitTurnIn);
    _worldPacket << uint32(QuestFlags[0]); // Flags
    _worldPacket << uint32(QuestFlags[1]); // FlagsEx
    _worldPacket << int32(SuggestedPartyMembers);
    _worldPacket << uint32(LearnSpells.size());
    _worldPacket << uint32(DescEmotes.size());
    _worldPacket << uint32(Objectives.size());
    _worldPacket << int32(QuestStartItemID);

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
    _worldPacket.WriteBit(AutoLaunched);
    _worldPacket.WriteBit(StartCheat);
    _worldPacket.WriteBit(DisplayPopup);
    _worldPacket.FlushBits();

    _worldPacket << Rewards; // WorldPackets::Quest::QuestRewards
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
        _worldPacket << uint32(obj.Flags);
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

WorldPacket const* WorldPackets::Quest::QuestGiverQuestListMessage::Write()
{
    _worldPacket << QuestGiverGUID;
    _worldPacket << uint32(GreetEmoteDelay);
    _worldPacket << uint32(GreetEmoteType);
    _worldPacket << uint32(QuestDataText.size());
    _worldPacket.WriteBits(Greeting.size(), 11);
    _worldPacket.FlushBits();

    for (GossipText const& gossip : QuestDataText)
    {
        _worldPacket << uint32(gossip.QuestID);
        _worldPacket << uint32(gossip.QuestType);
        _worldPacket << int32(gossip.QuestLevel);
        _worldPacket << int32(gossip.QuestMaxScalingLevel);
        _worldPacket << uint32(gossip.QuestFlags);
        _worldPacket << uint32(gossip.QuestFlagsEx);
        _worldPacket.WriteBit(gossip.Repeatable);
        _worldPacket.WriteBits(gossip.QuestTitle.size(), 9);
        _worldPacket.FlushBits();
        _worldPacket.WriteString(gossip.QuestTitle);
    }

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
    _worldPacket << int32(ContributionRewardID);

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

WorldPacket const* WorldPackets::Quest::WorldQuestUpdate::Write()
{
    _worldPacket << uint32(WorldQuestUpdates.size());

    for (WorldQuestUpdateInfo const& worldQuestUpdate : WorldQuestUpdates)
    {
        _worldPacket << int32(worldQuestUpdate.LastUpdate);
        _worldPacket << uint32(worldQuestUpdate.QuestID);
        _worldPacket << uint32(worldQuestUpdate.Timer);
        _worldPacket << int32(worldQuestUpdate.VariableID);
        _worldPacket << int32(worldQuestUpdate.Value);
    }

    return &_worldPacket;
}

ByteBuffer& operator<<(ByteBuffer& data, WorldPackets::Quest::PlayerChoiceResponseRewardEntry const& playerChoiceResponseRewardEntry)
{
    data << playerChoiceResponseRewardEntry.Item;
    data << int32(playerChoiceResponseRewardEntry.Quantity);
    return data;
}

ByteBuffer& operator<<(ByteBuffer& data, WorldPackets::Quest::PlayerChoiceResponseReward const& playerChoiceResponseReward)
{
    data << int32(playerChoiceResponseReward.TitleID);
    data << int32(playerChoiceResponseReward.PackageID);
    data << int32(playerChoiceResponseReward.SkillLineID);
    data << uint32(playerChoiceResponseReward.SkillPointCount);
    data << uint32(playerChoiceResponseReward.ArenaPointCount);
    data << uint32(playerChoiceResponseReward.HonorPointCount);
    data << uint64(playerChoiceResponseReward.Money);
    data << uint32(playerChoiceResponseReward.Xp);
    data << uint32(playerChoiceResponseReward.Items.size());
    data << uint32(playerChoiceResponseReward.Currencies.size());
    data << uint32(playerChoiceResponseReward.Factions.size());
    data << uint32(playerChoiceResponseReward.ItemChoices.size());

    for (WorldPackets::Quest::PlayerChoiceResponseRewardEntry const& item : playerChoiceResponseReward.Items)
        data << item;

    for (WorldPackets::Quest::PlayerChoiceResponseRewardEntry const& currency : playerChoiceResponseReward.Currencies)
        data << currency;

    for (WorldPackets::Quest::PlayerChoiceResponseRewardEntry const& faction : playerChoiceResponseReward.Factions)
        data << faction;

    for (WorldPackets::Quest::PlayerChoiceResponseRewardEntry const& itemChoice : playerChoiceResponseReward.ItemChoices)
        data << itemChoice;

    return data;
}

ByteBuffer& operator<<(ByteBuffer& data, WorldPackets::Quest::PlayerChoiceResponse const& playerChoiceResponse)
{
    data << int32(playerChoiceResponse.ResponseID);
    data << int32(playerChoiceResponse.ChoiceArtFileID);

    data.WriteBits(playerChoiceResponse.Answer.length(), 9);
    data.WriteBits(playerChoiceResponse.Header.length(), 9);
    data.WriteBits(playerChoiceResponse.Description.length(), 11);
    data.WriteBits(playerChoiceResponse.Confirmation.length(), 7);
    data.WriteBit(playerChoiceResponse.Reward.is_initialized());
    data.FlushBits();

    if (playerChoiceResponse.Reward)
        data << *playerChoiceResponse.Reward;

    data.WriteString(playerChoiceResponse.Answer);
    data.WriteString(playerChoiceResponse.Header);
    data.WriteString(playerChoiceResponse.Description);
    data.WriteString(playerChoiceResponse.Confirmation);
    return data;
}

WorldPacket const* WorldPackets::Quest::DisplayPlayerChoice::Write()
{
    _worldPacket << int32(ChoiceID);
    _worldPacket << uint32(Responses.size());
    _worldPacket << SenderGUID;
    _worldPacket << int32(UiTextureKitID);
    _worldPacket.WriteBits(Question.length(), 8);
    _worldPacket.WriteBit(CloseChoiceFrame);
    _worldPacket.WriteBit(HideWarboardHeader);
    _worldPacket.FlushBits();

    for (PlayerChoiceResponse const& response : Responses)
        _worldPacket << response;

    _worldPacket.WriteString(Question);
    return &_worldPacket;
}

void WorldPackets::Quest::ChoiceResponse::Read()
{
    _worldPacket >> ChoiceID;
    _worldPacket >> ResponseID;
}
