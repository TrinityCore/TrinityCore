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
SDName: Blackrock_Depths
SD%Complete: 95
SDComment: Quest support: 4001, 4342, 7604. Vendor Lokhtos Darkbargainer.
SDCategory: Blackrock Depths
EndScriptData */

/* ContentData
mob_phalanx
npc_kharan_mighthammer
npc_lokhtos_darkbargainer
EndContentData */

#include "precompiled.h"
#include "../../npc/npc_escortAI.h"
#include "def_blackrock_depths.h"
#include "GameObject.h"

/*######
## mob_phalanx
######*/

#define SPELL_THUNDERCLAP       8732
#define SPELL_FIREBALLVOLLEY    22425
#define SPELL_MIGHTYBLOW        14099

struct TRINITY_DLL_DECL mob_phalanxAI : public ScriptedAI
{
    mob_phalanxAI(Creature *c) : ScriptedAI(c) {Reset();}

    uint32 ThunderClap_Timer;
    uint32 FireballVolley_Timer;
    uint32 MightyBlow_Timer;

    void Reset()
    {
        ThunderClap_Timer = 12000;
        FireballVolley_Timer =0;
        MightyBlow_Timer = 15000;
    }

    void Aggro(Unit *who)
    {
    }

    void UpdateAI(const uint32 diff)
    {
        //Return since we have no target
        if(!m_creature->SelectHostilTarget() || !m_creature->getVictim() )
            return;

        //ThunderClap_Timer
        if( ThunderClap_Timer < diff )
        {
            DoCast(m_creature->getVictim(),SPELL_THUNDERCLAP);
            ThunderClap_Timer = 10000;
        }else ThunderClap_Timer -= diff;

        //FireballVolley_Timer
        if( m_creature->GetHealth()*100 / m_creature->GetMaxHealth() < 51 )
        {
            if (FireballVolley_Timer < diff)
            {
                DoCast(m_creature->getVictim(),SPELL_FIREBALLVOLLEY);
                FireballVolley_Timer = 15000;
            }else FireballVolley_Timer -= diff;
        }

        //MightyBlow_Timer
        if( MightyBlow_Timer < diff )
        {
            DoCast(m_creature->getVictim(),SPELL_MIGHTYBLOW);
            MightyBlow_Timer = 10000;
        }else MightyBlow_Timer -= diff;

        DoMeleeAttackIfReady();
    }
};
CreatureAI* GetAI_mob_phalanx(Creature *_Creature)
{
    return new mob_phalanxAI (_Creature);
}

/*######
## npc_kharan_mighthammer
######*/

#define QUEST_4001  4001
#define QUEST_4342  4342

bool GossipHello_npc_kharan_mighthammer(Player *player, Creature *_Creature)
{
    if( _Creature->isQuestGiver() )
        player->PrepareQuestMenu( _Creature->GetGUID() );

    if( player->GetQuestStatus(QUEST_4001) == QUEST_STATUS_INCOMPLETE )
        player->ADD_GOSSIP_ITEM( 0, "I need to know where the princess are, Kharan!", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+1);

    if( player->GetQuestStatus(4342) == QUEST_STATUS_INCOMPLETE )
        player->ADD_GOSSIP_ITEM( 0, "All is not lost, Kharan!", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+3);

    if( player->GetTeam() == HORDE ) player->SEND_GOSSIP_MENU(2473, _Creature->GetGUID());
    if( player->GetTeam() == ALLIANCE ) player->SEND_GOSSIP_MENU(2474, _Creature->GetGUID());

    return true;
}

bool GossipSelect_npc_kharan_mighthammer(Player *player, Creature *_Creature, uint32 sender, uint32 action)
{
    switch (action)
    {
        case GOSSIP_ACTION_INFO_DEF+1:
            player->ADD_GOSSIP_ITEM(0, "Gor'shak is my friend, you can trust me.", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+2);
            player->SEND_GOSSIP_MENU(2475, _Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF+2:
            player->ADD_GOSSIP_ITEM(0, "Not enough, you need to tell me more.", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+3);
            player->SEND_GOSSIP_MENU(2476, _Creature->GetGUID());
            break;

        case GOSSIP_ACTION_INFO_DEF+3:
            player->ADD_GOSSIP_ITEM(0, "So what happened?", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+4);
            player->SEND_GOSSIP_MENU(2477, _Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF+4:
            player->ADD_GOSSIP_ITEM(0, "Continue...", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+5);
            player->SEND_GOSSIP_MENU(2478, _Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF+5:
            player->ADD_GOSSIP_ITEM(0, "So you suspect that someone on the inside was involved? That they were tipped off?", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+6);
            player->SEND_GOSSIP_MENU(2479, _Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF+6:
            player->ADD_GOSSIP_ITEM(0, "Continue with your story please.", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+7);
            player->SEND_GOSSIP_MENU(2480, _Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF+7:
            player->ADD_GOSSIP_ITEM(0, "Indeed.", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+8);
            player->SEND_GOSSIP_MENU(2481, _Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF+8:
            player->ADD_GOSSIP_ITEM(0, "The door is open, Kharan. You are a free man.", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+9);
            player->SEND_GOSSIP_MENU(2482, _Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF+9:
            player->CLOSE_GOSSIP_MENU();
            if( player->GetTeam() == HORDE ) player->AreaExploredOrEventHappens(QUEST_4001);
            if( player->GetTeam() == ALLIANCE ) player->AreaExploredOrEventHappens(QUEST_4342);
            break;
    }
    return true;
}

/*######
## npc_lokhtos_darkbargainer
######*/

#define ITEM_THRORIUM_BROTHERHOOD_CONTRACT               18628
#define ITEM_SULFURON_INGOT                              17203
#define QUEST_A_BINDING_CONTRACT                         7604
#define SPELL_CREATE_THORIUM_BROTHERHOOD_CONTRACT_DND    23059

bool GossipHello_npc_lokhtos_darkbargainer(Player *player, Creature *_Creature)
{
    if (_Creature->isQuestGiver())
        player->PrepareQuestMenu( _Creature->GetGUID() );

    if (_Creature->isVendor() && player->GetReputationRank(59) >= REP_FRIENDLY)
        player->ADD_GOSSIP_ITEM( 1, "Show me what I have access to, Lothos.", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_TRADE);

    if (player->GetQuestRewardStatus(QUEST_A_BINDING_CONTRACT) != 1 &&
        !player->HasItemCount(ITEM_THRORIUM_BROTHERHOOD_CONTRACT, 1, true) &&
        player->HasItemCount(ITEM_SULFURON_INGOT, 1))
    {
        player->ADD_GOSSIP_ITEM(0, "Get Thorium Brotherhood Contract", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1);
    }

    if (player->GetReputationRank(59) < REP_FRIENDLY)
        player->SEND_GOSSIP_MENU(3673, _Creature->GetGUID());
    else
        player->SEND_GOSSIP_MENU(3677, _Creature->GetGUID());

    return true;
}

bool GossipSelect_npc_lokhtos_darkbargainer(Player *player, Creature *_Creature, uint32 sender, uint32 action )
{
    if (action == GOSSIP_ACTION_INFO_DEF + 1)
    {
        player->CLOSE_GOSSIP_MENU();
        player->CastSpell(player, SPELL_CREATE_THORIUM_BROTHERHOOD_CONTRACT_DND, false);
    }
    if (action == GOSSIP_ACTION_TRADE)
    {
        player->SEND_VENDORLIST( _Creature->GetGUID() );
    }
    return true;
}

/*######
## npc_dughal_stormwing
######*/

#define QUEST_JAIL_BREAK		4322
#define SAY_DUGHAL_FREE			"Thank you, $N! I'm free!!!"
#define GOSSIP_DUGHAL			"You're free, Dughal! Get out of here!"

ScriptedInstance *pInstance;

struct TRINITY_DLL_DECL npc_dughal_stormwingAI : public npc_escortAI
{
    npc_dughal_stormwingAI(Creature *c) : npc_escortAI(c) { Reset(); }

    void WaypointReached(uint32 i)
    {
	switch(i)
		{
		case 0:m_creature->Say(SAY_DUGHAL_FREE, LANG_UNIVERSAL, PlayerGUID); break;
		case 1:pInstance->SetData(DATA_DUGHAL,ENCOUNTER_STATE_OBJECTIVE_COMPLETED);break;
		case 2:
			m_creature->SetVisibility(VISIBILITY_OFF);
			m_creature->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
			m_creature->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
			pInstance->SetData(DATA_DUGHAL,ENCOUNTER_STATE_ENDED);
			break;
		}
	}

    void Aggro(Unit* who) { }
	void Reset() {}

    void JustDied(Unit* killer)
    {
        if (IsBeingEscorted && killer == m_creature)
        {
			m_creature->SetVisibility(VISIBILITY_OFF);
			m_creature->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
			m_creature->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
			pInstance->SetData(DATA_DUGHAL,ENCOUNTER_STATE_ENDED);
        }
    }

    void UpdateAI(const uint32 diff)
    {
		if(pInstance->GetData(DATA_QUEST_JAIL_BREAK) == ENCOUNTER_STATE_NOT_STARTED) return;
		if( (pInstance->GetData(DATA_QUEST_JAIL_BREAK) == ENCOUNTER_STATE_IN_PROGRESS || pInstance->GetData(DATA_QUEST_JAIL_BREAK) == ENCOUNTER_STATE_FAILED || pInstance->GetData(DATA_QUEST_JAIL_BREAK) == ENCOUNTER_STATE_ENDED)&& pInstance->GetData(DATA_DUGHAL) == ENCOUNTER_STATE_ENDED )
		{
			m_creature->SetVisibility(VISIBILITY_OFF);
			m_creature->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
			m_creature->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
		}
		else
		{
			m_creature->SetVisibility(VISIBILITY_ON);
			m_creature->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
			m_creature->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
		}
		npc_escortAI::UpdateAI(diff);
    }
};
CreatureAI* GetAI_npc_dughal_stormwing(Creature *_Creature)
{    
    npc_dughal_stormwingAI* dughal_stormwingAI = new npc_dughal_stormwingAI(_Creature);

    dughal_stormwingAI->AddWaypoint(0, 280.42,-82.86, -77.12,0);
    dughal_stormwingAI->AddWaypoint(1, 287.64,-87.01, -76.79,0);
    dughal_stormwingAI->AddWaypoint(2, 354.63,-64.95, -67.53,0);
    return (CreatureAI*)dughal_stormwingAI;
}
bool GossipHello_npc_dughal_stormwing(Player *player, Creature *_Creature)
{
  	if(player->GetQuestStatus(QUEST_JAIL_BREAK) == QUEST_STATUS_INCOMPLETE && pInstance->GetData(DATA_QUEST_JAIL_BREAK) == ENCOUNTER_STATE_IN_PROGRESS )
    {
        player->ADD_GOSSIP_ITEM(0, GOSSIP_DUGHAL, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1);
 		player->SEND_GOSSIP_MENU(2846, _Creature->GetGUID());
    }
    return true;
}

bool GossipSelect_npc_dughal_stormwing(Player *player, Creature *_Creature, uint32 sender, uint32 action )
{
    if (action == GOSSIP_ACTION_INFO_DEF + 1)
    {
        player->CLOSE_GOSSIP_MENU();
        ((npc_escortAI*)(_Creature->AI()))->Start(false, false, true, player->GetGUID());
		_Creature->RemoveFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP);
		pInstance->SetData(DATA_QUEST_JAIL_BREAK,ENCOUNTER_STATE_IN_PROGRESS);
    }
    return true;
}

/*######
## npc_marshal_windsor
######*/

#define SAY_WINDSOR_AGGRO1			"You locked up the wrong Marshal. Prepare to be destroyed!"
#define SAY_WINDSOR_AGGRO2			"I bet you're sorry now, aren't you !?!!"
#define SAY_WINDSOR_AGGRO3			"You better hold me back $N or they are going to feel some prison house beatings."
#define SAY_WINDSOR_1				"Let's get a move on. My gear should be in the storage area up this way..."
#define SAY_WINDSOR_4_1				"Check that cell, $N. If someone is alive in there, we need to get them out."
#define SAY_WINDSOR_4_2				"Get him out of there!"
#define SAY_WINDSOR_4_3				"Good work! We're almost there, $N. This way."
#define SAY_WINDSOR_6				"This is it, $N. My stuff should be in that room. Cover me, I'm going in!"
#define SAY_WINDSOR_9				"Ah, there it is!"
#define MOB_ENTRY_REGINALD_WINDSOR	9682    

Player* PlayerStart;

struct TRINITY_DLL_DECL npc_marshal_windsorAI : public npc_escortAI
{
	npc_marshal_windsorAI(Creature *c) : npc_escortAI(c) 
	{ 
		pInstance = ((ScriptedInstance*)c->GetInstanceData());
		Reset(); 
	}
	  
	void WaypointReached(uint32 i)
    {
	switch( i )
        {
		case 1:
			m_creature->Say(SAY_WINDSOR_1, LANG_UNIVERSAL, PlayerGUID);
			break;
		case 7:
			m_creature->HandleEmoteCommand(EMOTE_STATE_POINT);
			m_creature->Say(SAY_WINDSOR_4_1, LANG_UNIVERSAL, PlayerGUID);
			IsOnHold=true;
			break;
		case 10:
			m_creature->setFaction(534);
			break;
		case 12:
			m_creature->Say(SAY_WINDSOR_6, LANG_UNIVERSAL, PlayerGUID);
			pInstance->SetData(DATA_SUPPLY_ROOM, ENCOUNTER_STATE_IN_PROGRESS);
			break;
		case 13:
			m_creature->HandleEmoteCommand(EMOTE_STATE_USESTANDING);/*EMOTE_STATE_WORK*/
			break;
		case 14:
			pInstance->SetData(DATA_GATE_SR,0);
			m_creature->setFaction(11);
			break;
		case 16:
			m_creature->Say(SAY_WINDSOR_9, LANG_UNIVERSAL, PlayerGUID); 
			break;
		case 17: 
			m_creature->HandleEmoteCommand(EMOTE_STATE_USESTANDING);/*EMOTE_STATE_WORK*/
			break;
		case 18:
			pInstance->SetData(DATA_GATE_SC,0);
			break;
		case 19:
			m_creature->SetVisibility(VISIBILITY_OFF);
			m_creature->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
			m_creature->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
			m_creature->SummonCreature(MOB_ENTRY_REGINALD_WINDSOR,403.61,-51.71,-63.92,3.600434,TEMPSUMMON_DEAD_DESPAWN ,0);
			pInstance->SetData(DATA_SUPPLY_ROOM, ENCOUNTER_STATE_ENDED);
			break;
		}
	}

    void Aggro(Unit* who) 
		{
		switch(rand()%3)
			{
			case 0:m_creature->Say(SAY_WINDSOR_AGGRO1, LANG_UNIVERSAL, PlayerGUID);break;
			case 1:m_creature->Say(SAY_WINDSOR_AGGRO2, LANG_UNIVERSAL, PlayerGUID);break;
			case 2:m_creature->Say(SAY_WINDSOR_AGGRO3, LANG_UNIVERSAL, PlayerGUID);break;
			}
		}

    void Reset() {}

	void JustDied(Unit *slayer)
    {
		pInstance->SetData(DATA_QUEST_JAIL_BREAK,ENCOUNTER_STATE_FAILED);
    }

    void UpdateAI(const uint32 diff)
    {
		if(pInstance->GetData(DATA_QUEST_JAIL_BREAK) == ENCOUNTER_STATE_NOT_STARTED) return;
		if(pInstance->GetData(DATA_DUGHAL) == ENCOUNTER_STATE_OBJECTIVE_COMPLETED)
			IsOnHold = false;
		if(!pInstance->GetData(DATA_GATE_D) && pInstance->GetData(DATA_DUGHAL) == ENCOUNTER_STATE_NOT_STARTED )
			{
			m_creature->Say(SAY_WINDSOR_4_2, LANG_UNIVERSAL, PlayerGUID);    
			pInstance->SetData(DATA_DUGHAL, ENCOUNTER_STATE_BEFORE_START);
			}	
		if( pInstance->GetData(DATA_DUGHAL) == ENCOUNTER_STATE_OBJECTIVE_COMPLETED )
			{
			m_creature->Say(SAY_WINDSOR_4_3, LANG_UNIVERSAL, PlayerGUID);
			pInstance->SetData(DATA_DUGHAL, ENCOUNTER_STATE_ENDED);
			}
		if( (pInstance->GetData(DATA_QUEST_JAIL_BREAK) == ENCOUNTER_STATE_IN_PROGRESS || pInstance->GetData(DATA_QUEST_JAIL_BREAK) == ENCOUNTER_STATE_FAILED || pInstance->GetData(DATA_QUEST_JAIL_BREAK) == ENCOUNTER_STATE_ENDED)&& pInstance->GetData(DATA_SUPPLY_ROOM) == ENCOUNTER_STATE_ENDED )
		{
			m_creature->SetVisibility(VISIBILITY_OFF);
			m_creature->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
			m_creature->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
		}
		else
		{
			m_creature->SetVisibility(VISIBILITY_ON);
			m_creature->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
			m_creature->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
		}
		npc_escortAI::UpdateAI(diff);
    }
};
CreatureAI* GetAI_npc_marshal_windsor(Creature *_Creature)
{    
    npc_marshal_windsorAI* marshal_windsorAI = new npc_marshal_windsorAI(_Creature);
    marshal_windsorAI->AddWaypoint(0, 316.336,-225.528, -77.7258,7000);
    marshal_windsorAI->AddWaypoint(1, 316.336,-225.528, -77.7258,2000);
	marshal_windsorAI->AddWaypoint(2, 322.96,-207.13, -77.87,0);
    marshal_windsorAI->AddWaypoint(3, 281.05,-172.16, -75.12,0);
    marshal_windsorAI->AddWaypoint(4, 272.19,-139.14, -70.61,0);
    marshal_windsorAI->AddWaypoint(5, 283.62,-116.09, -70.21,0);
    marshal_windsorAI->AddWaypoint(6, 296.18,-94.30, -74.08,0);
    marshal_windsorAI->AddWaypoint(7, 294.57,-93.11, -74.08,0);
    marshal_windsorAI->AddWaypoint(8, 314.31,-74.31, -76.09,0);
    marshal_windsorAI->AddWaypoint(9, 360.22,-62.93, -66.77,0);
    marshal_windsorAI->AddWaypoint(10, 383.38,-69.40, -63.25,0);
    marshal_windsorAI->AddWaypoint(11, 389.99,-67.86, -62.57,0);
    marshal_windsorAI->AddWaypoint(12, 400.98,-72.01, -62.31,0);
    marshal_windsorAI->AddWaypoint(13, 404.22,-62.30, -63.50,2300);
    marshal_windsorAI->AddWaypoint(14, 404.22,-62.30, -63.50,1500);
	marshal_windsorAI->AddWaypoint(154, 407.65,-51.86, -63.96,0);
    marshal_windsorAI->AddWaypoint(16, 403.61,-51.71, -63.92,1000);
    marshal_windsorAI->AddWaypoint(17, 403.61,-51.71, -63.92,2000);
    marshal_windsorAI->AddWaypoint(18, 403.61,-51.71, -63.92,1000);
    marshal_windsorAI->AddWaypoint(19, 403.61,-51.71, -63.92,0);
    return (CreatureAI*)marshal_windsorAI;
}

bool QuestAccept_npc_marshal_windsor(Player *player, Creature *creature, Quest const *quest )
{
    if( quest->GetQuestId() == 4322 )                     
		{PlayerStart = player;
		if( pInstance->GetData(DATA_QUEST_JAIL_BREAK) == ENCOUNTER_STATE_NOT_STARTED )
		{
				((npc_escortAI*)(creature->AI()))->Start(true, true, false, player->GetGUID());
				pInstance->SetData(DATA_QUEST_JAIL_BREAK,ENCOUNTER_STATE_IN_PROGRESS);
				creature->setFaction(11); 
		}

		}
    return false;
}

/*######
## npc_marshal_reginald_windsor
######*/

#define SAY_REGINALD_WINDSOR_0_1	"Can you feel the power, $N??? It's time to ROCK!"
#define SAY_REGINALD_WINDSOR_0_2	"Now we just have to free Tobias and we can get out of here. This way!"
#define SAY_REGINALD_WINDSOR_5_1	"Open it."
#define SAY_REGINALD_WINDSOR_5_2	"I never did like those two. Let's get moving."
#define SAY_REGINALD_WINDSOR_7_1	"Open it and be careful this time!"
#define SAY_REGINALD_WINDSOR_7_2	"That intolerant dirtbag finally got what was coming to him. Good riddance!"
#define SAY_REGINALD_WINDSOR_7_3	"Alright, let's go."
#define SAY_REGINALD_WINDSOR_13_1	"Open it. We need to hurry up. I can smell those Dark Irons coming a mile away and I can tell you one thing, they're COMING!"
#define SAY_REGINALD_WINDSOR_13_2	"Administering fists of fury on Crest Killer!"
#define SAY_REGINALD_WINDSOR_13_3	"He has to be in the last cell. Unless... they killed him."
#define SAY_REGINALD_WINDSOR_14_1	"Get him out of there!"
#define SAY_REGINALD_WINDSOR_14_2	"Excellent work, $N. Let's find the exit. I think I know the way. Follow me!"
#define SAY_REGINALD_WINDSOR_20_1	"We made it!"
#define SAY_REGINALD_WINDSOR_20_2	"Meet me at Maxwell's encampment. We'll go over the next stages of the plan there and figure out a way to decode my tablets without the decryption ring."
#define MOB_ENTRY_SHILL_DINGER		9678    
#define MOB_ENTRY_CREST_KILLER		9680    

int wp = 0;

struct TRINITY_DLL_DECL npc_marshal_reginald_windsorAI : public npc_escortAI
{
	npc_marshal_reginald_windsorAI(Creature *c) : npc_escortAI(c) 
	{ 
		Reset(); 
	}
	  
	void WaypointReached(uint32 i)
    {
	wp=i;
	switch( i )
        {
		case 0:
			m_creature->setFaction(11); 
			m_creature->Say(SAY_REGINALD_WINDSOR_0_1, LANG_UNIVERSAL, PlayerGUID);
			break;
		case 1:
			m_creature->Say(SAY_REGINALD_WINDSOR_0_2, LANG_UNIVERSAL, PlayerGUID);
			break;
		case 7:
			m_creature->HandleEmoteCommand(EMOTE_STATE_POINT);
			m_creature->Say(SAY_REGINALD_WINDSOR_5_1, LANG_UNIVERSAL, PlayerGUID);
			IsOnHold=true;
			break;
		case 8:
			m_creature->Say(SAY_REGINALD_WINDSOR_5_2, LANG_UNIVERSAL, PlayerGUID);
			break;
		case 11:
			m_creature->HandleEmoteCommand(EMOTE_STATE_POINT);
			m_creature->Say(SAY_REGINALD_WINDSOR_7_1, LANG_UNIVERSAL, PlayerGUID);
			IsOnHold=true;
			break;
		case 12:
			m_creature->Say(SAY_REGINALD_WINDSOR_7_2, LANG_UNIVERSAL, PlayerGUID);
			break;
		case 13:
			m_creature->Say(SAY_REGINALD_WINDSOR_7_3, LANG_UNIVERSAL, PlayerGUID);
			break;
		case 20:
			m_creature->HandleEmoteCommand(EMOTE_STATE_POINT);
			m_creature->Say(SAY_REGINALD_WINDSOR_13_1, LANG_UNIVERSAL, PlayerGUID);
			IsOnHold=true;
			break;
		case 21:
			m_creature->Say(SAY_REGINALD_WINDSOR_13_3, LANG_UNIVERSAL, PlayerGUID);
			break;
		case 23:
			m_creature->HandleEmoteCommand(EMOTE_STATE_POINT);
			m_creature->Say(SAY_REGINALD_WINDSOR_14_1, LANG_UNIVERSAL, PlayerGUID);
			IsOnHold=true;
			break;
		case 24:
			m_creature->Say(SAY_REGINALD_WINDSOR_14_2, LANG_UNIVERSAL, PlayerGUID);
			break;
		case 31:
			m_creature->Say(SAY_REGINALD_WINDSOR_20_1, LANG_UNIVERSAL, PlayerGUID);
			break;
		case 32:
			m_creature->Say(SAY_REGINALD_WINDSOR_20_2, LANG_UNIVERSAL, PlayerGUID);
			PlayerStart->GroupEventHappens(QUEST_JAIL_BREAK,m_creature);
			pInstance->SetData(DATA_SHILL,ENCOUNTER_STATE_ENDED);
			break;
		}
	}

    void MoveInLineOfSight(Unit *who)
    {
        if( IsBeingEscorted )
            return;

        if( who->GetTypeId() == TYPEID_PLAYER )
        {
            if( ((Player*)who)->GetQuestStatus(4322) == QUEST_STATUS_INCOMPLETE )
            {
                float Radius = 10.0;
                if( m_creature->IsWithinDistInMap(who, Radius) )
                {
                    IsOnHold = false;
					((npc_escortAI*)(m_creature->AI()))->Start(true, true, false, who->GetGUID());
                }
            }
        }
    }

    void Aggro(Unit* who) 
		{
		switch(rand()%3)
			{
			case 0:m_creature->Say(SAY_WINDSOR_AGGRO1, LANG_UNIVERSAL, PlayerGUID);break;
			case 1:m_creature->Say(SAY_WINDSOR_AGGRO2, LANG_UNIVERSAL, PlayerGUID);break;
			case 2:m_creature->Say(SAY_WINDSOR_AGGRO3, LANG_UNIVERSAL, PlayerGUID);break;
			}
		}
    void Reset() {}

	void JustDied(Unit *slayer)
    {
		pInstance->SetData(DATA_QUEST_JAIL_BREAK,ENCOUNTER_STATE_FAILED);
    }

    void UpdateAI(const uint32 diff)
    {
		if(pInstance->GetData(DATA_QUEST_JAIL_BREAK) == ENCOUNTER_STATE_NOT_STARTED) return;
		if(wp==7)
			{
			if(!pInstance->GetData(DATA_GATE_J) && pInstance->GetData(DATA_JAZ) == ENCOUNTER_STATE_NOT_STARTED )
				{
					pInstance->SetData(DATA_CREATURE_JAZ,1);
					pInstance->SetData(DATA_JAZ,ENCOUNTER_STATE_IN_PROGRESS);
				}
			if( pInstance->GetData(DATA_CREATURE_JAZ) && pInstance->GetData(DATA_CREATURE_OGRABISI) && pInstance->GetData(DATA_JAZ) == ENCOUNTER_STATE_IN_PROGRESS )
				{
					IsOnHold = false;
					pInstance->SetData(DATA_JAZ,ENCOUNTER_STATE_ENDED);
				}
			}
		else if(wp==11)
			{
			if(!pInstance->GetData(DATA_GATE_S) && pInstance->GetData(DATA_SHILL) == ENCOUNTER_STATE_NOT_STARTED )
				{
					pInstance->SetData(DATA_CREATURE_SHILL,1);
					pInstance->SetData(DATA_SHILL,ENCOUNTER_STATE_IN_PROGRESS);
				}
			if( pInstance->GetData(DATA_CREATURE_SHILL) && pInstance->GetData(DATA_SHILL) == ENCOUNTER_STATE_IN_PROGRESS )
				{
					pInstance->SetData(DATA_SHILL,ENCOUNTER_STATE_ENDED);
					IsOnHold = false;
				}
			}
		else if(wp==20)
			{
			if(!pInstance->GetData(DATA_GATE_C) && pInstance->GetData(DATA_CREST) == ENCOUNTER_STATE_NOT_STARTED)
				{
					pInstance->SetData(DATA_CREATURE_CREST,1);
					m_creature->Say(SAY_REGINALD_WINDSOR_13_2, LANG_UNIVERSAL, PlayerGUID);
					pInstance->SetData(DATA_CREST,ENCOUNTER_STATE_IN_PROGRESS);
				}
			if( pInstance->GetData(DATA_CREATURE_CREST) && pInstance->GetData(DATA_CREST) == ENCOUNTER_STATE_IN_PROGRESS )
				{
					IsOnHold = false;
					pInstance->SetData(DATA_CREST,ENCOUNTER_STATE_ENDED);
				}
			}
		if( pInstance->GetData(DATA_TOBIAS)==ENCOUNTER_STATE_OBJECTIVE_COMPLETED ) IsOnHold = false;
		npc_escortAI::UpdateAI(diff);
    }
};
CreatureAI* GetAI_npc_marshal_reginald_windsor(Creature *_Creature)
{    
    npc_marshal_reginald_windsorAI* marshal_reginald_windsorAI = new npc_marshal_reginald_windsorAI(_Creature);
    marshal_reginald_windsorAI->AddWaypoint(0, 403.61,-52.71, -63.92,4000);
    marshal_reginald_windsorAI->AddWaypoint(1, 403.61,-52.71, -63.92,4000);
    marshal_reginald_windsorAI->AddWaypoint(2, 406.33,-54.87, -63.95,0);
    marshal_reginald_windsorAI->AddWaypoint(3, 407.99,-73.91, -62.26,0);
    marshal_reginald_windsorAI->AddWaypoint(4, 557.03,-119.71, -61.83,0);
    marshal_reginald_windsorAI->AddWaypoint(5, 573.40,-124.39, -65.07,0);
	marshal_reginald_windsorAI->AddWaypoint(6, 593.91,-130.29, -69.25,0);
	marshal_reginald_windsorAI->AddWaypoint(7, 593.21,-132.16, -69.25,0);
	marshal_reginald_windsorAI->AddWaypoint(8, 593.21,-132.16, -69.25,3000);
    marshal_reginald_windsorAI->AddWaypoint(9, 622.81,-135.55, -71.92,0);
    marshal_reginald_windsorAI->AddWaypoint(10, 634.68,-151.29, -70.32,0);
    marshal_reginald_windsorAI->AddWaypoint(11, 635.06,-153.25, -70.32,0);
    marshal_reginald_windsorAI->AddWaypoint(12, 635.06,-153.25, -70.32,3000);
    marshal_reginald_windsorAI->AddWaypoint(13, 635.06,-153.25, -70.32,1500);
    marshal_reginald_windsorAI->AddWaypoint(14, 655.25,-172.39, -73.72,0);
    marshal_reginald_windsorAI->AddWaypoint(15, 654.79,-226.30, -83.06,0);
    marshal_reginald_windsorAI->AddWaypoint(16, 622.85,-268.85, -83.96,0);
	marshal_reginald_windsorAI->AddWaypoint(17, 579.45,-275.56, -80.44,0);
    marshal_reginald_windsorAI->AddWaypoint(18, 561.19,-266.85, -75.59,0);
	marshal_reginald_windsorAI->AddWaypoint(19, 547.91,-253.92, -70.34,0);
	marshal_reginald_windsorAI->AddWaypoint(20, 549.20,-252.40, -70.34,0);
	marshal_reginald_windsorAI->AddWaypoint(21, 549.20,-252.40, -70.34,4000);
    marshal_reginald_windsorAI->AddWaypoint(22, 555.33,-269.16, -74.40,0);
    marshal_reginald_windsorAI->AddWaypoint(23, 554.31,-270.88, -74.40,0);
    marshal_reginald_windsorAI->AddWaypoint(24, 554.31,-270.88, -74.40,4000);
	marshal_reginald_windsorAI->AddWaypoint(25, 536.10,-249.60, -67.47,0);
    marshal_reginald_windsorAI->AddWaypoint(26, 520.94,-216.65, -59.28,0);
	marshal_reginald_windsorAI->AddWaypoint(27, 505.99,-148.74, -62.17,0);
    marshal_reginald_windsorAI->AddWaypoint(28, 484.21,-56.24, -62.43,0);
	marshal_reginald_windsorAI->AddWaypoint(29, 470.39,-6.01, -70.10,0);
    marshal_reginald_windsorAI->AddWaypoint(30, 451.27,30.85, -70.07,0);
    marshal_reginald_windsorAI->AddWaypoint(31, 452.45,29.85, -70.37,1500); //tezi trqbva da se opravqt
    marshal_reginald_windsorAI->AddWaypoint(32, 452.45,29.85, -70.37,7000);
    marshal_reginald_windsorAI->AddWaypoint(33, 452.45,29.85, -70.37,10000);
    marshal_reginald_windsorAI->AddWaypoint(34, 451.27,31.85, -70.07,0);
	return (CreatureAI*)marshal_reginald_windsorAI;
}

/*######
## npc_tobias_seecher
######*/

#define SAY_TOBIAS_FREE			"Thank you! I will run for safety immediately!"

struct TRINITY_DLL_DECL npc_tobias_seecherAI : public npc_escortAI
{
    npc_tobias_seecherAI(Creature *c) :npc_escortAI(c) {Reset();}
    
    void Aggro(Unit* who) { }
    void Reset() {}

    void JustDied(Unit* killer)
    {
        if (IsBeingEscorted && killer == m_creature)
        {
			m_creature->SetVisibility(VISIBILITY_OFF);
			m_creature->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
			m_creature->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
			pInstance->SetData(DATA_TOBIAS,ENCOUNTER_STATE_ENDED);
        }
    }

	void WaypointReached(uint32 i)
    {
	switch(i)
		{
		case 0:m_creature->Say(SAY_TOBIAS_FREE, LANG_UNIVERSAL, PlayerGUID); break;
		case 2:
			pInstance->SetData(DATA_TOBIAS,ENCOUNTER_STATE_OBJECTIVE_COMPLETED);break;
		case 4:
			m_creature->SetVisibility(VISIBILITY_OFF);
			m_creature->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
			m_creature->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
			pInstance->SetData(DATA_TOBIAS,ENCOUNTER_STATE_ENDED);
			break;
		}
	}

    void UpdateAI(const uint32 diff)
    {
		if(pInstance->GetData(DATA_QUEST_JAIL_BREAK) == ENCOUNTER_STATE_NOT_STARTED) return;
		if( (pInstance->GetData(DATA_QUEST_JAIL_BREAK) == ENCOUNTER_STATE_IN_PROGRESS || pInstance->GetData(DATA_QUEST_JAIL_BREAK) == ENCOUNTER_STATE_FAILED || pInstance->GetData(DATA_QUEST_JAIL_BREAK) == ENCOUNTER_STATE_ENDED)&& pInstance->GetData(DATA_TOBIAS) == ENCOUNTER_STATE_ENDED )
		{
			m_creature->SetVisibility(VISIBILITY_OFF);
			m_creature->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
			m_creature->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
		}
		else
		{
			m_creature->SetVisibility(VISIBILITY_ON);
			m_creature->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
			m_creature->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
		}
		npc_escortAI::UpdateAI(diff);
    }
};

CreatureAI* GetAI_npc_tobias_seecher(Creature *_Creature)
{    
    npc_tobias_seecherAI* tobias_seecherAI = new npc_tobias_seecherAI(_Creature);

    tobias_seecherAI->AddWaypoint(0, 549.21, -281.07, -75.27);
    tobias_seecherAI->AddWaypoint(1, 554.39, -267.39, -73.68);
    tobias_seecherAI->AddWaypoint(2, 533.59, -249.38, -67.04);
    tobias_seecherAI->AddWaypoint(3, 519.44, -217.02, -59.34);
    tobias_seecherAI->AddWaypoint(4, 506.55, -153.49, -62.34);
    return (CreatureAI*)tobias_seecherAI;
}

bool GossipHello_npc_tobias_seecher(Player *player, Creature *_Creature)
{
  	if(player->GetQuestStatus(QUEST_JAIL_BREAK) == QUEST_STATUS_INCOMPLETE && pInstance->GetData(DATA_QUEST_JAIL_BREAK) == ENCOUNTER_STATE_IN_PROGRESS )
    {
        player->ADD_GOSSIP_ITEM(0, "Get out of here, Tobias, you're free!", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1);
 		player->SEND_GOSSIP_MENU(2847, _Creature->GetGUID());
    }
    return true;
}

bool GossipSelect_npc_tobias_seecher(Player *player, Creature *_Creature, uint32 sender, uint32 action )
{
    if (action == GOSSIP_ACTION_INFO_DEF + 1)
    {
        player->CLOSE_GOSSIP_MENU();
        ((npc_escortAI*)(_Creature->AI()))->Start(false, false, true, player->GetGUID());
		_Creature->RemoveFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP);
		pInstance->SetData(DATA_TOBIAS,ENCOUNTER_STATE_IN_PROGRESS);
    }
    return true;
}

/*######
##
######*/

void AddSC_blackrock_depths()
{
    Script *newscript;

    newscript = new Script;
    newscript->Name="phalanx";
    newscript->GetAI = GetAI_mob_phalanx;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name="npc_kharan_mighthammer";
    newscript->pGossipHello =  &GossipHello_npc_kharan_mighthammer;
    newscript->pGossipSelect = &GossipSelect_npc_kharan_mighthammer;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name="npc_lokhtos_darkbargainer";
    newscript->pGossipHello =  &GossipHello_npc_lokhtos_darkbargainer;
    newscript->pGossipSelect = &GossipSelect_npc_lokhtos_darkbargainer;
    newscript->RegisterSelf();

	newscript = new Script;
	newscript->Name="npc_dughal_stormwing";
	newscript->pGossipHello =  &GossipHello_npc_dughal_stormwing;
	newscript->pGossipSelect = &GossipSelect_npc_dughal_stormwing;
	newscript->GetAI = &GetAI_npc_dughal_stormwing;
	newscript->RegisterSelf();

	newscript = new Script;
	newscript->Name="npc_tobias_seecher";
    newscript->pGossipHello =  &GossipHello_npc_tobias_seecher;
    newscript->pGossipSelect = &GossipSelect_npc_tobias_seecher;
	newscript->GetAI = &GetAI_npc_tobias_seecher;
	newscript->RegisterSelf();

	newscript = new Script;
    newscript->Name="npc_marshal_windsor";
    newscript->pQuestAccept = &QuestAccept_npc_marshal_windsor;
	newscript->GetAI = &GetAI_npc_marshal_windsor;
    newscript->RegisterSelf();

	newscript = new Script;
    newscript->Name="npc_marshal_reginald_windsor";
	newscript->GetAI = &GetAI_npc_marshal_reginald_windsor;
	newscript->RegisterSelf();
}
