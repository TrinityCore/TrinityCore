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
 * SPELL_SUMMON_RIFLEMAN should target something but there's nothing spawned in summon position
 */

#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "stratholme.h"

enum WilleySpells
{
    SPELL_SHOOT                = 16496,
    SPELL_KNOCK_AWAY           = 10101,
    SPELL_PUMMEL               = 15615,
    SPELL_SUMMON_RIFLEMAN      = 17279
};

enum WilleyEvents
{
    EVENT_SHOOT                = 1,
    EVENT_KNOCK_AWAY,
    EVENT_PUMMEL,
    EVENT_SUMMON_RIFLEMAN
};

// 10997 - Cannon Master Willey
struct boss_cannon_master_willey : public ScriptedAI
{
    boss_cannon_master_willey(Creature* creature) : ScriptedAI(creature) { }

    void Reset() override
    {
        _events.Reset();
    }

    void JustEngagedWith(Unit* /*who*/) override
    {
        _events.ScheduleEvent(EVENT_SHOOT, 0s);
        _events.ScheduleEvent(EVENT_KNOCK_AWAY, 10s, 20s);
        _events.ScheduleEvent(EVENT_PUMMEL, 10s, 15s);
        _events.ScheduleEvent(EVENT_SUMMON_RIFLEMAN, 5s, 10s);
    }

    void AttackStart(Unit* who) override
    {
        ScriptedAI::AttackStartCaster(who, 30.0f);
    }

    void UpdateAI(uint32 diff) override
    {
        if (!UpdateVictim())
            return;

        _events.Update(diff);

        if (me->HasUnitState(UNIT_STATE_CASTING))
            return;

        while (uint32 eventId = _events.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_SHOOT:
                    DoCastVictim(SPELL_SHOOT);
                    _events.Repeat(2s, 4s);
                    break;
                case EVENT_KNOCK_AWAY:
                    DoCastVictim(SPELL_KNOCK_AWAY);
                    _events.Repeat(15s, 25s);
                    break;
                case EVENT_PUMMEL:
                    DoCastVictim(SPELL_PUMMEL);
                    _events.Repeat(10s, 15s);
                    break;
                case EVENT_SUMMON_RIFLEMAN:
                    DoCastSelf(SPELL_SUMMON_RIFLEMAN);
                    _events.Repeat(15s, 25s);
                    break;
                default:
                    break;
            }

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;
        }

        DoMeleeAttackIfReady();
    }

private:
    EventMap _events;
};

void AddSC_boss_cannon_master_willey()
{
    RegisterStratholmeCreatureAI(boss_cannon_master_willey);
}
