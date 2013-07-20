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

#define SPELL_STUN_A		69708
#define SPELL_STUN_H		70194
#define SPELL_STUN		isJaina?SPELL_STUN_A:SPELL_STUN_H
#define STUN_CASTTIME		1500

class TW_npc_jaina_hor_part2 : public CreatureScript
{
public:
    TW_npc_jaina_hor_part2() : CreatureScript("TW_npc_jaina_hor_part2") { }
    
    ///On "We are ready", close gossip, set data to SPECIAL, spawn a new version of NPC and despawn self.
    bool OnGossipSelect(Player* player, Creature* creature, uint32 /*sender*/, uint32 action)
    {
        player->PlayerTalkClass->ClearMenus();
        InstanceScript *instance = creature->GetInstanceScript();
        if(instance==0)///This should never happen...
		return true;
	uint32 uiTeamInInstance = instance->GetData(DATA_TEAM_IN_INSTANCE);
	
        switch (action)
        {
            case GOSSIP_ACTION_INFO_DEF+1:
                player->CLOSE_GOSSIP_MENU();
                instance->SetData( DATA_LICHKING_EVENT, SPECIAL );
		Creature *newSyl = creature->SummonCreature( NPC_SYLVANAS2, WP_SYL_0, creature->GetOrientation(), TEMPSUMMON_MANUAL_DESPAWN, 0 );
		newSyl->RemoveFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP);
		newSyl->RemoveFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_QUESTGIVER);
		newSyl->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_NPC|UNIT_FLAG_IMMUNE_TO_PC);
		instance->SetData64(DATA_SYLVANAS2, newSyl->GetGUID());
		creature->DisappearAndDie();
		return true;
        }

        return true;
    }

    ///Offer one gossip item, and the quest menu if necessary
    bool OnGossipHello(Player* player, Creature* creature)
    {
        if (creature->IsQuestGiver())
            player->PrepareQuestMenu(creature->GetGUID());

        player->ADD_GOSSIP_ITEM( 0, "We are ready!", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+1);
        player->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE, creature->GetGUID());
        return true;
    }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new TW_npc_jaina_hor_part2AI(creature);
    }

    struct TW_npc_jaina_hor_part2AI : public ScriptedAI
    {
        TW_npc_jaina_hor_part2AI(Creature* creature) : ScriptedAI(creature) {
		instance = creature->GetInstanceScript();
		isJaina = creature->GetEntry() == NPC_SYLVANAS2_A;
        }

        InstanceScript *instance;
        bool hasStunned;
        bool isJaina;
        uint32 stun_timer;
        uint32 current_wp;
        uint32 reached_wp;

        void Reset()
        {
		hasStunned = false;
		stun_timer = 0;
		current_wp = 0;
		reached_wp = 0;
        }
        
        void MoveInLineOfSight(Unit * unit){
		if( instance == 0 || instance->GetData( DATA_LICHKING_EVENT ) != NOT_STARTED )
			return;
		if( unit->GetTypeId() != TYPEID_PLAYER )
			return;
// 		printf("Player moves in LOS of Sylvanas.\n");
		if( hasStunned || me->GetDistance(unit) > 40.0f )
			return;
		Creature *lichking = instance->instance->GetCreature( instance->GetData64(NPC_LICHKING2) );///TODO This line looks hairy
		if(!lichking){
			me->MonsterYell("Panic... Lich King Not Found!", LANG_UNIVERSAL, 0);
			return;
		}
		///HACK: Next line don't work, working around it...
// 		DoCast( lichking, SPELL_STUN );
		me->AddAura(SPELL_STUN, lichking);
		me->CombatStart(lichking, true);
		lichking->CombatStart(me, true);
// 		lichking->CastSpell(lichking, SPELL_STUN, true);
		hasStunned = true;
	}

        void EnterCombat(Unit* /*who*/)
        {
        
        }

        void JustDied(Unit* /*killer*/)
        {
        
        }

        void KilledUnit(Unit* /*victim*/)
        {
        
        }
        
        void MovementInform(uint32 /*MovementType*/, uint32 /*Data*/){
		if( instance == 0 )
			return;
		if( instance->GetData( DATA_LICHKING_EVENT ) == IN_PROGRESS ){
			instance->SetData( DATA_LK_SEND_WAVE, current_wp );
			reached_wp = current_wp;
		}
	}

        void UpdateAI(uint32 uiDiff)
        {
		if(!instance)
			return;
		if( instance->GetData( DATA_LICHKING_EVENT ) == NOT_STARTED ){
			if(reached_wp > 1)
				me->DisappearAndDie();
			if (!UpdateVictim())
				return;
		
			if( !hasStunned ){//If we didnt do the stun yet, do melee and wait...
				DoMeleeAttackIfReady();
				return;
			}
			
			if( stun_timer <= STUN_CASTTIME && stun_timer + uiDiff > STUN_CASTTIME )
				me->GetMotionMaster()->MovePoint( 0, WP_SYL_0 );
			
			stun_timer += uiDiff;//If we are still casting the stun, don't interrupt it.
			if( stun_timer < STUN_CASTTIME )
				return;
			me->SetFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP);
				
		}else if( instance->GetData( DATA_LICHKING_EVENT ) == SPECIAL ){
			if( current_wp == reached_wp ){
				current_wp++;
				switch( current_wp ){
					case 1:
						me->GetMotionMaster()->MovePoint( 0, WP_SYL_1 );
						break;
					case 2:
						me->GetMotionMaster()->MovePoint( 0, WP_SYL_2 );
						break;
					case 3:
						me->GetMotionMaster()->MovePoint( 0, WP_SYL_3 );
						break;
					case 4:
						me->GetMotionMaster()->MovePoint( 0, WP_SYL_4 );
						break;
					case 5:
						me->GetMotionMaster()->MovePoint( 0, WP_SYL_5 );
						break;
					
				}
				if(current_wp < 5)
					instance->SetData( DATA_LICHKING_EVENT, IN_PROGRESS );
				else
					instance->SetData(DATA_LICHKING_EVENT, DONE);
			}
		}
		if(!me->HasFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_PC)){
// 			printf("No PC immune\n");
			me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_PC);
		}
		if(!me->HasFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_NPC)){
// 			printf("No NPC immune\n");
			me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_NPC);
		}
        }
    };

};

#define SPELL_REMORSELESS_WINTER	69780

class TW_npc_lichking_hor : public CreatureScript
{
public:
    TW_npc_lichking_hor() : CreatureScript("TW_npc_lichking_hor") { }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new TW_npc_lichking_horAI(creature);
    }

    struct TW_npc_lichking_horAI : public ScriptedAI
    {
        TW_npc_lichking_horAI(Creature* creature) : ScriptedAI(creature) {
			instance = creature->GetInstanceScript();
			current_wp = 0;
			reached_wp = 0;
        }

        InstanceScript *instance;
        uint32 current_wp;
        uint32 reached_wp;

        void Reset()
        {
		
        }

        void EnterCombat(Unit* /*who*/)
        {
        
        }

        void JustDied(Unit* /*killer*/)
        {
        
        }

        void KilledUnit(Unit* /*victim*/)
        {
        
        }
        
        void MovementInform(uint32 /*MovementType*/, uint32 /*Data*/){
			if( instance == 0 )
				return;
			reached_wp = current_wp;
		}

        void UpdateAI(uint32 diff)
        {
			if( instance == 0 )
				return;
		
			if(!me->IsWalking())
				me->SetWalk(true);
		
			if( instance->GetData(DATA_LICHKING_EVENT) == NOT_STARTED ){
				if(reached_wp > 1)
					me->DisappearAndDie();
				if (!UpdateVictim())
					return;
				DoMeleeAttackIfReady();
			}else if( me->HasAura( SPELL_STUN_A ) )
				me->RemoveAurasDueToSpell( SPELL_STUN_A );
			else if( me->HasAura( SPELL_STUN_H ) )
				me->RemoveAurasDueToSpell( SPELL_STUN_H );
			else if( !me->HasAura(SPELL_REMORSELESS_WINTER) ){
				if(me->HasUnitState(UNIT_STATE_CASTING))
					return;
				DoCast(me, SPELL_REMORSELESS_WINTER);
				me->SetWalk(true);///TODO: Not sure if at all this takes effect if placed here.
	// 			printf("Updating LK speed when current rate is %f\n", me->GetSpeedRate(MOVE_WALK));
				me->SetSpeed(MOVE_WALK , me->GetSpeedRate(MOVE_WALK) * 0.5, true);
		
			}else{
				if( current_wp == reached_wp ){
					current_wp++;
					DoMove();
				
				}
				if( me->GetMotionMaster()->GetCurrentMovementGeneratorType() != POINT_MOTION_TYPE )
					DoMove();
			}
        }
        
        void DoMove(){
		switch( current_wp ){
			case 1:
				me->GetMotionMaster()->MovePoint( 0, WP_SYL_0 );
				break;
			case 2:
				me->GetMotionMaster()->MovePoint( 0, WP_SYL_1 );
				break;
			case 3:
				me->GetMotionMaster()->MovePoint( 0, WP_SYL_2 );
				break;
			case 4:
				me->GetMotionMaster()->MovePoint( 0, WP_SYL_3 );
				break;
			case 5:
				me->GetMotionMaster()->MovePoint( 0, WP_SYL_4 );
				break;
			case 6:
				me->GetMotionMaster()->MovePoint( 0, WP_SYL_5 );
				break;
		}
	}
    };

};

void AddSC_TW_boss_hor_lichking()
{
    new TW_npc_jaina_hor_part2();
    new TW_npc_lichking_hor();
}


