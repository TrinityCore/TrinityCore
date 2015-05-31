/*
* Copyright (C) 2008-2015 TrinityCore <http://www.trinitycore.org/>
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

#include <memory>

#include "ScriptMgr.h"
#include "ScriptedCreature.h"

#include "FunctionalScheduler.h"
#include "FunctionalCreatureAI.h"

///////////////////
// Not finished, early prototypes (maybe 1 single SimpleLoader can be used with std::enable_if).
template <class _Script>
class SimpleCreatureScriptLoader : public CreatureScript
{
public:
    SimpleCreatureScriptLoader(char const* scriptname) : CreatureScript(scriptname) { }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new _Script(creature);
    }
};

// This script shows how to use the FunctionScheduler as EventMap replacement.
// Embedded inside a CreatureScript
class npc_legacy_simple_scheduler_test : public CreatureScript
{
public:
    npc_legacy_simple_scheduler_test() : CreatureScript("npc_legacy_simple_scheduler_test") { }

    struct npc_legacy_simple_scheduler_testAI : public CreatureAI
    {
        FunctionScheduler scheduler;

        npc_legacy_simple_scheduler_testAI(Creature* creature) : CreatureAI(creature)
        {
        }

        void Reset() override
        {
            scheduler.CancelAll();
        }

        void EnterCombat(Unit* /*who*/) override
        {
            scheduler.Schedule(Seconds(5), [this](TaskContext /*context*/)
            {
                me->Yell("After 5s", LANG_UNIVERSAL);
            });
        }

        void UpdateAI(uint32 diff) override
        {
            if (!UpdateVictim())
                return;

            scheduler.Update(diff);
            
            DoMeleeAttackIfReady();
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_legacy_simple_scheduler_testAI(creature);
    }
};

struct npc_simple_scheduler_test : public CreatureAI
{
    FunctionScheduler scheduler;

    bool outro;

    npc_simple_scheduler_test(Creature* creature) : CreatureAI(creature)
    {
    }

    void Reset() override
    {
        // Cancel all tasks
        scheduler.CancelAll();

        outro = false;

        me->SetReactState(REACT_AGGRESSIVE);
    }

    void EnterCombat(Unit* /*who*/) override
    {
        me->Yell("Mh who is that...", LANG_UNIVERSAL);

        // Schedule a simple task that gets executed once in 5 seconds.
        // As time unit std::chrono::duration is used which offers typedef for common used timeunits.
        // No magic milliseconds anymore!
        scheduler.Schedule(Seconds(5), [this](TaskContext /*context*/)
        {
            me->Yell("After 5s", LANG_UNIVERSAL);
        });
    }

    void UpdateAI(uint32 diff) override
    {
        if (!outro)
            if (!UpdateVictim())
                return;

        // Update the scheduler with an offset, world update tick is in ms.
        scheduler.Update(diff);

        if (!outro)
            DoMeleeAttackIfReady();
    }

    void DamageTaken(Unit* /*attacker*/, uint32& damage)
    {
        if (!outro && (damage >= me->GetHealth()))
        {
            damage = 0;
            outro = true;

            me->SetReactState(REACT_PASSIVE);

            me->Yell("Outro....!", LANG_UNIVERSAL);

            // A simple outro event is scheduled here.
            // TaskContext offers several methods to repeat the event (same time, constant time/ random time).
            //
            // The task also provides a repeat counter which repeats
            // how often the task was repeated (best to use with dialogs or events).
            scheduler.Schedule(Seconds(3), [this](TaskContext context)
            {
                switch (context->GetRepeatCounter())
                {
                    case 0:
                        me->Yell("O shit!", LANG_UNIVERSAL);
                        context->Repeat(Seconds(3));
                        return;
                    case 1:
                        me->Yell("I see it was a mistake to fight you.", LANG_UNIVERSAL);
                        break;
                    case 2:
                        me->Yell("There is no loot you can get today, sorry!", LANG_UNIVERSAL);
                        break;
                    case 3:
                        me->Yell("See YA!", LANG_UNIVERSAL);
                        break;
                    default:
                        me->DisappearAndDie();
                        return;
                }

                /////////
                // Repeat the event with...

                // ... the same time again
                // context->Repeat();

                // ... a constant time
                // context->Repeat(Seconds(4));

                // ... a random time between min and max
                context->Repeat(Seconds(4), Seconds(6));
            });
        }
        else if (outro)
            damage = 0;
    }
};

struct npc_simple_functional_ai_test : public FunctionalCreatureAI
{
    npc_simple_functional_ai_test(Creature* creature) : FunctionalCreatureAI(creature)
    {
        // Smart overloaded, accepts OnEnterCombatEvent, OnJustDiedEvent and so on...
        AddListener([this](OnEnterCombatEvent& event)
        {
            me->Yell("Hey, OnEnterCombatEvent was thrown!", LANG_UNIVERSAL);

            // Access to the actual event parameters through the struct.
            // event.victim->GetTypeId()

            // We could modify the parameters without changing any script.
            // It also benefits from code completion, just write On... in your completion box and every event is listed.
            // You can change events with ease, just change the name of the struct.
        });
    }

    // Ands it not possible anymore to override
    // void EnterCombat(Unit* victim) { }
    // because it is marked as final.

    void UpdateAI(uint32 /*diff*/) override
    {
        if (!UpdateVictim())
            return;

        DoMeleeAttackIfReady();
    }
};

void AddSC_functional_ai_tests()
{
    new npc_legacy_simple_scheduler_test();

    // In nearly every script CreatureAI is wrapped inside a CreatureScript, this approach removes a lot of duplicated code.
    // SimpleLoaders wrap its AI into the corresponding loading script.
    new SimpleCreatureScriptLoader<npc_simple_scheduler_test>("npc_simple_scheduler_test");
    new SimpleCreatureScriptLoader<npc_simple_functional_ai_test>("npc_simple_functional_ai_test");
}
