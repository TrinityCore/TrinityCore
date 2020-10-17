/*
 * Copyright (C) 2008-2020 TrinityCore <http://www.trinitycore.org/>
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
#include "QuestObjectiveCriteriaMgr.h"
#include "Log.h"
#include "Containers.h"
#include "GridNotifiersImpl.h"

WorldQuestMgr::WorldQuestMgr()
{
}

WorldQuestMgr::~WorldQuestMgr()
{
    CleanWorldQuestTemplates();
}

void WorldQuestMgr::CleanWorldQuestTemplates()
{
    std::set<WorldQuestTemplate*> toDeleteTemplates;
    std::set<ActiveWorldQuest*> toDeleteActiveTemplates;

    for (auto expansionTemplates : _worldQuestTemplates)
        for (auto teamTemplates : expansionTemplates.second)
            for (auto itr : teamTemplates.second)
                toDeleteTemplates.insert(itr.second);

    for (auto expansionEmissaryTemplates : _emissaryWorldQuestTemplates)
        for (auto teamEmissaryTemplates : expansionEmissaryTemplates.second)
            for (auto itr : teamEmissaryTemplates.second)
                toDeleteTemplates.insert(itr.second);

    for (auto expansionWorldQuests : _activeWorldQuests)
        for (auto teamWorldQuest : expansionWorldQuests.second)
            for (auto activeWorldQuest : teamWorldQuest.second)
                toDeleteActiveTemplates.insert(activeWorldQuest.second);

    for (auto worldQuest : toDeleteTemplates)
        delete worldQuest;

    for (auto activeWorldQuest : toDeleteActiveTemplates)
        delete activeWorldQuest;

    _worldQuestTemplates.clear();
    _emissaryWorldQuestTemplates.clear();
    _activeWorldQuests.clear();
}

WorldQuestMgr* WorldQuestMgr::instance()
{
    static WorldQuestMgr instance;
    return &instance;
}

void WorldQuestMgr::LoadWorldQuestTemplates()
{
    CleanWorldQuestTemplates();

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
            continue;
        }

        WorldQuestTemplate* worldQuestTemplate = new WorldQuestTemplate(questId, fields[1].GetUInt32(), fields[2].GetUInt32(), fields[3].GetUInt8());
        AddWorldQuestTemplate(quest, worldQuestTemplate);

    } while (result->NextRow());

    WorldQuestContainer worldQuests = sObjectMgr->GetWorldQuestStore();
    for (auto quests : worldQuests)
    {
        for (uint32 questId : quests.second)
        {
            if (Quest const* quest = sObjectMgr->GetQuestTemplate(questId))
            {
                auto itr = _worldQuestTemplates[quest->GetExpansion()].find(questId);
                if (itr == _worldQuestTemplates[quest->GetExpansion()].end())
                {
                    WorldQuestTemplate* worldQuestTemplate = new WorldQuestTemplate(questId, 7200, 12506, 1);
                    AddWorldQuestTemplate(quest, worldQuestTemplate);
                }
            }
        }
    }

    if (_emissaryWorldQuestTemplates.size() < WORLD_QUEST_EMISSARY)
        TC_LOG_ERROR("server.loading", "World Quest: There is %lu emissary quests but %u needed...", _emissaryWorldQuestTemplates.size(), uint32(WORLD_QUEST_EMISSARY));
}

void WorldQuestMgr::AddWorldQuestTemplate(Quest const* quest, WorldQuestTemplate* worldQuestTemplate)
{
    uint8 questTeamId = GetQuestTeamId(quest);
    uint32 questId = quest->GetQuestId();
    int32 questExpansion = quest->GetExpansion();

    switch (questTeamId)
    {
        case TEAM_NEUTRAL:
        {
            _worldQuestTemplates[questExpansion][TEAM_ALLIANCE][questId] = worldQuestTemplate;
            _worldQuestTemplates[questExpansion][TEAM_HORDE][questId] = worldQuestTemplate;

            if (quest->IsEmissaryQuest())
            {
                _emissaryWorldQuestTemplates[questExpansion][TEAM_ALLIANCE][questId] = worldQuestTemplate;
                _emissaryWorldQuestTemplates[questExpansion][TEAM_HORDE][questId] = worldQuestTemplate;
            }

            break;
        }
        default:
        {
            _worldQuestTemplates[questExpansion][questTeamId][questId] = worldQuestTemplate;

            if (quest->IsEmissaryQuest())
                _emissaryWorldQuestTemplates[questExpansion][questTeamId][questId] = worldQuestTemplate;

            break;
        }
    }
}

void WorldQuestMgr::LoadWorldQuestRewardTemplates()
{
    QueryResult result = WorldDatabase.Query("SELECT id, questType, rewardType - 1 AS rewardType, rewardId, rewardCount, rewardContext FROM world_quest_reward");
    if (!result)
        return;

    do
    {
        Field* fields = result->Fetch();

        WorldQuestReward worldQuestReward = WorldQuestReward(fields[0].GetUInt32(),
                                                             fields[1].GetUInt8(),
                                                             fields[2].GetUInt8(),
                                                             fields[3].GetUInt32(),
                                                             fields[4].GetUInt32(),
                                                             fields[5].GetUInt32());

        _worldQuestRewards[worldQuestReward.Id].push_back(worldQuestReward);
        _worldQuestRewardByQuestInfos[worldQuestReward.QuestType].push_back(worldQuestReward.Id);
    } while (result->NextRow());
}

void WorldQuestMgr::LoadActiveWorldQuests()
{
    // not asynch, only at startup
    CharacterDatabasePreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_SEL_WORLD_QUEST);
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
        uint32 rewardId     = fields[1].GetUInt32();
        uint32 startTime    = fields[2].GetUInt32();

        Quest const* quest = sObjectMgr->GetQuestTemplate(questId);
        if (!quest)
        {
            TC_LOG_ERROR("server.loading", "World Quest: Quest %u has world quest duration but quest does not exist.", questId);
            continue;
        }

        WorldQuestTemplate* worldQuestTemplate = GetWorldQuestTemplate(questId);
        if (!worldQuestTemplate)
        {
            TC_LOG_ERROR("server.loading", "World Quest: Quest %u has world quest duration but quest is not a world quest.", questId);
            continue;
        }

        uint8 questTeamId = GetQuestTeamId(quest);
        if (questTeamId == TEAM_NEUTRAL)
        {
            _activeWorldQuests[quest->GetExpansion()][TEAM_ALLIANCE][worldQuestTemplate->QuestId]    = new ActiveWorldQuest(questId, rewardId, startTime);
            _activeWorldQuests[quest->GetExpansion()][TEAM_HORDE][worldQuestTemplate->QuestId]       = new ActiveWorldQuest(questId, rewardId, startTime);
        }
        else
            _activeWorldQuests[quest->GetExpansion()][questTeamId][worldQuestTemplate->QuestId]      = new ActiveWorldQuest(questId, rewardId, startTime);


    } while (result->NextRow());
}

void WorldQuestMgr::Update()
{
    for (auto& expansionWorldQuest : _activeWorldQuests)
    {
        for (auto& teamWorldQuest : expansionWorldQuest.second)
        {
            auto& worldQuests = teamWorldQuest.second;

            for (auto itr = worldQuests.begin(); itr != worldQuests.end();)
            {
                if (itr->second->GetRemainingTime() <= 0)
                {
                    DisableQuest(itr->second);
                    itr = teamWorldQuest.second.erase(itr);
                }
                else
                    ++itr;
            }
        }
    }

    for (uint8 expansion : WorldQuestsExpansions)
    {
        for (uint8 teamId : WorldQuestsTeams)
        {
            if (_worldQuestTemplates[expansion][teamId].size())
            {
                int32 questDiff = WORLD_QUEST_MAX_FILL - GetActiveQuestsCount(expansion, teamId) + GetActiveEmissaryQuestsCount(expansion, teamId);

                if (questDiff > 0)
                {
                    std::set<WorldQuestTemplate*> inactiveWorldQuestTemplates;
                    for (auto it : _worldQuestTemplates[expansion][teamId])
                    {
                        if (WorldQuestTemplate* wqTemplate = it.second)
                            if (!IsQuestActive(wqTemplate->QuestId)) // Do not add already active quests
                                if (!wqTemplate->GetQuest()->IsEmissaryQuest()) /// do not add emissay quest as world quest during roll
                                    inactiveWorldQuestTemplates.insert(wqTemplate);
                    }

                    while (questDiff && inactiveWorldQuestTemplates.size())
                    {
                        WorldQuestTemplate* wqTemplate = Trinity::Containers::SelectRandomContainerElement(inactiveWorldQuestTemplates);

                        ActivateQuest(wqTemplate);
                        inactiveWorldQuestTemplates.erase(wqTemplate);
                        --questDiff;
                    }
                }

                RefreshEmissaryQuests();
            }
        }
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

    uint32 questId      = worldQuestTemplate->QuestId;
    uint32 rewardId     = GetRandomRewardForQuestType(quest->GetQuestInfoID());
    uint32 startTime    = time(nullptr);

    uint8 questTeamId = GetQuestTeamId(quest);
    if (questTeamId == TEAM_NEUTRAL)
    {
        _activeWorldQuests[quest->GetExpansion()][TEAM_ALLIANCE][worldQuestTemplate->QuestId]    = new ActiveWorldQuest(questId, rewardId, startTime);
        _activeWorldQuests[quest->GetExpansion()][TEAM_HORDE][worldQuestTemplate->QuestId]       = new ActiveWorldQuest(questId, rewardId, startTime);
    }
    else
        _activeWorldQuests[quest->GetExpansion()][questTeamId][worldQuestTemplate->QuestId]      = new ActiveWorldQuest(questId, rewardId, startTime);

    // We add Emissary Quests to all eligible players
    if (quest->IsEmissaryQuest())
    {
        SessionMap const& smap = sWorld->GetAllSessions();
        for (SessionMap::const_iterator iter = smap.begin(); iter != smap.end(); ++iter)
            if (Player* player = iter->second->GetPlayer())
                if (player->HasWorldQuestEnabled(quest->GetExpansion()))
                    if (player->GetQuestStatus(worldQuestTemplate->QuestId) == QUEST_STATUS_NONE)
                        player->AddQuest(quest, nullptr);
    }

    CharacterDatabasePreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_REP_WORLD_QUEST);
    stmt->setUInt32(0, questId);
    stmt->setUInt32(1, rewardId);
    stmt->setUInt32(2, startTime);
    CharacterDatabase.Execute(stmt);
}

void WorldQuestMgr::DisableQuest(ActiveWorldQuest* activeWorldQuest)
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
            {
                player->GetAchievementMgr()->ResetCriteriaId(CRITERIA_TYPE_COMPLETE_QUEST, 0, criteria->ID);
                player->GetQuestObjectiveCriteriaMgr()->ResetCriteriaTree(criteria->ModifierTreeId);
            }
        }
    }

    for (auto criteria : GetCriteriasForQuest(quest->GetQuestId()))
        CharacterDatabase.PExecute("DELETE FROM character_achievement_progress WHERE criteria = %u", criteria->ID);

    CharacterDatabasePreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_WORLD_QUEST);
    stmt->setUInt32(0, quest->GetQuestId());
    CharacterDatabase.Execute(stmt);
    CharacterDatabase.PExecute("DELETE FROM character_queststatus WHERE quest = %u", quest->GetQuestId());
    CharacterDatabase.PExecute("DELETE FROM character_queststatus_objectives WHERE quest = %u", quest->GetQuestId());
    CharacterDatabase.PExecute("DELETE FROM character_queststatus_rewarded WHERE quest = %u", quest->GetQuestId());

    for (QuestObjective const& objective : quest->GetObjectives())
    {
        CharacterDatabase.PExecute("DELETE FROM character_queststatus_objectives_criteria WHERE questObjectiveId = %u", objective.ID);
        CharacterDatabase.PExecute("DELETE FROM character_queststatus_objectives_criteria_progress WHERE criteriaId = %u", objective.ObjectID);
    }

    delete activeWorldQuest;
}

bool WorldQuestMgr::IsQuestActive(uint32 questId)
{
    return GetActiveWorldQuest(questId) != nullptr;
}

void WorldQuestMgr::RewardQuestForPlayer(Player* player, uint32 questId)
{
    ActiveWorldQuest const* activeWorldQuest = sWorldQuestMgr->GetActiveWorldQuest(questId);
    if (!activeWorldQuest)
        return;

    std::vector<WorldQuestReward const*> worldQuestRewards = sWorldQuestMgr->GetRewardsForPlayerById(player, activeWorldQuest->RewardId);
    for (WorldQuestReward const* worldQuestReward : worldQuestRewards)
    {
        switch (worldQuestReward->RewardType)
        {
            case WORLD_QUEST_REWARD_ITEM:
            {
                ItemPosCountVec dest;
                if (player->CanStoreNewItem(NULL_BAG, NULL_SLOT, dest, worldQuestReward->RewardId, worldQuestReward->RewardCount) == EQUIP_ERR_OK)
                {
                    std::vector<int32> bonusListIDs = sDB2Manager.GetItemBonusTreeVector(worldQuestReward->RewardId, ItemContext(worldQuestReward->RewardContext));
                    Item* item = player->StoreNewItem(dest, worldQuestReward->RewardId, true, GenerateItemRandomBonusListId(worldQuestReward->RewardId), GuidSet(), ItemContext(0), bonusListIDs);
                    player->SendNewItem(item, worldQuestReward->RewardCount, true, false);
                }
                break;
            }
            case WORLD_QUEST_REWARD_CURRENCY:
            {
                player->ModifyCurrency(worldQuestReward->RewardId, worldQuestReward->RewardCount);
                break;
            }
            case WORLD_QUEST_REWARD_GOLD:
            {
                uint64 moneyRew = worldQuestReward->RewardCount * sWorld->getRate(RATE_MONEY_QUEST);
                player->ModifyMoney(moneyRew);

                if (moneyRew > 0)
                    player->UpdateCriteria(CRITERIA_TYPE_MONEY_FROM_QUEST_REWARD, uint32(moneyRew));
                break;
            }
            default:
                break;
        }
    }
}

WorldQuestTemplate* WorldQuestMgr::GetWorldQuestTemplate(uint32 questId)
{
    Quest const* quest = sObjectMgr->GetQuestTemplate(questId);
    if (!quest)
        return nullptr;

    auto expansionTemplates = _worldQuestTemplates.find(quest->GetExpansion());
    if (expansionTemplates == _worldQuestTemplates.end())
        return nullptr;

    uint8 questTeamId = GetQuestTeamId(quest);
    questTeamId = questTeamId == TEAM_NEUTRAL ? TEAM_ALLIANCE : questTeamId;

    auto teamTemplates = expansionTemplates->second.find(questTeamId);
    if (teamTemplates == expansionTemplates->second.end())
        return nullptr;

    auto questTemplate = teamTemplates->second.find(questId);
    if (questTemplate == teamTemplates->second.end())
        return nullptr;

    return questTemplate->second;
}

ActiveWorldQuest* WorldQuestMgr::GetActiveWorldQuest(uint32 questId)
{
    Quest const* quest = sObjectMgr->GetQuestTemplate(questId);
    if (!quest)
        return nullptr;

    auto expansionTemplates = _activeWorldQuests.find(quest->GetExpansion());
    if (expansionTemplates == _activeWorldQuests.end())
        return nullptr;

    uint8 questTeamId = GetQuestTeamId(quest);
    questTeamId = questTeamId == TEAM_NEUTRAL ? TEAM_ALLIANCE : questTeamId;

    auto teamTemplates = expansionTemplates->second.find(questTeamId);
    if (teamTemplates == expansionTemplates->second.end())
        return nullptr;

    auto questTemplate = teamTemplates->second.find(questId);
    if (questTemplate == teamTemplates->second.end())
        return nullptr;

    return questTemplate->second;
}

uint8 WorldQuestMgr::GetActiveEmissaryQuestsCount(uint8 expansion, uint8 teamId)
{
    return std::count_if(_activeWorldQuests[expansion][teamId].begin(), _activeWorldQuests[expansion][teamId].end(), [](auto pair) -> bool
    {
        return pair.second->IsEmissaryQuest();
    });
}

uint32 WorldQuestMgr::GetActiveQuestsCount(uint8 expansion, uint8 teamId)
{
    return _activeWorldQuests[expansion][teamId].size();
}

uint32 WorldQuestMgr::GetRandomRewardForQuestType(uint32 questType)
{
    auto rewardByQuestInfosItr = _worldQuestRewardByQuestInfos.find(questType);
    if (rewardByQuestInfosItr == _worldQuestRewardByQuestInfos.end())
        return 0;

    return Trinity::Containers::SelectRandomContainerElement(rewardByQuestInfosItr->second);
}

std::vector<WorldQuestReward const*> WorldQuestMgr::GetRewardsForPlayerById(Player* player, uint32 rewardId)
{
    std::vector<WorldQuestReward const*> rewards;

    auto rewardsItr = _worldQuestRewards.find(rewardId);
    if (rewardsItr == _worldQuestRewards.end())
        return rewards;

    for (WorldQuestReward const& reward : rewardsItr->second)
    {
        switch (reward.RewardType)
        {
            case WORLD_QUEST_REWARD_ITEM:
            {
                if (ItemTemplate const* proto = sObjectMgr->GetItemTemplate(reward.RewardId))
                    if (proto->IsUsableByLootSpecialization(player, false))
                        rewards.push_back(&reward);
                break;
            }
            default:
                rewards.push_back(&reward);
        }
    }

    return rewards;
}

void WorldQuestMgr::BuildPacket(Player* player, WorldPackets::Quest::WorldQuestUpdate& packet)
{
    WorldPackets::Quest::WorldQuestUpdateInfo quest;
    for (auto expansionWorldQuests : _activeWorldQuests)
    {
        for (auto itr : expansionWorldQuests.second[player->GetTeamId()])
        {
            ActiveWorldQuest* activeWorldQuest = itr.second;
            if (player->IsQuestRewarded(itr.first))
                continue;

            if (WorldQuestTemplate const* worldQuestTemplate = activeWorldQuest->GetTemplate())
            {
                quest.QuestID = activeWorldQuest->QuestId;
                quest.LastUpdate = activeWorldQuest->StartTime;
                quest.VariableID = worldQuestTemplate->VariableId;
                quest.Timer = worldQuestTemplate->Duration;
                quest.Value = worldQuestTemplate->Value;
                packet.WorldQuestUpdates.push_back(quest);
            }
        }
    }
}

void WorldQuestMgr::BuildRewardPacket(Player* player, uint32 questId, WorldPackets::Quest::QueryQuestRewardResponse& packet)
{
    ActiveWorldQuest const* activeWorldQuest = GetActiveWorldQuest(questId);
    if (!activeWorldQuest)
        return;

    std::vector<WorldQuestReward const*> worldQuestRewards = GetRewardsForPlayerById(player, activeWorldQuest->RewardId);
    if (!worldQuestRewards.size())
        return;

    for (WorldQuestReward const* worldQuestReward : worldQuestRewards)
    {
        switch (worldQuestReward->RewardType)
        {
            case WORLD_QUEST_REWARD_ITEM:
            {
                WorldPackets::Quest::QueryQuestRewardResponse::ItemReward itemReward;
                itemReward.Item.ItemID = worldQuestReward->RewardId;
                itemReward.Item.ItemBonus = WorldPackets::Item::ItemBonusInstanceData();
                itemReward.Item.ItemBonus->Context = (ItemContext)worldQuestReward->RewardContext;
                itemReward.Item.ItemBonus->BonusListIDs = sDB2Manager.GetItemBonusTreeVector(worldQuestReward->RewardId, ItemContext(worldQuestReward->RewardContext));
                itemReward.Quantity = worldQuestReward->RewardCount;
                packet.ItemRewards.push_back(itemReward);
                break;
            }
            case WORLD_QUEST_REWARD_CURRENCY:
            {
                WorldPackets::Quest::QueryQuestRewardResponse::CurrencyReward currencyReward;
                currencyReward.CurrencyID = worldQuestReward->RewardId;
                currencyReward.Quantity = worldQuestReward->RewardCount;
                packet.CurrencyRewards.push_back(currencyReward);
                break;
            }
            case WORLD_QUEST_REWARD_GOLD:
            {
                packet.Money = worldQuestReward->RewardCount;
                break;
            }
            default:
                break;
        }
    }
}

void WorldQuestMgr::FillInitWorldStates(WorldPackets::WorldState::InitWorldStates& packet)
{
    for (auto expansionWorldQuests : _activeWorldQuests)
        for (auto teamWorldQuests : expansionWorldQuests.second)
            for (auto itr : teamWorldQuests.second)
                if (WorldQuestTemplate const* worldQuestTemplate = itr.second->GetTemplate())
                    packet.Worldstates.emplace_back(worldQuestTemplate->VariableId, worldQuestTemplate->Value);
}

std::vector<CriteriaEntry const*> WorldQuestMgr::GetCriteriasForQuest(uint32 quest_id)
{
    std::vector<CriteriaEntry const*> gets;
    Quest const* quest = sObjectMgr->GetQuestTemplate(quest_id);
    if (!quest)
        return gets;

    CriteriaList criterias = sCriteriaMgr->GetPlayerCriteriaByType(CRITERIA_TYPE_COMPLETE_QUEST, 0);
    for (Criteria const* criteria : criterias)
        if (criteria->Entry->Asset.QuestID == uint64(quest_id) && criteria->Entry->Flags & 0x20) // guessed for World Quest related stuff
            gets.push_back(criteria->Entry);

    return gets;
}

void WorldQuestMgr::RefreshEmissaryQuests()
{
    for (uint8 expansion : WorldQuestsExpansions)
    {
        for (uint8 teamId : WorldQuestsTeams)
        {
            if (GetActiveEmissaryQuestsCount(expansion, teamId) >= WORLD_QUEST_EMISSARY)
                return;

            if (_emissaryWorldQuestTemplates[expansion][teamId].size() < WORLD_QUEST_EMISSARY)
                return;

            auto it = Trinity::Containers::SelectRandomContainerElement(_emissaryWorldQuestTemplates[expansion][teamId]);
            if (!IsQuestActive(it.first))
                ActivateQuest(it.second);
        }
    }
}

void WorldQuestMgr::AddEmissaryQuestsOnPlayerIfNeeded(Player* player)
{
    for (uint8 expansion : WorldQuestsExpansions)
    {
        if (!player->HasWorldQuestEnabled(expansion))
            continue;

        for (auto itr : _activeWorldQuests[expansion][player->GetTeamId()])
            if (WorldQuestTemplate const* worldQuestTemplate = itr.second->GetTemplate())
                if (Quest const* quest = worldQuestTemplate->GetQuest())
                    if (quest->IsEmissaryQuest())
                        if (player->GetQuestStatus(itr.first) == QUEST_STATUS_NONE)
                            player->AddQuest(quest, nullptr);
    }
}

uint32 WorldQuestMgr::GetTimerForQuest(uint32 questId)
{
    if (ActiveWorldQuest const* wq = GetActiveWorldQuest(questId))
        return wq->GetRemainingTime();

    return 0;
}

TeamId WorldQuestMgr::GetQuestTeamId(Quest const* quest)
{
    if (quest->GetAllowableRaces().RawValue == uint64(-1))
        return TEAM_NEUTRAL;

    if (quest->GetAllowableRaces().RawValue & RACEMASK_ALLIANCE)
        return TEAM_ALLIANCE;

    if (quest->GetAllowableRaces().RawValue & RACEMASK_HORDE)
        return TEAM_HORDE;

    return TEAM_NEUTRAL;
}
