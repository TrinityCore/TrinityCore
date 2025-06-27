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

/* ScriptData
Name: bf_commandscript
%Complete: 100
Comment: All bf related commands
Category: commandscripts
EndScriptData */

#include "ScriptMgr.h"
#include "BattlefieldMgr.h"
#include "Chat.h"
#include "RBAC.h"

using namespace Trinity::ChatCommands;

class bf_commandscript : public CommandScript
{
public:
    bf_commandscript() : CommandScript("bf_commandscript") { }

    ChatCommandTable GetCommands() const override
    {
        static ChatCommandTable battlefieldcommandTable =
        {
            { "start",      HandleBattlefieldStart,  rbac::RBAC_PERM_COMMAND_BF_START,  Console::No },
            { "stop",       HandleBattlefieldEnd,    rbac::RBAC_PERM_COMMAND_BF_STOP,   Console::No },
            { "switch",     HandleBattlefieldSwitch, rbac::RBAC_PERM_COMMAND_BF_SWITCH, Console::No },
            { "timer",      HandleBattlefieldTimer,  rbac::RBAC_PERM_COMMAND_BF_TIMER,  Console::No },
            { "enable",     HandleBattlefieldEnable, rbac::RBAC_PERM_COMMAND_BF_ENABLE, Console::No },
        };
        static ChatCommandTable commandTable =
        {
            { "bf", battlefieldcommandTable },
        };
        return commandTable;
    }

    static bool HandleBattlefieldStart(ChatHandler* handler, uint32 battleId)
    {
        Battlefield* bf = sBattlefieldMgr->GetBattlefieldByBattleId(battleId);

        if (!bf)
            return false;

        bf->StartBattle();

        if (battleId == 1)
            handler->SendGlobalGMSysMessage("Wintergrasp (Command start used)");

        return true;
    }

    static bool HandleBattlefieldEnd(ChatHandler* handler, uint32 battleId)
    {
        Battlefield* bf = sBattlefieldMgr->GetBattlefieldByBattleId(battleId);

        if (!bf)
            return false;

        bf->EndBattle(true);

        if (battleId == 1)
            handler->SendGlobalGMSysMessage("Wintergrasp (Command stop used)");

        return true;
    }

    static bool HandleBattlefieldEnable(ChatHandler* handler, uint32 battleId)
    {
        Battlefield* bf = sBattlefieldMgr->GetBattlefieldByBattleId(battleId);

        if (!bf)
            return false;

        if (bf->IsEnabled())
        {
            bf->ToggleBattlefield(false);
            if (battleId == 1)
                handler->SendGlobalGMSysMessage("Wintergrasp is disabled");
        }
        else
        {
            bf->ToggleBattlefield(true);
            if (battleId == 1)
                handler->SendGlobalGMSysMessage("Wintergrasp is enabled");
        }

        return true;
    }

    static bool HandleBattlefieldSwitch(ChatHandler* handler, uint32 battleId)
    {
        Battlefield* bf = sBattlefieldMgr->GetBattlefieldByBattleId(battleId);

        if (!bf)
            return false;

        bf->EndBattle(false);
        if (battleId == 1)
            handler->SendGlobalGMSysMessage("Wintergrasp (Command switch used)");

        return true;
    }

    static bool HandleBattlefieldTimer(ChatHandler* handler, uint32 battleId, uint32 time)
    {
        Battlefield* bf = sBattlefieldMgr->GetBattlefieldByBattleId(battleId);

        if (!bf)
            return false;

        bf->SetTimer(time * IN_MILLISECONDS);
        bf->SendInitWorldStatesToAll();
        if (battleId == 1)
            handler->SendGlobalGMSysMessage("Wintergrasp (Command timer used)");

        return true;
    }
};

void AddSC_bf_commandscript()
{
    new bf_commandscript();
}
