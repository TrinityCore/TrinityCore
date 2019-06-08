/*
 * Copyright (C) 2008-2019 TrinityCore <https://www.trinitycore.org/>
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

#include "zulgurub.h"
#include "ScriptedCreature.h"
#include "ScriptMgr.h"

enum Spells
{
    SPELL_FROSTBREATH = 16099,
    SPELL_MASSIVEGEYSER = 22421, // Not working. (summon)
    SPELL_SLAM = 24326
};

enum Events
{
    EVENT_FROSTBREATH = 1,
    EVENT_MASSIVEGEYSER = 2,
    EVENT_SLAM = 3
};

class boss_gahzranka : public CreatureScript // gahzranka
{
    public:
        boss_gahzranka() : CreatureScript("boss_gahzranka") { }

        struct boss_gahzrankaAI : public BossAI
        {
            boss_gahzrankaAI(Creature* creature) : BossAI(creature, DATA_GAHZRANKA) { }

            void Reset() override
            {
                _Reset();
            }

            void JustDied(Unit* /*killer*/) override
            {
                _JustDied();
            }

            void JustEngagedWith(Unit* /*who*/) override
            {
                _JustEngagedWith();
                events.ScheduleEvent(EVENT_FROSTBREATH, 8s);
                events.ScheduleEvent(EVENT_MASSIVEGEYSER, 25s);
                events.ScheduleEvent(EVENT_SLAM, 15s);
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
                        case EVENT_FROSTBREATH:
                            DoCastVictim(SPELL_FROSTBREATH, true);
                            events.ScheduleEvent(EVENT_FROSTBREATH, 7s, 11s);
                            break;
                        case EVENT_MASSIVEGEYSER:
                            DoCastVictim(SPELL_MASSIVEGEYSER, true);
                            events.ScheduleEvent(EVENT_MASSIVEGEYSER, 22s, 32s);
                            break;
                        case EVENT_SLAM:
                            DoCastVictim(SPELL_SLAM, true);
                            events.ScheduleEvent(EVENT_SLAM, 12s, 20s);
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
            return GetZulGurubAI<boss_gahzrankaAI>(creature);
        }
};

void AddSC_boss_gahzranka()
{
    new boss_gahzranka();
}
