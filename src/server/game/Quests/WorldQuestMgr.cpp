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
    for (auto& quest : _worldQuestTemplates)
        delete quest.second;

    _worldQuestTemplates.clear();
    _emissaryQuests.clear();    /// pointers previously deleted
}

WorldQuestMgr* WorldQuestMgr::instance()
{
    static WorldQuestMgr instance;
    return &instance;
}

void WorldQuestMgr::LoadWorldQuests()
{
    // For reload case
    for (WorldQuestMap::const_iterator itr = _worldQuestTemplates.begin(); itr != _worldQuestTemplates.end(); ++itr)
        delete itr->second;
    _worldQuestTemplates.clear();
    _emissaryQuests.clear();    /// pointers previously deleted

    QueryResult result = WorldDatabase.Query("SELECT id, duration, variable, value FROM world_quest");
    if (!result)
        return;
    do
    {
        Field* fields = result->Fetch();
        sWorldQuestMgr->AddQuest(fields);

    } while (result->NextRow());

    if (_emissaryQuests.size() < WORLD_QUEST_EMISSARY)
        TC_LOG_ERROR("server.loading", "World Quest: There is %lu emissary quests but %u needed...", _emissaryQuests.size(), uint32(WORLD_QUEST_EMISSARY));
}

void WorldQuestMgr::AddQuest(Field* fields)
{
    uint32 questid = fields[0].GetUInt32();
    Quest const* quest = sObjectMgr->GetQuestTemplate(questid);

    if (!quest)
    {
        TC_LOG_ERROR("server.loading", "World Quest: %u exist but no quest template found. Skip.", questid);
        return;
    }

    WorldQuestTemplate* world = new WorldQuestTemplate((Quest*)quest, fields[1].GetUInt32(), fields[2].GetUInt32(), fields[3].GetUInt8());
    _worldQuestTemplates[questid] = world;

    if (quest->IsEmissaryQuest())
        _emissaryQuests[questid] = world;
}

void WorldQuestMgr::LoadQuestsStatus()
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

        uint32 quest_id = fields[0].GetUInt32();
        uint32 starttime = fields[1].GetUInt32();
        uint32 remaining = fields[2].GetUInt32();
        WorldQuestTemplate* quest = GetQuest(quest_id);

        if (!quest)
        {
            TC_LOG_ERROR("server.loading", "World Quest: Quest %u has world quest duration but quest is not a world quest.", quest_id);
            continue;
        }

        quest->remaining = remaining;
        quest->starttimer = starttime;
        quest->active = true;

    } while (result->NextRow());
}

void WorldQuestMgr::Update(uint32 diff)
{
    for (auto& itr : _worldQuestTemplates)
    {
        WorldQuestTemplate* quest = itr.second;

        if (!quest)
            continue;

        if (quest->active)
        {
            quest->remaining -= diff;

            if (quest->remaining <= 0)
                DisableQuest(quest);
            else
                ActivateQuest(quest); // update timer
        }
    }

    if (_worldQuestTemplates.size())
    {
        int32 emissary_count = _emissaryQuests.size();
        int32 quest_count = WORLD_QUEST_MAX_FILL - GetActiveQuestsCount() + emissary_count;

        if (quest_count < 0)
            quest_count = 0;

        WorldQuestMap inactiveWorldQuestTemplates;
        for (auto it : _worldQuestTemplates)
        {
            if (!it.second->active && !it.second->quest->IsEmissaryQuest())   /// do not add emissay quest as world quest during roll
                inactiveWorldQuestTemplates[it.first] = it.second;
        }

        while (quest_count)
        {
            if (inactiveWorldQuestTemplates.size() <= 0)
                break;

            auto it = inactiveWorldQuestTemplates.begin();
            std::advance(it, rand() % inactiveWorldQuestTemplates.size());

            ActivateQuest(it->second, true);
            inactiveWorldQuestTemplates.erase(it);
            --quest_count;
        }

        RefreshEmissaryQuests();
    }
}

void WorldQuestMgr::DisableQuest(WorldQuestTemplate* quest)
{
    Quest* quest_template = quest->quest;
    if (!quest_template)
        return;

    if (quest_template->IsEmissaryQuest())
        if (std::find(_activeEmissaryQuests.begin(), _activeEmissaryQuests.end(), quest_template) != _activeEmissaryQuests.end())
            _activeEmissaryQuests.erase(std::find(_activeEmissaryQuests.begin(), _activeEmissaryQuests.end(), quest_template));

    quest->active = false;
    quest->remaining = 0;
    quest->starttimer = 0;

    /// Remove to connected quest status/rewarded and criteria for the next world quest fill
    SessionMap const& smap = sWorld->GetAllSessions();
    for (SessionMap::const_iterator iter = smap.begin(); iter != smap.end(); ++iter)
    {
        if (Player* player = iter->second->GetPlayer())
        {
            player->RemoveActiveQuest(quest_template, true);
            player->RemoveRewardedQuest(quest_template->GetQuestId(), true);
            for (auto criteria : GetCriteriasForQuest(quest_template->GetQuestId()))
                player->GetAchievementMgr()->ResetCriteriaId(CRITERIA_TYPE_COMPLETE_QUEST, criteria->ModifierTreeId);
        }
    }

    for (auto criteria : GetCriteriasForQuest(quest_template->GetQuestId()))
        CharacterDatabase.PExecute("DELETE FROM character_achievement_progress WHERE criteria = %u", criteria->ID);

    PreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_WORLD_QUEST);
    stmt->setUInt32(0, quest_template->GetQuestId());
    CharacterDatabase.Execute(stmt);
    CharacterDatabase.PExecute("DELETE FROM character_queststatus WHERE quest = %u", quest_template->GetQuestId());
    CharacterDatabase.PExecute("DELETE FROM character_queststatus_objectives WHERE quest = %u", quest_template->GetQuestId());
    CharacterDatabase.PExecute("DELETE FROM character_queststatus_rewarded WHERE quest = %u", quest_template->GetQuestId());
}

void WorldQuestMgr::ActivateQuest(WorldQuestTemplate* quest, bool create /* = flase */)
{
    Quest* quest_template = quest->quest;

    if (!quest_template)
        return;

    PreparedStatement* stmt = nullptr;

    if (create)
    {

        if (quest_template->IsEmissaryQuest())
            _activeEmissaryQuests.push_back(quest_template);

        if (quest_template->IsEmissaryQuest())
        {
            SessionMap const& smap = sWorld->GetAllSessions();
            for (SessionMap::const_iterator iter = smap.begin(); iter != smap.end(); ++iter)
                if (Player* player = iter->second->GetPlayer())
                    if (player->HasWorldQuestEnabled())
                        player->AddQuest(quest_template, nullptr);
        }

        quest->active = true;
        quest->starttimer = time(nullptr);
        quest->remaining = quest->duration;

        stmt = CharacterDatabase.GetPreparedStatement(CHAR_REP_WORLD_QUEST);
        stmt->setUInt32(0, quest_template->GetQuestId());
        stmt->setUInt32(1, quest->starttimer);
        stmt->setUInt32(2, quest->remaining);
    }
    else
    {
        stmt = CharacterDatabase.GetPreparedStatement(CHAR_UPD_WORLD_QUEST);
        stmt->setUInt32(0, quest->remaining);
        stmt->setUInt32(1, quest_template->GetQuestId());
    }

    CharacterDatabase.Execute(stmt);
}

WorldQuestTemplate* WorldQuestMgr::GetQuest(uint32 quest_id)
{
    if (_worldQuestTemplates.find(quest_id) == _worldQuestTemplates.end())
        return nullptr;

    return _worldQuestTemplates.find(quest_id)->second;
}

uint8 WorldQuestMgr::GetActiveEmissaryQuestsCount()
{
    uint8 index = 0;
    for (auto world : _worldQuestTemplates)
    {
        WorldQuestTemplate* temp = world.second;
        if (!temp)
            continue;

        if (temp->active && temp->quest->IsEmissaryQuest())
            index++;
    }
    return index;
}

uint32 WorldQuestMgr::GetActiveQuestsCount()
{
    uint32 index = 0;

    for (auto itr : _worldQuestTemplates)
        if (itr.second && itr.second->active)
            index++;

    return index;
}

void WorldQuestMgr::BuildPacket(WorldPackets::Quest::WorldQuestUpdate& packet)
{
    WorldPackets::Quest::WorldQuestUpdateInfo quest;
    for (auto itr : _worldQuestTemplates)
    {
        WorldQuestTemplate* temp = itr.second;
        if (temp->active)
        {
            quest.QuestID = temp->quest->GetQuestId();
            quest.LastUpdate = temp->starttimer;
            quest.VariableID = temp->variableID;
            quest.Timer = temp->duration;
            quest.Value = temp->value;
            packet.WorldQuestUpdates.push_back(quest);
        }
    }
}

void WorldQuestMgr::FillInitWorldStates(WorldPackets::WorldState::InitWorldStates& packet)
{
    for (auto itr : _worldQuestTemplates)
    {
        WorldQuestTemplate* temp = itr.second;
        if (temp->active)
            packet.Worldstates.emplace_back(temp->variableID, temp->value);
    }
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
    uint8 emissay_quest = GetActiveEmissaryQuestsCount();

    if (emissay_quest != WORLD_QUEST_EMISSARY)
    {
        if ((_emissaryQuests.size()) < WORLD_QUEST_EMISSARY)
            return;

        int8 diff = emissay_quest - WORLD_QUEST_EMISSARY;

        while (diff)
        {
            if (diff < 0)
            {
                auto it = _emissaryQuests.begin();
                std::advance(it, rand() % _emissaryQuests.size());
                if (!it->second->active)   /// do not add emissay quest as world quest during roll
                {
                    ActivateQuest(it->second, true);
                    diff++;
                }
            }
            else
            {
                auto it = _emissaryQuests.begin();
                std::advance(it, rand() % _emissaryQuests.size());
                if (it->second->active)   /// do not add emissay quest as world quest during roll
                {
                    DisableQuest(it->second);
                    diff--;
                }
            }
        }
    }
}

void WorldQuestMgr::AddEmissaryQuestOnPlayerIfNeeded(Player* player)
{
    if (!player->HasWorldQuestEnabled())
        return;

    for (auto temp : _emissaryQuests)
        if (temp.second->active)
            if (player->GetQuestStatus(temp.second->quest->GetQuestId()) == QUEST_STATUS_NONE)
                player->AddQuest(temp.second->quest, nullptr);
}

uint32 WorldQuestMgr::GetTimerForQuest(uint32 quest_id)
{
    for (auto tmp : _worldQuestTemplates)
    {
        WorldQuestTemplate* temp = tmp.second;

        if (!temp)
            continue;

        if (temp->quest->GetQuestId() == quest_id)
            return temp->remaining;
    }

    return 0;
}
