/*
 * Copyright (C) 2008-2019 TrinityCore <https://www.trinitycore.org/>
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
    SPELL_CLEAVE                                  = 15284,
    SPELL_FRIGHTENING_SHOUT                       = 19134,
    SPELL_WHIRLWIND1                              = 15589,
    SPELL_WHIRLWIND2                              = 13736,
    SPELL_MORTAL_STRIKE                           = 16856
};

enum Texts
{
    SAY_AGGRO                                    = 0,
    SAY_EVADE                                    = 1,
    SAY_BUFF                                     = 2
};

enum Events
{
    EVENT_CLEAVE = 1,
    EVENT_FRIGHTENING_SHOUT,
    EVENT_WHIRLWIND1,
    EVENT_WHIRLWIND2,
    EVENT_MORTAL_STRIKE
};

enum Action
{
    ACTION_BUFF_YELL                              = -30001 // shared from Battleground
};

class boss_galvangar : public CreatureScript
{
public:
    boss_galvangar() : CreatureScript("boss_galvangar") { }

    struct boss_galvangarAI : public ScriptedAI
    {
        boss_galvangarAI(Creature* creature) : ScriptedAI(creature) { }

        void Reset() override
        {
            events.Reset();
        }

        void JustEngagedWith(Unit* /*who*/) override
        {
            Talk(SAY_AGGRO);
            events.ScheduleEvent(EVENT_CLEAVE, 1s, 9s);
            events.ScheduleEvent(EVENT_FRIGHTENING_SHOUT, 2s, 19s);
            events.ScheduleEvent(EVENT_WHIRLWIND1, urand(1 * IN_MILLISECONDS, 13 * IN_MILLISECONDS));
            events.ScheduleEvent(EVENT_WHIRLWIND2, urand(5 * IN_MILLISECONDS, 20 * IN_MILLISECONDS));
            events.ScheduleEvent(EVENT_MORTAL_STRIKE, 5s, 20s);
        }

        void DoAction(int32 actionId) override
        {
            if (actionId == ACTION_BUFF_YELL)
                Talk(SAY_BUFF);
        }

        bool CheckInRoom() override
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
                    case EVENT_CLEAVE:
                        DoCastVictim(SPELL_CLEAVE);
                        events.ScheduleEvent(EVENT_CLEAVE, 10s, 16s);
                        break;
                    case EVENT_FRIGHTENING_SHOUT:
                        DoCastVictim(SPELL_FRIGHTENING_SHOUT);
                        events.ScheduleEvent(EVENT_FRIGHTENING_SHOUT, 10s, 15s);
                        break;
                    case EVENT_WHIRLWIND1:
                        DoCastVictim(SPELL_WHIRLWIND1);
                        events.ScheduleEvent(EVENT_WHIRLWIND1, urand(6 * IN_MILLISECONDS, 10 * IN_MILLISECONDS));
                        break;
                    case EVENT_WHIRLWIND2:
                        DoCastVictim(SPELL_WHIRLWIND2);
                        events.ScheduleEvent(EVENT_WHIRLWIND2, urand(10 * IN_MILLISECONDS, 25 * IN_MILLISECONDS));
                        break;
                    case EVENT_MORTAL_STRIKE:
                        DoCastVictim(SPELL_MORTAL_STRIKE);
                        events.ScheduleEvent(EVENT_MORTAL_STRIKE, 10s, 30s);
                        break;
                    default:
                        break;
                }

                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;
            }

            DoMeleeAttackIfReady();
        }

    private:
        EventMap events;
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new boss_galvangarAI(creature);
    }
};

void AddSC_boss_galvangar()
{
    new boss_galvangar;
}
