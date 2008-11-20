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
SDName: Ghostlands
SD%Complete: 100
SDComment: Quest support: 9692. Obtain Budd's Guise of Zul'aman. Vendor Rathis Tomber
SDCategory: Ghostlands
EndScriptData */

/* ContentData
npc_blood_knight_dawnstar
npc_budd_nedreck
npc_rathis_tomber
EndContentData */

#include "precompiled.h"

/*######
## npc_blood_knight_dawnstar
######*/

bool GossipHello_npc_blood_knight_dawnstar(Player *player, Creature *_Creature)
{
    if (player->GetQuestStatus(9692) == QUEST_STATUS_INCOMPLETE && !player->HasItemCount(24226,1,true))
        player->ADD_GOSSIP_ITEM( 0, "Take Blood Knight Insignia", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+1);

    player->SEND_GOSSIP_MENU(_Creature->GetNpcTextId(), _Creature->GetGUID());

    return true;
}

bool GossipSelect_npc_blood_knight_dawnstar(Player *player, Creature *_Creature, uint32 sender, uint32 action)
{
    if (action == GOSSIP_ACTION_INFO_DEF+1)
    {
        ItemPosCountVec dest;
        uint8 msg = player->CanStoreNewItem( NULL_BAG, NULL_SLOT, dest, 24226, 1, false);
        if( msg == EQUIP_ERR_OK )
        {
            player->StoreNewItem( dest, 24226, 1, true);
            player->PlayerTalkClass->ClearMenus();
        }
    }
    return true;
}

/*######
## npc_budd_nedreck
######*/

bool GossipHello_npc_budd_nedreck(Player *player, Creature *_Creature)
{
    if( _Creature->isQuestGiver())
        player->PrepareQuestMenu( _Creature->GetGUID() );

    if( player->GetQuestStatus(11166) == QUEST_STATUS_INCOMPLETE)
        player->ADD_GOSSIP_ITEM(0,"You gave the crew disguises?",GOSSIP_SENDER_MAIN,GOSSIP_ACTION_INFO_DEF);

    player->SEND_GOSSIP_MENU(_Creature->GetNpcTextId(),_Creature->GetGUID());
    return true;
}

bool GossipSelect_npc_budd_nedreck(Player *player, Creature *_Creature, uint32 sender, uint32 action )
{
    if( action==GOSSIP_ACTION_INFO_DEF )
    {
        player->CLOSE_GOSSIP_MENU();
        _Creature->CastSpell(player, 42540, false);
    }
    return true;
}

/*######
## npc_rathis_tomber
######*/

bool GossipHello_npc_rathis_tomber(Player *player, Creature *_Creature)
{
    if( _Creature->isQuestGiver() )
        player->PrepareQuestMenu( _Creature->GetGUID() );

    if( _Creature->isVendor() && player->GetQuestRewardStatus(9152) )
    {
        player->ADD_GOSSIP_ITEM(1, GOSSIP_TEXT_BROWSE_GOODS, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_TRADE);
        player->SEND_GOSSIP_MENU(8432,_Creature->GetGUID());
    }else
    player->SEND_GOSSIP_MENU(8431,_Creature->GetGUID());

    return true;
}

bool GossipSelect_npc_rathis_tomber(Player *player, Creature *_Creature, uint32 sender, uint32 action )
{
    if( action == GOSSIP_ACTION_TRADE )
        player->SEND_VENDORLIST( _Creature->GetGUID() );
    return true;
}

/*#####
## go_gilded_brazier (Paladin First Trail quest (9678))
#####*/

bool GOHello_gilded_brazier(Player *player, GameObject* _GO)
{
    if (player->GetQuestStatus(9678) == QUEST_STATUS_INCOMPLETE)
    {
        Creature *Stillblade = player->SummonCreature(17716, 8106.11, -7542.06, 151.775, 3.02598, TEMPSUMMON_DEAD_DESPAWN, 60000);
        if (Stillblade)
            ((CreatureAI*)Stillblade->AI())->AttackStart(player);
    }
    return true;
};

void AddSC_ghostlands()
{
    Script *newscript;

    newscript = new Script;
    newscript->Name="npc_blood_knight_dawnstar";
    newscript->pGossipHello = &GossipHello_npc_blood_knight_dawnstar;
    newscript->pGossipSelect = &GossipSelect_npc_blood_knight_dawnstar;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name="npc_budd_nedreck";
    newscript->pGossipHello = &GossipHello_npc_budd_nedreck;
    newscript->pGossipSelect = &GossipSelect_npc_budd_nedreck;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name="npc_rathis_tomber";
    newscript->pGossipHello = &GossipHello_npc_rathis_tomber;
    newscript->pGossipSelect = &GossipSelect_npc_rathis_tomber;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "go_gilded_brazier";
    newscript->pGOHello = &GOHello_gilded_brazier;
    newscript->RegisterSelf();
}
