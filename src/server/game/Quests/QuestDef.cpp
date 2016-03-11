/*
 * Copyright (C) 2008-2016 TrinityCore <http://www.trinitycore.org/>
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

Quest::Quest(Field* questRecord)
{
    EmoteOnIncomplete = 0;
    EmoteOnComplete = 0;
    _reqItemsCount = 0;
    _reqNpcOrGoCount = 0;
    _rewItemsCount = 0;
    _rewChoiceItemsCount = 0;
    _rewCurrencyCount = 0;
    _reqCurrencyCount = 0;

    Id = questRecord[0].GetUInt32();
    Method = questRecord[1].GetUInt8();
    Level = questRecord[2].GetInt16();
    MinLevel = uint32(questRecord[3].GetInt16());
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
    MinimapTargetMark = questRecord[23].GetUInt8();
    RewardTitleId = questRecord[24].GetUInt8();
    RequiredPlayerKills = questRecord[25].GetUInt8();
    RewardTalents = questRecord[26].GetUInt8();
    RewardArenaPoints = questRecord[27].GetUInt16();
    RewardSkillId = questRecord[28].GetUInt16();
    RewardSkillPoints = questRecord[29].GetUInt8();
    RewardReputationMask = questRecord[30].GetUInt8();
    QuestGiverPortrait = questRecord[31].GetUInt32();
    QuestTurnInPortrait = questRecord[32].GetUInt32();

    for (int i = 0; i < QUEST_REWARDS_COUNT; ++i)
    {
        RewardItemId[i] = questRecord[33 + i * 2].GetUInt32();
        RewardItemIdCount[i] = questRecord[34 + i * 2].GetUInt16();

        if (RewardItemId[i])
            ++_rewItemsCount;
    }

    for (int i = 0; i < QUEST_REWARD_CHOICES_COUNT; ++i)
    {
        RewardChoiceItemId[i] = questRecord[41 + i * 2].GetUInt32();
        RewardChoiceItemCount[i] = questRecord[42 + i * 2].GetUInt16();

        if (RewardChoiceItemId[i])
            ++_rewChoiceItemsCount;
    }

    for (int i = 0; i < QUEST_REPUTATIONS_COUNT; ++i)
    {
        RewardFactionId[i] = questRecord[53 + i * 3].GetUInt16();
        RewardFactionValueId[i] = questRecord[54 + i * 3].GetInt32();
        RewardFactionValueIdOverride[i] = questRecord[55 + i * 3].GetInt32();
    }

    POIContinent = questRecord[68].GetUInt16();
    POIx = questRecord[69].GetFloat();
    POIy = questRecord[70].GetFloat();
    POIPriority = questRecord[71].GetUInt32();
    Title = questRecord[72].GetString();
    Objectives = questRecord[73].GetString();
    Details = questRecord[74].GetString();
    AreaDescription = questRecord[75].GetString();
    CompletedText = questRecord[76].GetString();

    for (int i = 0; i < QUEST_OBJECTIVES_COUNT; ++i)
    {
        RequiredNpcOrGo[i] = questRecord[77 + i].GetInt32();
        RequiredNpcOrGoCount[i] = questRecord[81 + i].GetUInt16();
        ObjectiveText[i] = questRecord[106 + i].GetString();

        if (RequiredNpcOrGo[i])
            ++_reqNpcOrGoCount;
    }

    for (int i = 0; i < QUEST_SOURCE_ITEM_IDS_COUNT; ++i)
    {
        ItemDrop[i] = questRecord[85 + i].GetUInt32();
        ItemDropQuantity[i] = questRecord[89 + i].GetUInt16();
    }

    for (int i = 0; i < QUEST_ITEM_OBJECTIVES_COUNT; ++i)
    {
        RequiredItemId[i] = questRecord[93 + i].GetUInt32();
        RequiredItemCount[i] = questRecord[99 + i].GetUInt16();

        if (RequiredItemId[i])
            ++_reqItemsCount;
    }

    //int32 VerifiedBuild = questRecord[132].GetInt32();

    for (int i = 0; i < QUEST_EMOTE_COUNT; ++i)
    {
        DetailsEmote[i] = 0;
        DetailsEmoteDelay[i] = 0;
        OfferRewardEmote[i] = 0;
        OfferRewardEmoteDelay[i] = 0;
    }

    RequiredSpell = questRecord[105].GetUInt32();

    for (int i = 0; i < QUEST_REWARD_CURRENCY_COUNT; ++i)
    {
        RewardCurrencyId[i] = questRecord[110 + i].GetUInt16();
        RewardCurrencyCount[i] = questRecord[114 + i].GetUInt8();

        if (RewardCurrencyId[i])
            ++_rewCurrencyCount;
    }

    for (int i = 0; i < QUEST_REQUIRED_CURRENCY_COUNT; ++i)
    {
        RequiredCurrencyId[i] = questRecord[118 + i].GetUInt16();
        RequiredCurrencyCount[i] = questRecord[122 + i].GetUInt8();

        if (RequiredCurrencyId[i])
            ++_reqCurrencyCount;
    }

    QuestGiverTextWindow = questRecord[126].GetString();
    QuestGiverTargetName = questRecord[127].GetString();
    QuestTurnTextWindow = questRecord[128].GetString();
    QuestTurnTargetName = questRecord[129].GetString();
    SoundAccept = questRecord[130].GetUInt16();
    SoundTurnIn = questRecord[131].GetUInt16();
}

void Quest::LoadQuestDetails(Field* fields)
{
    for (int i = 0; i < QUEST_EMOTE_COUNT; ++i)
        DetailsEmote[i] = fields[1 + i].GetUInt16();

    for (int i = 0; i < QUEST_EMOTE_COUNT; ++i)
        DetailsEmoteDelay[i] = fields[5 + i].GetUInt32();
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
        OfferRewardEmote[i] = fields[1 + i].GetUInt16();

    for (int i = 0; i < QUEST_EMOTE_COUNT; ++i)
        OfferRewardEmoteDelay[i] = fields[5 + i].GetUInt32();

    OfferRewardText = fields[9].GetString();
}

void Quest::LoadQuestTemplateAddon(Field* fields)
{
    MaxLevel = fields[1].GetUInt8();
    AllowableClasses = fields[2].GetUInt32();
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
            data << uint32(itemTemplate->DisplayInfoID);
        else
            data << uint32(0);
    }

    data << uint32(GetReqItemsCount());
    for (uint8 i = 0; i < QUEST_REWARDS_COUNT; ++i)
        data << uint32(RewardItemId[i]);
    for (uint8 i = 0; i < QUEST_REWARDS_COUNT; ++i)
        data << uint32(RewardItemIdCount[i]);
    for (uint8 i = 0; i < QUEST_REWARDS_COUNT; ++i)
    {
        if (ItemTemplate const* itemTemplate = sObjectMgr->GetItemTemplate(RewardItemId[i]))
            data << uint32(itemTemplate->DisplayInfoID);
        else
            data << uint32(0);
    }

    data << uint32(GetRewOrReqMoney());
    data << uint32(XPValue(player) * sWorld->getRate(RATE_XP_QUEST));

    data << uint32(GetCharTitleId());
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
    data << uint32(quest->GetRewSpell());                   // reward spell, this spell will display (icon) (casted if RewSpellCast == 0)
    data << int32(quest->GetRewSpellCast());                // casted spell
    data << uint32(0);                                      // unknown
    data << uint32(quest->GetBonusTalents());               // bonus talents
    data << uint32(quest->GetRewArenaPoints());             // arena points
    data << uint32(0);
    */

    for (uint8 i = 0; i < QUEST_REPUTATIONS_COUNT; ++i)    // reward factions ids
        data << uint32(RewardFactionId[i]);

    for (uint8 i = 0; i < QUEST_REPUTATIONS_COUNT; ++i)    // columnid in QuestFactionReward.dbc (zero based)?
        data << int32(RewardFactionValueId[i]);

    for (uint8 i = 0; i < QUEST_REPUTATIONS_COUNT; ++i)    // reward reputation override?
        data << uint32(RewardFactionValueIdOverride[i]);

    data << uint32(GetRewSpell());
    data << uint32(GetRewSpellCast());

    for (uint8 i = 0; i < QUEST_REWARD_CURRENCY_COUNT; ++i)
        data << uint32(RewardCurrencyId[i]);

    for (uint8 i = 0; i < QUEST_REWARD_CURRENCY_COUNT; ++i)
        data << uint32(RewardCurrencyCount[i]);

    data << uint32(GetRewardSkillId());
    data << uint32(GetRewardSkillPoints());
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
    if (level > GT_MAX_LEVEL)
        level = GT_MAX_LEVEL;

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
