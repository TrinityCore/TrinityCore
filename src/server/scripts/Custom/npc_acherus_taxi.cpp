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

#define GOSSIP_FLIGHT "I need a ride"

class npc_acherus_taxi : public CreatureScript
{
public:
    npc_acherus_taxi() : CreatureScript("npc_acherus_taxi") { }

    bool OnGossipHello(Player *pPlayer, Creature *pCreature)
    {
        pPlayer->SetTaxiCheater(true);
        pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_FLIGHT, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1);
        pPlayer->SEND_GOSSIP_MENU(9978, pCreature->GetGUID());
        return true;
    }

    bool OnGossipSelect(Player *pPlayer, Creature * /*pCreature*/, uint32 /*uiSender*/, uint32 uiAction)
    {
        if (uiAction == GOSSIP_ACTION_INFO_DEF + 1)
        {
            if (pPlayer->GetPositionZ() >= 316)
                pPlayer->GetSession()->SendDoFlight(24446, 1053);
            else
                pPlayer->GetSession()->SendDoFlight(24446, 1054);
        }
        return true;
    }
};

void AddSC_npc_acherus_taxi()
{
    new npc_acherus_taxi;
}
