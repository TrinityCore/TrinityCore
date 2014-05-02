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
#include "culling_of_stratholme.h"

enum Spells
{
    SPELL_CORRUPTING_BLIGHT                     = 60588,
    SPELL_VOID_STRIKE                           = 60590,

    SPELL_CORRUPTION_OF_TIME_CHANNEL            = 60422,
    SPELL_CORRUPTION_OF_TIME_TARGET             = 60451
};

enum Yells
{
    SAY_AGGRO                                   = 0,
    SAY_DEATH                                   = 1,
    SAY_FAIL                                    = 2,

    SAY_SUCCESS                                 = 0
};

enum Events
{
    EVENT_CORRUPTING_BLIGHT                     = 1,
    EVENT_VOID_STRIKE                           = 2
};

class boss_infinite_corruptor : public CreatureScript
{
public:
    boss_infinite_corruptor() : CreatureScript("boss_infinite_corruptor") { }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return GetInstanceAI<boss_infinite_corruptorAI>(creature);
    }

    struct boss_infinite_corruptorAI : public ScriptedAI
    {
        boss_infinite_corruptorAI(Creature* creature) : ScriptedAI(creature)
        {
            instance = creature->GetInstanceScript();
        }

        InstanceScript* instance;
        EventMap events;

        void Reset() override
        {
            instance->SetData(DATA_INFINITE_EVENT, NOT_STARTED);

            if (Creature* guardian = me->FindNearestCreature(NPC_GUARDIAN_OF_TIME, 30.0f))
                DoCast(guardian, SPELL_CORRUPTION_OF_TIME_CHANNEL, false);
        }

        void EnterCombat(Unit* /*who*/) override
        {
            Talk(SAY_AGGRO);
            instance->SetData(DATA_INFINITE_EVENT, IN_PROGRESS);

            events.ScheduleEvent(EVENT_CORRUPTING_BLIGHT, 20*IN_MILLISECONDS);
            events.ScheduleEvent(EVENT_VOID_STRIKE, 15*IN_MILLISECONDS);         
        }

        void UpdateAI(uint32 diff) override
        {
            //Return since we have no target
            if (!UpdateVictim())
                return;

            events.Update(diff);

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch(eventId)
                {
                    case EVENT_CORRUPTING_BLIGHT:
                        DoCast(SelectTarget(SELECT_TARGET_RANDOM), SPELL_CORRUPTING_BLIGHT);
                        events.ScheduleEvent(EVENT_CORRUPTING_BLIGHT, 20*IN_MILLISECONDS);
                        break;
                    case EVENT_VOID_STRIKE:
                        DoCastVictim(SPELL_VOID_STRIKE);
                        events.ScheduleEvent(EVENT_VOID_STRIKE, 15*IN_MILLISECONDS);
                        break;
                }
            }

            DoMeleeAttackIfReady();
        }

        void JustDied(Unit* /*killer*/) override
        {
            Talk(SAY_DEATH);
            instance->SetData(DATA_INFINITE_EVENT, DONE);
            
            if (Creature* guardian = me->FindNearestCreature(NPC_GUARDIAN_OF_TIME, 100.0f))
            {
                guardian->RemoveAurasDueToSpell(SPELL_CORRUPTION_OF_TIME_TARGET);
                guardian->AI()->Talk(SAY_SUCCESS);
                guardian->DespawnOrUnsummon(5*IN_MILLISECONDS);
            }

            if (Creature* rift = me->FindNearestCreature(NPC_TIME_RIFT, 100.0f))
                rift->DespawnOrUnsummon();

        }
    };

};

void AddSC_boss_infinite_corruptor()
{
    new boss_infinite_corruptor();
}
