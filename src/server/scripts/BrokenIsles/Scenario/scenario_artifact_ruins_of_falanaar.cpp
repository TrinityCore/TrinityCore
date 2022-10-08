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

 /*scenario_artifact_ruins_of_falanaar*/
#include "PhasingHandler.h"
#include "ScriptedGossip.h"
#include "InstanceScenario.h"
#include "GameObject.h"
#include "SceneMgr.h"
#include "Log.h"
#include "Spell.h"

enum
{
    DATA_ROF = 0,
    DATA_STAGE_1 = 1,
    DATA_STAGE_2 = 2,
    DATA_STAGE_3 = 3,
    DATA_STAGE_4 = 4,
    DATA_STAGE_5 = 5,
    DATA_STAGE_6 = 6,
    DATA_STAGE_7 = 7,
    DATA_STAGE_8 = 8,
    DATA_MAX_ENCOUNTERS = 9,
    NORMAL_PHASE = 169,
    QUEST_1 = 1,
    DRUID_FERAL_ACQUISTION_ARTIFACT_LOOTED_SCENE = 1631,
    DRUID_FERAL_ACQUISTION_ARTIFACT_SECOND_DOOR_SCENE = 1736,
    DRUID_FERAL_ACQUISTION_ARTIFACT_3_SCENE = 1646,
};

enum
{
    ScenarioID = 1108,
    NPC_VERSTOK_DARKBOUGH = 108003,
    NPC_WEBBED_VICTIM_108028 = 108028,
    NPC_VERSTOK_DARKBOUGH2 = 108053,
    GO_DOOR_1 = 25064,
    GO_LEGION_GATE = 249494,
    GO_RUNIED_SWITCH = 250638,
    GO_PLATFORM = 250824,
};

struct scenario_artifact_ruins_of_falanaar : public InstanceScript
{
    scenario_artifact_ruins_of_falanaar(InstanceMap* map) : InstanceScript(map) {  }

    void Initialize() override
    {
        SetBossNumber(DATA_MAX_ENCOUNTERS);
        SetData(DATA_ROF, NOT_STARTED);
        for (uint8 i = 1; i < 8; ++i)
            SetData(i, NOT_STARTED);

        isComplete = false;
        StepID = 1;
        FirstCount = 0;
        m_playerGUID = ObjectGuid::Empty;
    }

    //ServerToClient: SMSG_NEW_WORLD(0x25A9) Length : 36 ConnIdx : 1 Time : 09 / 10 / 2016 13:05 : 52.368 Number : 13838
    //Map : 1612 (-Unknown - )
    //Position : X : 1940.97 Y : 5558.38 Z : 60.66 O : 4.746947
    void OnPlayerEnter(Player* player) override
    {
        InstanceScript::OnPlayerEnter(player);
        TC_LOG_ERROR("server.worldserver", "====================scenario_artifact_ruins_of_falanaar  ====================== ");
        if (player->GetMapId() == 1612)
        {
            m_playerGUID = player->GetGUID();
            PhasingHandler::AddPhase(player, NORMAL_PHASE, true);


        }
    }

    void OnCreatureCreate(Creature* creature) override
    {
        InstanceScript::OnCreatureCreate(creature);
        switch (creature->GetEntry())
        {
        case NPC_VERSTOK_DARKBOUGH:
        {
            verstokGUID = creature->GetGUID();
            break;
        }
        case NPC_WEBBED_VICTIM_108028:
        {
            victimGUID = creature->GetGUID();
            break;
        }
        case NPC_VERSTOK_DARKBOUGH2:
        {
            verstok2GUID = creature->GetGUID();
            break;
        }
        }
    }

    void OnGameObjectCreate(GameObject* go) override
    {
        InstanceScript::OnGameObjectCreate(go);

        switch (go->GetEntry())
        {
        case GO_DOOR_1:
        {
            firstdoorGUID = go->GetGUID();
            break;
        }
        case GO_RUNIED_SWITCH:
        {
            go->SetGoState(GO_STATE_ACTIVE);
            break;
        }
        case GO_LEGION_GATE:
        {
            legionGUID = go->GetGUID();
            break;
        }
        }
    }

    void NextStep()
    {
        TC_LOG_ERROR("server.worldserver", "====================scenario_artifact_ruins_of_falanaar  NextStep  %u====================== ", StepID);
        if (StepID < DATA_STAGE_8)
        {
            ++StepID;
            if (Scenario* scenario = instance->GetInstanceScenario())
                scenario->CompleteCurrStep();
        }
        else if (StepID == DATA_STAGE_8)
        {
            if (!isComplete)
                if (Scenario* scenario = instance->GetInstanceScenario())
                    scenario->CompleteCurrStep();

            ///COMPLETE SCENARIO
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
            ++FirstCount;
            TC_LOG_ERROR("server.worldserver", "====================scenario_artifact_ruins_of_falanaar  DATA_STAGE_2  %u====================== ", FirstCount);
            if (FirstCount == 2)
            {
                //open door 250632
                DoRespawnGameObject(firstdoorGUID);
                NextStep();
            }
        }
        else if (type == DATA_STAGE_3 && data == DONE)
        {
            NextStep();
            if (Creature* verstok = instance->GetCreature(verstokGUID))
                verstok->AI()->DoAction(1);
        }
        else if (type == DATA_STAGE_4 && data == DONE)
        {
            DoRespawnGameObject(legionGUID);
            NextStep();
        }
        else if (type == DATA_STAGE_5 && data == DONE)
        {
            DoPlayScenePackageIdOnPlayers(DRUID_FERAL_ACQUISTION_ARTIFACT_3_SCENE);
            NextStep();
        }
        else if (type == DATA_STAGE_6 && data == DONE)
        {
            NextStep();
            if (Creature* victim = instance->GetCreature(victimGUID))
                victim->DespawnOrUnsummon(1000);
            if (Creature* verstok2 = instance->GetCreature(verstok2GUID))
                verstok2->AI()->DoAction(1);

        }
        else if (type == DATA_STAGE_7 && data == DONE)
        {
            NextStep();
            DoPlayScenePackageIdOnPlayers(DRUID_FERAL_ACQUISTION_ARTIFACT_LOOTED_SCENE);
        }
        else if (type == DATA_STAGE_8 && data == DONE)
        {
            NextStep();
        }
    }

private:
    bool isComplete;
    ObjectGuid m_playerGUID;
    ObjectGuid verstokGUID;
    ObjectGuid firstdoorGUID;
    ObjectGuid seconddoorGUID;
    ObjectGuid legionGUID;
    ObjectGuid victimGUID;
    ObjectGuid verstok2GUID;
    uint8 StepID;
    uint8 FirstCount;
};

class reach_to_stage_2 : public PlayerScript
{
public:
    reach_to_stage_2() : PlayerScript("reach_to_stage_2") {}

    void OnUpdateAreaAlternate(Player* player, uint32 newArea, uint32 /*oldArea*/)
    {
        if (newArea == 8189)
            if (InstanceScript * instance = player->GetInstanceScript())
                if (instance->GetData(DATA_STAGE_1) == NOT_STARTED)
                    instance->SetData(DATA_STAGE_1, DONE);
    }
};

struct npc_ravenous_withered_107790 : public ScriptedAI
{
    npc_ravenous_withered_107790(Creature* creature) : ScriptedAI(creature) { Initialize(); }

    void Initialize()
    {
        isused = false;
        instance = me->GetInstanceScript();
    }

    void MoveInLineOfSight(Unit* who) override
    {
        if (Player* player = who->ToPlayer())
            if (me->IsWithinDist(who, 10.0f, false) && !isused)
            {
                isused = true;
                if (GameObject* go = player->FindNearestGameObject(250638, 15.0f))
                    player->CastSpell(go, 116401, true);

                instance->SetData(DATA_STAGE_2, DONE);
            }
    }
private:
    bool isused;
    InstanceScript * instance;
};

///250638   spell=116401 on go
class go_ruined_switch : public GameObjectScript
{
public:
    go_ruined_switch() : GameObjectScript("go_ruined_switch") { isused = false; }

    bool OnGossipHello(Player* player, GameObject* go) override
    {
        TC_LOG_ERROR("server.worldserver", "====================go_ruined_switch  OnGossipHello  ========= ");
        if (InstanceScript * instance = go->GetInstanceScript())
        {
            if (!isused)
            {
                isused = true;
                instance->SetData(DATA_STAGE_2, DONE);
            }
        }

        return false;
    }
    bool isused;
};
///250824
class go_platform : public GameObjectScript
{
public:
    go_platform() : GameObjectScript("go_platform") { isused = false; }

    bool OnGossipHello(Player* player, GameObject* go) override
    {
        if (InstanceScript * instance = go->GetInstanceScript())
        {
            if (!isused)
            {
                isused = true;
                instance->DoPlayScenePackageIdOnPlayers(DRUID_FERAL_ACQUISTION_ARTIFACT_SECOND_DOOR_SCENE);
                //jumpto or tele to
                if (Creature* target = go->FindNearestCreature(107944, 50.0f, true))
                {
                    //player->NearTeleportTo(target->GetPosition());
                    player->AddDelayedTeleport(2000, 1612, target->GetPosition());
                }
                //instance->SetData(DATA_STAGE_1, DONE);
            }
        }

        return false;
    }
    bool isused;
};

struct npc_clear_platform_107937 : public ScriptedAI
{
    npc_clear_platform_107937(Creature* creature) : ScriptedAI(creature) { Initialize(); }

    void Initialize()
    {
        instance = me->GetInstanceScript();

    }

    void MoveInLineOfSight(Unit* who) override
    {
        if (Player* player = who->ToPlayer())
            if (me->IsWithinDist(who, 10.0f, false))
                if (instance->GetData(DATA_STAGE_3) == NOT_STARTED)
                    instance->SetData(DATA_STAGE_3, DONE);
    }
private:
    InstanceScript * instance;
};

struct npc_verstok_darkbough_108003 : public BossAI
{
    npc_verstok_darkbough_108003(Creature* creature) : BossAI(creature, DATA_ROF)
    {
        hp25 = false;
    }

    void Reset() override
    {
        _Reset();
        me->RemoveUnitFlag(UnitFlags(UNIT_FLAG_IMMUNE_TO_PC));
        me->AddUnitFlag(UnitFlags(UNIT_FLAG_UNK_15));
        events.ScheduleEvent(SPELL_SWIPE, 2000);
        events.ScheduleEvent(SPELL_ASHAMANES_FRENZY, urand(4800, 6100));

        hp25 = false;
    }
    enum
    {
        ACTION_INTRO = 1,
        ACTION_LEAVE = 2,
        SPELL_SWIPE = 217373,
        SPELL_ASHAMANES_FRENZY = 217364,
        SPELL_MAIM = 214429,
        SPELL_STEALTH = 229112,
    };

    void DoAction(int32 action) override
    {
        if (action == ACTION_INTRO)
        {
            events.Reset();
            me->AI()->Talk(0);
            Position pos = me->GetPositionWithDistInFront(20.0f);
            me->GetMotionMaster()->MovePoint(0, pos, true);
            me->RemoveUnitFlag(UnitFlags(UNIT_FLAG_IMMUNE_TO_PC));
            me->AddUnitFlag(UnitFlags(UNIT_FLAG_UNK_15));
        }
        else if (action == ACTION_LEAVE)
        {
            events.Reset();
            me->CastSpell(me->GetVictim(), SPELL_MAIM, true);
            me->AI()->Talk(2);

            if (instance->GetData(DATA_STAGE_4) == NOT_STARTED)
                instance->SetData(DATA_STAGE_4, DONE);
            events.ScheduleEvent(SPELL_MAIM, 1000);
            me->DespawnOrUnsummon(4000);
        }
    }

    void DamageTaken(Unit* /*attacker*/, uint32& damage) override
    {
        if (me->HealthWillBeBelowPctDamaged(25, damage))
        {
            damage = 0;
            if (!hp25)
            {
                hp25 = true;
                DoAction(ACTION_LEAVE);
            }

        }
    }

    void EnterCombat(Unit* /*who*/) override
    {
        me->setActive(true);

        events.ScheduleEvent(SPELL_SWIPE, 2000);
        events.ScheduleEvent(SPELL_ASHAMANES_FRENZY, urand(4800, 6100));

        Talk(1);
    }

    void UpdateAI(uint32 diff) override
    {
        if (!UpdateVictim())
            return;

        events.Update(diff);
        /*
        if (!hp25 && HealthBelowPct(25))
        {
            hp25 = true;
            DoAction(ACTION_LEAVE);
        }*/

        if (me->HasUnitState(UNIT_STATE_CASTING))
            return;

        while (uint32 eventId = events.ExecuteEvent())
        {
            switch (eventId)
            {
            case SPELL_SWIPE:
            {
                if (Unit* target1 = SelectTarget(SELECT_TARGET_RANDOM, 0.0, 0.0, true))
                    me->CastSpell(target1, SPELL_SWIPE, false);

                events.Repeat(4500, 5000);
                break;
            }
            case SPELL_ASHAMANES_FRENZY:
            {
                if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0.0, 0.0, true))
                    me->CastSpell(target, SPELL_ASHAMANES_FRENZY);

                events.Repeat(20200, 22200);
                break;
            }
            case SPELL_MAIM:
            {
                //me->CombatStop(true);
                me->GetMotionMaster()->MoveJump(2301.8098f, 5429.521973f, 14.534f, 3.13f, 20.0f, 20.0f);

                if (GameObject* go = me->FindNearestGameObject(GO_LEGION_GATE, 50.0f))
                    go->UseDoorOrButton();
                me->AddUnitFlag(UnitFlags(UNIT_FLAG_UNK_15 | UNIT_FLAG_IMMUNE_TO_PC));

                me->CastSpell(me, SPELL_STEALTH, true);
                break;
            }
            }
        }

        DoMeleeAttackIfReady();
    }

private:
    bool hp25;
};

struct npc_webmistress_shinaris_108027 : public ScriptedAI
{
    npc_webmistress_shinaris_108027(Creature* creature) : ScriptedAI(creature) { Initialize(); }

    void Initialize()
    {
        instance = me->GetInstanceScript();
    }

    void JustDied(Unit* /*killer*/) override
    {
        if (instance->GetData(DATA_STAGE_6) == NOT_STARTED)
            instance->SetData(DATA_STAGE_6, DONE);
    }

    void MoveInLineOfSight(Unit* who) override
    {
        if (Player* player = who->ToPlayer())
            if (me->IsWithinDist(who, 60.0f, false))
                if ((instance->GetData(DATA_STAGE_4) == DONE) && (instance->GetData(DATA_STAGE_5) == NOT_STARTED))
                    instance->SetData(DATA_STAGE_5, DONE);
    }
private:
    InstanceScript * instance;
};

struct npc_verstok_darkbough_108053 : public ScriptedAI
{
    npc_verstok_darkbough_108053(Creature* creature) : ScriptedAI(creature) { Initialize(); }

    void DoAction(int32 param)
    {
        switch (param)
        {
        case 1:
            me->Say(113191);

            me->GetScheduler().Schedule(Milliseconds(3000), [this](TaskContext context)
            {
                me->Say(113193);
            });

            me->GetScheduler().Schedule(Milliseconds(6000), [this](TaskContext context)
            {
                //summon fang
                TempSummon* fang = me->SummonCreature(107385, Position(2063.92f, 5403.93f, -34.7028f, 0.715101f));

                GameObject* fangloot = me->SummonGameObject(250386, Position(2063.78f, 5403.75f, -34.7747f, 0.7151f), QuaternionData(), WEEK);
            });

            break;
        }
    }

    void Initialize()
    {
        instance = me->GetInstanceScript();
    }
private:
    InstanceScript * instance;
};

///250386
class go_fangs_of_ashamane : public GameObjectScript
{
public:
    go_fangs_of_ashamane() : GameObjectScript("go_fangs_of_ashamane") { isloot = false; }

    void OnLootStateChanged(GameObject* go, uint32 state, Unit* unit)
    {
        if (state == GO_ACTIVATED && unit && !isloot)
        {
            isloot = true;
            if(Player* player= unit->ToPlayer())
                if(!player->GetQuestObjectiveData(42430,1))
                    player->KilledMonsterCredit(107750);

            if (InstanceScript * instance = go->GetInstanceScript())
                instance->SetData(DATA_STAGE_7, DONE);
        }
    }
    bool isloot;
};

struct npc_ebonfang_108115 : public ScriptedAI
{
    npc_ebonfang_108115(Creature* creature) : ScriptedAI(creature) { }

    void OnSpellClick(Unit* clicker, bool& /*result*/)
    {
        if (InstanceScript * instance = me->GetInstanceScript())
            if (instance->GetData(DATA_STAGE_8) == NOT_STARTED)
                instance->SetData(DATA_STAGE_8, DONE);
        if (Player* player = clicker->ToPlayer())
            player->AddDelayedTeleport(1000, 1220, Position(3975.49f, 7389.64f, 23.91f, 1.575509f));
    }
};

void AddSC_scenario_artifact_ruins_of_falanaar()
{
    RegisterInstanceScript(scenario_artifact_ruins_of_falanaar, 1612);

    new reach_to_stage_2();
    RegisterCreatureAI(npc_ravenous_withered_107790);
    new go_ruined_switch();
    new go_platform();
    RegisterCreatureAI(npc_clear_platform_107937);
    RegisterCreatureAI(npc_verstok_darkbough_108003);
    RegisterCreatureAI(npc_webmistress_shinaris_108027);
    RegisterCreatureAI(npc_verstok_darkbough_108053);
    new go_fangs_of_ashamane();
    RegisterCreatureAI(npc_ebonfang_108115);
}
