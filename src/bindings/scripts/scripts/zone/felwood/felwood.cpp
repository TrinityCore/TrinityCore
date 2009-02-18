/* Copyright (C) 2006 - 2009 ScriptDev2 <https://scriptdev2.svn.sourceforge.net/>
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
SDName: Felwood
SD%Complete: 95
SDComment: Quest support: 4101, 4102
SDCategory: Felwood
EndScriptData */

/* ContentData
npcs_riverbreeze_and_silversky
EndContentData */

#include "precompiled.h"

/*######
## npcs_riverbreeze_and_silversky
######*/

#define GOSSIP_ITEM_BEACON  "Please make me a Cenarion Beacon"

bool GossipHello_npcs_riverbreeze_and_silversky(Player *player, Creature *_Creature)
{
    uint32 eCreature = _Creature->GetEntry();

    if( _Creature->isQuestGiver() )
        player->PrepareQuestMenu( _Creature->GetGUID() );

    if( eCreature==9528 )
    {
        if( player->GetQuestRewardStatus(4101) )
        {
            player->ADD_GOSSIP_ITEM(0, GOSSIP_ITEM_BEACON, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+1);
            player->SEND_GOSSIP_MENU(2848, _Creature->GetGUID());
        }else if( player->GetTeam()==HORDE )
        player->SEND_GOSSIP_MENU(2845, _Creature->GetGUID());
        else
            player->SEND_GOSSIP_MENU(2844, _Creature->GetGUID());
    }

    if( eCreature==9529 )
    {
        if( player->GetQuestRewardStatus(4102) )
        {
            player->ADD_GOSSIP_ITEM(0, GOSSIP_ITEM_BEACON, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+1);
            player->SEND_GOSSIP_MENU(2849, _Creature->GetGUID());
        }else if( player->GetTeam() == ALLIANCE )
        player->SEND_GOSSIP_MENU(2843, _Creature->GetGUID());
        else
            player->SEND_GOSSIP_MENU(2842, _Creature->GetGUID());
    }

    return true;
}

bool GossipSelect_npcs_riverbreeze_and_silversky(Player *player, Creature *_Creature, uint32 sender, uint32 action)
{
    if( action==GOSSIP_ACTION_INFO_DEF+1 )
    {
        player->CLOSE_GOSSIP_MENU();
        _Creature->CastSpell(player, 15120, false);
    }
    return true;
}

void AddSC_felwood()
{
    Script *newscript;

    newscript = new Script;
    newscript->Name="npcs_riverbreeze_and_silversky";
    newscript->pGossipHello = &GossipHello_npcs_riverbreeze_and_silversky;
    newscript->pGossipSelect = &GossipSelect_npcs_riverbreeze_and_silversky;
    newscript->RegisterSelf();
}

