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

#include "ScriptMgr.h"
#include "AuctionHouseBot.h"
#include "Chat.h"
#include "Language.h"
#include "RBAC.h"

static std::unordered_map<AuctionQuality, uint32> const ahbotQualityLangIds =
    {
        { AUCTION_QUALITY_GRAY,   LANG_AHBOT_QUALITY_GRAY },
        { AUCTION_QUALITY_WHITE,  LANG_AHBOT_QUALITY_WHITE },
        { AUCTION_QUALITY_GREEN,  LANG_AHBOT_QUALITY_GREEN },
        { AUCTION_QUALITY_BLUE,   LANG_AHBOT_QUALITY_BLUE },
        { AUCTION_QUALITY_PURPLE, LANG_AHBOT_QUALITY_PURPLE },
        { AUCTION_QUALITY_ORANGE, LANG_AHBOT_QUALITY_ORANGE },
        { AUCTION_QUALITY_YELLOW, LANG_AHBOT_QUALITY_YELLOW }
    };

using namespace Trinity::ChatCommands;

class ahbot_commandscript : public CommandScript
{
public:
    ahbot_commandscript(): CommandScript("ahbot_commandscript") {}

    std::vector<ChatCommand> GetCommands() const override
    {
        static std::vector<ChatCommand> ahbotItemsAmountCommandTable =
        {
            { "gray",           rbac::RBAC_PERM_COMMAND_AHBOT_ITEMS_GRAY,   true,  &HandleAHBotItemsAmountQualityCommand<AUCTION_QUALITY_GRAY>,     "" },
            { "white",          rbac::RBAC_PERM_COMMAND_AHBOT_ITEMS_WHITE,  true,  &HandleAHBotItemsAmountQualityCommand<AUCTION_QUALITY_WHITE>,    "" },
            { "green",          rbac::RBAC_PERM_COMMAND_AHBOT_ITEMS_GREEN,  true,  &HandleAHBotItemsAmountQualityCommand<AUCTION_QUALITY_GREEN>,    "" },
            { "blue",           rbac::RBAC_PERM_COMMAND_AHBOT_ITEMS_BLUE,   true,  &HandleAHBotItemsAmountQualityCommand<AUCTION_QUALITY_BLUE>,     "" },
            { "purple",         rbac::RBAC_PERM_COMMAND_AHBOT_ITEMS_PURPLE, true,  &HandleAHBotItemsAmountQualityCommand<AUCTION_QUALITY_PURPLE>,   "" },
            { "orange",         rbac::RBAC_PERM_COMMAND_AHBOT_ITEMS_ORANGE, true,  &HandleAHBotItemsAmountQualityCommand<AUCTION_QUALITY_ORANGE>,   "" },
            { "yellow",         rbac::RBAC_PERM_COMMAND_AHBOT_ITEMS_YELLOW, true,  &HandleAHBotItemsAmountQualityCommand<AUCTION_QUALITY_YELLOW>,   "" },
            { "",               rbac::RBAC_PERM_COMMAND_AHBOT_ITEMS,        true,  &HandleAHBotItemsAmountCommand,                                  "" },
        };

        static std::vector<ChatCommand> ahbotItemsRatioCommandTable =
        {
            { "alliance",       rbac::RBAC_PERM_COMMAND_AHBOT_RATIO_ALLIANCE, true,  &HandleAHBotItemsRatioHouseCommand<AUCTION_HOUSE_ALLIANCE>,    "" },
            { "horde",          rbac::RBAC_PERM_COMMAND_AHBOT_RATIO_HORDE,    true,  &HandleAHBotItemsRatioHouseCommand<AUCTION_HOUSE_HORDE>,       "" },
            { "neutral",        rbac::RBAC_PERM_COMMAND_AHBOT_RATIO_NEUTRAL,  true,  &HandleAHBotItemsRatioHouseCommand<AUCTION_HOUSE_NEUTRAL>,     "" },
            { "",               rbac::RBAC_PERM_COMMAND_AHBOT_RATIO,          true,  &HandleAHBotItemsRatioCommand,                                 "" },
        };

        static std::vector<ChatCommand> ahbotCommandTable =
        {
            { "items",          rbac::RBAC_PERM_COMMAND_AHBOT_ITEMS,    true,   nullptr,                    "", ahbotItemsAmountCommandTable },
            { "ratio",          rbac::RBAC_PERM_COMMAND_AHBOT_RATIO,    true,   nullptr,                    "", ahbotItemsRatioCommandTable },
            { "rebuild",        rbac::RBAC_PERM_COMMAND_AHBOT_REBUILD,  true,   &HandleAHBotRebuildCommand, "" },
            { "reload",         rbac::RBAC_PERM_COMMAND_AHBOT_RELOAD,   true,   &HandleAHBotReloadCommand,  "" },
            { "status",         rbac::RBAC_PERM_COMMAND_AHBOT_STATUS,   true,   &HandleAHBotStatusCommand,  "" },
        };

        static std::vector<ChatCommand> commandTable =
        {
            { "ahbot",          rbac::RBAC_PERM_COMMAND_AHBOT,  false, nullptr,    "", ahbotCommandTable },
        };

        return commandTable;
    }

    static bool HandleAHBotItemsAmountCommand(ChatHandler* handler, std::array<uint32, MAX_AUCTION_QUALITY> items)
    {
        sAuctionBot->SetItemsAmount(items);

        for (AuctionQuality quality : EnumUtils::Iterate<AuctionQuality>())
            handler->PSendSysMessage(LANG_AHBOT_ITEMS_AMOUNT, handler->GetTrinityString(ahbotQualityLangIds.at(quality)), sAuctionBotConfig->GetConfigItemQualityAmount(quality));

        return true;
    }

    template <AuctionQuality Q>
    static bool HandleAHBotItemsAmountQualityCommand(ChatHandler* handler, uint32 amount)
    {
        sAuctionBot->SetItemsAmountForQuality(Q, amount);
        handler->PSendSysMessage(LANG_AHBOT_ITEMS_AMOUNT, handler->GetTrinityString(ahbotQualityLangIds.at(Q)),
            sAuctionBotConfig->GetConfigItemQualityAmount(Q));

        return true;
    }

    static bool HandleAHBotItemsRatioCommand(ChatHandler* handler, uint32 alliance, uint32 horde, uint32 neutral)
    {
        sAuctionBot->SetItemsRatio(alliance, horde, neutral);

        for (AuctionHouseType type : EnumUtils::Iterate<AuctionHouseType>())
            handler->PSendSysMessage(LANG_AHBOT_ITEMS_RATIO, AuctionBotConfig::GetHouseTypeName(type), sAuctionBotConfig->GetConfigItemAmountRatio(type));
        return true;
    }

    template<AuctionHouseType H>
    static bool HandleAHBotItemsRatioHouseCommand(ChatHandler* handler, uint32 ratio)
    {
        sAuctionBot->SetItemsRatioForHouse(H, ratio);
        handler->PSendSysMessage(LANG_AHBOT_ITEMS_RATIO, AuctionBotConfig::GetHouseTypeName(H), sAuctionBotConfig->GetConfigItemAmountRatio(H));
        return true;
    }

    static bool HandleAHBotRebuildCommand(ChatHandler* /*handler*/, Optional<EXACT_SEQUENCE("all")> all)
    {
        sAuctionBot->Rebuild(all.has_value());
        return true;
    }

    static bool HandleAHBotReloadCommand(ChatHandler* handler)
    {
        sAuctionBot->ReloadAllConfig();
        handler->SendSysMessage(LANG_AHBOT_RELOAD_OK);
        return true;
    }

    static bool HandleAHBotStatusCommand(ChatHandler* handler, Optional<EXACT_SEQUENCE("all")> all)
    {
        std::unordered_map<AuctionHouseType, AuctionHouseBotStatusInfoPerType> statusInfo;
        sAuctionBot->PrepareStatusInfos(statusInfo);

        WorldSession* session = handler->GetSession();

        if (!session)
        {
            handler->SendSysMessage(LANG_AHBOT_STATUS_BAR_CONSOLE);
            handler->SendSysMessage(LANG_AHBOT_STATUS_TITLE1_CONSOLE);
            handler->SendSysMessage(LANG_AHBOT_STATUS_MIDBAR_CONSOLE);
        }
        else
            handler->SendSysMessage(LANG_AHBOT_STATUS_TITLE1_CHAT);

        uint32 fmtId = session ? LANG_AHBOT_STATUS_FORMAT_CHAT : LANG_AHBOT_STATUS_FORMAT_CONSOLE;

        handler->PSendSysMessage(fmtId, handler->GetTrinityString(LANG_AHBOT_STATUS_ITEM_COUNT),
            statusInfo[AUCTION_HOUSE_ALLIANCE].ItemsCount,
            statusInfo[AUCTION_HOUSE_HORDE].ItemsCount,
            statusInfo[AUCTION_HOUSE_NEUTRAL].ItemsCount,
            statusInfo[AUCTION_HOUSE_ALLIANCE].ItemsCount +
            statusInfo[AUCTION_HOUSE_HORDE].ItemsCount +
            statusInfo[AUCTION_HOUSE_NEUTRAL].ItemsCount);

        if (all)
        {
            handler->PSendSysMessage(fmtId, handler->GetTrinityString(LANG_AHBOT_STATUS_ITEM_RATIO),
                sAuctionBotConfig->GetConfig(CONFIG_AHBOT_ALLIANCE_ITEM_AMOUNT_RATIO),
                sAuctionBotConfig->GetConfig(CONFIG_AHBOT_HORDE_ITEM_AMOUNT_RATIO),
                sAuctionBotConfig->GetConfig(CONFIG_AHBOT_NEUTRAL_ITEM_AMOUNT_RATIO),
                sAuctionBotConfig->GetConfig(CONFIG_AHBOT_ALLIANCE_ITEM_AMOUNT_RATIO) +
                sAuctionBotConfig->GetConfig(CONFIG_AHBOT_HORDE_ITEM_AMOUNT_RATIO) +
                sAuctionBotConfig->GetConfig(CONFIG_AHBOT_NEUTRAL_ITEM_AMOUNT_RATIO));

            if (!session)
            {
                handler->SendSysMessage(LANG_AHBOT_STATUS_BAR_CONSOLE);
                handler->SendSysMessage(LANG_AHBOT_STATUS_TITLE2_CONSOLE);
                handler->SendSysMessage(LANG_AHBOT_STATUS_MIDBAR_CONSOLE);
            }
            else
                handler->SendSysMessage(LANG_AHBOT_STATUS_TITLE2_CHAT);

            for (AuctionQuality quality : EnumUtils::Iterate<AuctionQuality>())
                handler->PSendSysMessage(fmtId, handler->GetTrinityString(ahbotQualityLangIds.at(quality)),
                    statusInfo[AUCTION_HOUSE_ALLIANCE].QualityInfo.at(quality),
                    statusInfo[AUCTION_HOUSE_HORDE].QualityInfo.at(quality),
                    statusInfo[AUCTION_HOUSE_NEUTRAL].QualityInfo.at(quality),
                    sAuctionBotConfig->GetConfigItemQualityAmount(quality));
        }

        if (!session)
            handler->SendSysMessage(LANG_AHBOT_STATUS_BAR_CONSOLE);

        return true;
    }

};

template bool ahbot_commandscript::HandleAHBotItemsAmountQualityCommand<AUCTION_QUALITY_GRAY>(ChatHandler* handler, uint32 amount);
template bool ahbot_commandscript::HandleAHBotItemsAmountQualityCommand<AUCTION_QUALITY_WHITE>(ChatHandler* handler, uint32 amount);
template bool ahbot_commandscript::HandleAHBotItemsAmountQualityCommand<AUCTION_QUALITY_GREEN>(ChatHandler* handler, uint32 amount);
template bool ahbot_commandscript::HandleAHBotItemsAmountQualityCommand<AUCTION_QUALITY_BLUE>(ChatHandler* handler, uint32 amount);
template bool ahbot_commandscript::HandleAHBotItemsAmountQualityCommand<AUCTION_QUALITY_PURPLE>(ChatHandler* handler, uint32 amount);
template bool ahbot_commandscript::HandleAHBotItemsAmountQualityCommand<AUCTION_QUALITY_ORANGE>(ChatHandler* handler, uint32 amount);
template bool ahbot_commandscript::HandleAHBotItemsAmountQualityCommand<AUCTION_QUALITY_YELLOW>(ChatHandler* handler, uint32 amount);

template bool ahbot_commandscript::HandleAHBotItemsRatioHouseCommand<AUCTION_HOUSE_ALLIANCE>(ChatHandler* handler, uint32 ratio);
template bool ahbot_commandscript::HandleAHBotItemsRatioHouseCommand<AUCTION_HOUSE_HORDE>(ChatHandler* handler, uint32 ratio);
template bool ahbot_commandscript::HandleAHBotItemsRatioHouseCommand<AUCTION_HOUSE_NEUTRAL>(ChatHandler* handler, uint32 ratio);

void AddSC_ahbot_commandscript()
{
    new ahbot_commandscript();
}
