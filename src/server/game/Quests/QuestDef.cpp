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

Quest::Quest(Field* questRecord)
{
    Id = questRecord[0].GetUInt32();
    Method = questRecord[1].GetUInt8();
    Level = questRecord[2].GetInt16();
    MinLevel = uint32(questRecord[3].GetInt16());
    MaxLevel = uint32(questRecord[4].GetInt16());
    ZoneOrSort = questRecord[5].GetInt16();
    Type = questRecord[6].GetUInt16();
    SuggestedPlayers = questRecord[7].GetUInt8();
    LimitTime = questRecord[8].GetUInt32();
    RequiredClasses = questRecord[9].GetUInt16();
    RequiredRaces = questRecord[10].GetUInt32();
    RequiredSkillId = questRecord[11].GetUInt16();
    RequiredSkillPoints = questRecord[12].GetUInt16();
    RequiredFactionId1 = questRecord[13].GetUInt16();
    RequiredFactionId2 = questRecord[14].GetUInt16();
    RequiredFactionValue1 = questRecord[15].GetInt32();
    RequiredFactionValue2 = questRecord[16].GetInt32();
    RequiredMinRepFaction = questRecord[17].GetUInt16();
    RequiredMaxRepFaction = questRecord[18].GetUInt16();
    RequiredMinRepValue = questRecord[19].GetInt32();
    RequiredMaxRepValue = questRecord[20].GetInt32();
    PrevQuestId = questRecord[21].GetInt32();
    NextQuestId = questRecord[22].GetInt32();
    ExclusiveGroup = questRecord[23].GetInt32();
    NextQuestIdChain = questRecord[24].GetUInt32();
    RewardXPId = questRecord[25].GetUInt8();
    RewardOrRequiredMoney = questRecord[26].GetInt32();
    RewardMoneyMaxLevel = questRecord[27].GetUInt32();
    RewardSpell = questRecord[28].GetUInt32();
    RewardSpellCast = questRecord[29].GetInt32();
    RewardHonor = questRecord[30].GetUInt32();
    RewardHonorMultiplier = questRecord[31].GetFloat();
    RewardMailTemplateId = questRecord[32].GetUInt32();
    RewardMailDelay = questRecord[33].GetUInt32();
    SourceItemId = questRecord[34].GetUInt32();
    SourceItemIdCount = questRecord[35].GetUInt8();
    SourceSpellid = questRecord[36].GetUInt32();
    Flags = questRecord[37].GetUInt32();
    SpecialFlags = questRecord[38].GetUInt8();
    MinimapTargetMark = questRecord[39].GetUInt8();
    RewardTitleId = questRecord[40].GetUInt8();
    RequiredPlayerKills = questRecord[41].GetUInt8();
    RewardTalents = questRecord[42].GetUInt8();
    RewardArenaPoints = questRecord[43].GetUInt16();
    RewardSkillId = questRecord[44].GetUInt16();
    RewardSkillPoints = questRecord[45].GetUInt8();
    RewardReputationMask = questRecord[46].GetUInt8();
    QuestGiverPortrait = questRecord[47].GetUInt32();
    QuestTurnInPortrait = questRecord[48].GetUInt32();
    for (int i = 0; i < QUEST_REWARDS_COUNT; ++i)
        RewardItemId[i] = questRecord[49+i].GetUInt32();

    for (int i = 0; i < QUEST_REWARDS_COUNT; ++i)
        RewardItemIdCount[i] = questRecord[53+i].GetUInt16();

    for (int i = 0; i < QUEST_REWARD_CHOICES_COUNT; ++i)
        RewardChoiceItemId[i] = questRecord[57+i].GetUInt32();

    for (int i = 0; i < QUEST_REWARD_CHOICES_COUNT; ++i)
        RewardChoiceItemCount[i] = questRecord[63+i].GetUInt16();

    for (int i = 0; i < QUEST_REPUTATIONS_COUNT; ++i)
        RewardFactionId[i] = questRecord[69+i].GetUInt16();

    for (int i = 0; i < QUEST_REPUTATIONS_COUNT; ++i)
        RewardFactionValueId[i] = questRecord[74+i].GetInt32();

    for (int i = 0; i < QUEST_REPUTATIONS_COUNT; ++i)
        RewardFactionValueIdOverride[i] = questRecord[79+i].GetInt32();

    PointMapId = questRecord[84].GetUInt16();
    PointX = questRecord[85].GetFloat();
    PointY = questRecord[86].GetFloat();
    PointOption = questRecord[87].GetUInt32();
    Title = questRecord[88].GetString();
    Objectives = questRecord[89].GetString();
    Details = questRecord[90].GetString();
    EndText = questRecord[91].GetString();
    CompletedText = questRecord[92].GetString();
    OfferRewardText = questRecord[93].GetString();
    RequestItemsText = questRecord[94].GetString();

    for (int i = 0; i < QUEST_OBJECTIVES_COUNT; ++i)
        RequiredNpcOrGo[i] = questRecord[95+i].GetInt32();

    for (int i = 0; i < QUEST_OBJECTIVES_COUNT; ++i)
        RequiredNpcOrGoCount[i] = questRecord[99+i].GetUInt16();

    for (int i = 0; i < QUEST_SOURCE_ITEM_IDS_COUNT; ++i)
        RequiredSourceItemId[i] = questRecord[103+i].GetUInt32();

    for (int i = 0; i < QUEST_SOURCE_ITEM_IDS_COUNT; ++i)
        RequiredSourceItemCount[i] = questRecord[107+i].GetUInt16();

    for (int i = 0; i < QUEST_ITEM_OBJECTIVES_COUNT; ++i)
        RequiredItemId[i] = questRecord[111+i].GetUInt32();

    for (int i = 0; i < QUEST_ITEM_OBJECTIVES_COUNT; ++i)
        RequiredItemCount[i] = questRecord[117+i].GetUInt16();

    RequiredSpell = questRecord[123].GetUInt32();

    for (int i = 0; i < QUEST_OBJECTIVES_COUNT; ++i)
        ObjectiveText[i] = questRecord[124+i].GetString();

    for (int i = 0; i < QUEST_REWARD_CURRENCY_COUNT; ++i)
        RewardCurrencyId[i] = questRecord[128+i].GetUInt16();

    for (int i = 0; i < QUEST_REWARD_CURRENCY_COUNT; ++i)
        RewardCurrencyCount[i] = questRecord[132+i].GetUInt8();

    for (int i = 0; i < QUEST_REQUIRED_CURRENCY_COUNT; ++i)
        RequiredCurrencyId[i] = questRecord[136+i].GetUInt16();

    for (int i = 0; i < QUEST_REQUIRED_CURRENCY_COUNT; ++i)
        RequiredCurrencyCount[i] = questRecord[140+i].GetUInt8();

    QuestGiverTextWindow = questRecord[144].GetString();
    QuestGiverTargetName = questRecord[145].GetString();
    QuestTurnTextWindow = questRecord[146].GetString();
    QuestTurnTargetName = questRecord[147].GetString();
    SoundAccept = questRecord[148].GetUInt16();
    SoundTurnIn = questRecord[149].GetUInt16();

    for (int i = 0; i < QUEST_EMOTE_COUNT; ++i)
        DetailsEmote[i] = questRecord[150+i].GetUInt16();

    for (int i = 0; i < QUEST_EMOTE_COUNT; ++i)
        DetailsEmoteDelay[i] = questRecord[154+i].GetUInt32();

    EmoteOnIncomplete = questRecord[158].GetUInt16();
    EmoteOnComplete = questRecord[159].GetUInt16();

    for (int i = 0; i < QUEST_EMOTE_COUNT; ++i)
        OfferRewardEmote[i] = questRecord[160+i].GetInt16();

    for (int i = 0; i < QUEST_EMOTE_COUNT; ++i)
        OfferRewardEmoteDelay[i] = questRecord[164+i].GetInt32();

    //int32 VerifiedBuild = questRecord[168].GetInt32();

    if (SpecialFlags & QUEST_SPECIAL_FLAGS_AUTO_ACCEPT)
        Flags |= QUEST_FLAGS_AUTO_ACCEPT;

    _reqItemsCount = 0;
    _reqNpcOrGoCount = 0;
    _rewItemsCount = 0;
    _rewChoiceItemsCount = 0;
    _rewCurrencyCount = 0;
    _reqCurrencyCount = 0;

    for (int i = 0; i < QUEST_ITEM_OBJECTIVES_COUNT; ++i)
        if (RequiredItemId[i])
            ++_reqItemsCount;

    for (int i = 0; i < QUEST_OBJECTIVES_COUNT; ++i)
        if (RequiredNpcOrGo[i])
            ++_reqNpcOrGoCount;

    for (int i = 0; i < QUEST_REWARDS_COUNT; ++i)
        if (RewardItemId[i])
            ++_rewItemsCount;

    for (int i = 0; i < QUEST_REWARD_CHOICES_COUNT; ++i)
        if (RewardChoiceItemId[i])
            ++_rewChoiceItemsCount;

    for (int i = 0; i < QUEST_REWARD_CURRENCY_COUNT; ++i)
        if (RewardCurrencyId[i])
            ++_rewCurrencyCount;

    for (int i = 0; i < QUEST_REQUIRED_CURRENCY_COUNT; ++i)
        if (RequiredCurrencyId[i])
            ++_reqCurrencyCount;
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

        uint32 xp = diffFactor * xpentry->Exp[RewardXPId] / 10;
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
    if (RewardOrRequiredMoney <= 0)
        return RewardOrRequiredMoney;

    return int32(RewardOrRequiredMoney * sWorld->getRate(RATE_DROP_MONEY));
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
    if (HasFlag(QUEST_FLAGS_NO_MONEY_FROM_XP))
        return 0;

    return RewardMoneyMaxLevel;
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
