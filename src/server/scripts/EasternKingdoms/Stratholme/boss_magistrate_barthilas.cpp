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

enum BarthilasSpells
{
    SPELL_FURIOUS_ANGER     = 16791,
    SPELL_DRAINING_BLOW     = 16793,
    SPELL_CROWD_PUMMEL      = 10887,
    SPELL_MIGHTY_BLOW       = 14099,

    SPELL_TRANSFORMATION    = 16794
};

enum BarthilasEvents
{
    EVENT_FURIOUS_ANGER     = 1,
    EVENT_DRAINING_BLOW,
    EVENT_CROWD_PUMMEL,
    EVENT_MIGHTY_BLOW
};

// 10435 - Magistrate Barthilas
struct boss_magistrate_barthilas : public BossAI
{
    boss_magistrate_barthilas(Creature* creature) : BossAI(creature, BOSS_MAGISTRATE_BARTHILAS) { }

    void JustEngagedWith(Unit* who) override
    {
        BossAI::JustEngagedWith(who);

        events.ScheduleEvent(EVENT_FURIOUS_ANGER, 0s, 4s);
        events.ScheduleEvent(EVENT_DRAINING_BLOW, 0s, 5s);
        events.ScheduleEvent(EVENT_CROWD_PUMMEL, 15s, 20s);
        events.ScheduleEvent(EVENT_MIGHTY_BLOW, 15s, 25s);
    }

    void JustDied(Unit* killer) override
    {
        BossAI::JustDied(killer);

        DoCastSelf(SPELL_TRANSFORMATION, true);
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
                case EVENT_FURIOUS_ANGER:
                    DoCastSelf(SPELL_FURIOUS_ANGER);
                    events.Repeat(4s);
                    break;
                case EVENT_DRAINING_BLOW:
                    DoCastVictim(SPELL_DRAINING_BLOW);
                    events.Repeat(2s, 14s);
                    break;
                case EVENT_CROWD_PUMMEL:
                    DoCastSelf(SPELL_CROWD_PUMMEL);
                    events.Repeat(25s, 30s);
                    break;
                case EVENT_MIGHTY_BLOW:
                    DoCastVictim(SPELL_MIGHTY_BLOW);
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

void AddSC_boss_magistrate_barthilas()
{
    RegisterStratholmeCreatureAI(boss_magistrate_barthilas);
}
