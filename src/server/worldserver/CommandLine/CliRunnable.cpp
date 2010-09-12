/*
 * Copyright (C) 2005-2009 MaNGOS <http://getmangos.com/>
 *
 * Copyright (C) 2008-2010 Trinity <http://www.trinitycore.org/>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

/// \addtogroup Trinityd
/// @{
/// \file

#include "Common.h"
#include "ObjectMgr.h"
#include "World.h"
#include "WorldSession.h"
#include "Configuration/Config.h"

#include "AccountMgr.h"
#include "Chat.h"
#include "CliRunnable.h"
#include "Language.h"
#include "Log.h"
#include "MapManager.h"
#include "Player.h"
#include "Util.h"

#if PLATFORM != WINDOWS
#include <readline/readline.h>
#include <readline/history.h>

char * command_finder(const char* text, int state)
{
    static int idx,len;
    const char* ret;
    ChatCommand *cmd = ChatHandler::getCommandTable();

    if (!state)
    {
        idx = 0;
        len = strlen(text);
    }

    while ((ret = cmd[idx].Name))
    {
        if (!cmd[idx].AllowConsole)
        {
            idx++;
            continue;
        }

        idx++;
        //printf("Checking %s \n", cmd[idx].Name);
        if (strncmp(ret, text, len) == 0)
            return strdup(ret);
        if (cmd[idx].Name == NULL)
            break;
    }

    return ((char*)NULL);
}

char ** cli_completion(const char * text, int start, int /*end*/)
{
    char ** matches;
    matches = (char**)NULL;

    if (start == 0)
        matches = rl_completion_matches((char*)text,&command_finder);
    else
        rl_bind_key('\t',rl_abort);
    return (matches);
}

int cli_hook_func(void)
{
       if (World::IsStopped())
           rl_done = 1;
       return 0;
}

#endif

void utf8print(void* /*arg*/, const char* str)
{
#if PLATFORM == PLATFORM_WINDOWS
    wchar_t wtemp_buf[6000];
    size_t wtemp_len = 6000-1;
    if (!Utf8toWStr(str,strlen(str),wtemp_buf,wtemp_len))
        return;

    char temp_buf[6000];
    CharToOemBuffW(&wtemp_buf[0],&temp_buf[0],wtemp_len+1);
    printf(temp_buf);
#else
{
    va_list v = NULL;
    vprintf(str, v);
    va_end(v);
    fflush(stdout);
}
#endif
}

void commandFinished(void*, bool /*success*/)
{
    printf("TC> ");
    fflush(stdout);
}
/// Delete a user account and all associated characters in this realm
/// \todo This function has to be enhanced to respect the login/realm split (delete char, delete account chars in realm, delete account chars in realm then delete account
bool ChatHandler::HandleAccountDeleteCommand(const char* args)
{
    if (!*args)
        return false;

    ///- Get the account name from the command line
    char *account_name_str=strtok ((char*)args," ");
    if (!account_name_str)
        return false;

    std::string account_name = account_name_str;
    if (!AccountMgr::normalizeString(account_name))
    {
        PSendSysMessage(LANG_ACCOUNT_NOT_EXIST,account_name.c_str());
        SetSentErrorMessage(true);
        return false;
    }

    uint32 account_id = sAccountMgr.GetId(account_name);
    if (!account_id)
    {
        PSendSysMessage(LANG_ACCOUNT_NOT_EXIST,account_name.c_str());
        SetSentErrorMessage(true);
        return false;
    }

    /// Commands not recommended call from chat, but support anyway
    /// can delete only for account with less security
    /// This is also reject self apply in fact
    if (HasLowerSecurityAccount (NULL,account_id,true))
        return false;

    AccountOpResult result = sAccountMgr.DeleteAccount(account_id);
    switch(result)
    {
        case AOR_OK:
            PSendSysMessage(LANG_ACCOUNT_DELETED,account_name.c_str());
            break;
        case AOR_NAME_NOT_EXIST:
            PSendSysMessage(LANG_ACCOUNT_NOT_EXIST,account_name.c_str());
            SetSentErrorMessage(true);
            return false;
        case AOR_DB_INTERNAL_ERROR:
            PSendSysMessage(LANG_ACCOUNT_NOT_DELETED_SQL_ERROR,account_name.c_str());
            SetSentErrorMessage(true);
            return false;
        default:
            PSendSysMessage(LANG_ACCOUNT_NOT_DELETED,account_name.c_str());
            SetSentErrorMessage(true);
            return false;
    }

    return true;
}

/**
 * Collects all GUIDs (and related info) from deleted characters which are still in the database.
 *
 * @param foundList    a reference to an std::list which will be filled with info data
 * @param searchString the search string which either contains a player GUID or a part fo the character-name
 * @return             returns false if there was a problem while selecting the characters (e.g. player name not normalizeable)
 */
bool ChatHandler::GetDeletedCharacterInfoList(DeletedInfoList& foundList, std::string searchString)
{
    QueryResult resultChar;
    if (!searchString.empty())
    {
        // search by GUID
        if (isNumeric(searchString.c_str()))
            resultChar = CharacterDatabase.PQuery("SELECT guid, deleteInfos_Name, deleteInfos_Account, deleteDate FROM characters WHERE deleteDate IS NOT NULL AND guid = %u", uint64(atoi(searchString.c_str())));
        // search by name
        else
        {
            if (!normalizePlayerName(searchString))
                return false;

            resultChar = CharacterDatabase.PQuery("SELECT guid, deleteInfos_Name, deleteInfos_Account, deleteDate FROM characters WHERE deleteDate IS NOT NULL AND deleteInfos_Name " _LIKE_ " " _CONCAT3_("'%%'", "'%s'", "'%%'"), searchString.c_str());
        }
    }
    else
        resultChar = CharacterDatabase.Query("SELECT guid, deleteInfos_Name, deleteInfos_Account, deleteDate FROM characters WHERE deleteDate IS NOT NULL");

    if (resultChar)
    {
        do
        {
            Field* fields = resultChar->Fetch();

            DeletedInfo info;

            info.lowguid    = fields[0].GetUInt32();
            info.name       = fields[1].GetCppString();
            info.accountId  = fields[2].GetUInt32();

            // account name will be empty for not existed account
            sAccountMgr.GetName(info.accountId, info.accountName);

            info.deleteDate = time_t(fields[3].GetUInt64());

            foundList.push_back(info);
        } while (resultChar->NextRow());
    }

    return true;
}

/**
 * Generate WHERE guids list by deleted info in way preventing return too long where list for existed query string length limit.
 *
 * @param itr          a reference to an deleted info list iterator, it updated in function for possible next function call if list to long
 * @param itr_end      a reference to an deleted info list iterator end()
 * @return             returns generated where list string in form: 'guid IN (gui1, guid2, ...)'
 */
std::string ChatHandler::GenerateDeletedCharacterGUIDsWhereStr(DeletedInfoList::const_iterator& itr, DeletedInfoList::const_iterator const& itr_end)
{
    std::ostringstream wherestr;
    wherestr << "guid IN ('";
    for (; itr != itr_end; ++itr)
    {
        wherestr << itr->lowguid;

        if (wherestr.str().size() > MAX_QUERY_LEN - 50)     // near to max query
        {
            ++itr;
            break;
        }

        DeletedInfoList::const_iterator itr2 = itr;
        if (++itr2 != itr_end)
            wherestr << "','";
    }
    wherestr << "')";
    return wherestr.str();
}

/**
 * Shows all deleted characters which matches the given search string, expected non empty list
 *
 * @see ChatHandler::HandleCharacterDeletedListCommand
 * @see ChatHandler::HandleCharacterDeletedRestoreCommand
 * @see ChatHandler::HandleCharacterDeletedDeleteCommand
 * @see ChatHandler::DeletedInfoList
 *
 * @param foundList contains a list with all found deleted characters
 */
void ChatHandler::HandleCharacterDeletedListHelper(DeletedInfoList const& foundList)
{
    if (!m_session)
    {
        SendSysMessage(LANG_CHARACTER_DELETED_LIST_BAR);
        SendSysMessage(LANG_CHARACTER_DELETED_LIST_HEADER);
        SendSysMessage(LANG_CHARACTER_DELETED_LIST_BAR);
    }

    for (DeletedInfoList::const_iterator itr = foundList.begin(); itr != foundList.end(); ++itr)
    {
        std::string dateStr = TimeToTimestampStr(itr->deleteDate);

        if (!m_session)
            PSendSysMessage(LANG_CHARACTER_DELETED_LIST_LINE_CONSOLE,
                itr->lowguid, itr->name.c_str(), itr->accountName.empty() ? "<Not existed>" : itr->accountName.c_str(),
                itr->accountId, dateStr.c_str());
        else
            PSendSysMessage(LANG_CHARACTER_DELETED_LIST_LINE_CHAT,
                itr->lowguid, itr->name.c_str(), itr->accountName.empty() ? "<Not existed>" : itr->accountName.c_str(),
                itr->accountId, dateStr.c_str());
    }

    if (!m_session)
        SendSysMessage(LANG_CHARACTER_DELETED_LIST_BAR);
}

/**
 * Handles the '.character deleted list' command, which shows all deleted characters which matches the given search string
 *
 * @see ChatHandler::HandleCharacterDeletedListHelper
 * @see ChatHandler::HandleCharacterDeletedRestoreCommand
 * @see ChatHandler::HandleCharacterDeletedDeleteCommand
 * @see ChatHandler::DeletedInfoList
 *
 * @param args the search string which either contains a player GUID or a part fo the character-name
 */
bool ChatHandler::HandleCharacterDeletedListCommand(const char* args)
{
    DeletedInfoList foundList;
    if (!GetDeletedCharacterInfoList(foundList, args))
        return false;

    // if no characters have been found, output a warning
    if (foundList.empty())
    {
        SendSysMessage(LANG_CHARACTER_DELETED_LIST_EMPTY);
        return false;
    }

    HandleCharacterDeletedListHelper(foundList);
    return true;
}

/**
 * Restore a previously deleted character
 *
 * @see ChatHandler::HandleCharacterDeletedListHelper
 * @see ChatHandler::HandleCharacterDeletedRestoreCommand
 * @see ChatHandler::HandleCharacterDeletedDeleteCommand
 * @see ChatHandler::DeletedInfoList
 *
 * @param delInfo the informations about the character which will be restored
 */
void ChatHandler::HandleCharacterDeletedRestoreHelper(DeletedInfo const& delInfo)
{
    if (delInfo.accountName.empty())                    // account not exist
    {
        PSendSysMessage(LANG_CHARACTER_DELETED_SKIP_ACCOUNT, delInfo.name.c_str(), delInfo.lowguid, delInfo.accountId);
        return;
    }

    // check character count
    uint32 charcount = sAccountMgr.GetCharactersCount(delInfo.accountId);
    if (charcount >= 10)
    {
        PSendSysMessage(LANG_CHARACTER_DELETED_SKIP_FULL, delInfo.name.c_str(), delInfo.lowguid, delInfo.accountId);
        return;
    }

    if (sObjectMgr.GetPlayerGUIDByName(delInfo.name))
    {
        PSendSysMessage(LANG_CHARACTER_DELETED_SKIP_NAME, delInfo.name.c_str(), delInfo.lowguid, delInfo.accountId);
        return;
    }

    CharacterDatabase.PExecute("UPDATE characters SET name='%s', account='%u', deleteDate=NULL, deleteInfos_Name=NULL, deleteInfos_Account=NULL WHERE deleteDate IS NOT NULL AND guid = %u",
        delInfo.name.c_str(), delInfo.accountId, delInfo.lowguid);
}

/**
 * Handles the '.character deleted restore' command, which restores all deleted characters which matches the given search string
 *
 * The command automatically calls '.character deleted list' command with the search string to show all restored characters.
 *
 * @see ChatHandler::HandleCharacterDeletedRestoreHelper
 * @see ChatHandler::HandleCharacterDeletedListCommand
 * @see ChatHandler::HandleCharacterDeletedDeleteCommand
 *
 * @param args the search string which either contains a player GUID or a part of the character-name
 */
bool ChatHandler::HandleCharacterDeletedRestoreCommand(const char* args)
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
        SendSysMessage(LANG_CHARACTER_DELETED_LIST_EMPTY);
        return false;
    }

    SendSysMessage(LANG_CHARACTER_DELETED_RESTORE);
    HandleCharacterDeletedListHelper(foundList);

    if (newCharName.empty())
    {
        // Drop not existed account cases
        for (DeletedInfoList::iterator itr = foundList.begin(); itr != foundList.end(); ++itr)
            HandleCharacterDeletedRestoreHelper(*itr);
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
            sAccountMgr.GetName(newAccount, delInfo.accountName);
        }

        HandleCharacterDeletedRestoreHelper(delInfo);
    }
    else
        SendSysMessage(LANG_CHARACTER_DELETED_ERR_RENAME);

    return true;
}

/**
 * Handles the '.character deleted delete' command, which completely deletes all deleted characters which matches the given search string
 *
 * @see Player::GetDeletedCharacterGUIDs
 * @see Player::DeleteFromDB
 * @see ChatHandler::HandleCharacterDeletedListCommand
 * @see ChatHandler::HandleCharacterDeletedRestoreCommand
 *
 * @param args the search string which either contains a player GUID or a part fo the character-name
 */
bool ChatHandler::HandleCharacterDeletedDeleteCommand(const char* args)
{
    // It is required to submit at least one argument
    if (!*args)
        return false;

    DeletedInfoList foundList;
    if (!GetDeletedCharacterInfoList(foundList, args))
        return false;

    if (foundList.empty())
    {
        SendSysMessage(LANG_CHARACTER_DELETED_LIST_EMPTY);
        return false;
    }

    SendSysMessage(LANG_CHARACTER_DELETED_DELETE);
    HandleCharacterDeletedListHelper(foundList);

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
 * @see ChatHandler::HandleCharacterDeletedDeleteCommand
 * @see ChatHandler::HandleCharacterDeletedListCommand
 * @see ChatHandler::HandleCharacterDeletedRestoreCommand
 *
 * @param args the search string which either contains a player GUID or a part fo the character-name
 */
bool ChatHandler::HandleCharacterDeletedOldCommand(const char* args)
{
    int32 keepDays = sWorld.getIntConfig(CONFIG_CHARDELETE_KEEP_DAYS);

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

bool ChatHandler::HandleCharacterEraseCommand(const char* args){
    if (!*args)
        return false;

    char *character_name_str = strtok((char*)args," ");
    if (!character_name_str)
        return false;

    std::string character_name = character_name_str;
    if (!normalizePlayerName(character_name))
        return false;

    uint64 character_guid;
    uint32 account_id;

    Player *player = sObjectMgr.GetPlayer(character_name.c_str());
    if (player)
    {
        character_guid = player->GetGUID();
        account_id = player->GetSession()->GetAccountId();
        player->GetSession()->KickPlayer();
    }
    else
    {
        character_guid = sObjectMgr.GetPlayerGUIDByName(character_name);
        if (!character_guid)
        {
            PSendSysMessage(LANG_NO_PLAYER,character_name.c_str());
            SetSentErrorMessage(true);
            return false;
        }

        account_id = sObjectMgr.GetPlayerAccountIdByGUID(character_guid);
    }

    std::string account_name;
    sAccountMgr.GetName (account_id,account_name);

    Player::DeleteFromDB(character_guid, account_id, true, true);
    PSendSysMessage(LANG_CHARACTER_DELETED,character_name.c_str(),GUID_LOPART(character_guid),account_name.c_str(), account_id);
    return true;
}

/// Exit the realm
bool ChatHandler::HandleServerExitCommand(const char* /*args*/)
{
    SendSysMessage(LANG_COMMAND_EXIT);
    World::StopNow(SHUTDOWN_EXIT_CODE);
    return true;
}

/// Display info on users currently in the realm
bool ChatHandler::HandleAccountOnlineListCommand(const char* /*args*/)
{
    ///- Get the list of accounts ID logged to the realm
    QueryResult resultDB = CharacterDatabase.Query("SELECT name,account,map,zone FROM characters WHERE online > 0");
    if (!resultDB)
    {
        SendSysMessage(LANG_ACCOUNT_LIST_EMPTY);
        return true;
    }

    ///- Display the list of account/characters online
    SendSysMessage(LANG_ACCOUNT_LIST_BAR_HEADER);
    SendSysMessage(LANG_ACCOUNT_LIST_HEADER);
    SendSysMessage(LANG_ACCOUNT_LIST_BAR);

    ///- Circle through accounts
    do
    {
        Field *fieldsDB = resultDB->Fetch();
        std::string name = fieldsDB[0].GetCppString();
        uint32 account = fieldsDB[1].GetUInt32();

        ///- Get the username, last IP and GM level of each account
        // No SQL injection. account is uint32.
        QueryResult resultLogin =
            LoginDatabase.PQuery("SELECT a.username, a.last_ip, aa.gmlevel, a.expansion "
                                 "FROM account a "
                                 "LEFT JOIN account_access aa "
                                 "ON (a.id = aa.id) "
                                 "WHERE a.id = '%u'", account);
        if (resultLogin)
        {
            Field *fieldsLogin = resultLogin->Fetch();
            PSendSysMessage(LANG_ACCOUNT_LIST_LINE,
                fieldsLogin[0].GetString(),name.c_str(),fieldsLogin[1].GetString(),fieldsDB[2].GetInt32(),fieldsDB[3].GetInt32(),fieldsLogin[3].GetUInt32(),fieldsLogin[2].GetUInt32());
        }
        else
            PSendSysMessage(LANG_ACCOUNT_LIST_ERROR,name.c_str());

    }while (resultDB->NextRow());

    SendSysMessage(LANG_ACCOUNT_LIST_BAR);
    return true;
}

/// Create an account
bool ChatHandler::HandleAccountCreateCommand(const char* args)
{
    if (!*args)
        return false;

    ///- %Parse the command line arguments
    char *szAcc = strtok((char*)args, " ");
    char *szPassword = strtok(NULL, " ");
    if (!szAcc || !szPassword)
        return false;

    // normalized in sAccountMgr.CreateAccount
    std::string account_name = szAcc;
    std::string password = szPassword;

    AccountOpResult result = sAccountMgr.CreateAccount(account_name, password);
    switch(result)
    {
        case AOR_OK:
            PSendSysMessage(LANG_ACCOUNT_CREATED,account_name.c_str());
            break;
        case AOR_NAME_TOO_LONG:
            SendSysMessage(LANG_ACCOUNT_TOO_LONG);
            SetSentErrorMessage(true);
            return false;
        case AOR_NAME_ALREDY_EXIST:
            SendSysMessage(LANG_ACCOUNT_ALREADY_EXIST);
            SetSentErrorMessage(true);
            return false;
        case AOR_DB_INTERNAL_ERROR:
            PSendSysMessage(LANG_ACCOUNT_NOT_CREATED_SQL_ERROR,account_name.c_str());
            SetSentErrorMessage(true);
            return false;
        default:
            PSendSysMessage(LANG_ACCOUNT_NOT_CREATED,account_name.c_str());
            SetSentErrorMessage(true);
            return false;
    }

    return true;
}

/// Set the level of logging
bool ChatHandler::HandleServerSetLogFileLevelCommand(const char *args)
{
    if (!*args)
        return false;

    char *NewLevel = strtok((char*)args, " ");
    if (!NewLevel)
        return false;

    sLog.SetLogFileLevel(NewLevel);
    return true;
}

/// Set the level of logging
bool ChatHandler::HandleServerSetLogLevelCommand(const char *args)
{
    if (!*args)
        return false;

    char *NewLevel = strtok((char*)args, " ");
    if (!NewLevel)
        return false;

    sLog.SetLogLevel(NewLevel);
    return true;
}

/// set diff time record interval
bool ChatHandler::HandleServerSetDiffTimeCommand(const char *args)
{
    if (!*args)
        return false;

    char *NewTimeStr = strtok((char*)args, " ");
    if (!NewTimeStr)
        return false;

    int32 NewTime =atoi(NewTimeStr);
    if (NewTime < 0)
        return false;

    sWorld.SetRecordDiffInterval(NewTime);
    printf( "Record diff every %u ms\n", NewTime);
    return true;
}

/// @}

#ifdef linux
// Non-blocking keypress detector, when return pressed, return 1, else always return 0
int kb_hit_return()
{
    struct timeval tv;
    fd_set fds;
    tv.tv_sec = 0;
    tv.tv_usec = 0;
    FD_ZERO(&fds);
    FD_SET(STDIN_FILENO, &fds);
    select(STDIN_FILENO+1, &fds, NULL, NULL, &tv);
    return FD_ISSET(STDIN_FILENO, &fds);
}
#endif

/// %Thread start
void CliRunnable::run()
{
    ///- Display the list of available CLI functions then beep
    //sLog.outString("");
    #if PLATFORM != WINDOWS
    rl_attempted_completion_function = cli_completion;
    rl_event_hook = cli_hook_func;
    #endif
    if (sConfig.GetBoolDefault("BeepAtStart", true))
        printf("\a");                                       // \a = Alert

    // print this here the first time
    // later it will be printed after command queue updates
    printf("TC>");

    ///- As long as the World is running (no World::m_stopEvent), get the command line and handle it
    while (!World::IsStopped())
    {
        fflush(stdout);

        char *command_str ;             // = fgets(commandbuf,sizeof(commandbuf),stdin);

        #if PLATFORM == WINDOWS
        char commandbuf[256];
        command_str = fgets(commandbuf,sizeof(commandbuf),stdin);
        #else
        command_str = readline("TC>");
        rl_bind_key('\t',rl_complete);
        #endif
        if (command_str != NULL)
        {
            for (int x=0; command_str[x]; x++)
                if (command_str[x]=='\r'||command_str[x]=='\n')
                {
                    command_str[x]=0;
                    break;
                }

            if (!*command_str)
            {
                #if PLATFORM == WINDOWS
                printf("TC>");
                #endif
                continue;
            }

            std::string command;
            if (!consoleToUtf8(command_str,command))         // convert from console encoding to utf8
            {
                #if PLATFORM == WINDOWS
                printf("TC>");
                #endif
                continue;
            }
            fflush(stdout);
            sWorld.QueueCliCommand(new CliCommandHolder(NULL, command.c_str(), &utf8print, &commandFinished));
            #if PLATFORM != WINDOWS
            add_history(command.c_str());
            #endif

        }
        else if (feof(stdin))
        {
            World::StopNow(SHUTDOWN_EXIT_CODE);
        }

    }
}
