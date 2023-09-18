/*
 * This file is part of the TrinityCore Project. See AUTHORS file for Copyright information
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

/*
 * Timers requires to be revisited
 */

#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "stratholme.h"

enum TimmyTexts
{
    SAY_AGGRO               = 0
};

enum TimmySpells
{
    SPELL_THRASH            = 12787,
    SPELL_RAVENOUS_CLAW     = 17470
};

enum TimmyEvents
{
    EVENT_RAVENOUS_CLAW     = 1
};

// 10808 - Timmy the Cruel
struct boss_timmy_the_cruel : public BossAI
{
    boss_timmy_the_cruel(Creature* creature) : BossAI(creature, BOSS_TIMMY_THE_CRUEL) { }

    void Reset() override
    {
        BossAI::Reset();

        DoCastSelf(SPELL_THRASH);
    }

    void JustEngagedWith(Unit* who) override
    {
        BossAI::JustEngagedWith(who);

        Talk(SAY_AGGRO);

        events.ScheduleEvent(EVENT_RAVENOUS_CLAW, 10s, 15s);
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
                case EVENT_RAVENOUS_CLAW:
                    DoCastVictim(SPELL_RAVENOUS_CLAW);
                    events.Repeat(10s, 15s);
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

void AddSC_boss_timmy_the_cruel()
{
    RegisterStratholmeCreatureAI(boss_timmy_the_cruel);
}
