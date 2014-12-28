/*
 * Copyright (C) 2008-2014 TrinityCore <http://www.trinitycore.org/>
 * Copyright (C) 2005-2009 MaNGOS <http://getmangos.com/>
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

#include "QuestDef.h"
#include "Player.h"
#include "World.h"
#include "ObjectMgr.h"
#include "QuestPackets.h"

Quest::Quest(Field* questRecord)
{
    Id = questRecord[0].GetUInt32();
    Method = questRecord[1].GetUInt8();
    Level = questRecord[2].GetInt32();
    PackageID = questRecord[3].GetUInt32();
    MinLevel = questRecord[4].GetUInt32();
    ZoneOrSort = questRecord[5].GetInt16();
    Type = questRecord[6].GetUInt16();
    SuggestedPlayers = questRecord[7].GetUInt8();
    NextQuestInChain = questRecord[8].GetUInt32();
    RewardXPDifficulty = questRecord[9].GetUInt32();
    Float10 = questRecord[10].GetFloat();
    RewardMoney = questRecord[11].GetUInt32();
    RewardMoneyDifficulty = questRecord[12].GetUInt32();
    Float13 = questRecord[13].GetFloat();
    RewardBonusMoney = questRecord[14].GetUInt32();
    RewardDisplaySpell = questRecord[15].GetUInt32();
    RewardSpell = questRecord[16].GetUInt32();
    RewardHonor = questRecord[17].GetUInt32();
    RewardKillHonor = questRecord[18].GetUInt32();
    SourceItemId = questRecord[19].GetUInt32();
    Flags = questRecord[20].GetUInt32();
    FlagsEx = questRecord[21].GetUInt32();

    for (uint32 i = 0; i < QUEST_ITEM_DROP_COUNT; ++i)
    {
        RewardItemId[i] = questRecord[22+i].GetUInt32();
        RewardItemCount[i] = questRecord[23+i].GetUInt32();
        ItemDrop[i] = questRecord[24+i].GetUInt32();
        ItemDropQuantity[i] = questRecord[25+i].GetUInt32();
    }

    for (uint32 i = 0; i < QUEST_REWARD_CHOICES_COUNT; ++i)
    {
        RewardChoiceItemId[i] = questRecord[38+i].GetUInt32();
        RewardChoiceItemCount[i] = questRecord[39+i].GetUInt32();
        RewardChoiceItemDisplayId[i] = questRecord[40+i].GetUInt32();
    }

    POIContinent = questRecord[56].GetUInt32();
    POIx = questRecord[57].GetFloat();
    POIy = questRecord[58].GetFloat();
    POIPriority = questRecord[59].GetUInt32();

    RewardTitleId = questRecord[60].GetUInt32();
    RewardTalents = questRecord[61].GetUInt32();
    RewardArenaPoints = questRecord[62].GetUInt32();
    RewardSkillId = questRecord[63].GetUInt32();
    RewardSkillPoints = questRecord[64].GetUInt32();

    QuestGiverPortrait = questRecord[65].GetUInt32();
    QuestTurnInPortrait = questRecord[66].GetUInt32();

    for (uint32 i = 0; i < QUEST_REWARD_REPUTATIONS_COUNT; ++i)
    {
        RewardFactionId[i] = questRecord[67+i].GetUInt32();
        RewardFactionValue[i] = questRecord[68+i].GetInt32();
        RewardFactionOverride[i] = questRecord[69+i].GetInt32();
    }

    RewardReputationMask = questRecord[82].GetUInt32();

    for (uint32 i = 0; i < QUEST_REWARD_CURRENCY_COUNT; ++i)
    {
        RewardCurrencyId[i] = questRecord[83+i].GetUInt32();
        RewardCurrencyCount[i] = questRecord[84+i].GetUInt32();
    }

    SoundAccept = questRecord[91].GetUInt32();
    SoundTurnIn = questRecord[92].GetUInt32();
    AreaGroupID = questRecord[93].GetUInt32();
    LimitTime = questRecord[94].GetUInt32();
    AllowableRaces = questRecord[95].GetInt32();

    LogTitle = questRecord[96].GetString();
    LogDescription = questRecord[97].GetString();
    QuestDescription = questRecord[98].GetString();
    AreaDescription = questRecord[99].GetString();
    PortraitGiverText = questRecord[100].GetString();
    PortraitGiverName = questRecord[101].GetString();
    PortraitTurnInText = questRecord[102].GetString();
    PortraitTurnInName = questRecord[103].GetString();
    QuestCompletionLog = questRecord[104].GetString();

    _rewItemsCount = 0;
    _rewChoiceItemsCount = 0;
    _rewCurrencyCount = 0;

    for (int i = 0; i < QUEST_REWARD_ITEM_COUNT; ++i)
        if (RewardItemId[i])
            ++_rewItemsCount;

    for (int i = 0; i < QUEST_REWARD_CHOICES_COUNT; ++i)
        if (RewardChoiceItemId[i])
            ++_rewChoiceItemsCount;

    for (int i = 0; i < QUEST_REWARD_CURRENCY_COUNT; ++i)
        if (RewardCurrencyId[i])
            ++_rewCurrencyCount;
}

void Quest::LoadQuestDetails(Field* fields)
{
    for (int i = 0; i < QUEST_EMOTE_COUNT; ++i)
        DetailsEmote[i] = fields[1+i].GetUInt16();

    for (int i = 0; i < QUEST_EMOTE_COUNT; ++i)
        DetailsEmoteDelay[i] = fields[5+i].GetUInt32();
}

void Quest::LoadQuestRequestItems(Field* fields)
{
    EmoteOnComplete = fields[1].GetUInt16();
    EmoteOnIncomplete = fields[2].GetUInt16();
    EmoteOnCompleteDelay = fields[3].GetUInt32();
    EmoteOnIncompleteDelay = fields[4].GetUInt32();
    RequestItemsText = fields[5].GetString();
}


void Quest::LoadQuestOfferReward(Field* fields)
{
    for (int i = 0; i < QUEST_EMOTE_COUNT; ++i)
        OfferRewardEmote[i] = fields[1+i].GetUInt16();

    for (int i = 0; i < QUEST_EMOTE_COUNT; ++i)
        OfferRewardEmoteDelay[i] = fields[5+i].GetUInt32();

    OfferRewardText = fields[9].GetString();
}

void Quest::LoadQuestTemplateAddon(Field* fields)
{
    MaxLevel = fields[1].GetUInt8();
    AllowableClasses = fields[2].GetUInt32();
    SourceSpellID = fields[3].GetUInt32();
    PrevQuestID = fields[4].GetInt32();
    NextQuestID = fields[5].GetInt32();
    ExclusiveGroup = fields[6].GetInt32();
    RewardMailTemplateId = fields[7].GetUInt32();
    RewardMailDelay = fields[8].GetUInt32();
    SourceItemIdCount = fields[9].GetUInt8();
    SpecialFlags = fields[10].GetUInt8();

    if (SpecialFlags & QUEST_SPECIAL_FLAGS_AUTO_ACCEPT)
        Flags |= QUEST_FLAGS_AUTO_ACCEPT;
}

void Quest::LoadQuestObjective(Field* fields)
{
    uint8 storageIndex = fields[3].GetUInt8();

    // Allocate space
    if (storageIndex >= Objectives.size())
        Objectives.resize(storageIndex+1);

    QuestObjective& obj = Objectives[storageIndex];
    obj.ID = fields[0].GetUInt32();
    obj.Type = fields[2].GetUInt8();
    obj.StorageIndex = storageIndex;
    obj.ObjectID = fields[4].GetInt32();
    obj.Amount = fields[5].GetInt32();
    obj.Flags = fields[6].GetUInt32();
    obj.UnkFloat = fields[7].GetFloat();
    obj.Description = fields[8].GetString();
}

void Quest::LoadQuestObjectiveVisualEffect(Field* fields)
{
    // No need to check index because checks is objective exists are done in ObjectMgr while loading quest_visual_effect
    uint8 storageIndex = fields[3].GetUInt8();
    QuestObjective& obj = Objectives[storageIndex];

    uint8 effectIndex = fields[4].GetUInt8();
    if (effectIndex >= obj.VisualEffects.size())
        obj.VisualEffects.resize(effectIndex+1, 0);

    obj.VisualEffects[effectIndex] = fields[5].GetInt32();
}

uint32 Quest::XPValue(uint32 playerLevel) const
{
    if (playerLevel)
    {
        int32 quest_level = (Level == -1 ? playerLevel : Level);
        const QuestXPEntry* xpentry = sQuestXPStore.LookupEntry(quest_level);
        if (!xpentry)
            return 0;

        int32 diffFactor = 2 * (quest_level - playerLevel) + 20;
        if (diffFactor < 1)
            diffFactor = 1;
        else if (diffFactor > 10)
            diffFactor = 10;

        uint32 xp = diffFactor * xpentry->Exp[RewardXPDifficulty] / 10;
        if (xp <= 100)
            xp = 5 * ((xp + 2) / 5);
        else if (xp <= 500)
            xp = 10 * ((xp + 5) / 10);
        else if (xp <= 1000)
            xp = 25 * ((xp + 12) / 25);
        else
            xp = 50 * ((xp + 25) / 50);

        return xp;
    }

    return 0;
}

int32 Quest::GetRewMoney() const
{
    return int32(RewardMoney * sWorld->getRate(RATE_MONEY_QUEST));
}

void Quest::BuildExtraQuestInfo(WorldPacket& data, Player* player) const
{
    data << uint32(GetRewChoiceItemsCount());
    for (uint8 i = 0; i < QUEST_REWARD_CHOICES_COUNT; ++i)
        data << uint32(RewardChoiceItemId[i]);
    for (uint8 i = 0; i < QUEST_REWARD_CHOICES_COUNT; ++i)
        data << uint32(RewardChoiceItemCount[i]);
    for (uint8 i = 0; i < QUEST_REWARD_CHOICES_COUNT; ++i)
    {
        if (ItemTemplate const* itemTemplate = sObjectMgr->GetItemTemplate(RewardChoiceItemId[i]))
            data << uint32(/*itemTemplate->DisplayInfoID*/);
        else
            data << uint32(0);
    }

    data << uint32(GetRewItemsCount());
    for (uint8 i = 0; i < QUEST_REWARD_ITEM_COUNT; ++i)
        data << uint32(RewardItemId[i]);
    for (uint8 i = 0; i < QUEST_REWARD_ITEM_COUNT; ++i)
        data << uint32(RewardItemCount[i]);
    for (uint8 i = 0; i < QUEST_REWARD_ITEM_COUNT; ++i)
    {
        if (ItemTemplate const* itemTemplate = sObjectMgr->GetItemTemplate(RewardItemId[i]))
            data << uint32(/*itemTemplate->DisplayInfoID*/);
        else
            data << uint32(0);
    }

    data << uint32(GetRewMoney());
    data << uint32(player->GetQuestXPReward(this));

    data << uint32(GetRewTitle());
    data << uint32(0);                                      // unk
    data << float(0.0f);                                    // unk
    data << uint32(GetBonusTalents());
    data << uint32(0);                                      // unk
    data << uint32(GetRewardReputationMask());

    /* Pre cata struct, some of these unks might be the missing values in cata:
    // rewarded honor points. Multiply with 10 to satisfy client
    data << 10 * Trinity::Honor::hk_honor_at_level(_session->GetPlayer()->getLevel(), quest->GetRewHonorMultiplier());
    data << float(0);                                       // unk, honor multiplier?
    data << uint32(0x08);                                   // unused by client?
    data << uint32(quest->GetRewDisplaySpell());            // reward spell, this spell will display (icon) (casted if RewSpellCast == 0)
    data << int32(quest->GetRewSpell());                    // casted spell
    data << uint32(0);                                      // unknown
    data << uint32(quest->GetBonusTalents());               // bonus talents
    data << uint32(quest->GetRewArenaPoints());             // arena points
    data << uint32(0);
    */

    for (uint8 i = 0; i < QUEST_REWARD_REPUTATIONS_COUNT; ++i)    // reward factions ids
        data << uint32(RewardFactionId[i]);

    for (uint8 i = 0; i < QUEST_REWARD_REPUTATIONS_COUNT; ++i)    // columnid in QuestFactionReward.dbc (zero based)?
        data << int32(RewardFactionValue[i]);

    for (uint8 i = 0; i < QUEST_REWARD_REPUTATIONS_COUNT; ++i)    // reward reputation override?
        data << uint32(RewardFactionOverride[i]);

    data << uint32(GetRewDisplaySpell());
    data << uint32(GetRewSpell());

    for (uint8 i = 0; i < QUEST_REWARD_CURRENCY_COUNT; ++i)
        data << uint32(RewardCurrencyId[i]);

    for (uint8 i = 0; i < QUEST_REWARD_CURRENCY_COUNT; ++i)
        data << uint32(RewardCurrencyCount[i]);

    data << uint32(GetRewardSkillId());
    data << uint32(GetRewardSkillPoints());
}

void Quest::BuildQuestRewards(WorldPackets::Quest::QuestRewards& rewards, Player* player) const
{
    rewards.ChoiceItemCount         = GetRewChoiceItemsCount();
    rewards.ItemCount               = GetRewItemsCount();
    rewards.Money                   = GetRewMoney();
    rewards.XP                      = player->GetQuestXPReward(this);
    rewards.Title                   = GetRewTitle();
    rewards.Talents                 = GetBonusTalents();
    rewards.FactionFlags            = GetRewardReputationMask();
    rewards.SpellCompletionDisplayID = GetRewDisplaySpell();
    rewards.SpellCompletionID       = GetRewSpell();
    rewards.SkillLineID             = GetRewardSkillId();
    rewards.NumSkillUps             = GetRewardSkillPoints();

    for (uint32 i = 0; i < QUEST_REWARD_CHOICES_COUNT; ++i)
    {
        rewards.ChoiceItems[i].ItemID = RewardChoiceItemId[i];
        rewards.ChoiceItems[i].Quantity = RewardChoiceItemCount[i];
    }

    for (uint32 i = 0; i < QUEST_REWARD_ITEM_COUNT; ++i)
    {
        rewards.ItemID[i] = RewardItemId[i];
        rewards.ItemQty[i] = RewardItemCount[i];
    }

    for (uint32 i = 0; i < QUEST_REWARD_REPUTATIONS_COUNT; ++i)
    {
        rewards.FactionID[i] = RewardFactionId[i];
        rewards.FactionValue[i] = RewardFactionValue[i];
        rewards.FactionOverride[i] = RewardFactionOverride[i];
    }

    for (uint32 i = 0; i < QUEST_REWARD_CURRENCY_COUNT; ++i)
    {
        rewards.CurrencyID[i] = RewardCurrencyId[i];
        rewards.CurrencyQty[i] = RewardCurrencyCount[i];
    }
}

uint32 Quest::GetRewMoneyMaxLevel() const
{
    // If Quest has flag to not give money on max level, it's 0
    if (HasFlag(QUEST_FLAGS_NO_MONEY_FROM_XP))
        return 0;

    // Else, return the rewarded copper sum modified by the rate
    return uint32(RewardBonusMoney * sWorld->getRate(RATE_MONEY_MAX_LEVEL_QUEST));
}

bool Quest::IsAutoAccept() const
{
    return !sWorld->getBoolConfig(CONFIG_QUEST_IGNORE_AUTO_ACCEPT) && HasFlag(QUEST_FLAGS_AUTO_ACCEPT);
}

bool Quest::IsAutoComplete() const
{
    return !sWorld->getBoolConfig(CONFIG_QUEST_IGNORE_AUTO_COMPLETE) && Method == 0;
}

bool Quest::IsRaidQuest(Difficulty difficulty) const
{
    switch (Type)
    {
        case QUEST_TYPE_RAID:
            return true;
        case QUEST_TYPE_RAID_10:
            return !(difficulty & RAID_DIFFICULTY_MASK_25MAN);
        case QUEST_TYPE_RAID_25:
            return difficulty & RAID_DIFFICULTY_MASK_25MAN;
        default:
            break;
    }

    return false;
}

bool Quest::IsAllowedInRaid(Difficulty difficulty) const
{
    if (IsRaidQuest(difficulty))
        return true;

    return sWorld->getBoolConfig(CONFIG_QUEST_IGNORE_RAID);
}

uint32 Quest::CalculateHonorGain(uint8 level) const
{
    uint32 honor = 0;

    /*if (GetRewHonorAddition() > 0 || GetRewHonorMultiplier() > 0.0f)
    {
        // values stored from 0.. for 1...
        TeamContributionPointsEntry const* tc = sTeamContributionPointsStore.LookupEntry(level);
        if (!tc)
            return 0;

        honor = uint32(tc->value * GetRewHonorMultiplier() * 0.1f);
        honor += GetRewHonorAddition();
    }*/

    return honor;
}
