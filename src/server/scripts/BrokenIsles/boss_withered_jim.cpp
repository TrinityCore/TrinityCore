/*
* Copyright (C) 2008-2017 TrinityCore <http://www.trinitycore.org/>
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
#include "Player.h"
#include "ObjectMgr.h"
#include "ObjectAccessor.h"
#include "SpellInfo.h"

enum WitheredJim
{
    NPC_ENTRY_WITHERED_JIM_CLONE              = 112350,
    NPC_ENTRY_WITHERED_JIM                    = 102075,
    NPC_ENTRY_NIGHTSTABLE_ENERGY              = 112342,

    SPELL_WITHERED_PRESENCE_AREA_TRIGGER      = 223632,
    SPELL_WITHERED_PRESENCE_BUFF              = 223599,
    SPELL_MORE_MORE_MORE                      = 223715,
    SPELL_MORE_MORE_MORE_TRIGGERED            = 223723,
    SPELL_NIGHTSHIFTED_BOLTS                  = 223623,
    SPELL_RESONANCE                           = 223614,
    SPELL_NIGHTSTABLE_ENERGY                  = 223689
};

enum WitheredJimEvents
{
    EVENT_NIGHTSHIFTED_BOLTS = 0,
    EVENT_RESONANCE          = 1,
    EVENT_NIGHTSTABLE_ENERGY = 2,
    EVENT_MORE_MORE_MORE     = 3,
    EVENT_SUMMON_CLONE       = 4
};

#define CLONE_MAX_COUNT 5

class boss_withered_jim : public CreatureScript
{
public:
    boss_withered_jim() : CreatureScript("boss_withered_jim") {}

    struct boss_withered_jimAI : public ScriptedAI
    {
        boss_withered_jimAI(Creature* creature) : ScriptedAI(creature), summons(me), countclons(0)
        {
        }

        EventMap events;
        SummonList summons;
        uint8 countclons;
        
        void Reset() override
        {
            events.Reset();
            summons.DespawnAll();
            countclons = 0;
        }
        
        void EnterCombat(Unit* unit) override
        {
            events.ScheduleEvent(EVENT_NIGHTSHIFTED_BOLTS, 18000);
            events.ScheduleEvent(EVENT_RESONANCE, 24000);
            events.ScheduleEvent(EVENT_NIGHTSTABLE_ENERGY, 22000);
            if (me->GetEntry() == NPC_ENTRY_WITHERED_JIM)
                events.ScheduleEvent(EVENT_MORE_MORE_MORE, 30000);
            DoCast(SPELL_WITHERED_PRESENCE_AREA_TRIGGER); // AT
            DoCast(SPELL_WITHERED_PRESENCE_BUFF);
        }  
        
        void JustSummoned(Creature* summon) override
        {
            summons.Summon(summon);  
            DoZoneInCombat(me, 150.0f);
            if (summon->GetEntry() == NPC_ENTRY_WITHERED_JIM_CLONE)
                summon->CastSpell(summon, SPELL_WITHERED_PRESENCE_BUFF);
            if (summon->GetEntry() == NPC_ENTRY_NIGHTSTABLE_ENERGY)
                summon->DespawnOrUnsummon(9000);
        }

        void JustDied(Unit* who) override
        {
            summons.DespawnAll();
        }
                
        void DamageTaken(Unit* attacker, uint32& /*damage*/) override
        {
            if (attacker->GetTypeId() != TYPEID_PLAYER)
                return;
            
            if (attacker->GetPositionZ() >= 60.0f)
                me->Kill(attacker); //cheaters and others
        }
              
        void UpdateAI(uint32 diff) override
        {
            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;
            
            if (!UpdateVictim())
                return;

            events.Update(diff);
            
            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case EVENT_NIGHTSHIFTED_BOLTS:
                        DoCast(SPELL_NIGHTSHIFTED_BOLTS);
                        events.ScheduleEvent(EVENT_NIGHTSHIFTED_BOLTS, urand(25000, 30000));
                        break;
                    case EVENT_RESONANCE:
                        DoCast(SPELL_RESONANCE);
                        events.ScheduleEvent(EVENT_NIGHTSHIFTED_BOLTS, urand(24000, 30000));
                        break;
                    case EVENT_NIGHTSTABLE_ENERGY:
                        DoCast(SPELL_NIGHTSTABLE_ENERGY);
                        events.ScheduleEvent(EVENT_NIGHTSHIFTED_BOLTS, urand(29000, 34000));
                        break;
                    case EVENT_MORE_MORE_MORE:
                        ++countclons;
                        DoCast(SPELL_MORE_MORE_MORE);
                        if (countclons < CLONE_MAX_COUNT)
                            events.ScheduleEvent(EVENT_MORE_MORE_MORE, 30000);
                        events.ScheduleEvent(EVENT_SUMMON_CLONE, 1000);
                        break;
                    case EVENT_SUMMON_CLONE:
                        if (me->HasAura(SPELL_MORE_MORE_MORE))
                            events.ScheduleEvent(EVENT_SUMMON_CLONE, 1000);
                        else
                        {
                            if (Creature* clone = me->SummonCreature(NPC_ENTRY_WITHERED_JIM_CLONE, me->GetPositionX(), me->GetPositionY(), me->GetPositionZ(), me->GetOrientation()))
                                clone->CastSpell(clone, SPELL_MORE_MORE_MORE_TRIGGERED);
                        }
                        break;
                }
            }
            
            DoMeleeAttackIfReady();
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new boss_withered_jimAI(creature);
    }
};


void AddSC_boss_withered_jim()
{
     new boss_withered_jim();
}
