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

#include "blackrock_spire.h"

enum Spells
{
    SPELL_CROWDPUMMEL               = 10887,
    SPELL_MIGHTYBLOW                = 14099,
};

enum Events
{
    EVENT_CROWD_PUMMEL              = 1,
    EVENT_MIGHTY_BLOW               = 2,
};

const Position SummonLocation = { -169.839f, -324.961f, 64.401f, 3.124f };

class boss_halycon : public CreatureScript
{
public:
    boss_halycon() : CreatureScript("boss_halycon") { }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new boss_halyconAI(creature);
    }

    struct boss_halyconAI : public BossAI
    {
        boss_halyconAI(Creature* creature) : BossAI(creature, DATA_HALYCON) {}

        bool Summoned;

        void Reset()
        {
            _Reset();
            Summoned = false;
        }

        void EnterCombat(Unit* /*who*/)
        {
            _EnterCombat();
            events.ScheduleEvent(EVENT_CROWD_PUMMEL, 8*IN_MILLISECONDS);
            events.ScheduleEvent(EVENT_MIGHTY_BLOW, 14*IN_MILLISECONDS);
        }

        void JustDied(Unit* /*who*/)
        {
            _JustDied();
        }

        void UpdateAI(uint32 const diff)
        {
            if (!UpdateVictim())
                return;

            //Summon Gizrul
            if (!Summoned && HealthBelowPct(25))
            {
                me->SummonCreature(NPC_GIZRUL_THE_SLAVENER, SummonLocation, TEMPSUMMON_TIMED_DESPAWN, 300*IN_MILLISECONDS);
                Summoned = true;
            }

            events.Update(diff);

            if (me->HasUnitState(UNIT_STAT_CASTING))
                return;

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case EVENT_CROWD_PUMMEL:
                        DoCast(me->getVictim(), SPELL_CROWDPUMMEL);
                        events.ScheduleEvent(EVENT_CROWD_PUMMEL, 14*IN_MILLISECONDS);
                        break;
                    case EVENT_MIGHTY_BLOW:
                        DoCast(me->getVictim(), SPELL_MIGHTYBLOW);
                        events.ScheduleEvent(EVENT_MIGHTY_BLOW, 10*IN_MILLISECONDS);
                        break;
                }
            }
            DoMeleeAttackIfReady();
        }
    };

};

void AddSC_boss_halycon()
{
    new boss_halycon();
}
