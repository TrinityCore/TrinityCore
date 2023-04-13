///*
// * Copyright (C) 2008-2012 TrinityCore <http://www.trinitycore.org/>
// * Copyright (C) 2006-2009 ScriptDev2 <https://scriptdev2.svn.sourceforge.net/>
// *
// * This program is free software; you can redistribute it and/or modify it
// * under the terms of the GNU General Public License as published by the
// * Free Software Foundation; either version 2 of the License, or (at your
// * option) any later version.
// *
// * This program is distributed in the hope that it will be useful, but WITHOUT
// * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
// * FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
// * more details.
// *
// * You should have received a copy of the GNU General Public License along
// * with this program. If not, see <http://www.gnu.org/licenses/>.
// */
//
//#include "PrecompiledHeaders/ScriptPCH.h"
//
//#define MSG_ERR_HONOR "Not enough honor points!"
//#define MSG_ERR_ARENA "Not enough arena points!"
//#define CONST_AP  
//#define CONST_HONOR  
//#define CONST_HONOR  
//
//
//class custum_trainer : public CreatureScript
//{
//public:
//    custum_trainer() : CreatureScript("custum_trainer") { }
//
//    bool OnGossipHello(Player* player, Creature* creature) override
//    {
//        player->ADD_GOSSIP_ITEM(GOSSIP_ICON_TRAINER, "Learn additional spells", GOSSIP_SENDER_MAIN, 1);
//        player->ADD_GOSSIP_ITEM(GOSSIP_ICON_TRAINER, "Unlearn additional spells", GOSSIP_SENDER_MAIN, 4);
//        player->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_1, "Teleport menu", GOSSIP_SENDER_MAIN, 2);
//        player->ADD_GOSSIP_ITEM(GOSSIP_ICON_MONEY_BAG, "Useful items for honor points", GOSSIP_SENDER_MAIN, 3);
//        player->ADD_GOSSIP_ITEM(GOSSIP_ICON_VENDOR, "Donation menu (Spells for Ethereal Credits)", GOSSIP_SENDER_MAIN, 5);
//        player->SEND_GOSSIP_MENU(51000, creature->GetGUID());
//        return true;
//    }
//
//    bool OnGossipSelect(Player* player, Creature* creature, uint32 /*sender*/, uint32 action) override
//    {
//        uint64 PriceInGold = 3000000; // 300 gold
//        player->PlayerTalkClass->ClearMenus();
//        switch (action)
//        {
//        case 999999:
//            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_TRAINER, "Learn Additional Spells", GOSSIP_SENDER_MAIN, 1);
//            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_TRAINER, "Forget Additional Spells", GOSSIP_SENDER_MAIN, 4);
//            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_1, "Teleport Menu", GOSSIP_SENDER_MAIN, 2);
//            //player->ADD_GOSSIP_ITEM(GOSSIP_ICON_MONEY_BAG, "Useful Items for Honor Points", GOSSIP_SENDER_MAIN, 3); 
//            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_VENDOR, "Donate Menu (Spells for Ethereal Coins)", GOSSIP_SENDER_MAIN, 5);
//            player->SEND_GOSSIP_MENU(51000, creature->GetGUID());
//            break;
//        case 1: // First menu (SPELLS) and it's cases
//            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_TRAINER, "Food", GOSSIP_SENDER_MAIN, 45548);
//            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_TRAINER, "Drinking", GOSSIP_SENDER_MAIN, 43183);
//            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_TRAINER, "Water Breathing", GOSSIP_SENDER_MAIN, 1446);
//            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_TRAINER, "Parachute", GOSSIP_SENDER_MAIN, 45472);
//            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_TRAINER, "Lockbreaker", GOSSIP_SENDER_MAIN, 1804);
//            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_TRAINER, "Rapid Bird's Face", GOSSIP_SENDER_MAIN, 40123);
//            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_TRAINER, "Call of the Meeting Stone", GOSSIP_SENDER_MAIN, 23598);
//            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_TRAINER, "Defibrillation", GOSSIP_SENDER_MAIN, 54732);
//            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_TRAINER, "Portal to Dalaran - 300 gold", GOSSIP_SENDER_MAIN, 73324);
//            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_TRAINER, "Portal to Shuttle -300 gold", GOSSIP_SENDER_MAIN, 57676);
//            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_TRAINER, "Portal to the Black Temple -300 gold", GOSSIP_SENDER_MAIN, 41234);
//            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_1, "Back", GOSSIP_SENDER_MAIN, 11);
//            player->SEND_GOSSIP_MENU(51000, creature->GetGUID());
//            break;
//        case 54732: //Defibrillate
//            player->learnSpell(54732, false);
//            OnGossipSelect(player, creature, GOSSIP_SENDER_MAIN, 1);
//            break;
//        case 45548: //food
//            player->learnSpell(64355, false);
//            OnGossipSelect(player, creature, GOSSIP_SENDER_MAIN, 1);
//            break;
//        case 43183: //drink
//            player->learnSpell(43183, false);
//            OnGossipSelect(player, creature, GOSSIP_SENDER_MAIN, 1);
//            break;
//        case 1804: //lockpick
//            player->learnSpell(1804, false);
//            OnGossipSelect(player, creature, GOSSIP_SENDER_MAIN, 1);
//            break;
//        case 40123: //Fform
//            player->CastSpell(player, 40123, true);
//            player->CLOSE_GOSSIP_MENU();
//            break;
//        case 1446:
//            player->learnSpell(24347, false);
//            player->removeSpell(1446);
//            OnGossipSelect(player, creature, GOSSIP_SENDER_MAIN, 1);
//            break;
//        case 45472:
//            player->learnSpell(45472, false);
//            OnGossipSelect(player, creature, GOSSIP_SENDER_MAIN, 1);
//            break;
//        case 23598:
//            player->learnSpell(23598, false);
//            OnGossipSelect(player, creature, GOSSIP_SENDER_MAIN, 1);
//            break;
//        case 41234:
//            if (player->HasEnoughMoney(PriceInGold))
//            {
//                player->ModifyMoney(-1 * PriceInGold);
//                player->learnSpell(41234, false);
//            }
//            else
//                player->SendBuyError(BUY_ERR_NOT_ENOUGHT_MONEY);
//            player->CLOSE_GOSSIP_MENU();
//            break;
//        case 73324:
//            if (player->HasEnoughMoney(PriceInGold))
//            {
//                player->ModifyMoney(-1 * PriceInGold);
//                player->learnSpell(73324, false);
//            }
//            else
//                player->SendBuyError(BUY_ERR_NOT_ENOUGHT_MONEY);
//            player->CLOSE_GOSSIP_MENU();
//            break;
//        case 57676:
//            if (player->HasEnoughMoney(PriceInGold))
//            {
//                player->ModifyMoney(-1 * PriceInGold);
//                player->learnSpell(57676, false);
//            }
//            else
//                player->SendBuyError(BUY_ERR_NOT_ENOUGHT_MONEY);
//            player->CLOSE_GOSSIP_MENU();
//            break;
//        case 11:
//            OnGossipHello(player, creature);
//            break;
//        case 2: //Second menu (TELEPORT_MAIN) and it's cases
//            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_1, "Cities", GOSSIP_SENDER_MAIN, 21);
//            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_1, "Danji", GOSSIP_SENDER_MAIN, 22);
//            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_1, "Raid Dungeons", GOSSIP_SENDER_MAIN, 23);
//            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_1, "PvP Zones", GOSSIP_SENDER_MAIN, 24);
//            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_1, "Just interesting places", GOSSIP_SENDER_MAIN, 25);
//            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_1, "Back", GOSSIP_SENDER_MAIN, 999999);
//            player->SEND_GOSSIP_MENU(51000, creature->GetGUID());
//            break;
//        case 21: //Second menu (TELEPORT_CITIES) and it's cases
//            if (player->GetTeam() == ALLIANCE)
//            {
//                player->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_1, "Teleport to Stormgrad", GOSSIP_SENDER_MAIN, 211);
//                player->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_1, "Teleport to Stalhorn", GOSSIP_SENDER_MAIN, 212);
//                player->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_1, "Teleport to Darnas", GOSSIP_SENDER_MAIN, 213);
//                player->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_1, "Teleport to Exodar", GOSSIP_SENDER_MAIN, 214);
//                player->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_1, "Teleport to Examodar", GOSSIP_SENDER_MAIN, 2113);
//            }
//            else
//            {
//                player->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_1, "Teleport to Orgrimmare", GOSSIP_SENDER_MAIN, 215);
//                player->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_1, "Teleport to Thunderbird", GOSSIP_SENDER_MAIN, 216);
//                player->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_1, "Teleport to Suburban", GOSSIP_SENDER_MAIN, 217);
//                player->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_1, "Teleport to the Moonlight", GOSSIP_SENDER_MAIN, 218);
//                player->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_1, "Teleport to the Immortal Island", GOSSIP_SENDER_MAIN, 2114);
//            }
//            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_1, "Teleport to Cabestan", GOSSIP_SENDER_MAIN, 219);
//            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_1, "Teleport to Circlesworth", GOSSIP_SENDER_MAIN, 2110);
//            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_1, "Teleport to Pribambassk", GOSSIP_SENDER_MAIN, 2111);
//            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_1, "Teleport to Pirate Cove", GOSSIP_SENDER_MAIN, 2112);
//            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_1, "Back", GOSSIP_SENDER_MAIN, 2);
//            player->SEND_GOSSIP_MENU(51000, creature->GetGUID());
//            break;
//        case 211: //Stormwind
//            player->CLOSE_GOSSIP_MENU();
//            player->TeleportTo(0, -8832.53f, 622.9f, 93.97f, 0.70f);
//            break;
//        case 212: //Ironforge
//            player->CLOSE_GOSSIP_MENU();
//            player->TeleportTo(0, -4924.07f, -951.95f, 501.55f, 5.40f);
//            break;
//        case 213: //Darnassus
//            player->CLOSE_GOSSIP_MENU();
//            player->TeleportTo(1, 9947.52f, 2482.73f, 1316.21f, 0.0f);
//            break;
//        case 214: //Exodar
//            player->CLOSE_GOSSIP_MENU();
//            player->TeleportTo(530, -3965.6f, -11653.5f, -138.8f, 0.0f);
//            break;
//        case 215: //Orgrimmar
//            player->CLOSE_GOSSIP_MENU();
//            player->TeleportTo(1, 1586.25f, -4386.31f, 18.31f, 0.56f);
//            break;
//        case 216: //Thunderbluff
//            player->CLOSE_GOSSIP_MENU();
//            player->TeleportTo(1, -1280.19f, 127.21f, 131.35f, 5.16f);
//            break;
//        case 217: //Undercity
//            player->CLOSE_GOSSIP_MENU();
//            player->TeleportTo(0, 1560.05f, 240.213f, -43.1025f, 0.0f);
//            break;
//        case 218: //Silvermoon
//            player->CLOSE_GOSSIP_MENU();
//            player->TeleportTo(530, 9487.690f, -7279.2f, 14.2866f, 0.0f);
//            break;
//        case 219: //Ratchet
//            player->CLOSE_GOSSIP_MENU();
//            player->TeleportTo(1, -956.664f, -3754.709f, 5.3323f, 0.99f);
//            break;
//        case 2110: //Everlook
//            player->CLOSE_GOSSIP_MENU();
//            player->TeleportTo(1, 6725.504f, -4621.73f, 720.843f, 4.78f);
//            break;
//        case 2111: //Gadgetzan
//            player->CLOSE_GOSSIP_MENU();
//            player->TeleportTo(1, -7177.149f, -3785.34f, 8.369f, 6.1f);
//            break;
//        case 2112: //Booty bay
//            player->CLOSE_GOSSIP_MENU();
//            player->TeleportTo(0, -14297.2f, 530.992f, 8.779f, 3.98f);
//            break;
//        case 2113: //Timeless Isle A
//            player->CLOSE_GOSSIP_MENU();
//            player->TeleportTo(870, -901.53f, -4642.63f, 5.33f, 2.86f);
//            break;
//        case 2114: //Timeless Isle H
//            player->CLOSE_GOSSIP_MENU();
//            player->TeleportTo(870, -415.64f, -4602.04f, 3.67f, 5.93f);
//            break;
//
//
//        case 22: //Second menu (TELEPORT_DUNGEON_INSTANCES) and it's cases
//            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_1, "Classic dungeon instances", GOSSIP_SENDER_MAIN, 221);
//            if (player->getLevel() >= 58)
//            {
//                player->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_1, "Burning Crusade dungeon instances", GOSSIP_SENDER_MAIN, 222);
//            }
//            if (player->getLevel() >= 68)
//            {
//                player->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_1, "Lich King dungeon instances", GOSSIP_SENDER_MAIN, 223);
//            }
//            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_1, "Back", GOSSIP_SENDER_MAIN, 2);
//            player->SEND_GOSSIP_MENU(51000, creature->GetGUID());
//            break;
//        case 221: //Second menu (TELEPORT_DUNGEON_INSTANCES_CLASSIC)
//            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_1, "Deadmines", GOSSIP_SENDER_MAIN, 2211);
//            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_1, "Wailing caverns", GOSSIP_SENDER_MAIN, 2212);
//            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_1, "Blackfathom Deeps", GOSSIP_SENDER_MAIN, 2213);
//            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_1, "Gnomeregan", GOSSIP_SENDER_MAIN, 2214);
//            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_1, "Razorfen Downs", GOSSIP_SENDER_MAIN, 2215);
//            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_1, "Uldaman", GOSSIP_SENDER_MAIN, 2216);
//            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_1, "Maraudon", GOSSIP_SENDER_MAIN, 2217);
//            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_1, "Blackrock Depths", GOSSIP_SENDER_MAIN, 2218);
//            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_1, "Dire Maul", GOSSIP_SENDER_MAIN, 2219);
//            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_1, "Stratholme", GOSSIP_SENDER_MAIN, 22110);
//            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_1, "Ragefire Chasm", GOSSIP_SENDER_MAIN, 22111);
//            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_1, "Shadowfang Keep", GOSSIP_SENDER_MAIN, 22112);
//            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_1, "Stormwind Stockade", GOSSIP_SENDER_MAIN, 22113);
//            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_1, "Razorfen Kraul", GOSSIP_SENDER_MAIN, 22114);
//            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_1, "Scarlet Monastery", GOSSIP_SENDER_MAIN, 22115);
//            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_1, "Zul'Farrak", GOSSIP_SENDER_MAIN, 22116);
//            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_1, "Sunken Temple", GOSSIP_SENDER_MAIN, 22117);
//            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_1, "Lower Blackrock Spire", GOSSIP_SENDER_MAIN, 22118);
//            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_1, "Scholomance", GOSSIP_SENDER_MAIN, 22119);
//            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_1, "Back", GOSSIP_SENDER_MAIN, 22);
//            player->SEND_GOSSIP_MENU(51000, creature->GetGUID());
//            break;
//        case 2211: //Deadmines
//            player->CLOSE_GOSSIP_MENU();
//            player->TeleportTo(0, -11212.04f, 1658.58f, 25.67f, 1.45f);
//            break;
//        case 2212: //Wailing caverns
//            player->CLOSE_GOSSIP_MENU();
//            player->TeleportTo(1, -722.53f, -2226.30f, 16.94f, 2.71f);
//            break;
//        case 2213: //Blackfathom Deeps
//            player->CLOSE_GOSSIP_MENU();
//            player->TeleportTo(1, 4254.58f, 664.74f, -29.04f, 1.97f);
//            break;
//        case 2214: //Gnomeregan
//            player->CLOSE_GOSSIP_MENU();
//            player->TeleportTo(0, -5163.43f, 660.40f, 348.28f, 4.65f);
//            break;
//        case 2215: //Razorfen Downs
//            player->CLOSE_GOSSIP_MENU();
//            player->TeleportTo(1, -4645.08f, -2470.85f, 85.53f, 4.39f);
//            break;
//        case 2216: //Uldaman
//            player->CLOSE_GOSSIP_MENU();
//            player->TeleportTo(0, -6119.70f, -2957.30f, 204.11f, 0.03f);
//            break;
//        case 2217: //Maraudon
//            player->CLOSE_GOSSIP_MENU();
//            player->TeleportTo(1, -1433.33f, 2955.34f, 96.21f, 4.82f);
//            break;
//        case 2218: //Blackrock Depths
//            player->CLOSE_GOSSIP_MENU();
//            player->TeleportTo(0, -7301.03f, -913.19f, 165.37f, 0.08f);
//            break;
//        case 2219: //Dire Maul
//            player->CLOSE_GOSSIP_MENU();
//            player->TeleportTo(1, -3982.47f, 1127.79f, 161.02f, 0.05f);
//            break;
//        case 22110: //Stratholme
//            player->CLOSE_GOSSIP_MENU();
//            player->TeleportTo(0, 3263.54f, -3379.46f, 143.59f, 0.00f);
//            break;
//        case 22111: //Ragefire Chasm
//            if (player->GetTeam() == ALLIANCE)
//            {
//                player->CLOSE_GOSSIP_MENU();
//                creature->MonsterSay("You are from the Alliance and we won't let you Teleport to Orgrimmar that easy, bro.", LANG_UNIVERSAL, ObjectGuid::Empty);
//            }
//            else
//            {
//                player->CLOSE_GOSSIP_MENU();
//                player->TeleportTo(1, 1800.53f, -4394.68f, -17.93f, 5.49f);
//            }
//            break;
//        case 22112: //Shadowfang Keep
//            player->CLOSE_GOSSIP_MENU();
//            player->TeleportTo(0, -254.47f, 1524.68f, 76.89f, 1.56f);
//            break;
//        case 22113: //Stormwind Stockade
//            if (player->GetTeam() == ALLIANCE)
//            {
//                player->CLOSE_GOSSIP_MENU();
//                player->TeleportTo(0, -8769.76f, 813.08f, 97.63f, 2.26f);
//            }
//            else
//            {
//                player->CLOSE_GOSSIP_MENU();
//                creature->MonsterSay("You are from the Horde and we won't let you Teleport to Stormwind that easy, bro.", LANG_UNIVERSAL, ObjectGuid::Empty);
//            }
//            break;
//        case 22114: //Razorfen Kraul
//            player->CLOSE_GOSSIP_MENU();
//            player->TeleportTo(1, -4484.04f, -1739.40f, 86.47f, 1.23f);
//            break;
//        case 22115: //Scarlet Monastery
//            player->CLOSE_GOSSIP_MENU();
//            player->TeleportTo(0, 2843.89f, -693.74f, 139.32f, 5.11f);
//            break;
//        case 22116: //Zul'Farrak
//            player->CLOSE_GOSSIP_MENU();
//            player->TeleportTo(1, -6839.39f, -2911.03f, 8.87f, 0.41f);
//            break;
//        case 22117: //Sunken Temple
//            player->CLOSE_GOSSIP_MENU();
//            player->TeleportTo(0, -10346.92f, -3851.90f, -43.41f, 6.09f);
//            break;
//        case 22118: //Lower Blackrock Spire
//            player->CLOSE_GOSSIP_MENU();
//            player->TeleportTo(0, -7535.43f, -1212.04f, 285.45f, 5.29f);
//            break;
//        case 22119: //Scholomance
//            player->CLOSE_GOSSIP_MENU();
//            player->TeleportTo(0, 1219.01f, -2604.66f, 85.61f, 0.50f);
//            break;
//        case 222: //Second menu (TELEPORT_DUNGEON_INSTANCES_BC)
//            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_1, "The Shattered Halls, Hellfire Ramparts, The Blood Furnace", GOSSIP_SENDER_MAIN, 2221);
//            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_1, "The Steamvault, Underbog, The Slave Pens", GOSSIP_SENDER_MAIN, 2222);
//            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_1, "Mana-Tombs, Sethekk Halls, Shadow Labyrinth, Auchenai Crypts", GOSSIP_SENDER_MAIN, 2223);
//            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_1, "The Mechanar", GOSSIP_SENDER_MAIN, 2224);
//            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_1, "The Botanica", GOSSIP_SENDER_MAIN, 2225);
//            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_1, "The Arcatraz", GOSSIP_SENDER_MAIN, 2226);
//            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_1, "Magister's Terrace", GOSSIP_SENDER_MAIN, 2227);
//            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_1, "Opening of the Dark Portal, The Escape From Durnholde", GOSSIP_SENDER_MAIN, 2228);
//            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_1, "Back", GOSSIP_SENDER_MAIN, 22);
//            player->SEND_GOSSIP_MENU(51000, creature->GetGUID());
//            break;
//        case 2221: //The Shattered Halls, Hellfire Ramparts, The Blood Furnace +
//            player->CLOSE_GOSSIP_MENU();
//            player->TeleportTo(530, -305.816223f, 3056.401611f, -2.473183f, 2.01f);
//            break;
//        case 2222: //The Steamvault, Underbog, The Slave Pens +
//            player->CLOSE_GOSSIP_MENU();
//            player->TeleportTo(530, 734.39f, 6866.09f, -69.72f, 0.00f);
//            break;
//        case 2223: //Mana-Tombs, Sethekk Halls, Shadow Labyrinth, Auchenai Crypts +
//            player->CLOSE_GOSSIP_MENU();
//            player->TeleportTo(530, -3322.89f, 4941.024f, -101.21f, 3.72f);
//            break;
//        case 2224: //The Mechanar +
//            player->CLOSE_GOSSIP_MENU();
//            player->TeleportTo(530, 2873.38f, 1554.49f, 252.159f, 3.82f);
//            break;
//        case 2225: //The Botanica +
//            player->CLOSE_GOSSIP_MENU();
//            player->TeleportTo(530, 3403.67f, 1491.30f, 182.543f, 5.59f);
//            break;
//        case 2226: //The Arcatraz +
//            player->CLOSE_GOSSIP_MENU();
//            player->TeleportTo(530, 3307.53f, 1343.1f, 505.56f, 5.08f);
//            break;
//        case 2227: //Magister's Terrace +
//            player->CLOSE_GOSSIP_MENU();
//            player->TeleportTo(530, 12888.501f, -7317.7f, 65.508f, 4.82f);
//            break;
//        case 2228: //Opening of the Dark Portal, The Escape From Durnholde +
//            player->CLOSE_GOSSIP_MENU();
//            player->TeleportTo(1, -8484.37f, -4491.85f, -212.96f, 1.61f);
//            break;
//        case 223: //Second menu (TELEPORT_DUNGEON_INSTANCES_LK)
//            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_1, "Utgarde Keep", GOSSIP_SENDER_MAIN, 2231);
//            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_1, "Drak'Tharon Keep", GOSSIP_SENDER_MAIN, 2232);
//            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_1, "Ahn'kahet: The Old Kingdom", GOSSIP_SENDER_MAIN, 2233);
//            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_1, "The Violet Hold", GOSSIP_SENDER_MAIN, 2234);
//            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_1, "Halls of Stone", GOSSIP_SENDER_MAIN, 2235);
//            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_1, "The Oculus, The Nexus", GOSSIP_SENDER_MAIN, 2236);
//            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_1, "Azjol-Nerub", GOSSIP_SENDER_MAIN, 2237);
//            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_1, "The Culling of Stratholme", GOSSIP_SENDER_MAIN, 2238);
//            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_1, "Gundrak", GOSSIP_SENDER_MAIN, 2239);
//            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_1, "Halls of Lightning", GOSSIP_SENDER_MAIN, 22310);
//            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_1, "Utgarde Pinnacle", GOSSIP_SENDER_MAIN, 22311);
//            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_1, "Trial of the Champion", GOSSIP_SENDER_MAIN, 22312);
//            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_1, "Forge of Souls, Pit of Saron, Halls of Reflection", GOSSIP_SENDER_MAIN, 22313);
//            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_1, "Back", GOSSIP_SENDER_MAIN, 22);
//            player->SEND_GOSSIP_MENU(51000, creature->GetGUID());
//            break;
//        case 2231: //Utgarde Keep +
//            player->CLOSE_GOSSIP_MENU();
//            player->TeleportTo(571, 1219.720f, -4865.28f, 41.25f, 0.31f);
//            break;
//        case 2232: //Drak'Tharon Keep +
//            player->CLOSE_GOSSIP_MENU();
//            player->TeleportTo(571, 4450.860f, -2045.25f, 162.83f, 0.00f);
//            break;
//        case 2233: //Ahn'kahet: The Old Kingdom +
//            player->CLOSE_GOSSIP_MENU();
//            player->TeleportTo(571, 3646.760f, 2045.17f, 1.79f, 4.37f);
//            break;
//        case 2234: //The Violet Hold +
//            player->CLOSE_GOSSIP_MENU();
//            player->TeleportTo(571, 5679.820f, 486.80f, 652.40f, 4.08f);
//            break;
//        case 2235: //Halls of Stone +
//            player->CLOSE_GOSSIP_MENU();
//            player->TeleportTo(571, 8922.68f, -990.62f, 1039.387f, 1.60f);
//            break;
//        case 2236: //The Oculus, The Nexus +
//            player->CLOSE_GOSSIP_MENU();
//            player->TeleportTo(571, 3808.83f, 6967.47f, 100.1f, 0.468f);
//            break;
//        case 2237: //Azjol-Nerub +
//            player->CLOSE_GOSSIP_MENU();
//            player->TeleportTo(571, 3675.430f, 2169.00f, 35.90f, 2.29f);
//            break;
//        case 2238: //The Culling of Stratholme +
//            player->CLOSE_GOSSIP_MENU();
//            player->TeleportTo(1, -8484.37f, -4491.85f, -212.96f, 1.61f);
//            break;
//        case 2239: //Gundrak +
//            player->CLOSE_GOSSIP_MENU();
//            player->TeleportTo(571, 6937.540f, -4455.98f, 450.68f, 1.00f);
//            break;
//        case 22310: //Halls of Lightning +
//            player->CLOSE_GOSSIP_MENU();
//            player->TeleportTo(571, 9131.15f, -1334.98f, 1061.533f, 5.517f);
//            break;
//        case 22311: //Utgarde Pinnacle +
//            player->CLOSE_GOSSIP_MENU();
//            player->TeleportTo(571, 1245.690f, -4856.59f, 216.86f, 3.45f);
//            break;
//        case 22312: //Trial of the Champion +
//            player->CLOSE_GOSSIP_MENU();
//            player->TeleportTo(571, 8604.999f, 791.69f, 558.26f, 3.14f);
//            break;
//        case 22313: //Forge of Souls, Pit of Saron, Halls of Reflection +
//            player->CLOSE_GOSSIP_MENU();
//            player->TeleportTo(571, 5635.173f, 2048.567f, 798.10f, 4.67f);
//            break;
//        case 23: //Third menu (TELEPORT_RAID_INSTANCES) and it's cases
//            if (player->getLevel() >= 50)
//            {
//                player->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_1, "Classic raid instances", GOSSIP_SENDER_MAIN, 231);
//            }
//            if (player->getLevel() >= 65)
//            {
//                player->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_1, "Burning Crusade raid instances", GOSSIP_SENDER_MAIN, 232);
//            }
//            if (player->getLevel() >= 80)
//            {
//                player->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_1, "Lich King raid instances", GOSSIP_SENDER_MAIN, 233);
//            }
//            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_1, "Back", GOSSIP_SENDER_MAIN, 2);
//            player->SEND_GOSSIP_MENU(51000, creature->GetGUID());
//            break;
//        case 231: //Third menu (TELEPORT_RAID_INSTANCES_CLASSIC) and it's cases
//            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_1, "Molten Core", GOSSIP_SENDER_MAIN, 2311);
//            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_1, "Blackwing Lair", GOSSIP_SENDER_MAIN, 2312);
//            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_1, "Ruins of Ahn'Qiraj, Temple of Ahn'Qiraj", GOSSIP_SENDER_MAIN, 2313);
//            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_1, "Zul'Gurub", GOSSIP_SENDER_MAIN, 2314);
//            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_1, "Back", GOSSIP_SENDER_MAIN, 23);
//            player->SEND_GOSSIP_MENU(51000, creature->GetGUID());
//            break;
//        case 2311: //Molten Core +
//            player->CLOSE_GOSSIP_MENU();
//            player->TeleportTo(230, 1117.7214f, -458.81399f, -102.87f, 3.56f);
//            break;
//        case 2312: //Blackwing Lair +
//            player->CLOSE_GOSSIP_MENU();
//            player->TeleportTo(229, 166.0446f, -455.714f, 121.97f, 4.74f);
//            break;
//        case 2313: //Ruins of Ahn'Qiraj, Temple of Ahn'Qiraj +
//            player->CLOSE_GOSSIP_MENU();
//            player->TeleportTo(1, -8164.7f, 1526.07f, 4.1949f, 2.84f);
//            break;
//        case 2314: //Zul'Gurub +
//            player->CLOSE_GOSSIP_MENU();
//            player->TeleportTo(0, -11916.85f, -1207.372f, 92.287f, 4.72f);
//            break;
//        case 232: //Third menu (TELEPORT_RAID_INSTANCES_BC) and it's cases
//            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_1, "Karazhan", GOSSIP_SENDER_MAIN, 2321);
//            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_1, "Gruul's Lair", GOSSIP_SENDER_MAIN, 2322);
//            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_1, "Magtheridon's Lair", GOSSIP_SENDER_MAIN, 2323);
//            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_1, "Zul'Aman", GOSSIP_SENDER_MAIN, 2324);
//            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_1, "Coilfang Reservoir: Serpentshrine Cavern", GOSSIP_SENDER_MAIN, 2325);
//            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_1, "Tempest Keep: The Eye", GOSSIP_SENDER_MAIN, 2326);
//            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_1, "Caverns of Time: Battle for Mount Hyjal", GOSSIP_SENDER_MAIN, 2327);
//            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_1, "Black Temple", GOSSIP_SENDER_MAIN, 2328);
//            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_1, "Sunwell Plateau", GOSSIP_SENDER_MAIN, 2329);
//            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_1, "Back", GOSSIP_SENDER_MAIN, 23);
//            player->SEND_GOSSIP_MENU(51000, creature->GetGUID());
//            break;
//        case 2321: //Karazhan +
//            player->CLOSE_GOSSIP_MENU();
//            player->TeleportTo(0, -11118.8f, -2010.84f, 47.0807f, 0.0f);
//            break;
//        case 2322: //Gruul's Lair +
//            player->CLOSE_GOSSIP_MENU();
//            player->TeleportTo(530, 3539.007568f, 5082.357910f, 1.691071f, 0.0f);
//            break;
//        case 2323: //Magtheridon's Lair +
//            player->CLOSE_GOSSIP_MENU();
//            player->TeleportTo(530, -363.460f, 3173.506f, -97.280f, 5.26f);
//            break;
//        case 2324: //Zul'Aman +
//            player->CLOSE_GOSSIP_MENU();
//            player->TeleportTo(530, 6846.95f, -7954.5f, 170.028f, 4.61501f);
//            break;
//        case 2325: //Coilfang Reservoir: Serpentshrine Cavern +
//            player->CLOSE_GOSSIP_MENU();
//            player->TeleportTo(530, 734.39f, 6866.09f, -69.72f, 0.00f);
//            break;
//        case 2326: //Tempest Keep: The Eye +
//            player->CLOSE_GOSSIP_MENU();
//            player->TeleportTo(530, 3090.6503f, 1408.584f, 189.652f, 4.61f);
//            break;
//        case 2327: //Caverns of Time: Battle for Mount Hyjal +
//            player->CLOSE_GOSSIP_MENU();
//            player->TeleportTo(1, -8484.37f, -4491.85f, -212.96f, 1.61f);
//            break;
//        case 2328: //Black Temple +
//            player->CLOSE_GOSSIP_MENU();
//            player->TeleportTo(530, -3610.719482f, 324.987579f, 37.400028f, 3.282981f);
//            break;
//        case 2329: //Sunwell Plateau +
//            player->CLOSE_GOSSIP_MENU();
//            player->TeleportTo(530, 12574.1f, -6774.81f, 15.0904f, 3.13788f);
//            break;
//        case 233: //Third menu (TELEPORT_RAID_INSTANCES_LK) and it's cases
//            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_1, "The Eye of Eternity", GOSSIP_SENDER_MAIN, 2331);
//            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_1, "Onyxia's Lair", GOSSIP_SENDER_MAIN, 2332);
//            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_1, "Vault of Archavon (outside the fortress)", GOSSIP_SENDER_MAIN, 2333);
//            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_1, "Naxxramas", GOSSIP_SENDER_MAIN, 2334);
//            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_1, "Ulduar", GOSSIP_SENDER_MAIN, 2335);
//            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_1, "Trial of the Crusader ", GOSSIP_SENDER_MAIN, 2336);
//            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_1, "Icecrown Citadel", GOSSIP_SENDER_MAIN, 2337);
//            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_1, "Ruby Sanctum, Obsidian Sanctum", GOSSIP_SENDER_MAIN, 2338);
//            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_1, "Back", GOSSIP_SENDER_MAIN, 23);
//            player->SEND_GOSSIP_MENU(51000, creature->GetGUID());
//            break;
//        case 2331: //The Eye of Eternity +
//            player->CLOSE_GOSSIP_MENU();
//            player->TeleportTo(571, 3808.83f, 6967.47f, 100.1f, 0.468f);
//            break;
//        case 2332: //Onyxia's Lair +
//            player->CLOSE_GOSSIP_MENU();
//            player->TeleportTo(1, -4672.895f, -3664.67f, 46.648f, 4.189f);
//            break;
//        case 2333: //Vault of Archavon +
//            player->CLOSE_GOSSIP_MENU();
//            player->TeleportTo(571, 5128.978f, 2840.344f, 407.17f, 0.0255f);
//            break;
//        case 2334: //Naxxramas +
//            player->CLOSE_GOSSIP_MENU();
//            player->TeleportTo(571, 3668.719f, -1262.460f, 243.63f, 2.304f);
//            break;
//        case 2335: //Ulduar +
//            player->CLOSE_GOSSIP_MENU();
//            player->TeleportTo(571, 9330.955f, -1114.82f, 1245.146f, 6.28f);
//            break;
//        case 2336: //Trial of the Crusader +
//            player->CLOSE_GOSSIP_MENU();
//            player->TeleportTo(571, 8515.889f, 629.25f, 547.395f, 1.574f);
//            break;
//        case 2337: //Icecrownc citadel +
//            player->CLOSE_GOSSIP_MENU();
//            player->TeleportTo(571, 5873.819f, 2110.979f, 636.0109f, 3.55f);
//            break;
//        case 2338: //Ruby Sanctum, Obsidian Sanctum +
//            player->CLOSE_GOSSIP_MENU();
//            player->TeleportTo(571, 3624.78f, 280.987f, -120.145f, 3.2f);
//            break;
//        case 24: //Fourth menu (TELEPORT_PVPZONES) and it's cases
//            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_1, "Armistice PvP zone", GOSSIP_SENDER_MAIN, 241);
//            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_1, "Circle of Blood", GOSSIP_SENDER_MAIN, 242);
//            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_1, "Gurubashi Arena", GOSSIP_SENDER_MAIN, 243);
//            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_1, "The Maul", GOSSIP_SENDER_MAIN, 244);
//            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_1, "The Ring of Trials", GOSSIP_SENDER_MAIN, 245);
//            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_1, "Back", GOSSIP_SENDER_MAIN, 2);
//            player->SEND_GOSSIP_MENU(51000, creature->GetGUID());
//            break;
//        case 241: //Armistice PvP zone
//            player->CLOSE_GOSSIP_MENU();
//            player->TeleportTo(37, 852.267f, 339.953f, 269.508f, 4.23f);
//            break;
//        case 242: //Circle of Blood
//            player->CLOSE_GOSSIP_MENU();
//            player->TeleportTo(530, 2756.722f, 5850.075f, -2.239f, 1.12f);
//            break;
//        case 243: //Gurubashi Arena
//            player->CLOSE_GOSSIP_MENU();
//            player->TeleportTo(0, -13259.043f, 164.976f, 35.49f, 1.1f);
//            break;
//        case 244: //The Maul
//            player->CLOSE_GOSSIP_MENU();
//            player->TeleportTo(1, -3660.064f, 1092.909f, 162.115005f, 3.15f);
//            break;
//        case 245: //The Ring of Trials
//            player->CLOSE_GOSSIP_MENU();
//            player->TeleportTo(530, -2102.818f, 6743.5473f, -3.536184f, 5.5f);
//            break;
//        case 25: //Fifth menu (TELEPORT_PLACESOFINTEREST) and it's cases
//            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_1, "Easter Eggs", GOSSIP_SENDER_MAIN, 251);
//            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_1, "Hidden Locations", GOSSIP_SENDER_MAIN, 252);
//            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_1, "Back", GOSSIP_SENDER_MAIN, 2);
//            player->SEND_GOSSIP_MENU(51000, creature->GetGUID());
//            break;
//        case 251: //Easter Eggs
//            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_1, "The trapdoor from the Lost series", GOSSIP_SENDER_MAIN, 2511);
//            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_1, "Back", GOSSIP_SENDER_MAIN, 25);
//            player->SEND_GOSSIP_MENU(51000, creature->GetGUID());
//            break;
//        case 2511: //Trapdoor from lost                    
//            player->CLOSE_GOSSIP_MENU();
//            player->TeleportTo(571, 6208.752f, 5238.3823f, -97.823f, 1.757f);
//            break;
//        case 252: //Hidden Locations
//            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_1, "Ahn Qiraj Hall", GOSSIP_SENDER_MAIN, 2521);
//            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_1, "Old Ironforge Map", GOSSIP_SENDER_MAIN, 2522);
//            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_1, "Tanaris Islands", GOSSIP_SENDER_MAIN, 2523);
//            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_1, "Wetlands, Mountain Village", GOSSIP_SENDER_MAIN, 2524);
//            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_1, "Back", GOSSIP_SENDER_MAIN, 25);
//            player->SEND_GOSSIP_MENU(51000, creature->GetGUID());
//            break;
//        case 2521: //Ahn Qiraj Hall             
//            player->CLOSE_GOSSIP_MENU();
//            player->TeleportTo(1, -8516.652344f, 2016.7146f, 104.748749f, 3.557f);
//            break;
//        case 2522: //Old Ironforge Map                   
//            player->CLOSE_GOSSIP_MENU();
//            player->TeleportTo(0, -4817.906738f, -973.383911f, 464.709106f, 3.821704f);
//            break;
//        case 2523: //Tanaris Islands                  
//            player->CLOSE_GOSSIP_MENU();
//            player->TeleportTo(1, -11839.35f, -4754.812f, 6.23413f, 1.757f);
//            break;
//        case 2524: //Wetlands, Mountain Village               
//            player->CLOSE_GOSSIP_MENU();
//            player->TeleportTo(0, -4053.333f, -1260.901f, 146.313f, 1.757f);
//            break;
//
//
//        case 3: //Honor shop
//            player->GetSession()->SendListInventory(creature->GetGUID());
//            break;
//        case 4: //Unlearn spells
//            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_TRAINER, "Unlearn Aquatic Form", GOSSIP_SENDER_MAIN, 41);
//            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_TRAINER, "Unlearn Swift Flight Form", GOSSIP_SENDER_MAIN, 42);
//            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_TRAINER, "Unlearn Water Breathing", GOSSIP_SENDER_MAIN, 43);
//            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_1, "Back", GOSSIP_SENDER_MAIN, 999999);
//            player->SEND_GOSSIP_MENU(51000, creature->GetGUID());
//            break;
//        case 41: //Unlearn Aquatic Form
//            if (player->HasSpell(1066))
//            {
//                player->CLOSE_GOSSIP_MENU();
//                player->removeSpell(1066);
//            }
//            else
//            {
//                player->CLOSE_GOSSIP_MENU();
//                creature->MonsterSay("You don't know Aquatic Form spell", LANG_UNIVERSAL, ObjectGuid::Empty);
//            }
//            break;
//        case 42: //Unlearn Swift Flight Form
//            if (player->HasSpell(40120))
//            {
//                player->CLOSE_GOSSIP_MENU();
//                player->removeSpell(40120);
//                player->removeSpell(33943);
//                player->learnSpell(34091, false);
//            }
//            else
//            {
//                player->CLOSE_GOSSIP_MENU();
//                creature->MonsterSay("You don't know Swift Flight Form spell", LANG_UNIVERSAL, ObjectGuid::Empty);
//            }
//            break;
//        case 43: //Unlearn Water Breathing
//            if (player->HasSpell(24347))
//            {
//                player->CLOSE_GOSSIP_MENU();
//                player->removeSpell(24347);
//            }
//            else
//            {
//                player->CLOSE_GOSSIP_MENU();
//                creature->MonsterSay("You don't know Water Breathing spell", LANG_UNIVERSAL, ObjectGuid::Empty);
//            }
//            break;
//        case 5: //Donation main menu
//            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_VENDOR, "Illusion spells for Ethereal Credits", GOSSIP_SENDER_MAIN, 51);
//            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_VENDOR, "Interesting spells for Ethereal Credits", GOSSIP_SENDER_MAIN, 52);
//            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_1, "Back", GOSSIP_SENDER_MAIN, 999999);
//            player->SEND_GOSSIP_MENU(51000, creature->GetGUID());
//            break;
//        case 51: //Donation illusion submenu
//            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_TRAINER, "Learn Human Male Illusion - 25 Ethereal Credits", GOSSIP_SENDER_MAIN, 511);
//            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_TRAINER, "Learn Human Female Illusion - 25 Ethereal Credits", GOSSIP_SENDER_MAIN, 512);
//            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_TRAINER, "Learn Blood Elf Male Illusion - 25 Ethereal Credits", GOSSIP_SENDER_MAIN, 513);
//            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_TRAINER, "Learn Blood Elf Female Illusion - 25 Ethereal Credits", GOSSIP_SENDER_MAIN, 514);
//            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_TRAINER, "Learn Tauren Male Illusion - 25 Ethereal Credits", GOSSIP_SENDER_MAIN, 515);
//            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_TRAINER, "Learn Tauren Female Illusion - 25 Ethereal Credits", GOSSIP_SENDER_MAIN, 516);
//            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_TRAINER, "Learn Gnome Male Illusion - 25 Ethereal Credits", GOSSIP_SENDER_MAIN, 517);
//            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_TRAINER, "Learn Gnome Female Illusion - 25 Ethereal Credits", GOSSIP_SENDER_MAIN, 518);
//            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_TRAINER, "Learn Skeleton Illusion - 25 Ethereal Credits", GOSSIP_SENDER_MAIN, 519);
//            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_1, "Back", GOSSIP_SENDER_MAIN, 5);
//            player->SEND_GOSSIP_MENU(51000, creature->GetGUID());
//            break;
//        case 511: //Learn Human Male Illusion
//            spellDonate(player, creature, 35466, 51);
//            break;
//        case 512: //Learn Human Female Illusion
//            spellDonate(player, creature, 37805, 51);
//            break;
//        case 513: //Learn Blood Elf Male Illusion
//            spellDonate(player, creature, 37807, 51);
//            break;
//        case 514: //Learn Blood Elf Female Illusion
//            spellDonate(player, creature, 37806, 51);
//            break;
//        case 515: //Learn Tauren Male Illusion
//            spellDonate(player, creature, 37810, 51);
//            break;
//        case 516: //Learn Tauren Female Illusion
//            spellDonate(player, creature, 37811, 51);
//            break;
//        case 517: //Learn Gnome Male Illusion
//            spellDonate(player, creature, 37808, 51);
//            break;
//        case 518: //Learn Gnome Female Illusion
//            spellDonate(player, creature, 37809, 51);
//            break;
//        case 519: //Learn Skeleton Illusion
//            spellDonate(player, creature, 21751, 51);
//            break;
//        case 52: //Donation interesting spells submenu
//            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_TRAINER, "Learn Ray of Light - 25 Ethereal Credits", GOSSIP_SENDER_MAIN, 521);
//            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_TRAINER, "Learn Cascade of Ebon Petals (2 min) - 25 Ethereal Credits", GOSSIP_SENDER_MAIN, 522);
//            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_TRAINER, "Learn Cascade of Red Petals (1 min) - 25 Ethereal Credits", GOSSIP_SENDER_MAIN, 523);
//            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_TRAINER, "Learn Chilling Aura - 25 Ethereal Credits", GOSSIP_SENDER_MAIN, 524);
//            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_1, "Back", GOSSIP_SENDER_MAIN, 5);
//            player->SEND_GOSSIP_MENU(51000, creature->GetGUID());
//            break;
//        case 521: //Ray of Light
//            spellDonate(player, creature, 70571, 52);
//            break;
//        case 522: //Cascade of Ebon Petals 
//            spellDonate(player, creature, 61415, 52);
//            break;
//        case 523: //Cascade of Red Petals
//            spellDonate(player, creature, 67554, 52);
//            break;
//        case 524: //Chilling Aura
//            spellDonate(player, creature, 46885, 52);
//            break;
//        default:
//            break;
//        }
//        return true;
//    }
//
//    void spellDonate(Player* player, Creature* creature, uint32 spellid, uint32 caseid)
//    {
//        if (player->HasSpell(spellid) || player->GetItemCount(38186) < 25)
//        {
//            creature->MonsterSay("You already know this spell or you don't have enough Ethereal Credits to buy it", LANG_UNIVERSAL, ObjectGuid::Empty);
//            player->CLOSE_GOSSIP_MENU();
//        }
//        else
//        {
//            player->DestroyItemCount(38186, 25, true); //true has to be here
//            player->learnSpell(spellid, false);
//            CharacterDatabase.PExecute("INSERT INTO character_donate_service SET `account`='%u',`guid`='%u', `service`='BYU_SPELL %u', `cost`='%u', `targetguid`='%u'", player->GetSession()->GetAccountId(), player->GetGUID().GetCounter(), spellid, 25, player->GetGUID().GetCounter());
//            OnGossipSelect(player, creature, GOSSIP_SENDER_MAIN, caseid);
//        }
//    }
//};
//
//
//void AddSC_custum_trainer()
//{
//    new custum_trainer;
//}
