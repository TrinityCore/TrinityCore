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

enum Spells
{
    SPELL_SOLAR_BURST = 154396
};

enum Events
{
    EVENT_SOLAR_BURST = 1
};

class boss_high_sage_viryx : public CreatureScript
{
public:
    boss_high_sage_viryx() : CreatureScript("boss_high_sage_viryx") { }

    struct boss_high_sage_viryxAI : public BossAI
    {
        boss_high_sage_viryxAI(Creature* creature) : BossAI(creature, 76266)
        {
        }

        void Reset() override
        {
            BossAI::Reset();
        }

        void EnterCombat(Unit* victim) override
        {
            BossAI::EnterCombat(victim);
            events.ScheduleEvent(EVENT_SOLAR_BURST, 4000);
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
                case EVENT_SOLAR_BURST:
                    DoCastVictim(SPELL_SOLAR_BURST);
                    events.ScheduleEvent(EVENT_SOLAR_BURST, 4000);
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
        return new boss_high_sage_viryxAI(creature);
    }
};

void AddSC_boss_high_sage_viryx()
{
    new boss_high_sage_viryx();
}
