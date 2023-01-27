/*
 * Copyright (C) 2022 BfaCore Reforged
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
#include "PassiveAI.h"
#include "ragefire_chasm.h"

class boss_taragaman_the_hungerer : public CreatureScript
{
public:
    boss_taragaman_the_hungerer() : CreatureScript("boss_taragaman_the_hungerer") { }

    struct boss_taragaman_the_hungererAI : public BossAI
    {
        boss_taragaman_the_hungererAI(Creature* creature) : BossAI(creature, BOSS_TARAGAMAN_THE_HUNGERER)
        {
            m_instance = creature->GetInstanceScript();
        }

        InstanceScript* m_instance;
        EventMap m_events;
        uint8 m_phase;

        void Reset()
        {
            m_events.Reset();
            m_events.ScheduleEvent(1, 10000);
            m_phase = 0;
            if (instance->GetData(BOSS_TARAGAMAN_THE_HUNGERER) == TO_BE_DECIDED)
                instance->SetData(BOSS_TARAGAMAN_THE_HUNGERER, NOT_STARTED);
        }

        void EnterCombat(Unit* /*who*/)
        {
            instance->SetData(BOSS_TARAGAMAN_THE_HUNGERER, IN_PROGRESS);
        }

        void DamageTaken(Unit* /*attacker*/, uint32& damage)
        {
        }

        void JustDied(Unit* Killer)
        {
            instance->SetData(BOSS_TARAGAMAN_THE_HUNGERER, DONE);
        }

        void KilledUnit(Unit* Victim)
        {
        }

        void UpdateAI(uint32 diff)
        {
            m_events.Update(diff);
            while (uint32 eventId = m_events.ExecuteEvent())
            {
                switch (eventId)
                {
                case 1:
                {
                    // if (GameObject* door = ObjectAccessor::GetGameObject(*me, m_instance->GetData64(DATA_FACTORY_DOOR)))
                    // door->UseDoorOrButton();



                    m_events.ScheduleEvent(1, 10000);
                    break;
                }
                }
            }

            if (!UpdateVictim())
                return;
        }
    };

    CreatureAI* GetAI(Creature* creature) const
    {
        return GetRagefireChasmAI<boss_taragaman_the_hungererAI>(creature);
    }
};

void AddSC_boss_taragaman_the_hungerer()
{
    new boss_taragaman_the_hungerer();
}

