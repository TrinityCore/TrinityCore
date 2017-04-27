/*
 * Copyright (C) 2008-2017 TrinityCore <http://www.trinitycore.org/>
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
#include "RelayHandler.h"

class relay_commandscript : public CommandScript
{
public:
    relay_commandscript() : CommandScript("relay_commandscript") { }

    std::vector<ChatCommand> GetCommands() const override
    {
        static std::vector<ChatCommand> RelayCommandTable =
        {
            { "send", 0, true, &HandleRelaySendCommand, "" },
        };

        static std::vector<ChatCommand> commandTable =
        {
            { "relayhandler", 0, true, nullptr, "", RelayCommandTable },
        };
        return commandTable;
    }

    static bool HandleRelaySendCommand(ChatHandler* /*handler*/, char const* args)
    {
        sRelayHandler->Send(args);
        return true;
    }
};

void AddSC_relay_commandscript()
{
    new relay_commandscript();
}
