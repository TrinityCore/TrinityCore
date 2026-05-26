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
#include "scholomance.h"
#include "ScriptedCreature.h"

enum PolkeltSpells
{
    SPELL_VOLATILE_INFECTION    = 18149,
    SPELL_NOXIOUS_CATALYST      = 18151,
    SPELL_CORROSIVE_ACID        = 8245
};

enum PolkeltEvents
{
    EVENT_VOLATILE_INFECTION    = 1,
    EVENT_NOXIOUS_CATALYST,
    EVENT_CORROSIVE_ACID
};

// 10901 - Lorekeeper Polkelt
struct boss_lorekeeper_polkelt : public BossAI
{
    boss_lorekeeper_polkelt(Creature* creature) : BossAI(creature, DATA_LOREKEEPER_POLKELT) { }

    void JustEngagedWith(Unit* who) override
    {
        BossAI::JustEngagedWith(who);

        events.ScheduleEvent(EVENT_VOLATILE_INFECTION, 15s, 20s);
        events.ScheduleEvent(EVENT_NOXIOUS_CATALYST, 10s, 20s);
        events.ScheduleEvent(EVENT_CORROSIVE_ACID, 20s, 30s);
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
                case EVENT_VOLATILE_INFECTION:
                    DoCastVictim(SPELL_VOLATILE_INFECTION);
                    events.Repeat(10s, 20s);
                    break;
                case EVENT_NOXIOUS_CATALYST:
                    DoCastVictim(SPELL_NOXIOUS_CATALYST);
                    events.Repeat(20s, 30s);
                    break;
                case EVENT_CORROSIVE_ACID:
                    DoCastSelf(SPELL_CORROSIVE_ACID);
                    events.Repeat(30s, 40s);
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

void AddSC_boss_lorekeeperpolkelt()
{
    RegisterScholomanceCreatureAI(boss_lorekeeper_polkelt);
}
