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

enum AlexeiSpells
{
    // Passive
    SPELL_IMMOLATE              = 15506,
    SPELL_UNHOLY_AURA           = 17467,

    // Combat
    SPELL_VEIL_OF_SHADOW        = 17820

};

enum AlexeiEvents
{
    EVENT_VEIL_OF_SHADOW        = 1
};

// 10504 - Lord Alexei Barov
struct boss_lord_alexei_barov : public BossAI
{
    boss_lord_alexei_barov(Creature* creature) : BossAI(creature, DATA_LORD_ALEXEI_BAROV) { }

    void Reset() override
    {
        _Reset();

        DoCastSelf(SPELL_IMMOLATE);
        DoCastSelf(SPELL_UNHOLY_AURA);
    }

    void JustEngagedWith(Unit* who) override
    {
        BossAI::JustEngagedWith(who);

        events.ScheduleEvent(EVENT_VEIL_OF_SHADOW, 10s, 15s);
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
                case EVENT_VEIL_OF_SHADOW:
                    DoCastVictim(SPELL_VEIL_OF_SHADOW);
                    events.Repeat(15s, 25s);
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

void AddSC_boss_lordalexeibarov()
{
    RegisterScholomanceCreatureAI(boss_lord_alexei_barov);
}
