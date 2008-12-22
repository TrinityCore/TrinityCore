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
SDName: Tanaris
SD%Complete: 80
SDComment: Quest support: 2954, 4005, 10277, 10279(Special flight path). Noggenfogger vendor
SDCategory: Tanaris
EndScriptData */

/* ContentData
mob_aquementas
npc_custodian_of_time
npc_marin_noggenfogger
npc_steward_of_time
npc_stone_watcher_of_norgannon
EndContentData */

#include "precompiled.h"
#include "../../npc/npc_escortAI.h"

/*######
## mob_aquementas
######*/

#define AGGRO_YELL_AQUE     "Who dares awaken Aquementas?"

#define SPELL_AQUA_JET      13586
#define SPELL_FROST_SHOCK   15089

struct TRINITY_DLL_DECL mob_aquementasAI : public ScriptedAI
{
    mob_aquementasAI(Creature *c) : ScriptedAI(c) {Reset();}

    uint32 SendItem_Timer;
    uint32 SwitchFaction_Timer;
    bool isFriendly;

    uint32 FrostShock_Timer;
    uint32 AquaJet_Timer;

    void Reset()
    {
        SendItem_Timer = 0;
        SwitchFaction_Timer = 10000;
        m_creature->setFaction(35);
        isFriendly = true;

        AquaJet_Timer = 5000;
        FrostShock_Timer = 1000;
    }

    void SendItem(Unit* receiver)
    {
        if (((Player*)receiver)->HasItemCount(11169,1,false) &&
            ((Player*)receiver)->HasItemCount(11172,11,false) &&
            ((Player*)receiver)->HasItemCount(11173,1,false) &&
            !((Player*)receiver)->HasItemCount(11522,1,true))
        {
            ItemPosCountVec dest;
            uint8 msg = ((Player*)receiver)->CanStoreNewItem( NULL_BAG, NULL_SLOT, dest, 11522, 1, false);
            if( msg == EQUIP_ERR_OK )
                ((Player*)receiver)->StoreNewItem( dest, 11522, 1, true);
        }
    }

    void Aggro(Unit* who)
    {
        DoYell(AGGRO_YELL_AQUE,LANG_UNIVERSAL,who);
    }

    void UpdateAI(const uint32 diff)
    {
        if( isFriendly )
        {
            if( SwitchFaction_Timer < diff )
            {
                m_creature->setFaction(91);
                isFriendly = false;
            }else SwitchFaction_Timer -= diff;
        }

        if (!m_creature->SelectHostilTarget() || !m_creature->getVictim())
            return;

        if( !isFriendly )
        {
            if( SendItem_Timer < diff )
            {
                if( m_creature->getVictim()->GetTypeId() == TYPEID_PLAYER )
                    SendItem(m_creature->getVictim());
                SendItem_Timer = 5000;
            }else SendItem_Timer -= diff;
        }

        if( FrostShock_Timer < diff )
        {
            DoCast(m_creature->getVictim(),SPELL_FROST_SHOCK);
            FrostShock_Timer = 15000;
        }else FrostShock_Timer -= diff;

        if( AquaJet_Timer < diff )
        {
            DoCast(m_creature,SPELL_AQUA_JET);
            AquaJet_Timer = 15000;
        }else AquaJet_Timer -= diff;

        DoMeleeAttackIfReady();
    }
};
CreatureAI* GetAI_mob_aquementas(Creature *_Creature)
{
    return new mob_aquementasAI (_Creature);
}

/*######
## npc_custodian_of_time
######*/

#define WHISPER_CUSTODIAN_1     "Greetings, $N. I will guide you through the cavern. Please try and keep up."
#define WHISPER_CUSTODIAN_2     "We do not know if the Caverns of Time have always been accessible to mortals. Truly, it is impossible to tell as the Timeless One is in perpetual motion, changing our timeways as he sees fit. What you see now may very well not exist tomorrow. You may wake up and have no memory of this place."
#define WHISPER_CUSTODIAN_3     "It is strange, I know... Most mortals cannot actually comprehend what they see here, as often, what they see is not anchored within their own perception of reality."
#define WHISPER_CUSTODIAN_4     "Follow me, please."
#define WHISPER_CUSTODIAN_5     "There are only two truths to be found here: First, that time is chaotic, always in flux, and completely malleable and second, perception does not dictate reality."
#define WHISPER_CUSTODIAN_6     "As custodians of time, we watch over and care for Nozdormu's realm. The master is away at the moment, which means that attempts are being made to dramatically alter time. The master never meddles in the affairs of mortals but instead corrects the alterations made to time by others. He is reactionary in this regard."
#define WHISPER_CUSTODIAN_7     "For normal maintenance of time, the Keepers of Time are sufficient caretakers. We are able to deal with most ordinary disturbances. I speak of little things, such as rogue mages changing something in the past to elevate their status or wealth in the present."
#define WHISPER_CUSTODIAN_8     "These tunnels that you see are called timeways. They are infinite in number. The ones that currently exist in your reality are what the master has deemed as 'trouble spots.' These trouble spots may differ completely in theme but they always share a cause. That is, their existence is a result of the same temporal disturbance. Remember that should you venture inside one..."
#define WHISPER_CUSTODIAN_9     "This timeway is in great disarray! We have agents inside right now attempting to restore order. What information I have indicates that Thrall's freedom is in jeopardy. A malevolent organization known as the Infinite Dragonflight is trying to prevent his escape. I fear without outside assistance, all will be lost."
#define WHISPER_CUSTODIAN_10    "We have very little information on this timeway. Sa'at has been dispatched and is currently inside. The data we have gathered from his correspondence is that the Infinite Dragonflight are once again attempting to alter time. Could it be that the opening of the Dark Portal is being targeted for sabotage? Let us hope not..."
#define WHISPER_CUSTODIAN_11    "This timeway is currently collapsing. What that may hold for the past, present and future is currently unknown..."
#define WHISPER_CUSTODIAN_12    "The timeways are currently ranked in order from least catastrophic to most catastrophic. Note that they are all classified as catastrophic, meaning that any single one of these timeways collapsing would mean that your world would end. We only classify them in such a way so that the heroes and adventurers that are sent here know which timeway best suits their abilities."
#define WHISPER_CUSTODIAN_13    "All we know of this timeway is that it leads to Mount Hyjal. The Infinite Dragonflight have gone to great lengths to prevent our involvement. We know next to nothing, mortal. Soridormi is currently attempting to break through the timeway's defenses but has thus far been unsuccessful. You might be our only hope of breaking through and resolving the conflict."
#define WHISPER_CUSTODIAN_14    "Our time is at an end $N. I would wish you luck, if such a thing existed."

struct TRINITY_DLL_DECL npc_custodian_of_timeAI : public npc_escortAI
{
    npc_custodian_of_timeAI(Creature *c) : npc_escortAI(c) { Reset(); }

    void WaypointReached(uint32 i)
    {
        Unit *pTemp = Unit::GetUnit(*m_creature,PlayerGUID);
        if( !pTemp )
            return;

        switch( i )
        {
            case 0: DoWhisper(WHISPER_CUSTODIAN_1, pTemp); break;
            case 1: DoWhisper(WHISPER_CUSTODIAN_2, pTemp); break;
            case 2: DoWhisper(WHISPER_CUSTODIAN_3, pTemp); break;
            case 3: DoWhisper(WHISPER_CUSTODIAN_4, pTemp); break;
            case 5: DoWhisper(WHISPER_CUSTODIAN_5, pTemp); break;
            case 6: DoWhisper(WHISPER_CUSTODIAN_6, pTemp); break;
            case 7: DoWhisper(WHISPER_CUSTODIAN_7, pTemp); break;
            case 8: DoWhisper(WHISPER_CUSTODIAN_8, pTemp); break;
            case 9: DoWhisper(WHISPER_CUSTODIAN_9, pTemp); break;
            case 10: DoWhisper(WHISPER_CUSTODIAN_4, pTemp); break;
            case 13: DoWhisper(WHISPER_CUSTODIAN_10, pTemp); break;
            case 14: DoWhisper(WHISPER_CUSTODIAN_4, pTemp); break;
            case 16: DoWhisper(WHISPER_CUSTODIAN_11, pTemp); break;
            case 17: DoWhisper(WHISPER_CUSTODIAN_12, pTemp); break;
            case 18: DoWhisper(WHISPER_CUSTODIAN_4, pTemp); break;
            case 22: DoWhisper(WHISPER_CUSTODIAN_13, pTemp); break;
            case 23: DoWhisper(WHISPER_CUSTODIAN_4, pTemp); break;
            case 24:
                DoWhisper(WHISPER_CUSTODIAN_14, pTemp);
                DoCast(pTemp,34883);
                //below here is temporary workaround, to be removed when spell works properly
                ((Player*)pTemp)->AreaExploredOrEventHappens(10277);
                break;
        }
    }

    void MoveInLineOfSight(Unit *who)
    {
        if( IsBeingEscorted )
            return;

        if( who->GetTypeId() == TYPEID_PLAYER )
        {
            if( ((Player*)who)->HasAura(34877,1) && ((Player*)who)->GetQuestStatus(10277) == QUEST_STATUS_INCOMPLETE )
            {
                float Radius = 10.0;
                if( m_creature->IsWithinDistInMap(who, Radius) )
                {
                    ((npc_escortAI*)(m_creature->AI()))->Start(false, false, false, who->GetGUID());
                }
            }
        }
    }

    void Aggro(Unit* who) { }
    void Reset() { }

    void UpdateAI(const uint32 diff)
    {
        npc_escortAI::UpdateAI(diff);
    }
};

CreatureAI* GetAI_npc_custodian_of_time(Creature *_Creature)
{
    npc_custodian_of_timeAI* custodian_of_timeAI = new npc_custodian_of_timeAI(_Creature);

    custodian_of_timeAI->AddWaypoint(0, -8374.93,-4250.21, -204.38,5000);
    custodian_of_timeAI->AddWaypoint(1, -8374.93,-4250.21, -204.38,16000);
    custodian_of_timeAI->AddWaypoint(2, -8374.93,-4250.21, -204.38,10000);
    custodian_of_timeAI->AddWaypoint(3, -8374.93,-4250.21, -204.38,2000);
    custodian_of_timeAI->AddWaypoint(4, -8439.40,-4180.05, -209.25);
    custodian_of_timeAI->AddWaypoint(5, -8437.82,-4120.84, -208.59,10000);
    custodian_of_timeAI->AddWaypoint(6, -8437.82,-4120.84, -208.59,16000);
    custodian_of_timeAI->AddWaypoint(7, -8437.82,-4120.84, -208.59,13000);
    custodian_of_timeAI->AddWaypoint(8, -8437.82,-4120.84, -208.59,18000);
    custodian_of_timeAI->AddWaypoint(9, -8437.82,-4120.84, -208.59,15000);
    custodian_of_timeAI->AddWaypoint(10, -8437.82,-4120.84, -208.59,2000);
    custodian_of_timeAI->AddWaypoint(11, -8467.26,-4198.63, -214.21);
    custodian_of_timeAI->AddWaypoint(12, -8667.76,-4252.13, -209.56);
    custodian_of_timeAI->AddWaypoint(13, -8703.71,-4234.58, -209.5,14000);
    custodian_of_timeAI->AddWaypoint(14, -8703.71,-4234.58, -209.5,2000);
    custodian_of_timeAI->AddWaypoint(15, -8642.81,-4304.37, -209.57);
    custodian_of_timeAI->AddWaypoint(16, -8649.06,-4394.36, -208.46,6000);
    custodian_of_timeAI->AddWaypoint(17, -8649.06,-4394.36, -208.46,18000);
    custodian_of_timeAI->AddWaypoint(18, -8649.06,-4394.36, -208.46,2000);
    custodian_of_timeAI->AddWaypoint(19, -8468.72,-4437.67, -215.45);
    custodian_of_timeAI->AddWaypoint(20, -8427.54,-4426, -211.13);
    custodian_of_timeAI->AddWaypoint(21, -8364.83,-4393.32, -205.91);
    custodian_of_timeAI->AddWaypoint(22, -8304.54,-4357.2, -208.2,18000);
    custodian_of_timeAI->AddWaypoint(23, -8304.54,-4357.2, -208.2,2000);
    custodian_of_timeAI->AddWaypoint(24, -8375.42,-4250.41, -205.14,5000);
    custodian_of_timeAI->AddWaypoint(25, -8375.42,-4250.41, -205.14,5000);

    return (CreatureAI*)custodian_of_timeAI;
}

/*######
## npc_marin_noggenfogger
######*/

bool GossipHello_npc_marin_noggenfogger(Player *player, Creature *_Creature)
{
    if( _Creature->isQuestGiver() )
        player->PrepareQuestMenu( _Creature->GetGUID() );

    if( _Creature->isVendor() && player->GetQuestRewardStatus(2662) )
        player->ADD_GOSSIP_ITEM(1, GOSSIP_TEXT_BROWSE_GOODS, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_TRADE);

    player->SEND_GOSSIP_MENU(_Creature->GetNpcTextId(), _Creature->GetGUID());

    return true;
}

bool GossipSelect_npc_marin_noggenfogger(Player *player, Creature *_Creature, uint32 sender, uint32 action)
{
    if( action == GOSSIP_ACTION_TRADE )
        player->SEND_VENDORLIST( _Creature->GetGUID() );

    return true;
}

/*######
## npc_steward_of_time
######*/

#define GOSSIP_ITEM_FLIGHT  "Please take me to the master's lair."

bool GossipHello_npc_steward_of_time(Player *player, Creature *_Creature)
{
    if( _Creature->isQuestGiver() )
        player->PrepareQuestMenu( _Creature->GetGUID() );

    if( player->GetQuestStatus(10279) == QUEST_STATUS_INCOMPLETE || player->GetQuestRewardStatus(10279) )
    {
        player->ADD_GOSSIP_ITEM(0, GOSSIP_ITEM_FLIGHT, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1);
        player->SEND_GOSSIP_MENU(9978,_Creature->GetGUID());
    }
    else
        player->SEND_GOSSIP_MENU(9977,_Creature->GetGUID());

    return true;
}

bool QuestAccept_npc_steward_of_time(Player *player, Creature *creature, Quest const *quest )
{
    if( quest->GetQuestId() == 10279 )                      //Quest: To The Master's Lair
        player->CastSpell(player,34891,true);               //(Flight through Caverns)

    return false;
}

bool GossipSelect_npc_steward_of_time(Player *player, Creature *_Creature, uint32 sender, uint32 action )
{
    if( action == GOSSIP_ACTION_INFO_DEF + 1 )
        player->CastSpell(player,34891,true);               //(Flight through Caverns)

    return true;
}

/*######
## npc_stone_watcher_of_norgannon
######*/

#define GOSSIP_ITEM_NORGANNON_1     "What function do you serve?"
#define GOSSIP_ITEM_NORGANNON_2     "What are the Plates of Uldum?"
#define GOSSIP_ITEM_NORGANNON_3     "Where are the Plates of Uldum?"
#define GOSSIP_ITEM_NORGANNON_4     "Excuse me? We've been \"reschedueled for visitations\"? What does that mean?!"
#define GOSSIP_ITEM_NORGANNON_5     "So, what's inside Uldum?"
#define GOSSIP_ITEM_NORGANNON_6     "I will return when i have the Plates of Uldum."

bool GossipHello_npc_stone_watcher_of_norgannon(Player *player, Creature *_Creature)
{
    if( _Creature->isQuestGiver() )
        player->PrepareQuestMenu( _Creature->GetGUID() );

    if( player->GetQuestStatus(2954) == QUEST_STATUS_INCOMPLETE )
        player->ADD_GOSSIP_ITEM( 0, GOSSIP_ITEM_NORGANNON_1, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF);

    player->SEND_GOSSIP_MENU(1674, _Creature->GetGUID());

    return true;
}

bool GossipSelect_npc_stone_watcher_of_norgannon(Player *player, Creature *_Creature, uint32 sender, uint32 action)
{
    switch (action)
    {
        case GOSSIP_ACTION_INFO_DEF:
            player->ADD_GOSSIP_ITEM( 0, GOSSIP_ITEM_NORGANNON_2, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+1);
            player->SEND_GOSSIP_MENU(1675, _Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF+1:
            player->ADD_GOSSIP_ITEM( 0, GOSSIP_ITEM_NORGANNON_3, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+2);
            player->SEND_GOSSIP_MENU(1676, _Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF+2:
            player->ADD_GOSSIP_ITEM( 0, GOSSIP_ITEM_NORGANNON_4, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+3);
            player->SEND_GOSSIP_MENU(1677, _Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF+3:
            player->ADD_GOSSIP_ITEM( 0, GOSSIP_ITEM_NORGANNON_5, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+4);
            player->SEND_GOSSIP_MENU(1678, _Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF+4:
            player->ADD_GOSSIP_ITEM( 0, GOSSIP_ITEM_NORGANNON_6, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+5);
            player->SEND_GOSSIP_MENU(1679, _Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF+5:
            player->CLOSE_GOSSIP_MENU();
            player->AreaExploredOrEventHappens(2954);
            break;
    }
    return true;
}

/*######
## AddSC
######*/

void AddSC_tanaris()
{
    Script *newscript;

    newscript = new Script;
    newscript->Name="mob_aquementas";
    newscript->GetAI = &GetAI_mob_aquementas;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name="npc_custodian_of_time";
    newscript->GetAI = &GetAI_npc_custodian_of_time;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name="npc_marin_noggenfogger";
    newscript->pGossipHello =  &GossipHello_npc_marin_noggenfogger;
    newscript->pGossipSelect = &GossipSelect_npc_marin_noggenfogger;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name="npc_steward_of_time";
    newscript->pGossipHello =  &GossipHello_npc_steward_of_time;
    newscript->pGossipSelect = &GossipSelect_npc_steward_of_time;
    newscript->pQuestAccept =  &QuestAccept_npc_steward_of_time;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name="npc_stone_watcher_of_norgannon";
    newscript->pGossipHello =  &GossipHello_npc_stone_watcher_of_norgannon;
    newscript->pGossipSelect = &GossipSelect_npc_stone_watcher_of_norgannon;
    newscript->RegisterSelf();
}
