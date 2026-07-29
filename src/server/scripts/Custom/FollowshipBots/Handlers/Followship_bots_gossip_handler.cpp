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

#include "ObjectAccessor.h"
#include "ScriptedGossip.h"
#include "WorldSession.h"

#include "Followship_bots.h"
#include "Followship_bots_ai_base.h"
#include "Followship_bots_config.h"
#include "Followship_bots_mage.h"
#include "Followship_bots_mgr.h"
#include "Followship_bots_utils.h"

#include "GenAI_client.h"
#include "GenAI_chatter_prompts.h"

#include "Followship_bots_chatter_handler.h"
#include "Followship_bots_events_handler.h"
#include "Followship_bots_gossip_handler.h"
#include "Followship_bots_movement_handler.h"
#include "Followship_bots_powers_handler.h"

namespace FSBGossip
{
    bool HandleDefaultGossipHello(Creature* bot, Player* player, bool hired, ObjectGuid& outPlayerGuid)
    {
        if (!bot || !player)
            return false;

        if (FSBMgr::Get()->IsBotOwned(bot) && !FSBMgr::Get()->IsBotOwnedByPlayer(player, bot))
            return false;

        // TO-DO make this a method to check when to enable certain bots
        if (bot->GetEntry() == 16502 && !player->GetQuestRewardStatus(9283))
            return false;

        if (FSBMgr::Get()->CheckPlayerHasBotWithEntry(player, bot->GetEntry()) && !hired)
        {
            auto baseAI = dynamic_cast<FSB_BaseAI*>(bot->AI());
            bot->Say(FSB_SAY_DUPLICATE_FOLLOWER, baseAI ? baseAI->botLanguage : LANG_UNIVERSAL);
            ClearGossipMenuFor(player);
            CloseGossipMenuFor(player);
            return true;
        }

        outPlayerGuid = player->GetGUID();

        uint32 menuId = bot->GetGossipMenuId();

        if (menuId > 0)
            InitGossipMenuFor(player, menuId);
        else InitGossipMenuFor(player, FSB_GOSSIP_DEFAULT_MENU);

        if (hired)
        {
            AddGossipItemFor(player, GossipOptionNpc::Auctioneer,
                FSB_GOSSIP_ITEM_FIRE, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 5);

            AddGossipItemFor(player, GossipOptionNpc::None,
                FSB_GOSSIP_ITEM_INFO, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 2);

            AddGossipItemFor(player, GossipOptionNpc::None,
                FSB_GOSSIP_MENU_ROLES, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 3);

            AddGossipItemFor(player, GossipOptionNpc::Trainer,
                FSB_GOSSIP_MENU_INSTRUCTIONS, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 6);

            if (FSBMgr::Get()->GetBotClassForEntry(bot->GetEntry()) == FSB_Class::Mage)
                AddGossipItemFor(player, GossipOptionNpc::None,
                    FSB_GOSSIP_MENU_PORTAL, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 26);
        }
        else
        {
            AddGossipItemFor(player, GossipOptionNpc::Auctioneer,
                FSB_GOSSIP_MENU_HIRE, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1);

            AddGossipItemFor(player, GossipOptionNpc::None,
                FSB_GOSSIP_ITEM_INFO, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 2);
        }

        SendGossipMenuFor(player, FSBGossipUtils::ResolveGossipTextId(player, bot), bot->GetGUID());
        return true;
    }

    bool HandleGossipMenuFollowAngle(Creature* bot, Player* player)
    {
        AddGossipItemFor(player, GossipOptionNpc::None, FSB_GOSSIP_ITEM_FOLLOW_ANGLE_FRONT, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 17);
        AddGossipItemFor(player, GossipOptionNpc::None, FSB_GOSSIP_ITEM_FOLLOW_ANGLE_BACK, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 18);
        AddGossipItemFor(player, GossipOptionNpc::None, FSB_GOSSIP_ITEM_FOLLOW_ANGLE_RIGHT, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 19);
        AddGossipItemFor(player, GossipOptionNpc::None, FSB_GOSSIP_ITEM_FOLLOW_ANGLE_LEFT, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 22);
        AddGossipItemFor(player, GossipOptionNpc::None, FSB_GOSSIP_ITEM_BACKMAIN, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 4);

        SendGossipMenuFor(player, FSBGossipUtils::ResolveGossipTextId(player, bot), bot->GetGUID());
        return true;
    }
    bool HandleGossipMenuFollowDistance(Creature* bot, Player* player)
    {
        AddGossipItemFor(player, GossipOptionNpc::None, FSB_GOSSIP_ITEM_FOLLOW_DIST1, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 14);
        AddGossipItemFor(player, GossipOptionNpc::None, FSB_GOSSIP_ITEM_FOLLOW_DIST2, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 15);
        AddGossipItemFor(player, GossipOptionNpc::None, FSB_GOSSIP_ITEM_FOLLOW_DIST3, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 16);
        AddGossipItemFor(player, GossipOptionNpc::None, FSB_GOSSIP_ITEM_BACKMAIN, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 4);

        SendGossipMenuFor(player, FSBGossipUtils::ResolveGossipTextId(player, bot), bot->GetGUID());
        return true;
    }
    bool HandleGossipMenuHire(Creature* bot, Player* player)
    {
        uint32 pLevel = player->GetLevel();

        // we first calculate hire price based configs base price and hire duration options and actual player level
        int64 hirePrice1 = (FollowshipBotsConfig::configFSBPricePerLevel * pLevel * FollowshipBotsConfig::configFSBHireDuration1);
        std::string hireText1 = FSBGossipUtils::BuildHireText(hirePrice1, FollowshipBotsConfig::configFSBHireDuration1);

        int64 hirePrice2 = (FollowshipBotsConfig::configFSBPricePerLevel * pLevel * FollowshipBotsConfig::configFSBHireDuration2);
        std::string hireText2 = FSBGossipUtils::BuildHireText(hirePrice2, FollowshipBotsConfig::configFSBHireDuration2);

        int64 hirePrice3 = (FollowshipBotsConfig::configFSBPricePerLevel * pLevel * FollowshipBotsConfig::configFSBHireDuration3);
        std::string hireText3 = FSBGossipUtils::BuildHireText(hirePrice3, FollowshipBotsConfig::configFSBHireDuration3);

        AddGossipItemFor(player, GossipOptionNpc::Auctioneer, hireText1, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 10);
        AddGossipItemFor(player, GossipOptionNpc::Auctioneer, hireText2, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 11);
        AddGossipItemFor(player, GossipOptionNpc::Auctioneer, hireText3, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 12);
        AddGossipItemFor(player, GossipOptionNpc::Auctioneer, FSB_GOSSIP_ITEM_PHIRE, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 13);
        AddGossipItemFor(player, GossipOptionNpc::None, FSB_GOSSIP_ITEM_BACKMAIN, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 4);

        SendGossipMenuFor(player, FSBGossipUtils::ResolveGossipTextId(player, bot), bot->GetGUID());
        return true;
    }
    bool HandleGossipMenuInstructions(Creature* bot, Player* player)
    {
        if (FSBMovement::GetMovementType(bot) == FOLLOW_MOTION_TYPE)
        {
            AddGossipItemFor(player, GossipOptionNpc::None, FSB_GOSSIP_ITEM_STAY_HERE, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 20);
            AddGossipItemFor(player, GossipOptionNpc::None, FSB_GOSSIP_MENU_FOLLOW_DIST, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 7);
            AddGossipItemFor(player, GossipOptionNpc::None, FSB_GOSSIP_MENU_FOLLOW_ANGLE, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 8);
            AddGossipItemFor(player, GossipOptionNpc::None, FSB_GOSSIP_MENU_LANGUAGE, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 32);
            AddGossipItemFor(player, GossipOptionNpc::Auctioneer, FSB_GOSSIP_ITEM_BACKMAIN, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 4);
        }
        else if (FSBMovement::GetMovementType(bot) == IDLE_MOTION_TYPE)
        {
            AddGossipItemFor(player, GossipOptionNpc::None, FSB_GOSSIP_ITEM_FOLLOW, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 21);
            AddGossipItemFor(player, GossipOptionNpc::None, FSB_GOSSIP_MENU_FOLLOW_DIST, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 7);
            AddGossipItemFor(player, GossipOptionNpc::None, FSB_GOSSIP_MENU_FOLLOW_ANGLE, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 8);
            AddGossipItemFor(player, GossipOptionNpc::None, FSB_GOSSIP_MENU_LANGUAGE, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 32);
            AddGossipItemFor(player, GossipOptionNpc::Auctioneer, FSB_GOSSIP_ITEM_BACKMAIN, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 4);
        }

        SendGossipMenuFor(player, FSBGossipUtils::ResolveGossipTextId(player, bot), bot->GetGUID());
        return true;
    }
    bool HandleGossipMenuPortals(Creature* bot, Player* player)
    {
        AddGossipItemFor(player, GossipOptionNpc::None, FSB_GOSSIP_ITEM_PORTAL_STORMWIND, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 27);
        AddGossipItemFor(player, GossipOptionNpc::None, FSB_GOSSIP_ITEM_PORTAL_DARNASSUS, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 28);
        AddGossipItemFor(player, GossipOptionNpc::None, FSB_GOSSIP_ITEM_PORTAL_IRONFORGE, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 29);
        AddGossipItemFor(player, GossipOptionNpc::None, FSB_GOSSIP_ITEM_PORTAL_EXODAR, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 30);
        AddGossipItemFor(player, GossipOptionNpc::None, FSB_GOSSIP_ITEM_BACKMAIN, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 4);

        SendGossipMenuFor(player, FSBGossipUtils::ResolveGossipTextId(player, bot), bot->GetGUID());
        return true;
    }
    bool HandleGossipMenuRoles(Creature* bot, Player* player)
    {
        FSB_Class botClass = FSBMgr::Get()->GetBotClassForEntry(bot->GetEntry());
        switch (botClass)
        {
        case FSB_Class::None:
            break;
        case FSB_Class::Warrior:
            AddGossipItemFor(player, GossipOptionNpc::Trainer, FSB_GOSSIP_ITEM_ROLE_TANK, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 23);
            AddGossipItemFor(player, GossipOptionNpc::Trainer, FSB_GOSSIP_ITEM_ROLE_MELEE, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 24);
            break;
        case FSB_Class::Priest:
            AddGossipItemFor(player, GossipOptionNpc::Trainer, FSB_GOSSIP_ITEM_ROLE_ASSIST, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 23);
            AddGossipItemFor(player, GossipOptionNpc::Trainer, FSB_GOSSIP_ITEM_ROLE_DAMAGE, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 24);
            AddGossipItemFor(player, GossipOptionNpc::Trainer, FSB_GOSSIP_ITEM_ROLE_BALANCED, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 25);
            break;
        case FSB_Class::Mage:
            AddGossipItemFor(player, GossipOptionNpc::Trainer, FSB_GOSSIP_ITEM_ROLE_ARCANE, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 23);
            AddGossipItemFor(player, GossipOptionNpc::Trainer, FSB_GOSSIP_ITEM_ROLE_FROST, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 24);
            AddGossipItemFor(player, GossipOptionNpc::Trainer, FSB_GOSSIP_ITEM_ROLE_FIRE, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 25);
            break;
        case FSB_Class::Monk:
            AddGossipItemFor(player, GossipOptionNpc::Trainer, FSB_GOSSIP_ITEM_ROLE_HEALER, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 23);
            AddGossipItemFor(player, GossipOptionNpc::Trainer, FSB_GOSSIP_ITEM_ROLE_TANK, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 24);
            AddGossipItemFor(player, GossipOptionNpc::Trainer, FSB_GOSSIP_ITEM_ROLE_MELEE, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 25);
            break;
        case FSB_Class::Rogue:
            AddGossipItemFor(player, GossipOptionNpc::Trainer, FSB_GOSSIP_ITEM_ROLE_ROGUE_1, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 23);
            AddGossipItemFor(player, GossipOptionNpc::Trainer, FSB_GOSSIP_ITEM_ROLE_ROGUE_2, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 24);
            AddGossipItemFor(player, GossipOptionNpc::Trainer, FSB_GOSSIP_ITEM_ROLE_ROGUE_3, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 25);
            break;
        case FSB_Class::Druid:
            AddGossipItemFor(player, GossipOptionNpc::Trainer, FSB_GOSSIP_ITEM_ROLE_TANK, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 23);
            AddGossipItemFor(player, GossipOptionNpc::Trainer, FSB_GOSSIP_ITEM_ROLE_MELEE, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 24);
            AddGossipItemFor(player, GossipOptionNpc::Trainer, FSB_GOSSIP_ITEM_ROLE_HEALER, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 25);
            AddGossipItemFor(player, GossipOptionNpc::Trainer, FSB_GOSSIP_ITEM_ROLE_DAMAGE, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 31);
            break;
        case FSB_Class::Paladin:
            AddGossipItemFor(player, GossipOptionNpc::Trainer, FSB_GOSSIP_ITEM_ROLE_TANK, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 23);
            AddGossipItemFor(player, GossipOptionNpc::Trainer, FSB_GOSSIP_ITEM_ROLE_MELEE, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 24);
            AddGossipItemFor(player, GossipOptionNpc::Trainer, FSB_GOSSIP_ITEM_ROLE_HEALER, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 25);
            break;
        case FSB_Class::Hunter:
            AddGossipItemFor(player, GossipOptionNpc::Trainer, FSB_GOSSIP_ITEM_ROLE_DAMAGE, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 23);
            AddGossipItemFor(player, GossipOptionNpc::Trainer, FSB_GOSSIP_ITEM_ROLE_BEAST, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 25);
            break;
        case FSB_Class::Shaman:
            AddGossipItemFor(player, GossipOptionNpc::Trainer, FSB_GOSSIP_ITEM_ROLE_DAMAGE, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 23);
            AddGossipItemFor(player, GossipOptionNpc::Trainer, FSB_GOSSIP_ITEM_ROLE_MELEE, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 24);
            AddGossipItemFor(player, GossipOptionNpc::Trainer, FSB_GOSSIP_ITEM_ROLE_HEALER, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 25);
            break;
        case FSB_Class::Warlock:
            AddGossipItemFor(player, GossipOptionNpc::Trainer, FSB_GOSSIP_ITEM_ROLE_AFFLICTION, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 23);
            AddGossipItemFor(player, GossipOptionNpc::Trainer, FSB_GOSSIP_ITEM_ROLE_DEMONOLOGY, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 24);
            AddGossipItemFor(player, GossipOptionNpc::Trainer, FSB_GOSSIP_ITEM_ROLE_DESTRUCTION, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 25);
            break;
        default:
            break;
        }

        AddGossipItemFor(player, GossipOptionNpc::None, FSB_GOSSIP_ITEM_BACKMAIN, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 4);

        SendGossipMenuFor(player, FSBGossipUtils::ResolveGossipTextId(player, bot), bot->GetGUID());
        return true;
    }
    bool HandleGossipMenuLanguage(Creature* bot, Player* player)
    {
        AddGossipItemFor(player, GossipOptionNpc::None, FSB_GOSSIP_ITEM_LANG_RACIAL, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 33);
        AddGossipItemFor(player, GossipOptionNpc::None, FSB_GOSSIP_ITEM_LANG_TEAM, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 34);
        AddGossipItemFor(player, GossipOptionNpc::Auctioneer, FSB_GOSSIP_ITEM_BACKMAIN, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 4);

        SendGossipMenuFor(player, FSBGossipUtils::ResolveGossipTextId(player, bot), bot->GetGUID());
        return true;
    }

    void HandleGossipItemInfo(Creature* bot, Player* player)
    {
        if (!bot || !player)
            return;

        player->PlayerTalkClass->SendCloseGossip();

        FSBGenAIPrompts::DispatchBotInfoRequest(bot);
    }
    void HandleGossipItemRole(Creature* bot, FSB_Class botClass, uint8 roleOption, bool& botHasDemon)
    {
        if (!bot)
            return;

        switch (botClass)
        {
        case FSB_Class::Druid:
            if (roleOption == FSB_GOSSIP_ROLE_1)
                FSBMgr::Get()->SetRole(bot, FSB_Roles::FSB_ROLE_TANK);
            else if (roleOption == FSB_GOSSIP_ROLE_2)
                FSBMgr::Get()->SetRole(bot, FSB_Roles::FSB_ROLE_MELEE_DAMAGE);
            else if (roleOption == FSB_GOSSIP_ROLE_3)
                FSBMgr::Get()->SetRole(bot, FSB_Roles::FSB_ROLE_HEALER);
            else if (roleOption == FSB_GOSSIP_ROLE_4)
                FSBMgr::Get()->SetRole(bot, FSB_Roles::FSB_ROLE_RANGED_DAMAGE);
            FSBMgr::Get()->ApplyRoleAuras(bot, FSBMgr::Get()->GetRole(bot));
            break;

        case FSB_Class::Hunter:
            if (roleOption == FSB_GOSSIP_ROLE_1)
            {
                FSBMgr::Get()->SetRole(bot, FSB_Roles::FSB_ROLE_RANGED_DAMAGE);
                break;
            }
            else if (roleOption == FSB_GOSSIP_ROLE_3)
            {
                FSBMgr::Get()->SetRole(bot, FSB_Roles::FSB_ROLE_ASSIST);
                break;
            }
            break;

        case FSB_Class::Paladin:
            if (roleOption == FSB_GOSSIP_ROLE_1)
                FSBMgr::Get()->SetRole(bot, FSB_Roles::FSB_ROLE_TANK);
            else if (roleOption == FSB_GOSSIP_ROLE_2)
                FSBMgr::Get()->SetRole(bot, FSB_Roles::FSB_ROLE_MELEE_DAMAGE);
            else if (roleOption == FSB_GOSSIP_ROLE_3)
                FSBMgr::Get()->SetRole(bot, FSB_Roles::FSB_ROLE_HEALER);
            FSBMgr::Get()->ApplyRoleAuras(bot, FSBMgr::Get()->GetRole(bot));
            break;
        case FSB_Class::Shaman:
            if (roleOption == FSB_GOSSIP_ROLE_1)
            {
                FSBMgr::Get()->SetRole(bot, FSB_Roles::FSB_ROLE_RANGED_DAMAGE);
                break;
            }
            else if (roleOption == FSB_GOSSIP_ROLE_2)
            {
                FSBMgr::Get()->SetRole(bot, FSB_Roles::FSB_ROLE_MELEE_DAMAGE);
                break;
            }
            else if (roleOption == FSB_GOSSIP_ROLE_3)
            {
                FSBMgr::Get()->SetRole(bot, FSB_Roles::FSB_ROLE_HEALER);
                break;
            }
            break;
        case FSB_Class::Rogue:
            if (roleOption == FSB_GOSSIP_ROLE_1)
            {
                FSBMgr::Get()->SetRole(bot, FSB_Roles::FSB_ROLE_MELEE_DAMAGE);
                break;
            }
            else if (roleOption == FSB_GOSSIP_ROLE_2)
            {
                FSBMgr::Get()->SetRole(bot, FSB_Roles::FSB_ROLE_MELEE_DAMAGE_2);
                break;
            }
            else if (roleOption == FSB_GOSSIP_ROLE_3)
            {
                FSBMgr::Get()->SetRole(bot, FSB_Roles::FSB_ROLE_MELEE_DAMAGE_3);
                break;
            }
            break;
        case FSB_Class::Warrior:
            if (roleOption == FSB_GOSSIP_ROLE_1)
                FSBMgr::Get()->SetRole(bot, FSB_Roles::FSB_ROLE_TANK);
            else if (roleOption == FSB_GOSSIP_ROLE_2)
                FSBMgr::Get()->SetRole(bot, FSB_Roles::FSB_ROLE_MELEE_DAMAGE);
            FSBMgr::Get()->ApplyRoleAuras(bot, FSBMgr::Get()->GetRole(bot));
            break;
        case FSB_Class::Priest:
            if (roleOption == FSB_GOSSIP_ROLE_1)
                FSBMgr::Get()->SetRole(bot, FSB_Roles::FSB_ROLE_HEALER);
            else if (roleOption == FSB_GOSSIP_ROLE_2)
                FSBMgr::Get()->SetRole(bot, FSB_Roles::FSB_ROLE_RANGED_DAMAGE);
            else if (roleOption == FSB_GOSSIP_ROLE_3)
                FSBMgr::Get()->SetRole(bot, FSB_Roles::FSB_ROLE_ASSIST);
            FSBMgr::Get()->ApplyRoleAuras(bot, FSBMgr::Get()->GetRole(bot));
            break;
        case FSB_Class::Mage:
            if (roleOption == FSB_GOSSIP_ROLE_1)
            {
                FSBMgr::Get()->SetRole(bot, FSB_Roles::FSB_ROLE_RANGED_ARCANE);
                break;
            }
            else if (roleOption == FSB_GOSSIP_ROLE_2)
            {
                FSBMgr::Get()->SetRole(bot, FSB_Roles::FSB_ROLE_RANGED_FROST);
                break;
            }
            else if (roleOption == FSB_GOSSIP_ROLE_3)
            {
                FSBMgr::Get()->SetRole(bot, FSB_Roles::FSB_ROLE_RANGED_FIRE);
                break;
            }
            break;
        case FSB_Class::Monk:
            if (roleOption == FSB_GOSSIP_ROLE_1)
            {
                FSBMgr::Get()->SetRole(bot, FSB_Roles::FSB_ROLE_HEALER);
                FSBPowers::SetBotToMana(bot);
                break;
            }
            else if (roleOption == FSB_GOSSIP_ROLE_2)
            {
                FSBMgr::Get()->SetRole(bot, FSB_Roles::FSB_ROLE_TANK);
                FSBPowers::SetBotToEnergy(bot);
                break;
            }
            else if (roleOption == FSB_GOSSIP_ROLE_3)
            {
                FSBMgr::Get()->SetRole(bot, FSB_Roles::FSB_ROLE_MELEE_DAMAGE);
                FSBPowers::SetBotToChi(bot);
                break;
            }
            break;
        case FSB_Class::Warlock:
            if (roleOption == FSB_GOSSIP_ROLE_1)
                FSBMgr::Get()->SetRole(bot, FSB_Roles::FSB_ROLE_RANGED_AFFLICTION);
            else if (roleOption == FSB_GOSSIP_ROLE_2)
                FSBMgr::Get()->SetRole(bot, FSB_Roles::FSB_ROLE_RANGED_DEMONOLOGY);
            else if (roleOption == FSB_GOSSIP_ROLE_3)
                FSBMgr::Get()->SetRole(bot, FSB_Roles::FSB_ROLE_RANGED_DESTRUCTION);

            FSBMgr::Get()->ApplyRoleAuras(bot, FSBMgr::Get()->GetRole(bot));
            botHasDemon = false;
            break;
        default:
            break;
        }

        bot->SetReactState(REACT_AGGRESSIVE);
        FSBGenAIPrompts::DispatchBotRoleAcknowledge(bot);
    }
    bool HandleGossipItemHirePermanent(Creature* bot, Player* player)
    {
        if (!bot || !player)
            return false;

        auto baseAI = dynamic_cast<FSB_BaseAI*>(bot->AI());
        if (!baseAI)
            return false;

        uint8 pLevel = player->GetLevel();

        // End price is base cost per level times player level
        if (player->HasEnoughMoney(int64(FollowshipBotsConfig::configFSBPermanentPricePerLevel * pLevel)))
        {
            player->ModifyMoney(-int64(FollowshipBotsConfig::configFSBPermanentPricePerLevel * pLevel));
            player->GetSession()->SendNotification(FSB_PLAYER_NOTIFICATION_PAYMENT_SUCCESS);

            baseAI->botHired = true;
            FSBMgr::Get()->HirePersistentBot(player, bot, 0);

            FSBMovement::ResumeFollow(bot, baseAI->botFollowDistance, baseAI->botFollowAngle);

            FSBGenAIPrompts::DispatchBotHired(bot, 0);
        }
        else
            player->GetSession()->SendNotification(FSB_PLAYER_NOTIFICATION_PAYMENT_FAIL);

        player->PlayerTalkClass->SendCloseGossip();
        return true;
    }

    bool HandleGossipItemHire(Creature* bot, Player* player, uint32 durationHours)
    {
        if (!bot || !player)
            return false;

        auto baseAI = dynamic_cast<FSB_BaseAI*>(bot->AI());
        if (!baseAI)
            return false;

        // 1. Charge the player
        if (!FSBUtils::TryChargeHire(player, durationHours))
        {
            player->PlayerTalkClass->SendCloseGossip();
            return false;
        }

        // 2. Mark hired
        baseAI->botHired = true;

        // 3. Persist bot hire
        FSBMgr::Get()->HirePersistentBot(player, bot, durationHours);

        // 4. Schedule expiration
        FSBEvents::ScheduleBotEvent(bot, FSB_EVENT_HIRED_EXPIRED, std::chrono::minutes(durationHours * 60));

        // 5. Resume follow
        FSBMovement::ResumeFollow(bot, baseAI->botFollowDistance, baseAI->botFollowAngle);

        // 6. Chatter
        FSBGenAIPrompts::DispatchBotHired(bot, durationHours);

        // 7. Close gossip
        player->PlayerTalkClass->SendCloseGossip();
        return true;
    }

    bool HandleGossipSelect(Creature* bot, ObjectGuid playerGuid, uint32 /*menuId*/, uint32 gossipListId)
    {
        if (!bot)
            return false;

        Player* player = ObjectAccessor::GetPlayer(*bot, playerGuid);
        if (!player)
            return false;

        auto baseAI = dynamic_cast<FSB_BaseAI*>(bot->AI());
        if (!baseAI)
            return false;

        uint32 const action = player->PlayerTalkClass->GetGossipOptionAction(gossipListId);
        ClearGossipMenuFor(player);

        switch (action)
        {
            // Hire Menu
        case GOSSIP_ACTION_INFO_DEF + 1:
            return HandleGossipMenuHire(bot, player);

            // Bot Info
        case GOSSIP_ACTION_INFO_DEF + 2:
            HandleGossipItemInfo(bot, player);
            return true;

            // Roles Menu
        case GOSSIP_ACTION_INFO_DEF + 3:
            return HandleGossipMenuRoles(bot, player);

            // Bot Gossip Back to main
        case GOSSIP_ACTION_INFO_DEF + 4:
        {
            ObjectGuid localPlayerGuid;
            return HandleDefaultGossipHello(bot, player, baseAI->botHired, localPlayerGuid);
        }

            // Bot Dismiss
        case GOSSIP_ACTION_INFO_DEF + 5:
            FSBEvents::ScheduleBotEvent(bot, FSB_EVENT_HIRED_EXPIRED, 1s, 3s);
            break;

            // Bot Instructions Menu
        case GOSSIP_ACTION_INFO_DEF + 6:
            return HandleGossipMenuInstructions(bot, player);

            // Bot Follow Distance Menu
        case GOSSIP_ACTION_INFO_DEF + 7:
            return HandleGossipMenuFollowDistance(bot, player);

            // Bot Follow Angle Menu
        case GOSSIP_ACTION_INFO_DEF + 8:
            return HandleGossipMenuFollowAngle(bot, player);

            // Bot Hire Option 1
        case GOSSIP_ACTION_INFO_DEF + 10:
            return HandleGossipItemHire(bot, player, FollowshipBotsConfig::configFSBHireDuration1);

            // Bot Hire Option 2
        case GOSSIP_ACTION_INFO_DEF + 11:
            return HandleGossipItemHire(bot, player, FollowshipBotsConfig::configFSBHireDuration2);

            // Bot Hire Option 3
        case GOSSIP_ACTION_INFO_DEF + 12:
            return HandleGossipItemHire(bot, player, FollowshipBotsConfig::configFSBHireDuration3);

            // Bot Hire Option Permanent
        case GOSSIP_ACTION_INFO_DEF + 13:
            return HandleGossipItemHirePermanent(bot, player);

            // Bot Follow Distance Option 1
        case GOSSIP_ACTION_INFO_DEF + 14:
            baseAI->botFollowDistance = FOLLOW_DISTANCE_CLOSE;
            FSBMovement::ResumeFollow(bot, baseAI->botFollowDistance, baseAI->botFollowAngle);
            FSBGenAIPrompts::DispatchBotAcknowledge(bot, FSBGenAIPrompts::FSB_AcknowledgeContext::FollowDistanceClose);
            break;

            // Bot Follow Distance Option 2
        case GOSSIP_ACTION_INFO_DEF + 15:
            baseAI->botFollowDistance = FOLLOW_DISTANCE_NORMAL;
            FSBMovement::ResumeFollow(bot, baseAI->botFollowDistance, baseAI->botFollowAngle);
            FSBGenAIPrompts::DispatchBotAcknowledge(bot, FSBGenAIPrompts::FSB_AcknowledgeContext::FollowDistanceNormal);
            break;

            // Bot Follow Distance Option 3
        case GOSSIP_ACTION_INFO_DEF + 16:
            baseAI->botFollowDistance = FOLLOW_DISTANCE_WIDE;
            FSBMovement::ResumeFollow(bot, baseAI->botFollowDistance, baseAI->botFollowAngle);
            FSBGenAIPrompts::DispatchBotAcknowledge(bot, FSBGenAIPrompts::FSB_AcknowledgeContext::FollowDistanceWide);
            break;

            // Bot Follow Angle Option 1
        case GOSSIP_ACTION_INFO_DEF + 17:
            baseAI->botFollowAngle = FOLLOW_ANGLE_FRONT;
            FSBMovement::ResumeFollow(bot, baseAI->botFollowDistance, baseAI->botFollowAngle);
            FSBGenAIPrompts::DispatchBotAcknowledge(bot, FSBGenAIPrompts::FSB_AcknowledgeContext::FollowAngleFront);
            break;

            // Bot Follow Angle Option 2
        case GOSSIP_ACTION_INFO_DEF + 18:
            baseAI->botFollowAngle = FOLLOW_ANGLE_BEHIND;
            FSBMovement::ResumeFollow(bot, baseAI->botFollowDistance, baseAI->botFollowAngle);
            FSBGenAIPrompts::DispatchBotAcknowledge(bot, FSBGenAIPrompts::FSB_AcknowledgeContext::FollowAngleBehind);
            break;

            // Bot Follow Angle Option 3
        case GOSSIP_ACTION_INFO_DEF + 19:
            baseAI->botFollowAngle = FSBUtils::GetRandomRightAngle();
            FSBMovement::ResumeFollow(bot, baseAI->botFollowDistance, baseAI->botFollowAngle);
            FSBGenAIPrompts::DispatchBotAcknowledge(bot, FSBGenAIPrompts::FSB_AcknowledgeContext::FollowAngleRight);
            break;

            // Bot Stay Option
        case GOSSIP_ACTION_INFO_DEF + 20:
            FSBMovement::StopFollow(bot);
            FSBGenAIPrompts::DispatchBotAcknowledge(bot, FSBGenAIPrompts::FSB_AcknowledgeContext::StayCommand);
            break;

            // Bot Follow Option
        case GOSSIP_ACTION_INFO_DEF + 21:
            FSBMovement::ResumeFollow(bot, baseAI->botFollowDistance, baseAI->botFollowAngle);
            FSBGenAIPrompts::DispatchBotAcknowledge(bot, FSBGenAIPrompts::FSB_AcknowledgeContext::FollowCommand);
            break;

            // Bot Follow Angle Option 4
        case GOSSIP_ACTION_INFO_DEF + 22:
            baseAI->botFollowAngle = FSBUtils::GetRandomLeftAngle();
            FSBMovement::ResumeFollow(bot, baseAI->botFollowDistance, baseAI->botFollowAngle);
            FSBGenAIPrompts::DispatchBotAcknowledge(bot, FSBGenAIPrompts::FSB_AcknowledgeContext::FollowAngleLeft);
            break;

            // Bot Role Option 1
        case GOSSIP_ACTION_INFO_DEF + 23:
            HandleGossipItemRole(bot, baseAI->botClass, FSB_GOSSIP_ROLE_1, baseAI->botHasDemon);
            break;

            // Bot Role Option 2
        case GOSSIP_ACTION_INFO_DEF + 24:
            HandleGossipItemRole(bot, baseAI->botClass, FSB_GOSSIP_ROLE_2, baseAI->botHasDemon);
            break;

            // Bot Role Option 3
        case GOSSIP_ACTION_INFO_DEF + 25:
            HandleGossipItemRole(bot, baseAI->botClass, FSB_GOSSIP_ROLE_3, baseAI->botHasDemon);
            break;

        case GOSSIP_ACTION_INFO_DEF + 26:
            return HandleGossipMenuPortals(bot, player);

        case GOSSIP_ACTION_INFO_DEF + 27:
            bot->CastSpell(bot, SPELL_MAGE_PORTAL_STORMWIND);
            bot->Say("Okay one portal coming up!", baseAI->botLanguage);
            break;

        case GOSSIP_ACTION_INFO_DEF + 28:
            player->CastSpell(bot, 121849);
            bot->Say("Okay one portal coming up!", baseAI->botLanguage);
            break;

        case GOSSIP_ACTION_INFO_DEF + 29:
            player->CastSpell(player, 121851);
            bot->Say("Okay one portal coming up!", baseAI->botLanguage);
            break;

        case GOSSIP_ACTION_INFO_DEF + 30:
            player->CastSpell(player, 121850);
            bot->Say("Okay one portal coming up!", baseAI->botLanguage);
            break;

            // Bot Role Option 4 - Druid
        case GOSSIP_ACTION_INFO_DEF + 31:
            HandleGossipItemRole(bot, baseAI->botClass, FSB_GOSSIP_ROLE_4, baseAI->botHasDemon);
            break;

            // Language Menu
        case GOSSIP_ACTION_INFO_DEF + 32:
            return HandleGossipMenuLanguage(bot, player);

            // Language: Racial
        case GOSSIP_ACTION_INFO_DEF + 33:
            baseAI->botLanguage = FSBUtils::GetLanguageForFSBRace(baseAI->botRace);
            FSBGenAIPrompts::DispatchBotAcknowledge(bot, FSBGenAIPrompts::FSB_AcknowledgeContext::LanguageCommand);
            break;

            // Language: Team
        case GOSSIP_ACTION_INFO_DEF + 34:
            baseAI->botLanguage = FSBUtils::GetTeamLanguageForFSBRace(baseAI->botRace);
            FSBGenAIPrompts::DispatchBotAcknowledge(bot, FSBGenAIPrompts::FSB_AcknowledgeContext::LanguageCommand);
            break;

        default:
            break;
        }

        CloseGossipMenuFor(player);
        return true;
    }
}
