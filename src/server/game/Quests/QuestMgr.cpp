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
#include "ObjectMgr.h"
#include "Player.h"
#include <algorithm>

namespace
{
std::unordered_map<uint32, std::vector<QuestLineXQuestEntry const*>> QuestsByQuestLine;
}

void QuestMgr::Load()
{
    for (QuestLineXQuestEntry const* questLineQuest : sQuestLineXQuestStore)
        QuestsByQuestLine[questLineQuest->QuestLineID].push_back(questLineQuest);

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
