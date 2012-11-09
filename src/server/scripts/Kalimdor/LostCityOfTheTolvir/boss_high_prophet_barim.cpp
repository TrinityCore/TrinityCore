/*
 * Copyright (C) 2008-2012 TrinityCore <http://www.trinitycore.org/>
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
 
#include"ScriptPCH.h"
#include"WorldPacket.h"
#include"lost_city_of_the_tolvir.h"
#include"ScriptMgr.h"
#include"ScriptedCreature.h"
#include"SpellScript.h"
#include"SpellAuraEffects.h"

enum ScriptTexts
{
    SAY_AGGRO                   = 0,
    SAY_KILL_1                  = 1,
    SAY_REPENTANCE              = 2,
    SAY_KILL_2                  = 3,
    SAY_DEATH                   = 4,
};

enum Spells
{
    SPELL_FIFTY_LASHING         = 82506,
    SPELL_PLAGUE_OF_AGES        = 82622,
    H_SPELL_PLAGUEOF_AGES       = 89997,
    SPELL_REPENTANCE            = 81947,
    SPELL_REPENTANCE_IMMUNE     = 82320,
    SPELL_BLAZE_OF_HEAVENS      = 95248, /* Blaze of Heavens ability */
    SPELL_SOUL_SEVER            = 82255, /* Harbinger of Darkness ability */
    SPELL_HEAVENS_FURY          = 81939,
    H_SPELL_HEAVENS_FURY        = 90040,
    SPELL_HALLOWED_GROUND       = 88814,
    H_SPELL_HALLOWED_GROUND     = 90010,
};

enum Events
{
    EVENT_FIFTY_LASHING         = 0,
    EVENT_PLAGUE_OF_AGES        = 1,
    EVENT_REPENTANCE            = 2,
    EVENT_BLAZE_OF_HEAVENS      = 3,
    EVENT_SOUL_SEVER            = 4,
    EVENT_HEAVENS_FURY          = 5,
    EVENT_HALLOWED_GROUND       = 6,
    EVENT_PHASE_1               = 7,
};

enum SummonIds
{
    NPC_BLAZE_OF_HEAVENS        = 48906,
    NPC_HARBINGER_OF_DARKNESS   = 43927,
};

enum ProphetPhases
{
    PHASE_1                     = 1,  /* Light Phase */
    PHASE_2                     = 2,  /* Darkness Phase */
};

const Position SummonLocations[2] =
{
    /* Blaze of Heavens */
    {-11015.45f, -1288.05f, -10.22f, 4.82f},
    /* Harbinger of Darkness */
    {-11015.45f, -1288.05f, -10.22f, 4.82f},
};

class boss_high_prophet_barim : public CreatureScript
{
public:
    boss_high_prophet_barim() : CreatureScript("boss_high_prophet_barim") { }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new boss_high_prophet_barimAI(creature);
    }
    struct boss_high_prophet_barimAI : public ScriptedAI
    {
        boss_high_prophet_barimAI(Creature* creature) : ScriptedAI(creature), Summons(me)
        {
            instance = creature->GetInstanceScript();
        }

        InstanceScript* instance;
        bool check_in;
        SummonList Summons;
        EventMap events;
        uint32 Phase;

        void Reset()
        {
            events.Reset();
            Summons.DespawnAll();
            Phase = PHASE_1;

            if (instance && (instance->GetData(DATA_HIGH_PROPHET_BARIM_EVENT) != DONE && !check_in))
                instance->SetData(DATA_HIGH_PROPHET_BARIM_EVENT, NOT_STARTED);

            check_in = false;
        }

        void JustDied(Unit* /*Kill*/)
        {
            DoScriptText(SAY_DEATH, me);
            Summons.DespawnAll();
            if (instance)
                instance->SetData(DATA_HIGH_PROPHET_BARIM_EVENT, DONE);
        }

        void KilledUnit(Unit* /*Killed*/)
        {
            DoScriptText(RAND(SAY_KILL_1, SAY_KILL_2), me);
        }

        void EnterCombat(Unit* /*Ent*/)
        {
            DoScriptText(SAY_AGGRO, me);
            DoZoneInCombat();

            if (instance)
                instance->SetData(DATA_HIGH_PROPHET_BARIM_EVENT, IN_PROGRESS);
        }

        void EnterPhase1()
        {
            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0))
                DoCast(me->getVictim(), SPELL_HEAVENS_FURY);
                events.ScheduleEvent(EVENT_HEAVENS_FURY, 4000);

            Creature* BlazeOfHeavens = me->SummonCreature(NPC_BLAZE_OF_HEAVENS, SummonLocations[0], TEMPSUMMON_CORPSE_DESPAWN);
            BlazeOfHeavens->AddThreat(me->getVictim(), 0.0f);
            DoZoneInCombat(BlazeOfHeavens);
        }

        void EnterPhase2()
        {
            DoCast(me, SPELL_HALLOWED_GROUND);
            events.ScheduleEvent(EVENT_HALLOWED_GROUND, 4000);

            DoScriptText(SAY_REPENTANCE, me);
            DoCast(me, SPELL_REPENTANCE_IMMUNE);
            Creature* Harbinger = me->SummonCreature(NPC_HARBINGER_OF_DARKNESS, SummonLocations[1], TEMPSUMMON_CORPSE_DESPAWN);
            Harbinger->AddThreat(me->getVictim(), 0.0f);
            DoZoneInCombat(Harbinger);
        }

        void UpdateAI(const uint32 diff)
        {
            /* No target to kill */
            if (!UpdateVictim())
                return;
            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            events.Update(diff);

            if (Phase == PHASE_1 && !HealthAbovePct(50))
            {
                Phase = PHASE_2;
                EnterPhase2();
            }

            Phase = PHASE_1;

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                    EnterPhase1();

                    case EVENT_FIFTY_LASHING:
                        DoCast(me->getVictim(), SPELL_FIFTY_LASHING);
                        events.ScheduleEvent(EVENT_FIFTY_LASHING, 4000);
                        return;
                    case EVENT_PLAGUE_OF_AGES:
                        if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0))
                            DoCast(target, SPELL_PLAGUE_OF_AGES);
                        events.ScheduleEvent(EVENT_PLAGUE_OF_AGES, 6000);
                        return;
                    default:
                        break;
                }
            }
            DoMeleeAttackIfReady();
        }
     };
};

class npc_blaze_of_heavens: public CreatureScript
{
public:
    npc_blaze_of_heavens() : CreatureScript("npc_blaze_of_heavens") { }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new npc_blaze_of_heavensAI(creature);
    }

    struct npc_blaze_of_heavensAI : public ScriptedAI
    {
        npc_blaze_of_heavensAI(Creature* creature) : ScriptedAI(creature) {}

        EventMap events;

        void Reset()
        {
            events.Reset();
        }

        void EnterCombat(Unit* /*who*/)
        {
            events.ScheduleEvent(EVENT_BLAZE_OF_HEAVENS, 1000);
        }

        void UpdateAI(const uint32 diff)
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
                    case EVENT_BLAZE_OF_HEAVENS:
                        DoCast(me, SPELL_BLAZE_OF_HEAVENS);
                        events.RescheduleEvent(EVENT_BLAZE_OF_HEAVENS, 2000);
                        return;
                }
            }

            DoMeleeAttackIfReady();
        }
    };
};

class npc_harbinger_of_darkness: public CreatureScript
{
public:
    npc_harbinger_of_darkness() : CreatureScript("npc_harbinger_of_darkness") { }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new npc_harbinger_of_darknessAI(creature);
    }

    struct npc_harbinger_of_darknessAI : public ScriptedAI
    {
        npc_harbinger_of_darknessAI(Creature* creature) : ScriptedAI(creature) {}

        EventMap events;

        void Reset()
        {
            events.Reset();
        }

        void EnterCombat(Unit* /*who*/)
        {
            events.ScheduleEvent(EVENT_SOUL_SEVER, 1000);
        }

        void UpdateAI(const uint32 diff)
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
                    case EVENT_SOUL_SEVER:
                        DoCast(me->getVictim(), SPELL_SOUL_SEVER);
                        events.RescheduleEvent(EVENT_SOUL_SEVER, 2000);
                        return;
                }
            }

            DoMeleeAttackIfReady();
        }
    };
};

void AddSC_boss_high_prophet_barim()
{
    new boss_high_prophet_barim();
    new npc_blaze_of_heavens();
    new npc_harbinger_of_darkness();
}