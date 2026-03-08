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

#include "QuestMgr.h"
#include "DB2Stores.h"
#include "MapUtils.h"
#include "ObjectMgr.h"
#include "Player.h"
#include <algorithm>

namespace
{
std::unordered_map<uint32, std::vector<QuestLineXQuestEntry const*>> QuestsByQuestLine;

struct QuestLineData
{
    QuestLineXQuestEntry const* QuestLineQuest = nullptr;
    std::vector<CampaignEntry const*>* Campaigns = nullptr;
};
std::map<uint32, std::vector<CampaignEntry const*>> CampaignsByQuestLine;
std::unordered_map<uint32, std::vector<QuestLineData>> QuestLineDataByQuest;

struct CampaignQuestLine
{
    uint32 CampaignId = 0;
    uint32 QuestLineId = 0;

    friend std::strong_ordering operator<=>(CampaignQuestLine const& left, CampaignQuestLine const& right) = default;
};
std::vector<CampaignQuestLine> CampaignQuestLines;

struct CampaignQuestLinesSentinel
{
    std::vector<CampaignQuestLine>::const_iterator End;
    uint32 CampaignId;

    friend bool operator==(std::vector<CampaignQuestLine>::const_iterator const& itr, CampaignQuestLinesSentinel const& end)
    {
        return itr == end.End || itr->CampaignId != end.CampaignId;
    }
};

Trinity::IteratorPair<std::vector<CampaignQuestLine>::iterator, CampaignQuestLinesSentinel> GetQuestLinesForCampaign(uint32 campaignId)
{
    return Trinity::Containers::MakeIteratorPair(
        std::ranges::lower_bound(CampaignQuestLines, campaignId, std::ranges::less(), &CampaignQuestLine::CampaignId),
        CampaignQuestLinesSentinel{ .End = CampaignQuestLines.end(), .CampaignId = campaignId });
}
}

void QuestMgr::Load()
{
    for (CampaignXQuestLineEntry const* campaignQuestLine : sCampaignXQuestLineStore)
    {
        if (CampaignEntry const* campaign = sCampaignStore.LookupEntry(campaignQuestLine->CampaignID))
        {
            CampaignsByQuestLine[campaignQuestLine->QuestLineID].push_back(campaign);
            CampaignQuestLines.push_back({ .CampaignId = campaignQuestLine->CampaignID, .QuestLineId = campaignQuestLine->QuestLineID });
        }
    }

    for (QuestLineXQuestEntry const* questLineQuest : sQuestLineXQuestStore)
    {
        QuestsByQuestLine[questLineQuest->QuestLineID].push_back(questLineQuest);

        QuestLineData& questLineData = QuestLineDataByQuest[questLineQuest->QuestID].emplace_back();
        questLineData.QuestLineQuest = questLineQuest;
        questLineData.Campaigns = Trinity::Containers::MapGetValuePtr(CampaignsByQuestLine, questLineQuest->QuestLineID);
    }

    std::ranges::sort(CampaignQuestLines);

    for (auto& [_, questLineQuests] : QuestsByQuestLine)
        std::ranges::sort(questLineQuests, std::ranges::less(), &QuestLineXQuestEntry::OrderIndex);
}

std::span<QuestLineXQuestEntry const* const> QuestMgr::GetQuestsForQuestLine(uint32 questLineId)
{
    std::span<QuestLineXQuestEntry const* const> result;
    if (auto itr = QuestsByQuestLine.find(questLineId); itr != QuestsByQuestLine.end())
        result = itr->second;

    return result;
}

bool QuestMgr::IsQuestLineQuestAvailableForPlayer(uint32 questLineId, Player const* player)
{
    for (QuestLineXQuestEntry const* questLineQuest : GetQuestsForQuestLine(questLineId))
        if (Quest const* quest = sObjectMgr->GetQuestTemplate(questLineQuest->QuestID))
            if (player->CanTakeQuest(quest, false))
                return true;

    return false;
}

bool QuestMgr::IsQuestLineQuestActiveForPlayer(uint32 questLineId, Player const* player)
{
    for (QuestLineXQuestEntry const* questLineQuest : GetQuestsForQuestLine(questLineId))
        if (player->IsActiveQuest(questLineQuest->QuestID))
            return true;

    return false;
}

bool QuestMgr::IsQuestLineCompletedByPlayer(uint32 questLineId, Player const* player)
{
    for (QuestLineXQuestEntry const* questLineQuest : GetQuestsForQuestLine(questLineId))
    {
        if (questLineQuest->HasFlag(QuestLineXQuestFlags::IgnoreForCompletion))
            continue;

        if (!player->IsQuestCompletedBitSet(questLineQuest->QuestID))
            return false;
    }

    return true;
}

QuestMgr::QuestLineStats QuestMgr::GetQuestLineStatsForPlayer(uint32 questLineId, Player const* player)
{
    QuestLineStats stats;
    for (QuestLineXQuestEntry const* questLineQuest : GetQuestsForQuestLine(questLineId))
    {
        if (questLineQuest->HasFlag(QuestLineXQuestFlags::IgnoreForCompletion))
            continue;

        stats.Completed += player->IsQuestCompletedBitSet(questLineQuest->QuestID) ? 1 : 0;
        ++stats.Total;
    }

    return stats;
}

void QuestMgr::SkipQuestLineForPlayer(uint32 questLineId, Player* player)
{
    std::span<QuestLineXQuestEntry const* const> questLineQuests = GetQuestsForQuestLine(questLineId);
    std::vector<uint32> questIds(questLineQuests.size());
    std::ranges::transform(questLineQuests, questIds.begin(), &QuestLineXQuestEntry::QuestID);
    player->SkipQuests(questIds);
}

bool QuestMgr::IsCampaignCompletedByPlayer(uint32 campaignId, Player const* player)
{
    auto questLines = GetQuestLinesForCampaign(campaignId);
    if (questLines.begin() == questLines.end())
        return false;

    for (CampaignQuestLine const& campaignQuestLine : questLines)
        if (!IsQuestLineCompletedByPlayer(campaignQuestLine.QuestLineId, player))
            return false;

    // all questlines completed
    return true;
}

bool QuestMgr::IsCampaignQuestStatusVisibleForPlayer(uint32 questId, Player const* player)
{
    auto itr = QuestLineDataByQuest.find(questId);
    if (itr == QuestLineDataByQuest.end())
        return false;

    for (QuestLineData const& questLineData : itr->second)
    {
        if (!questLineData.Campaigns)
            continue;

        for (CampaignEntry const* campaign : *questLineData.Campaigns)
        {
            if (campaign->HasFlag(CampaignFlags::DontUseJourneyQuestBang))
                continue;

            if (!ConditionMgr::IsPlayerMeetingCondition(player, campaign->Prerequisite))
                continue;

            if (!ConditionMgr::IsPlayerMeetingCondition(player, campaign->Stalled))
                continue;

            if (campaign->Completed && ConditionMgr::IsPlayerMeetingCondition(player, campaign->Completed))
                continue;

            if (!ConditionMgr::IsPlayerMeetingCondition(player, campaign->OnlyStallIf))
                continue;

            return true;
        }
    }

    return false;
}

void QuestMgr::SkipCampaignForPlayer(uint32 campaignId, Player* player)
{
    std::vector<uint32> questIds;

    for (CampaignQuestLine const& campaignQuestLine : GetQuestLinesForCampaign(campaignId))
    {
        std::ptrdiff_t oldSize = std::ssize(questIds);
        std::span<QuestLineXQuestEntry const* const> questLineQuests = GetQuestsForQuestLine(campaignQuestLine.QuestLineId);
        questIds.resize(oldSize + questLineQuests.size());
        std::ranges::transform(questLineQuests, questIds.begin() + oldSize, &QuestLineXQuestEntry::QuestID);
    }

    player->SkipQuests(questIds);
}
