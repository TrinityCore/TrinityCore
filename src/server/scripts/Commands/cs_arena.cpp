/*
 * Copyright (C) 2008-2018 TrinityCore <https://www.trinitycore.org/>
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
Name: arena_commandscript
%Complete: 100
Comment: All arena team related commands
Category: commandscripts
EndScriptData */

#include "ScriptMgr.h"
#include "Chat.h"
#include "Language.h"
#include "Log.h"
#include "ObjectMgr.h"
#include "Player.h"
#include "RBAC.h"
#include "WorldSession.h"

class arena_commandscript : public CommandScript
{
public:
    arena_commandscript() : CommandScript("arena_commandscript") { }

    std::vector<ChatCommand> GetCommands() const override
    {
        static std::vector<ChatCommand> arenaCommandTable =
        {
            { "end",            rbac::RBAC_PERM_COMMAND_ARENA,      true,  &HandleEndArenaCommand,          "" },
        };
        static std::vector<ChatCommand> commandTable =
        {
            { "arena",          rbac::RBAC_PERM_COMMAND_ARENA,      false, NULL,         "", arenaCommandTable },
        };
        return commandTable;
    }

    static bool HandleEndArenaCommand(ChatHandler* handler, char const* args)
    {
        CommandArgs cmdArgs = CommandArgs(handler, args, { CommandArgs::ARG_STRING });
        if (!cmdArgs.ValidArgs())
            return false;

        std::string winnerStr = cmdArgs.GetNextArg<std::string>();
        if (winnerStr != "horde" && winnerStr != "alliance"
         && winnerStr != "green" && winnerStr != "gold"
         && winnerStr != "none")
            return false;

        uint32 winner = (winnerStr == "horde" || winnerStr == "green") ? HORDE : (winnerStr != "none" ? ALLIANCE: 0);

        Player* player = handler->getSelectedPlayerOrSelf();
        Battleground* bg = player->GetBattleground();

        if (!bg)
            return false;

        bg->EndBattleground(winner);
        return true;
    }
};

void AddSC_arena_commandscript()
{
    new arena_commandscript();
}
