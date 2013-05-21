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
Name: arena_commandscript
%Complete: 100
Comment: All arena team related commands
Category: commandscripts
EndScriptData */

#include "ObjectMgr.h"
#include "Chat.h"
#include "Language.h"
#include "ArenaTeamMgr.h"
#include "Player.h"
#include "ScriptMgr.h"

class arena_commandscript : public CommandScript
{
public:
    arena_commandscript() : CommandScript("arena_commandscript") { }

    ChatCommand* GetCommands() const
    {
        static ChatCommand arenaCommandTable[] =
        {
            { "create",         SEC_ADMINISTRATOR,  true, &HandleArenaCreateCommand,   "", NULL },
            { "disband",        SEC_ADMINISTRATOR,  true, &HandleArenaDisbandCommand,  "", NULL },
            { "rename",         SEC_ADMINISTRATOR,  true, &HandleArenaRenameCommand,   "", NULL },
            { "captain",        SEC_ADMINISTRATOR,  false, &HandleArenaCaptainCommand,  "", NULL },
            { "info",           SEC_GAMEMASTER,     true, &HandleArenaInfoCommand,     "", NULL },
            { "lookup",         SEC_GAMEMASTER,     false, &HandleArenaLookupCommand,   "", NULL },
            { NULL,             SEC_GAMEMASTER,     false, NULL,                        "", NULL }
        };
        static ChatCommand commandTable[] =
        {
            { "arena",          SEC_GAMEMASTER,     false, NULL,     "",   arenaCommandTable  },
            { NULL,             SEC_PLAYER,         false, NULL,                     "", NULL }
        };
        return commandTable;
    }

    static bool HandleArenaCreateCommand(ChatHandler* handler, char const* args)
    {
        if (!*args)
            return false;

        Player* target;
        if (!handler->extractPlayerTarget(*args != '"' ? (char*)args : NULL, &target))
            return false;

        char* tailStr = *args != '"' ? strtok(NULL, "") : (char*)args;
        if (!tailStr)
            return false;

        char* name = handler->extractQuotedArg(tailStr);
        if (!name)
            return false;
        char* typeStr = strtok(NULL, "");
        if (!typeStr)
            return false;
        int8 type = atoi(typeStr);
        if (sArenaTeamMgr->GetArenaTeamByName(name))
        {
            handler->PSendSysMessage(LANG_ARENA_ERROR_NAME_EXISTS, name);
            handler->SetSentErrorMessage(true);
            return false;
        }
        if (type == 2 || type == 3 || type == 5 )
        {
            if (Player::GetArenaTeamIdFromDB(target->GetGUID(), type) != 0)
            {
                handler->PSendSysMessage(LANG_ARENA_ERROR_SIZE, target->GetName().c_str());
                handler->SetSentErrorMessage(true);
                return false;
            }

            ArenaTeam* Arena = new ArenaTeam();

            if (!Arena->Create(target->GetGUID(), type, name, 4293102085, 101, 4293253939, 4, 4284049911))
            {
                delete Arena;
                handler->SendSysMessage(LANG_BAD_VALUE);
                handler->SetSentErrorMessage(true);
                return false;
            }

            sArenaTeamMgr->AddArenaTeam(Arena);
            handler->PSendSysMessage(LANG_ARENA_CREATE, Arena->GetName().c_str(), Arena->GetId(), Arena->GetType(), Arena->GetCaptain());
        }
        else
        {
            handler->SendSysMessage(LANG_BAD_VALUE);
            handler->SetSentErrorMessage(true);
            return false;
        }
        return true;
    }

    static bool HandleArenaDisbandCommand(ChatHandler* handler, char const* args)
    {
        if (!*args)
            return false;

        uint32 teamid = atoi((char*)args);
        if (!teamid)
            return false;

        ArenaTeam* Arena = sArenaTeamMgr->GetArenaTeamById(teamid);

        if (!Arena)
        {
            handler->PSendSysMessage(LANG_ARENA_ERROR_NOT_FOUND, teamid);
            handler->SetSentErrorMessage(true);
            return false;
        }

        if (Arena->IsFighting())
        {
            handler->SendSysMessage(LANG_ARENA_ERROR_COMBAT);
            handler->SetSentErrorMessage(true);
            return false;
        }
        std::string name = Arena->GetName();
        Arena->Disband();
        if (handler->GetSession())
            TC_LOG_DEBUG(LOG_FILTER_ARENAS, "GameMaster: %s [GUID: %u] disbanded arena team type: %u [Id: %u].", 
                handler->GetSession()->GetPlayer()->GetName().c_str(), handler->GetSession()->GetPlayer()->GetGUIDLow(), Arena->GetType(), teamid);
        else
            TC_LOG_DEBUG(LOG_FILTER_ARENAS, "Console: disbanded arena team type: %u [Id: %u].", Arena->GetType(), teamid);
        delete(Arena);
        handler->PSendSysMessage(LANG_ARENA_DISBAND, name.c_str(), teamid);
        return true;
    }

    static bool HandleArenaRenameCommand(ChatHandler* handler, char const* _args)
    {
        if (!*_args)
            return false;

        char *args = (char *)_args;

        char const* oldArenaStr = handler->extractQuotedArg(args);
        if (!oldArenaStr)
        {
            handler->SendSysMessage(LANG_BAD_VALUE);
            handler->SetSentErrorMessage(true);
            return false;
        }

        char const* newArenaStr = handler->extractQuotedArg(strtok(NULL, ""));
        if (!newArenaStr)
        {
            handler->SendSysMessage(LANG_BAD_VALUE);
            handler->SetSentErrorMessage(true);
            return false;
        }

        ArenaTeam* Arena = sArenaTeamMgr->GetArenaTeamByName(oldArenaStr);
        if (!Arena)
        {
            handler->PSendSysMessage(LANG_AREAN_ERROR_NAME_NOT_FOUND, oldArenaStr);
            handler->SetSentErrorMessage(true);
            return false;
        }

        if (sArenaTeamMgr->GetArenaTeamByName(newArenaStr))
        {
            handler->PSendSysMessage(LANG_ARENA_ERROR_NAME_EXISTS, oldArenaStr);
            handler->SetSentErrorMessage(true);
            return false;
        }

        if (Arena->IsFighting())
        {
            handler->SendSysMessage(LANG_ARENA_ERROR_COMBAT);
            handler->SetSentErrorMessage(true);
            return false;
        }

        if (!Arena->SetName(newArenaStr))
        {
            handler->SendSysMessage(LANG_BAD_VALUE);
            handler->SetSentErrorMessage(true);
            return false;
        }
        handler->PSendSysMessage(LANG_ARENA_RENAME, Arena->GetId(), oldArenaStr, newArenaStr);
        if (handler->GetSession())
            TC_LOG_DEBUG(LOG_FILTER_ARENAS, "GameMaster: %s [GUID: %u] rename arena team \"%s\"[Id: %u] to \"%s\"", 
                handler->GetSession()->GetPlayer()->GetName().c_str(), handler->GetSession()->GetPlayer()->GetGUIDLow(), oldArenaStr, Arena->GetId(), newArenaStr);
        else
            TC_LOG_DEBUG(LOG_FILTER_ARENAS, "Console: rename arena team \"%s\"[Id: %u] to \"%s\"", oldArenaStr, Arena->GetId(), newArenaStr);
        return true;
    }

    static bool HandleArenaCaptainCommand(ChatHandler* handler, char const* args)
    {
        if (!*args)
            return false;

        char* idStr;
        char* nameStr;
        handler->extractOptFirstArg((char*)args, &idStr, &nameStr);
        if (!idStr)
            return false;

        uint32 teamid = atoi(idStr);
        if (!teamid)
            return false;

        Player* target;
        uint64 target_guid;
        if (!handler->extractPlayerTarget(nameStr, &target, &target_guid))
            return false;

        ArenaTeam *Arena = sArenaTeamMgr->GetArenaTeamById(teamid);

        if (!Arena)
        {
            handler->PSendSysMessage(LANG_ARENA_ERROR_NOT_FOUND, teamid);
            handler->SetSentErrorMessage(true);
            return false;
        }

        if (!target)
        {
            handler->PSendSysMessage(LANG_PLAYER_NOT_EXIST_OR_OFFLINE, nameStr);
            handler->SetSentErrorMessage(true);
            return false;
        }

        if (Arena->IsFighting())
        {
            handler->SendSysMessage(LANG_ARENA_ERROR_COMBAT);
            handler->SetSentErrorMessage(true);
            return false;
        }

        if(!Arena->IsMember(target_guid))
        {
            handler->PSendSysMessage(LANG_ARENA_ERROR_NOT_MEMBER, nameStr, Arena->GetName().c_str());
            handler->SetSentErrorMessage(true);
            return false;
        }

        if(Arena->GetCaptain() == target_guid)
        {
            handler->PSendSysMessage(LANG_ARENA_ERROR_CAPTAIN, nameStr, Arena->GetName().c_str());
            handler->SetSentErrorMessage(true);
            return false;
        }

        Player* oldCaptain = sObjectMgr->GetPlayerByLowGUID(Arena->GetCaptain());
        Arena->SetCaptain(target_guid);
        handler->PSendSysMessage(LANG_ARENA_CAPTAIN, Arena->GetName().c_str(), Arena->GetId(), oldCaptain->GetName().c_str(), target->GetName().c_str());
        if (handler->GetSession())
            TC_LOG_DEBUG(LOG_FILTER_ARENAS, "GameMaster: %s [GUID: %u] promoted player: %s [GUID: %u] to leader of arena team \"%s\"[Id: %u]",
                handler->GetSession()->GetPlayer()->GetName().c_str(), handler->GetSession()->GetPlayer()->GetGUIDLow(), target->GetName().c_str(), target->GetGUIDLow(), Arena->GetName().c_str(), Arena->GetId());
        else
            TC_LOG_DEBUG(LOG_FILTER_ARENAS, "Console: promoted player: %s [GUID: %u] to leader of arena team \"%s\"[Id: %u]", 
                target->GetName().c_str(), target->GetGUIDLow(), Arena->GetName().c_str(), Arena->GetId());
        return true;
    }

    static bool HandleArenaInfoCommand(ChatHandler* handler, char const* args)
    {
        if (!*args)
            return false;

        uint32 teamid = atoi((char*)args);
        if (!teamid)
            return false;

        ArenaTeam *Arena = sArenaTeamMgr->GetArenaTeamById(teamid);

        if (!Arena)
        {
            handler->PSendSysMessage(LANG_ARENA_ERROR_NOT_FOUND, teamid);
            handler->SetSentErrorMessage(true);
            return false;
        }

        handler->PSendSysMessage(LANG_ARENA_INFO_HEADER, Arena->GetName().c_str(), Arena->GetId(), Arena->GetRating(), Arena->GetType(), Arena->GetType());
        for (ArenaTeam::MemberList::iterator itr = Arena->m_membersBegin(); itr != Arena->m_membersEnd(); ++itr)
        {
            handler->PSendSysMessage(LANG_ARENA_INFO_MEMBERS, itr->Name.c_str(), GUID_LOPART(itr->Guid), itr->PersonalRating, (Arena->GetCaptain() == itr->Guid ? "- Captain" : ""));
        }
        return true;
    }

    static bool HandleArenaLookupCommand(ChatHandler* handler, char const* args)
    {
        if (!*args)
            return false;

        std::string namepart = args;
        std::wstring wnamepart;

        if (!Utf8toWStr(namepart, wnamepart))
            return false;

        wstrToLower(wnamepart);

        bool found = false;
        ArenaTeamMgr::ArenaTeamContainer::const_iterator i = sArenaTeamMgr->GetArenaTeamMapBegin();
        for (; i != sArenaTeamMgr->GetArenaTeamMapEnd(); ++i)
        {
            ArenaTeam *Arena = i->second;

            if (Utf8FitTo(Arena->GetName(), wnamepart))
            {
                uint32 teamid = Arena->GetId();

                if (handler->GetSession())
                    handler->PSendSysMessage(LANG_ARENA_LOOKUP, Arena->GetName().c_str(), Arena->GetId(), Arena->GetType(), Arena->GetType());

                    if (!found)
                        found = true;

                        continue;
             }
        }

        if (!found)
            handler->PSendSysMessage(LANG_AREAN_ERROR_NAME_NOT_FOUND, namepart.c_str());

        return true;
    }
};

void AddSC_arena_commandscript()
{
    new arena_commandscript();
}
