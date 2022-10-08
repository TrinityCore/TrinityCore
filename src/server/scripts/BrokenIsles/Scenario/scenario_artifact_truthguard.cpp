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

#include "PhasingHandler.h"
#include "ScriptedGossip.h"
#include "InstanceScenario.h"
#include "GameObject.h"
#include "InstanceScript.h"
#include "Scenario.h"
#include "SceneMgr.h"
#include "Log.h"
#include "Player.h"
#include "Creature.h"
#include "Spell.h"

enum
{
    DATA_Stormheim     = 0,
    DATA_STAGE_1 = 1,
    DATA_STAGE_2 = 2,
    DATA_STAGE_3 = 3,
    DATA_STAGE_4 = 4,
    DATA_STAGE_5 = 5,
    DATA_STAGE_6 = 6,
    DATA_MAX_ENCOUNTERS = 7,
    NORMAL_PHASE = 169,
};

enum CriteriaTrees
{
    //CLASS_PALADIN
    CRITERIA_TREE_YOU_VE_ARRIVED_AT_SHIELD_S_REST_MEET_UP_WITH_ORIK_AND_PREPARE_TO_ENTER_THE_TOMB = 47433,
    CRITERIA_TREE_INSIDE_THE_TOMB_LIES_THE_SHRINE_OF_THE_TRUTHGUARD_OVERCOME_ANY_DEFENSES_AND_FIND_THE_SHRINE = 47435,
    CRITERIA_TREE_THE_DOOR_TO_THE_SHRINE_IS_THE_FIRST_TRIAL_SURVIVE_ITS_TEST = 47505,
    CRITERIA_TREE_THE_WAY_IS_OPEN_AND_THE_SHRINE_AWAITS_THE_SHIELD_IS_BELOW_SOMEWHERE_FIND_IT = 47521,
    CRITERIA_TREE_YRGRIM_WIELDER_OF_THE_TRUTHGUARD_HAS_CHALLENGED_YOU_TO_A_TRIAL_BY_COMBAT_COMPLETE_THE_TRIAL_TO_EARN_HIS_RESPECT = 47523,
    CRITERIA_TREE_THE_TRIAL_IS_OVER_TAKE_UP_THE_TRUTHGUARD = 47525,
    //CLASS_HUNTER
    CRITERIA_TREE_SPEAK_WITH_GRIF_AND_MEET_HIS_VRYKUL_GUIDE_PRUSTAGA = 47167,
    CRITERIA_TREE_FIND_THE_ENTRANCE_TO_THE_TOMB_OF_WARLORD_VOLUND_INSIDE_THE_TOMB_OF_ANCIENT_KINGS = 47215,
    CRITERIA_TREE_ASSIST_PRUSTAGA_IN_OPENING_THE_DOOR_TO_VOLUND_S_TOMB = 47217,
    CRITERIA_TREE_SCOUR_VOLUND_S_HOARD_FOR_A_SIGN_OF_TITANSTRIKE = 47178,
    CRITERIA_TREE_WARLORD_VOLUND_SEEKS_TO_STOP_YOU_FROM_CLAIMING_TITANSTRIKE = 47556,
    CRITERIA_TREE_USE_THE_TELEPORTATION_PAD_TO_JOIN_MIMIRON_IN_ULDUAR = 47558,
    //CLASS_WARRIOR
    CRITERIA_TREE_FIND_MAGNAR_S_TOMB_WITH_HRUTHNIR = 45335,
    CRITERIA_TREE_DEFEAT_THE_LEGION_FORCES = 45337,
    CRITERIA_TREE_FIND_MAGNAR_S_RESTING_PLACE_WITHIN_THE_TOMB = 44568,
    CRITERIA_TREE_DEFEND_HRUTHNIR_FROM_MAGNAR_S_FORCES = 44570,
    CRITERIA_TREE_DEFEAT_MAGNAR_ICEBREAKER = 45762,
    CRITERIA_TREE_THE_SWORD_AND_SHIELD_ARE_YOURS_CLAIM_THEM = 44572,
};

enum
{
    ScenarioID = 1108,
};

struct scenario_paladin_truthguard : public InstanceScript
{
    scenario_paladin_truthguard(InstanceMap* map) : InstanceScript(map) {  }

    void Initialize() override
    {
        SetBossNumber(DATA_MAX_ENCOUNTERS);
        SetData(DATA_Stormheim, NOT_STARTED);
        for (uint8 i = 1; i < 6; ++i)
            SetData(i, NOT_STARTED);
        StepID = DATA_STAGE_1;
        isComplete = false;
        FirstCount = 0;
        m_playerGUID = ObjectGuid::Empty;
    }

    void OnPlayerEnter(Player* player) override
    {
        InstanceScript::OnPlayerEnter(player);
        if (player->GetMapId() == 1495)
        {
            m_playerGUID = player->GetGUID();
            PhasingHandler::AddPhase(player, NORMAL_PHASE, true);
        }
    }

    void OnCreatureCreate(Creature* creature) override
    {

    }

    void OnGameObjectCreate(GameObject* go) override
    {

    }

    void NextStep()
    {
        TC_LOG_ERROR("server.worldserver", " === scenario_paladin_truthguard  NextStep  %u === ", StepID);
        if (StepID < DATA_STAGE_6)
        {
            ++StepID;
            if (Scenario* scenario = instance->GetInstanceScenario())
                scenario->CompleteCurrStep();
        }
        else if (StepID == DATA_STAGE_6)
        {
            if (!isComplete)
                if (Scenario* scenario = instance->GetInstanceScenario())
                    scenario->CompleteCurrStep();

            // COMPLETE SCENARIO
            if (Scenario* scenario = instance->GetInstanceScenario())
                scenario->CompleteScenario();
        }
    }

    void SetData(uint32 type, uint32 data) override
    {
        InstanceScript::SetData(type, data);
        if (data == NOT_STARTED)
            return;

        if (type == DATA_STAGE_1 && data == DONE)
        {
            NextStep();
        }
        else if (type == DATA_STAGE_2 && data == DONE)
        {
            NextStep();
        }
        else if (type == DATA_STAGE_3 && data == DONE)
        {
            NextStep();
        }
        else if (type == DATA_STAGE_4 && data == DONE)
        {
            NextStep();
        }
        else if (type == DATA_STAGE_5 && data == DONE)
        {
            NextStep();
        }
        else if (type == DATA_STAGE_6 && data == DONE)
        {
            NextStep();
            DoPlayScenePackageIdOnPlayers(1259);
        }
    }

private:
    uint8 StepID;
    bool isComplete;
    ObjectGuid m_playerGUID;
    uint8 FirstCount;
};

struct npc_orik_trueheart_105910 : public ScriptedAI
{
    npc_orik_trueheart_105910(Creature* creature) : ScriptedAI(creature) { instance = creature->GetInstanceScript(); }

    void MoveInLineOfSight(Unit* who) override
    {
        if (Player* player = who->ToPlayer())
        {
            if (who->IsWithinDist(player, 15.0f, false))
            {
                if (instance->GetData(DATA_STAGE_1) == NOT_STARTED)
                {
                    IsLock = true;
                    Talk(0);
                    me->GetScheduler().Schedule(Milliseconds(6000), [player, this](TaskContext context)
                    {
                        if (Creature* kato = me->FindNearestCreature(105694, 25.0f, true))
                            kato->AI()->Talk(0);
                    });
                    me->GetScheduler().Schedule(Milliseconds(12000), [this](TaskContext context)
                    {
                        Talk(1);
                    });
                    me->GetScheduler().Schedule(Milliseconds(18000), [player, this](TaskContext context)
                    {
                        Talk(2, player);
                        if (instance->GetData(DATA_STAGE_1) == NOT_STARTED)
                            instance->SetData(DATA_STAGE_1, DONE);
                        me->GetMotionMaster()->MoveFollow(player, PET_FOLLOW_DIST, me->GetFollowAngle());
                        if (Creature* kato = me->FindNearestCreature(105694, 25.0f, true))
                            kato->GetMotionMaster()->MoveFollow(player, PET_FOLLOW_DIST, kato->GetFollowAngle());
                    });
                }
            }
        }
    }
private:
    InstanceScript* instance;
};

class go_truthguard_249420 : public GameObjectScript
{
public:
    go_truthguard_249420() : GameObjectScript("go_truthguard") { isloot = false; }

    void OnLootStateChanged(GameObject* go, uint32 state, Unit* unit)
    {
        if (state == GO_ACTIVATED && unit && !isloot)
        {
            isloot = true;
            if(Player* player= unit->ToPlayer())
                if(!player->GetQuestObjectiveData(42017,1))
                    player->KilledMonsterCredit(105891);

            if (InstanceScript * instance = go->GetInstanceScript())
                instance->SetData(DATA_STAGE_6, DONE);
        }
    }
    bool isloot;
};

//spell summon 209953
//spell npc105968 210976
//spell 204224
void AddSC_scenario_artifact_truthguard()
{
    RegisterInstanceScript(scenario_paladin_truthguard, 1495);
    RegisterCreatureAI(npc_orik_trueheart_105910);
    new go_truthguard_249420();
}
