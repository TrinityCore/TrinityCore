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

#include "zulgurub.h"
#include "ScriptedCreature.h"
#include "ScriptMgr.h"

enum Yells
{
};

enum Spells
{
};

enum Events
{
};

struct boss_wushoolay : public BossAI
{
    boss_wushoolay(Creature* creature) : BossAI(creature, DATA_HAZZARAH)
    {
    }

    void JustEngagedWith(Unit* who) override
    {
        BossAI::JustEngagedWith(who);
    }

    void UpdateAI(uint32 diff) override
    {
        if (!UpdateVictim())
            return;

        events.Update(diff);

        if (me->HasUnitState(UNIT_STATE_CASTING))
            return;
        /*
        while (uint32 eventId = events.ExecuteEvent())
        {
            switch (eventId)
            {
                default:
                    break;
            }

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;
        }
        */
    }
};

void AddSC_boss_wushoolay()
{
    RegisterZulGurubCreatureAI(boss_wushoolay);
}
