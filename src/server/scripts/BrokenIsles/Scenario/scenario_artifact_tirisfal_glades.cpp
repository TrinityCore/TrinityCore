/*
 * Copyright (C) 2022 BfaCore Reforged
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

 /*scenario_artifact_tirisfal_glades*/
#include "Log.h"
#include "Scenario.h"
#include "GameObject.h"
#include "InstanceScenario.h"
#include "PhasingHandler.h"
#include "SceneMgr.h"
#include "ScriptMgr.h"

enum DataTypes
{
    DATA_ARTIFACT_TIRISFAL_GLADES = 0,
    DATA_STAGE_1 = 1,
    DATA_STAGE_2 = 2,
    DATA_STAGE_3 = 3,
    DATA_STAGE_4 = 4,
    DATA_STAGE_5 = 5,
    DATA_STAGE_6 = 6,
    DATA_STAGE_7 = 7,
    DATA_MAX_ENCOUNTERS = 8,

    ///paladin DATA_STAGE_7
    ///paladin area 7797
    SCENARIO_ID_PALADIN = 775, ///DATA_STAGE_7
    PHASE_PALADIN = 5171,

    //SCENARIO_ID_WARRIOR = 961, ///DATA_STAGE_5
    PHASE_WARRIOR = 6815,
    QUEST__RETURN_TO_THE_BROKEN_SHORE = 38904,
    DATA_STEP_1 = 1939,
    DATA_STEP_2 = 2327,
    DATA_STEP_3 = 2030,
    DATA_STEP_4 = 2033,
    DATA_STEP_5 = 2034,
    DATA_STEP_6 = 2035,
    DATA_STEP_7 = 2040,
    DATA_STEP_8 = 2041,

    EVENT_STEP_1 = 1,
    EVENT_STEP_2 = 2,
    EVENT_STEP_3 = 3,
    EVENT_STEP_4 = 4,
    EVENT_STEP_5 = 5,
    EVENT_STEP_6 = 6,
    EVENT_STEP_7 = 7,
    EVENT_STEP_8 = 8,

    SPELL_SCENE_MALGALOR_ARRIVES = 197593, ///warrior SceneID: 1144     PlaybackFlags : 25    SceneInstanceID : 1    SceneScriptPackageID : 1515
};

struct scenario_artifact_tirisfal_glades : public InstanceScript
{
    scenario_artifact_tirisfal_glades(InstanceMap* map) : InstanceScript(map) { }

    void Initialize() override
    {
        SetBossNumber(DATA_MAX_ENCOUNTERS);
        events.ScheduleEvent(DATA_STEP_1, 3s);
        SetData(DATA_ARTIFACT_TIRISFAL_GLADES, NOT_STARTED);
        ///default in paradin
        ClassMode = DATA_STAGE_7;
        for (uint8 i = 1; i < ClassMode; ++i)
            SetData(i, NOT_STARTED);
        isIntr = false;
        needKillCount = 0;
        KillCount = 0;
        StepID = DATA_STAGE_1;
        isComplete = false;
    }

    void OnPlayerAreaUpdate(Player* player, uint32 newAreaId, uint32 /*oldAreaId*/)
    {
        
        if (newAreaId == 7796 && player->HasQuest(QUEST__RETURN_TO_THE_BROKEN_SHORE) && player->getClass() == CLASS_WARRIOR)
        {
            PhasingHandler::AddPhase(player, PHASE_WARRIOR);
            ClassMode = DATA_STAGE_5;
            //conversation
           // SendScenarioState(ScenarioData(SCENARIO_ID_WARRIOR, DATA_STEP_1));
            ///SMSG_SET_DUNGEON_DIFFICULTY 12
        }
        ///.go -2421.58 144.59 7.7694 1500
        if (newAreaId == 7797 && player->getClass() == CLASS_PALADIN)
        {
            PhasingHandler::AddPhase(player, PHASE_PALADIN);
            ClassMode = DATA_STAGE_7;
            //conversation
            ///SendScenarioState(ScenarioData(SCENARIO_ID_PALADIN, DATA_STEP_1));
            ///SMSG_SET_DUNGEON_DIFFICULTY 12
        }
        
    }

    void NextStep()
    {
        if (StepID < ClassMode)
        {
            ++StepID;
            if (Scenario* scenario = instance->GetInstanceScenario())
                scenario->CompleteCurrStep();
        }
        else if (StepID == ClassMode)
        {
            if (!isComplete)
                if (Scenario* scenario = instance->GetInstanceScenario())
                    scenario->CompleteCurrStep();

            ///COMPLETE SCENARIO
            if (Scenario* scenario = instance->GetInstanceScenario())
                scenario->CompleteScenario();
        }
    }

private:
    EventMap events;
    bool isIntr;
    ObjectGuid GUID_SKYLORD_SHADEGROVE;
    ObjectGuid GUID_CYLINDER_COLLISION;
    std::set<ObjectGuid> m_guardMobs;
    std::set<ObjectGuid> m_targetMobs;
    uint32 needKillCount;
    uint32 KillCount;
    uint8 StepID;
    uint8 ClassMode;
    bool isComplete;
};


void AddSC_scenario_artifact_tirisfal_glades()
{
    RegisterInstanceScript(scenario_artifact_tirisfal_glades, 1539);

}
