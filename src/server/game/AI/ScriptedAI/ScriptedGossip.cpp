/*
* This file is part of the TrinityCore Project. See AUTHORS file for Copyright information
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

#include "ScriptedGossip.h"
#include "Creature.h"
#include "Player.h"

uint32 GetGossipSenderFor(Player* player, uint32 menuId)
{
    return player->PlayerTalkClass->GetGossipOptionSender(menuId);
}

uint32 GetGossipActionFor(Player* player, uint32 gossipListId)
{
    return player->PlayerTalkClass->GetGossipOptionAction(gossipListId);
}

void InitGossipMenuFor(Player* player, uint32 menuId)
{
    player->PlayerTalkClass->GetGossipMenu().SetMenuId(menuId);
}

void ClearGossipMenuFor(Player* player)
{
    player->PlayerTalkClass->ClearMenus();
}

// Using provided text, not from DB
void AddGossipItemFor(Player* player, GossipOptionNpc optionNpc, std::string text, uint32 sender, uint32 action)
{
    player->PlayerTalkClass->GetGossipMenu().AddMenuItem(0, -1, optionNpc, std::move(text), 0, GossipOptionFlags::None, {}, 0, 0, false, 0, "", {}, {}, sender, action);
}

// Using provided texts, not from DB
void AddGossipItemFor(Player* player, GossipOptionNpc optionNpc, std::string text, uint32 sender, uint32 action, std::string popupText, uint64 popupMoney, bool coded)
{
    player->PlayerTalkClass->GetGossipMenu().AddMenuItem(0, -1, optionNpc, std::move(text), 0, GossipOptionFlags::None, {}, 0, 0, coded, popupMoney, std::move(popupText), {}, {}, sender, action);
}

// Uses gossip item info from DB
void AddGossipItemFor(Player* player, uint32 gossipMenuID, uint32 gossipMenuItemID, uint32 sender, uint32 action)
{
    player->PlayerTalkClass->GetGossipMenu().AddMenuItem(gossipMenuID, gossipMenuItemID, sender, action);
}

void SendGossipMenuFor(Player* player, uint32 npcTextID, ObjectGuid const& guid)
{
    player->PlayerTalkClass->SendGossipMenu(npcTextID, guid);
}

void SendGossipMenuFor(Player* player, uint32 npcTextID, Creature const* creature)
{
    if (creature)
        SendGossipMenuFor(player, npcTextID, creature->GetGUID());
}

void CloseGossipMenuFor(Player* player)
{
    player->PlayerTalkClass->SendCloseGossip();
}
