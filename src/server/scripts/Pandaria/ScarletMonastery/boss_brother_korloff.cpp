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
    SPELL_BLAZING_FISTS = 114807,
    SPELL_FIRESTORM_KICK = 113764,
    SPELL_RISING_FLAME = 114410
};

enum Events
{
    EVENT_BLAZING_FISTS = 1,
    EVENT_FIRESTORM_KICK,
    EVENT_RISING_FLAME
};

class boss_brother_korloff : public CreatureScript
{
public:
    boss_brother_korloff() : CreatureScript("boss_brother_korloff") { }

    struct boss_brother_korloffAI : public BossAI
    {
        boss_brother_korloffAI(Creature* creature) : BossAI(creature, 59223)
        {
        }

        void Reset() override
        {
            BossAI::Reset();
        }

        void EnterCombat(Unit* victim) override
        {
            BossAI::EnterCombat(victim);
            events.ScheduleEvent(EVENT_BLAZING_FISTS, 4000);
            events.ScheduleEvent(EVENT_FIRESTORM_KICK, 8000);
            events.ScheduleEvent(EVENT_RISING_FLAME, 12000);
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
                case EVENT_BLAZING_FISTS:
                    DoCast(SPELL_BLAZING_FISTS);
                    events.ScheduleEvent(EVENT_BLAZING_FISTS, 4000);
                    break;
                case EVENT_FIRESTORM_KICK:
                    DoCastAOE(SPELL_FIRESTORM_KICK);
                    events.ScheduleEvent(EVENT_FIRESTORM_KICK, 8000);
                    break;
                case EVENT_RISING_FLAME:
                    DoCast(me,SPELL_RISING_FLAME);
                    events.ScheduleEvent(EVENT_RISING_FLAME, 12000);
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
        return new boss_brother_korloffAI(creature);
    }
};

void AddSC_boss_brother_korloff()
{
    new boss_brother_korloff();
}
