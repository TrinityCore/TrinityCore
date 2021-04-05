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
Name: character_commandscript
%Complete: 100
Comment: All character related commands
Category: commandscripts
EndScriptData */

#include "ScriptMgr.h"
#include "AccountMgr.h"
#include "CharacterCache.h"
#include "Chat.h"
#include "DatabaseEnv.h"
#include "DBCStores.h"
#include "Log.h"
#include "ObjectAccessor.h"
#include "ObjectMgr.h"
#include "Player.h"
#include "PlayerDump.h"
#include "ReputationMgr.h"
#include "World.h"
#include "WorldSession.h"

using namespace Trinity::ChatCommands;

class character_commandscript : public CommandScript
{
public:
    character_commandscript() : CommandScript("character_commandscript") { }

    ChatCommandTable GetCommands() const override
    {
        static ChatCommandTable pdumpCommandTable =
        {
            { "copy",          HandlePDumpCopyCommand,               rbac::RBAC_PERM_COMMAND_PDUMP_COPY,                Console::Yes },
            { "load",          HandlePDumpLoadCommand,               rbac::RBAC_PERM_COMMAND_PDUMP_LOAD,                Console::Yes },
            { "write",         HandlePDumpWriteCommand,              rbac::RBAC_PERM_COMMAND_PDUMP_WRITE,               Console::Yes },
        };
        static ChatCommandTable characterDeletedCommandTable =
        {
            { "delete",        HandleCharacterDeletedDeleteCommand,  rbac::RBAC_PERM_COMMAND_CHARACTER_DELETED_DELETE,  Console::Yes },
            { "list",          HandleCharacterDeletedListCommand,    rbac::RBAC_PERM_COMMAND_CHARACTER_DELETED_LIST,    Console::Yes },
            { "restore",       HandleCharacterDeletedRestoreCommand, rbac::RBAC_PERM_COMMAND_CHARACTER_DELETED_RESTORE, Console::Yes },
            { "old",           HandleCharacterDeletedOldCommand,     rbac::RBAC_PERM_COMMAND_CHARACTER_DELETED_OLD,     Console::Yes },
        };

        static ChatCommandTable characterCommandTable =
        {
            { "customize",     HandleCharacterCustomizeCommand,      rbac::RBAC_PERM_COMMAND_CHARACTER_CUSTOMIZE,       Console::Yes },
            { "changefaction", HandleCharacterChangeFactionCommand,  rbac::RBAC_PERM_COMMAND_CHARACTER_CHANGEFACTION,   Console::Yes },
            { "changerace",    HandleCharacterChangeRaceCommand,     rbac::RBAC_PERM_COMMAND_CHARACTER_CHANGERACE,      Console::Yes },
            { "changeaccount", HandleCharacterChangeAccountCommand,  rbac::RBAC_PERM_COMMAND_CHARACTER_CHANGEACCOUNT,   Console::Yes },
            { "deleted",       characterDeletedCommandTable },
            { "erase",         HandleCharacterEraseCommand,          rbac::RBAC_PERM_COMMAND_CHARACTER_ERASE,           Console::Yes },
            { "level",         HandleCharacterLevelCommand,          rbac::RBAC_PERM_COMMAND_CHARACTER_LEVEL,           Console::Yes },
            { "rename",        HandleCharacterRenameCommand,         rbac::RBAC_PERM_COMMAND_CHARACTER_RENAME,          Console::Yes },
            { "reputation",    HandleCharacterReputationCommand,     rbac::RBAC_PERM_COMMAND_CHARACTER_REPUTATION,      Console::Yes },
            { "titles",        HandleCharacterTitlesCommand,         rbac::RBAC_PERM_COMMAND_CHARACTER_TITLES,          Console::Yes },
        };

        static ChatCommandTable commandTable =
        {
            { "character", characterCommandTable },
            { "levelup",       HandleLevelUpCommand,                 rbac::RBAC_PERM_COMMAND_LEVELUP,                   Console::No },
            { "pdump", pdumpCommandTable },
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
    static bool GetDeletedCharacterInfoList(DeletedInfoList& foundList, std::string& searchString)
    {
        PreparedQueryResult result;
        CharacterDatabasePreparedStatement* stmt;
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

        CharacterDatabasePreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_UPD_RESTORE_DELETE_INFO);
        stmt->setString(0, delInfo.name);
        stmt->setUInt32(1, delInfo.accountId);
        stmt->setUInt32(2, delInfo.guid.GetCounter());
        CharacterDatabase.Execute(stmt);

        stmt = CharacterDatabase.GetPreparedStatement(CHAR_SEL_CHARACTER_NAME_DATA);
        stmt->setUInt32(0, delInfo.guid.GetCounter());
        if (PreparedQueryResult result = CharacterDatabase.Query(stmt))
            sCharacterCache->AddCharacterCacheEntry(delInfo.guid, delInfo.accountId, delInfo.name, (*result)[2].GetUInt8(), (*result)[0].GetUInt8(), (*result)[1].GetUInt8(), (*result)[3].GetUInt8());
    }

    static bool HandleCharacterTitlesCommand(ChatHandler* handler, Optional<PlayerIdentifier> player)
    {
        if (!player)
            player = PlayerIdentifier::FromTargetOrSelf(handler);
        if (!player || !player->IsConnected())
        {
            handler->SendSysMessage(LANG_PLAYER_NOT_FOUND);
            handler->SetSentErrorMessage(true);
            return false;
        }

        Player const* target = player->GetConnectedPlayer();

        LocaleConstant loc = handler->GetSessionDbcLocale();
        char const* knownStr = handler->GetTrinityString(LANG_KNOWN);

        // Search in CharTitles.dbc
        for (uint32 id = 0; id < sCharTitlesStore.GetNumRows(); id++)
        {
            CharTitlesEntry const* titleInfo = sCharTitlesStore.LookupEntry(id);

            if (titleInfo && target->HasTitle(titleInfo))
            {
                char const* name = target->GetNativeGender() == GENDER_MALE ? titleInfo->Name[loc] : titleInfo->Name1[loc];
                if (!*name)
                    name = (target->GetNativeGender() == GENDER_MALE ? titleInfo->Name[sWorld->GetDefaultDbcLocale()] : titleInfo->Name1[sWorld->GetDefaultDbcLocale()]);
                if (!*name)
                    continue;

                char const* activeStr = "";
                if (target->GetUInt32Value(PLAYER_CHOSEN_TITLE) == titleInfo->MaskID)
                    activeStr = handler->GetTrinityString(LANG_ACTIVE);

                std::string titleName = Trinity::StringFormat(name, player->GetName().c_str());

                // send title in "id (idx:idx) - [namedlink locale]" format
                if (handler->GetSession())
                    handler->PSendSysMessage(LANG_TITLE_LIST_CHAT, id, titleInfo->MaskID, id, titleName.c_str(), localeNames[loc], knownStr, activeStr);
                else
                    handler->PSendSysMessage(LANG_TITLE_LIST_CONSOLE, id, titleInfo->MaskID, name, localeNames[loc], knownStr, activeStr);
            }
        }

        return true;
    }

    //rename characters
    static bool HandleCharacterRenameCommand(ChatHandler* handler, Optional<PlayerIdentifier> player, Optional<std::string_view> newNameV)
    {
        if (!player && newNameV)
            return false;

        if (!player)
            player = PlayerIdentifier::FromTarget(handler);
        if (!player)
            return false;

        if (handler->HasLowerSecurity(nullptr, player->GetGUID()))
            return false;

        if (newNameV)
        {
            std::string newName{ *newNameV };
            if (!normalizePlayerName(newName))
            {
                handler->SendSysMessage(LANG_BAD_VALUE);
                handler->SetSentErrorMessage(true);
                return false;
            }

            if (ObjectMgr::CheckPlayerName(newName, player->IsConnected() ? player->GetConnectedPlayer()->GetSession()->GetSessionDbcLocale() : sWorld->GetDefaultDbcLocale(), true) != CHAR_NAME_SUCCESS)
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

            CharacterDatabasePreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_SEL_CHECK_NAME);
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
            stmt->setUInt32(0, player->GetGUID().GetCounter());
            CharacterDatabase.Execute(stmt);

            if (Player* target = player->GetConnectedPlayer())
            {
                target->SetName(newName);

                if (WorldSession* session = target->GetSession())
                    session->KickPlayer("HandleCharacterRenameCommand GM Command renaming character");
            }
            else
            {
                stmt = CharacterDatabase.GetPreparedStatement(CHAR_UPD_NAME_BY_GUID);
                stmt->setString(0, newName);
                stmt->setUInt32(1, player->GetGUID().GetCounter());
                CharacterDatabase.Execute(stmt);
            }

            sCharacterCache->UpdateCharacterData(*player, newName);

            handler->PSendSysMessage(LANG_RENAME_PLAYER_WITH_NEW_NAME, player->GetName().c_str(), newName.c_str());

            if (WorldSession* session = handler->GetSession())
            {
                if (Player* player = session->GetPlayer())
                    sLog->outCommand(session->GetAccountId(), "GM %s (Account: %u) forced rename %s to player %s (Account: %u)", player->GetName().c_str(), session->GetAccountId(), newName.c_str(), player->GetName().c_str(), sCharacterCache->GetCharacterAccountIdByGuid(player->GetGUID()));
            }
            else
                sLog->outCommand(0, "CONSOLE forced rename '%s' to '%s' (%s)", player->GetName().c_str(), newName.c_str(), player->GetGUID().ToString().c_str());
        }
        else
        {
            if (Player* target = player->GetConnectedPlayer())
            {
                handler->PSendSysMessage(LANG_RENAME_PLAYER, handler->GetNameLink(target).c_str());
                target->SetAtLoginFlag(AT_LOGIN_RENAME);
            }
            else
            {
                // check offline security
                if (handler->HasLowerSecurity(nullptr, player->GetGUID()))
                    return false;

                handler->PSendSysMessage(LANG_RENAME_PLAYER_GUID, handler->playerLink(*player).c_str(), player->GetGUID().GetCounter());

                CharacterDatabasePreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_UPD_ADD_AT_LOGIN_FLAG);
                stmt->setUInt16(0, uint16(AT_LOGIN_RENAME));
                stmt->setUInt32(1, player->GetGUID().GetCounter());
                CharacterDatabase.Execute(stmt);
            }
        }

        return true;
    }

    // customize characters
    static bool HandleCharacterCustomizeCommand(ChatHandler* handler, Optional<PlayerIdentifier> player)
    {
        if (!player)
            player = PlayerIdentifier::FromTarget(handler);
        if (!player)
            return false;

        if (Player* target = player->GetConnectedPlayer())
        {
            handler->PSendSysMessage(LANG_CUSTOMIZE_PLAYER, handler->GetNameLink(target).c_str());
            target->SetAtLoginFlag(AT_LOGIN_CUSTOMIZE);
        }
        else
        {
            handler->PSendSysMessage(LANG_CUSTOMIZE_PLAYER_GUID, handler->playerLink(*player).c_str(), player->GetGUID().GetCounter());
            CharacterDatabasePreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_UPD_ADD_AT_LOGIN_FLAG);
            stmt->setUInt16(0, static_cast<uint16>(AT_LOGIN_CUSTOMIZE));
            stmt->setUInt32(1, player->GetGUID().GetCounter());
            CharacterDatabase.Execute(stmt);
        }

        return true;
    }

    static bool HandleCharacterChangeFactionCommand(ChatHandler* handler, Optional<PlayerIdentifier> player)
    {
        if (!player)
            player = PlayerIdentifier::FromTarget(handler);
        if (!player)
            return false;

        if (Player* target = player->GetConnectedPlayer())
        {
            handler->PSendSysMessage(LANG_CUSTOMIZE_PLAYER, handler->GetNameLink(target).c_str());
            target->SetAtLoginFlag(AT_LOGIN_CHANGE_FACTION);
        }
        else
        {
            handler->PSendSysMessage(LANG_CUSTOMIZE_PLAYER_GUID, handler->playerLink(*player).c_str(), player->GetGUID().GetCounter());
            CharacterDatabasePreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_UPD_ADD_AT_LOGIN_FLAG);
            stmt->setUInt16(0, uint16(AT_LOGIN_CHANGE_FACTION));
            stmt->setUInt32(1, player->GetGUID().GetCounter());
            CharacterDatabase.Execute(stmt);
        }

        return true;
    }

    static bool HandleCharacterChangeRaceCommand(ChatHandler* handler, Optional<PlayerIdentifier> player)
    {
        if (!player)
            player = PlayerIdentifier::FromTarget(handler);
        if (!player)
            return false;

        if (Player* target = player->GetConnectedPlayer())
        {
            handler->PSendSysMessage(LANG_CUSTOMIZE_PLAYER, handler->GetNameLink(target).c_str());
            target->SetAtLoginFlag(AT_LOGIN_CHANGE_RACE);
        }
        else
        {
            handler->PSendSysMessage(LANG_CUSTOMIZE_PLAYER_GUID, handler->playerLink(*player).c_str(), player->GetGUID().GetCounter());
            CharacterDatabasePreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_UPD_ADD_AT_LOGIN_FLAG);
            stmt->setUInt16(0, uint16(AT_LOGIN_CHANGE_RACE));
            stmt->setUInt32(1, player->GetGUID().GetCounter());
            CharacterDatabase.Execute(stmt);
        }

        return true;
    }

    static bool HandleCharacterChangeAccountCommand(ChatHandler* handler, Optional<PlayerIdentifier> player, AccountIdentifier newAccount)
    {
        if (!player)
            player = PlayerIdentifier::FromTarget(handler);
        if (!player)
            return false;

        CharacterCacheEntry const* characterInfo = sCharacterCache->GetCharacterCacheByGuid(player->GetGUID());
        if (!characterInfo)
        {
            handler->SendSysMessage(LANG_PLAYER_NOT_FOUND);
            handler->SetSentErrorMessage(true);
            return false;
        }

        uint32 oldAccountId = characterInfo->AccountId;
        // nothing to do :)
        if (newAccount.GetID() == oldAccountId)
            return true;

        if (uint32 charCount = AccountMgr::GetCharactersCount(newAccount.GetID()))
        {
            if (charCount >= sWorld->getIntConfig(CONFIG_CHARACTERS_PER_REALM))
            {
                handler->PSendSysMessage(LANG_ACCOUNT_CHARACTER_LIST_FULL, newAccount.GetName().c_str(), newAccount.GetID());
                handler->SetSentErrorMessage(true);
                return false;
            }
        }

        if (Player* onlinePlayer = player->GetConnectedPlayer())
            onlinePlayer->GetSession()->KickPlayer("HandleCharacterChangeAccountCommand GM Command transferring character to another account");

        CharacterDatabasePreparedStatement* charStmt = CharacterDatabase.GetPreparedStatement(CHAR_UPD_ACCOUNT_BY_GUID);
        charStmt->setUInt32(0, newAccount.GetID());
        charStmt->setUInt32(1, player->GetGUID().GetCounter());
        CharacterDatabase.DirectExecute(charStmt);

        sWorld->UpdateRealmCharCount(oldAccountId);
        sWorld->UpdateRealmCharCount(newAccount.GetID());

        sCharacterCache->UpdateCharacterAccountId(*player, newAccount.GetID());

        handler->PSendSysMessage(LANG_CHANGEACCOUNT_SUCCESS, player->GetName().c_str(), newAccount.GetName().c_str());

        std::string logString = Trinity::StringFormat("changed ownership of player %s (%s) from account %u to account %u", player->GetName().c_str(), player->GetGUID().ToString().c_str(), oldAccountId, newAccount.GetID());
        if (WorldSession* session = handler->GetSession())
        {
            if (Player* player = session->GetPlayer())
                sLog->outCommand(session->GetAccountId(), "GM %s (Account: %u) %s", player->GetName().c_str(), session->GetAccountId(), logString.c_str());
        }
        else
            sLog->outCommand(0, "%s %s", handler->GetTrinityString(LANG_CONSOLE), logString.c_str());
        return true;
    }

    static bool HandleCharacterReputationCommand(ChatHandler* handler, Optional<PlayerIdentifier> player)
    {
        if (!player)
            player = PlayerIdentifier::FromTargetOrSelf(handler);
        if (!player || !player->IsConnected())
        {
            handler->SendSysMessage(LANG_PLAYER_NOT_FOUND);
            handler->SetSentErrorMessage(true);
            return false;
        }

        Player const* target = player->GetConnectedPlayer();
        LocaleConstant loc = handler->GetSessionDbcLocale();

        FactionStateList const& targetFSL = target->GetReputationMgr().GetStateList();
        for (FactionStateList::const_iterator itr = targetFSL.begin(); itr != targetFSL.end(); ++itr)
        {
            FactionState const& faction = itr->second;
            FactionEntry const* factionEntry = sFactionStore.LookupEntry(faction.ID);
            char const* factionName = factionEntry ? factionEntry->Name[loc] : "#Not found#";
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
    static bool HandleCharacterDeletedListCommand(ChatHandler* handler, Optional<std::string_view> needleStr)
    {
        std::string needle;
        if (needleStr)
            needle.assign(*needleStr);
        DeletedInfoList foundList;
        if (!GetDeletedCharacterInfoList(foundList, needle))
            return false;

        // if no characters have been found, output a warning
        if (foundList.empty())
        {
            handler->SendSysMessage(LANG_CHARACTER_DELETED_LIST_EMPTY);
            handler->SetSentErrorMessage(true);
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
    static bool HandleCharacterDeletedRestoreCommand(ChatHandler* handler, std::string needle, Optional<std::string_view> newCharName, Optional<AccountIdentifier> newAccount)
    {
        DeletedInfoList foundList;
        if (!GetDeletedCharacterInfoList(foundList, needle))
            return false;

        if (foundList.empty())
        {
            handler->SendSysMessage(LANG_CHARACTER_DELETED_LIST_EMPTY);
            handler->SetSentErrorMessage(true);
            return false;
        }

        handler->SendSysMessage(LANG_CHARACTER_DELETED_RESTORE);
        HandleCharacterDeletedListHelper(foundList, handler);

        if (!newCharName)
        {
            // Drop nonexisting account cases
            for (DeletedInfoList::iterator itr = foundList.begin(); itr != foundList.end(); ++itr)
                HandleCharacterDeletedRestoreHelper(*itr, handler);
            return true;
        }

        if (foundList.size() == 1)
        {
            std::string newName{ *newCharName };
            DeletedInfo delInfo = foundList.front();

            // update name
            delInfo.name = newName;

            // if new account provided update deleted info
            if (newAccount)
            {
                delInfo.accountId = newAccount->GetID();
                delInfo.accountName = newAccount->GetName();
            }

            HandleCharacterDeletedRestoreHelper(delInfo, handler);
            return true;
        }

        handler->SendSysMessage(LANG_CHARACTER_DELETED_ERR_RENAME);
        handler->SetSentErrorMessage(true);
        return false;
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
    static bool HandleCharacterDeletedDeleteCommand(ChatHandler* handler, std::string needle)
    {
        DeletedInfoList foundList;
        if (!GetDeletedCharacterInfoList(foundList, needle))
            return false;

        if (foundList.empty())
        {
            handler->SendSysMessage(LANG_CHARACTER_DELETED_LIST_EMPTY);
            handler->SetSentErrorMessage(true);
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
    static bool HandleCharacterDeletedOldCommand(ChatHandler* /*handler*/, Optional<uint16> days)
    {
        int32 keepDays = static_cast<int32>(sWorld->getIntConfig(CONFIG_CHARDELETE_KEEP_DAYS));

        if (days)
            keepDays = static_cast<int32>(*days);
        else if (keepDays <= 0) // config option value 0 -> disabled and can't be used
            return false;

        Player::DeleteOldCharacters(static_cast<uint32>(keepDays));

        return true;
    }

    static bool HandleCharacterEraseCommand(ChatHandler* handler, PlayerIdentifier player)
    {
        uint32 accountId;
        if (Player* target = player.GetConnectedPlayer())
        {
            accountId = target->GetSession()->GetAccountId();
            target->GetSession()->KickPlayer("HandleCharacterEraseCommand GM Command deleting character");
        }
        else
            accountId = sCharacterCache->GetCharacterAccountIdByGuid(player);

        std::string accountName;
        AccountMgr::GetName(accountId, accountName);

        Player::DeleteFromDB(player, accountId, true, true);
        handler->PSendSysMessage(LANG_CHARACTER_DELETED, player.GetName().c_str(), player.GetGUID().GetCounter(), accountName.c_str(), accountId);

        return true;
    }

    static bool HandleCharacterLevelCommand(ChatHandler* handler, Optional<PlayerIdentifier> player, int16 newlevel)
    {
        if (!player)
            player = PlayerIdentifier::FromTargetOrSelf(handler);
        if (!player)
            return false;

        uint8 oldlevel = static_cast<uint8>(player->IsConnected() ? player->GetConnectedPlayer()->GetLevel() : sCharacterCache->GetCharacterLevelByGuid(*player));

        if (newlevel < 1)
            newlevel = 1;

        if (newlevel > static_cast<int16>(STRONG_MAX_LEVEL))
            newlevel = static_cast<int16>(STRONG_MAX_LEVEL);

        if (Player* target = player->GetConnectedPlayer())
        {
            target->GiveLevel(static_cast<uint8>(newlevel));
            target->InitTalentForLevel();
            target->SetXP(0);

            if (handler->needReportToTarget(target))
            {
                if (oldlevel == newlevel)
                    ChatHandler(target->GetSession()).PSendSysMessage(LANG_YOURS_LEVEL_PROGRESS_RESET, handler->GetNameLink().c_str());
                else if (oldlevel < static_cast<uint8>(newlevel))
                    ChatHandler(target->GetSession()).PSendSysMessage(LANG_YOURS_LEVEL_UP, handler->GetNameLink().c_str(), newlevel);
                else                                                // if (oldlevel > newlevel)
                    ChatHandler(target->GetSession()).PSendSysMessage(LANG_YOURS_LEVEL_DOWN, handler->GetNameLink().c_str(), newlevel);
            }
        }
        else
        {
            // Update level and reset XP, everything else will be updated at login
            CharacterDatabasePreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_UPD_LEVEL);
            stmt->setUInt8(0, static_cast<uint8>(newlevel));
            stmt->setUInt32(1, player->GetGUID());
            CharacterDatabase.Execute(stmt);
        }

        if (!handler->GetSession() || (handler->GetSession()->GetPlayer() != player->GetConnectedPlayer()))      // including chr == NULL
            handler->PSendSysMessage(LANG_YOU_CHANGE_LVL, handler->playerLink(*player).c_str(), newlevel);

        return true;
    }

    static bool HandleLevelUpCommand(ChatHandler* handler, Optional<PlayerIdentifier> player, int16 level)
    {
        if (!player)
            player = PlayerIdentifier::FromTargetOrSelf(handler);
        if (!player)
            return false;

        uint8 oldlevel = static_cast<uint8>(player->IsConnected() ? player->GetConnectedPlayer()->GetLevel() : sCharacterCache->GetCharacterLevelByGuid(*player));
        int16 newlevel = static_cast<int16>(oldlevel) + level;

        if (newlevel < 1)
            newlevel = 1;

        if (newlevel > static_cast<int16>(STRONG_MAX_LEVEL))
            newlevel = static_cast<int16>(STRONG_MAX_LEVEL);

        if (Player* target = player->GetConnectedPlayer())
        {
            target->GiveLevel(static_cast<uint8>(newlevel));
            target->InitTalentForLevel();
            target->SetXP(0);

            if (handler->needReportToTarget(target))
            {
                if (oldlevel == newlevel)
                    ChatHandler(target->GetSession()).PSendSysMessage(LANG_YOURS_LEVEL_PROGRESS_RESET, handler->GetNameLink().c_str());
                else if (oldlevel < static_cast<uint8>(newlevel))
                    ChatHandler(target->GetSession()).PSendSysMessage(LANG_YOURS_LEVEL_UP, handler->GetNameLink().c_str(), newlevel);
                else                                                // if (oldlevel > newlevel)
                    ChatHandler(target->GetSession()).PSendSysMessage(LANG_YOURS_LEVEL_DOWN, handler->GetNameLink().c_str(), newlevel);
            }
        }
        else
        {
            // Update level and reset XP, everything else will be updated at login
            CharacterDatabasePreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_UPD_LEVEL);
            stmt->setUInt8(0, static_cast<uint8>(newlevel));
            stmt->setUInt32(1, player->GetGUID());
            CharacterDatabase.Execute(stmt);
        }

        if (!handler->GetSession() || (handler->GetSession()->GetPlayer() != player->GetConnectedPlayer()))      // including chr == NULL
            handler->PSendSysMessage(LANG_YOU_CHANGE_LVL, handler->playerLink(*player).c_str(), newlevel);

        return true;
    }

    static bool HandlePDumpCopyCommand(ChatHandler* handler, PlayerIdentifier player, AccountIdentifier account, Optional<std::string_view> characterName, Optional<ObjectGuid::LowType> characterGUID)
    {
        std::string name;
        if (!ValidatePDumpTarget(handler, name, characterName, characterGUID))
            return false;

        std::string dump;
        switch (PlayerDumpWriter().WriteDumpToString(dump, player.GetGUID().GetCounter()))
        {
            case DUMP_SUCCESS:
                break;
            case DUMP_CHARACTER_DELETED:
                handler->PSendSysMessage(LANG_COMMAND_EXPORT_DELETED_CHAR);
                handler->SetSentErrorMessage(true);
                return false;
            case DUMP_FILE_OPEN_ERROR: // this error code should not happen
            default:
                handler->PSendSysMessage(LANG_COMMAND_EXPORT_FAILED);
                handler->SetSentErrorMessage(true);
                return false;
        }

        switch (PlayerDumpReader().LoadDumpFromString(dump, account, name, characterGUID.value_or(0)))
        {
            case DUMP_SUCCESS:
                break;
            case DUMP_TOO_MANY_CHARS:
                handler->PSendSysMessage(LANG_ACCOUNT_CHARACTER_LIST_FULL, account.GetName().c_str(), account.GetID());
                handler->SetSentErrorMessage(true);
                return false;
            case DUMP_FILE_OPEN_ERROR: // this error code should not happen
            case DUMP_FILE_BROKEN: // this error code should not happen
            default:
                handler->PSendSysMessage(LANG_COMMAND_IMPORT_FAILED);
                handler->SetSentErrorMessage(true);
                return false;
        }

        // ToDo: use a new trinity_string for this commands
        handler->PSendSysMessage(LANG_COMMAND_IMPORT_SUCCESS);

        return true;
    }

    static bool HandlePDumpLoadCommand(ChatHandler* handler, std::string fileName, AccountIdentifier account, Optional<std::string_view> characterName, Optional<ObjectGuid::LowType> characterGUID)
    {
        std::string name;
        if (!ValidatePDumpTarget(handler, name, characterName, characterGUID))
            return false;

        switch (PlayerDumpReader().LoadDumpFromFile(fileName, account, name, characterGUID.value_or(0)))
        {
            case DUMP_SUCCESS:
                handler->PSendSysMessage(LANG_COMMAND_IMPORT_SUCCESS);
                break;
            case DUMP_FILE_OPEN_ERROR:
                handler->PSendSysMessage(LANG_FILE_OPEN_FAIL, fileName.c_str());
                handler->SetSentErrorMessage(true);
                return false;
            case DUMP_FILE_BROKEN:
                handler->PSendSysMessage(LANG_DUMP_BROKEN, fileName.c_str());
                handler->SetSentErrorMessage(true);
                return false;
            case DUMP_TOO_MANY_CHARS:
                handler->PSendSysMessage(LANG_ACCOUNT_CHARACTER_LIST_FULL, account.GetName().c_str(), account.GetID());
                handler->SetSentErrorMessage(true);
                return false;
            default:
                handler->PSendSysMessage(LANG_COMMAND_IMPORT_FAILED);
                handler->SetSentErrorMessage(true);
                return false;
        }

        return true;
    }

    static bool ValidatePDumpTarget(ChatHandler* handler, std::string& name, Optional<std::string_view> characterName, Optional<ObjectGuid::LowType> characterGUID)
    {
        if (characterName)
        {
            name.assign(*characterName);
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
        }

        if (characterGUID)
        {
            if (sCharacterCache->GetCharacterCacheByGuid(ObjectGuid(HighGuid::Player, *characterGUID)))
            {
                handler->PSendSysMessage(LANG_CHARACTER_GUID_IN_USE, *characterGUID);
                handler->SetSentErrorMessage(true);
                return false;
            }
        }

        return true;
    }

    static bool HandlePDumpWriteCommand(ChatHandler* handler, std::string fileName, PlayerIdentifier player)
    {
        switch (PlayerDumpWriter().WriteDumpToFile(fileName, player.GetGUID().GetCounter()))
        {
            case DUMP_SUCCESS:
                handler->PSendSysMessage(LANG_COMMAND_EXPORT_SUCCESS);
                break;
            case DUMP_FILE_OPEN_ERROR:
                handler->PSendSysMessage(LANG_FILE_OPEN_FAIL, fileName.c_str());
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
