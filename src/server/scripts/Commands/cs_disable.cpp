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
 
/* ScriptData
Name: disable_commandscript
%Complete: 100
Comment: All disable related commands
Category: commandscripts
EndScriptData */
 
#include "ScriptMgr.h"
#include "ObjectMgr.h"
#include "Chat.h"
#include "DisableMgr.h"
 
class disable_commandscript : public CommandScript
{
public:
    disable_commandscript() : CommandScript("disable_commandscript") { }
 
    ChatCommand* GetCommands() const
    {
 
        static ChatCommand disableCommandTable[] =
        {
            { "spell",          SEC_GAMEMASTER,     false, &HandleDisableSpellCommand,         "", NULL },
            { "map",            SEC_GAMEMASTER,     false, &HandleDisableMapCommand,           "", NULL },
            { "battleground",   SEC_GAMEMASTER,     false, &HandleDisableBattlegroundCommand,  "", NULL },
            { "achievement_criteria", SEC_GAMEMASTER, false, &HandleDisableAchievementCriteriaCommand, "", NULL },
            { "outdoorpvp",     SEC_GAMEMASTER,     false, &HandleDisableOutdoorPvPCommand,    "", NULL },
            { "vmap",           SEC_GAMEMASTER,     false, &HandleDisableVmapCommand,          "", NULL },
            { NULL,             0,                  false, NULL,                               "", NULL }
        };
 
        static ChatCommand commandTable[] =
        {
            { "disable",        SEC_GAMEMASTER,     false, NULL,                "", disableCommandTable },
            { NULL,             0,                  false, NULL,                               "", NULL }
        };
        return commandTable;
    }
 
   
    static void HandleDisables(ChatHandler* handler, char const* args, uint8 disableType)
    {
        char* cEntry = strtok((char*)args, " ");
        if (!cEntry || !atoi(cEntry))
        {
            handler->SendSysMessage("No entry specified.");
            return;
        }
 
        char* cFlags = strtok(NULL, " ");
        if (!cFlags || !atoi(cFlags))
        {
            handler->SendSysMessage("No flags specified.");
            return;
        }
       
        char* cComment = strtok(NULL, "");
        if (!cComment)
        {
            handler->SendSysMessage("No comment specified.");
            return;
        }
 
        std::string entryStr = cEntry;
        std::string disableComment = cComment;
        uint32 entry = (uint32)atoi(cEntry);
        uint8 flags = atoi(cFlags);
 
       
 
        std::string disableTypeStr = "";
 
        switch(disableType)
        {
            case DISABLE_TYPE_SPELL:
                disableTypeStr = "spell";
                break;
            case DISABLE_TYPE_MAP:
                disableTypeStr = "map";
                break;
            case DISABLE_TYPE_BATTLEGROUND:
                disableTypeStr = "battleground";
                break;
            case DISABLE_TYPE_ACHIEVEMENT_CRITERIA:
                disableTypeStr = "achievement criteria";
                break;
            case DISABLE_TYPE_OUTDOORPVP:
                disableTypeStr = "outdoorpvp";
                break;
            case DISABLE_TYPE_VMAP:
                disableTypeStr = "vmap";
                break;
        }
       
        PreparedStatement* stmt = WorldDatabase.GetPreparedStatement(WORLD_SEL_DISABLES);
        stmt->setUInt32(0, entry);
        stmt->setUInt8(1, disableType);  
        PreparedQueryResult result = WorldDatabase.Query(stmt);
       
 
        if (result)
        {
            handler->PSendSysMessage("This %s (id %u) is already disabled.", disableTypeStr.c_str(), entry);
            return;
        }
     
        PreparedStatement* stmt2 = WorldDatabase.GetPreparedStatement(WORLD_INS_DISABLES);
        stmt2->setUInt32(0, entry);
        stmt2->setUInt8(1, disableType);
        stmt->setUInt16(2, flags);
        stmt2->setString(3, disableComment);
        WorldDatabase.Execute(stmt2);
               
        handler->PSendSysMessage("Disabled %s %u for reason %s", disableTypeStr.c_str(), entry, disableComment.c_str());
        return;
       
    }
   
    static bool HandleDisableSpellCommand(ChatHandler* handler, char const* args)
    {
        if (!*args)
            return false;
       
        HandleDisables(handler, args, DISABLE_TYPE_SPELL);
        return true;
    }
 
    static bool HandleDisableMapCommand(ChatHandler* handler, char const* args)
    {
        if (!*args)
            return false;
       
        HandleDisables(handler, args, DISABLE_TYPE_MAP);
        return true;
    }
 
    static bool HandleDisableBattlegroundCommand(ChatHandler* handler, char const* args)
    {
        if (!*args)
            return false;
       
        HandleDisables(handler, args, DISABLE_TYPE_BATTLEGROUND);
        return true;
    }
 
    static bool HandleDisableAchievementCriteriaCommand(ChatHandler* handler, char const* args)
    {
        if (!*args)
            return false;
       
        HandleDisables(handler, args, DISABLE_TYPE_ACHIEVEMENT_CRITERIA);
        return true;
    }
 
    static bool HandleDisableOutdoorPvPCommand(ChatHandler* handler, char const* args)
    {
        if (!*args)
            return false;
       
        HandleDisables(handler, args, DISABLE_TYPE_OUTDOORPVP);
        return true;
    }
 
    static bool HandleDisableVmapCommand(ChatHandler* handler, char const* args)
    {
        if (!*args)
            return false;
       
        HandleDisables(handler, args, DISABLE_TYPE_VMAP);
        return true;
    }
 
};
 
void AddSC_disable_commandscript()
{
    new disable_commandscript();
}