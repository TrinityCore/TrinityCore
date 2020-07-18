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
Name: Boss_Doctor_Theolen_Krastinov
%Complete: 100
Comment:
Category: Scholomance
*/

#include "ScriptMgr.h"
#include "scholomance.h"
#include "ScriptedCreature.h"

enum Say
{
    EMOTE_FRENZY_KILL           = 0,
};

enum Spells
{
    SPELL_REND                  = 16509,
    SPELL_BACKHAND              = 18103,
    SPELL_FRENZY                = 8269
};

enum Events
{
    EVENT_REND                  = 1,
    EVENT_BACKHAND              = 2,
    EVENT_FRENZY                = 3
};

class boss_doctor_theolen_krastinov : public CreatureScript
{
    public: boss_doctor_theolen_krastinov() : CreatureScript("boss_doctor_theolen_krastinov") { }

        struct boss_theolenkrastinovAI : public BossAI
        {
            boss_theolenkrastinovAI(Creature* creature) : BossAI(creature, DATA_DOCTORTHEOLENKRASTINOV) { }

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
                            DoCastVictim(SPELL_REND, true);
                            events.ScheduleEvent(EVENT_REND, 10s);
                            break;
                        case EVENT_BACKHAND:
                            DoCastVictim(SPELL_BACKHAND, true);
                            events.ScheduleEvent(EVENT_BACKHAND, 10s);
                            break;
                        case EVENT_FRENZY:
                            DoCast(me, SPELL_FRENZY, true);
                            Talk(EMOTE_FRENZY_KILL);
                            events.ScheduleEvent(EVENT_FRENZY, 120s);
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

        CreatureAI* GetAI(Creature* creature) const override
        {
            return GetScholomanceAI<boss_theolenkrastinovAI>(creature);
        }

};

void AddSC_boss_theolenkrastinov()
{
    new boss_doctor_theolen_krastinov();
}
