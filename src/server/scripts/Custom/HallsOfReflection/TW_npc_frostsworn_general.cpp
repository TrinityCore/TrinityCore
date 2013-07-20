/*
 * Copyright (C) 2008-2012 TrinityCore <http://www.trinitycore.org/>
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
#include "TW_halls_of_reflection.h"


#define SPELL_STRIKE_N		69933
#define SPELL_STRIKE_H		70400
#define SPELL_STRIKE		isHeroic?SPELL_STRIKE_H:SPELL_STRIKE_N
#define STRIKE_RANGE		8.0f
#define STRIKE_TIMER		8000

#define SPELL_BURST_N		69900
#define SPELL_BURST_H		73046
#define SPELL_BURST		isHeroic?SPELL_BURST_H:SPELL_BURST_N


class TW_npc_spiritual_reflection : public CreatureScript
{
public:
    TW_npc_spiritual_reflection() : CreatureScript("TW_npc_spiritual_reflection") { }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new TW_npc_spiritual_reflectionAI(creature);
    }

    struct TW_npc_spiritual_reflectionAI : public ScriptedAI
    {
        TW_npc_spiritual_reflectionAI(Creature* creature) : ScriptedAI(creature) {
		isHeroic = creature->GetMap()->IsRaidOrHeroicDungeon();
		Reset();
        }
        
        bool isHeroic;
        uint32 strike_timer;

        void Reset()
        {
        	strike_timer = rand() % STRIKE_TIMER;
        }

        void EnterCombat(Unit* /*who*/)
        {
        }

        void JustDied(Unit* killer)
        {
		if(killer)
			DoCast( killer, SPELL_BURST );
		else
			DoCast(me, SPELL_BURST);
        }

        void KilledUnit(Unit* /*victim*/)
        {
        
        }

        void UpdateAI(uint32 diff)
        {
		// Return since we have no target
		if (!UpdateVictim())
			return;
		
		strike_timer += diff;
		
		if( strike_timer >= STRIKE_TIMER ){
			Unit *target = SelectTarget( SELECT_TARGET_RANDOM, 0 );
			if( target != 0 && target->GetTypeId() == TYPEID_PLAYER && me->GetDistance(target) <= STRIKE_RANGE ){
				strike_timer = 0;
				DoCast(target, SPELL_STRIKE);
			}
		}
        
		DoMeleeAttackIfReady();
        }

    };

};



#define SPELL_THROW_SHIELD_N		69222
#define SPELL_THROW_SHIELD_H		73076
#define SPELL_THROW_SHIELD		isHeroic?SPELL_THROW_SHIELD_H:SPELL_THROW_SHIELD_N
#define THROW_SHIELD_TIMER		6000
#define THROW_SHIELD_RANGE_MIN		5.0f
#define THROW_SHIELD_RANGE_MAX		45.0f

#define SAY_AGGRO			"You are not worthy to face the Lich King!"
#define SAY_DEATH			"Master! I have failed!"

#define SOUND_AGGRO			16921
#define SOUND_DEATH			16922

#define SPELL_CLONE_PLAYER_1		69837
#define SPELL_CLONE_PLAYER_2		69828


class TW_npc_frostsworn_general : public CreatureScript
{
public:
    TW_npc_frostsworn_general() : CreatureScript("TW_npc_frostsworn_general") { }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new TW_npc_frostsworn_generalAI(creature);
    }

    struct TW_npc_frostsworn_generalAI : public ScriptedAI
    {
        TW_npc_frostsworn_generalAI(Creature* creature) : ScriptedAI(creature) {
		Reset();
		instance = creature->GetInstanceScript();
		isHeroic = creature->GetMap()->IsRaidOrHeroicDungeon();
        }

        InstanceScript *instance;
        bool isHeroic;
        uint32 throw_shield_timer;
	bool hasSummonedAdds;
	
	void SayAggro(){
		me->MonsterYell( SAY_AGGRO, LANG_UNIVERSAL, 0 );
		DoPlaySoundToSet( me, SOUND_AGGRO );
	}
	
	void SayDeath(){
		me->MonsterYell( SAY_DEATH, LANG_UNIVERSAL, 0 );
		DoPlaySoundToSet( me, SOUND_DEATH );
	}

        void Reset()
        {
		throw_shield_timer = THROW_SHIELD_TIMER;
		hasSummonedAdds = false;
        }

        void EnterCombat(Unit* /*who*/)
        {
		SayAggro();
        }

        void JustDied(Unit* /*killer*/)
        {
		if(instance)
			instance->SetData(DATA_GENERAL_EVENT, DONE);
		SayDeath();
        }

        void KilledUnit(Unit* /*victim*/)
        {
        
        }

        void UpdateAI(uint32 diff)
        {
		// Return since we have no target
		if (!UpdateVictim())
			return;
			
		throw_shield_timer += diff;
		
		if( Unit *target = ShouldCastThrowShield() )
			CastThrowShield( target );
		else if( ShouldSummonAdds() )
			SummonAdds();

        
		DoMeleeAttackIfReady();
        }
        
        bool ShouldSummonAdds(){
		if( hasSummonedAdds )
			return false;
		return me->GetHealth() * 100 / me->GetMaxHealth() <= 40;
	}
	
	void SummonAdds(){
		Map::PlayerList const &players = me->GetMap()->GetPlayers();
		for (Map::PlayerList::const_iterator i = players.begin(); i != players.end(); ++i)
		{
			Player* player = i->GetSource();
			if(player && player->IsAlive()){
				if(Creature *add = me->SummonCreature(NPC_SPIRITUAL_REFLECTION, 0.0, 0.0, 0.0, 0.0, TEMPSUMMON_CORPSE_DESPAWN, 0) ){
					player->CastSpell(add, SPELL_CLONE_PLAYER_1, true);
					player->CastSpell(add, SPELL_CLONE_PLAYER_2, true);
					if(add->AI()){
						add->AI()->AttackStart(player);
						add->AI()->DoZoneInCombat();
					}
					
				}
			}
		}
		hasSummonedAdds = true;
	}
	
	Unit *ShouldCastThrowShield(){
		if( throw_shield_timer < THROW_SHIELD_TIMER )
			return 0;
		Unit *target = 0;
		for( uint8 i = 0; i < 5 && !target; i++ ){
			target = SelectTarget( SELECT_TARGET_RANDOM, 0 );
			if(	target == 0 
			||	target->GetTypeId() != TYPEID_PLAYER
			||	me->GetDistance(target) >= THROW_SHIELD_RANGE_MAX
			||	me->GetDistance(target) <= THROW_SHIELD_RANGE_MIN )
				target = 0;
		}
		return target;
	}
	
	void CastThrowShield( Unit *target ){
		DoCast( target, SPELL_THROW_SHIELD );
		throw_shield_timer = 0;
	}
    };

};

void AddSC_TW_npc_frostsworn_general()
{
    new TW_npc_frostsworn_general();
    new TW_npc_spiritual_reflection();
}

