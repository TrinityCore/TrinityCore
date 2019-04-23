/*
 * Copyright (C) 2017-2018 AshamaneProject <https://github.com/AshamaneProject>
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

#include "BlackMarketMgr.h"
#include "ScriptMgr.h"
#include "Chat.h"
#include "Language.h"
#include "Log.h"
#include "ObjectMgr.h"
#include "Player.h"
#include "RBAC.h"
#include "WorldSession.h"

class blackmarket_commandscript : public CommandScript
{
public:
    blackmarket_commandscript() : CommandScript("blackmarket_commandscript") { }

    std::vector<ChatCommand> GetCommands() const override
    {
        static std::vector<ChatCommand> blackmarketCommandTable =
        {
            { "setduration",    rbac::RBAC_PERM_COMMAND_BLACKMARKET_SET_DURATION,   true,  &HandleBMSetAuctionDurationCommand,                  "" },
        };
        static std::vector<ChatCommand> commandTable =
        {
            { "blackmarket",    rbac::RBAC_PERM_COMMAND_BLACKMARKET,                false, nullptr,                    "", blackmarketCommandTable },
        };
        return commandTable;
    }

    static bool HandleBMSetAuctionDurationCommand(ChatHandler* handler, const char* args)
    {
        CommandArgs cmdArgs = CommandArgs(handler, args, { CommandArgs::ARG_UINT, CommandArgs::ARG_UINT });

        if (!cmdArgs.ValidArgs())
            return false;

        uint32 marketId         = cmdArgs.GetArg<uint32>(0);
        uint32 durationSeconds  = cmdArgs.GetArg<uint32>(1);

        if (BlackMarketEntry* entry = sBlackMarketMgr->GetAuctionByID(marketId))
            entry->SetStartTime(durationSeconds + time(nullptr) - sBlackMarketMgr->GetTemplateByID(entry->GetMarketId())->Duration);

        return true;
    }
};

void AddSC_blackmarket_commandscript()
{
    new blackmarket_commandscript();
}
