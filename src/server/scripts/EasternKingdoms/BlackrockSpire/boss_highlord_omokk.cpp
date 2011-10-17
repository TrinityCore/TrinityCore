/*
 * Copyright (C) 2008-2011 TrinityCore <http://www.trinitycore.org/>
 * Copyright (C) 2006-2009 ScriptDev2 <https://scriptdev2.svn.sourceforge.net/>
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
    SPELL_WARSTOMP                  = 24375,
    SPELL_CLEAVE                    = 15579,
    SPELL_STRIKE                    = 18368,
    SPELL_REND                      = 18106,
    SPELL_SUNDERARMOR               = 24317,
    SPELL_KNOCKAWAY                 = 20686,
    SPELL_SLOW                      = 22356,
};

enum Events
{
    EVENT_WARSTOMP                  = 1,
    EVENT_CLEAVE                    = 2,
    EVENT_STRIKE                    = 3,
    EVENT_REND                      = 4,
    EVENT_SUNDER_ARMOR              = 5,
    EVENT_KNOCK_AWAY                = 6,
    EVENT_SLOW                      = 7,
};

class boss_highlord_omokk : public CreatureScript
{
public:
    boss_highlord_omokk() : CreatureScript("boss_highlord_omokk") { }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new boss_highlordomokkAI(creature);
    }

    struct boss_highlordomokkAI : public BossAI
    {
        boss_highlordomokkAI(Creature* creature) : BossAI(creature, DATA_OMOKK) {}

        void Reset()
        {
            _Reset();
        }

        void EnterCombat(Unit* /*who*/)
        {
            _EnterCombat();
            events.ScheduleEvent(EVENT_WARSTOMP, 15 * IN_MILLISECONDS);
            events.ScheduleEvent(EVENT_CLEAVE,    6 * IN_MILLISECONDS);
            events.ScheduleEvent(EVENT_STRIKE,   10 * IN_MILLISECONDS);
            events.ScheduleEvent(EVENT_REND,     14 * IN_MILLISECONDS);
            events.ScheduleEvent(EVENT_SUNDER_ARMOR, 2 * IN_MILLISECONDS);
            events.ScheduleEvent(EVENT_KNOCK_AWAY,  18 * IN_MILLISECONDS);
            events.ScheduleEvent(EVENT_SLOW, 24 * IN_MILLISECONDS);
        }

        void JustDied(Unit* /*who*/)
        {
            _JustDied();
        }

        void UpdateAI(uint32 const diff)
        {
            if (!UpdateVictim())
                return;

            events.Update(diff);

            if (me->HasUnitState(UNIT_STAT_CASTING))
                return;

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case EVENT_WARSTOMP:
                        DoCast(me->getVictim(), SPELL_WARSTOMP);
                        events.ScheduleEvent(EVENT_WARSTOMP, 14 * IN_MILLISECONDS);
                        break;
                    case EVENT_CLEAVE:
                        DoCast(me->getVictim(), SPELL_CLEAVE);
                        events.ScheduleEvent(EVENT_CLEAVE, 8 * IN_MILLISECONDS);
                        break;
                    case EVENT_STRIKE:
                        DoCast(me->getVictim(), SPELL_STRIKE);
                        events.ScheduleEvent(EVENT_STRIKE, 10 * IN_MILLISECONDS);
                        break;
                    case EVENT_REND:
                        DoCast(me->getVictim(), SPELL_REND);
                        events.ScheduleEvent(EVENT_REND, 18 * IN_MILLISECONDS);
                        break;
                    case EVENT_SUNDER_ARMOR:
                        DoCast(me->getVictim(), SPELL_SUNDERARMOR);
                        events.ScheduleEvent(EVENT_SUNDER_ARMOR, 25 * IN_MILLISECONDS);
                        break;
                    case EVENT_KNOCK_AWAY:
                        DoCast(me->getVictim(), SPELL_KNOCKAWAY);
                        events.ScheduleEvent(EVENT_KNOCK_AWAY, 12 * IN_MILLISECONDS);
                        break;
                    case EVENT_SLOW:
                        DoCast(me->getVictim(), SPELL_SLOW);
                        events.ScheduleEvent(EVENT_SLOW, 18 * IN_MILLISECONDS);
                        break;
                }
            }
            DoMeleeAttackIfReady();
        }
    };

};

void AddSC_boss_highlordomokk()
{
    new boss_highlord_omokk();
}
