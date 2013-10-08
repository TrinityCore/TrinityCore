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
 
#include "the_vortex_pinnacle.h"
#include "ScriptMgr.h"
#include "ScriptedCreature.h"

enum Texts
{
    SAY_AGGRO                 = 0,
    SAY_SLAY                  = 1,
    SAY_DEATH                 = 2,
    SAY_FIELD                 = 3
};

enum Spells
{
    SPELL_CHAIN_LIGHTNING             = 87622,
    SPELL_SUPREMACY_OF_THE_STORM      = 86930,
    SPELL_UNSESTABLE_GROUNDING_FIELD  = 86911,
    SPELL_STATIC_CLING                = 87618,    // Heroic
    
    SPELL_ARCANE_BARRAGE              = 87845
};

enum Events
{
    EVENT_CHAIN_LIGHTNING             = 1,
    EVENT_SUPREMACY_OF_THE_STORM      = 2,
    EVENT_UNSESTABLE_GROUNDING_FIELD  = 3,
    EVENT_STATIC_CLING                = 4,       // Heroic
    EVENT_SUMMON_SKYFALL_STAR         = 5
};

class boss_asaad : public CreatureScript
{
    public:
    boss_asaad() : CreatureScript("boss_asaad") {}
	
    struct boss_asaadAI : public BossAI
    {
        boss_asaadAI(Creature* creature) : BossAI(creature, DATA_ASAAD) {}
		
        void Reset() OVERRIDE
        {
           _Reset();
        }
		
        void EnterCombat(Unit* /*who*/) OVERRIDE
	{
	    _EnterCombat();
	    Talk(SAY_AGGRO);
	    events.ScheduleEvent(EVENT_CHAIN_LIGHTNING, 15000);
	    events.ScheduleEvent(EVENT_SUPREMACY_OF_THE_STORM, 15000);
	    events.ScheduleEvent(EVENT_UNSESTABLE_GROUNDING_FIELD, 10000);
	    if(IsHeroic()) events.ScheduleEvent(EVENT_STATIC_CLING, 20000);
	    events.ScheduleEvent(EVENT_SUMMON_SKYFALL_STAR, 30000);
	}
		
        void JustDied(Unit* /*killer*/) OVERRIDE
	{
	    _JustDied();
	    Talk(SAY_DEATH);
	}
		
	void KilledUnit(Unit* who) OVERRIDE
	{
	    if (who->GetTypeId() == TYPEID_PLAYER) Talk(SAY_SLAY);         
	}
		
	void UpdateAI(uint32 diff) OVERRIDE
	{
	    if (!UpdateVictim()) return;
			
	    events.Update(diff);
			
	    while(uint32 eventId = events.ExecuteEvent())
	    {
	        switch(eventId)
		{
	        case EVENT_CHAIN_LIGHTNING:
	            if(Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 100, true))
                    {
	                DoCast(target, SPELL_CHAIN_LIGHTNING, true);
	            }
                    events.ScheduleEvent(EVENT_CHAIN_LIGHTNING, 15000);
                    break;
                case EVENT_SUPREMACY_OF_THE_STORM:
                    events.ScheduleEvent(EVENT_SUPREMACY_OF_THE_STORM, 15000);
                    break;
                case EVENT_UNSESTABLE_GROUNDING_FIELD:
                    Talk(SAY_FIELD);
                    events.ScheduleEvent(EVENT_UNSESTABLE_GROUNDING_FIELD, 10000);
                    break;
                case EVENT_STATIC_CLING:
                    events.ScheduleEvent(EVENT_STATIC_CLING, 20000);
                    break;
                case EVENT_SUMMON_SKYFALL_STAR:
                    if(Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 100, true))
                    {
                        float posX = target->GetPositionX();
                        float posY = target->GetPositionY();
                        float posZ = target->GetPositionZ();
                        Position const sumpos = {posX, posY, posZ};
                        Creature *star = me->SummonCreature(NPC_SKYFALL_STAR, sumpos, TEMPSUMMON_CORPSE_TIMED_DESPAWN, 1000);
                    }
                    events.ScheduleEvent(EVENT_SUMMON_SKYFALL_STAR, 30000);
                    break;
                }
            }
			
            DoMeleeAttackIfReady();
        }
    };

    CreatureAI* GetAI(Creature* creature) const OVERRIDE
    {
        return GetTheVortexPinnacleAI<boss_asaadAI>(creature);
    }
};

class npc_skyfall_star : public CreatureScript
{
    public:
    npc_skyfall_star() : CreatureScript("npc_skyfall_star") {}
	
    struct npc_skyfall_starAI  : public ScriptedAI
    {
        npc_skyfall_starAI(Creature* creature) : ScriptedAI(creature) {}
    
        void Reset() OVERRIDE
        {
	    DoCast(me, SPELL_ARCANE_BARRAGE, true);
        }
		
        void UpdateAI(uint32 diff) OVERRIDE
        {
            if(me->GetInstanceScript()->GetBossState(DATA_GRAND_VIZIER_ERTAN) == NOT_STARTED || me->GetInstanceScript()->GetBossState(DATA_GRAND_VIZIER_ERTAN) == DONE) me->DespawnOrUnsummon(); 
            if (!UpdateVictim()) return;
			
            DoMeleeAttackIfReady();
        }
    };
	
    CreatureAI* GetAI(Creature* creature) const OVERRIDE
    {
        return new npc_skyfall_starAI(creature);
    }
};

void AddSC_boss_asaad()
{
    new boss_asaad();
    new npc_skyfall_star();
}
