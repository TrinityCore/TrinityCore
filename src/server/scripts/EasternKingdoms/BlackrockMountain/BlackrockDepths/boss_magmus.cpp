/*
 * Copyright (C) 2008-2014 TrinityCore <http://www.trinitycore.org/>
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

enum Spells
{
    SPELL_FIERYBURST                                       = 13900,
    SPELL_WARSTOMP                                         = 24375
};

enum Events
{
    EVENT_FIERY_BURST                                      = 1,
    EVENT_WARSTOMP                                         = 2
};

enum Misc
{
    DATA_THRONE_DOOR                                       = 24 // not id or guid of doors but number of enum in blackrock_depths.h
};

class boss_magmus : public CreatureScript
{
public:
    boss_magmus() : CreatureScript("boss_magmus") { }

    CreatureAI* GetAI(Creature* creature) const OVERRIDE
    {
        return new boss_magmusAI(creature);
    }

    struct boss_magmusAI : public ScriptedAI
    {
        boss_magmusAI(Creature* creature) : ScriptedAI(creature) { }

        void Reset() OVERRIDE
        {
            _events.ScheduleEvent(EVENT_FIERY_BURST, 5000);
            _phaseTwo = false;
        }

        void DamageTaken(Unit* /*attacker*/, uint32& /*damage*/) OVERRIDE
        {
            if (!HealthAbovePct(50) && !_phaseTwo)
            {
                _phaseTwo = true;
                _events.ScheduleEvent(EVENT_WARSTOMP, 0);
            }
        }

        void UpdateAI(uint32 diff) OVERRIDE
        {
            //Return since we have no target
            if (!UpdateVictim())
                return;

            _events.Update(diff);

            while (uint32 eventId = _events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case EVENT_FIERY_BURST:
                        DoCastVictim(SPELL_FIERYBURST);
                        _events.ScheduleEvent(EVENT_FIERY_BURST, 6000);
                        break;
                    case EVENT_WARSTOMP:
                        DoCastVictim(SPELL_WARSTOMP);
                        _events.ScheduleEvent(EVENT_WARSTOMP, 8000);
                        break;
                }
            }

            DoMeleeAttackIfReady();
        }
        // When he dies open door to last chamber
        void JustDied(Unit* killer) OVERRIDE
        {
            if (InstanceScript* instance = killer->GetInstanceScript())
                instance->HandleGameObject(instance->GetData64(DATA_THRONE_DOOR), true);
        }
        private:
            EventMap _events;
            bool _phaseTwo; // Sub-50% Phase
    };
};

void AddSC_boss_magmus()
{
    new boss_magmus();
}
