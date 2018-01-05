/*
 * Copyright (C) 2017-2018 AshamaneProject <https://github.com/AshamaneProject>
 * Copyright (C) 2008-2017 TrinityCore <http://www.trinitycore.org/>
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

#include "WorldQuestMgr.h"
#include "ObjectMgr.h"
#include "AchievementMgr.h"
#include "DatabaseEnv.h"
#include "Log.h"
#include "Containers.h"
#include "GridNotifiersImpl.h"

WorldQuestMgr::WorldQuestMgr()
{
}

WorldQuestMgr::~WorldQuestMgr()
{
    for (auto& worldQuestTemplate : _worldQuestTemplates)
        delete worldQuestTemplate.second;

    for (auto& activeWorldQuest : _activeWorldQuests)
        delete activeWorldQuest.second;
}

WorldQuestMgr* WorldQuestMgr::instance()
{
    static WorldQuestMgr instance;
    return &instance;
}

void WorldQuestMgr::LoadWorldQuestTemplates()
{
    // For reload case
    for (WorldQuestTemplateMap::const_iterator itr = _worldQuestTemplates.begin(); itr != _worldQuestTemplates.end(); ++itr)
        delete itr->second;
    _worldQuestTemplates.clear();
    _emissaryWorldQuestTemplates.clear();    /// pointers previously deleted

    QueryResult result = WorldDatabase.Query("SELECT id, duration, variable, value FROM world_quest");
    if (!result)
        return;

    do
    {
        Field* fields       = result->Fetch();
        uint32 questId      = fields[0].GetUInt32();
        Quest const* quest  = sObjectMgr->GetQuestTemplate(questId);

        if (!quest)
        {
            TC_LOG_ERROR("server.loading", "World Quest: %u exist but no quest template found. Skip.", questId);
            return;
        }

        WorldQuestTemplate* worldQuestTemplate = new WorldQuestTemplate(questId, fields[1].GetUInt32(), fields[2].GetUInt32(), fields[3].GetUInt8());
        _worldQuestTemplates[questId] = worldQuestTemplate;

        if (quest->IsEmissaryQuest())
            _emissaryWorldQuestTemplates[questId] = worldQuestTemplate;

    } while (result->NextRow());

    if (_emissaryWorldQuestTemplates.size() < WORLD_QUEST_EMISSARY)
        TC_LOG_ERROR("server.loading", "World Quest: There is %lu emissary quests but %u needed...", _emissaryWorldQuestTemplates.size(), uint32(WORLD_QUEST_EMISSARY));
}

void WorldQuestMgr::LoadActiveWorldQuests()
{
    // not asynch, only at startup
    PreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_SEL_WORLD_QUEST);
    PreparedQueryResult result = CharacterDatabase.Query(stmt);

    if (!result)
    {
        TC_LOG_INFO("server.loading", "World Quest: There is no active world quests.");
        return;
    }

    do 
    {
        Field* fields = result->Fetch();

        uint32 questId      = fields[0].GetUInt32();
        uint32 startTime    = fields[1].GetUInt32();

        WorldQuestTemplate* worldQuestTemplate = GetWorldQuestTemplate(questId);
        if (!worldQuestTemplate)
        {
            TC_LOG_ERROR("server.loading", "World Quest: Quest %u has world quest duration but quest is not a world quest.", questId);
            continue;
        }

        ActiveWorldQuest* activeWorldQuest = new ActiveWorldQuest(questId, startTime);
        _activeWorldQuests[worldQuestTemplate->QuestId] = activeWorldQuest;

    } while (result->NextRow());
}

void WorldQuestMgr::Update()
{
    for (auto itr = _activeWorldQuests.begin(); itr != _activeWorldQuests.end();)
    {
        if (itr->second->GetRemainingTime() <= 0)
        {
            DisableQuest(itr->second, false);
            itr = _activeWorldQuests.erase(itr);
        }
        else
            ++itr;
    }

    if (_worldQuestTemplates.size())
    {
        int32 questDiff = WORLD_QUEST_MAX_FILL - GetActiveQuestsCount() + GetActiveEmissaryQuestsCount();

        if (questDiff > 0)
        {
            WorldQuestTemplateMap inactiveWorldQuestTemplates;
            for (auto it : _worldQuestTemplates)
            {
                if (!IsQuestActive(it.first)) // Do not add already active quests
                    if (!it.second->GetQuest()->IsEmissaryQuest()) /// do not add emissay quest as world quest during roll
                        inactiveWorldQuestTemplates[it.first] = it.second;
            }

            while (questDiff && inactiveWorldQuestTemplates.size())
            {
                auto it = Trinity::Containers::SelectRandomContainerElement(inactiveWorldQuestTemplates);

                ActivateQuest(it.second);
                inactiveWorldQuestTemplates.erase(it.first);
                --questDiff;
            }
        }

        RefreshEmissaryQuests();
    }
}

void WorldQuestMgr::ActivateQuest(WorldQuestTemplate* worldQuestTemplate)
{
    Quest const* quest = worldQuestTemplate->GetQuest();
    if (!quest)
        return;

    // Shouldn't activate same quest twice
    if (IsQuestActive(worldQuestTemplate->QuestId))
        return;

    ActiveWorldQuest* activeWorldQuest = new ActiveWorldQuest(worldQuestTemplate->QuestId, time(nullptr));
    _activeWorldQuests[worldQuestTemplate->QuestId] = activeWorldQuest;

    // We add Emissary Quests to all eligible players
    if (quest->IsEmissaryQuest())
    {
        SessionMap const& smap = sWorld->GetAllSessions();
        for (SessionMap::const_iterator iter = smap.begin(); iter != smap.end(); ++iter)
            if (Player* player = iter->second->GetPlayer())
                if (player->HasWorldQuestEnabled())
                    if (player->GetQuestStatus(worldQuestTemplate->QuestId) == QUEST_STATUS_NONE)
                        player->AddQuest(quest, nullptr);
    }

    PreparedStatement* stmt = nullptr;
    stmt = CharacterDatabase.GetPreparedStatement(CHAR_REP_WORLD_QUEST);
    stmt->setUInt32(0, activeWorldQuest->QuestId);
    stmt->setUInt32(1, activeWorldQuest->StartTime);
    CharacterDatabase.Execute(stmt);
}

void WorldQuestMgr::DisableQuest(ActiveWorldQuest* activeWorldQuest, bool deleteFromMap/* = true*/)
{
    Quest const* quest = sObjectMgr->GetQuestTemplate(activeWorldQuest->QuestId);
    if (!quest)
        return;

    // Can't disable non active world quests
    if (!IsQuestActive(activeWorldQuest->QuestId))
        return;

    // Remove to connected quest status/rewarded and criteria for the next world quest fill
    SessionMap const& smap = sWorld->GetAllSessions();
    for (SessionMap::const_iterator iter = smap.begin(); iter != smap.end(); ++iter)
    {
        if (Player* player = iter->second->GetPlayer())
        {
            player->RemoveActiveQuest(quest, true);
            player->RemoveRewardedQuest(quest->GetQuestId(), true);
            for (auto criteria : GetCriteriasForQuest(quest->GetQuestId()))
                player->GetAchievementMgr()->ResetCriteriaId(CRITERIA_TYPE_COMPLETE_QUEST, criteria->ModifierTreeId);
        }
    }

    for (auto criteria : GetCriteriasForQuest(quest->GetQuestId()))
        CharacterDatabase.PExecute("DELETE FROM character_achievement_progress WHERE criteria = %u", criteria->ID);

    PreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_WORLD_QUEST);
    stmt->setUInt32(0, quest->GetQuestId());
    CharacterDatabase.Execute(stmt);
    CharacterDatabase.PExecute("DELETE FROM character_queststatus WHERE quest = %u", quest->GetQuestId());
    CharacterDatabase.PExecute("DELETE FROM character_queststatus_objectives WHERE quest = %u", quest->GetQuestId());
    CharacterDatabase.PExecute("DELETE FROM character_queststatus_rewarded WHERE quest = %u", quest->GetQuestId());

    delete activeWorldQuest;
    if (deleteFromMap)
        _activeWorldQuests.erase(activeWorldQuest->QuestId);
}

bool WorldQuestMgr::IsQuestActive(uint32 questId)
{
    return _activeWorldQuests.find(questId) != _activeWorldQuests.end();
}

WorldQuestTemplate* WorldQuestMgr::GetWorldQuestTemplate(uint32 questId)
{
    if (_worldQuestTemplates.find(questId) == _worldQuestTemplates.end())
        return nullptr;

    return _worldQuestTemplates.find(questId)->second;
}

uint8 WorldQuestMgr::GetActiveEmissaryQuestsCount()
{
    return std::count_if(_activeWorldQuests.begin(), _activeWorldQuests.end(), [](const std::pair<uint32, ActiveWorldQuest*> pair) -> bool
    {
        return pair.second->IsEmissaryQuest();
    });
}

uint32 WorldQuestMgr::GetActiveQuestsCount()
{
    return _activeWorldQuests.size();
}

void WorldQuestMgr::BuildPacket(Player* player, WorldPackets::Quest::WorldQuestUpdate& packet)
{
    WorldPackets::Quest::WorldQuestUpdateInfo quest;
    for (auto itr : _activeWorldQuests)
    {
        ActiveWorldQuest* activeWorldQuest = itr.second;
        if (player->IsQuestRewarded(itr.first))
            continue;

        if (WorldQuestTemplate const* worldQuestTemplate = activeWorldQuest->GetTemplate())
        {
            quest.QuestID       = activeWorldQuest->QuestId;
            quest.LastUpdate    = activeWorldQuest->StartTime;
            quest.VariableID    = worldQuestTemplate->VariableId;
            quest.Timer         = worldQuestTemplate->Duration;
            quest.Value         = worldQuestTemplate->Value;
            packet.WorldQuestUpdates.push_back(quest);
        }
    }
}

void WorldQuestMgr::FillInitWorldStates(WorldPackets::WorldState::InitWorldStates& packet)
{
    for (auto itr : _activeWorldQuests)
        if (WorldQuestTemplate const* worldQuestTemplate = itr.second->GetTemplate())
            packet.Worldstates.emplace_back(worldQuestTemplate->VariableId, worldQuestTemplate->Value);
}

std::vector<CriteriaEntry const*> WorldQuestMgr::GetCriteriasForQuest(uint32 quest_id)
{
    std::vector<CriteriaEntry const*> gets;
    Quest const* quest = sObjectMgr->GetQuestTemplate(quest_id);
    if (!quest)
        return gets;

    CriteriaList criterias = sCriteriaMgr->GetPlayerCriteriaByType(CRITERIA_TYPE_COMPLETE_QUEST);
    for (Criteria const* criteria : criterias)
        if (criteria->Entry->Asset.QuestID == quest_id && criteria->Entry->Flags & 0x20) // guessed for World Quest related stuff
            gets.push_back(criteria->Entry);

    return gets;
}

void WorldQuestMgr::RefreshEmissaryQuests()
{
    if (GetActiveEmissaryQuestsCount() >= WORLD_QUEST_EMISSARY)
        return;

    if (_emissaryWorldQuestTemplates.size() < WORLD_QUEST_EMISSARY)
        return;

    auto it = Trinity::Containers::SelectRandomContainerElement(_emissaryWorldQuestTemplates);
    if (!IsQuestActive(it.first))
        ActivateQuest(it.second);
}

void WorldQuestMgr::AddEmissaryQuestsOnPlayerIfNeeded(Player* player)
{
    if (!player->HasWorldQuestEnabled())
        return;

    for (auto itr : _activeWorldQuests)
        if (WorldQuestTemplate const* worldQuestTemplate = itr.second->GetTemplate())
            if (Quest const* quest = worldQuestTemplate->GetQuest())
                if (quest->IsEmissaryQuest())
                    if (player->GetQuestStatus(itr.first) == QUEST_STATUS_NONE)
                        player->AddQuest(quest, nullptr);
}

uint32 WorldQuestMgr::GetTimerForQuest(uint32 questId)
{
    auto itr = _activeWorldQuests.find(questId);
    if (itr == _activeWorldQuests.end())
        return 0;

    return std::max(0, itr->second->GetRemainingTime());
}
