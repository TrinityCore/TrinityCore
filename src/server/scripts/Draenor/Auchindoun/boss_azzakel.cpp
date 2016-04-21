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
    SPELL_CLAWS_OF_ARGUS = 153764,
    SPELL_CURTAIN_OF_FLAME = 153396,
    SPELL_FEL_LASH = 153234,
    SPELL_MALEVOLENT_CRASH = 153499,
};

enum Events
{
    EVENT_CLAWS_OF_ARGUS = 1,
    EVENT_CURTAIN_OF_FLAME,
    EVENT_FEL_LASH,
    EVENT_MALEVOLENT_CRASH,
};

class boss_azzakel : public CreatureScript
{
public:
    boss_azzakel() : CreatureScript("boss_azzakel") { }

    struct boss_azzakelAI : public BossAI
    {
        boss_azzakelAI(Creature* creature) : BossAI(creature, 75927)
        {
        }

        void Reset() override
        {
            BossAI::Reset();
        }

        void EnterCombat(Unit* victim) override
        {
            BossAI::EnterCombat(victim);

            events.ScheduleEvent(EVENT_CLAWS_OF_ARGUS, 4000);
            events.ScheduleEvent(EVENT_CURTAIN_OF_FLAME, 8000);
            events.ScheduleEvent(EVENT_FEL_LASH, 12000);
            events.ScheduleEvent(EVENT_MALEVOLENT_CRASH, 16000);
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
                case EVENT_CLAWS_OF_ARGUS:
                    DoCast(SPELL_CLAWS_OF_ARGUS);
                    events.ScheduleEvent(EVENT_CLAWS_OF_ARGUS, 4000);
                    break;
                case EVENT_CURTAIN_OF_FLAME:
                    DoCastVictim(SPELL_CURTAIN_OF_FLAME);
                    events.ScheduleEvent(EVENT_CURTAIN_OF_FLAME, 8000);
                    break;
                case EVENT_FEL_LASH:
                    DoCastVictim(SPELL_FEL_LASH);
                    events.ScheduleEvent(EVENT_FEL_LASH, 12000);
                    break;
                case EVENT_MALEVOLENT_CRASH:
                    DoCastAOE(SPELL_MALEVOLENT_CRASH);
                    events.ScheduleEvent(EVENT_MALEVOLENT_CRASH, 16000);
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
        return new boss_azzakelAI(creature);
    }
};

void AddSC_boss_azzakel()
{
    new boss_azzakel();
}
