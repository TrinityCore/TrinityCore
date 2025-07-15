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
#include "scholomance.h"
#include "ScriptedCreature.h"

enum TheolenTexts
{
    EMOTE_FRENZY_KILL           = 0
};

enum TheolenSpells
{
    SPELL_REND                  = 16509,
    SPELL_BACKHAND              = 18103,
    SPELL_FRENZY                = 8269
};

enum TheolenEvents
{
    EVENT_REND = 1,
    EVENT_BACKHAND,
    EVENT_FRENZY
};

// 11261 - Doctor Theolen Krastinov
struct boss_doctor_theolen_krastinov : public BossAI
{
    boss_doctor_theolen_krastinov(Creature* creature) : BossAI(creature, DATA_DOCTOR_THEOLEN_KRASTINOV) { }

    void JustEngagedWith(Unit* who) override
    {
        BossAI::JustEngagedWith(who);
        events.ScheduleEvent(EVENT_REND, 8s);
        events.ScheduleEvent(EVENT_BACKHAND, 9s);
        events.ScheduleEvent(EVENT_FRENZY, 1s);
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
                case EVENT_REND:
                    DoCastVictim(SPELL_REND);
                    events.Repeat(10s);
                    break;
                case EVENT_BACKHAND:
                    DoCastVictim(SPELL_BACKHAND);
                    events.Repeat(10s);
                    break;
                case EVENT_FRENZY:
                    DoCastSelf(SPELL_FRENZY);
                    Talk(EMOTE_FRENZY_KILL);
                    events.Repeat(120s);
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

void AddSC_boss_theolenkrastinov()
{
    RegisterScholomanceCreatureAI(boss_doctor_theolen_krastinov);
}
