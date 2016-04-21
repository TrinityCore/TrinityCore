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
    SPELL_ABRUPT_RESTORATION = 163705,
    SPELL_BLOOD_BOLT = 165122,
    SPELL_SANGUINE_SPHERE = 163689,
    SPELL_TAINTED_BLOOD = 163740,
};

enum Events
{
    EVENT_ABRUPT_RESTORATION = 1,
    EVENT_BLOOD_BOLT,
    EVENT_SANGUINE_SPHERE,
    EVENT_TAINTED_BLOOD,
};

class boss_ahriok_dugru : public CreatureScript
{
public:
    boss_ahriok_dugru() : CreatureScript("boss_ahriok_dugru") { }

    struct boss_ahriok_dugruAI : public BossAI
    {
        boss_ahriok_dugruAI(Creature* creature) : BossAI(creature, 80816)
        {
        }

        void Reset() override
        {
            BossAI::Reset();
        }

        void EnterCombat(Unit* victim) override
        {
            BossAI::EnterCombat(victim);
            events.ScheduleEvent(EVENT_ABRUPT_RESTORATION, 4000);
            events.ScheduleEvent(EVENT_BLOOD_BOLT, 8000);
            events.ScheduleEvent(EVENT_SANGUINE_SPHERE, 12000);
            events.ScheduleEvent(EVENT_TAINTED_BLOOD, 16000);
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
                case EVENT_ABRUPT_RESTORATION:
                    DoCast(me,SPELL_ABRUPT_RESTORATION);
                    events.ScheduleEvent(EVENT_ABRUPT_RESTORATION, 4000);
                    break;
                case EVENT_BLOOD_BOLT:
                    DoCast(SPELL_BLOOD_BOLT);
                    events.ScheduleEvent(EVENT_BLOOD_BOLT, 8000);
                    break;
                case EVENT_SANGUINE_SPHERE:
                    DoCast(SPELL_SANGUINE_SPHERE);
                    events.ScheduleEvent(EVENT_SANGUINE_SPHERE, 12000);
                    break;
                case EVENT_TAINTED_BLOOD:
                    DoCastVictim(SPELL_TAINTED_BLOOD);
                    events.ScheduleEvent(EVENT_TAINTED_BLOOD, 12000);
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
        return new boss_ahriok_dugruAI(creature);
    }
};

void AddSC_boss_ahriok_dugru()
{
    new boss_ahriok_dugru();
}
