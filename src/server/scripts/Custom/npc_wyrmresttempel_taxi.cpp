/*
 * Copyright (C) 2008-2010 TrinityCore <http://www.trinitycore.org/>
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

#include "ScriptPCH.h"
#include "WorldPacket.h"

#define GOSSIP_UP      "My Lord, I must go to the upper floor of the temple."
#define GOSSIP_DOWN    "I would like to take a flight to the ground, Lord Afrasastrasz."
#define GOSSIP_MIDDLE  "Can you spare a drake to travel to Lord Afrasastrasz, in the middle of the temple?"
#define GOSSIP_TOP     "Please, Let me take one of these dragons to the top floor of the temple."
#define GOSSIP_BOTTOM  "Yes, Please. I would like to return to the ground floor of the temple."
#define GOSSIP_ONEDOWN "I would like to see Lord Afrasastrasz, in the middle of the temple."

class npc_wyrmrest_temple_middle_taxi : public CreatureScript
{
public:
    npc_wyrmrest_temple_middle_taxi() : CreatureScript("npc_wyrmresttempelmiddle_taxi") { }

    bool OnGossipHello(Player* pPlayer, Creature* pCreature)
    {
        pPlayer->SetTaxiCheater(true);

        pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_UP, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1);
        pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_DOWN, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 2);
        pPlayer->SEND_GOSSIP_MENU(12887, pCreature->GetGUID());

        return true;
    }

    bool OnGossipSelect(Player* pPlayer, Creature* /*pCreature*/, uint32 /*uiSender*/, uint32 uiAction)
    {
        pPlayer->PlayerTalkClass->ClearMenus();
        if (uiAction == GOSSIP_ACTION_INFO_DEF + 1)
            pPlayer->GetSession()->SendDoFlight(6376, 881);

        if (uiAction == GOSSIP_ACTION_INFO_DEF + 2)
            pPlayer->GetSession()->SendDoFlight(6376, 882);

        return true;
    }
};

class npc_wyrmrest_temple_bottom_taxi : public CreatureScript
{
public:
    npc_wyrmrest_temple_bottom_taxi() : CreatureScript("npc_wyrmresttempelbottom_taxi") { }
    bool OnGossipHello(Player* pPlayer, Creature* pCreature)
    {
        pPlayer->SetTaxiCheater(true);

        pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_TOP, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 4);
        pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_MIDDLE, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 3);
        pPlayer->SEND_GOSSIP_MENU(12713, pCreature->GetGUID());

        return true;
    }

    bool OnGossipSelect(Player* pPlayer, Creature* /*pCreature*/, uint32 /*uiSender*/, uint32 uiAction)
    {
        pPlayer->PlayerTalkClass->ClearMenus();
        if (uiAction == GOSSIP_ACTION_INFO_DEF + 4)
            pPlayer->GetSession()->SendDoFlight(6376, 878);

        if (uiAction == GOSSIP_ACTION_INFO_DEF + 3)
            pPlayer->GetSession()->SendDoFlight(6376, 883);
        return true;
    }
};

class npc_wyrmrest_temple_top_taxi : public CreatureScript
{
public:
    npc_wyrmrest_temple_top_taxi() : CreatureScript("npc_wyrmresttempeltop_taxi") { }
    bool OnGossipHello(Player* pPlayer, Creature* pCreature)
    {
        pPlayer->SetTaxiCheater(true);

        pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_BOTTOM, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 5);
        pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_ONEDOWN, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 6);
        pPlayer->SEND_GOSSIP_MENU(12714, pCreature->GetGUID());

        return true;
    }

    bool OnGossipSelect(Player* pPlayer, Creature* /*pCreature*/, uint32 /*uiSender*/, uint32 uiAction)
    {
        pPlayer->PlayerTalkClass->ClearMenus();
        if (uiAction == GOSSIP_ACTION_INFO_DEF + 5)
            pPlayer->GetSession()->SendDoFlight(6376, 879);

        if (uiAction == GOSSIP_ACTION_INFO_DEF + 6)
            pPlayer->GetSession()->SendDoFlight(6376, 880);
        return true;
    }
};

void AddSC_npc_wyrmresttempel_taxi()
{
    new npc_wyrmrest_temple_middle_taxi;
    new npc_wyrmrest_temple_bottom_taxi;
    new npc_wyrmrest_temple_top_taxi;
}
