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

class boss_oggleflint : public CreatureScript
{
public:
    boss_oggleflint() : CreatureScript("boss_oggleflint") { }

    struct boss_oggleflintAI : public BossAI
    {
        boss_oggleflintAI(Creature* creature) : BossAI(creature, BOSS_OGGLEFLINT)
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
            
            if (instance->GetData(BOSS_OGGLEFLINT) == TO_BE_DECIDED)
                instance->SetData(BOSS_OGGLEFLINT, NOT_STARTED);
        }

        void EnterCombat(Unit* /*who*/)
        {
            instance->SetData(BOSS_OGGLEFLINT, IN_PROGRESS);
        }

        void DamageTaken(Unit* /*attacker*/, uint32& damage)
        {
        }

        void JustDied(Unit* Killer)
        {
            instance->SetData(BOSS_OGGLEFLINT, DONE);
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
            DoMeleeAttackIfReady();

        }
    };

    CreatureAI* GetAI(Creature* creature) const
    {
        return GetRagefireChasmAI<boss_oggleflintAI>(creature);
    }
};

void AddSC_boss_oggleflint()
{
    new boss_oggleflint();
}

