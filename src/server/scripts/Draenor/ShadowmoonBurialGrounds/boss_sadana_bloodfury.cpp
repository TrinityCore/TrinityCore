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
    SPELL_DAGGERFALL = 153240,
    SPELL_DARK_COMMUNION = 153153,
    SPELL_DARK_ECLIPSE = 164974,
    SPELL_DEATHSPIKE = 162696,
    SPELL_WHISPERS_OF_THE_DARK_START = 153094
};

enum Events
{
    EVENT_DAGGERFALL = 1,
    EVENT_DARK_COMMUNION,
    EVENT_DARK_ECLIPSE,
    EVENT_DEATHSPIKE,
    EVENT_WHISPERS_OF_THE_DARK_START
};

class boss_sadana_bloodfury : public CreatureScript
{
public:
    boss_sadana_bloodfury() : CreatureScript("boss_sadana_bloodfury") { }

    struct boss_sadana_bloodfuryAI : public BossAI
    {
        boss_sadana_bloodfuryAI(Creature* creature) : BossAI(creature, 75509)
        {
        }

        void Reset() override
        {
            BossAI::Reset();
        }

        void EnterCombat(Unit* victim) override
        {
            BossAI::EnterCombat(victim);
            events.ScheduleEvent(EVENT_DAGGERFALL, 4000);
            events.ScheduleEvent(EVENT_DARK_COMMUNION, 8000);
            events.ScheduleEvent(EVENT_DARK_ECLIPSE, 12000);
            events.ScheduleEvent(EVENT_DEATHSPIKE, 16000);
            events.ScheduleEvent(EVENT_WHISPERS_OF_THE_DARK_START, 20000);
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
                case EVENT_DAGGERFALL:
                    if(Unit *target = SelectTarget(SELECT_TARGET_RANDOM, 0))
                        DoCast(target,SPELL_DAGGERFALL);
                    events.ScheduleEvent(EVENT_DAGGERFALL, 4000);
                    break;
                case EVENT_DARK_COMMUNION:
                    DoCast(me,SPELL_DARK_COMMUNION);
                    events.ScheduleEvent(EVENT_DARK_COMMUNION, 8000);
                    break;
                case EVENT_DARK_ECLIPSE:
                    DoCastAOE(SPELL_DARK_ECLIPSE);
                    events.ScheduleEvent(EVENT_DARK_ECLIPSE, 12000);
                    break;
                case EVENT_DEATHSPIKE:
                    DoCast(SPELL_DEATHSPIKE);
                    events.ScheduleEvent(EVENT_DEATHSPIKE, 16000);
                    break;
                case EVENT_WHISPERS_OF_THE_DARK_START:
                    DoCastAOE(SPELL_WHISPERS_OF_THE_DARK_START);
                    events.ScheduleEvent(EVENT_WHISPERS_OF_THE_DARK_START, 20000);
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
        return new boss_sadana_bloodfuryAI(creature);
    }
};

void AddSC_boss_sadana_bloodfury()
{
    new boss_sadana_bloodfury();
}
