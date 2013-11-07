/*
 * Copyright (C) 2008-2013 TrinityCore <http://www.trinitycore.org/>
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

#ifndef TRINITYCORE_LOG_H
#define TRINITYCORE_LOG_H

#include "Define.h"
#include "Appender.h"
#include "LogWorker.h"
#include "Logger.h"
#include "Dynamic/UnorderedMap.h"

#include <string>
#include <ace/Singleton.h>

// TODO: Replace all defines in core
#define LOG_FILTER_ACHIEVEMENTSYS "achievement"
#define LOG_FILTER_AUCTIONHOUSE   "auctionHouse"
#define LOG_FILTER_ARENAS         "bg.arena"
#define LOG_FILTER_BATTLEFIELD    "bg.battlefield"
#define LOG_FILTER_BATTLEGROUND   "bg.battleground"
#define LOG_FILTER_PLAYER_CHATLOG "chat.log"
#define LOG_FILTER_CALENDAR       "calendar"
#define LOG_FILTER_CHATSYS        "chat.system"
#define LOG_FILTER_CHEAT          "cheat"
#define LOG_FILTER_REMOTECOMMAND  "commands.ra"
#define LOG_FILTER_GMCOMMAND      "commands.gm"
#define LOG_FILTER_CONDITIONSYS   "condition"
#define LOG_FILTER_PETS           "entities.pet"
#define LOG_FILTER_CHARACTER      "entities.player.character"
#define LOG_FILTER_PLAYER_DUMP    "entities.player.dump"
#define LOG_FILTER_PLAYER         "entities.player"
#define LOG_FILTER_PLAYER_ITEMS   "entities.player.items"
#define LOG_FILTER_PLAYER_LOADING "entities.player.loading"
#define LOG_FILTER_PLAYER_SKILLS  "entities.player.skills"
#define LOG_FILTER_TRANSPORTS     "entities.transport"
#define LOG_FILTER_UNITS          "entities.unit"
#define LOG_FILTER_VEHICLES       "entities.vehicle"
#define LOG_FILTER_GAMEEVENTS     "gameevent"
#define LOG_FILTER_GUILD          "guild"
#define LOG_FILTER_LFG            "lfg"
#define LOG_FILTER_LOOT           "loot"
#define LOG_FILTER_MAPSCRIPTS     "maps.script"
#define LOG_FILTER_MAPS           "maps"
#define LOG_FILTER_GENERAL        "misc"
#define LOG_FILTER_NETWORKIO      "network"
#define LOG_FILTER_OPCODES        "network.opcode"
#define LOG_FILTER_SOAP           "network.soap"
#define LOG_FILTER_OUTDOORPVP     "outdoorpvp"
#define LOG_FILTER_POOLSYS        "pool"
#define LOG_FILTER_RBAC           "rbac"
#define LOG_FILTER_TSCR           "scripts"
#define LOG_FILTER_DATABASE_AI    "scripts.ai"
#define LOG_FILTER_SERVER_LOADING "server.loading"
#define LOG_FILTER_AUTHSERVER     "server.authserver"
#define LOG_FILTER_WORLDSERVER    "server.worldserver"
#define LOG_FILTER_SPELLS_AURAS   "spells"
#define LOG_FILTER_SQL_DEV        "sql.dev"
#define LOG_FILTER_SQL_DRIVER     "sql.driver"
#define LOG_FILTER_SQL            "sql.sql"
#define LOG_FILTER_WARDEN         "warden"

#define LOGGER_ROOT "root"

class Log
{
    friend class ACE_Singleton<Log, ACE_Thread_Mutex>;

    typedef UNORDERED_MAP<std::string, Logger> LoggerMap;

    private:
        Log();
        ~Log();

    public:
        void LoadFromConfig();
        void Close();
        bool ShouldLog(std::string const& type, LogLevel level) const;
        bool SetLogLevel(std::string const& name, char const* level, bool isLogger = true);

        void outTrace(std::string const& f, char const* str, ...) ATTR_PRINTF(3, 4);
        void outDebug(std::string const& f, char const* str, ...) ATTR_PRINTF(3, 4);
        void outInfo(std::string const& f, char const* str, ...) ATTR_PRINTF(3, 4);
        void outWarn(std::string const& f, char const* str, ...) ATTR_PRINTF(3, 4);
        void outError(std::string const& f, char const* str, ...) ATTR_PRINTF(3, 4);
        void outFatal(std::string const& f, char const* str, ...) ATTR_PRINTF(3, 4);

        void outCommand(uint32 account, const char * str, ...) ATTR_PRINTF(3, 4);
        void outCharDump(char const* str, uint32 account_id, uint32 guid, char const* name);
        static std::string GetTimestampStr();

        void SetRealmId(uint32 id);

    private:
        void vlog(std::string const& f, LogLevel level, char const* str, va_list argptr);
        void write(LogMessage* msg) const;

        Logger const* GetLoggerByType(std::string const& type) const;
        Appender* GetAppenderByName(std::string const& name);
        uint8 NextAppenderId();
        void CreateAppenderFromConfig(std::string const& name);
        void CreateLoggerFromConfig(std::string const& name);
        void ReadAppendersFromConfig();
        void ReadLoggersFromConfig();

        AppenderMap appenders;
        LoggerMap loggers;
        uint8 AppenderId;

        std::string m_logsDir;
        std::string m_logsTimestamp;

        LogWorker* worker;
};

inline Logger const* Log::GetLoggerByType(std::string const& type) const
{
    LoggerMap::const_iterator it = loggers.find(type);
    if (it != loggers.end())
        return &(it->second);

    if (type == LOGGER_ROOT)
        return NULL;

    std::string parentLogger = LOGGER_ROOT;
    size_t found = type.find_last_of(".");
    if (found != std::string::npos)
        parentLogger = type.substr(0,found);

    return GetLoggerByType(parentLogger);
}

inline bool Log::ShouldLog(std::string const& type, LogLevel level) const
{
    // TODO: Use cache to store "Type.sub1.sub2": "Type" equivalence, should
    // Speed up in cases where requesting "Type.sub1.sub2" but only configured
    // Logger "Type"

    Logger const* logger = GetLoggerByType(type);
    if (!logger)
        return false;

    LogLevel logLevel = logger->getLogLevel();
    return logLevel != LOG_LEVEL_DISABLED && logLevel <= level;
}

#define sLog ACE_Singleton<Log, ACE_Thread_Mutex>::instance()

#if COMPILER != COMPILER_MICROSOFT
#define TC_LOG_MESSAGE_BODY(level__, call__, filterType__, ...)     \
        do {                                                        \
            if (sLog->ShouldLog(filterType__, level__))             \
                sLog->call__(filterType__, __VA_ARGS__);            \
        } while (0)
#else
#define TC_LOG_MESSAGE_BODY(level__, call__, filterType__, ...)     \
        __pragma(warning(push))                                     \
        __pragma(warning(disable:4127))                             \
        do {                                                        \
            if (sLog->ShouldLog(filterType__, level__))             \
                sLog->call__(filterType__, __VA_ARGS__);            \
        } while (0)                                                 \
        __pragma(warning(pop))
#endif

#define TC_LOG_TRACE(filterType__, ...) \
    TC_LOG_MESSAGE_BODY(LOG_LEVEL_TRACE, outTrace, filterType__, __VA_ARGS__)

#define TC_LOG_DEBUG(filterType__, ...) \
    TC_LOG_MESSAGE_BODY(LOG_LEVEL_DEBUG, outDebug, filterType__, __VA_ARGS__)

#define TC_LOG_INFO(filterType__, ...)  \
    TC_LOG_MESSAGE_BODY(LOG_LEVEL_INFO, outInfo, filterType__, __VA_ARGS__)

#define TC_LOG_WARN(filterType__, ...)  \
    TC_LOG_MESSAGE_BODY(LOG_LEVEL_WARN, outWarn, filterType__, __VA_ARGS__)

#define TC_LOG_ERROR(filterType__, ...) \
    TC_LOG_MESSAGE_BODY(LOG_LEVEL_ERROR, outError, filterType__, __VA_ARGS__)

#define TC_LOG_FATAL(filterType__, ...) \
    TC_LOG_MESSAGE_BODY(LOG_LEVEL_FATAL, outFatal, filterType__, __VA_ARGS__)

#endif
