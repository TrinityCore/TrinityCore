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
#include "Player.h"

enum Texts
{
};

enum Spells
{
    //SPELL_CALL_THE_WIND   = 88244, 88276, 88772,    // ?
    SPELL_CHILLING_BREATH = 88308,
    SPELL_LIGHTING_BLAST  = 88357
};

enum Events
{
    EVENT_CALL_THE_WIND      = 1,
    EVENT_CHILLING_BREATH    = 2,
    EVENT_LIGHTING_BLAST     = 3   
};

class boss_altairus : public CreatureScript
{
    public:
    boss_altairus() : CreatureScript("boss_altairus") {}
	
    struct boss_altairusAI : public BossAI
    {
        boss_altairusAI(Creature* creature) : BossAI(creature, DATA_ALTAIRUS) {}
		
        void Reset() OVERRIDE
        {
            _Reset();
        }
		
        void EnterCombat(Unit* /*who*/) OVERRIDE
	{
	    _EnterCombat();
	    events.ScheduleEvent(EVENT_CHILLING_BREATH, 15000);
	    events.ScheduleEvent(EVENT_LIGHTING_BLAST, 3000);
	}
		
	void JustDied(Unit* /*killer*/) OVERRIDE
	{
	    _JustDied();
	}
		
	void KilledUnit(Unit* who) OVERRIDE
	{        
	}
		
	void UpdateAI(uint32 diff) OVERRIDE
	{
	    if (!UpdateVictim()) return;
			
	    events.Update(diff);
			
	    while(uint32 eventId = events.ExecuteEvent())
	    {
	        switch(eventId)
	        {
	        case EVENT_CALL_THE_WIND:
		    break;
                case EVENT_CHILLING_BREATH:
                    if(Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 100, true))
                    {
                        DoCast(target, SPELL_CHILLING_BREATH, true);
                    }
                    events.ScheduleEvent(EVENT_CHILLING_BREATH, 15000);
                    break;
                case EVENT_LIGHTING_BLAST:
                    Map::PlayerList const &PlList = me->GetMap()->GetPlayers();
			          
                    if(PlList.isEmpty()) break;
			            
                    for(Map::PlayerList::const_iterator i = PlList.begin(); i != PlList.end(); ++i)
                    {
                        if (Player* player = i->GetSource())
                        {
                            if(player->IsGameMaster()) continue;
                            
                            if(player->GetPositionZ() < 734.170) DoCast((Unit*)player, EVENT_LIGHTING_BLAST, true);
                        }
                    }
                    events.ScheduleEvent(EVENT_LIGHTING_BLAST, 3000);
                    break;
                }
            }
			
            DoMeleeAttackIfReady();
        }
    };

    CreatureAI* GetAI(Creature* creature) const OVERRIDE
    {
        return GetTheVortexPinnacleAI<boss_altairusAI>(creature);
    }
};

void AddSC_boss_altairus()
{
    new boss_altairus();
}
