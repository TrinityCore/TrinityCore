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
SDName: Feralas
SD%Complete: 100
SDComment: Quest support: 3520. Special vendor Gregan Brewspewer
SDCategory: Feralas
EndScriptData */

#include "precompiled.h"

/*######
## npc_gregan_brewspewer
######*/

#define GOSSIP_HELLO "Buy somethin', will ya?"

bool GossipHello_npc_gregan_brewspewer(Player *player, Creature *_Creature)
{
    if( _Creature->isQuestGiver() )
        player->PrepareQuestMenu( _Creature->GetGUID() );

    if( _Creature->isVendor() && player->GetQuestStatus(3909) == QUEST_STATUS_INCOMPLETE )
        player->ADD_GOSSIP_ITEM(0, GOSSIP_HELLO, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+1);

    player->SEND_GOSSIP_MENU(2433,_Creature->GetGUID());
    return true;
}

bool GossipSelect_npc_gregan_brewspewer(Player *player, Creature *_Creature, uint32 sender, uint32 action )
{
    if( action == GOSSIP_ACTION_INFO_DEF+1 )
    {
        player->ADD_GOSSIP_ITEM(1, GOSSIP_TEXT_BROWSE_GOODS, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_TRADE);
        player->SEND_GOSSIP_MENU(2434,_Creature->GetGUID());
    }
    if( action == GOSSIP_ACTION_TRADE )
        player->SEND_VENDORLIST( _Creature->GetGUID() );
    return true;
}

/*######
## npc_screecher_spirit
######*/

bool GossipHello_npc_screecher_spirit(Player *player, Creature *_Creature)
{
    player->SEND_GOSSIP_MENU(2039, _Creature->GetGUID() );
    player->TalkedToCreature(_Creature->GetEntry(), _Creature->GetGUID());
    _Creature->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);

    return true;
}

/*######
## AddSC
######*/

void AddSC_feralas()
{
    Script *newscript;

    newscript = new Script;
    newscript->Name="npc_gregan_brewspewer";
    newscript->pGossipHello = &GossipHello_npc_gregan_brewspewer;
    newscript->pGossipSelect = &GossipSelect_npc_gregan_brewspewer;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name="npc_screecher_spirit";
    newscript->pGossipHello = &GossipHello_npc_screecher_spirit;
    newscript->RegisterSelf();
}

