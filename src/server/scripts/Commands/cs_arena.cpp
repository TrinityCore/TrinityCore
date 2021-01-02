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
Name: arena_commandscript
%Complete: 100
Comment: All arena team related commands
Category: commandscripts
EndScriptData */

#include "ScriptMgr.h"
#include "ArenaTeamMgr.h"
#include "CharacterCache.h"
#include "Chat.h"
#include "Language.h"
#include "Log.h"
#include "ObjectMgr.h"
#include "Player.h"
#include "RBAC.h"
#include "WorldSession.h"

using namespace Trinity::ChatCommands;

class arena_commandscript : public CommandScript
{
public:
    arena_commandscript() : CommandScript("arena_commandscript") { }

    ChatCommandTable GetCommands() const override
    {
        static ChatCommandTable arenaCommandTable =
        {
            { "create",         HandleArenaCreateCommand,   rbac::RBAC_PERM_COMMAND_ARENA_CREATE,  Console::Yes },
            { "disband",        HandleArenaDisbandCommand,  rbac::RBAC_PERM_COMMAND_ARENA_DISBAND, Console::Yes },
            { "rename",         HandleArenaRenameCommand,   rbac::RBAC_PERM_COMMAND_ARENA_RENAME,  Console::Yes },
            { "captain",        HandleArenaCaptainCommand,  rbac::RBAC_PERM_COMMAND_ARENA_CAPTAIN, Console::No },
            { "info",           HandleArenaInfoCommand,     rbac::RBAC_PERM_COMMAND_ARENA_INFO,    Console::Yes },
            { "lookup",         HandleArenaLookupCommand,   rbac::RBAC_PERM_COMMAND_ARENA_LOOKUP,  Console::No },
        };
        static ChatCommandTable commandTable =
        {
            { "arena", arenaCommandTable },
        };
        return commandTable;
    }

    static bool HandleArenaCreateCommand(ChatHandler* handler, Optional<PlayerIdentifier> captain, QuotedString name, ArenaTeamTypes type)
    {
        if (sArenaTeamMgr->GetArenaTeamByName(name))
        {
            handler->PSendSysMessage(LANG_ARENA_ERROR_NAME_EXISTS, name);
            handler->SetSentErrorMessage(true);
            return false;
        }

        if (!captain)
            captain = PlayerIdentifier::FromTargetOrSelf(handler);
        if (!captain)
            return false;

        if (sCharacterCache->GetCharacterArenaTeamIdByGuid(captain->GetGUID(), type) != 0)
        {
            handler->PSendSysMessage(LANG_ARENA_ERROR_SIZE, captain->GetName().c_str());
            handler->SetSentErrorMessage(true);
            return false;
        }

        ArenaTeam* arena = new ArenaTeam();

        if (!arena->Create(captain->GetGUID(), type, name, 4293102085, 101, 4293253939, 4, 4284049911))
        {
            delete arena;
            handler->SendSysMessage(LANG_BAD_VALUE);
            handler->SetSentErrorMessage(true);
            return false;
        }

        sArenaTeamMgr->AddArenaTeam(arena);
        handler->PSendSysMessage(LANG_ARENA_CREATE, arena->GetName().c_str(), arena->GetId(), arena->GetType(), arena->GetCaptain().GetCounter());

        return true;
    }

    static bool HandleArenaDisbandCommand(ChatHandler* handler, uint32 teamId)
    {
        ArenaTeam* arena = sArenaTeamMgr->GetArenaTeamById(teamId);

        if (!arena)
        {
            handler->PSendSysMessage(LANG_ARENA_ERROR_NOT_FOUND, teamId);
            handler->SetSentErrorMessage(true);
            return false;
        }

        if (arena->IsFighting())
        {
            handler->SendSysMessage(LANG_ARENA_ERROR_COMBAT);
            handler->SetSentErrorMessage(true);
            return false;
        }

        std::string name = arena->GetName();
        arena->Disband();
        delete arena;

        handler->PSendSysMessage(LANG_ARENA_DISBAND, name.c_str(), teamId);
        return true;
    }

    static bool HandleArenaRenameCommand(ChatHandler* handler, QuotedString oldName, QuotedString newName)
    {
        ArenaTeam* arena = sArenaTeamMgr->GetArenaTeamByName(oldName);
        if (!arena)
        {
            handler->PSendSysMessage(LANG_ARENA_ERROR_NAME_NOT_FOUND, oldName.c_str());
            handler->SetSentErrorMessage(true);
            return false;
        }

        if (sArenaTeamMgr->GetArenaTeamByName(newName))
        {
            handler->PSendSysMessage(LANG_ARENA_ERROR_NAME_EXISTS, newName.c_str());
            handler->SetSentErrorMessage(true);
            return false;
        }

        if (arena->IsFighting())
        {
            handler->SendSysMessage(LANG_ARENA_ERROR_COMBAT);
            handler->SetSentErrorMessage(true);
            return false;
        }

        if (arena->SetName(newName))
        {
            handler->PSendSysMessage(LANG_ARENA_RENAME, arena->GetId(), oldName.c_str(), newName.c_str());
            return true;
        }
        else
        {
            handler->SendSysMessage(LANG_BAD_VALUE);
            handler->SetSentErrorMessage(true);
            return false;
        }
    }

    static bool HandleArenaCaptainCommand(ChatHandler* handler, uint32 teamId, Optional<PlayerIdentifier> target)
    {
        ArenaTeam* arena = sArenaTeamMgr->GetArenaTeamById(teamId);
        if (!arena)
        {
            handler->PSendSysMessage(LANG_ARENA_ERROR_NOT_FOUND, teamId);
            handler->SetSentErrorMessage(true);
            return false;
        }

        if (arena->IsFighting())
        {
            handler->SendSysMessage(LANG_ARENA_ERROR_COMBAT);
            handler->SetSentErrorMessage(true);
            return false;
        }

        if (!target)
            target = PlayerIdentifier::FromTargetOrSelf(handler);
        if (!target)
            return false;

        if (!arena->IsMember(target->GetGUID()))
        {
            handler->PSendSysMessage(LANG_ARENA_ERROR_NOT_MEMBER, target->GetName().c_str(), arena->GetName().c_str());
            handler->SetSentErrorMessage(true);
            return false;
        }

        if (arena->GetCaptain() == target->GetGUID())
        {
            handler->PSendSysMessage(LANG_ARENA_ERROR_CAPTAIN, target->GetName().c_str(), arena->GetName().c_str());
            handler->SetSentErrorMessage(true);
            return false;
        }

        CharacterCacheEntry const* oldCaptainNameData = sCharacterCache->GetCharacterCacheByGuid(arena->GetCaptain());
        char const* oldCaptainName = oldCaptainNameData ? oldCaptainNameData->Name.c_str() : "<unknown>";

        arena->SetCaptain(target->GetGUID());
        handler->PSendSysMessage(LANG_ARENA_CAPTAIN, arena->GetName().c_str(), arena->GetId(), oldCaptainName, target->GetName().c_str());

        return true;
    }

    static bool HandleArenaInfoCommand(ChatHandler* handler, uint32 teamId)
    {
        ArenaTeam* arena = sArenaTeamMgr->GetArenaTeamById(teamId);

        if (!arena)
        {
            handler->PSendSysMessage(LANG_ARENA_ERROR_NOT_FOUND, teamId);
            handler->SetSentErrorMessage(true);
            return false;
        }

        handler->PSendSysMessage(LANG_ARENA_INFO_HEADER, arena->GetName().c_str(), arena->GetId(), arena->GetRating(), arena->GetType(), arena->GetType());
        for (ArenaTeam::MemberList::iterator itr = arena->m_membersBegin(); itr != arena->m_membersEnd(); ++itr)
            handler->PSendSysMessage(LANG_ARENA_INFO_MEMBERS, itr->Name.c_str(), itr->Guid.GetCounter(), itr->PersonalRating, (arena->GetCaptain() == itr->Guid ? "- Captain" : ""));

        return true;
    }

    static bool HandleArenaLookupCommand(ChatHandler* handler, Tail needle)
    {
        if (needle.empty())
            return false;

        bool found = false;
        for (auto [teamId, team] : sArenaTeamMgr->GetArenaTeams())
        {
            if (StringContainsStringI(team->GetName(), needle))
            {
                if (handler->GetSession())
                {
                    handler->PSendSysMessage(LANG_ARENA_LOOKUP, team->GetName().c_str(), team->GetId(), team->GetType(), team->GetType());
                    found = true;
                    continue;
                }
             }
        }

        if (!found)
            handler->PSendSysMessage(LANG_ARENA_ERROR_NAME_NOT_FOUND, std::string(needle).c_str());

        return true;
    }
};

void AddSC_arena_commandscript()
{
    new arena_commandscript();
}
