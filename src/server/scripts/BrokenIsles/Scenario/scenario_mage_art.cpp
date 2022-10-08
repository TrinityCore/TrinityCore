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
#include "InstanceScenario.h"
#include "GameObject.h"
#include "ScriptedGossip.h"
#include "PhasingHandler.h"
#include "SceneMgr.h"
#include "ScriptMgr.h"

#include "Log.h"
#include "Scenario.h"
#include "InstanceScenario.h"
#include "GameObject.h"
#include "PhasingHandler.h"
#include "SceneMgr.h"
#include "ScriptMgr.h"

enum
{
    DATA_Nexus     = 0,
    DATA_STAGE_1 = 1,
    DATA_STAGE_2 = 2,
    DATA_STAGE_3 = 3,
    DATA_STAGE_4 = 4,
    DATA_STAGE_5 = 5,
    DATA_STAGE_6 = 6,
    DATA_STAGE_7 = 7,
    DATA_MAX_ENCOUNTERS = 8,
    NORMAL_PHASE = 169,
};

struct scenario_mage_art : public InstanceScript
{
    scenario_mage_art(InstanceMap* map) : InstanceScript(map) {  }

    void Initialize() override
    {
        SetBossNumber(DATA_MAX_ENCOUNTERS);
        SetData(DATA_Nexus, NOT_STARTED);
        for (uint8 i = 1; i < 7; ++i)
            SetData(i, NOT_STARTED);
        StepID = DATA_STAGE_1;
        isComplete = false;
        exorcistsKilled = 0;
        FirstCount = 0;
        m_playerGUID = ObjectGuid::Empty;
    }

    void OnPlayerEnter(Player* player) override
    {
        InstanceScript::OnPlayerEnter(player);
        if (player->GetMapId() == 1583)
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
            ++exorcistsKilled;
            if (exorcistsKilled == 3)
            {
                NextStep();
            }
        }
        else if (type == DATA_STAGE_2 && data == DONE)
        {
            NextStep();
            SummonEcho_of_Aluneth();
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
            void SummonAluneth();
        }
        else if (type == DATA_STAGE_7 && data == DONE)
        {
            NextStep();
            DoPlayScenePackageIdOnPlayers(1259);
        }
    }

    void SummonAluneth()
    {
        GameObject* Aluneth = instance->SummonGameObject(249814, Position(1117.78f, 1048.028f, 314.6193f, 2.096361f), QuaternionData(), 300);
    }

    void SummonEcho_of_Aluneth()
    {
        TempSummon* Aluneth = instance->SummonCreature(106706, Position(4067.734f, 7453.73f, 267.3939f, 3.032354f));
    }

 private:
    EventMap events;
    uint8 StepID;
    bool isComplete;
    ObjectGuid m_playerGUID;
    uint8 FirstCount;
    uint8 exorcistsKilled;
};


class npc_Scion_of_Magic_106702 : public CreatureScript
{
public:
    npc_Scion_of_Magic_106702() : CreatureScript("npc_Scion_of_Magic_106702") { }

    enum eRevenant
    {
        SPELL_Arcane_Orb = 209853,
        SPELL_Dark_Empowerment = 227731,
        SPELL_Void_Consumption = 209315,
        EVENT_Arcane_Orb = 1,
        EVENT_Dark_Empowerment = 2,
        EVENT_Void_Consumption = 3,
    };

    struct npc_Scion_of_Magic_106702_AI : public ScriptedAI
    {
        npc_Scion_of_Magic_106702_AI(Creature* creature) : ScriptedAI(creature) {
            Initialize();
        }

        void Initialize()
        {
            instance = me->GetInstanceScript();
        }

        void Reset() override
        {
            _events.Reset();
            Initialize();
        }

        void JustDied(Unit* /*killer*/) override
        {
            instance->SetData(DATA_STAGE_1, DONE);
        }

        void EnterCombat(Unit* /*who*/) override
        {
            _events.ScheduleEvent(EVENT_Arcane_Orb, 1500);
            _events.ScheduleEvent(EVENT_Dark_Empowerment, 8000);
            _events.ScheduleEvent(EVENT_Void_Consumption, 9000);
        }

        void UpdateAI(uint32 diff) override
        {
            _events.Update(diff);

            while (uint32 eventId = _events.ExecuteEvent())
            {
                switch (eventId)
                {
                case EVENT_Arcane_Orb:
                    DoCastVictim(SPELL_Arcane_Orb);
                    _events.ScheduleEvent(EVENT_Arcane_Orb, urand(6000, 8000));
                    break;
                case EVENT_Dark_Empowerment:
                    DoCastVictim(SPELL_Dark_Empowerment);
                    _events.ScheduleEvent(EVENT_Dark_Empowerment, 5000);
                    break;
                case EVENT_Void_Consumption:
                    DoCastVictim(SPELL_Void_Consumption);
                    _events.ScheduleEvent(EVENT_Void_Consumption, 3000);
                    break;
                default:
                    break;
                }
            }
            if (!UpdateVictim())
                return;
            else
                DoMeleeAttackIfReady();
        }

    private:
        EventMap _events;
        InstanceScript * instance;
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_Scion_of_Magic_106702_AI(creature);
    }
};

class npc_Scion_of_Ice_106701 : public CreatureScript
{
public:
    npc_Scion_of_Ice_106701() : CreatureScript("npc_Scion_of_Ice_106701") { }

    enum eRevenant
    {
        SPELL_Frostbolt = 209851,
        SPELL_Dark_Empowerment = 227731,
        SPELL_Icicle_Barrage = 209846,
        EVENT_Frostbolt = 1,
        EVENT_Dark_Empowerment = 2,
        EVENT_Icicle_Barrage = 3,
    };

    struct npc_Scion_of_Ice_106701_AI : public ScriptedAI
    {
        npc_Scion_of_Ice_106701_AI(Creature* creature) : ScriptedAI(creature) {
            Initialize();
        }

        void Initialize()
        {
            instance = me->GetInstanceScript();
        }

        void Reset() override
        {
            _events.Reset();
            Initialize();
        }

        void JustDied(Unit* /*killer*/) override
        {
            instance->SetData(DATA_STAGE_1, DONE);
        }

        void EnterCombat(Unit* /*who*/) override
        {
            _events.ScheduleEvent(EVENT_Frostbolt, 1500);
            _events.ScheduleEvent(EVENT_Dark_Empowerment, 8000);
            _events.ScheduleEvent(EVENT_Icicle_Barrage, 9000);
        }

        void UpdateAI(uint32 diff) override
        {
            _events.Update(diff);

            while (uint32 eventId = _events.ExecuteEvent())
            {
                switch (eventId)
                {
                case EVENT_Frostbolt:
                    DoCastVictim(SPELL_Frostbolt);
                    _events.ScheduleEvent(EVENT_Frostbolt, urand(6000, 8000));
                    break;
                case EVENT_Dark_Empowerment:
                    DoCastVictim(SPELL_Dark_Empowerment);
                    _events.ScheduleEvent(EVENT_Dark_Empowerment, 5000);
                    break;
                case EVENT_Icicle_Barrage:
                    DoCastVictim(SPELL_Icicle_Barrage);
                    _events.ScheduleEvent(EVENT_Icicle_Barrage, 3000);
                    break;
                default:
                    break;
                }
            }
            if (!UpdateVictim())
                return;
            else
                DoMeleeAttackIfReady();
        }

    private:
        EventMap _events;
        InstanceScript * instance;
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_Scion_of_Ice_106701_AI(creature);
    }
};

class npc_Scion_of_fire_106700 : public CreatureScript
{
public:
    npc_Scion_of_fire_106700() : CreatureScript("npc_Scion_of_fire_106700") { }

    enum eRevenant
    {
        SPELL_Fireball = 209854,
        SPELL_Dark_Empowerment = 227731,
        SPELL_Blaze = 209855,
        EVENT_Frostbolt = 1,
        EVENT_Dark_Empowerment = 2,
        EVENT_Blaze = 3,
    };

    struct npc_Scion_of_fire_106700_AI : public ScriptedAI
    {
        npc_Scion_of_fire_106700_AI(Creature* creature) : ScriptedAI(creature)
        {
            Initialize();
        }

        void Initialize()
        {
            instance = me->GetInstanceScript();
        }

        void Reset() override
        {
            _events.Reset();
            Initialize();
        }

        void JustDied(Unit* /*killer*/) override
        {
            instance->SetData(DATA_STAGE_1, DONE);
        }

        void EnterCombat(Unit* /*who*/) override
        {
            _events.ScheduleEvent(EVENT_Frostbolt, 1500);
            _events.ScheduleEvent(EVENT_Dark_Empowerment, 8000);
            _events.ScheduleEvent(EVENT_Blaze, 9000);
        }

        void UpdateAI(uint32 diff) override
        {
            _events.Update(diff);

            while (uint32 eventId = _events.ExecuteEvent())
            {
                switch (eventId)
                {
                case EVENT_Frostbolt:
                    DoCastVictim(SPELL_Fireball);
                    _events.ScheduleEvent(EVENT_Frostbolt, urand(6000, 8000));
                    break;
                case EVENT_Dark_Empowerment:
                    DoCastVictim(SPELL_Dark_Empowerment);
                    _events.ScheduleEvent(EVENT_Dark_Empowerment, 5000);
                    break;
                case EVENT_Blaze:
                    DoCastVictim(SPELL_Blaze);
                    _events.ScheduleEvent(EVENT_Blaze, 3000);
                    break;
                default:
                    break;
                }
            }
            if (!UpdateVictim())
                return;
            else
                DoMeleeAttackIfReady();
        }

    private:
        EventMap _events;
        InstanceScript * instance;
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_Scion_of_fire_106700_AI(creature);
    }
};

void AddSC_scenario_mage_art()
{
    RegisterInstanceScript(scenario_mage_art, 1583);
    new npc_Scion_of_Magic_106702();
    new npc_Scion_of_fire_106700();
    new npc_Scion_of_Ice_106701();
}
