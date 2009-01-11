/* Copyright (C) 2006 - 2008 ScriptDev2 <https://scriptdev2.svn.sourceforge.net/>
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
 */

/* ScriptData
SDName: Mulgore
SD%Complete: 100
SDComment: Support for quest: 11129
SDCategory: Mulgore
EndScriptData */

/* ContentData
npc_skorn_whitecloud
npc_kyle_frenzied
EndContentData */

#include "precompiled.h"

/*######
# npc_skorn_whitecloud
######*/

bool GossipHello_npc_skorn_whitecloud(Player *player, Creature *_Creature)
{
    if (_Creature->isQuestGiver())
        player->PrepareQuestMenu( _Creature->GetGUID() );

    if (!player->GetQuestRewardStatus(770))
        player->ADD_GOSSIP_ITEM( 0, "Tell me a story, Skorn.", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF );

    player->SEND_GOSSIP_MENU(522,_Creature->GetGUID());

    return true;
}

bool GossipSelect_npc_skorn_whitecloud(Player *player, Creature *_Creature, uint32 sender, uint32 action )
{
    if (action == GOSSIP_ACTION_INFO_DEF)
        player->SEND_GOSSIP_MENU(523,_Creature->GetGUID());

    return true;
}

/*#####
# npc_kyle_frenzied
######*/

struct TRINITY_DLL_DECL npc_kyle_frenziedAI : public ScriptedAI
{
	npc_kyle_frenziedAI(Creature *c) : ScriptedAI(c) {Reset();}

	int STATE;
	uint32 wait;
	uint64 player;

	void Reset()
	{
		STATE = 0;
		m_creature->SetDefaultMovementType(WAYPOINT_MOTION_TYPE);
		m_creature->GetMotionMaster()->Initialize();
	}
	void Aggro(Unit* who){}

	void SpellHit(Unit *caster, const SpellEntry* spell)
	{	// we can feed him without any quest
		if(spell->Id == 42222 && caster->GetTypeId() == TYPEID_PLAYER && ((Player*)caster)->GetTeam() == HORDE)
		{
			STATE = 1;
			player = caster->GetGUID();
			float x, y, z, z2;
			caster->GetPosition(x, y, z);
			x = x + 3.7*cos(caster->GetOrientation());
			y = y + 3.7*sin(caster->GetOrientation());
			z2 = m_creature->GetBaseMap()->GetHeight(x,y,z,false);
			z = (z2 <= INVALID_HEIGHT) ? z : z2;
			m_creature->SetDefaultMovementType(IDLE_MOTION_TYPE);		//there is other way to stop waypoint movement?
			m_creature->GetMotionMaster()->Initialize();
			m_creature->RemoveUnitMovementFlag(MOVEMENTFLAG_WALK_MODE);
			m_creature->GetMotionMaster()->MovePoint(0,x, y, z);
		}
	}

    void MovementInform(uint32 type, uint32 id)
	{
		if(type == POINT_MOTION_TYPE)
		{	
			switch(STATE)
			{
			case 1:
				{
				Unit *plr = Unit::GetUnit((*m_creature),player);
				if(plr)
				m_creature->SetOrientation(m_creature->GetAngle(plr));
				m_creature->HandleEmoteCommand(EMOTE_STATE_USESTANDING);	//eat
				WorldPacket data;
				m_creature->BuildHeartBeatMsg(&data);
				m_creature->SendMessageToSet(&data,true);
				wait = 3000;
				STATE = 2;
				break;
				}
			case 4:
				m_creature->setDeathState(JUST_DIED);
				m_creature->Respawn();
				break;
			}
		}
	}

	void UpdateAI(const uint32 diff)
	{
		if (!STATE || STATE == 4)
			return;
		if(wait < diff)
		{
			switch(STATE)
			{
			case 2: 
				STATE = 3; wait = 7000;
				m_creature->UpdateEntry(23622,HORDE);
				m_creature->HandleEmoteCommand(EMOTE_ONESHOT_DANCE);
				break;
			case 3:
				STATE = 4;	//go home
				Unit *plr = Unit::GetUnit((*m_creature),player);
					if(plr && ((Player*)plr)->GetQuestStatus(11129) == QUEST_STATUS_INCOMPLETE)
						((Player*)plr)->CompleteQuest(11129);
				float x, y, z, z2, angle;
				angle = m_creature->GetAngle(-2146, -430);
				m_creature->GetPosition(x,y,z);
				x = x + 40*cos(angle);
				y = y + 40*sin(angle);
				z2 = m_creature->GetBaseMap()->GetHeight(x,y,MAX_HEIGHT,false);
				z = (z2 <= INVALID_HEIGHT) ? z : z2;
				m_creature->GetMotionMaster()->MovePoint(0,x,y,z);
				break;
			}
		}else wait -= diff;
	}
};

CreatureAI* GetAI_npc_kyle_frenzied(Creature *_Creature)
{
    return new npc_kyle_frenziedAI (_Creature);
}

void AddSC_mulgore()
{
    Script *newscript;

    newscript = new Script;
    newscript->Name="npc_skorn_whitecloud";
    newscript->pGossipHello = &GossipHello_npc_skorn_whitecloud;
    newscript->pGossipSelect = &GossipSelect_npc_skorn_whitecloud;
    newscript->RegisterSelf();

	newscript = new Script;
    newscript->Name="npc_kyle_frenzied";
    newscript->GetAI = &GetAI_npc_kyle_frenzied;
    newscript->RegisterSelf();
}
