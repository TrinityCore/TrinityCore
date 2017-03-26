/*
 * Copyright (C) 2008-2017 TrinityCore <http://www.trinitycore.org/>
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
Name: character_commandscript
%Complete: 100
Comment: All character related commands
Category: commandscripts
EndScriptData */

#include "AccountMgr.h"
#include "CharacterCache.h"
#include "Chat.h"
#include "ObjectMgr.h"
#include "PlayerDump.h"
#include "Player.h"
#include "ReputationMgr.h"
#include "ScriptMgr.h"

class character_commandscript : public CommandScript
{
public:
    character_commandscript() : CommandScript("character_commandscript") { }

    std::vector<ChatCommand> GetCommands() const override
    {
        static std::vector<ChatCommand> pdumpCommandTable =
        {
            { "load",          rbac::RBAC_PERM_COMMAND_PDUMP_LOAD,                true,  &HandlePDumpLoadCommand,               "" },
            { "write",         rbac::RBAC_PERM_COMMAND_PDUMP_WRITE,               true,  &HandlePDumpWriteCommand,              "" },
        };
        static std::vector<ChatCommand> characterDeletedCommandTable =
        {
            { "delete",        rbac::RBAC_PERM_COMMAND_CHARACTER_DELETED_DELETE,  true,  &HandleCharacterDeletedDeleteCommand,  "" },
            { "list",          rbac::RBAC_PERM_COMMAND_CHARACTER_DELETED_LIST,    true,  &HandleCharacterDeletedListCommand,    "" },
            { "restore",       rbac::RBAC_PERM_COMMAND_CHARACTER_DELETED_RESTORE, true,  &HandleCharacterDeletedRestoreCommand, "" },
            { "old",           rbac::RBAC_PERM_COMMAND_CHARACTER_DELETED_OLD,     true,  &HandleCharacterDeletedOldCommand,     "" },
        };

        static std::vector<ChatCommand> characterCommandTable =
        {
            { "customize",     rbac::RBAC_PERM_COMMAND_CHARACTER_CUSTOMIZE,       true,  &HandleCharacterCustomizeCommand,      "", },
            { "changefaction", rbac::RBAC_PERM_COMMAND_CHARACTER_CHANGEFACTION,   true,  &HandleCharacterChangeFactionCommand,  "", },
            { "changerace",    rbac::RBAC_PERM_COMMAND_CHARACTER_CHANGERACE,      true,  &HandleCharacterChangeRaceCommand,     "", },
            { "changeaccount", rbac::RBAC_PERM_COMMAND_CHARACTER_CHANGEACCOUNT,   true,  &HandleCharacterChangeAccountCommand,  "", },
            { "deleted",       rbac::RBAC_PERM_COMMAND_CHARACTER_DELETED,         true,  NULL,                                  "", characterDeletedCommandTable },
            { "erase",         rbac::RBAC_PERM_COMMAND_CHARACTER_ERASE,           true,  &HandleCharacterEraseCommand,          "", },
            { "level",         rbac::RBAC_PERM_COMMAND_CHARACTER_LEVEL,           true,  &HandleCharacterLevelCommand,          "", },
            { "rename",        rbac::RBAC_PERM_COMMAND_CHARACTER_RENAME,          true,  &HandleCharacterRenameCommand,         "", },
            { "reputation",    rbac::RBAC_PERM_COMMAND_CHARACTER_REPUTATION,      true,  &HandleCharacterReputationCommand,     "", },
            { "titles",        rbac::RBAC_PERM_COMMAND_CHARACTER_TITLES,          true,  &HandleCharacterTitlesCommand,         "", },
        };

        static std::vector<ChatCommand> commandTable =
        {
            { "character",     rbac::RBAC_PERM_COMMAND_CHARACTER,                 true,  NULL,                                  "", characterCommandTable },
            { "levelup",       rbac::RBAC_PERM_COMMAND_LEVELUP,                   false, &HandleLevelUpCommand,                 "" },
            { "pdump",         rbac::RBAC_PERM_COMMAND_PDUMP,                     true,  NULL,                                  "", pdumpCommandTable },
        };
        return commandTable;
    }

    // Stores informations about a deleted character
    struct DeletedInfo
    {
        ObjectGuid  guid;                               ///< the GUID from the character
        std::string name;                               ///< the character name
        uint32      accountId;                          ///< the account id
        std::string accountName;                        ///< the account name
        time_t      deleteDate;                         ///< the date at which the character has been deleted
    };

    typedef std::list<DeletedInfo> DeletedInfoList;

    /**
    * Collects all GUIDs (and related info) from deleted characters which are still in the database.
    *
    * @param foundList    a reference to an std::list which will be filled with info data
    * @param searchString the search string which either contains a player GUID or a part fo the character-name
    * @return             returns false if there was a problem while selecting the characters (e.g. player name not normalizeable)
    */
    static bool GetDeletedCharacterInfoList(DeletedInfoList& foundList, std::string searchString)
    {
        PreparedQueryResult result;
        PreparedStatement* stmt;
        if (!searchString.empty())
        {
            // search by GUID
            if (isNumeric(searchString.c_str()))
            {
                stmt = CharacterDatabase.GetPreparedStatement(CHAR_SEL_CHAR_DEL_INFO_BY_GUID);
                stmt->setUInt32(0, uint32(atoi(searchString.c_str())));
                result = CharacterDatabase.Query(stmt);
            }
            // search by name
            else
            {
                if (!normalizePlayerName(searchString))
                    return false;

                stmt = CharacterDatabase.GetPreparedStatement(CHAR_SEL_CHAR_DEL_INFO_BY_NAME);
                stmt->setString(0, searchString);
                result = CharacterDatabase.Query(stmt);
            }
        }
        else
        {
            stmt = CharacterDatabase.GetPreparedStatement(CHAR_SEL_CHAR_DEL_INFO);
            result = CharacterDatabase.Query(stmt);
        }

        if (result)
        {
            do
            {
                Field* fields = result->Fetch();

                DeletedInfo info;

                info.guid       = ObjectGuid(HighGuid::Player, fields[0].GetUInt32());
                info.name       = fields[1].GetString();
                info.accountId  = fields[2].GetUInt32();

                // account name will be empty for nonexisting account
                AccountMgr::GetName(info.accountId, info.accountName);
                info.deleteDate = time_t(fields[3].GetUInt32());
                foundList.push_back(info);
            }
            while (result->NextRow());
        }

        return true;
    }

    /**
    * Shows all deleted characters which matches the given search string, expected non empty list
    *
    * @see HandleCharacterDeletedListCommand
    * @see HandleCharacterDeletedRestoreCommand
    * @see HandleCharacterDeletedDeleteCommand
    * @see DeletedInfoList
    *
    * @param foundList contains a list with all found deleted characters
    */
    static void HandleCharacterDeletedListHelper(DeletedInfoList const& foundList, ChatHandler* handler)
    {
        if (!handler->GetSession())
        {
            handler->SendSysMessage(LANG_CHARACTER_DELETED_LIST_BAR);
            handler->SendSysMessage(LANG_CHARACTER_DELETED_LIST_HEADER);
            handler->SendSysMessage(LANG_CHARACTER_DELETED_LIST_BAR);
        }

        for (DeletedInfoList::const_iterator itr = foundList.begin(); itr != foundList.end(); ++itr)
        {
            std::string dateStr = TimeToTimestampStr(itr->deleteDate);

            if (!handler->GetSession())
                handler->PSendSysMessage(LANG_CHARACTER_DELETED_LIST_LINE_CONSOLE,
                    itr->guid.GetCounter(), itr->name.c_str(), itr->accountName.empty() ? "<Not existing>" : itr->accountName.c_str(),
                    itr->accountId, dateStr.c_str());
            else
                handler->PSendSysMessage(LANG_CHARACTER_DELETED_LIST_LINE_CHAT,
                    itr->guid.GetCounter(), itr->name.c_str(), itr->accountName.empty() ? "<Not existing>" : itr->accountName.c_str(),
                    itr->accountId, dateStr.c_str());
        }

        if (!handler->GetSession())
            handler->SendSysMessage(LANG_CHARACTER_DELETED_LIST_BAR);
    }

    /**
    * Restore a previously deleted character
    *
    * @see HandleCharacterDeletedListHelper
    * @see HandleCharacterDeletedRestoreCommand
    * @see HandleCharacterDeletedDeleteCommand
    * @see DeletedInfoList
    *
    * @param delInfo the informations about the character which will be restored
    */
    static void HandleCharacterDeletedRestoreHelper(DeletedInfo const& delInfo, ChatHandler* handler)
    {
        if (delInfo.accountName.empty())                    // account does not exist
        {
            handler->PSendSysMessage(LANG_CHARACTER_DELETED_SKIP_ACCOUNT, delInfo.name.c_str(), delInfo.guid.GetCounter(), delInfo.accountId);
            return;
        }

        // check character count
        uint32 charcount = AccountMgr::GetCharactersCount(delInfo.accountId);
        if (charcount >= 10)
        {
            handler->PSendSysMessage(LANG_CHARACTER_DELETED_SKIP_FULL, delInfo.name.c_str(), delInfo.guid.GetCounter(), delInfo.accountId);
            return;
        }

        if (sCharacterCache->GetCharacterGuidByName(delInfo.name))
        {
            handler->PSendSysMessage(LANG_CHARACTER_DELETED_SKIP_NAME, delInfo.name.c_str(), delInfo.guid.GetCounter(), delInfo.accountId);
            return;
        }

        PreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_UPD_RESTORE_DELETE_INFO);
        stmt->setString(0, delInfo.name);
        stmt->setUInt32(1, delInfo.accountId);
        stmt->setUInt32(2, delInfo.guid.GetCounter());
        CharacterDatabase.Execute(stmt);

        stmt = CharacterDatabase.GetPreparedStatement(CHAR_SEL_CHARACTER_NAME_DATA);
        stmt->setUInt32(0, delInfo.guid.GetCounter());
        if (PreparedQueryResult result = CharacterDatabase.Query(stmt))
            sCharacterCache->AddCharacterCacheEntry(delInfo.guid, delInfo.accountId, delInfo.name, (*result)[2].GetUInt8(), (*result)[0].GetUInt8(), (*result)[1].GetUInt8(), (*result)[3].GetUInt8());
    }

    static void HandleCharacterLevel(Player* player, ObjectGuid playerGuid, uint32 oldLevel, uint32 newLevel, ChatHandler* handler)
    {
        if (player)
        {
            player->GiveLevel(newLevel);
            player->InitTalentForLevel();
            player->SetUInt32Value(PLAYER_XP, 0);

            if (handler->needReportToTarget(player))
            {
                if (oldLevel == newLevel)
                    ChatHandler(player->GetSession()).PSendSysMessage(LANG_YOURS_LEVEL_PROGRESS_RESET, handler->GetNameLink().c_str());
                else if (oldLevel < newLevel)
                    ChatHandler(player->GetSession()).PSendSysMessage(LANG_YOURS_LEVEL_UP, handler->GetNameLink().c_str(), newLevel);
                else                                                // if (oldlevel > newlevel)
                    ChatHandler(player->GetSession()).PSendSysMessage(LANG_YOURS_LEVEL_DOWN, handler->GetNameLink().c_str(), newLevel);
            }
        }
        else
        {
            // Update level and reset XP, everything else will be updated at login
            PreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_UPD_LEVEL);
            stmt->setUInt8(0, uint8(newLevel));
            stmt->setUInt32(1, playerGuid.GetCounter());
            CharacterDatabase.Execute(stmt);
        }
    }

    static bool HandleCharacterTitlesCommand(ChatHandler* handler, char const* args)
    {
        if (!*args)
            return false;

        Player* target;
        if (!handler->extractPlayerTarget((char*)args, &target))
            return false;

        LocaleConstant loc = handler->GetSessionDbcLocale();
        char const* targetName = target->GetName().c_str();
        char const* knownStr = handler->GetTrinityString(LANG_KNOWN);

        // Search in CharTitles.dbc
        for (uint32 id = 0; id < sCharTitlesStore.GetNumRows(); id++)
        {
            CharTitlesEntry const* titleInfo = sCharTitlesStore.LookupEntry(id);

            if (titleInfo && target->HasTitle(titleInfo))
            {
                std::string name = target->getGender() == GENDER_MALE ? titleInfo->nameMale[loc] : titleInfo->nameFemale[loc];
                if (name.empty())
                    continue;

                char const* activeStr = target->GetUInt32Value(PLAYER_CHOSEN_TITLE) == titleInfo->bit_index
                ? handler->GetTrinityString(LANG_ACTIVE)
                : "";

                char titleNameStr[80];
                snprintf(titleNameStr, 80, name.c_str(), targetName);

                // send title in "id (idx:idx) - [namedlink locale]" format
                if (handler->GetSession())
                    handler->PSendSysMessage(LANG_TITLE_LIST_CHAT, id, titleInfo->bit_index, id, titleNameStr, localeNames[loc], knownStr, activeStr);
                else
                    handler->PSendSysMessage(LANG_TITLE_LIST_CONSOLE, id, titleInfo->bit_index, name.c_str(), localeNames[loc], knownStr, activeStr);
            }
        }

        return true;
    }

    //rename characters
    static bool HandleCharacterRenameCommand(ChatHandler* handler, char const* args)
    {
        Player* target;
        ObjectGuid targetGuid;
        std::string targetName;
        if (!handler->extractPlayerTarget((char*)args, &target, &targetGuid, &targetName))
            return false;

        char const* newNameStr = strtok(NULL, " ");

        if (newNameStr)
        {
            std::string playerOldName;
            std::string newName = newNameStr;

            if (target)
            {
                // check online security
                if (handler->HasLowerSecurity(target, ObjectGuid::Empty))
                    return false;

                playerOldName = target->GetName();
            }
            else
            {
                // check offline security
                if (handler->HasLowerSecurity(NULL, targetGuid))
                    return false;

                sCharacterCache->GetCharacterNameByGuid(targetGuid, playerOldName);
            }

            if (!normalizePlayerName(newName))
            {
                handler->SendSysMessage(LANG_BAD_VALUE);
                handler->SetSentErrorMessage(true);
                return false;
            }

            if (ObjectMgr::CheckPlayerName(newName, target ? target->GetSession()->GetSessionDbcLocale() : sWorld->GetDefaultDbcLocale(), true) != CHAR_NAME_SUCCESS)
            {
                handler->SendSysMessage(LANG_BAD_VALUE);
                handler->SetSentErrorMessage(true);
                return false;
            }

            if (WorldSession* session = handler->GetSession())
            {
                if (!session->HasPermission(rbac::RBAC_PERM_SKIP_CHECK_CHARACTER_CREATION_RESERVEDNAME) && sObjectMgr->IsReservedName(newName))
                {
                    handler->SendSysMessage(LANG_RESERVED_NAME);
                    handler->SetSentErrorMessage(true);
                    return false;
                }
            }

            PreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_SEL_CHECK_NAME);
            stmt->setString(0, newName);
            PreparedQueryResult result = CharacterDatabase.Query(stmt);
            if (result)
            {
                handler->PSendSysMessage(LANG_RENAME_PLAYER_ALREADY_EXISTS, newName.c_str());
                handler->SetSentErrorMessage(true);
                return false;
            }

            // Remove declined name from db
            stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_DECLINED_NAME);
            stmt->setUInt32(0, targetGuid.GetCounter());
            CharacterDatabase.Execute(stmt);

            if (target)
            {
                target->SetName(newName);

                if (WorldSession* session = target->GetSession())
                    session->KickPlayer();
            }
            else
            {
                stmt = CharacterDatabase.GetPreparedStatement(CHAR_UPD_NAME_BY_GUID);
                stmt->setString(0, newName);
                stmt->setUInt32(1, targetGuid.GetCounter());
                CharacterDatabase.Execute(stmt);
            }

            sCharacterCache->UpdateCharacterData(targetGuid, newName);

            handler->PSendSysMessage(LANG_RENAME_PLAYER_WITH_NEW_NAME, playerOldName.c_str(), newName.c_str());

            if (WorldSession* session = handler->GetSession())
            {
                if (Player* player = session->GetPlayer())
                    sLog->outCommand(session->GetAccountId(), "GM %s (Account: %u) forced rename %s to player %s (Account: %u)", player->GetName().c_str(), session->GetAccountId(), newName.c_str(), playerOldName.c_str(), sCharacterCache->GetCharacterAccountIdByGuid(targetGuid));
            }
            else
                sLog->outCommand(0, "CONSOLE forced rename '%s' to '%s' (%s)", playerOldName.c_str(), newName.c_str(), targetGuid.ToString().c_str());
        }
        else
        {
            if (target)
            {
                // check online security
                if (handler->HasLowerSecurity(target, ObjectGuid::Empty))
                    return false;

                handler->PSendSysMessage(LANG_RENAME_PLAYER, handler->GetNameLink(target).c_str());
                target->SetAtLoginFlag(AT_LOGIN_RENAME);
            }
            else
            {
                // check offline security
                if (handler->HasLowerSecurity(NULL, targetGuid))
                    return false;

                std::string oldNameLink = handler->playerLink(targetName);
                handler->PSendSysMessage(LANG_RENAME_PLAYER_GUID, oldNameLink.c_str(), targetGuid.GetCounter());

                PreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_UPD_ADD_AT_LOGIN_FLAG);
                stmt->setUInt16(0, uint16(AT_LOGIN_RENAME));
                stmt->setUInt32(1, targetGuid.GetCounter());
                CharacterDatabase.Execute(stmt);
            }
        }

        return true;
    }

    static bool HandleCharacterLevelCommand(ChatHandler* handler, char const* args)
    {
        char* nameStr;
        char* levelStr;
        handler->extractOptFirstArg((char*)args, &nameStr, &levelStr);
        if (!levelStr)
            return false;

        // exception opt second arg: .character level $name
        if (isalpha(levelStr[0]))
        {
            nameStr = levelStr;
            levelStr = nullptr;                                    // current level will used
        }

        Player* target;
        ObjectGuid targetGuid;
        std::string targetName;
        if (!handler->extractPlayerTarget(nameStr, &target, &targetGuid, &targetName))
            return false;

        int32 oldlevel = target ? target->getLevel() : sCharacterCache->GetCharacterLevelByGuid(targetGuid);
        int32 newlevel = levelStr ? atoi(levelStr) : oldlevel;

        if (newlevel < 1)
            return false;                                       // invalid level

        if (newlevel > STRONG_MAX_LEVEL)                         // hardcoded maximum level
            newlevel = STRONG_MAX_LEVEL;

        HandleCharacterLevel(target, targetGuid, oldlevel, newlevel, handler);
        if (!handler->GetSession() || handler->GetSession()->GetPlayer() != target)      // including player == NULL
        {
            std::string nameLink = handler->playerLink(targetName);
            handler->PSendSysMessage(LANG_YOU_CHANGE_LVL, nameLink.c_str(), newlevel);
        }

        return true;
    }

    // customize characters
    static bool HandleCharacterCustomizeCommand(ChatHandler* handler, char const* args)
    {
        Player* target;
        ObjectGuid targetGuid;
        std::string targetName;
        if (!handler->extractPlayerTarget((char*)args, &target, &targetGuid, &targetName))
            return false;

        PreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_UPD_ADD_AT_LOGIN_FLAG);
        stmt->setUInt16(0, uint16(AT_LOGIN_CUSTOMIZE));
        if (target)
        {
            handler->PSendSysMessage(LANG_CUSTOMIZE_PLAYER, handler->GetNameLink(target).c_str());
            target->SetAtLoginFlag(AT_LOGIN_CUSTOMIZE);
            stmt->setUInt32(1, target->GetGUID().GetCounter());
        }
        else
        {
            std::string oldNameLink = handler->playerLink(targetName);
            stmt->setUInt32(1, targetGuid.GetCounter());
            handler->PSendSysMessage(LANG_CUSTOMIZE_PLAYER_GUID, oldNameLink.c_str(), targetGuid.GetCounter());
        }
        CharacterDatabase.Execute(stmt);

        return true;
    }

    static bool HandleCharacterChangeFactionCommand(ChatHandler* handler, char const* args)
    {
        Player* target;
        ObjectGuid targetGuid;
        std::string targetName;

        if (!handler->extractPlayerTarget((char*)args, &target, &targetGuid, &targetName))
            return false;

        PreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_UPD_ADD_AT_LOGIN_FLAG);
        stmt->setUInt16(0, uint16(AT_LOGIN_CHANGE_FACTION));
        if (target)
        {
            handler->PSendSysMessage(LANG_CUSTOMIZE_PLAYER, handler->GetNameLink(target).c_str());
            target->SetAtLoginFlag(AT_LOGIN_CHANGE_FACTION);
            stmt->setUInt32(1, target->GetGUID().GetCounter());
        }
        else
        {
            std::string oldNameLink = handler->playerLink(targetName);
            handler->PSendSysMessage(LANG_CUSTOMIZE_PLAYER_GUID, oldNameLink.c_str(), targetGuid.GetCounter());
            stmt->setUInt32(1, targetGuid.GetCounter());
        }
        CharacterDatabase.Execute(stmt);

        return true;
    }

    static bool HandleCharacterChangeRaceCommand(ChatHandler* handler, char const* args)
    {
        Player* target;
        ObjectGuid targetGuid;
        std::string targetName;
        if (!handler->extractPlayerTarget((char*)args, &target, &targetGuid, &targetName))
            return false;

        PreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_UPD_ADD_AT_LOGIN_FLAG);
        stmt->setUInt16(0, uint16(AT_LOGIN_CHANGE_RACE));
        if (target)
        {
            /// @todo add text into database
            handler->PSendSysMessage(LANG_CUSTOMIZE_PLAYER, handler->GetNameLink(target).c_str());
            target->SetAtLoginFlag(AT_LOGIN_CHANGE_RACE);
            stmt->setUInt32(1, target->GetGUID().GetCounter());
        }
        else
        {
            std::string oldNameLink = handler->playerLink(targetName);
            /// @todo add text into database
            handler->PSendSysMessage(LANG_CUSTOMIZE_PLAYER_GUID, oldNameLink.c_str(), targetGuid.GetCounter());
            stmt->setUInt32(1, targetGuid.GetCounter());
        }
        CharacterDatabase.Execute(stmt);

        return true;
    }

    static bool HandleCharacterChangeAccountCommand(ChatHandler* handler, char const* args)
    {
        char* playerNameStr;
        char* accountNameStr;
        handler->extractOptFirstArg(const_cast<char*>(args), &playerNameStr, &accountNameStr);
        if (!accountNameStr)
            return false;

        ObjectGuid targetGuid;
        std::string targetName;
        if (!handler->extractPlayerTarget(playerNameStr, nullptr, &targetGuid, &targetName))
            return false;

        CharacterCacheEntry const* characterInfo = sCharacterCache->GetCharacterCacheByGuid(targetGuid);
        if (!characterInfo)
        {
            handler->SendSysMessage(LANG_PLAYER_NOT_FOUND);
            handler->SetSentErrorMessage(true);
            return false;
        }

        uint32 oldAccountId = characterInfo->AccountId;
        uint32 newAccountId = oldAccountId;

        std::string accountName(accountNameStr);
        if (!Utf8ToUpperOnlyLatin(accountName))
        {
            handler->PSendSysMessage(LANG_ACCOUNT_NOT_EXIST, accountName.c_str());
            handler->SetSentErrorMessage(true);
            return false;
        }

        PreparedStatement* stmt = LoginDatabase.GetPreparedStatement(LOGIN_SEL_ACCOUNT_ID_BY_NAME);
        stmt->setString(0, accountName);
        if (PreparedQueryResult result = LoginDatabase.Query(stmt))
            newAccountId = (*result)[0].GetUInt32();
        else
        {
            handler->PSendSysMessage(LANG_ACCOUNT_NOT_EXIST, accountName.c_str());
            handler->SetSentErrorMessage(true);
            return false;
        }

        // nothing to do :)
        if (newAccountId == oldAccountId)
            return true;

        if (uint32 charCount = AccountMgr::GetCharactersCount(newAccountId))
        {
            if (charCount >= sWorld->getIntConfig(CONFIG_CHARACTERS_PER_REALM))
            {
                handler->PSendSysMessage(LANG_ACCOUNT_CHARACTER_LIST_FULL, accountName.c_str(), newAccountId);
                handler->SetSentErrorMessage(true);
                return false;
            }
        }

        stmt = CharacterDatabase.GetPreparedStatement(CHAR_UPD_ACCOUNT_BY_GUID);
        stmt->setUInt32(0, newAccountId);
        stmt->setUInt32(1, targetGuid.GetCounter());
        CharacterDatabase.DirectExecute(stmt);

        sWorld->UpdateRealmCharCount(oldAccountId);
        sWorld->UpdateRealmCharCount(newAccountId);

        sCharacterCache->UpdateCharacterAccountId(targetGuid, newAccountId);

        handler->PSendSysMessage(LANG_CHANGEACCOUNT_SUCCESS, targetName.c_str(), accountName.c_str());

        std::string logString = Trinity::StringFormat("changed ownership of player %s (%s) from account %u to account %u", targetName.c_str(), targetGuid.ToString().c_str(), oldAccountId, newAccountId);
        if (WorldSession* session = handler->GetSession())
        {
            if (Player* player = session->GetPlayer())
                sLog->outCommand(session->GetAccountId(), "GM %s (Account: %u) %s", player->GetName().c_str(), session->GetAccountId(), logString.c_str());
        }
        else
            sLog->outCommand(0, "%s %s", handler->GetTrinityString(LANG_CONSOLE), logString.c_str());
        return true;
    }

    static bool HandleCharacterReputationCommand(ChatHandler* handler, char const* args)
    {
        Player* target;
        if (!handler->extractPlayerTarget((char*)args, &target))
            return false;

        LocaleConstant loc = handler->GetSessionDbcLocale();

        FactionStateList const& targetFSL = target->GetReputationMgr().GetStateList();
        for (FactionStateList::const_iterator itr = targetFSL.begin(); itr != targetFSL.end(); ++itr)
        {
            FactionState const& faction = itr->second;
            FactionEntry const* factionEntry = sFactionStore.LookupEntry(faction.ID);
            char const* factionName = factionEntry ? factionEntry->name[loc] : "#Not found#";
            ReputationRank rank = target->GetReputationMgr().GetRank(factionEntry);
            std::string rankName = handler->GetTrinityString(ReputationRankStrIndex[rank]);
            std::ostringstream ss;
            if (handler->GetSession())
                ss << faction.ID << " - |cffffffff|Hfaction:" << faction.ID << "|h[" << factionName << ' ' << localeNames[loc] << "]|h|r";
            else
                ss << faction.ID << " - " << factionName << ' ' << localeNames[loc];

            ss << ' ' << rankName << " (" << target->GetReputationMgr().GetReputation(factionEntry) << ')';

            if (faction.Flags & FACTION_FLAG_VISIBLE)
                ss << handler->GetTrinityString(LANG_FACTION_VISIBLE);
            if (faction.Flags & FACTION_FLAG_AT_WAR)
                ss << handler->GetTrinityString(LANG_FACTION_ATWAR);
            if (faction.Flags & FACTION_FLAG_PEACE_FORCED)
                ss << handler->GetTrinityString(LANG_FACTION_PEACE_FORCED);
            if (faction.Flags & FACTION_FLAG_HIDDEN)
                ss << handler->GetTrinityString(LANG_FACTION_HIDDEN);
            if (faction.Flags & FACTION_FLAG_INVISIBLE_FORCED)
                ss << handler->GetTrinityString(LANG_FACTION_INVISIBLE_FORCED);
            if (faction.Flags & FACTION_FLAG_INACTIVE)
                ss << handler->GetTrinityString(LANG_FACTION_INACTIVE);

            handler->SendSysMessage(ss.str().c_str());
        }

        return true;
    }

   /**
    * Handles the '.character deleted list' command, which shows all deleted characters which matches the given search string
    *
    * @see HandleCharacterDeletedListHelper
    * @see HandleCharacterDeletedRestoreCommand
    * @see HandleCharacterDeletedDeleteCommand
    * @see DeletedInfoList
    *
    * @param args the search string which either contains a player GUID or a part fo the character-name
    */
    static bool HandleCharacterDeletedListCommand(ChatHandler* handler, char const* args)
    {
        DeletedInfoList foundList;
        if (!GetDeletedCharacterInfoList(foundList, args))
            return false;

        // if no characters have been found, output a warning
        if (foundList.empty())
        {
            handler->SendSysMessage(LANG_CHARACTER_DELETED_LIST_EMPTY);
            return false;
        }

        HandleCharacterDeletedListHelper(foundList, handler);

        return true;
    }

    /**
     * Handles the '.character deleted restore' command, which restores all deleted characters which matches the given search string
     *
     * The command automatically calls '.character deleted list' command with the search string to show all restored characters.
     *
     * @see HandleCharacterDeletedRestoreHelper
     * @see HandleCharacterDeletedListCommand
     * @see HandleCharacterDeletedDeleteCommand
     *
     * @param args the search string which either contains a player GUID or a part of the character-name
     */
    static bool HandleCharacterDeletedRestoreCommand(ChatHandler* handler, char const* args)
    {
        // It is required to submit at least one argument
        if (!*args)
            return false;

        std::string searchString;
        std::string newCharName;
        uint32 newAccount = 0;

        // GCC by some strange reason fail build code without temporary variable
        std::istringstream params(args);
        params >> searchString >> newCharName >> newAccount;

        DeletedInfoList foundList;
        if (!GetDeletedCharacterInfoList(foundList, searchString))
            return false;

        if (foundList.empty())
        {
            handler->SendSysMessage(LANG_CHARACTER_DELETED_LIST_EMPTY);
            return false;
        }

        handler->SendSysMessage(LANG_CHARACTER_DELETED_RESTORE);
        HandleCharacterDeletedListHelper(foundList, handler);

        if (newCharName.empty())
        {
            // Drop nonexisting account cases
            for (DeletedInfoList::iterator itr = foundList.begin(); itr != foundList.end(); ++itr)
                HandleCharacterDeletedRestoreHelper(*itr, handler);
        }
        else if (foundList.size() == 1 && normalizePlayerName(newCharName))
        {
            DeletedInfo delInfo = foundList.front();

            // update name
            delInfo.name = newCharName;

            // if new account provided update deleted info
            if (newAccount && newAccount != delInfo.accountId)
            {
                delInfo.accountId = newAccount;
                AccountMgr::GetName(newAccount, delInfo.accountName);
            }

            HandleCharacterDeletedRestoreHelper(delInfo, handler);
        }
        else
            handler->SendSysMessage(LANG_CHARACTER_DELETED_ERR_RENAME);

        return true;
    }

    /**
     * Handles the '.character deleted delete' command, which completely deletes all deleted characters which matches the given search string
     *
     * @see Player::GetDeletedCharacterGUIDs
     * @see Player::DeleteFromDB
     * @see HandleCharacterDeletedListCommand
     * @see HandleCharacterDeletedRestoreCommand
     *
     * @param args the search string which either contains a player GUID or a part fo the character-name
     */
    static bool HandleCharacterDeletedDeleteCommand(ChatHandler* handler, char const* args)
    {
        // It is required to submit at least one argument
        if (!*args)
            return false;

        DeletedInfoList foundList;
        if (!GetDeletedCharacterInfoList(foundList, args))
            return false;

        if (foundList.empty())
        {
            handler->SendSysMessage(LANG_CHARACTER_DELETED_LIST_EMPTY);
            return false;
        }

        handler->SendSysMessage(LANG_CHARACTER_DELETED_DELETE);
        HandleCharacterDeletedListHelper(foundList, handler);

        // Call the appropriate function to delete them (current account for deleted characters is 0)
        for (DeletedInfoList::const_iterator itr = foundList.begin(); itr != foundList.end(); ++itr)
            Player::DeleteFromDB(itr->guid, 0, false, true);

        return true;
    }

    /**
     * Handles the '.character deleted old' command, which completely deletes all deleted characters deleted with some days ago
     *
     * @see Player::DeleteOldCharacters
     * @see Player::DeleteFromDB
     * @see HandleCharacterDeletedDeleteCommand
     * @see HandleCharacterDeletedListCommand
     * @see HandleCharacterDeletedRestoreCommand
     *
     * @param args the search string which either contains a player GUID or a part fo the character-name
     */
    static bool HandleCharacterDeletedOldCommand(ChatHandler* /*handler*/, char const* args)
    {
        int32 keepDays = sWorld->getIntConfig(CONFIG_CHARDELETE_KEEP_DAYS);

        char* daysStr = strtok((char*)args, " ");
        if (daysStr)
        {
            if (!isNumeric(daysStr))
                return false;

            keepDays = atoi(daysStr);
            if (keepDays < 0)
                return false;
        }
        // config option value 0 -> disabled and can't be used
        else if (keepDays <= 0)
            return false;

        Player::DeleteOldCharacters(uint32(keepDays));

        return true;
    }

    static bool HandleCharacterEraseCommand(ChatHandler* handler, char const* args)
    {
        if (!*args)
            return false;

        char* characterName_str = strtok((char*)args, " ");
        if (!characterName_str)
            return false;

        std::string characterName = characterName_str;
        if (!normalizePlayerName(characterName))
            return false;

        ObjectGuid characterGuid;
        uint32 accountId;

        Player* player = ObjectAccessor::FindPlayerByName(characterName);
        if (player)
        {
            characterGuid = player->GetGUID();
            accountId = player->GetSession()->GetAccountId();
            player->GetSession()->KickPlayer();
        }
        else
        {
            characterGuid = sCharacterCache->GetCharacterGuidByName(characterName);
            if (characterGuid.IsEmpty())
            {
                handler->PSendSysMessage(LANG_NO_PLAYER, characterName.c_str());
                handler->SetSentErrorMessage(true);
                return false;
            }
            accountId = sCharacterCache->GetCharacterAccountIdByGuid(characterGuid);
        }

        std::string accountName;
        AccountMgr::GetName(accountId, accountName);

        Player::DeleteFromDB(characterGuid, accountId, true, true);
        handler->PSendSysMessage(LANG_CHARACTER_DELETED, characterName.c_str(), characterGuid.GetCounter(), accountName.c_str(), accountId);

        return true;
    }

    static bool HandleLevelUpCommand(ChatHandler* handler, char const* args)
    {
        char* nameStr;
        char* levelStr;
        handler->extractOptFirstArg((char*)args, &nameStr, &levelStr);

        // exception opt second arg: .character level $name
        if (levelStr && isalpha(levelStr[0]))
        {
            nameStr = levelStr;
            levelStr = NULL;                                    // current level will be used
        }

        Player* target;
        ObjectGuid targetGuid;
        std::string targetName;
        if (!handler->extractPlayerTarget(nameStr, &target, &targetGuid, &targetName))
            return false;

        int32 oldlevel = target ? target->getLevel() : sCharacterCache->GetCharacterLevelByGuid(targetGuid);
        int32 addlevel = levelStr ? atoi(levelStr) : 1;
        int32 newlevel = oldlevel + addlevel;

        if (newlevel < 1)
            newlevel = 1;

        if (newlevel > STRONG_MAX_LEVEL)                         // hardcoded maximum level
            newlevel = STRONG_MAX_LEVEL;

        HandleCharacterLevel(target, targetGuid, oldlevel, newlevel, handler);

        if (!handler->GetSession() || handler->GetSession()->GetPlayer() != target)      // including chr == NULL
        {
            std::string nameLink = handler->playerLink(targetName);
            handler->PSendSysMessage(LANG_YOU_CHANGE_LVL, nameLink.c_str(), newlevel);
        }

        return true;
    }

    static bool HandlePDumpLoadCommand(ChatHandler* handler, char const* args)
    {
        if (!*args)
            return false;

        char* fileStr = strtok((char*)args, " ");
        if (!fileStr)
            return false;

        char* accountStr = strtok(NULL, " ");
        if (!accountStr)
            return false;

        std::string accountName = accountStr;
        if (!Utf8ToUpperOnlyLatin(accountName))
        {
            handler->PSendSysMessage(LANG_ACCOUNT_NOT_EXIST, accountName.c_str());
            handler->SetSentErrorMessage(true);
            return false;
        }

        uint32 accountId = AccountMgr::GetId(accountName);
        if (!accountId)
        {
            accountId = atoi(accountStr);                             // use original string
            if (!accountId)
            {
                handler->PSendSysMessage(LANG_ACCOUNT_NOT_EXIST, accountName.c_str());
                handler->SetSentErrorMessage(true);
                return false;
            }
        }

        if (!AccountMgr::GetName(accountId, accountName))
        {
            handler->PSendSysMessage(LANG_ACCOUNT_NOT_EXIST, accountName.c_str());
            handler->SetSentErrorMessage(true);
            return false;
        }

        char* guidStr = NULL;
        char* nameStr = strtok(NULL, " ");

        std::string name;
        if (nameStr)
        {
            name = nameStr;
            // normalize the name if specified and check if it exists
            if (!normalizePlayerName(name))
            {
                handler->PSendSysMessage(LANG_INVALID_CHARACTER_NAME);
                handler->SetSentErrorMessage(true);
                return false;
            }

            if (ObjectMgr::CheckPlayerName(name, sWorld->GetDefaultDbcLocale(), true) != CHAR_NAME_SUCCESS)
            {
                handler->PSendSysMessage(LANG_INVALID_CHARACTER_NAME);
                handler->SetSentErrorMessage(true);
                return false;
            }

            guidStr = strtok(NULL, " ");
        }

        ObjectGuid::LowType guid = 0;

        if (guidStr)
        {
            guid = uint32(atoi(guidStr));
            if (!guid)
            {
                handler->PSendSysMessage(LANG_INVALID_CHARACTER_GUID);
                handler->SetSentErrorMessage(true);
                return false;
            }

            if (sCharacterCache->GetCharacterAccountIdByGuid(ObjectGuid(HighGuid::Player, guid)))
            {
                handler->PSendSysMessage(LANG_CHARACTER_GUID_IN_USE, guid);
                handler->SetSentErrorMessage(true);
                return false;
            }
        }

        switch (PlayerDumpReader().LoadDump(fileStr, accountId, name, guid))
        {
            case DUMP_SUCCESS:
                handler->PSendSysMessage(LANG_COMMAND_IMPORT_SUCCESS);
                break;
            case DUMP_FILE_OPEN_ERROR:
                handler->PSendSysMessage(LANG_FILE_OPEN_FAIL, fileStr);
                handler->SetSentErrorMessage(true);
                return false;
            case DUMP_FILE_BROKEN:
                handler->PSendSysMessage(LANG_DUMP_BROKEN, fileStr);
                handler->SetSentErrorMessage(true);
                return false;
            case DUMP_TOO_MANY_CHARS:
                handler->PSendSysMessage(LANG_ACCOUNT_CHARACTER_LIST_FULL, accountName.c_str(), accountId);
                handler->SetSentErrorMessage(true);
                return false;
            default:
                handler->PSendSysMessage(LANG_COMMAND_IMPORT_FAILED);
                handler->SetSentErrorMessage(true);
                return false;
        }

        return true;
    }

    static bool HandlePDumpWriteCommand(ChatHandler* handler, char const* args)
    {
        if (!*args)
            return false;

        char* fileStr = strtok((char*)args, " ");
        char* playerStr = strtok(NULL, " ");

        if (!fileStr || !playerStr)
            return false;

        ObjectGuid guid;
        // character name can't start from number
        if (isNumeric(playerStr))
            guid = ObjectGuid(HighGuid::Player, uint32(atoi(playerStr)));
        else
        {
            std::string name = handler->extractPlayerNameFromLink(playerStr);
            if (name.empty())
            {
                handler->SendSysMessage(LANG_PLAYER_NOT_FOUND);
                handler->SetSentErrorMessage(true);
                return false;
            }

            guid = sCharacterCache->GetCharacterGuidByName(name);
        }

        if (!sCharacterCache->GetCharacterAccountIdByGuid(guid))
        {
            handler->PSendSysMessage(LANG_PLAYER_NOT_FOUND);
            handler->SetSentErrorMessage(true);
            return false;
        }

        switch (PlayerDumpWriter().WriteDump(fileStr, uint32(guid)))
        {
            case DUMP_SUCCESS:
                handler->PSendSysMessage(LANG_COMMAND_EXPORT_SUCCESS);
                break;
            case DUMP_FILE_OPEN_ERROR:
                handler->PSendSysMessage(LANG_FILE_OPEN_FAIL, fileStr);
                handler->SetSentErrorMessage(true);
                return false;
            case DUMP_CHARACTER_DELETED:
                handler->PSendSysMessage(LANG_COMMAND_EXPORT_DELETED_CHAR);
                handler->SetSentErrorMessage(true);
                return false;
            default:
                handler->PSendSysMessage(LANG_COMMAND_EXPORT_FAILED);
                handler->SetSentErrorMessage(true);
                return false;
        }

        return true;
    }
};

void AddSC_character_commandscript()
{
    new character_commandscript();
}
