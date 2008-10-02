/* Copyright (C) 2006 - 2008 ScriptDev2 <https://scriptdev2.svn.sourceforge.net/>
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

/* ScriptData
SDName: Moonglade
SD%Complete: 100
SDComment: Quest support: 30, 272, 5929, 5930. Special Flight Paths for Druid class.
SDCategory: Moonglade
EndScriptData */

/* ContentData
npc_bunthen_plainswind
npc_great_bear_spirit
npc_silva_filnaveth
EndContentData */

#include "precompiled.h"

/*######
## npc_bunthen_plainswind
######*/

bool GossipHello_npc_bunthen_plainswind(Player *player, Creature *_Creature)
{
    if(player->getClass() != CLASS_DRUID)
        player->SEND_GOSSIP_MENU(4916,_Creature->GetGUID());
    else if(player->GetTeam() != HORDE)
    {
        if(player->GetQuestStatus(272) == QUEST_STATUS_INCOMPLETE)
            player->ADD_GOSSIP_ITEM( 0, "Do you know where I can find Half Pendant of Aquatic Endurance?", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 2);

        player->SEND_GOSSIP_MENU(4917,_Creature->GetGUID());
    }
    else if(player->getClass() == CLASS_DRUID && player->GetTeam() == HORDE)
    {
        player->ADD_GOSSIP_ITEM( 0, "I'd like to fly to Thunder Bluff.", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1);

        if(player->GetQuestStatus(30) == QUEST_STATUS_INCOMPLETE)
            player->ADD_GOSSIP_ITEM( 0, "Do you know where I can find Half Pendant of Aquatic Endurance?", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 3);

        player->SEND_GOSSIP_MENU(4918,_Creature->GetGUID());
    }
    return true;
}

bool GossipSelect_npc_bunthen_plainswind(Player *player, Creature *_Creature, uint32 sender, uint32 action )
{
    switch(action)
    {
        case GOSSIP_ACTION_INFO_DEF + 1:
        {
            player->CLOSE_GOSSIP_MENU();
            if (player->getClass() == CLASS_DRUID && player->GetTeam() == HORDE)
            {
                std::vector<uint32> nodes;

                nodes.resize(2);
                nodes[0] = 63;                              // Nighthaven, Moonglade
                nodes[1] = 22;                              // Thunder Bluff, Mulgore
                player->ActivateTaxiPathTo(nodes);
            }
            break;
        }
        case GOSSIP_ACTION_INFO_DEF + 2:
            player->SEND_GOSSIP_MENU(5373,_Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 3:
            player->SEND_GOSSIP_MENU(5376,_Creature->GetGUID());
            break;
    }
    return true;
}

/*######
## npc_great_bear_spirit
######*/

#define GOSSIP_BEAR1 "What do you represent, spirit?"
#define GOSSIP_BEAR2 "I seek to understand the importance of strength of the body."
#define GOSSIP_BEAR3 "I seek to understand the importance of strength of the heart."
#define GOSSIP_BEAR4 "I have heard your words, Great Bear Spirit, and I understand. I now seek your blessings to fully learn the way of the Claw."

bool GossipHello_npc_great_bear_spirit(Player *player, Creature *_Creature)
{
    //ally or horde quest
    if (player->GetQuestStatus(5929) == QUEST_STATUS_INCOMPLETE || player->GetQuestStatus(5930) == QUEST_STATUS_INCOMPLETE)
    {
        player->ADD_GOSSIP_ITEM( 0, GOSSIP_BEAR1, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF);
        player->SEND_GOSSIP_MENU(4719, _Creature->GetGUID());
    }
    else
        player->SEND_GOSSIP_MENU(4718, _Creature->GetGUID());

    return true;
}

bool GossipSelect_npc_great_bear_spirit(Player *player, Creature *_Creature, uint32 sender, uint32 action )
{
    switch (action)
    {
        case GOSSIP_ACTION_INFO_DEF:
            player->ADD_GOSSIP_ITEM( 0, GOSSIP_BEAR2, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1);
            player->SEND_GOSSIP_MENU(4721, _Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 1:
            player->ADD_GOSSIP_ITEM( 0, GOSSIP_BEAR3, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 2);
            player->SEND_GOSSIP_MENU(4733, _Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 2:
            player->ADD_GOSSIP_ITEM( 0, GOSSIP_BEAR4, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 3);
            player->SEND_GOSSIP_MENU(4734, _Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 3:
            player->SEND_GOSSIP_MENU(4735, _Creature->GetGUID());
            if (player->GetQuestStatus(5929)==QUEST_STATUS_INCOMPLETE)
                player->AreaExploredOrEventHappens(5929);
            if (player->GetQuestStatus(5930)==QUEST_STATUS_INCOMPLETE)
                player->AreaExploredOrEventHappens(5930);
            break;
    }
    return true;
}

/*######
## npc_silva_filnaveth
######*/

bool GossipHello_npc_silva_filnaveth(Player *player, Creature *_Creature)
{
    if(player->getClass() != CLASS_DRUID)
        player->SEND_GOSSIP_MENU(4913,_Creature->GetGUID());
    else if(player->GetTeam() != ALLIANCE)
    {
        if(player->GetQuestStatus(30) == QUEST_STATUS_INCOMPLETE)
            player->ADD_GOSSIP_ITEM( 0, "Do you know where I can find Half Pendant of Aquatic Agility?", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 2);

        player->SEND_GOSSIP_MENU(4915,_Creature->GetGUID());
    }
    else if(player->getClass() == CLASS_DRUID && player->GetTeam() == ALLIANCE)
    {
        player->ADD_GOSSIP_ITEM( 0, "I'd like to fly to Rut'theran Village.", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1);

        if(player->GetQuestStatus(272) == QUEST_STATUS_INCOMPLETE)
            player->ADD_GOSSIP_ITEM( 0, "Do you know where I can find Half Pendant of Aquatic Agility?", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 3);

        player->SEND_GOSSIP_MENU(4914,_Creature->GetGUID());
    }
    return true;
}

bool GossipSelect_npc_silva_filnaveth(Player *player, Creature *_Creature, uint32 sender, uint32 action )
{
    switch(action)
    {
        case GOSSIP_ACTION_INFO_DEF + 1:
        {
            player->CLOSE_GOSSIP_MENU();
            if (player->getClass() == CLASS_DRUID && player->GetTeam() == ALLIANCE)
            {
                std::vector<uint32> nodes;

                nodes.resize(2);
                nodes[0] = 62;                              // Nighthaven, Moonglade
                nodes[1] = 27;                              // Rut'theran Village, Teldrassil
                player->ActivateTaxiPathTo(nodes);
            }
            break;
        }
        case GOSSIP_ACTION_INFO_DEF + 2:
            player->SEND_GOSSIP_MENU(5374,_Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 3:
            player->SEND_GOSSIP_MENU(5375,_Creature->GetGUID());
            break;
    }
    return true;
}

/*######
##
######*/

void AddSC_moonglade()
{
    Script *newscript;

    newscript = new Script;
    newscript->Name="npc_bunthen_plainswind";
    newscript->pGossipHello =  &GossipHello_npc_bunthen_plainswind;
    newscript->pGossipSelect = &GossipSelect_npc_bunthen_plainswind;
    m_scripts[nrscripts++] = newscript;

    newscript = new Script;
    newscript->Name="npc_great_bear_spirit";
    newscript->pGossipHello =  &GossipHello_npc_great_bear_spirit;
    newscript->pGossipSelect = &GossipSelect_npc_great_bear_spirit;
    m_scripts[nrscripts++] = newscript;

    newscript = new Script;
    newscript->Name="npc_silva_filnaveth";
    newscript->pGossipHello =  &GossipHello_npc_silva_filnaveth;
    newscript->pGossipSelect = &GossipSelect_npc_silva_filnaveth;
    m_scripts[nrscripts++] = newscript;
}
