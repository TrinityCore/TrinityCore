/*
 * This file is part of the Stefal WoW Project.
 * It is designed to work exclusively with the TrinityCore framework.
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
 * This code is provided for personal and educational use within the
 * Stefal WoW Project. It is not intended for commercial distribution,
 * resale, or any form of monetization.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#include "Followship_bots_defines.h"

// Player Notifications
constexpr auto FSB_PLAYER_NOTIFICATION_PAYMENT_SUCCESS = "Payment successful!";
constexpr auto FSB_PLAYER_NOTIFICATION_PAYMENT_FAIL = "Not enough money!";

// Menu items - these have sub items
constexpr auto FSB_GOSSIP_MENU_HIRE = "I'd like to hire you!";
constexpr auto FSB_GOSSIP_MENU_INSTRUCTIONS = "Instructions";

constexpr auto FSB_GOSSIP_MENU_FOLLOW_DIST = "Follow Distance";
constexpr auto FSB_GOSSIP_MENU_FOLLOW_ANGLE = "Follow Angle";
constexpr auto FSB_GOSSIP_MENU_ROLES = "Roles";
constexpr auto FSB_GOSSIP_MENU_LANGUAGE = "Language";

constexpr auto FSB_GOSSIP_MENU_PORTAL = "I need a portal";

constexpr auto FSB_GOSSIP_ITEM_LANG_RACIAL = "Speak in your racial tongue";
constexpr auto FSB_GOSSIP_ITEM_LANG_TEAM = "Speak in the common team language";

// Non menu items
constexpr auto FSB_GOSSIP_ITEM_PHIRE = "I need you for a longer time...";
constexpr auto FSB_GOSSIP_ITEM_FIRE = "Dismiss!";
constexpr auto FSB_GOSSIP_ITEM_BACKMAIN = "Let's talk about something else";

constexpr auto FSB_GOSSIP_ITEM_STAY_HERE = "Stay here!";
constexpr auto FSB_GOSSIP_ITEM_FOLLOW = "Follow me!";

constexpr auto FSB_GOSSIP_ITEM_FOLLOW_DIST1 = "Stay close: 3 feet...";
constexpr auto FSB_GOSSIP_ITEM_FOLLOW_DIST2 = "Normal distance: 5 feet...";
constexpr auto FSB_GOSSIP_ITEM_FOLLOW_DIST3 = "Keep your distance: 8 feet...";

constexpr auto FSB_GOSSIP_ITEM_FOLLOW_ANGLE_FRONT = "Take the lead! Move in front!";
constexpr auto FSB_GOSSIP_ITEM_FOLLOW_ANGLE_BACK = "Get behind me!";
constexpr auto FSB_GOSSIP_ITEM_FOLLOW_ANGLE_LEFT = "Move on my left!";
constexpr auto FSB_GOSSIP_ITEM_FOLLOW_ANGLE_RIGHT = "Move on my right!";

constexpr auto FSB_GOSSIP_ITEM_ROLE_ASSIST = "Healer Role: mostly heals and light combat assist";
constexpr auto FSB_GOSSIP_ITEM_ROLE_DAMAGE = "Damage Dealer: only damage on all targets";
constexpr auto FSB_GOSSIP_ITEM_ROLE_BALANCED = "Assist Role: a mix of heals and damage spells";
constexpr auto FSB_GOSSIP_ITEM_ROLE_TANK = "Tank Role: take a beating";
constexpr auto FSB_GOSSIP_ITEM_ROLE_MELEE = "Melee DPS Role: use close range weapons and attacks";
constexpr auto FSB_GOSSIP_ITEM_ROLE_ROGUE_1 = "Assassin DPS Role: use close range weapons and attacks";
constexpr auto FSB_GOSSIP_ITEM_ROLE_ROGUE_2 = "Subtlety DPS Role: use close range weapons and attacks";
constexpr auto FSB_GOSSIP_ITEM_ROLE_ROGUE_3 = "Combat DPS Role: use close range weapons and attacks";
constexpr auto FSB_GOSSIP_ITEM_ROLE_HEALER = "Healer Role: mostly heals and light combat assist";
constexpr auto FSB_GOSSIP_ITEM_ROLE_ARCANE = "Arcane Damage Role: mostly arcane spells";
constexpr auto FSB_GOSSIP_ITEM_ROLE_FROST = "Frost Damage Dealer: mostly frost and ice spells";
constexpr auto FSB_GOSSIP_ITEM_ROLE_FIRE = "Fire Damage Role: mostly fire spells";
constexpr auto FSB_GOSSIP_ITEM_ROLE_AFFLICTION = "Affliction: A master of shadow magic";
constexpr auto FSB_GOSSIP_ITEM_ROLE_DEMONOLOGY = "Demonology: A master of demons";
constexpr auto FSB_GOSSIP_ITEM_ROLE_DESTRUCTION = "Destruction: A master of chaos";
constexpr auto FSB_GOSSIP_ITEM_ROLE_BEAST = "Hybrid Damage Role: Relies on a pet as well as ranged abilities";

constexpr auto FSB_GOSSIP_ITEM_PORTAL_STORMWIND = "Stormwind";
constexpr auto FSB_GOSSIP_ITEM_PORTAL_DARNASSUS = "Darnassus";
constexpr auto FSB_GOSSIP_ITEM_PORTAL_IRONFORGE = "Ironforge";
constexpr auto FSB_GOSSIP_ITEM_PORTAL_EXODAR = "Exodar";

constexpr auto FSB_GOSSIP_ITEM_INFO = "Tell me more about yourself";

// NPC SAY
constexpr auto FSB_SAY_DUPLICATE_FOLLOWER = "I'm sorry but I cannot come with you... one of us is already with you!";

static constexpr uint32 FSB_GOSSIP_DEFAULT_MENU = 12504;

enum FSB_GossipRoleItems
{
    FSB_GOSSIP_ROLE_1,
    FSB_GOSSIP_ROLE_2,
    FSB_GOSSIP_ROLE_3,
    FSB_GOSSIP_ROLE_4
};

namespace FSBGossip
{
    bool HandleDefaultGossipHello(Creature* bot, Player* player, bool hired, ObjectGuid& outPlayerGuid);

    bool HandleGossipMenuFollowAngle(Creature* bot, Player* player);
    bool HandleGossipMenuFollowDistance(Creature* bot, Player* player);
    bool HandleGossipMenuHire(Creature* bot, Player* player);
    bool HandleGossipMenuInstructions(Creature* bot, Player* player);
    bool HandleGossipMenuPortals(Creature* bot, Player* player);
    bool HandleGossipMenuRoles(Creature* bot, Player* player);
    bool HandleGossipMenuLanguage(Creature* bot, Player* player);

    void HandleGossipItemInfo(Creature* bot, Player* player);
    void HandleGossipItemRole(Creature* bot, FSB_Class botClass, uint8 roleOption, bool& botHasDemon);
    bool HandleGossipItemHirePermanent(Creature* bot, Player* player);
    bool HandleGossipItemHire(Creature* bot, Player* player, uint32 durationHours);

    bool HandleGossipSelect(Creature* bot, ObjectGuid playerGuid, uint32 menuId, uint32 gossipListId);
}
