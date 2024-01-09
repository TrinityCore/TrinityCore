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

/* ScriptData
SDName: Boss_Lucifron
SD%Complete: 100
SDComment:
SDCategory: Molten Core
EndScriptData */

#include "ScriptMgr.h"
#include "molten_core.h"
#include "ScriptedCreature.h"

enum Spells
{
    SPELL_IMPENDING_DOOM    = 19702,
    SPELL_LUCIFRON_CURSE    = 19703,
    SPELL_SHADOW_SHOCK      = 20603,
};

enum Events
{
    EVENT_IMPENDING_DOOM    = 1,
    EVENT_LUCIFRON_CURSE    = 2,
    EVENT_SHADOW_SHOCK      = 3,
};

struct boss_lucifron : public BossAI
{
    boss_lucifron(Creature* creature) : BossAI(creature, BOSS_LUCIFRON)
    {
    }

    void JustEngagedWith(Unit* victim) override
    {
        BossAI::JustEngagedWith(victim);
        events.ScheduleEvent(EVENT_IMPENDING_DOOM, 10s);
        events.ScheduleEvent(EVENT_LUCIFRON_CURSE, 20s);
        events.ScheduleEvent(EVENT_SHADOW_SHOCK, 6s);
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
                case EVENT_IMPENDING_DOOM:
                    DoCastVictim(SPELL_IMPENDING_DOOM);
                    events.ScheduleEvent(EVENT_IMPENDING_DOOM, 20s);
                    break;
                case EVENT_LUCIFRON_CURSE:
                    DoCastVictim(SPELL_LUCIFRON_CURSE);
                    events.ScheduleEvent(EVENT_LUCIFRON_CURSE, 15s);
                    break;
                case EVENT_SHADOW_SHOCK:
                    DoCastVictim(SPELL_SHADOW_SHOCK);
                    events.ScheduleEvent(EVENT_SHADOW_SHOCK, 6s);
                    break;
                default:
                    break;
            }

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;
        }
    }
};

void AddSC_boss_lucifron()
{
    RegisterMoltenCoreCreatureAI(boss_lucifron);
}
