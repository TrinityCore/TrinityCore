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

#ifndef _WORLDQUESTMGR_H
#define _WORLDQUESTMGR_H

#define WORLD_QUEST_MAX_FILL 77
#define WORLD_QUEST_EMISSARY 3

#include "QuestDef.h"
#include "ObjectMgr.h"
#include "World.h"
#include "Player.h"
#include "CriteriaHandler.h"
#include "QuestPackets.h"
#include "WorldStatePackets.h"
#include <unordered_map>
#include <vector>

struct WorldQuestTemplate;
struct ActiveWorldQuest;

typedef std::unordered_map<uint32, WorldQuestTemplate*> WorldQuestTemplateMap;
typedef std::unordered_map<uint32, ActiveWorldQuest*> ActiveWorldQuestMap;

class TC_GAME_API WorldQuestMgr
{
public:
    WorldQuestMgr();
    ~WorldQuestMgr();

    static WorldQuestMgr* instance();

    void LoadWorldQuestTemplates();
    void LoadActiveWorldQuests();
    void Update();

    void ActivateQuest(WorldQuestTemplate* worldQuestTemplate);
    void DisableQuest(ActiveWorldQuest* activeWorldQuest, bool deleteFromMap = true);
    bool IsQuestActive(uint32 questId);

    WorldQuestTemplate* GetWorldQuestTemplate(uint32 questId);

    uint8 GetActiveEmissaryQuestsCount();
    uint32 GetActiveQuestsCount();

    void BuildPacket(Player* player, WorldPackets::Quest::WorldQuestUpdate& packet);
    void FillInitWorldStates(WorldPackets::WorldState::InitWorldStates& packet);

    std::vector<CriteriaEntry const*> GetCriteriasForQuest(uint32 quest_id);

    void RefreshEmissaryQuests();
    void AddEmissaryQuestsOnPlayerIfNeeded(Player* player);

    uint32 GetTimerForQuest(uint32 questId);

private:
    WorldQuestTemplateMap _worldQuestTemplates;
    WorldQuestTemplateMap _emissaryWorldQuestTemplates;

    ActiveWorldQuestMap _activeWorldQuests;
};

#define sWorldQuestMgr WorldQuestMgr::instance()

struct WorldQuestTemplate
{
    WorldQuestTemplate(uint32 questId, uint32 duration, uint32 variableId, uint8 value) :
        QuestId(questId), Duration(duration), VariableId(variableId), Value(value) { }

    uint32 QuestId;
    uint32 Duration;
    uint32 VariableId;
    uint8 Value;

    Quest const* GetQuest() const { return sObjectMgr->GetQuestTemplate(QuestId); }
};

struct ActiveWorldQuest
{
    ActiveWorldQuest(uint32 questId, int32 startTime) :
        QuestId(questId), StartTime(startTime) { }

    uint32 QuestId;
    int32 StartTime;

    WorldQuestTemplate const* GetTemplate() const { return sWorldQuestMgr->GetWorldQuestTemplate(QuestId); }

    int32 GetRemainingTime() const
    {
        if (WorldQuestTemplate const* worldQuestTemplate = GetTemplate())
            return (StartTime + worldQuestTemplate->Duration) - time(nullptr);

        return 0;
    }

    bool IsEmissaryQuest() const
    {
        if (WorldQuestTemplate const* worldQuestTemplate = GetTemplate())
            if (Quest const* quest = worldQuestTemplate->GetQuest())
                return quest->IsEmissaryQuest();

        return false;
    }
};

#endif
