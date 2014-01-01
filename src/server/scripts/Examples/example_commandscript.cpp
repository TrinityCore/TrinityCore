/*
 * Copyright (C) 2008-2014 TrinityCore <http://www.trinitycore.org/>
 * Copyright (C) 2006-2009 ScriptDev2 <https://scriptdev2.svn.sourceforge.net/>
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
Name: Example_Commandscript
%Complete: 100
Comment: Short custom scripting example
Category: Script Examples
EndScriptData */

#include "ScriptMgr.h"
#include "Chat.h"

// **** This script is designed as an example for others to build on ****
// **** Please modify whatever you'd like to as this script is only for developement ****

// **** Script Info* ***
// This script's primary purpose is to show just how much you can really do with commandscripts

class example_commandscript : public CommandScript
{
    public:
        example_commandscript() : CommandScript("example_commandscript") { }

        static bool HandleHelloWorldCommand(ChatHandler* handler, const char* /*args*/)
        {
            handler->PSendSysMessage("Hello World");
            return true;
        }

        ChatCommand* GetCommands() const OVERRIDE
        {
            static ChatCommand HelloWorldCommandTable[] =
            {
                { "hello",          SEC_PLAYER,         true,   &HandleHelloWorldCommand,        "", NULL },
                { NULL,             0,                  false,  NULL,                            "", NULL }
            };
            return HelloWorldCommandTable;
        }
};

void AddSC_example_commandscript()
{
    new example_commandscript();
}
