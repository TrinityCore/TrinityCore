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

#ifndef SC_GOSSIP_H
#define SC_GOSSIP_H

#include "GossipDef.h"
#include "QuestDef.h"

// Gossip Item Text
#define GOSSIP_TEXT_BROWSE_GOODS        "I'd like to browse your goods."
#define GOSSIP_TEXT_TRAIN               "Train me!"

enum eTradeskill
{
    // Skill defines
    TRADESKILL_ALCHEMY                  = 1,
    TRADESKILL_BLACKSMITHING            = 2,
    TRADESKILL_COOKING                  = 3,
    TRADESKILL_ENCHANTING               = 4,
    TRADESKILL_ENGINEERING              = 5,
    TRADESKILL_FIRSTAID                 = 6,
    TRADESKILL_HERBALISM                = 7,
    TRADESKILL_LEATHERWORKING           = 8,
    TRADESKILL_POISONS                  = 9,
    TRADESKILL_TAILORING                = 10,
    TRADESKILL_MINING                   = 11,
    TRADESKILL_FISHING                  = 12,
    TRADESKILL_SKINNING                 = 13,
    TRADESKILL_JEWLCRAFTING             = 14,
    TRADESKILL_INSCRIPTION              = 15,
    TRADESKILL_ARCHAEOLOGY              = 16,

    TRADESKILL_LEVEL_NONE               = 0,
    TRADESKILL_LEVEL_APPRENTICE         = 1,
    TRADESKILL_LEVEL_JOURNEYMAN         = 2,
    TRADESKILL_LEVEL_EXPERT             = 3,
    TRADESKILL_LEVEL_ARTISAN            = 4,
    TRADESKILL_LEVEL_MASTER             = 5,
    TRADESKILL_LEVEL_GRAND_MASTER       = 6,
    TRADESKILL_LEVEL_ILLUSTRIOUS        = 7,

    // Gossip defines
    GOSSIP_ACTION_TRADE                 = 1,
    GOSSIP_ACTION_TRAIN                 = 2,
    GOSSIP_ACTION_TAXI                  = 3,
    GOSSIP_ACTION_GUILD                 = 4,
    GOSSIP_ACTION_BATTLE                = 5,
    GOSSIP_ACTION_BANK                  = 6,
    GOSSIP_ACTION_INN                   = 7,
    GOSSIP_ACTION_HEAL                  = 8,
    GOSSIP_ACTION_TABARD                = 9,
    GOSSIP_ACTION_AUCTION               = 10,
    GOSSIP_ACTION_INN_INFO              = 11,
    GOSSIP_ACTION_UNLEARN               = 12,
    GOSSIP_ACTION_INFO_DEF              = 1000,

    GOSSIP_SENDER_MAIN                  = 1,
    GOSSIP_SENDER_INN_INFO              = 2,
    GOSSIP_SENDER_INFO                  = 3,
    GOSSIP_SENDER_SEC_PROFTRAIN         = 4,
    GOSSIP_SENDER_SEC_CLASSTRAIN        = 5,
    GOSSIP_SENDER_SEC_BATTLEINFO        = 6,
    GOSSIP_SENDER_SEC_BANK              = 7,
    GOSSIP_SENDER_SEC_INN               = 8,
    GOSSIP_SENDER_SEC_MAILBOX           = 9,
    GOSSIP_SENDER_SEC_STABLEMASTER      = 10
};

class Creature;
uint32 TC_GAME_API GetGossipActionFor(Player* player, uint32 gossipListId);
void TC_GAME_API InitGossipMenuFor(Player* player, uint32 menuId);
void TC_GAME_API ClearGossipMenuFor(Player* player);
// Using provided text, not from DB
void TC_GAME_API AddGossipItemFor(Player* player, GossipOptionIcon icon, std::string const& text, uint32 sender, uint32 action);
// Using provided texts, not from DB
void TC_GAME_API AddGossipItemFor(Player* player, GossipOptionIcon icon, std::string const& text, uint32 sender, uint32 action, std::string const& popupText, uint32 popupMoney, bool coded);
// Uses gossip item info from DB
void TC_GAME_API AddGossipItemFor(Player* player, uint32 gossipMenuID, uint32 gossipMenuItemID, uint32 sender, uint32 action);
void TC_GAME_API SendGossipMenuFor(Player* player, uint32 npcTextID, ObjectGuid const& guid);
void TC_GAME_API SendGossipMenuFor(Player* player, uint32 npcTextID, Creature const* creature);
void TC_GAME_API CloseGossipMenuFor(Player* player);

#endif
