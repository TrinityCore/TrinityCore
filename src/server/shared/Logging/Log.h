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

class Log
{
    friend class ACE_Singleton<Log, ACE_Thread_Mutex>;

    typedef UNORDERED_MAP<uint8, Logger> LoggerMap;

    private:
        Log();
        ~Log();

    public:
        void LoadFromConfig();
        void Close();
        bool ShouldLog(LogFilterType type, LogLevel level) const;
        bool SetLogLevel(std::string const& name, char const* level, bool isLogger = true);

        void outTrace(LogFilterType f, char const* str, ...) ATTR_PRINTF(3, 4);
        void outDebug(LogFilterType f, char const* str, ...) ATTR_PRINTF(3, 4);
        void outInfo(LogFilterType f, char const* str, ...) ATTR_PRINTF(3, 4);
        void outWarn(LogFilterType f, char const* str, ...) ATTR_PRINTF(3, 4);
        void outError(LogFilterType f, char const* str, ...) ATTR_PRINTF(3, 4);
        void outFatal(LogFilterType f, char const* str, ...) ATTR_PRINTF(3, 4);

        void outCommand(uint32 account, const char * str, ...) ATTR_PRINTF(3, 4);
        void outCharDump(char const* str, uint32 account_id, uint32 guid, char const* name);
        static std::string GetTimestampStr();

        void SetRealmId(uint32 id);

    private:
        void vlog(LogFilterType f, LogLevel level, char const* str, va_list argptr);
        void write(LogMessage* msg);

        Logger* GetLoggerByType(LogFilterType filter);
        Appender* GetAppenderByName(std::string const& name);
        uint8 NextAppenderId();
        void CreateAppenderFromConfig(const char* name);
        void CreateLoggerFromConfig(const char* name);
        void ReadAppendersFromConfig();
        void ReadLoggersFromConfig();

        AppenderMap appenders;
        LoggerMap loggers;
        uint8 AppenderId;

        std::string m_logsDir;
        std::string m_logsTimestamp;

        LogWorker* worker;
};

inline bool Log::ShouldLog(LogFilterType type, LogLevel level) const
{
    LoggerMap::const_iterator it = loggers.find(uint8(type));
    if (it != loggers.end())
    {
        LogLevel logLevel = it->second.getLogLevel();
        return logLevel != LOG_LEVEL_DISABLED && logLevel <= level;
    }

    if (type != LOG_FILTER_GENERAL)
        return ShouldLog(LOG_FILTER_GENERAL, level);
    else
        return false;
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
