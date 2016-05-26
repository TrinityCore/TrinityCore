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
#include "karazhan.h"

enum Spells
{
    SPELL_REPENTANCE    = 29511,
    SPELL_HOLYFIRE      = 29522,
    SPELL_HOLYWRATH     = 32445,
    SPELL_HOLYGROUND    = 29512,
    SPELL_BERSERK       = 26662
};

enum Yells
{
    SAY_AGGRO           = 0,
    SAY_SLAY            = 1,
    SAY_REPENTANCE      = 2,
    SAY_DEATH           = 3
};

enum Events
{
    EVENT_REPENTANCE    = 1,
    EVENT_HOLYFIRE      = 2,
    EVENT_HOLYWRATH     = 3,
    EVENT_HOLYGROUND    = 4,
    EVENT_ENRAGE        = 5
};

class boss_maiden_of_virtue : public CreatureScript
{
public:
    boss_maiden_of_virtue() : CreatureScript("boss_maiden_of_virtue") { }

    struct boss_maiden_of_virtueAI : public BossAI
    {
        boss_maiden_of_virtueAI(Creature* creature) : BossAI(creature, DATA_MAIDEN_OF_VIRTUE) { }

        void KilledUnit(Unit* /*Victim*/) override
        {
            if (urand(0, 1) == 0)
                Talk(SAY_SLAY);
        }

        void JustDied(Unit* /*killer*/) override
        {
            Talk(SAY_DEATH);
            _JustDied();
        }

        void EnterCombat(Unit* /*who*/) override
        {
            _EnterCombat();
            Talk(SAY_AGGRO);

            events.ScheduleEvent(EVENT_REPENTANCE, urand(33, 45) * IN_MILLISECONDS);
            events.ScheduleEvent(EVENT_HOLYFIRE, 12 * IN_MILLISECONDS);
            events.ScheduleEvent(EVENT_HOLYWRATH, urand(15, 25) * IN_MILLISECONDS);
            events.ScheduleEvent(EVENT_HOLYGROUND, 3 * IN_MILLISECONDS);
            events.ScheduleEvent(EVENT_ENRAGE, 600 * IN_MILLISECONDS);
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
                    case EVENT_REPENTANCE:
                        DoCastVictim(SPELL_REPENTANCE);
                        Talk(SAY_REPENTANCE);
                        events.ScheduleEvent(EVENT_REPENTANCE, urand(33, 45) * IN_MILLISECONDS);
                        break;
                    case EVENT_HOLYFIRE:
                        if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 50, true))
                            DoCast(target, SPELL_HOLYFIRE);
                        events.ScheduleEvent(EVENT_HOLYFIRE, 12 * IN_MILLISECONDS);
                        break;
                    case EVENT_HOLYWRATH:
                        if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 80, true))
                            DoCast(target, SPELL_HOLYWRATH);
                        events.ScheduleEvent(EVENT_HOLYWRATH, urand(15, 25) * IN_MILLISECONDS);
                        break;
                    case EVENT_HOLYGROUND:
                        DoCast(me, SPELL_HOLYGROUND, true);
                        events.ScheduleEvent(EVENT_HOLYGROUND, 3 * IN_MILLISECONDS);
                        break;
                    case EVENT_ENRAGE:
                        DoCast(me, SPELL_BERSERK, true);
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
        return new boss_maiden_of_virtueAI(creature);
    }
};

void AddSC_boss_maiden_of_virtue()
{
    new boss_maiden_of_virtue();
}
