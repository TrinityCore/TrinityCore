/*
 * Copyright (C) 2008-2012 TrinityCore <http://www.trinitycore.org/>
 * Copyright (C) 2005-2009 MaNGOS <http://getmangos.com/>
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

#if PLATFORM != PLATFORM_WINDOWS
#include <readline/readline.h>
#include <readline/history.h>

char * command_finder(const char* text, int state)
{
    static int idx, len;
    const char* ret;
    ChatCommand* cmd = ChatHandler::getCommandTable();

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
        matches = rl_completion_matches((char*)text, &command_finder);
    else
        rl_bind_key('\t', rl_abort);
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
    if (!Utf8toWStr(str, strlen(str), wtemp_buf, wtemp_len))
        return;

    char temp_buf[6000];
    CharToOemBuffW(&wtemp_buf[0], &temp_buf[0], wtemp_len+1);
    printf(temp_buf);
#else
{
    printf("%s", str);
    fflush(stdout);
}
#endif
}

void commandFinished(void*, bool /*success*/)
{
    printf("TC> ");
    fflush(stdout);
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
            wherestr << "', '";
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
    uint32 charcount = AccountMgr::GetCharactersCount(delInfo.accountId);
    if (charcount >= 10)
    {
        PSendSysMessage(LANG_CHARACTER_DELETED_SKIP_FULL, delInfo.name.c_str(), delInfo.lowguid, delInfo.accountId);
        return;
    }

    if (sObjectMgr->GetPlayerGUIDByName(delInfo.name))
    {
        PSendSysMessage(LANG_CHARACTER_DELETED_SKIP_NAME, delInfo.name.c_str(), delInfo.lowguid, delInfo.accountId);
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
    //sLog->outString("");
#if PLATFORM != PLATFORM_WINDOWS
    rl_attempted_completion_function = cli_completion;
    rl_event_hook = cli_hook_func;
#endif

    if (ConfigMgr::GetBoolDefault("BeepAtStart", true))
        printf("\a");                                       // \a = Alert

    // print this here the first time
    // later it will be printed after command queue updates
    printf("TC>");

    ///- As long as the World is running (no World::m_stopEvent), get the command line and handle it
    while (!World::IsStopped())
    {
        fflush(stdout);

        char *command_str ;             // = fgets(commandbuf, sizeof(commandbuf), stdin);

#if PLATFORM == PLATFORM_WINDOWS
        char commandbuf[256];
        command_str = fgets(commandbuf, sizeof(commandbuf), stdin);
#else
        command_str = readline("TC>");
        rl_bind_key('\t', rl_complete);
#endif

        if (command_str != NULL)
        {
            for (int x=0; command_str[x]; ++x)
                if (command_str[x] == '\r' || command_str[x] == '\n')
                {
                    command_str[x] = 0;
                    break;
                }

            if (!*command_str)
            {
#if PLATFORM == PLATFORM_WINDOWS
                printf("TC>");
#endif
                continue;
            }

            std::string command;
            if (!consoleToUtf8(command_str, command))         // convert from console encoding to utf8
            {
#if PLATFORM == PLATFORM_WINDOWS
                printf("TC>");
#endif
                continue;
            }

            fflush(stdout);
            sWorld->QueueCliCommand(new CliCommandHolder(NULL, command.c_str(), &utf8print, &commandFinished));
#if PLATFORM != PLATFORM_WINDOWS
            add_history(command.c_str());
#endif
        }
        else if (feof(stdin))
        {
            World::StopNow(SHUTDOWN_EXIT_CODE);
        }
    }
}
