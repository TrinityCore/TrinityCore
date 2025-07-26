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

#include "scholomance.h"
#include "ScriptMgr.h"
#include "ScriptedCreature.h"

enum AlexeiSpells
{
    SPELL_IMMOLATE                  = 20294,
    SPELL_VEIL_OF_SHADOW            = 17820,
    SPELL_UNHOLY_AURA               = 17467
};

enum AlexeiEvents
{
    EVENT_IMMOLATE = 1,
    EVENT_VEIL_OF_SHADOW
};

// 10504 - Lord Alexei Barov
struct boss_lord_alexei_barov : public BossAI
{
    boss_lord_alexei_barov(Creature* creature) : BossAI(creature, DATA_LORD_ALEXEI_BAROV) { }

    void Reset() override
    {
        _Reset();

        if (!me->HasAura(SPELL_UNHOLY_AURA))
            DoCastSelf(SPELL_UNHOLY_AURA);
    }

    void JustEngagedWith(Unit* who) override
    {
        BossAI::JustEngagedWith(who);
        events.ScheduleEvent(EVENT_IMMOLATE, 7s);
        events.ScheduleEvent(EVENT_VEIL_OF_SHADOW, 15s);
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
                case EVENT_IMMOLATE:
                    DoCast(SelectTarget(SelectTargetMethod::Random, 0, 100, true), SPELL_IMMOLATE);
                    events.Repeat(12s);
                    break;
                case EVENT_VEIL_OF_SHADOW:
                    DoCastVictim(SPELL_VEIL_OF_SHADOW);
                    events.Repeat(20s);
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
