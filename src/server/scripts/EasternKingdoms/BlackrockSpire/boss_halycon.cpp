/*
 * Copyright (C) 2008-2013 TrinityCore <http://www.trinitycore.org/>
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
#include "blackrock_spire.h"

enum Spells
{
    SPELL_REND                      = 13738,
    SPELL_THRASH                    = 3391,
};

enum Says
{
    EMOTE_DEATH                     = 0
};

enum Events
{
    EVENT_REND                      = 1,
    EVENT_THRASH                    = 2,
};

const Position SummonLocation = { -167.9561f, -411.7844f, 76.23057f, 1.53589f };

class boss_halycon : public CreatureScript
{
public:
    boss_halycon() : CreatureScript("boss_halycon") { }

    struct boss_halyconAI : public BossAI
    {
        boss_halyconAI(Creature* creature) : BossAI(creature, DATA_HALYCON) {}

        void Reset()
        {
            _Reset();
            Summoned = false;
        }

        void EnterCombat(Unit* /*who*/)
        {
            _EnterCombat();
            events.ScheduleEvent(EVENT_REND, urand(17000,20000));
            events.ScheduleEvent(EVENT_THRASH, urand(10000,12000));
        }

        void JustDied(Unit* /*killer*/)
        {
            me->SummonCreature(NPC_GIZRUL_THE_SLAVENER, SummonLocation, TEMPSUMMON_TIMED_DESPAWN, 300000);
            Talk(EMOTE_DEATH);

            Summoned = true;
        }

        void UpdateAI(uint32 diff)
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
                        events.ScheduleEvent(EVENT_REND, urand(8000,10000));
                        break;
                    case EVENT_THRASH:
                        DoCast(me, SPELL_THRASH);
                        break;
                    default:
                        break;
                }
            }
            DoMeleeAttackIfReady();
        }
        private:
            bool Summoned;
    };

    CreatureAI* GetAI(Creature* creature) const
    {
        return new boss_halyconAI(creature);
    }
};

void AddSC_boss_halycon()
{
    new boss_halycon();
}
