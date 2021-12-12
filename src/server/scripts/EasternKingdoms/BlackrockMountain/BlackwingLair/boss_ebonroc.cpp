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
#include "blackwing_lair.h"
#include "ScriptedCreature.h"

enum Spells
{
    SPELL_SHADOWFLAME           = 22539,
    SPELL_WINGBUFFET            = 23339,
    SPELL_SHADOWOFEBONROC       = 23340
};

enum Events
{
    EVENT_SHADOWFLAME           = 1,
    EVENT_WINGBUFFET            = 2,
    EVENT_SHADOWOFEBONROC       = 3
};

struct boss_ebonroc : public BossAI
{
    boss_ebonroc(Creature* creature) : BossAI(creature, DATA_EBONROC) { }

    void JustEngagedWith(Unit* who) override
    {
        BossAI::JustEngagedWith(who);

        events.ScheduleEvent(EVENT_SHADOWFLAME, 10s, 20s);
        events.ScheduleEvent(EVENT_WINGBUFFET, 30s);
        events.ScheduleEvent(EVENT_SHADOWOFEBONROC, 8s, 10s);
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
                case EVENT_SHADOWFLAME:
                    DoCastVictim(SPELL_SHADOWFLAME);
                    events.ScheduleEvent(EVENT_SHADOWFLAME, 10s, 20s);
                    break;
                case EVENT_WINGBUFFET:
                    DoCastVictim(SPELL_WINGBUFFET);
                    events.ScheduleEvent(EVENT_WINGBUFFET, 30s);
                    break;
                case EVENT_SHADOWOFEBONROC:
                    DoCastVictim(SPELL_SHADOWOFEBONROC);
                    events.ScheduleEvent(EVENT_SHADOWOFEBONROC, 8s, 10s);
                    break;
            }

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;
        }

        DoMeleeAttackIfReady();
    }
};

void AddSC_boss_ebonroc()
{
    RegisterBlackwingLairCreatureAI(boss_ebonroc);
}
