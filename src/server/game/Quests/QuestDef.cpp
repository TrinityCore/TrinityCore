/*
 * Copyright (C) 2008-2015 TrinityCore <http://www.trinitycore.org/>
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

Quest::Quest(Field* questRecord)
{
    Id = questRecord[0].GetUInt32();
    Method = questRecord[1].GetUInt8();
    Level = questRecord[2].GetInt16();
    MinLevel = questRecord[3].GetUInt8();
    ZoneOrSort = questRecord[4].GetInt16();
    Type = questRecord[5].GetUInt16();
    SuggestedPlayers = questRecord[6].GetUInt8();
    TimeAllowed = questRecord[7].GetUInt32();
    AllowableRaces = questRecord[8].GetUInt16();
    RequiredFactionId1 = questRecord[9].GetUInt16();
    RequiredFactionId2 = questRecord[10].GetUInt16();
    RequiredFactionValue1 = questRecord[11].GetInt32();
    RequiredFactionValue2 = questRecord[12].GetInt32();
    RewardNextQuest = questRecord[13].GetUInt32();
    RewardXPDifficulty = questRecord[14].GetUInt8();
    RewardMoney = questRecord[15].GetInt32();
    RewardBonusMoney = questRecord[16].GetUInt32();
    RewardDisplaySpell = questRecord[17].GetUInt32();
    RewardSpell = questRecord[18].GetInt32();
    RewardHonor = questRecord[19].GetUInt32();
    RewardKillHonor = questRecord[20].GetFloat();
    StartItem = questRecord[21].GetUInt32();
    Flags = questRecord[22].GetUInt32();
    RewardTitleId = questRecord[23].GetUInt8();
    RequiredPlayerKills = questRecord[24].GetUInt8();
    RewardTalents = questRecord[25].GetUInt8();
    RewardArenaPoints = questRecord[26].GetUInt16();

    for (int i = 0; i < QUEST_REWARDS_COUNT; ++i)
    {
        RewardItemId[i] = questRecord[27+i*2].GetUInt32();
        RewardItemIdCount[i] = questRecord[28+i*2].GetUInt16();
    }

    for (int i = 0; i < QUEST_REWARD_CHOICES_COUNT; ++i)
    {
        RewardChoiceItemId[i] = questRecord[35+i*2].GetUInt32();
        RewardChoiceItemCount[i] = questRecord[36+i*2].GetUInt16();
    }

    for (int i = 0; i < QUEST_REPUTATIONS_COUNT; ++i)
    {
        RewardFactionId[i] = questRecord[47+i*3].GetUInt16();
        RewardFactionValueId[i] = questRecord[48+i*3].GetInt32();
        RewardFactionValueIdOverride[i] = questRecord[49+i*3].GetInt32();
    }

    POIContinent = questRecord[62].GetUInt16();
    POIx = questRecord[63].GetFloat();
    POIy = questRecord[64].GetFloat();
    POIPriority = questRecord[65].GetUInt32();
    Title = questRecord[66].GetString();
    Objectives = questRecord[67].GetString();
    Details = questRecord[68].GetString();
    AreaDescription = questRecord[69].GetString();
    CompletedText = questRecord[70].GetString();

    for (int i = 0; i < QUEST_OBJECTIVES_COUNT; ++i)
        RequiredNpcOrGo[i] = questRecord[71+i].GetInt32();

    for (int i = 0; i < QUEST_OBJECTIVES_COUNT; ++i)
        RequiredNpcOrGoCount[i] = questRecord[75+i].GetUInt16();

    for (int i = 0; i < QUEST_SOURCE_ITEM_IDS_COUNT; ++i)
        ItemDrop[i] = questRecord[79+i].GetUInt32();

    for (int i = 0; i < QUEST_SOURCE_ITEM_IDS_COUNT; ++i)
        ItemDropQuantity[i] = questRecord[83+i].GetUInt16();

    for (int i = 0; i < QUEST_ITEM_OBJECTIVES_COUNT; ++i)
        RequiredItemId[i] = questRecord[87+i].GetUInt32();

    for (int i = 0; i < QUEST_ITEM_OBJECTIVES_COUNT; ++i)
        RequiredItemCount[i] = questRecord[93+i].GetUInt16();

    // int8 Unknown0 = questRecord[99].GetUInt8();

    for (int i = 0; i < QUEST_OBJECTIVES_COUNT; ++i)
        ObjectiveText[i] = questRecord[100+i].GetString();

    EmoteOnIncomplete = 0;
    EmoteOnComplete = 0;

    //int32 VerifiedBuild = questRecord[104].GetInt32();

    _reqItemsCount = 0;
    _reqCreatureOrGOcount = 0;
    _rewItemsCount = 0;
    _rewChoiceItemsCount = 0;

    for (int i = 0; i < QUEST_ITEM_OBJECTIVES_COUNT; ++i)
        if (RequiredItemId[i])
            ++_reqItemsCount;

    for (int i = 0; i < QUEST_OBJECTIVES_COUNT; ++i)
        if (RequiredNpcOrGo[i])
            ++_reqCreatureOrGOcount;

    for (int i = 0; i < QUEST_REWARDS_COUNT; ++i)
        if (RewardItemId[i])
            ++_rewItemsCount;

    for (int i = 0; i < QUEST_REWARD_CHOICES_COUNT; ++i)
        if (RewardChoiceItemId[i])
            ++_rewChoiceItemsCount;
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
    RequestItemsText = fields[3].GetString();
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
    RequiredClasses = fields[2].GetUInt32();
    SourceSpellid = fields[3].GetUInt32();
    PrevQuestId = fields[4].GetInt32();
    NextQuestId = fields[5].GetInt32();
    ExclusiveGroup = fields[6].GetInt32();
    RewardMailTemplateId = fields[7].GetUInt32();
    RewardMailDelay = fields[8].GetUInt32();
    RequiredSkillId = fields[9].GetUInt16();
    RequiredSkillPoints = fields[10].GetUInt16();
    RequiredMinRepFaction = fields[11].GetUInt16();
    RequiredMaxRepFaction = fields[12].GetUInt16();
    RequiredMinRepValue = fields[13].GetInt32();
    RequiredMaxRepValue = fields[14].GetInt32();
    StartItemCount = fields[15].GetUInt8();
    SpecialFlags = fields[16].GetUInt8();

    if (SpecialFlags & QUEST_SPECIAL_FLAGS_AUTO_ACCEPT)
        Flags |= QUEST_FLAGS_AUTO_ACCEPT;
}

uint32 Quest::XPValue(Player* player) const
{
    if (player)
    {
        int32 quest_level = (Level == -1 ? player->getLevel() : Level);
        const QuestXPEntry* xpentry = sQuestXPStore.LookupEntry(quest_level);
        if (!xpentry)
            return 0;

        int32 diffFactor = 2 * (quest_level - player->getLevel()) + 20;
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

int32 Quest::GetRewOrReqMoney() const
{
    // RequiredMoney: the amount is the negative copper sum.
    if (RewardMoney <= 0)
        return RewardMoney;

    // RewardMoney: the positive amount
    return int32(RewardMoney * sWorld->getRate(RATE_MONEY_QUEST));
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
    return !sWorld->getBoolConfig(CONFIG_QUEST_IGNORE_AUTO_COMPLETE) && (Method == 0 || HasFlag(QUEST_FLAGS_AUTOCOMPLETE));
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
    if (level > GT_MAX_LEVEL)
        level = GT_MAX_LEVEL;

    uint32 honor = 0;

    if (GetRewHonorAddition() > 0 || GetRewHonorMultiplier() > 0.0f)
    {
        // values stored from 0.. for 1...
        TeamContributionPointsEntry const* tc = sTeamContributionPointsStore.LookupEntry(level);
        if (!tc)
            return 0;

        honor = uint32(tc->value * GetRewHonorMultiplier() * 0.1f);
        honor += GetRewHonorAddition();
    }

    return honor;
}
