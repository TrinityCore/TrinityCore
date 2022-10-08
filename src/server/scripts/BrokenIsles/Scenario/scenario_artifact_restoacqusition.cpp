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
#include "SceneMgr.h"
#include "Log.h"
#include "Spell.h"
enum
{
    DATA_RESTOACQUSITON = 0,
    DATA_STAGE_1 = 1,
    DATA_STAGE_2 = 2,
    DATA_STAGE_3 = 3,
    DATA_STAGE_4 = 4,
    DATA_STAGE_5 = 5,
    DATA_STAGE_6 = 6,
    DATA_STAGE_7 = 7,
    DATA_MAX_ENCOUNTERS = 8,
    NORMAL_PHASE = 6115,
    QUEST_CLEANSING_THE_MOTHER_TREE = 41689,
    DRUID_RESTO_ACQUISTION_ARTIFACT_LOOTED_SCENE = 1595,
};

enum
{
    NPC_SKYLORD_OMNURON_104620 = 104620,
    NPC_ZEN_TABRA_104658 = 104658,
    NPC_CELESTINE_OF_THE_HARVEST_104657 = 104657,
    NPC_ARCHDRUID_HAMUUL_RUNETOTEM_104659 = 104659,
    NPC_LYESSA_BLOOMWATCHER_104628 = 104628,
    NPC_DESTROMATH_104619 = 104619,
};

struct scenario_artifact_restoacqusition : public InstanceScript
{
    scenario_artifact_restoacqusition(InstanceMap* map) : InstanceScript(map) {  }

    void Initialize() override
    {
        SetBossNumber(DATA_MAX_ENCOUNTERS);
        SetData(DATA_RESTOACQUSITON, NOT_STARTED);
        for (uint8 i = 1; i < 8; ++i)
            SetData(i, NOT_STARTED);

        isComplete = false;
        StepID = 1;
        stage2count = 0;
        m_playerGUID = ObjectGuid::Empty;
    }

    void OnPlayerEnter(Player* player) override
    {
        InstanceScript::OnPlayerEnter(player);
        ///player->GetMapId() == 1599
        if (player->GetMapId() == 1599 )//&& player->HasQuest(QUEST_CLEANSING_THE_MOTHER_TREE)
        {
            m_playerGUID = player->GetGUID();
            PhasingHandler::AddPhase(player, NORMAL_PHASE, true);

            if (Creature* lyessa = instance->GetCreature(_lyessaGUID))
                lyessa->Say(107083, player);//"Such devastation.", LANG_UNIVERSAL

            //player->CastSpell(player, 207008, true);
            if (Creature* omnuron = instance->GetCreature(_omnuronGUID))
               omnuron->Say(107069, player);//"$n...thank the earth that you're here.", LANG_UNIVERSAL
        }
    }

    void OnCreatureCreate(Creature* creature) override
    {
        InstanceScript::OnCreatureCreate(creature);
        switch (creature->GetEntry())
        {
            case NPC_SKYLORD_OMNURON_104620:
            {
                _omnuronGUID = creature->GetGUID();
                creature->SetHealth(creature->GetMaxHealth() * 0.8f);
                break;
            }
            case NPC_ZEN_TABRA_104658:
            {
                _zentabraGUID = creature->GetGUID();
                break;
            }
            case NPC_CELESTINE_OF_THE_HARVEST_104657:
            {
                _cothGUID = creature->GetGUID();
                creature->SetHealth(creature->GetMaxHealth() * 0.15f);
                break;
            }
            case NPC_ARCHDRUID_HAMUUL_RUNETOTEM_104659:
            {
                _hamuulGUID = creature->GetGUID();
                creature->SetHealth(creature->GetMaxHealth() * 0.2f);
                break;
            }
            case NPC_LYESSA_BLOOMWATCHER_104628:
            {
                _lyessaGUID = creature->GetGUID();
                break;
            case NPC_DESTROMATH_104619:
                _destromathGUID = creature->GetGUID();
                break;
            }
        }
    }

    void NextStep()
    {
        TC_LOG_ERROR("server.worldserver", "====================scenario_artifact_restoacqusition  NextStep  %u====================== ", StepID);
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
            if (Creature* lyessa = instance->GetCreature(_lyessaGUID))
                lyessa->AI()->DoAction(1);
            if (Creature* omnuron = instance->GetCreature(_omnuronGUID))
            {
                omnuron->RemoveAura(68442);
                omnuron->CastSpell(omnuron, 207043, true);
                omnuron->GetMotionMaster()->MoveAwayAndDespawn(15.0f, 3000);
            }
            if (Creature* hamuul = instance->GetCreature(_hamuulGUID))
                hamuul->AI()->DoAction(2);
            if (Creature* coth = instance->GetCreature(_cothGUID))
                coth->AI()->DoAction(2);
        }
        else if (type == DATA_STAGE_2 && data == DONE)
        {
            ++stage2count;
            if (stage2count == 3 && GetData(DATA_STAGE_1) == DONE)
            {
                NextStep();

                ///delay 2s giving weapon  lyessa
                if (Creature* lyessa = instance->GetCreature(_lyessaGUID))
                    lyessa->AI()->DoAction(2);
            }
        }
        else if (type == DATA_STAGE_3 && data == DONE)
        {
            NextStep();
            DoCastSpellOnPlayers(227997);
            if (Creature* zentabra = instance->GetCreature(_zentabraGUID))
                zentabra->Say(107162);//"Somethin' ain't right. Da spirits be cryin' out.", LANG_UNIVERSAL
            //delay 1s
            if (Creature* hamuul = instance->GetCreature(_hamuulGUID))
                hamuul->Say(107163);//"The gaeway is activating!", LANG_UNIVERSAL
            //show weapon
            //delay 1s play scence destromath show
            DoCastSpellOnPlayers(207276);
            TempSummon* dest = instance->SummonCreature(NPC_DESTROMATH_104619, Position(5446.76f, -3545.663f, 1555.387f, 1.121394f));
            PhasingHandler::AddPhase(dest, 6115, true);

            //ID - 92183 Detect: Quest Invis Zone 25

            //hamuul fight bear
            if (Creature* hamuul = instance->GetCreature(_hamuulGUID))
            {
                hamuul->CastSpell(hamuul, 207418, true);
                hamuul->Say("For G'Hanir!", LANG_UNIVERSAL);
                //move to destromath
            }
            //cat
            if (Creature* zentabra = instance->GetCreature(_zentabraGUID))
            {
                zentabra->CastSpell(zentabra, 207416, true);
                //move to destromath
            }
            //bird
            if (Creature* coth = instance->GetCreature(_cothGUID))
            {
                coth->CastSpell(coth, 207420, true);
                coth->Say("I'm gonna light you up!", LANG_UNIVERSAL);
                //move to destromath
            }

            ///destromath enterCombat 207423
            //In Mannoroth's name!

            ///lyess
            //75%
            //I can feel the corruption receiding.We must push forward!
            //50%
            //The darkness is fading faster with every moment.This day will be ours!
            //25%
            //107269 ?????????????!We are almost ther - do not give up hope!

            //delay 10s summon 3 mob
            //delay 20s summon 4 mob
            //delay 20s summon 5 mob

            //107130 ??????,$n!

            ///104628
            //107147 ?????????????
            //107148 ???????????,????????!
            //SMSG_MOVE_SPLINE_SET_WATER_WALK
            //ID - 115790 Water Walking
            //move
            //ID - 227997 Earthquake Camera Shake 10s
            //107162 ??????????????
            //107163 ??????!
            //ID - 207215 Ritual of Cleansing
        }
        else if (type == DATA_STAGE_4 && data == DONE)
        {
            NextStep();
            if (Creature* lyessa = instance->GetCreature(_lyessaGUID))
            {
                lyessa->GetScheduler().Schedule(Milliseconds(2000), [lyessa](TaskContext context)
                {
                    lyessa->Say(108566);
                });
                lyessa->GetScheduler().Schedule(Milliseconds(4000), [lyessa](TaskContext context)
                {
                    lyessa->Say(108567);
                });
            }
            //
            //    107222 ?????????????! man
            //    108260 ???????,?????????????!female

            //    107280 ??????????????
            //    108261 ?,??!?????????????!

            //108566 ????!??????!????????!
            //108567 ??,????????!????????!
            //https://cn.wowhead.com/spell=207544 ?? on 104726
        }
        else if (type == DATA_STAGE_5 && data == DONE)
        {
            NextStep();
            instance->SummonGameObject(248499, Position(5474.0f, -3501.37f, 1557.3f), QuaternionData(), WEEK);
        }
        else if (type == DATA_STAGE_6 && data == DONE)
        {
            if (Creature* hamuul = instance->GetCreature(_hamuulGUID))
                    hamuul->Say(108260);

            if (Creature* destromath = instance->GetCreature(_destromathGUID))
                destromath->Say(107280);
            if (Creature* lyessa = instance->GetCreature(_lyessaGUID))
                lyessa->Say(108261);
            NextStep();
            DoPlayScenePackageIdOnPlayers(DRUID_RESTO_ACQUISTION_ARTIFACT_LOOTED_SCENE);
            DoCastSpellOnPlayers(207582);
        }
        else if (type == DATA_STAGE_7 && data == DONE)
        {
            if (Creature* destromath = instance->GetCreature(_destromathGUID))
                destromath->AI()->DoAction(1);
            NextStep();

            if (Creature* lyessa = instance->GetCreature(_lyessaGUID))
                lyessa->Say(107309);

            if (Creature* hamuul = instance->GetCreature(_hamuulGUID))
            {
                hamuul->GetScheduler().Schedule(Milliseconds(2000), [hamuul](TaskContext context)
                {
                    hamuul->Say(107310);
                });
                hamuul->GetScheduler().Schedule(Milliseconds(4000), [hamuul](TaskContext context)
                {
                    hamuul->Say(107311);
                });

            }
        }
    }


private:
    bool isComplete;
    ObjectGuid _omnuronGUID;
    ObjectGuid _zentabraGUID;
    ObjectGuid _cothGUID;
    ObjectGuid _hamuulGUID;
    ObjectGuid _lyessaGUID;
    ObjectGuid _destromathGUID;
    ObjectGuid m_playerGUID;
    uint8 StepID;
    uint8 stage2count;
};

struct npc_skylord_omnuron_104620 : public ScriptedAI
{
    npc_skylord_omnuron_104620(Creature* creature) : ScriptedAI(creature) { Initialize(); }

    void DoAction(int32 param)
    {
        switch (param)
        {
        case 1:
            me->RemoveAura(68442);
            me->Say(107102);//"The gates of hell descended upon us. They were everywhere..."

            me->GetScheduler().Schedule(Milliseconds(2000), [this](TaskContext context)
            {
                me->Say(107103);//"The other's wounds are more severe than my own. They are in dire need of aid."
            });
            ///delay 2s next step
            me->GetScheduler().Schedule(Milliseconds(4000), [this](TaskContext context)
            {
                instance->SetData(DATA_STAGE_1, DONE);
            });
            break;
        }
    }

    void Initialize()
    {
        instance = me->GetInstanceScript();
    }

    void sGossipSelect(Player* player, uint32 /*menuId*/, uint32 /*gossipListId*/)
    {
        CloseGossipMenuFor(player);
        DoAction(1);
    }
private:
    InstanceScript * instance;
};

struct npc_zen_tabra_104658 : public ScriptedAI
{
    npc_zen_tabra_104658(Creature* creature) : ScriptedAI(creature) { Initialize(); }

    void DoAction(int32 param)
    {
        switch (param)
        {
        case 1:///save me
            ishaveaura = false;
            instance->SetData(DATA_STAGE_2, DONE);
            me->Say(107120);//"Bless ya, $n - I could feel my soul returnin' to the loa.", LANG_UNIVERSAL
            if (Creature* lyessa = me->FindNearestCreature(NPC_LYESSA_BLOOMWATCHER_104628, 50.0f, true))
            {
                me->GetMotionMaster()->MoveCloserAndStop(1, lyessa, 10.0f);
            }
            break;
        }
    }

    void Initialize()
    {
        instance = me->GetInstanceScript();
        ishaveaura = true;
    }

    void UpdateAI(uint32 diff) override
    {
        _scheduler.Update(diff);
        //save me
        if (ishaveaura && !me->HasAura(207117))
            DoAction(1);

        if (!UpdateVictim())
            return;

        DoMeleeAttackIfReady();
    }
private:
    bool ishaveaura;
    InstanceScript * instance;
    TaskScheduler _scheduler;
};

struct npc_celestine_of_the_harvest_104657 : public ScriptedAI
{
    npc_celestine_of_the_harvest_104657(Creature* creature) : ScriptedAI(creature) { Initialize(); }

    void DoAction(int32 param)
    {
        switch (param)
        {
        case 1:///save me
            issaved = true;
            instance->SetData(DATA_STAGE_2, DONE);
            me->RemoveAura(68442);
            me->Say(107116);//"The well was nearly lost during the assault,but so long as a single drop remains there is hope!", LANG_UNIVERSAL

            if (Creature* lyessa = me->FindNearestCreature(NPC_LYESSA_BLOOMWATCHER_104628, 150.0f, true))
            {
                me->GetMotionMaster()->MoveCloserAndStop(1, lyessa, 10.0f);
            }
            break;
        case 2:
            isstart = true;
            break;
        }
    }

    void Initialize()
    {
        instance = me->GetInstanceScript();
        sayhelp = false;
        issaved = false;
        isstart = false;
        me->SetHealth(me->GetMaxHealth()*0.15f);
        me->CastSpell(me, 207106, true);
    }

    void UpdateAI(uint32 diff) override
    {
        _scheduler.Update(diff);
        if (isstart && !issaved)
        {
            if (HealthAbovePct(16) && me->HasAura(207106))
                me->RemoveAura(207106);
            if (HealthAbovePct(95) && !me->HasAura(207106))
                DoAction(1);
        }


        if (!UpdateVictim())
            return;

        DoMeleeAttackIfReady();
    }

    void MoveInLineOfSight(Unit* who) override
    {
        if (!who || !who->IsInWorld() || !me->IsWithinDist(who, 15.0f, false))
            return;

        Player* player = who->GetCharmerOrOwnerPlayerOrPlayerItself();
        if (!player)
            return;
        if (!sayhelp && HealthBelowPct(20))
        {
            sayhelp = true;
            me->Say(107114);//"Oh, my head...I feel dizzy...", LANG_UNIVERSAL
        }

    }
private:
    InstanceScript * instance;
    TaskScheduler _scheduler;
    bool sayhelp;
    bool issaved;
    bool isstart;
};

struct npc_archdruid_hamuul_runetotem_104659 : public ScriptedAI
{
    npc_archdruid_hamuul_runetotem_104659(Creature* creature) : ScriptedAI(creature) { Initialize(); }

    void DoAction(int32 param)
    {
        switch (param)
        {
        case 1:///save me
            issaved = true;
            instance->SetData(DATA_STAGE_2, DONE);
            me->RemoveAura(68442);
            me->Say(107115);//"The Legion has not forgotten their defeat here.", LANG_UNIVERSAL

            if (Creature* lyessa = me->FindNearestCreature(NPC_LYESSA_BLOOMWATCHER_104628, 150.0f, true))
            {
                me->GetMotionMaster()->MoveCloserAndStop(1, lyessa, 10.0f);
            }
            break;
        case 2:
            isstart = true;
            break;
        }
    }

    void Initialize()
    {
        instance = me->GetInstanceScript();
        sayhelp = false;
        issaved = false;
        isstart = false;
        me->SetHealth(me->GetMaxHealth()*0.15f);
        me->CastSpell(me, 207106, true);
    }

    void UpdateAI(uint32 diff) override
    {
        _scheduler.Update(diff);
        if (isstart && !issaved)
        {
            if (HealthAbovePct(16) && me->HasAura(207106))
                me->RemoveAura(207106);
            if (HealthAbovePct(95) && !me->HasAura(207106))
                DoAction(1);
        }

        if (!UpdateVictim())
            return;

        DoMeleeAttackIfReady();
    }

    void MoveInLineOfSight(Unit* who) override
    {
        if (!who || !who->IsInWorld() || !me->IsWithinDist(who, 15.0f, false))
            return;

        Player* player = who->GetCharmerOrOwnerPlayerOrPlayerItself();
        if (!player)
            return;
        if (!sayhelp && HealthAbovePct(25) && HealthBelowPct(60))
        {
            sayhelp = true;
            me->Say(107111);//"Thank you, Shan'do. We barely made it out of their last attack.", LANG_UNIVERSAL
        }
    }
private:
    InstanceScript * instance;
    TaskScheduler _scheduler;
    bool sayhelp;
    bool issaved;
    bool isstart;
};

struct npc_lyessa_bloomwatcher_104628 : public ScriptedAI
{
    npc_lyessa_bloomwatcher_104628(Creature* creature) : ScriptedAI(creature) { Initialize(); }

    void DoAction(int32 param)
    {
        switch (param)
        {
        case 1:
            me->Say(107104);
            me->GetMotionMaster()->MovePoint(1, Position(5475.65f, -3488.561f, 1555.676f), true);
            me->GetScheduler().Schedule(Milliseconds(3000), [this](TaskContext context)
            {
                me->Say(107129);
            });
            break;
        case 2:
            me->GetScheduler().Schedule(Milliseconds(2000), [this](TaskContext context)
            {
                me->Say(107147);//"I will use the well's power to absorb G'Hair's corruption into my body."
            });
            me->GetScheduler().Schedule(Milliseconds(4000), [this](TaskContext context)
            {
                me->CastSpell(me, 115790, true);
                me->GetMotionMaster()->MovePoint(2, Position(5474.202f, -3500.13f, 1554.453f));
                me->AddNpcFlag(UNIT_NPC_FLAG_SPELLCLICK);
            });
            break;
        }
    }

    void Initialize()
    {
        instance = me->GetInstanceScript();
    }

    void OnSpellClick(Unit* clicker, bool& /*result*/)
    {
        if (Player* player = clicker->ToPlayer())
        {
            //remove spellclick
            me->AddNpcFlag(UNIT_NPC_FLAG_NONE);

            if (instance->GetData(DATA_STAGE_3) == NOT_STARTED)
            {
                player->CastSpell(me, 207158, true);

                instance->SetData(DATA_STAGE_3, DONE);
                ///ID - 28892 Nature Channeling ID - 207215 Ritual of Cleansing
                me->CastSpell(me, 207215, true);
                me->GetScheduler().Schedule(Milliseconds(3000), [this](TaskContext context)
                {
                    me->Say(107148);///"You must restore my body while I fight the darkness within my soul. Only then will theritual complete!."
                });
                me->GetScheduler().Schedule(Milliseconds(180000), [this](TaskContext context)
                {
                    instance->SetData(DATA_STAGE_4, DONE);
                    //add spellclick
                    me->AddNpcFlag(UNIT_NPC_FLAG_SPELLCLICK);
                });
            }
            else if(instance->GetData(DATA_STAGE_4) == DONE && instance->GetData(DATA_STAGE_5) == NOT_STARTED)
            {
                player->CastSpell(me, 207158, true);
                instance->SetData(DATA_STAGE_5, DONE);
            }
        }
    }
private:
    InstanceScript * instance;
};

enum
{
    SPELL_FEL_FIRESTORM = 208731,
    SPELL_FEL_SLIME =209020,
    SPELL_GRIP_OF_THE_LEGION = 208733,
    SPELL_TREMBLING_STOMP = 208730,
};

struct npc_destromath_104619 : public BossAI
{
    npc_destromath_104619(Creature* creature) : BossAI(creature, DATA_RESTOACQUSITON) { Initialize(); }

    void Reset() override
    {
        BossAI::Reset();
    }

    void EnterCombat(Unit* /*who*/) override
    {
        me->Say("In Mannoroth's name!", LANG_UNIVERSAL);
    }

    void Initialize()
    {
        instance = me->GetInstanceScript();
        m_playerGUID = ObjectGuid::Empty;
    }

    void ScheduleTasks() override
    {
        events.ScheduleEvent(SPELL_TREMBLING_STOMP, 10s);
        events.ScheduleEvent(SPELL_GRIP_OF_THE_LEGION, 20s);
        events.ScheduleEvent(SPELL_FEL_FIRESTORM, 10s, 20s);
        events.ScheduleEvent(SPELL_FEL_SLIME, 12s);
    }

    void DoAction(int32 param)
    {
        switch (param)
        {
        case 1:
            me->Say(107307);
            DoCastSelf(207656);
            DoCastSelf(207652);
            me->Say(107308);
            break;
        }
    }

    void ExecuteEvent(uint32 eventId) override
    {
        switch (eventId)
        {
        case SPELL_TREMBLING_STOMP:
        {
            DoCast(SPELL_TREMBLING_STOMP);
            events.Repeat(10s);
            break;
        }
        case SPELL_GRIP_OF_THE_LEGION:
        {
            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 1))
                DoCast(target, SPELL_GRIP_OF_THE_LEGION);
            events.Repeat(20s);

            break;
        }
        case SPELL_FEL_FIRESTORM:
        {
            DoCast(SPELL_FEL_FIRESTORM);
            events.Repeat(10s, 20s);
            break;
        }
        case SPELL_FEL_SLIME:
        {
            DoCast(SPELL_FEL_SLIME);
            events.Repeat(12s);
            break;
        }
        default:
            break;
        }
    }

    void SummonMob(uint16 count)
    {
        me->GetScheduler().Schedule(1s, 2s, [this, count](TaskContext context)
        {
            Position pos;
            GetRandPosFromCenterInDist(me, 30.f, pos);
            pos.m_positionZ = 20.0f;

            me->SummonCreature(NPC_SKYLORD_OMNURON_104620, pos);

            if (context.GetRepeatCounter() <= count)
                context.Repeat(1s, 2s);
        });
    }

    void MoveInLineOfSight(Unit* who) override
    {
        if (!who || !who->IsInWorld() || !me->IsWithinDist(who, 15.0f, false))
            return;

        Player* player = who->GetCharmerOrOwnerPlayerOrPlayerItself();
        if (!player)
            return;
        m_playerGUID = player->GetGUID();
    }
private:
    InstanceScript * instance;
    ObjectGuid   m_playerGUID;
};

///248499
class go_g_hanir_1 : public GameObjectScript
{
public:
    go_g_hanir_1() : GameObjectScript("go_g_hanir_1") { isloot = false; }

    void OnLootStateChanged(GameObject* go, uint32 state, Unit* unit)
    {
        if (state == GO_ACTIVATED && unit && !isloot)
        {
            isloot = true;
            if (InstanceScript * instance = go->GetInstanceScript())
                instance->SetData(DATA_STAGE_6, DONE);
        }
    }
    bool isloot;
};

class playerscript_call_of_mother_tree : public PlayerScript {
public:
    playerscript_call_of_mother_tree() : PlayerScript("playerscript_call_of_mother_tree") {}

    void OnSuccessfulSpellCast(Player* player, Spell* spell)
    {
        if (spell->GetSpellInfo()->Id == 207583)
        {
            if (InstanceScript * instance = player->GetInstanceScript())
                instance->SetData(DATA_STAGE_7, DONE);
            player->ForceCompleteQuest(QUEST_CLEANSING_THE_MOTHER_TREE);
            //player->AddDelayedTeleport(2000, 1536, -12408.0f, -12955.2f, 320.26f, 4.427202f);
        }
    }
};

void AddSC_scenario_artifact_restoacqusition()
{
    RegisterInstanceScript(scenario_artifact_restoacqusition, 1599);

    RegisterCreatureAI(npc_skylord_omnuron_104620);
    RegisterCreatureAI(npc_zen_tabra_104658);
    RegisterCreatureAI(npc_celestine_of_the_harvest_104657);
    RegisterCreatureAI(npc_archdruid_hamuul_runetotem_104659);
    RegisterCreatureAI(npc_lyessa_bloomwatcher_104628);
    RegisterCreatureAI(npc_destromath_104619);
    new go_g_hanir_1();
    new playerscript_call_of_mother_tree();
}
