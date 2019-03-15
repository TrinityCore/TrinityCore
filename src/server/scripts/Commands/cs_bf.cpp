/*
 * Copyright (C) 2008-2019 TrinityCore <https://www.trinitycore.org/>
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
#include "Chat.h"
#include "RBAC.h"

class bf_commandscript : public CommandScript
{
public:
    bf_commandscript() : CommandScript("bf_commandscript") { }

    std::vector<ChatCommand> GetCommands() const override
    {
        static std::vector<ChatCommand> battlefieldcommandTable =
        {
            { "start",          rbac::RBAC_PERM_COMMAND_BF_START,  false, &HandleBattlefieldStart,  "" },
            { "stop",           rbac::RBAC_PERM_COMMAND_BF_STOP,   false, &HandleBattlefieldEnd,    "" },
            { "switch",         rbac::RBAC_PERM_COMMAND_BF_SWITCH, false, &HandleBattlefieldSwitch, "" },
            { "timer",          rbac::RBAC_PERM_COMMAND_BF_TIMER,  false, &HandleBattlefieldTimer,  "" },
            { "enable",         rbac::RBAC_PERM_COMMAND_BF_ENABLE, false, &HandleBattlefieldEnable, "" },
        };
        static std::vector<ChatCommand> commandTable =
        {
            { "bf",             rbac::RBAC_PERM_COMMAND_BF,        false, nullptr,                  "", battlefieldcommandTable },
        };
        return commandTable;
    }

    static bool HandleBattlefieldStart(ChatHandler* /*handler*/, char const* /*args*/)
    {
        return true;
    }

    static bool HandleBattlefieldEnd(ChatHandler* /*handler*/, char const* /*args*/)
    {
        return true;
    }

    static bool HandleBattlefieldEnable(ChatHandler* /*handler*/, char const* /*args*/)
    {
        return true;
    }

    static bool HandleBattlefieldSwitch(ChatHandler* /*handler*/, char const* /*args*/)
    {
        return true;
    }

    static bool HandleBattlefieldTimer(ChatHandler* /*handler*/, char const* /*args*/)
    {
        return true;
    }
};

void AddSC_bf_commandscript()
{
    new bf_commandscript();
}
