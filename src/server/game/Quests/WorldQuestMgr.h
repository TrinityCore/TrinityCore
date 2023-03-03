///*
// * Copyright (C) 2020 
// *
// * This program is free software; you can redistribute it and/or modify it
// * under the terms of the GNU General Public License as published by the
// * Free Software Foundation; either version 2 of the License, or (at your
// * option) any later version.
// *
// * This program is distributed in the hope that it will be useful, but WITHOUT
// * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
// * FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
// * more details.
// *
// * You should have received a copy of the GNU General Public License along
// * with this program. If not, see <http://www.gnu.org/licenses/>.
// */
//
//#ifndef _WORLDQUESTMGR_H
//#define _WORLDQUESTMGR_H
//
//#define WORLD_QUEST_MAX_FILL 77
//#define WORLD_QUEST_EMISSARY 4
//
//#include "QuestDef.h"
//#include "ObjectMgr.h"
//#include "World.h"
//#include "Player.h"
//#include "CriteriaHandler.h"
//#include "QuestPackets.h"
//#include "WorldStatePackets.h"
//#include <unordered_map>
//#include <vector>
//
//struct WorldQuestTemplate;
//struct ActiveWorldQuest;
//struct WorldQuestReward;
//
////typedef std::unordered_map<uint8 /*expansion*/, std::unordered_map<uint8 /*teamId*/, std::unordered_map<uint32 /*questId*/, WorldQuestTemplate*>>> WorldQuestTemplateMap;
//typedef std::unordered_map<uint8 /*expansion*/, std::unordered_map<uint8 /*teamId*/, std::unordered_map<uint32 /*questId*/, ActiveWorldQuest*>>> ActiveWorldQuestMap;
//
//typedef std::unordered_map<uint32 /*RewardId*/, std::vector<WorldQuestReward>> WorldQuestRewardMap;
//typedef std::unordered_map<uint32 /*QuestInfo*/, std::vector<uint32 /*RewardId*/>> WorldQuestRewardByQuestInfoMap;
//
//enum WorldQuestRewardType
//{
//    WORLD_QUEST_REWARD_ITEM     = 0,
//    WORLD_QUEST_REWARD_CURRENCY = 1,
//    WORLD_QUEST_REWARD_GOLD     = 2,
//};
//
//class TC_GAME_API WorldQuestMgr
//{
//public:
//    WorldQuestMgr();
//    ~WorldQuestMgr();
//
//    static WorldQuestMgr* instance();
//    const std::vector<uint8> WorldQuestsExpansions = { EXPANSION_LEGION, EXPANSION_BATTLE_FOR_AZEROTH };
//    const std::vector<uint8> WorldQuestsTeams = { TEAM_ALLIANCE, TEAM_HORDE };
//
//    void LoadWorldQuestTemplates();
//    void LoadWorldQuestRewardTemplates();
//    void AddWorldQuestTemplate(Quest const* quest, WorldQuestTemplate* worldQuestTemplate);
//    void LoadActiveWorldQuests();
//    void Update();
//
//    void CleanWorldQuestTemplates();
//
//    void ActivateQuest(WorldQuestTemplate* worldQuestTemplate);
//    void DisableQuest(ActiveWorldQuest* activeWorldQuest);
//
//    bool IsQuestActive(uint32 questId);
//
//    void RewardQuestForPlayer(Player* player, uint32 questId);
//
//    WorldQuestTemplate* GetWorldQuestTemplate(uint32 questId);
//    ActiveWorldQuest* GetActiveWorldQuest(uint32 questId);
//
//    uint8 GetActiveEmissaryQuestsCount(uint8 expansion, uint8 teamId);
//    uint32 GetActiveQuestsCount(uint8 expansion, uint8 teamId);
//
//    uint32 GetRandomRewardForQuestType(uint32 questType);
//    std::vector<WorldQuestReward const*> GetRewardsForPlayerById(Player* player, uint32 rewardId);
//
//    void BuildPacket(Player* player, WorldPackets::Quest::WorldQuestUpdateResponse& packet);
//    void BuildRewardPacket(Player* player, uint32 questId, WorldPackets::Quest::QueryQuestRewardResponse& packet);
//    void FillInitWorldStates(WorldPackets::WorldState::InitWorldStates& packet);
//
//    std::vector<CriteriaEntry const*> GetCriteriasForQuest(uint32 quest_id);
//
//    void RefreshEmissaryQuests();
//    void AddEmissaryQuestsOnPlayerIfNeeded(Player* player);
//
//    uint32 GetTimerForQuest(uint32 questId);
//    TeamId GetQuestTeamId(Quest const* quest);
//
//private:
//   // WorldQuestTemplateMap _worldQuestTemplates;
//   // WorldQuestTemplateMap _emissaryWorldQuestTemplates;
//
//    WorldQuestRewardMap _worldQuestRewards;
//    WorldQuestRewardByQuestInfoMap _worldQuestRewardByQuestInfos;
//
//    ActiveWorldQuestMap _activeWorldQuests;
//};
//
//#define sWorldQuestMgr WorldQuestMgr::instance()
//
///*struct WorldQuestTemplate
//{
//    WorldQuestTemplate(uint32 questId, uint32 duration, uint32 variableId, uint8 value) :
//        QuestId(questId), Duration(duration), VariableId(variableId), Value(value) { }
//
//    uint32 QuestId;
//    uint32 Duration;
//    uint32 VariableId;
//    uint8 Value;
//
//    Quest const* GetQuest() const { return sObjectMgr->GetQuestTemplate(QuestId); }
//};*/
//
//struct WorldQuestReward
//{
//    WorldQuestReward(uint32 id, uint8 questType, uint8 rewardType, uint32 rewardId, uint32 rewardCount, uint32 rewardContext) :
//        Id(id), QuestType(questType), RewardType(rewardType), RewardId(rewardId), RewardCount(rewardCount), RewardContext(rewardContext) { }
//
//    uint32 Id;
//    uint8 QuestType;
//    uint8 RewardType;
//    uint32 RewardId;
//    uint32 RewardCount;
//    uint32 RewardContext;
//};
//
//struct ActiveWorldQuest
//{
//    ActiveWorldQuest(uint32 questId, uint32 rewardId, int32 startTime) :
//        QuestId(questId), RewardId(rewardId), StartTime(startTime) { }
//
//    uint32 QuestId;
//    uint32 RewardId;
//    int32 StartTime;
//
//    WorldQuestTemplate const* GetTemplate() const { return sWorldQuestMgr->GetWorldQuestTemplate(QuestId); }
//
//    int32 GetRemainingTime() const
//    {
//        if (WorldQuestTemplate const* worldQuestTemplate = GetTemplate())
////            return (StartTime + worldQuestTemplate->Duration) - time(nullptr);
//
//        return 0;
//    }
//
//    bool IsEmissaryQuest() const
//    {
//        if (WorldQuestTemplate const* worldQuestTemplate = GetTemplate())
////            if (Quest const* quest = worldQuestTemplate->GetQuest())
//               // return quest->IsEmissaryQuest();
//
//        return false;
//    }
//};
//
//#endif
