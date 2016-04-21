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
    SPELL_ICE_WAVE = 111854,
    SPELL_ICE_WRATH = 111610,
    SPELL_TOUCH_OF_THE_GRAVE = 111606
};

enum Events
{
    EVENT_ICE_WAVE = 1,
    EVENT_ICE_WRATH
};

class boss_instructor_chillheart : public CreatureScript
{
public:
    boss_instructor_chillheart() : CreatureScript("boss_instructor_chillheart") { }

    struct boss_instructor_chillheartAI : public BossAI
    {
        boss_instructor_chillheartAI(Creature* creature) : BossAI(creature, 58633)
        {
        }

        void Reset() override
        {
            BossAI::Reset();
        }

        void EnterCombat(Unit* victim) override
        {
            BossAI::EnterCombat(victim);
            events.ScheduleEvent(EVENT_ICE_WAVE, 4000);
            events.ScheduleEvent(EVENT_ICE_WRATH, 8000);
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
                case EVENT_ICE_WAVE:
                    DoCast(SPELL_ICE_WAVE);
                    events.ScheduleEvent(EVENT_ICE_WAVE, 4000);
                    break;
                case EVENT_ICE_WRATH:
                    DoCastAOE(SPELL_ICE_WRATH);
                    events.ScheduleEvent(EVENT_ICE_WRATH, 8000);
                    break;
                default:
                    break;
                }
            }
            DoMeleeAttackIfReady();
            DoCastVictim(SPELL_TOUCH_OF_THE_GRAVE);
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new boss_instructor_chillheartAI(creature);
    }
};

void AddSC_boss_instructor_chillheart()
{
    new boss_instructor_chillheart();
}
