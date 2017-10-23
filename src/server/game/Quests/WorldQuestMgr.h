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

struct WorldQuestTemplate
{
    WorldQuestTemplate(Quest* _quest, uint32 _duration, uint32 _variableID, uint8 _value, int32 _remaining = 0) :
        quest(_quest), duration(_duration), remaining(_remaining), starttimer(0), variableID(_variableID), value(_value), active(false) { }

    Quest* quest;
    uint32 duration;
    int32 remaining;
    int32 starttimer;
    uint32 variableID;
    uint8 value;
    bool active;
};

typedef std::unordered_map<uint32, WorldQuestTemplate*> WorldQuestMap;

class TC_GAME_API WorldQuestMgr
{
public:
    WorldQuestMgr();
    ~WorldQuestMgr();

    static WorldQuestMgr* instance();

    void LoadWorldQuests();
    void AddQuest(Field* fields);
    void LoadQuestsStatus();
    void Update(uint32 diff);
    void DisableQuest(WorldQuestTemplate* quest);
    void ActivateQuest(WorldQuestTemplate* quest, bool create = false);
    WorldQuestTemplate* GetQuest(uint32 quest_id);
    uint8 GetActiveEmissaryQuestsCount();
    uint32 GetActiveQuestsCount();
    void BuildPacket(WorldPackets::Quest::WorldQuestUpdate& packet);
    void FillInitWorldStates(WorldPackets::WorldState::InitWorldStates& packet);
    std::vector<CriteriaEntry const*> GetCriteriasForQuest(uint32 quest_id);
    void RefreshEmissaryQuests();
    void AddEmissaryQuestOnPlayerIfNeeded(Player* player);
    uint32 GetTimerForQuest(uint32 quest_id);

private:
    WorldQuestMap _worldQuestTemplates;
    WorldQuestMap _emissaryQuests;
    std::vector<Quest*> _activeEmissaryQuests;
};

#define sWorldQuestMgr WorldQuestMgr::instance()

#endif
