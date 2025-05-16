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

enum RavenianSpells
{
    SPELL_TRAMPLE                   = 15550,
    SPELL_CLEAVE                    = 20691,
    SPELL_SUNDERING_CLEAVE          = 25174,
    SPELL_KNOCK_AWAY                = 10101
};

enum RavenianEvents
{
    EVENT_TRAMPLE = 1,
    EVENT_CLEAVE,
    EVENT_SUNDERING_CLEAVE,
    EVENT_KNOCK_AWAY
};

// 10507 - The Ravenian
struct boss_the_ravenian : public BossAI
{
    boss_the_ravenian(Creature* creature) : BossAI(creature, DATA_THE_RAVENIAN) { }

    void JustEngagedWith(Unit* who) override
    {
        BossAI::JustEngagedWith(who);
        events.ScheduleEvent(EVENT_TRAMPLE, 24s);
        events.ScheduleEvent(EVENT_CLEAVE, 15s);
        events.ScheduleEvent(EVENT_SUNDERING_CLEAVE, 40s);
        events.ScheduleEvent(EVENT_KNOCK_AWAY, 32s);
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
                    events.Repeat(10s);
                    break;
                case EVENT_CLEAVE:
                    DoCastVictim(SPELL_CLEAVE);
                    events.Repeat(7s);
                    break;
                case EVENT_SUNDERING_CLEAVE:
                    DoCastVictim(SPELL_SUNDERING_CLEAVE);
                    events.Repeat(20s);
                    break;
                case EVENT_KNOCK_AWAY:
                    DoCastVictim(SPELL_KNOCK_AWAY);
                    events.Repeat(12s);
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

void AddSC_boss_theravenian()
{
    RegisterScholomanceCreatureAI(boss_the_ravenian);
}
