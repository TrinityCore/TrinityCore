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
#include "zulaman.h"

enum Says
{
    SAY_AGGRO               = 0,
    SAY_PLAYER_KILL         = 1,
    EMOTE_ELECTRICAL_STORM  = 2,
    SAY_SUMMON_EAGLE        = 3,
    SAY_SUMMON_BIRDS        = 4,
    SAY_BERSERK             = 5,
    SAY_DEATH               = 6
};

enum Spells
{
};

enum Events
{
};

enum Events
{
    EVENT_STATIC_DISRUPTION     = 1,
    EVENT_GUST_OF_WIND          = 2,
    EVENT_CALL_LIGHTNING        = 3,
    EVENT_ELECTRICAL_STORM      = 4,
    EVENT_RAIN                  = 5,
    EVENT_SUMMON_EAGLES         = 6,
    EVENT_STORM_SEQUENCE        = 7,
    EVENT_ENRAGE                = 8
};

class boss_akilzon : public CreatureScript
{
    public:
        boss_akilzon() : CreatureScript("boss_akilzon") { }

        boss_akilzon() : CreatureScript("boss_akilzon") { }

        struct boss_akilzonAI : public BossAI
        {
            boss_akilzonAI(Creature* creature) : BossAI(creature, DATA_AKILZON) { }

            void Reset()
            {
                _Reset();
            }

            void EnterCombat(Unit* /*who*/)
            {
                events.ScheduleEvent(EVENT_STATIC_DISRUPTION, urand(10000, 20000)); // 10 to 20 seconds (bosskillers)
                events.ScheduleEvent(EVENT_GUST_OF_WIND, urand(20000, 30000));      // 20 to 30 seconds(bosskillers)
                events.ScheduleEvent(EVENT_CALL_LIGHTNING, urand(10000, 20000));    // totaly random timer. can't find any info on this
                events.ScheduleEvent(EVENT_ELECTRICAL_STORM, 60000);                // 60 seconds(bosskillers)
                events.ScheduleEvent(EVENT_RAIN, urand(47000, 52000));
                events.ScheduleEvent(EVENT_ENRAGE, 10*MINUTE*IN_MILLISECONDS);      // 10 minutes till enrage(bosskillers)

                Talk(SAY_AGGRO);
                _EnterCombat();
            }

            void JustDied(Unit* /*killer*/)
            {
                Talk(SAY_DEATH);
                _JustDied();
            }

            void KilledUnit(Unit* victim)
            {
                if (victim->GetTypeId() == TYPEID_PLAYER)
                    Talk(SAY_PLAYER_KILL);
            }

            void UpdateAI(uint32 diff)
            {
                if (!UpdateVictim())
                    return;

                events.Update(diff);

                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;
                /*
                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        default:
                            break;
                    }
                }
                */

                DoMeleeAttackIfReady();
            }

            private:
                uint64 BirdGUIDs[8];
                uint64 TargetGUID;
                uint64 CycloneGUID;
                uint64 CloudGUID;
                uint8  StormCount;
                bool   isRaining;
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return GetZulAmanAI<boss_akilzonAI>(creature);
        }
};

void AddSC_boss_akilzon()
{
    new boss_akilzon();
}
