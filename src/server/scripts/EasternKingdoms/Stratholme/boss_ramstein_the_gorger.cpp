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
 * Intro NYI
 */

#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "stratholme.h"

enum RamsteinSpells
{
    SPELL_FLURRY            = 15088,
    SPELL_TRAMPLE           = 5568,
    SPELL_KNOCKOUT          = 17307
};

enum RamsteinEvents
{
    EVENT_TRAMPLE           = 1,
    EVENT_KNOCKOUT
};

enum RamsteinMisc
{
    SUMMON_GROUP_SENTRY     = 0,
    SUMMON_GROUP_UNDEAD     = 1
};

// 10439 - Ramstein the Gorger
struct boss_ramstein_the_gorger : public BossAI
{
    boss_ramstein_the_gorger(Creature* creature) : BossAI(creature, BOSS_RAMSTEIN_THE_GORGER) { }

    void Reset() override
    {
        BossAI::Reset();

        DoCastSelf(SPELL_FLURRY);
    }

    void JustEngagedWith(Unit* who) override
    {
        BossAI::JustEngagedWith(who);

        events.ScheduleEvent(EVENT_TRAMPLE, 10s, 15s);
        events.ScheduleEvent(EVENT_KNOCKOUT, 10s, 20s);
    }

    void JustDied(Unit* killer) override
    {
        BossAI::JustDied(killer);

        me->SummonCreatureGroup(SUMMON_GROUP_SENTRY);
        me->SummonCreatureGroup(SUMMON_GROUP_UNDEAD);
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
                case EVENT_TRAMPLE:
                    DoCastSelf(SPELL_TRAMPLE);
                    events.Repeat(10s, 25s);
                    break;
                case EVENT_KNOCKOUT:
                    DoCastVictim(SPELL_KNOCKOUT);
                    events.Repeat(15s, 20s);
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

void AddSC_boss_ramstein_the_gorger()
{
    RegisterStratholmeCreatureAI(boss_ramstein_the_gorger);
}
