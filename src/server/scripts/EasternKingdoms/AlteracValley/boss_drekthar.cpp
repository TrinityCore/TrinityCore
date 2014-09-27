/*
 * Copyright (C) 2008-2014 TrinityCore <http://www.trinitycore.org/>
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
#include "ScriptedCreature.h"

enum Spells
{
    SPELL_WHIRLWIND                               = 15589,
    SPELL_WHIRLWIND2                              = 13736,
    SPELL_KNOCKDOWN                               = 19128,
    SPELL_FRENZY                                  = 8269,
    SPELL_SWEEPING_STRIKES                        = 18765, // not sure
    SPELL_CLEAVE                                  = 20677, // not sure
    SPELL_WINDFURY                                = 35886, // not sure
    SPELL_STORMPIKE                               = 51876  // not sure
};

enum Texts
{
    SAY_AGGRO                                    = 0,
    SAY_EVADE                                    = 1,
    SAY_RESPAWN                                  = 2,
    SAY_RANDOM                                   = 3
};

enum Events
{
    EVENT_WHIRLWIND = 1,
    EVENT_WHIRLWIND2,
    EVENT_KNOCKDOWN,
    EVENT_FRENZY,
    EVENT_RANDOM_YELL
};

class boss_drekthar : public CreatureScript
{
public:
    boss_drekthar() : CreatureScript("boss_drekthar") { }

    struct boss_drektharAI : public ScriptedAI
    {
        boss_drektharAI(Creature* creature) : ScriptedAI(creature) { }

        void Reset() override
        {
            events.Reset();
        }

        void EnterCombat(Unit* /*who*/) override
        {
            Talk(SAY_AGGRO);
            events.ScheduleEvent(EVENT_WHIRLWIND, urand(1 * IN_MILLISECONDS, 20 * IN_MILLISECONDS));
            events.ScheduleEvent(EVENT_WHIRLWIND2, urand(1 * IN_MILLISECONDS, 20 * IN_MILLISECONDS));
            events.ScheduleEvent(EVENT_KNOCKDOWN, 12 * IN_MILLISECONDS);
            events.ScheduleEvent(EVENT_FRENZY, 6 * IN_MILLISECONDS);
            events.ScheduleEvent(EVENT_RANDOM_YELL, urand(20 * IN_MILLISECONDS, 30 * IN_MILLISECONDS)); //20 to 30 seconds
        }

        void JustRespawned() override
        {
            Reset();
            Talk(SAY_RESPAWN);
        }

        bool CheckInRoom()
        {
            if (me->GetDistance2d(me->GetHomePosition().GetPositionX(), me->GetHomePosition().GetPositionY()) > 50)
            {
                EnterEvadeMode();
                Talk(SAY_EVADE);
                return false;
            }

            return true;
        }

        void UpdateAI(uint32 diff) override
        {
            if (!UpdateVictim() || !CheckInRoom())
                return;

            events.Update(diff);

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case EVENT_WHIRLWIND:
                        DoCastVictim(SPELL_WHIRLWIND);
                        events.ScheduleEvent(EVENT_WHIRLWIND, urand(8 * IN_MILLISECONDS, 18 * IN_MILLISECONDS));
                        break;
                    case EVENT_WHIRLWIND2:
                        DoCastVictim(SPELL_WHIRLWIND2);
                        events.ScheduleEvent(EVENT_WHIRLWIND2, urand(7 * IN_MILLISECONDS, 25 * IN_MILLISECONDS));
                        break;
                    case EVENT_KNOCKDOWN:
                        DoCastVictim(SPELL_KNOCKDOWN);
                        events.ScheduleEvent(EVENT_KNOCKDOWN, urand(10 * IN_MILLISECONDS, 15 * IN_MILLISECONDS));
                        break;
                    case EVENT_FRENZY:
                        DoCastVictim(SPELL_FRENZY);
                        events.ScheduleEvent(EVENT_FRENZY, urand(20 * IN_MILLISECONDS, 30 * IN_MILLISECONDS));
                        break;
                    case EVENT_RANDOM_YELL:
                        Talk(SAY_RANDOM);
                        events.ScheduleEvent(EVENT_RANDOM_YELL, urand(20 * IN_MILLISECONDS, 30 * IN_MILLISECONDS));
                        break;
                    default:
                        break;
                }
            }

            DoMeleeAttackIfReady();
        }

        private:
            EventMap events;
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new boss_drektharAI(creature);
    }
};

void AddSC_boss_drekthar()
{
    new boss_drekthar;
}