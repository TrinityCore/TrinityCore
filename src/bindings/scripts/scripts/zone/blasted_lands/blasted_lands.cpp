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
SDName: Blasted_Lands
SD%Complete: 90
SDComment: Quest support: 2784, 2801, 3628. Missing some texts for Fallen Hero. Teleporter to Rise of the Defiler missing group support.
SDCategory: Blasted Lands
EndScriptData */

/* ContentData
npc_deathly_usher
npc_fallen_hero_of_horde
EndContentData */

#include "precompiled.h"

/*######
## npc_deathly_usher
######*/

#define GOSSIP_ITEM_USHER "I wish to to visit the Rise of the Defiler."

#define SPELL_TELEPORT_SINGLE           12885
#define SPELL_TELEPORT_SINGLE_IN_GROUP  13142
#define SPELL_TELEPORT_GROUP            27686

bool GossipHello_npc_deathly_usher(Player *player, Creature *_Creature)
{
    if(player->GetQuestStatus(3628) == QUEST_STATUS_INCOMPLETE && player->HasItemCount(10757, 1))
        player->ADD_GOSSIP_ITEM(0, GOSSIP_ITEM_USHER, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF);

    player->SEND_GOSSIP_MENU(_Creature->GetNpcTextId(), _Creature->GetGUID());

    return true;
}

bool GossipSelect_npc_deathly_usher(Player *player, Creature *_Creature, uint32 sender, uint32 action)
{
    if(action == GOSSIP_ACTION_INFO_DEF)
    {
        player->CLOSE_GOSSIP_MENU();
        _Creature->CastSpell(player, SPELL_TELEPORT_SINGLE, true);
    }

    return true;
}

/*######
## npc_fallen_hero_of_horde
######*/
#define GOSSIP_H_F1 "Why are you here?"
#define GOSSIP_H_F2 "Continue story..."

#define GOSSIP_ITEM_FALLEN "Continue..."

#define GOSSIP_ITEM_FALLEN1 "What could be worse than death?"
#define GOSSIP_ITEM_FALLEN2 "Subordinates?"
#define GOSSIP_ITEM_FALLEN3 "What are the stones of binding?"
#define GOSSIP_ITEM_FALLEN4 "You can count on me, Hero"
#define GOSSIP_ITEM_FALLEN5 "I shall"

bool GossipHello_npc_fallen_hero_of_horde(Player *player, Creature *_Creature)
{
    if (_Creature->isQuestGiver())
        player->PrepareQuestMenu( _Creature->GetGUID() );

    if (player->GetQuestStatus(2784) == QUEST_STATUS_INCOMPLETE)
        player->ADD_GOSSIP_ITEM( 0, GOSSIP_H_F1, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+1);

    if (player->GetQuestStatus(2801) == QUEST_STATUS_INCOMPLETE && player->GetTeam() == HORDE)
        player->ADD_GOSSIP_ITEM( 0, GOSSIP_H_F2, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+2);

    if (player->GetQuestStatus(2801) == QUEST_STATUS_INCOMPLETE && player->GetTeam() == ALLIANCE)
        player->ADD_GOSSIP_ITEM( 0, GOSSIP_H_F1, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+1);

    player->SEND_GOSSIP_MENU(_Creature->GetNpcTextId(), _Creature->GetGUID());

    return true;
}

bool GossipSelect_npc_fallen_hero_of_horde(Player *player, Creature *_Creature, uint32 sender, uint32 action)
{
    switch (action)
    {
        case GOSSIP_ACTION_INFO_DEF+1:
            player->ADD_GOSSIP_ITEM( 0, GOSSIP_ITEM_FALLEN, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 11);
            player->SEND_GOSSIP_MENU(1392, _Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF+11:
            player->SEND_GOSSIP_MENU(1411, _Creature->GetGUID());
            if (player->GetQuestStatus(2784) == QUEST_STATUS_INCOMPLETE)
                player->AreaExploredOrEventHappens(2784);
            if (player->GetTeam() == ALLIANCE)
            {
                player->ADD_GOSSIP_ITEM( 0, GOSSIP_ITEM_FALLEN, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 2);
                player->SEND_GOSSIP_MENU(1411, _Creature->GetGUID());
            }
            break;

        case GOSSIP_ACTION_INFO_DEF+2:
            player->ADD_GOSSIP_ITEM( 0, GOSSIP_ITEM_FALLEN, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 21);
            player->SEND_GOSSIP_MENU(1451, _Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF+21:
            player->ADD_GOSSIP_ITEM( 0, GOSSIP_ITEM_FALLEN1, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 22);
            player->SEND_GOSSIP_MENU(1452, _Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF+22:
            player->ADD_GOSSIP_ITEM( 0, GOSSIP_ITEM_FALLEN2, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 23);
            player->SEND_GOSSIP_MENU(1453, _Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF+23:
            player->ADD_GOSSIP_ITEM( 0, GOSSIP_ITEM_FALLEN3, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 24);
            player->SEND_GOSSIP_MENU(1454, _Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF+24:
            player->ADD_GOSSIP_ITEM( 0, GOSSIP_ITEM_FALLEN4, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 25);
            player->SEND_GOSSIP_MENU(1455, _Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF+25:
            player->ADD_GOSSIP_ITEM( 0, GOSSIP_ITEM_FALLEN5, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 26);
            player->SEND_GOSSIP_MENU(1456, _Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF+26:
            player->CLOSE_GOSSIP_MENU();
            player->AreaExploredOrEventHappens(2801);
            break;
    }
    return true;
}

void AddSC_blasted_lands()
{
    Script *newscript;

    newscript = new Script;
    newscript->Name="npc_deathly_usher";
    newscript->pGossipHello =  &GossipHello_npc_deathly_usher;
    newscript->pGossipSelect = &GossipSelect_npc_deathly_usher;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name="npc_fallen_hero_of_horde";
    newscript->pGossipHello =  &GossipHello_npc_fallen_hero_of_horde;
    newscript->pGossipSelect = &GossipSelect_npc_fallen_hero_of_horde;
    newscript->RegisterSelf();
}

