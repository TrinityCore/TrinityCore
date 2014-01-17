/*
 * Copyright (C) 2008-2014 TrinityCore <http://www.trinitycore.org/>
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

#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "razorfen_downs.h"

enum Say
{
    SAY_AGGRO               = 0,
    SAY_SUMMON60            = 1,
    SAY_SUMMON30            = 2,
    SAY_HP                  = 3,
    SAY_KILL                = 4
};

enum Spells
{
    SPELL_AMNENNARSWRATH    = 13009,
    SPELL_FROSTBOLT         = 15530,
    SPELL_FROST_NOVA        = 15531,
    SPELL_FROST_SPECTRES    = 12642
};

enum Events
{
    EVENT_AMNENNARSWRATH    = 1,
    EVENT_FROSTBOLT         = 2,
    EVENT_FROST_NOVA        = 3
};

class boss_amnennar_the_coldbringer : public CreatureScript
{
public:
    boss_amnennar_the_coldbringer() : CreatureScript("boss_amnennar_the_coldbringer") { }

    struct boss_amnennar_the_coldbringerAI : public BossAI
    {
        boss_amnennar_the_coldbringerAI(Creature* creature) : BossAI(creature, DATA_AMNENNAR_THE_COLD_BRINGER) { }

        void Reset() OVERRIDE
        {
            _Reset();
            hp60Spectrals = false;
            hp30Spectrals = false;
            hp50          = false;
        }

        void EnterCombat(Unit* /*who*/) OVERRIDE
        {
            _EnterCombat();
            events.ScheduleEvent(EVENT_AMNENNARSWRATH, 8000);
            events.ScheduleEvent(EVENT_FROSTBOLT, 1000);
            events.ScheduleEvent(EVENT_FROST_NOVA, urand(10000, 15000));
            Talk(SAY_AGGRO);
        }

        void KilledUnit(Unit* who) OVERRIDE
        {
            if (who->GetTypeId() == TYPEID_PLAYER)
                Talk(SAY_KILL);
        }

        void JustDied(Unit* /*killer*/) OVERRIDE
        {
            _JustDied();
        }

        void UpdateAI(uint32 diff) OVERRIDE
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
                    case EVENT_AMNENNARSWRATH:
                        DoCastVictim(SPELL_AMNENNARSWRATH);
                        events.ScheduleEvent(EVENT_AMNENNARSWRATH, 12000);
                        break;
                    case EVENT_FROSTBOLT:
                        DoCastVictim(SPELL_FROSTBOLT);
                        events.ScheduleEvent(EVENT_FROSTBOLT, 8000);
                        break;
                    case EVENT_FROST_NOVA:
                        DoCast(me, SPELL_FROST_NOVA);
                        events.ScheduleEvent(EVENT_FROST_NOVA, 15000);
                        break;
                }
            }

            if (!hp60Spectrals && HealthBelowPct(60))
            {
                Talk(SAY_SUMMON60);
                DoCastVictim(SPELL_FROST_SPECTRES);
                hp60Spectrals = true;
            }

            if (!hp50 && HealthBelowPct(50))
            {
                Talk(SAY_HP);
                hp50 = true;
            }

            if (!hp30Spectrals && HealthBelowPct(30))
            {
                Talk(SAY_SUMMON30);
                DoCastVictim(SPELL_FROST_SPECTRES);
                hp30Spectrals = true;
            }

            DoMeleeAttackIfReady();
        }

    private:
        bool hp60Spectrals;
        bool hp30Spectrals;
        bool hp50;
    };

    CreatureAI* GetAI(Creature* creature) const OVERRIDE
    {
        return new boss_amnennar_the_coldbringerAI(creature);
    }
};

void AddSC_boss_amnennar_the_coldbringer()
{
    new boss_amnennar_the_coldbringer();
}
