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

#include "Battleground.h"
#include "Chat.h"
#include "Language.h"
#include "Player.h"
#include "RBAC.h"
#include "ScriptMgr.h"

using namespace Trinity::ChatCommands;

class bg_commandscript : public CommandScript
{
public:
    bg_commandscript() : CommandScript("bg_commandscript") { }

    ChatCommandTable GetCommands() const override
    {
        static ChatCommandTable commandTable =
        {
            { "bg start",   HandleBgStartCommand,   LANG_COMMAND_BG_START_HELP, rbac::RBAC_PERM_COMMAND_BG_START,   Console::No },
            { "bg stop",    HandleBgStopCommand,    LANG_COMMAND_BG_STOP_HELP,  rbac::RBAC_PERM_COMMAND_BG_STOP,    Console::No }
        };
        return commandTable;
    }

    static bool HandleBgStartCommand(ChatHandler* handler)
    {
        Battleground* bg = handler->GetPlayer()->GetBattleground();
        if (!bg)
        {
            handler->SendSysMessage(LANG_COMMAND_NO_BATTLEGROUND_FOUND);
            handler->SetSentErrorMessage(true);
            return false;
        }

        bg->SetStartDelayTime(0);

        return true;
    }

    static bool HandleBgStopCommand(ChatHandler* handler)
    {
        Battleground* bg = handler->GetPlayer()->GetBattleground();
        if (!bg)
        {
            handler->SendSysMessage(LANG_COMMAND_NO_BATTLEGROUND_FOUND);
            handler->SetSentErrorMessage(true);
            return false;
        }

        bg->EndBattleground(0);

        return true;
    }
};

void AddSC_bg_commandscript()
{
    new bg_commandscript();
}
