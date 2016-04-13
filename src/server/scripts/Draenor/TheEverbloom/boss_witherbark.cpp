/*
 * Copyright (C) 2008-2016 TrinityCore <http://www.trinitycore.org/>
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

enum Spells
{
    SPELL_BRITTLE_BARK = 164275,
    SPELL_PARCHED_GASP = 164357
};

enum Events
{
    EVENT_BRITTLE_BARK = 1,
    EVENT_PARCHED_GASP
};

class boss_witherbark : public CreatureScript
{
public:
    boss_witherbark() : CreatureScript("boss_witherbark") { }

    struct boss_witherbarkAI : public BossAI
    {
        boss_witherbarkAI(Creature* creature) : BossAI(creature, 81522)
        {
        }

        void Reset() override
        {
            BossAI::Reset();
        }

        void EnterCombat(Unit* victim) override
        {
            BossAI::EnterCombat(victim);
            events.ScheduleEvent(EVENT_BRITTLE_BARK, 4000);
            events.ScheduleEvent(EVENT_PARCHED_GASP, 8000);
        }

        void KilledUnit(Unit * /*victim*/) override
        {
        }

        void JustDied(Unit * /*victim*/) override
        {
            _JustDied();
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
                case EVENT_BRITTLE_BARK:
                    DoCast(me,SPELL_BRITTLE_BARK);
                    events.ScheduleEvent(EVENT_BRITTLE_BARK, 4000);
                    break;
                case EVENT_PARCHED_GASP:
                    DoCastAOE(SPELL_PARCHED_GASP);
                    events.ScheduleEvent(EVENT_PARCHED_GASP, 8000);
                    break;
                default:
                    break;
                }
            }
            DoMeleeAttackIfReady();
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new boss_witherbarkAI(creature);
    }
};

void AddSC_boss_witherbark()
{
    new boss_witherbark();
}
