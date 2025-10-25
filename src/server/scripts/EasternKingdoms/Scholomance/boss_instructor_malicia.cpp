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

enum MaliciaSpells
{
    SPELL_CALL_OF_GRAVES        = 17831,
    SPELL_CORRUPTION            = 18376,
    SPELL_SLOW                  = 13747,
    SPELL_FLASH_HEAL            = 17843,
    SPELL_HEAL                  = 15586,
    SPELL_RENEW                 = 8362
};

enum MaliciaEvents
{
    EVENT_CALL_OF_GRAVES        = 1,
    EVENT_CORRUPTION,
    EVENT_SLOW,
    EVENT_FLASH_HEAL,
    EVENT_HEAL,
    EVENT_RENEW
};

// 10505 - Instructor Malicia
struct boss_instructor_malicia : public BossAI
{
    boss_instructor_malicia(Creature* creature) : BossAI(creature, DATA_INSTRUCTOR_MALICIA) { }

    void JustEngagedWith(Unit* who) override
    {
        BossAI::JustEngagedWith(who);

        events.ScheduleEvent(EVENT_CALL_OF_GRAVES, 20s, 30s);
        events.ScheduleEvent(EVENT_CORRUPTION, 10s, 15s);
        events.ScheduleEvent(EVENT_SLOW, 5s, 10s);
        events.ScheduleEvent(EVENT_FLASH_HEAL, 5s, 10s);
        events.ScheduleEvent(EVENT_HEAL, 5s, 15s);
        events.ScheduleEvent(EVENT_RENEW, 15s, 20s);
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
                case EVENT_CALL_OF_GRAVES:
                    DoCastSelf(SPELL_CALL_OF_GRAVES);
                    events.Repeat(30s, 40s);
                    break;
                case EVENT_CORRUPTION:
                    DoCastSelf(SPELL_CORRUPTION);
                    events.Repeat(30s, 40s);
                    break;
                case EVENT_SLOW:
                    DoCastSelf(SPELL_SLOW);
                    events.Repeat(15s, 25s);
                    break;
                case EVENT_FLASH_HEAL:
                    DoCastSelf(SPELL_FLASH_HEAL);
                    events.Repeat(10s, 15s);
                    break;
                case EVENT_HEAL:
                    DoCastSelf(SPELL_HEAL);
                    events.Repeat(20s, 30s);
                    break;
                case EVENT_RENEW:
                    DoCastSelf(SPELL_RENEW);
                    events.Repeat(15s, 20s);
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

void AddSC_boss_instructormalicia()
{
    RegisterScholomanceCreatureAI(boss_instructor_malicia);
}
