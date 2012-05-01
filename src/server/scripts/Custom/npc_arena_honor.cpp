/*
* Copyright (C) 2010-2011 TrinityCore <http://www.trinitycore.org/>
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

/* Script
Name: npc_arena_honor
Complete:
Author patch based, supported by: Easy ????
Modified patch, supported by; Wasy
Category: Custom
End */

#include "ScriptPCH.h"

#define GOSSIP_ITEM_HONOR_TO_ARENA  "Обменять 1000 очков чести на 3 очка арены."
#define GOSSIP_ITEM_HONOR_TO_ARENA1 "Обменять 30000 очков чести на 30 очков арены."

#define GOSSIP_ITEM_ARENA_TO_HONOR  "Обменять 3 очка арены на 100 очков чести."
#define GOSSIP_ITEM_ARENA_TO_HONOR1 "Обменять 30 очков арены на 3000 очков чести."


class npc_arena_honor : public CreatureScript
{
public:
    npc_arena_honor() : CreatureScript("npc_arena_honor") { }

    bool OnGossipHello(Player* player, Creature* creature)
    {
        player->ADD_GOSSIP_ITEM(0, GOSSIP_ITEM_HONOR_TO_ARENA,  GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1);
        player->ADD_GOSSIP_ITEM(0, GOSSIP_ITEM_HONOR_TO_ARENA1, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 2);
        player->ADD_GOSSIP_ITEM(0, GOSSIP_ITEM_ARENA_TO_HONOR,  GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 3);
        player->ADD_GOSSIP_ITEM(0, GOSSIP_ITEM_ARENA_TO_HONOR1, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 4);
        player->SEND_GOSSIP_MENU(3961, creature->GetGUID());
        return true;
    }

    bool OnGossipSelect(Player* player, Creature* creature, uint32 sender, uint32 action)
    {
        if (action == GOSSIP_ACTION_INFO_DEF + 1)
        {
            if (player->GetHonorPoints() >= 1000)
            {
                player->ModifyHonorPoints(-1000);
                player->ModifyArenaPoints(+3);
            }
            else
            {
                creature->MonsterSay("Недостаточно очков чести!", LANG_UNIVERSAL, 0);
            }
        }
        if (action == GOSSIP_ACTION_INFO_DEF + 2)
        {
            if (player->GetHonorPoints() >= 30000)
            {
                player->ModifyHonorPoints(-30000);
                player->ModifyArenaPoints(+30);
            }
            else
            {
                creature->MonsterSay("Недостаточно очков чести!", LANG_UNIVERSAL, 0);
            }
        }
        if (action == GOSSIP_ACTION_INFO_DEF + 3)
        {
            if (player->GetArenaPoints() >= 3)
            {
                player->ModifyArenaPoints(-3);
                player->ModifyHonorPoints(+100);
            }
            else
            {
                creature->MonsterSay("Недостаточно очков арены!", LANG_UNIVERSAL, 0);
            }
        }
        if (action == GOSSIP_ACTION_INFO_DEF + 4)
        {
            if (player->GetArenaPoints() >= 30)
            {
                player->ModifyArenaPoints(-30);
                player->ModifyHonorPoints(+3000);
            }
            else
            {
                creature->MonsterSay("Недостаточно очков арены!", LANG_UNIVERSAL, 0);
            }
        }
        player->CLOSE_GOSSIP_MENU();
        return true;
    }

};

void AddSC_npc_arena_honor()
{
    new npc_arena_honor();
}
