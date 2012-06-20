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
Name: server_commandscript
%Complete: 100
Comment: All server related commands
Category: commandscripts
EndScriptData */

#include "ScriptMgr.h"
#include "Chat.h"
#include "SystemConfig.h"
#include "Config.h"

class server_commandscript : public CommandScript
{
public:
    server_commandscript() : CommandScript("server_commandscript") { }

    ChatCommand* GetCommands() const
    {
        static ChatCommand serverIdleRestartCommandTable[] =
        {
            { "cancel",         SEC_ADMINISTRATOR,  true,  &HandleServerShutDownCancelCommand, "", NULL },
            { ""   ,            SEC_ADMINISTRATOR,  true,  &HandleServerIdleRestartCommand,    "", NULL },
            { NULL,             0,                  false, NULL,                               "", NULL }
        };

        static ChatCommand serverIdleShutdownCommandTable[] =
        {
            { "cancel",         SEC_ADMINISTRATOR,  true,  &HandleServerShutDownCancelCommand, "", NULL },
            { ""   ,            SEC_ADMINISTRATOR,  true,  &HandleServerIdleShutDownCommand,   "", NULL },
            { NULL,             0,                  false, NULL,                               "", NULL }
        };

        static ChatCommand serverRestartCommandTable[] =
        {
            { "cancel",         SEC_ADMINISTRATOR,  true,  &HandleServerShutDownCancelCommand, "", NULL },
            { ""   ,            SEC_ADMINISTRATOR,  true,  &HandleServerRestartCommand,        "", NULL },
            { NULL,             0,                  false, NULL,                               "", NULL }
        };

        static ChatCommand serverShutdownCommandTable[] =
            {
            { "cancel",         SEC_ADMINISTRATOR,  true,  &HandleServerShutDownCancelCommand, "", NULL },
            { ""   ,            SEC_ADMINISTRATOR,  true,  &HandleServerShutDownCommand,       "", NULL },
            { NULL,             0,                  false, NULL,                               "", NULL }
        };

        static ChatCommand serverSetCommandTable[] =
        {
            { "difftime",       SEC_CONSOLE,        true,  &HandleServerSetDiffTimeCommand,       "", NULL },
            { "loglevel",       SEC_CONSOLE,        true,  &HandleServerSetLogLevelCommand,       "", NULL },
            { "logfilelevel",   SEC_CONSOLE,        true,  &HandleServerSetLogFileLevelCommand,   "", NULL },
            { "motd",           SEC_ADMINISTRATOR,  true,  &HandleServerSetMotdCommand,           "", NULL },
            { "closed",         SEC_ADMINISTRATOR,  true,  &HandleServerSetClosedCommand,         "", NULL },
            { NULL,             0,                  false, NULL,                                  "", NULL }
        };

        static ChatCommand serverCommandTable[] =
        {
            { "corpses",        SEC_GAMEMASTER,     true,  &HandleServerCorpsesCommand,           "", NULL },
            { "exit",           SEC_CONSOLE,        true,  &HandleServerExitCommand,              "", NULL },
            { "idlerestart",    SEC_ADMINISTRATOR,  true,  NULL,         "", serverIdleRestartCommandTable },
            { "idleshutdown",   SEC_ADMINISTRATOR,  true,  NULL,        "", serverIdleShutdownCommandTable },
            { "info",           SEC_PLAYER,         true,  &HandleServerInfoCommand,              "", NULL },
            { "motd",           SEC_PLAYER,         true,  &HandleServerMotdCommand,              "", NULL },
            { "plimit",         SEC_ADMINISTRATOR,  true,  &HandleServerPLimitCommand,            "", NULL },
            { "restart",        SEC_ADMINISTRATOR,  true,  NULL,             "", serverRestartCommandTable },
            { "shutdown",       SEC_ADMINISTRATOR,  true,  NULL,            "", serverShutdownCommandTable },
            { "set",            SEC_ADMINISTRATOR,  true,  NULL,                 "", serverSetCommandTable },
            { "togglequerylog", SEC_CONSOLE,        true,  &HandleServerToggleQueryLogging,       "", NULL },
            { NULL,             0,                  false, NULL,                                  "", NULL }
        };

         static ChatCommand commandTable[] =
        {
            { "server",         SEC_ADMINISTRATOR,  true,  NULL,            "", serverCommandTable   },
            { NULL,             0,                  false, NULL,            "", NULL }
        };
        return commandTable;
    }

    // Triggering corpses expire check in world
    static bool HandleServerCorpsesCommand(ChatHandler* handler, char const* args)
    {
        sObjectAccessor->RemoveOldCorpses();
        return true;
    }

    static bool HandleServerInfoCommand(ChatHandler* handler, char const* args)
    {
        uint32 playersNum = sWorld->GetPlayerCount();
        uint32 maxPlayersNum = sWorld->GetMaxPlayerCount();
        uint32 activeClientsNum = sWorld->GetActiveSessionCount();
        uint32 queuedClientsNum = sWorld->GetQueuedSessionCount();
        uint32 maxActiveClientsNum = sWorld->GetMaxActiveSessionCount();
        uint32 maxQueuedClientsNum = sWorld->GetMaxQueuedSessionCount();
        std::string uptime = secsToTimeString(sWorld->GetUptime());
        uint32 updateTime = sWorld->GetUpdateTime();

        handler->SendSysMessage(_FULLVERSION);
        handler->PSendSysMessage(LANG_CONNECTED_PLAYERS, playersNum, maxPlayersNum);
        handler->PSendSysMessage(LANG_CONNECTED_USERS, activeClientsNum, maxActiveClientsNum, queuedClientsNum, maxQueuedClientsNum);
        handler->PSendSysMessage(LANG_UPTIME, uptime.c_str());
        handler->PSendSysMessage(LANG_UPDATE_DIFF, updateTime);
        // Can't use sWorld->ShutdownMsg here in case of console command
        if (sWorld->IsShuttingDown())
            handler->PSendSysMessage(LANG_SHUTDOWN_TIMELEFT, secsToTimeString(sWorld->GetShutDownTimeLeft()).c_str());

        return true;
    }
    // Display the 'Message of the day' for the realm
    static bool HandleServerMotdCommand(ChatHandler* handler, char const* args)
    {
        handler->PSendSysMessage(LANG_MOTD_CURRENT, sWorld->GetMotd());
        return true;
    }

    static bool HandleServerPLimitCommand(ChatHandler* handler, char const* args)
    {
        if (*args)
        {
            char* param = strtok((char*)args, " ");
            if (!param)
                return false;

            int l = strlen(param);

            if (strncmp(param, "player", l) == 0)
                sWorld->SetPlayerSecurityLimit(SEC_PLAYER);
            else if (strncmp(param, "moderator", l) == 0)
                sWorld->SetPlayerSecurityLimit(SEC_MODERATOR);
            else if (strncmp(param, "gamemaster", l) == 0)
                sWorld->SetPlayerSecurityLimit(SEC_GAMEMASTER);
            else if (strncmp(param, "administrator", l) == 0)
                sWorld->SetPlayerSecurityLimit(SEC_ADMINISTRATOR);
            else if (strncmp(param, "reset", l) == 0)
            {
                sWorld->SetPlayerAmountLimit(ConfigMgr::GetIntDefault("PlayerLimit", 100));
                sWorld->LoadDBAllowedSecurityLevel();
            }
            else
            {
                int val = atoi(param);
                if (val < 0)
                    sWorld->SetPlayerSecurityLimit(AccountTypes(uint32(-val)));
                else
                    sWorld->SetPlayerAmountLimit(uint32(val));
                }
        }

        uint32 pLimit = sWorld->GetPlayerAmountLimit();
        AccountTypes allowedAccountType = sWorld->GetPlayerSecurityLimit();
        char const* secName = "";
        switch (allowedAccountType)
        {
            case SEC_PLAYER:        secName = "Player";        break;
            case SEC_MODERATOR:     secName = "Moderator";     break;
            case SEC_GAMEMASTER:    secName = "Gamemaster";    break;
            case SEC_ADMINISTRATOR: secName = "Administrator"; break;
            default:                secName = "<unknown>";     break;
        }
        handler->PSendSysMessage("Player limits: amount %u, min. security level %s.", pLimit, secName);

        return true;
    }

    static bool HandleServerShutDownCancelCommand(ChatHandler* handler, char const* args)
    {
        sWorld->ShutdownCancel();
        return true;
    }

    static bool HandleServerShutDownCommand(ChatHandler* handler, char const* args)
    {
        if (!*args)
        return false;

        char* time_str = strtok ((char*) args, " ");
        char* exitcode_str = strtok (NULL, "");

        int32 time = atoi (time_str);

        // Prevent interpret wrong arg value as 0 secs shutdown time
        if ((time == 0 && (time_str[0] != '0' || time_str[1] != '\0')) || time < 0)
        return false;

        if (exitcode_str)
        {
        int32 exitcode = atoi(exitcode_str);

        // Handle atoi() errors
        if (exitcode == 0 && (exitcode_str[0] != '0' || exitcode_str[1] != '\0'))
            return false;

        // Exit code should be in range of 0-125, 126-255 is used
        // in many shells for their own return codes and code > 255
        // is not supported in many others
        if (exitcode < 0 || exitcode > 125)
            return false;

        sWorld->ShutdownServ(time, 0, exitcode);
        }
        else
        sWorld->ShutdownServ(time, 0, SHUTDOWN_EXIT_CODE);
        return true;
    }

    static bool HandleServerRestartCommand(ChatHandler* handler, char const* args)
    {
        if (!*args)
            return false;

        char* time_str = strtok ((char*) args, " ");
        char* exitcode_str = strtok (NULL, "");

        int32 time = atoi (time_str);

        //  Prevent interpret wrong arg value as 0 secs shutdown time
        if ((time == 0 && (time_str[0] != '0' || time_str[1] != '\0')) || time < 0)
            return false;

        if (exitcode_str)
        {
        int32 exitcode = atoi (exitcode_str);

        // Handle atoi() errors
        if (exitcode == 0 && (exitcode_str[0] != '0' || exitcode_str[1] != '\0'))
            return false;

        // Exit code should be in range of 0-125, 126-255 is used
        // in many shells for their own return codes and code > 255
        // is not supported in many others
        if (exitcode < 0 || exitcode > 125)
            return false;

        sWorld->ShutdownServ(time, SHUTDOWN_MASK_RESTART, exitcode);
        }
        else
        sWorld->ShutdownServ(time, SHUTDOWN_MASK_RESTART, RESTART_EXIT_CODE);
            return true;
    }

    static bool HandleServerIdleRestartCommand(ChatHandler* handler, char const* args)
    {
        if (!*args)
            return false;

        char* time_str = strtok ((char*) args, " ");
        char* exitcode_str = strtok (NULL, "");

        int32 time = atoi (time_str);

        // Prevent interpret wrong arg value as 0 secs shutdown time
        if ((time == 0 && (time_str[0] != '0' || time_str[1] != '\0')) || time < 0)
            return false;

        if (exitcode_str)
        {
        int32 exitcode = atoi (exitcode_str);

        // Handle atoi() errors
        if (exitcode == 0 && (exitcode_str[0] != '0' || exitcode_str[1] != '\0'))
            return false;

        // Exit code should be in range of 0-125, 126-255 is used
        // in many shells for their own return codes and code > 255
        // is not supported in many others
        if (exitcode < 0 || exitcode > 125)
            return false;

        sWorld->ShutdownServ(time, SHUTDOWN_MASK_RESTART|SHUTDOWN_MASK_IDLE, exitcode);
        }
        else
        sWorld->ShutdownServ(time, SHUTDOWN_MASK_RESTART|SHUTDOWN_MASK_IDLE, RESTART_EXIT_CODE);
            return true;
    }

    static bool HandleServerIdleShutDownCommand(ChatHandler* handler, char const* args)
    {
        if (!*args)
            return false;

        char* time_str = strtok ((char*) args, " ");
        char* exitcode_str = strtok (NULL, "");

        int32 time = atoi (time_str);

        // Prevent interpret wrong arg value as 0 secs shutdown time
        if ((time == 0 && (time_str[0] != '0' || time_str[1] != '\0')) || time < 0)
            return false;

        if (exitcode_str)
        {
        int32 exitcode = atoi (exitcode_str);

        // Handle atoi() errors
        if (exitcode == 0 && (exitcode_str[0] != '0' || exitcode_str[1] != '\0'))
            return false;

        // Exit code should be in range of 0-125, 126-255 is used
        // in many shells for their own return codes and code > 255
        // is not supported in many others
        if (exitcode < 0 || exitcode > 125)
            return false;

        sWorld->ShutdownServ(time, SHUTDOWN_MASK_IDLE, exitcode);
        }
        else
        sWorld->ShutdownServ(time, SHUTDOWN_MASK_IDLE, SHUTDOWN_EXIT_CODE);
            return true;
    }

    // Exit the realm
    static bool HandleServerExitCommand(ChatHandler* handler, char const* args)
    {
        handler->SendSysMessage(LANG_COMMAND_EXIT);
        World::StopNow(SHUTDOWN_EXIT_CODE);
        return true;
    }

    // Define the 'Message of the day' for the realm
    static bool HandleServerSetMotdCommand(ChatHandler* handler, char const* args)
    {
        sWorld->SetMotd(args);
        handler->PSendSysMessage(LANG_MOTD_NEW, args);
        return true;
    }

    // Set whether we accept new clients
    static bool HandleServerSetClosedCommand(ChatHandler* handler, char const* args)
    {
        if (strncmp(args, "on", 3) == 0)
        {
        handler->SendSysMessage(LANG_WORLD_CLOSED);
        sWorld->SetClosed(true);
        return true;
        }
        else if (strncmp(args, "off", 4) == 0)
        {
        handler->SendSysMessage(LANG_WORLD_OPENED);
        sWorld->SetClosed(false);
        return true;
        }

        handler->SendSysMessage(LANG_USE_BOL);
        handler->SetSentErrorMessage(true);
        return false;
    }

    // Set the level of logging
    static bool HandleServerSetLogFileLevelCommand(ChatHandler* handler, char const* args)
    {
        if (!*args)
            return false;

        char *NewLevel = strtok((char*)args, " ");
        if (!NewLevel)
            return false;

        sLog->SetLogFileLevel(NewLevel);
            return true;
    }

    // Set the level of logging
    static bool HandleServerSetLogLevelCommand(ChatHandler* handler, char const* args)
    {
        if (!*args)
            return false;

        char *NewLevel = strtok((char*)args, " ");
        if (!NewLevel)
            return false;

        sLog->SetLogLevel(NewLevel);
            return true;
    }

    // set diff time record interval
    static bool HandleServerSetDiffTimeCommand(ChatHandler* handler, char const* args)
    {
        if (!*args)
            return false;

        char *NewTimeStr = strtok((char*)args, " ");
        if (!NewTimeStr)
            return false;

        int32 NewTime =atoi(NewTimeStr);
        if (NewTime < 0)
            return false;

        sWorld->SetRecordDiffInterval(NewTime);
        printf( "Record diff every %u ms\n", NewTime);
            return true;
    }

    // toggle sql driver query logging
    static bool HandleServerToggleQueryLogging(ChatHandler* handler,const char* args )
    {
        sLog->SetSQLDriverQueryLogging(!sLog->GetSQLDriverQueryLogging());
        if (sLog->GetSQLDriverQueryLogging())
            handler->PSendSysMessage(LANG_SQLDRIVER_QUERY_LOGGING_ENABLED);
        else
            handler->PSendSysMessage(LANG_SQLDRIVER_QUERY_LOGGING_DISABLED);

        return true;
    }
};

void AddSC_server_commandscript()
{
    new server_commandscript();
}