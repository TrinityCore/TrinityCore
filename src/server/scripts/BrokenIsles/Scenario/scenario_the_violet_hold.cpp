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

 /*scenario_the_violet_hold*/
#include "GameObject.h"
#include "PhasingHandler.h"
#include "Log.h"
enum StepID
{
    STEP_0 = 2175,
    STEP_1 = 2176,
    STEP_2 = 2177,
    STEP_3 = 2178,
    STEP_4 = 2181,
    STEP_5 = 2179,
};

enum
{
    NPC_KATHRA_NATIR_102785 = 102785,
    NPC_MERYL_FELSTORM_102850 = 102850,
    NPC_SIPHONING_RIFT_102787 = 102787,
    NPC_FORGE_OF_THE_GUARDIAN_447175 = 447175,
    NPC_ALODI = 102846,
    PLAYER_GUID = 0,
    TALK_INTRO = 0,
    EVENT_INTRO = 1,
    EVENT_ATTACK_1 = 2,
    EVENT_ATTACK_2 = 3,
    EVENT_PART2 = 4,
    EVENT_PART3 = 5,
    EVENT_PART4 = 6,
    EVENT_MOVE_TO = 7,
    EVENT_MOVE_TO_POSITION = 8,

    EVENT_FORGE_OF_THE_GUARDIAN_1 = 1,
    EVENT_FORGE_OF_THE_GUARDIAN_2 = 2,

    SPELL_CONVERSATION_KATHRA_FIGHT1 = 205450,
    SPELL_CONVERSATION_KATHRA_FIGHT2 = 205451,
    SPELL_CONVERSATION_KATHRA_FIGHT3 = 205452,
    SPELL_CONVERSATION_KATHRA_FIGHT4 = 205453,
    ///205453 1421 ?????????
    SPELL_CONVERSATION_KATHRA_FIGHT5 = 205454,
    SPELL_CONVERSATION_KATHRA_FIGHT6 = 203444,
    SPELL_CONVERSATION_KATHRA_FIGHT7 = 205455,//death

    SPELL_CONVERSATION_MERYL_1 = 203265,
    SPELL_CONVERSATION_PART_3 = 203422,

    SPELL_MARK_OF_THE_GUARDIAN = 203363,

    SPELL_ATTACK_KATHRA_DRAIN_LIFE = 207639,
    SPELL_ATTACK_MERYL_1 = 227382,
    SPELL_ATTACK_MERYL_2 = 211581,

    SPELL_ATTACK_MERYL_3 = 211589,
    GO_PRISON_SEAL = 105772,
};

struct scenario_the_violet_hold : public InstanceScript
{
    scenario_the_violet_hold(InstanceMap* map) : InstanceScript(map) { Initialize(); }

    void Initialize() override
    {
        KillCount = 0;
        m_meryl_felstormGUID = ObjectGuid::Empty;
        m_kathra_natirGUID = ObjectGuid::Empty;
        m_forge_of_the_guardianGUID = ObjectGuid::Empty;
        m_alodiGUID = ObjectGuid::Empty;
    }

    void OnPlayerEnter(Player* player) override
    {
        instance->SetDifficultyID(DIFFICULTY_3_MAN_SCENARIO_N);

        TC_LOG_ERROR("scripts", "DoSendDiffcultyOnPlayers SendDungeonDifficulty %s", player->GetName().c_str());
        player->SendDungeonDifficulty(DIFFICULTY_3_MAN_SCENARIO_N);
    }

    void OnCreatureCreate(Creature* creature) override
    {
        InstanceScript::OnCreatureCreate(creature);
        switch (creature->GetEntry())
        {
        case NPC_MERYL_FELSTORM_102850:
            m_meryl_felstormGUID = creature->GetGUID();
            break;
        case NPC_KATHRA_NATIR_102785:
            m_kathra_natirGUID = creature->GetGUID();
            break;
        case NPC_FORGE_OF_THE_GUARDIAN_447175:
            m_forge_of_the_guardianGUID = creature->GetGUID();
            break;
        case NPC_ALODI:
            m_alodiGUID = creature->GetGUID();
            break;
        }
    }

    void OnGameObjectCreate(GameObject* go) override
    {
        InstanceScript::OnGameObjectCreate(go);
        /*
        switch (go->GetEntry())
        {
        case GO_PRISON_SEAL:
            m_prison_sealGUID = go->GetGUID();
            break;
        }*/
    }


    void OnUnitDeath(Unit* who)
    {
        if (who->GetEntry() == NPC_SIPHONING_RIFT_102787)
        {
            KillCount++;
            if (KillCount >= needKillCount)
            {
                //SendScenarioState(ScenarioData(1034, STEP_2));
                if (Creature* guardian = instance->GetCreature(m_forge_of_the_guardianGUID))
                {
                    guardian->AI()->DoAction(EVENT_FORGE_OF_THE_GUARDIAN_1);
                }
                DoCastSpellOnPlayers(203421);
            }
        }


        if (who->GetEntry() == NPC_KATHRA_NATIR_102785)
        {
            DoCastSpellOnPlayers(SPELL_CONVERSATION_KATHRA_FIGHT7);///to do
            DoCastSpellOnPlayers(203446);
            DoCastSpellOnPlayers(205456);
            /*
            Map::PlayerList const &PlayerList = instance->GetPlayers();

            if (!PlayerList.isEmpty())
            {
                for (Map::PlayerList::const_iterator i = PlayerList.begin(); i != PlayerList.end(); ++i)
                {
                    if (Player* player = i->GetSource())
                    {
                        PhasingHandler::AddPhase(player, 5847, true);
                    }
                }
            }
            */
           // DoDelayedConversation(4000, 1359);
            ///player 203458 clear buff
            DoCastSpellOnPlayers(203458);
            DoCastSpellOnPlayers(203461);



            if (Creature* meryl = instance->GetCreature(m_meryl_felstormGUID))
            {
                //PhasingHandler::AddPhase(meryl, 5847, true);
                meryl->AI()->DoAction(EVENT_PART4);
                ///Do Talk to meryl event
                ///1359,

            }
            if (Creature* guardian = instance->GetCreature(m_forge_of_the_guardianGUID))
            {
                //PhasingHandler::RemovePhase(guardian, 5847, true);
                guardian->AI()->DoAction(EVENT_FORGE_OF_THE_GUARDIAN_2);
                ///Do Talk to meryl event
            }
            if (Creature* alodi = instance->GetCreature(m_alodiGUID))
            {
                //PhasingHandler::ResetPhaseShift(alodi);
                alodi->AI()->DoAction(EVENT_PART4);
                ///Do Talk to meryl event
            }
            //SendScenarioState(ScenarioData(1034, STEP_4));///

        }
    }
    int32 needKillCount = 4;
    int32 KillCount;
    ObjectGuid m_meryl_felstormGUID;
    ObjectGuid m_kathra_natirGUID;
    ObjectGuid m_forge_of_the_guardianGUID;
    ObjectGuid m_prison_sealGUID;
    ObjectGuid m_alodiGUID;
};



struct npc_kathra_natir_102785 : public ScriptedAI
{
    npc_kathra_natir_102785(Creature* creature) : ScriptedAI(creature) { Step2 = false; }

    void Reset() override
    {
        m_playerGUID = ObjectGuid::Empty;
        m_meryl_felstormGUID = ObjectGuid::Empty;
        Step2 = false;
    }
    void SetGUID(ObjectGuid guid, int32 id = 0) override
    {
        switch (id)
        {
        case PLAYER_GUID:
        {
            m_playerGUID = guid;
            break;
        }
        case NPC_MERYL_FELSTORM_102850:
        {
            m_meryl_felstormGUID = guid;
            break;
        }
        }
    }

    ///on death kill 102785
    void DamageTaken(Unit* /*attacker*/, uint32& /*damage*/) override
    {
        if (me->GetHealthPct() < 90.0f && !Step2)
        {
            Step2 = true;
            DoAction(EVENT_PART2);
        }
    }
    //in com 1419
    void EnterCombat(Unit* /*victim*/)
    {
        if (Player* player = ObjectAccessor::GetPlayer(*me, m_playerGUID))
            player->CastSpell(player, SPELL_CONVERSATION_KATHRA_FIGHT2, true);

        if (Creature* meryl = ObjectAccessor::GetCreature(*me, m_meryl_felstormGUID))
            meryl->AI()->DoAction(EVENT_ATTACK_1);
        //105772
        //if (GameObject *prisonseal = me->FindNearestGameObject(105772, 100.0f))
        //me->FindNearestGameObject(105772, 100.0f)->SetGoState( GO_STATE_READY);//GOState
        //if (GameObject* ps = me->FindNearestGameObject(GO_PRISON_SEAL, 100.0f))
        //{
        //    ps->SetGoState(GO_STATE_READY);
        //}
        me->AddAura(207647);
        events.ScheduleEvent(EVENT_ATTACK_2, 5000);
        events.ScheduleEvent(EVENT_ATTACK_1, 2000);

    }
    void DoAction(int32 param) override
    {
        switch (param)
        {
        case TALK_INTRO:
        {
            Player* player = me->SelectNearestPlayer(100.0f);
            SetGUID(player->GetGUID(), PLAYER_GUID);
            if (Creature* marker = me->FindNearestCreature(NPC_MERYL_FELSTORM_102850, 100.0f))
            {
                SetGUID(marker->GetGUID(), NPC_MERYL_FELSTORM_102850);
                me->SetFacingToObject(marker);
            }

            events.ScheduleEvent(EVENT_INTRO, 1000);
            break;
        }
        case EVENT_PART2:

            events.ScheduleEvent(EVENT_PART2, 1000);
            break;
        case EVENT_PART3:
            //events.Reset();
            events.ScheduleEvent(EVENT_PART3, 10000);
            break;
        case EVENT_PART4:
            //events.Reset();
            //events.ScheduleEvent(EVENT_ATTACK_1, 1000);
            //events.ScheduleEvent(EVENT_ATTACK_2, 1000);
            break;

        }
    }
    void UpdateAI(uint32 diff) override
    {
        events.Update(diff);

        while (uint32 eventId = events.ExecuteEvent())
        {
            switch (eventId)
            {
            case EVENT_INTRO:
                //Talk(TALK_INTRO); //1418
                if (Player* player = ObjectAccessor::GetPlayer(*me, m_playerGUID))
                    player->CastSpell(player, SPELL_CONVERSATION_KATHRA_FIGHT1, true);
                break;
            case EVENT_ATTACK_1:
                if (Player* player = ObjectAccessor::GetPlayer(*me, m_playerGUID))
                {
                    DoSpellAttackIfReady(SPELL_ATTACK_KATHRA_DRAIN_LIFE);
                    events.Repeat(7500, 12500);
                }
                break;
            case EVENT_ATTACK_2:
                if (Player* player = ObjectAccessor::GetPlayer(*me, m_playerGUID))
                    player->CastSpell(player, SPELL_CONVERSATION_KATHRA_FIGHT3, true);
                break;
            case EVENT_PART2:
                /*if (InstanceScript* l_InstanceScript = me->GetInstanceScript())
                {
                    l_InstanceScript->SendScenarioState(InstanceScript::ScenarioData(1034, STEP_1));
                }*/
                if (Creature* meryl = ObjectAccessor::GetCreature(*me, m_meryl_felstormGUID))
                    meryl->AI()->DoAction(EVENT_PART2);


                //if (Player* player = ObjectAccessor::GetPlayer(*me, m_playerGUID))
                //    player->CastSpell(player, SPELL_CONVERSATION_KATHRA_FIGHT4, true);

                break;
            case EVENT_PART3:
                me->RemoveAurasDueToSpell(SPELL_ATTACK_MERYL_3);
                if (Player* player = ObjectAccessor::GetPlayer(*me, m_playerGUID))
                {
                    player->CastSpell(player, SPELL_CONVERSATION_KATHRA_FIGHT5, true);
                    player->AddDelayedConversation(1000, 1255);
                }

                if (Creature* meryl = ObjectAccessor::GetCreature(*me, m_meryl_felstormGUID))
                {
                    meryl->CastSpell(meryl, 203440);
                    //meryl->GetInstanceScript()->DoDelayedConversation(1000, 1255);

                }
                ///203440 ON MEYL

                ///82238 update phase??
                ///203390 buff on player
                ///spell conversation 1255
                break;

            }
        }
        if (!UpdateVictim())
            return;
        else
            DoMeleeAttackIfReady();
    }
private:
    EventMap events;
    ObjectGuid m_playerGUID;
    ObjectGuid m_meryl_felstormGUID;
    bool Step2;
};


struct npc_meryl_felstorm_102850 : public ScriptedAI
{
    npc_meryl_felstorm_102850(Creature* creature) : ScriptedAI(creature) { Intro = false; FirstMove = false; }

    void Reset() override
    {
        m_playerGUID = ObjectGuid::Empty;
        m_kathra_natirGUID = ObjectGuid::Empty;
        //Intro = false;
        //FirstMove = false;
    }
    void SetGUID(ObjectGuid guid, int32 id = 0) override
    {
        switch (id)
        {
        case PLAYER_GUID:
        {
            m_playerGUID = guid;
            break;
        }
        case NPC_KATHRA_NATIR_102785:
        {
            m_kathra_natirGUID = guid;
            break;
        }
        }
    }
    enum {
        DELAY_EVENT_1 =10,
        DELAY_EVENT_2 =11,
    };
    void MoveInLineOfSight(Unit* who) override
    {
        if (!who || !who->IsInWorld())
            return;
        Player* player = who->GetCharmerOrOwnerPlayerOrPlayerItself();

        if (!me->IsWithinDist(who, 20.0f, false))
        {
            return;
        }

        if (!player)
        {
            switch (who->GetEntry())
            {
            case NPC_KATHRA_NATIR_102785:
                SetGUID(who->GetGUID(), NPC_KATHRA_NATIR_102785);
                if (!Intro)
                {
                    Intro = true;
                    Talk(TALK_INTRO);
                    who->GetAI()->DoAction(TALK_INTRO);
                }

                break;
            default:
                break;
            }
        }
        else
        {
            SetGUID(player->GetGUID(), PLAYER_GUID);
            if (!FirstMove)
            {
                FirstMove = true;
                Position fistpos = { 1303.22f, -264.677f, 44.3579f, 0.1396263f };
                //me->GetMotionMaster()->MovePoint(1, fistpos);
                /*if (InstanceScript* l_InstanceScript = me->GetInstanceScript())
                {
                    l_InstanceScript->SendScenarioState(InstanceScript::ScenarioData(1034, STEP_0));
                }*/
                me->GetMotionMaster()->MovePoint(1, Position(1302.7479f, -264.6903f, 44.3579f, 0.02832f));
                //me->GetMotionMaster()->MovePoint(1, me->GetNearPosition(30.0f, 0.0f));

            }
        }

    }

    void DoAction(int32 param) override
    {
        switch (param)
        {
        case EVENT_ATTACK_1:
            events.ScheduleEvent(EVENT_ATTACK_1, 1000);
            //events.ScheduleEvent(EVENT_ATTACK_2, 10000);
            break;
        case EVENT_PART2:
            events.ScheduleEvent(EVENT_PART2, 500);
            events.ScheduleEvent(DELAY_EVENT_1, 10000);
            events.ScheduleEvent(DELAY_EVENT_2, 12000);
            break;
        case EVENT_PART3:
            //events.Reset();
            break;
        case EVENT_PART4:
            events.ScheduleEvent(EVENT_PART4, 5000);
            break;
        case EVENT_MOVE_TO:
            events.ScheduleEvent(EVENT_MOVE_TO, 5000);
            break;
        case EVENT_MOVE_TO_POSITION:
            events.ScheduleEvent(EVENT_MOVE_TO_POSITION, 7000);
            break;
        }
    }
    void UpdateAI(uint32 diff) override
    {
        events.Update(diff);

        while (uint32 eventId = events.ExecuteEvent())
        {
            switch (eventId)
            {
            case EVENT_ATTACK_1:
                if (Creature* kathra = ObjectAccessor::GetCreature(*me, m_kathra_natirGUID))
                {
                    me->AI()->AttackStart(kathra);
                    if (!UpdateVictim())
                        return;
                    else
                    {
                        if (roll_chance_i(50))
                            DoSpellAttackIfReady(SPELL_ATTACK_MERYL_1);
                        else
                            DoSpellAttackIfReady(SPELL_ATTACK_MERYL_2);
                    }
                }
                events.Repeat(1000);
                break;

            case EVENT_PART2:
                if (Player* player = ObjectAccessor::GetPlayer(*me, m_playerGUID))
                    player->CastSpell(player, SPELL_CONVERSATION_MERYL_1, true);                ///1240

                if (Creature* kathra = ObjectAccessor::GetCreature(*me, m_kathra_natirGUID))
                {
                    DoCast(kathra, SPELL_ATTACK_MERYL_3, true);
                }


                break;
            case DELAY_EVENT_1:
                if (InstanceScript* l_InstanceScript = me->GetInstanceScript())
                {

                    l_InstanceScript->DoCastSpellOnPlayers(SPELL_CONVERSATION_KATHRA_FIGHT4);
                }
                break;
            case DELAY_EVENT_2:
                if (InstanceScript* l_InstanceScript = me->GetInstanceScript())
                {
                    l_InstanceScript->DoPlayConversation(1247);
                }
                break;
            case EVENT_PART3:

                break;
            case EVENT_PART4:
                //me->SetHomePosition(1302.7479f, -264.6903f, 44.2903f, 0.02832f);
                me->RemoveAurasDueToSpell(203440);

                me->CombatStop();
                //me->MovePosition(Position(1302.7479f, -264.6903f, 44.2903f, 0.02832f));
                me->GetMotionMaster()->MovePoint(1, Position(1302.7479f, -264.6903f, 44.2903f, 0.02832f),true);
                me->SetHomePosition(1302.7479f, -264.6903f, 44.2903f, 0.02832f);
                //npc_alodi_102846
                if (!me->FindNearestCreature(NPC_ALODI, 50.0f, true))
                {
                   // if (Creature* alodi = me->SummonCreature(NPC_ALODI, Position(1303.271f, -260.0243f, 44.32788f, 0.02832f), TEMPSUMMON_TIMED_DESPAWN,7200))
                    //{

                   //}
                }
                else
                {
                    if(Creature* alodime=me->FindNearestCreature(NPC_ALODI, 50.0f, true))
                    {

                    }
                }
                if (InstanceScript* l_InstanceScript = me->GetInstanceScript())
                {
                    ///part 5 talk
                    l_InstanceScript->DoCastSpellOnPlayers(203488);
                }

                //events.Repeat(10s);
                DoAction(EVENT_MOVE_TO);
                break;
            case EVENT_MOVE_TO:
                /*if (InstanceScript* l_InstanceScript = me->GetInstanceScript())
                {
                    l_InstanceScript->SendScenarioState(InstanceScript::ScenarioData(1034, STEP_5));
                }*/

                ///move
                me->GetMotionMaster()->MovePoint(1, Position(1327.17f, -266.4983f, 44.3579f), true);
                me->GetMotionMaster()->MovePoint(2, Position(1334.598f, -267.1635f, 39.3824f), true);
                me->GetMotionMaster()->MovePoint(3, Position(1353.75f, -268.8177f, 38.68335f), true);

                if (Creature* alodime = me->FindNearestCreature(NPC_ALODI, 50.0f, true))
                {
                    alodime->GetMotionMaster()->MovePoint(1, Position(1327.106f, -259.3438f, 44.08223f), true);
                    alodime->GetMotionMaster()->MovePoint(2, Position(1334.84f, -258.651f, 39.23363f), true);
                    alodime->GetMotionMaster()->MovePoint(3, Position(1354.2f, -257.8559f, 38.67764f), true);
                }
                break;
            case EVENT_MOVE_TO_POSITION:
                ///alodi 1354.2 -257.8559 38.67764 FaceDirection: 5.445427
                ///cast 205514 talk
                ///cast 182938 action  (NoCaster, Positive)
                if (InstanceScript* l_InstanceScript = me->GetInstanceScript())
                {
                    l_InstanceScript->DoCastSpellOnPlayers(205514);
                }
                DoCast(182938);
                if (Creature* alodime = me->FindNearestCreature(NPC_ALODI, 50.0f, true))
                {
                    alodime->AI()->DoCast(182938);
                }
                events.Repeat(1000);
                break;
            }

        }

    }
private:
    EventMap events;
    ObjectGuid m_playerGUID;
    ObjectGuid m_kathra_natirGUID;
    bool Intro;
    bool FirstMove;
};


///SPELL 211666
struct npc_siphoning_rift_102787 : public ScriptedAI
{
    npc_siphoning_rift_102787(Creature* creature) : ScriptedAI(creature) { }

    void Reset() override
    {

    }
    void MoveInLineOfSight(Unit* who) override
    {
        if (!who || !who->IsInWorld())
            return;
        Player* player = who->GetCharmerOrOwnerPlayerOrPlayerItself();

        if (!me->IsWithinDist(who, 40.0f, false))
        {
            return;
        }
    }
    void UpdateAI(uint32 diff) override
    {
        _scheduler.Update(diff);
        if (!UpdateVictim())
            return;
        else
            DoSpellAttackIfReady(211666);
    }
private:
    TaskScheduler _scheduler;
};
///spell 203356
struct npc_forge_of_the_guardian_102786 : public ScriptedAI
{
    npc_forge_of_the_guardian_102786(Creature* creature) : ScriptedAI(creature) { isFirst = false; }
    ///EVENT_FORGE_OF_THE_GUARDIAN_1
    void DoAction(int32 param) override
    {
        me->RemoveUnitFlag(UnitFlags(UNIT_FLAG_NOT_SELECTABLE));
        switch (param)
        {
        case EVENT_FORGE_OF_THE_GUARDIAN_1:
            isFirst = false;
            me->RemoveAura(203246);
            break;
        case EVENT_FORGE_OF_THE_GUARDIAN_2:
            isFirst = true;
            break;

        }
    }
    void OnSpellClick(Unit* who, bool& /*result*/) override
    {

        if (!who || !who->IsInWorld())
            return;
        if (!who->ToPlayer() || who->ToPlayer()->IsBeingTeleported())
            return;
        Player* player = who->GetCharmerOrOwnerPlayerOrPlayerItself();

        if (!player)
            return;
        TC_LOG_ERROR("server.worldserver", "npc_forge_of_the_guardian_102786 OnSpellClick ");
        if (!isFirst)
        {
            isFirst = true;
            if (InstanceScript* l_InstanceScript = me->GetInstanceScript())
            {
                //l_InstanceScript->SendScenarioState(InstanceScript::ScenarioData(1034, STEP_3));
                l_InstanceScript->DoCastSpellOnPlayers(SPELL_CONVERSATION_PART_3);
                l_InstanceScript->DoCastSpellOnPlayers(203390);///buff

                //l_InstanceScript->DoCastSpellOnPlayers(SPELL_MARK_OF_THE_GUARDIAN);
                //l_InstanceScript->DoCastSpellOnPlayers(88885);
                if (Creature* meryl = me->FindNearestCreature(NPC_MERYL_FELSTORM_102850, 100.0f))
                {
                    meryl->AI()->DoAction(EVENT_PART3);
                }
                if (Creature* kathra = me->FindNearestCreature(NPC_KATHRA_NATIR_102785, 100.0f))
                {
                    kathra->AI()->DoAction(EVENT_PART3);
                }
                me->RemoveAura(203246);
            }
        }
        else
        {
            //killmonistercredit
            player->RemoveAurasDueToSpell(203390);
            player->KilledMonsterCredit(102842);
            ///spellclick 203675 teleto

            player->TeleportTo(1513,  -823.27f, 4693.47f, 939.66f, 6.167819f);
        }
        me->AddUnitFlag(UnitFlags(UNIT_FLAG_IMMUNE_TO_PC | UNIT_FLAG_IMMUNE_TO_NPC | UNIT_FLAG_NOT_SELECTABLE));//| UNIT_FLAG_NOT_SELECTABLE
    }

    void UpdateAI(uint32 diff) override
    {
        _scheduler.Update(diff);
    }
private:
    TaskScheduler _scheduler;
    bool isFirst;
};
///182938

struct npc_alodi_102846 : public ScriptedAI
{
    npc_alodi_102846(Creature* creature) : ScriptedAI(creature) { }

    void Reset() override
    {

    }

    void UpdateAI(uint32 diff) override
    {
        _scheduler.Update(diff);
    }
private:
    TaskScheduler _scheduler;
};



void AddSC_scenario_the_violet_hold()
{
    RegisterInstanceScript(scenario_the_violet_hold, 1494);
    RegisterCreatureAI(npc_kathra_natir_102785);
    RegisterCreatureAI(npc_meryl_felstorm_102850);
    RegisterCreatureAI(npc_siphoning_rift_102787);
    RegisterCreatureAI(npc_forge_of_the_guardian_102786);
    RegisterCreatureAI(npc_alodi_102846);
}
