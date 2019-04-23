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

/* ScriptData
Name: achievement_commandscript
%Complete: 100
Comment: All achievement related commands
Category: commandscripts
EndScriptData */

#include "ScriptMgr.h"
#include "AchievementMgr.h"
#include "Chat.h"
#include "ClassHall.h"
#include "DB2Stores.h"
#include "Garrison.h"
#include "GarrisonMgr.h"
#include "Language.h"
#include "Player.h"
#include "RBAC.h"
#include "WodGarrison.h"

class garrison_commandscript : public CommandScript
{
public:
    garrison_commandscript() : CommandScript("garrison_commandscript") { }

    std::vector<ChatCommand> GetCommands() const override
    {
        static std::vector<ChatCommand> garrisonFollowerCommandTable =
        {
            { "add", rbac::RBAC_PERM_COMMAND_ACHIEVEMENT_ADD,       false, &HandleGarrisonFollowerAddCommand,   "" },
        };
        static std::vector<ChatCommand> garrisonMissionCommandTable =
        {
            { "add", rbac::RBAC_PERM_COMMAND_ACHIEVEMENT_ADD,       false, &HandleGarrisonMissionAddCommand,    "" },
        };
        static std::vector<ChatCommand> garrisonCommandTable =
        {
            { "follower", rbac::RBAC_PERM_COMMAND_ACHIEVEMENT,      false, NULL, "", garrisonFollowerCommandTable },
            { "mission",  rbac::RBAC_PERM_COMMAND_ACHIEVEMENT,      false, NULL, "", garrisonMissionCommandTable },
        };
        static std::vector<ChatCommand> commandTable =
        {
            { "garrison", rbac::RBAC_PERM_COMMAND_ACHIEVEMENT,      false, NULL, "", garrisonCommandTable },
        };
        return commandTable;
    }

    static bool HandleGarrisonFollowerAddCommand(ChatHandler* handler, char const* args)
    {
        if (!*args)
            return false;

        Player* target = handler->getSelectedPlayerOrSelf();
        if (!target)
        {
            handler->SendSysMessage(LANG_NO_CHAR_SELECTED);
            handler->SetSentErrorMessage(true);
            return false;
        }

        uint32 followerId = atoi((char*)args);
        target->AddGarrisonFollower(followerId);
        return true;
    }

    static bool HandleGarrisonMissionAddCommand(ChatHandler* handler, char const* args)
    {
        if (!*args)
            return false;

        Player* target = handler->getSelectedPlayerOrSelf();
        if (!target)
        {
            handler->SendSysMessage(LANG_NO_CHAR_SELECTED);
            handler->SetSentErrorMessage(true);
            return false;
        }

        uint32 missionId = atoi((char*)args);
        target->AddGarrisonMission(missionId);
        return true;
    }
};

void AddSC_garrison_commandscript()
{
    new garrison_commandscript();
}
