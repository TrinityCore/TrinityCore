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

/* ScriptData
Name: bf_commandscript
%Complete: 100
Comment: All bf related commands
Category: commandscripts
EndScriptData */

#include "ScriptMgr.h"
#include "Battlefield.h"
#include "BattlefieldMgr.h"
#include "Chat.h"
#include "Language.h"
#include "RBAC.h"

class bf_commandscript : public CommandScript
{
public:
    bf_commandscript() : CommandScript("bf_commandscript") { }

    static std::string GetBattleIdString(BattlefieldId battleId)
    {
        switch (battleId)
        {
            case BATTLEFIELD_BATTLEID_WINTERGRASP:
                return "Wintergrasp";
            default:
                return "";
        }
    }

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

    static bool HandleBattlefieldStart(ChatHandler* handler, char const* args)
    {
        if (!*args)
            return false;

        char* battleidstr = strtok((char*)args, " ");
        if (!battleidstr)
            return false;

        uint32 battlearg = atoul(battleidstr);
        if (battlearg == 0 || battlearg >= BATTLEFIELD_BATTLEID_MAX)
        {
            handler->PSendSysMessage(LANG_COMMAND_BF_INCORRECT_ID);
            return true;
        }

        BattlefieldId battleId = BattlefieldId(battlearg);
        Battlefield* battlefield = sBattlefieldMgr->GetBattlefield(battleId);
        if (!battlefield)
            return true;

        if (!battlefield->IsEnabled())
        {
            handler->PSendSysMessage(LANG_COMMAND_BF_DISABLED, GetBattleIdString(battleId));
            return true;
        }

        if (battlefield->IsWarTime())
        {
            handler->PSendSysMessage(LANG_COMMAND_BF_ACTIVE, GetBattleIdString(battleId));
            return true;
        }

        battlefield->StartBattle();
        handler->PSendSysMessage(LANG_COMMAND_BF_START, GetBattleIdString(battleId));
        return true;
    }

    static bool HandleBattlefieldEnd(ChatHandler* handler, char const* args)
    {
        if (!*args)
            return false;

        char* battleidstr = strtok((char*)args, " ");
        if (!battleidstr)
            return false;

        uint32 battlearg = atoul(battleidstr);
        if (battlearg == 0 || battlearg >= BATTLEFIELD_BATTLEID_MAX)
        {
            handler->PSendSysMessage(LANG_COMMAND_BF_INCORRECT_ID);
            return true;
        }

        BattlefieldId battleId = BattlefieldId(battlearg);
        Battlefield* battlefield = sBattlefieldMgr->GetBattlefield(battleId);
        if (!battlefield)
            return true;

        if (!battlefield->IsEnabled())
        {
            handler->PSendSysMessage(LANG_COMMAND_BF_DISABLED, GetBattleIdString(battleId));
            return true;
        }

        if (!battlefield->IsWarTime())
        {
            handler->PSendSysMessage(LANG_COMMAND_BF_ALREADY_STOPPED, GetBattleIdString(battleId));
            return true;
        }

        battlefield->EndBattle(true);
        handler->PSendSysMessage(LANG_COMMAND_BF_STOP, GetBattleIdString(battleId));
        return true;
    }

    static bool HandleBattlefieldEnable(ChatHandler* handler, char const* args)
    {
        if (!*args)
            return false;

        char* battleidstr = strtok((char*)args, " ");
        if (!battleidstr)
            return false;

        uint32 battlearg = atoul(battleidstr);
        if (battlearg == 0 || battlearg >= BATTLEFIELD_BATTLEID_MAX)
        {
            handler->PSendSysMessage(LANG_COMMAND_BF_INCORRECT_ID);
            return true;
        }

        BattlefieldId battleId = BattlefieldId(battlearg);
        Battlefield* battlefield = sBattlefieldMgr->GetBattlefield(battleId);
        if (!battlefield)
            return true;

        if (battlefield->IsEnabled())
        {
            battlefield->ToggleBattlefield(false);
            handler->PSendSysMessage(LANG_COMMAND_BF_DISABLE, GetBattleIdString(battleId));
        }
        else
        {
            battlefield->ToggleBattlefield(true);
            handler->PSendSysMessage(LANG_COMMAND_BF_ENABLE, GetBattleIdString(battleId));
        }
        return true;
    }

    static bool HandleBattlefieldSwitch(ChatHandler* handler, char const* args)
    {
        if (!*args)
            return false;

        char* battleidstr = strtok((char*)args, " ");
        if (!battleidstr)
            return false;

        uint32 battlearg = atoul(battleidstr);
        if (battlearg == 0 || battlearg >= BATTLEFIELD_BATTLEID_MAX)
        {
            handler->PSendSysMessage(LANG_COMMAND_BF_INCORRECT_ID);
            return true;
        }

        BattlefieldId battleId = BattlefieldId(battlearg);
        Battlefield* battlefield = sBattlefieldMgr->GetBattlefield(battleId);
        if (!battlefield)
            return true;

        if (battlefield->IsWarTime())
        {
            handler->PSendSysMessage(LANG_COMMAND_BF_ACTIVE, GetBattleIdString(battleId));
            return true;
        }

        battlefield->EndBattle(false);
        handler->PSendSysMessage(LANG_COMMAND_BF_SWITCH, GetBattleIdString(battleId));
        return true;
    }

    static bool HandleBattlefieldTimer(ChatHandler* handler, char const* args)
    {
        if (!*args)
            return false;

        char* battleidstr = strtok((char*)args, " ");
        if (!battleidstr)
            return false;

        char* timestr = strtok(nullptr, " ");
        if (!timestr)
            return false;

        uint32 battlearg = atoul(battleidstr);
        if (battlearg == 0 || battlearg >= BATTLEFIELD_BATTLEID_MAX)
        {
            handler->PSendSysMessage(LANG_COMMAND_BF_INCORRECT_ID);
            return true;
        }

        BattlefieldId battleId = BattlefieldId(battlearg);
        Battlefield* battlefield = sBattlefieldMgr->GetBattlefield(battleId);
        if (!battlefield)
            return true;

        if (!battlefield->IsEnabled())
        {
            handler->PSendSysMessage(LANG_COMMAND_BF_DISABLED, GetBattleIdString(battleId));
            return true;
        }

        uint32 time = atoul(timestr);
        battlefield->SetTimer(time * IN_MILLISECONDS);
        battlefield->SendInitWorldStatesToAll();
        handler->PSendSysMessage(LANG_COMMAND_BF_TIMER, GetBattleIdString(battleId), time, battlefield->IsWarTime() ? "war time" : "no war time");
        return true;
    }
};

void AddSC_bf_commandscript()
{
    new bf_commandscript();
}
