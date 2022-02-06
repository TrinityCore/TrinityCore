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
Name: guild_commandscript
%Complete: 100
Comment: All guild related commands
Category: commandscripts
EndScriptData */

#include "ScriptMgr.h"
#include "AchievementMgr.h"
#include "CharacterCache.h"
#include "Chat.h"
#include "Guild.h"
#include "GuildMgr.h"
#include "Language.h"
#include "ObjectAccessor.h"
#include "ObjectMgr.h"
#include "Player.h"
#include "RBAC.h"
#include <iomanip>

using namespace Trinity::ChatCommands;
class guild_commandscript : public CommandScript
{
public:
    guild_commandscript() : CommandScript("guild_commandscript") { }

    std::vector<ChatCommand> GetCommands() const override
    {
        static std::vector<ChatCommand> guildCommandTable =
        {
            { "create",   rbac::RBAC_PERM_COMMAND_GUILD_CREATE,   true, &HandleGuildCreateCommand,           "" },
            { "delete",   rbac::RBAC_PERM_COMMAND_GUILD_DELETE,   true, &HandleGuildDeleteCommand,           "" },
            { "invite",   rbac::RBAC_PERM_COMMAND_GUILD_INVITE,   true, &HandleGuildInviteCommand,           "" },
            { "uninvite", rbac::RBAC_PERM_COMMAND_GUILD_UNINVITE, true, &HandleGuildUninviteCommand,         "" },
            { "rank",     rbac::RBAC_PERM_COMMAND_GUILD_RANK,     true, &HandleGuildRankCommand,             "" },
            { "rename",   rbac::RBAC_PERM_COMMAND_GUILD_RENAME,   true, &HandleGuildRenameCommand,           "" },
            { "info",     rbac::RBAC_PERM_COMMAND_GUILD_INFO,     true, &HandleGuildInfoCommand,             "" },
        };
        static std::vector<ChatCommand> commandTable =
        {
            { "guild", rbac::RBAC_PERM_COMMAND_GUILD,  true, nullptr, "", guildCommandTable },
        };
        return commandTable;
    }

    /** \brief GM command level 3 - Create a guild.
     *
     * This command allows a GM (level 3) to create a guild.
     *
     * The "args" parameter contains the name of the guild leader
     * and then the name of the guild.
     *
     */
    static bool HandleGuildCreateCommand(ChatHandler* handler, char const* args)
    {
        if (!*args)
            return false;

        // if not guild name only (in "") then player name
        Player* target;
        if (!handler->extractPlayerTarget(*args != '"' ? (char*)args : nullptr, &target))
            return false;

        char* tailStr = *args != '"' ? strtok(nullptr, "") : (char*)args;
        if (!tailStr)
            return false;

        char* guildStr = handler->extractQuotedArg(tailStr);
        if (!guildStr)
            return false;

        std::string guildName = guildStr;

        if (target->GetGuildId())
        {
            handler->SendSysMessage(LANG_PLAYER_IN_GUILD);
            handler->SetSentErrorMessage(true);
            return false;
        }

        if (sGuildMgr->GetGuildByName(guildName))
        {
            handler->SendSysMessage(LANG_GUILD_RENAME_ALREADY_EXISTS);
            handler->SetSentErrorMessage(true);
            return false;
        }

        if (sObjectMgr->IsReservedName(guildName) || !sObjectMgr->IsValidCharterName(guildName))
        {
            handler->SendSysMessage(LANG_BAD_VALUE);
            handler->SetSentErrorMessage(true);
            return false;
        }

        Guild* guild = new Guild;
        if (!guild->Create(target, guildName))
        {
            delete guild;
            handler->SendSysMessage(LANG_GUILD_NOT_CREATED);
            handler->SetSentErrorMessage(true);
            return false;
        }

        sGuildMgr->AddGuild(guild);

        return true;
    }

    static bool HandleGuildDeleteCommand(ChatHandler* handler, char const* args)
    {
        if (!*args)
            return false;

        char* guildStr = handler->extractQuotedArg((char*)args);
        if (!guildStr)
            return false;

        std::string guildName = guildStr;

        Guild* targetGuild = sGuildMgr->GetGuildByName(guildName);
        if (!targetGuild)
            return false;

        targetGuild->Disband();
        delete targetGuild;

        return true;
    }

    static bool HandleGuildInviteCommand(ChatHandler* handler, char const* args)
    {
        if (!*args)
            return false;

        // if not guild name only (in "") then player name
        ObjectGuid targetGuid;
        if (!handler->extractPlayerTarget(*args != '"' ? (char*)args : nullptr, nullptr, &targetGuid))
            return false;

        char* tailStr = *args != '"' ? strtok(nullptr, "") : (char*)args;
        if (!tailStr)
            return false;

        char* guildStr = handler->extractQuotedArg(tailStr);
        if (!guildStr)
            return false;

        std::string guildName = guildStr;
        Guild* targetGuild = sGuildMgr->GetGuildByName(guildName);
        if (!targetGuild)
            return false;

        // player's guild membership checked in AddMember before add
        CharacterDatabaseTransaction trans(nullptr);
        return targetGuild->AddMember(trans, targetGuid);
    }

    static bool HandleGuildUninviteCommand(ChatHandler* handler, char const* args)
    {
        Player* target;
        ObjectGuid targetGuid;
        if (!handler->extractPlayerTarget((char*)args, &target, &targetGuid))
            return false;

        ObjectGuid::LowType guildId = target ? target->GetGuildId() : sCharacterCache->GetCharacterGuildIdByGuid(targetGuid);
        if (!guildId)
            return false;

        Guild* targetGuild = sGuildMgr->GetGuildById(guildId);
        if (!targetGuild)
            return false;

        CharacterDatabaseTransaction trans(nullptr);
        targetGuild->DeleteMember(trans, targetGuid, false, true, true);
        return true;
    }

    static bool HandleGuildRankCommand(ChatHandler* handler, Optional<PlayerIdentifier> player, uint8 rank)
    {
        if (!player)
            player = PlayerIdentifier::FromTargetOrSelf(handler);
        if (!player)
            return false;

        ObjectGuid::LowType guildId = player->IsConnected() ? player->GetConnectedPlayer()->GetGuildId() : sCharacterCache->GetCharacterGuildIdByGuid(*player);
        if (!guildId)
            return false;

        Guild* targetGuild = sGuildMgr->GetGuildById(guildId);
        if (!targetGuild)
            return false;

        return targetGuild->ChangeMemberRank(nullptr, *player, GuildRankId(rank));
    }

    static bool HandleGuildRenameCommand(ChatHandler* handler, char const* _args)
    {
        if (!*_args)
            return false;

        char *args = (char *)_args;

        char const* oldGuildStr = handler->extractQuotedArg(args);
        if (!oldGuildStr)
        {
            handler->SendSysMessage(LANG_BAD_VALUE);
            handler->SetSentErrorMessage(true);
            return false;
        }

        char const* newGuildStr = handler->extractQuotedArg(strtok(nullptr, ""));
        if (!newGuildStr)
        {
            handler->SendSysMessage(LANG_INSERT_GUILD_NAME);
            handler->SetSentErrorMessage(true);
            return false;
        }

        Guild* guild = sGuildMgr->GetGuildByName(oldGuildStr);
        if (!guild)
        {
            handler->PSendSysMessage(LANG_COMMAND_COULDNOTFIND, oldGuildStr);
            handler->SetSentErrorMessage(true);
            return false;
        }

        if (sGuildMgr->GetGuildByName(newGuildStr))
        {
            handler->PSendSysMessage(LANG_GUILD_RENAME_ALREADY_EXISTS, newGuildStr);
            handler->SetSentErrorMessage(true);
            return false;
        }

        if (!guild->SetName(newGuildStr))
        {
            handler->SendSysMessage(LANG_BAD_VALUE);
            handler->SetSentErrorMessage(true);
            return false;
        }

        handler->PSendSysMessage(LANG_GUILD_RENAME_DONE, oldGuildStr, newGuildStr);
        return true;
    }

    static bool HandleGuildInfoCommand(ChatHandler* handler, char const* args)
    {
        Guild* guild = nullptr;

        if (args && args[0] != '\0')
        {
            if (isNumeric(args))
                guild = sGuildMgr->GetGuildById(strtoull(args, nullptr, 10));
            else
                guild = sGuildMgr->GetGuildByName(args);
        }
        else if (Player* target = handler->getSelectedPlayerOrSelf())
            guild = target->GetGuild();

        if (!guild)
            return false;

        // Display Guild Information
        handler->PSendSysMessage(LANG_GUILD_INFO_NAME, guild->GetName().c_str(), std::to_string(guild->GetId()).c_str()); // Guild Id + Name

        std::string guildMasterName;
        if (sCharacterCache->GetCharacterNameByGuid(guild->GetLeaderGUID(), guildMasterName))
            handler->PSendSysMessage(LANG_GUILD_INFO_GUILD_MASTER, guildMasterName.c_str(), guild->GetLeaderGUID().ToString().c_str()); // Guild Master

        // Format creation date
        char createdDateStr[20];
        time_t createdDate = guild->GetCreatedDate();
        tm localTm;
        strftime(createdDateStr, 20, "%Y-%m-%d %H:%M:%S", localtime_r(&createdDate, &localTm));

        handler->PSendSysMessage(LANG_GUILD_INFO_CREATION_DATE, createdDateStr); // Creation Date
        handler->PSendSysMessage(LANG_GUILD_INFO_MEMBER_COUNT, guild->GetMembersCount()); // Number of Members
        handler->PSendSysMessage(LANG_GUILD_INFO_BANK_GOLD, std::to_string(guild->GetBankMoney() / 100 / 100).c_str()); // Bank Gold (in gold coins)
        handler->PSendSysMessage(LANG_GUILD_INFO_LEVEL, guild->GetLevel()); // Level
        handler->PSendSysMessage(LANG_GUILD_INFO_MOTD, guild->GetMOTD().c_str()); // Message of the Day
        handler->PSendSysMessage(LANG_GUILD_INFO_EXTRA_INFO, guild->GetInfo().c_str()); // Extra Information
        return true;
    }
};

void AddSC_guild_commandscript()
{
    new guild_commandscript();
}
