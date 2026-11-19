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

#include "ScriptMgr.h"
#include "blackfathom_deeps.h"
#include "ScriptedCreature.h"

enum Spells
{
    SPELL_NET         = 6533
};

enum Events
{
    EVENT_THROW_NET   = 1
};

struct boss_gelihast : public BossAI
{
    boss_gelihast(Creature* creature) : BossAI(creature, DATA_GELIHAST) { }

    void JustEngagedWith(Unit* who) override
    {
        BossAI::JustEngagedWith(who);
        events.ScheduleEvent(EVENT_THROW_NET, 2s, 4s);
    }

    void UpdateAI(uint32 diff) override
    {
        if (!UpdateVictim())
            return;

        events.Update(diff);

        while (uint32 eventId = events.ExecuteEvent())
        {
            if (eventId == EVENT_THROW_NET)
            {
                DoCastVictim(SPELL_NET);
                events.ScheduleEvent(EVENT_THROW_NET, 4s, 7s);
            }
        }
    }
};

void AddSC_boss_gelihast()
{
    RegisterBlackfathomDeepsCreatureAI(boss_gelihast);
}
