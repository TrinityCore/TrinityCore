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

/// \addtogroup Trinityd
/// @{
/// \file

#include "Common.h"
#include "ObjectMgr.h"
#include "World.h"
#include "Configuration/Config.h"

#include "CliRunnable.h"
#include "Log.h"
#include "Util.h"

#if TRINITY_PLATFORM != TRINITY_PLATFORM_WINDOWS
#include <readline/readline.h>
#include <readline/history.h>
#include "Chat.h"

char* command_finder(char const* text, int state)
{
    static size_t idx, len;
    char const* ret;
    std::vector<ChatCommand> const& cmd = ChatHandler::getCommandTable();

    if (!state)
    {
        idx = 0;
        len = strlen(text);
    }

    while (idx < cmd.size())
    {
        ret = cmd[idx].Name;
        if (!cmd[idx].AllowConsole)
        {
            ++idx;
            continue;
        }

        ++idx;
        //printf("Checking %s \n", cmd[idx].Name);
        if (strncmp(ret, text, len) == 0)
            return strdup(ret);
    }

    return ((char*)nullptr);
}

char** cli_completion(char const* text, int start, int /*end*/)
{
    char** matches = nullptr;

    if (start)
        rl_bind_key('\t', rl_abort);
    else
        matches = rl_completion_matches((char*)text, &command_finder);
    return matches;
}

int cli_hook_func()
{
       if (World::IsStopped())
           rl_done = 1;
       return 0;
}

#endif

void utf8print(void* /*arg*/, char const* str)
{
#if TRINITY_PLATFORM == TRINITY_PLATFORM_WINDOWS
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
    select(STDIN_FILENO+1, &fds, nullptr, nullptr, &tv);
    return FD_ISSET(STDIN_FILENO, &fds);
}
#endif

/// %Thread start
void CliThread()
{
    ///- Display the list of available CLI functions then beep
    //TC_LOG_INFO("server.worldserver", "");
#if TRINITY_PLATFORM != TRINITY_PLATFORM_WINDOWS
    rl_attempted_completion_function = cli_completion;
    rl_event_hook = cli_hook_func;
#endif

    if (sConfigMgr->GetBoolDefault("BeepAtStart", true))
        printf("\a");                                       // \a = Alert

    // print this here the first time
    // later it will be printed after command queue updates
    printf("TC>");

    ///- As long as the World is running (no World::m_stopEvent), get the command line and handle it
    while (!World::IsStopped())
    {
        fflush(stdout);

        char *command_str ;             // = fgets(commandbuf, sizeof(commandbuf), stdin);

#if TRINITY_PLATFORM == TRINITY_PLATFORM_WINDOWS
        char commandbuf[256];
        command_str = fgets(commandbuf, sizeof(commandbuf), stdin);
#else
        command_str = readline("TC>");
        rl_bind_key('\t', rl_complete);
#endif

        if (command_str != nullptr)
        {
            for (int x=0; command_str[x]; ++x)
                if (command_str[x] == '\r' || command_str[x] == '\n')
                {
                    command_str[x] = 0;
                    break;
                }

            if (!*command_str)
            {
#if TRINITY_PLATFORM == TRINITY_PLATFORM_WINDOWS
                printf("TC>");
#else
                free(command_str);
#endif
                continue;
            }

            std::string command;
            if (!consoleToUtf8(command_str, command))         // convert from console encoding to utf8
            {
#if TRINITY_PLATFORM == TRINITY_PLATFORM_WINDOWS
                printf("TC>");
#else
                free(command_str);
#endif
                continue;
            }

            fflush(stdout);
            sWorld->QueueCliCommand(new CliCommandHolder(nullptr, command.c_str(), &utf8print, &commandFinished));
#if TRINITY_PLATFORM != TRINITY_PLATFORM_WINDOWS
            add_history(command.c_str());
            free(command_str);
#endif
        }
        else if (feof(stdin))
        {
            World::StopNow(SHUTDOWN_EXIT_CODE);
        }
    }
}
