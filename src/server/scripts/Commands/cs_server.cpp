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
Name: server_commandscript
%Complete: 100
Comment: All server related commands
Category: commandscripts
EndScriptData */

#include "ScriptMgr.h"
#include "Chat.h"
#include "Config.h"
#include "DatabaseEnv.h"
#include "DatabaseLoader.h"
#include "GameTime.h"
#include "GitRevision.h"
#include "Language.h"
#include "Log.h"
#include "MySQLThreading.h"
#include "ObjectAccessor.h"
#include "Player.h"
#include "RBAC.h"
#include "Realm.h"
#include "UpdateTime.h"
#include "Util.h"
#include "VMapFactory.h"
#include "VMapManager2.h"
#include "World.h"
#include "WorldSession.h"

#include <numeric>

#include <boost/filesystem/operations.hpp>
#include <openssl/crypto.h>
#include <openssl/opensslv.h>

class server_commandscript : public CommandScript
{
public:
    server_commandscript() : CommandScript("server_commandscript") { }

    std::vector<ChatCommand> GetCommands() const override
    {
        static std::vector<ChatCommand> serverIdleRestartCommandTable =
        {
            { "cancel", rbac::RBAC_PERM_COMMAND_SERVER_IDLERESTART_CANCEL, true, &HandleServerShutDownCancelCommand, "" },
            { ""   ,    rbac::RBAC_PERM_COMMAND_SERVER_IDLERESTART,        true, &HandleServerIdleRestartCommand,    "" },
        };

        static std::vector<ChatCommand> serverIdleShutdownCommandTable =
        {
            { "cancel", rbac::RBAC_PERM_COMMAND_SERVER_IDLESHUTDOWN_CANCEL, true, &HandleServerShutDownCancelCommand, "" },
            { ""   ,    rbac::RBAC_PERM_COMMAND_SERVER_IDLESHUTDOWN,        true, &HandleServerIdleShutDownCommand,   "" },
        };

        static std::vector<ChatCommand> serverRestartCommandTable =
        {
            { "cancel", rbac::RBAC_PERM_COMMAND_SERVER_RESTART_CANCEL, true, &HandleServerShutDownCancelCommand, "" },
            { "force",  rbac::RBAC_PERM_COMMAND_SERVER_RESTART_FORCE,  true, &HandleServerForceRestartCommand,   "" },
            { ""   ,    rbac::RBAC_PERM_COMMAND_SERVER_RESTART,        true, &HandleServerRestartCommand,        "" },
        };

        static std::vector<ChatCommand> serverShutdownCommandTable =
        {
            { "cancel", rbac::RBAC_PERM_COMMAND_SERVER_SHUTDOWN_CANCEL, true, &HandleServerShutDownCancelCommand, "" },
            { "force",  rbac::RBAC_PERM_COMMAND_SERVER_SHUTDOWN_FORCE,  true, &HandleServerForceShutDownCommand,  "" },
            { ""   ,    rbac::RBAC_PERM_COMMAND_SERVER_SHUTDOWN,        true, &HandleServerShutDownCommand,       "" },
        };

        static std::vector<ChatCommand> serverSetCommandTable =
        {
            { "difftime", rbac::RBAC_PERM_COMMAND_SERVER_SET_DIFFTIME, true, &HandleServerSetDiffTimeCommand, "" },
            { "loglevel", rbac::RBAC_PERM_COMMAND_SERVER_SET_LOGLEVEL, true, &HandleServerSetLogLevelCommand, "" },
            { "motd",     rbac::RBAC_PERM_COMMAND_SERVER_SET_MOTD,     true, &HandleServerSetMotdCommand,     "" },
            { "closed",   rbac::RBAC_PERM_COMMAND_SERVER_SET_CLOSED,   true, &HandleServerSetClosedCommand,   "" },
        };

        static std::vector<ChatCommand> serverCommandTable =
        {
            { "corpses",      rbac::RBAC_PERM_COMMAND_SERVER_CORPSES,      true, &HandleServerCorpsesCommand, "" },
            { "debug",        rbac::RBAC_PERM_COMMAND_SERVER_DEBUG,        true, &HandleServerDebugCommand,   "" },
            { "exit",         rbac::RBAC_PERM_COMMAND_SERVER_EXIT,         true, &HandleServerExitCommand,    "" },
            { "idlerestart",  rbac::RBAC_PERM_COMMAND_SERVER_IDLERESTART,  true, nullptr,                     "", serverIdleRestartCommandTable },
            { "idleshutdown", rbac::RBAC_PERM_COMMAND_SERVER_IDLESHUTDOWN, true, nullptr,                     "", serverIdleShutdownCommandTable },
            { "info",         rbac::RBAC_PERM_COMMAND_SERVER_INFO,         true, &HandleServerInfoCommand,    "" },
            { "motd",         rbac::RBAC_PERM_COMMAND_SERVER_MOTD,         true, &HandleServerMotdCommand,    "" },
            { "plimit",       rbac::RBAC_PERM_COMMAND_SERVER_PLIMIT,       true, &HandleServerPLimitCommand,  "" },
            { "restart",      rbac::RBAC_PERM_COMMAND_SERVER_RESTART,      true, nullptr,                     "", serverRestartCommandTable },
            { "shutdown",     rbac::RBAC_PERM_COMMAND_SERVER_SHUTDOWN,     true, nullptr,                     "", serverShutdownCommandTable },
            { "set",          rbac::RBAC_PERM_COMMAND_SERVER_SET,          true, nullptr,                     "", serverSetCommandTable },
        };

        static std::vector<ChatCommand> commandTable =
        {
            { "server", rbac::RBAC_PERM_COMMAND_SERVER, true, nullptr, "", serverCommandTable },
        };
        return commandTable;
    }

    // Triggering corpses expire check in world
    static bool HandleServerCorpsesCommand(ChatHandler* /*handler*/, char const* /*args*/)
    {
        sWorld->RemoveOldCorpses();
        return true;
    }

    static bool HandleServerDebugCommand(ChatHandler* handler, char const* /*args*/)
    {
        uint16 worldPort = uint16(sWorld->getIntConfig(CONFIG_PORT_WORLD));
        std::string dbPortOutput;

        {
            uint16 dbPort = 0;
            if (QueryResult res = LoginDatabase.PQuery("SELECT port FROM realmlist WHERE id = %u", realm.Id.Realm))
                dbPort = (*res)[0].GetUInt16();

            if (dbPort)
                dbPortOutput = Trinity::StringFormat("Realmlist (Realm Id: %u) configured in port %" PRIu16, realm.Id.Realm, dbPort);
            else
                dbPortOutput = Trinity::StringFormat("Realm Id: %u not found in `realmlist` table. Please check your setup", realm.Id.Realm);
        }

        handler->PSendSysMessage("%s", GitRevision::GetFullVersion());
        handler->PSendSysMessage("Using SSL version: %s (library: %s)", OPENSSL_VERSION_TEXT, SSLeay_version(SSLEAY_VERSION));
        handler->PSendSysMessage("Using Boost version: %i.%i.%i", BOOST_VERSION / 100000, BOOST_VERSION / 100 % 1000, BOOST_VERSION % 100);
        handler->PSendSysMessage("Using MySQL version: %u", MySQL::GetLibraryVersion());
        handler->PSendSysMessage("Using CMake version: %s", GitRevision::GetCMakeVersion());

        handler->PSendSysMessage("Compiled on: %s", GitRevision::GetHostOSVersion());

        uint32 updateFlags = sConfigMgr->GetIntDefault("Updates.EnableDatabases", DatabaseLoader::DATABASE_NONE);
        if (!updateFlags)
            handler->SendSysMessage("Automatic database updates are disabled for all databases!");
        else
        {
            static char const* const databaseNames[3 /*TOTAL_DATABASES*/] =
            {
                "Auth",
                "Characters",
                "World"
            };

            std::string availableUpdateDatabases;
            for (uint32 i = 0; i < 3 /* TOTAL_DATABASES*/; ++i)
            {
                if (!(updateFlags & (1 << i)))
                    continue;

                availableUpdateDatabases += databaseNames[i];
                if (i != 3 /*TOTAL_DATABASES*/ - 1)
                    availableUpdateDatabases += ", ";
            }

            handler->PSendSysMessage("Automatic database updates are enabled for the following databases: %s", availableUpdateDatabases.c_str());
        }

        handler->PSendSysMessage("Worldserver listening connections on port %" PRIu16, worldPort);
        handler->PSendSysMessage("%s", dbPortOutput.c_str());

        bool vmapIndoorCheck = sWorld->getBoolConfig(CONFIG_VMAP_INDOOR_CHECK);
        bool vmapLOSCheck = VMAP::VMapFactory::createOrGetVMapManager()->isLineOfSightCalcEnabled();
        bool vmapHeightCheck = VMAP::VMapFactory::createOrGetVMapManager()->isHeightCalcEnabled();

        bool mmapEnabled = sWorld->getBoolConfig(CONFIG_ENABLE_MMAPS);

        std::string dataDir = sWorld->GetDataPath();
        std::vector<std::string> subDirs;
        subDirs.emplace_back("maps");
        if (vmapIndoorCheck || vmapLOSCheck || vmapHeightCheck)
        {
            handler->PSendSysMessage("VMAPs status: Enabled. LineOfSight: %i, getHeight: %i, indoorCheck: %i", vmapLOSCheck, vmapHeightCheck, vmapIndoorCheck);
            subDirs.emplace_back("vmaps");
        }
        else
            handler->SendSysMessage("VMAPs status: Disabled");

        if (mmapEnabled)
        {
            handler->SendSysMessage("MMAPs status: Enabled");
            subDirs.emplace_back("mmaps");
        }
        else
            handler->SendSysMessage("MMAPs status: Disabled");

        for (std::string const& subDir : subDirs)
        {
            boost::filesystem::path mapPath(dataDir);
            mapPath.append(subDir);

            if (!boost::filesystem::exists(mapPath))
            {
                handler->PSendSysMessage("%s directory doesn't exist!. Using path: %s", subDir.c_str(), mapPath.generic_string().c_str());
                continue;
            }

            auto end = boost::filesystem::directory_iterator();
            std::size_t folderSize = std::accumulate(boost::filesystem::directory_iterator(mapPath), end, std::size_t(0), [](std::size_t val, boost::filesystem::path const& mapFile)
            {
                if (boost::filesystem::is_regular_file(mapFile))
                    val += boost::filesystem::file_size(mapFile);
                return val;
            });

            handler->PSendSysMessage("%s directory located in %s. Total size: " SZFMTD " bytes", subDir.c_str(), mapPath.generic_string().c_str(), folderSize);
        }

        LocaleConstant defaultLocale = sWorld->GetDefaultDbcLocale();
        uint32 availableLocalesMask = (1 << defaultLocale);

        for (uint8 i = 0; i < TOTAL_LOCALES; ++i)
        {
            LocaleConstant locale = static_cast<LocaleConstant>(i);
            if (locale == defaultLocale)
                continue;

            if (sWorld->GetAvailableDbcLocale(locale) != defaultLocale)
                availableLocalesMask |= (1 << locale);
        }

        std::string availableLocales;
        for (uint8 i = 0; i < TOTAL_LOCALES; ++i)
        {
            if (!(availableLocalesMask & (1 << i)))
                continue;

            availableLocales += localeNames[i];
            if (i != TOTAL_LOCALES - 1)
                availableLocales += " ";
        }

        handler->PSendSysMessage("Using %s DBC Locale as default. All available DBC locales: %s", localeNames[defaultLocale], availableLocales.c_str());

        handler->PSendSysMessage("Using World DB: %s", sWorld->GetDBVersion());

        handler->PSendSysMessage("LoginDatabase queue size: %zu", LoginDatabase.QueueSize());
        handler->PSendSysMessage("CharacterDatabase queue size: %zu", CharacterDatabase.QueueSize());
        handler->PSendSysMessage("WorldDatabase queue size: %zu", WorldDatabase.QueueSize());
        handler->PSendSysMessage("HotfixDatabase queue size: %zu", HotfixDatabase.QueueSize());
        return true;
    }

    static bool HandleServerInfoCommand(ChatHandler* handler, char const* /*args*/)
    {
        uint32 playersNum           = sWorld->GetPlayerCount();
        uint32 maxPlayersNum        = sWorld->GetMaxPlayerCount();
        uint32 activeClientsNum     = sWorld->GetActiveSessionCount();
        uint32 queuedClientsNum     = sWorld->GetQueuedSessionCount();
        uint32 maxActiveClientsNum  = sWorld->GetMaxActiveSessionCount();
        uint32 maxQueuedClientsNum  = sWorld->GetMaxQueuedSessionCount();
        std::string uptime          = secsToTimeString(GameTime::GetUptime());
        uint32 updateTime           = sWorldUpdateTime.GetLastUpdateTime();

        handler->PSendSysMessage("%s", GitRevision::GetFullVersion());
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
    static bool HandleServerMotdCommand(ChatHandler* handler, char const* /*args*/)
    {
        std::string motd;
        for (std::string const& line : sWorld->GetMotd())
            motd += line;
        handler->PSendSysMessage(LANG_MOTD_CURRENT, motd.c_str());
        return true;
    }

    static bool HandleServerPLimitCommand(ChatHandler* handler, char const* args)
    {
        if (*args)
        {
            char* paramStr = strtok((char*)args, " ");
            if (!paramStr)
                return false;

            int32 limit = strlen(paramStr);

            if (strncmp(paramStr, "player", limit) == 0)
                sWorld->SetPlayerSecurityLimit(SEC_PLAYER);
            else if (strncmp(paramStr, "moderator", limit) == 0)
                sWorld->SetPlayerSecurityLimit(SEC_MODERATOR);
            else if (strncmp(paramStr, "gamemaster", limit) == 0)
                sWorld->SetPlayerSecurityLimit(SEC_GAMEMASTER);
            else if (strncmp(paramStr, "administrator", limit) == 0)
                sWorld->SetPlayerSecurityLimit(SEC_ADMINISTRATOR);
            else if (strncmp(paramStr, "reset", limit) == 0)
            {
                sWorld->SetPlayerAmountLimit(sConfigMgr->GetIntDefault("PlayerLimit", 100));
                sWorld->LoadDBAllowedSecurityLevel();
            }
            else
            {
                int32 value = atoi(paramStr);
                if (value < 0)
                    sWorld->SetPlayerSecurityLimit(AccountTypes(-value));
                else
                    sWorld->SetPlayerAmountLimit(uint32(value));
            }
        }

        uint32 playerAmountLimit = sWorld->GetPlayerAmountLimit();
        AccountTypes allowedAccountType = sWorld->GetPlayerSecurityLimit();
        char const* secName = "";
        switch (allowedAccountType)
        {
            case SEC_PLAYER:
                secName = "Player";
                break;
            case SEC_MODERATOR:
                secName = "Moderator";
                break;
            case SEC_GAMEMASTER:
                secName = "Gamemaster";
                break;
            case SEC_ADMINISTRATOR:
                secName = "Administrator";
                break;
            default:
                secName = "<unknown>";
                break;
        }
        handler->PSendSysMessage("Player limits: amount %u, min. security level %s.", playerAmountLimit, secName);

        return true;
    }

    static bool HandleServerShutDownCancelCommand(ChatHandler* handler, char const* /*args*/)
    {
        if (uint32 timer = sWorld->ShutdownCancel())
            handler->PSendSysMessage(LANG_SHUTDOWN_CANCELLED, timer);

        return true;
    }

    static bool IsOnlyUser(WorldSession* mySession)
    {
        // check if there is any session connected from a different address
        std::string myAddr = mySession ? mySession->GetRemoteAddress() : "";
        SessionMap const& sessions = sWorld->GetAllSessions();
        for (SessionMap::value_type const& session : sessions)
            if (session.second && myAddr != session.second->GetRemoteAddress())
                return false;
        return true;
    }
    static bool HandleServerShutDownCommand(ChatHandler* handler, char const* args)
    {
        return ShutdownServer(handler, args, 0, SHUTDOWN_EXIT_CODE);
    }

    static bool HandleServerRestartCommand(ChatHandler* handler, char const* args)
    {
       return ShutdownServer(handler, args, SHUTDOWN_MASK_RESTART, RESTART_EXIT_CODE);
    }

    static bool HandleServerForceShutDownCommand(ChatHandler* handler, char const* args)
    {
        return ShutdownServer(handler, args, SHUTDOWN_MASK_FORCE, SHUTDOWN_EXIT_CODE);
    }

    static bool HandleServerForceRestartCommand(ChatHandler* handler, char const* args)
    {
        return ShutdownServer(handler, args, SHUTDOWN_MASK_FORCE | SHUTDOWN_MASK_RESTART, RESTART_EXIT_CODE);
    }

    static bool HandleServerIdleShutDownCommand(ChatHandler* handler, char const* args)
    {
        return ShutdownServer(handler, args, SHUTDOWN_MASK_IDLE, SHUTDOWN_EXIT_CODE);
    }

    static bool HandleServerIdleRestartCommand(ChatHandler* handler, char const* args)
    {
        return ShutdownServer(handler, args, SHUTDOWN_MASK_RESTART | SHUTDOWN_MASK_IDLE, RESTART_EXIT_CODE);
    }

    // Exit the realm
    static bool HandleServerExitCommand(ChatHandler* handler, char const* /*args*/)
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
    static bool HandleServerSetLogLevelCommand(ChatHandler* /*handler*/, char const* args)
    {
        if (!*args)
            return false;

        char* type = strtok((char*)args, " ");
        char* name = strtok(nullptr, " ");
        char* level = strtok(nullptr, " ");

        if (!type || !name || !level || *name == '\0' || *level == '\0' || (*type != 'a' && *type != 'l'))
            return false;

        sLog->SetLogLevel(name, level, *type == 'l');
        return true;
    }

    // set diff time record interval
    static bool HandleServerSetDiffTimeCommand(ChatHandler* /*handler*/, char const* args)
    {
        if (!*args)
            return false;

        char* newTimeStr = strtok((char*)args, " ");
        if (!newTimeStr)
            return false;

        int32 newTime = atoi(newTimeStr);
        if (newTime < 0)
            return false;

        sWorldUpdateTime.SetRecordUpdateTimeInterval(newTime);
        printf("Record diff every %i ms\n", newTime);

        return true;
    }

private:
    static bool ParseExitCode(char const* exitCodeStr, int32& exitCode)
    {
        exitCode = atoi(exitCodeStr);

        // Handle atoi() errors
        if (exitCode == 0 && (exitCodeStr[0] != '0' || exitCodeStr[1] != '\0'))
            return false;

        // Exit code should be in range of 0-125, 126-255 is used
        // in many shells for their own return codes and code > 255
        // is not supported in many others
        if (exitCode < 0 || exitCode > 125)
            return false;

        return true;
    }

    static bool ShutdownServer(ChatHandler* handler, char const* args, uint32 shutdownMask, int32 defaultExitCode)
    {
        if (!*args)
            return false;

        if (strlen(args) > 255)
            return false;

        // #delay [#exit_code] [reason]
        int32 delay = 0;
        char* delayStr = strtok((char*)args, " ");
        if (!delayStr)
            return false;

        if (isNumeric(delayStr))
        {
            delay = atoi(delayStr);
            // Prevent interpret wrong arg value as 0 secs shutdown time
            if ((delay == 0 && (delayStr[0] != '0' || delayStr[1] != '\0')) || delay < 0)
                return false;
        }
        else
        {
            delay = TimeStringToSecs(std::string(delayStr));

            if (delay == 0)
                return false;
        }

        char* exitCodeStr = nullptr;

        char reason[256] = { 0 };

        while (char* nextToken = strtok(nullptr, " "))
        {
            if (isNumeric(nextToken))
                exitCodeStr = nextToken;
            else
            {
                strcat(reason, nextToken);
                if (char* remainingTokens = strtok(nullptr, "\0"))
                {
                    strcat(reason, " ");
                    strcat(reason, remainingTokens);
                }
                break;
            }
        }

        int32 exitCode = defaultExitCode;
        if (exitCodeStr)
            if (!ParseExitCode(exitCodeStr, exitCode))
                return false;

        // Override parameter "delay" with the configuration value if there are still players connected and "force" parameter was not specified
        if (delay < (int32)sWorld->getIntConfig(CONFIG_FORCE_SHUTDOWN_THRESHOLD) && !(shutdownMask & SHUTDOWN_MASK_FORCE) && !IsOnlyUser(handler->GetSession()))
        {
              delay = (int32)sWorld->getIntConfig(CONFIG_FORCE_SHUTDOWN_THRESHOLD);
            handler->PSendSysMessage(LANG_SHUTDOWN_DELAYED, delay);
        }

        sWorld->ShutdownServ(delay, shutdownMask, static_cast<uint8>(exitCode), std::string(reason));

        return true;
    }
};

void AddSC_server_commandscript()
{
    new server_commandscript();
}
