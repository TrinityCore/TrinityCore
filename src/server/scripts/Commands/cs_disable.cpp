/*
 * Copyright (C) 2008-2013 TrinityCore <http://www.trinitycore.org/>
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

#include "DisableMgr.h"
#include "AchievementMgr.h"
#include "Chat.h"
#include "Language.h"
#include "ObjectMgr.h"
#include "OutdoorPvP.h"
#include "Player.h"
#include "ScriptMgr.h"
#include "SpellMgr.h"

class disable_commandscript : public CommandScript
{
public:
    disable_commandscript() : CommandScript("disable_commandscript") { }

    ChatCommand* GetCommands() const
    {
        static ChatCommand removeDisableCommandTable[] =
        {
            { "spell",                  SEC_ADMINISTRATOR,      true,   &HandleRemoveDisableSpellCommand,               "", NULL },
            { "quest",                  SEC_ADMINISTRATOR,      true,   &HandleRemoveDisableQuestCommand,               "", NULL },
            { "map",                    SEC_ADMINISTRATOR,      true,   &HandleRemoveDisableMapCommand,                 "", NULL },
            { "battleground",           SEC_ADMINISTRATOR,      true,   &HandleRemoveDisableBattlegroundCommand,        "", NULL },
            { "achievement_criteria",   SEC_ADMINISTRATOR,      true,   &HandleRemoveDisableAchievementCriteriaCommand, "", NULL },
            { "outdoorpvp",             SEC_ADMINISTRATOR,      true,   &HandleRemoveDisableOutdoorPvPCommand,          "", NULL },
            { "vmap",                   SEC_ADMINISTRATOR,      true,   &HandleRemoveDisableVmapCommand,                "", NULL },
            { NULL,                     0,                      false,  NULL,                                           "", NULL }
        };
        static ChatCommand addDisableCommandTable[] =
        {
            { "spell",                  SEC_ADMINISTRATOR,      true,   &HandleAddDisableSpellCommand,                  "", NULL },
            { "quest",                  SEC_ADMINISTRATOR,      true,   &HandleAddDisableQuestCommand,                  "", NULL },
            { "map",                    SEC_ADMINISTRATOR,      true,   &HandleAddDisableMapCommand,                    "", NULL },
            { "battleground",           SEC_ADMINISTRATOR,      true,   &HandleAddDisableBattlegroundCommand,           "", NULL },
            { "achievement_criteria",   SEC_ADMINISTRATOR,      true,   &HandleAddDisableAchievementCriteriaCommand,    "", NULL },
            { "outdoorpvp",             SEC_ADMINISTRATOR,      true,   &HandleAddDisableOutdoorPvPCommand,             "", NULL },
            { "vmap",                   SEC_ADMINISTRATOR,      true,   &HandleAddDisableVmapCommand,                   "", NULL },
            { NULL,                     0,                      false,  NULL,                                           "", NULL }
        };
        static ChatCommand disableCommandTable[] =
        {
            { "add",                    SEC_ADMINISTRATOR,      true,   NULL,                                           "", addDisableCommandTable },
            { "remove",                 SEC_ADMINISTRATOR,      true,   NULL,                                           "", removeDisableCommandTable },
            { NULL,                     0,                      false,  NULL,                                           "", NULL }
        };
        static ChatCommand commandTable[] =
        {
            { "disable",                SEC_ADMINISTRATOR,     false,   NULL,                                           "", disableCommandTable },
            { NULL,                     0,                     false,   NULL,                                           "", NULL }
        };
        return commandTable;
    }

    static bool HandleAddDisables(ChatHandler* handler, char const* args, uint8 disableType)
    {
        char* entryStr = strtok((char*)args, " ");
        if (!entryStr || !atoi(entryStr))
            return false;

        char* flagsStr = strtok(NULL, " ");
        uint8 flags = flagsStr ? uint8(atoi(flagsStr)) : 0;

        char* commentStr = strtok(NULL, "");
        if (!commentStr)
            return false;

        std::string disableComment = commentStr;
        uint32 entry = uint32(atoi(entryStr));

        std::string disableTypeStr = "";

        switch (disableType)
        {
            case DISABLE_TYPE_SPELL:
            {
                if (!sSpellMgr->GetSpellInfo(entry))
                {
                    handler->PSendSysMessage(LANG_COMMAND_NOSPELLFOUND);
                    handler->SetSentErrorMessage(true);
                    return false;
                }
                disableTypeStr = "spell";
                break;
            }
            case DISABLE_TYPE_QUEST:
            {
                if (!sObjectMgr->GetQuestTemplate(entry))
                {
                    handler->PSendSysMessage(LANG_COMMAND_QUEST_NOTFOUND, entry);
                    handler->SetSentErrorMessage(true);
                    return false;
                }
                disableTypeStr = "quest";
                break;
            }
            case DISABLE_TYPE_MAP:
            {
                if (!sMapStore.LookupEntry(entry))
                {
                    handler->PSendSysMessage(LANG_COMMAND_NOMAPFOUND);
                    handler->SetSentErrorMessage(true);
                    return false;
                }
                disableTypeStr = "map";
                break;
            }
            case DISABLE_TYPE_BATTLEGROUND:
            {
                if (!sBattlemasterListStore.LookupEntry(entry))
                {
                    handler->PSendSysMessage(LANG_COMMAND_NO_BATTLEGROUND_FOUND);
                    handler->SetSentErrorMessage(true);
                    return false;
                }
                disableTypeStr = "battleground";
                break;
            }
            case DISABLE_TYPE_ACHIEVEMENT_CRITERIA:
            {
                if (!sAchievementMgr->GetAchievementCriteria(entry))
                {
                    handler->PSendSysMessage(LANG_COMMAND_NO_ACHIEVEMENT_CRITERIA_FOUND);
                    handler->SetSentErrorMessage(true);
                    return false;
                }
                disableTypeStr = "achievement criteria";
                break;
            }
            case DISABLE_TYPE_OUTDOORPVP:
            {
                if (entry > MAX_OUTDOORPVP_TYPES)
                {
                    handler->PSendSysMessage(LANG_COMMAND_NO_OUTDOOR_PVP_FORUND);
                    handler->SetSentErrorMessage(true);
                    return false;
                }
                disableTypeStr = "outdoorpvp";
                break;
            }
            case DISABLE_TYPE_VMAP:
            {
                if (!sMapStore.LookupEntry(entry))
                {
                    handler->PSendSysMessage(LANG_COMMAND_NOMAPFOUND);
                    handler->SetSentErrorMessage(true);
                    return false;
                }
                disableTypeStr = "vmap";
                break;
            }
            default:
                break;
        }

        PreparedStatement* stmt = NULL;
        stmt = WorldDatabase.GetPreparedStatement(WORLD_SEL_DISABLES);
        stmt->setUInt32(0, entry);
        stmt->setUInt8(1, disableType);
        PreparedQueryResult result = WorldDatabase.Query(stmt);
        if (result)
        {
            handler->PSendSysMessage("This %s (Id: %u) is already disabled.", disableTypeStr.c_str(), entry);
            handler->SetSentErrorMessage(true);
            return false;
        }

        stmt = WorldDatabase.GetPreparedStatement(WORLD_INS_DISABLES);
        stmt->setUInt32(0, entry);
        stmt->setUInt8(1, disableType);
        stmt->setUInt16(2, flags);
        stmt->setString(3, disableComment);
        WorldDatabase.Execute(stmt);

        handler->PSendSysMessage("Add Disabled %s (Id: %u) for reason %s", disableTypeStr.c_str(), entry, disableComment.c_str());
        return true;
    }

    static bool HandleAddDisableSpellCommand(ChatHandler* handler, char const* args)
    {
        if (!*args)
            return false;

        return HandleAddDisables(handler, args, DISABLE_TYPE_SPELL);
    }

    static bool HandleAddDisableQuestCommand(ChatHandler* handler, char const* args)
    {
        if (!*args)
            return false;

        return HandleAddDisables(handler, args, DISABLE_TYPE_QUEST);
    }

    static bool HandleAddDisableMapCommand(ChatHandler* handler, char const* args)
    {
        if (!*args)
            return false;

        return HandleAddDisables(handler, args, DISABLE_TYPE_MAP);
    }

    static bool HandleAddDisableBattlegroundCommand(ChatHandler* handler, char const* args)
    {
        if (!*args)
            return false;

        return HandleAddDisables(handler, args, DISABLE_TYPE_BATTLEGROUND);
    }

    static bool HandleAddDisableAchievementCriteriaCommand(ChatHandler* handler, char const* args)
    {
        if (!*args)
            return false;

        return HandleAddDisables(handler, args, DISABLE_TYPE_ACHIEVEMENT_CRITERIA);
    }

    static bool HandleAddDisableOutdoorPvPCommand(ChatHandler* handler, char const* args)
    {
        if (!*args)
            return false;

        HandleAddDisables(handler, args, DISABLE_TYPE_OUTDOORPVP);
        return true;
    }

    static bool HandleAddDisableVmapCommand(ChatHandler* handler, char const* args)
    {
        if (!*args)
            return false;

        return HandleAddDisables(handler, args, DISABLE_TYPE_VMAP);
    }

    static bool HandleRemoveDisables(ChatHandler* handler, char const* args, uint8 disableType)
    {
        char* entryStr = strtok((char*)args, " ");
        if (!entryStr || !atoi(entryStr))
            return false;

        uint32 entry = uint32(atoi(entryStr));

        std::string disableTypeStr = "";

        switch (disableType)
        {
            case DISABLE_TYPE_SPELL:
                disableTypeStr = "spell";
                break;
            case DISABLE_TYPE_QUEST:
                disableTypeStr = "quest";
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

        PreparedStatement* stmt = NULL;
        stmt = WorldDatabase.GetPreparedStatement(WORLD_SEL_DISABLES);
        stmt->setUInt32(0, entry);
        stmt->setUInt8(1, disableType);
        PreparedQueryResult result = WorldDatabase.Query(stmt);
        if (!result)
        {
            handler->PSendSysMessage("This %s (Id: %u) is not disabled.", disableTypeStr.c_str(), entry);
            handler->SetSentErrorMessage(true);
            return false;
        }

        stmt = WorldDatabase.GetPreparedStatement(WORLD_DEL_DISABLES);
        stmt->setUInt32(0, entry);
        stmt->setUInt8(1, disableType);
        WorldDatabase.Execute(stmt);

        handler->PSendSysMessage("Remove Disabled %s (Id: %u)", disableTypeStr.c_str(), entry);
        return true;
    }

    static bool HandleRemoveDisableSpellCommand(ChatHandler* handler, char const* args)
    {
        if (!*args)
            return false;

        return HandleRemoveDisables(handler, args, DISABLE_TYPE_SPELL);
    }

    static bool HandleRemoveDisableQuestCommand(ChatHandler* handler, char const* args)
    {
        if (!*args)
            return false;

        return HandleRemoveDisables(handler, args, DISABLE_TYPE_QUEST);
    }

    static bool HandleRemoveDisableMapCommand(ChatHandler* handler, char const* args)
    {
        if (!*args)
            return false;

        return HandleAddDisables(handler, args, DISABLE_TYPE_MAP);
    }

    static bool HandleRemoveDisableBattlegroundCommand(ChatHandler* handler, char const* args)
    {
        if (!*args)
            return false;

        return HandleRemoveDisables(handler, args, DISABLE_TYPE_BATTLEGROUND);
    }

    static bool HandleRemoveDisableAchievementCriteriaCommand(ChatHandler* handler, char const* args)
    {
        if (!*args)
            return false;

        return HandleRemoveDisables(handler, args, DISABLE_TYPE_ACHIEVEMENT_CRITERIA);
    }

    static bool HandleRemoveDisableOutdoorPvPCommand(ChatHandler* handler, char const* args)
    {
        if (!*args)
            return false;

        return HandleRemoveDisables(handler, args, DISABLE_TYPE_OUTDOORPVP);
    }

    static bool HandleRemoveDisableVmapCommand(ChatHandler* handler, char const* args)
    {
        if (!*args)
            return false;

        return HandleRemoveDisables(handler, args, DISABLE_TYPE_VMAP);
    }
};

void AddSC_disable_commandscript()
{
    new disable_commandscript();
}
