/*
 * Copyright (C) 2022 BfaCore Reforged
 *
 * This SourceCode is NOT free a software. Please hold everything Private
 * and read our Terms
 */

#include "ScriptMgr.h"
#include "ScriptedCreature.h"

enum Spells
{
    SPELL_SHADOW_STORM     = 119971,
    SPELL_TWISTED_ELEMENTS = 119300
};

enum Events
{
    EVENT_STORM,
    EVENT_ELEMENTS
};

class boss_koranthal : public CreatureScript
{
    public:
        boss_koranthal() : CreatureScript("boss_koranthal") { }

        struct boss_koranthalAI : public ScriptedAI
        {
            boss_koranthalAI(Creature* creature) : ScriptedAI(creature) { }

            void Reset() { }

            void EnterCombat(Unit* /*who*/)
            {
                events.ScheduleEvent(EVENT_STORM, 10000);
                events.ScheduleEvent(EVENT_ELEMENTS, 8000);
            }

            void JustDied(Unit* /*killer*/) { }

            void UpdateAI(uint32 const diff)
            {
                if(!UpdateVictim())
                    return;

                events.Update(diff);

                if(me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                if(uint32 eventId = events.ExecuteEvent())
                {
                    switch(eventId)
                    {
                        case EVENT_STORM:
                            DoCast(me, SPELL_SHADOW_STORM, false);
                            events.ScheduleEvent(EVENT_STORM, 15*IN_MILLISECONDS);
                            break;
                        case EVENT_ELEMENTS:
                            DoCastVictim(SPELL_TWISTED_ELEMENTS);
                            events.ScheduleEvent(EVENT_ELEMENTS, 8*IN_MILLISECONDS);
                            break;
                        default:
                            break;
                    }
                }
                DoMeleeAttackIfReady();
            }
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new boss_koranthalAI(creature);
        }
};

void AddSC_boss_koranthal()
{
    new boss_koranthal();
}
