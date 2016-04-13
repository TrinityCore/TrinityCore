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
    SPELL_BODY_SLAM = 154175,
    SPELL_CORPSE_BREATH = 165578,
    SPELL_FETID_SPLIT = 153680,
    SPELL_FETID_SPLIT2 = 153681,
    SPELL_INHALE = 153804
};

enum Events
{
    EVENT_BODY_SLAM = 1,
    EVENT_CORPSE_BREATH,
    EVENT_FETID_SPLIT,
    EVENT_FETID_SPLIT2,
    EVENT_INHALE
};

class boss_bonemaw : public CreatureScript
{
public:
    boss_bonemaw() : CreatureScript("boss_bonemaw") { }

    struct boss_bonemawAI : public BossAI
    {
        boss_bonemawAI(Creature* creature) : BossAI(creature, 75452)
        {
        }

        void Reset() override
        {
            BossAI::Reset();
        }

        void EnterCombat(Unit* victim) override
        {
            BossAI::EnterCombat(victim);
            events.ScheduleEvent(EVENT_BODY_SLAM, 4000);
            events.ScheduleEvent(EVENT_CORPSE_BREATH, 8000);
            events.ScheduleEvent(EVENT_FETID_SPLIT, 12000);
            events.ScheduleEvent(EVENT_FETID_SPLIT2, 16000);
            events.ScheduleEvent(EVENT_INHALE, 20000);
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
                case EVENT_BODY_SLAM:
                    DoCast(SPELL_BODY_SLAM);
                    events.ScheduleEvent(EVENT_BODY_SLAM, 4000);
                    break;
                case EVENT_CORPSE_BREATH:
                    DoCastAOE(SPELL_CORPSE_BREATH);
                    events.ScheduleEvent(EVENT_CORPSE_BREATH, 8000);
                    break;
                case EVENT_FETID_SPLIT:
                    DoCastVictim(SPELL_FETID_SPLIT);
                    events.ScheduleEvent(EVENT_FETID_SPLIT, 12000);
                    break;
                case EVENT_FETID_SPLIT2:
                    DoCastVictim(SPELL_FETID_SPLIT2);
                    events.ScheduleEvent(EVENT_FETID_SPLIT2, 16000);
                    break;
                case EVENT_INHALE:
                    DoCastAOE(SPELL_INHALE);
                    events.ScheduleEvent(EVENT_INHALE, 20000);
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
        return new boss_bonemawAI(creature);
    }
};

void AddSC_boss_bonemaw()
{
    new boss_bonemaw();
}
