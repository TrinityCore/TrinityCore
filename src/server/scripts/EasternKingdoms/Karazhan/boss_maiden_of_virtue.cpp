/*
 * Copyright (C) 2008-2018 TrinityCore <https://www.trinitycore.org/>
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
#include "karazhan.h"
#include "ScriptedCreature.h"

enum Spells
{
    SPELL_REPENTANCE    = 29511,
    SPELL_HOLYFIRE      = 29522,
    SPELL_HOLYWRATH     = 32445,
    SPELL_HOLYGROUND    = 29523,
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
    EVENT_ENRAGE        = 4
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
            if (roll_chance_i(50))
                Talk(SAY_SLAY);
        }

        void JustDied(Unit* /*killer*/) override
        {
            Talk(SAY_DEATH);
            _JustDied();
        }

        void JustEngagedWith(Unit* /*who*/) override
        {
            _JustEngagedWith();
            Talk(SAY_AGGRO);

            DoCastSelf(SPELL_HOLYGROUND, true);
            events.ScheduleEvent(EVENT_REPENTANCE, 33s, 45s);
            events.ScheduleEvent(EVENT_HOLYFIRE, 8s);
            events.ScheduleEvent(EVENT_HOLYWRATH, 15s, 25s);
            events.ScheduleEvent(EVENT_ENRAGE, 10min);
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
                        events.Repeat(Seconds(35));
                        break;
                    case EVENT_HOLYFIRE:
                        if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 50, true))
                            DoCast(target, SPELL_HOLYFIRE);
                        events.Repeat(Seconds(8), Seconds(19));
                        break;
                    case EVENT_HOLYWRATH:
                        if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 80, true))
                            DoCast(target, SPELL_HOLYWRATH);
                        events.Repeat(Seconds(15), Seconds(25));
                        break;
                    case EVENT_ENRAGE:
                        DoCastSelf(SPELL_BERSERK, true);
                        break;
                    default:
                        break;
                }

                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;
            }

            DoMeleeAttackIfReady();
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return GetKarazhanAI<boss_maiden_of_virtueAI>(creature);
    }
};

void AddSC_boss_maiden_of_virtue()
{
    new boss_maiden_of_virtue();
}
