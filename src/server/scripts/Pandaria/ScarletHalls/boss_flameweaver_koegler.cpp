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
    SPELL_BOOK_BURNER = 113364,
    SPELL_FIREBALL_VOLLEY = 113691,
    SPELL_GREATER_DRAGONS_BREATH = 113653,
    SPELL_PYROBLAST = 113690,
    SPELL_TELEPORT = 113626
};

enum Events
{
    EVENT_BOOK_BURNER = 1,
    EVENT_FIREBALL_VOLLEY,
    EVENT_GREATER_DRAGONS_BREATH,
    EVENT_PYROBLAST,
    EVENT_TELEPORT
};

class boss_flameweaver_koegler : public CreatureScript
{
public:
    boss_flameweaver_koegler() : CreatureScript("boss_flameweaver_koegler") { }

    struct boss_flameweaver_koeglerAI : public BossAI
    {
        boss_flameweaver_koeglerAI(Creature* creature) : BossAI(creature, 59150)
        {
        }

        void Reset() override
        {
            BossAI::Reset();
        }

        void EnterCombat(Unit* victim) override
        {
            BossAI::EnterCombat(victim);
            events.ScheduleEvent(EVENT_BOOK_BURNER, 4000);
            events.ScheduleEvent(EVENT_FIREBALL_VOLLEY, 8000);
            events.ScheduleEvent(EVENT_GREATER_DRAGONS_BREATH, 12000);
            events.ScheduleEvent(EVENT_PYROBLAST, 16000);
            events.ScheduleEvent(EVENT_TELEPORT, 20000);
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
                case EVENT_BOOK_BURNER:
                    DoCastAOE(SPELL_BOOK_BURNER);
                    events.ScheduleEvent(EVENT_BOOK_BURNER, 4000);
                    break;
                case EVENT_FIREBALL_VOLLEY:
                    DoCastAOE(SPELL_FIREBALL_VOLLEY);
                    events.ScheduleEvent(EVENT_FIREBALL_VOLLEY, 8000);
                    break;
                case EVENT_GREATER_DRAGONS_BREATH:
                    DoCastVictim(SPELL_GREATER_DRAGONS_BREATH);
                    events.ScheduleEvent(EVENT_GREATER_DRAGONS_BREATH, 12000);
                    break;
                case EVENT_PYROBLAST:
                    DoCastVictim(SPELL_PYROBLAST);
                    events.ScheduleEvent(EVENT_PYROBLAST, 16000);
                    break;
                case EVENT_TELEPORT:
                    DoCast(SPELL_TELEPORT);
                    events.ScheduleEvent(EVENT_TELEPORT, 20000);
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
        return new boss_flameweaver_koeglerAI(creature);
    }
};

void AddSC_boss_flameweaver_koegler()
{
    new boss_flameweaver_koegler();
}
