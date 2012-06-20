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
Name: character_commandscript
%Complete: 100
Comment: All character related commands
Category: commandscripts
EndScriptData */

#include "ScriptMgr.h"
#include "Chat.h"
#include "AccountMgr.h"

class character_commandscript : public CommandScript
{
public:
    character_commandscript() : CommandScript("character_commandscript") { }

    ChatCommand* GetCommands() const
    {
        static ChatCommand characterDeletedCommandTable[] =
        {
            { "delete",         SEC_CONSOLE,        true,  &HandleCharacterDeletedDeleteCommand,   "", NULL },
            { "list",           SEC_ADMINISTRATOR,  true,  &HandleCharacterDeletedListCommand,     "", NULL },
            { "restore",        SEC_ADMINISTRATOR,  true,  &HandleCharacterDeletedRestoreCommand,  "", NULL },
            { "old",            SEC_CONSOLE,        true,  &HandleCharacterDeletedOldCommand,      "", NULL },
            { NULL,             0,                  false, NULL,                                   "", NULL }
        };

        static ChatCommand characterCommandTable[] =
        {
            { "customize",      SEC_GAMEMASTER,     true,  &HandleCharacterCustomizeCommand,       "", NULL },
            { "changefaction",  SEC_GAMEMASTER,     true,  &HandleCharacterChangeFactionCommand,   "", NULL },
            { "changerace",     SEC_GAMEMASTER,     true,  &HandleCharacterChangeRaceCommand,      "", NULL },
            { "deleted",        SEC_GAMEMASTER,     true,  NULL,            "", characterDeletedCommandTable},
            { "erase",          SEC_CONSOLE,        true,  &HandleCharacterEraseCommand,           "", NULL },
            { "level",          SEC_ADMINISTRATOR,  true,  &HandleCharacterLevelCommand,           "", NULL },
            { "rename",         SEC_GAMEMASTER,     true,  &HandleCharacterRenameCommand,          "", NULL },
            { "reputation",     SEC_GAMEMASTER,     true,  &HandleCharacterReputationCommand,      "", NULL },
            { "titles",         SEC_GAMEMASTER,     true,  &HandleCharacterTitlesCommand,          "", NULL },
            { NULL,             0,                  false, NULL,                                   "", NULL }
        };

        static ChatCommand commandTable[] =
        {
            { "character",      SEC_GAMEMASTER,     true,  NULL,                    "", characterCommandTable},
            { NULL,             0,                  false, NULL,                               "", NULL }
        };
 
        return commandTable;
    }

    // Stores informations about a deleted character
    struct DeletedInfo
    {
        uint32      lowguid;                            ///< the low GUID from the character
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
    
                info.lowguid    = fields[0].GetUInt32();
                info.name       = fields[1].GetString();
                info.accountId  = fields[2].GetUInt32();
    
                // account name will be empty for not existed account
                AccountMgr::GetName(info.accountId, info.accountName);
    
                info.deleteDate = time_t(fields[3].GetUInt32());
    
                foundList.push_back(info);
            } while (result->NextRow());
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
                    itr->lowguid, itr->name.c_str(), itr->accountName.empty() ? "<Not existed>" : itr->accountName.c_str(),
                    itr->accountId, dateStr.c_str());
            else
                handler->PSendSysMessage(LANG_CHARACTER_DELETED_LIST_LINE_CHAT,
                    itr->lowguid, itr->name.c_str(), itr->accountName.empty() ? "<Not existed>" : itr->accountName.c_str(),
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
        if (delInfo.accountName.empty())                    // account not exist
        {
            handler->PSendSysMessage(LANG_CHARACTER_DELETED_SKIP_ACCOUNT, delInfo.name.c_str(), delInfo.lowguid, delInfo.accountId);
            return;
        }
    
        // check character count
        uint32 charcount = AccountMgr::GetCharactersCount(delInfo.accountId);
        if (charcount >= 10)
        {
            handler->PSendSysMessage(LANG_CHARACTER_DELETED_SKIP_FULL, delInfo.name.c_str(), delInfo.lowguid, delInfo.accountId);
            return;
        }
    
        if (sObjectMgr->GetPlayerGUIDByName(delInfo.name))
        {
            handler->PSendSysMessage(LANG_CHARACTER_DELETED_SKIP_NAME, delInfo.name.c_str(), delInfo.lowguid, delInfo.accountId);
            return;
        }
    
        PreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_UDP_RESTORE_DELETE_INFO);
    
        stmt->setString(0, delInfo.name);
        stmt->setUInt32(1, delInfo.accountId);
        stmt->setUInt32(2, delInfo.lowguid);
    
        CharacterDatabase.Execute(stmt);
    
        stmt = CharacterDatabase.GetPreparedStatement(CHAR_SEL_CHARACTER_NAME_DATA);
        stmt->setUInt32(0, delInfo.lowguid);
        if (PreparedQueryResult result = CharacterDatabase.Query(stmt))
            sWorld->AddCharacterNameData(delInfo.lowguid, delInfo.name, (*result)[2].GetUInt8(), (*result)[0].GetUInt8(), (*result)[1].GetUInt8());
    }

    static bool HandleCharacterTitlesCommand(ChatHandler* handler, char const* args)
    {
        if (!*args)
            return false;

        Player* target;
        if (!handler->extractPlayerTarget((char*)args, &target))
            return false;

        LocaleConstant loc = handler->GetSessionDbcLocale();
        char const* targetName = target->GetName();
        char const* knownStr = handler->GetTrinityString(LANG_KNOWN);

        // Search in CharTitles.dbc
        for (uint32 id = 0; id < sCharTitlesStore.GetNumRows(); id++)
        {
            CharTitlesEntry const* titleInfo = sCharTitlesStore.LookupEntry(id);

            if (titleInfo && target->HasTitle(titleInfo))
            {
                std::string name = titleInfo->name[loc];
                if (name.empty())
                    continue;

                char const* activeStr = target && target->GetUInt32Value(PLAYER_CHOSEN_TITLE) == titleInfo->bit_index
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
        uint64 targetGuid;
        std::string targetName;
        if (!handler->extractPlayerTarget((char*)args, &target, &targetGuid, &targetName))
            return false;

        if (target)
        {
            // check online security
            if (handler->HasLowerSecurity(target, 0))
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
            handler->PSendSysMessage(LANG_RENAME_PLAYER_GUID, oldNameLink.c_str(), GUID_LOPART(targetGuid));
            PreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_UPD_ADD_AT_LOGIN_FLAG);
            stmt->setUInt16(0, uint16(AT_LOGIN_RENAME));
            stmt->setUInt32(1, GUID_LOPART(targetGuid));
            CharacterDatabase.Execute(stmt);
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
            levelStr = NULL;                                    // current level will used
        }

        Player* target;
        uint64 target_guid;
        std::string target_name;
        if (!handler->extractPlayerTarget(nameStr, &target, &target_guid, &target_name))
        return false;

        int32 oldlevel = target ? target->getLevel() : Player::GetLevelFromDB(target_guid);
        int32 newlevel = levelStr ? atoi(levelStr) : oldlevel;

        if (newlevel < 1)
            return false;                                       // invalid level

        if (newlevel > STRONG_MAX_LEVEL)                         // hardcoded maximum level
            newlevel = STRONG_MAX_LEVEL;

        handler->HandleCharacterLevel(target, target_guid, oldlevel, newlevel);
        if (!handler->GetSession() || handler->GetSession()->GetPlayer() != target)      // including player == NULL
        {
            std::string nameLink = handler->playerLink(target_name);
            handler->PSendSysMessage(LANG_YOU_CHANGE_LVL, nameLink.c_str(), newlevel);
        }

        return true;
    }

    // customize characters
    static bool HandleCharacterCustomizeCommand(ChatHandler* handler, char const* args)
    {
        Player* target;
        uint64 targetGuid;
        std::string targetName;
        if (!handler->extractPlayerTarget((char*)args, &target, &targetGuid, &targetName))
            return false;

        PreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_UPD_ADD_AT_LOGIN_FLAG);
        stmt->setUInt16(0, uint16(AT_LOGIN_CUSTOMIZE));
        if (target)
        {
            handler->PSendSysMessage(LANG_CUSTOMIZE_PLAYER, handler->GetNameLink(target).c_str());
            target->SetAtLoginFlag(AT_LOGIN_CUSTOMIZE);
            stmt->setUInt32(1, target->GetGUIDLow());
        }
        else
        {
            std::string oldNameLink = handler->playerLink(targetName);
            stmt->setUInt32(1, GUID_LOPART(targetGuid));
            handler->PSendSysMessage(LANG_CUSTOMIZE_PLAYER_GUID, oldNameLink.c_str(), GUID_LOPART(targetGuid));
        }
        CharacterDatabase.Execute(stmt);

        return true;
    }

    static bool HandleCharacterChangeFactionCommand(ChatHandler* handler, char const* args)
    {
        Player* target;
        uint64 targetGuid;
        std::string targetName;

        if (!handler->extractPlayerTarget((char*)args, &target, &targetGuid, &targetName))
            return false;

        PreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_UPD_ADD_AT_LOGIN_FLAG);
        stmt->setUInt16(0, uint16(AT_LOGIN_CHANGE_FACTION));
        if (target)
        {
            handler->PSendSysMessage(LANG_CUSTOMIZE_PLAYER, handler->GetNameLink(target).c_str());
            target->SetAtLoginFlag(AT_LOGIN_CHANGE_FACTION);
            stmt->setUInt32(1, target->GetGUIDLow());
        }
        else
        {
            std::string oldNameLink = handler->playerLink(targetName);
            handler->PSendSysMessage(LANG_CUSTOMIZE_PLAYER_GUID, oldNameLink.c_str(), GUID_LOPART(targetGuid));
            stmt->setUInt32(1, GUID_LOPART(targetGuid));
        }
        CharacterDatabase.Execute(stmt);

        return true;
    }

    static bool HandleCharacterChangeRaceCommand(ChatHandler* handler, char const* args)
    {
        Player* target;
        uint64 targetGuid;
        std::string targetName;
        if (!handler->extractPlayerTarget((char*)args, &target, &targetGuid, &targetName))
            return false;

        PreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_UPD_ADD_AT_LOGIN_FLAG);
        stmt->setUInt16(0, uint16(AT_LOGIN_CHANGE_RACE));
        if (target)
        {
            // TODO : add text into database
            handler->PSendSysMessage(LANG_CUSTOMIZE_PLAYER, handler->GetNameLink(target).c_str());
            target->SetAtLoginFlag(AT_LOGIN_CHANGE_RACE);
            stmt->setUInt32(1, target->GetGUIDLow());
        }
        else
        {
            std::string oldNameLink = handler->playerLink(targetName);
            // TODO : add text into database
            handler->PSendSysMessage(LANG_CUSTOMIZE_PLAYER_GUID, oldNameLink.c_str(), GUID_LOPART(targetGuid));
            stmt->setUInt32(1, GUID_LOPART(targetGuid));
        }
        CharacterDatabase.Execute(stmt);

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
            const FactionState& faction = itr->second;
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
            // Drop not existed account cases
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
            Player::DeleteFromDB(itr->lowguid, 0, false, true);

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
    static bool HandleCharacterDeletedOldCommand(ChatHandler* handler, char const* args)
    {
        int32 keepDays = sWorld->getIntConfig(CONFIG_CHARDELETE_KEEP_DAYS);

        char* px = strtok((char*)args, " ");
        if (px)
        {
            if (!isNumeric(px))
                return false;

            keepDays = atoi(px);
            if (keepDays < 0)
                return false;
        }
        // config option value 0 -> disabled and can't be used
        else if (keepDays <= 0)
            return false;

        Player::DeleteOldCharacters((uint32)keepDays);
        return true;
    }

    static bool HandleCharacterEraseCommand(ChatHandler* handler, char const* args)
    {
        if (!*args)
            return false;

        char *character_name_str = strtok((char*)args, " ");
        if (!character_name_str)
            return false;

        std::string character_name = character_name_str;
        if (!normalizePlayerName(character_name))
            return false;

        uint64 character_guid;
        uint32 account_id;

        Player* player = sObjectAccessor->FindPlayerByName(character_name.c_str());
        if (player)
        {
            character_guid = player->GetGUID();
            account_id = player->GetSession()->GetAccountId();
            player->GetSession()->KickPlayer();
        }
        else
        {
            character_guid = sObjectMgr->GetPlayerGUIDByName(character_name);
            if (!character_guid)
            {
                handler->PSendSysMessage(LANG_NO_PLAYER, character_name.c_str());
                handler->SetSentErrorMessage(true);
                return false;
            }
            account_id = sObjectMgr->GetPlayerAccountIdByGUID(character_guid);
        }

        std::string account_name;
        AccountMgr::GetName (account_id, account_name);

        Player::DeleteFromDB(character_guid, account_id, true, true);
        handler->PSendSysMessage(LANG_CHARACTER_DELETED, character_name.c_str(), GUID_LOPART(character_guid), account_name.c_str(), account_id);
        return true;
    }
};

void AddSC_character_commandscript()
{
    new character_commandscript();
}