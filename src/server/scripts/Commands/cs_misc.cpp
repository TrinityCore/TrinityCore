/*
 * Copyright (C) 2008-2012 TrinityCore <http://www.trinitycore.org/>
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

#include "ScriptPCH.h"
#include "Chat.h"

class misc_commandscript : public CommandScript
{
public:
    misc_commandscript() : CommandScript("misc_commandscript") { }

    ChatCommand* GetCommands() const
    {
        static ChatCommand commandTable[] =
        {
            { "dev",            SEC_ADMINISTRATOR,  false,  &HandleDevCommand,          "", NULL }, 
            { NULL,             0,                  false,  NULL,                       "", NULL }
        };
        return commandTable;
    }

    static bool HandleDevCommand(ChatHandler* handler, char const* args)
    {
        if (!*args)
        {
            if (handler->GetSession()->GetPlayer()->HasFlag(PLAYER_FLAGS, PLAYER_FLAGS_DEVELOPER))
                handler->GetSession()->SendNotification(LANG_DEV_ON);
            else
                handler->GetSession()->SendNotification(LANG_DEV_OFF);
            return true;
        }

        std::string argstr = (char*)args;

        if (argstr == "on")
        {
            handler->GetSession()->GetPlayer()->SetFlag(PLAYER_FLAGS, PLAYER_FLAGS_DEVELOPER);
            handler->GetSession()->SendNotification(LANG_DEV_ON);
            return true;
        }

        if (argstr == "off")
        {
            handler->GetSession()->GetPlayer()->RemoveFlag(PLAYER_FLAGS, PLAYER_FLAGS_DEVELOPER);
            handler->GetSession()->SendNotification(LANG_DEV_OFF);
            return true;
        }

        handler->SendSysMessage(LANG_USE_BOL);
        handler->SetSentErrorMessage(true);
        return false;
    }
};

void AddSC_misc_commandscript()
{
    new misc_commandscript();
}
