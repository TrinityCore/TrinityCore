/* Copyright (C) 2008-2009 Trinity <http://www.trinitycore.org/>
 *
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

#include "precompiled.h"

/*######
## npc_frostborn_scout
######*/

#define GOSSIP_ITEM1    "Are you okay? I've come to take you back to Frosthold if you can stand."
#define GOSSIP_ITEM2    "I'm sorry that I didn't get here sooner. What happened?"
#define GOSSIP_ITEM3    "I'll go get some help. Hang in there."

enum
{
    QUEST_MISSING_SCOUTS  =  12864
};


bool GossipHello_npc_frostborn_scout(Player* pPlayer, Creature* pCreature)
{    
    
    if (pPlayer->GetQuestStatus(QUEST_MISSING_SCOUTS) == QUEST_STATUS_INCOMPLETE)
    {
        pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_ITEM1, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+1);
        pPlayer->PlayerTalkClass->SendGossipMenu(13611, pCreature->GetGUID());
    }

    return true;
}

bool GossipSelect_npc_frostborn_scout(Player* pPlayer, Creature* pCreature, uint32 uiSender, uint32 uiAction)
{
    switch (uiAction)
    {
    case GOSSIP_ACTION_INFO_DEF+1:
        pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_ITEM2, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+2);
        pPlayer->PlayerTalkClass->SendGossipMenu(13612, pCreature->GetGUID());
        break;
    case GOSSIP_ACTION_INFO_DEF+2:
        pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_ITEM3, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+3);
        pPlayer->PlayerTalkClass->SendGossipMenu(13613, pCreature->GetGUID());
        break;
    case GOSSIP_ACTION_INFO_DEF+3:
        pPlayer->PlayerTalkClass->SendGossipMenu(13614, pCreature->GetGUID());
        pPlayer->AreaExploredOrEventHappens(QUEST_MISSING_SCOUTS);
        break;
    }

    return true;
}

void AddSC_storm_peaks()
{
    Script* newscript;

    newscript = new Script;
    newscript->Name = "npc_frostborn_scout";
    newscript->pGossipHello = &GossipHello_npc_frostborn_scout;
    newscript->pGossipSelect = &GossipSelect_npc_frostborn_scout;
    newscript->RegisterSelf();
}
