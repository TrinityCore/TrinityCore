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
#include "ObjectMgr.h"
#include "SceneMgr.h"
#include "Log.h"
#include "Spell.h"

enum
{
    DATA_AKC = 0,
    DATA_STAGE_1 = 1,
    DATA_STAGE_2 = 2,
    DATA_STAGE_3 = 3,
    DATA_STAGE_4 = 4,
    DATA_STAGE_5 = 5,
    DATA_STAGE_6 = 6,
    DATA_STAGE_7 = 7,

    DATA_MAX_ENCOUNTERS = 8,

    NORMAL_PHASE = 169,
    QUEST_DRUID = 40838,
    DRUID_BALANCE_ACQUISTION_ARTIFACT_LOOTED_SCENE = 1579,
};

enum
{
    ScenarioID = 1014,///druid

    NPC_THE_CONSERVATOR = 101257,
    NPC_TARGET_BUNNY = 101361,


    NPC_WEBBED_VICTIM_108028 = 108028,
    NPC_VERSTOK_DARKBOUGH2 = 108053,


    GO_DOOR_1 = 247322,
    GO_DOOR_2 = 123,

    GO_LEGION_GATE = 249494,
    GO_RUNIED_SWITCH = 250638,
    GO_PLATFORM = 250824,

};


struct scenario_artifact_karazhan_catacombs : public InstanceScript
{
    scenario_artifact_karazhan_catacombs(InstanceMap* map) : InstanceScript(map) {  }

    void Initialize() override
    {
        SetBossNumber(DATA_MAX_ENCOUNTERS);
        SetData(DATA_AKC, NOT_STARTED);
        for (uint8 i = 1; i < 7; ++i)
            SetData(i, NOT_STARTED);

        isComplete = false;
        StepID = 1;
        FirstCount = 0;
        m_playerGUID = ObjectGuid::Empty;
    }

    //.go -11018.37f -2002.739f 24.99422 1533
    //player->TeleportTo(1533, Position(-11018.37f, -2002.739f, 24.99422f, 1.369567f));
    void OnPlayerEnter(Player* player) override
    {
        InstanceScript::OnPlayerEnter(player);
        TC_LOG_ERROR("server.worldserver", "====================scenario_artifact_karazhan_catacombs  ====================== ");
        if (player->GetMapId() == 1533)
        {
            m_playerGUID = player->GetGUID();
            PhasingHandler::AddPhase(player, NORMAL_PHASE, true);
            DoCloseDoorOrButton(firstdoorGUID);
        }
    }

    void OnCreatureCreate(Creature* creature) override
    {
        InstanceScript::OnCreatureCreate(creature);
        switch (creature->GetEntry())
        {
            case 1:
            {
                revil1GUID = creature->GetGUID();
                break;
            }
            case NPC_THE_CONSERVATOR:
            {
                conservatGUID = creature->GetGUID();
                break;
            }
            case NPC_TARGET_BUNNY:
            {
                targetGUID = creature->GetGUID();
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
        case GO_DOOR_2:
        {
            seconddoorGUID = go->GetGUID();
            break;
        }
        }
    }

    void NextStep()
    {
        TC_LOG_ERROR("server.worldserver", "====================scenario_artifact_karazhan_catacombs  NextStep  %u====================== ", StepID);
        if (StepID < DATA_STAGE_7)
        {
            ++StepID;
            if (Scenario* scenario = instance->GetInstanceScenario())
                scenario->CompleteCurrStep();
        }
        else if (StepID == DATA_STAGE_7)
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
            NextStep();
            DoRespawnGameObject(seconddoorGUID);
            if (Creature* conservat = instance->GetCreature(conservatGUID))
                conservat->AI()->DoAction(1);
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
            DoKilledMonsterCredit(QUEST_DRUID,100813);
            if (Creature* rabit = instance->GetCreature(targetGUID))
                rabit->SummonGameObject(246437, Position(-10865.06f, - 1961.418f, - 39.69912f, 0.1293521f), QuaternionData(), WEEK);
            TempSummon* revil = instance->SummonCreature(101282, Position(-10855.7666f, -1962.79126f, -41.23f, 3.21543f));
            revil->AI()->DoAction(4);
        }
        else if (type == DATA_STAGE_7 && data == DONE)
        {
            NextStep();
            DoPlayScenePackageIdOnPlayers(DRUID_BALANCE_ACQUISTION_ARTIFACT_LOOTED_SCENE);
            DoKilledMonsterCredit(QUEST_DRUID, 103748);
        }

    }

private:
    bool isComplete;
    ObjectGuid m_playerGUID;
    ObjectGuid revil1GUID;
    ObjectGuid conservatGUID;
    ObjectGuid firstdoorGUID;
    ObjectGuid seconddoorGUID;
    ObjectGuid targetGUID;

    uint8 StepID;
    uint8 FirstCount;
};

struct npc_revil_kost_101282 : public ScriptedAI
{
    npc_revil_kost_101282(Creature* creature) : ScriptedAI(creature) { Initialize(); }

    enum
    {
        ACTION_STAGE_2 = 1,
        ACTION_STAGE_3_return = 2,
        ACTION_STAGE_3_kill_conservator = 3,
        ACTION_STAGE_7 = 4,
    };
    void DoAction(int32 param)
    {
        switch (param)
        {
        case ACTION_STAGE_2:
        {
            if (instance->GetData(DATA_STAGE_1) == NOT_STARTED)
            {
                instance->SetData(DATA_STAGE_1, DONE);
                if (Creature* revil2 = me->FindNearestCreature(101286, 15.0f, true))
                {
                    me->GetMotionMaster()->Clear();
                    me->GetMotionMaster()->MoveCloserAndStop(1, revil2, 0.0f);
                    revil2->DespawnOrUnsummon();
                    me->GetScheduler().Schedule(Milliseconds(1000), [](TaskContext context)
                    {
                        GetContextCreature()->Say(103596);
                    });

                    me->GetScheduler().Schedule(Milliseconds(3000), [](TaskContext context)
                    {
                        if (Creature* ariden = GetContextCreature()->FindNearestCreature(100850, 35.0f, true))
                        {
                            ariden->CastSpell(ariden, 199576, true);
                            ariden->Say(103598);
                        }
                    });

                    me->GetScheduler().Schedule(Milliseconds(5000), [](TaskContext context)
                    {
                        GetContextCreature()->Say(103599);
                    });

                    me->GetScheduler().Schedule(Milliseconds(7000), [](TaskContext context)
                    {
                        GetContextCreature()->Say(103600);
                    });
                }
            }
            break;
        }
        case ACTION_STAGE_3_return:
            me->GetMotionMaster()->MoveFollow(me->GetOwner(), PET_FOLLOW_DIST, me->GetFollowAngle());
            break;
        case ACTION_STAGE_3_kill_conservator:
        {
            me->GetScheduler().Schedule(Milliseconds(1000), [](TaskContext context)
            {
                GetContextCreature()->Say(103606);
            });

            me->GetScheduler().Schedule(Milliseconds(3000), [](TaskContext context)
            {
                GetContextCreature()->Say(103607);
            });

            me->GetScheduler().Schedule(Milliseconds(5000), [](TaskContext context)
            {
                GetContextCreature()->Say(103684);
                GetContextCreature()->GetMotionMaster()->Clear();
                GetContextCreature()->GetMotionMaster()->MovePoint(2, Position(-10960.8f, -1892.344f, -48.30285f, 1.796813f), true);
            });
            break;
        }
        case ACTION_STAGE_7:
        {
            //change npcflag
            me->AddNpcFlag(UNIT_NPC_FLAG_QUESTGIVER);
            me->GetScheduler().Schedule(Milliseconds(1000), [](TaskContext context)
            {
                GetContextCreature()->AI()->Talk(0);
            });
            me->GetScheduler().Schedule(Milliseconds(3000), [](TaskContext context)
            {
                GetContextCreature()->AI()->Talk(1);
            });
            me->GetScheduler().Schedule(Milliseconds(5000), [](TaskContext context)
            {
                GetContextCreature()->AI()->Talk(2);
            });
            me->GetScheduler().Schedule(Milliseconds(7000), [](TaskContext context)
            {
                GetContextCreature()->AI()->Talk(3);
            });
            break;
        }
        }
    }

    void Initialize()
    {
        instance = me->GetInstanceScript();
        IsLock = false;
    }

    void MoveInLineOfSight(Unit* who) override
    {
        if (!who || !who->IsInWorld() || !me->IsWithinDist(who, 10.0f, false))
            return;

        Player* player = who->GetCharmerOrOwnerPlayerOrPlayerItself();
        if (!player)
            return;
        if (instance->GetData(DATA_STAGE_1) == NOT_STARTED && !IsLock)
        {
            IsLock = true;
            me->Say(103594);
            me->SetOwnerGUID(player->GetGUID());
            me->GetMotionMaster()->MoveFollow(player, PET_FOLLOW_DIST, me->GetFollowAngle());

            me->GetScheduler().Schedule(Milliseconds(2000), [player](TaskContext context)
            {
                if (GetContextCreature()->FindNearestCreature(101286, 15.0f, true))
                    GetContextCreature()->AI()->DoAction(ACTION_STAGE_2);
                else
                    context.Repeat(2s);
            });

            me->GetScheduler().Schedule(Milliseconds(10000), [player](TaskContext context)
            {
                GetContextCreature()->Say(103595, player);
            });
        }

    }
private:
    InstanceScript * instance;
};

struct npc_the_conservator_101257 : public ScriptedAI
{
    npc_the_conservator_101257(Creature* creature) : ScriptedAI(creature) { Initialize(); }

    enum
    {
        SPELL_HATEFUL_BOLT = 201693,
        SPELL_EVOCATION = 201692 ,
    };
    void DoAction(int32 param)
    {
        switch (param)
        {
        case 1:
            me->Yell(103603);
            me->GetMotionMaster()->MovePoint(1, me->GetPositionWithDistInFront(15.0f), true);
            break;
        case 2:
            islow = true;
            events.CancelEvent(SPELL_HATEFUL_BOLT);
            events.ScheduleEvent(SPELL_EVOCATION, 2 * IN_MILLISECONDS);
            break;
        }
    }

    void Initialize()
    {
        instance = me->GetInstanceScript();
        islow = false;
    }

    void EnterCombat(Unit* victim)
    {
        events.ScheduleEvent(SPELL_HATEFUL_BOLT, 2 * IN_MILLISECONDS);
    }

    void JustDied(Unit* /*killer*/) override
    {
        if (instance->GetData(DATA_STAGE_3) == NOT_STARTED)
            instance->SetData(DATA_STAGE_3, DONE);
        if (Creature* revil1 = me->FindNearestCreature(101282, 50.0f, true))
            revil1->AI()->DoAction(3);
    }

    void UpdateAI(uint32 diff) override
    {
        if (!UpdateVictim())
            return;

        events.Update(diff);

        if (me->HasUnitState(UNIT_STATE_CASTING))
            return;

        if (!islow && me->GetHealthPct() <= 50)
            DoAction(2);

        while (uint32 eventId = events.ExecuteEvent())
        {
            switch (eventId)
            {
            case SPELL_HATEFUL_BOLT:
            {
                DoCast(SPELL_HATEFUL_BOLT);
                events.ScheduleEvent(SPELL_HATEFUL_BOLT, 2 * IN_MILLISECONDS);
                break;
            }
            case SPELL_EVOCATION:
            {
                DoCast(SPELL_EVOCATION);
                events.ScheduleEvent(SPELL_EVOCATION, 10 * IN_MILLISECONDS);
                break;
            }
            default:
                break;
            }
        }
        DoMeleeAttackIfReady();
    }
private:
    InstanceScript * instance;
    bool islow;
};

///go 246436 The Scythe of Elune
class go_the_scythe_of_elune_1 : public GameObjectScript
{
public:
    go_the_scythe_of_elune_1() : GameObjectScript("go_the_scythe_of_elune_1") { isloot = false; }

    bool OnGossipHello(Player* /*player*/, GameObject* go)
    {
        if (!isloot)
        {
            isloot = true;
            TempSummon* ariden = go->SummonCreature(100850, Position(-10962.4f, -1874.459961f, -48.288898f, 4.70906f));
            ariden->AI()->DoAction(2);
        }

        return false;
    }
    bool isloot;
};

struct npc_ariden_100850 : public ScriptedAI
{
    npc_ariden_100850(Creature* creature) : ScriptedAI(creature) { Initialize(); }

    enum
    {
        ACTION_STAGE_2 = 1,
        ACTION_STAGE_4 = 2,
        ACTION_STAGE_4_COMPLETE = 3,
    };

    void DoAction(int32 param)
    {
        switch (param)
        {
        case ACTION_STAGE_2:
        {
            std::list<Creature*> cList = me->FindNearestCreatures(100845, 50.0f);
            for (auto creature : cList)
                creature->DespawnOrUnsummon();

            me->Say(103602);
            me->DespawnOrUnsummon(2000);
            if (instance->GetData(DATA_STAGE_2) == NOT_STARTED)
                instance->SetData(DATA_STAGE_2, DONE);
            if (Creature* revil1 = me->FindNearestCreature(101282, 50.0f, true))
                revil1->AI()->DoAction(2);
            break;
        }
        case ACTION_STAGE_4:
        {
            me->Yell(103608);

            if (Creature* revil = me->FindNearestCreature(101282, 50.0f, true))
            {
                revil->GetScheduler().Schedule(Milliseconds(2000), [](TaskContext context)
                {
                    GetContextCreature()->Say(103609);
                });

                revil->GetScheduler().Schedule(Milliseconds(5000), [this, revil](TaskContext context)
                {
                    me->CastSpell(revil, 199735, true);
                });

                revil->GetScheduler().Schedule(Milliseconds(7000), [](TaskContext context)
                {
                    GetContextCreature()->Say(103612);
                });
            }

            me->GetScheduler().Schedule(Milliseconds(4000), [](TaskContext context)
            {
                GetContextCreature()->Say(103610);
            });

            me->GetScheduler().Schedule(Milliseconds(6000), [](TaskContext context)
            {
                GetContextCreature()->Say(104467);
                GetContextCreature()->GetMotionMaster()->MoveAwayAndDespawn(40.0f, 5000);
                GetContextCreature()->AI()->DoAction(ACTION_STAGE_4_COMPLETE);
            });
            break;
        }
        case ACTION_STAGE_4_COMPLETE:
        {
            if (instance->GetData(DATA_STAGE_4) == NOT_STARTED)
                instance->SetData(DATA_STAGE_4, DONE);
            break;
        }
        }
    }

    void SpellHit(Unit* /*caster*/, SpellInfo const* spell) override
    {
        if (spell->Id == 78675 || spell->Id == 97547)
            DoAction(ACTION_STAGE_2);
    }

    void Initialize()
    {
        instance = me->GetInstanceScript();
    }
private:
    InstanceScript * instance;
};

struct npc_ariden_102200 : public ScriptedAI
{
    npc_ariden_102200(Creature* creature) : ScriptedAI(creature) { Initialize(); }

    enum
    {
        ACTION_STAGE_5 = 1,

        SPELL_PHANTOM_SCYTHE = 201833,
        SPELL_BLOODREAP = 204659,
        SPELL_EXHAUSTION = 204661,
    };

    void DoAction(int32 param)
    {
        switch (param)
        {
        case ACTION_STAGE_5:
            if (instance->GetData(DATA_STAGE_5) == NOT_STARTED)
                instance->SetData(DATA_STAGE_5, DONE);
            break;
        }
    }

    void JustDied(Unit* /*killer*/) override
    {
        Talk(5);
        if (instance->GetData(DATA_STAGE_6) == NOT_STARTED)
            instance->SetData(DATA_STAGE_6, DONE);
    }

    void EnterCombat(Unit* victim)
    {
        Talk(0);
        me->GetScheduler().Schedule(Milliseconds(1000), [](TaskContext context)
        {
            GetContextCreature()->AI()->Talk(1);
        });

        me->GetScheduler().Schedule(Milliseconds(10000), [](TaskContext context)
        {
            GetContextCreature()->AI()->Talk(2);
        });

        me->GetScheduler().Schedule(Milliseconds(12000), [](TaskContext context)
        {
            GetContextCreature()->AI()->Talk(3);
        });

        me->GetScheduler().Schedule(Milliseconds(14000), [](TaskContext context)
        {
            GetContextCreature()->AI()->Talk(4);
        });
        events.ScheduleEvent(SPELL_PHANTOM_SCYTHE, 2 * IN_MILLISECONDS);
        events.ScheduleEvent(SPELL_BLOODREAP, 10 * IN_MILLISECONDS);
        events.ScheduleEvent(SPELL_EXHAUSTION, 25 * IN_MILLISECONDS);
    }

    void UpdateAI(uint32 diff) override
    {
        if (!UpdateVictim())
            return;

        events.Update(diff);

        if (me->HasUnitState(UNIT_STATE_CASTING))
            return;

        while (uint32 eventId = events.ExecuteEvent())
        {
            switch (eventId)
            {
            case SPELL_PHANTOM_SCYTHE:
            {
                DoCast(SPELL_PHANTOM_SCYTHE);
                events.ScheduleEvent(SPELL_PHANTOM_SCYTHE, 10 * IN_MILLISECONDS);
                break;
            }
            case SPELL_BLOODREAP:
            {
                DoCast(SPELL_BLOODREAP);
                events.ScheduleEvent(SPELL_BLOODREAP, 10 * IN_MILLISECONDS);
                break;
            }
            case SPELL_EXHAUSTION:
            {
                DoCast(SPELL_EXHAUSTION);
                events.ScheduleEvent(SPELL_EXHAUSTION, 25 * IN_MILLISECONDS);
                break;
            }
            default:
                break;
            }
        }
        DoMeleeAttackIfReady();
    }
    void Initialize()
    {
        instance = me->GetInstanceScript();
        issay = false;
    }

    void SpellHit(Unit* /*caster*/, SpellInfo const* spell) override
    {
        if (!issay && spell->Id == 339)
        {
            issay = true;
            me->Yell(106035);
        }
    }

    void MoveInLineOfSight(Unit* who) override
    {
        if (!who || !who->IsInWorld() || !me->IsWithinDist(who, 25.0f, false))
            return;

        Player* player = who->GetCharmerOrOwnerPlayerOrPlayerItself();
        if (!player)
            return;
        if (instance->GetData(DATA_STAGE_5) == NOT_STARTED)
            DoAction(ACTION_STAGE_5);

    }
private:
    InstanceScript * instance;
    bool issay;
};

class go_the_scythe_of_elune_246437 : public GameObjectScript
{
public:
    go_the_scythe_of_elune_246437() : GameObjectScript("go_the_scythe_of_elune_246437") { isloot = false; }

    void OnLootStateChanged(GameObject* go, uint32 state, Unit* unit)
    {
        if (state == GO_ACTIVATED && unit && !isloot)
        {
            isloot = true;
            if (InstanceScript * instance = go->GetInstanceScript())
                instance->SetData(DATA_STAGE_7, DONE);
        }
    }
    bool isloot;
};

void AddSC_scenario_artifact_karazhan_catacombs()
{
    RegisterInstanceScript(scenario_artifact_karazhan_catacombs, 1533);

    RegisterCreatureAI(npc_revil_kost_101282);
    RegisterCreatureAI(npc_ariden_100850);
    RegisterCreatureAI(npc_the_conservator_101257);
    new go_the_scythe_of_elune_1();
    RegisterCreatureAI(npc_ariden_102200);
    new go_the_scythe_of_elune_246437();
}
