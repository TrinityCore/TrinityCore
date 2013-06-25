/*
 * Copyright (C) 2008-2013 TrinityCore <http://www.trinitycore.org/>
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
#include "blackrock_spire.h"

enum Spells
{
    SPELL_REND_MOUNTS               = 16167, // Change model
    SPELL_FREEZE                    = 16350, // Combat
    SPELL_KNOCK_AWAY                = 10101, // Combat
    SPELL_FLAMEBREATH               = 16390, // Combat (Self cast)
    SPELL_CORROSIVE_ACID            = 16359, // Combat (self cast)
    SPELL_SUMMON_REND               = 16328  // Summons Rend near death
};

enum Events
{
    EVENT_CORROSIVE_ACID            = 1,
    EVENT_FREEZE                    = 2,
    EVENT_FLAME_BREATH              = 3,
    EVENT_SUMMONED                  = 4,
};

class boss_gyth : public CreatureScript
{
public:
    boss_gyth() : CreatureScript("boss_gyth") { }

    struct boss_gythAI : public BossAI
    {
        boss_gythAI(Creature* creature) : BossAI(creature, DATA_GYTH) { }

        bool SummonedRend;

        void Reset()
        {
            _Reset();
            SummonedRend = false;
        }

        void EnterCombat(Unit* /*who*/)
        {
            _EnterCombat();

            events.ScheduleEvent(EVENT_CORROSIVE_ACID, 18000);
            events.ScheduleEvent(EVENT_FREEZE, 20000);
            events.ScheduleEvent(EVENT_FLAME_BREATH, 16000);
        }

        void JustDied(Unit* /*killer*/)
        {
            _JustDied();
            // Open doors
        }

        void IsSummonedBy(Unit* /*summoner*/)
        {
            events.ScheduleEvent(EVENT_SUMMONED, 8000);
        }

        void UpdateAI(uint32 diff)
        {
            if (!UpdateVictim())
                return;

            if (!SummonedRend && HealthBelowPct(5))
            {
                DoCast(me, SPELL_REND_MOUNTS);
                me->RemoveAura(SPELL_REND_MOUNTS);
                SummonedRend = true;
            }

            events.Update(diff);

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case EVENT_SUMMONED:
                        DoCast(me, SPELL_REND_MOUNTS);
                        // Load Path
                        break;
                    case EVENT_CORROSIVE_ACID:
                        DoCastVictim(SPELL_CORROSIVE_ACID);
                        events.ScheduleEvent(EVENT_CORROSIVE_ACID, 20000);
                        break;
                    case EVENT_FREEZE:
                        DoCastVictim(SPELL_FREEZE);
                        events.ScheduleEvent(EVENT_FREEZE, 16000);
                        break;
                    case EVENT_FLAME_BREATH:
                        DoCastVictim(SPELL_FLAMEBREATH);
                        events.ScheduleEvent(EVENT_FLAME_BREATH, 10000);
                        break;
                }
            }
            DoMeleeAttackIfReady();
        }
    };

    CreatureAI* GetAI(Creature* creature) const
    {
        return new boss_gythAI(creature);
    }
};

void AddSC_boss_gyth()
{
    new boss_gyth();
}
