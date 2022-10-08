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

#include "Log.h"
#include "Scenario.h"
#include "GameObject.h"
#include "InstanceScenario.h"
#include "PhasingHandler.h"
#include "SceneMgr.h"
#include "ScriptMgr.h"
#include "ObjectMgr.h"

enum DataTypes
{
    DATA_CLAWS_OF_URSOC = 0,
    DATA_MAX_ENCOUNTERS = 1,

    SCENARIO_ID = 990,
    DATA_STEP_1 = 2029,
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



    NPC_MYLUNE_101393 = 101393,
    NPC_SHADE_OF_XAVIUS_101403 = 101403,
    NPC_LEA_STONEPAW_101742 = 101742,
    NPC_VERDANT_WARDER_101754 = 101754,
    NPC_LEA_STONEPAW_101743 = 101743,
    ///On door
    NPC_LEA_STONEPAW_105243 = 105243,
    NPC_CLAWS_OF_URSOC_105331 = 105331,

    NPC_SPIRIT_OF_URSOC_101362 = 101362,
    NPC_BLIGHTBORN_SLUDGE_101384 = 101384,
    NPC_ROTHOOF_DEFILER_101386 = 101386,
    NPC_ROTHOOF_SHADOWSTALKER_101388 = 101388,
    NPC_CORRUPTED_DEFENDER_101389 = 101389,
    NPC_ARCH_DESECRATOR_MALITHAR_101390 = 101390,
    NPC_ROTHOOF_SHADOWSTALKER_105294 = 105294,


    QUEST_WHEN_DREAMS_BECOME_NIGHTMARES = 40647,
    SCENE_PLAYER_ENTER = 1177,
    GO_CYLINDER_COLLISION = 248827,
    DRUID_GUARDIA_ACQUISTION_ARTIFACT_LOOTED_SCENE = 1605,
    //DoPlayScenePackageIdOnPlayers(DRUID_GUARDIA_ACQUISTION_ARTIFACT_LOOTED_SCENE);
    TEST_EVENT = 9999,
};

struct SpawnData
{
    uint32 event, npcId;
    float X;
    float Y;
    float Z;
    float orientation;
};

SpawnData const spawnData[] =
{
    { EVENT_STEP_1, NPC_ROTHOOF_SHADOWSTALKER_101388, -12224.7998f, -13092.7f,      326.7f,     5.703f },
    { EVENT_STEP_1, NPC_ROTHOOF_SHADOWSTALKER_101388, -12214.0f,    -13129.0f,      326.56f,    0.872626f },
    { EVENT_STEP_1, NPC_ROTHOOF_SHADOWSTALKER_105294, -12192.0f,    -13090.7998f,   328.359f,   0.366053f },

    { EVENT_STEP_2, NPC_BLIGHTBORN_SLUDGE_101384, -12210.0f, -13080.7f,     327.475f, 5.1437f },
    { EVENT_STEP_2, NPC_BLIGHTBORN_SLUDGE_101384, -12193.2f, -13096.2998f,  329.333f, 6.0219f },
    { EVENT_STEP_2, NPC_BLIGHTBORN_SLUDGE_101384, -12205.6f, -13093.0996f,  327.139f, 0.2357f },
    { EVENT_STEP_2, NPC_BLIGHTBORN_SLUDGE_101384, -12216.2f, -13094.5996f,  326.5f,   5.537f },
    { EVENT_STEP_2, NPC_BLIGHTBORN_SLUDGE_101384, -12203.3f, -13108.5f,     329.29f,  5.9529f },
    { EVENT_STEP_2, NPC_BLIGHTBORN_SLUDGE_101384, -12210.3f, -13112.7998f,  329.29f, 5.9529f },
    { EVENT_STEP_2, NPC_BLIGHTBORN_SLUDGE_101384, -12223.6f, -13117.9f,     325.881f, 0.3889f },
    { EVENT_STEP_2, NPC_BLIGHTBORN_SLUDGE_101384, -12194.4f, -13119.5f,     329.29f,  5.9529f },
    { EVENT_STEP_2, NPC_BLIGHTBORN_SLUDGE_101384, -12204.0f, -13121.7998f,  335.329f, 0.2151f },
    { EVENT_STEP_2, NPC_BLIGHTBORN_SLUDGE_101384, -12213.5f, -13124.2f,     329.454f, 0.6245f },
    { EVENT_STEP_2, NPC_BLIGHTBORN_SLUDGE_101384, -12201.0f, -13127.9f,     329.29f, 6.158f },
    { EVENT_STEP_2, NPC_BLIGHTBORN_SLUDGE_101384, -12213.5f, -13132.7f,     329.29f, 6.158f },
    { EVENT_STEP_2, NPC_BLIGHTBORN_SLUDGE_101384, -12203.9f, -13140.9f,     329.29f, 6.158f },
    { EVENT_STEP_2, NPC_ROTHOOF_SHADOWSTALKER_101388,   -12192.0f,    -13090.7998f,   328.359f,   0.366053f },

    { EVENT_STEP_3, NPC_ROTHOOF_DEFILER_101386, -12192.0f,    -13090.7998f,   328.359f,   0.366053f },
    { EVENT_STEP_3, NPC_ROTHOOF_DEFILER_101386, -12229.3f,    -13093.3f,      326.814f,   6.1183f },
    { EVENT_STEP_3, NPC_ROTHOOF_DEFILER_101386, -12245.2f,    -13102.7f,      329.265f,   0.0f },
    { EVENT_STEP_3, NPC_ROTHOOF_DEFILER_101386, -12230.0f,    -13123.3f,      325.96f,    0.3465f },
    { EVENT_STEP_3, NPC_ROTHOOF_SHADOWSTALKER_105294, -12192.0f,    -13090.7998f,   328.359f,   0.366053f },
    { EVENT_STEP_3, NPC_ROTHOOF_SHADOWSTALKER_101388, -12224.7998f, -13092.7f,      326.7f,     5.703f },

    { EVENT_STEP_4, NPC_BLIGHTBORN_SLUDGE_101384, -12210.0f, -13080.7f,     327.475f, 5.1437f },
    { EVENT_STEP_4, NPC_BLIGHTBORN_SLUDGE_101384, -12193.2f, -13096.2998f,  329.333f, 6.0219f },
    { EVENT_STEP_4, NPC_BLIGHTBORN_SLUDGE_101384, -12205.6f, -13093.0996f,  327.139f, 0.2357f },
    { EVENT_STEP_4, NPC_BLIGHTBORN_SLUDGE_101384, -12216.2f, -13094.5996f,  326.5f,   5.537f },
    { EVENT_STEP_4, NPC_BLIGHTBORN_SLUDGE_101384, -12203.3f, -13108.5f,     329.29f,  5.9529f },
    { EVENT_STEP_4, NPC_BLIGHTBORN_SLUDGE_101384, -12210.3f, -13112.7998f,  329.29f, 5.9529f },
    { EVENT_STEP_4, NPC_BLIGHTBORN_SLUDGE_101384, -12223.6f, -13117.9f,     325.881f, 0.3889f },
    { EVENT_STEP_4, NPC_BLIGHTBORN_SLUDGE_101384, -12194.4f, -13119.5f,     329.29f,  5.9529f },
    { EVENT_STEP_4, NPC_BLIGHTBORN_SLUDGE_101384, -12204.0f, -13121.7998f,  335.329f, 0.2151f },
    { EVENT_STEP_4, NPC_BLIGHTBORN_SLUDGE_101384, -12213.5f, -13124.2f,     329.454f, 0.6245f },
    ///{ EVENT_STEP_4, NPC_BLIGHTBORN_SLUDGE_101384, -12201.0f, -13127.9f,     329.29f, 6.158f },
    ///{ EVENT_STEP_4, NPC_BLIGHTBORN_SLUDGE_101384, -12213.5f, -13132.7f,     329.29f, 6.158f },
    ///{ EVENT_STEP_4, NPC_BLIGHTBORN_SLUDGE_101384, -12203.9f, -13140.9f,     329.29f, 6.158f },
    { EVENT_STEP_4, NPC_CORRUPTED_DEFENDER_101389, -12229.3f, -13093.3f, 326.814f, 6.1184f },

    { EVENT_STEP_5, NPC_CORRUPTED_DEFENDER_101389, -12229.3f, -13093.3f, 326.814f, 6.1184f },
    { EVENT_STEP_5, NPC_CORRUPTED_DEFENDER_101389, -12194.7f, -13140.3f, 328.84f,  1.681f },

    { EVENT_STEP_6, NPC_ARCH_DESECRATOR_MALITHAR_101390, -12219.9f, -13106.9f, 326.054f, 0.336f },
    { EVENT_STEP_6, NPC_SHADE_OF_XAVIUS_101403,          -12215.6f, -13097.5f, 326.383f, 0.352f },
};


struct scenario_artifact_ursocslair : public InstanceScript
{
    scenario_artifact_ursocslair(InstanceMap* map) : InstanceScript(map) { }

    void Initialize() override
    {
        SetBossNumber(DATA_MAX_ENCOUNTERS);
        //events.ScheduleEvent(DATA_STEP_1, 3s);
        SetData(DATA_CLAWS_OF_URSOC, NOT_STARTED);
        isIntr = false;
        needKillCount = 0;
        KillCount = 0;
        StepID = EVENT_STEP_1;
        isComplete = false;
    }

    uint32 GetStepID()
    {
        switch (StepID)
        {
        case EVENT_STEP_1:
            return DATA_STEP_1;
            break;
        case EVENT_STEP_2:
            return DATA_STEP_2;
            break;
        case EVENT_STEP_3:
            return DATA_STEP_3;
            break;
        case EVENT_STEP_4:
            return DATA_STEP_4;
            break;
        case EVENT_STEP_5:
            return DATA_STEP_5;
            break;
        case EVENT_STEP_6:
            return DATA_STEP_6;
            break;
        case EVENT_STEP_7:
            return DATA_STEP_7;
            break;
        case EVENT_STEP_8:
            return DATA_STEP_8;
            break;
        default:
            break;
        }
    }

    void LoadNPC(uint32 event, const SpawnData* data)
    {
        while (data->event)
        {
            if (data->event == event)
            {
                    if (TempSummon* personalCreature = instance->SummonCreature(data->npcId, Position(data->X,data->Y,data->Z,data->orientation), NULL, 600000, 0, true))
                    {
                        m_targetMobs.insert(personalCreature->GetGUID());
                    }
            }
            ++data;
        }
        //KillCount = 0;
        needKillCount = m_targetMobs.size();
        TC_LOG_ERROR("server.worldserver", "LoadNPC needKillCount = %u;KillCount = %u;", needKillCount, KillCount);
    }

    void OnCreatureRemove(Creature* creature) override
    {
        m_targetMobs.erase(creature->GetGUID());
        ++KillCount;
    }

    void OnGameObjectCreate(GameObject* go) override
    {
        if (go->GetEntry() == GO_CYLINDER_COLLISION)
            GUID_CYLINDER_COLLISION = go->GetGUID();
    }

    void NextStep()
    {

        TC_LOG_ERROR("server.worldserver", "====================scenario_artifact_ursocslair  NextStep  %u====================== ", StepID);
        if (StepID < EVENT_STEP_8)
        {
            ++StepID;
            if(Scenario* scenario=instance->GetInstanceScenario())
                scenario->CompleteCurrStep();

            //SendScenarioState(ScenarioData(SCENARIO_ID, GetStepID()));
        }
        else if(StepID == EVENT_STEP_8)
        {
            if(!isComplete)
                if (Scenario* scenario = instance->GetInstanceScenario())
                    scenario->CompleteCurrStep();
               // SendScenarioState(ScenarioData(SCENARIO_ID, GetStepID()));
            if (GameObject* go =instance->GetGameObject(GUID_CYLINDER_COLLISION))
            {
                TC_LOG_ERROR("server.worldserver", "====================scenario_artifact_ursocslair  TEST_EVENT GO_CYLINDER_COLLISION====================== ");
                //go->GetPhaseShift().AddPhase(170, PhaseFlags::None, nullptr);
                go->DestroyForNearbyPlayers();
            }
            ///COMPLETE SCENARIO
            if (Scenario* scenario = instance->GetInstanceScenario())
                scenario->CompleteScenario();
        }

    }

    void OnPlayerEnter(Player* player) override
    {
        //instance->GetInstanceScenario()->SendScenarioEvent(player, 46437);
        ///first talk
        TC_LOG_ERROR("server.worldserver", "====================scenario_artifact_ursocslair====================== ");
        //DoUpdateCriteria(CRITERIA_TYPE_SEND_EVENT_SCENARIO, 46437, 0, nullptr);
        //DoUpdateCriteria(CRITERIA_TYPE_SEND_EVENT_SCENARIO, 47340, 0, nullptr);
        //Scenario::CompleteScenario();
        //SendScenarioState(ScenarioData(SCENARIO_ID, DATA_STEP_2));
        if (!isIntr)
        {
            isIntr = true;
            events.ScheduleEvent(SCENE_PLAYER_ENTER, 5s);
        }
        events.ScheduleEvent(TEST_EVENT, 10 * IN_MILLISECONDS);
        if (InstanceScenario* scenario = instance->GetInstanceScenario())
        {
            DoUpdateCriteria(CRITERIA_TYPE_SEND_EVENT_SCENARIO, 46437, 0, nullptr);
            //scenario->CompleteCurrStep();
            //TC_LOG_ERROR("server.worldserver", "====================scenario_artifact_ursocslair  InstanceScenario====================== ");
            //scenario->CompleteScenario();
            //scenario->CompleteScenario();
            //UpdateCriteria(CRITERIA_TYPE_SEND_EVENT_SCENARIO, eventId, 0, 0, nullptr, player);
            //scenario->SendScenarioEvent(player, 46437);
            //if (players.begin() != players.end())
            //    scenario->UpdateCriteria(CRITERIA_TYPE_COMPLETE_DUNGEON_ENCOUNTER, encounter->dbcEntry->ID, 0, 0, nullptr, players.begin()->GetSource());
       }

    }

    void LeaveMap()
    {
        Map::PlayerList const& players = instance->GetPlayers();
        for (Map::PlayerList::const_iterator itr = players.begin(); itr != players.end(); ++itr)
            itr->GetSource()->TeleportTo(571, 4224.9f, -3803.161f, 119.358f, 5.3749f);
    }

    void Update(uint32 diff) override
    {
        events.Update(diff);

        switch (events.ExecuteEvent())
        {
        case SCENE_PLAYER_ENTER:
        {
            Map::PlayerList const& players = instance->GetPlayers();
            for (Map::PlayerList::const_iterator itr = players.begin(); itr != players.end(); ++itr)
                itr->GetSource()->GetSceneMgr().PlayScene(SCENE_PLAYER_ENTER);
            LoadNPC(EVENT_STEP_1, spawnData);
            break;
        }

        case TEST_EVENT:
            NextStep();
            LoadNPC(StepID, spawnData);
            events.ScheduleEvent(TEST_EVENT, 10 * IN_MILLISECONDS);
            break;

        default:
            break;
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
    bool isComplete;
};


struct npc_mylune_101393 : public ScriptedAI
{
    npc_mylune_101393(Creature* creature) : ScriptedAI(creature) { Initialize(); }

    void UpdateAI(uint32 diff) override
    {
        _scheduler.Update(diff);

        if (!UpdateVictim())
            return;

        DoMeleeAttackIfReady();
    }
    void Initialize()
    {
        instance = me->GetInstanceScript();
    }

    void MoveInLineOfSight(Unit* who) override
    {
        if (!who || !who->IsInWorld())
            return;
        if (!me->IsWithinDist(who, 15.0f, false))
            return;

        Player* player = who->GetCharmerOrOwnerPlayerOrPlayerItself();
        if (!player)
            return;
    }
private:
    InstanceScript * instance;
    TaskScheduler _scheduler;
};

struct npc_lea_stonepaw_101742 : public ScriptedAI
{
    npc_lea_stonepaw_101742(Creature* creature) : ScriptedAI(creature) { Initialize(); }

    void UpdateAI(uint32 diff) override
    {
        _scheduler.Update(diff);

        if (!UpdateVictim())
            return;

        DoMeleeAttackIfReady();
    }
    void Initialize()
    {
        instance = me->GetInstanceScript();
    }

    void MoveInLineOfSight(Unit* who) override
    {
        if (!who || !who->IsInWorld())
            return;
        if (!me->IsWithinDist(who, 15.0f, false))
            return;

        Player* player = who->GetCharmerOrOwnerPlayerOrPlayerItself();
        if (!player)
            return;
    }
private:
    InstanceScript * instance;
    TaskScheduler _scheduler;
};

struct npc_lea_stonepaw_101743 : public ScriptedAI
{
    npc_lea_stonepaw_101743(Creature* creature) : ScriptedAI(creature) { Initialize(); }

    void UpdateAI(uint32 diff) override
    {
        _scheduler.Update(diff);

        if (!UpdateVictim())
            return;

        DoMeleeAttackIfReady();
    }
    void Initialize()
    {
        instance = me->GetInstanceScript();
    }

    void MoveInLineOfSight(Unit* who) override
    {
        if (!who || !who->IsInWorld())
            return;
        if (!me->IsWithinDist(who, 15.0f, false))
            return;

        Player* player = who->GetCharmerOrOwnerPlayerOrPlayerItself();
        if (!player)
            return;
    }
private:
    InstanceScript * instance;
    TaskScheduler _scheduler;
};

struct npc_verdant_warder_101754 : public ScriptedAI
{
    npc_verdant_warder_101754(Creature* creature) : ScriptedAI(creature) { Initialize(); }

    void UpdateAI(uint32 diff) override
    {
        _scheduler.Update(diff);

        if (!UpdateVictim())
            return;

        DoMeleeAttackIfReady();
    }
    void Initialize()
    {
        instance = me->GetInstanceScript();
    }

    void MoveInLineOfSight(Unit* who) override
    {
        if (!who || !who->IsInWorld())
            return;
        if (!me->IsWithinDist(who, 15.0f, false))
            return;

        Player* player = who->GetCharmerOrOwnerPlayerOrPlayerItself();
        if (!player)
            return;
    }
private:
    InstanceScript * instance;
    TaskScheduler _scheduler;
};

struct npc_shade_of_xavius_101403 : public ScriptedAI
{
    npc_shade_of_xavius_101403(Creature* creature) : ScriptedAI(creature) { Initialize(); }

    void UpdateAI(uint32 diff) override
    {
        _scheduler.Update(diff);

        if (!UpdateVictim())
            return;

        DoMeleeAttackIfReady();
    }
    void Initialize()
    {
        instance = me->GetInstanceScript();
    }

    void MoveInLineOfSight(Unit* who) override
    {
        if (!who || !who->IsInWorld())
            return;
        if (!me->IsWithinDist(who, 15.0f, false))
            return;

        Player* player = who->GetCharmerOrOwnerPlayerOrPlayerItself();
        if (!player)
            return;
    }
private:
    InstanceScript * instance;
    TaskScheduler _scheduler;
};

struct npc_claws_of_ursoc_105331 : public ScriptedAI
{
    npc_claws_of_ursoc_105331(Creature* creature) : ScriptedAI(creature) { Initialize(); }

    void UpdateAI(uint32 diff) override
    {
        _scheduler.Update(diff);

        if (!UpdateVictim())
            return;

        DoMeleeAttackIfReady();
    }
    void Initialize()
    {
        instance = me->GetInstanceScript();
    }

    void MoveInLineOfSight(Unit* who) override
    {
        if (!who || !who->IsInWorld())
            return;
        if (!me->IsWithinDist(who, 15.0f, false))
            return;

        Player* player = who->GetCharmerOrOwnerPlayerOrPlayerItself();
        if (!player)
            return;
    }
private:
    InstanceScript * instance;
    TaskScheduler _scheduler;
};

struct npc_spirit_of_ursoc_101362 : public ScriptedAI
{
    npc_spirit_of_ursoc_101362(Creature* creature) : ScriptedAI(creature) { Initialize(); }

    void UpdateAI(uint32 diff) override
    {
        _scheduler.Update(diff);

        if (!UpdateVictim())
            return;

        DoMeleeAttackIfReady();
    }
    void Initialize()
    {
        instance = me->GetInstanceScript();
    }

    void MoveInLineOfSight(Unit* who) override
    {
        if (!who || !who->IsInWorld())
            return;
        if (!me->IsWithinDist(who, 15.0f, false))
            return;

        Player* player = who->GetCharmerOrOwnerPlayerOrPlayerItself();
        if (!player)
            return;
    }
private:
    InstanceScript * instance;
    TaskScheduler _scheduler;
};

struct npc_lea_stonepaw_105243 : public ScriptedAI
{
    npc_lea_stonepaw_105243(Creature* creature) : ScriptedAI(creature) { Initialize(); }

    void UpdateAI(uint32 diff) override
    {
        _scheduler.Update(diff);
        if (!UpdateVictim())
            return;

        DoMeleeAttackIfReady();
    }
    void Initialize()
    {
        instance = me->GetInstanceScript();
        isSayHi = false;
        isStep1 = true;
    }

    void EnterCombat(Unit* victim)
    {
        TC_LOG_ERROR("server.worldserver", "====================scenario_artifact_ursocslair  EnterCombat====================== ");
        if (!me->HasAura(186588))
            me->CastSpell(me, 186588, true);
        Player* player = me->GetCharmerOrOwnerPlayerOrPlayerItself();
        _scheduler.Schedule(1s, 2s, [this, player, victim](TaskContext context)
        {
            me->GetMotionMaster()->Clear();
            me->GetMotionMaster()->MoveCloserAndStop(1, victim, PET_FOLLOW_DIST);
            me->Say(104079);
            DoMeleeAttackIfReady();
            context.Repeat(2s);
        });
    }

    void MoveInLineOfSight(Unit* who) override
    {
        if (!who || !who->IsInWorld())
            return;
        if (!me->IsWithinDist(who, 15.0f, false))
            return;

        Player* player = who->GetCharmerOrOwnerPlayerOrPlayerItself();
        if (!player)
            return;

        //me->GetScenario()->CompleteScenario();
        if (!isSayHi)
        {
            isSayHi = true;
            me->Say(104079);
            me->SetOwnerGUID(player->GetGUID());
            me->SetFaction(player->getFaction());
            //PhasingHandler::InheritPhaseShift(tempSumm, caster);
            //me->GetMotionMaster()->MoveFollow(player, PET_FOLLOW_DIST, me->GetFollowAngle());
        }

        if (player->IsInCombat())
        {
            if (!me->IsInCombat())
                if (Creature* npc = me->FindNearestCreature(NPC_ROTHOOF_DEFILER_101386, 25.0f, true))
                    if (me->IsValidAttackTarget(npc))
                    {
                        me->Attack(npc, true);
                    }
                    else
                    {
                        if (!me->HasAura(186588))
                            me->CastSpell(me, 186588, true);
                        me->CastSpell(npc, 194153, false);
                        TC_LOG_ERROR("server.worldserver", "====================scenario_artifact_ursocslair  can't attack npc====================== ");
                    }


        } else
        {
            _scheduler.CancelAll();
            me->RemoveAurasDueToSpell(186588);
            me->AttackStop();

            if(isStep1)
             me->GetMotionMaster()->MoveFollow(player, PET_FOLLOW_DIST, me->GetFollowAngle());
        }


        if (me->FindNearestCreature(59113, 15.0f, true))
        {
            isStep1 = false;
            //instance->SendScenarioState(InstanceScript::ScenarioData(SCENARIO_ID, DATA_STEP_2));
        }



        player->GetScenario()->CompleteScenario();

        if (InstanceScenario* scenario = me->GetMap()->ToInstanceMap()->GetInstanceScenario())
        {

            //TC_LOG_ERROR("server.worldserver", "====================scenario_artifact_ursocslair  InstanceScenario111====================== ");
            //instance->SendScenarioState(InstanceScript::ScenarioData(SCENARIO_ID, DATA_STEP_1));

            //instance->SendScenarioProgressUpdate(InstanceScript::CriteriaProgressData(SCENARIO_ID, 1, me->GetInstanceId(), uint32(time(nullptr)), 0, 0));
            //scenario->CompleteScenario();
            //scenario->SendScenarioEvent(player, 47340);
            //scenario->CompleteScenario();
            //UpdateCriteria(CRITERIA_TYPE_SEND_EVENT_SCENARIO, eventId, 0, 0, nullptr, player);
            //scenario->SendScenarioEvent(player, 46437);
            //if (players.begin() != players.end())
            //    scenario->UpdateCriteria(CRITERIA_TYPE_COMPLETE_DUNGEON_ENCOUNTER, encounter->dbcEntry->ID, 0, 0, nullptr, players.begin()->GetSource());
        }

        ///if (InstanceScenario* scenario = instance->ToInstanceMap()->GetInstanceScenario())        DoUpdateCriteria(CRITERIA_TYPE_SEND_EVENT_SCENARIO, 46437, 0, nullptr);
        //instance->SendScenarioState(InstanceScript::ScenarioData(SCENARIO_ID, DATA_STEP_2));
    }
private:
    InstanceScript* instance;
    TaskScheduler _scheduler;
    bool isSayHi;
    bool isStep1;
};


class go_claws_of_ursoc_248853 : public GameObjectScript
{
public:
    go_claws_of_ursoc_248853() : GameObjectScript("go_claws_of_ursoc_248853") { }

    bool OnGossipHello(Player* player, GameObject* go) override
    {

        return false;
    }

    void OnLootStateChanged(GameObject* go, uint32 state, Unit* unit)
    {
        if (state == GO_ACTIVATED && unit)
            if (Player* player = unit->ToPlayer())
                if (player->GetQuestStatus(QUEST_WHEN_DREAMS_BECOME_NIGHTMARES) == QUEST_STATUS_INCOMPLETE || player->GetQuestStatus(QUEST_WHEN_DREAMS_BECOME_NIGHTMARES) == QUEST_STATUS_COMPLETE)
                {
                    //player->CastSpell(player, 199963, true);
                    //player->CastSpell(player, 199960, true);
                    //player->CastSpell(player, 208779, true);

                    ///Scenaro Complete
                    if (instance = go->GetInstanceScript())
                    {
                        instance->DoPlayScenePackageIdOnPlayers(DRUID_GUARDIA_ACQUISTION_ARTIFACT_LOOTED_SCENE);
                        player->GetScenario()->CompleteScenario();
                    }
                    player->KilledMonsterCredit(101334);
                    if (Creature* lea = go->FindNearestCreature(NPC_LEA_STONEPAW_101742, 25.0f))
                    {
                        ///TO DO
                        //lea->AI()->DoAction(1);
                        lea->GetScheduler().Schedule(10s, 11s, [lea, player](TaskContext context)
                        {
                            lea->RemoveAurasDueToSpell(208707);
                            lea->Say(108061, player);
                        });

                        lea->GetScheduler().Schedule(14s, 15s, [lea, player](TaskContext context)
                        {
                            lea->Say("balarabala", LANG_UNIVERSAL, player);
                            ///player->TeleportTo();
                        });
                        ///BroadcastTextId: 108061 SoundId: 69750 ?????????????????????????,??????????????
                    }
                }
    }

    InstanceScript* instance;
};

void AddSC_scenario_artifact_ursocslair()
{
    RegisterInstanceScript(scenario_artifact_ursocslair, 1536);
    RegisterCreatureAI(npc_mylune_101393);
    RegisterCreatureAI(npc_shade_of_xavius_101403);
    RegisterCreatureAI(npc_lea_stonepaw_101742);
    RegisterCreatureAI(npc_verdant_warder_101754);
    RegisterCreatureAI(npc_lea_stonepaw_101743);
    RegisterCreatureAI(npc_claws_of_ursoc_105331);
    RegisterCreatureAI(npc_spirit_of_ursoc_101362);
    RegisterCreatureAI(npc_lea_stonepaw_105243);

    new go_claws_of_ursoc_248853();
}
